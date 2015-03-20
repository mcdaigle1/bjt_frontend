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
#include "ShoeSixAccess.h"
#include "../utility/Logger.h"
#include "../exception/ShoeException.h"

using namespace std;

ShoeSixAccess * ShoeSixAccess::_instance;

/*
 * Creates a Card object initialized with suit and value
 * Parameters:
 * 		position - an integer number between 0 and 51 inclusive representing the position
 *                 in a deck that is sorted A-K for each suit C,H,D and S.
 */
ShoeSixAccess::ShoeSixAccess() {
	_tableName = "shoe_six";
}

ShoeSixAccess::~ShoeSixAccess() {
}

ShoeSixAccess * ShoeSixAccess::instance() {
	if (_instance == NULL) {
		_instance = new ShoeSixAccess();
	}
	return _instance;
}

