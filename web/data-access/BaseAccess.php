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
include_once($_SERVER['DOCUMENT_ROOT'] . "/../php-common/database/DbConnection.php");

Class BaseAccess {
	protected $_dbConnection;
	protected $_adminUserId = 0;
	
	function __construct() {
		$this->_dbConnection = DbConnection::instance();
	}
}
?>