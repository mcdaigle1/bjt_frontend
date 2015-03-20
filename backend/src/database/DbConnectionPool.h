/***********************************************************
 * Copyright 2012 Blue Cask Software. All rights reserved.
 *
 * THIS PROGRAM IS CONFIDENTIAL AND PROPRIETARY TO BLUE CASK
 * SOFTWARE.  Any unauthorized use, reproduction, modification, or
 * disclosure of this program is strictly prohibited without the
 * express written permission of an authorized representative of
 * Blue Cask Software.
 ***********************************************************/
#ifndef DATABASE_H
#define DATABASE_H

#include <string>
#include <string.h>
#include <mysql++.h>
#include <connection.h>

class Database {

public:
	/**
	 * Return the singleton database instance
	 * @returns the singleton Database object
	 */
	static Database * instance();

	/**
	 * Initialize the database
	 * @param hostName char pointer database host name
	 * @param dbName char pointer database name
	 * @param userName char pointer database user name
	 * @param password char pointer database password
	 */
	void initialize(const char * hostName, const char * dbName, const char * userName, const char * password);

	/**
	 * Get a connection to the database
	 * @returns mysqlpp connection to the database
	 */
	mysqlpp::Connection * getConnection();

private:
	const char * _hostName;
	const char * _dbName;
	const char * _userName;
	const char * _password;
	bool _isInitialized;
	static Database * _instance;
	Database();
};

#endif
