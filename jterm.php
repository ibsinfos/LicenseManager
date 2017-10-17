<?php
/**
 * Giovanne Oliveira - JhollsOliver.me.
 * Date: 16/05/2016
 * Time: 16:25
 */
include_once 'system/autoloader.php';
?>

<!DOCTYPE HTML>
<html xmlns="http://www.w3.org/1999/xhtml">
<head>
    <meta charset="utf-8" />
    <title>JSON-RPC Demo for JQuery Terminal Emulator</title>
    <meta name="author" content="Jakub Jankiewicz - jcubic&#64;onet.pl"/>
    <meta name="Description" content="Demonstration for JQuery Terminal Emulator using call automaticly JSON-RPC service (in php) with authentication."/>
    <script src="http://code.jquery.com/jquery-1.7.2.min.js"></script>
    <script src="system/libs/jterm/jsjquery.mousewheel-min.js"></script>
    <script src="system/libs/jterm/js/jquery.terminal.min.js"></script>
    <link href="system/libs/jterm/css/jquery.terminal.min.css" rel="stylesheet"/>
    <script>
        jQuery(document).ready(function($) {
            $('body').terminal("system/rpc.php", {
                login: true,
                greetings: "You are authenticated",
                onBlur: function() {
                    // the height of the body is only 2 lines initialy
                    return false;
                }
            });
        });
    </script>
</head>
<body>
</body>
</html>

