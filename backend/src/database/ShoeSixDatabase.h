/***********************************************************
 * Copyright 2012 Blue Cask Software. All rights reserved.
 *
 * THIS PROGRAM IS CONFIDENTIAL AND PROPRIETARY TO BLUE CASK
 * SOFTWARE.  Any unauthorized use, reproduction, modification, or
 * disclosure of this program is strictly prohibited without the
 * express written permission of an authorized representative of
 * Blue Cask Software.
 ***********************************************************/
#ifndef SHOE_SIX_ShoeSixDatabase_H
#define SHOE_SIX_ShoeSixDatabase_H

#include <string>
#include <string.h>
#include <mysql++.h>
#include <connection.h>

class ShoeSixDatabase {

public:
	static ShoeSixDatabase * instance();

	void initialize(const char * hostName, const char * dbName, const char * userName, const char * password);

	mysqlpp::Connection * getConnection();

private:
	const char * _hostName;
	const char * _dbName;
	const char * _userName;
	const char * _password;
	bool _isInitialized;
	static ShoeSixDatabase * _instance;

	ShoeSixDatabase();

};

#endif
