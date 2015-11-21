<?php
$pageName="betting/betting";
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
<?php include("pages/global_includes.php"); ?>
		<link href="/css/betting.css" rel="stylesheet" type="text/css">    
    <script src="/js/betting.js"></script>
		<title>BlackJackTrack - Betting</title>
</head>

<body>
  <div class="main_content">
<?php include("pages/header.php"); ?>
    <div class="page_content">
      <div class="tabs">
        <div class="tab active_tab" id="tab_betting_strategy">Betting Strategy</div>
      </div>
      <div class="tab_section active_section" id="section_betting_strategy">
<?php include("pages/betting/_betting.php"); ?>
      </div>
    </div>
  </div>
</body>
</html>
