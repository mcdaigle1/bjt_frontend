<?php
$pageName="strategy/strategy";
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
		<link href="/css/strategy.css" rel="stylesheet" type="text/css">    
    <script src="/js/strategy.js"></script>
		<title>BlackJackTrack - Strategy</title>
</head>

<body>
  <div class="hidden_field" id='tab_index'><?php if (array_key_exists("t", $_GET)) {echo $_GET["t"];}; ?></div>

  <div class="main_content">
<?php include("pages/header.php"); ?>
    <div class="page_content">
      <div class="tabs">
        <div class="tab inactive_tab" id="tab_player_strategy">Player Strategy</div>
        <div class="tab inactive_tab" id="tab_dealer_strategy">Dealer Strategy</div>
      </div>
      <div class="tab_section active_section" id="section_player_strategy">
<?php include("pages/strategy/_player_strategy.php"); ?>
      </div>
      
      <div class="tab_section" id="section_dealer_strategy">
<?php include("pages/strategy/_dealer_strategy.php"); ?>
      </div>

    </div>
  </div>
	
</body>
</html>
