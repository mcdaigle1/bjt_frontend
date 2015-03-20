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
#include <sstream>
#include <iomanip>
#include <openssl/md5.h>
#include "Md5.h"
#include "../exception/UtilityException.h"

using namespace std;

string Md5::Md5Sum(string origString) {
	unsigned char * ibuf = (unsigned char *)origString.c_str();
	unsigned char obuf[16];

	MD5(ibuf, strlen(origString.c_str()), obuf);

	ostringstream oString;

	for (int i = 0; i < 16; i++) {
		char hex[2];
		sprintf(hex, "%02x", obuf[i]);
		oString << hex;
	}

	return oString.str();
}
