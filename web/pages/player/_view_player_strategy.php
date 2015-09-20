<?php
/***********************************************************************
 * Copyright 2015 Blue Cask Software. All rights reserved.
 *                                                                                                                       
 * THIS PROGRAM IS CONFIDENTIAL AND PROPRIETARY TO BLUE CASK
 * SOFTWARE.  Any unauthorized use, reproduction, modification, or
 * disclosure of this program is strictly prohibited without the
 * express written permission of an authorized representative of
 * Blue Cask Software..
 ************************************************************************/
include_once("data-access/PlayerStrategyAccess.php");
include_once("util/DealerStrategyUtil.php");
include_once("util/PlayerStrategyUtil.php");
include_once("utilities/ArrayUtil.php");

// get the desired player strategy
$playerStrategyAccess = new PlayerStrategyAccess();

$strategy = $playerStrategyAccess->readPlayerStrategy(PlayerStrategyAccess::DEFAULT_STRATEGY_ID);
$strategySetString = $strategy['strategy_set'];
$strategyArray = json_decode($strategySetString);
$strategy_abbrevs = PlayerStrategyUtil::getStrategyAbbrevArray();

print "<div class='strategy_section'>";
print   "<div class='strategy_table_section'>"; 
print     "<div class='strategy_table_label_top'>Dealer Up Card</div>";
print     "<div class='strategy_table_section'>";
print       "<table class='strategy_table'>";
print         "<tr class='strategy_table_row'><td></td><td></td>";
for($i = 0; $i < 10; $i++) {
  print         "<td class='strategy_table_label_cell_top'>" . DealerStrategyUtil::getDealerHandAbbrev($i) . "</td>";
}

$i = 0;
// each row is an array of numeric values that represent a hit action
foreach($strategyArray as $strategyRow) {
  print       "<tr class='strategy_table_row'>";
  if($i == 7) {
    print       "<td>Player Cards</td>";
  } else {
    print       "<td></td>";
  }
  print         "<td class='strategy_table_label_cell_left'>" . PlayerStrategyUtil::getPlayerHandAbbrev($i) . "</td>";

  // each hit action is a number that represents a hit action
  foreach($strategyRow as $hitAction) {
    // the color of this cell corresponds to the hit action type
    print       "<td class='strategy_table_cell_display'>";
    print         "<div class='strategy_" . $strategy_abbrevs[$hitAction] . " strategy_display'>" .  PlayerStrategyUtil::getStrategyAbbrev($hitAction);
    print       "</td>";
  }

  $i++;
  print       "</tr>";
}
print         "<tr class='strategy_table_row'><td></td><td></td>";
for($i = 0; $i < 10; $i++) {
  print       "<td class='strategy_table_label_cell_top'>" . DealerStrategyUtil::getDealerHandAbbrev($i) . "</td>";
}
print       "</table>";
print     "</div>";
print   "</div>";
print   "<div class = 'legend_section'>"; 
include("pages/player/_strategy_legend.php"); 
print   "</div>";
print "</div>";
