/***********************************************************
 * Copyright 2012 Blue Cask Software. All rights reserved.
 *
 * THIS PROGRAM IS CONFIDENTIAL AND PROPRIETARY TO BLUE CASK
 * SOFTWARE.  Any unauthorized use, reproduction, modification, or
 * disclosure of this program is strictly prohibited without the
 * express written permission of an authorized representative of
 * Blue Cask Software.
 ***********************************************************/
#include "Hand.h"
#include "../utility/Logger.h"
#include "../exception/HandException.h"

using namespace std;

Hand::Hand() {

}

Hand::Hand(int gameId, Card * card1, Card * card2, int handSequence)  : Storable() {
	_gameId = gameId;
	_handSequence = handSequence;
	_cards = new CardList;

	if (card2->isAce()) {
		_cards->push_back(card2);
		_cards->push_back(card1);
	} else {
		_cards->push_back(card1);
		_cards->push_back(card2);
	}

	recalculateValues();
}

Hand::Hand(int gameId, Card * card1, int handSequence) : Storable() {
	_gameId = gameId;
	_handSequence = handSequence;
	_cards = new CardList;
	_cards->push_back(card1);

	recalculateValues();
}

int Hand::getValue1() {
	return _value1;
}

int Hand::getValue2() {
	return _value2;
}

int Hand::getFinalValue() {
	int value1;

	// if the first card is and ace and the rest of the cards total ten or less, we
	// must be using the ace as 11
	if (_cards->front()->isAce() && _value2 <= 10) {
		value1 = 11;
	} else {
		value1 = _value1;
	}

	return (value1 + _value2);
}

int Hand::getHandSequence() {
	return _handSequence;
}

int Hand::cardCount() {
	return _cards->size();
}

bool Hand::isBusted() {
	return (_value1 + _value2) > 21;
}

void Hand::addCard(Card * card) {
	if (card->isAce() && !_cards->front()->isAce()) {
		_cards->push_front(card);
	} else {
		_cards->push_back(card);
	}

	recalculateValues();
}

void Hand::recalculateValues() {
	CardList::iterator cardIter = _cards->begin();

	int value2Total = 0;
	for (int i = 0; i != _cards->size(); i++) {
		if (i == 0) {
			_value1 = (*cardIter)->getNumericValue();
		} else {
			value2Total += (*cardIter)->getNumericValue();
		}
		cardIter++;
	}
	_value2 = value2Total;
}
