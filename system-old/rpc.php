<?php
/**
 * Giovanne Oliveira - JhollsOliver.me.
 * Date: 16/05/2016
 * Time: 16:27
 */

require('libs/jterm/examples/json-rpc.php');
include('autoloader.php');
/*
if (function_exists('xdebug_disable')) {
    xdebug_disable();
}*/

class PML_RPC {

    private $DbHandler;

    static $login_documentation = "login to the server (return token)";
    public function login($user, $passwd) {

        $pass = hash('sha256', $passwd);
        $sql = "SELECT * FROM `users` WHERE `username` = '$user' AND `password` = '$pass'";
        $query = $this->DbHandler->query($sql);
        if($query->num_rows > 0)
        {
            return md5($user . ":" . $pass);
        }

    }

    static $unlockfromapi_documentation = "Unlock all connections to PHPMyLicense API";
    public function unlockfromapi($dir)
    {
        return 'Offline mode set';
    }

    static $checkforupdates_documentation = "Check for PHPMyLicense Updates";
    public function checkforupdates($dir)
    {
        $sql = "SELECT purchasecode FROM settings";
        $query = $this->DbHandler->query($sql);
        $data = $query->fetch_array();
        $purchasecode = $data['purchasecode'];

        $response = json_decode(file_get_contents(PHPMYLICENSE_API . '/update/latest?purchasecode=' . $purchasecode));

        if ($response->latestversion > PRODUCT_VERSION) {

            return "There is an update avaiable: ".$response->latestversion;

        } else {
            return "The software is up to date.";
        }
    }

    static $updatechannel_documentation = "Check for PHPMyLicense Updates";
    public function updatechannel($a, $status)
    {
        if($status == 'internaltest')
        {
            $newstatus = 'internal';
        }
        if($status == 'beta')
        {
            $newstatus = 'beta';
        }else{
            $newstatus = 'stable';
        }
        $sql = "SELECT configurations FROM settings";
        $query = $this->DbHandler->query($sql);
        $data = $query->fetch_array();
        $data = json_decode($data['configurations'], true);

        $data['updatechannel'] = $newstatus;

        $configs = json_encode($data);

        $sql = "UPDATE settings SET configurations = '$configs'";
        $query = $this->DbHandler->query($sql);
        if($query)
        {
            return 'Success';
        }else{
            throw new Exception("Error while updating");
        }
    }

    /*static $updatesettings_documentation = "Update Settings";
    public function updatesettings($a, $field, $value)
    {
        switch($field)
        {
            case 'signapiresponse':
                
                break;
            
        }
    }*/


    static $ls_documentation = "list directory if token is valid";
    public function ls($token, $path = null) {
        if (strcmp(md5("demo:demo"), $token) == 0) {
            if (preg_match("/\.\./", $path)) {
                throw new Exception("No directory traversal Dude");
            }
            $base = preg_replace("/(.*\/).*/", "$1", $_SERVER["SCRIPT_FILENAME"]);
            $path = $base . ($path[0] != '/' ? "/" : "") . $path;
            $dir = opendir($path);
            while($name = readdir($dir)) {
                $fname = $path."/".$name;
                if (!is_dir($name) && !is_dir($fname)) {
                    $list[] = $name;
                }
            }
            closedir($dir);
            return $list;
        } else {
            throw new Exception("Access Denied");
        }
    }


    public function RegisterClass($classname, $object)
    {
        $this->$classname = $object;
    }

}
$PML_RPC = new PML_RPC();
$PML_RPC->RegisterClass('DbHandler', $DatabaseHandler);
handle_json_rpc($PML_RPC);

?>
