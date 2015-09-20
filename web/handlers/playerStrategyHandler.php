<?php
/***********************************************************************
 * Copyright 2012 Blue Cask Software. All rights reserved.
 *                                                                                                                       
 * THIS PROGRAM IS CONFIDENTIAL AND PROPRIETARY TO BLUE CASK
 * SOFTWARE.  Any unauthorized use, reproduction, modification, or
 * disclosure of this program is strictly prohibited without the
 * express written permission of an authorized representative of
 * Blue Cask Software..
 ************************************************************************/
include_once("config/init.php");
include_once("data-access/PlayerAccess.php");
include_once("data-access/PlayerStrategyAccess.php");

if (array_key_exists('createPlayerStrategySet', $_POST)) { 
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
    $playerStrategyNames = $playerStrategyAccess->readPlayerStrategyNames($player["id"]);

    $result = array("result" => "success", "message" => "Player strategyset created", "playerStrategyId" => $playerStrategyId, "playerStrategyNames" => $playerStrategyNames);

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
    
    $result = array("result" => "success", "message" => "Player strategyset created", "playerStrategyNames" => $playerStrategyNames);
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
    
    $result = array("result" => "success", "message" => "Player strategy info retreived", "playerStrategyInfo" => $playerStrategyInfo);
    echo(json_encode($result));
  } catch (Exception $e) {
    $result = array("result" => "error", "message" => $e->getMessage());
    echo(json_encode($result));
  }
    
} else { 
  $result = array("result" => "error", "message" => "Could not find valid action for strategyHandler");
}
?>
