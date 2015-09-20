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

Class PlayerStrategyAccess extends BaseAccess {

  const DEFAULT_STRATEGY_ID = 1;  

  const STATUS_MUTABLE = 0;
  const STATUS_IMMUTABLE = 1;
  const STATUS_INACTIVE = 2;

  function __construct() {
    parent::__construct();
  }
  
  /**
   */
  function createPlayerStrategy($name, $description, $playerId, $strategySet) {
    if(intval($playerId) == 0) {
      throw new Exception("Player ID: ". $playerId . " should be an integer");
    }
    $strategySetMd5 = md5($strategySet);

    $sql =
      "INSERT INTO player_strategy (create_time, mod_time, " .
      "name, description, status, player_id, strategy_md5, strategy_set) " .
      "values (now(), now(), " .
      "'" . mysql_real_escape_string($name) . "', " .
      "'" . mysql_real_escape_string($description) . "', " .
      self::STATUS_MUTABLE . ", " .
      $playerId . ", " .
      "'" . mysql_real_escape_string($strategySetMd5) . "', " .
      "'" . mysql_real_escape_string($strategySet) . "')";
    $playerStrategyId = $this->_dbConnection->dbInsert($sql);
    return $playerStrategyId;
  }
  
  /**
   * Read a player strategy by ID
   * @param int $id - unique id of player strategy
   * @throws AccessException
   * @return array of single strategy data
   */
  function readPlayerStrategy($id) {  
    $sql =  "SELECT * FROM player_strategy WHERE id = " . $id;
    $strategyArray = $this->_dbConnection->dbQuery($sql);        

    return $this->firstRow($strategyArray);
  }
  
  function updatePlayerStrategy($id) {

  }
  
  function deletePlayerStrategy() {
    
  }
  
  /**
   * Select the player strategys for a given user id
   * @param int $userId - the id of the user for which we want to search
   * @return array of strategy arrays for the user
   */
  function readPlayerStrategyByUserId($userId) {
    $sql = "SELECT * FROM player_strategy where player_id = " . $userId;
    $strategyArray = $this->_dbConnection->dbQuery($sql);

    return $this->firstRow($strategyArray);
  }
  
  /**
   * Find the names of all strategys for given user id
   * @param int $userId - the id we want to search for
   * @throws AccessException
   * @return array of strategy names
   */
  function readPlayerStrategyInfo($userId) {    
    $sql = "SELECT id, name, description  FROM player_strategy WHERE player_id = " .  $userId;
    
    $strategyInfoArray = $this->_dbConnection->dbQuery($sql);
    return $strategyInfoArray;   
  }
}
?>
