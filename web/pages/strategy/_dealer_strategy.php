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
include_once("util/DealerStrategyUtil.php");

$dealerHandAbbrevs = DealerStrategyUtil::getHandAbbrevArray();

?>
<hr class='strategy_selector_hr'>
<div class='strategy_selector_section'>
  <div class='strategy_selector_label'>Strategy:</div>
  <div class='strategy_selector'> 
    <select class='strategy_selector_dropdown' id='dealer_strategy_selector_dropdown'>
    </select>
  </div>
  <div class='strategy_selector_button_section'>
    <button id='dealer_strategy_selector_button' type='button'>Select</button>
  </div>
  <div class='strategy_checkbox_section'>
    <input id='dealer_strategy_checkbox' type='checkbox' checked>
  </div>
  <div class='strategy_checkbox_label'>Include System Strategies</div>
  <div class='strategy_edit_button_section' id='dealer_strategy_edit_button_section'>
    <button id='dealer_strategy_edit_button' type='button'>Edit Strategy</button>
  </div>
</div>
<hr class='strategy_selector_hr'>
<div class='strategy_section'>
  <div class='strategy_table_section'> 
    <div class='strategy_table_label_top'>Dealer Up Card</div>
    <table class='dealer_strategy_table'>
<?php for ($i = 0; $i < count($dealerHandAbbrevs); ++$i) { ?>
      <tr class='strategy_table_row'>
<?php   if ($i == 7) { ?>
        <td>Dealer Cards</td>
<?php   } else { ?>
        <td></td>
<?php   } ?>
        <td class='strategy_table_label_cell_left'><?php echo $dealerHandAbbrevs[$i]; ?></td>
        <td class='strategy_table_cell_display' id='dealer_strategy_table_cell_<?php echo $i ?>'></td>
      </tr>
<?php } ?>
    </table>
  </div>
  <div class = 'legend_section'> 
<?php include("pages/strategy/_dealer_strategy_legend.php"); ?>
  </div>
</div>
<div class='strategy_create_section' id='dealer_strategy_create_section'>
  <div class='strategy_create_name_input_section'>
    <div class='strategy_name_input_label'>Strategy Name</div>
    <div class='strategy_name_input_field'><input class='strategy_name_input' type='text' id='dealer_strategy_name_input'></div>
  </div>
  <div class='strategy_create_description_input_section'>
    <div class='strategy_description_input_label'>Strategy Description </div>
    <div class='strategy_description_input_field'><textarea class='strategy_description_input' id='dealer_strategy_description_input'></textarea></div>
  </div>
  <div class='strategy_create_button'>
    <input type='submit' value='Save Strategy' id='dealer_strategy_create_button'>
  </div>
  <div class='strategy_create_cancel'>
    <a id='dealer_strategy_create_cancel'>cancel</a>
  </div>
</div>
