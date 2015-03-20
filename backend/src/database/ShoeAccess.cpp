/***********************************************************
 * Copyright 2012 Blue Cask Software. All rights reserved.
 *
 * THIS PROGRAM IS CONFIDENTIAL AND PROPRIETARY TO BLUE CASK
 * SOFTWARE.  Any unauthorized use, reproduction, modification, or
 * disclosure of this program is strictly prohibited without the
 * express written permission of an authorized representative of
 * Blue Cask Software.
 ***********************************************************/
#include <iostream>
#include "ShoeAccess.h"
#include "../utility/Logger.h"
#include "../exception/ShoeException.h"

using namespace std;

ShoeAccess * ShoeAccess::_instance;

//int ShoeAccess::numAvailableShoes() {
//	ostringstream sql;
//
//	sql << "SELECT count(*) AS num_shoes FROM " << _tableName;
//	mysqlpp::StoreQueryResult result = DbAccess::select(sql.str());
//
//	if (result.num_rows() != 1) {
//		ostringstream errMsg; errMsg << "Available shoe query should return one row. ";
//		errMsg << "This query returned " << result.num_rows();
//		throw ShoeException("");
//	}
//
//	mysqlpp::String numShoesStr = result[0]["num_shoes"];
//
//	int numShoes;
//	if (EOF == sscanf(numShoesStr.c_str(), "%d", &numShoes)) {
//		ostringstream errMsg; errMsg << "Available shoe query should return integer value. ";
//		errMsg << "This query returned " << numShoesStr;
//		throw ShoeException(errMsg.str());
//	}
//
//	return numShoes;
//}

/*
 * Creates a Card object initialized with suit and value
 * Parameters:
 * 		position - an integer number between 0 and 51 inclusive representing the position
 *                 in a deck that is sorted A-K for each suit C,H,D and S.
 */
ShoeAccess::ShoeAccess() {
	_tableName = "shoe";
}

void ShoeAccess::create(Storable * storable) {

}

Storable * ShoeAccess::read(int id) {
	mysqlpp::StoreQueryResult result = raw_select(id);
	return rowToStorable(result.at(0));
}

void ShoeAccess::update(Storable * storable) {

}

//void ShoeAccess::create(Storable * storable) {
//	ostringstream sql;
//	Shoe * shoe = (Shoe *)storable;
//
//	sql << "INSERT INTO " << _tableName << " (create_time, mod_time, num_decks, "
//			<< "game_id, sequence, cards, cut_position) values(now(), now(), "
//			<< shoe->getNumDecks() << ", " << shoe->getGameId() << ", "
//			<< shoe->getSequence() << ", '" << shoe->getCards() << "', "
//			<< shoe->getCutPosition() << ")";
//
//	DbAccess::insert(sql.str());
//}
//
//Storable * ShoeAccess::read(int id) {
//	mysqlpp::StoreQueryResult result = select(id);
//	return new Shoe(result[0]);
//}
//
//void ShoeAccess::update(Storable * storable) {
//	ostringstream sql;
//	Shoe * shoe = (Shoe *)storable;
//
//	sql << "UPDATE " << _tableName << " SET num_decks = " << shoe->getNumDecks()
//		<< ", game_id = " << shoe->getGameId() << ", sequence = " << shoe->getSequence()
//		<< ", cards = '" << shoe->getCards() << "', cut_position = " << shoe->getCutPosition();
//
//	DbAccess::update(sql.str());
//}

Shoe * ShoeAccess::rowToStorable(mysqlpp::Row row) {
	return new Shoe(row);
}
