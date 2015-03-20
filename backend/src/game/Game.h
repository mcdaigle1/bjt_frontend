/***********************************************************
 * Copyright 2012 Blue Cask Software. All rights reserved.
 *
 * THIS PROGRAM IS CONFIDENTIAL AND PROPRIETARY TO BLUE CASK
 * SOFTWARE.  Any unauthorized use, reproduction, modification, or
 * disclosure of this program is strictly prohibited without the
 * express written permission of an authorized representative of
 * Blue Cask Software.
 ***********************************************************/
#ifndef MY_GAME_H
#define MY_GAME_H

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <vector>
#include <mysql++.h>
#include "PlayerHand.h"
#include "../database/Storable.h"
#include "../rule/PlayerHitRule.h"
#include "../rule/DealerHitRule.h"
#include "../rule/BetRule.h"

typedef std::list<PlayerHand *> PlayerHandList;

// game statuses
enum status {GS_NEW, GS_PLAYING, GS_COMPLETE, GS_ERROR};

class Game : public Storable{
private:
	// db fields
	int _status;
	int _playerId;
	int _numDecks;
	int _handLimit;
	int _bankroll;
	bool _endAtZero;
	int _reserveId;

	int _currHandCount;   // the hand count, changes as we play
	int _currBankroll;    // the bankroll, changes as we play
	PlayerHitRule * _playerHitRule;
	DealerHitRule * _dealerHitRule;
	BetRule * _betRule;

	bool gameDone();

	/**
	 * Delete the player hand list held in this game
	 * @param playerHandList pointer to the list of player hands
	 */
	void deletePlayerHandList(PlayerHandList * playerHandList);

	/**
	 * display the game to log
	 */
	void displayToLog();
public:

	/**
	 * Create a game object from given database info
	 * @param gameRow mysqlpp::Row single row holding game data from db
	 */
	Game(mysqlpp::Row gameRow);

	~Game();

	/**
	 * Get the status of the game
	 * @returns int status as an integer
	 */
	int getStatus();

	/**
	 * Get the player ID for the game
	 * @returns int player ID
	 */
	int getPlayerId();

	/**
	 * Get the number of decks in the shoe for this game
	 * @returns int the number of decks in the shoe for
	 * 		this game
	 */
	int getNumDecks();

	/**
	 * Get the number of hands to be played in this game
	 * @returns int the number of hands to play
	 */
	int getHandLimit();

	/**
	 * Get the bankroll
	 * @returns int the current amount of currency in the player's
	 * 		bankroll
	 */
	int getBankroll();

	/**
	 * Get end at zero, which decides if the game should end when
	 * 		the bankroll hit's zero, or should continue with
	 * 		negative bankroll
	 * @returns bool - true if the game should end when the bankroll
	 * 		reaches zero, false if the bankroll can continue into
	 * 		negative amounts
	 */
	bool getEndAtZero();

	/**
	 * Get the player hit rule object for this game.  The player hit
	 * 		rule governs the player choices in the game.
	 * @returns PlayerHitRule pointer - pointer to the player hit rule
	 * 		object
	 */
	PlayerHitRule * getPlayerHitRule();

	/**
	 * Get the dealer hit rule object for this game.  The dealer hit
	 * 		rule governs the dealer choices in the game.
	 * @returns DealerHitRule pointer - pointer to the dealer hit rule
	 * 		object
	 */
	int getDealerHitRuleId();

	/**
	 * Get the bet hit rule object for this game.  The bet rule governs
	 * 		the player betting choices in the game.
	 * @returns BetRule pointer - pointer to the player bet rule
	 * 		object
	 */
	int getBetRuleId();

	/**
	 * Get the reserve ID for the game.  The reserve ID is used when
	 * 		trying to reserve a game in the database.  By setting the
	 * 		reserve ID before reading the game, we avoid race conditions
	 * 		with other processes.
	 * @returns int the integer reserve ID of the game.
	 */
	int getReserveId();

	/**
	 * Play the game
	 */
	void play();

};

#endif
