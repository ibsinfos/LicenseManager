<?php

/**
 * Project:     PHP Time One Time Password
 * File:        totp.class.php
 * Purpose:		Time based one time password for PHP
 * 
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 *
 * For questions, help, comments, discussion, etc., please send
 * e-mail to dragos@protung.ro
 *
 * @link http://www.protung.ro/
 * @copyright 2009 Dragos Protung
 * @author Dragos Protung <dragos@protung.ro>
 * @package PHP Time based One Time Password
 * @version 1.5a
 */

class TOTP {
	
	/**
	 * Default hash method 
	 *
	 */
	const DEFAULT_HASH = "sha1";
	
	/**
	 * Default value for how long the code will be valid
	 * Value is in seconds
	 * 
	 */
	const DEFAULT_EXPIRATION = 30;
	
	/**
	 * Default value for the number of digits in the code
	 *
	 */
	const DEFAULT_DIGITSNR = 7;
	
	/**
	 * Double digits
	 *
	 * @var array
	 */
	protected $doubleDigits = array (0 => "0", 1 => "2", 2 => "4", 3 => "6", 4 => "8", 5 => "1", 6 => "3", 7 => "5", 8 => "7", 9 => "9" );
	
	/**
	 * The secret key
	 *
	 * @var string
	 */
	protected $secretKey;
	
	/**
	 * Time of execution
	 *
	 * @var long
	 */
	protected $time;
	
	/**
	 * The expiration time of the code
	 *
	 * @var long
	 */
	protected $expiration;
	
	/**
	 * The number of digits in the code
	 *
	 * @var int
	 */
	protected $codeDigitsNr;
	
	/**
	 * Flag to add or not a checksum at the end of the code
	 *
	 * @var bool
	 */
	protected $addChecksum = false;
	
	/**
	 * Generated code
	 *
	 * @var string
	 */
	protected $generatedCode;
	
	/**
	 * Constructor
	 *
	 * @param string $secretKey
	 * @param int $expiration
	 * @param int $digits
	 * 
	 */
	public function __construct($secretKey = false, $expiration = false, $digits = false) {
		$this->time = time();
		$this->setSecretKey($secretKey);
		$this->setExpirationTime($expiration);
		$this->setDigitsNumber($digits);
	}
	
	/**
	 * Returns the timestamp used for creating the code
	 *
	 * @return long
	 */
	public function getTimeUsedInGeneration () {
		return $this->time;
	}
	
	/**
	 * Get the generated code
	 *
	 * @return string
	 */
	public function getGeneratedCode () {
		return $this->generatedCode;
	}
	
	/**
	 * Set the secret key
	 *
	 * @param string $secretKey - the secret key
	 * @return bool
	 */
	public function setSecretKey ($secretKey) {
		if ($secretKey) {
			$this->secretKey = $secretKey;
			return true; 
		} else {
			return false;
		}
	}
	
	/**
	 * Set the expiration time (in seconds) of a password
	 * The actual time is (at 'random' - time based) between the input expiration time and input expiration time + 50%
	 * For example: if $expiration=30 => $actualExpiration=[30,45]
	 * 
	 * If the expiration time is not valid will return false
	 * but it will set it to the default value 
	 *
	 * @param int $expiration
	 * @return bool
	 */
	public function setExpirationTime ($expiration = self::DEFAULT_EXPIRATION) {
		$expiration = (int)$expiration;
		if ($expiration > 0) {
			$this->expiration = $expiration;
			return true;
		} else {
			$this->expiration = self::DEFAULT_EXPIRATION;
			return false;
		}
	}
	
	/**
	 * Get the expiration time of the passwordd
	 *
	 * @return int
	 */
	public function getExpirationTime () {
		return $this->expiration;
	}
	
