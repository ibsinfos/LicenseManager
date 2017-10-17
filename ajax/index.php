<?php
/**
 * Unreal Studio
 * Project: UnrealLicensing
 * User: jhollsoliver
 * Date: 03/06/15
 * Time: 18:28
 */

include_once('../system/autoloader.php');
$sql = "SELECT * FROM settings";
$query = $DatabaseHandler->query($sql);
$data = $query->fetch_array();
$configurations = json_decode($data['configurations'], true);
$purchasecode = $data['purchasecode'];


$_REQUEST = FilterClass::filterXSS($_REQUEST);

if(isset($_REQUEST['handler'])) {
    $handler = $_REQUEST['handler'];
    @$token = $_REQUEST['token'];

    if ($handler == 'login') {
        $user = $Gauntlet->filter($_REQUEST['user']);
        $pass = hash('sha256', $_REQUEST['pass']);
        $sql = "SELECT id, name, status, email, role, last_login_ip, last_login_timestamp FROM `users` WHERE `username` = '$user' AND `password` = '$pass'";
        $query = $DatabaseHandler->query($sql);
        if ($query) {
            if ($query->num_rows > 0) {
                $data = $query->fetch_array();
                if ($data['status'] == 'active') {
                    $_SESSION['logged'] = true;
                    $_SESSION['username'] = $user;
                    $_SESSION['id'] = $data['id'];
                    $_SESSION['name'] = $data['name'];
                    $_SESSION['email'] = $data['email'];
                    $_SESSION['role'] = $data['role'];
                    $_SESSION['last_login_ip'] = $data['last_login_ip'];
                    $_SESSION['last_login_timestamp'] = $data['last_login_timestamp'];
                    $_SESSION['session_logged_token'] = hash('sha512', $_SESSION['username'].$_SESSION['name'].microtime(true));
                    //$_SESSION['session_auth_token'] = $TOTP->generateCode();
                    $sql = "UPDATE `users` SET last_login_ip`='" . $_SERVER['REMOTE_ADDR'] . "',`last_login_timestamp`='" . time() . "',`WHERE `id` = 'ID'";
                    @$query = $DatabaseHandler->query($sql);
                    $json['status'] = 200;
                    $json['message']['header'] = 'Success!';
                    $json['message']['text'] = 'Login Success! Redirecting you...';
                    $json['message']['type'] = 'success';
                    die(json_encode($json));
                } else {
                    $json['status'] = 301;
                    $json['message']['header'] = 'Oops!';
                    $json['message']['text'] = 'This user is not active.';
                    $json['message']['type'] = 'error';
                    die(json_encode($json));
                }

            } else {
                $json['status'] = 301;
                $json['message']['header'] = 'Oops!';
                $json['message']['text'] = 'Username or password invalid. Try again.';
                $json['message']['type'] = 'error';
                die(json_encode($json));
            }
        } else {
            $json['status'] = 500;
            $json['message']['header'] = 'Oops!';
            $json['message']['text'] = 'Error in Dsavelicenseatabase.';
            $json['message']['type'] = 'error';
            die(json_encode($json));
        }

    } else if ($handler == 'newlicense') {
        if(!$TOTP->validateCode($token))
        {
            $json['status'] = 401;
            $json['message']['header'] = 'Oops!';
            $json['message']['text'] = 'Invalid Token. Refresh the page and try again.';
            $json['message']['type'] = 'error';
            die(json_encode($json));
        }
        $domain = $Gauntlet->filter($_REQUEST['domain']);
        $customer_email = $Gauntlet->filter($_REQUEST['customer_email']);
        $expirydate = strtotime($_REQUEST['expirydate']);
        $productid = $Gauntlet->filter($_REQUEST['productid']);
        $productStripeId = $Gauntlet->filter($_REQUEST['productStripeId']);
        $status = $Gauntlet->filter($_REQUEST['status']);
        $comments = $Gauntlet->filter($_REQUEST['comments']);
        $parameters = $Gauntlet->filter($_REQUEST['parameters']);
        $ip_count = $Gauntlet->filter($_REQUEST['ip_count']);
        
        if ($customer_email == '' || $expirydate == '' || $status == '') {
            $json['status'] = 500;
            $json['message']['header'] = 'Oops!';
            $json['message']['text'] = 'You need to input Mandatory Fields.';
            $json['message']['type'] = 'error';
            die(json_encode($json));
        }
        if($domain == "*")
        {
            $status = 'inactive';
        }
        $LicenseKey = $Gauntlet->filter($_REQUEST['serialkey']);
        $userid = $_SESSION['id'];

        if(!empty($domain) || $domain!=""){

          $domain_array = explode(",", $domain);

          if(count($domain_array) <= $ip_count){

           $sql = "INSERT INTO `licenses` (`licensekey`, `customer_email`, `expirydate`, `productid`, `product_purchase_stripe_id`, `status`, `issued-by`, `comments`, `parameters`,`ip_count`) VALUES ('$LicenseKey', '$customer_email', '$expirydate', '$productid','$productStripeId', '$status', '$userid', '$comments', '$parameters','$ip_count');";
        //die(var_dump($sql));
           $query = $DatabaseHandler->query($sql);

           if ($query) {
               foreach ($domain_array as $value) {

                $current_date = date("Y-m-d H:i:s");
                $sql_ipaddress_tbl = "INSERT INTO `ipaddress` (`licensekey`,`host_ipaddress`, `added_time`) VALUES ('$LicenseKey','$value','$current_date')";
                $query_ipaddress = $DatabaseHandler->query($sql_ipaddress_tbl);

            }
            $json['status'] = 200;
            $json['message']['header'] = 'Success!';
            $json['message']['text'] = 'License inserted successfully!';
            $json['message']['type'] = 'success';
        }else {

            $json['status'] = 500;
            $json['message']['header'] = 'Oops!';
            $json['message']['text'] = 'Error in Database.';
            $json['message']['type'] = 'error';
        }

    }else{

        $json['status'] = 500;
        $json['message']['header'] = 'Oops!';
        $json['message']['text'] = 'Number of IP Address assigned is more than alloted!';
        $json['message']['type'] = 'error';
    }
    die(json_encode($json));

}else{

   $sql = "INSERT INTO `licenses` (`licensekey`, `customer_email`, `expirydate`, `productid`, `product_purchase_stripe_id`, `status`, `issued-by`, `comments`, `parameters`,`ip_count`) VALUES ('$LicenseKey', '$customer_email', '$expirydate', '$productid','$productStripeId', '$status', '$userid', '$comments', '$parameters','$ip_count');";
        //die(var_dump($sql));
   $query = $DatabaseHandler->query($sql);

       if ($query) {

           $json['status'] = 200;
           $json['message']['header'] = 'Success!';
           $json['message']['text'] = 'License inserted successfully!';
           $json['message']['type'] = 'success';
           die(json_encode($json));

       } else {

        $json['status'] = 500;
        $json['message']['header'] = 'Oops!';
        $json['message']['text'] = 'Error in Database.';
        $json['message']['type'] = 'error';
        die(json_encode($json));
    }
}


} else if ($handler == 'savelicense') {
    if(!$TOTP->validateCode($token))
    {
        $json['status'] = 401;
        $json['message']['header'] = 'Oops!';
        $json['message']['text'] = 'Invalid Token. Refresh the page and try again.';
        $json['message']['type'] = 'error';
        die(json_encode($json));
    }
    $id = $Gauntlet->filter($_REQUEST['id']);
    $domain = $Gauntlet->filter($_REQUEST['domain']);
    $licensekey = $Gauntlet->filter($_REQUEST['licensekey']);
    $customer_email = $Gauntlet->filter($_REQUEST['customer_email']);
    $expirydate = strtotime($_REQUEST['expirydate']);
    $productid = $Gauntlet->filter($_REQUEST['productid']);
    $productStripeId = $Gauntlet->filter($_REQUEST['productStripeId']);
    $status = $Gauntlet->filter($_REQUEST['status']);
    $comments = $Gauntlet->filter($_REQUEST['comments']);
        //$LicenseKey = $Tools->create_guid();
    $parameters = $Gauntlet->filter($_REQUEST['parameters']);
    $ip_count = $Gauntlet->filter($_REQUEST['ip_count']);
    $userid = $_SESSION['id'];
    if ($customer_email == '' || $expirydate == '' || $status == '') {
        $json['status'] = 500;
        $json['message']['header'] = 'Oops!';
        $json['message']['text'] = 'You need to input Mandatory Fields.';
        $json['message']['type'] = 'error';
        die(json_encode($json));
    }

    $sql = "UPDATE `licenses` SET `customer_email`='$customer_email',`expirydate`='$expirydate',`productid`='$productid',`product_purchase_stripe_id`='$productStripeId',`status`='$status',`comments`= '$comments', `parameters` = '$parameters' , `ip_count` = '$ip_count' WHERE `id` = '$id'";
        //die(var_dump($sql));
    $query = $DatabaseHandler->query($sql);
    if ($query) {

        if(!empty($domain) || $domain!=""){
           $i = 0;
           $domain_array = explode(",", $domain);

           if(count($domain_array) <= $ip_count){

             $sql_del_ipaddress = "DELETE FROM ipaddress WHERE licensekey='$licensekey'";
             $query_del_ipaddress = $DatabaseHandler->query($sql_del_ipaddress);

             foreach ($domain_array as $value) {

                 $exist_count = 0;
                 $sql_check_ip_exist = "SELECT * FROM ipaddress WHERE licensekey='$licensekey' AND host_ipaddress='$value'";
                 $query_check_ip_exist = $DatabaseHandler->query($sql_check_ip_exist);

                 if($query_check_ip_exist->num_rows < 1){

                     $current_date = date("Y-m-d H:i:s");
                     $sql_ipaddress_tbl = "INSERT INTO `ipaddress` (`licensekey`,`host_ipaddress`, `added_time`) VALUES ('$licensekey','$value','$current_date')";
                     $query_ipaddress = $DatabaseHandler->query($sql_ipaddress_tbl);

                 }

                 $i++;
             }
             $json['status'] = 200;
             $json['message']['header'] = 'Success!';
             $json['message']['text'] = 'License inserted successfully!';
             $json['message']['type'] = 'success';
               //die(json_encode($json));

         }else{

            $json['status'] = 500;
            $json['message']['header'] = 'Oops!';
            $json['message']['text'] = 'Number of IP Address assigned is more than alloted!';
            $json['message']['type'] = 'error';

        }

    }else{      /* end of  if of $domain check */
        $json['status'] = 200;
        $json['message']['header'] = 'Success!';
        $json['message']['text'] = 'License inserted successfully!';
        $json['message']['type'] = 'success';
    } 
    die(json_encode($json));

} else {

    $json['status'] = 500;
    $json['message']['header'] = 'Oops!';
    $json['message']['text'] = 'Error in Database.';
    $json['message']['type'] = 'error';
    die(json_encode($json));
}

} else if ($handler == 'obfuscate') {

 if(!$TOTP->validateCode($token))
 {
    $json['status'] = 401;
    $json['message']['header'] = 'Oops!';
    $json['message']['text'] = 'Invalid Token. Refresh the page and try again.';
    $json['message']['type'] = 'error';
    die(json_encode($json));
}
$script = $_REQUEST['script'];
         /*$query = $DatabaseHandler->query("SELECT purchasecode FROM settings");
        $data = $query->fetch_array();
        $purchasecode = $data['purchasecode'];
        $fields = array(
            'purchasecode' => $purchasecode,
            'script' => urlencode($script),
        );
        $fields_string = '';
        foreach ($fields as $key => $value) {
            $fields_string .= $key . '=' . $value . '&';
        }
        rtrim($fields_string, '&');
        $ch = curl_init();
        curl_setopt($ch, CURLOPT_URL, PHPMYLICENSE_API . '/phpobfuscator/encode');
        curl_setopt($ch, CURLOPT_POST, count($fields));
        curl_setopt($ch, CURLOPT_POSTFIELDS, $fields_string);
        curl_setopt($ch, CURLOPT_RETURNTRANSFER, TRUE);
        $result = json_decode(curl_exec($ch), true);
        curl_close($ch);
        if ($result['status'] == 200) {
            $json['status'] = 200;
            $json['message']['header'] = 'Success!';
            $json['message']['text'] = 'Script obfuscated successfully!';
            $json['message']['type'] = 'success';
            $json['script'] = $result['script'];
            die(json_encode($json));
        } else if ($result['status'] == 301) {
            $json['status'] = 301;
            $json['message']['header'] = 'Oops!';
            $json['message']['text'] = 'Your purchase code is invalid.';
            $json['message']['type'] = 'error';
            die(json_encode($json));
        } else {
            $json['status'] = 500;
            $json['message']['header'] = 'Oops!';
            $json['message']['text'] = 'PHPMyLicense API Error. Contact the support.';
            $json['message']['type'] = 'error';
            die(json_encode($json));

        }*/
        $encoder = new PML_Obfuscator();
        $encoder->SetCode(base64_decode($script));
        $json['status'] = 200;
        $json['message']['header'] = 'Success!';
        $json['message']['text'] = 'Script obfuscated successfully!';
        $json['message']['type'] = 'success';
        $json['script'] = base64_encode($encoder->GetEncodedCode());
        die(json_encode($json));


    } else if ($handler == 'newproduct') {
        if(!$TOTP->validateCode($token))
        {
            $json['status'] = 401;
            $json['message']['header'] = 'Oops!';
            $json['message']['text'] = 'Invalid Token. Refresh the page and try again.';
            $json['message']['type'] = 'error';
            die(json_encode($json));
        }
        $fullname = $Gauntlet->filter($_REQUEST['fullname']);
        $shortname = $Gauntlet->filter($_REQUEST['shortname']);
        $sandbox = $Gauntlet->filter($_REQUEST['sandbox']);
        $ProductStripeId = $Gauntlet->filter($_REQUEST['ProductStripeId']);
        $trialtime = $Gauntlet->filter($_REQUEST['trialtime']);
        $added = time();
        if ($fullname == '' || $shortname == '' || $sandbox == '' || $trialtime == '' || $ProductStripeId == '') {
            $json['status'] = 500;
            $json['message']['header'] = 'Oops!';
            $json['message']['text'] = 'You need to input all values.';
            $json['message']['type'] = 'error';
            die(json_encode($json));
        }

        $sql = "INSERT INTO `products` (`fullname`, `shortname`, `added`, `sandbox`, `trialtime`,`stripe_product_id`) VALUES ('$fullname', '$shortname', '$added', '$sandbox', '$trialtime','$ProductStripeId');";
        //die(var_dump($sql));
        $query = $DatabaseHandler->query($sql);
        if ($query) {
            $json['status'] = 200;
            $json['message']['header'] = 'Success!';
            $json['message']['text'] = 'Product inserted successfully!';
            $json['message']['type'] = 'success';
            die(json_encode($json));
        } else {
            $json['status'] = 500;
            $json['message']['header'] = 'Oops!';
            $json['message']['text'] = 'Error in Database.';
            $json['message']['type'] = 'error';
            die(json_encode($json));
        }
    } else if ($handler == 'genclass') {
        if(!$TOTP->validateCode($token))
        {
            $json['status'] = 401;
            $json['message']['header'] = 'Oops!';
            $json['message']['text'] = 'Invalid Token. Refresh the page and try again.';
            $json['message']['type'] = 'error';
            die(json_encode($json));
        }
        $productid = $Gauntlet->filter($_REQUEST['productid']);
        $expired_html = file_get_contents('../api/tpl/license_expired.tpl');


        $class_content = "
        \$domain=\$_SERVER['SERVER_NAME'];
        \$product=\"$productid\";
        \$licenseServer = \"" . BASE_URL . "/api/\";

        \$postvalue=\"domain=\$domain&product=\".urlencode(\$product);

        \$ch = curl_init();
        curl_setopt(\$ch,CURLOPT_RETURNTRANSFER, 1);
        curl_setopt(\$ch, CURLOPT_URL, \$licenseServer);
        curl_setopt(\$ch, CURLOPT_POST, true);
        curl_setopt(\$ch, CURLOPT_POSTFIELDS, \$postvalue);
        \$result= json_decode(curl_exec(\$ch), true);
        curl_close(\$ch);

        if(\$result['status'] != 200) {
            \$html = \"" . $expired_html . "\";
            \$search = '<%returnmessage%>';
            \$replace = \$result['message'];
            \$html = str_replace(\$search, \$replace, \$html);


            die( \$html );

        }
        ?>";

        $comment = "<?php /**
            * Unreal Security - PHPMyLicense Check Class v2.5.0
            *
            * PHP version > 5
            *
            * LICENSE: This source file is subject to version 3.01 of the PHP license
            * that is available through the world-wide-web at the following URI:
            * http://www.php.net/license/3_01.txt.  If you did not receive a copy of
            * the PHP License and are unable to obtain it through the web, please
            * send a note to license@php.net so we can mail you a copy immediately.
            *
            * @package    PHPMyLicense
            * @author     Giovanne Oliveira <jhollsantos@gmail.com>
            * @copyright  2009 - 2015 PHPMyLicense
            * @license    http://www.php.net/license/3_01.txt  PHP License 3.01
            * @version    v3.0.0
            * @link       https://phpmylicense.com */
        ";

        $code = base64_encode($comment . $class_content);
        $json['status'] = 200;
        $json['message']['header'] = 'Success!';
        $json['message']['text'] = 'Class Generated Successfully!';
        $json['message']['type'] = 'success';
        $json['class'] = $code;
        die(json_encode($json));
    } else if ($handler == 'editproduct') {
        if(!$TOTP->validateCode($token))
        {
            $json['status'] = 401;
            $json['message']['header'] = 'Oops!';
            $json['message']['text'] = 'Invalid Token. Refresh the page and try again.';
            $json['message']['type'] = 'error';
            die(json_encode($json));
        }
        $fullname = $Gauntlet->filter($_REQUEST['fullname']);
        $shortname = $Gauntlet->filter($_REQUEST['shortname']);
        $sandbox = $Gauntlet->filter($_REQUEST['sandbox']);
        $trialtime = $Gauntlet->filter($_REQUEST['trialtime']);
        $productid = $Gauntlet->filter($_REQUEST['id']);

        $sql = "UPDATE `products` SET `fullname`= '$fullname',`shortname`= '$shortname',`sandbox`= '$sandbox',`trialtime`= '$trialtime' WHERE `id` = '$productid'";
        $query = $DatabaseHandler->query($sql);
        if ($query) {
            $json['status'] = 200;
            $json['message']['header'] = 'Success!';
            $json['message']['text'] = 'Product updated successfully!';
            $json['message']['type'] = 'success';
            die(json_encode($json));
        } else {
            $json['status'] = 500;
            $json['message']['header'] = 'Oops!';
            $json['message']['text'] = 'Error in Database.';
            $json['message']['type'] = 'error';
            die(json_encode($json));
        }

    } else if ($handler == 'changepwd') {
        if(!$TOTP->validateCode($token))
        {
            $json['status'] = 401;
            $json['message']['header'] = 'Oops!';
            $json['message']['text'] = 'Invalid Token. Refresh the page and try again.';
            $json['message']['type'] = 'error';
            die(json_encode($json));
        }
        $actual = hash('sha256', $_REQUEST['oldpass']);
        $newpwd = hash('sha256', $_REQUEST['newpass']);
        $newpwd2 = hash('sha256', $_REQUEST['newpass2']);

        if ($newpwd <> $newpwd2) {
            $json['status'] = 500;
            $json['message']['header'] = 'Oops!';
            $json['message']['text'] = 'The password and the confirm don\'t match.';
            $json['message']['type'] = 'error';
            die(json_encode($json));
        }
        $username = $_SESSION['username'];

        $sql = "SELECT password FROM users WHERE username = '$username'";
        $query = $DatabaseHandler->query($sql);
        if (!$query) {
            $json['status'] = 500;
            $json['message']['header'] = 'Oops!';
            $json['message']['text'] = 'Error in Database.';
            $json['message']['type'] = 'error';
            die(json_encode($json));
        }
        $data = $query->fetch_array();
        if ($data['password'] <> $actual) {
            $json['status'] = 500;
            $json['message']['header'] = 'Oops!';
            $json['message']['text'] = 'The old password don\'t match.';
            $json['message']['type'] = 'error';
            die(json_encode($json));
        }

        $sql = "UPDATE users SET password = '$newpwd' WHERE username = '$username'";
        $query = $DatabaseHandler->query($sql);
        if ($query) {
            session_destroy();
            $json['status'] = 200;
            $json['message']['header'] = 'Success!';
            $json['message']['text'] = 'Password updated successfully.';
            $json['message']['type'] = 'success';
            die(json_encode($json));
        } else {
            $json['status'] = 500;
            $json['message']['header'] = 'Oops!';
            $json['message']['text'] = 'Error in Database.';
            $json['message']['type'] = 'error';
            die(json_encode($json));
        }
    } else if ($handler == 'updatesettings') {
        if(!$TOTP->validateCode($token))
        {
            $json['status'] = 401;
            $json['message']['header'] = 'Oops!';
            $json['message']['text'] = 'Invalid Token. Refresh the page and try again.';
            $json['message']['type'] = 'error';
            die(json_encode($json));
        }
        $serialmask = $Gauntlet->filter($_REQUEST['serialmask']);
        $returnvalue = $Gauntlet->filter($_REQUEST['returndata']);
        $encryption_key = $Gauntlet->filter($_REQUEST['encryption_key']);
        $returnencrypted = $Gauntlet->filter($_REQUEST['returnencrypted']);
        $updatechannel = $Gauntlet->filter($_REQUEST['updatechannel']);
        $signresponse = $Gauntlet->filter($_REQUEST['signresponse']);
        $signaturetype = $Gauntlet->filter($_REQUEST['signaturetype']);


        if($updatechannel == 'beta')
        {
            $apiquery = PHPMYLICENSE_API.'/update/checkbetastatus?purchasecode='.$purchasecode;
            $apiquery = file_get_contents($apiquery);
            $apiresponse = json_decode($apiquery);

            if($apiresponse->beta <> true)
            {
                $json['status'] = 401;
                $json['message']['header'] = 'Oops!';
                $json['message']['text'] = 'You are not a beta tester, so, you can\'t use Beta Update Channel.';
                $json['message']['type'] = 'error';
                die(json_encode($json));
            }
        }
        if($updatechannel == 'internal')
        {
            $json['status'] = 401;
            $json['message']['header'] = 'Oops!';
            $json['message']['text'] = 'Missing your employee ID and access key into config file. <br><br> Your IP don\'t seems to be registered as Employee IP or PHPMySecurity Internal IPs';
            $json['message']['type'] = 'error';
            die(json_encode($json));
        }
        $sql = "SELECT configurations FROM settings";
        $query = $DatabaseHandler->query($sql);
        $data = $query->fetch_array();
        $data = json_decode($data['configurations'], true);
        $data['serialmask'] = $serialmask;
        $data['returndata'] = $returnvalue;
        $data['encryption_key'] = $encryption_key;
        $data['return_encrypted'] = $returnencrypted;
        $data['signresponse'] = $signresponse;
        $data['signaturetype'] = $signaturetype;
        $data['updatechannel'] = $updatechannel;
        $data = json_encode($data);

        $sql = "UPDATE settings SET configurations = '$data'";
        $query = $DatabaseHandler->query($sql);
        if ($query) {
            $json['status'] = 200;
            $json['message']['header'] = 'Success!';
            $json['message']['text'] = 'Settings updated successfully.';
            $json['message']['type'] = 'success';
            die(json_encode($json));
        } else {
            $json['status'] = 500;
            $json['message']['header'] = 'Oops!';
            $json['message']['text'] = 'Error in Database.';
            $json['message']['type'] = 'error';
            die(json_encode($json));
        }


    } else if ($handler == 'checkforupdates') {
        if(!$TOTP->validateCode($token))
        {
            $json['status'] = 401;
            $json['message']['header'] = 'Oops!';
            $json['message']['text'] = 'Invalid Token. Refresh the page and try again.';
            $json['message']['type'] = 'error';
            die(json_encode($json));
        }

        //$channel = $Gauntlet->filter($_REQUEST['channel']);

        $sql = "SELECT purchasecode FROM settings";
        $query = $DatabaseHandler->query($sql);
        $data = $query->fetch_array();
        $purchasecode = $data['purchasecode'];

        $response = json_decode(file_get_contents(PHPMYLICENSE_API . '/update/latest?purchasecode=' . $purchasecode));

        if ($response->latestversion > PRODUCT_VERSION) {

            $json['status'] = 200;
            $json['newversion'] = $response->latestversion;
            die(json_encode($json));
        } else {
            $json['status'] = 203;
            $json['message']['header'] = 'Updater';
            $json['message']['text'] = 'You are using the latest verson';
            $json['message']['type'] = 'info';
            die(json_encode($json));
        }

    } else if($handler == 'installupdate') {
        if(!$TOTP->validateCode($token))
        {
            $json['status'] = 401;
            $json['message']['header'] = 'Oops!';
            $json['message']['text'] = 'Invalid Token. Refresh the page and try again.';
            $json['message']['type'] = 'error';
            die(json_encode($json));
        }

        $update = $Gauntlet->filter($_REQUEST['update']);
        $filename = md5(microtime());

        $file = '../system/temp/'.$filename.'.zip';
        $return = json_decode(file_get_contents(PHPMYLICENSE_UPDATESERVICE.'/?purchasecode='.$purchasecode.'&channel='.PRODUCT_UPDATECHANNEL.'&version='.$update.'&act=getpackage'));
        if($return->status <> 200)
        {
            $json['status'] = $return->status;
            $json['message']['header'] = 'Updater';
            $json['message']['text'] = $return->message;
            $json['message']['type'] = 'warning';
            die(json_encode($json));
        }

        $dltoken = $return->dltoken;


        $Tools->downloadFile(PHPMYLICENSE_UPDATESERVICE.'/dl.php?token='.$dltoken, $file);

        $filestream = file_get_contents($file);
        $original = mb_substr($filestream, 0, -32);
        file_put_contents($file, $original);
        $md5 = substr($filestream, -32, 32);
        $checksum = md5_file($file);
        if($checksum == $md5)
        {
            $json['status'] = 200;
            $json['installurl'] = BASE_URL.'/installzip.php?f='.$RevAlgo->EncryptAndEncode($filename);
            die(json_encode($json));
        }else{
            //@unlink($file);
            $json['status'] = 500;
            $json['message']['header'] = 'Oops!';
            $json['message']['text'] = 'Error while checking the package signature. Please, try again.';
            $json['message']['type'] = 'error';
            die(json_encode($json));
        }


    } else if($handler == 'encodejs')
    {
        /*if(!$TOTP->validateCode($token))
        {
            $json['status'] = 401;
            $json['message']['header'] = 'Oops!';
            $json['message']['text'] = 'Invalid Token. Refresh the page and try again.';
            $json['message']['type'] = 'error';
            die(json_encode($json));
        }
        $jscode = $_REQUEST['jscode'];

        $apiquery = file_get_contents(PHPMYLICENSE_API.'/jsobfuscator/encode?code='.$jscode.'&purchasecode='.$purchasecode);

        $apiresponse = json_decode($apiquery, true);
        if($apiresponse['status'] == 200)
        {
            $json['status'] = 200;
            $json['jscode'] = $apiresponse['code'];
            die(json_encode($json));
        }else{
            $json['status'] = 500;
            $json['message']['header'] = 'Oops!';
            $json['message']['text'] = $apiresponse['error'];
            $json['message']['type'] = 'error';
            die(json_encode($json));

        }*/

        $json['status'] = 404;
        $json['message']['header'] = 'Oops!';
        $json['message']['text'] = 'This resource is no more avaiable.';
        $json['message']['type'] = 'error';
        die(json_encode($json));


    }else if($handler == 'resetpwd')
    {
        if(!isset($_REQUEST['email']))
        {
            $json['status'] = 404;
            $json['message']['header'] = 'Oops!';
            $json['message']['text'] = 'Missing parameters.';
            $json['message']['type'] = 'error';
            die(json_encode($json));
        }
        if($configurations['mail']['active'] <> true)
        {
            $json['status'] = 500;
            $json['message']['header'] = 'Oops!';
            $json['message']['text'] = 'Function disabled by admin.';
            $json['message']['type'] = 'error';
            die(json_encode($json));
        }

        $email = $_REQUEST['email'];

        $sql = "SELECT name, email FROM users WHERE email = '$email'";
        $query = $DatabaseHandler->query($sql);
        if(!$query)
        {
            $json['status'] = 500;
            $json['message']['header'] = 'Oops!';
            $json['message']['text'] = 'Database Error.';
            $json['message']['type'] = 'error';
            die(json_encode($json));
        }
        if($query->num_rows < 1)
        {
            $json['status'] = 500;
            $json['message']['header'] = 'Oops!';
            $json['message']['text'] = 'User not found.';
            $json['message']['type'] = 'error';
            die(json_encode($json));
        }

        $userdata = $query->fetch_array();

        $newpwd = $Tools->generatePassword(16);
        $newpwd_hash = hash('sha256', $newpwd);
        $sql = "UPDATE users SET password = '$newpwd_hash' WHERE email = '$email'";
        $query = $DatabaseHandler->query($sql);
        if(!$query)
        {
            $json['status'] = 500;
            $json['message']['header'] = 'Oops!';
            $json['message']['text'] = 'Database Error.';
            $json['message']['type'] = 'error';
            die(json_encode($json));
        }

        $mail = new PHPMailer();
        $body = file_get_contents('../system/libs/resetpwdmail.tpl');
        $search = array('{$name}', '{$newpwd}');
        $replace = array($userdata['name'], $newpwd);
        $body = str_replace($search, $replace, $body);
        $mail->IsSMTP(); // telling the class to use SMTP
        $mail->SMTPDebug  = 0;                     // enables SMTP debug information (for testing)
        // 1 = errors and messages
        // 2 = messages only
        $mail->SMTPAuth   = true;                  // enable SMTP authentication

        switch($configurations['mail']['smtp_security'])
        {
            case 'none':
            break;
            case 'ssl':
            $mail->SMTPSecure = 'ssl';
            break;
            case 'tls':
            $mail->SMTPSecure = 'tls';
            break;
            default:
            break;

        }
        $mail->Timeout  =   20;
        $mail->CharSet = 'UTF-8';
        $mail->setFrom($configurations['mail']['smtp_sender']);
        $mail->Host       = $configurations['mail']['smtp_host']; // sets the SMTP server
        $mail->Port       = $configurations['mail']['smtp_port'];                    // set the SMTP port for the GMAIL server
        $mail->Username   = $configurations['mail']['smtp_user']; // SMTP account username
        $mail->Password   = $configurations['mail']['smtp_pass'];        // SMTP account password
        $mail->FromName = "PHPMyLicense Mailer";
        $mail->AddAddress($email);
        $mail->IsHTML(true);
        $mail->Subject  = "Password Recovery";
        $mail->Body = $body;
        $sended = $mail->Send();

        $mail->ClearAllRecipients();
        $mail->ClearAttachments();

        if($sended)
        {
            $json['status'] = 200;
            $json['message']['header'] = 'Yay!';
            $json['message']['text'] = 'Check your email! Your new password will be there.';
            $json['message']['type'] = 'success';
            die(json_encode($json));
        }else{
            $json['status'] = 500;
            $json['message']['header'] = 'Oops!';
            $json['message']['text'] = 'Error!! '.$mail->ErrorInfo;
            $json['message']['type'] = 'error';
            die(json_encode($json));
        }
    }

    else if($handler == 'backupdb')
    {
        /*if(!$TOTP->validateCode($token))
        {
            $json['status'] = 401;
            $json['message']['header'] = 'Oops!';
            $json['message']['text'] = 'Invalid Token. Refresh the page and try again.';
            $json['message']['type'] = 'error';
            die(json_encode($json));
        }*/

        $para = array(
            'db_to_backup' => $Database['data'], //database name
            'db_exclude_tables' => array('ignore') //tables to exclude
            );

        $dump = $Tools->BackupDB($DatabaseHandler, $para);
        $time = time();
        file_put_contents('../system/temp/dbdump.sql', $dump);

        $zip = new ZipArchive;
        $res = $zip->open('../system/temp/backup_'.$time.'.zip', ZipArchive::CREATE);
        if ($res === TRUE) {
            $zip->addFile('../system/temp/dbdump.sql', '/dbdump.sql');
            $zip->addEmptyDir('system');
            $zip->addFile('../system/config.php', '/system/config.php');
            $zip->addFile('../system/cryptoconfig.php', '/system/cryptoconfig.php');

            if($zip->close())
            {
                $json['status'] = 200;
                $json['message']['header'] = 'Yay!';
                $json['message']['text'] = 'Backup Complete!';
                $json['message']['type'] = 'success';
                $json['message']['url'] = '';
                die(json_encode($json));
            }
        } else {
            $json['status'] = 500;
            $json['message']['header'] = 'Oops!';
            $json['message']['text'] = 'Error while packing your backup. Try again.';
            $json['message']['type'] = 'error';
            die(json_encode($json));
        }



    }else if($handler == 'updatemailsettings') {


        if(!$TOTP->validateCode($token))
        {
            $json['status'] = 401;
            $json['message']['header'] = 'Oops!';
            $json['message']['text'] = 'Invalid Token. Refresh the page and try again.';
            $json['message']['type'] = 'error';
            die(json_encode($json));
        }
        $smtp_enabled = $Gauntlet->filter($_REQUEST['smtp_enabled']);
        $smtp_user = $Gauntlet->filter($_REQUEST['smtp_user']);
        $smtp_pass = $Gauntlet->filter($_REQUEST['smtp_pass']);
        $smtp_host = $Gauntlet->filter($_REQUEST['smtp_host']);
        $smtp_port = $Gauntlet->filter($_REQUEST['smtp_port']);
        $smtp_sender = $Gauntlet->filter($_REQUEST['smtp_sender']);
        $smtp_security = $Gauntlet->filter($_REQUEST['smtp_security']);

        $sql = "SELECT configurations FROM settings";
        $query = $DatabaseHandler->query($sql);
        $data = $query->fetch_array();
        $data = json_decode($data['configurations'], true);
        $data['mail']['active'] = $smtp_enabled;
        $data['mail']['smtp_host'] = $smtp_host;
        $data['mail']['smtp_user'] = $smtp_user;
        $data['mail']['smtp_pass'] = $smtp_pass;
        $data['mail']['smtp_port'] = $smtp_port;
        $data['mail']['smtp_sender'] = $smtp_sender;
        $data['mail']['smtp_security'] = $smtp_security;
        $data = json_encode($data);

        $sql = "UPDATE settings SET configurations = '$data'";
        $query = $DatabaseHandler->query($sql);
        if ($query) {
            $json['status'] = 200;
            $json['message']['header'] = 'Success!';
            $json['message']['text'] = 'Settings updated successfully.';
            $json['message']['type'] = 'success';
            die(json_encode($json));
        } else {
            $json['status'] = 500;
            $json['message']['header'] = 'Oops!';
            $json['message']['text'] = 'Error in Database.';
            $json['message']['type'] = 'error';
            die(json_encode($json));
        }


    }else{
        $json['status'] = 404;
        $json['message']['header'] = 'Oops!';
        $json['message']['text'] = 'Unknown operation.';
        $json['message']['type'] = 'error';
        die(json_encode($json));
    }
}