var login = require("facebook-chat-api");

var standAlone = false;
var args;
if(standAlone) args = process.argv.slice(1);
else args = process.argv.slice(2)
//console.log(args)


login({email: args[0], password: args[1]}, function callback (err, api) {
    if(err) return console.error(err);

    var yourID = args[2];
    var msg = {body: args[3]};
    api.sendMessage(msg, yourID);
});