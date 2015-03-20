/***********************************************************
 * Copyright 2012 Blue Cask Software. All rights reserved.
 *
 * THIS PROGRAM IS CONFIDENTIAL AND PROPRIETARY TO BLUE CASK
 * SOFTWARE.  Any unauthorized use, reproduction, modification, or
 * disclosure of this program is strictly prohibited without the
 * express written permission of an authorized representative of
 * Blue Cask Software.
 *
 * The dealer hit rules are held in a vector. Each element represents
 * a dealer hand and holds a vector of dealer hands.
 *
 * Vector Index: 0  1  2  3  4  5  6   7   8   9   10  11  12  13  14  15  16  17   18   19   20   21   22   23   24   25   26
 * Dealer Hand:  4  5  6  7  8  9  10  11  12  13  14  15  16  17  18  19  20  A,A  A,2  A,3  A,4  A,5  A,6  A,7  A,8  A,9  A,10
 *
 * Each cell holds an int that represents the hit action as defined in the
 * DealerHitRuleAction enum.
 ***********************************************************/
#ifndef DEALER_HIT_RULE_H
#define DEALER_HIT_RULE_H

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <map>
#include <mysql++.h>
#include "./HitRule.h"
#include "../deck/Card.h"
#include "../game/Hand.h"
#include "../utility/VectorUtil.h"

//enum DealerHitRuleStatus {DHR_ACTIVE, DHR_INACTIVE};
//enum DealerHitRuleAction {DHR_HIT, DHR_STAND};

class DealerHitRule : public HitRule {
private:
	int _DealerHitRuleId;
	std::string _createTime;
	std::string _modTime;
	std::string _description;
	int _status;
	std::string _ruleMd5;
	std::string _ruleSet;
	IntVector * _ruleSetVector;

	static int NUM_DEALER_HANDS;
	static int HARD_OFFSET;
	static int ACE_OFFSET;
	static int HARD_ACE_VALUE;
	static std::string _dealerHandAbbrev[];
	static std::string _hitRuleActionAbbrev[];
	static const std::string idx_dealer_value_1;
	static const std::string idx_dealer_value_2;
public:

	/**
	 * Create a DealerHitRule object with a given dealer hit rule id.  The hit rules will
	 * be read from the database and held in memory.
	 * @param hitRuleId An int that references a dealer hit rule in the database.
	 */
	DealerHitRule(mysqlpp::Row dealerHitRuleRow);

	~DealerHitRule();

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
	 * Determine the dealer hit action given the dealer's first card value and remaining
	 * card values
	 * @param ruleInputs an integer value map with the values needed to make the hit action
	 * 		decision.  Required fields are
	 * 		idx_dealer_value_1 The int value representing the dealer's first card.  If there
	 *      	is an ace in the hand, it should be in the playerValue1.
	 * 		idx_dealer_value_2 The int value representing the sum of the remaining cards.
	 * @return HitRuleAction representing the action to take.
	 */
	HitRuleAction getHitAction(Hand * dealerHand);

	/**
	 * Print the dealer rules to log at info level
	 */
	void displayToLog();

};

#endif
