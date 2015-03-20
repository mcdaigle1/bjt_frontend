/***********************************************************
 * Copyright 2012 Blue Cask Software. All rights reserved.
 *
 * THIS PROGRAM IS CONFIDENTIAL AND PROPRIETARY TO BLUE CASK
 * SOFTWARE.  Any unauthorized use, reproduction, modification, or
 * disclosure of this program is strictly prohibited without the
 * express written permission of an authorized representative of
 * Blue Cask Software.
 ***********************************************************/
#ifndef RANDOM_H
#define RANDOM_H

#include <string>
#include <string.h>

class Random {

private:
	static bool _seeded;
	static void seed();

public:
	static int generate(int limit);
};

#endif
