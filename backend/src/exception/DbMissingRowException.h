/***********************************************************
 * Copyright 2012 Blue Cask Software. All rights reserved.
 *
 * THIS PROGRAM IS CONFIDENTIAL AND PROPRIETARY TO BLUE CASK
 * SOFTWARE.  Any unauthorized use, reproduction, modification, or
 * disclosure of this program is strictly prohibited without the
 * express written permission of an authorized representative of
 * Blue Cask Software.
 ***********************************************************/
#ifndef DB_MISSING_ROW_EXCEPTION_H
#define DB_MISSING_ROW_EXCEPTION_H

#include "DatabaseException.h"

class DbMissingRowException : public DatabaseException {
public:
	DbMissingRowException(BaseException * e, std::string msg) : DatabaseException(e, msg) {};

	DbMissingRowException(std::exception * e, std::string msg) : DatabaseException(e, msg) {};

	DbMissingRowException(std::string msg) : DatabaseException(msg) {};
};

#endif
