/***********************************************************
 * Copyright 2012 Blue Cask Software. All rights reserved.
 *
 * THIS PROGRAM IS CONFIDENTIAL AND PROPRIETARY TO BLUE CASK
 * SOFTWARE.  Any unauthorized use, reproduction, modification, or
 * disclosure of this program is strictly prohibited without the
 * express written permission of an authorized representative of
 * Blue Cask Software.
 ***********************************************************/
#ifndef DEALER_HAND_H
#define DEALER_HAND_H

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <list>
#include <mysql++.h>
#include "Hand.h"
#include "../deck/Card.h"
#include "../utility/VectorUtil.h"

class DealerHand : public Hand {
private:

public:

	/**
	 * Creates a Hand object initialized with the intial two cards and hand sequence.  This
	 * constructor is for hands that are not the result of a split.  The main constructor is
	 * called with the NON_SPLIT_SEQUENCE value as the handSubSequence and parentSequence
	 * @param gameId int id of the game in which this hand was played
	 * @param card1 pointer to the first card object
	 * @param card2 pointer to the second card object
	 * @param handSequence the order this hand was played in the game
	 */
	DealerHand(int gameId, Card * card1, Card * card2, int handSequence);

	DealerHand(mysqlpp::Row shoeRow);

	~DealerHand();

//	/**
//	 * Save the dealer hand to the database
//	 */
//	void save();

};

#endif
