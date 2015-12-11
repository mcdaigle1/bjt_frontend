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
include_once("data-access/GameAccess.php");
include_once("data-access/PlayerAccess.php");
include_once("data-access/PlayerStrategyAccess.php");

if (array_key_exists('getGames', $_POST)) { 
  try {
    if (Session::isLoggedIn()) {
      $playerAccess = new PlayerAccess();
      $player = $playerAccess->readPlayerByEmail($_SESSION['user_email']);
    } else {
      throw "Player is not logged in";
    }
    
    $gameAccess = new GameAccess();
    $playerGames = $gameAccess->readGamesForPlayer($player["id"]);
    $systemGames = $gameAccess->readGamesForPlayer(PlayerAccess::DEFAULT_PLAYER_ID);

    $result = array("result" => "success", "message" => "Player games retreived", "playerGames" => $playerGames, "systemGames" => $systemGames);

    echo(json_encode($result));
  } catch (Exception $e) {
    $result = array("result" => "error", "message" => $e->getMessage());
    echo(json_encode($result));
  }
} elseif (array_key_exists('getPlayerGames', $_POST)) {
  try {
    if (Session::isLoggedIn()) {
      $playerAccess = new PlayerAccess();
      $player = $playerAccess->readPlayerByEmail($_SESSION['user_email']);
    } else {
      throw "Player is not logged in";
    }

    $gameAccess = new GameAccess();
    $playerGames = $gameAccess->readGamesForPlayer($player["id"]);

    $result = array("result" => "success", "message" => "Player games retreived", "playerGames" => $playerGames);

    echo(json_encode($result));
  } catch (Exception $e) {
    $result = array("result" => "error", "message" => $e->getMessage());
    echo(json_encode($result));
  }
} elseif (array_key_exists('getGame', $_POST)) { 
  try {
    $gameAccess = new GameAccess();
    $game = $gameAccess->readGame($_POST['getGame']);
    
    $result = array("result" => "success", "message" => "Game retreived", "game" => $game);
    echo(json_encode($result));
  } catch (Exception $e) {
    $result = array("result" => "error", "message" => $e->getMessage());
    echo(json_encode($result));
  }
} elseif (array_key_exists('getGameDisplayInfo', $_POST)) { 
  try {
    if (!array_key_exists('gameId', $_POST)) {
      throw new Exception("gameId must be provided when getting game display info");
    }

    $gameAccess = new GameAccess();
    $gameDisplayInfo = $gameAccess->readGameDisplayInfo($_POST["gameId"]);

    $result = array("result" => "success",
                    "message" => "Game display info retreived",
                    "gameDisplayInfo" => $gameDisplayInfo);
    echo(json_encode($result));
  } catch (Exception $e) {
    $result = array("result" => "error", "message" => $e->getMessage());
    echo(json_encode($result));
  }
} elseif (array_key_exists('getAllGameInfo', $_POST)) { 
  try {
    if (!array_key_exists('gameId', $_POST)) {
      throw new Exception("gameId must be provided when getting all game info");
    }

    $gameAccess = new GameAccess();
    $game = $gameAccess->readGame($_POST["gameId"]);

    $playerStrategyAccess = new PlayerStrategyAccess();
    $playerStrategy = $playerStrategyAccess->readPlayerStrategy($game["player_hit_strategy_id"]);

    $dealerStrategyAccess = new DealerStrategyAccess();
    $dealerStrategy = $dealerStrategyAccess->readDealerStrategy($game["dealer_hit_strategy_id"]);
    
//    $betStrategyAccess = new BettStrategyAccess();
//    $bettStrategy = $betStrategyAccess->readBetStrategy($game["bet_strategy_id"]);
    
    $result = array("result" => "success", 
                    "message" => "All game info retreived", 
                    "game" => $game,
                    "playerStrategyAccess" => $playerStrategyAccess,
                    "dealerStrategyAccess" => $dealerStrategyAccess);
    echo(json_encode($result));
  } catch (Exception $e) {
    $result = array("result" => "error", "message" => $e->getMessage());
    echo(json_encode($result));
  }
} else { 
  $result = array("result" => "error", "message" => "Could not find valid action for gameController");
}
?>
