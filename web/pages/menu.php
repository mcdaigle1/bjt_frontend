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
include_once("/var/www/php-common/display/Menu.php");
include_once("/var/www/php-common/session/Session.php");
?>


<SCRIPT LANGUAGE="JavaScript">
<!-- hide from none JavaScript Browsers 

<?php 

	$menu = new Menu();

	$menu->preloadImage("home");
	$menu->preloadImage("games");
	$menu->preloadImage("reports");
	$menu->preloadImage("login");
	$menu->preloadImage("logout");
?>

// End Hiding -->
</SCRIPT>


<div class="menu_bar">
<?php
	if (Session::isLoggedIn()) {
		$menu->menuItem("home", $pageName);
    	$menu->menuItem("games", $pageName);
		$menu->menuItem("reports", $pageName);
		$menu->menuItem("about_us", $pageName);
		$menu->menuItem("logout", $pageName);
	} else {
		$menu->menuItem("home", $pageName, true);
    	$menu->menuItem("games", $pageName, true);
		$menu->menuItem("reports", $pageName, true);
		$menu->menuItem("about_us", $pageName);
		$menu->menuItem("login", $pageName);
	}
?>
</div>
