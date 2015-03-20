/***********************************************************
 * Copyright 2012 Blue Cask Software. All rights reserved.
 *
 * THIS PROGRAM IS CONFIDENTIAL AND PROPRIETARY TO BLUE CASK
 * SOFTWARE.  Any unauthorized use, reproduction, modification, or
 * disclosure of this program is strictly prohibited without the
 * express written permission of an authorized representative of
 * Blue Cask Software.
 ***********************************************************/
#include "GameAccess.h"
#include "../game/Game.h"
#include "../utility/Logger.h"

using namespace std;

GameAccess * GameAccess::_instance;

GameAccess::GameAccess() {
	_tableName = "game";
}

GameAccess::~GameAccess() {
}

GameAccess * GameAccess::instance() {
	if (_instance == NULL) {
		_instance = new GameAccess();
	}
	return _instance;
}

void GameAccess::create(Storable * storable) {

}

Storable * GameAccess::read(int id) {
	mysqlpp::StoreQueryResult result = raw_select(id);
	return rowToStorable(result.at(0));
}

void GameAccess::update(Storable * storable) {

}


mysqlpp::StoreQueryResult GameAccess::selectAvailableIds() {
	ostringstream sql;
	sql << "SELECT id FROM game WHERE status = " << GS_NEW;

	mysqlpp::StoreQueryResult result = raw_select(sql.str());
	return result;
}

bool GameAccess::reserveGame(int availableGameId, int _reserveId) {
	ostringstream sql;

	// Attempt to update the status and reserve_id for a given game id
	// where the status in GS_NEW
	sql << "UPDATE game SET status = " << GS_PLAYING << ", reserve_id = "
			<< _reserveId << " WHERE id = " << availableGameId
			<< " AND status = " << GS_NEW;

	mysqlpp::SimpleResult result = raw_update(sql.str());
	if (result.rows() == 1) {
		// If one row was updated then return true that we reserved
		// the game
		return true;
	} else {
		// If one row was not updated, then this id was reserved by
		// another process.
		return false;
	}
}

Game * GameAccess::rowToStorable(mysqlpp::Row row) {
	return new Game(row);
}


