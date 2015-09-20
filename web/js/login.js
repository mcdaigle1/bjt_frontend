$(document).ready(function() {
  $("#login_button").click(function() {
    if($("#login_user_email").val() == "") {
      alert("User Email is required to log in");
    }
    
    if($("#login_password").val() == "") {
      alert("Password is required to log in");
    }

    $.ajax({
      type: 'POST',
      url: "/handlers/loginHandler.php",
      data: { 
        submitLogin: "true",
        userEmail: $("#login_user_email").val(),
        password: $("#login_password").val()
      }
    }).done(function(data, status) {
      window.location.href = "home.php";
    });
  });
});

