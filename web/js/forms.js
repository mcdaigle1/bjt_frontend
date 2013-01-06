
function validatePHRuleEditForm(all_descriptions) {
	var form_hr_name = document.forms["phr_edit_form"]["hit_rule_name"].value;
	
	if (form_hr_name.search("XXXXXXXX") != -1) {
		alert("name connot contain XXXXXXXX");
		return false;
	}
	if (all_descriptions.search("XXXXXXXX" + form_hr_name + "XXXXXXXX") != -1) {
		alert("Name has already been used: " + form_hr_name);
		return false;
	}
}