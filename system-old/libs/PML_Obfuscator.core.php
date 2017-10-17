<?php
/**
 * Giovanne Oliveira - JhollsOliver.me.
 * Date: 16/05/2016
 * Time: 16:00
 */
class PML_Obfuscator{

    /**
     *
     *@var int
     */
    private $_splitLine = 40;

    /**
     * @var string
     */
    private $_code;

    /**
     * @var string
     */
    private $_comment = "";

    /**
     * @var string
     */
    private $_checksum;

    /**
     * @var int
     */
    private $_expiredate;

    /**
     * @var int
     */
    private $_expiremessage;

    /**
     * @var int
     */
    private $_expirecallback;

    /**
     * @var int
     */
    private $_validhosts;

    private $_validhostsmessage;

    const NEWLINE = "\n";

    /**
     * Set code
     *
     * @param string $code
     */
    public function SetCode($code){
        $this->_code = $code;
    }

    /**
     * Clean string, replace chars
     *
     * @param string $string
     * @access private
     */
    private function clean($string){
        $find 		= array("<?php"	, "?>");
        $replace 	= array(""		, "");
        return str_replace($find, $replace, $string);
    }

    /**
     * Split lines
     *
     * @param string $code
     * @access private
     */
    private function splitLines($code){
        $splittedcode 	= "";
        $length 		= strlen($code);
        $parts 			= ceil($length / $this->_splitLine);
        for($i=0 ; $i < $parts ; $i++){
            $splittedcode .= substr($code, ($i*$this->_splitLine), $this->_splitLine) . "\n";
        }
        return $splittedcode;
    }

    /**
     * Encode the string
     *
     * @param string $code
     * @return string
     * @access private
     */
    public function Encode($code, $gzalias='gzinflate', $base64alias='base64_decode'){
        return "eval(" . $gzalias . "(base64_decode('" . base64_encode(gzdeflate($code)) . "')));";
    }

    /**
     * Add code tags
     *
     * @param string $code
     * @return string
     * @access private
     */
    private function addCodeTags($code){
        return "<?php \n " . $code . "?>";
    }

    /**
     * Add functions obfuscation
     *
     * @param string $code
     * @return string
     * @access private
     */
    private function addFunctions($code){

        $keystroke1 = "wdr159sq4ayez7xcgnf_tv8nluk6jhbio32mp";
        $keystroke2 = "wdr159sq4ayez7xcgnf_tv8nluk6jhbio32mp";

        $functions = '$keystroke1 = base64_decode("' . base64_encode($keystroke1) . '");';
        $functions .= "\n";
        $functions .= $this->Encode('if(!function_exists("rotencode")){function rotencode($string,$amount) { $key = substr($string, 0, 1); if(strlen($string)==1) { return chr(ord($key) + $amount); } else { return chr(ord($key) + $amount) . rotEncode(substr($string, 1, strlen($string)-1), $amount); }}}');
        $functions .= "\n";
        $functions .= $this->obfuscateFunction($keystroke1, 'rotencode', '$keystroke1', 'O0O0O0O0O0O0');
        $functions .= "\n";
        $functions .= '$keystroke2 = $O0O0O0O0O0O0("' . $this->rotEncode($keystroke1,1) . '", -1);';
        $functions .= "\n";
        $functions .= $this->obfuscateFunction($keystroke2, 'gzinflate', '$keystroke2', 'OO000OO000OO');
        $functions .= "\n";
        $functions .= $this->obfuscateFunction($keystroke1, 'base64_decode', '$keystroke1', 'O0000000000O');
        $functions .= "\n";
        return $functions . $code;
    }

    /**
     * Create obfuscated functionname
     */
    private function obfuscateFunction($keystroke, $function, $keystrokevar, $newfunctionname){
        $keystrokelen = strlen($keystroke);
        $functionlen = strlen($function);

        // Create keystroke id list
        $keystrokeid = array();
        for($i=0;$i < $keystrokelen;$i++){
            $keystrokeid[$keystroke[$i]] = $i;
        }

        // Create obfuscated function name
        $functionconcat = "";
        for($i=0;$i < $functionlen;$i++){
            $functionconcat .= $keystrokevar . "[" . $keystrokeid[$function[$i]] . "].";
        }
        return '$' . $newfunctionname . '=' . substr($functionconcat,0,-1) . ';';
    }

    /**
     * Rotate encoding
     *
     * @param string $string
     * @param int $amount
     * @return string
     * @access private
     */
    private function rotEncode($string,$amount) {
        $key = substr($string, 0, 1);
        if(strlen($string)==1) {
            return chr(ord($key) + $amount);
        } else {
            return chr(ord($key) + $amount) . $this->rotEncode(substr($string, 1, strlen($string)-1), $amount);
        }
    }

