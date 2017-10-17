<?php
/**
 * Unreal Studio
 * Project: UnrealLicensing
 * User: jhollsoliver
 * Date: 05/06/15
 * Time: 16:21
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

    <title><?php echo PRODUCT_NAME;?> Class Generator</title>

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

    <link rel="stylesheet" type="text/css" href="<?php echo ASSETS_URL;?>/css/jquery.steps.css" />


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
                            <?php
                            $query = $DatabaseHandler->query("SELECT id, shortname FROM products");
                            if($query->num_rows < 1)
                            {
                            ?>
                            <div class="alert alert-block alert-danger fade in">
                                <button data-dismiss="alert" class="close close-sm" type="button">
                                    <i class="fa fa-times"></i>
                                </button>
                                <strong>Oh snap!</strong> You don't have any product. Insert one first.
                            </div>
                            <?php }else{?>
                                <form role="form" id="frmGenerateClass">
                                    <div class="form-group">
                                        <label for="slcProduct">Product</label>
                                        <select class="form-control m-bot15" id="slcProduct">
                                            <?php $query = $DatabaseHandler->query("SELECT id, shortname FROM products");
                                            while($row = $query->fetch_array())
                                            {?>
                                                <option value="<?php echo $row['id'];?>"><?php echo $row['shortname'];?></option>
                                            <?php }?>
                                        </select>
                                    </div>

                                    <button type="submit" id="btnSubmit" class="btn btn-info">Generate</button>
                                </form>

                                <form role="form" id="frmShowClass" style="display:none">
                                    <div class="alert alert-block alert-success fade in" id="msgSuccess">
                                        <button data-dismiss="alert" class="close close-sm" type="button">
                                            <i class="fa fa-times"></i>
                                        </button>
                                        <strong>Yay!</strong> <div id="msgSuccess_Text">Here's your protecion class. We recommend you to encode this script before include it before your code logic.</div>
                                    </div>
                                    <div class="form-group">
                                        <label for="txtClass">Protection Class</label>
                                        <textarea class="form-control" id="txtScript" cols="60" rows="15" readonly></textarea>
                                    </div>
                                </form>
                            <?php }?>
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
        $("#frmGenerateClass").submit(function (e) {
            e.preventDefault();

            var productid = $("#slcProduct").val();

            $.ajax({

                type: "POST",
                data: {
                    productid:productid,
                    token:'<?php echo $TOTP->generateCode();?>',
                    handler: 'genclass'
                },

                url: "ajax/",
                dataType: "json",
                success: function (result) {

                    if(result.status == 200)
                    {
                        $("#btnSubmit").html('Success...');
                        $("#btnSubmit").addClass('btn-success');
                        $("#frmGenerateClass").fadeOut();
                        $("#frmShowClass").fadeIn();
                        $("#txtScript").val(base64_decode(result.class));
                    }else{
                        $("#btnSubmit").html('Generate');
                        //swal(result.message.header, result.message.text, result.message.type);
                        toastr[result.message.type](result.message.text, result.message.header);
                        $("#btnSubmit").removeClass('disabled');
                        $("#btnSubmit").addClass('btn-danger');
                    }


                },
                beforeSend: function () {

                    $("#btnSubmit").html('Processing...');
                    $("#btnSubmit").addClass('disabled');

                },
                error: function () {
                    $("#btnSubmit").removeClass('disabled');
                    $("#btnSubmit").html('Error!');
                    $("#btnSubmit").addClass('btn-danger');
                    toastr['error']("Unknown Error. Contact the support team.", "Oops!");
                }
            });
            return false;
        });
    });

</script>
</body>
</html>
