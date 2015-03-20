/***********************************************************
 * Copyright 2012 Blue Cask Software. All rights reserved.
 *
 * THIS PROGRAM IS CONFIDENTIAL AND PROPRIETARY TO BLUE CASK
 * SOFTWARE.  Any unauthorized use, reproduction, modification, or
 * disclosure of this program is strictly prohibited without the
 * express written permission of an authorized representative of
 * Blue Cask Software.
 ***********************************************************/
#ifndef DB_DUPLICATE_ENTRY_EXCEPTION_H
#define DB_DUPLICATE_ENTRY_EXCEPTION_H

#include "DatabaseException.h"

class DbDuplicateEntryException : public DatabaseException {
public:
	DbDuplicateEntryException(BaseException * e, std::string msg) : DatabaseException(e, msg) {};

	DbDuplicateEntryException(std::exception * e, std::string msg) : DatabaseException(e, msg) {};

	DbDuplicateEntryException(std::string msg) : DatabaseException(msg) {};
};

#endif
