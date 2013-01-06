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
include_once($_SERVER['DOCUMENT_ROOT'] . "/data-access/PlayerExistsException.php");

Class PlayerAccess extends BaseAccess {
	const STATUS_NEW = 0;
	const STATUS_INVITED = 1;
	const STATUS_VERIFIED = 2;
	
	function __construct() {
		parent::__construct();
	}
	
	/**
	 * Create a player in the database 
	 * @param string $email - the email of the user
	 * @param int $status - status of the player
	 * @param string $validationId - the id used in the signup validation email
	 * @param string $passwordSalt - the salt user to encrypt the password
	 * @param string $encryptedPassword - encrypted password
	 * @throws PlayerExistsException
	 * @throws AccessException
	 */
	function createPlayer($email, $status, $validationId, $passwordSalt, $encryptedPassword) {
		$sql = 
			"INSERT INTO player (create_time, mod_time, " .
			"email, status, validation_id, password_salt, password_md5) " .
			"values (now(), now(), " .
			"'" . mysql_real_escape_string($email) . "', " .
			mysql_real_escape_string($status) . ", " .
			"'" . mysql_real_escape_string($validationId) . "', " .
			"'" . mysql_real_escape_string($passwordSalt) . "', " .
			"'" . mysql_real_escape_string($encryptedPassword) . "')";
		try {
			$rowsModified = $this->_dbConnection->dbModify($sql);
		} catch (DuplicateEntryException $dee) { 
			$message = "Player " . $email . " already exists";
			Throw new PlayerExistsException($dee->getMessage(), $dee->getCode(), $dee);
		} catch (DbException $dbe) {
			$message = "Error inserting player " . $email;
			Throw new AccessException($message, $dbe->getCode(), $dbe);
		}
		if ($rowsModified != 1) {
			throw new AccessException("Expected to modify one row but actually modified: " . 
				$rowsModified . " SQL: " . $sql);
		}
	}
	
	/**
	 * Create a new player with status set to STATUS_NEW
	 * @param unknown_type $email - the email of the user
	 * @param unknown_type $validationId - the id used in the signup validation email 
	 * @param unknown_type $passwordSalt - the salt user to encrypt the password
	 * @param unknown_type $passwordMd5 - encrypted password
	 */
	function createNewPlayer($email, $validationId, 
		$passwordSalt, $passwordMd5) {
		$this->createPlayer($email, self::STATUS_NEW, $validationId, $passwordSalt, $encryptedPassword);	
	}
	
	function readPlayer($id) {
		$sql =  "SELECT * FROM player WHERE id = " . $id;
		try {
			$playerArray = $this->_dbConnection->dbQuery($sql);
		} catch (DbException $dbe) {
			$message = "Error reading player " . $id;
			Throw new AccessException($message, $dbe->getCode(), $dbe);
		}
		if (array_size($playerArray) > 0) {
			return $playerArray[1]; 
		} else {
			return array();
		}
	}
	
	/**
	 * Read player from database by email
	 * @param string $email - the email to select by
	 */
	function readPlayerByEmail($email) {
		$sql =  "SELECT * FROM player WHERE email = '" . $email . "'";
		$playerArray = $this->_dbConnection->dbQuery($sql);
		return $playerArray;
	}
	
	function updatePlayer($id) {

	}
	
	function deletePlayer() {
		
	}
}
?>