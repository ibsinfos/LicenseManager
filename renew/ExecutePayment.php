<?php
/**
 * User: jhollsoliver
 * Date: 7/24/16
 * Time: 12:04 PM
 */
include_once('../system/autoloader.php');
//include_once('paypal-sdk/autoload.php');
include_once ('paypal-sdk/paypal/rest-api-sdk-php/sample/bootstrap.php');

use PayPal\Api\Amount;
use PayPal\Api\Details;
use PayPal\Api\ExecutePayment;
use PayPal\Api\Payment;
use PayPal\Api\PaymentExecution;
use PayPal\Api\Transaction;

if (isset($_GET['success']) && $_GET['success'] == 'true' && isset($_REQUEST['tid'])) {

    $transaction_guid = $_REQUEST['tid'];
    $paymentId = $_GET['paymentId'];
    $payment = Payment::get($paymentId, $apiContext);
    $payerid = $_GET['PayerID'];
    $sql = "UPDATE renew_transactions SET payerid = '$payerid' WHERE guid = '$transaction_guid'";
    $query = $DatabaseHandler->query($sql);
    if (!$query) {
        $json['status'] = 500;
        $json['message']['header'] = 'Oops!';
        $json['message']['text'] = 'Database Error';
        $json['message']['type'] = 'error';
        die(json_encode($json));
    }


    $execution = new PaymentExecution();
    $execution->setPayerId($_GET['PayerID']);


    $transaction = new Transaction();
    $amount = new Amount();
    $details = new Details();


    $amount->setCurrency('USD');
    $amount->setTotal(50);
    $amount->setDetails($details);
    $transaction->setAmount($amount);

    $execution->addTransaction($transaction);

    try {
        $result = $payment->execute($execution, $apiContext);

        try {
            $payment = Payment::get($paymentId, $apiContext);
            $transactionid = $payment->getId();
            $status = $payment->getState();
            $now = time();
            $fullresponse = base64_encode($result->toJSON());
            $sql = "UPDATE renew_transactions SET status = '$status', return_timestamp = '$now', transactionid = '$transactionid', payerid = '$payerid', rawjson = '$fullresponse' WHERE guid = '$transaction_guid'";
            $query = $DatabaseHandler->query($sql);
            if($query)
            {
                $sql = "SELECT licenseid FROM renew_transactions WHERE guid = '$transaction_guid'";
                $query = $DatabaseHandler->query($sql);
                if(!$query)
                {
                    echo 'Error while fetching your license data';
                }

                if($query->num_rows < 1)
                {
                    echo 'License not found';
                }

                $data = $query->fetch_array();
                $licensekey = $data['licenseid'];
                $newexpirydate = strtotime("+ 1 year");
                $sql = "UPDATE licenses SET status = 'active', expirydate = '$newexpirydate' WHERE licensekey = '$licensekey'";
                $query = $DatabaseHandler->query($sql);
                if($query)
                {
                    echo 'License updated!';
                    header("Location: success.php?tid=".$transaction_guid);
                }else{
                    echo 'SQL Error - Stage 2';
                }
            }else{
                echo 'SQL Error';
            }
        } catch (Exception $ex) {
            ResultPrinter::printError("Get Payment", "Payment", null, null, $ex);
            exit(1);
        }
    } catch (Exception $ex) {
        ResultPrinter::printError("Executed Payment", "Payment", null, null, $ex);
        exit(1);
    }
}