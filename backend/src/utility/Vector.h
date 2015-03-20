/***********************************************************
 * Copyright 2012 Blue Cask Software. All rights reserved.
 *
 * THIS PROGRAM IS CONFIDENTIAL AND PROPRIETARY TO BLUE CASK
 * SOFTWARE.  Any unauthorized use, reproduction, modification, or
 * disclosure of this program is strictly prohibited without the
 * express written permission of an authorized representative of
 * Blue Cask Software.
 ***********************************************************/
#ifndef MY_VECTOR_H
#define MY_VECTOR_H

#include <string>
#include <string.h>
#include <vector>

typedef std::vector<std::string *> StrVector;
typedef std::vector<StrVector *> StrVector2D;
typedef std::vector<int *> IntVector;
typedef std::vector<IntVector *> IntVector2D;

class Vector {

private:

public:

	/**
	 * Convert a single dimensional vector of string pointers to a string
	 * representation.
	 * @param strVector a single dimensional vector of string pointers
	 * @returns a string representation of the vector.  The format is:
	 * 		["string1","string2",...]
	 */
	static std::string toString(StrVector strVector);

	/**
	 * Convert a two dimensional vector of string pointers to a string
	 * representation.
	 * @param strVector2D a two dimensional vector of string pointers
	 * @returns a string representation of the vector.  The format is:
	 * 		[["string1.1","string1.2",...]["string2.1","string2.2",...]...]
	 */
	static std::string toString(StrVector2D strVector2D);

	/**
	 * Convert a single dimensional vector of integer pointers to a string
	 * representation.
	 * @param intVector a single dimensional vector of integer pointers
	 * @returns a string representation of the vector.  The format is:
	 * 		["int1","int2",...]
	 */
	static std::string toString(IntVector intVector);

	/**
	 * Convert a two dimensional vector of integer pointers to a string
	 * representation.
	 * @param intVector2D a two dimensional vector of string pointers
	 * @returns a string representation of the vector.  The format is:
	 * 		[["int1.1","int1.2",...]["int2.1","int2.2",...]...]
	 */
	static std::string toString(IntVector2D intVector2D);

	/**
	 * Convert a string representation of a single dimensional vector
	 * of strings to a vector of string pointers.
	 * @param vectorString string representation of a single
	 * 		dimensional vector of strings.  The string format is:
	 * 		["string1","string2",...]
	 * @returns a vector of string pointers
	 */
	static StrVector * fromString(std::string vectorString);

	/**
	 * Convert a string representation of a two dimensional vector
	 * of strings to a two dimensional vector of string pointers.
	 * @param vectorString string representation of a single
	 * 		dimensional vector of strings.  The string format is:
	 * 		["string1","string2",...]
	 * @returns a two dimensional vector of string pointers
	 */
	static StrVector2D * from2DString(std::string vector2DString);

	/**
	 * Convert a string representation of a single dimensional vector
	 * of integers to a vector of integer pointers.
	 * @param vectorString string representation of a single
	 * 		dimensional vector of integers.  The string format is:
	 * 		["int1","int2",...]
	 * @returns a vector of integer pointers
	 */
	static IntVector * fromIntString(std::string vectorString);

	/**
	 * Convert a string representation of a two dimensional vector
	 * of integers to a two dimensional vector of integer pointers.
	 * @param vectorString string representation of a single
	 * 		dimensional vector of integers.  The string format is:
	 * 		["string1","string2",...]
	 * @returns a two dimensional vector of integer pointers
	 */
	static IntVector2D * from2DIntString(std::string vector2DString);

	/**
	 * Delete all elements of a single dimensional vector of string
	 * pointers.
	 * @param strVector a single dimensional vector of string pointers
	 */
	static void deleteVector(StrVector * strVector);

	/**
	 * Delete all elements of a two dimensional vector of string
	 * pointers.
	 * @param strVector a two dimensional vector of string pointers
	 */
	static void deleteVector(StrVector2D * strVector2D);

	/**
	 * Delete all elements of a single dimensional vector of integer
	 * pointers.
	 * @param strVector a single dimensional vector of integer pointers
	 */
	static void deleteVector(IntVector * intVector);

	/**
	 * Delete all elements of a two dimensional vector of integer
	 * pointers.
	 * @param strVector a two dimensional vector of integer pointers
	 */
	static void deleteVector(IntVector2D * intVector2D);
};

#endif
