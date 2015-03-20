/***********************************************************
 * Copyright 2012 Blue Cask Software. All rights reserved.
 *
 * THIS PROGRAM IS CONFIDENTIAL AND PROPRIETARY TO BLUE CASK
 * SOFTWARE.  Any unauthorized use, reproduction, modification, or
 * disclosure of this program is strictly prohibited without the
 * express written permission of an authorized representative of
 * Blue Cask Software.
 ***********************************************************/
#ifndef SHOE_TWO_ACCESS_H
#define SHOE_TWO_ACCESS_H

#include <string>
#include <string.h>
#include <unordered_map>
#include <mysql++.h>

#include "ShoeAccess.h"
#include "../exception/InvalidArgumentException.h"

class ShoeTwoAccess : public ShoeAccess {

public:
	/**
	 * Return the singleton ShoeTwoAccess instance.
	 * @returns the singleton ShoeTwoAccess object
	 */
	static ShoeTwoAccess * instance();

private:
	ShoeTwoAccess();

	~ShoeTwoAccess();

	static ShoeTwoAccess * _instance;
};

#endif
