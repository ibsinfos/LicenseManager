<?php

/**
 * Created by PhpStorm.
 * User: Giovanne
 * Date: 23-Oct-15
 * Time: 1:57 PM
 */
class SignatureHandler
{
    private $privatekey = "";

    private $publickey = "";

    private $Rsa;

    public function __construct()
    {
        if(file_exists(__DIR__.'/signature/phpmylicense.pub'))
        {
            $this->publickey = file_get_contents(__DIR__.'/signature/phpmylicense.pub');
        }else{
            throw new ErrorException('Unable to load the public key');
        }
        if(file_exists(__DIR__.'/signature/phpmylicense.pri'))
        {
            $this->privatekey = file_get_contents(__DIR__.'/signature/phpmylicense.pri');
        }else{
            throw new ErrorException('Unable to load the private key');
        }
        //return true;
    }

    public function Sign($str)
    {
        $this->Rsa->loadKey($this->privatekey);
        $this->Rsa->setSignatureMode(CRYPT_RSA_SIGNATURE_PKCS1);
        $signature = $this->Rsa->sign($str);
        return base64_encode($signature);
    }

    public function CheckSignature($str, $sign, $pub = "")
    {
        if($pub == "") {
            $pub = $this->publickey;
        }
        $this->Rsa->loadKey($pub);
        $this->Rsa->setSignatureMode(CRYPT_RSA_SIGNATURE_PKCS1);
        $sign = base64_decode($sign);
        $valid = $this->Rsa->verify($str, $sign);
        if($valid)
        {
            return true;
        }else{
            return false;
        }
    }

    public function FormatJsonSignature($json, $signature = "")
    {
        if($signature == "")
        {
            $j = json_encode($json);
            $signature = $this->Sign($j);
        }
        $json['signature'] = $signature;
        return $json;
    }

    public function ValidateJsonSignature($json)
    {
        if(!is_array($json))
        {
            $json = json_decode($json, true);
        }
        $signature = $json['signature'];
        unset($json['signature']);
        $valid = $this->CheckSignature(json_encode($json), $signature);
        if($valid)
        {
            return true;
        }else{
            return false;
        }

    }

    public function LoadExternalClass($classname, $object)
    {
        $this->$classname = $object;
    }
    public function LoadCustomKey($key, $type = 'public')
    {
        if($type == 'public')
        {
            $this->publickey = $key;
        }else{
            $this->privatekey = $key;
        }
    }

}