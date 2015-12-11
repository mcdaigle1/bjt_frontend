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

/* 
 * Manage bet strategy table access.  Table looks like:
 *    id              INT             NOT NULL PRIMARY KEY AUTO_INCREMENT
 *    create_time     TIMESTAMP       NOT NULL
 *    mod_time        TIMESTAMP       NOT NULL
 *    description     VARCHAR(1024)
 *    status          INT             NOT NULL
 *    player_id       INT             NOT NULL
 *    strategy_json   VARCHAR(2048)   NOT NULL
 *
 * the strategy_json holds the actual strategy.  The JSON looks like:
 *   {
 *     "start_bet" : {"bet" : "minimum"}
 *     "start_bet" : {"bet" : "minimum_times", "multiplier" : "<multiplier value>"}
 *     "win_bet" : {"bet" : "let_ride"}
 *     "win_bet" : {"bet" : "minimum"}
 *     "win_bet" : {"bet" : "increase_by_minimum"}
 *     "win_bet" : {"bet" : "increase_by_minimum_times", "multiplier" : "<multiplier value>"}
 *     "win_bet" : {"bet" : "double_down"}
 *     "win_bet" : {"bet" : "decrease_by_minimum"}
 *     "win_bet" : {"bet" : "decrease_by_minimum_times", "multiplier" : "<multiplier value>"}
 *     "win_bet" : {"bet" : "halve"}
 *     "win_repeat" : {"repeat" : "forever"}
 *     "win_repeat" : {"repeat" : "times", "multiplier" : "<multiplier value>"}
 *     "lose_bet" : {"bet" : "let_ride"}
 *     "lose_bet" : {"bet" : "minimum"}
 *     "lose_bet" : {"bet" : "increase_by_minimum"}
 *     "lose_bet" : {"bet" : "increase_by_minimum_times", "multiplier" : "<multiplier value>"}
 *     "lose_bet" : {"bet" : "double_down"}
 *     "lose_bet" : {"bet" : "decrease_by_minimum"}
 *     "lose_bet" : {"bet" : "decrease_by_minimum_times", "multiplier" : "<multiplier value>"}
 *     "lose_bet" : {"bet" : "halve"}
 *     "lose_repeat" : {"repeat" : "forever"}
 *     "lose_repeat" : {"repeat" : "times", "multiplier" : "<multiplier value>"}
 *   }
 *
 * where the top level hash would have one value each for keys start_bet, win_bet, win_repeat, lose_bet, and lose_repeat
 */
Class BetStrategyAccess extends BaseAccess {

  const DEFAULT_STRATEGY_ID = 1;  

  const STATUS_MUTABLE = 0;
  const STATUS_IMMUTABLE = 1;
  const STATUS_INACTIVE = 2;

  function __construct() {
    parent::__construct();
  }
  
  /**
   */
  function createBetStrategy() {
  }
  
  /**
   * Read a bet rule by ID
   * @param int $id - unique id of player strategy
   * @throws AccessException
   * @return single bet rule
   */
  function readBetStrategy($id) {  
    $sql =  "SELECT * FROM bet_strategy WHERE id = " . $id;
    $strategyArray = $this->_dbConnection->dbQuery($sql);        

    return $this->firstRow($strategyArray);
  }

  /**
   * Find the id, name and description of all bet strategys for given user id
   * @param int $userId - the id we want to search for
   * @throws AccessException
   * @return array of bet strategy infos
   */
  function readBetStrategyInfo($userId) {
    $sql = "SELECT id, name, description FROM bet_strategy WHERE player_id = " .  $userId;

    $strategyInfoArray = $this->_dbConnection->dbQuery($sql);
    return $strategyInfoArray;
  }
  
  /**
   * Select the player strategys for a given user id
   * @param int $userId - the id of the user for which we want to search
   * @return array of strategy arrays for the user
   */
  function readBetStrategyByUserId($userId) {
    $sql = "SELECT * FROM bet_rule where player_id = " . $userId;
    $strategyArray = $this->_dbConnection->dbQuery($sql);

    return $this->firstRow($strategyArray);
  }
  
  function updateBetStrategy($id) {

  }
  
  function deleteBetStrategy() {
    
  }
  
}
?>
