<?php
/**
 * User: jhollsoliver
 * Date: 7/24/16
 * Time: 5:36 PM
 */
include_once('../system/autoloader.php');
$transaction_guid = $_GET['tid'];
$sql = "SELECT licenseid FROM renew_transactions WHERE guid = '$transaction_guid'";
$query = $DatabaseHandler->query($sql);
$data = $query->fetch_array();
$licensekey = $data['licenseid'];

$sql = "SELECT * FROM licenses WHERE licensekey = '$licensekey'";
$query = $DatabaseHandler->query($sql);

$licdata = $query->fetch_array();

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


    <form class="form-signin" id="frmCheckLicenseData" >
        <h2 class="form-signin-heading">SUCCESS!!</h2>

        <div class="login-wrap">
            <h4>Hello! Your license was renewed!<br>Check your new license info<br></h4>

            <p style="color:black">License Key: <b style="color:gray" id="lblLicenseKey"><?php echo $licdata['licensekey'];?></b></p>
            <p style="color:black">Email: <b style="color:gray" id="lblEmail"><?php echo $licdata['customer_email'];?></b></p>
            <p style="color:black">Domain: <b style="color:gray" id="lblDomain"><?php echo $licdata['host'];?></b></p>
            <p style="color:black">Expiration Date: <b style="color:gray" id="lblExpiryDate"><?php echo date("F j, Y", $licdata['expirydate']);?></b></p>
            <p style="color:black">Status: <b id="lblStatus"><?php

                    switch($licdata['status'])
                    {
                        case 'active':
                            ?><span class="label label-success">Active</span><?php
                            break;
                        case 'inactive':
                            ?><span class="label label-warning">Inactive</span><?php
                            break;
                        case 'suspended':
                            ?><span class="label label-danger">Suspended</span><?php
                            break;
                        case 'processing':
                            ?><span class="label label-info">Processing</span><?php
                            break;
                        default:
                            ?><span class="label label-default">Unknown</span><?php
                            break;
                    }

                    ?></b></p>
           <br> <h4>You will receive an email with more details about this transaction. Thank you!</h4>

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

</body>
</html>
