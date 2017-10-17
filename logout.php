<?php
/**
 * Unreal Studio
 * Project: UnrealLicensing
 * User: jhollsoliver
 * Date: 06/06/15
 * Time: 10:20
 */

include 'system/autoloader.php';
session_destroy();
header("Location: login.php");