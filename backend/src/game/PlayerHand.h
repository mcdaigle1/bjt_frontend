/***********************************************************
 * Copyright 2012 Blue Cask Software. All rights reserved.
 *
 * THIS PROGRAM IS CONFIDENTIAL AND PROPRIETARY TO BLUE CASK
 * SOFTWARE.  Any unauthorized use, reproduction, modification, or
 * disclosure of this program is strictly prohibited without the
 * express written permission of an authorized representative of
 * Blue Cask Software.
 ***********************************************************/
#ifndef PLAYER_HAND_H
#define PLAYER_HAND_H

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <list>
#include <mysql++.h>
#include "Hand.h"
#include "../deck/Card.h"
#include "../utility/VectorUtil.h"

class PlayerHand : public Hand {
private:
	int _playerId;  // the ID of the player playing the hand.
	int _handSubSequence; // the hand subsequence, set to 0 for initial hands and
                          // incremented for split hands
	int _parentSubSequence; // the subsequence id of the hand from which we split.  This is
	                        // set to NON_SPLIT_SEQUENCE if this is not a split hand.
	int _bet; // the amount bet
	int _bankroll; // the amount the player has left after the hand
	HandOutcome _outcome; // the outcome of this hand versus the dealers

public:

	static const int NON_SPLIT_SEQUENCE;
	static const std::string HAND_OUTCOME_STRING[];

	/**
	 * Creates a Hand object initialized with one intial cards and hand sequence ids.
	 * This constructor is for hands that get created as the result of a split.  Only
	 * one card get set initially.
	 * @param gameId int id of the game in which this hand was played
	 * @param card1 pointer to the first card object
	 * @param handSequence int sequence this hand was played in the game
	 * @param handSubSequence int subsequence if this hand was a result of a split. Value is
	 * 		NON_SPLIT_SEQUENCE if this hand is not the result of a split
	 * @param parentSequence int sequence number of the hand this was split from.  Value
	 * 		is NON_SPLIT_SEQUENCE if this hand is not the result of a split
	 */
	PlayerHand(int gameId, Card * card1, int handSequence, int handSubSequence, int parentSequence);

	/**
	 * Creates a Hand object initialized with the intial two cards and hand sequence.  This
	 * constructor is for hands that are not the result of a split.  The main constructor is
	 * called with the NON_SPLIT_SEQUENCE value as the handSubSequence and parentSequence
	 * @param gameId int id of the game in which this hand was played
	 * @param card1 pointer to the first card object
	 * @param card2 pointer to the second card object
	 * @param handSequence int sequence this hand was played in the game
	 */
	PlayerHand(int gameId, Card * card1, Card * card2, int handSequence);

	PlayerHand(mysqlpp::Row shoeRow);

	~PlayerHand();

//	/**
//	 * Save the player hand to the database
//	 */
//	void save();

	/**
	 * Get the hand subsequence.  This is necessary because it is possible to have multiple
	 * split hands from one original hand. The original hand will have a subsequence of 0 and
	 * split hands will increment as they are created.
	 * @returns int subsequence of this hand.
	 */
	int getHandSubSequence();

	/**
	 * Get the parent sub sequence.  If this hand is the result of a split, the parent sequence
	 * will be the subsequence of the hand from which this one was created, Otherwise, it will
	 * be NON_SPLIT_SEQUENCE.  This is necessary because it is possibly allowed to split from
	 * a previously split hand and we want to be able to track that case.
	 * @returns int parent subsequence from which this hand was created.
	 */
	int getParentSubSequence();

	/**
	 * get the outcome as a string
	 * @returns string representation of outcome
	 */
	std::string getOutcomeAbbrev();

	/*
	 * Set the outcome of the hand
	 * @params outcome a value of HandOutcome type to OC_WIN, OC_LOSE, or OC_TIE
	 */
	void setOutcome(HandOutcome outcome);

	/**
	 * Replace the second card in the hand.  This needs to be done when the hand is split.
	 * It is only valid when there are two cards in the hand.
	 * @param card pointer to the card object that will be set as the second card in the hand.
	 * @returns pointer to the card object that was replaced.
	 */
	Card * replaceCard2(Card * card);

	/**
	 * Checks to see if this hand is the result of a split and only has one card initialized
	 * so far.
	 * @returns bool true if this hand was the result of a spit and only has one card so far,
	 * 		false otherwise.
	 */
	bool isRawSplitHand();
};

#endif
