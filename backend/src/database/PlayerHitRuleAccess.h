/***********************************************************
 * Copyright 2012 Blue Cask Software. All rights reserved.
 *
 * THIS PROGRAM IS CONFIDENTIAL AND PROPRIETARY TO BLUE CASK
 * SOFTWARE.  Any unauthorized use, reproduction, modification, or
 * disclosure of this program is strictly prohibited without the
 * express written permission of an authorized representative of
 * Blue Cask Software.
 ***********************************************************/
#ifndef PLAYER_HIT_RULE_ACCESS_H
#define PLAYER_HIT_RULE_ACCESS_H

#include <string>
#include <string.h>
#include <mysql++.h>
#include "DbAccess.h"
#include "../rule/PlayerHitRule.h"

class PlayerHitRuleAccess : public DbAccess {

public:
	/**
	 * Return the singleton PlayerHitRuleAccess instance.
	 * @returns the singleton PlayerHitRuleAccess object
	 */
	static PlayerHitRuleAccess * instance();

	/**
	 * Create a PlayerHitRule in the db
	 * @param storable the base object which points at a player
	 * 		hit rule
	 */
	void create(Storable * storable);

	/**
	 * Retrieve a PlayerHitRule object by ID
	 * @param id the id of the player hit rule we want to retrieve
	 * @returns storable object pointing to the player hit rule object
	 */
	Storable * read(int id);

	/**
	 * Update a Game in the db
	 * @param storable the base object which points at a player hit rule
	 */
	void update(Storable * storable);


	/**
	 * Select player hit rule row by md5.  The md5 is a sum of the string
	 * representation of the hit rule table.
	 * @param md5 string holding md5 sum of string representation of
	 * 		rule table
	 * @returns mysqlpp::StoreQueryResult holding row that matches the rule md5
	 */
	mysqlpp::StoreQueryResult selectByMd5(std::string md5);

private:
	PlayerHitRuleAccess();

	~PlayerHitRuleAccess();

	static PlayerHitRuleAccess * _instance;

	PlayerHitRule * rowToStorable(mysqlpp::Row row);
};

#endif
