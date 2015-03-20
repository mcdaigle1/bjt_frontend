/***********************************************************
 * Copyright 2012 Blue Cask Software. All rights reserved.
 *
 * THIS PROGRAM IS CONFIDENTIAL AND PROPRIETARY TO BLUE CASK
 * SOFTWARE.  Any unauthorized use, reproduction, modification, or
 * disclosure of this program is strictly prohibited without the
 * express written permission of an authorized representative of
 * Blue Cask Software.
 ***********************************************************/
#include <iostream>
#include "ShoeOneAccess.h"

using namespace std;

ShoeOneAccess * ShoeOneAccess::_instance;

/*
 * Creates a Card object initialized with suit and value
 * Parameters:
 * 		position - an integer number between 0 and 51 inclusive representing the position
 *                 in a deck that is sorted A-K for each suit C,H,D and S.
 */
ShoeOneAccess::ShoeOneAccess() {
	_tableName = "shoe_one";
}

ShoeOneAccess::~ShoeOneAccess() {
}

ShoeOneAccess * ShoeOneAccess::instance() {
	if (_instance == NULL) {
		_instance = new ShoeOneAccess();
	}
	return _instance;
}
