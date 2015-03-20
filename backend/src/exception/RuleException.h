/***********************************************************
 * Copyright 2012 Blue Cask Software. All rights reserved.
 *
 * THIS PROGRAM IS CONFIDENTIAL AND PROPRIETARY TO BLUE CASK
 * SOFTWARE.  Any unauthorized use, reproduction, modification, or
 * disclosure of this program is strictly prohibited without the
 * express written permission of an authorized representative of
 * Blue Cask Software.
 ***********************************************************/
#ifndef RULE_EXCEPTION_H
#define RULE_EXCEPTION_H

#include "BaseException.h"

class RuleException : public BaseException {
public:
	RuleException(BaseException * e, std::string msg) : BaseException(e, msg) {};

	RuleException(std::exception * e, std::string msg) : BaseException(e, msg) {};

	RuleException(std::string msg) : BaseException(msg) {};
};

#endif
