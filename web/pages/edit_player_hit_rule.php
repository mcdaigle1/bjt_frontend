<?php
$pageName="edit_player_hit_rule";
/***********************************************************************
 * Copyright 2012 Blue Cask Software. All rights reserved.
 *                                                                                                                       
 * THIS PROGRAM IS CONFIDENTIAL AND PROPRIETARY TO BLUE CASK
 * SOFTWARE.  Any unauthorized use, reproduction, modification, or
 * disclosure of this program is strictly prohibited without the
 * express written permission of an authorized representative of
 * Blue Cask Software..
 ************************************************************************/
include_once("/var/www/blackjack/data-access/PlayerHitRuleAccess.php");
include_once("/var/www/blackjack/rule/PlayerHitRule.php");
include_once("/var/www/php-common/utilities/ArrayUtil.php");

?>

<html>
  <head><meta http-equiv=content-type content="text/html; charset=UTF-8">
    <link href="/css/main.css" rel="stylesheet" type="text/css"> 
    <link href="/css/rule.css" rel="stylesheet" type="text/css">    
    <script src="/js/forms.js"></script>
    <title>BlackJackTrack</title>
  </head>

  <body>

  <div class="main_content">
    <?php
        include("./header.php"); 
        include("./menu.php");
        
        if (array_key_exists('submit_phr', $_POST)) { 
        	// extract the hit rule values and create a string representation
        	$rule_set_string = "[";  
			for ($i=0; $i < sizeof(PlayerHitRule::getPlayerHandAbbrevArray()); $i++) {
				$rule_set_string .= "[";
				for ($j=0; $j < sizeof(PlayerHitRule::getDealerHandAbbrevArray()); $j++) {
					$rule_set_string .= $_POST['phr_' . $i . "_" . $j];
					if ($j < (sizeof(PlayerHitRule::getDealerHandAbbrevArray()) - 1)) {
						$rule_set_string .= ",";
					}
				}
				$rule_set_string .= "]";
			}
			$rule_set_string .= "]";
			
			
        } else {
        	// get the desired player rule
			$playerHitRuleAccess = new PlayerHitRuleAccess();
			try {
        		$rule = $playerHitRuleAccess->readPlayerHitRule($_GET['phr_id']);
			} catch (AccessException $ae) {
				error_log("Error reading player hit rule: " . $ae->getMessage());
			}
        	$rule_set_string = $rule['rule_set'];
        	// convert the string representation of rules to a 2D array
        	$ruleArray = ArrayUtil::from2DString($rule_set_string);
        	
        	// get a delimited string of rule names.  We use this to 
        	// validate the name does not already exist
        	// TODO get real player ID after login stuff is created
        	try {
        		$ruleNameArray = $playerHitRuleAccess->readAvailableHitRuleNames(10);
        	} catch (AccessException $ae) {
				error_log("Error reading available hit rule: " . $ae->getMessage());
			}
        	$delimiter = "XXXXXXXX";
        	$ruleName = $delimiter;
        	foreach ($ruleNameArray as $ruleNameItem) {
        		$ruleName .= $ruleNameItem["name"];
        		$ruleName .= $delimiter;
        	}
        	
        print "<div class='hit_rule_title'>";
		print "Edit: " . $rule['description'];
		print "</div>";
	
        print "<form method = 'POST' action = " . $_SERVER['PHP_SELF'] . 
        	" name = 'phr_edit_form' onsubmit = 'return validatePHRuleEditForm(\"" . $ruleName . "\")'>";   	
	        
	        print "<table class=rule_table>";
	        print "<tr class=rule_table_row><td></td>";
	        for($i = 0; $i < 10; $i++) {
	        	print "<td class=rule_table_label_cell>" . PlayerHitRule::getDealerHandAbbrev($i) . "</td>";
	        }
	        
	        $i = 0;
	        // each row is an array of numeric values that represent a hit action
	        foreach($ruleArray as $row) {
	        	print "<tr class=rule_table_row>";
	        	print "<td class=rule_table_label_cell>" . PlayerHitRule::getPlayerHandAbbrev($i) . "</td>";
	        	$j = 0;
	        	// each hit_action is a number that represents a hit action
	        	foreach($row as $hit_action) {
	        		// the color of this cell corresponds to the hit action type
	        		print "<td class=rule_table_cell_select>";
	        		print "<select name='phr_" . $i . "_" . $j ."'>";
					$k = 0;
					// create the dropdown options from the PlayerHitRule::getHitRuleAbbrevArray
	        		foreach(PlayerHitRule::getHitRuleAbbrevArray() as $hraa) {
	        			if($hit_action == $k) {
	        				print "<option selected value='" . $k . "'>" . $hraa . "</option>";
	        			} else {
	        				print "<option value='" . $k . "'>" . $hraa . "</option>";
	        			}
						$k++;
	        		}
					print "</select>";
					$j++;
	        	}
	        	$i++;
	        	print "</tr>";
	        }
	        print "</table>";
	  
	        print "<div class='edit_hit_rule_text'>";
	        	print "New Rule Name: <input class='edit_hit_rule_text_input' type='text' name='hit_rule_name'>";
	        print "</div>";
	        print "<div class='edit_hitrule_submit_button'>";
	        	print "<input type='submit' name='Submit' value='Save Ruleset'>";
	       	print "</div>";
			print "<input type='hidden' name='submit_phr' value='1'/>";
		print "</form>";

        }
    ?>
  </div>

  </body>
</html>


