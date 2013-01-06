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
include("/var/www/blackjack/data-access/PlayerHitRuleAccess.php");
include("/var/www/blackjack/rule/PlayerHitRule.php");
include("/var/www/php-common/utilities/ArrayUtil.php");

?>

<html>
	<head><meta http-equiv=content-type content="text/html; charset=UTF-8">
		<link href="/css/main.css" rel="stylesheet" type="text/css">    
		<link href="/css/rule.css" rel="stylesheet" type="text/css"> 
		<title>BlackJackTrack</title>
	</head>

	<body>

	<div class="main_content">
  
    <?php
        include("./header.php"); 
        include("./menu.php");
        
        $playerHitRuleAccess = new PlayerHitRuleAccess();
        $rule = $playerHitRuleAccess->readPlayerHitRule($_GET['phr_id']);
        $rule_set_string = $rule['rule_set'];
        // Get two dimensional rule array
        $ruleArray = ArrayUtil::from2DString($rule_set_string);
    ?>    
    <div class="hit_rule_title">
		<?php echo $rule['description'];?>
	</div>
	<div class="edit_hit_rule_link">
		<a href='/pages/edit_player_hit_rule.php?phr_id=<?php echo $_GET['phr_id'];?>'>Create new ruleset from this one</a>
	</div>

    <?php      
        
        print "<table class=rule_table>";
        print "<tr class=rule_table_row><td></td>";
        for($i = 0; $i < 10; $i++) {
        	print "<td class=rule_table_label_cell>" . PlayerHitRule::getDealerHandAbbrev($i) . "</td>";
        }
        
        $i = 0;
        foreach($ruleArray as $row) {
        	print "<tr class=rule_table_row>";
        	print "<td class=rule_table_label_cell>" . PlayerHitRule::getPlayerHandAbbrev($i) . "</td>";
        	$i++;
        	foreach($row as $element) {
        		//error_log($element);
        		print "<td class=rule_table_cell_" . $element . ">" . PlayerHitRule::getHitRuleAbbrev($element) . "</td>";
        	}
        	print "</tr>";
        }
        print "</table>"
    ?>
	</div>

	</body>
</html>


