/***********************************************************
 * Copyright 2012 Blue Cask Software. All rights reserved.
 *
 * THIS PROGRAM IS CONFIDENTIAL AND PROPRIETARY TO BLUE CASK
 * SOFTWARE.  Any unauthorized use, reproduction, modification, or
 * disclosure of this program is strictly prohibited without the
 * express written permission of an authorized representative of
 * Blue Cask Software.
 ***********************************************************/
#include "Random.h"
#include <ctime>
#include <cstdlib>
#include <iostream>
#include <sstream>

using namespace std;

bool Random::_seeded = false;

int Random::generate(int limit) {
	if (!Random::_seeded) {
		seed();
		Random::_seeded = true;
	}
	return rand() % limit;
}

void Random::seed() {
	srand(time(0));
}


