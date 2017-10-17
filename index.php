<?php
/**
 * Unreal Studio
 * Project: UnrealLicensing
 * User: jhollsoliver
 * Date: 03/06/15
 * Time: 21:29
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

    <title><?php echo PRODUCT_NAME;?> Dashboard</title>

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
                <div class="col-lg-12">
                    <!--work progress start-->
                    <section class="panel">
                        <div class="panel-body progress-panel">
                            <div class="task-progress">
                                <h1>Licenses Overview</h1>
                                <p>Recent Licenses Added to Server</p>
                            </div>
                        </div>
                        <table class="table table-hover personal-task">
                            <tbody>
                            <?php $query = $DatabaseHandler->query("SELECT id, host, customer_email, status, expirydate FROM licenses");
                                while($row = $query->fetch_array()){?>
                            <tr>
                                <td><?php echo $row['id'];?></td>
                                <td>
                                    <?php $row['host'];?>
                                </td>
                                <td>
                                    <?php switch($row['status'])
                                    {
                                        case 'active':
                                            ?><span class="label label-success">ACTIVE</span><?php
                                            break;
                                        case 'inactive':
                                            ?><span class="label label-warning">INACTIVE</span><?php
                                            break;
                                        case 'suspended':
                                            ?><span class="label label-danger">SUSPENDED</span><?php
                                            break;
                                        case 'processing':
                                            ?><span class="label label-info">PROCESSING</span><?php
                                            break;
                                        default:
                                            ?><span class="label label-default">UNKNOWN</span><?php
                                            break;
                                    }?>
                                </td>
                                <td>
                                    <?php echo $row['customer_email'];?>
                                </td>
                                <td>
                                    <?php echo date('d/m/Y', $row['expirydate']);?>
                                </td>
                            </tr><?php }?>
                            </tbody>
                        </table>
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

<?php
include 'assets/inc/changepwd.php';
?>

</body>
</html>

