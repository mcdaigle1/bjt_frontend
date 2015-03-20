function tweetme(threadid)
{
	tweetlink = fetch_object('tweetlink').className = 'tweeting';
	
	do_tweet = new vB_AJAX_Handler(true);
	do_tweet.onreadystatechange(metweeted);
	do_tweet.send('ajax.php', 'do=tweetme&threadid=' + threadid);
}

function metweeted()
{
	if (do_tweet.handler.readyState == 4 && do_tweet.handler.status == 200)
	{
		if (do_tweet.handler.responseText == 'success')
		{
			fetch_object('tweetlink').className = 'twitterposter tweeted';
			fetch_object('tweetlink').title = vbphrase['already_tweeted'];
		}
		else
		{
			fetch_object('tweetlink').className = 'twitterposter untweeted';
			fetch_object('tweetlink').title = vbphrase['tweetme'];
			alert(do_tweet.handler.responseText);
		}
	}
}

function tweet_counter()
{
	var tweetlength = fetch_object('tweetlength');
	var status_message = fetch_object('status_message');
	var tweet_button = fetch_object('tweet_button');
	
	tweetlength.innerHTML = status_message.value.length;
	
	if (status_message.value.length > 140)
	{
		tweetlength.className = 'red';
		tweet_button.disabled = 'disabled';
	}
	else
	{
		tweetlength.className = '';
		tweet_button.disabled = '';
	}
}

function shorten_url()
{
	fetch_object('twitterposter_url_img').style.display = 'inline';
	fetch_object('twitterposter_url_button').disabled = 'disabled';
	
	do_shorten_url = new vB_AJAX_Handler(true);
	do_shorten_url.onreadystatechange(url_shortened);
	do_shorten_url.send('ajax.php', 'do=shorten_url&url=' + fetch_object('twitterposter_url').value);
	
}

function url_shortened()
{
	if (do_shorten_url.handler.readyState == 4 && do_shorten_url.handler.status == 200)
	{
		fetch_object('twitterposter_url').value = do_shorten_url.handler.responseText;
		fetch_object('twitterposter_url_img').style.display = 'none';
		fetch_object('twitterposter_url_button').disabled = '';
	}
}

function fast_tweet()
{
	var status_message = fetch_object('status_message').value;
	
	if (status_message != '')
	{
		fetch_object('tweet_img').style.display = 'inline';
		fetch_object('tweet_button').disabled = 'disabled';
		fetch_object('status_message').readOnly = true;
		
		do_fast_tweet = new vB_AJAX_Handler(true);
		do_fast_tweet.onreadystatechange(tweeted_fastly);
		do_fast_tweet.send('ajax.php', 'do=fast_tweet&status=' + status_message);
	}
	else
	{
		alert(vbphrase['at_least_write_something']);
	}
}

function tweeted_fastly()
{
	fetch_object('tweet_img').style.display = 'none';
	fetch_object('tweet_button').disabled = '';
	fetch_object('status_message').readOnly = false;
	
	if (do_fast_tweet.handler.readyState == 4 && do_fast_tweet.handler.status == 200)
	{
		if (do_fast_tweet.handler.responseText == 'success')
		{
			fetch_object('status_message').value = '';
			fetch_object('tweetlength').innerHTML = '0';
			fetch_object('tweetlink').className = 'twitterposter tweeted';
			fetch_object('tweetlink').title = vbphrase['already_tweeted'];
		}
		else
		{
			fetch_object('tweetlink').className = 'twitterposter untweeted';
			fetch_object('tweetlink').title = vbphrase['tweetme'];
			alert(do_fast_tweet.handler.responseText);
		}
	}
}