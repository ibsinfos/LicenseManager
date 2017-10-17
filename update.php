<?php
/**
 * Created by PhpStorm.
 * User: jholl
 * Date: 14/07/15
 * Time: 2:35 PM
 */


include_once 'system/autoloader.php';
$Logged = $Tools->CheckIfLogged($_SESSION);
if(!$Logged)
{
    header("Location: login.php?go=".base64_encode($_SERVER["REQUEST_URI"])."");
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

    <title><?php echo PRODUCT_NAME;?> Upload File</title>

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

    <link rel="stylesheet" type="text/css" href="<?php echo ASSETS_URL;?>/bootstrap-fileupload/bootstrap-fileupload.css" />



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
                <div class="col-lg-12">
                    <!--work progress start-->
                    <section class="panel">
                        <div class="panel-body">
                            <form method="post" id="frmCheckforUpdates">

                                <div style="padding:50px;padding-top:30px;padding-bottom:60px" class="text-center">
                                    <i class="fa fa-cloud-download" style="color:#676767;font-size:10em"></i>

                                    <h2>Auto Updater</h2><br>

                                    <!--<div class="form-group col-lg-2 col-lg-offset-5">
                                        Update Channel
                                        <select id="channel" class="form-control m-bot15">
                                            <option value="stable">Stable</option>
                                            <option value="beta">Beta</option>
                                            <option value="alpha">Alpha</option>
                                        </select>
                                    </div>-->

                                    <div class="form-group">

                                        <button type="button" id="btnCheckforUpdates" class="btn btn-primary btn-shadow"><i id="spinner" style="display:none" class="fa fa-spinner fa-spin"></i> <span id="btnTxt">Check for Updates</span></button>

                                    </div>

                                </div>

                            </form>
                            <form method="post" style="display:none" id="frmInstallUpdates">

                                <div style="padding:50px;padding-top:10px;padding-bottom:20px" class="text-center">
                                    <i class="fa fa-cloud-download" style="color:#676767;font-size:10em"></i>

                                    <h2>Auto Updater</h2><br>

                                    <div class="form-group">
                                        <div class="alert alert-block alert-success">The update <span id="version"></span> was found. Do you want to download and install this update?</div>
                                    </div>

                                    <div class="form-group col-lg-2 col-lg-offset-5">

                                        <button type="button" id="btnInstallUpdate" class="btn btn-success btn-shadow"><i id="spinner2" style="display:none" class="fa fa-spinner fa-spin"></i> <span id="btnTxt2">Download and Install</span></button>

                                    </div>

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

<!--script for this page-->
<script type="text/javascript" src="<?php echo ASSETS_URL;?>/bootstrap-fileupload/bootstrap-fileupload.js"></script>

<?php
include 'assets/inc/changepwd.php';
?>


<script>
    $(function () {
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


        $("#btnCheckforUpdates").click(function (e) {
            e.preventDefault();

            var btn = $("#btnCheckforUpdates");
            var btntxt = $("#btnTxt");
            var spinner = $("#spinner");
            var frmcheck = $("#frmCheckforUpdates");
            var frmdl = $("#frmInstallUpdates");

            $.ajax({

                type: "POST",
                data: {
                    handler: 'checkforupdates',
                    token:'<?php echo $TOTP->generateCode();?>',
                },

                url: "ajax/",
                dataType: "json",
                success: function (result) {

                    if(result.status == 200)
                    {
                        btntxt.html('Processing...');
                        $("#version").html(result.newversion);
                        frmcheck.slideUp('slow', function(){
                           frmdl.slideDown('slow');
                        });
                    }else{
                        btntxt.html('Check for Updates');
                        toastr[result.message.type](result.message.text, result.message.header);
                        btn.removeClass('disabled');
                        spinner.hide();
                    }


                },
                beforeSend: function () {

                    spinner.show();
                    btn.addClass('disabled');

                },
                error: function () {
                    btn.removeClass('disabled');
                    spinner.hide();
                    btntxt.html('Error!');
                    btn.addClass('btn-danger');
                    toastr['error']("Unknown Error. Contact the support team.", "Oops!");
                }
            });
            return false;
        });

        $("#btnInstallUpdate").click(function (e) {
            e.preventDefault();
            var btn = $("#btnInstallUpdate");
            var btntxt = $("#btnTxt2");
            var spinner = $("#spinner2");
            var update = $("#version").html();

            $.ajax({

                type: "POST",
                data: {
                    update : update,
                    token:'<?php echo $TOTP->generateCode();?>',
                    handler: 'installupdate'
                },

                url: "ajax/",
                dataType: "json",
                success: function (result) {

                    if(result.status == 200)
                    {
                        btntxt.html('Processing...');
                        $(window.document.location).attr('href', result.installurl);
                    }else{
                        btntxt.html('Download and Install');
                        toastr[result.message.type](result.message.text, result.message.header);
                        btn.removeClass('disabled');
                        spinner.hide();
                    }


                },
                beforeSend: function () {

                    spinner.show();
                    btn.addClass('disabled');

                },
                error: function () {
                    btn.removeClass('disabled');
                    spinner.hide();
                    btntxt.html('Error!');
                    btn.addClass('btn-danger');
                    toastr['error']("Unknown Error. Contact the support team.", "Oops!");
                }
            });
            return false;
        });
    });

</script>
</body>
</html>
