<?php
$pageName="home";
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
include_once($_SERVER['DOCUMENT_ROOT'] . "/data-access/PlayerHitRuleAccess.php");

// Initialize a session. This call either creates
// a new session or re-establishes an existing one.
session_start();
?>

<html>
	<head><meta http-equiv=content-type content="text/html; charset=UTF-8">
		<link rel="SHORTCUT ICON" HREF="/images/favicon.ico">
		<link href="/css/main.css" rel="stylesheet" type="text/css">    
		<title>BlackJackTrack</title>
	</head>

  	<body>

	<div class="main_content">
	<?php
        include($_SERVER['DOCUMENT_ROOT'] . "/pages/header.php");  
	?>
	<a href='/pages/view_player_hit_rule.php?phr_id=1'>view player hit rule 1</a>
    
    
	</div>
	
	</body>
</html>


