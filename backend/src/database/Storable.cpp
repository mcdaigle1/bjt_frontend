/***********************************************************
 * Copyright 2012 Blue Cask Software. All rights reserved.
 *
 * THIS PROGRAM IS CONFIDENTIAL AND PROPRIETARY TO BLUE CASK
 * SOFTWARE.  Any unauthorized use, reproduction, modification, or
 * disclosure of this program is strictly prohibited without the
 * express written permission of an authorized representative of
 * Blue Cask Software.
 ***********************************************************/
#include "Storable.h"
#include "../utility/Logger.h"

using namespace std;

Storable::Storable() {
}

Storable::~Storable() {
}

int Storable::getId() {
	return _id;
}

string Storable::getCreateTime() {
	return _createTime;
}

string Storable::getModTime() {
	return _modTime;
}


