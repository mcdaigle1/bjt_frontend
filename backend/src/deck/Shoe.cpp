/***********************************************************
 * Copyright 2012 Blue Cask Software. All rights reserved.
 *
 * THIS PROGRAM IS CONFIDENTIAL AND PROPRIETARY TO BLUE CASK
 * SOFTWARE.  Any unauthorized use, reproduction, modification, or
 * disclosure of this program is strictly prohibited without the
 * express written permission of an authorized representative of
 * Blue Cask Software.
 ***********************************************************/
#include "Shoe.h"
#include "../database/ShoeOneAccess.h"
#include "../database/ShoeTwoAccess.h"
#include "../database/ShoeSixAccess.h"
#include "../utility/Md5Util.h"
#include "../utility/RandomUtil.h"
#include "../utility/StringUtil.h"
#include "../utility/VectorUtil.h"
#include "../utility/Logger.h"
#include "../exception/ShoeException.h"
#include "../exception/DbDuplicateEntryException.h"

using namespace std;

Shoe::Shoe(int numDecks) {
	_numDecks = numDecks;
	_numCards = numDecks * 52;
//	_dirty = false;
	_currCardPos = 0;
	_shuffledShoe = new vector<Card *>();

	_sortedShoeArray = new bool[_numCards];
	initSortedShoeArray();
	shuffleShoe();
}

Shoe::Shoe(mysqlpp::Row shoeRow) {
	_id = StringUtil::toInt(shoeRow["id"].data());
	shoeRow["create_time"].to_string(_createTime);
	shoeRow["mod_time"].to_string(_modTime);
	shoeRow["description"].to_string(_description);
	_cutPosition = StringUtil::toInt(shoeRow["cut_position"].data());
	shoeRow["cards_md5"].to_string(_cardMd5);
	shoeRow["cards"].to_string(_cards);
	_shuffledShoe = cardStringToVector();
}

Shoe::~Shoe() {
	delete [] _sortedShoeArray;
	for (int i = 0; i < _shuffledShoe->size(); i++) {
		delete _shuffledShoe->at(i);
	}
}

int Shoe::getNumDecks() {
	return _numDecks;
}

int Shoe::getGameId() {
	return _gameId;
}

int Shoe::getSequence() {
	return _sequence;
}

string Shoe::getCards() {
	return _cards;
}

int Shoe::getCutPosition() {
	return _cutPosition;
}

string Shoe::getMd5() {
	return _cardMd5;
}

void Shoe::initSortedShoeArray() {
	for (int i = 0; i < _numCards; i++) {
		_sortedShoeArray[i] = true;
	}
}

void Shoe::shuffleShoe() {
	int cardIndex;
	int deckIteration;
	Card * nextCard = NULL;

	for (int i = 0; i < _numCards; i++) {
		// get a random index for the next card
		cardIndex = RandomUtil::generate(_numCards);
		deckIteration = 0;

		// if the index points to a card that was already used, increment
		// until we find one that wasn't used.
		while (!_sortedShoeArray[cardIndex]) {
			cardIndex++;
			if (cardIndex == _numCards) { cardIndex = 0; }
			deckIteration++;
			if (deckIteration > _numCards) {
				// safety valve to make sure we don't get into infinite loop.
				throw ShoeException("Stuck in loop while shuffling deck");
			}
		}

		_sortedShoeArray[cardIndex] = false;
		nextCard = new Card(cardIndex % 52);
		_shuffledShoe->push_back(nextCard);
	}

	int shuffleRand = RandomUtil::generate(10);
	_cutPosition = _numCards - (20 + shuffleRand);

	_cards = this->toString();
	_cardMd5 = Md5Util::Md5Sum(_cards);
}

Card * Shoe::dealCard() {
	Card * card = _shuffledShoe->at(_currCardPos);
	_currCardPos++;
	return card;
}

bool Shoe::pastCut() {
	return _currCardPos > _cutPosition;
}

//ShoeAccess * Shoe::getShoeAccess(int numDecks) {
//	switch (numDecks) {
//		case 1: {
//			return (ShoeAccess *)ShoeOneAccess::instance();
//			break;
//		}
//		case 2: {
//			return (ShoeAccess *)ShoeTwoAccess::instance();
//			break;
//		}
//		case 6: {
//			return (ShoeAccess *)ShoeSixAccess::instance();
//			break;
//		}
//		default: {
//			ostringstream errMsg;
//			errMsg << "Supported number of decks is 1, 2 or 6. ";
//			errMsg << "This number: " << _numDecks;
//			throw ShoeException(errMsg.str());
//		}
//
//	}
//}

void Shoe::displayShuffledShoe() {
	for (int i = 0; i < _shuffledShoe->size(); i++) {
		_shuffledShoe->at(i)->display();
	}
}

string Shoe::toString() {
	ostringstream shoeDisplay;

	shoeDisplay << "[";
	for (int i = 0; i < _shuffledShoe->size(); i++) {
		shoeDisplay << _shuffledShoe->at(i)->getPosition();
		if (i < (_shuffledShoe->size() - 1)) {
			shoeDisplay << ",";
		}
	}
	shoeDisplay << "]";

	return shoeDisplay.str();
}

CardVector * Shoe::cardStringToVector() {
	CardVector * cardVector = new CardVector();

	IntVector * cardStringVector = VectorUtil::fromIntString(&_cards);

	for (IntVector::iterator i = cardStringVector->begin(); i != cardStringVector->end(); ++i) {
		int cardPos = **i;
		cardVector->push_back(new Card(cardPos));
	}

	return cardVector;
}
