/***********************************************************
 * Copyright 2012 Blue Cask Software. All rights reserved.
 *
 * THIS PROGRAM IS CONFIDENTIAL AND PROPRIETARY TO BLUE CASK
 * SOFTWARE.  Any unauthorized use, reproduction, modification, or
 * disclosure of this program is strictly prohibited without the
 * express written permission of an authorized representative of
 * Blue Cask Software.
 ***********************************************************/
#ifndef DB_ACCESS_EXCEPTION_H
#define DB_ACCESS_EXCEPTION_H

#include "BaseException.h"

class DbAccessException : public BaseException {
public:
	DbAccessException(BaseException * e, std::string msg) : BaseException(e, msg){};

	DbAccessException(std::exception * e, std::string msg) : BaseException(e, msg){};

	DbAccessException(std::string msg) : BaseException(msg) {};
};

#endif
