<?php
/**
 * Unreal Studio
 * Project: UnrealLicensing
 * User: jhollsoliver
 * Date: 05/06/15
 * Time: 19:39
 */


include_once 'system/autoloader.php';
$Logged = $Tools->CheckIfLogged($_SESSION);
if(!$Logged)
{
    header("Location: login.php?go=".base64_encode($_SERVER["REQUEST_URI"])."");
}
/*$sql = "SELECT id FROM licenses";
$query = $DatabaseHandler->query($sql);*/
?>

<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="utf-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <meta name="description" content="">
    <meta name="author" content="Giovanne Oliveira">
    <link rel="shortcut icon" href="<?php echo ASSETS_URL;?>/img/favicon.png">

    <title><?php echo PRODUCT_NAME;?> New Product</title>

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

    <link rel="stylesheet" type="text/css" href="<?php echo ASSETS_URL;?>/bootstrap-datepicker/css/datepicker.css" />


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
                        <div class="panel-body progress-panel">
                            <div class="task-progress">
                                <h1>Insert new Product</h1>
                                <p>Fill the form with Product Informations.</p>
                            </div>
                        </div>
                        <form role="form" id="frmIssueLicense">
                            <div class="form-group">
                                <label for="txtFullName">Full Name</label>
                                <input type="text" id="txtFullName" class="form-control" placeholder="Full Name">
                            </div>
                            <div class="form-group">
                                <label for="txtShortName">Short Name</label>
                                <input type="text" class="form-control" id="txtShortName" placeholder="Short Name">
                            </div>
                            <div class="form-group">
                                <label for="exampleInputFile">Sandbox</label>
                                <select class="form-control m-bot15" id="slcSandbox">
                                    <option value="1">Active</option>
                                    <option value="0" selected>Inactive</option>
                                </select>
                            </div>
                             <div class="form-group">
                                <label for="txtShortName">Product Stripe Id</label>
                                <input type="text" class="form-control" id="txtProductStripeId" placeholder="Stripe Product Id">
                            </div>
                            <div class="form-group">
                                <label for="txtDomain">Trial Time</label>
                                <div id="spinner3">
                                    <div class="input-group" style="width:150px;">
                                        <input type="text" id="TrialTime" class="spinner-input form-control" maxlength="3" readonly>
                                        <div class="spinner-buttons input-group-btn">
                                            <button type="button" class="btn btn-default spinner-up">
                                                <i class="fa fa-angle-up"></i>
                                            </button>
                                            <button type="button" class="btn btn-default spinner-down">
                                                <i class="fa fa-angle-down"></i>
                                            </button>
                                        </div>
                                    </div>
                                </div>
                            </div>
                            <button type="submit" id="btnSubmit" class="btn btn-info">Insert Product</button>
                        </form>
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
<script src="<?php echo ASSETS_URL;?>/js/sparkline-chart.js"></script>
<script src="<?php echo ASSETS_URL;?>/js/easy-pie-chart.js"></script>
<script src="<?php echo ASSETS_URL;?>/js/count.js"></script>
<script type="text/javascript" src="<?php echo ASSETS_URL;?>/fuelux/js/spinner.min.js"></script>

<?php
include 'assets/inc/changepwd.php';
?>
<script>
    $('#spinner3').spinner({value:0, min: 0, max: 30});
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
        $("#frmIssueLicense").submit(function (e) {
            e.preventDefault();

            var fullname = $("#txtFullName").val();
            var shortname = $("#txtShortName").val();
            var sandbox = $("#slcSandbox").val();
            var ProductStripeId = $("#txtProductStripeId").val();
            var trialtime = $("#TrialTime").val();
            $.ajax({

                type: "POST",
                data: {
                    fullname:fullname,
                    shortname:shortname,
                    sandbox:sandbox,
                    ProductStripeId:ProductStripeId,
                    trialtime:trialtime,
                    token:'<?php echo $TOTP->generateCode();?>',
                    handler: 'newproduct'
                },

                url: "ajax/",
                dataType: "json",
                success: function (result) {

                    if(result.status == 200)
                    {
                        $("#btnSubmit").html('Success...');
                        $(window.document.location).attr('href', 'products.php');
                    }else{
                        $("#btnSubmit").html('Insert Product');
                        toastr[result.message.type](result.message.text, result.message.header);
                        $("#btnSubmit").removeClass('disabled');
                    }


                },
                beforeSend: function () {

                    $("#btnSubmit").html('Processing...');
                    $("#btnSubmit").addClass('disabled');

                },
                error: function () {
                    $("#btnSubmit").removeClass('disabled');
                    $("#btnSubmit").html('Insert License');
                    toastr['error']("Unknown Error. Contact the support team.", "Oops!");
                }
            });
            return false;
        });
    });

</script>
</body>
</html>
