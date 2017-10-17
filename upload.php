<?php
/**
 * Unreal Studio
 * Project: UnrealLicensing
 * User: jhollsoliver
 * Date: 05/06/15
 * Time: 22:38
 */


include_once 'system/autoloader.php';
$Logged = $Tools->CheckIfLogged($_SESSION);
if(!$Logged)
{
    header("Location: login.php?go=".base64_encode($_SERVER["REQUEST_URI"])."");
}
if(isset($_POST['btnSend']))
{
    $uploaddir = 'system/temp/';
    $filename = explode(".", $_FILES["zipfile"]["name"]);
    $ext = end($filename);
    //if($_FILES['zipfile']['type'] == 'application/zip')
    if($ext == 'pkg')
    {
        $filename = md5(microtime());
        $uploadedfile = $uploaddir.$filename.'.zip';
        if(move_uploaded_file($_FILES['zipfile']['tmp_name'], $uploadedfile))
        {
            $filestream = file_get_contents($uploadedfile);
            $original = mb_substr($filestream, 0, -32);
            file_put_contents($uploadedfile, $original);
            $md5 = substr($filestream, -32, 32);
            $checksum = md5_file($uploadedfile);

            if($checksum == $md5)
            {
                header("Location: installzip.php?f=".$RevAlgo->EncryptAndEncode($filename));
            }else{
                $error = 'This is not a signed update package.';
            }


        }else{
            $error = 'Unknown Error. Try again.';
        }
    }else{
        $error = 'File uploaded is not a Zip File';
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
                            <?php if(isset($error))
                            {?>
                            <div class="alert alert-block alert-danger fade in">
                                <button data-dismiss="alert" class="close close-sm" type="button">
                                    <i class="fa fa-times"></i>
                                </button>
                                <strong>Error!</strong> <?php echo $error;?>.
                            </div><?php }?>
                            <form method="post" enctype="multipart/form-data">

                                <div style="padding:50px;padding-top:50px;padding-bottom:100px" class="text-center">
                                    <i class="fa fa-cloud-upload" style="color:#676767;font-size:10em"></i>

                                    <h2>Install Updates and New Modules</h2>

                                    <div class="form-group">

                                        <div class="fileupload fileupload-new" data-provides="fileupload">
                                                <span class="btn btn-white btn-file">
                                                <span class="fileupload-new"><i class="fa fa-paper-clip"></i> Select file</span>
                                                <span class="fileupload-exists"><i class="fa fa-undo"></i> Change</span>
                                                <input type="file" name="zipfile" id="zipfile" class="default">
                                                </span>
                                            <span class="fileupload-preview" style="margin-left:5px;"></span>
                                            <a href="#" class="close fileupload-exists" data-dismiss="fileupload" style="float: none; margin-left:5px;"></a>
                                        </div>

                                    </div>
                                    <div class="form-group">
                                        <button type="submit" name="btnSend" class="btn btn-primary">Install Module / Update</button>
                                    </div>
                    <span class="inline-help">
                    Search your <strong>zip</strong> file and upload it!
                    </span>

                                    <div class="clearfix"></div>
                    <span class="inline-help text-warning">
                    Please make <strong>backup</strong> of all files before to upload new module or update
                    </span>
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

</body>
</html>
