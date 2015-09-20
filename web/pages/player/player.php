<?php
$pageName="player/player";
/***********************************************************************
 * Copyright 2015 Blue Cask Software. All rights reserved.
 *                                                                                                                       
 * THIS PROGRAM IS CONFIDENTIAL AND PROPRIETARY TO BLUE CASK
 * SOFTWARE.  Any unauthorized use, reproduction, modification, or
 * disclosure of this program is strictly prohibited without the
 * express written permission of an authorized representative of
 * Blue Cask Software..
 ************************************************************************/
include_once("config/init.php");

if (!Session::isLoggedIn()) {
  header("Location: /pages/home.php");
  exit(); 
}

?>

<html>
<head><meta http-equiv=content-type content="text/html; charset=UTF-8">
		<link rel="SHORTCUT ICON" HREF="images/favicon.ico">
		<link href="/css/main.css" rel="stylesheet" type="text/css">    
		<link href="/css/strategy.css" rel="stylesheet" type="text/css">    
		<link href="/css/tabs.css" rel="stylesheet" type="text/css">    
    <script src="http://ajax.googleapis.com/ajax/libs/jquery/1.11.2/jquery.min.js"></script>
    <script src="/js/strategy.js"></script>
    <script src="/js/tabs.js"></script>
		<title>BlackJackTrack</title>
</head>

<body>
  <div class="main_content">
<?php include("pages/header.php"); ?>
    <div class="page_content">
      <div class="tabs">
        <div class="tab active_tab" id="tab_view_player_strategy">View Player Strategy</div>
        <div class="tab inactive_tab" id="tab_create_player_strategy">Create Player Strategy</div>
        <div class="tab inactive_tab" id="tab_edit_player_strategy">Edit Player Strategy</div>
      </div>
      <div class="tab_section active_section" id="section_view_player_strategy">
<?php include("pages/player/_view_player_strategy.php"); ?>
      </div>
      <div class="tab_section" id="section_create_player_strategy">
<?php include("pages/player/_create_player_strategy.php"); ?>
      </div>
      
      <div class="tab_section" id="section_edit_player_strategy">
      </div>

    </div>
  </div>
	
</body>
</html>
