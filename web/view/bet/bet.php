<?php
$pageName="bet/bet";
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
  header("Location: /view/home.php");
  exit(); 
}

?>

<html>
<head><meta http-equiv=content-type content="text/html; charset=UTF-8">
<?php include("view/global_includes.php"); ?>
		<link href="/css/bet.css" rel="stylesheet" type="text/css">    
    <script src="/js/bet.js"></script>
		<title>BlackJackTrack - Betting</title>
</head>

<body>
  <div class="main_content">
<?php include("view/header.php"); ?>
    <div class="page_content">
      <div class="tabs">
        <div class="tab active_tab" id="tab_bet_strategy">Betting Strategy</div>
      </div>
      <div class="tab_section active_section" id="section_bet_strategy">
<?php include("view/bet/_bet_strategy.php"); ?>
      </div>
    </div>
  </div>
</body>
</html>
