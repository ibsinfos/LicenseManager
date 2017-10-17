<?php
/**
 * User: jhollsoliver
 * Date: 7/19/16
 * Time: 7:19 PM
 */

include_once('../system/autoloader.php');

?>
<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="utf-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <meta name="description" content="">
    <meta name="author" content="Giovanne Oliveira">
    <link rel="shortcut icon" href="<?php echo ASSETS_URL; ?>/img/favicon.png">

    <title><?php echo PRODUCT_NAME; ?> Renew License</title>

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

    <!-- SWAL -->
    <link href="<?php echo ASSETS_URL; ?>/swal/dist/sweetalert.css" rel="stylesheet" type="text/css"/>

    <!-- HTML5 shim and Respond.js IE8 support of HTML5 tooltipss and media queries -->
    <!--[if lt IE 9]>
    <script src="<?php echo ASSETS_URL;?>/js/html5shiv.js"></script>
    <script src="<?php echo ASSETS_URL;?>/js/respond.min.js"></script>
    <![endif]-->
</head>

<body class="login-body">

<div class="container">

    <form class="form-signin" id="frmSearchLicense">
        <h2 class="form-signin-heading">RENEW YOUR LICENSE</h2>

        <div class="login-wrap">
            <input type="text" class="form-control" id="txtLicenseKey" placeholder="License Key" autofocus>
            <input type="text" class="form-control" id="txtCustomerEmail" placeholder="Your Email">

            <button class="btn btn-lg btn-login btn-block" id="btnSubmit" type="submit">Search License</button>


        </div>
    </form>

    <form class="form-signin" id="frmCheckLicenseData" style="display:none">
        <h2 class="form-signin-heading">CHECK THE LICENSE INFO</h2>

        <div class="login-wrap">

            <p style="color:black">License Key: <b style="color:gray" id="lblLicenseKey">TEST</b></p>
            <p style="color:black">Email: <b style="color:gray" id="lblEmail">TEST</b></p>
            <p style="color:black">Domain: <b style="color:gray" id="lblDomain">TEST</b></p>
            <p style="color:black">Product: <b style="color:gray" id="lblProduct">TEST</b></p>
            <p style="color:black">Expiration Date: <b style="color:gray" id="lblExpiryDate">TEST</b></p>
            <p style="color:black">Status: <b style="color:red" id="lblStatus">TEST</b></p>
            <br>
            <p style="color:black">Renew Price: <b style="color:gray" id="lblPrice">$50</b></p>
            <p style="color:black">Payment Cicle: <b style="color:gray" id="lblCycle">Annual</b></p>
            <p style="color:black">Payment Method:</p>
            <select id="paymentmethod" class="form-control m-bot15">
                <option id="paypal">PayPal</option>
            </select>

            <button class="btn btn-lg btn-login btn-block" id="btnConfirmRenew" type="submit">Renew License</button>


        </div>
    </form>


</div>


<!-- js placed at the end of the document so the pages load faster -->
<script src="<?php echo ASSETS_URL; ?>/js/jquery.js"></script>
<script src="<?php echo ASSETS_URL; ?>/js/bootstrap.min.js"></script>
<!--toastr-->
<script src="<?php echo ASSETS_URL; ?>/toastr-master/toastr.js"></script>

<script type="text/javascript" src="<?php echo ASSETS_URL;?>/swal/dist/sweetalert.min.js"></script>


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
        $("#frmSearchLicense").submit(function (e) {
            e.preventDefault();

            var licensekey = $("#txtLicenseKey").val();
            var customer_email = $("#txtCustomerEmail").val();
            var btn = $("#btnSubmit");
            $.ajax({

                type: "POST",
                data: {
                    licensekey:licensekey,
                    customer_email:customer_email,
                    handler: 'searchlicense'
                },

                url: "application.php",
                dataType: "json",
                success: function (result) {

                    if (result.status == 200) {
                        $("#lblLicenseKey").html(licensekey);
                        $("#lblEmail").html(customer_email);
                        $("#lblProduct").html(result.license.product);
                        $("#lblExpiryDate").html(result.license.expirydate);

                        switch(result.license.status)
                        {
                            case 'active':
                                $("#lblStatus").css('color', '#33cc33');
                                $("#lblStatus").html('Active');
                                $("#btnConfirmRenew").addClass('disabled');
                                $("#btnConfirmRenew").html('Don\'t need renewal.')
                                break;
                            case 'inactive':
                                $("#lblStatus").css('color', '#ff0000');
                                $("#lblStatus").html('Inactive');
                                break;
                            case 'suspended':
                                $("#lblStatus").html('Suspended');
                                $("#lblStatus").css('color', '#ff0000');
                                break;
                            case 'processing':
                                $("#lblStatus").html('Processing');
                                $("#lblStatus").css('color', '#3366ff');
                                break;
                            default:
                                $("#lblStatus").css('color', '#000000');
                                break;
                        }
                        $("#frmSearchLicense").slideUp(function()
                        {
                           $("#frmCheckLicenseData").slideDown();
                        });
                    } else {
                        btn.html('Search License');
                        toastr[result.message.type](result.message.text, result.message.header);
                        btn.removeClass('disabled');
                    }


                },
                beforeSend: function () {

                    btn.html('Checking...');
                    btn.addClass('disabled');

                },
                error: function () {
                    btn.removeClass('disabled');
                    btn.html('Search License');
                    toastr['error']("Unknown Error. Contact the support team.", "Oops!");
                }
            });
            return false;
        });

        $("#frmCheckLicenseData").submit(function (e) {
            e.preventDefault();

            var licensekey = $("#txtLicenseKey").val();
            var customer_email = $("#txtCustomerEmail").val();
            var btn = $("#btnConfirmRenew");
            $.ajax({

                type: "POST",
                data: {
                    licensekey:licensekey,
                    handler: 'processrenew'
                },

                url: "application.php",
                dataType: "json",
                success: function (result2) {

                    if (result2.status == 200) {
                        swal({
                            title: "Confirm?",
                            text: "Your purchase was processed! You will be redirected to PayPal to make the Payment. After the payment, your license will be processed automatically, and you will receive an e-mail with futher details.",
                            type: "success",
                            showCancelButton: true,
                            confirmButtonColor: "#DD6B55",
                            confirmButtonText: "Yes, go to payment!",
                            cancelButtonText: "No, cancel operation!",
                            closeOnConfirm: false,
                            closeOnCancel: false
                        }, function(isConfirm){
                            if (isConfirm) {
                                $(window.document.location).attr('href', result2.redirecturl);
                            } else {
                                swal("Cancelled", "You can check the info again.", "error");
                            }
                        });
                    } else {
                        btn.html('Renew License');
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
                    btn.html('Renew License');
                    toastr['error']("Unknown Error. Contact the support team.", "Oops!");
                }
            });
            return false;
        });



    });

</script>
</body>
</html>
