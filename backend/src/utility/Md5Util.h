/***********************************************************
 * Copyright 2012 Blue Cask Software. All rights reserved.
 *
 * THIS PROGRAM IS CONFIDENTIAL AND PROPRIETARY TO BLUE CASK
 * SOFTWARE.  Any unauthorized use, reproduction, modification, or
 * disclosure of this program is strictly prohibited without the
 * express written permission of an authorized representative of
 * Blue Cask Software.
 ***********************************************************/
#ifndef MD5_UTIL_H
#define MD5_UTIL_H

#include <string>
#include <string.h>


class Md5Util {

private:

public:
	static std::string Md5Sum(std::string origString);
};

#endif