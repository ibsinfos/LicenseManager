<?php
error_reporting(E_ALL);
/**
 * Unreal Studio
 * Project: UnrealLicensing
 * User: jhollsoliver
 * Date: 03/06/15
 * Time: 16:37
 */

include 'system/autoloader.php';
if (isset($_GET["go"])) {
    $go = base64_decode($_GET['go']);
} else {
    $go = './';
}
?>
<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="utf-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <meta name="description" content="">
    <meta name="author" content="Giovanne Oliveira">
    <link rel="shortcut icon" href="<?php echo ASSETS_URL; ?>/img/favicon.png">

    <title><?php echo PRODUCT_NAME; ?> Login</title>

    <!-- Bootstrap core CSS -->
    <link href="<?php echo ASSETS_URL; ?>/css/bootstrap.min.css" rel="stylesheet">
    <link href="<?php echo ASSETS_URL; ?>/css/bootstrap-reset.css" rel="stylesheet">
    <!--external css-->
    <link href="<?php echo ASSETS_URL; ?>/font-awesome/css/font-awesome.css" rel="stylesheet"/>
    <!-- Custom styles for this template -->
    <link href="<?php echo ASSETS_URL; ?>/css/style.css" rel="stylesheet">
    <link href="<?php echo ASSETS_URL; ?>/css/style-responsive.css" rel="stylesheet"/>
    <!--toastr-->
    <link href="<?php echo ASSETS_URL; ?>/toastr-master/toastr.css" rel="stylesheet" type="text/css"/>

    <!-- HTML5 shim and Respond.js IE8 support of HTML5 tooltipss and media queries -->
    <!--[if lt IE 9]>
    <script src="<?php echo ASSETS_URL;?>/js/html5shiv.js"></script>
    <script src="<?php echo ASSETS_URL;?>/js/respond.min.js"></script>
    <![endif]-->
</head>

<body class="login-body">

<div class="container">

    <form class="form-signin" id="frmLogin">
        <h2 class="form-signin-heading"><?php echo $logo_name; ?> LOGIN</h2>

        <div class="login-wrap">
            <input type="text" class="form-control" id="txtUser" placeholder="User ID" autofocus>
            <input type="password" class="form-control" id="txtPass" placeholder="Password">
            <label class="checkbox">
                <input type="checkbox" value="remember-me"> Remember me
                <span class="pull-right">
                    <a data-toggle="modal" href="#myModal"> Forgot Password?</a>

                </span>
            </label>
            <button class="btn btn-lg btn-login btn-block" id="btnDoLogin" type="submit">Sign in</button>


        </div>
    </form>
    <!-- Modal -->
    <div aria-hidden="true" aria-labelledby="myModalLabel" role="dialog" tabindex="-1" id="myModal" class="modal fade">
        <div class="modal-dialog">
            <form id="frmRecoverPwd">
                <div class="modal-content">
                    <div class="modal-header">
                        <button type="button" class="close" data-dismiss="modal" aria-hidden="true">&times;</button>
                        <h4 class="modal-title">Forgot Password ?</h4>
                    </div>
                    <div class="modal-body">
                        <p>Enter your username below to reset your password.</p>
                        <input type="text" name="username" id="recoverEmail" placeholder="E-mail" autocomplete="off"
                               class="form-control placeholder-no-fix">

                    </div>
                    <div class="modal-footer">
                        <button data-dismiss="modal" class="btn btn-default" type="button">Cancel</button>
                        <button class="btn btn-success" id="btnSubmitResetPwd" type="submit">Submit</button>
                    </div>
                </div>
            </form>
        </div>
    </div>
    <!-- modal -->


</div>


<!-- js placed at the end of the document so the pages load faster -->
<script src="<?php echo ASSETS_URL; ?>/js/jquery.js"></script>
<script src="<?php echo ASSETS_URL; ?>/js/bootstrap.min.js"></script>
<!--toastr-->
<script src="<?php echo ASSETS_URL; ?>/toastr-master/toastr.js"></script>

<script type="text/javascript" src="<?php echo ASSETS_URL;?>/jCryption/jquery.jcryption.3.1.0.js"></script>


</body>
</html>

<script>
    $(function () {
        //$("#frmLogin").jCryption();
        toastr.options = {
            "closeButton": true,
            "debug": false,
            "progressBar": true,
            "positionClass": "toast-top-right",
            "onclick": null,
            "showDuration": "300",
            "hideDuration": "1000",
            "timeOut": "3000",
            "extendedTimeOut": "1000",
            "showEasing": "swing",
            "hideEasing": "linear",
            "showMethod": "fadeIn",
            "hideMethod": "fadeOut"
        }
        $("#frmLogin").submit(function (e) {
            e.preventDefault();

            var username = $("#txtUser").val();
            var password = $("#txtPass").val();
            $.ajax({

                type: "POST",
                data: {
                    user: username,
                    pass: password,
                    handler: 'login'
                },

                url: "ajax/",
                dataType: "json",
                success: function (result) {

                    if (result.status == 200) {
                        $("#btnDoLogin").html('Redirecting...');
                        $(window.document.location).attr('href', '<?php echo $go;?>');
                    } else {
                        $("#btnDoLogin").html('Sign in');
                        //swal(result.message.header, result.message.text, result.message.type);
                        toastr[result.message.type](result.message.text, result.message.header);
                        $("#btnDoLogin").removeClass('disabled');
                    }


                },
                beforeSend: function () {

                    $("#btnDoLogin").html('Checking...');
                    $("#btnDoLogin").addClass('disabled');

                },
                error: function () {
                    $("#btnDoLogin").removeClass('disabled');
                    $("#btnDoLogin").html('Efetuar Login');
                    toastr['error']("Unknown Error. Contact the support team.", "Oops!");
                }
            });
            return false;
        });

        $("#frmRecoverPwd").submit(function (e) {
            e.preventDefault();

            var email = $("#recoverEmail").val();
            var btn = $("#btnSubmitResetPwd");
            $.ajax({

                type: "POST",
                data: {
                    email: email,
                    handler: 'resetpwd'
                },

                url: "ajax/",
                dataType: "json",
                success: function (result) {

                    if (result.status == 200) {
                        btn.html('Processed.');
                        toastr[result.message.type](result.message.text, result.message.header);
                    } else {
                        btn.html('Submit');
                        toastr[result.message.type](result.message.text, result.message.header);
                        btn.removeClass('disabled');
                    }


                },
                beforeSend: function () {

                    btn.html('Processing...');
                    btn.addClass('disabled');

                },
                error: function () {
                    btn.removeClass('disabled');
                    btn.html('Submit');
                    toastr[error]("Unknown Error. Contact the support team.", "Oops!");
                }
            });
            return false;
        });
    });

</script>
</body>
</html>