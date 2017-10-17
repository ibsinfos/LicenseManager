<?php
/**
 * Unreal Studio
 * Project: UnrealLicensing
 * User: jhollsoliver
 * Date: 04/06/15
 * Time: 10:18
 */

include_once 'system/autoloader.php';
$Logged = $Tools->CheckIfLogged($_SESSION);
if(!$Logged)
{
    header("Location: login.php?go=".base64_encode($_SERVER["REQUEST_URI"])."");
}
if(isset($_GET['c']))
{
    $c = $RevAlgo->DecryptAndDecode($_GET['c']);
    $com = explode('|', $c);
   // die(var_dump($com));
    switch($com[0])
    {
        case 'delete':
        $id = $com[1];
        $licensekey = $com[2];
        $sql = "DELETE FROM licenses WHERE id = '$id'";
        $query = $DatabaseHandler->query($sql);
       
        $sql_del_entries = "DELETE FROM ipaddress WHERE licensekey='$licensekey'";
        $query_del_entries = $DatabaseHandler->query($sql_del_entries);
        header("Location: licenses.php");
        break;
        case 'activate':
        $id = $com[1];
        $sql = "UPDATE licenses SET status = 'active' WHERE id = '$id'";
        $query = $DatabaseHandler->query($sql);
        header("Location: licenses.php");
        break;
        case 'deactivate':
        $id = $com[1];
        $sql = "UPDATE licenses SET status = 'inactive' WHERE id = '$id'";
        $query = $DatabaseHandler->query($sql);
        header("Location: licenses.php");
        break;
        case 'downloadlicensecert':
        $id = $com[1];
        $sql = "SELECT * FROM licenses WHERE id = '$id'";
        $query = $DatabaseHandler->query($sql);
        $data = $query->fetch_array();
        $hosts[] = $data['host'];
        $hosts[] = '127.0.0.1';
        $lic_cert = $LicenseCertificateIssuer->GenerateLicenseFile(99, $data['licensekey'], $data['customer_email'], $data['productid'], $data['expirydate'], $hosts, $data['comments'], true);
        header('Content-disposition: attachment; filename="License_'.$data['host'].'.lic"');
        header('Content-type: "text/xml"; charset="utf8"');
        echo $lic_cert;
        exit();
        break;
        default:
        header("Location: licenses.php");
        break;

    }
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

    <title><?php echo PRODUCT_NAME;?> Licenses</title>

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


    <!--dynamic table-->
    <link href="<?php echo ASSETS_URL;?>/advanced-datatable/media/css/demo_page.css" rel="stylesheet" />
    <link href="<?php echo ASSETS_URL;?>/advanced-datatable/media/css/demo_table.css" rel="stylesheet" />
    <link rel="stylesheet" href="<?php echo ASSETS_URL;?>/data-tables/DT_bootstrap.css" />


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
                                    <h1>Licenses</h1>
                                    <p>These are all licenses in database. To toggle de status, just click on it.</p>
                                </div>
                            </div>
                            <table  class="display table table-bordered table-striped" id="dynamic-table">
                                <thead>
                                    <tr>
                                        <th>ID</th>
                                        <th>License Key</th>
                                        <th>Customer Email</th>
                                        <th>Expiration Date</th>
                                        <th>Product</th>
                                        <th>Stripe Product Id</th>
                                        <th>Status</th>
                                        <th>Issued By</th>
                                        <!-- <th>Comments</th>-->
                                        <th>Actions</th>
                                    </tr>
                                </thead>
                                <tbody>
                                    <?php
                                    $query = $DatabaseHandler->query("SELECT * FROM licenses ORDER BY id ASC");
                                    while($row = $query->fetch_array()){ 
                                        ?>
                                        <tr class="gradeX">
                                            <td><?php echo $row['id'];?></td>
                                            <td>
                                                <?php
                                     echo $license_key = $row['licensekey'];
                                          ?>
                                        </td>
                                            <td><?php echo $row['customer_email'];?></td>
                                            <td><?php echo date('d/m/Y', $row['expirydate']);?></td>
                                            <td>
                                                <?php
                                                $productid = $row['productid'];
                                                $query2 = $DatabaseHandler->query("SELECT shortname,stripe_product_id FROM products WHERE id = '$productid'");
                                                $data2 = $query2->fetch_array();
                                                echo $data2['shortname'];
                                                ?>
                                            </td>
                                            <td><?php echo $row['product_purchase_stripe_id'];?></td>
                                            <td><?php switch($row['status'])
                                            {
                                                case 'active':
                                                ?><span class="label label-success"><a style="color:white" href="?c=<?php echo $RevAlgo->EncryptAndEncode('deactivate|'.$row['id'].'|'.microtime());?>">ACTIVE</a></span><?php
                                                break;
                                                case 'inactive':
                                                ?><span class="label label-warning"><a style="color:white" href="?c=<?php echo $RevAlgo->EncryptAndEncode('activate|'.$row['id'].'|'.microtime());?>">INACTIVE</a></span><?php
                                                break;
                                                case 'suspended':
                                                ?><span class="label label-danger"><a style="color:white" href="?c=<?php echo $RevAlgo->EncryptAndEncode('activate|'.$row['id'].'|'.microtime());?>">SUSPENDED</a></span><?php
                                                break;
                                                case 'processing':
                                                ?><span class="label label-info"><a style="color:white" href="?c=<?php echo $RevAlgo->EncryptAndEncode('activate|'.$row['id'].'|'.microtime());?>">PROCESSING</a></span><?php
                                                break;
                                                default:
                                                ?><span class="label label-default"><a style="color:white" href="?c=<?php echo $RevAlgo->EncryptAndEncode('activate|'.$row['id'].'|'.microtime());?>">UNKNOWN</a></span><?php
                                                break;
                                            }?></td>
                                            <td><?php echo $Tools->GetUserById($row['issued-by']);?></td>
                                            <!-- <td><?php //echo $row['comments'];?></td>-->
                                            <td><a href="editlicense.php?d=<?php echo $RevAlgo->EncryptAndEncode($row['id']);?>" class="btn btn-primary btn-xs"><i class="fa fa-edit"></i></a>   <a href="?c=<?php echo $RevAlgo->EncryptAndEncode('delete|'.$row['id'].'|'.$row['licensekey'].'|'.microtime());?>" class="btn btn-primary btn-xs"><i class="fa fa-ban"></i></a>   <a href="?c=<?php echo $RevAlgo->EncryptAndEncode('downloadlicensecert|'.$row['id'].'|'.microtime());?>" class="btn btn-primary btn-xs"><i class="fa fa-download"></i></a></td>
                                        </tr><?php } ?>
                                    </tbody>
                                    <tfoot>
                                        <tr>
                                            <th>ID</th>
                                            <th>License Key</th>
                                            <th>Customer Email</th>
                                            <th>Expiration Date</th>
                                            <th>Product</th>
                                            <th>Stripe Product Id</th>
                                            <th>Status</th>
                                            <th>Issued By</th>
                                            <!-- <th>Comments</th>-->
                                            <th>Actions</th>
                                        </tr>
                                    </tfoot>
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


            <script type="text/javascript" language="javascript" src="<?php echo ASSETS_URL;?>/advanced-datatable/media/js/jquery.dataTables.js"></script>
            <script type="text/javascript" src="<?php echo ASSETS_URL;?>/data-tables/DT_bootstrap.js"></script>
            <!--dynamic table initialization -->
            <script src="<?php echo ASSETS_URL;?>/js/dynamic_table_init.js"></script>

            <?php
            include 'assets/inc/changepwd.php';
            ?>

        </body>
        </html>
