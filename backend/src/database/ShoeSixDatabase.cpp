/***********************************************************
 * Copyright 2012 Blue Cask Software. All rights reserved.
 *
 * THIS PROGRAM IS CONFIDENTIAL AND PROPRIETARY TO BLUE CASK
 * SOFTWARE.  Any unauthorized use, reproduction, modification, or
 * disclosure of this program is strictly prohibited without the
 * express written permission of an authorized representative of
 * Blue Cask Software.
 ***********************************************************/
#include "ShoeSixDatabase.h"
#include "../exception/DatabaseException.h"
#include "../utility/Logger.h"

using namespace std;

int numConnections = 3;
ShoeSixDatabase * ShoeSixDatabase::_instance = NULL;

/*
 * Creates a Card object initialized with suit and value
 * Parameters:
 * 		position - an integer number between 0 and 51 inclusive representing the position
 *                 in a deck that is sorted A-K for each suit C,H,D and S.
 */
ShoeSixDatabase::ShoeSixDatabase() {

}

ShoeSixDatabase * ShoeSixDatabase::instance() {
	if (_instance == NULL) {
		_instance = new ShoeSixDatabase();
	}
	return _instance;
}

void ShoeSixDatabase::initialize(const char * hostName, const char * dbName, const char * userName, const char * password) {
	_hostName = hostName;
	_dbName = dbName;
	_userName = userName;
	_password = password;
	_isInitialized = true;
}

mysqlpp::Connection * ShoeSixDatabase::getConnection() {
	mysqlpp::Connection * conn = NULL;
	try {
		conn = new mysqlpp::Connection(false);

		if (!conn->connect(_dbName, _hostName, _userName, _password)) {
			Logger::debug("Error with ShoeSixDatabase connect call");
			throw new DatabaseException("Error with ShoeSixDatabase connect call");
		}
	} catch (exception& e) {
		Logger::debug("Error making ShoeSixDatabase connection");
		throw new DatabaseException(&e, "Error making ShoeSixDatabase connection");
	}
	return conn;
}


