/***********************************************************
 * Copyright 2012 Blue Cask Software. All rights reserved.
 *
 * THIS PROGRAM IS CONFIDENTIAL AND PROPRIETARY TO BLUE CASK
 * SOFTWARE.  Any unauthorized use, reproduction, modification, or
 * disclosure of this program is strictly prohibited without the
 * express written permission of an authorized representative of
 * Blue Cask Software.
 ***********************************************************/
#ifndef MY_STRING_H
#define MY_STRING_H

#include <string>
#include <string.h>

class String {

private:

public:
	static int toInt(const char * strToConvert);

	static int toInt(std::string strToConvert);

	static bool toBool(const char * strToConvert);

	static bool toBool(std::string strToConvert);

	/**
	 * Pad a given string with spaces on the left.  This is typically done for display purposes
	 * when outputting tables of data in text format.
	 * @param strToPad string that needs to be padded
	 * @param fieldSize int representing the total size of the returned string with padding
	 * @returns string with padding.  If the original string is longer than fieldSize, the
	 * 		original string is returned.
	 */
	static std::string padLeft(std::string strToPad, int fieldSize);
};

#endif
