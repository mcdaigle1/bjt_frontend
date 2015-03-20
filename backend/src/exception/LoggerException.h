/***********************************************************
 * Copyright 2012 Blue Cask Software. All rights reserved.
 *
 * THIS PROGRAM IS CONFIDENTIAL AND PROPRIETARY TO BLUE CASK
 * SOFTWARE.  Any unauthorized use, reproduction, modification, or
 * disclosure of this program is strictly prohibited without the
 * express written permission of an authorized representative of
 * Blue Cask Software.
 ***********************************************************/
#ifndef LOGGER_EXCEPTION_H
#define LOGGER_EXCEPTION_H

#include "BaseException.h"

class LoggerException : public BaseException {
public:
	LoggerException(BaseException * e, std::string msg) : BaseException(e, msg){};

	LoggerException(std::exception * e, std::string msg) : BaseException(e, msg){};

	LoggerException(std::string msg) : BaseException(msg) {};
};

#endif
