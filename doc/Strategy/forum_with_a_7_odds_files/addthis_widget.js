/* (c) 2008-2012 Add This, LLC */
if(!((window._atc||{}).ver)){var _atd="www.addthis.com/",_atr="//s7.addthis.com/",_euc=encodeURIComponent,_duc=decodeURIComponent,_atc={rrev:114791,dr:0,ver:250,loc:0,enote:"",cwait:500,bamp:0.25,camp:1,csmp:0.0001,damp:0,famp:0.02,pamp:0.2,tamp:1,lamp:1,vamp:1,vrmp:0.0001,ohmp:0,ltj:1,xamp:1,abf:!!window.addthis_do_ab,qs:0,cdn:0,rsrcs:{bookmark:_atr+"static/r07/bookmark018.html",atimg:_atr+"static/r07/atimg018.html",countercss:_atr+"static/r07/counter002.css",counterIE67css:_atr+"static/r07/counterIE67002.css",counter:_atr+"static/r07/counter002.js",core:_atr+"static/r07/core023.js",wombat:_atr+"static/r07/bar007.js",qbarcss:_atr+"bannerQuirks.css",fltcss:_atr+"static/r07/floating001.css",barcss:_atr+"static/r07/banner004.css",barjs:_atr+"static/r07/banner001.js",contentcss:_atr+"static/r07/content005.css",contentjs:_atr+"static/r07/content005.js",ssojs:_atr+"static/r07/sso002.js",ssocss:_atr+"static/r07/sso000.css",peekaboocss:_atr+"static/r07/peekaboo002.css",overlayjs:_atr+"static/r07/overlay004.js",widget32css:_atr+"static/r07/widgetbig045.css",widgetcss:_atr+"static/r07/widget086.css",widgetIE67css:_atr+"static/r07/widgetIE67002.css",widgetpng:"//s7.addthis.com/static/r07/widget045.png",link:_atr+"static/r07/link.html",pinit:_atr+"static/r07/pinit005.html",linkedin:_atr+"static/r07/linkedin018.html",tweet:_atr+"static/r07/tweet018.html",menujs:_atr+"static/r07/menu116.js",sh:_atr+"static/r07/sh090.html"}};}(function(){var f;var j=(window.location.protocol=="https:"),x,o,c={0:_atr,1:"//ct1.addthis.com/",2:"//ct2.addthis.com/",3:"//ct3.addthis.com/",4:"//ct4.addthis.com/",100:"//ct0.addthis.com/"},u=Math.random();_atc.cdn=0;if(!window.addthis||window.addthis.nodeType!==f){try{x=window.navigator?(navigator.userLanguage||navigator.language):"";o=x.split("-").pop().toLowerCase()=="us";_atc.cdn=j?0:(window.addthis_cdn||(u>=0.99?100:(u>=0.98?2:(u>=0.97?3:(u>=0.96&&o?4:(u>=0.95&&o?1:0))))));if(_atc.cdn){for(var q in _atc.rsrcs){if(_atc.rsrcs.hasOwnProperty(q)){_atc.rsrcs[q]=_atc.rsrcs[q].replace(_atr,c[_atc.cdn]).replace(/live\/[a-z]07/,"live/d07");}}_atr=c[_atc.cdn];}}catch(v){}function b(r,k,e,a){return function(){if(!this.qs){this.qs=0;}_atc.qs++;if(!((this.qs++>0&&a)||_atc.qs>1000)&&window.addthis){window.addthis.plo.push({call:r,args:arguments,ns:k,ctx:e});}};}function p(k){var e=this,a=this.queue=[];this.name=k;this.call=function(){a.push(arguments);};this.call.queuer=this;this.flush=function(y,s){this.flushed=1;for(var r=0;r<a.length;r++){y.apply(s||e,a[r]);}return y;};}window.addthis={ost:0,cache:{},plo:[],links:[],ems:[],timer:{load:((new Date()).getTime())},_Queuer:p,_queueFor:b,data:{getShareCount:b("getShareCount","data")},bar:{show:b("show","bar"),initialize:b("initialize","bar")},login:{initialize:b("initialize","login"),connect:b("connect","login")},box:b("box"),button:b("button"),counter:b("counter"),count:b("count"),toolbox:b("toolbox"),update:b("update"),init:b("init"),ad:{event:b("event","ad"),getPixels:b("getPixels","ad")},util:{getServiceName:b("getServiceName")},ready:b("ready"),addEventListener:b("addEventListener","ed","ed"),removeEventListener:b("removeEventListener","ed","ed"),user:{getID:b("getID","user"),getGeolocation:b("getGeolocation","user",null,true),getPreferredServices:b("getPreferredServices","user",null,true),getServiceShareHistory:b("getServiceShareHistory","user",null,true),ready:b("ready","user"),isReturning:b("isReturning","user"),isOptedOut:b("isOptedOut","user"),isUserOf:b("isUserOf","user"),hasInterest:b("hasInterest","user"),isLocatedIn:b("isLocatedIn","user"),interests:b("getInterests","user"),services:b("getServices","user"),location:b("getLocation","user")},session:{source:b("getSource","session"),isSocial:b("isSocial","session"),isSearch:b("isSearch","session")},_pmh:new p("pmh")};var l=document.getElementsByTagName("script")[0];function d(a){a.style.width=a.style.height="1px";a.style.position="absolute";a.style.zIndex=100000;}if(document.location.href.indexOf(_atr)==-1){var m=document.getElementById("_atssh");if(!m){m=document.createElement("div");m.style.visibility="hidden";m.id="_atssh";d(m);l.parentNode.appendChild(m);}function g(a){if(addthis._pmh.flushed){_ate.pmh(a);}else{addthis._pmh.call(a);}}if(window.postMessage){if(window.attachEvent){window.attachEvent("onmessage",g);}else{if(window.addEventListener){window.addEventListener("message",g,false);}}}if(!m.firstChild){var h,t=navigator.userAgent.toLowerCase(),n=Math.floor(Math.random()*1000);if(/msie/.test(t)&&!(/opera/.test(t))){m.innerHTML="<iframe id=\"_atssh"+n+"\" width=\"1\" height=\"1\" title=\"AddThis utility frame\" name=\"_atssh"+n+"\" src=\"\">";h=document.getElementById("_atssh"+n);}else{h=document.createElement("iframe");h.id="_atssh"+n;h.title="AddThis utility frame";m.appendChild(h);}d(h);h.frameborder=h.style.border=0;h.style.top=h.style.left=0;_atc._atf=h;}}var w=document.createElement("script");w.type="text/javascript";w.src=(j?"https:":"http:")+_atc.rsrcs.core;l.parentNode.appendChild(w);var i=10000;if(Math.random()<_atc.ohmp){setTimeout(function(){if(!window.addthis.timer.core){(new Image()).src="//m.addthisedge.com/live/t00/oh.gif?"+Math.floor(Math.random()*4294967295).toString(36)+"&cdn="+_atc.cdn+"&sr="+_atc.ohmp+"&rev="+_atc.rrev+"&to="+i;if(_atc.cdn!==0){var e=document.createElement("script");e.type="text/javascript";e.src=(j?"https:":"http:")+_atr+"static/r07/core023.js";l.parentNode.appendChild(e);}}},i);}}})();