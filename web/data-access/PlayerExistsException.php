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
include_once($_SERVER['DOCUMENT_ROOT'] . "/../php-common/exceptions/BaseException.php");

class PlayerExistsException extends BaseException {
	public function errorMessage() {
		//error message
		return formatError("Player Exists");
	}
}

?>