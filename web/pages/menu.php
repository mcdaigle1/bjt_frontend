<?php
/***********************************************************************
 * Copyright 2011 Blue Cask Software. All rights reserved.
 *                                                                                                                       
 * THIS PROGRAM IS CONFIDENTIAL AND PROPRIETARY TO BLUE CASK
 * SOFTWARE.  Any unauthorized use, reproduction, modification, or
 * disclosure of this program is strictly prohibited without the
 * express written permission of an authorized representative of
 * Blue Cask Software..
 ************************************************************************/
include_once("display/MenuText.php");
include_once("session/Session.php");
?>


<SCRIPT LANGUAGE="JavaScript">
<!-- hide from none JavaScript Browsers 

<?php 
	$menu = new MenuText();
?>

// End Hiding -->
</SCRIPT>


<div class="menu_bar">
<?php
	if (Session::isLoggedIn()) {
		$menu->menuItem("HOME", "home", $pageName);
   	$menu->menuItem("GAMES", "game/game", $pageName);
   	$menu->menuItem("PLAYER", "player/player", $pageName);
   	$menu->menuItem("DEALER", "dealer/dealer", $pageName);
   	$menu->menuItem("BETTING", "betting/betting", $pageName);
		$menu->menuItem("LOGOUT", "logout", $pageName);
	} else {
		$menu->menuItem("HOME", "home", $pageName, true);
   	$menu->menuItem("GAMES", "game/game", $pageName, true);
   	$menu->menuItem("PLAYER", "player/player", $pageName, true);
   	$menu->menuItem("DEALER", "dealer/dealer", $pageName, true);
   	$menu->menuItem("BETTING", "betting/betting", $pageName, true);
		$menu->menuItem("LOGIN", "login", $pageName);
	}
?>
</div>
