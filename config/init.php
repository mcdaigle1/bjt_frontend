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
include_once("logging/Logging.php");
include_once("session/Session.php");
include_once("security/Encryption.php");
include_once("utilities/StringUtil.php");
include_once("utilities/ArrayUtil.php");
include_once("email/Email.php");
include_once("display/MessageBanner.php");
include_once("exceptions/DuplicateEntryException.php");
include_once("exceptions/MailException.php");

$productName = "BlackJackTrack";
$fromEmailAddress = "webmaster@blackjacktrack.com";
$replyEmailAddress = "webmaster@blackjacktrack.com";
?>
