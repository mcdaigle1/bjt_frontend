/***********************************************************
 * Copyright 2012 Blue Cask Software. All rights reserved.
 *
 * THIS PROGRAM IS CONFIDENTIAL AND PROPRIETARY TO BLUE CASK
 * SOFTWARE.  Any unauthorized use, reproduction, modification, or
 * disclosure of this program is strictly prohibited without the
 * express written permission of an authorized representative of
 * Blue Cask Software.
 ***********************************************************/
#include "PlayerHand.h"
#include "../database/PlayerHandAccess.h"
#include "../utility/Logger.h"
#include "../utility/StringUtil.h"
#include "../utility/VectorUtil.h"
#include "../exception/HandException.h"

using namespace std;

const int PlayerHand::NON_SPLIT_SEQUENCE = -1;
const string PlayerHand::HAND_OUTCOME_STRING[] = {"WON","LOST","TIED"};

PlayerHand::PlayerHand(int gameId, Card * card1, int handSequence, int handSubSequence,
		int parentSequence) : Hand(gameId, card1, handSequence) {
	_id = 1; //TODO real player ID here
	_bet = 1000; // TODO real bet here
	_handSubSequence = handSubSequence;
	_parentSubSequence = parentSequence;
}

PlayerHand::PlayerHand(int gameId, Card * card1, Card * card2, int handSequence) :
		Hand(gameId, card1, card2, handSequence) {
	_id = 1; //TODO real player ID here
	_bet = 1000; // TODO real bet here
	_handSubSequence = 0; // the intial hand has a subsequence of 0
	_parentSubSequence = NON_SPLIT_SEQUENCE;
}

PlayerHand::PlayerHand(mysqlpp::Row playerRow) {
	_id = StringUtil::toInt(playerRow["id"].data());
	playerRow["create_time"].to_string(_createTime);
	playerRow["mod_time"].to_string(_modTime);
	playerRow["description"].to_string(_description);
	_playerId = StringUtil::toInt(playerRow["player_id"].data());
	_gameId = StringUtil::toInt(playerRow["game_id"].data());
	_shoeId = StringUtil::toInt(playerRow["shoe_id"].data());
	_handSequence = StringUtil::toInt(playerRow["sequence"].data());
	_handSubSequence = StringUtil::toInt(playerRow["sub_sequence"].data());
	_parentSubSequence = StringUtil::toInt(playerRow["parent_sequence"].data());
	_bet = StringUtil::toInt(playerRow["bet"].data());
	_bankroll = StringUtil::toInt(playerRow["bankroll"].data());
	_outcome = (HandOutcome)StringUtil::toInt(playerRow["outcome"].data());
}

PlayerHand::~PlayerHand() {
	for(CardList::iterator i = _cards->begin(); i != _cards->end(); ++i) {
		delete (*i);
	}
	delete _cards;
}

//void PlayerHand::save() {
//	IntVector * cardPosVector = new IntVector();
//	for (CardList::iterator i = _cards->begin(); i != _cards->end(); ++i) {
//		int cardPos = (*i)->getPosition();
//		cardPosVector->push_back(&cardPos);
//	}
//	string cardListString = VectorUtil::toString(cardPosVector);
//
//	PlayerHandAccess * handAccess = (PlayerHandAccess *)PlayerHandAccess::instance();
//	handAccess->insert(_playerId, _gameId, _shoeId, _handSequence, _handSubSequence,
//			_parentSubSequence, _bet, _bankroll, cardListString, _outcome);
//	delete cardPosVector;
//}

int PlayerHand::getHandSubSequence() {
	return _handSubSequence;
}

int PlayerHand::getParentSubSequence() {
	return _parentSubSequence;
}

string PlayerHand::getOutcomeAbbrev() {
	return (HAND_OUTCOME_STRING[_outcome]);
}

void PlayerHand::setOutcome(HandOutcome outcome) {
	_outcome = outcome;
}

Card * PlayerHand::replaceCard2(Card * card) {
	if (_cards->size() != 2) {
		ostringstream errMsg; errMsg << "PlayerHand::replaceCard2 - to replace card, "
			<< "hand must have 2 cards.  This has: " << _cards->size();
		throw HandException(errMsg.str());
	}

	Card * backCard = _cards->back();
	_cards->pop_back();
	addCard(card);

	recalculateValues();

	return backCard;
}

bool PlayerHand::isRawSplitHand() {
	return (_cards->size() == 1) && (_parentSubSequence != NON_SPLIT_SEQUENCE);
}
