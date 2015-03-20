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
#include "String.h"
#include "../exception/IntegerConversionException.h"
#include "../utility/Logger.h"

using namespace std;

int String::toInt(const char * strToConvert) {
	int convertedInt;
	if(EOF == sscanf(strToConvert, "%d", &convertedInt)) {
		ostringstream errMsg;
		errMsg << "String::toInt - could not convert selected string to int: " << strToConvert;
		throw IntegerConversionException(errMsg.str());
	}

	return convertedInt;
}

int String::toInt(string strToConvert) {
	int convertedInt;
	convertedInt = toInt(strToConvert.c_str());

	return convertedInt;
}

bool String::toBool(const char * strToConvert) {
	return (strcmp(strToConvert, "1") == 0);
}

bool String::toBool(string strToConvert) {
	return toBool(strToConvert.c_str());
}

std::string String::padLeft(std::string strToPad, int fieldSize) {
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

