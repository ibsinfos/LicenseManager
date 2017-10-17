var page = require('webpage').create();
var system = require('system');
page.viewportSize = {width: 1024,height:576};
page.settings.userAgent = "Mozilla/5.0 (Macintosh; Intel Mac OS X) AppleWebKit/538.1 (KHTML, like Gecko) Version/8.0 Safari/538.1";

var fillLoginInfo = function(system){
  	//console.log(system.args[1]);
  	var frm = document.getElementById("login_form");
    frm.elements["email"].value = system.args[1];
    frm.elements["pass"].value = system.args[2];
    frm.submit();
}

page.onLoadFinished = function(){
	//console.log(page.url);
	if(page.title == "Facebook"){
		console.log("Success");
		//page.render("1.png");
		phantom.exit();
	}
	else if(page.url.indexOf("login_attempt")!=-1){
		console.log("Wrong Username or Password. Login failed");
		phantom.exit();
	}
	else{
		page.evaluate(fillLoginInfo,system);
		return;
	}
}

page.open('https://www.facebook.com/');