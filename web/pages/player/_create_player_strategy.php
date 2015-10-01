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
$strategyAbbrevs = PlayerStrategyUtil::getStrategyAbbrevArray();
      
?>
<div class='strategy_section'>
  <div class='strategy_table_section'>
    <div class='strategy_table_label_top'>Dealer Up Card</div>
    <div class='strategy_table_section'>
      <table class='strategy_table'>
        <tr class='strategy_table_row'><td></td><td></td>
<?php for($i = 0; $i < 10; $i++) { ?>
          <td class='strategy_table_label_cell_top'><?php echo DealerStrategyUtil::getDealerHandAbbrev($i) ?></td>
<?php } 
      
      // each row is an array of numeric values that represent a hit action
      for ($i = 0; $i < count($strategyArray); ++$i) {
        $strategyRow = $strategyArray[$i];
?>
        <tr class='strategy_table_row'>
<?php   if($i == 7) { ?>
          <td>Player Cards</td>
<?php   } else { ?>
          <td></td>
<?php   } ?>
          <td class='strategy_table_label_cell_left'><?php echo PlayerStrategyUtil::getPlayerHandAbbrev($i) ?></td>
<?php   // each hit action is a number that represents a hit action
        for ($j = 0; $j < count($strategyRow); ++$j) {
          $hitAction = $strategyRow[$j];
          // the color of this cell corresponds to the hit action type
?>
          <td class='strategy_table_cell_select'>
            <select class='strategy_<?php echo  $strategyAbbrevs[$hitAction] ?> strategy_selector' id='ps_<?php echo $i ?>_<?php echo $j ?>'>
<?php     // create the dropdown options from the PlayerStrategy::getStrategyAbbrevArray
          for ($k = 0; $k < count($strategyAbbrevs); ++$k) {
            $strategyAbbrev = $strategyAbbrevs[$k];
            if($hitAction == $k) {
?>
              <option selected value='<?php echo $k ?>'><?php echo $strategyAbbrev ?></option>
<?php       } else { ?>
              <option value='<?php echo $k ?>'><?php echo $strategyAbbrev ?></option>
<?php       }
          }
?>
            </select>
          </td>
<?php   } ?>
        </tr>
<?php } ?>
        <tr class='strategy_table_row'><td></td><td></td>
<?php for($i = 0; $i < 10; $i++) { ?>
          <td class='strategy_table_label_cell_top'><?php echo DealerStrategyUtil::getDealerHandAbbrev($i) ?></td>
<?php } ?>
      </table>
    </div>
    <div class='create_strategy_name_input_section'>
      <div class='strategy_name_input_label'>Strategy Name</div>
      <div class='strategy_name_input_field'><input class='strategy_name_input' type='text' id='ps_name_input'></div>
    </div>
    <div class='create_strategy_description_input_section'>
      <div class='strategy_description_input_label'>Strategy Description </div>
      <div class='strategy_description_input_field'><textarea class='strategy_description_input' id='ps_description_input'></textarea></div>
    </div>
    <div class='create_strategy_button'>
      <input type='submit' value='Save Strategy' id='ps_create_button'>
    </div>
  </div>
  <div class = 'legend_section'>
<?php include("pages/player/_strategy_legend.php"); ?>
  </div>
</div>
