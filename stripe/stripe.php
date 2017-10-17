	<?php
	error_reporting(E_ALL); 
	require_once('vendor/autoload.php');
	require_once('init.php');
	include_once '../system/autoloader.php';
	include_once '../system/libs/PHPMailer-master/PHPMailerAutoload.php';

	//phpinfo();
	$server_name = $_SERVER['SERVER_NAME'];
	$count = "";
	$to = "";
	$customer_email = "";
	$date = date("Y-M-d");
	$expiry_date = strtotime(date("Y-M-d", strtotime($date)) . "+1 month");
	$domain = "";
	$productid = "";
	$comments = "one month license";
	$parameters = "monthly";
	$expirydate = $expiry_date;
	$status = "active";
	// $productid = "1";
	$userid = "1";

	/* DB connection details */

	$hostname = "localhost";
	$username = "root";
	$DBpassword = "m2n1shlko";			/* password for Dealopia server DB */
	//$DBpassword = "m2n1shlko@1250";   /* password for Cient server DB */
	$DBname = "licensemanager";
	

	\Stripe\Stripe::setApiKey("sk_test_1lWBfNNuBsAJIpTmBx63kyyD");
	$res =\Stripe\Charge::all(array("limit" => 1));

	$input = @file_get_contents("php://input");

	$res_new = str_replace('Stripe\Collection JSON:','',$res);

	$date = date("Y-M-d h:i:s");
	$expiry_date = strtotime(date("Y-M-d h:i:s", strtotime($date)) . "+1 month");

	$decoded_val = json_decode($res_new);
	$trans_id = $decoded_val->data[0]->balance_transaction;
	$charge_id = $decoded_val->data[0]->id;
	$customer_id = $decoded_val->data[0]->customer;
	$invoice_id = $decoded_val->data[0]->invoice;

	if(!empty($customer_id)){

		$cus_res = \Stripe\Customer::retrieve($customer_id);
		$cus_res_new = str_replace('Stripe\Customer JSON:','',$cus_res);
		if(!empty($cus_res_new)){

			$decoded_cust_details = json_decode($cus_res_new);
			if(!empty($decoded_cust_details)){

				$customer_email = $decoded_cust_details->email;
				$full_name = $decoded_cust_details->metadata->name;
				$first_name = $decoded_cust_details->metadata->first_name;
				$last_name = $decoded_cust_details->metadata->last_name;
			}
		}
	}

	if(!empty($invoice_id)){

		$invoice_res = \Stripe\Invoice::retrieve($invoice_id);
		$invoice_res_new = str_replace('Stripe\Invoice JSON:','',$invoice_res);
		
		if(!empty($invoice_res_new)){
			$decode_invoice_res = json_decode($invoice_res_new);

			if($charge_id==$decode_invoice_res->charge){

				$purchase_plan_id = $decode_invoice_res->lines->data[0]->plan->id;
				$purchase_plan_name = $decode_invoice_res->lines->data[0]->plan->name;
			}
		}
		
	}

	/*
	echo '<br><br>Invoice json data: <pre/>'.$invoice_res_new;
	echo '<br><br>customer data: <pre/>'.$cus_res_new;
	echo '<br><br>customer email id is: '.$customer_email;
	*/

	$link = mysql_connect($hostname, $username, $DBpassword);

	if (!$link) {
		die('<br>Could not connect: ' . mysql_error());
	}
	$db_selected = mysql_select_db($DBname, $link);

	$sql_check = "SELECT * FROM webhookdata WHERE charge_id='$charge_id' AND transaction_id='$trans_id'";
	$sql_res_check = mysql_query($sql_check);

	// if ($sql_res_check === TRUE) {
	// 	$count = mysql_num_rows($sql_res_check);
	// } else {
	// 	/* echo "Error: " . $sql_res . "<br>" .mysql_error(); */
	// }

	//echo 'num rows: '.$count = $sql_res->num_rows;

	if (mysql_num_rows($sql_res_check)===0){

// echo 'if';

		$sql = "SELECT configurations FROM settings";
		$query = $DatabaseHandler->query($sql);
		$data = $query->fetch_array();
		$configurations = json_decode($data['configurations'], true);

		$LicenseKey = $Tools->GenSerialByMask($configurations['serialmask']);

		$sql_product = "SELECT * FROM products WHERE stripe_product_id ='$purchase_plan_id'";
		$query_product = $DatabaseHandler->query($sql_product);
		$data_product = $query_product->fetch_array();
		$productid = $data_product['id'];

		$sql = "INSERT INTO webhookdata (webhook_data,transaction_id,charge_id,added_date)VALUES ('$res_new','$trans_id','$charge_id',now())";
		$sql_res_2 = mysql_query($sql);

		if($sql_res_2 === TRUE) {

			$sql_license = "INSERT INTO `licenses` (`host`, `licensekey`, `customer_email`, `expirydate`, `productid`,`product_purchase_stripe_id`, `status`, `issued-by`, `comments`, `parameters`) VALUES ('$domain', '$LicenseKey', '$customer_email', '$expirydate', '$productid','$purchase_plan_id', '$status', '1', '$comments', '$parameters');";      
			$query = mysql_query($sql_license);

			if($query === TRUE) {
				$current_date = date("Y-m-d H:i:s");
				$sql_ipaddress_tbl = "INSERT INTO `ipaddress` (`licensekey`, `added_time`) VALUES ('$LicenseKey','$current_date')";
				$query_ipaddress = mysql_query($sql_ipaddress_tbl);
				
				if($query_ipaddress === TRUE) {

					echo "<html><body><p style='font-size:20px;'> Thank you! <br> Your payment is successful!<br> A mail with license details has been sent to your ".$customer_email." email.</p></body></html>";

// --------------------------mail send code starts here--------------------------------------------

					$mail = new PHPMailer;
					$mail->isMail();
					/* $mail->isSMTP(); */                                     
					$mail->Host = $configurations['mail']['smtp_host'];  
					$mail->SMTPAuth = true;                          
					$mail->Username = $configurations['mail']['smtp_user'];        
					$mail->Password = $configurations['mail']['smtp_pass'];       
					$mail->SMTPSecure = $configurations['mail']['smtp_security'];                       
					$mail->Port = $configurations['mail']['smtp_port'];                               
					$mail->isHTML(true);   
					$mail->Priority = 1; 
					if($purchase_plan_id=="mock_page"){
						$rediect_link = $server_name."/MockPageInstaller.rar";
					}else{
						$rediect_link = $server_name."/FBLeadBankProInstaller.rar";
					}

					$to = $customer_email;
					$mail->setFrom($configurations['mail']['smtp_sender'], $configurations['mail']['smtp_user']);

					/* Send Email to user */
					$mail->addAddress($customer_email,$full_name);
					/* send email to admin */
					$mail->addReplyTo($configurations['mail']['smtp_sender'], $configurations['mail']['smtp_user']);

					$mail->Subject = 'License Payment';

					/* Compose a simple HTML email message */
					// $message = '<html><body>';
					// $message .= '<h4 style="color:#000000;"> Hello '.ucfirst($first_name).',</h4>';
					// $message .= '<p style="font-size:15px;">Please find your license Details below : <p> <b>License key </b>: '.$LicenseKey.'</b><br><b> Product Name </b>: '.$purchase_plan_name.'<br> <b> Product Id</b> : '.$purchase_plan_id.'</p><br>Please refer this link: <a href="'.$rediect_link.'">Click here to download Application</a></p><p>Thank You for Purchasing!</br></p>';
					// $message .= '</body></html>';

					$message = '<html><body>';
					$message .= '<h4 style="color:#000000;"> Hello '.ucfirst($first_name).',</h4>';
					$message .= '<p>Thank You for Purchasing '.$purchase_plan_name.' .<br> Here’s your license key and access.</p>';
					$message .= '<p> <b>License key </b>: '.$LicenseKey.'</b><br><b> Product Name </b>: '.$purchase_plan_name.'<br> <b> Product Id</b> : '.$purchase_plan_id.'</p>';
					$message .= '<p>Keep this information in a safe place as you will need to reference it to access '.$purchase_plan_name.'</p>';
					$message .= '<p style="font-size:15px;"> Download '.$purchase_plan_name .'by click link below: <br><a href="'.$rediect_link.'">Click here to download Application</a></p>';
					$message .= '<p style="font-size:15px;">Should require any assistance with '.$purchase_plan_name.'<br> Please contact support at: <a href="mailto:support@leadbankpro.com" target="_top">support@leadbankpro.com</a></p>';
					$message .= '</body></html>';


					$mail->Body  = $message;

					if(!$mail->send()) {
						/* echo 'Message could not be sent.'; */
						echo 'Mailer Error: ' . $mail->ErrorInfo;
					}

// --------------------------mail send code ends here--------------------------------------------

				}else {
					echo "Error: " . $query . "<br>" .mysql_error();
				}
			}else {
				echo "Error: " . $query_ipaddress . "<br>" .mysql_error();
			}
		} else {
			echo "Error: " . $sql_res_2 . "<br>" .mysql_error();
		}

	}else {
		
		echo "<html><body><p style='font-size:20px;'> Page does not exist! </p></body></html>";
	}
	
	//header("Location: https://phillip-kasik.clickfunnels.com/thank-you-page16cgzdlk");
	mysql_close($link);
	exit();
	?>