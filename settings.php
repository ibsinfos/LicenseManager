<?php
/**
 * Created by PhpStorm.
 * User: jholl
 * Date: 07/07/15
 * Time: 8:46 PM
 */

include_once 'system/autoloader.php';
$Logged = $Tools->CheckIfLogged($_SESSION);
if(!$Logged)
{
    header("Location: login.php?go=".base64_encode($_SERVER["REQUEST_URI"])."");
}

$sql = "SELECT * FROM settings";
$query = $DatabaseHandler->query($sql);
if($query)
{
    $data = $query->fetch_array();
    $configurations = json_decode($data['configurations'], true);
    $purchasecode = $data['purchasecode'];
}
?>


<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="utf-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <meta name="description" content="">
    <meta name="author" content="Giovanne Oliveira">
    <link rel="shortcut icon" href="<?php echo ASSETS_URL;?>/img/favicon.png">

    <title><?php echo PRODUCT_NAME;?> Settings</title>

    <!-- Bootstrap core CSS -->
    <link href="<?php echo ASSETS_URL;?>/css/bootstrap.min.css" rel="stylesheet">
    <link href="<?php echo ASSETS_URL;?>/css/bootstrap-reset.css" rel="stylesheet">
    <!--external css-->
    <link href="<?php echo ASSETS_URL;?>/font-awesome/css/font-awesome.css" rel="stylesheet" />
    <link href="<?php echo ASSETS_URL;?>/jquery-easy-pie-chart/jquery.easy-pie-chart.css" rel="stylesheet" type="text/css" media="screen"/>
    <link rel="stylesheet" href="<?php echo ASSETS_URL;?>/css/owl.carousel.css" type="text/css">

    <!--right slidebar-->
    <link href="<?php echo ASSETS_URL;?>/css/slidebars.css" rel="stylesheet">

    <!-- Custom styles for this template -->

    <link href="<?php echo ASSETS_URL;?>/css/style.css" rel="stylesheet">
    <link href="<?php echo ASSETS_URL;?>/css/style-responsive.css" rel="stylesheet" />



    <!-- HTML5 shim and Respond.js IE8 support of HTML5 tooltipss and media queries -->
    <!--[if lt IE 9]>
    <script src="<?php echo ASSETS_URL;?>/js/html5shiv.js"></script>
    <script src="<?php echo ASSETS_URL;?>/js/respond.min.js"></script>
    <![endif]-->
</head>

<body>

