var DEFAULT_SUCCESS_TIMEOUT_SECS = 3
var DEFAULT_ERROR_TIMEOUT_SECS = 0

$(document).ready(function() {
  // if the x is selected in the message box, hide the message
  $(document.body).on('click', '#message_x', function() {
    $("#message_box").css('visibility', 'hidden');
  });
});


// Process ajax result data for display purposes.  This will display a message in the case 
// of processing success or error.
// params:
//   dataObj - the data object returned from an ajax call
function processMessage(dataObj, displaySecs) {
  if (dataObj.result == "success") {
    showSuccessMessage(dataObj.message, displaySecs);
  } else {
    showErrorMessage(dataObj.message, displaySecs);
    
  }
}

// Process ajax result data for display purposes.  This will display a message in the case 
// of processing error.
// params:
//   dataObj - the data object returned from an ajax call
//   displaySecs - int holding the number of seconds the message will display or undefined
//                 for system default DEFAULT_ERROR_TIMEOUT_SECS
function processErrorMessage(dataObj, displaySecs) {
  if (dataObj.result == "error") {
    showErrorMessage(dataObj.message, displaySecs);
  }
}

// Process failed ajax result data for display purposes. 
// params:
//   data - the jquery request object
//   testStatus - string holding request status
//   displaySecs - int holding the number of seconds the message will display or undefined
//                 for system default DEFAULT_ERROR_TIMEOUT_SECS
function processFailMessage(jqXHR, textStatus, displaySecs) {
  showErrorMessage(textStatus, displaySecs);
}


// Display a success message, setting a timer to remove the message after provided number of seconds
// params:
//   message - string holding the message to display
//   displaySecs - int holding the number of seconds the message will display or undefined
//                 for system default DEFAULT_SUCCESS_TIMEOUT_SECS
function showSuccessMessage(message, displaySecs) {
  successHtml =  "<div class='message_success'>";
  successHtml +=   message
  successHtml += "</div>";
  $("#message_content").html(successHtml); 
  $("#message_box").css('visibility', 'visible');

  if (typeof displaySecs === "undefined") {
    displaySecs = DEFAULT_SUCCESS_TIMEOUT_SECS;
  }
  if (displaySecs > 0) {
    window.setTimeout(function() {
      $("#message_box").css('visibility', 'hidden');
    }, displaySecs * 1000);
  }
}

// Display an error message, setting a timer to remove the message after provided number of seconds
// params:
//   message - string holding the message to display
//   displaySecs - int holding the number of seconds the message will display or undefined
//                 for system default DEFAULT_ERROR_TIMEOUT_SECS
function showErrorMessage(message, displaySecs) {
  errorHtml =  "<div class='message_error'>";
  errorHtml +=   message
  errorHtml += "</div>";
  $("#message_content").html(errorHtml);
  $("#message_box").css('visibility', 'visible');

  if (displaySecs == undefined) {
    displaySecs = DEFAULT_ERROR_TIMEOUT_SECS;
  }
  if (displaySecs > 0) {
    window.setTimeout(function() {
      $("#message_box").css('visibility', 'hidden');
    }, displaySecs * 1000);
  }
}
