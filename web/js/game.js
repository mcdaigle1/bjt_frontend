playerGames = [];
systemGames = [];
GAME_STATUS_STR = { 0: "New",
                    1: "Running",
                    2: "interrupted",
                    3: "Complete" }

$(document).ready(function() {
  getPlayerGames();

  $("#game_select_button").click(function() {
    var selectValue = $("#game_select_dropdown").find(":selected").attr('id');
    var selectValueArray = selectValue.split("_")
    var gameId = selectValueArray[selectValueArray.length - 1]
    if (selectValue != "default") {
      $.ajax({
        type: 'POST',
        url: "/control/gameController.php",
        data: {
          getGameDisplayInfo: "true",
          gameId: gameId
        }
      }).done(function(data, status) {
        var dataObj = JSON.parse(data);
        processMessage(dataObj);

        gameDisplayInfo = dataObj.gameDisplayInfo;
        $("#game_name").html(gameDisplayInfo.name);
        $("#game_description").html(gameDisplayInfo.description);
        $("#game_status").html(GAME_STATUS_STR[gameDisplayInfo.status]);
        $("#player_strategy_name").html(gameDisplayInfo.ps_name);
        $("#dealer_strategy_name").html(gameDisplayInfo.ds_name);
        $("#deck_number").html(gameDisplayInfo.num_decks);
        $("#hand_number").html(gameDisplayInfo.hand_limit);
        $("#bankroll").html("$" + gameDisplayInfo.bankroll);
        if(gameDisplayInfo.end_at_zero == 0) {
          $("#end_at_zero").html("False");
        } else {
          $("#end_at_zero").html("True");
        }
      }).fail(function(jqXHR, textStatus, errorThrown) {
        processFailMessage(jqXHR, textStatus);
      });
    }
  });

  $('#system_games_checkbox').change(function() {
    populatePlayerGamesSelector();
  });
//  $("#player_strategy_select_button").click(function() {
//   $("#player_strategy_label_right").html("- " + $("#player_strategy_select_dropdown").val());
//  });

//  $("#player_strategy_create_link").click(function() {
//    $("#player_strategy_select_subsection").hide();
//    $("#player_strategy_create_subsection").show();
//  });

//  $("#player_strategy_select_link").click(function() {
//    $("#player_strategy_create_subsection").hide();
//    $("#player_strategy_select_subsection").show();
//  });
});

function getPlayerGames() {
  $.ajax({
    type: 'POST',
    url: "/control/gameController.php",
    data: {
      getGames: "true"
    }
  }).done(function(data, status) {
    var dataObj = JSON.parse(data);
    processErrorMessage(dataObj);

    playerGames = dataObj.playerGames;
    populatePlayerGamesSelector();
  }).fail(function(jqXHR, textStatus, errorThrown) {
    processFailMessage(jqXHR, textStatus);
  });
}

function getAllGames() {
  $.ajax({
    type: 'POST',
    url: "/control/gameController.php",
    data: {
      getGames: "true"
    }
  }).done(function(data, status) {
    var dataObj = JSON.parse(data);
    processErrorMessage(dataObj);

    playerGames = dataObj.playerGames;
    systemGames = dataObj.systemGames;
    populateAllGamesSelector();
  }).fail(function(jqXHR, textStatus, errorThrown) {
    processFailMessage(jqXHR, textStatus);
  });
}

function populatePlayerGamesSelector() {
  var options = "<option id='default'>Select a Game</option>";
  if($('#system_games_checkbox').is(":checked")) {
    for(var systemGame in systemGames) {
      options += "<option id='player_game_" + systemGame + "' class='system_game_option'>* " + systemGames[systemGame].name + "</option>";
    }
  }
  for(var playerGame in playerGames) {
    options += "<option id='player_game_" + playerGame + "' class='player_game_option'>" + playerGames[playerGame].name + "</option>";
  }
  $("#game_select_dropdown").html(options);
}

function populateAllGamesSelector() {
  var options = "<option id='default'>Select a Game</option>";
  if($('#system_games_checkbox').is(":checked")) {
    for(var systemGame in systemGames) {
      options += "<option id='player_game_" + systemGame + "' class='system_game_option'>* " + systemGames[systemGame].name + "</option>";
    }
  }
  for(var playerGame in playerGames) {
    options += "<option id='player_game_" + playerGame + "' class='player_game_option'>" + playerGames[playerGame].name + "</option>";
  }
  $("#game_select_dropdown").html(options);
}
