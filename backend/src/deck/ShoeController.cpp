/***********************************************************
 * Copyright 2012 Blue Cask Software. All rights reserved.
 *
 * THIS PROGRAM IS CONFIDENTIAL AND PROPRIETARY TO BLUE CASK
 * SOFTWARE.  Any unauthorized use, reproduction, modification, or
 * disclosure of this program is strictly prohibited without the
 * express written permission of an authorized representative of
 * Blue Cask Software.
 ***********************************************************/
#include "ShoeController.h"
#include "Shoe.h"
#include "../utility/Logger.h"
#include "../utility/RandomUtil.h"
#include "../utility/StringUtil.h"
#include "../exception/DbDuplicateEntryException.h"

using namespace std;

ShoeController * ShoeController::_instance = NULL;

ShoeController::ShoeController() {
}

ShoeController * ShoeController::instance() {
	if (_instance == NULL) {
		_instance = new ShoeController();
	}
	return _instance;
}

//void ShoeController::generateShoes(int numShoes, int numDecks) {
//	ostringstream logMsg;
//	logMsg << "ShoeController::generateShoes - number of shoes: " << numShoes
//			<< ", number of decks: " << numDecks << endl;
//	Logger::debug(logMsg);
//
//	for (int i = 0; i < numShoes; i++) {
//		ostringstream logMsg; logMsg << "Creating shoe number " << i << endl;
//		Logger::debug(logMsg);
//		Shoe * shoe = new Shoe(numDecks, true);
//		try {
//			shoe->save();
//		} catch(DbDuplicateEntryException &ddee) {
//			ostringstream errMsg; errMsg << "Looks like we had a duplicate entry. ";
//			errMsg << "md5:" << shoe->getMd5() << "Trying again. "
//					<< ddee.getMsg();
//			Logger::warn(errMsg);
//		}
//		delete shoe;
//	}
//}

