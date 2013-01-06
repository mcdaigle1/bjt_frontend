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
include_once($_SERVER['DOCUMENT_ROOT'] . "/config/init.php");
include_once($_SERVER['DOCUMENT_ROOT'] . "/data-access/BaseAccess.php");
include_once($_SERVER['DOCUMENT_ROOT'] . "/data-access/AccessException.php");

Class PlayerHitRuleAccess extends BaseAccess {
	
	function __construct() {
		parent::__construct();
	}
	
	function createPlayerHitRule() {
	}
	
	/**
	 * Read a player hit rule by ID
	 * @param int $id - unique id of player hit rule
	 * @throws AccessException
	 * @return array of single hit rule data
	 */
	function readPlayerHitRule($id) {	
		try {
			$sql =  "SELECT * FROM player_hit_rule WHERE id = " . $id;
			$ruleArray = $this->_dbConnection->dbQuery($sql);				
		} catch (DbException $de) {
			throw new AccessException($de->getMessage());
		}
		return $ruleArray[1];
	}
	
	function updatePlayerHitRule($id) {

	}
	
	function deletePlayerHitRule() {
		
	}
	
	/**
	 * Select the player hit rules for a given user id
	 * @param int $userId - the id of the user for which we want to search
	 * @return array of hit rule arrays for the user
	 */
	function readPlayerHitRuleByUserId($userId) {
		// TODO - make it actually select by ID
		try {
			$sql = "SELECT * FROM player_hit_rule";
			$ruleArray = $this->_dbConnection->dbQuery($sql);
		} catch (DbException $de) {
			throw new AccessException($de->getMessage());
		}
		return $ruleArray[1];
	}
	
	/**
	 * Find the names of all hit rules for given user id
	 * @param int $userId - the id we want to search for
	 * @throws AccessException
	 * @return array of hit rule names
	 */
	function readAvailableHitRuleNames($userId) {		
		try {
			$sql =  "SELECT name FROM player_hit_rule WHERE player_id = " . 
				$this->_adminUserId . " OR player_id = " . $userId;
		
			$nameArray = $this->_dbConnection->dbSelect($sql, "name");
		} catch (DbException $de) {
			throw new AccessException($de->getMessage());
		}
		return $nameArray;	 
	}
}
?>