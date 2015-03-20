/***********************************************************
 * Copyright 2012 Blue Cask Software. All rights reserved.
 *
 * THIS PROGRAM IS CONFIDENTIAL AND PROPRIETARY TO BLUE CASK
 * SOFTWARE.  Any unauthorized use, reproduction, modification, or
 * disclosure of this program is strictly prohibited without the
 * express written permission of an authorized representative of
 * Blue Cask Software.
 ***********************************************************/
#ifndef INTEGER_CONVERSION_EXCEPTION_H
#define INTEGER_CONVERSION_EXCEPTION_H

#include "BaseException.h"

class IntegerConversionException : public BaseException {
public:
	IntegerConversionException(BaseException * e, std::string msg) : BaseException(e, msg){};

	IntegerConversionException(std::exception * e, std::string msg) : BaseException(e, msg){};

	IntegerConversionException(std::string msg) : BaseException(msg) {};
};

#endif
