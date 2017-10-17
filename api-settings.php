<?php
/**
 * Created by PhpStorm.
 * User: GiovannedeOliveira
 * Date: 12/08/2015
 * Time: 12:19
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
    //die(var_dump($com));
    switch($com[0])
    {
        case 'delete':
            $id = $com[1];
            $sql = "DELETE FROM apikeys WHERE id = '$id'";
            $query = $DatabaseHandler->query($sql);
            header("Location: api-settings.php");
            break;
        case 'activate_insertpermission':
            $id = $com[1];
            $sql = "UPDATE apikeys SET license_insert_permission = 1 WHERE id = '$id'";
            $query = $DatabaseHandler->query($sql);
            header("Location: api-settings.php");
            break;
        case 'deactivate_insertpermission':
            $id = $com[1];
            $sql = "UPDATE apikeys SET license_insert_permission = 0 WHERE id = '$id'";
            $query = $DatabaseHandler->query($sql);
            header("Location: api-settings.php");
            break;
        case 'activate_updatepermission':
            $id = $com[1];
            $sql = "UPDATE apikeys SET license_update_permission = 1 WHERE id = '$id'";
            $query = $DatabaseHandler->query($sql);
            header("Location: api-settings.php");
            break;
        case 'deactivate_updatepermission':
            $id = $com[1];
            $sql = "UPDATE apikeys SET license_update_permission = 0 WHERE id = '$id'";
            $query = $DatabaseHandler->query($sql);
            header("Location: api-settings.php");
            break;
        case 'activate_deletepermission':
            $id = $com[1];
            $sql = "UPDATE apikeys SET license_delete_permission = 1 WHERE id = '$id'";
            $query = $DatabaseHandler->query($sql);
            header("Location: api-settings.php");
            break;
        case 'deactivate_deletepermission':
            $id = $com[1];
            $sql = "UPDATE apikeys SET license_delete_permission = 0 WHERE id = '$id'";
            $query = $DatabaseHandler->query($sql);
            header("Location: api-settings.php");
            break;

        case 'activate_readpermission':
            $id = $com[1];
            $sql = "UPDATE apikeys SET license_read_permission = 1 WHERE id = '$id'";
            $query = $DatabaseHandler->query($sql);
            header("Location: api-settings.php");
            break;
        case 'deactivate_readpermission':
            $id = $com[1];
            $sql = "UPDATE apikeys SET license_read_permission = 0 WHERE id = '$id'";
            $query = $DatabaseHandler->query($sql);
            header("Location: api-settings.php");
            break;

        case 'activatestatus':
            $id = $com[1];
            $sql = "UPDATE apikeys SET status = 'active' WHERE id = '$id'";
            $query = $DatabaseHandler->query($sql);
            header("Location: api-settings.php");
            break;
        case 'deactivatestatus':
            $id = $com[1];
            $sql = "UPDATE apikeys SET status = 'inactive' WHERE id = '$id'";
            $query = $DatabaseHandler->query($sql);
            header("Location: api-settings.php");
            break;
        case 'generate':
            //$id = $com[1];
            $key = $Tools->keygen();
            $timestamp = time();
            $sql = "INSERT INTO `apikeys` (`apikey`, `license_insert_permission`, `license_update_permission`, `license_delete_permission`, `license_read_permission`, `status`, `issued`) VALUES ('$key', '0', '0', '0', '1', 'active', '$timestamp')";
            $query = $DatabaseHandler->query($sql);
            header("Location: api-settings.php");
            break;


        default:
            header("Location: api-settings.php");
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

    <title><?php echo PRODUCT_NAME;?> API Settings</title>

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
                            API Keys
                        </header>
                        <div class="panel-body">
                            <table  class="display table table-bordered table-striped" id="dynamic-table">
                                <thead>
                                <tr>
                                    <th>ID</th>
                                    <th>API Key</th>
                                    <th>Created in</th>
                                    <th>Insert Permission</th>
                                    <th>Update Permission</th>
                                    <th>Delete Permission</th>
                                    <th>Read Permission</th>
                                    <th>Status</th>
                                    <th>Actions</th>
                                </tr>
                                </thead>
                                <tbody>
                                <?php
                                $query = $DatabaseHandler->query("SELECT * FROM apikeys");
                                while($row = $query->fetch_array()){?>
                                    <tr class="gradeX">
                                    <td><?php echo $row['id'];?></td>
                                    <td><?php echo $row['apikey'];?></td>
                                    <td><?php echo date('d/m/Y h:i:s', $row['issued']);?></td>
                                    <td><?php switch($row['license_insert_permission'])
                                        {
                                            case true:
                                                ?><span class="label label-success"><a style="color:white" href="?c=<?php echo $RevAlgo->EncryptAndEncode('deactivate_insertpermission|'.$row['id'].'|'.microtime());?>">ACTIVE</a></span><?php
                                                break;
                                            case false:
                                                ?><span class="label label-warning"><a style="color:white" href="?c=<?php echo $RevAlgo->EncryptAndEncode('activate_insertpermission|'.$row['id'].'|'.microtime());?>">INACTIVE</a></span><?php
                                                break;
                                            default:
                                                ?><span class="label label-default"><a style="color:white" href="?c=<?php echo $RevAlgo->EncryptAndEncode('activate_insertpermission|'.$row['id'].'|'.microtime());?>">UNKNOWN</a></span><?php
                                                break;
                                        }?></td>
                                    <td><?php switch($row['license_update_permission'])
                                        {
                                            case true:
                                                ?><span class="label label-success"><a style="color:white" href="?c=<?php echo $RevAlgo->EncryptAndEncode('deactivate_updatepermission|'.$row['id'].'|'.microtime());?>">ACTIVE</a></span><?php
                                                break;
                                            case false:
                                                ?><span class="label label-warning"><a style="color:white" href="?c=<?php echo $RevAlgo->EncryptAndEncode('activate_updatepermission|'.$row['id'].'|'.microtime());?>">INACTIVE</a></span><?php
                                                break;
                                            default:
                                                ?><span class="label label-default"><a style="color:white" href="?c=<?php echo $RevAlgo->EncryptAndEncode('activate_updatepermission|'.$row['id'].'|'.microtime());?>">UNKNOWN</a></span><?php
                                                break;
                                        }?></td>
                                    <td><?php switch($row['license_delete_permission'])
                                        {
                                            case true:
                                                ?><span class="label label-success"><a style="color:white" href="?c=<?php echo $RevAlgo->EncryptAndEncode('deactivate_deletepermission|'.$row['id'].'|'.microtime());?>">ACTIVE</a></span><?php
                                                break;
                                            case false:
                                                ?><span class="label label-warning"><a style="color:white" href="?c=<?php echo $RevAlgo->EncryptAndEncode('activate_deletepermission|'.$row['id'].'|'.microtime());?>">INACTIVE</a></span><?php
                                                break;
                                            default:
                                                ?><span class="label label-default"><a style="color:white" href="?c=<?php echo $RevAlgo->EncryptAndEncode('activate_deletepermission|'.$row['id'].'|'.microtime());?>">UNKNOWN</a></span><?php
                                                break;
                                        }?></td>
                                    <td><?php switch($row['license_read_permission'])
                                        {
                                            case true:
                                                ?><span class="label label-success"><a style="color:white" href="?c=<?php echo $RevAlgo->EncryptAndEncode('deactivate_readpermission|'.$row['id'].'|'.microtime());?>">ACTIVE</a></span><?php
                                                break;
                                            case false:
                                                ?><span class="label label-warning"><a style="color:white" href="?c=<?php echo $RevAlgo->EncryptAndEncode('activate_readpermission|'.$row['id'].'|'.microtime());?>">INACTIVE</a></span><?php
                                                break;
                                            default:
                                                ?><span class="label label-default"><a style="color:white" href="?c=<?php echo $RevAlgo->EncryptAndEncode('activate_readpermission|'.$row['id'].'|'.microtime());?>">UNKNOWN</a></span><?php
                                                break;
                                        }?></td>

                                    <td><?php switch($row['status'])
                                        {
                                            case 'active':
                                                ?><span class="label label-success"><a style="color:white" href="?c=<?php echo $RevAlgo->EncryptAndEncode('deactivatestatus|'.$row['id'].'|'.microtime());?>">ACTIVE</a></span><?php
                                                break;
                                            case 'inactive':
                                                ?><span class="label label-warning"><a style="color:white" href="?c=<?php echo $RevAlgo->EncryptAndEncode('activatestatus|'.$row['id'].'|'.microtime());?>">INACTIVE</a></span><?php
                                                break;
                                            default:
                                                ?><span class="label label-default"><a style="color:white" href="?c=<?php echo $RevAlgo->EncryptAndEncode('activatestatus|'.$row['id'].'|'.microtime());?>">UNKNOWN</a></span><?php
                                                break;
                                        }?></td>

                                    <td>   <a href="?c=<?php echo $RevAlgo->EncryptAndEncode('delete|'.$row['id'].'|'.microtime());?>" class="btn btn-primary btn-xs"><i class="fa fa-ban"></i></a></td>
                                    </tr><?php }?>
                                </tbody>
                                <tfoot>
                                <tr>
                                    <th>ID</th>
                                    <th>API Key</th>
                                    <th>Created in</th>
                                    <th>Insert Permission</th>
                                    <th>Update Permission</th>
                                    <th>Delete Permission</th>
                                    <th>Read Permission</th>
                                    <th>Status</th>
                                    <th>Actions</th>
                                </tr>
                                </tfoot>
                            </table>
                            <a href="?c=<?php echo $RevAlgo->EncryptAndEncode('generate|'.microtime());?>" type="button" class="btn btn-primary">Generate new API Key</a>
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

            url: "http://api.phpmylicense.com/v1/public/generatekey",
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
    })
    $("#btnUpdate").click(function(e){

        var serialmask = $("#mask").val();
        var returndata = $("#returndata").bootstrapSwitch('status');
        var returnencrypted = $("#returnencrypted").bootstrapSwitch('status');
        var encryption_key = $("#encryption_key").val();
        var updatechannel = $("#updatechannel").val();
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

