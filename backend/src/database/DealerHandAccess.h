/***********************************************************
 * Copyright 2012 Blue Cask Software. All rights reserved.
 *
 * THIS PROGRAM IS CONFIDENTIAL AND PROPRIETARY TO BLUE CASK
 * SOFTWARE.  Any unauthorized use, reproduction, modification, or
 * disclosure of this program is strictly prohibited without the
 * express written permission of an authorized representative of
 * Blue Cask Software.
 ***********************************************************/
#ifndef DEALER_HAND_ACCESS_H
#define DEALER_HAND_ACCESS_H

#include <string>
#include <string.h>
#include <mysql++.h>
#include <unordered_map>
#include "DbAccess.h"
#include "../game/DealerHand.h"
#include "../exception/InvalidArgumentException.h"

class DealerHandAccess: public DbAccess {

public:
	/**
	 * Return the singleton DealerHandAccess instance.
	 * @returns the singleton DealerHandAccess object
	 */
	static DealerHandAccess * instance();

	/**
	 * Create a DealerHand in the db
	 * @param storable the base object which points at a hand
	 */
	void create(Storable * storable);

	/**
	 * Retrieve a DealerHand object by ID
	 * @param id the id of the hand we want to retrieve
	 * @returns storable object pointing to the hand object
	 */
	Storable * read(int id);

	/**
	 * Update a DealerHand in the db
	 * @param storable the base object which points at a hand
	 */
	void update(Storable * storable);


	/**
	 * Insert a dealer hand record
	 * @param gameId int the game id
	 * @param shoeId int shoe id
	 * @param sequence int sequence of this hand in the game
	 * @param cardList string representation of postions (0 - 51) of each card in hand
	 */
	void insert(int gameId, int shoeId, int sequence, std::string cardList);

	/**
	 * Update a hand with given fields
	 * @param id int id of hand to update
	 * @param fields unordered map holding column name / value pairs for columns to
	 * 		update.
	 */
	void update(int id, std::unordered_map<std::string, std::string> fields);

	/**
	 * Select all dealer hands for a given game
	 * @param gameId int id of game for which to get hands
	 * @returns mysqlpp::StoreQueryResult holding hands that match game
	 */
	mysqlpp::StoreQueryResult selectByGame(int gameId);

private:
	DealerHandAccess();

	~DealerHandAccess();

	static DealerHandAccess * _instance;

	DealerHand * rowToStorable(mysqlpp::Row row);
};

#endif
