<?php
/**
 * Unreal Studio
 * Project: UnrealLicensing
 * User: jhollsoliver
 * Date: 04/06/15
 * Time: 14:51
 */

?>
<!--search & user info start-->
<ul class="nav pull-right top-menu">
    <!-- user login dropdown start-->
    <li class="dropdown">
        <a data-toggle="dropdown" class="dropdown-toggle" href="#">
            <!--<img alt="" src="<?php echo ASSETS_URL;?>img/avatar1_small.jpg">-->
            <span class="username"><?php echo $_SESSION['name'];?></span>
            <b class="caret"></b>
        </a>
        <ul class="dropdown-menu extended logout">
            <div class="log-arrow-up"></div>
            <li><a href="#mdlChangePwd" data-toggle="modal"><i class="fa fa-key"></i> Change Password</a></li>
            <li><a href="about.php"><i class="fa fa-cog"></i> About</a></li>
            <li><a href="logout.php"><i class="fa fa-key"></i> Log Out</a></li>
        </ul>
    </li>
    <!-- user login dropdown end -->
</ul>
<!--search & user info end-->

<div aria-hidden="true" aria-labelledby="myModalLabel" role="dialog" tabindex="-1" id="mdlChangePwd" class="modal fade">
    <div class="modal-dialog">
        <div class="modal-content">
            <div class="modal-header">
                <button aria-hidden="true" data-dismiss="modal" class="close" type="button">×</button>
                <h4 class="modal-title">Update your Password</h4>
            </div>
            <div class="modal-body">

                <form class="form-horizontal" id="frmChangePwd" role="form">
                    <div class="form-group">
                        <label for="inputPassword1" class="col-lg-2 col-sm-2 control-label">Old Password</label>
                        <div class="col-lg-10">
                            <input type="password" class="form-control" id="OldPwd" placeholder="Old Password">
                        </div>
                    </div>
                    <div class="form-group">
                        <label for="inputPassword1" class="col-lg-2 col-sm-2 control-label">New Password</label>
                        <div class="col-lg-10">
                            <input type="password" class="form-control" id="NewPwd" placeholder="New Password">
                        </div>
                    </div>
                    <div class="form-group">
                        <label for="inputPassword1" class="col-lg-2 col-sm-2 control-label">Repeat New Password</label>
                        <div class="col-lg-10">
                            <input type="password" class="form-control" id="NewPwd2" placeholder="Repeat New Password">
                        </div>
                    </div>
                    <div class="form-group">
                        <div class="col-lg-offset-2 col-lg-10">
                            <button type="button" id="btnChangePwd" onClick="javascript:UpdatePwd();" class="btn btn-default">Update Password</button>
                        </div>
                    </div>
                </form>

            </div>

        </div>
    </div>
</div>