/***********************************************************
 * Copyright 2012 Blue Cask Software. All rights reserved.
 *
 * THIS PROGRAM IS CONFIDENTIAL AND PROPRIETARY TO BLUE CASK
 * SOFTWARE.  Any unauthorized use, reproduction, modification, or
 * disclosure of this program is strictly prohibited without the
 * express written permission of an authorized representative of
 * Blue Cask Software.
 ***********************************************************/
#include "DealerHandAccess.h"
#include "../utility/Logger.h"

using namespace std;

DealerHandAccess * DealerHandAccess::_instance;

DealerHandAccess::DealerHandAccess() {
	_tableName = "dealer_hand";
}

DealerHandAccess::~DealerHandAccess() {
}

DealerHandAccess * DealerHandAccess::instance() {
	if (_instance == NULL) {
		_instance = new DealerHandAccess();
	}
	return _instance;
}

void DealerHandAccess::create(Storable * storable) {

}

Storable * DealerHandAccess::read(int id) {
	mysqlpp::StoreQueryResult result = raw_select(id);
	return rowToStorable(result.at(0));
}

void DealerHandAccess::update(Storable * storable) {

}

//void DealerHandAccess::insert(int gameId, int shoeId, int sequence, std::string cardList) {
//	ostringstream sql;
//
//	sql << "INSERT INTO " << _tableName << " (create_time, mod_time, game_id, shoe_id, "
//			<< "sequence, card_list) "
//			<< "values(now(), now(), " << gameId << ", " << shoeId << ", "
//			<< sequence << ", '" << cardList << "')";
//	DbAccess::insert(sql.str());
//}
//
//void DealerHandAccess::update(int id, unordered_map<string, string> fields) {
//	char * shoeIdStr;
//	int fieldsMatched = 0;
//	ostringstream sql;
//
//	sscanf(shoeIdStr, "%d", id);
//
//	sql << "UPDATE " << _tableName << " SET ";
//	if (!fields["num_decks"].empty()) {
//		sql << "num_decks = " << fields["num_decks"];
//		fieldsMatched++;
//	}
//	if (!fields["cards"].empty()) {
//		if (fieldsMatched > 0) {
//			sql << ",";
//		}
//		sql << "cards = '" << fields["num_decks"] << "'";
//		fieldsMatched++;
//	}
//	if (fieldsMatched == 0) {
//		throw InvalidArgumentException("update inputs must contain a num_decks or cards value");
//	}
//}

mysqlpp::StoreQueryResult DealerHandAccess::selectByGame(int gameId) {
	ostringstream sql;
	sql << "SELECT * FROM " << _tableName << "WHERE game_id = " << gameId;

	return raw_select(sql.str());
}

DealerHand * DealerHandAccess::rowToStorable(mysqlpp::Row row) {
	return new DealerHand(row);
}

