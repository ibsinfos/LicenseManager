<?php
/**
 * Basic extension of Jim Wiggintons Pure-PHP PKCS#1 (v2.1) compliant implementation of RSA
 * to allow easy use with .NET based XML keys.
 *
 * Requires the http://phpseclib.sourceforge.net library, this file should be placed within
 * the 'Crypt' directory.
 *
 * This could be done better, even integrated into the lib itself, O for more time...
 *
 * @category   Crypt
 * @package    Crypt_RSA
 * @author     Oliver Green <green2go@gmail.com>
 * @version    1.0 (12/04/2011)
 * @link       http://www.codeblog.co.uk
 * @license    http://www.gnu.org/licenses/lgpl.txt
 *
 * Here's an example of how to encrypt and decrypt text with this library:
 * <code>
 * <?php
 *    include('Crypt/RSA_XML.php');
 *
 *    $publicKey = "";
 *    $privateKey = "";
 *
 *    $rsa = Crypt_RSA_XML::fromXML($key,Crypt_RSA_XML::PrivateKey);
 *
 *    $plaintext = 'terrafrost';
 *
 *    $rsa->loadKey($privatekey);
 *    $ciphertext = $rsa->encrypt($plaintext);
 *
 *    $rsa->loadKey($publickey);
 *    echo $rsa->decrypt($ciphertext);
 * ?>
 * </code>
 *
 * Here's an example of how to create signatures and verify signatures with this library:
 * <code>
 * <?php
 *    include('Crypt/RSA.php');
 *
 *    $rsa = new Crypt_RSA();
 *    extract($rsa->createKey());
 *
 *    $plaintext = 'terrafrost';
 *
 *    $rsa->loadKey($privatekey);
 *    $signature = $rsa->sign($plaintext);
 *
 *    $rsa->loadKey($publickey);
 *    echo $rsa->verify($plaintext, $signature) ? 'verified' : 'unverified';
 * ?>
 * </code>
 *
 * LICENSE: This library is free software; you can redistribute it and/or
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
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston,
 * MA  02111-1307  USA
 *
 * Original code by TerraFrost
 * @link http://www.frostjedi.com/phpbb/viewtopic.php?f=46&t=20255
 *
 */

require_once('RSA.php');

class Crypt_RSA_XML extends Crypt_RSA {

    public function loadKeyfromXML($key)
    {
	$xml = new DOMDocument();
	$xml->loadXML($key);
	$modulus = new Math_BigInteger(base64_decode($xml->getElementsByTagName('Modulus')->item(0)->nodeValue), 256);
	$exponent = new Math_BigInteger(base64_decode($xml->getElementsByTagName('Exponent')->item(0)->nodeValue), 256);

	$this->setSignatureMode(CRYPT_RSA_SIGNATURE_PKCS1);
	$this->modulus = $modulus;
	$this->exponent = $exponent;
	$this->publicExponent = $exponent;
	$this->k = strlen($this->modulus->toBytes());

	if(isset($xml->getElementsByTagName('D')->item(0)->nodeValue)
		&& isset($xml->getElementsByTagName('InverseQ')->item(0)->nodeValue)) {
	    $d = new Math_BigInteger(base64_decode($xml->getElementsByTagName('D')->item(0)->nodeValue), 256);
	    $dp = new Math_BigInteger(base64_decode($xml->getElementsByTagName('DP')->item(0)->nodeValue), 256);
	    $dq = new Math_BigInteger(base64_decode($xml->getElementsByTagName('DQ')->item(0)->nodeValue), 256);
	    $inverseq = new Math_BigInteger(base64_decode($xml->getElementsByTagName('InverseQ')->item(0)->nodeValue), 256);
	    $p = new Math_BigInteger(base64_decode($xml->getElementsByTagName('P')->item(0)->nodeValue), 256);
	    $q = new Math_BigInteger(base64_decode($xml->getElementsByTagName('Q')->item(0)->nodeValue), 256);

	    $this->exponents = array(1=> $dp, $dq);
	    $this->coefficients = array(2 => $inverseq);
	    $this->primes = array(1 => $p, $q);
	}
    }
}

?>
