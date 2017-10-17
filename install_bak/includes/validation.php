<?php
/**
* Validation class
*/
class Validation extends Validation_Core
{
	// These function are part of the default $steps array to help you
	// illustrate how this script works. Feel free to delete them.

	function validate_license($value, $params = array())
	{
        /*$product = "VW5yZWFsTGljZW5zaW5nIHYyIC0gQWR2YW5jZWQgUEhQIExpY2Vuc2luZyBTeXN0ZW0=";
		$result = file_get_contents('http://api.unreal-security.ga/envato/envato.php?purchase_code='.$value.'&product='.$product);
		if ( $result <> 1 ) {
			return false;
		}
		return true;*/

		$result = json_decode(file_get_contents('http://api.phpmylicense.ml/v1/envato/verifypurchase?purchasecode='.$value), true);
		if($result['valid'] <> true)
		{
			return false;
		}else{
			return true;
		}
	}

	function validate_system_path($value, $params = array())
	{
		if ( !is_file(rtrim($value, '/').'/system/config.php') || !is_writable(rtrim($value, '/').'/system/config.php') ) {
			$this->error = rtrim($value, '/').'/system/config.php file does not exist or is not writeable.';
			return false;
		}

		return true;
	}
}
