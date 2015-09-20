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
 * 
 * Dealer Strategy utilities
 * @author mdaigle
 *
 */
Class DealerStrategyUtil extends StrategyUtil {
	
	/**
	 * Get the array of dealer hand abbreviations
	 * @return array of dealer hand abbreviations
	 */
	static function getDealerHandAbbrevArray() { 
		return array("A", "2", "3", "4", "5", "6", "7", "8", "9", "10");
	}    	
		
	/**
	 * Get the dealer hand abbreviation by index
	 * @param int index of dealer hand abbreviation
	 * @return string holding dealer hand abbreviation
	 */
	static function getDealerHandAbbrev($i) { 
		$dhaArray = self::getDealerHandAbbrevArray();
        return $dhaArray[$i];
	}    	

}

?>
