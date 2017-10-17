<?php
// phpinfo();



 //create a new cURL resource handle
$ch = curl_init();

    $domain = $_SERVER['SERVER_NAME'];;
   // $domain = 'http://licensemanager.dealopia.com';
   $license_domain = 'http://licensemanager.stpi.com/demowebsite/index.php';
 //  $domain = $_SERVER['SERVER_NAME']; // application domain
    $product_id = $_REQUEST['product_id'];
   // $ip_address = '192.168.1.123';
    $uuid = "";

    // Now set some options (most are optional)
    //$Url = 'http://licensemanager.stpi.com/api/?domain=http://licensemanager.stpi.com/demowebsite/index.php&product=1';

   echo $Url = $domain.'/api/?licensekey=PML-UB77-S270-8W56-H9O1&product_id='.$product_id.'&uuid=';
   //echo $Url = $domain.'/api/?domain='.$license_domain.'&product='.$product_id;
   // Set URL to download
    curl_setopt($ch, CURLOPT_URL, $Url);

    // Set a referer
    // curl_setopt($ch, CURLOPT_REFERER, "http://licensemanager.stpi.com/api/?domain=http://licensemanager.stpi.com/demowebsite/index.php&product=1");

    // User agent
    curl_setopt($ch, CURLOPT_USERAGENT, "MozillaXYZ/1.0");

    // Should cURL return or print out the data? (true = return, false = print)
    curl_setopt($ch, CURLOPT_RETURNTRANSFER, true);

    // Timeout in seconds
    // curl_setopt($ch, CURLOPT_TIMEOUT, 10);

    // Download the given URL, and return output
    $output = curl_exec($ch);
   // echo '<br><br>API response: '.$output.'<br><br>';
    $result= json_decode(curl_exec($ch), true);
   // echo '<pre>'; print_r($result);
    // Close the cURL resource, and free system resources
    curl_close($ch);

    if($result['status'] != 200) {

        $search = '<%returnmessage%>';
        $replace = $result['message'];

        $html = str_replace($search, $replace, $html);
        $html = "<div align='center'>
        <table width='100%' border='0' style='padding:15px; border-color:#F00; border-style:solid; background-color:#FF6C70; font-family:Tahoma, Geneva, sans-serif; font-size:22px; color:white;'>
        <tr>
        <td><b>You don't have permission to use this product. <br>The message from server is: <%returnmessage%> <br > Contact the product developer.</b></td >
        </tr>
        </table>

        </div>";
        $search = '<%returnmessage%>';
        $replace = $result['message'];
        $html = str_replace($search, $replace, $html);

            die( $html );

    }
    ?>
