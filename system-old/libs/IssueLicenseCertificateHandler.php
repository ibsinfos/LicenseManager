<?php

/**
 * Created by PhpStorm.
 * User: jhollsoliver
 * Date: 7/16/16
 * Time: 11:25 AM
 */
class IssueLicenseCertificateHandler
{

    /**
     * @var object AESHelper Class Object
     */
    private $AES;
    /**
     * @var object Crypt_RSA Class Object
     */
    private $RSA;
    /**
     * @var string License XML Object
     */
    public $LicenseData = '';

    /**
     * @var string Private Key
     */
    private $PrivateKey = '';

    /**
     * LicenseCertificateHandler constructor.
     * @param object $RSA Crypt_RSA class object
     * @param object $AES AESHelper Class Object
     */
    public function __construct($RSA, $AES)
    {
        if(!isset($AES))
        {
            throw new Exception('Missing AESHelper Class in constructor');
        }else{
            $this->AES = $AES;
        }

        if(!isset($RSA))
        {
            throw new Exception('Missing CryptRSA class in constructor');

        }else{
            $this->RSA = $RSA;
        }


    }

    public function LoadPrivateKey($privkey)
    {
        $this->PrivateKey = $privkey;
    }

    protected function HashAndSignBytes($stringToSign)
    {
        $this->RSA->loadKey($this->PrivateKey); // private key
        $this->RSA->setSignatureMode(CRYPT_RSA_SIGNATURE_PKCS1);
        $signature = $this->RSA->sign($stringToSign);
        return base64_encode($signature);
    }

    
    private function GenerateLicenseFileSignature($VendorID, $LicenseKey, $IssuedIn, $AuthenticationKey, $CustomerEmail, $ProductID, $ExpirationDate, $hosts)
    {
        $hosts = json_encode($hosts);
        $verifystring = $VendorID.$IssuedIn.$LicenseKey.$ExpirationDate.$hosts.$AuthenticationKey;
        $signature = $this->HashAndSignBytes($verifystring);
        return $signature;
    }

    public function GenerateLicenseFile($VendorID = 99, $LicenseKey, $CustomerEmail, $ProductID, $ExpirationDate, $hosts, $comments, $encrypted = true)
    {
        $AuthenticationKey = md5(rand(1111,9999));
        $IssuedIn = time();
        $xml = new SimpleXMLElement('<licensefile/>');

        $xml->addChild('VendorID', $VendorID); //
        $xml->addChild('IssuedIn', $IssuedIn);//
        $xml->addChild('CustomerEmail', $CustomerEmail);//
        $xml->addChild('ProductID', $ProductID);//
        $xml->addchild('LicenseKey', $LicenseKey);//
        $xml->addChild('ExpirationDate', $ExpirationDate);//
        $xml->addChild('Hosts', json_encode($hosts));//
        $xml->addChild('Comments', $comments);//
        $xml->addChild('AuthenticationToken', $AuthenticationKey);
        $signature = $this->GenerateLicenseFileSignature($VendorID, $LicenseKey, $IssuedIn, $AuthenticationKey, $CustomerEmail, $ProductID, $ExpirationDate, $hosts);
        $xml->addChild('signature', $signature);

        if($encrypted == true)
        {
            $encxml = $this->AES->encrypt($xml->asXML());
            $encxml = chunk_split($encxml, 35);
            return $encxml;
        }else{
            return $xml->asXML();
        }


    }
    
    

}