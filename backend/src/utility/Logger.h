/***********************************************************
 * Copyright 2012 Blue Cask Software. All rights reserved.
 *
 * THIS PROGRAM IS CONFIDENTIAL AND PROPRIETARY TO BLUE CASK
 * SOFTWARE.  Any unauthorized use, reproduction, modification, or
 * disclosure of this program is strictly prohibited without the
 * express written permission of an authorized representative of
 * Blue Cask Software.
 ***********************************************************/
#ifndef LOGGER_H
#define LOGGER_H

#include <iostream>
#include <fstream>
#include <sstream>
#include <string.h>
#include <string>

enum logLevel { SQL, DEBUG, INFO, WARN, ERROR };

class Logger {

private:
	static const char *    _logFileLocation;
	static std::ofstream * _logFile;
	static logLevel        _logLevel;
	static bool            _logSql;
	static bool            _isInitialized;

	static void logMessage(logLevel level, std::string message);

public:
	static const std::string * _levelStrArray;

	static void initialize(logLevel level, const char * logFileLocation);

	static void debug(std::string message);

	static void debug(std::ostringstream &message);

	static void info(std::string message);

	static void info(std::ostringstream &message);

	static void warn(std::string message);

	static void warn(std::ostringstream &message);

	static void error(std::string message);

	static void error(std::ostringstream &message);

	static void sql(std::string message);

	static void sql(std::ostringstream &message);
};

#endif
