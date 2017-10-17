<?php
/**
 * User: jholl
 * Date: 19/07/15
 * Time: 7:19 PM
 */

class SecureCookies {

    var $_CookieObject;
    var $_CookieID;
    var $_Expire;
    var $_EncryptionPassword;
    var $_Path;
    var $_Domain;
    var $_Secure;

    function SecureCookie($EncryptionPassword,$CookieID,$expire=false,$path=false,$domain=false,$secure=false) {
        // Store all our passed parameters.
        $this->_Expire=$expire;
        $this->_EncryptionPassword=$EncryptionPassword;
        $this->_CookieID=$CookieID;
        $this->_Path=$path;
        $this->_Domain=$domain;
        $this->_Secure=$secure;
        // Does this cookie ID exists?
        if(isset($_COOKIE[$CookieID])) {
            // Decrypt it.
            $obj=unserialize($this->_Decrypt($_COOKIE[$this->_CookieID],$this->_EncryptionPassword));
            // The best way to see if a successful decryption, check a stored value to see if the passwords match.
            // A failed decryption would corrupt it and return bad data.
            if($obj['____ENCRYPTIONPASSWORD'] == md5($this->_EncryptionPassword)) {
                // Its good! Lets use it.
                $this->_CookieObject=$obj;
            }else{
                // Failed! Developer may of changed the encryption password.
                // Open up with a blank object and set our verification field.
                $this->_CookieObject=array('____ENCRYPTIONPASSWORD' => md5($this->_EncryptionPassword));
            }
        }else{
            // Cookie doesn't exists, Open up with a blank object and set our verification field.
            $this->_CookieObject=array('____ENCRYPTIONPASSWORD' => md5($this->_EncryptionPassword));
        }
        // Cleanup obj.
        unset($obj);
    }
    // Alias: SetCookie()
    function Set($name,$value) {
        $this->SetCookie($name,$value);
    }
    // Alias: GetCookie()
    function Get($name,$default = null) {
        return $this->GetCookie($name,$default);
    }
    // Alias: DeleteCookie()
    function Del($name) {
        $this->DeleteCookie($name);
    }
    /**
     * Sets the value of the cookie.
     **/
    function SetCookie($name,$value) {
        // Check to make sure not using invalid name.
        if($name != '____ENCRYPTIONPASSWORD') {
            // Make a copy of our object
            $obj=$this->_CookieObject;
            // Be sure the encryption password is in the object for password verifcation.
            $obj['____ENCRYPTIONPASSWORD'] = md5($this->_EncryptionPassword);
            // Set our new value
            $obj[$name]=$value;
            // Restore the new data to the object
            $this->_CookieObject=$obj;
            // Lets reuse $obj to store our encrypted object
            $obj=$this->_Encrypt(serialize($obj),$this->_EncryptionPassword);
            // Set the actual cookie with our encrypted data.
            setcookie($this->_CookieID,$obj,$this->_Expire,$this->_Path,$this->_Domain,$this->_Secure);
            // Set the cookie global so the data is usable on this page load.
            $_COOKIE[$this->_CookieID] = $obj;
            // Cleanup obj.
            unset($obj);
        }else{
            // See if your trying to intentionally break my script smile.gif Why else would you name it this!
            die('INVALID COOKIE NAME. YOU MAY NOT USE "____ENCRYPTIONPASSWORD" AS YOUR COOKIE NAME');
        }
    }
    /**
     * Retrieves the specified name from the object.
     **/
    function GetCookie($name,$default=null) {
        // Check to make sure not using invalid name.
        if($name != '____ENCRYPTIONPASSWORD') {
            // Make a copy of object
            $obj=$this->_CookieObject;
            // Return the value.
            return isset($obj[$name]) ? $obj[$name] : $default;
        }else{
            // See if your trying to intentionally break my script smile.gif Why else would you name it this!
            die('INVALID COOKIE NAME. YOU MAY NOT USE "____ENCRYPTIONPASSWORD" AS YOUR COOKIE NAME');
        }
    }
    /**
     * Deletes the specified name from the object.
     **/
    function DeleteCookie($name) {
        // Check to make sure not using invalid name.
        if($name != '____ENCRYPTIONPASSWORD') {
            // Make a copy of object.
            $obj=$this->_CookieObject;
            // Unset the value to delete it.
            unset($obj[$name]);
            // Restore our new data to the object.
            $this->_CookieObject=$obj;
            // Lets reuse $obj to store our encrypted object
            $obj=$this->_Encrypt(serialize($obj),$this->_EncryptionPassword);
            // Set the actual cookie with our encrypted data.
            setcookie($this->_CookieID,$obj,$this->_Expire,$this->_Path,$this->_Domain,$this->_Secure);
            // Set the cookie global so the data is usable on this page load.
            $_COOKIE[$this->_CookieID] = $obj;
            // Cleanup obj.
            unset($obj);
        }else{
            // See if your trying to intentionally break my script smile.gif Why else would you name it this!
            die('INVALID COOKIE NAME. YOU MAY NOT USE "____ENCRYPTIONPASSWORD" AS YOUR COOKIE NAME');
        }
    }
    // Returns the Cookie Array
    function GetObject(){
        // Make a copy of the object
        $obj=$this->_CookieObject;
        // Get Rid of our encryption password value.
        unset($obj['____ENCRYPTIONPASSWORD']);
        // Return the array of values.
        return $obj;
    }
    // Standard Encryption Functions.
    function _Encrypt($string,$key) {
        $result = '';
        for($i=0; $i<strlen($string); $i++) {
            $char = substr($string, $i, 1);
            $keychar = substr($key, ($i % strlen($key))-1, 1);
            $char = chr(ord($char)+ord($keychar));
            $result.=$char;
        }
        return base64_encode(gzdeflate($result,9));
    }
    function _Decrypt($string,$key) {
        $result = '';
        $string = gzinflate(base64_decode($string));
        for($i=0; $i<strlen($string); $i++) {
            $char = substr($string, $i, 1);
            $keychar = substr($key, ($i % strlen($key))-1, 1);
            $char = chr(ord($char)-ord($keychar));
            $result.=$char;
        }
        return $result;
    }

}