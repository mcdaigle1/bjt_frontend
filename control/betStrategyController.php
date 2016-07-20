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
include_once("data-access/BetStrategyAccess.php");

$valid_actions = array("createBetStrategy", "getBetStrategyInfo");
$action = $_POST["action"];

if (!in_array($action, $valid_actions)) {
  $result = array("result" => "error", "message" => "Invalid action to betStrategyController: " . $action);
  echo(json_encode($result));
  return;
}

try {
  switch ($action) {
    case "createBetStrategy":
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
    
      $betStrategyAccess = new BetStrategyAccess();
      $betStrategyId = $betStrategyAccess->createBetStrategy($_POST["strategySetName"], $_POST["strategySetDescription"], $player["id"], $_POST["strategySet"]);

      $result = array("result" => "success", "message" => "Bet strategy created");

      echo(json_encode($result));
      break;
    case "getBetStrategyInfo":
      if (Session::isLoggedIn()) {
        $playerAccess = new PlayerAccess();
        $player = $playerAccess->readPlayerByEmail($_SESSION['user_email']);
      }

      $betStrategyAccess = new BetStrategyAccess();
      $betStrategyInfo = $betStrategyAccess->readBetStrategyInfo($player["id"]);
      $systemStrategyInfo = $betStrategyAccess->readBetStrategyInfo(PlayerAccess::DEFAULT_PLAYER_ID);

      $result = array("result" => "success",
                      "message" => "Bet strategy info retreived",
                      "betStrategyInfo" => $betStrategyInfo,
                      "systemStrategyInfo" => $systemStrategyInfo);
      echo(json_encode($result));
      break;
  }
} catch (Exception $e) {
   $result = array("result" => "error", "message" => $e->getMessage());
   echo(json_encode($result));
}
?>
