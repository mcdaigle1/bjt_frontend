/***********************************************************
 * Copyright 2012 Blue Cask Software. All rights reserved.
 *
 * THIS PROGRAM IS CONFIDENTIAL AND PROPRIETARY TO BLUE CASK
 * SOFTWARE.  Any unauthorized use, reproduction, modification, or
 * disclosure of this program is strictly prohibited without the
 * express written permission of an authorized representative of
 * Blue Cask Software.
 ***********************************************************/
#ifndef STORABLE_H
#define STORABLE_H

#include <string>
#include <string.h>
#include <vector>
#include <unordered_map>

enum DB_FIELD_TYPE {INT, VARCHAR, TIMESTAMP, BOOL, TEXT};

class Storable {

private:

protected:

public:
	int _id;
	std::string _createTime;
	std::string _modTime;
	std::string _description;

	std::unordered_map<std::string, std::string> * dbFields;
	std::unordered_map<std::string, std::string> * requiredDbFields;

	Storable();

	~Storable();

	/**
	 * Get the id of the row
	 * @returns int id of row
	 */
	int getId();

	//TODO find out the best way to hold time
	/**
	 * Get the create time of the row
	 * @returns string create time of row
	 */
	std::string getCreateTime();

	/**
	 * Get the last modified time of the row
	 * @returns string modified time of row
	 */
	std::string getModTime();

	/**
	 * Get the row description
	 * @returns string description
	 */
	std::string getDescription();

	//TODO find out the best way to hold time
	void setCreateTime(std::string);

	void setModTime(std::string);

};

#endif
