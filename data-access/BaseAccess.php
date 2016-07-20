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
include_once("config/init.php");
include_once("database/DbConnection.php");

Class BaseAccess {
	protected $_dbConnection;
	protected $_adminUserId = 0;
 
	function __construct() {
    $env_type = getenv("ENVIRONMENT_TYPE");

    if (strcmp($env_type, "development") == 0) {
      include("config/blackjack_conf_dev.php");
    } else {
      include("config/blackjack_conf.php");
    }

		$this->_dbConnection = DbConnection::instance($dbHost, $dbName, $dbUser, $dbPassword);
	}

  function firstRow($resultArray) {
    if (sizeof($resultArray) > 0) {
      return array_values($resultArray)[0];
    } else {
      return array();
    }
  }
}
?>