    /**
     * Add Comment
     *
     * @param string $code
     * @return $code
     * @access private
     */
    private function addComment($code){
        if(!empty($this->_comment)){
            $commentline = "/* " . $this->_comment . " */\n";
            return $commentline . $code;
        }
        return $code;
    }

    /**
     * Set comment string
     *
     * @param string $string
     * @return void
     * @access private
     */
    public function SetComment($string){
        $this->_comment = $string;
    }

    /**
     * Add expire functionality
     *
     * @param string $code
     * @return $code
     * @access private
     */
    private function addExpire($code){

        // date, message, callhome address
        $expire_code = "";

        if(!empty($this->_expiredate) && !empty($this->_expiremessage) && empty($this->_expirecallback)){
            $expire_code = 'if(date("Ymd") > ' . $this->_expiredate . '){' . self::NEWLINE;
            $expire_code .= 'echo "' . $this->_expiremessage . '";' . self::NEWLINE;
            $expire_code .= 'exit;' . self::NEWLINE;
            $expire_code .= '}' . self::NEWLINE;
        }

        if(!empty($this->_expiredate) && !empty($this->_expiremessage) && !empty($this->_expirecallback)){
            $expire_code = 'if(date("Ymd") > ' . $this->_expiredate . '){' . self::NEWLINE;
            $expire_code .= '@file_get_contents("' . $this->_expirecallback . '?host=" . $_SERVER[\'HOST\']);' . self::NEWLINE;
            $expire_code .= 'echo "' . $this->_expiremessage . '";' . self::NEWLINE;
            $expire_code .= 'exit;' . self::NEWLINE;
            $expire_code .= '}' . self::NEWLINE;
        }

        return $expire_code . $code;
    }

    /**
     * Set expire
     *
     * @param string $string
     * @return void
     * @access private
     */
    public function SetExpire($date, $message="License expired", $callback=null){
        $this->_expiredate = $date;
        $this->_expiremessage = $message;
        if($callback != "") $this->_expirecallback = $callback;
    }

    /**
     * Set expire
     *
     * @param string $string
     * @return void
     * @access private
     */
    private function addValidHost($code){

        $validhost_code = "";
        if(!empty($this->_validhosts)){
            if(is_array($this->_validhosts)){
                $validhost_code = '$found = FALSE;' . self::NEWLINE;
                $validhost_code .= 'foreach(array("' . implode("\",\"", $this->_validhosts) . '") as $host){' . self::NEWLINE;
                $validhost_code .= 'if(strstr($_SERVER[\'HTTP_HOST\'],$host)) $found = TRUE;' . self::NEWLINE;
                $validhost_code .= '}' . self::NEWLINE;
                $validhost_code .= 'if(!$found) exit("' . $this->_validhostsmessage . '");' . self::NEWLINE;
            }else{
                $validhost_code = 'if(!strstr($_SERVER[\'HTTP_HOST\'],"' . $this->_validhosts . '")) exit("' . $this->_validhostsmessage . '");';
            }
        }

        return $validhost_code . "\n" . $code;
    }

    /**
     * Set Valid hosts
     *
     * @param string $string
     * @return void
     * @access private
     */
    public function SetValidHosts($host, $message="Invalid host"){
        $this->_validhosts = $host;
        $this->_validhostsmessage = $message;
    }

    /**
     * Add fixed home
     *
     * @param string $code
     * @return $code
     * @access private
     */
    private function addHome(){
        // array van hostnames of ip adressen

    }

    /**
     * Get Encoded code
     *
     * @access public
     */
    public function GetEncodedCode(){
        //$code = $this->EncodeBlock($this->_code);
        $code = preg_replace_callback('/<\?php(.*?)\?>/is',array( &$this, 'EncodeBlock'), $this->_code);
        return $code;

    }

    /**
     * Encode this code
     */
    public function EncodeBlock($code) {

        // Clean code
        $code = $this->clean($code[1]);

        // Add expire
        $code = $this->addExpire($code);

        // Add valid host
        $code = $this->addValidHost($code);

        // Encode code
        for($i=0;$i<10;$i++){
            $code = $this->Encode($code, '$OO000OO000OO', '$O0000000000O');
        }

        // Split lines
        $code = $this->splitLines($code);

        // Add functions
        $code = $this->addFunctions($code);

        // Add Comment
        $code = $this->addComment($code);

        // Add code tags
        $code = $this->addCodeTags($code);

        return $code;
    }

}