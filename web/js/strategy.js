playerStrategyNames = [];
playerStrategyAbbrevs = ["SR", "HT", "ST", "DH", "SP", "DS"];

$(document).ready(function() {

  $(".game_section_label").click(function() {
    var gameSectionId = $(this).attr("id");
    var prefix = gameSectionId.replace("_label", "");
    var sectionDisplay =  $("#" + prefix + "_section").css("display");
    $(".game_section").hide();
    if(sectionDisplay == "none") {
      $("#" + prefix + "_section").show();
    }
  });

  $(".game_subsection_label").click(function() {
    var gameSubsectionId = $(this).attr("id");
    var prefix = gameSubsectionId.replace("_label", "");
    var subsectionDisplay =  $("#" + prefix + "_subsection").css("display");
    $(".game_subsection").hide();
    if(subsectionDisplay == "none") {
      $("#" + prefix + "_subsection").show();
      $("#" + prefix + "_subsection").css({"border-width":"1px"});
    }
  });

  // when the create strategy button is selected, get the list of existing player strategy names.  If 
  // the strategy name is not taken, make a call to create the new strategy
  $("#ps_create_button").click(function() {
    if($("#ps_name_input").val() == "") {
      alert("You must enter a strategy name");
      return false;
    } 
    if($("#ps_description_input").val() == "") {
      alert("You must enter a strategy definition");
      return false;
    } 

    // get the list of available player strategy names
    $.ajax({
      type: 'POST',
      url: "/handlers/strategyHandler.php",
      data: { getPlayerStrategyNames: "true" },
    }).done(function(data, status) {
      dataObj = JSON.parse(data);
      for(var strategyName in dataObj.playerStrategyNames) playerStrategyNames.push(strategyName);

      if($.inArray($("#ps_name_input").val(), playerStrategyNames) >= 0) {
        alert($("#ps_name_input").val() + " has already been taken");
        return false;
      }

      var strategySet = [];
      for(var i = 0; i < 35; i++) {
        var strategyRow = [];
        for(var j = 0; j < 10; j++) {
          strategyRow.push($("#ps_" + i + "_" + j + " option:selected").val());
        }
        strategySet.push(strategyRow);
      }

      // make a call to create the new strategy
      $.ajax({
        type: 'POST',
        url: "/handlers/strategyHandler.php",
        data: { 
          createPlayerStrategySet: "true", 
          strategySet: JSON.stringify(strategySet), 
          strategySetName: $("#ps_name_input").val(), 
          strategySetDescription: $("#ps_description_input").val() 
        }
      }).done(function(data, status) {
          $("#player_strategy_label_right").html(" - " + $("#ps_name_input").val());
          $("#ps_name_input").val("");
          $("#ps_description_input").val("");
          $("#player_strategy_section").hide();
      });
    });
  }); 

  // change the look of a strategy if a new strategy is selected
  $(".strategy_selector").on('change', function() {
    var oldClass = $(this).attr('class');
    $(this).removeClass(oldClass).addClass("strategy_" + $(this).find('option:selected').text()).addClass("strategy_selector");
  });

});

