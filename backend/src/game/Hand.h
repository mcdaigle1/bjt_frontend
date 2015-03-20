/***********************************************************
 * Copyright 2012 Blue Cask Software. All rights reserved.
 *
 * THIS PROGRAM IS CONFIDENTIAL AND PROPRIETARY TO BLUE CASK
 * SOFTWARE.  Any unauthorized use, reproduction, modification, or
 * disclosure of this program is strictly prohibited without the
 * express written permission of an authorized representative of
 * Blue Cask Software.
 ***********************************************************/
#ifndef HAND_H
#define HAND_H

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <list>
#include <mysql++.h>
#include "../deck/Card.h"
#include "../database/Storable.h"
#include "../utility/VectorUtil.h"

typedef std::list<Card *> CardList;

enum HandOutcome {OC_WIN, OC_LOSE, OC_TIE};

class Hand : public Storable {

protected:

	CardList * _cards; // list of card objects in the hand
	int _value1; // the numeric value of the first card in the hand
	int _value2; // the numeric value of the remaining cards in the hand
	int _gameId; // the id of the game to which this hand belongs
	int _shoeId; // the shoe id from which this hand was dealt
	int _handSequence; // the sequence in the game in which this hand was played

	/*
	 * recalulate value1 and value2.
	 */
	void recalculateValues();

public:

	static const int NON_SPLIT_SEQUENCE;  // sequence place keeper value for non-split hands
	static const std::string HAND_OUTCOME_STRING[];  // string representation of hand outcome

	Hand();

	Hand(int gameId, Card * card1, Card * card2, int handSequence);

	Hand(int gameId, Card * card1, int handSequence);

//	/**
//	 * Save the hand to DB
//	 */
//	virtual void save() = 0;

	/**
	 * Get the value of the first card in the hand.  If there is at least one ace
	 * in the hand, the first card will be an ace
	 * @returns int numeric value of the first card (ace will return 1 ... face cards, 10)
	 */
	int getValue1();

	/**
	 * Get the value of all the card except the first
	 * @returns int numeric value of all cards except the first (ace will count as 1 ...
	 * 		face cards, 10)
	 */
	int getValue2();

	/**
	 * Get the final value of the hand.  This takes into consideration that an ace might
	 * be worth 1 or 11.
	 */
	int getFinalValue();

	/**
	 * Get the hand sequence.  The hand sequence is the nth hand in a game.  Note that
	 * a split hand counts as the same hand and has the same hand sequence.
	 * @returns int sequence of this hand.
	 */
	int getHandSequence();

	/**
	 * Add a card to the hand.  If the card is an ace and the first card is not already an
	 * ace, this card will be added to the front of the hand.
	 * @param card a pointer to the Card object we want to add.
	 */
	void addCard(Card * card);

	/**
	 * Get the count of cards in the hand
	 * @returns int number of cards in the hand
	 */
	int cardCount();

	/**
	 * Determine if the hand has busted
	 * @returns bool - true if the combined card values > 21, false otherwise
	 */
	bool isBusted();

};

#endif
