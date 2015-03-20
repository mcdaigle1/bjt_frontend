/***********************************************************
 * Copyright 2012 Blue Cask Software. All rights reserved.
 *
 * THIS PROGRAM IS CONFIDENTIAL AND PROPRIETARY TO BLUE CASK
 * SOFTWARE.  Any unauthorized use, reproduction, modification, or
 * disclosure of this program is strictly prohibited without the
 * express written permission of an authorized representative of
 * Blue Cask Software.
 ***********************************************************/
#ifndef SHOE_ACCESS_H
#define SHOE_ACCESS_H

#include <string>
#include <string.h>
#include <unordered_map>
#include <mysql++.h>
#include "DbAccess.h"
#include "../deck/Shoe.h"
#include "../database/Storable.h"
#include "../exception/InvalidArgumentException.h"

class ShoeAccess : public DbAccess {

public:
	/**
	 * Return the singleton ShoeAccess instance.
	 * @returns the singleton ShoeAccess object
	 */
	static ShoeAccess * instance();

	/**
	 * Create a Shoe in the db
	 * @param storable the base object which points at a shoe
	 */
	void create(Storable * storable);

	/**
	 * Retrieve a Shoe object by ID
	 * @param id the id of the shoe we want to retrieve
	 * @returns storable object pointing to the shoe object
	 */
	Storable * read(int id);

	/**
	 * Update a Shoe in the db
	 * @param storable the base object which points at a shoe
	 */
	void update(Storable * storable);

//	void create(Storable * storable);
//
//	Storable * read(int id);
//
//	void update(Storable * storable);

private:
	ShoeAccess();

	~ShoeAccess();

	static ShoeAccess * _instance;

	Shoe * rowToStorable(mysqlpp::Row row);
};

#endif
