<?php
/***********************************************************************
 * Copyright 2015 Blue Cask Software. All rights reserved.
 *                                                                                                                       
 * THIS PROGRAM IS CONFIDENTIAL AND PROPRIETARY TO BLUE CASK
 * SOFTWARE.  Any unauthorized use, reproduction, modification, or
 * disclosure of this program is strictly prohibited without the
 * express written permission of an authorized representative of
 * Blue Cask Software..
 ************************************************************************/
include_once("config/init.php");
include_once("data-access/PlayerAccess.php");
include_once("data-access/BetRuleAccess.php");

if (array_key_exists('createBetRule', $_POST)) { 
  try {
    if (!array_key_exists('strategySet', $_POST)) {
      throw new Exception("strategySet must be provided when creating player strategyset");
    }
    if (!array_key_exists('strategySetName', $_POST)) {
      throw new Exception("strategySetName must be provided when creating player strategyset");
    }
    if (!array_key_exists('strategySetDescription', $_POST)) {
      throw new Exception("strategySetDescription must be provided when creating player strategyset");
    }
    
    if (Session::isLoggedIn()) {
      $playerAccess = new PlayerAccess();
      $player = $playerAccess->readPlayerByEmail($_SESSION['user_email']);
    }
    
    $playerStrategyAccess = new PlayerStrategyAccess();
    $playerStrategyId = $playerStrategyAccess->createPlayerStrategy($_POST["strategySetName"], $_POST["strategySetDescription"], $player["id"], $_POST["strategySet"]);

    $result = array("result" => "success", "message" => "Player strategyset created");

    echo(json_encode($result));
  } catch (Exception $e) {
    $result = array("result" => "error", "message" => $e->getMessage());
    echo(json_encode($result));
  }
} elseif (array_key_exists('getPlayerStrategyNames', $_POST)) { 
  try {
    if (Session::isLoggedIn()) {
      $playerAccess = new PlayerAccess();
      $player = $playerAccess->readPlayerByEmail($_SESSION['user_email']);
    }

    $playerStrategyAccess = new PlayerStrategyAccess();
    $playerStrategyNames = $playerStrategyAccess->readPlayerStrategyNames($player["id"]);
    
    $result = array("result" => "success", "message" => "Player strategy names retrieved", "playerStrategyNames" => $playerStrategyNames);
    echo(json_encode($result));
  } catch (Exception $e) {
    $result = array("result" => "error", "message" => $e->getMessage());
    echo(json_encode($result));
  }
} elseif (array_key_exists('getPlayerStrategyInfo', $_POST)) { 
  try {
    if (Session::isLoggedIn()) {
      $playerAccess = new PlayerAccess();
      $player = $playerAccess->readPlayerByEmail($_SESSION['user_email']);
    }

    $playerStrategyAccess = new PlayerStrategyAccess();
    $playerStrategyInfo = $playerStrategyAccess->readPlayerStrategyInfo($player["id"]);
    $systemStrategyInfo = $playerStrategyAccess->readPlayerStrategyInfo(PlayerAccess::DEFAULT_PLAYER_ID);
    
    $result = array("result" => "success", 
                    "message" => "Player strategy info retreived", 
                    "playerStrategyInfo" => $playerStrategyInfo,
                    "systemStrategyInfo" => $systemStrategyInfo);
    echo(json_encode($result));
  } catch (Exception $e) {
    $result = array("result" => "error", "message" => $e->getMessage());
    echo(json_encode($result));
  }
} elseif (array_key_exists('getPlayerStrategySet', $_POST)) {
  try {
    if (!array_key_exists('strategyId', $_POST)) {
      throw new Exception("strategyId must be provided when getting player strategyset");
    }

    if (Session::isLoggedIn()) {
      $playerAccess = new PlayerAccess();
      $player = $playerAccess->readPlayerByEmail($_SESSION['user_email']);
    }

    $playerStrategyAccess = new PlayerStrategyAccess();
    $playerStrategySet = $playerStrategyAccess->readPlayerStrategy($_POST['strategyId']);

    $result = array("result" => "success",
                    "message" => "Player strategy set retreived",
                    "playerStrategySet" => $playerStrategySet);
    echo(json_encode($result));
  } catch (Exception $e) {
    $result = array("result" => "error", "message" => $e->getMessage());
    echo(json_encode($result));
  }    
} else { 
  $result = array("result" => "error", "message" => "Could not find valid action for strategyHandler");
  echo(json_encode($result));
}
?>
