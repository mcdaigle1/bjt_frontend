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

?>

<div class="main_logo">
	<a href="/pages/home.php"><img src="/images/bjt_header.jpg"></a>
<?php
   	session_start();

	include($_SERVER['DOCUMENT_ROOT'] . "/pages/menu.php");
	include($_SERVER['DOCUMENT_ROOT'] . "/pages/message_banner.php");
?>
</div>
