/***********************************************************
 * Copyright 2012 Blue Cask Software. All rights reserved.
 *
 * THIS PROGRAM IS CONFIDENTIAL AND PROPRIETARY TO BLUE CASK
 * SOFTWARE.  Any unauthorized use, reproduction, modification, or
 * disclosure of this program is strictly prohibited without the
 * express written permission of an authorized representative of
 * Blue Cask Software.
 ***********************************************************/
#ifndef SHOE_ONE_ACCESS_H
#define SHOE_ONE_ACCESS_H

#include <string>
#include <string.h>
#include <unordered_map>
#include <mysql++.h>
#include "ShoeAccess.h"
#include "../exception/InvalidArgumentException.h"

class ShoeOneAccess : public ShoeAccess {

public:
	/**
	 * Return the singleton ShoeOneAccess instance.
	 * @returns the singleton ShoeOneAccess object
	 */
	static ShoeOneAccess * instance();

private:
	ShoeOneAccess();

	~ShoeOneAccess();

	static ShoeOneAccess * _instance;
};

#endif
