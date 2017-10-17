<?php
/**
 * Unreal Studio
 * Project: UnrealLicensing
 * User: jhollsoliver
 * Date: 05/06/15
 * Time: 23:04
 */


include_once 'system/autoloader.php';
$Logged = $Tools->CheckIfLogged($_SESSION);
if(!$Logged)
{
    header("Location: login.php?go=".base64_encode($_SERVER["REQUEST_URI"])."");
}

if(isset($_GET['f']))
{
    $file = $RevAlgo->DecryptAndDecode($_GET['f']);
}else{
    header("Location: upload.php");
}
if(!is_file('system/temp/'.$file.'.zip'))
{
    header("Location: upload.php");
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

    <title><?php echo PRODUCT_NAME;?> Install Package</title>

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
            <div class="row">
                <div class="col-lg-12">
                    <!--work progress start-->
                    <section class="panel">
                        <div class="panel-body">
                            <h1>PHPMYLICENSE UPDATER</h1>
                            <?php
                            //define('SITEPATH', SYSTEMPATH);
                            $file = 'system/temp/'.$file.'.zip';

                            $zipHandle = zip_open($file);
                            while ($aF = zip_read($zipHandle) )
                            {
                                $thisFileName = zip_entry_name($aF);
                                $thisFileDir = dirname($thisFileName);

                                //Continue if its not a file
                                if ( substr($thisFileName,-1,1) == '/') continue;


                                //Make the directory if we need to...
                                if ( !is_dir ( $thisFileDir ) )
                                {
                                    mkdir ( $thisFileDir );
                                    echo '<li>Created Directory '.$thisFileDir.'</li>';
                                }

                                //Overwrite the file
                                if ( !is_dir($thisFileDir.'/'.$thisFileName) ) {
                                    echo '<li>'.$thisFileName.'...........';
                                    $contents = zip_entry_read($aF, zip_entry_filesize($aF));
                                    $contents = str_replace("\\r\\n", "\\n", $contents);
                                    $updateThis = '';

                                    //If we need to run commands, then do it.
                                    if ( $thisFileName == 'upgrade.php' )
                                    {
                                        $upgradeExec = fopen ('upgrade.php','w');
                                        fwrite($upgradeExec, $contents);
                                        fclose($upgradeExec);
                                        chmod('upgrade.php', 0777);
                                        include ('upgrade.php');
                                        unlink('upgrade.php');
                                        echo' EXECUTED</li>';
                                    }
                                    else
                                    {
                                        $updateThis = fopen($thisFileName, 'w');
                                        fwrite($updateThis, $contents);
                                        fclose($updateThis);
                                        unset($contents);
                                        echo' UPDATED</li>';
                                    }
                                }
                           }
                            unlink($file);?>
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