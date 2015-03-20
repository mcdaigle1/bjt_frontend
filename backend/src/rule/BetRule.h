/***********************************************************
 * Copyright 2012 Blue Cask Software. All rights reserved.
 *
 * THIS PROGRAM IS CONFIDENTIAL AND PROPRIETARY TO BLUE CASK
 * SOFTWARE.  Any unauthorized use, reproduction, modification, or
 * disclosure of this program is strictly prohibited without the
 * express written permission of an authorized representative of
 * Blue Cask Software.
 ***********************************************************/
#ifndef BET_RULE_H
#define BET_RULE_H

#include <stdio.h>
#include <stdlib.h>
#include "../database/Storable.h"

class BetRule : public Storable {
private:
	int _BetRuleId;

public:

	/**
	 * Create a BetRule object with a given bet rule id.  The bet rules will
	 * be read from the database and held in memory.
	 * @param betRuleId An int that references a bet hit rule in the database.
	 */
	BetRule(int betRuleId);

	~BetRule();

	/**
	 * Return the unit amount of the next bet.
	 */
	int nextBet();

	/**
	 * Print the betting rules to log at info level
	 */
	void displayToLog();

};

#endif
