/***********************************************************
 * Copyright 2012 Blue Cask Software. All rights reserved.
 *
 * THIS PROGRAM IS CONFIDENTIAL AND PROPRIETARY TO BLUE CASK
 * SOFTWARE.  Any unauthorized use, reproduction, modification, or
 * disclosure of this program is strictly prohibited without the
 * express written permission of an authorized representative of
 * Blue Cask Software.
 ***********************************************************/
#include <mysql++.h>
#include "Game.h"
#include "PlayerHand.h"
#include "DealerHand.h"
#include "../deck/Shoe.h"
#include "../rule/PlayerHitRule.h"
#include "../rule/DealerHitRule.h"
#include "../utility/Logger.h"
#include "../utility/RandomUtil.h"
#include "../utility/StringUtil.h"
#include "../utility/VectorUtil.h"
#include "../database/GameAccess.h"
#include "../database/ShoeOneAccess.h"
#include "../database/ShoeTwoAccess.h"
#include "../database/ShoeSixAccess.h"
#include "../database/PlayerHitRuleAccess.h"
#include "../database/DealerHitRuleAccess.h"
#include "../database/PlayerHandAccess.h"
#include "../database/DealerHandAccess.h"
//#include "../database/BetRuleAccess.h"
#include "../exception/GameReserveException.h"
#include "../exception/DatabaseException.h"

using namespace std;

Game::Game(mysqlpp::Row gameRow) {
	Logger::debug("in Game::Game");
	int dealerHitRuleId;
	int playerHitRuleId;
	int betRuleId;

	Logger::debug("Game::Game - setting fields");
	// set the fields
	_id = StringUtil::toInt(gameRow["id"].data());
	gameRow["create_time"].to_string(_createTime);
	gameRow["mod_time"].to_string(_modTime);
	gameRow["description"].to_string(_description);
	_status = StringUtil::toInt(gameRow["status"].data());
	_numDecks = StringUtil::toInt(gameRow["num_decks"].data());
	_handLimit = StringUtil::toInt(gameRow["num_hands"].data());
	_bankroll = StringUtil::toInt(gameRow["bankroll"].data());
	_endAtZero = StringUtil::toBool(gameRow["end_at_zero"].data());
	dealerHitRuleId = StringUtil::toInt(gameRow["dealer_hit_rule_id"].data());
	playerHitRuleId = StringUtil::toInt(gameRow["player_hit_rule_id"].data());
	betRuleId = StringUtil::toInt(gameRow["bet_rule_id"].data());

	// create rule objects
	Logger::debug("Game::Game - Getting player hit rule");
	PlayerHitRuleAccess * playerHitRuleAccess = PlayerHitRuleAccess::instance();
	_playerHitRule = (PlayerHitRule *)playerHitRuleAccess->read(playerHitRuleId);

	Logger::debug("Game::Game - Getting dealer hit rule");
	DealerHitRuleAccess * dealerHitRuleAccess = DealerHitRuleAccess::instance();
	_dealerHitRule = (DealerHitRule *)dealerHitRuleAccess->read(dealerHitRuleId);

	Logger::debug("Game::Game - Getting bet rule");
//	BetRuleAccess * betRuleAccess = BetRuleAccess::instance();
//	_betRule = (BetRule *)betRuleAccess->read(betRuleId);

	_betRule = new BetRule(betRuleId);

	// These curr values are the ones that will change as we play
	_currHandCount = 0;
	_currBankroll = _bankroll;
}

Game::~Game() {
	delete _playerHitRule;
	delete _dealerHitRule;
	delete _betRule;
}

