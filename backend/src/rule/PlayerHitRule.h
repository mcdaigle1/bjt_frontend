/***********************************************************
 * Copyright 2012 Blue Cask Software. All rights reserved.
 *
 * THIS PROGRAM IS CONFIDENTIAL AND PROPRIETARY TO BLUE CASK
 * SOFTWARE.  Any unauthorized use, reproduction, modification, or
 * disclosure of this program is strictly prohibited without the
 * express written permission of an authorized representative of
 * Blue Cask Software.
 *
 * The player hit rules are held in a two dimensional vector. Each
 * element of the top vector represents a player hand and holds a
 * vector of dealer hands.  The indexes of the player vector represent:
 *
 * Vector Index: 0  1  2  3  4  5   6   7   8   9   10  11  12  13  14  15  16   17   18   19   20   21   22   23   24    25   26   27   28   29   30   31   32   33   34
 * Player Hand:  5  6  7  8  9  10  11  12  13  14  15  16  17  18  19  20  A,2  A,3  A,4  A,5  A,6  A,7  A,8  A,9  A,10  A,A  2,2  3,3  4,4  5,5  6,6  7,7  8,8  9,9  10,10
 *
 * Each of those rows holds a vector that represents dealer up cards:
 *
 * Vector Index: 0  1  2  3  4  5   6   7   8   9   10
 * Dealer Hand:  A  1  2  3  4  5   6   7   8   9   10/Face
 *
 * Each cell holds an int that represents the hit action as defined in the
 * PlayerHitRuleAction enum.
 ***********************************************************/
#ifndef PLAYER_HIT_RULE_H
#define PLAYER_HIT_RULE_H

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <map>
#include <mysql++.h>
#include "HitRule.h"
#include "../deck/Card.h"
#include "../game/Hand.h"
#include "../utility/VectorUtil.h"

class PlayerHitRule : public HitRule {
private:
	// db fields
	int _status;
	std::string _ruleMd5;
	std::string _ruleSet;
	IntVector2D * _ruleSetVector;

	static int NUM_PLAYER_HANDS;
	static int NUM_DEALER_HANDS;
	static int HARD_OFFSET;
	static int ACE_OFFSET;
	static int PAIR_OFFSET;
	static int HARD_ACE_VALUE;
	static std::string _playerHandAbbrev[];
	static std::string _dealerHandAbbrev[];
	static std::string _hitRuleActionAbbrev[];
	static const std::string idx_player_value_1;
	static const std::string idx_player_value_2;
	static const std::string idx_dealer_value;
	static const std::string idx_player_card_count;

public:

	/**
	 * Create a PlayerHitRule object with a given hitRuleId.  The hit rules will be read from
	 * the database and held in memory.
	 * @param hitRuleId An int that references a hit rule in the database.
	 */
	PlayerHitRule(mysqlpp::Row playerHitRuleRow);

	~PlayerHitRule();

	/**
	 * Get the status
	 * @returns int the status as an integer
	 */
	int getStatus();

	/**
	 * Get the MD5 for this rule
	 * @return string MD5 for the rule set
	 */
	std::string getRuleMd5();

	/**
	 * Get the rule set as a comma delimited string
	 * @return string comma delimited rules
	 */
	std::string getRuleSet();

	/**
	 * Determine the player hit action given the player's first card value, remaining card values
	 * dealer show card value and number of player cards.
	 * @param ruleInputs an integer value map with the values needed to make the hit action
	 * 		decision.  Required fields are
	 * 		idx_player_value_1 - int value representing the player's first card.  If there
	 *      	is an ace in the hand, it should be in this position.
	 * 		idx_player_value_2 - int value representing the sum of the remaining cards.
	 * 		idx_dealer_value - int value of the dealer's show card
	 * 		idx_player_card_count - int value holding the number of cards in the players hand.
	 * @return HitRuleAction representing the action to take.
	 */
	HitRuleAction getHitAction(Hand * playerHand, Hand * dealerHand);

	/**
	 * Print the player rules to log at info level
	 */
	void displayToLog();
};

#endif
