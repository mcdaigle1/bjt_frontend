function processDone(data) {
  if (data.result -= "success") {
    showSuccessMessage(data.message)
  } else {
    showMessage(data.message)
  }
}

function processFail(jqXHR, textStatus) {
  showErrorMessage(textStatus)
}

function showSuccessMessage(message) {
   
}

function showErrorMessage(message) {

}
