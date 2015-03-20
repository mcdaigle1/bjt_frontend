/***********************************************************
 * Copyright 2012 Blue Cask Software. All rights reserved.
 *
 * THIS PROGRAM IS CONFIDENTIAL AND PROPRIETARY TO BLUE CASK
 * SOFTWARE.  Any unauthorized use, reproduction, modification, or
 * disclosure of this program is strictly prohibited without the
 * express written permission of an authorized representative of
 * Blue Cask Software.
 ***********************************************************/
#include <iostream>
#include "utility/Logger.h"
#include "deck/ShoeController.h"
#include "game/GameController.h"
#include "deck/Shoe.h"
#include "game/Game.h"
#include "database/Database.h"
#include "database/GameAccess.h"
#include "exception/BaseException.h"
#include "exception/CommandArgumentException.h"
#include "utility/Md5Util.h"

using namespace std;

void parseArgs(int argc, char * argv[]);
void createShoes();

bool _optCreateShoes = false;
int _numCreateShoes;
int _numDecks = 6;

int main(int argc, char * argv[])
{
	try {
		cout << "Starting blackjack application" << endl;

		parseArgs(argc, argv);

		Logger::initialize(DEBUG, "/var/log/blackjack/blackjack.log");
		Logger::info("Starting blackjack application");

		Database * database = Database::instance();
		database->initialize("localhost", "blackjack", "blackjack", "blackjack");

		if (_optCreateShoes) {
//			ostringstream logMsg;
//			logMsg << "running in shoe creation mode.  Number of shoes: " << _numCreateShoes << endl;
//			Logger::info(logMsg);
//
//			// Get the shoe controller, generate the shoes which saves to DB
//			ShoeController * shoeController = ShoeController::instance();
//			shoeController->generateShoes(_numCreateShoes, _numDecks);

		} else {
			// This is where we should loop through and wait for input
			// TODO create a game admin class that manages getting and running games
			Logger::debug("getting game controller");
			GameController * gameController = GameController::instance();

			gameController->findAndPlayGames();
		}

		Logger::info("Exiting blackjack application");
	} catch (CommandArgumentException& cae) {
		string errMsg = "Command line error: " + cae.getMsg();
		cout << errMsg << endl;
		// TODO show usage
	} catch (BaseException& be) {
		string errMsg = "top level catch: " + be.getMsg();
		Logger::error(errMsg);
	} catch (exception& e) {
		cout << "we caught an exception: " << e.what() << endl;
		ostringstream errMsg;
		errMsg << "we caught an exception: " << e.what();
		Logger::error(errMsg);
	}
}

void parseArgs(int argc, char * argv[]) {
	for (int i = 1; i < argc; i++) {
		if (strcmp(argv[i], "-create_shoes") == 0) {
			if (argc == i + 1) {
				throw CommandArgumentException("-create_shoes option must be followed by additional integer argument");
			}

			if(EOF == sscanf(argv[i + 1], "%d", &_numCreateShoes)) {
				throw CommandArgumentException("-create_shoes option must be followed by integer argument");
			}
			_optCreateShoes = true;
		} else if (argv[i] == "-num_decks") {
			if (argc == i + 1) {
				throw CommandArgumentException("-num_decks option must be followed by additional integer argument");
			}

			if(EOF == sscanf(argv[i + 1], "%d", &_numDecks)) {
				throw CommandArgumentException("-num_decks option must be followed by integer argument");
			}
		}
	}
}

void createShoes() {

}
