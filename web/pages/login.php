<?php
$pageName="login";
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
include_once($_SERVER['DOCUMENT_ROOT'] . "/data-access/PlayerAccess.php");
include_once($_SERVER['DOCUMENT_ROOT'] . "/data-access/PlayerExistsException.php");
?>

<html>
  <head><meta http-equiv=content-type content="text/html; charset=UTF-8">
    <link rel="SHORTCUT ICON" HREF="/images/favicon.ico">
    <link href="/css/main.css" rel="stylesheet" type="text/css"> 
    <link href="/css/login.css" rel="stylesheet" type="text/css">      
    <title>BlackJackTrack</title>
  </head>

  <body>

  <div class="main_content">
    <?php 
    	// show the header
        include($_SERVER['DOCUMENT_ROOT'] . "/pages/header.php"); 
            	
        // the user submitted a login
        if (array_key_exists('submit_login', $_POST)) { 
        	try {
        		//verify login
        		Session::logIn();
        		header("Location: /pages/home.php");
        	} catch (BaseException $be) {
        		
        	} catch (Exception $e) {
        		
        	}
        } elseif (array_key_exists('submit_signup', $_POST)) { 
        	try {
        		$playerAccess = new PlayerAccess();
        		// see if the player already exists
        		$playerRow = $playerAccess->readPlayerByEmail($_POST['user_email']);
	        	if (sizeof($playerRow) > 0) {
	        		throw new PlayerExistsException("User " . $_POST['user_email'] . 
	        			" was found in the db during a signup event");
	        	}
	        	// create password salt and encrypt password
	        	$passwordSalt = Encryption::uniqueMd5(strval(time()));
	        	$encryptedPassword = 
	        		Encryption::encryptPassword($_POST['password'], $passwordSalt);
	        	// create an invitation validation ID	
	        	$validationId = StringUtil::generateUnique(10);
	        	// create the new player
        		$playerAccess->createNewPlayer($_POST['user_email'], $validationId, $passwordSalt, 
        														$encryptedPassword);
        		Email::sendValidationEmail($_POST['user_email'], $validationId);
        	} catch (PlayerExistsException $pee) {
				l_warn($pee->getMessage());
				MessageBanner::addWarning("Player account " . $_POST['user_email'] . " already exists.");
        		header("Location: " . $_SERVER['PHP_SELF']);
        		exit;
        	} catch (AccessException $ae) {
				l_err($ae->getMessage());
				MessageBanner::addError("Database error occurred adding " . $_POST['user_email']);
				header("Location: " . $_SERVER['PHP_SELF']);
				exit;
        	} catch (BaseException $be) {
        		l_err($be->getMessage());
				MessageBanner::addError("General error create account " . $_POST['user_email']);
				header("Location: " . $_SERVER['PHP_SELF']);
				exit;
        	} catch (Exception $e) {
        		l_err($e->getMessage());
				MessageBanner::addError("Unexpected error occurred adding " . $_POST['user_email']);
				header("Location: " . $_SERVER['PHP_SELF']);
				exit;
        	}
        	header("Location: /pages/home.php");
        } else {
        	// show login forms 
	        print "<div class='login_title'>";
			print "Log In";
			print "</div>";
		
	        print "<form method = 'POST' action = " . $_SERVER['PHP_SELF'] . 
	        	" name = 'login_form' onsubmit = 'return validateLoginForm()'>"; 	  
		        print "<div class='login_text'>";
		        	print "User Email:";
		        print "</div>";
		        print "<div class='login_input'>";
		        	print "<input class='login_text_input' type='text' name='user_email'>";
		        print "</div>";
		        
		        print "<div class='login_text'>";
		        	print "Password:";
		        print "</div>";
		        print "<div class='login_password_input'>";
		        	print "<input class='login_text_input' type='password' name='password'>";
		        print "</div>";
		        
		        print "<div class='login_submit_button'>";
		        	print "<input type='submit' name='Submit' value='Log In'>";
		       	print "</div>";
				print "<input type='hidden' name='submit_login' value='1'/>";
			print "</form>";
			
			print "<div class='create_account_title'>";
			print "Create Account";
			print "</div>";
			
			print "<form method = 'POST' action = " . $_SERVER['PHP_SELF'] . 
	        	" name = 'create_form' onsubmit = 'return validateCreateAccountForm()'>"; 	  
				print "<div class='login_text'>";
		        	print "User Email:";
		        print "</div>";
		        print "<div class='login_input'>";
		        	print "<input class='login_text_input' type='text' name='user_email'>";
		        print "</div>";
		        
		        print "<div class='login_text'>";
		        	print "Verify User Email:";
		        print "</div>";
		        print "<div class='login_input'>";
		        	print "<input class='login_text_input' type='text' name='user_email2'>";
		        print "</div>";
		        
		        print "<div class='login_text'>";
		        	print "Password:";
		        print "</div>";
		        print "<div class='login_password_input'>";
		        	print "<input class='login_text_input' type='password' name='password'>";
		        print "</div>";
		        
		        print "<div class='login_submit_button'>";
		        	print "<input type='submit' name='Submit' value='Create Account'>";
		       	print "</div>";
				print "<input type='hidden' name='submit_signup' value='1'/>";
			print "</form>";
        }
	?>
  </div>

  </body>
</html>


