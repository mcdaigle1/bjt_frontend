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

/**
 * 
 * Player Hit Rule utilities
 * @author mdaigle
 *
 */
Class PlayerHitRule {
	
	/**
	 * Get the array of hit rule abbreviations
	 * @return array of hit rule abbreviations
	 */
	static function getHitRuleAbbrevArray() { 
        return array("SR", "HT", "ST", "DH", "SP", "DS");
	}

	/**
	 * Get the array of dealer hand abbreviations
	 * @return array of dealer hand abbreviations
	 */
	static function getDealerHandAbbrevArray() { 
		return array("A", "2", "3", "4", "5", "6", "7", "8", "9", "10");
	}    	
		
	/**
	 * Get the array of player hand abbreviations
	 * @return array of player hand abbreviations
	 */
	static function getPlayerHandAbbrevArray() {
		return array("5", "6", "7", "8", "9", "10", "11", "12", "13", "14",
		"15", "16", "17", "18", "19", "20", "A,2", "A,3", "A,4", "A,5", "A,6", "A,7",
		"A,8", "A,9", "A,10", "A,A", "2,2", "3,3", "4,4", "5,5", "6,6", "7,7", "8,8",
		"9,9", "10,10");
	}
	
	/**
	 * Get the hit rule abbreviation by index
	 * @param int index of hit rule abbreviation
	 * @return string holding hit rule abbreviation
	 */
	static function getHitRuleAbbrev($i) { 
        $hraArray = self::getHitRuleAbbrevArray();
        return $hraArray[$i];
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

	/**
	 * Get the player hand abbreviation by index
	 * @param int index of player hand abbreviation
	 * @return string holding player hand abbreviation
	 */
	static function getPlayerHandAbbrev($i) {
		$phaArray = self::getPlayerHandAbbrevArray();
        return $phaArray[$i];
	}
}

?>