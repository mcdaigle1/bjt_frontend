/***********************************************************
 * Copyright 2012 Blue Cask Software. All rights reserved.
 *
 * THIS PROGRAM IS CONFIDENTIAL AND PROPRIETARY TO BLUE CASK
 * SOFTWARE.  Any unauthorized use, reproduction, modification, or
 * disclosure of this program is strictly prohibited without the
 * express written permission of an authorized representative of
 * Blue Cask Software.
 ***********************************************************/
#include "GameController.h"
#include "Game.h"
#include "../utility/Logger.h"
#include "../utility/RandomUtil.h"
#include "../utility/StringUtil.h"
#include "../database/GameAccess.h"

using namespace std;

GameController * GameController::_instance = NULL;
string GameController::idx_reserve_id = "RESERVE_ID";
string GameController::idx_game_id = "GAME_ID";
int GameController::GAME_ITERATION_WAIT_SECS = 60;  // TODO, get this from configuration

GameController::GameController() {

}

GameController * GameController::instance() {
	if (_instance == NULL) {
		_instance = new GameController();
	}
	return _instance;
}

void GameController::findAndPlayGames() {
	while(true) {
		// reserve the next available game if there is one.
		Game * nextGame = reserveNext();

		if (nextGame != NULL) {
			ostringstream msg; msg << "Reserved game: " << nextGame->getId();
			Logger::debug(msg.str());
			// fork and play the game
			pid_t pid = fork();
			if (pid == 0) {
				nextGame->play();

				_exit(EXIT_SUCCESS);
			} else if (pid < 0) {
				ostringstream errMsg; errMsg << "GameController::findAndPlayGames - ";
				errMsg << "failure creating game child process.  PID returned: " << pid;
				Logger::error(errMsg);
			}
		}
		sleep(GAME_ITERATION_WAIT_SECS);
	}

}

Game * GameController::reserveNext() {
	int reserveId = RandomUtil::generate(1000000);
	Game * reservedGame = NULL;

	GameAccess * gameAccess = (GameAccess *)GameAccess::instance();

	// Get the ids of all available games from the DB
	mysqlpp::StoreQueryResult availableGameIds = gameAccess->selectAvailableIds();

	for (int i = 0; i < availableGameIds.size(); i++) {
		int availableGameId = StringUtil::toInt(availableGameIds[i]["id"].data());
		if(gameAccess->reserveGame(availableGameId, reserveId)) {
			reservedGame = (Game *)gameAccess->read(availableGameId);
			break;
		}
	}

	return reservedGame;
}

