$(document).ready(function() {
  $('.tab').on('click', function(e)  {
    var currentId = jQuery(this).attr('id');
    var idArray = currentId.split("_");
    var idRoot = "";
    for (var i = 1; i < idArray.length; i++) {
      if (i == 1) {
        idRoot = idArray[i];
      } else {
        idRoot += "_" + idArray[i];
      }
    }
 
    // Show/Hide Tabs
    $('.tab_section').hide();
    $('.tab').removeClass('active_tab');
    $('.tab').addClass('inactive_tab');
    $('#tab_' + idRoot).removeClass('inactive_tab');
    $('#tab_' + idRoot).addClass('active_tab');
    $('#section_' + idRoot).show();   
  });
});
