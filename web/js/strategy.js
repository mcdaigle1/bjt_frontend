playerStrategyAbbrevs = ["SR", "HT", "ST", "DH", "SP", "DS"];
dealerStrategyAbbrevs = ["HT", "ST"];
globalPlayerStrategySet = "";
globalDealerStrategySet = "";

$(document).ready(function() {
  // get player and dealer strategy names and load dropdowns
  load_player_select_dropdown();
  load_dealer_select_dropdown();
  // activate the correct tab based on the values saved from the request params
  activate_tab();

  // when the create strategy button is selected, get the list of existing player strategy names.  If 
  // the strategy name is not taken, make a call to create the new strategy
  $("#player_strategy_create_button").click(function() {
    if($("#player_strategy_name_input").val() == "") {
      alert("You must enter a strategy name");
      return false;
    } 
    if($("#player_strategy_description_input").val() == "") {
      alert("You must enter a strategy definition");
      return false;
    } 

    var strategySet = [];
    for(var i = 0; i < 35; i++) {
      var strategyRow = [];
      for(var j = 0; j < 10; j++) {
        strategyRow.push(parseInt($("#player_strategy_" + i + "_" + j + " option:selected").val()));
      }
      strategySet.push(strategyRow);
    }

    // make a call to create the new strategy
    $.ajax({
      type: 'POST',
      url: "/handlers/playerStrategyHandler.php",
      data: { 
        createPlayerStrategySet: "true", 
        strategySet: JSON.stringify(strategySet), 
        strategySetName: $("#player_strategy_name_input").val(), 
        strategySetDescription: $("#player_strategy_description_input").val() 
      }
    }).done(function(data, status) {
      $("#player_strategy_label_right").html(" - " + $("#player_strategy_name_input").val());
      $("#player_strategy_name_input").val("");
      $("#player_strategy_description_input").val("");
      $("#player_strategy_section").hide();

      load_player_select_dropdown(); 
    });

  }); 

  // change the look of a strategy if a new strategy is selected
  $(document.body).on('change', '.strategy_selector' ,function() {
    var oldClass = $(this).attr('class');
    $(this).removeClass(oldClass).addClass("strategy_" + $(this).find('option:selected').text()).addClass("strategy_selector");
  });

  // When the player strategy is selected, get the strategy set info and display it
  $("#player_strategy_selector_button").click(function() {
    var strategy_id = $("#player_strategy_selector_dropdown").val();

    $.ajax({
      type: 'POST',
      url: "/handlers/playerStrategyHandler.php",
      data: {
        getPlayerStrategySet: "true",
        strategyId: strategy_id
      }
    }).done(function(data, status) {
      var dataObj = JSON.parse(data);
      var playerStrategySet = dataObj.playerStrategySet["strategy_set"];
      var playerStrategySetArray = JSON.parse(playerStrategySet);
      // set the player strategy set globally
      globalPlayerStrategySet = playerStrategySetArray.slice();
      show_player_strategy_view();
      $("#player_strategy_edit_button_section").css('display', 'inline-block');
    });
  });

  // When the dealer strategy is selected, get the strategy set info and display it
  $("#dealer_strategy_selector_button").click(function() {
    var strategy_id = $("#dealer_strategy_selector_dropdown").val();

    $.ajax({
      type: 'POST',
      url: "/handlers/dealerStrategyHandler.php",
      data: {
        getDealerStrategySet: "true",
        strategyId: strategy_id
      }
    }).done(function(data, status) {
      var dataObj = JSON.parse(data);
      var dealerStrategySet = dataObj.dealerStrategySet["strategy_set"];
      var dealerStrategySetArray = JSON.parse(dealerStrategySet);
      // set the dealer strategy set globally
      globalDealerStrategySet = dealerStrategySetArray.slice();
      show_dealer_strategy_view();
      $("#dealer_strategy_edit_button_section").css('display', 'inline-block');
    });
  });

  // if the edit player strategy button is pushed, display dropdowns in the strategy cells and display the submit section
  $("#player_strategy_edit_button").click(function() {
    for (var i = 0; i < globalPlayerStrategySet.length; i++) {
      for (var j = 0; j < globalPlayerStrategySet[i].length; j++) {
        hitAction = globalPlayerStrategySet[i][j];
        strategyHtml = "<select class='strategy_" + playerStrategyAbbrevs[hitAction] + " strategy_selector' id='" + i + "_" + j + "'>";
        for (var k = 0; k < playerStrategyAbbrevs.length; k++) {
          var strategyAbbrev = playerStrategyAbbrevs[k];
          if(hitAction == k) {
            strategyHtml += "<option selected value='" + k + "'>" + strategyAbbrev + "</option>";
          } else {
            strategyHtml += "<option value='" + k + "'>" + strategyAbbrev + "</option>";
          }
        }     
        strategyHtml += "</select>";

        $("#player_strategy_table_cell_" + i + "_" + j).html(strategyHtml);
      }
    }
    $("#player_strategy_create_section").css('display', 'block');
  });

  // if the edit dealer strategy button is pushed, display dropdowns in the strategy cells and display the submit section
  $("#dealer_strategy_edit_button").click(function() {
    for (var i = 0; i < globalDealerStrategySet.length; i++) {
      hitAction = globalDealerStrategySet[i];
      strategyHtml = "<select class='strategy_" + dealerStrategyAbbrevs[hitAction] + " strategy_selector' id='" + i + "'>";
      for (var j = 0; j < dealerStrategyAbbrevs.length; j++) {
        var strategyAbbrev = dealerStrategyAbbrevs[j];
        if (hitAction == j) {
          strategyHtml += "<option selected value='" + j + "'>" + strategyAbbrev + "</option>";
        } else {
          strategyHtml += "<option value='" + j + "'>" + strategyAbbrev + "</option>";
        }
      }
      strategyHtml += "</select>";

      $("#dealer_strategy_table_cell_" + i).html(strategyHtml);
    }
    $("#dealer_strategy_create_section").css('display', 'block');
  });

  $("#player_strategy_checkbox").click(function() {
    load_player_select_dropdown();
  });

  $("#player_strategy_create_cancel").click(function() {
    show_player_strategy_view();
    $("#player_strategy_create_section").css('display', 'none');
  });
});

