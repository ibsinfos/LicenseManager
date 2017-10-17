<?php

/**
 * User: jhollsoliver
 * Date: 7/14/16
 * Time: 7:43 PM
 */
class LicenseCertificateHandler
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
    private $PublicKey = '';



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

    /**
     * @param $LicenseStr License File in String Format
     * @return void
     */
    public function LoadLicenseData($LicenseStr)
    {
        $licdec = $this->AES->decrypt($LicenseStr);
        if($licdec)
        {
            $licxml = simplexml_load_string($licdec);
            if($licxml)
            {
                $this->LicenseData = $licxml;
            }else{
                throw new Exception('Invalid or Corrupted License File - Wrong File Structure');
            }

        }else{
            throw new Exception('Invalid or Corrupted License File - Decryption failure');
        }
    }

    /**
     * @param $stringToSign String to be signed
     * @param $Key Key in XML format
     * @return string Signature String
     */
    /*protected function HashAndSignBytes($stringToSign)
    {
        $this->RSA->loadKey($this->PrivateKey); // private key
        $this->RSA->setSignatureMode(CRYPT_RSA_SIGNATURE_PKCS1);
        $signature = $this->RSA->sign($stringToSign);
        return base64_encode($signature);
    }*/


    public function ValidateLicenseSignature()
    {
        //$this->
            
        $this->RSA->loadKey($this->PublicKey);

        $VendorID = $this->LicenseData->VendorID;
        $IssuedIn = $this->LicenseData->IssuedIn->__toString();
        $LicenseKey = $this->LicenseData->LicenseKey;
        $ExpirationDate = $this->LicenseData->ExpirationDate->__toString();
        $hosts = $this->LicenseData->Hosts;
        $AuthenticationKey = $this->LicenseData->AuthenticationToken;
        $verifystring = $VendorID.$IssuedIn.$LicenseKey.$ExpirationDate.$hosts.$AuthenticationKey;
        $valid = $this->RSA->verify($verifystring, base64_decode($this->LicenseData->signature));
        return $valid;
    }

    public function LoadPublicKey($pubkey)
    {
        $this->PublicKey = $pubkey;
    }

    public function ValidateLicenseAllParameters()
    {
        if($this->LicenseData->ExpirationDate < time())
        {
            $return['valid'] = false;
            $return['message'] = 'License Expired';
            return $return;
        }
        $thishost = $_SERVER['SERVER_NAME'];
        $hostlist = json_decode($this->LicenseData->Hosts, true);
        if(!in_array($thishost, $hostlist))
        {
            $return['valid'] = false;
            $return['message'] = 'Invalid Host - You are using this license in another machine.';
            return $return;
        }
        if(!$this->ValidateLicenseSignature())
        {
            $return['valid'] = false;
            $return['message'] = 'Invalid or corrupted signature. Are you trying to crack me?';
            return $return;
        }
        $return['valid'] = true;
        $return['message'] = 'License is Valid!';
        return $return;
    }
    
    

}