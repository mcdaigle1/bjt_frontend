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
$playerHandAbbrevs = PlayerStrategyUtil::getHandAbbrevArray();
$dealerFirstCardAbbrevs = DealerStrategyUtil::getFirstCardAbbrevArray();

?>
<hr class='strategy_selector_hr'>
<div class='strategy_selector_section'>
  <div class='strategy_selector_label'>Strategy:</div>
  <div class='strategy_selector'> 
    <select class='strategy_selector_dropdown' id='player_strategy_selector_dropdown'>
    </select>
  </div>
  <div class='strategy_selector_button_section'>
    <button id='player_strategy_selector_button' type='button'>Select</button>
  </div>
  <div class='strategy_checkbox_section'>
    <input id='player_strategy_checkbox' type='checkbox' checked>
  </div>
  <div class='strategy_checkbox_label'>Include System Strategies</div>
  <div class='strategy_edit_button_section' id='player_strategy_edit_button_section'>
    <button id='player_strategy_edit_button' type='button'>Edit Strategy</button>
  </div>
</div>
<hr class='strategy_selector_hr'>
<div class='strategy_section'>
  <div class='strategy_table_section'> 
    <div class='strategy_table_label_top'>Dealer Up Card</div>
    <table class='player_strategy_table'>
      <tr class='strategy_table_row'><td></td><td></td>
<?php for($i = 0; $i < count($dealerFirstCardAbbrevs); $i++) { ?>
        <td class='strategy_table_label_cell_top'><?php echo $dealerFirstCardAbbrevs[$i]; ?></td>
<?php }
      // each row is an array of numeric values that represent a hit action
      for ($i = 0; $i < count($playerHandAbbrevs); ++$i) {
?>
       <tr class='strategy_table_row'>
<?php   if ($i == 7) { ?>
        <td>Player Cards</td>
<?php   } else { ?>
        <td></td>
<?php   } ?>
        <td class='strategy_table_label_cell_left'><?php echo $playerHandAbbrevs[$i]; ?></td>

<?php   for ($j = 0; $j < count($dealerFirstCardAbbrevs); ++$j) {
?>
        <td class='strategy_table_cell_display' id='player_strategy_table_cell_<?php echo $i ?>_<?php echo $j ?>'></td>
<?php   } ?>
      </tr>
<?php } ?>
      <tr class='strategy_table_row'><td></td><td></td>
<?php for($i = 0; $i < count($dealerFirstCardAbbrevs); $i++) { ?>
        <td class='strategy_table_label_cell_top'><?php echo $dealerFirstCardAbbrevs[$i]; ?></td>
<?php } ?>
    </table>
  </div>
  <div class = 'legend_section'> 
<?php include("pages/strategy/_player_strategy_legend.php"); ?>
  </div>
</div>
<div class='strategy_create_section' id='player_strategy_create_section'>
  <div class='strategy_create_name_input_section'>
    <div class='strategy_name_input_label'>Strategy Name</div>
    <div class='strategy_name_input_field'><input class='strategy_name_input' type='text' id='player_strategy_name_input'></div>
  </div>
  <div class='strategy_create_description_input_section'>
    <div class='strategy_description_input_label'>Strategy Description </div>
    <div class='strategy_description_input_field'><textarea class='strategy_description_input' id='player_strategy_description_input'></textarea></div>
  </div>
  <div class='strategy_create_button'>
    <input type='submit' value='Save Strategy' id='player_strategy_create_button'>
  </div>
</div>
