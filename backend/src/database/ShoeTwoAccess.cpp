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
#include "ShoeTwoAccess.h"

using namespace std;

ShoeTwoAccess * ShoeTwoAccess::_instance;

ShoeTwoAccess::ShoeTwoAccess() {
	_tableName = "shoe_two";
}

ShoeTwoAccess::~ShoeTwoAccess() {
}

ShoeTwoAccess * ShoeTwoAccess::instance() {
	if (_instance == NULL) {
		_instance = new ShoeTwoAccess();
	}
	return _instance;
}

