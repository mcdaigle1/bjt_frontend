/***********************make************************************
 * Copyright 2012 Blue Cask Software. All rights reserved.
 *
 * THIS PROGRAM IS CONFIDENTIAL AND PROPRIETARY TO BLUE CASK
 * SOFTWARE.  Any unauthorized use, reproduction, modification, or
 * disclosure of this program is strictly prohibited without the
 * express written permission of an authorized representative of
 * Blue Cask Software.
 ***********************************************************/
#include "VectorUtil.h"
#include "StringUtil.h"
#include "../utility/Logger.h"
#include <ctime>
#include <cstdlib>
#include <iostream>
#include <sstream>

using namespace std;

/*
 * We assume at this point that our strings do not contain commas.  If they do, we will
 * need to come up with an escaping strategy for the commas.
 */
string VectorUtil::toString(StrVector * strVector) {
	ostringstream retVal;

	retVal << "[";
	for (StrVector::iterator i = strVector->begin(); i != strVector->end(); ++i) {
		if (i != strVector->begin()) {
			retVal << ",";
		}
		retVal << **i;
	}
	retVal << "]";

	return retVal.str();
}

string VectorUtil::toString(StrVector2D * strVector2D) {
	ostringstream retVal;

	retVal << "[";
	for (StrVector2D::iterator i = strVector2D->begin(); i != strVector2D->end(); ++i) {
		retVal << toString(*i);
	}
	retVal << "]";

	return retVal.str();
}

string VectorUtil::toString(IntVector * intVector) {
	ostringstream retVal;

	retVal << "[";
	for (IntVector::iterator i = intVector->begin(); i != intVector->end(); ++i) {
		if (i != intVector->begin()) {
			retVal << ",";
		}
		retVal << **i;
	}
	retVal << "]";

	return retVal.str();
}

string VectorUtil::toString(IntVector2D * intVector2D) {
	ostringstream retVal;

	retVal << "[";
	for (IntVector2D::iterator i = intVector2D->begin(); i != intVector2D->end(); ++i) {
		retVal << toString(*i);
	}
	retVal << "]";

	return retVal.str();
}

StrVector * VectorUtil::fromString(string * vectorString) {
	StrVector * currStrVector = new StrVector();

	int startPos = 1;
	int endPos = 1;
	while (true) {
		endPos = vectorString->find(',', startPos);

		if (endPos > 0) {
			string * currString = new string(vectorString->substr(startPos, endPos - startPos));
			currStrVector->push_back(currString);
			startPos = endPos + 1;
		} else {
			endPos = vectorString->find(']', startPos);
			string * currString = new string(vectorString->substr(startPos, endPos - startPos));
			currStrVector->push_back(currString);
			break;
		}
	}

	return currStrVector;
}

StrVector2D * VectorUtil::from2DString(string * vector2DString){
	StrVector2D * strVector2D = new StrVector2D();

	int startPos = 1;
	int endPos = 1;
	while (endPos > 0) {
		string currString;
		endPos = vector2DString->find(']', startPos) + 1;
		currString = vector2DString->substr(startPos, endPos - startPos);
		StrVector * strVector = fromString(&currString);
		strVector2D->push_back(strVector);
		startPos = endPos;
		if (endPos == vector2DString->size() - 1) {
			break;
		}
	}

	return strVector2D;
}

IntVector * VectorUtil::fromIntString(string * vectorString) {
	StrVector * currStrVector = fromString(vectorString);
	IntVector * currIntVector = new IntVector();

	for (int i = 0; i < currStrVector->size(); i++) {
		string * strValue = currStrVector->at(i);
		int * intValue = new int(StringUtil::toInt(*strValue));
		currIntVector->push_back(intValue);
	}

	deleteVector(currStrVector);

	return currIntVector;
}

IntVector2D * VectorUtil::from2DIntString(string * vector2DString) {
	StrVector2D * strVector2D = from2DString(vector2DString);
	IntVector2D * intVector2D = new IntVector2D();

	for (int i = 0; i < strVector2D->size(); i++) {
		IntVector * intVector = new IntVector();
		for (int j = 0; j < strVector2D->at(i)->size(); j++) {
			string * strValue = strVector2D->at(i)->at(j);
			int * intValue = new int(StringUtil::toInt(*strValue));
			intVector->push_back(intValue);
		}
		intVector2D->push_back(intVector);
	}

	deleteVector(strVector2D);

	return intVector2D;
}

void VectorUtil::deleteVector(StrVector * strVector) {
	for (int i = 0; i < strVector->size(); i++) {
		delete strVector->at(i);
	}
	delete strVector;
}

void VectorUtil::deleteVector(StrVector2D * strVector2D) {
	for (int i = 0; i < strVector2D->size(); i++) {
		deleteVector(strVector2D->at(i));
	}
}

void VectorUtil::deleteVector(IntVector * intVector) {
	for (int i = 0; i < intVector->size(); i++) {
		delete intVector->at(i);
	}
	delete intVector;
}

void VectorUtil::deleteVector(IntVector2D * intVector2D) {
	for (int i = 0; i < intVector2D->size(); i++) {
		deleteVector(intVector2D->at(i));
	}
}