<section id="container" >
    <!--header start-->
    <header class="header white-bg">
        <div class="sidebar-toggle-box">
            <div class="fa fa-bars tooltips" data-placement="right" data-original-title="Toggle Navigation"></div>
        </div>
        <!--logo start-->
        <a href="index.html" class="logo"><?php echo $logo_name; ?></a>
        <!--logo end-->
        <div class="nav notify-row" id="top_menu">

        </div>
        <div class="top-nav ">

            <?php include 'assets/inc/topbar.php';?>
        </div>
    </header>
    <!--header end-->
    <!--sidebar start-->
    <?php include 'assets/inc/sidebar.php';?>
    <!--sidebar end-->
    <!--main content start-->
    <section id="main-content">
        <section class="wrapper">
            <!--state overview start-->
            <?php include 'assets/inc/overview.php';?>
            <!--state overview end-->
            <div class="row">
                <div class="col-md-12">
                    <!--work progress start-->
                    <section class="panel">
                        <header class="panel-heading">
                            Form Elements
                        </header>
                        <div class="panel-body">
                            <form class="form-horizontal tasi-form" id="frmSettings">
                                <div class="form-group">
                                    <label class="col-sm-2 col-sm-2 control-label">Update Channel</label>
                                    <div class="col-sm-10">
                                        <select id="updatechannel" class="form-control m-bot15">
                                            <option <?php if($configurations['updatechannel'] == 'stable'){echo 'selected';}?> value="stable">Stable</option>
                                            <option <?php if($configurations['updatechannel'] == 'beta'){echo 'selected';}?> value="beta">Beta</option>
                                            <option <?php if($configurations['updatechannel'] == 'internal'){echo 'selected';}?>  value="internal">Internal Testing</option>
                                        </select>
                                        <span class="help-block">Update channel to your PHPMyLicense. If you choose beta, remember to get your beta flag first.</span>
                                    </div>
                                </div>
                                <div class="form-group">
                                    <label class="col-sm-2 col-sm-2 control-label">License Key Mask</label>
                                    <div class="col-sm-10">
                                        <input type="text" id="mask" value="<?php echo $configurations['serialmask'];?>" class="form-control">
                                        <span class="help-block">Input a mask for the Serial Keys. Use 9 to numbers, X to uppercase letters, x to lowercase letters and # for uppercase and numbers. To insert static characters, just type it.</span>
                                    </div>
                                </div>
                                <div class="form-group">
                                    <label class="col-sm-2 col-sm-2 control-label">Sign API Response</label>
                                    <div class="col-sm-10">
                                        <div id="signresponse" class="switch switch-square">
                                            <input class="switch" id="signresponse" <?php
                                            $checked = $configurations['signresponse'];
                                            if($checked == 'true')
                                            {
                                                echo 'checked';
                                            }

                                            ?> type="checkbox" />
                                        </div>
                                        <span class="help-block">Sign json responses with RSA Private Key. <a href="http://support.phpmylicense.com/">Read the Documentation</a></span>
                                    </div>
                                </div>
                                <div id="signresponsecontainer" <?php
                                $checked = $configurations['signresponse'];
                                if($checked == 'false')
                                {
                                    echo 'style="display:none"';
                                }
                                ?> class="form-group">
                                    <label class="col-sm-2 col-sm-2 control-label">Signature Type</label>
                                    <div class="col-sm-10">
                                        <select id="signaturetype" class="form-control m-bot15">
                                            <option <?php if($configurations['signaturetype'] == 'raw'){echo 'selected';}?> value="raw">Raw Data</option>
                                            <option <?php if($configurations['signaturetype'] == 'md5'){echo 'selected';}?> value="md5">MD5</option>
                                            <option <?php if($configurations['signaturetype'] == 'sha1'){echo 'selected';}?> value="sha1">SHA1</option>
                                        </select>
                                        <span class="help-block">Signature Type on Return.</span>
                                    </div>
                                </div>
                                <div class="form-group">
                                    <label class="col-sm-2 col-sm-2 control-label">Return Encrypted API Response</label>
                                    <div class="col-sm-10">
                                        <div id="returnencrypted" class="switch switch-square">
                                            <input class="switch" id="returnencrypted" <?php
                                            $checked = $configurations['return_encrypted'];
                                            if($checked == 'true')
                                            {
                                                echo 'checked';
                                            }
                                            ?> type="checkbox" />

                                        </div>
                                        <span class="help-block">Return the API response encrypted with MCrypt Rijndel 256 bits. <a href="http://support.phpmylicense.ml/">Read the Documentation</a></span>
                                    </div>
                                </div>
                                <div id="encryptionkeycontainer" <?php
                                $checked = $configurations['return_encrypted'];
                                if($checked == 'false')
                                {
                                    echo 'style="display:none"';
                                }
                                ?> class="form-group">
                                    <label class="col-sm-2 col-sm-2 control-label">API Return Encryption Key</label>
                                    <div class="col-sm-10">
                                        <input class="form-control" id="encryption_key" value="<?php echo $configurations['encryption_key'];?>" type="text" placeholder="Encryption Key">
                                        <span class="help-block"><a onClick="javascript:GetCryptographicKeyFromAPI();" class="btn btn-shadow btn-info btn-xs">Generate</a></span>
                                    </div>
                                </div>
                                <div class="form-group">
                                    <label class="col-sm-2 col-sm-2 control-label">Return All License Data on API Response</label>
                                    <div class="col-sm-10">
                                        <div id="returndata" class="switch switch-square">
                                            <input class="switch" id="returndata" <?php
                                            $checked = $configurations['returndata'];
                                            if($checked == 'true')
                                            {
                                                echo 'checked';
                                            }

                                            ?> type="checkbox" />
                                        </div>
                                        <span class="help-block">Return all license informations in API response. <a href="http://support.phpmylicense.ml/">Read the Documentation</a></span>
                                    </div>
                                </div>
                                <div class="form-group">
                                    <label class="col-sm-2 col-sm-2 control-label">Purchase Code</label>
                                    <div class="col-sm-10">
                                        <input class="form-control" id="purchasecode" value="<?php echo $purchasecode;?>" type="text" placeholder="Purchase Code" disabled="demo">
                                    </div>
                                </div>
                                <div class="form-group">
                                    <label class="col-sm-2 col-sm-2 control-label"></label>
                                    <button type="button" id="btnUpdate" class="btn btn-info btn-lg"><i class="fa fa-refresh" id="spinner"></i> <span id="btnText">Update Settings</span></button>
                                </div>
                            </form>
                        </div>
                    </section>
                    <!--work progress end-->
                </div>

        </section>
    </section>
    <!--main content end-->

    <!--footer start-->
    <?php include 'assets/inc/footer.php';?>
    <!--footer end-->
</section>

