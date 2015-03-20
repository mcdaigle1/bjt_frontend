/***********************************************************
 * Copyright 2012 Blue Cask Software. All rights reserved.
 *
 * THIS PROGRAM IS CONFIDENTIAL AND PROPRIETARY TO BLUE CASK
 * SOFTWARE.  Any unauthorized use, reproduction, modification, or
 * disclosure of this program is strictly prohibited without the
 * express written permission of an authorized representative of
 * Blue Cask Software.
 ***********************************************************/
#include <time.h>
#include "Logger.h"
#include "../exception/LoggerException.h"

using namespace std;

string levelArray[] =  {"SQL","DEBUG","INFO","WARN","ERROR"};
const string * Logger::_levelStrArray = levelArray;
const char * Logger::_logFileLocation = NULL;
ofstream * Logger::_logFile           = new ofstream();
logLevel Logger::_logLevel             = INFO;
bool Logger::_logSql                   = true;
bool Logger::_isInitialized            = false;

void Logger::initialize(logLevel level, const char * logFileLocation) {
	if (_isInitialized) {
		throw LoggerException("Attempt to initialize previously initialized logger.");
	} else {
		_logFileLocation = logFileLocation;
		_logLevel = level;
		cout << "opening log file: " << logFileLocation << endl;
		_logFile->open(logFileLocation, ios::app);
		_isInitialized = true;
	}
}

void Logger::debug(string message) {
	if(_logLevel <= DEBUG) {
		logMessage(DEBUG, message);
	}
}

void Logger::debug(ostringstream &message) {
	debug(message.str());
}

void Logger::info(string message) {
	if(_logLevel <= INFO) {
		logMessage(INFO, message);
	}
}

void Logger::info(ostringstream &message) {
	info(message.str());
}

void Logger::warn(string message) {
	if(_logLevel <= WARN) {
		logMessage(WARN, message);
	}
}

void Logger::warn(ostringstream &message) {
	warn(message.str());
}

void Logger::error(string message) {
	if(_logLevel <= ERROR) {
		logMessage(ERROR, message);
	}
}

void Logger::error(ostringstream &message) {
	error(message.str());
}

void Logger::sql(string message) {
	if(_logSql) {
		logMessage(SQL, message);
	}
}

void Logger::sql(ostringstream &message) {
	sql(message.str());
}

void Logger::logMessage(logLevel level, string message) {
	if(!_isInitialized) {
		throw LoggerException("Attempt to log message before logger is initialized.");
	}

	pid_t pid = getpid();

	time_t rawtime;
	struct tm * timeinfo;
	char timeBuffer [80];

	time(&rawtime);
	timeinfo = gmtime(&rawtime);

	strftime(timeBuffer, 80, "%b %d %H:%M:%S ", timeinfo);
	*_logFile << timeBuffer << "[" << _levelStrArray[level] << "] (" << pid << ") - "
			<< message << endl;
}
