/***********************************************************
 * Copyright 2012 Blue Cask Software. All rights reserved.
 *
 * THIS PROGRAM IS CONFIDENTIAL AND PROPRIETARY TO BLUE CASK
 * SOFTWARE.  Any unauthorized use, reproduction, modification, or
 * disclosure of this program is strictly prohibited without the
 * express written permission of an authorized representative of
 * Blue Cask Software.
 ***********************************************************/
#ifndef BASE_EXCEPTION_H
#define BASE_EXCEPTION_H

#include <string>
#include <string.h>

class BaseException : public std::exception {

public:
	BaseException(BaseException * e, std::string);

	BaseException(std::exception * e, std::string);

	BaseException(std::string msg);

	~BaseException() throw ();

	std::string getMsg();

private:
	std::string _msg;
	BaseException * _childException;

	BaseException();
};

#endif
