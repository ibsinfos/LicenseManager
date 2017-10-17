<?php
/**
 * Unreal Studio
 * Project: UnrealLicensing
 * User: jhollsoliver
 * Date: 04/06/15
 * Time: 14:59
 */
?>
<aside>
    <div id="sidebar"  class="nav-collapse ">
        <!-- sidebar menu start-->
        <ul class="sidebar-menu" id="nav-accordion">
            <li>
                <a <?php if(basename($_SERVER["SCRIPT_FILENAME"], '.php') == 'index'){echo('class="active" ');}?>href="./">
                    <i class="fa fa-dashboard"></i>
                    <span>Dashboard</span>
                </a>
            </li>

            <li class="sub-menu">
                <a <?php if(basename($_SERVER["SCRIPT_FILENAME"], '.php') == 'licenses' or basename($_SERVER["SCRIPT_FILENAME"], '.php') == 'newlicense'){echo('class="active" ');}?>href="javascript:;" >
                    <i class="fa fa-key"></i>
                    <span>Licenses</span>
                </a>
                <ul class="sub">
                    <li <?php if(basename($_SERVER["SCRIPT_FILENAME"], '.php') == 'licenses'){echo('class="active"');}?>><a  href="licenses.php">Manage Licenses</a></li>
                    <li <?php if(basename($_SERVER["SCRIPT_FILENAME"], '.php') == 'newlicense'){echo('class="active"');}?>><a  href="newlicense.php">Issue new License</a></li>
                </ul>
            </li>

            <li class="sub-menu">
                <a <?php if(basename($_SERVER["SCRIPT_FILENAME"], '.php') == 'jsobfuscator' or basename($_SERVER["SCRIPT_FILENAME"], '.php') == 'generateclass' or basename($_SERVER["SCRIPT_FILENAME"], '.php') == 'obfuscator' or basename($_SERVER["SCRIPT_FILENAME"], '.php') == 'checklicensefile'){echo('class="active" ');}?>href="javascript:;" >
                    <i class="fa fa-shield"></i>
                    <span>Security Tools</span>
                </a>
                <ul class="sub">
                    <li <?php if(basename($_SERVER["SCRIPT_FILENAME"], '.php') == 'generateclass'){echo('class="active"');}?>><a  href="generateclass.php">Generate Protection Class</a></li>
                    <li <?php if(basename($_SERVER["SCRIPT_FILENAME"], '.php') == 'obfuscator'){echo('class="active"');}?>><a  href="obfuscator.php">PHP Obfuscator</a></li>
                    <li <?php if(basename($_SERVER["SCRIPT_FILENAME"], '.php') == 'checklicensefile'){echo('class="active"');}?>><a  href="checklicensefile.php">License Certificate Checker</a></li>
                </ul>
            </li>

            <li class="sub-menu">
                <a <?php if(basename($_SERVER["SCRIPT_FILENAME"], '.php') == 'products' or basename($_SERVER["SCRIPT_FILENAME"], '.php') == 'newproduct'){echo('class="active" ');}?>href="javascript:;" >
                    <i class="fa fa-tags"></i>
                    <span>Products</span>
                </a>
                <ul class="sub">
                    <li <?php if(basename($_SERVER["SCRIPT_FILENAME"], '.php') == 'products'){echo('class="active"');}?>><a  href="products.php">Manage Products</a></li>
                    <li <?php if(basename($_SERVER["SCRIPT_FILENAME"], '.php') == 'newproduct'){echo('class="active"');}?>><a  href="newproduct.php">New Product</a></li>
                </ul>
            </li>

            <li>
                <a <?php if(basename($_SERVER["SCRIPT_FILENAME"], '.php') == 'about'){echo('class="active" ');}?>href="about.php">
                    <i class="fa fa-question-circle"></i>
                    <span>About / Version</span>
                </a>
            </li>

            <li class="sub-menu">
                <a <?php if(basename($_SERVER["SCRIPT_FILENAME"], '.php') == 'settings' or basename($_SERVER["SCRIPT_FILENAME"], '.php') == 'api-settings' or basename($_SERVER["SCRIPT_FILENAME"], '.php') == 'upload' or basename($_SERVER["SCRIPT_FILENAME"], '.php') == 'mailsettings'){echo('class="active" ');}?>href="javascript:;" >
                    <i class="fa fa-cogs"></i>
                    <span>Settings</span>
                </a>
                <ul class="sub">
                    <li <?php if(basename($_SERVER["SCRIPT_FILENAME"], '.php') == 'settings'){echo('class="active"');}?>><a  href="settings.php">General Settings</a></li>
                    <li <?php if(basename($_SERVER["SCRIPT_FILENAME"], '.php') == 'mailsettings'){echo('class="active"');}?>><a  href="mailsettings.php">Mail Settings</a></li>
                    <li <?php if(basename($_SERVER["SCRIPT_FILENAME"], '.php') == 'api-settings'){echo('class="active"');}?>><a  href="api-settings.php">API Settings</a></li>
                    <li <?php if(basename($_SERVER["SCRIPT_FILENAME"], '.php') == 'upload'){echo('class="active"');}?>><a  href="upload.php">Upload Module</a></li>
                    <li <?php if(basename($_SERVER["SCRIPT_FILENAME"], '.php') == 'update'){echo('class="active"');}?>><a  href="update.php">Update Center</a></li>
                </ul>
            </li>


        </ul>
        <!-- sidebar menu end-->
    </div>
</aside>