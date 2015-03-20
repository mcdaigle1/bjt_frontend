/***********************************************************
 * Copyright 2012 Blue Cask Software. All rights reserved.
 *
 * THIS PROGRAM IS CONFIDENTIAL AND PROPRIETARY TO BLUE CASK
 * SOFTWARE.  Any unauthorized use, reproduction, modification, or
 * disclosure of this program is strictly prohibited without the
 * express written permission of an authorized representative of
 * Blue Cask Software.
 ***********************************************************/
#ifndef HIT_RULE_H
#define HIT_RULE_H

#include "../database/Storable.h"
#include "../utility/VectorUtil.h"

/** HitRuleStatus The status of the hit rule */
enum HitRuleStatus {HR_ACTIVE, HR_INACTIVE};
/** HitRuleAction The actions the player can take */
enum HitRuleAction {HR_SURRENDER, HR_HIT, HR_STAND, HR_DOUBLE, HR_SPLIT, HR_DOUBLE_STAND};


class HitRule : public Storable {
private:

public:


};

#endif
