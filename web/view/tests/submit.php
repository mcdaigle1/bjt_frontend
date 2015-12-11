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
$pageName="submit";
include("database/DbConnection.php");
include("view/header.php"); 
include("view/menu.php");

$DOWNLOAD_SIZE_MB = 5;
?>

<html>
<head><meta http-equiv=content-type content="text/html; charset=UTF-8">
  <link href="/css/main.css" rel="stylesheet" type="text/css">    
  <title>Winspiration</title>
</head>
<body>

<div class="main_content">
<?php
$show_form = FALSE;
if (isset($_POST['submit'])) { 
	if ($_FILES["file"]["error"] > 0) {
    	echo "<div class='error_message'>Error: Return Code - " . $_FILES["file"]["error"] . "</div>";
  		$show_form = TRUE;		
	} elseif ($_FILES["file"]["size"] > (1048576 * $DOWNLOAD_SIZE_MB)) {
		echo "<div class='error_message'>Error: File cannot exceed $DOWNLOAD_SIZE_MB MB</div>";
		$show_form = TRUE;
	} elseif (!strcmp("jpeg", $_FILES["file"]["name"]) && !strcmp("jpeg", $_FILES["file"]["name"])) {
		echo "<div class='error_message'>Error: Only jpeg files are allowed : " . $_FILES["file"]["name"] . "</div>";
		$show_form = TRUE;
	} else {		
    	echo "Upload: " . $_FILES["file"]["name"] . "<br />";
    	echo "Type: " . $_FILES["file"]["type"] . "<br />";
    	echo "Size: " . ($_FILES["file"]["size"] / 1024) . " Kb<br />";
    	echo "Temp file: " . $_FILES["file"]["tmp_name"] . "<br />";

      	move_uploaded_file($_FILES["file"]["tmp_name"], "/var/www/upload/" . $_FILES["file"]["name"]);
      	echo "Stored in: " . "upload/" . $_FILES["file"]["name"];
	}
} 

if (!isset($_POST['submit']) || $show_form == TRUE) {	
?>

<!-- http://www.sitepoint.com/style-web-forms-css/ -->

<form action="<?php echo $_SERVER['PHP_SELF'];?>" method="post" enctype="multipart/form-data">
	<div class="form_row">
		<div class="form_label"><label class="form_label" for="email">Your Email:</label></div>
		<input type="text" name="email" id="email" />
	</div>
	<div class="form_row">
		<div class="form_label"><label class="form_label" for="file">Filename:</label></div>
		<input type="file" name="file" id="file" />
	</div>	
	<input type="submit" name="submit" value="Submit" />
</form>

<?php


}
?> 
</div>
</body>
</html>
