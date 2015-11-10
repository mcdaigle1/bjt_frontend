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

?>

<div class="main_logo">
  <div class="message_box" id="message_box">hello</div>
	<a href="/pages/home.php"><img src="/images/bjt_header.jpg"></a>
<?php
  if (!Session::isLoggedIn()) {
    if (session_status() == PHP_SESSION_NONE) {
      session_start();
    }
  }

	include("pages/menu.php");
	include("pages/message_banner.php");
?>
</div>
