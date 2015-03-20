/***********************************************************
 * Copyright 2012 Blue Cask Software. All rights reserved.
 *
 * THIS PROGRAM IS CONFIDENTIAL AND PROPRIETARY TO BLUE CASK
 * SOFTWARE.  Any unauthorized use, reproduction, modification, or
 * disclosure of this program is strictly prohibited without the
 * express written permission of an authorized representative of
 * Blue Cask Software.
 ***********************************************************/
#include "BetRule.h"
//#include "../database/BetRuleAccess.h"
#include "../utility/Logger.h"
#include "../utility/StringUtil.h"
#include "../exception/RuleException.h"

using namespace std;

BetRule::BetRule(int betRuleId) : Storable() {
//	BetRuleAccess * BetRuleAccess = new BetRuleAccess();
//	mysqlpp::StoreQueryResult result = BetRuleAccess->selectById(BetRuleId);

//	delete BetRuleAccess;
}

BetRule::~BetRule() {

}

int BetRule::nextBet() {
	return 1;
}

void BetRule::displayToLog() {

}
