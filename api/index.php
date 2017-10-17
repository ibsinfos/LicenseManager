<?php
/**
 * Unreal Studio
 * Project: UnrealLicensing
 * User: jhollsoliver
 * Date: 06/06/15
 * Time: 10:31
 */

include_once '../system/autoloader.php';
$sql = "SELECT configurations FROM settings";
$query = $DatabaseHandler->query($sql);
$data = $query->fetch_array();
$configurations = json_decode($data['configurations'], true);
if(isset($_REQUEST['licensekey']))
{
    $licensekey = $Gauntlet->filter($_REQUEST['licensekey']);
    
    if($_REQUEST['licensekey']=="" || empty($_REQUEST['licensekey'])){

        $json['status'] = 301;
        $json['message'] = 'Invalid License Key';

        if($configurations['signresponse'] == 'true')
        {
            $SignatureHandler->FormatJsonSignature($json);
        }
        if($configurations['return_encrypted'] == 'true')
        {
            $key = $configurations['encryption_key'];
            $encrypted = $Tools->encryptRJ256($key, json_encode($json));
            die($encrypted);
        }else{
            die(json_encode($json));
        }

    }else{
        $licensekey = $Gauntlet->filter($_REQUEST['licensekey']);
    }

// request code for product id param

    if(isset($_REQUEST['product_id']))
    {
        $productId = $Gauntlet->filter($_REQUEST['product_id']);

    // request code for uuid param.

        if(isset($_REQUEST['uuid']))
        {
          
            if($_REQUEST['uuid']=="" || empty($_REQUEST['uuid'])){

                $json['status'] = 301;
                $json['message'] = 'Invalid Unique Key';

                if($configurations['signresponse'] == 'true')
                {
                    $SignatureHandler->FormatJsonSignature($json);
                }
                if($configurations['return_encrypted'] == 'true')
                {
                    $key = $configurations['encryption_key'];
                    $encrypted = $Tools->encryptRJ256($key, json_encode($json));
                    die($encrypted);
                }else{
                    die(json_encode($json));
                }
            }else{
                 $uuid = $Gauntlet->filter($_REQUEST['uuid']);
            }

        }else{

            $uuid = "";

            $productId = 0;

            $json['status'] = 301;
            $json['message'] = 'Invalid Unique Key';

            if($configurations['signresponse'] == 'true')
            {
                $SignatureHandler->FormatJsonSignature($json);
            }
            if($configurations['return_encrypted'] == 'true')
            {
                $key = $configurations['encryption_key'];
                $encrypted = $Tools->encryptRJ256($key, json_encode($json));
                die($encrypted);
            }else{
                die(json_encode($json));
            }
        }

    }else{

        $productId = 0;

        $json['status'] = 301;
        $json['message'] = 'Invalid Product Id';

        if($configurations['signresponse'] == 'true')
        {
            $SignatureHandler->FormatJsonSignature($json);
        }
        if($configurations['return_encrypted'] == 'true')
        {
            $key = $configurations['encryption_key'];
            $encrypted = $Tools->encryptRJ256($key, json_encode($json));
            die($encrypted);
        }else{
            die(json_encode($json));
        }
    }


    $sql = "SELECT * FROM licenses WHERE licensekey = '$licensekey' AND product_purchase_stripe_id = '$productId'";
    $query = $DatabaseHandler->query($sql);
    if($query->num_rows < 1)
    {

        $sql_check_productId = "SELECT * FROM licenses WHERE licensekey = '$licensekey'";
        $query_check_productId = $DatabaseHandler->query($sql_check_productId);
        if($query_check_productId->num_rows < 1)
        {
            if (!isset($_REQUEST['product_id'])){
                $json['status'] = 301;
                $json['message'] = 'Invalid Product Id';
            }else{
                $json['status'] = 301;
                $json['message'] = 'Invalid License Key';
            }
        }else{
            $json['status'] = 301;
            $json['message'] = 'Invalid Product Id';
        }
        if($configurations['signresponse'] == 'true')
        {
            $SignatureHandler->FormatJsonSignature($json);
        }
        if($configurations['return_encrypted'] == 'true')
        {
            $key = $configurations['encryption_key'];
            $encrypted = $Tools->encryptRJ256($key, json_encode($json));
            die($encrypted);
        }else{
            die(json_encode($json));
        }

    }else{

        $data = $query->fetch_array();

        $sql_get_host_entries = "SELECT * FROM ipaddress WHERE licensekey = '$licensekey'";
        $query_get_host_entries = $DatabaseHandler->query($sql_get_host_entries);

        if($query_get_host_entries->num_rows < 1){

            /* code to update host in DB. 
            /check for ip count and then insert ip address code starts here */
            
            if($data['ip_count']>0){

                $current_date = date("Y-m-d H:i:s");
            //$sql = "UPDATE ipaddress SET host_ipaddress = '$uuid,', status = '$current_date' WHERE licensekey = '$licensekey'";
               echo $sql = "INSERT INTO `ipaddress` (`licensekey`, `host_ipaddress`, `added_time`) VALUES ('$licensekey','$uuid','$current_date')";
                $query = $DatabaseHandler->query($sql);

                if($query)
                {
                    $json['status'] = 200;
                    $json['message'] = 'License activated Successfully for '.$uuid.' Unique Key!';
                    if($configurations['return_encrypted'] == 'true')
                    {
                        $key = $configurations['encryption_key'];
                        $encrypted = $Tools->encryptRJ256($key, json_encode($json));
                        die($encrypted);
                    }else{
                        die(json_encode($json));
                    }
                }else{
                    $json['status'] = 500;
                    $json['message'] = 'Database Error. Try again.';
                    if($configurations['return_encrypted'] == 'true')
                    {
                        $key = $configurations['encryption_key'];
                        $encrypted = $Tools->encryptRJ256($key, json_encode($json));
                        die($encrypted);
                    }else{
                        die(json_encode($json));
                    }
                }

            }else{

             $json['status'] = 401;
             $json['message'] = 'Unique Key cannot be Registered.Please contact Admin!';

             if($configurations['signresponse'] == 'true')
             {
                $SignatureHandler->FormatJsonSignature($json);
            }
            if($configurations['return_encrypted'] == 'true')
            {
                $key = $configurations['encryption_key'];
                $encrypted = $Tools->encryptRJ256($key, json_encode($json));
                die($encrypted);
            }else{
                die(json_encode($json));
            }
        }
        /* check for ip count and then insert ip address code ends here */


    }else{

        while ($row_host_data = $query_get_host_entries->fetch_array())
        {
            $uuid_array[] = $row_host_data['host_ipaddress'];
        }
        $uuid_array_count = count($uuid_array);

        if(isset($_REQUEST['uuid']))
        {          
            if(in_array($_REQUEST['uuid'], $uuid_array))
            {        
                $now = strtotime(date("Y-M-d", strtotime(date("Y-M-d"))));
                switch($data['status'])
                {
                    case 'active':
                    if($data['expirydate'] >= $now)  /* license expiry if */
                    { 

                        $json['status'] = 200;
                        $json['message'] = 'License is valid.';
                        if(isset($licensedata['parameters']) && $licensedata['parameters'] <> '')
                        {
                            $parameters = $data['parameters'];
                            parse_str($parameters, $parameters);
                            $json['parameters'] = $parameters;
                        }
                        if($configurations['returndata'] == 'true')
                        {
                            $json['licensedata']['domain'] = $_REQUEST['uuid'];
                            $json['licensedata']['customer_email'] = $data['customer_email'];
                            $json['licensedata']['licensekey'] = $data['licensekey'];
                            $json['licensedata']['expirydate'] = $data['expirydate'];
                            $json['licensedata']['issued-by'] = $data['issued-by'];
                            $json['licensedata']['comments'] = $data['comments'];
                        }
                        if($configurations['signresponse'] == 'true')
                        {
                            $json = $SignatureHandler->FormatJsonSignature($json);
                            switch($configurations['signaturetype'])
                            {
                                case 'sha1':
                                $json['signature'] = sha1($json['signature']);
                                $json['signaturetype'] = 'sha1';
                                break;
                                case 'md5':
                                $json['signature'] = md5($json['signature']);
                                $json['signaturetype'] = 'md5';
                                break;
                                case 'raw':
                                default:
                                $json['signature'] = $json['signature'];
                                $json['signaturetype'] = 'raw_base64';
                                break;
                            }
                        }
                        if($configurations['return_encrypted'] == 'true')
                        {
                            $key = $configurations['encryption_key'];
                            $key = $configurations['encryption_key'];
                            $encrypted = $Tools->encryptRJ256($key, json_encode($json));
                            die($encrypted);
                        }else{
                            die(json_encode($json));
                        }
                    }else{  /* license expiry else start */

                        $json['status'] = 301;
                        $json['message'] = 'Your license is expired.Please contact Admin!';
                        if($configurations['signresponse'] == 'true')
                        {
                            $SignatureHandler->FormatJsonSignature($json);
                        }
                        if($configurations['return_encrypted'] == 'true')
                        {
                            $key = $configurations['encryption_key'];
                            $encrypted = $Tools->encryptRJ256($key, json_encode($json));
                            die($encrypted);
                        }else{
                            die(json_encode($json));
                        }
                    }  /* license expiry else end */
                    break;   
                }  /* switch case end */

            }else{

                if($data['ip_count'] > $uuid_array_count){

                    $current_date = date("Y-m-d H:i:s");

                    $sql = "INSERT INTO `ipaddress` (`licensekey`, `host_ipaddress`, `added_time`) VALUES ('$licensekey','$uuid','$current_date')";
                    $query = $DatabaseHandler->query($sql);

                    if($query)
                    {
                        $json['status'] = 200;
                        $json['message'] = 'License activated Successfully for '.$uuid.' Unique Key!';
                        if($configurations['return_encrypted'] == 'true')
                        {
                            $key = $configurations['encryption_key'];
                            $encrypted = $Tools->encryptRJ256($key, json_encode($json));
                            die($encrypted);
                        }else{
                            die(json_encode($json));
                        }
                    }else{
                        $json['status'] = 500;
                        $json['message'] = 'Database Error. Try again.';
                        if($configurations['return_encrypted'] == 'true')
                        {
                            $key = $configurations['encryption_key'];
                            $encrypted = $Tools->encryptRJ256($key, json_encode($json));
                            die($encrypted);
                        }else{
                            die(json_encode($json));
                        }
                    }
                }else{

                    $json['status'] = 401;
                    $json['message'] = 'Unique Key Cannot be Registered.Please contact Admin!';

                    if($configurations['signresponse'] == 'true')
                    {
                        $SignatureHandler->FormatJsonSignature($json);
                    }
                    if($configurations['return_encrypted'] == 'true')
                    {
                        $key = $configurations['encryption_key'];
                        $encrypted = $Tools->encryptRJ256($key, json_encode($json));
                        die($encrypted);
                    }else{
                        die(json_encode($json));
                    }
                }

            }     
        }
    } 
} /*else tag end*/

}else{

    $json['status'] = 301;
    $json['message'] = 'Invalid License key';

    if($configurations['signresponse'] == 'true')
    {
        $SignatureHandler->FormatJsonSignature($json);
    }
    if($configurations['return_encrypted'] == 'true')
    {
        $key = $configurations['encryption_key'];
        $encrypted = $Tools->encryptRJ256($key, json_encode($json));
        die($encrypted);
    }else{
        die(json_encode($json));
    }
}

