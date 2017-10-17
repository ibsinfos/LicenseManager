<?php
/**
 * Unreal Studio
 * Project: UnrealLicensing
 * User: jhollsoliver
 * Date: 05/06/15
 * Time: 09:18
 */


include_once 'system/autoloader.php';
$Logged = $Tools->CheckIfLogged($_SESSION);
if(!$Logged)
{
    header("Location: login.php?go=".base64_encode($_SERVER["REQUEST_URI"])."");
}

if(isset($_GET['d']))
{
    $id = $RevAlgo->DecryptAndDecode($_GET['d']);
    $sql = "SELECT * FROM licenses WHERE id = '$id'";
    $query = $DatabaseHandler->query($sql);
    $data = $query->fetch_array();

    if($query){
        $sql_get_ips = "SELECT * FROM ipaddress WHERE licensekey='$data[licensekey]'";
        $query_ips = $DatabaseHandler->query($sql_get_ips);
        while ($row = $query_ips->fetch_array()) {
            $ip_addresses_array[] = $row['host_ipaddress'];
        }
        $ip_address_string = implode(",", $ip_addresses_array);
    }

}else{
    header("Location: licenses.php");
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

    <title><?php echo PRODUCT_NAME;?> New License</title>

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
                                    <h1>Issue New License</h1>
                                    <p>Fill the form with License Data.</p>
                                </div>
                            </div>
                            <form role="form" id="frmEditLicense">
                                <div class="form-group">
                                    <label for="txtDomain">ID</label>
                                    <input type="text" id="txtId" disabled class="form-control" value="<?php echo $data['id'];?>" placeholder="ID">
                                </div>
                                <div class="form-group">
                                    <label for="txtDomain">Unique Keys</label>
                                    <input type="text" id="txtDomain" class="form-control" value="<?php echo $ip_address_string;?>" placeholder="Domain Name">
                                    <span><i>comma(,) separated values</i></span>
                                </div>
                                <div class="form-group">
                                    <label for="txtDomain">License Key</label>
                                    <input type="text" id="txtLicenseKey" value="<?php echo $data['licensekey'];?>" class="form-control" readonly placeholder="License Key">
                                </div>
                                <div class="form-group">
                                    <label for="txtCustomerEmail">Customer E-mail</label>
                                    <input type="email" class="form-control" id="txtCustomerEmail" value="<?php echo $data['customer_email'];?>" placeholder="Customer E-mail">
                                </div>
                                <div class="form-group">
                                    <label for="exampleInputFile">Expiration Date</label>
                                    <input class="form-control form-control-inline input-medium default-date-picker" id="expirationdate"  size="16" type="text" value="<?php echo date('d-m-Y', $data['expirydate']);?>" />
                                </div>
                                <div class="form-group">
                                    <label for="exampleInputFile">Product</label>
                                    <select class="form-control m-bot15" id="slcProduct">
                                        <?php $query = $DatabaseHandler->query("SELECT id, shortname,stripe_product_id FROM products");
                                        while($row = $query->fetch_array())
                                            {?>
                                        <option value="<?php echo $row['id'].'<#>'.$row['stripe_product_id'];?>" <?php if($row['id'] == $data['productid']){echo 'selected';}?>><?php echo $row['shortname'];?></option>
                                        <?php }?>
                                    </select>
                                </div>
                                <div class="form-group">
                                    <label for="exampleInputFile">Status</label>
                                    <select class="form-control m-bot15" id="slcStatus">
                                        <option <?php if($data['status'] == 'active'){echo 'selected';}?> value="active">Active</option>
                                        <option <?php if($data['status'] == 'inactive'){echo 'selected';}?> value="inactive">Inactive</option>
                                        <option <?php if($data['status'] == 'suspended'){echo 'selected';}?> value="suspended">Suspended</option>
                                        <option <?php if($data['status'] == 'processing'){echo 'selected';}?> value="processing">Processing</option>
                                    </select>
                                </div>

                                <div class="form-group">
                                    <label for="txtDomain">Comments</label>
                                    <input type="text" id="txtComments" value="<?php echo $data['comments'];?>" class="form-control" placeholder="Comments">
                                </div>

                                <div class="form-group">
                                    <label for="txtParameters">Parameters</label>
                                    <input type="text" id="txtParameters" class="form-control" value="<?php echo $data['parameters'];?>" placeholder="Parameters">
                                </div>
                                <div class="form-group">
                                    <label for="txtDomain">Unique Key Count</label>
                                    <div id="spinner3">
                                        <div class="input-group" style="width:150px;">
                                            <input type="text" id="ip_count" class="spinner-input form-control" value="<?php echo $data['ip_count'];?>" maxlength="3" readonly>
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
                                <button type="submit" id="btnSubmit" class="btn btn-info">Save License</button>
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

        <script type="text/javascript" src="<?php echo ASSETS_URL;?>/bootstrap-datepicker/js/bootstrap-datepicker.js"></script>
        <script>
        $('#spinner3').spinner({value:0, min: 1, max: 30});
        $('.default-date-picker').datepicker({
            format: 'dd-mm-yyyy',
            autoclose: true
        });
        </script>
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
            $("#frmEditLicense").submit(function (e) {
                e.preventDefault();

                var id = $("#txtId").val();
                var domain = $("#txtDomain").val();
                var licensekey = $('#txtLicenseKey').val();
                var customer_email = $("#txtCustomerEmail").val();
                var expirydate = $("#expirationdate").val();
                var productidString = $("#slcProduct").val();
                var productidStringexplode = productidString.split("<#>");
                var productid = productidStringexplode[0];
                var productStripeId = productidStringexplode[1];
                var status = $("#slcStatus").val();
                var comments = $("#txtComments").val();
                var parameters = $("#txtParameters").val();
                var ip_count = $("#ip_count").val();
                $.ajax({

                    type: "POST",
                    data: {
                        id:id,
                        domain:domain,
                        licensekey:licensekey,
                        customer_email:customer_email,
                        expirydate:expirydate,
                        productid:productid,
                        productStripeId:productStripeId,
                        status:status,
                        comments:comments,
                        parameters:parameters,
                        ip_count:ip_count,
                        token:'<?php echo $TOTP->generateCode();?>',
                        handler: 'savelicense'
                    },

                    url: "ajax/",
                    dataType: "json",
                    success: function (result) {

                        if(result.status == 200)
                        {
                            $("#btnSubmit").html('Success...');
                            $("#btnSubmit").addClass('btn-success');
                            $(window.document.location).attr('href', 'licenses.php');
                        }else{
                            $("#btnSubmit").html('Save License');
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
                    toastr[error]("Unknown Error. Contact the support team.", "Oops!");
                }
            });
return false;
});
});

</script>
</body>
</html>
