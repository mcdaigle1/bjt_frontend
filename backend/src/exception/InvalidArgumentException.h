/***********************************************************
 * Copyright 2012 Blue Cask Software. All rights reserved.
 *
 * THIS PROGRAM IS CONFIDENTIAL AND PROPRIETARY TO BLUE CASK
 * SOFTWARE.  Any unauthorized use, reproduction, modification, or
 * disclosure of this program is strictly prohibited without the
 * express written permission of an authorized representative of
 * Blue Cask Software.
 ***********************************************************/
#ifndef INVALID_ARGUMENT_EXCEPTION_H
#define INVALID_ARGUMENT_EXCEPTION_H

#include "BaseException.h"

class InvalidArgumentException : public BaseException {
public:
	InvalidArgumentException(BaseException * e, std::string msg) : BaseException(e, msg){};

	InvalidArgumentException(std::exception * e, std::string msg) : BaseException(e, msg){};

	InvalidArgumentException(std::string msg) : BaseException(msg) {};
};

#endif
