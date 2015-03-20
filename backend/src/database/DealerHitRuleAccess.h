/***********************************************************
 * Copyright 2012 Blue Cask Software. All rights reserved.
 *
 * THIS PROGRAM IS CONFIDENTIAL AND PROPRIETARY TO BLUE CASK
 * SOFTWARE.  Any unauthorized use, reproduction, modification, or
 * disclosure of this program is strictly prohibited without the
 * express written permission of an authorized representative of
 * Blue Cask Software.
 ***********************************************************/
#ifndef DEALER_HIT_RULE_ACCESS_H
#define DEALER_HIT_RULE_ACCESS_H

#include <string>
#include <string.h>
#include <mysql++.h>
#include "DbAccess.h"
#include "../rule/DealerHitRule.h"

class DealerHitRuleAccess : public DbAccess {

public:
	/**
	 * Return the singleton DealerHitRuleAccess instance.
	 * @returns the singleton DealerHitRuleAccess object
	 */
	static DealerHitRuleAccess * instance();

	/**
	 * Create a DealerHitRule in the db
	 * @param storable the base object which points at a dealer
	 * 		hit rule
	 */
	void create(Storable * storable);

	/**
	 * Retrieve a DealerHitRule object by ID
	 * @param id the id of the dealer hit rule we want to retrieve
	 * @returns storable object pointing to the dealer hit rule object
	 */
	Storable * read(int id);

	/**
	 * Update a DealerHitRule in the db
	 * @param storable the base object which points at a dealer
	 * 		hit rule
	 */
	void update(Storable * storable);

	/**
	 * Select hit rules by MD5
	 * @param md5 string holding the md5 we are looking for
	 * @returns mysqlpp::StoreQueryResult holding the dealer hit
	 * 		rules.
	 */
	mysqlpp::StoreQueryResult selectByMd5(std::string md5);

	void insertTest();

private:
	DealerHitRuleAccess();

	~DealerHitRuleAccess();

	static DealerHitRuleAccess * _instance;

	DealerHitRule * rowToStorable(mysqlpp::Row row);
};

#endif
