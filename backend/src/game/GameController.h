/***********************************************************
 * Copyright 2012 Blue Cask Software. All rights reserved.
 *
 * THIS PROGRAM IS CONFIDENTIAL AND PROPRIETARY TO BLUE CASK
 * SOFTWARE.  Any unauthorized use, reproduction, modification, or
 * disclosure of this program is strictly prohibited without the
 * express written permission of an authorized representative of
 * Blue Cask Software.
 ***********************************************************/
#ifndef GAME_CONTROLLER_H
#define GAME_CONTROLLER_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <string>
#include <unordered_map>
#include "../game/Game.h"

//typedef std::unordered_map<std::string, int> ReservedGame;

class GameController {
public:
	static std::string idx_reserve_id;
	static std::string idx_game_id;

	/**
	 * Get the singleton instance of the GameController.
	 * @returns GameController the single game controller object.
	 */
	static GameController * instance();

	/**
	 * Loop infinitely, checking for available games in the db.  If one is found,
	 * try and reserve it (before another process does).  If the reservation is
	 * successful, fork a child process and play the game in that process.  This allows
	 * us to play multiple games concurrently.
	 */
	void findAndPlayGames();

private:
	static GameController * _instance;
	static int GAME_ITERATION_WAIT_SECS;

	GameController();

	// Get the available game ids (status GS_NEW)
	Game * reserveNext();

};

#endif
