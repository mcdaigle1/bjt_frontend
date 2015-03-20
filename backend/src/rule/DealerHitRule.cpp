/***********************************************************
 * Copyright 2012 Blue Cask Software. All rights reserved.
 *
 * THIS PROGRAM IS CONFIDENTIAL AND PROPRIETARY TO BLUE CASK
 * SOFTWARE.  Any unauthorized use, reproduction, modification, or
 * disclosure of this program is strictly prohibited without the
 * express written permission of an authorized representative of
 * Blue Cask Software.
 ***********************************************************/
#include "DealerHitRule.h"
#include "../database/DealerHitRuleAccess.h"
#include "../utility/Logger.h"
#include "../utility/StringUtil.h"
#include "../exception/RuleException.h"

using namespace std;

int DealerHitRule::NUM_DEALER_HANDS = 27;
/*
 * These offsets put us at a place in the rule vector where we can use
 * the card values to get to the correct hit rule
 *
 * HARD_OFFSET - the first hard rule (no A,X or doubles) starts at row zero
 * in the rule table with card value four.  By setting the offset to -4
 * we can use the card values to get to the rule row.
 *
 * ACE_OFFSET - if the first card is ace, and the second card is 10 or
 * less, then use the ace rules.  These first of these starts at row 16
 * with A,2.  By setting the offset to 14, we can use the value of the
 * second card to get to the rule row.
 *
 */
int DealerHitRule::HARD_OFFSET = -5;
int DealerHitRule::ACE_OFFSET = 16;
int DealerHitRule::HARD_ACE_VALUE = 11;
const string DealerHitRule::idx_dealer_value_1 = "IDX_DEALER_VALUE_1";
const string DealerHitRule::idx_dealer_value_2 = "IDX_DEALER_VALUE_2";

string DealerHitRule::_dealerHandAbbrev[] = {"4", "5", "6", "7", "8", "9", "10", "11", "12",
		"13", "14", "15", "16", "17", "18", "19", "20", "A,A", "A,2", "A,3", "A,4", "A,5",
		"A,6", "A,7", "A,8", "A,9", "A,10"};
// TODO _hitRuleActionAbbrev is repeated in playerhitrule.  Move this to central location.
string DealerHitRule::_hitRuleActionAbbrev[] = {"SR","HT", "ST", "DH", "SP", "DS"};

DealerHitRule::DealerHitRule(mysqlpp::Row dealerHitRuleRow) {
	DealerHitRuleAccess * dealerHitRuleAccess =
			(DealerHitRuleAccess *)DealerHitRuleAccess::instance();

	_id = StringUtil::toInt(dealerHitRuleRow["id"].data());
	dealerHitRuleRow["create_time"].to_string(_createTime);
	dealerHitRuleRow["mod_time"].to_string(_modTime);
	dealerHitRuleRow["description"].to_string(_description);
	_status = StringUtil::toInt(dealerHitRuleRow["status"].data());
	dealerHitRuleRow["rule_md5"].to_string(_ruleMd5);
	dealerHitRuleRow["rule_set"].to_string(_ruleSet);
	_ruleSetVector = VectorUtil::fromIntString(&_ruleSet);

	displayToLog();
}

DealerHitRule::~DealerHitRule() {
	VectorUtil::deleteVector(_ruleSetVector);
}

int DealerHitRule::getStatus() {
	return _status;
}

string DealerHitRule::getRuleMd5() {
	return _ruleMd5;
}

string DealerHitRule::getRuleSet() {
	return _ruleSet;
}

HitRuleAction DealerHitRule::getHitAction(Hand * dealerHand) {
	HitRuleAction dealerHitAction;
	int dealerOffset;

	int dealerValue1 = dealerHand->getValue1();
	int dealerValue2 = dealerHand->getValue2();

	if ((dealerValue1 + dealerValue2) > 21) {
		ostringstream errMsg; errMsg << "Can't get dealer hit action.  Dealer busted at: "
			<< dealerValue1 + dealerValue2;
		throw RuleException(errMsg.str());
	}

    if ((dealerValue1 == ACE_VAL) && (dealerValue2 <= TEN_VAL)) { // soft ace
    	dealerOffset = ACE_OFFSET + dealerValue2;
	} else if (dealerValue1 == ACE_VAL) { // hard ace
		dealerOffset = HARD_ACE_VALUE + dealerValue2;
	} else {  // hard values
		dealerOffset = HARD_OFFSET + dealerValue1 + dealerValue2;
	}

	int * offsetValue = _ruleSetVector->at(dealerOffset);
	dealerHitAction = (HitRuleAction)*offsetValue;

	return dealerHitAction;
}

void DealerHitRule::displayToLog() {
	Logger::info("      DEALER HIT RULES:");

	// log the top row which is the dealer cards
	ostringstream dealerRow;
	for (int i = 0; i < 10; i++) {
		dealerRow << StringUtil::padLeft(_dealerHandAbbrev[i], 5);
	}
	Logger::info(dealerRow);

	// log each of the dealer rules
	ostringstream playerRow;
	for (int i = 0; i < 10; i++) {
		int * hitRule = _ruleSetVector->at(i);
		playerRow << StringUtil::padLeft(_hitRuleActionAbbrev[*hitRule], 5);
	}
	Logger::info(playerRow);

	Logger::info("");

	// log the top row which is the dealer cards
	ostringstream dealerRow2;
	for (int i = 10; i < NUM_DEALER_HANDS; i++) {
		dealerRow2 << StringUtil::padLeft(_dealerHandAbbrev[i], 5);
	}
	Logger::info(dealerRow2);

	// log each of the dealer rules
	ostringstream playerRow2;
	for (int i = 10; i < _ruleSetVector->size(); i++) {
		int * hitRule = _ruleSetVector->at(i);
		playerRow2 << StringUtil::padLeft(_hitRuleActionAbbrev[*hitRule], 5);
	}
	Logger::info(playerRow2);
}