/* end of request license key code */

if(isset($_REQUEST['domain']))
{
    $domain = $Gauntlet->filter($_REQUEST['domain']);
    if(isset($_REQUEST['product']))
    {
        $product = $Gauntlet->filter($_REQUEST['product']);
    }else{
        $product = 0;
    }

    if (strpos($domain, "www.") === 0) {
        $URL1 = $domain;
        $URL2 = preg_replace("/www./", "", $domain, 1);
    } else {
        $URL1 = $domain;
        $URL2 = "www." . $domain;
    }
    $now = time();

    $sql = "SELECT trialtime, sandbox FROM products WHERE id = '$product'";
    @$query = $DatabaseHandler->query($sql);
    $productdata = $query->fetch_array();

    if($productdata['sandbox'] == true)
    {
        $json['status'] = 200;
        $json['message'] = 'License is valid by Sandbox.';
        if($configurations['returndata'] == 'true')
        {
            $json['licensedata']['domain'] = $licensedata['host'];
            $json['licensedata']['customer_email'] = $licensedata['customer_email'];
            $json['licensedata']['licensekey'] = $licensedata['licensekey'];
            $json['licensedata']['expirydate'] = $licensedata['expirydate'];
            $json['licensedata']['issued-by'] = $licensedata['issued-by'];
            $json['licensedata']['comments'] = $licensedata['comments'];
        }
        if($configurations['return_encrypted'] == 'true')
        {
            $key = $configurations['encryption_key'];
            $encrypted = $Tools->encryptRJ256($key, json_encode($json));
            die($encrypted);
        }else{
            die(json_encode($json));
        }
    }

    //$sql = "SELECT id FROM licenses WHERE expirydate > '$now' AND host = '$URL1' OR '$URL2' AND productid = '$product' AND status = 'ACTIVE'";
    $sql = "SELECT * FROM licenses WHERE productid = '$product' AND host IN ('$URL1', '$URL2')";
    @$query = $DatabaseHandler->query($sql);
    if($query)
    {
        if($query->num_rows > 0)
        {
            $licensedata = $query->fetch_array();
            if($licensedata['status'] == 'active')
            {
                if($licensedata['expirydate'] > $now)
                {
                    $json['status'] = 200;
                    $json['message'] = 'License is valid.';
                    if(isset($licensedata['parameters']) && $licensedata['parameters'] <> '')
                    {
                        $parameters = $licensedata['parameters'];
                        parse_str($parameters, $parameters);
                        $json['parameters'] = $parameters;
                    }
                    if($configurations['returndata'] == 'true')
                    {
                        $json['licensedata']['domain'] = $licensedata['host'];
                        $json['licensedata']['customer_email'] = $licensedata['customer_email'];
                        $json['licensedata']['licensekey'] = $licensedata['licensekey'];
                        $json['licensedata']['expirydate'] = $licensedata['expirydate'];
                        $json['licensedata']['issued-by'] = $licensedata['issued-by'];
                        $json['licensedata']['comments'] = $licensedata['comments'];
                    }
                    if($configurations['signresponse'] == 'true')
                    {
                        $json = $SignatureHandler->FormatJsonSignature($json);
                        switch($configurations['signaturetype'])
                        {
                            case 'sha1':
                            $json['signature'] = sha1($json['signature']);
                            $json['signaturetype'] = 'sha1';
                            break;
                            case 'md5':
                            $json['signature'] = md5($json['signature']);
                            $json['signaturetype'] = 'md5';
                            break;
                            case 'raw':
                            default:
                            $json['signature'] = $json['signature'];
                            $json['signaturetype'] = 'raw_base64';
                            break;
                        }
                    }
                    if($configurations['return_encrypted'] == 'true')
                    {
                        $key = $configurations['encryption_key'];
                        $key = $configurations['encryption_key'];
                        $encrypted = $Tools->encryptRJ256($key, json_encode($json));
                        die($encrypted);
                    }else{
                        die(json_encode($json));
                    }


                }else{
                    $json['status'] = 301;
                    $json['message'] = 'Your license is expired';
                    if($configurations['returndata'] == 'true')
                    {
                        $json['licensedata']['domain'] = $licensedata['host'];
                        $json['licensedata']['customer_email'] = $licensedata['customer_email'];
                        $json['licensedata']['licensekey'] = $licensedata['licensekey'];
                        $json['licensedata']['expirydate'] = $licensedata['expirydate'];
                        $json['licensedata']['issued-by'] = $licensedata['issued-by'];
                        $json['licensedata']['comments'] = $licensedata['comments'];
                    }
                    if($configurations['signresponse'] == 'true')
                    {
                        $json = $SignatureHandler->FormatJsonSignature($json);
                        switch($configurations['signaturetype'])
                        {
                            case 'sha1':
                            $json['signature'] = sha1($json['signature']);
                            $json['signaturetype'] = 'sha1';
                            break;
                            case 'md5':
                            $json['signature'] = md5($json['signature']);
                            $json['signaturetype'] = 'md5';
                            break;
                            case 'raw':
                            default:
                            $json['signature'] = $json['signature'];
                            $json['signaturetype'] = 'raw_base64';
                            break;
                        }
                    }
                    if($configurations['return_encrypted'] == 'true')
                    {
                        $key = $configurations['encryption_key'];
                        $key = $configurations['encryption_key'];
                        $encrypted = $Tools->encryptRJ256($key, json_encode($json));
                        die($encrypted);
                    }else{
                        die(json_encode($json));
                    }
                }
            }else{
                switch($licensedata['status'])
                {
                    case 'inactive':
                    $json['status'] = 301;
                    $json['message'] = 'Your license is inactive. Maybe, you need to activate it.';
                    if($configurations['returndata'] == 'true')
                    {
                        $json['licensedata']['domain'] = $licensedata['host'];
                        $json['licensedata']['customer_email'] = $licensedata['customer_email'];
                        $json['licensedata']['licensekey'] = $licensedata['licensekey'];
                        $json['licensedata']['expirydate'] = $licensedata['expirydate'];
                        $json['licensedata']['issued-by'] = $licensedata['issued-by'];
                        $json['licensedata']['comments'] = $licensedata['comments'];
                    }
                    if($configurations['signresponse'] == 'true')
                    {
                        $json = $SignatureHandler->FormatJsonSignature($json);
                        switch($configurations['signaturetype'])
                        {
                            case 'sha1':
                            $json['signature'] = sha1($json['signature']);
                            $json['signaturetype'] = 'sha1';
                            break;
                            case 'md5':
                            $json['signature'] = md5($json['signature']);
                            $json['signaturetype'] = 'md5';
                            break;
                            case 'raw':
                            default:
                            $json['signature'] = $json['signature'];
                            $json['signaturetype'] = 'raw_base64';
                            break;
                        }
                    }
                    if($configurations['return_encrypted'] == 'true')
                    {
                        $key = $configurations['encryption_key'];
                        $key = $configurations['encryption_key'];
                        $encrypted = $Tools->encryptRJ256($key, json_encode($json));
                        die($encrypted);
                    }else{
                        die(json_encode($json));
                    }
                    break;
                    case 'processing':
                    $json['status'] = 301;
                    $json['message'] = 'Your license is in processing status. Wait some time and try again.';
                    if($configurations['returndata'] == 'true')
                    {
                        $json['licensedata']['domain'] = $licensedata['host'];
                        $json['licensedata']['customer_email'] = $licensedata['customer_email'];
                        $json['licensedata']['licensekey'] = $licensedata['licensekey'];
                        $json['licensedata']['expirydate'] = $licensedata['expirydate'];
                        $json['licensedata']['issued-by'] = $licensedata['issued-by'];
                        $json['licensedata']['comments'] = $licensedata['comments'];
                    }
                    if($configurations['signresponse'] == 'true')
                    {
                        $json = $SignatureHandler->FormatJsonSignature($json);
                        switch($configurations['signaturetype'])
                        {
                            case 'sha1':
                            $json['signature'] = sha1($json['signature']);
                            $json['signaturetype'] = 'sha1';
                            break;
                            case 'md5':
                            $json['signature'] = md5($json['signature']);
                            $json['signaturetype'] = 'md5';
                            break;
                            case 'raw':
                            default:
                            $json['signature'] = $json['signature'];
                            $json['signaturetype'] = 'raw_base64';
                            break;
                        }
                    }
                    if($configurations['return_encrypted'] == 'true')
                    {
                        $key = $configurations['encryption_key'];
                        $key = $configurations['encryption_key'];
                        $encrypted = $Tools->encryptRJ256($key, json_encode($json));
                        die($encrypted);
                    }else{
                        die(json_encode($json));
                    }
                    break;
                    case 'suspended':
                    $json['status'] = 301;
                    $json['message'] = 'Your license is suspended. Contact the Administrator.';
                    if($configurations['returndata'] == 'true')
                    {
                        $json['licensedata']['domain'] = $licensedata['host'];
                        $json['licensedata']['customer_email'] = $licensedata['customer_email'];
                        $json['licensedata']['licensekey'] = $licensedata['licensekey'];
                        $json['licensedata']['expirydate'] = $licensedata['expirydate'];
                        $json['licensedata']['issued-by'] = $licensedata['issued-by'];
                        $json['licensedata']['comments'] = $licensedata['comments'];
                    }
                    if($configurations['signresponse'] == 'true')
                    {
                        $json = $SignatureHandler->FormatJsonSignature($json);
                        switch($configurations['signaturetype'])
                        {
                            case 'sha1':
                            $json['signature'] = sha1($json['signature']);
                            $json['signaturetype'] = 'sha1';
                            break;
                            case 'md5':
                            $json['signature'] = md5($json['signature']);
                            $json['signaturetype'] = 'md5';
                            break;
                            case 'raw':
                            default:
                            $json['signature'] = $json['signature'];
                            $json['signaturetype'] = 'raw_base64';
                            break;
                        }
                    }
                    if($configurations['return_encrypted'] == 'true')
                    {
                        $key = $configurations['encryption_key'];
                        $key = $configurations['encryption_key'];
                        $encrypted = $Tools->encryptRJ256($key, json_encode($json));
                        die($encrypted);
                    }else{
                        die(json_encode($json));
                    }
                    break;
                    default:
                    $json['status'] = 301;
                    $json['message'] = 'Your license is inactive. Maybe, you need to activate it.';
                    if($configurations['returndata'] == 'true')
                    {
                        $json['licensedata']['domain'] = $licensedata['host'];
                        $json['licensedata']['customer_email'] = $licensedata['customer_email'];
                        $json['licensedata']['licensekey'] = $licensedata['licensekey'];
                        $json['licensedata']['expirydate'] = $licensedata['expirydate'];
                        $json['licensedata']['issued-by'] = $licensedata['issued-by'];
                        $json['licensedata']['comments'] = $licensedata['comments'];
                    }
                    if($configurations['signresponse'] == 'true')
                    {
                        $json = $SignatureHandler->FormatJsonSignature($json);
                        switch($configurations['signaturetype'])
                        {
                            case 'sha1':
                            $json['signature'] = sha1($json['signature']);
                            $json['signaturetype'] = 'sha1';
                            break;
                            case 'md5':
                            $json['signature'] = md5($json['signature']);
                            $json['signaturetype'] = 'md5';
                            break;
                            case 'raw':
                            default:
                            $json['signature'] = $json['signature'];
                            $json['signaturetype'] = 'raw_base64';
                            break;
                        }
                    }
                    if($configurations['return_encrypted'] == 'true')
                    {
                        $key = $configurations['encryption_key'];
                        $key = $configurations['encryption_key'];
                        $encrypted = $Tools->encryptRJ256($key, json_encode($json));
                        die($encrypted);
                    }else{
                        die(json_encode($json));
                    }
                    break;
                }
            }


        }else{
            if($productdata['trialtime'] > 0)
            {
                //$licensekey = $Tools->create_guid();
                $licensekey = $Tools->GenSerialByMask($configurations['serialmask']);
                $trialtime = $productdata['trialtime'];
                $expirydate = strtotime("+$trialtime days");
                $sql = "INSERT INTO `licenses`(`host`, `licensekey`, `customer_email`, `expirydate`, `productid`, `status`, `issued-by`, `comments`) VALUES ('$URL1','$licensekey','automatic@issuer.php','$expirydate','$product','active','1','Issued by Trial Time Automatic Setup')";
                @$query = $DatabaseHandler->query($sql);
                if($query)
                {
                    $json['status'] = 200;
                    $json['message'] = 'License in Trial.';
                    if($configurations['signresponse'] == 'true')
                    {
                        $json = $SignatureHandler->FormatJsonSignature($json);
                        switch($configurations['signaturetype'])
                        {
                            case 'sha1':
                            $json['signature'] = sha1($json['signature']);
                            $json['signaturetype'] = 'sha1';
                            break;
                            case 'md5':
                            $json['signature'] = md5($json['signature']);
                            $json['signaturetype'] = 'md5';
                            break;
                            case 'raw':
                            default:
                            $json['signature'] = $json['signature'];
                            $json['signaturetype'] = 'raw_base64';
                            break;
                        }
                    }
                    if($configurations['return_encrypted'] == 'true')
                    {
                        $key = $configurations['encryption_key'];
                        $key = $configurations['encryption_key'];
                        $encrypted = $Tools->encryptRJ256($key, json_encode($json));
                        die($encrypted);
                    }else{
                        die(json_encode($json));
                    }
                }else{
                    $json['status'] = 500;
                    $json['message'] = 'Error while setup your trial.';
                    if($configurations['signresponse'] == 'true')
                    {
                        $json = $SignatureHandler->FormatJsonSignature($json);
                        switch($configurations['signaturetype'])
                        {
                            case 'sha1':
                            $json['signature'] = sha1($json['signature']);
                            $json['signaturetype'] = 'sha1';
                            break;
                            case 'md5':
                            $json['signature'] = md5($json['signature']);
                            $json['signaturetype'] = 'md5';
                            break;
                            case 'raw':
                            default:
                            $json['signature'] = $json['signature'];
                            $json['signaturetype'] = 'raw_base64';
                            break;
                        }
                    }
                    if($configurations['return_encrypted'] == 'true')
                    {
                        $key = $configurations['encryption_key'];
                        $encrypted = $Tools->encryptRJ256($key, json_encode($json));
                        die($encrypted);
                    }else{
                        die(json_encode($json));
                    }
                }
            }else{
                $json['status'] = 301;
                $json['message'] = 'License not Found';
                if($configurations['signresponse'] == 'true')
                {
                    $json = $SignatureHandler->FormatJsonSignature($json);
                    switch($configurations['signaturetype'])
                    {
                        case 'sha1':
                        $json['signature'] = sha1($json['signature']);
                        $json['signaturetype'] = 'sha1';
                        break;
                        case 'md5':
                        $json['signature'] = md5($json['signature']);
                        $json['signaturetype'] = 'md5';
                        break;
                        case 'raw':
                        default:
                        $json['signature'] = $json['signature'];
                        $json['signaturetype'] = 'raw_base64';
                        break;
                    }
                }
                if($configurations['return_encrypted'] == 'true')
                {
                    $key = $configurations['encryption_key'];
                    $encrypted = $Tools->encryptRJ256($key, json_encode($json));
                    die($encrypted);
                }else{
                    die(json_encode($json));
                }
            }
        }
    }
}

