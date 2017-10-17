<?php
/**
 * Unreal Studio
 * Project: UnrealLicensing
 * User: jhollsoliver
 * Date: 05/06/15
 * Time: 16:35
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

    <title><?php echo PRODUCT_NAME;?> Obfuscator</title>

    <!-- Bootstrap core CSS -->
    <link href="<?php echo ASSETS_URL;?>/css/bootstrap.min.css" rel="stylesheet">
    <link href="<?php echo ASSETS_URL;?>/css/bootstrap-reset.css" rel="stylesheet">
    <!--external css-->
    <link href="<?php echo ASSETS_URL;?>/font-awesome/css/font-awesome.css" rel="stylesheet" />
    <!--toastr-->
    <link href="<?php echo ASSETS_URL;?>/toastr-master/toastr.css" rel="stylesheet" type="text/css" />

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
        <a href="./" class="logo"><?php echo $logo_name; ?></a>
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
            <div class="row">
                <div class="col-lg-12">
                    <!--work progress start-->
                    <section class="panel">
                        <div class="panel-body">

                            <form role="form" id="frmObfuscate">
                                <div class="form-group">
                                    <label for="slcObfuscator">Product</label>
                                    <select class="form-control m-bot15" id="slcProduct">
                                        <option value="1">PML Obfuscator v1 (Offline)</option>
                                        <option value="2">PML Enhanced Encoder v2 (Online)</option>
                                    </select>
                                </div>
                                <div class="form-group">
                                    <label for="txtObfuscate">Script to Obfuscate</label>
                                    <textarea class="form-control" id="txtScript" cols="60" rows="15"></textarea>
                                </div>

                                <button type="submit" id="btnSubmit" class="btn btn-info">Obfuscate</button>
                            </form>

                            <div class="alert alert-block alert-danger fade in" style="display:none" id="msgError">
                                <button data-dismiss="alert" class="close close-sm" type="button">
                                    <i class="fa fa-times"></i>
                                </button>
                                <strong>Oh snap!</strong> <div id="msgError_Text"></div>
                            </div>

                            <form role="form" style="display:none" id="frmResult">
                                <div class="alert alert-block alert-success fade in" id="msgSuccess">
                                    <button data-dismiss="alert" class="close close-sm" type="button">
                                        <i class="fa fa-times"></i>
                                    </button>
                                    <strong>Yay!</strong> <div id="msgSuccess_Text">Here's your obfuscated script.</div>
                                </div>

                                <div class="form-group">
                                    <label for="txtObfuscated">Obfuscated Script</label>
                                    <textarea class="form-control" id="obfuscated" cols="60" rows="15"></textarea>
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

<!-- Custom Functions -->
<script src="<?php echo ASSETS_URL;?>/js/customfunctions.js"></script>

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
        $("#frmObfuscate").submit(function (e) {
            e.preventDefault();

            var script = base64_encode($("#txtScript").val());
            var obfuscator = $("#slcObfuscator").val();
            $.ajax({

                type: "POST",
                data: {
                    script:script,
                    token:'<?php echo $TOTP->generateCode();?>',
                    obfuscator:obfuscator,
                    handler: 'obfuscate'
                },
                crossDomain: true,
                url: "ajax/",
                dataType: "json",
                success: function (result) {

                    if(result.status == 200)
                    {
                        $("#btnSubmit").html('Success...');
                        $("#btnSubmit").addClass('btn-success');
                        $("#frmObfuscate").fadeOut();
                        $("#frmResult").fadeIn();
                        $("#obfuscated").val(base64_decode(result.script));
                        $("#btnSubmit").hide();
                    }else{
                        $("#btnSubmit").html('Obfuscate');
                        toastr[result.message.type](result.message.text, result.message.header);
                        $("#btnSubmit").removeClass('disabled');
                        $("#btnSubmit").addClass('btn-danger');
                    }


                },
                beforeSend: function () {

                    $("#btnSubmit").html('Processing...');
                    $("#btnSubmit").addClass('disabled');
                    //toastr['info']("Your script was added to query on PHPMyLicense API ", "Script on Queue");
                },
                error: function () {
                    $("#btnSubmit").removeClass('disabled');
                    $("#btnSubmit").html('Error!');
                    $("#btnSubmit").addClass('btn-danger');
                    toastr['error']('Unknown Error. Contact the support team.', 'Oops!');
                }
            });
            return false;
        });
    });

</script>
</body>
</html>
