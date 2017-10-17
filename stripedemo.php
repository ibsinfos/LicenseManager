<?php 


require_once('vendor/autoload.php');

\Stripe\Stripe::setApiKey('sk_test_BQokikJOvBiI2HlWgH4olfQ2');
$charge = \Stripe\Charge::create(array('amount' => 2000, 'currency' => 'usd', 'source' => 'tok_189fqt2eZvKYlo2CTGBeg6Uq' ));
echo $charge;

?>
