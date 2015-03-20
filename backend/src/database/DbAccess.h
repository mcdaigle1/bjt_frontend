/***********************************************************
 * Copyright 2012 Blue Cask Software. All rights reserved.
 *
 * THIS PROGRAM IS CONFIDENTIAL AND PROPRIETARY TO BLUE CASK
 * SOFTWARE.  Any unauthorized use, reproduction, modification, or
 * disclosure of this program is strictly prohibited without the
 * express written permission of an authorized representative of
 * Blue Cask Software.
 ***********************************************************/
#ifndef DB_ACCESS_H
#define DB_ACCESS_H

#include <string>
#include <string.h>
#include <unordered_map>
#include <mysql++.h>
#include "Database.h"
#include "Storable.h"

typedef std::unordered_map<std::string, std::string> ColumnMetadata;
typedef std::vector<ColumnMetadata> TableMetadata;

class DbAccess {

public:
	/**
	 * Save an instance of a storable object in the db
	 * @param storable Storable object we want to create in the db
	 */
	virtual void create(Storable * storable) = 0;

	/**
	 * Read an instance of a storable object by id from the db
	 * @param id in the id of the object we want to read
	 */
	virtual Storable * read(int id) = 0;

	/**
	 * Update a storable object.  Only update the dirty fields.
	 * @param storable Storable object to update
	 */
	virtual void update(Storable * storable) = 0;

	/**
	 * Delete a storable object from the database.
	 * @param storable Storable object to delete
	 */
	void destroy(Storable * storable);

	/**
	 * Delete a storable object from the database by id.
	 * @param id int id of object to delete
	 */
	void destroy_by_id(int id);

private:
	Database * _db;

	void handleError(std::string prefix, mysqlpp::Query query);

protected:
	DbAccess();

	~DbAccess();

	std::string _tableName; // this table name

	/**
	 * Run an insert using given sql
	 * @params sql string holding insert sql to run
	 * @returns mysqlpp::SimpleResult holding the result of the insert
	 */
	mysqlpp::SimpleResult raw_insert(std::string sql);

	/**
	 * Run a select of given sql
	 * @params sql string holding select sql to run
	 * @returns mysqlpp::StoreQueryResult holding selected rows
	 */
	mysqlpp::StoreQueryResult raw_select(std::string sql);

	/**
	 * Select a single row by id
	 * @param id int id of the row to retrieve
	 * @returns mysqlpp::StoreQueryResult holding the single row of data
	 */
	mysqlpp::StoreQueryResult raw_select(int id);

	/**
	 * Run an update using given sql
	 * @params sql string holding update sql to run
	 * @returns mysqlpp::SimpleResult holding the result of the update
	 */
	mysqlpp::SimpleResult raw_update(std::string sql);

	/**
	 * Run a delete using given sql
	 * @params sql string holding delete sql to run
	 * @returns mysqlpp::SimpleResult holding the result of the delete
	 */
	mysqlpp::SimpleResult raw_remove(std::string sql);



};

#endif
