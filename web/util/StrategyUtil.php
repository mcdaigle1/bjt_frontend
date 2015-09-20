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
 * Strategy utilities
 * @author mdaigle
 *
 */
Class StrategyUtil {
	
	/**
	 * Get the array of strategy abbreviations
	 * @return array of strategy abbreviations
	 */
	static function getStrategyAbbrevArray() { 
    return array("SR", "HT", "ST", "DH", "SP", "DS");
	}

	/**
	 * Get the strategy abbreviation by index
	 * @param int index of strategy abbreviation
	 * @return string holding strategy abbreviation
	 */
	static function getStrategyAbbrev($i) { 
    $aArray = self::getStrategyAbbrevArray();
    return $aArray[$i];
	}

}

?>