if(isset($_REQUEST['apikey']) && isset($_REQUEST['handler']) && isset($_REQUEST['parameters']))
{
    $apikey = $Gauntlet->filter($_REQUEST['apikey']);
    $handler = $Gauntlet->filter($_REQUEST['handler']);
    $parameters = $_REQUEST['parameters'];
    $parameters = json_decode($parameters, true);

    $sql = "SELECT * FROM apikeys WHERE apikey = '$apikey' AND status = 'active'";
    $query = $DatabaseHandler->query($sql);
    if($query)
    {
        if($query->num_rows < 1)
        {
            $json['status'] = 301;
            $json['message'] = 'Invalid API Key';
            if($configurations['signresponse'] == 'true')
            {
                $json = $SignatureHandler->FormatJsonSignature($json);
                switch($configurations['signaturetype'])
                {
                    case 'sha1':
                    $json['signature'] = sha1($json['signature']);
                    $json['signaturetype'] = 'sha1';
                    break;
                    case 'md5':
                    $json['signature'] = md5($json['signature']);
                    $json['signaturetype'] = 'md5';
                    break;
                    case 'raw':
                    default:
                    $json['signature'] = $json['signature'];
                    $json['signaturetype'] = 'raw_base64';
                    break;
                }
            }
            if($configurations['return_encrypted'] == 'true')
            {
                $key = $configurations['encryption_key'];
                $encrypted = $Tools->encryptRJ256($key, json_encode($json));
                die($encrypted);
            }else{
                die(json_encode($json));
            }
        }
        $apikey_data = $query->fetch_array();

        switch($handler){

           
                case 'changestatus':
                if($apikey_data['license_update_permission'] <> true)
                {
                    $json['status'] = 401;
                    $json['message'] = 'Permission denied.';
                    if($configurations['signresponse'] == 'true')
                    {
                        $json = $SignatureHandler->FormatJsonSignature($json);
                        switch($configurations['signaturetype'])
                        {
                            case 'sha1':
                            $json['signature'] = sha1($json['signature']);
                            $json['signaturetype'] = 'sha1';
                            break;
                            case 'md5':
                            $json['signature'] = md5($json['signature']);
                            $json['signaturetype'] = 'md5';
                            break;
                            case 'raw':
                            default:
                            $json['signature'] = $json['signature'];
                            $json['signaturetype'] = 'raw_base64';
                            break;
                        }
                    }
                    if($configurations['return_encrypted'] == 'true')
                    {
                        $key = $configurations['encryption_key'];
                        $encrypted = $Tools->encryptRJ256($key, json_encode($json));
                        die($encrypted);
                    }else{
                        die(json_encode($json));
                    }
                }
                if(!isset($parameters['domain']))
                {
                    $json['status'] = 500;
                    $json['message'] = 'Missing the Domain parameter. Try again.';
                    if($configurations['signresponse'] == 'true')
                    {
                        $json = $SignatureHandler->FormatJsonSignature($json);
                        switch($configurations['signaturetype'])
                        {
                            case 'sha1':
                            $json['signature'] = sha1($json['signature']);
                            $json['signaturetype'] = 'sha1';
                            break;
                            case 'md5':
                            $json['signature'] = md5($json['signature']);
                            $json['signaturetype'] = 'md5';
                            break;
                            case 'raw':
                            default:
                            $json['signature'] = $json['signature'];
                            $json['signaturetype'] = 'raw_base64';
                            break;
                        }
                    }
                    if($configurations['return_encrypted'] == 'true')
                    {
                        $key = $configurations['encryption_key'];
                        $encrypted = $Tools->encryptRJ256($key, json_encode($json));
                        die($encrypted);
                    }else{
                        die(json_encode($json));
                    }
                }
                if(!isset($parameters['status']))
                {
                    $json['status'] = 500;
                    $json['message'] = 'Missing the status parameter. Try again.';
                    if($configurations['signresponse'] == 'true')
                    {
                        $json = $SignatureHandler->FormatJsonSignature($json);
                        switch($configurations['signaturetype'])
                        {
                            case 'sha1':
                            $json['signature'] = sha1($json['signature']);
                            $json['signaturetype'] = 'sha1';
                            break;
                            case 'md5':
                            $json['signature'] = md5($json['signature']);
                            $json['signaturetype'] = 'md5';
                            break;
                            case 'raw':
                            default:
                            $json['signature'] = $json['signature'];
                            $json['signaturetype'] = 'raw_base64';
                            break;
                        }
                    }
                    if($configurations['return_encrypted'] == 'true')
                    {
                        $key = $configurations['encryption_key'];
                        $encrypted = $Tools->encryptRJ256($key, json_encode($json));
                        die($encrypted);
                    }else{
                        die(json_encode($json));
                    }
                }

                $host = $parameters['domain'];
                $sql = "SELECT status FROM licenses WHERE host = '$host'";
                $query = $DatabaseHandler->query($sql);
                if($query->num_rows < 1)
                {
                    $json['status'] = 500;
                    $json['message'] = 'No such domain.';
                    if($configurations['signresponse'] == 'true')
                    {
                        $json = $SignatureHandler->FormatJsonSignature($json);
                        switch($configurations['signaturetype'])
                        {
                            case 'sha1':
                            $json['signature'] = sha1($json['signature']);
                            $json['signaturetype'] = 'sha1';
                            break;
                            case 'md5':
                            $json['signature'] = md5($json['signature']);
                            $json['signaturetype'] = 'md5';
                            break;
                            case 'raw':
                            default:
                            $json['signature'] = $json['signature'];
                            $json['signaturetype'] = 'raw_base64';
                            break;
                        }
                    }
                    if($configurations['return_encrypted'] == 'true')
                    {
                        $key = $configurations['encryption_key'];
                        $encrypted = $Tools->encryptRJ256($key, json_encode($json));
                        die($encrypted);
                    }else{
                        die(json_encode($json));
                    }
                }
                $data = $query->fetch_array();

                switch($parameters['status'])
                {
                    case 'active':
                    case 'inactive':
                    case 'suspended':
                    case 'processing':
                    $status = $parameters['status'];
                    break;
                    default:
                    $json['status'] = 500;
                    $json['message'] = 'Unknown Status.';
                    if($configurations['signresponse'] == 'true')
                    {
                        $json = $SignatureHandler->FormatJsonSignature($json);
                        switch($configurations['signaturetype'])
                        {
                            case 'sha1':
                            $json['signature'] = sha1($json['signature']);
                            $json['signaturetype'] = 'sha1';
                            break;
                            case 'md5':
                            $json['signature'] = md5($json['signature']);
                            $json['signaturetype'] = 'md5';
                            break;
                            case 'raw':
                            default:
                            $json['signature'] = $json['signature'];
                            $json['signaturetype'] = 'raw_base64';
                            break;
                        }
                    }
                    if($configurations['return_encrypted'] == 'true')
                    {
                        $key = $configurations['encryption_key'];
                        $encrypted = $Tools->encryptRJ256($key, json_encode($json));
                        die($encrypted);
                    }else{
                        die(json_encode($json));
                    }
                    break;

                }

                $sql = "UPDATE licenses SET status = '$status' WHERE host = '$host'";
                $query = $DatabaseHandler->query($sql);
                if($query)
                {
                    $json['status'] = 200;
                    $json['message'] = 'Success!';
                    if($configurations['signresponse'] == 'true')
                    {
                        $json = $SignatureHandler->FormatJsonSignature($json);
                        switch($configurations['signaturetype'])
                        {
                            case 'sha1':
                            $json['signature'] = sha1($json['signature']);
                            $json['signaturetype'] = 'sha1';
                            break;
                            case 'md5':
                            $json['signature'] = md5($json['signature']);
                            $json['signaturetype'] = 'md5';
                            break;
                            case 'raw':
                            default:
                            $json['signature'] = $json['signature'];
                            $json['signaturetype'] = 'raw_base64';
                            break;
                        }
                    }
                    if($configurations['return_encrypted'] == 'true')
                    {
                        $key = $configurations['encryption_key'];
                        $encrypted = $Tools->encryptRJ256($key, json_encode($json));
                        die($encrypted);
                    }else{
                        die(json_encode($json));
                    }
                }else {
                    $json['status'] = 500;
                    $json['message'] = 'Error while executing the action.';
                    if($configurations['signresponse'] == 'true')
                    {
                        $json = $SignatureHandler->FormatJsonSignature($json);
                        switch($configurations['signaturetype'])
                        {
                            case 'sha1':
                            $json['signature'] = sha1($json['signature']);
                            $json['signaturetype'] = 'sha1';
                            break;
                            case 'md5':
                            $json['signature'] = md5($json['signature']);
                            $json['signaturetype'] = 'md5';
                            break;
                            case 'raw':
                            default:
                            $json['signature'] = $json['signature'];
                            $json['signaturetype'] = 'raw_base64';
                            break;
                        }
                    }
                    if ($configurations['return_encrypted'] == 'true') {
                        $key = $configurations['encryption_key'];
                        $encrypted = $Tools->encryptRJ256($key, json_encode($json));
                        die($encrypted);
                    } else {
                        die(json_encode($json));
                    }
                }


                break;

                case 'changeexpirydate':

                if(!isset($parameters['domain']))
                {
                    $json['status'] = 500;
                    $json['message'] = 'Missing the Domain parameter. Try again.';
                    if($configurations['signresponse'] == 'true')
                    {
                        $json = $SignatureHandler->FormatJsonSignature($json);
                        switch($configurations['signaturetype'])
                        {
                            case 'sha1':
                            $json['signature'] = sha1($json['signature']);
                            $json['signaturetype'] = 'sha1';
                            break;
                            case 'md5':
                            $json['signature'] = md5($json['signature']);
                            $json['signaturetype'] = 'md5';
                            break;
                            case 'raw':
                            default:
                            $json['signature'] = $json['signature'];
                            $json['signaturetype'] = 'raw_base64';
                            break;
                        }
                    }
                    if($configurations['return_encrypted'] == 'true')
                    {
                        $key = $configurations['encryption_key'];
                        $encrypted = $Tools->encryptRJ256($key, json_encode($json));
                        die($encrypted);
                    }else{
                        die(json_encode($json));
                    }
                }
                if(!isset($parameters['timestamp']))
                {
                    $json['status'] = 500;
                    $json['message'] = 'Missing the Timestamp parameter. Try again.';
                    if($configurations['signresponse'] == 'true')
                    {
                        $json = $SignatureHandler->FormatJsonSignature($json);
                        switch($configurations['signaturetype'])
                        {
                            case 'sha1':
                            $json['signature'] = sha1($json['signature']);
                            $json['signaturetype'] = 'sha1';
                            break;
                            case 'md5':
                            $json['signature'] = md5($json['signature']);
                            $json['signaturetype'] = 'md5';
                            break;
                            case 'raw':
                            default:
                            $json['signature'] = $json['signature'];
                            $json['signaturetype'] = 'raw_base64';
                            break;
                        }
                    }
                    if($configurations['return_encrypted'] == 'true')
                    {
                        $key = $configurations['encryption_key'];
                        $encrypted = $Tools->encryptRJ256($key, json_encode($json));
                        die($encrypted);
                    }else{
                        die(json_encode($json));
                    }
                }
                $host = $parameters['domain'];
                $sql = "SELECT expirydate FROM licenses WHERE host = '$host'";
                $query = $DatabaseHandler->query($sql);
                if($query->num_rows < 1)
                {
                    $json['status'] = 500;
                    $json['message'] = 'No such domain.';
                    if($configurations['signresponse'] == 'true')
                    {
                        $json = $SignatureHandler->FormatJsonSignature($json);
                        switch($configurations['signaturetype'])
                        {
                            case 'sha1':
                            $json['signature'] = sha1($json['signature']);
                            $json['signaturetype'] = 'sha1';
                            break;
                            case 'md5':
                            $json['signature'] = md5($json['signature']);
                            $json['signaturetype'] = 'md5';
                            break;
                            case 'raw':
                            default:
                            $json['signature'] = $json['signature'];
                            $json['signaturetype'] = 'raw_base64';
                            break;
                        }
                    }
                    if($configurations['return_encrypted'] == 'true')
                    {
                        $key = $configurations['encryption_key'];
                        $encrypted = $Tools->encryptRJ256($key, json_encode($json));
                        die($encrypted);
                    }else{
                        die(json_encode($json));
                    }
                }
                $data = $query->fetch_array();
                $timestamp = $parameters['timestamp'];
                if(!$Tools->is_timestamp($timestamp))
                {
                    $json['status'] = 500;
                    $json['message'] = 'Timestamp field is not an unix timestamp.';
                    if($configurations['signresponse'] == 'true')
                    {
                        $json = $SignatureHandler->FormatJsonSignature($json);
                        switch($configurations['signaturetype'])
                        {
                            case 'sha1':
                            $json['signature'] = sha1($json['signature']);
                            $json['signaturetype'] = 'sha1';
                            break;
                            case 'md5':
                            $json['signature'] = md5($json['signature']);
                            $json['signaturetype'] = 'md5';
                            break;
                            case 'raw':
                            default:
                            $json['signature'] = $json['signature'];
                            $json['signaturetype'] = 'raw_base64';
                            break;
                        }
                    }
                    if($configurations['return_encrypted'] == 'true')
                    {
                        $key = $configurations['encryption_key'];
                        $encrypted = $Tools->encryptRJ256($key, json_encode($json));
                        die($encrypted);
                    }else{
                        die(json_encode($json));
                    }
                }
                $sql = "UPDATE licenses SET expirydate = '$timestamp' WHERE host = '$host'";
                $query = $DatabaseHandler->query($sql);
                if($query)
                {
                    $json['status'] = 200;
                    $json['message'] = 'Success!';
                    if($configurations['signresponse'] == 'true')
                    {
                        $json = $SignatureHandler->FormatJsonSignature($json);
                        switch($configurations['signaturetype'])
                        {
                            case 'sha1':
                            $json['signature'] = sha1($json['signature']);
                            $json['signaturetype'] = 'sha1';
                            break;
                            case 'md5':
                            $json['signature'] = md5($json['signature']);
                            $json['signaturetype'] = 'md5';
                            break;
                            case 'raw':
                            default:
                            $json['signature'] = $json['signature'];
                            $json['signaturetype'] = 'raw_base64';
                            break;
                        }
                    }
                    if($configurations['return_encrypted'] == 'true')
                    {
                        $key = $configurations['encryption_key'];
                        $encrypted = $Tools->encryptRJ256($key, json_encode($json));
                        die($encrypted);
                    }else{
                        die(json_encode($json));
                    }
                }else{
                    $json['status'] = 500;
                    $json['message'] = 'Error while executing the action.';
                    if($configurations['signresponse'] == 'true')
                    {
                        $json = $SignatureHandler->FormatJsonSignature($json);
                        switch($configurations['signaturetype'])
                        {
                            case 'sha1':
                            $json['signature'] = sha1($json['signature']);
                            $json['signaturetype'] = 'sha1';
                            break;
                            case 'md5':
                            $json['signature'] = md5($json['signature']);
                            $json['signaturetype'] = 'md5';
                            break;
                            case 'raw':
                            default:
                            $json['signature'] = $json['signature'];
                            $json['signaturetype'] = 'raw_base64';
                            break;
                        }
                    }
                    if($configurations['return_encrypted'] == 'true')
                    {
                        $key = $configurations['encryption_key'];
                        $encrypted = $Tools->encryptRJ256($key, json_encode($json));
                        die($encrypted);
                    }else{
                        die(json_encode($json));
                    }
                }

                break;

                default:
                $json['status'] = 401;
                $json['message'] = 'Unknown Handler.';
                if($configurations['signresponse'] == 'true')
                {
                    $json = $SignatureHandler->FormatJsonSignature($json);
                    switch($configurations['signaturetype'])
                    {
                        case 'sha1':
                        $json['signature'] = sha1($json['signature']);
                        $json['signaturetype'] = 'sha1';
                        break;
                        case 'md5':
                        $json['signature'] = md5($json['signature']);
                        $json['signaturetype'] = 'md5';
                        break;
                        case 'raw':
                        default:
                        $json['signature'] = $json['signature'];
                        $json['signaturetype'] = 'raw_base64';
                        break;
                    }
                }
                if($configurations['return_encrypted'] == 'true')
                {
                    $key = $configurations['encryption_key'];
                    $encrypted = $Tools->encryptRJ256($key, json_encode($json));
                    die($encrypted);
                }else{
                    die(json_encode($json));
                }
                break;
            }

        }else{
            $json['status'] = 500;
            $json['message'] = 'Database Error';
            if($configurations['signresponse'] == 'true')
            {
                $json = $SignatureHandler->FormatJsonSignature($json);
                switch($configurations['signaturetype'])
                {
                    case 'sha1':
                    $json['signature'] = sha1($json['signature']);
                    $json['signaturetype'] = 'sha1';
                    break;
                    case 'md5':
                    $json['signature'] = md5($json['signature']);
                    $json['signaturetype'] = 'md5';
                    break;
                    case 'raw':
                    default:
                    $json['signature'] = $json['signature'];
                    $json['signaturetype'] = 'raw_base64';
                    break;
                }
            }
            if($configurations['return_encrypted'] == 'true')
            {
                $key = $configurations['encryption_key'];
                $encrypted = $Tools->encryptRJ256($key, json_encode($json));
                die($encrypted);
            }else{
                die(json_encode($json));
            }
        }
    }
