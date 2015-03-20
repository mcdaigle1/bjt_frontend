/***********************************************************
 * Copyright 2012 Blue Cask Software. All rights reserved.
 *
 * THIS PROGRAM IS CONFIDENTIAL AND PROPRIETARY TO BLUE CASK
 * SOFTWARE.  Any unauthorized use, reproduction, modification, or
 * disclosure of this program is strictly prohibited without the
 * express written permission of an authorized representative of
 * Blue Cask Software.
 ***********************************************************/
#include <mysql++.h>
#include "DbAccess.h"
#include "../utility/Logger.h"
#include "../exception/DatabaseException.h"
#include "../exception/DbAccessException.h"
#include "../exception/DbDuplicateEntryException.h"
#include "../exception/DbMissingRowException.h"

using namespace std;

/*
 * Creates a Card object initialized with suit and value
 * Parameters:
 * 		position - an integer number between 0 and 51 inclusive representing the position
 *                 in a deck that is sorted A-K for each suit C,H,D and S.
 */
DbAccess::DbAccess() {
	_db = Database::instance();
	if (_db == NULL) {
		throw DatabaseException("Could not get Database instance");
	}
}

DbAccess::~DbAccess() {
	//delete _conn;
}

void DbAccess::destroy(Storable * storable) {
	destroy_by_id(storable->getId());
}

void DbAccess::destroy_by_id(int id) {
	ostringstream sql;

	sql << "DELETE FROM " << _tableName << " WHERE id = " << id;
	mysqlpp::SimpleResult res = raw_remove(sql.str());
}

mysqlpp::SimpleResult DbAccess::raw_insert(string sql) {
	mysqlpp::Connection * conn = _db->getConnection();
	Logger::sql(sql);
	mysqlpp::Query query = conn->query(sql.c_str());
	mysqlpp::SimpleResult res = query.execute();
	if (!res) {
		handleError("Insert", query);
	}
	return res;
}

mysqlpp::StoreQueryResult DbAccess::raw_select(string sql) {
	mysqlpp::Connection * conn = _db->getConnection();
	Logger::sql(sql);
	mysqlpp::Query query = conn->query(sql.c_str());
	mysqlpp::StoreQueryResult res = query.store();
	if (!res) {
		handleError("Select", query);
	}
	return res;
}

mysqlpp::StoreQueryResult DbAccess::raw_select(int id) {
	ostringstream sql;

	sql << "SELECT * FROM " << _tableName << " WHERE id = " << id;
	mysqlpp::StoreQueryResult res = raw_select(sql.str());

	if (res.size() == 0) {
		ostringstream errorMsg;
		errorMsg << "DbAccess::select - no row found for " << _tableName << ".id " << id;
		throw DbMissingRowException(errorMsg.str());
	}

	return res;
}

mysqlpp::SimpleResult DbAccess::raw_update(string sql) {
	mysqlpp::Connection * conn = _db->getConnection();
	Logger::sql(sql);
	mysqlpp::Query query = conn->query(sql.c_str());
	mysqlpp::SimpleResult res = query.execute();
	return res;
}

mysqlpp::SimpleResult DbAccess::raw_remove(string sql) {
	mysqlpp::Connection * conn = _db->getConnection();
	Logger::sql(sql);
	mysqlpp::Query query = conn->query(sql.c_str());
	mysqlpp::SimpleResult res = query.execute();
	return res;
}

void DbAccess::handleError(string prefix, mysqlpp::Query query) {
	ostringstream errorMsg;
	errorMsg << "DB " << prefix << " issue: (" << query.errnum() << ") " << string(query.error());
	cout << "errnum: " << query.errnum() << endl;
	switch (query.errnum()) {
	case 1062 :
		cout << "gonna throw DbDuplicateEntryException" << endl;
		throw DbDuplicateEntryException(errorMsg.str());
		break;
	default :
		throw DatabaseException(errorMsg.str());
	}

}