	/**
	 * Set the number of digits the code should have
	 * If it's less than 0 or bigger than 10 it defaults to self::DEFAULT_DIGITSNR
	 *
	 * @param int $digits - the number of digits the computed code shoud have
	 * @return bool
	 */
	public function setDigitsNumber ($digits = self::DEFAULT_DIGITSNR) {
		$digits = (int)$digits;
		if ($digits > 0 && $digits <= count($this->doubleDigits)) {
//		if ($digits > 0) {
			$this->codeDigitsNr = $digits;
			return true;
		} else {
			$this->codeDigitsNr = self::DEFAULT_DIGITSNR;
			return false;
		}
	}

	
	/**
	 * Set if it should add or not a checksum at the end of the code
	 *
	 * @param bool $addChecksum
	 */
	public function addChecksum ($addChecksum = false) {
		$this->addChecksum = (bool)$addChecksum;
	}
	
	/**
	 * Calculate the checksum of a result
	 *
	 * @param int $num - number
	 * @param int $digits - number of digits
	 * @return int
	 */
	public function calcChecksum($num, $digits) {
		$doubleDigit = true;
		$total = 0;
		while ($digits-- > 0) {
			$digit = (int)($num%10);
			$num /= 10;
			if ($doubleDigit) {
				$digit = $this->doubleDigits[$digit];
			}
			$total += $digit;
			$doubleDigit = !$doubleDigit;
		}
		return 10 - $total%10;
	}
	
	
	/**
	 * Generate a keyed hash value using the HMAC method
	 * For PHP < 5.1.2 @see otp_p512 class
	 *
	 * @param string $data - data to be hashed
	 * @param string $hashFunct - hash function to be used
	 * @param bool $rawOutput - if the output should be binary data or hex
	 * @return string
	 */
	private function hmac($data, $hashFunct = self::DEFAULT_HASH, $rawOutput = true) {
		
		if (!in_array($hashFunct, hash_algos())) {
			$hashFunct = self::DEFAULT_HASH;
		}
		return hash_hmac($hashFunct, $data, $this->secretKey, $rawOutput);
	}
	
	/**
	 * Calculate the one time password
	 *
	 * @param int $movingFactor
	 * @return string
	 */
	protected function calcOTP($movingFactor) {
		
		$movingFactor = floor($movingFactor);
		$digits = $this->addChecksum ? ($this->codeDigitsNr + 1) : $this->codeDigitsNr;
		
		$text = array();
		for($i = 7; $i >= 0; $i--) {
			$text[] = ($movingFactor & 0xff);
			$movingFactor >>= 8;
		}
		$text = array_reverse($text);
		foreach ($text as $index=>$value) {
			$text[$index] = chr($value);
		}
		$text = implode("", $text);
		
		$hash = $this->hmac($text);
		$hashLenght = strlen($hash);
		$offset = ord($hash[$hashLenght-1]) & 0xf;
		
		$hash = str_split($hash);
		foreach ($hash as $index=>$value) {
			$hash[$index] = ord($value);
		}
		
		$binary = ( ($hash[$offset] & 0x7f) << 24) | (($hash[$offset + 1] & 0xff) << 16) | (($hash[$offset + 2] & 0xff) << 8) | ($hash[$offset + 3] & 0xff);
		
		$otp = $binary % pow(10, $this->codeDigitsNr);
		if ($this->addChecksum) {
			$otp = ($otp * 10) + $this->calcChecksum($otp, $this->codeDigitsNr);
		}
		
		$this->generatedCode = str_pad($otp, $digits, "0", STR_PAD_LEFT);;
		return $this->generatedCode;
	}
	
	/**
	 * Generate a new code
	 *
	 * @return string
	 */
	public function generateCode () {
		return $this->calcOTP($this->time/$this->expiration);
	}
	
	/**
	 * Validate code
	 *
	 * @param string $code
	 * @return bool
	 */
	public function validateCode ($code) {
		
		if ($code == $this->calcOTP($this->time/$this->expiration)) {
			return true;
		} else {
			$movingFactor = ($this->time-floor($this->expiration/(2)))/$this->expiration;
			return ($code == $this->calcOTP($movingFactor));
		}
	}
}

?>