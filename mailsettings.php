<?php
/**
 * PHPMyLicense Development Enviroment v11.51.617
 * User: GiovannedeOliveira
 * Date: 02/10/2015
 * Time: 13:07
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

    <title><?php echo PRODUCT_NAME;?> Mail Settings</title>

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
                            Mail Settings
                        </header>
                        <div class="panel-body">
                            <form class="form-horizontal tasi-form" id="frmSettings">
                                <div class="form-group">
                                    <label class="col-sm-2 col-sm-2 control-label">SMTP Mailer Enabled</label>
                                    <div class="col-sm-10">
                                        <div id="smtp_enabled" class="switch switch-square">
                                            <input class="switch" id="smtp_enabled" <?php
                                            $checked = $configurations['mail']['active'];
                                            if($checked == 'true')
                                            {
                                                echo 'checked';
                                            }

                                            ?> type="checkbox" />
                                        </div>
                                        <span class="help-block">Enable or Disable the Support for Sending Emails using SMTP</span>
                                    </div>
                                </div>
                                <div class="form-group" id="smtp_settings_container" <?php
                                $checked = $configurations['mail']['active'];
                                if($checked == 'false')
                                {
                                    echo 'style="display:none"';
                                }
                                ?>>
                                    <div class="form-group">
                                        <label class="col-sm-2 col-sm-2 control-label">SMTP Host</label>
                                        <div class="col-sm-10">
                                            <input class="form-control" id="smtphost" value="<?php echo $configurations['mail']['smtp_host'];?>" type="text" placeholder="SMTP Host">
                                        </div>
                                    </div>

                                    <div class="form-group">
                                        <label class="col-sm-2 col-sm-2 control-label">SMTP User</label>
                                        <div class="col-sm-10">
                                            <input class="form-control" id="smtpuser" value="<?php echo $configurations['mail']['smtp_user'];?>" type="text" placeholder="SMTP User">
                                        </div>
                                    </div>

                                    <div class="form-group">
                                        <label class="col-sm-2 col-sm-2 control-label">SMTP Password</label>
                                        <div class="col-sm-10">
                                            <input class="form-control" id="smtppass" value="<?php echo $configurations['mail']['smtp_pass'];?>" type="password" placeholder="SMTP Password">
                                        </div>
                                    </div>

                                    <div class="form-group">
                                        <label class="col-sm-2 col-sm-2 control-label">SMTP Port</label>
                                        <div class="col-sm-10">
                                            <input class="form-control" id="smtpport" value="<?php echo $configurations['mail']['smtp_port'];?>" type="number" placeholder="SMTP Port">
                                        </div>
                                    </div>

                                    <div class="form-group">
                                        <label class="col-sm-2 col-sm-2 control-label">Security</label>
                                        <div class="col-sm-10">
                                            <select id="smtpsecurity" class="form-control m-bot15">
                                                <option <?php if($configurations['mail']['smtp_security'] == 'none'){echo 'selected';}?> value="none">None</option>
                                                <option <?php if($configurations['mail']['smtp_security'] == 'tls'){echo 'selected';}?> value="tls">TLS</option>
                                                <option <?php if($configurations['mail']['smtp_security'] == 'ssl'){echo 'selected';}?> value="ssl">SSL</option>
                                            </select>
                                        </div>
                                    </div>

                                    <div class="form-group">
                                        <label class="col-sm-2 col-sm-2 control-label">Sender Address</label>
                                        <div class="col-sm-10">
                                            <input class="form-control" id="smtpsender" value="<?php echo $configurations['mail']['smtp_sender'];?>" type="text" placeholder="SMTP Sender">
                                        </div>
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


    $("#smtp_enabled").on("switch-change", function(event, data)
    {
        if(data.value == true)
        {
            $("#smtp_settings_container").slideDown();
        }else{
            $("#smtp_settings_container").slideUp();
        }
    });

    $("#btnUpdate").click(function(e){

        var smtp_enabled = $("#smtp_enabled").bootstrapSwitch('status');
        var smtp_user = $("#smtpuser").val();
        var smtp_pass = $("#smtppass").val();
        var smtp_host = $("#smtphost").val();
        var smtp_port = $("#smtpport").val();
        var smtp_sender = $("#smtpsender").val();
        var smtp_security = $("#smtpsecurity").val();
        var btn = $("#btnText");
        var spinner = $("#spinner");
        $.ajax({

            type: "POST",
            data: {
                smtp_enabled:smtp_enabled,
                smtp_user:smtp_user,
                smtp_pass:smtp_pass,
                smtp_host:smtp_host,
                smtp_port:smtp_port,
                smtp_sender:smtp_sender,
                smtp_security:smtp_security,
                token:'<?php echo $TOTP->generateCode();?>',
                handler: 'updatemailsettings'
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

