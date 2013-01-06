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
include_once($_SERVER['DOCUMENT_ROOT'] . "/../php-common/logging/Logging.php");
include_once($_SERVER['DOCUMENT_ROOT'] . "/../php-common/session/Session.php");
include_once($_SERVER['DOCUMENT_ROOT'] . "/../php-common/security/Encryption.php");
include_once($_SERVER['DOCUMENT_ROOT'] . "/../php-common/utilities/StringUtil.php");
include_once($_SERVER['DOCUMENT_ROOT'] . "/../php-common/utilities/ArrayUtil.php");
include_once($_SERVER['DOCUMENT_ROOT'] . "/../php-common/email/Email.php");
include_once($_SERVER['DOCUMENT_ROOT'] . "/../php-common/display/MessageBanner.php");
include_once($_SERVER['DOCUMENT_ROOT'] . "/../php-common/exceptions/DuplicateEntryException.php");
include_once($_SERVER['DOCUMENT_ROOT'] . "/../php-common/exceptions/MailException.php");

$productName = "BlackJackTrack";
$fromEmailAddress = "webmaster@blackjacktrack.com";
$replyEmailAddress = "webmaster@blackjacktrack.com";
?>