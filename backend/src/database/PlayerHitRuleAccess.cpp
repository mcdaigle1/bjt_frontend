/***********************************************************
 * Copyright 2012 Blue Cask Software. All rights reserved.
 *
 * THIS PROGRAM IS CONFIDENTIAL AND PROPRIETARY TO BLUE CASK
 * SOFTWARE.  Any unauthorized use, reproduction, modification, or
 * disclosure of this program is strictly prohibited without the
 * express written permission of an authorized representative of
 * Blue Cask Software.
 ***********************************************************/
#include "PlayerHitRuleAccess.h"
#include "../exception/RuleException.h"

using namespace std;

PlayerHitRuleAccess * PlayerHitRuleAccess::_instance;

PlayerHitRuleAccess::PlayerHitRuleAccess() {
	_tableName = "player_hit_rule";
}

PlayerHitRuleAccess::~PlayerHitRuleAccess() {
}

PlayerHitRuleAccess * PlayerHitRuleAccess::instance() {
	if (_instance == NULL) {
		_instance = new PlayerHitRuleAccess();
	}
	return _instance;
}

void PlayerHitRuleAccess::create(Storable * storable) {

}

Storable * PlayerHitRuleAccess::read(int id) {
	mysqlpp::StoreQueryResult result = raw_select(id);
	return rowToStorable(result.at(0));
}

void PlayerHitRuleAccess::update(Storable * storable) {

}

mysqlpp::StoreQueryResult PlayerHitRuleAccess::selectByMd5(string md5) {
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

PlayerHitRule * PlayerHitRuleAccess::rowToStorable(mysqlpp::Row row) {
	return new PlayerHitRule(row);
}

