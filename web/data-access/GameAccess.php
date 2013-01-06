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

Class GameAccess extends baseAccess {
	function createGame() {
	}
	
	function readGame($id) {
		$sql =  "SELECT * FROM game WHERE id = " . $id;
		$gameArray = $dbConnection->dbQuery($sql);
		return $gameArray[1];
	}
	
	function updateGame($id) {

	}
	
	function deleteGame() {
		
	}
}
?>