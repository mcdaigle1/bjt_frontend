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
include_once("data-access/DealerStrategyAccess.php");

$valid_actions = array("createDealerStrategySet", "getDealerStrategyNames", "getDealerStrategyInfo", "getDealerStrategySet");
$action = $_POST["action"];

if (!in_array($action, $valid_actions)) {
  $result = array("result" => "error", "message" => "Invalid action to dealerStrategyController: " . $action);
  echo(json_encode($result));
  return;
}

try {
  switch ($action) {
    case "createDealerStrategySet":
      if (!array_key_exists('strategySet', $_POST)) {
        throw new Exception("strategySet must be provided when creating dealer strategyset");
      }
      if (!array_key_exists('strategySetName', $_POST)) {
        throw new Exception("strategySetName must be provided when creating dealer strategyset");
      }
      if (!array_key_exists('strategySetDescription', $_POST)) {
        throw new Exception("strategySetDescription must be provided when creating dealer strategyset");
      }
    
      if (Session::isLoggedIn()) {
        $playerAccess = new PlayerAccess();
        $player = $playerAccess->readPlayerByEmail($_SESSION['user_email']);
      }
    
      $dealerStrategyAccess = new DealerStrategyAccess();
      $dealerStrategyId = $dealerStrategyAccess->createDealerStrategy($_POST["strategySetName"], $_POST["strategySetDescription"], $player["id"], $_POST["strategySet"]);

      $result = array("result" => "success", "message" => "Dealer strategyset created");

      echo(json_encode($result));
      break;
    case "getDealerStrategyNames":
      if (Session::isLoggedIn()) {
        $playerAccess = new PlayerAccess();
        $player = $playerAccess->readPlayerByEmail($_SESSION['user_email']);
      }

      $dealerStrategyAccess = new DealerStrategyAccess();
      $dealerStrategyNames = $dealerStrategyAccess->readDealerStrategyNames($player["id"]);
    
      $result = array("result" => "success", "message" => "Dealer strategy names retrieved", "dealerStrategyNames" => $dealerStrategyNames);
      echo(json_encode($result));
      break;
    case "getDealerStrategyInfo":
      if (Session::isLoggedIn()) {
        $playerAccess = new PlayerAccess();
        $player = $playerAccess->readPlayerByEmail($_SESSION['user_email']);
      }

      $dealerStrategyAccess = new DealerStrategyAccess();
      $dealerStrategyInfo = $dealerStrategyAccess->readDealerStrategyInfo($player["id"]);
      $systemStrategyInfo = $dealerStrategyAccess->readDealerStrategyInfo(PlayerAccess::DEFAULT_PLAYER_ID);
    
      $result = array("result" => "success", 
                      "message" => "Dealer strategy info retreived", 
                      "dealerStrategyInfo" => $dealerStrategyInfo,
                      "systemStrategyInfo" => $systemStrategyInfo);
      echo(json_encode($result));
      break;
    case "getDealerStrategySet":
      if (!array_key_exists('strategyId', $_POST)) {
        throw new Exception("strategyId must be provided when getting dealer strategyset");
      }

      if (Session::isLoggedIn()) {
        $playerAccess = new PlayerAccess();
        $player = $playerAccess->readPlayerByEmail($_SESSION['user_email']);
      }

      $dealerStrategyAccess = new DealerStrategyAccess();
      $dealerStrategySet = $dealerStrategyAccess->readDealerStrategy($_POST['strategyId']);

      $result = array("result" => "success",
                      "message" => "Dealer strategy set retreived",
                      "dealerStrategySet" => $dealerStrategySet);
      echo(json_encode($result));
      break;
  }    
} catch (Exception $e) {
   $result = array("result" => "error", "message" => $e->getMessage());
   echo(json_encode($result));
}
?>
