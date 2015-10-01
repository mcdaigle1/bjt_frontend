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

/**
 * 
 * Player Strategy utilities
 * @author mdaigle
 *
 */
Class StrategyUtil {
	
  /**
   * Get the array of first card abbreviations
   * @return array of first card abbreviations
   */
  static function getFirstCardAbbrevArray() {
    return array("A", "2", "3", "4", "5", "6", "7", "8", "9", "10");
  }

  /**
   * Get the first card abbreviation by index
   * @param int index of first card abbreviation
   * @return string holding first card abbreviation
   */
  static function getFirstCardAbbrev($i) {
    $dhaArray = self::getDealerHandAbbrevArray();
        return $dhaArray[$i];
  }
}

?>
