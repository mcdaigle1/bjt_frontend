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
include_once("util/BetStrategyUtil.php");
?>
<hr class='bet_selector_hr'>
<div class='bet_selector_section'>
  <div class='bet_selector_label'>Bet Rule:</div>
  <div class='bet_selector'>
    <select class='bet_selector_dropdown' id='bet_selector_dropdown'>
    </select>
  </div>
  <div class='bet_selector_button_section'>
    <button id='bet_selector_button' type='button'>Select</button>
  </div>
  <div class='bet_checkbox_section'>
    <input id='bet_checkbox' type='checkbox' checked>
  </div>
  <div class='bet_checkbox_label'>Include System Bet Rules</div>
  <div class='bet_edit_button_section' id='bet_edit_button_section'>
    <button id='bet_edit_button' type='button'>Edit Bet Rule</button>
  </div>
</div>
<hr class='bet_selector_hr'>
<div class='bet_section'>
</div>
<div class='bet_create_section' id='bet_create_section'>
  <div class='bet_create_name_input_section'>
    <div class='bet_name_input_label'>Bet Rule Name</div>
    <div class='bet_name_input_field'>
      <input class='bet_name_input' type='text' id='bet_name_input'>
    </div>
  </div>
  <div class='bet_create_description_input_section'>
    <div class='bet_description_input_label'>Bet Rule Description </div>
    <div class='bet_description_input_field'>
      <textarea class='bet_description_input' id='bet_description_input'></textarea>
    </div>
  </div>
  <div class='bet_create_start_bet_input_section'>
    <div class='bet_input_section_label'>Starting Bet</div>
    <div class='bet_radio_input_section'>
       <div class='bet_radio_input'>
         <input id='start_bet_minimum' type="radio" name="radio_start_bet" checked>
       </div>
       <div class='bet_radio_input_label'>Game minimum</div>
    </div>
    <div class='bet_radio_input_section'>
       <div class='bet_radio_input'>
         <input id='start_bet_minimum_times' type="radio" name="radio_start_bet">
       </div>
       <div class='bet_radio_input_label'>Game minimum X </div>
       <div class='bet_multiplier_input_field'>
         <input id='start_bet_minimum_times_multiplier' class='bet_multiplier_input' type='text'>
       </div> 
    </div>
  </div>
  <div class='bet_create_win_bet_input_section'>
    <div class='bet_input_section_label'>After Win</div>
    <div class='bet_input_subsection_label'>Next Bet:</div>
    <div class='bet_radio_input_section'>
       <div class='bet_radio_input'>
         <input id='win_bet_let_ride' type="radio" name="radio_win_next_bet" checked>
       </div>
       <div class='bet_radio_input_label'>Let winnings ride</div>
    </div>
    <div class='bet_radio_input_section'>
       <div class='bet_radio_input'>
         <input id='win_bet_minimum' type="radio" name="radio_win_next_bet">
       </div>
       <div class='bet_radio_input_label'>Bet game minimum</div>
    </div>
    <div class='bet_radio_input_section'>
       <div class='bet_radio_input'>
         <input id='win_bet_increase_by_minimum' type="radio" name="radio_win_next_bet">
       </div>
       <div class='bet_radio_input_label'>Increase existing bet by game minimum</div>
    </div>
    <div class='bet_radio_input_section'>
       <div class='bet_radio_input'>
         <input id='win_bet_increase_by_minimum_times' type="radio" name="radio_win_next_bet">
       </div>
       <div class='bet_radio_input_label'>Increase existing bet by game minimum X</div>
       <div class='bet_multiplier_input_field'>
         <input id='win_bet_increase_by_minimum_times_multiplier' class='bet_multiplier_input' type='text'>
       </div>
    </div>
    <div class='bet_radio_input_section'>
       <div class='bet_radio_input'>
         <input id='win_bet_double_down' type="radio" name="radio_win_next_bet">
       </div>
       <div class='bet_radio_input_label'>Double exiting bet</div>
    </div>
    <div class='bet_radio_input_section'>
       <div class='bet_radio_input'>
         <input id='win_bet_decrease_by_minimum' type="radio" name="radio_win_next_bet">
       </div>
       <div class='bet_radio_input_label'>Decrease existing bet by game minimum</div>
    </div>
    <div class='bet_radio_input_section'>
       <div class='bet_radio_input'>
         <input id='win_bet_decrease_by_minimum_times' type="radio" name="radio_win_next_bet">
       </div>
       <div class='bet_radio_input_label'>Decrease existing bet by game minimum X</div>
       <div class='bet_multiplier_input_field'>
         <input id='win_bet_decrease_by_minimum_times_multiplier' class='bet_multiplier_input' type='text'>
       </div>
    </div>
    <div class='bet_radio_input_section'>
       <div class='bet_radio_input'>
         <input id='win_bet_halve' type="radio" name="radio_win_next_bet">
       </div>
       <div class='bet_radio_input_label'>Halve existing bet</div>
    </div>
    <div class='bet_input_subsection_label'>Repeat:</div>
    <div class='bet_radio_input_section'>
       <div class='bet_radio_input'>
         <input id='win_repeat_forever' type="radio" name="radio_win_repeat_bet" checked>
       </div>
       <div class='bet_radio_input_label'>Forever</div>
    </div>
    <div class='bet_radio_input_section'>
       <div class='bet_radio_input'>
         <input id='win_repeat_times' type="radio" name="radio_win_repeat_bet">
       </div>
       <div class='bet_multiplier_input_field'>
         <input id='win_repeat_times_multiplier' class='bet_multiplier_input' type='text'>
       </div>
       <div class='bet_radio_input_label'>times then return to starting bet</div>
    </div>
    <div class='bet_input_section_label'>After Loss</div>
    <div class='bet_input_subsection_label'>Next Bet:</div>
    <div class='bet_radio_input_section'>
       <div class='bet_radio_input'>
         <input id='lose_bet_let_ride' type="radio" name="radio_loss_next_bet" checked>
       </div>
       <div class='bet_radio_input_label'>Let winnings ride</div>
    </div>
    <div class='bet_radio_input_section'>
       <div class='bet_radio_input'>
         <input id='lose_bet_minimum' type="radio" name="radio_loss_next_bet">
       </div>
       <div class='bet_radio_input_label'>Bet game minimum</div>
    </div>
    <div class='bet_radio_input_section'>
       <div class='bet_radio_input'>
         <input id='lose_bet_increase_by_minimum' type="radio" name="radio_loss_next_bet">
       </div>
       <div class='bet_radio_input_label'>Increase existing bet by game minimum</div>
    </div>
    <div class='bet_radio_input_section'>
       <div class='bet_radio_input'>
         <input id='lose_bet_increase_by_minimum_times' type="radio" name="radio_loss_next_bet">
       </div>
       <div class='bet_radio_input_label'>Increase existing bet by game minimum X</div>
       <div class='bet_multiplier_input_field'>
         <input id='lose_bet_increase_by_minimum_times_multiplier' class='bet_multiplier_input' type='text'>
       </div>
    </div>
    <div class='bet_radio_input_section'>
       <div class='bet_radio_input'>
         <input id='lose_bet_double' type="radio" name="radio_loss_next_bet">
       </div>
       <div class='bet_radio_input_label'>Double exiting bet</div>
    </div>
    <div class='bet_radio_input_section'>
       <div class='bet_radio_input'>
         <input id='lose_bet_decrease_by_minimum' type="radio" name="radio_loss_next_bet">
       </div>
       <div class='bet_radio_input_label'>Decrease existing bet by game minimum</div>
    </div>
    <div class='bet_radio_input_section'>
       <div class='bet_radio_input'>
         <input id='lose_bet_decrease_by_minimum_times' type="radio" name="radio_loss_next_bet">
       </div>
       <div class='bet_radio_input_label'>Decrease existing bet by game minimum X</div>
       <div class='bet_multiplier_input_field'>
         <input id='lose_bet_decrease_by_minimum_times_multiplier' class='bet_multiplier_input' type='text'>
       </div>
    </div>
    <div class='bet_radio_input_section'>
       <div class='bet_radio_input'>
         <input id='lose_bet_halve' type="radio" name="radio_loss_next_bet">
       </div>
       <div class='bet_radio_input_label'>Halve existing bet</div>
    </div>
    <div class='bet_input_subsection_label'>Repeat:</div>
    <div class='bet_radio_input_section'>
       <div class='bet_radio_input'>
         <input id='lose_repeat_forever' type="radio" name="radio_lose_repeat_bet" checked>
       </div>
       <div class='bet_radio_input_label'>Forever</div>
    </div>
    <div class='bet_radio_input_section'>
       <div class='bet_radio_input'>
         <input id='lose_repeat_times' type="radio" name="radio_lose_repeat_bet">
       </div>
       <div class='bet_multiplier_input_field'>
         <input id='lose_repeat_times_multiplier' class='bet_multiplier_input' type='text'>
       </div>
       <div class='bet_radio_input_label'>times then return to starting bet</div>
    </div>
  </div>
  </div>
  <div class='bet_create_button'>
    <input type='submit' value='Save Bet Rule' id='bet_create_button'>
  </div>
  <div class='bet_create_cancel'>
    <a id='bet_create_cancel'>cancel</a>
  </div>
</div>