<!-- js placed at the end of the document so the pages load faster -->
<script src="<?php echo ASSETS_URL;?>/js/jquery.js"></script>
<script src="<?php echo ASSETS_URL;?>/js/bootstrap.min.js"></script>
<script class="include" type="text/javascript" src="<?php echo ASSETS_URL;?>/js/jquery.dcjqaccordion.2.7.js"></script>
<script src="<?php echo ASSETS_URL;?>/js/jquery.scrollTo.min.js"></script>
<script src="<?php echo ASSETS_URL;?>/js/jquery.nicescroll.js" type="text/javascript"></script>
<script src="<?php echo ASSETS_URL;?>/js/jquery.sparkline.js" type="text/javascript"></script>
<script src="<?php echo ASSETS_URL;?>/jquery-easy-pie-chart/jquery.easy-pie-chart.js"></script>
<script src="<?php echo ASSETS_URL;?>/js/owl.carousel.js" ></script>
<script src="<?php echo ASSETS_URL;?>/js/jquery.customSelect.min.js" ></script>
<script src="<?php echo ASSETS_URL;?>/js/respond.min.js" ></script>

<!--right slidebar-->
<script src="<?php echo ASSETS_URL;?>/js/slidebars.min.js"></script>

<!--common script for all pages-->
<script src="<?php echo ASSETS_URL;?>/js/common-scripts.js"></script>

<!--custom switch-->
<script src="<?php echo ASSETS_URL;?>/js/bootstrap-switch.js"></script>

<?php
include 'assets/inc/changepwd.php';
?>

<script>
    //$("[data-toggle='switch']").wrap('<div class="switch" />').parent().bootstrapSwitch();

    function GetCryptographicKeyFromAPI()
    {
        $.ajax({

            type: "GET",

            url: "http://api.phpmylicense.ml/v1/public/generatekey",
            dataType: "json",
            success: function (result) {

                if(result.status == 200)
                {
                    $("#encryption_key").removeClass('spinner');
                    $("#encryption_key").prop('disabled', false);
                    $("#encryption_key").val(result.key);
                }else{
                    $("#encryption_key").removeClass('spinner');
                    $("#encryption_key").prop('disabled', false);
                    toastr[result.message.type](result.message.text, result.message.header);
                }

            },
            beforeSend: function () {

                $("#encryption_key").addClass('spinner');
                $("#encryption_key").prop('disabled', true);
            },
            error: function () {
                $("#encryption_key").removeClass('spinner');
                $("#encryption_key").prop('disabled', false);
                toastr['error']('Unknown error', 'Oops!');
            }
        });
    }

    $("#returnencrypted").on("switch-change", function(event, data)
    {
        if(data.value == true)
        {
            $("#encryptionkeycontainer").slideDown();
        }else{
            $("#encryptionkeycontainer").slideUp();
        }
    });
    $("#signresponse").on("switch-change", function(event, data)
    {
        if(data.value == true)
        {
            $("#signresponsecontainer").slideDown();
        }else{
            $("#signresponsecontainer").slideUp();
        }
    });
    $("#btnUpdate").click(function(e){

        var serialmask = $("#mask").val();
        var returndata = $("#returndata").bootstrapSwitch('status');
        var returnencrypted = $("#returnencrypted").bootstrapSwitch('status');
        var encryption_key = $("#encryption_key").val();
        var updatechannel = $("#updatechannel").val();
        var signresponse = $("#signresponse").bootstrapSwitch('status');
        var signaturetype = $("#signaturetype").val();
        var btn = $("#btnText");
        var spinner = $("#spinner");
        $.ajax({

            type: "POST",
            data: {
                serialmask:serialmask,
                returndata:returndata,
                returnencrypted:returnencrypted,
                encryption_key:encryption_key,
                updatechannel:updatechannel,
                signresponse:signresponse,
                signaturetype:signaturetype,
                token:'<?php echo $TOTP->generateCode();?>',
                handler: 'updatesettings'
            },

            url: "ajax/",
            dataType: "json",
            success: function (result) {

                if(result.status == 200)
                {
                    spinner.removeClass('fa-spin');
                    toastr[result.message.type](result.message.text, result.message.header);
                    btn.html('Updated.');
                }else{
                    btn.removeClass('disabled');
                    spinner.removeClass('fa-spin');
                    toastr[result.message.type](result.message.text, result.message.header);
                    btn.html('Update Settings');
                }




            },
            beforeSend: function () {

                btn.html('Updating...');
                btn.addClass('disabled');
                spinner.addClass('fa-spin');

            },
            error: function () {
                btn.removeClass('disabled');
                spinner.removeClass('fa-spin');
                btn.html('Error!');
                btn.addClass('btn-danger');
                toastr['error']("Unknown Error. Contact the support team.", "Oops!");
            }
        });


    });

</script>

</body>
</html>

