/***********************************************************
 * Copyright 2012 Blue Cask Software. All rights reserved.
 *
 * THIS PROGRAM IS CONFIDENTIAL AND PROPRIETARY TO BLUE CASK
 * SOFTWARE.  Any unauthorized use, reproduction, modification, or
 * disclosure of this program is strictly prohibited without the
 * express written permission of an authorized representative of
 * Blue Cask Software.
 ***********************************************************/
#ifndef CARD_H
#define CARD_H

#include <string.h>
#include <string>
#include <sstream>
#include <iostream>
#include "../database/Storable.h"

/** enum - the four suits */
enum CardSuit { CLUB, HEART, DIAMOND, SPADE };

/** enum - the card types, from ace = 0 to king = 12 */
enum CardIndex { ACE_INDEX, TWO_INDEX, THREE_INDEX, FOUR_INDEX, FIVE_INDEX, SIX_INDEX,
	SEVEN_INDEX, EIGHT_INDEX, NINE_INDEX, TEN_INDEX, JACK_INDEX, QUEEN_INDEX, KING_INDEX };

/** enum - the card values, from ace = 1 to face cards which = 10 */
enum CardValue { ACE_VAL = 1, TWO_VAL, THREE_VAL, FOUR_VAL, FIVE_VAL, SIX_VAL,
	SEVEN_VAL, EIGHT_VAL, NINE_VAL, TEN_VAL, JACK_VAL = 10, QUEEN_VAL = 10, KING_VAL = 10 };

class Card : public Storable {

private:
	static std::string _suitAbbrev[];  // holds abbreviated names of suits
	static std::string _nameAbbrev[]; // holds abbreviated names of cards by index

	int _absPosition; // holds the absolute position of the card in the deck
	CardSuit _suit;   // the suit of this card
	CardIndex _index; // the index of this card

	Card();

public:

	/**
	 * Creates a Card object initialized with suit and value
	 * @param position An integer number between 0 and 51 inclusive representing the
	 * 		position in a deck that is sorted A-K for each suit C,H,D and S.
	 */
	Card(int position);

	~Card();

	/**
	 * Get the numeric value of a card.  Ace will return 1 and face values will return 10. All
	 * other cards will return their face value.
	 * @returns int numeric value of card
	 */
	int getNumericValue();

	/**
	 * Get index value of a card, starting at Ace = 0 through King = 12.
	 * @returns CardIndex enum that references the card index value
	 */
	CardIndex getIndex();

	/**
	 * Get the absolute position of a card in the deck that is sorted A-K for each suit
	 * C,H,D and S.
	 * @returns int absolute position of card in the deck
	 */
	int getPosition();

	/**
	 * Check if this card is an ace
	 * @returns bool true if this card is an ace
	 */
	bool isAce();

	/**
	 * Display this card object to the log file as debug
	 */
	void display();

	/**
	 * Get the card name by index
	 * @param nameIndex int index of the card
	 * @returns string name of the card
	 */
	static std::string getNameStr(int nameIndex);

	/**
	 * Get the card suit by index
	 * @param nameIndex int index of the suit
	 * @returns string name of the suit
	 */
	static std::string getSuitStr(int suitIndex);

	/**
	 * Convert a card position in the deck to a human readable string
	 * @param position int position of card in deck.  Number must be between 0 and 51
	 * 		inclusive representing the position in a deck that is sorted A-K for each
	 * 		suit C,H,D and S.
	 * @returns string representation of the card
	 */
	static std::string posToString(int position);





};

#endif
