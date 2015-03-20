/***********************************************************
 * Copyright 2012 Blue Cask Software. All rights reserved.
 *
 * THIS PROGRAM IS CONFIDENTIAL AND PROPRIETARY TO BLUE CASK
 * SOFTWARE.  Any unauthorized use, reproduction, modification, or
 * disclosure of this program is strictly prohibited without the
 * express written permission of an authorized representative of
 * Blue Cask Software.
 ***********************************************************/
#ifndef GAME_ACCESS_H
#define GAME_ACCESS_H

#include <string>
#include <string.h>
#include <mysql++.h>
#include "DbAccess.h"
#include "../game/Game.h"
#include "../database/Storable.h"

class GameAccess : public DbAccess {

public:
	/**
	 * Return the singleton GameAccess instance.
	 * @returns the singleton GameAccess object
	 */
	static GameAccess * instance();

	/**
	 * Create a Game in the db
	 * @param storable the base object which points at a game
	 */
	void create(Storable * storable);

	/**
	 * Retrieve a Game object by ID
	 * @param id the id of the game we want to retrieve
	 * @returns storable object pointing to the game object
	 */
	Storable * read(int id);

	/**
	 * Update a Game in the db
	 * @param storable the base object which points at a game
	 */
	void update(Storable * storable);

	/**
	 * Select the ids of the games that are available to play (status = GS_NEW)
	 * @returns mysqlpp::StoreQueryResult holding ids of available games
	 */
	mysqlpp::StoreQueryResult selectAvailableIds();

	/**
	 * Attempt to reserve an available game by updating the game in the database
	 * if its status is GS_NEW.  This makes sure that the game was not reserved
	 * by another process since the selectAvailableIds() query.
	 * @param availableGameId int id of an available game
	 * @param reserveId int unique id that we want to reserve
	 * @returns bool - true if the game was updated (reserved) in the database,
	 * 		false otherwise.
	 */
	bool reserveGame(int availableGameId, int reserveId);

private:
	GameAccess();

	~GameAccess();

	static GameAccess * _instance;

	Game * rowToStorable(mysqlpp::Row row);
};

#endif
