var androidBranded = false;
var iphoneBranded = false;
var forumName = 'BlackjackInfo.com';

function
setCookie (cookieName, cookieValue, expireDays)
{
    var expires = new Date()
    expires.setDate(expires.getDate() + expireDays);
    var val = escape(cookieValue) + ((expires == null) ? '' : ';expires=' + expires.toUTCString());
    document.cookie = cookieName + '=' + val;
}

function
getCookie (cookieName)
{
    var i, x, y, cookiesArray = document.cookie.split(';');
    for (i = 0; i < cookiesArray.length; i++) {
        x = cookiesArray[i].substr(0, cookiesArray[i].indexOf('='));
        y = cookiesArray[i].substr(cookiesArray[i].indexOf('=') + 1);
        x = x.replace(/^\s+|\s+$/g, '');
        if (x == cookieName) {
            return unescape(y);
        }
    }
    return null;
}

function
needForumRunnerPrompt ()
{
    var firstPopup = getCookie('frfdate');
    if (firstPopup == null) {
        var d = new Date();
        setCookie('frfdate', d.toGMTString());
        return true;
    } else {
        var d = new Date(getCookie('frfdate'));
        var now = new Date();
        if (((now - d) / 1000) > 60 * 60 * 24) {
            setCookie('skip_fr_detect', 'true', 9000);
            return true;
        }
    }
    return false;
}

function
forumRunnerPrompt (type, opera)
{
    var operaMsg;
    var safariMsg;

    if (type == 'iPad' || type == 'iPhone') {
        if (iphoneBranded && forumName != '') {
            operaMsg = 'Get our ' + type + ' app for easier viewing and posting on this forum!  Search for "' + forumName + '" in the App Store.';
            safariMsg = 'Get our ' + type + ' app for easier viewing and posting on this forum, optional push notifications and more!';

        } else {
            operaMsg = 'Get our ' + type + ' app for easier viewing and posting on this forum!  Search for "Forum Runner" in the App Store.';
            safariMsg = 'Get our ' + type + ' app for easier viewing and posting on this forum, optional push notifications and more!';
        }
    } else if (type == 'Android') {
        if (androidBranded && forumName != '') {
            safariMsg = 'Get our Android app for easier viewing and posting on this forum, optional push notifications and more!';
            operaMsg = 'Get our Android app for easier viewing and posting on this forum!  Search for "' + forumName + '" in the Market.  Reload this page to load the normal website.';
        } else {
            safariMsg = 'Get our Android app for easier viewing and posting on this forum, optional push notifications and more!';
            operaMsg = 'Get our Android app for easier viewing and posting on this forum!  Search for "Forum Runner" in the Market.  Reload the page to load the normal website.';
        }
    }

    if (opera) {
        setCookie('skip_fr_detect', 'true', 9000);
	alert(operaMsg);
	return;
    }

    if (needForumRunnerPrompt() && confirm(safariMsg)) {
        setCookie('skip_fr_detect', 'true', 9000);
        if (type == 'iPad' || type == 'iPhone') {
            //window.location = 'http://itunes.apple.com/us/app/forum-runner-vbulletin/id362527234?mt=8';
            window.location = 'http://click.linksynergy.com/fs-bin/click?id=*V77VFjwi8w&subid=&offerid=146261.1&type=10&tmpid=3909&RD_PARM1=http%3A%2F%2Fitunes.apple.com%2Fus%2Fapp%2Fforum-runner-vbulletin%2Fid362527234%3Fmt';
        } else if (type == 'Android') {
            window.location = 'market://details?id=net.endoftime.android.forumrunner';
        }
    }
}

function
forumRunnerDetect ()
{
    if (getCookie('skip_fr_detect') == null) {
	var agent = navigator.userAgent.toLowerCase();
	var type;
	var opera = (agent.indexOf('opera') != -1);

	if (agent.indexOf('iphone') != -1) {
	    type = 'iPhone';
	} else if (agent.indexOf('ipod') != -1) {
	    type = 'iPod Touch';
	} else if (agent.indexOf('ipad') != -1) {
	    type = 'iPad';
	} else if (agent.indexOf('android') != -1) {
            type = 'Android';
	} else {
	    return;
	}
        forumRunnerPrompt(type, opera);
    }
}

forumRunnerDetect();
