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
include_once("util/PlayerStrategyUtil.php");
include_once("util/DealerStrategyUtil.php");
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

  $j = 0;
  // each hit action is a number that represents a hit action
  foreach($strategyRow as $hitAction) {
    // the color of this cell corresponds to the hit action type
    print       "<td class='strategy_table_cell_select'>";
    print         "<select class='strategy_" . $strategy_abbrevs[$hitAction] . " strategy_selector' id='ps_" . $i . "_" . $j ."'>";
    $k = 0;
    // create the dropdown options from the PlayerStrategy::getStrategyAbbrevArray
    foreach($strategy_abbrevs as $strategy_abbrev) {
      if($hitAction == $k) {
        print       "<option selected value='" . $k . "'>" . $strategy_abbrev . "</option>";
      } else {
        print       "<option value='" . $k . "'>" . $strategy_abbrev . "</option>";
      }
      $k++;
    }
    print         "</select>";
    print       "</td>";
    $j++;
  }

  $i++;
  print       "</tr>";
}
print         "<tr class='strategy_table_row'><td></td><td></td>";
for($i = 0; $i < 10; $i++) {
  print         "<td class='strategy_table_label_cell_top'>" . DealerStrategyUtil::getDealerHandAbbrev($i) . "</td>";
}
print       "</table>";
print     "</div>";

print     "<div class='create_strategy_name_input_section'>";
print       "<div class='strategy_name_input_label'>Strategy Name </div>";
print       "<div class='strategy_name_input_field'><input class='strategy_name_input' type='text' id='ps_name_input'></div>";
print     "</div>";
print     "<div class='create_strategy_description_input_section'>";
print       "<div class='strategy_description_input_label'>Strategy Description </div>";
print       "<div class='strategy_description_input_field'><textarea class='strategy_description_input' id='ps_description_input'></textarea></div>";
print     "</div>";
print     "<div class='create_strategy_button'>";
print       "<input type='submit' value='Save Strategy' id='ps_create_button'>";
print     "</div>";
print   "</div>";
print   "<div class = 'legend_section'>";
include("pages/player/_strategy_legend.php");
print   "</div>";
print "</div>";
?>


