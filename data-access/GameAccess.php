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
include_once("data-access/BaseAccess.php");
include_once("data-access/AccessException.php");

Class GameAccess extends baseAccess {

  const STATUS_NEW = 0;
  const STATUS_RUNNING = 1;
  const STATUS_INTERRUPTED = 2;
  const STATUS_COMPLETE = 2;

	function createGame() {
	}
	
	function readGame($id) {
		$sql =  "SELECT * FROM game WHERE id = " . $id;
		$gameArray = $this->_dbConnection->dbQuery($sql);

    return $this->firstRow($gameArray);
	}

  function readGameDisplayInfo($gameId) {
		$sql =  "SELECT g.*, ps.name as ps_name, ds.name as ds_name FROM game as g ";
    $sql .= "JOIN player_strategy as ps ON g.player_strategy_id = ps.id ";
    $sql .= "JOIN dealer_strategy as ds ON g.dealer_strategy_id = ds.id ";
    $sql .= "WHERE g.id = " . $gameId;
		$gameArray = $this->_dbConnection->dbQuery($sql);

    return $this->firstRow($gameArray);
  }
  
  /**
   * Find all games for a user
   * @param int $playerId - the id of the player whose games we want
   * @return array of games 
   */
  function readGamesForPlayer($playerId) {
    $sql = "SELECT * FROM game WHERE player_id = " . $playerId;

    $gameArray = $this->_dbConnection->dbQuery($sql);
    return $gameArray;
  }
	
	function updateGame($id) {

	}
	
	function deleteGame() {
		
	}
}
?>
