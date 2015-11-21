<?php
$pageName="game/game";
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

if (!Session::isLoggedIn()) {
  header("Location: /pages/home.php");
  exit(); 
}

?>

<html>
<head><meta http-equiv=content-type content="text/html; charset=UTF-8">
<?php include("pages/global_includes.php"); ?>
		<link href="/css/game.css" rel="stylesheet" type="text/css">    
    <script src="/js/game.js"></script>
		<title>BlackJackTrack - Game</title>
</head>

<body>
  <div class="main_content">
<?php include("pages/header.php"); ?>
    <div class="page_content">
      <div class="tabs">
        <div class="tab active_tab" id="tab_play_game">Play Game</div>
        <div class="tab inactive_tab" id="tab_create_game">Create Game</div>
        <div class="tab inactive_tab" id="tab_edit_game">Edit Game</div>
      </div>
      <div class="tab_section active_section" id="section_play_game">
<?php include("pages/game/_play_game.php"); ?>
      </div>
      
      <div class="tab_section" id="section_create_game">
<?php include("pages/game/_create_game.php"); ?>
      </div>

      <div class="tab_section" id="section_edit_game">
<?php include("pages/game/_edit_game.php"); ?>
      </div>
    </div>
  </div>
	
</body>
</html>
