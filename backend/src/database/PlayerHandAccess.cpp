/***********************************************************
 * Copyright 2012 Blue Cask Software. All rights reserved.
 *
 * THIS PROGRAM IS CONFIDENTIAL AND PROPRIETARY TO BLUE CASK
 * SOFTWARE.  Any unauthorized use, reproduction, modification, or
 * disclosure of this program is strictly prohibited without the
 * express written permission of an authorized representative of
 * Blue Cask Software.
 ***********************************************************/
#include "PlayerHandAccess.h"
#include "../utility/Logger.h"

using namespace std;

PlayerHandAccess * PlayerHandAccess::_instance;

PlayerHandAccess::PlayerHandAccess() {
	_tableName = "player_hand";
}

PlayerHandAccess::~PlayerHandAccess() {
}

PlayerHandAccess * PlayerHandAccess::instance() {
	if (_instance == NULL) {
		_instance = new PlayerHandAccess();
	}
	return _instance;
}

void PlayerHandAccess::create(Storable * storable) {

}

Storable * PlayerHandAccess::read(int id) {
	mysqlpp::StoreQueryResult result = raw_select(id);
	return rowToStorable(result.at(0));
}

void PlayerHandAccess::update(Storable * storable) {

}

//void PlayerHandAccess::insert(int playerId, int gameId, int shoeId, int sequence, int subSequence,
//		int parentSequence, int bet, int bankroll, std::string cardList, int outcome) {
//	ostringstream sql;
//
//	sql << "INSERT INTO " << _tableName << " (create_time, mod_time, player_id, game_id, shoe_id, "
//			<< "sequence, sub_sequence, parent_sequence, bet, bankroll, card_list, outcome) "
//			<< "values(now(), now(), " << playerId << ", " << gameId << ", " << shoeId << ", "
//			<< sequence << ", " << subSequence << ", " << parentSequence << ", " << bet << ", "
//			<< bankroll << ", '" << cardList << "', " << outcome << ")";
//	DbAccess::insert(sql.str());
//}
//
//void PlayerHandAccess::update(int id, unordered_map<string, string> fields) {
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

mysqlpp::StoreQueryResult PlayerHandAccess::selectByGame(int gameId) {
	ostringstream sql;
	sql << "SELECT * FROM " << _tableName << "WHERE game_id = " << gameId <<
			" ORDER BY sequence, subsequence";

	return raw_select(sql.str());
}

PlayerHand * PlayerHandAccess::rowToStorable(mysqlpp::Row row) {
	return new PlayerHand(row);
}

