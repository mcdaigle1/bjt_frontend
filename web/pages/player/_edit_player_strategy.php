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
$StrategyAbbrevs = PlayerStrategyUtil::getStrategyAbbrevArray();

?>
<hr class='strategy_selector_hr'>
<div class='player_strategy_selector_section'>
  <div class='player_strategy_selector_label'>Strategy:</div>
  <div class='player_strategy_selector'> 
    <select class='player_strategy_selector_dropdown' id='player_strategy_selector_dropdown'>
    </select>
  </div>
  <div class='player_strategy_selector_button_section'>
    <button id='player_strategy_selector_button' type='button'>Select</button>
  </div>
  <div class='player_strategy_checkbox_section'>
    <input id='player_strategy_checkbox' type='checkbox' checked>
  </div>
  <div class='player_strategy_checkbox_label'>Include System Strategies</div>
</div>
<hr class='strategy_selector_hr'>
<div class='strategy_section'>
  <div class='strategy_table_section'> 
    <div class='strategy_table_label_top'>Dealer Up Card</div>
    <table class='strategy_table'>
      <tr class='strategy_table_row'><td></td><td></td>
<?php for($i = 0; $i < 10; $i++) { ?>
        <td class='strategy_table_label_cell_top'><?php DealerStrategyUtil::getDealerHandAbbrev($i); ?></td>
<?php }
      // each row is an array of numeric values that represent a hit action
      for ($i = 0; $i < count($strategyArray); ++$i) {
        $strategyRow = $strategyArray[$i];
?>
       <tr class='strategy_table_row'>
<?php   if ($i == 7) { ?>
        <td>Player Cards</td>
<?php   } else { ?>
        <td></td>
<?php   } ?>
        <td class='strategy_table_label_cell_left'><?php PlayerStrategyUtil::getPlayerHandAbbrev($i); ?></td>

<?php   // each hit action is a number that represents a hit action
        for ($j = 0; $j < count($strategyRow); ++$j) {
          $hitAction = $strategyRow[$j];
?>
        <td class='strategy_table_cell_display' id='strategy_table_cell_<?php echo $i ?>_<?php echo $j ?>'></td>
<?php   } ?>
      </tr>
<?php } ?>
      <tr class='strategy_table_row'><td></td><td></td>
<?php for($i = 0; $i < 10; $i++) { ?>
      <td class='strategy_table_label_cell_top'><?php DealerStrategyUtil::getDealerHandAbbrev($i); ?></td>
<?php } ?>
    </table>
    <div class='create_strategy_name_input_section'>
      <div class='strategy_name_input_label'>Strategy Name</div>
      <div class='strategy_name_input_field'><input class='strategy_name_input' type='text' id='ps_name_input'></div>
    </div>
    <div class='create_strategy_description_input_section'>
      <div class='strategy_description_input_label'>Strategy Description </div>
      <div class='strategy_description_input_field'><textarea class='strategy_description_input' id='ps_description_input'></textarea></div>
    </div>
    <div class='edit_strategy_button'>
      <input type='submit' value='Save Strategy' id='player_strategy_edit_button'>
    </div>
  </div>
  <div class = 'legend_section'> 
<?php include("pages/player/_strategy_legend.php"); ?>
  </div>
</div>