// load the player select dropdown with default and player strategies
function load_player_select_dropdown() {
  $.ajax({
    type: 'POST',
    url: "/handlers/playerStrategyHandler.php",
    data: {
      getPlayerStrategyInfo: "true"
    }
  }).done(function(data, status) {
    var dataObj = JSON.parse(data);
    var playerStrategyInfos = dataObj.playerStrategyInfo;
    var systemStrategyInfos = dataObj.systemStrategyInfo;

    var options = "";
    if ($("#player_strategy_checkbox").is(':checked')) {
      for (var i = 0; i < systemStrategyInfos.length; i++) {
        options += "<option value='" + systemStrategyInfos[i]["id"] + "' class='player_strategy_option'>[" + systemStrategyInfos[i]["name"] + "]</option>";
      }
    }
    for (var i = 0; i < playerStrategyInfos.length; i++) {
      options += "<option value='" + playerStrategyInfos[i]["id"] + "' class='player_strategy_option'>" + playerStrategyInfos[i]["name"] + "</option>";
    }
    $("#player_strategy_selector_dropdown").html(options);
  });
}

// load the player select dropdown with default and player strategies
function load_dealer_select_dropdown() {
  $.ajax({
    type: 'POST',
    url: "/handlers/dealerStrategyHandler.php",
    data: {
      getDealerStrategyInfo: "true"
    }
  }).done(function(data, status) {
    var dataObj = JSON.parse(data);
    var dealerStrategyInfos = dataObj.dealerStrategyInfo;
    var systemStrategyInfos = dataObj.systemStrategyInfo;

    var options = "";
    if ($("#dealer_strategy_checkbox").is(':checked')) {
      for (var i = 0; i < systemStrategyInfos.length; i++) {
        options += "<option value='" + systemStrategyInfos[i]["id"] + "' class='dealer_strategy_option'>[" + systemStrategyInfos[i]["name"] + "]</option>";
      }
    }
    for (var i = 0; i < dealerStrategyInfos.length; i++) {
      options += "<option value='" + dealerStrategyInfos[i]["id"] + "' class='dealer_strategy_option'>" + dealerStrategyInfos[i]["name"] + "</option>";
    }
    $("#dealer_strategy_selector_dropdown").html(options);
  });
}

function show_player_strategy_view() {
  for (var i = 0; i < globalPlayerStrategySet.length; i++) {
    for (var j = 0; j < globalPlayerStrategySet[i].length; j++) {
      var playerStrategyAbbrev = playerStrategyAbbrevs[globalPlayerStrategySet[i][j]];
      var strategyHtml = "<div class='strategy_" + playerStrategyAbbrev + " strategy_display'>" +  playerStrategyAbbrev + "</div>";
      $("#player_strategy_table_cell_" + i + "_" + j).html(strategyHtml);
    }
  }
}

function show_dealer_strategy_view() {
  for (var i = 0; i < globalDealerStrategySet.length; i++) {
      var dealerStrategyAbbrev = dealerStrategyAbbrevs[globalDealerStrategySet[i]];
      var strategyHtml = "<div class='strategy_" + dealerStrategyAbbrev + " strategy_display'>" +  dealerStrategyAbbrev + "</div>";
      $("#dealer_strategy_table_cell_" + i).html(strategyHtml);
  }
}

// Set the currently active tab based on a tab index element set from request params
function activate_tab() {
  var tab_index = $("#tab_index").text();
  switch(tab_index) {
    case "1":
      var oldClass = $("#tab_player_strategy").attr('class');
      $("#tab_player_strategy").removeClass(oldClass).addClass("tab").addClass("active_tab");
      $("#section_player_strategy").removeClass(oldClass).addClass("tab_section").addClass("active_section");
      break;
    case "2":
      var oldClass = $("#tab_dealer_strategy").attr('class');
      $("#tab_dealer_strategy").removeClass(oldClass).addClass("tab").addClass("active_tab");
      $("#section_dealer_strategy").removeClass(oldClass).addClass("tab_section").addClass("active_section");
      break;
    default:
      var oldClass = $("#tab_player_strategy").attr('class');
      $("#tab_player_strategy").removeClass(oldClass).addClass("tab").addClass("active_tab");
      $("#section_player_strategy").removeClass(oldClass).addClass("tab_section").addClass("active_section");
      break;
  }
}
