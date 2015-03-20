/***********************************************************
 * Copyright 2012 Blue Cask Software. All rights reserved.
 *
 * THIS PROGRAM IS CONFIDENTIAL AND PROPRIETARY TO BLUE CASK
 * SOFTWARE.  Any unauthorized use, reproduction, modification, or
 * disclosure of this program is strictly prohibited without the
 * express written permission of an authorized representative of
 * Blue Cask Software.
 ***********************************************************/
#ifndef SHOE_CONTROLLER_H
#define SHOE_CONTROLLER_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <string>
#include <unordered_map>
#include "../deck/Shoe.h"

class ShoeController {
public:

	/**
	 * Get the singleton instance of ShoeController
	 * @returns ShoeController singleton
	 */
	static ShoeController * instance();

//	/**
//	 * Generate a given number of sorted shoes and save them in the
//	 * database
//	 * @param numShoes int number of shoes to create
//	 * @param numDecks int number of decks in the shoes
//	 */
//	void generateShoes(int numShoes, int numDecks);

private:
	static ShoeController * _instance;

	ShoeController();

};

#endif
