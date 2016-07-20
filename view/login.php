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
include_once("config/init.php");
include_once("data-access/PlayerAccess.php");
include_once("data-access/PlayerExistsException.php");
?>

<html>
  <head><meta http-equiv=content-type content="text/html; charset=UTF-8">
<?php include("view/global_includes.php"); ?>
    <link href="/css/login.css" rel="stylesheet" type="text/css">      
    <script src="/js/login.js"></script>
    <title>BlackJackTrack - Login</title>
  </head>

  <body>

  <div class="main_content">
<?php 
   // show the header
  include("view/header.php"); 
?>              
<div class='login_title'>Log In</div>
<div>
  <div class='login_label_left'>User Email:</div>
  <div class='login_input'>
    <input class='login_text_input' type='text' name='user_email' id='login_user_email'>
  </div>
</div>
<div>
  <div class='login_label_left'>Password:</div>
  <div class='login_password_input'>
    <input class='login_text_input' type='password' name='password' id='login_password'>
  </div>
</div>
<div class='login_submit_button'>
  <input type='submit' value='Log In' id='login_button'>
</div>

<div class='create_account_title'>Create Account</div>
<div>      
  <div class='login_label_left'>User Email:</div>
  <div class='login_input'>
    <input class='login_text_input' type='text' name='user_email' id='login_create_user_email'>
  </div>
</div>
<div>
  <div class='login_label_left'>Verify User Email:</div>
  <div class='login_input'>
    <input class='login_text_input' type='text' name='user_email2' id='login_create_user_email2'>
  </div>
</div>
<div>
  <div class='login_label_left'>Password:</div>
  <div class='login_password_input'>
    <input class='login_text_input' type='password' name='password' id='login_create_password'>
  </div>
<div>
<div class='login_submit_button'>
  <input type='submit' value='Create Account' id='login_create_button'>
</div>
