<?php
/**
 * Unreal Studio
 * Project: UnrealLicensing
 * User: jhollsoliver
 * Date: 04/06/15
 * Time: 15:25
 */
?>
<div class="row state-overview">

    <?php
    $query = $DatabaseHandler->query("SELECT purchasecode FROM settings");
    $data = $query->fetch_array();
    $latestversion = $Tools->GetLatestVersion($data['purchasecode']);
    if($latestversion > PRODUCT_VERSION)
    {?><div class="alert alert-warning fade in">
        <button data-dismiss="alert" class="close close-sm" type="button">
            <i class="fa fa-times"></i>
        </button>
        <strong>Hey!</strong> An update to the version <?php echo $latestversion;?> is avaiable! Go to <a href="update.php">Update Center</a> to Install.
    </div>
    <?php }?>
    <?php
    if(isset($admin_override))
    {
        ?>
        <div class="alert alert-warning fade in">
            <button data-dismiss="alert" class="close close-sm" type="button">
                <i class="fa fa-times"></i>
            </button>
            ADMIN OVERRIDE - DEVELOPER MODE! BE CAREFULL!
        </div>
        <?php

    }

    /*

    // Deactivated by resolution PML_Disable_API_COM

    $return = json_decode(file_get_contents(PHPMYLICENSE_API.'/public/getmessages?purchasecode='.$data['purchasecode']), true);
    $total = $return['total'];
    if($total > 0)
    {
        for($i = 0;$i < $total; $i++)
        {?>
            <div class="alert alert-<?php echo $return['messages'][$i]['class'];?> fade in">
                <button data-dismiss="alert" class="close close-sm" type="button">
                    <i class="fa fa-times"></i>
                </button>
                <?php echo base64_decode($return['messages'][$i]['text']);?>
            </div>

        <?php }
    }
*/
    ?>
    <div class="col-lg-4 col-sm-6">
        <section class="panel">
            <div class="symbol terques">
                <i class="fa fa-key"></i>
            </div>
            <div class="value">
                <h1>
                    <?php
                    $sql = "SELECT id FROM licenses";
                    $query = $DatabaseHandler->query($sql);
                    if($query)
                    {
                        echo $query->num_rows;
                    }else{
                        echo 'ERROR';
                    }
                    ?>
                </h1>
                <p>Licenses</p>
            </div>
        </section>
    </div>
    <div class="col-lg-4 col-sm-6">
        <section class="panel">
            <div class="symbol red">
                <i class="fa fa-tags"></i>
            </div>
            <div class="value">
                <h1>
                    <?php
                    $sql = "SELECT id FROM products";
                    $query = $DatabaseHandler->query($sql);
                    if($query)
                    {
                        echo $query->num_rows;
                    }else{
                        echo 'ERROR';
                    }

                    ?>
                </h1>
                <p>Products</p>
            </div>
        </section>
    </div>
    <div class="col-lg-4 col-sm-6">
        <section class="panel">
            <div class="symbol blue">
                <i class="fa fa-cogs"></i>
            </div>
            <div class="value">
                <h1>
                    <?php echo PRODUCT_VERSION;?>
                </h1>
                <p>System Version</p>
            </div>
        </section>
    </div>

</div>