void Game::play() {
	Shoe * shoe = new Shoe(_numDecks);

	// iterate through hands until our game definition tells us we have
	// reached a completion criterion
	while ( !gameDone() ) {
		int handSubSequence = 0;

		// if we are past the cut card in the shoe, get a new shoe.
		if (shoe->pastCut()) {
			shoe = new Shoe(_numDecks);
		}

		// Depending on the outcome of the initial hand, we may generate
		// more by splitting, so we maintain the hands in the handList
		PlayerHandList * playerHandList = new PlayerHandList();

		// deal out the initial cards to the player and dealer
		Card * playerCard1 = shoe->dealCard();
		Card * dealerCard1 = shoe->dealCard();
		Card * playerCard2 = shoe->dealCard();
		Card * dealerCard2 = shoe->dealCard();

		// add the initial player hand to the player hand list
		playerHandList->push_back(new PlayerHand(_id, playerCard1, playerCard2, _currHandCount));

		DealerHand * dealerHand =
				new DealerHand(_id, dealerCard1, dealerCard2, _currHandCount);

		// iterate through the player hands until the hand busts or the action is HR_STAND.
		// More hands may get added on a split action
		for (PlayerHandList::iterator i = playerHandList->begin(); i != playerHandList->end(); ++i) {
			PlayerHand * currPlayerHand = *i;

			// if this hand was the result of a split, it only has one card.  we need to deal
			// it a second one
			if (currPlayerHand->isRawSplitHand()) {
				currPlayerHand->addCard(shoe->dealCard());
			}

			// play this hand until its action is to stand, or it busts
			HitRuleAction playerAction;
			do {
				// get the hit action for this hand versus the dealer
				playerAction = _playerHitRule->getHitAction(currPlayerHand, dealerHand);

				if (playerAction == HR_SPLIT) {
					// increment the hand subsequence for this newly created hand
					handSubSequence++;

					// if the action is to split, create a new hand, move one of the cards to
					// that hand and deal out another card to the first hand.
					Card * origHandSecondCard = shoe->dealCard();
					Card * newHandFirstCard = currPlayerHand->replaceCard2(origHandSecondCard);

					int parentSequence = currPlayerHand->getHandSubSequence();
					PlayerHand * newPlayerHand = new PlayerHand(_id, newHandFirstCard, _currHandCount,
									handSubSequence, parentSequence);

					// add the newly created hand to the player hand list
					i = playerHandList->insert(++i, newPlayerHand);
					// iterater is set to the newly inserted hand.  Move it back to where it was.
					i--;
				} else if (playerAction == HR_HIT || playerAction == HR_DOUBLE) {
					// TODO separate out HR_DOUBLE action
					// if the action is to hit, deal another card
					currPlayerHand->addCard(shoe->dealCard());
				}
			} while (playerAction != HR_STAND && !currPlayerHand->isBusted());
		}

		// find out if any hands did not bust
		int nonBustedHands = 0;
		for (PlayerHandList::iterator i = playerHandList->begin(); i != playerHandList->end(); ++i) {
			Hand * playerHand = *i;
			if (!playerHand->isBusted()) {
				nonBustedHands++;
			}
		}

		// only play the dealer hand if there is at least one player hand that didn't bust.
		// Play the dealer hand until the hand busts or the action is HR_STAND.
		HitRuleAction dealerAction;
		if (nonBustedHands > 0) {
			do {
				dealerAction = _dealerHitRule->getHitAction(dealerHand);

				if (dealerAction == HR_HIT) {
					dealerHand->addCard(shoe->dealCard());
				}
			} while (dealerAction != HR_STAND && !dealerHand->isBusted());
		}

		// for each player hand, figure out what the outcome was and set it on that hand.
		for (PlayerHandList::iterator i = playerHandList->begin(); i != playerHandList->end(); ++i) {
			PlayerHand * playerHand = *i;
			if (playerHand->isBusted()) {
				playerHand->setOutcome(OC_LOSE);
			} else if (dealerHand->isBusted()) {
				playerHand->setOutcome(OC_WIN);
			} else if (playerHand->getFinalValue() > dealerHand->getFinalValue()) {
				playerHand->setOutcome(OC_WIN);
			} else if (playerHand->getFinalValue() == dealerHand->getFinalValue()) {
				playerHand->setOutcome(OC_TIE);
			} else if (playerHand->getFinalValue() < dealerHand->getFinalValue()) {
				playerHand->setOutcome(OC_LOSE);
			}
		}

//		ostringstream msg; msg << "Hand #" << _currHandCount << endl;
//		for (PlayerHandList::iterator i = playerHandList->begin(); i != playerHandList->end(); ++i) {
//			PlayerHand * playerHand = *i;
//			playerHand->save();
//			msg << "   Player Hand: " << endl;
//			msg << "      Value1: " << playerHand->getValue1() << endl;
//			msg << "      Value2: " << playerHand->getValue2() << endl;
//			msg << "      Final Value: " << playerHand->getFinalValue() << endl;
//			msg << "      Is Busted:   " << playerHand->isBusted() << endl;
//			msg << "      Subsequence: " << playerHand->getHandSubSequence() << endl;
//			msg << "      Parent ID:   " << playerHand->getParentSubSequence() << endl;
//			msg << "      Outcome:     " << playerHand->getOutcomeAbbrev() << endl;
//		}
//		dealerHand->save();
//		msg << "   Dealer Hand: " << endl;
//		msg << "      Value1:      " << dealerHand->getValue1() << endl;
//		msg << "      Value2:      " << dealerHand->getValue2() << endl;
//		msg << "      Sequence:    " << dealerHand->getHandSequence() << endl;
//		msg << "      Num Cards:   " << dealerHand->cardCount() << endl;
//		msg << "      Final Value: " << dealerHand->getFinalValue() << endl;
//		msg << "      Is Busted:   " << dealerHand->isBusted() << endl;
//
//		Logger::info(msg);


		delete dealerHand;
		deletePlayerHandList(playerHandList);

		_currHandCount++;
	}

	displayToLog();
}

bool Game::gameDone() {
	return _currHandCount > _handLimit;
}

void Game::deletePlayerHandList(PlayerHandList * playerHandList) {
	for (PlayerHandList::iterator i = playerHandList->begin(); i != playerHandList->end(); ++i) {
		delete *i;
	}
	delete playerHandList;
}

void Game::displayToLog() {
	PlayerHandAccess * playerHandAccess = PlayerHandAccess::instance();
	mysqlpp::StoreQueryResult playerHands = playerHandAccess->selectByGame(_id);

	DealerHandAccess * dealerHandAccess = DealerHandAccess::instance();
	mysqlpp::StoreQueryResult dealerHands = dealerHandAccess->selectByGame(_id);

	for (size_t i = 0; i < dealerHands.num_rows(); ++i) {
		Logger::info("*******************************************");
		ostringstream dealerInfo;
		dealerInfo << "** HAND: " << i << endl;
		dealerInfo << "   DEALER: ";


	}
}


