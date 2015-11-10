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
include_once("util/StrategyUtil.php");

/**
 * Player Strategy utilities
 */
Class PlayerStrategyUtil extends StrategyUtil {
	
  /*
   * Get the array of strategy abbreviations
   * @return array of strategy abbreviations
   */
  static function getPlayerStrategyAbbrevArray() {
    return array("SR", "HT", "ST", "DH", "SP", "DS");
  }

  /**
   * Get the array of hand abbreviations
   * @return array of hand abbreviations
   */
  static function getHandAbbrevArray() {
    return array("5", "6", "7", "8", "9", "10", "11", "12", "13", "14",
    "15", "16", "17", "18", "19", "20", "A,2", "A,3", "A,4", "A,5", "A,6", "A,7",
    "A,8", "A,9", "A,10", "A,A", "2,2", "3,3", "4,4", "5,5", "6,6", "7,7", "8,8",
    "9,9", "10,10");
  }

  /**
   * Get the hand abbreviation by index
   * @param int index of hand abbreviation
   * @return string holding hand abbreviation
   */
  static function getHandAbbrev($i) {
    $phaArray = self::getHandAbbrevArray();
        return $phaArray[$i];
  }
}
?>
