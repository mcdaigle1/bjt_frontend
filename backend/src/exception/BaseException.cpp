/***********************************************************
 * Copyright 2012 Blue Cask Software. All rights reserved.
 *
 * THIS PROGRAM IS CONFIDENTIAL AND PROPRIETARY TO BLUE CASK
 * SOFTWARE.  Any unauthorized use, reproduction, modification, or
 * disclosure of this program is strictly prohibited without the
 * express written permission of an authorized representative of
 * Blue Cask Software.
 ***********************************************************/
#include "BaseException.h"

using namespace std;

BaseException * childException = NULL;

BaseException::BaseException(BaseException * e, std::string msg) {
	_childException = e;
	_msg = msg;
}

BaseException::BaseException(exception * e, string msg) {
	_childException = new BaseException(string(e->what()));
	_msg = msg;
}

BaseException::BaseException(string msg) {
	_msg = msg;
}

BaseException::~BaseException() throw() {}

string BaseException::getMsg() {
	return _msg;
}
