<?php
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
include_once("data-access/PlayerAccess.php");
include_once("data-access/PlayerExistsException.php");

// the user submitted a login
if (array_key_exists('submitLogin', $_POST)) {
  try {
    //verify login
    Session::logIn($_POST['userEmail']);

    $result = array("result" => "success", "message" => "Player logged in");

    echo(json_encode($result));
  } catch (Exception $e) {
    $result = array("result" => "error", "message" => $e->getMessage());
    echo(json_encode($result));
  }
} elseif (array_key_exists('submit_signup', $_POST)) {
  try {
    $playerAccess = new PlayerAccess();
    // see if the player already exists
    $playerRow = $playerAccess->readPlayerByEmail($_POST['user_email']);
    if (sizeof($playerRow) > 0) {
      throw new PlayerExistsException("User " . $_POST['user_email'] . " was found in the db during a signup event");
    }
    // create password salt and encrypt password
    $passwordSalt = Encryption::uniqueMd5(strval(time()));
    $encryptedPassword = Encryption::encryptPassword($_POST['password'], $passwordSalt);
    // create an invitation validation ID
    $validationId = StringUtil::generateUnique(10);
    // create the new player
    $playerAccess->createNewPlayer($_POST['user_email'], $validationId, $passwordSalt, $encryptedPassword);
    Email::sendValidationEmail($_POST['user_email'], $validationId);
  } catch (Exception $e) {
    l_err($e->getMessage());
    MessageBanner::addError("Unexpected error occurred adding " . $_POST['user_email']);
    $result = array("result" => "error", "message" => $e->getMessage());
    echo(json_encode($result));
  }
}
?>
