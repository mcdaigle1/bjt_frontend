/***********************************************************
 * Copyright 2012 Blue Cask Software. All rights reserved.
 *
 * THIS PROGRAM IS CONFIDENTIAL AND PROPRIETARY TO BLUE CASK
 * SOFTWARE.  Any unauthorized use, reproduction, modification, or
 * disclosure of this program is strictly prohibited without the
 * express written permission of an authorized representative of
 * Blue Cask Software.
 ***********************************************************/
#include "DealerHitRuleAccess.h"
#include "../exception/RuleException.h"

using namespace std;

DealerHitRuleAccess * DealerHitRuleAccess::_instance;

DealerHitRuleAccess::DealerHitRuleAccess() {
	_tableName = "dealer_hit_rule";
}

DealerHitRuleAccess::~DealerHitRuleAccess() {
}

DealerHitRuleAccess * DealerHitRuleAccess::instance() {
	if (_instance == NULL) {
		_instance = new DealerHitRuleAccess();
	}
	return _instance;
}

void DealerHitRuleAccess::create(Storable * storable) {

}

Storable * DealerHitRuleAccess::read(int id) {
	mysqlpp::StoreQueryResult result = raw_select(id);
	return rowToStorable(result.at(0));
}

void DealerHitRuleAccess::update(Storable * storable) {

}

mysqlpp::StoreQueryResult DealerHitRuleAccess::selectByMd5(string md5) {
	ostringstream sql;

	sql << "SELECT * FROM hit_rule WHERE md5 = '" << md5 << "'";

	mysqlpp::StoreQueryResult result = DbAccess::raw_select(sql.str());

	if (result.num_rows() != 1) {
		ostringstream errMsg; errMsg << "hit_rule query by md5 should return one row. ";
		errMsg << "This query returned " << result.num_rows();
		throw RuleException(errMsg.str());
	}

	return result;
}

DealerHitRule * DealerHitRuleAccess::rowToStorable(mysqlpp::Row row) {
	return new DealerHitRule(row);
}

void DealerHitRuleAccess::insertTest() {
}
