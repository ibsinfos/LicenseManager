<?php
/**
 * Unreal Studio
 * Project: UnrealLicensing
 * User: jhollsoliver
 * Date: 03/06/15
 * Time: 16:38
 */

/**
 * Configuration Includes
 */

include_once 'config.php';
include_once 'cryptoconfig.php';

if (!isset($BaseURL)) {
    header("Location: install/");
}

/**
 * Library Includes
 */
include_once 'libs/RevAlgo.php';
include_once 'libs/Gauntlet.php';
include_once 'libs/Tools.php';
include_once 'libs/FilterClass.php';
include_once 'libs/totp.class.php';
include_once 'libs/sqAES.php';
include_once 'libs/SignatureHandler.php';
include_once 'libs/PML_Obfuscator.core.php';
include_once 'libs/AESHelper.php';
define('basepath', dirname(__FILE__) . '/libs');
include_once 'libs/phpseclib/Crypt/RSA.php';
include_once 'libs/IssueLicenseCertificateHandler.php';
include_once 'libs/LicenseCertificateHandler.php';
include_once 'libs/PHPMailer-master/PHPMailerAutoload.php';
//include_once 'libs/PHPMailer-master/class.smtp.php';

/**
 * Library Object Initialization
 */

$AES = new AESHelper();
$RSA = new Crypt_RSA();

$LicenseCertChecker = new LicenseCertificateHandler($RSA, $AES);
$LicenseCertChecker->LoadPublicKey($RSAKeyPair['public']);

$LicenseCertificateIssuer = new IssueLicenseCertificateHandler($RSA, $AES);
$LicenseCertificateIssuer->LoadPrivateKey($RSAKeyPair['private']);

$Gauntlet = new Gauntlet();
$RevAlgo = new RevAlgo($RevAlgoCfg['key'], $RevAlgoCfg['sep']);
$Tools = new Tools();
$TOTP = new TOTP();
@$DatabaseHandler = new mysqli($Database['host'], $Database['user'], $Database['pass'], $Database['data']);
if ($DatabaseHandler->connect_errno > 0) {
    die($DatabaseHandler->error);
}
$TOTP->setSecretKey($RevAlgoCfg['key']);
$TOTP->setDigitsNumber(16);
$TOTP->setExpirationTime(240);
$Tools->RegisterClass('DbHandler', $DatabaseHandler);
$Tools->RegisterClass('TOTP', $TOTP);

/**
 * Constants Declaration
 */
define('BASE_URL', $BaseURL);
define('ASSETS_URL', $BaseURL . '/assets');
unset($BaseURL);
define('PRODUCT_NAME', 'PHPMyLicense');
define('PRODUCT_VERSION', '3.4.0');
define('SYSTEMPATH', dirname(__FILE__));
define('PHPMYLICENSE_API', 'https://api.phpmylicense.ml/v1');
define('PHPMYLICENSE_UPDATESERVICE', 'https://updates.phpmylicense.ml');
$query = $DatabaseHandler->query("SELECT purchasecode, configurations FROM settings");
$settings = $query->fetch_array();
$data = json_decode($settings['configurations']);
define('PRODUCT_UPDATECHANNEL', $data->updatechannel);
$purchasecode = $settings['purchasecode'];

/**
 * Security Initialization
 */

$SignatureHandler = new SignatureHandler();
$SignatureHandler->LoadExternalClass('Rsa', $RSA);

/**
 * Session Declaration
 */

session_start();


/**
 * License Verification
 */

$response = @file_get_contents(PHPMYLICENSE_API . '/envato/verifypurchase?purchasecode=' . $purchasecode);
$response_json = json_decode($response, true);
if ($response_json['valid'] == false && $response <> false) {
    die('<b>Error! </b>Your Purchase Code appears to be invalid or banned. Get in touch with us.<br><br>Error ID: 65d194c<br>Operation ID: ' . substr(md5(rand(0, 999)), 0, 11));
}
$f = json_decode(base64_decode(file_get_contents(__DIR__ . '/offline.dat')), true);
if ($response === false) {
    if (file_exists(__DIR__ . '/offline.dat')) {
        $SignatureHandler->LoadCustomKey(file_get_contents(__DIR__ . '/public_pml.pem'));
        $v = $SignatureHandler->ValidateJsonSignature($f);
        if (!$v) {
            die('<b>Error! </b>PHPMyLicense tried to validate your purchase via Offline Activation, but it seems to be invalid. Please connect to the Internet to be validated..<br><br>Error ID: a430f2b<br>Operation ID: ' . substr(md5(rand(0, 999)), 0, 11));
        }

        $now = time();
        if ($f['expiry'] < $now) {
            die('<b>Error! </b>PHPMyLicense tried to validate your purchase via Offline Activation, but it seems to be expired, it means you are too long off the network. Please connect to the Internet to be validated..<br><br>Error ID: c883432<br>Operation ID: ' . substr(md5(rand(0, 999)), 0, 11));
        }

        if ($f['purchasecode'] != $purchasecode) {
            die('<b>Error! </b>PHPMyLicense tried to validate your purchase via Offline Activation, but the purchase code seems not to be the same of your PML installation. Are you trying to null PML? If you want a copy, get in touch with us, maybe we can give you a free license!<br><br>Error ID: 3bbc5f3<br>Operation ID: ' . substr(md5(rand(0, 999)), 0, 11));
        }
        if ($f['host'] != $_SERVER['SERVER_ADDR'] && $_SERVER['SERVER_ADDR'] != '127.0.0.1') {
            /*die('<b>Error! </b>PHPMyLicense tried to validate your purchase via Offline Activation, but the machine you are trying to run this PML installation is not the same that generated the Offline Activation. Are you trying to null PML? If you want a copy, get in touch with us, maybe we can give you a free license!<br><br>Error ID: 16f0a8c<br>Operation ID: ' . substr(md5(rand(0, 999)), 0, 11));*/
			die(var_dump($_SERVER['SERVER_ADDR']));
        }


    } else {
        die('<b>Error! </b>PHPMyLicense tried to validate your License with Offline Methods and failed. Please try again in few seconds.<br><br>Error ID: 8b7432d<br>Operation ID: ' . substr(md5(rand(0, 999)), 0, 11));
    }
    
}else{
	$SignatureHandler->LoadCustomKey(file_get_contents(__DIR__ . '/public_pml.pem'));
        $v = $SignatureHandler->ValidateJsonSignature($f);
	if ($f['expiry'] < time() || $v == true) {
        $response = @file_get_contents(PHPMYLICENSE_API . '/envato/getofflinekey?purchasecode=' . $purchasecode);
        $response = @json_decode($response, true);
        if ($response['valid'] == true) {
            file_put_contents(__DIR__ . '/offline.dat', $response['activationfile']);
        }
    }
}

