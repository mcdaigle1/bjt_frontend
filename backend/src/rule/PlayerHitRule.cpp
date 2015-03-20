/***********************************************************
 * Copyright 2012 Blue Cask Software. All rights reserved.
 *
 * THIS PROGRAM IS CONFIDENTIAL AND PROPRIETARY TO BLUE CASK
 * SOFTWARE.  Any unauthorized use, reproduction, modification, or
 * disclosure of this program is strictly prohibited without the
 * express written permission of an authorized representative of
 * Blue Cask Software.
 ***********************************************************/
#include "PlayerHitRule.h"
#include "../database/PlayerHitRuleAccess.h"
#include "../utility/Logger.h"
#include "../utility/StringUtil.h"
#include "../exception/RuleException.h"

using namespace std;

int PlayerHitRule::NUM_DEALER_HANDS = 10;
int PlayerHitRule::NUM_PLAYER_HANDS = 35;
/*
 * These offsets put us at a place in the rule table where we can use
 * the card values to get to the correct hit rule
 *
 * HARD_OFFSET - the first hard rule (no A,X or doubles) starts at row zero
 * in the rule table with card value five.  By setting the offset to -5
 * we can use the card values to get to the rule row.
 *
 * ACE_OFFSET - if the first card is ace, and the second card is 10 or
 * less, then use the ace rules.  These first of these starts at row 16
 * with A,2.  By setting the offset to 14, we can use the value of the
 * second card to get to the rule row.
 *
 * PAIR_OFFSET - if this is a pair, the rules start at row 25 with A,A.  By
 * setting the offset to 24, we can use the value of one of the cards to get
 * to the rule row.
 */
int PlayerHitRule::HARD_OFFSET = -5;
int PlayerHitRule::ACE_OFFSET = 14;
int PlayerHitRule::PAIR_OFFSET = 24;
int PlayerHitRule::HARD_ACE_VALUE = 11;
const string PlayerHitRule::idx_player_value_1 = "IDX_PLAYER_VALUE_1";
const string PlayerHitRule::idx_player_value_2 = "IDX_PLAYER_VALUE_2";
const string PlayerHitRule::idx_dealer_value = "IDX_DEALER_VALUE";
const string PlayerHitRule::idx_player_card_count = "IDX_PLAYER_CARD_COUNT";

string PlayerHitRule::_playerHandAbbrev[] = {"5", "6", "7", "8", "9", "10", "11", "12", "13", "14",
			"15", "16", "17", "18", "19", "20", "A,2", "A,3", "A,4", "A,5", "A,6", "A,7",
			"A,8", "A,9", "A,10", "A,A", "2,2", "3,3", "4,4", "5,5", "6,6", "7,7", "8,8",
			"9,9", "10,10"};
string PlayerHitRule::_dealerHandAbbrev[] = {"A", "2", "3", "4", "5", "6", "7", "8", "9", "10"};
string PlayerHitRule::_hitRuleActionAbbrev[] = {"SR","HT", "ST", "DH", "SP", "DS"};

PlayerHitRule::PlayerHitRule(mysqlpp::Row playerHitRuleRow) {
	PlayerHitRuleAccess * playerHitRuleAccess =
			(PlayerHitRuleAccess *)PlayerHitRuleAccess::instance();

	_id = StringUtil::toInt(playerHitRuleRow["id"].data());
	playerHitRuleRow["create_time"].to_string(_createTime);
	playerHitRuleRow["mod_time"].to_string(_modTime);
	playerHitRuleRow["description"].to_string(_description);
	_status = StringUtil::toInt(playerHitRuleRow["status"].data());
	playerHitRuleRow["rule_md5"].to_string(_ruleMd5);
	playerHitRuleRow["rule_set"].to_string(_ruleSet);
	_ruleSetVector = VectorUtil::from2DIntString(&_ruleSet);

	displayToLog();
}

PlayerHitRule::~PlayerHitRule() {
	VectorUtil::deleteVector(_ruleSetVector);
}

int PlayerHitRule::getStatus() {
	return _status;
}

string PlayerHitRule::getRuleMd5() {
	return _ruleMd5;
}

string PlayerHitRule::getRuleSet() {
	return _ruleSet;
}

HitRuleAction PlayerHitRule::getHitAction(Hand * playerHand, Hand * dealerHand) {
	HitRuleAction hitRuleAction;
	int playerOffset;

	int playerValue1 = playerHand->getValue1();
	int playerValue2 = playerHand->getValue2();
	int dealerValue = dealerHand->getValue1();
	int playerCardCount = playerHand->cardCount();

	// whoops, we shoudn't try to get an action for a busted hand
	if ((playerValue1 + playerValue2) > 21) {
		ostringstream errMsg; errMsg << "Can't get player hit action.  Player busted at: "
			<< playerValue1 + playerValue2;
		throw RuleException(errMsg.str());
	}

	// always stand on 21
	if ((playerValue1 + playerValue2) == 21) {
		return HR_STAND;
	}

	if (playerCardCount == 2 && (playerValue1 == playerValue2)) { // this is a pair
		playerOffset = PAIR_OFFSET + playerValue1;
	} else if ((playerValue1 == ACE_VAL) && (playerValue2 <= TEN_VAL)) { // soft ace
		playerOffset = ACE_OFFSET + playerValue2;
	} else if (playerValue1 == ACE_VAL) { // hard ace
		playerOffset = HARD_OFFSET + HARD_ACE_VALUE + playerValue2;
	} else {  // hard values
		playerOffset = HARD_OFFSET + playerValue1 + playerValue2;
	}

	// get the action from the player hit rule action table
	int * offsetValue = _ruleSetVector->at(playerOffset)->at(dealerValue - 1);
	hitRuleAction = (HitRuleAction)*offsetValue;

	// if our rule is to double/hit and we have more than two cards, change
	// action to hit
	if ((hitRuleAction == HR_DOUBLE) && (playerCardCount > 2)) {
		hitRuleAction = HR_HIT;
	}

	// if our rule is to double/stand and we have more than two cards, change
	// action to stand
	if ((hitRuleAction == HR_DOUBLE_STAND) && (playerCardCount > 2)) {
		hitRuleAction = HR_STAND;
	}

	return hitRuleAction;
}

void PlayerHitRule::displayToLog() {
	Logger::info("      PLAYER HIT RULES:");

	// log the top row which is the dealer cards
	ostringstream dealerRow; dealerRow << StringUtil::padLeft("", 5);
	for (int i = 0; i < NUM_DEALER_HANDS; i++) {
		dealerRow << StringUtil::padLeft(_dealerHandAbbrev[i], 5);
	}
	Logger::info(dealerRow);

	// log each of the player rules
	for (int i = 0; i < _ruleSetVector->size(); i++) {
		ostringstream playerRow; playerRow << StringUtil::padLeft(_playerHandAbbrev[i], 5);
		for (int j = 0; j < _ruleSetVector->at(i)->size(); j++) {
			int * hitRule = _ruleSetVector->at(i)->at(j);
			playerRow << StringUtil::padLeft(_hitRuleActionAbbrev[*hitRule], 5);
		}
		Logger::info(playerRow);
	}

}
