/***********************************************************
 * Copyright 2012 Blue Cask Software. All rights reserved.
 *
 * THIS PROGRAM IS CONFIDENTIAL AND PROPRIETARY TO BLUE CASK
 * SOFTWARE.  Any unauthorized use, reproduction, modification, or
 * disclosure of this program is strictly prohibited without the
 * express written permission of an authorized representative of
 * Blue Cask Software.
 ***********************************************************/
#include <ctime>
#include <cstdlib>
#include <iostream>
#include <sstream>
#include "StringUtil.h"
#include "../exception/IntegerConversionException.h"
#include "../utility/Logger.h"

using namespace std;

int StringUtil::toInt(const char * strToConvert) {
	int convertedInt;
	if(EOF == sscanf(strToConvert, "%d", &convertedInt)) {
		ostringstream errMsg;
		errMsg << "StringUtil::toInt - could not convert selected string to int: " << strToConvert;
		throw IntegerConversionException(errMsg.str());
	}

	return convertedInt;
}

int StringUtil::toInt(string strToConvert) {
	int convertedInt;
	convertedInt = toInt(strToConvert.c_str());

	return convertedInt;
}

bool StringUtil::toBool(const char * strToConvert) {
	return (strcmp(strToConvert, "1") == 0);
}

bool StringUtil::toBool(string strToConvert) {
	return toBool(strToConvert.c_str());
}

std::string StringUtil::padLeft(std::string strToPad, int fieldSize) {
	if (strToPad.size() >= fieldSize) {
		return strToPad;
	} else {
		ostringstream returnStream;
		for (int i = 0; i < (fieldSize - strToPad.size()); i++) {
			returnStream << " ";
		}
		returnStream << strToPad;
		return returnStream.str();
	}
}

