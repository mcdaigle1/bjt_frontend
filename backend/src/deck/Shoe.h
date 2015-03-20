/***********************************************************
 * Copyright 2012 Blue Cask Software. All rights reserved.
 *
 * THIS PROGRAM IS CONFIDENTIAL AND PROPRIETARY TO BLUE CASK
 * SOFTWARE.  Any unauthorized use, reproduction, modification, or
 * disclosure of this program is strictly prohibited without the
 * express written permission of an authorized representative of
 * Blue Cask Software.
 ***********************************************************/
#ifndef SHOE_H
#define SHOE_H

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <vector>
#include <mysql++.h>
#include "Card.h"
//#include "../database/ShoeAccess.h"
#include "../database/Storable.h"

typedef std::vector<Card *> CardVector;

class Shoe : public Storable {

private:
	// db fields
	int _numDecks; // number of decks in this shoe
	int _gameId; // game this shoe belongs to
	int _sequence; // sequence in the game in which this shoe was played
	std::string _cards; // string representation of cards in shoe
	int _cutPosition; // position of cut card in shoe

	bool * _sortedShoeArray;
	int _numCards;
	CardVector * _shuffledShoe;
	std::string _cardMd5;
	int _currCardPos;

	static int _maxSixShoeCount;

//	ShoeAccess * getShoeAccess(int numDecks);

	void initSortedShoeArray();

	CardVector * cardStringToVector();

	/**
	 * Shuffle the shoe
	 */
	void shuffleShoe();

public:
	static const bool CREATE_NEW_SHOE;
	static const bool USE_DB_SHOE;

	/**
	 * Create a new shoe object, which initializes, and shuffles
	 * the decks
	 */
	Shoe();

	/**
	 * Create a shoe object from given database info
	 * @param shoeRow mysqlpp::Row single row holding shoe data from db
	 */
	Shoe(mysqlpp::Row shoeRow);

	/**
	 * Create a new shoe object which holds a shuffled shoe of the given number of decks
	 * @params numDecks int representing number of decks in the shoe.
	 */
	Shoe(int numDecks);

	~Shoe();

	/**
	 * Get the number of decks in shoe
	 * @returns int number of decks in shoe
	 */
	int getNumDecks();

	/**
	 * Get the id of the game in which this shoe was played
	 * @returns int game id
	 */
	int getGameId();

	/**
	 * Get the sequence that this shoe was played in the game
	 * @returns int sequence
	 */
	int getSequence();

	/**
	 * Get the cards represented as a string
	 * @returns string cards
	 */
	std::string getCards();

	/**
	 * Get the position of the cut card
	 * @returns int cut position
	 */
	int getCutPosition();

	/**
	 * Get the Md5 of the string representation of the shoe
	 * @returns string md5 hash of the string representation of this shoe
	 */
	std::string getMd5();

	/**
	 * Deal out the next available card in the shoe
	 * @returns Card object holding the next card in the shoe
	 */
	Card * dealCard();

	/**
	 * Determine if the current card in the shoe is past the cut card
	 * @returns bool - true if current card position is greater than cut
	 * 		position, false otherwise.
	 */
	bool pastCut();

	void displayShuffledShoe();

	std::string toString();
};

#endif
