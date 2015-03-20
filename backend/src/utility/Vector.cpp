/***********************make************************************
 * Copyright 2012 Blue Cask Software. All rights reserved.
 *
 * THIS PROGRAM IS CONFIDENTIAL AND PROPRIETARY TO BLUE CASK
 * SOFTWARE.  Any unauthorized use, reproduction, modification, or
 * disclosure of this program is strictly prohibited without the
 * express written permission of an authorized representative of
 * Blue Cask Software.
 ***********************************************************/
#include "Vector.h"
#include "String.h"
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
string Vector::toString(StrVector strVector) {
	ostringstream retVal;

	for (int i = 0; i < strVector.size(); i++ ) {
		if (i == 0) {
			retVal << "[";
		}

		retVal << strVector[i];

		if (i == strVector.size()) {
			retVal << "]";
		} else {
			retVal << ",";
		}
	}

	return retVal.str();
}

string Vector::toString(StrVector2D _strVector2D) {
	ostringstream retVal;

	for (int i = 0; i < _strVector2D.size(); i++) {
		if (i == 0) {
			retVal << "[";
		}

		retVal << toString(*_strVector2D[i]);

		if (i == _strVector2D.size()) {
			retVal << "]";
		} else {
			retVal << ",";
		}
	}

	return retVal.str();
}

string Vector::toString(IntVector intVector) {
	ostringstream retVal;

	for (int i = 0; i < intVector.size(); i++ ) {
		if (i == 0) {
			retVal << "[";
		}

		retVal << intVector[i];

		if (i == intVector.size()) {
			retVal << "]";
		} else {
			retVal << ",";
		}
	}

	return retVal.str();
}

string Vector::toString(IntVector2D intVector2D) {
	ostringstream retVal;

	for (int i = 0; i < intVector2D.size(); i++) {
		if (i == 0) {
			retVal << "[";
		}

		retVal << toString(*intVector2D[i]);

		if (i == intVector2D.size()) {
			retVal << "]";
		} else {
			retVal << ",";
		}
	}

	return retVal.str();
}

StrVector * Vector::fromString(string vectorString) {
	StrVector * currStrVector = new StrVector();

	int startPos = 1;
	int endPos = 1;
	while (true) {
		endPos = vectorString.find(',', startPos);

		if (endPos > 0) {
			string * currString = new string(vectorString.substr(startPos, endPos - startPos));
			currStrVector->push_back(currString);
			startPos = endPos + 1;
		} else {
			endPos = vectorString.find(']', startPos);
			string * currString = new string(vectorString.substr(startPos, endPos - startPos));
			currStrVector->push_back(currString);
			break;
		}
	}

	return currStrVector;
}

StrVector2D * Vector::from2DString(string vector2DString){
	StrVector2D * strVector2D = new StrVector2D();

	int startPos = 1;
	int endPos = 1;
	while (endPos > 0) {
		string currString;
		endPos = vector2DString.find(']', startPos) + 1;
		currString = vector2DString.substr(startPos, endPos - startPos);
		StrVector * strVector = fromString(currString);
		strVector2D->push_back(strVector);
		startPos = endPos;
		if (endPos == vector2DString.size() - 1) {
			break;
		}
	}

	return strVector2D;
}

IntVector * Vector::fromIntString(string vectorString) {
	StrVector * currStrVector = fromString(vectorString);
	IntVector * currIntVector = new IntVector();

	for (int i = 0; i < currStrVector->size(); i++) {
		string * strValue = currStrVector->at(i);
		int * intValue = new int(String::toInt(*strValue));
		currIntVector->push_back(intValue);
	}

	deleteVector(currStrVector);

	return currIntVector;
}

IntVector2D * Vector::from2DIntString(string vector2DString) {
	StrVector2D * strVector2D = from2DString(vector2DString);
	IntVector2D * intVector2D = new IntVector2D();

	for (int i = 0; i < strVector2D->size(); i++) {
		IntVector * intVector = new IntVector();
		for (int j = 0; j < strVector2D->at(i)->size(); j++) {
			string * strValue = strVector2D->at(i)->at(j);
			int * intValue = new int(String::toInt(*strValue));
			intVector->push_back(intValue);
		}
		intVector2D->push_back(intVector);
	}

	deleteVector(strVector2D);

	return intVector2D;
}

void Vector::deleteVector(StrVector * strVector) {
	for (int i = 0; i < strVector->size(); i++) {
		delete strVector->at(i);
	}
	delete strVector;
}

void Vector::deleteVector(StrVector2D * strVector2D) {
	for (int i = 0; i < strVector2D->size(); i++) {
		deleteVector(strVector2D->at(i));
	}
}

void Vector::deleteVector(IntVector * intVector) {
	for (int i = 0; i < intVector->size(); i++) {
		delete intVector->at(i);
	}
	delete intVector;
}

void Vector::deleteVector(IntVector2D * intVector2D) {
	for (int i = 0; i < intVector2D->size(); i++) {
		deleteVector(intVector2D->at(i));
	}
}

