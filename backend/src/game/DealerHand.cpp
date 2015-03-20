/***********************************************************
 * Copyright 2012 Blue Cask Software. All rights reserved.
 *
 * THIS PROGRAM IS CONFIDENTIAL AND PROPRIETARY TO BLUE CASK
 * SOFTWARE.  Any unauthorized use, reproduction, modification, or
 * disclosure of this program is strictly prohibited without the
 * express written permission of an authorized representative of
 * Blue Cask Software.
 ***********************************************************/
#include "DealerHand.h"
#include "../database/DealerHandAccess.h"
#include "../utility/Logger.h"
#include "../utility/StringUtil.h"
#include "../exception/HandException.h"

using namespace std;

DealerHand::DealerHand(int gameId, Card * card1, Card * card2, int handSequence) :
		Hand(gameId, card1, card2, handSequence) {
}

DealerHand::DealerHand(mysqlpp::Row dealerRow) {
	_id = StringUtil::toInt(dealerRow["id"].data());
	dealerRow["create_time"].to_string(_createTime);
	dealerRow["mod_time"].to_string(_modTime);
	dealerRow["description"].to_string(_description);
	_gameId = StringUtil::toInt(dealerRow["game_id"].data());
	_shoeId = StringUtil::toInt(dealerRow["shoe_id"].data());
	_handSequence = StringUtil::toInt(dealerRow["sequence"].data());
}

DealerHand::~DealerHand() {
	for(CardList::iterator i = _cards->begin(); i != _cards->end(); ++i) {
		delete (*i);
	}
	delete _cards;
}

//void DealerHand::save() {
//	IntVector * cardPosVector = new IntVector();
//	for (CardList::iterator i = _cards->begin(); i != _cards->end(); ++i) {
//		int * cardPos = new int((*i)->getPosition());
//		cardPosVector->push_back(cardPos);
//	}
//
//	string cardListString = VectorUtil::toString(cardPosVector);
//
//	DealerHandAccess * handAccess = (DealerHandAccess *)DealerHandAccess::instance();;
//	handAccess->insert(_gameId, _shoeId, _handSequence, cardListString);
//}
