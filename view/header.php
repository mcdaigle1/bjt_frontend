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
  <div class="message_box" id="message_box">
  <div class="message_box_inner_border">
    <div class="message_content" id="message_content"></div>
    <div class="message_x" id="message_x">
      <img class="message_x_image" src="/images/x_25_25.jpg">
    </div>
  </div>
  </div>
    
	<a href="/view/home.php"><img src="/images/bjt_header.jpg"></a>
<?php
  if (!Session::isLoggedIn()) {
    if (session_status() == PHP_SESSION_NONE) {
      session_start();
    }
  }

	include("view/menu.php");
	include("view/message_banner.php");
?>
</div>
