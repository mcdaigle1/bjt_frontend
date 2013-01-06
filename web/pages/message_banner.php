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
include_once($_SERVER['DOCUMENT_ROOT'] . "/../php-common/display/MessageBanner.php");

$errorArray = MessageBanner::getErrorList();
$warningArray = MessageBanner::getWarningList();
$infoArray = MessageBanner::getInfoList();

if (sizeof($errorArray) > 0) {
	print "<div class='error_banner'>";
	foreach($errorArray as $error) {
		print "<div class='error_line'>" . $error . "</div>";
	}
	print "</div>";
}

if (sizeof($warningArray) > 0) {
	print "<div class='warning_banner'>";
	foreach($warningArray as $warning) {
		print "<div class='error_line'>" . $warning . "</div>";
	}
	print "</div>";
}

if (sizeof($infoArray) > 0) {
	print "<div class='info_banner'>";
	foreach($infoArray as $info) {
		print "<div class='error_line'>" . $info . "</div>";
	}
	print "</div>";
}

MessageBanner::clearAll();


?>
