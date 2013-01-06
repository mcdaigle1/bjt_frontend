<?php
$pageName="logout";
/***********************************************************************
 * Copyright 2012 Blue Cask Software. All rights reserved.
 *                                                                                                                       
 * THIS PROGRAM IS CONFIDENTIAL AND PROPRIETARY TO BLUE CASK
 * SOFTWARE.  Any unauthorized use, reproduction, modification, or
 * disclosure of this program is strictly prohibited without the
 * express written permission of an authorized representative of
 * Blue Cask Software..
 ************************************************************************/

?>

<html>
  <head><meta http-equiv=content-type content="text/html; charset=UTF-8">
    <link href="/css/main.css" rel="stylesheet" type="text/css"> 
    <link href="/css/login.css" rel="stylesheet" type="text/css">      
    <title>BlackJackTrack</title>
  </head>

  <body>

  <div class="main_content">
    <?php
        Session::logOut();
        header("Location: /pages/home.php");
	?>
  </div>

  </body>
</html>


