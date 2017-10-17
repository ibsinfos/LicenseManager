<?php
/**
 * User: jhollsoliver
 * Date: 7/20/16
 * Time: 9:26 AM
 */

include_once('../system/autoloader.php');
//include_once('paypal-sdk/autoload.php');
include_once ('paypal-sdk/paypal/rest-api-sdk-php/sample/bootstrap.php');

use PayPal\Api\Amount;
use PayPal\Api\Details;
use PayPal\Api\Item;
use PayPal\Api\ItemList;
use PayPal\Api\Payer;
use PayPal\Api\Payment;
use PayPal\Api\RedirectUrls;
use PayPal\Api\Transaction;




$_REQUEST = FilterClass::filterXSS($_REQUEST);

if(isset($_REQUEST['handler']))
{
    $handler = $_REQUEST['handler'];

    if($handler == 'searchlicense')
    {
        if(!isset($_REQUEST['licensekey']) || !isset($_REQUEST['customer_email']))
        {
            $json['status'] = 401;
            $json['message']['header'] = 'Oops!';
            $json['message']['text'] = 'Missing parameters';
            $json['message']['type'] = 'error';
            die(json_encode($json));
        }

        $licensekey = $_REQUEST['licensekey'];
        $customer_email = $_REQUEST['customer_email'];

        $sql = "SELECT * FROM licenses WHERE customer_email = '$customer_email' AND licensekey = '$licensekey'";
        $query = $DatabaseHandler->query($sql);
        if($query)
        {
            if($query->num_rows > 0)
            {
                $data = $query->fetch_array();

                $json['status'] = 200;
                $json['message']['header'] = 'Ok!';
                $json['message']['text'] = 'Licenses found';
                $json['message']['type'] = 'success';
                $json['license']['host'] = $data['host'];
                $json['license']['expirydate'] = date("F j, Y", $data['expirydate']);
                $pid = $data['productid'];
                $sql2 = "SELECT shortname FROM products WHERE id = '$pid'";
                $query2 = $DatabaseHandler->query($sql2);
                $data2 = $query2->fetch_array();
                $json['license']['product'] = $data2['shortname'];
                $json['license']['status'] = $data['status'];
                $json['license']['customer_email'] = $data['customer_email'];
                $json['license']['renewcycle'] = 'Annual';
                $json['license']['price'] = '50';
                $json['license']['currency'] = 'USD';
                $json['license']['id'] = $data['id'];
                die(json_encode($json));

            }else{
                $json['status'] = 404;
                $json['message']['header'] = 'Oops!';
                $json['message']['text'] = 'License not found';
                $json['message']['type'] = 'error';
                die(json_encode($json));
            }

        }else{
            $json['status'] = 500;
            $json['message']['header'] = 'Oops!';
            $json['message']['text'] = 'Database Error';
            $json['message']['type'] = 'error';
            die(json_encode($json));
        }
    }elseif($handler == 'processrenew')
    {
        if(!isset($_REQUEST['licensekey']))
        {
            $json['status'] = 401;
            $json['message']['header'] = 'Oops!';
            $json['message']['text'] = 'Missing parameters';
            $json['message']['type'] = 'error';
            die(json_encode($json));
        }

        $licensekey = $_REQUEST['licensekey'];

        $sql = "SELECT * FROM licenses WHERE licensekey = '$licensekey'";
        $query = $DatabaseHandler->query($sql);
        if($query)
        {
            if($query->num_rows > 0)
            {
                $data = $query->fetch_array();
                $pid = $data['productid'];
                $sql2 = "SELECT shortname FROM products WHERE id = '$pid'";
                $query2 = $DatabaseHandler->query($sql2);
                $data2 = $query2->fetch_array();
                $productname = $data2['shortname'];

                $payer = new Payer();
                $payer->setPaymentMethod("paypal");

                $item1 = new Item();
                $item1->setName($productname.' - License')
                    ->setCurrency('USD')
                    ->setQuantity(1)
                    ->setSku("1424") // Similar to `item_number` in Classic API
                    ->setPrice(50);

                $itemList = new ItemList();
                $itemList->setItems(array($item1));

                $details = new Details();
                $details->setShipping(0)
                    ->setTax(0)
                    ->setSubtotal(50);

                $amount = new Amount();
                $amount->setCurrency("USD")
                    ->setTotal(50)
                    ->setDetails($details);

                $transaction = new Transaction();
                $transaction->setAmount($amount)
                    ->setItemList($itemList)
                    ->setDescription("License Payment")
                    ->setInvoiceNumber(uniqid());

//                $baseUrl = getBaseUrl();
                $baseUrl = 'http://dev.phpmylicense.ml/renew';
                $redirectUrls = new RedirectUrls();
                $OperationGUID = $Tools->create_guid();
                $redirectUrls->setReturnUrl("$baseUrl/ExecutePayment.php?success=true&tid=".$OperationGUID)
                    ->setCancelUrl("$baseUrl/ExecutePayment.php?success=false&tid=".$OperationGUID);

                $payment = new Payment();
                $payment->setIntent("sale")
                    ->setPayer($payer)
                    ->setRedirectUrls($redirectUrls)
                    ->setTransactions(array($transaction));
                $request = clone $payment;

                try {
                    $payment->create($apiContext);
                } catch (Exception $ex) {
                    $json['status'] = 500;
                    $json['message']['header'] = 'Oops!';
                    $json['message']['text'] = 'PayPal Error: '.$ex->getMessage();
                    $json['message']['type'] = 'error';
                    die(json_encode($json));
                }
                $now = time();
                $state = $payment->getState();
                $sql = "INSERT INTO `renew_transactions`(`guid`, `licenseid`, `created_timestamp`, `return_timestamp`, `status`, `transactionid`, `payerid`) VALUES ('$OperationGUID','$licensekey','$now',NULL,'$state',NULL,NULL)";
                $query = $DatabaseHandler->query($sql);
                if(!$query)
                {
                    $json['status'] = 500;
                    $json['message']['header'] = 'Oops!';
                    $json['message']['text'] = 'PayPal processed your request, but some issue happened with our backend. You can complete the purchase, but, maybe you will need some help.';
                    $json['message']['type'] = 'warning';
                    $approvalUrl = $payment->getApprovalLink();
                    $json['redirecturl'] = $approvalUrl;
                    die(json_encode($json));
                }else{
                    $approvalUrl = $payment->getApprovalLink();
                    $json['status'] = 200;
                    $json['redirecturl'] = $approvalUrl;
                    die(json_encode($json));
                }



            }else{
                $json['status'] = 404;
                $json['message']['header'] = 'Oops!';
                $json['message']['text'] = 'License not found';
                $json['message']['type'] = 'error';
                die(json_encode($json));
            }

        }else{
            $json['status'] = 500;
            $json['message']['header'] = 'Oops!';
            $json['message']['text'] = 'Database Error';
            $json['message']['type'] = 'error';
            die(json_encode($json));
        }
    }

}