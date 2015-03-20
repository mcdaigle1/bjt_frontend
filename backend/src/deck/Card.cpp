/***********************************************************
 * Copyright 2012 Blue Cask Software. All rights reserved.
 *
 * THIS PROGRAM IS CONFIDENTIAL AND PROPRIETARY TO BLUE CASK
 * SOFTWARE.  Any unauthorized use, reproduction, modification, or
 * disclosure of this program is strictly prohibited without the
 * express written permission of an authorized representative of
 * Blue Cask Software.
 ***********************************************************/
#include "Card.h"
#include "../exception/CardException.h"
#include "../exception/InvalidArgumentException.h"
#include "../utility/Logger.h"

using namespace std;

string Card::_suitAbbrev[] = {"C","H","D","S"};
string Card::_nameAbbrev[] = {"A","2","3","4","5","6","7","8","9","10","J","Q","K"};


Card::Card(int position) : Storable() {
	/* If position is not 0 - 51, throw exception here */
	if( position < 0 || position > 51 ) {
		ostringstream errMsg; errMsg << "Card::Card - card suit position: " << position
			<< " out of range.  Must be between 0 and 51 inclusive.";
		throw InvalidArgumentException(errMsg.str());
	}

	_absPosition = position;
	int suitPos = (position / 13);
	int indexPos = position % 13;

	_suit = (CardSuit)suitPos;
	_index = (CardIndex)indexPos;
}

Card::~Card() {

}

int Card::getNumericValue() {
	if (_index <= TEN_INDEX) {
		return _index + 1;
	}
	return TEN_VAL;
}

CardIndex Card::getIndex() {
	return _index;
}

int Card::getPosition() {
	return _absPosition;
}

bool Card::isAce() {
	return _index == ACE_INDEX;
}

void Card::display() {
	cout << _suit << " " << _index << endl;
}

string Card::posToString(int position) {
	int suitPos = (position / 13);
	int indexPos = position % 13;

	ostringstream name; name << _nameAbbrev[indexPos] << " " << _suitAbbrev[suitPos];
	return name.str();
}

