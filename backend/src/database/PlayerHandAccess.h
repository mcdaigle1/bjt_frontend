/***********************************************************
 * Copyright 2012 Blue Cask Software. All rights reserved.
 *
 * THIS PROGRAM IS CONFIDENTIAL AND PROPRIETARY TO BLUE CASK
 * SOFTWARE.  Any unauthorized use, reproduction, modification, or
 * disclosure of this program is strictly prohibited without the
 * express written permission of an authorized representative of
 * Blue Cask Software.
 ***********************************************************/
#ifndef PLAYER_HAND_ACCESS_H
#define PLAYER_HAND_ACCESS_H

#include <string>
#include <string.h>
#include <mysql++.h>
#include <unordered_map>
#include "DbAccess.h"
#include "../game/PlayerHand.h"
#include "../exception/InvalidArgumentException.h"

class PlayerHandAccess: public DbAccess {

public:
	/**
	 * Return the singleton PlayerHandAccess instance.
	 * @returns the singleton PlayerHandAccess object
	 */
	static PlayerHandAccess * instance();

	/**
	 * Create a PlayerHand in the db
	 * @param storable the base object which points at a player hand
	 */
	void create(Storable * storable);

	/**
	 * Retrieve a PlayerHand object by ID
	 * @param id the id of the player hand we want to retrieve
	 * @returns storable object pointing to the player hand object
	 */
	Storable * read(int id);

	/**
	 * Update a PlayerHand in the db
	 * @param storable the base object which points at a player hand
	 */
	void update(Storable * storable);

//	 * Insert a player hand record
//	 * @param playerId int the player id
//	 * @param gameId int the game id
//	 * @param shoeId int shoe id
//	 * @param sequence int sequence of this hand in the game
//	 * @param subSequence int subsequence in this hand, 0 if this the primary
//	 * 		hand, incremented for each split hand in the sequence
//	 * @param parentSequence in sequence of hand from which this was split, if
//	 * 		applicable, PlayerHand::NON_SPLIT_SEQUENCE otherwise.
//	 * @param bet int the amount bet on this hand
//	 * @param bankroll int amount left in bankroll after hand is played
//	 * @param cardList string representation of postions (0 - 51) of each card in hand
//	 * @param int outcome of the hand.  The string representation of this int can be
//	 * 		found in PlayerHand::HAND_OUTCOME_STRING
//	 */
//	void insert(int playerId, int gameId, int shoeId, int sequence, int subSequence,
//			int parentSequence, int bet, int bankroll, std::string cardList, int outcome);
//
//	/**
//	 * Update a hand with given fields
//	 * @param id int id of hand to update
//	 * @param fields unordered map holding column name / value pairs for columns to
//	 * 		update.
//	 */
//	void update(int id, std::unordered_map<std::string, std::string> fields);

	/**
	 * Select all hands for a given game, sorted by sequence and subsequence
	 * @param gameId int id of game for which to get hands
	 * @returns mysqlpp::StoreQueryResult holding hands that match game
	 */
	mysqlpp::StoreQueryResult selectByGame(int gameId);

private:
	PlayerHandAccess();

	~PlayerHandAccess();

	static PlayerHandAccess * _instance;

	PlayerHand * rowToStorable(mysqlpp::Row row);
};

#endif
