/***********************************************************
 * Copyright 2012 Blue Cask Software. All rights reserved.
 *
 * THIS PROGRAM IS CONFIDENTIAL AND PROPRIETARY TO BLUE CASK
 * SOFTWARE.  Any unauthorized use, reproduction, modification, or
 * disclosure of this program is strictly prohibited without the
 * express written permission of an authorized representative of
 * Blue Cask Software.
 ***********************************************************/
#ifndef GAME_RESERVED_H
#define GAME_RESERVED_H

#include "BaseException.h"

class GameReserveException : public BaseException {
public:
	GameReserveException(BaseException * e, std::string msg) : BaseException(e, msg){};

	GameReserveException(std::exception * e, std::string msg) : BaseException(e, msg){};

	GameReserveException(std::string msg) : BaseException(msg) {};
};

#endif
