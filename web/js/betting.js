$(document).ready(function() {
  // get player and dealer strategy names and load dropdowns
  loadBettingSelectDropdown();

});

// load the betting select dropdown with default and player betting rules
function loadBettingSelectDropdown() {
  $.ajax({
    type: 'POST',
    url: "/handlers/betRuleHandler.php",
    data: {
      getBettingInfo: "true"
    }
  }).done(function(data) {
    var dataObj = JSON.parse(data);
    processDone(dataObj)

    var playerBettingInfos = dataObj.playerBettingInfo;
    var systemBettingInfos = dataObj.systemBettingInfo;

    var options = "";
    if ($("#betting_checkbox").is(':checked')) {
      for (var i = 0; i < systemBettingInfos.length; i++) {
        options += "<option value='" + systemBettingInfos[i]["id"] + "' class='betting_option'>[" + systemBettingInfos[i]["name"] + "]</option>";
      }
    }
    for (var i = 0; i < playerStrategyInfos.length; i++) {
      options += "<option value='" + playerBettingInfos[i]["id"] + "' class='betting_option'>" + playerBettingInfos[i]["name"] + "</option>";
    }
    $("#betting_selector_dropdown").html(options);
  }).fail(function(jqXHR, textStatus, errorThrown) {
    processFail(jqXHR, textStatus)
  });
}

function show_betting_strategy() {
}
