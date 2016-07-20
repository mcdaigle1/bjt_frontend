
/*******************************************************
* This JSON hash holds the 
********************************************************/
var BET_IDS = {
    "start_bet" : {
        {"label" : "start_bet_minimum"},
        {"label" : "start_bet_minimum_times", "multiplier_label" : "<multiplier value>"}
    },
    "win_bet" : {
        {"label" : "win_bet_let_ride"},
        {"label" : "win_bet_minimum"},
        {"label" : "win_bet_increase_by_minimum"},
        {"label" : "win_bet_increase_by_minimum_times", "multiplier_label" : "<multiplier value>"},
        {"label" : "win_bet_double_down"},
        {"label" : "win_bet_decrease_by_minimum"},
        {"label" : "win_bet_decrease_by_minimum_times", "multiplier_label" : "<multiplier value>"},
        {"label" : "win_bet_halve"}
    },
    "win_repeat" : {
        {"label" : "win_repeat_forever"},
        {"label" : "win_repeat_times", "multiplier_label" : "<multiplier value>"}
    },
    "lose_bet" : {
        {"label" : "lose_bet_let_ride"},
        {"label" : "lose_bet_minimum"},
        {"label" : "lose_bet_increase_by_minimum"},
        {"label" : "lose_bet_increase_by_minimum_times", "multiplier_label" : "<multiplier value>"},
        {"label" : "lose_bet_double_down"},
        {"label" : "lose_bet_decrease_by_minimum"},
        {"label" : "lose_bet_decrease_by_minimum_times", "multiplier_label" : "<multiplier value>"},
        {"label" : "lose_bet_halve"}
  },
  "lose_repeat" : {
        {"label" : "lose_repeat_forever"},
        {"label" : "lose_repeat_times", "multiplier_label" : "<multiplier value>"}
  }
}

$(document).ready(function() {
  // get player and dealer strategy names and load dropdowns
  loadBetSelectDropdown();
});

// load the bet select dropdown with default and player bet rules
function loadBetSelectDropdown() {
  try {
    $.ajax({
      type: 'POST',
      url: "/control/betStrategyController.php",
      data: {
        action: "getBetStrategyInfo"
      }
    }).done(function(data) {
      var dataObj = JSON.parse(data);
      processErrorMessage(dataObj);

      var playerBetInfos = dataObj.betStrategyInfo;
      var systemBetInfos = dataObj.systemStrategyInfo;

      var options = "";
      if ($("#bet_checkbox").is(':checked')) {
        for (var i = 0; i < systemBetInfos.length; i++) {
          options += "<option value='" + systemBetInfos[i]["id"] + "' class='bet_option'>[" + systemBetInfos[i]["name"] + "]</option>";
        }
      }
      for (var i = 0; i < playerBetInfos.length; i++) {
        options += "<option value='" + playerBetInfos[i]["id"] + "' class='bet_option'>" + playerBetInfos[i]["name"] + "</option>";
      }
      $("#bet_selector_dropdown").html(options);
    }).fail(function(jqXHR, textStatus, errorThrown) {
      processFailMessage(jqXHR, textStatus);
    });
  } catch(err)  {
    showErrorMessage(err);
    throw err;
  }
}

function show_bet_strategy() {
}
