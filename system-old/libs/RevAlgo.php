<?php
/**
 * RevAlgo Cryptography Algorithm
 * Unreal Security Lab
 * User: root
 * File: RevAlgoCfg.php
 * Date: 19/08/14
 * Time: 16:44
 */

class RevAlgo {

    public $key;
    public $iv;
    public $separator;

    public $MCRYPT = array(
        'CIPHER' => MCRYPT_RIJNDAEL_256, //  Others ciphers Mcrypt - http://php.net/manual/en/mcrypt.ciphers.php#mcrypt.ciphers
        'MODE' => MCRYPT_MODE_ECB,       //  Others ciphers Modes - http://php.net/manual/en/mcrypt.constants.php#mcrypt.constants
    );

    /**
     * Constantes para geraÃ§Ã£o de chaves criptograficas.
     *
     */
    const KEYGEN_128_BITS = 16;
    const KEYGEN_192_BITS = 24;
    const KEYGEN_256_BITS = 32;


    /**
     * O nÃºmero de palavras de 32 bits que inclui o texto pleno e
     * colunas com o estado de uma matriz AES cifra.
     *
     * @var integer $Nb
     *
     */
    private static $Nb = 4;


    /**
     * O nÃºmero de 32 bits compreendendo as palavras-chave neste codificador
     * AES cipher.
     *
     * @var integer $Nk
     *
     */
    private $Nk;


    /**
     * Numero de 32 bits para criptografia AES.
     *
     * @var integer $Nr
     *
     */
    private $Nr;


    /**
     * O S-Box da tabela de substituiÃ§Ã£o.
     *
     * @var array $sBox
     *
     */
    private static $sBox = array(
        0x63, 0x7c, 0x77, 0x7b, 0xf2, 0x6b, 0x6f, 0xc5,
        0x30, 0x01, 0x67, 0x2b, 0xfe, 0xd7, 0xab, 0x76,
        0xca, 0x82, 0xc9, 0x7d, 0xfa, 0x59, 0x47, 0xf0,
        0xad, 0xd4, 0xa2, 0xaf, 0x9c, 0xa4, 0x72, 0xc0,
        0xb7, 0xfd, 0x93, 0x26, 0x36, 0x3f, 0xf7, 0xcc,
        0x34, 0xa5, 0xe5, 0xf1, 0x71, 0xd8, 0x31, 0x15,
        0x04, 0xc7, 0x23, 0xc3, 0x18, 0x96, 0x05, 0x9a,
        0x07, 0x12, 0x80, 0xe2, 0xeb, 0x27, 0xb2, 0x75,
        0x09, 0x83, 0x2c, 0x1a, 0x1b, 0x6e, 0x5a, 0xa0,
        0x52, 0x3b, 0xd6, 0xb3, 0x29, 0xe3, 0x2f, 0x84,
        0x53, 0xd1, 0x00, 0xed, 0x20, 0xfc, 0xb1, 0x5b,
        0x6a, 0xcb, 0xbe, 0x39, 0x4a, 0x4c, 0x58, 0xcf,
        0xd0, 0xef, 0xaa, 0xfb, 0x43, 0x4d, 0x33, 0x85,
        0x45, 0xf9, 0x02, 0x7f, 0x50, 0x3c, 0x9f, 0xa8,
        0x51, 0xa3, 0x40, 0x8f, 0x92, 0x9d, 0x38, 0xf5,
        0xbc, 0xb6, 0xda, 0x21, 0x10, 0xff, 0xf3, 0xd2,
        0xcd, 0x0c, 0x13, 0xec, 0x5f, 0x97, 0x44, 0x17,
        0xc4, 0xa7, 0x7e, 0x3d, 0x64, 0x5d, 0x19, 0x73,
        0x60, 0x81, 0x4f, 0xdc, 0x22, 0x2a, 0x90, 0x88,
        0x46, 0xee, 0xb8, 0x14, 0xde, 0x5e, 0x0b, 0xdb,
        0xe0, 0x32, 0x3a, 0x0a, 0x49, 0x06, 0x24, 0x5c,
        0xc2, 0xd3, 0xac, 0x62, 0x91, 0x95, 0xe4, 0x79,
        0xe7, 0xc8, 0x37, 0x6d, 0x8d, 0xd5, 0x4e, 0xa9,
        0x6c, 0x56, 0xf4, 0xea, 0x65, 0x7a, 0xae, 0x08,
        0xba, 0x78, 0x25, 0x2e, 0x1c, 0xa6, 0xb4, 0xc6,
        0xe8, 0xdd, 0x74, 0x1f, 0x4b, 0xbd, 0x8b, 0x8a,
        0x70, 0x3e, 0xb5, 0x66, 0x48, 0x03, 0xf6, 0x0e,
        0x61, 0x35, 0x57, 0xb9, 0x86, 0xc1, 0x1d, 0x9e,
        0xe1, 0xf8, 0x98, 0x11, 0x69, 0xd9, 0x8e, 0x94,
        0x9b, 0x1e, 0x87, 0xe9, 0xce, 0x55, 0x28, 0xdf,
        0x8c, 0xa1, 0x89, 0x0d, 0xbf, 0xe6, 0x42, 0x68,
        0x41, 0x99, 0x2d, 0x0f, 0xb0, 0x54, 0xbb, 0x16
    );


    /**
     * O Inverso da tabela substituiÃ§Ã£o.
     *
     * @var array $invSBox
     *
     */
    private static $invSBox = array(
        0x52, 0x09, 0x6a, 0xd5, 0x30, 0x36, 0xa5, 0x38,
        0xbf, 0x40, 0xa3, 0x9e, 0x81, 0xf3, 0xd7, 0xfb,
        0x7c, 0xe3, 0x39, 0x82, 0x9b, 0x2f, 0xff, 0x87,
        0x34, 0x8e, 0x43, 0x44, 0xc4, 0xde, 0xe9, 0xcb,
        0x54, 0x7b, 0x94, 0x32, 0xa6, 0xc2, 0x23, 0x3d,
        0xee, 0x4c, 0x95, 0x0b, 0x42, 0xfa, 0xc3, 0x4e,
        0x08, 0x2e, 0xa1, 0x66, 0x28, 0xd9, 0x24, 0xb2,
        0x76, 0x5b, 0xa2, 0x49, 0x6d, 0x8b, 0xd1, 0x25,
        0x72, 0xf8, 0xf6, 0x64, 0x86, 0x68, 0x98, 0x16,
        0xd4, 0xa4, 0x5c, 0xcc, 0x5d, 0x65, 0xb6, 0x92,
        0x6c, 0x70, 0x48, 0x50, 0xfd, 0xed, 0xb9, 0xda,
        0x5e, 0x15, 0x46, 0x57, 0xa7, 0x8d, 0x9d, 0x84,
        0x90, 0xd8, 0xab, 0x00, 0x8c, 0xbc, 0xd3, 0x0a,
        0xf7, 0xe4, 0x58, 0x05, 0xb8, 0xb3, 0x45, 0x06,
        0xd0, 0x2c, 0x1e, 0x8f, 0xca, 0x3f, 0x0f, 0x02,
        0xc1, 0xaf, 0xbd, 0x03, 0x01, 0x13, 0x8a, 0x6b,
        0x3a, 0x91, 0x11, 0x41, 0x4f, 0x67, 0xdc, 0xea,
        0x97, 0xf2, 0xcf, 0xce, 0xf0, 0xb4, 0xe6, 0x73,
        0x96, 0xac, 0x74, 0x22, 0xe7, 0xad, 0x35, 0x85,
        0xe2, 0xf9, 0x37, 0xe8, 0x1c, 0x75, 0xdf, 0x6e,
        0x47, 0xf1, 0x1a, 0x71, 0x1d, 0x29, 0xc5, 0x89,
        0x6f, 0xb7, 0x62, 0x0e, 0xaa, 0x18, 0xbe, 0x1b,
        0xfc, 0x56, 0x3e, 0x4b, 0xc6, 0xd2, 0x79, 0x20,
        0x9a, 0xdb, 0xc0, 0xfe, 0x78, 0xcd, 0x5a, 0xf4,
        0x1f, 0xdd, 0xa8, 0x33, 0x88, 0x07, 0xc7, 0x31,
        0xb1, 0x12, 0x10, 0x59, 0x27, 0x80, 0xec, 0x5f,
        0x60, 0x51, 0x7f, 0xa9, 0x19, 0xb5, 0x4a, 0x0d,
        0x2d, 0xe5, 0x7a, 0x9f, 0x93, 0xc9, 0x9c, 0xef,
        0xa0, 0xe0, 0x3b, 0x4d, 0xae, 0x2a, 0xf5, 0xb0,
        0xc8, 0xeb, 0xbb, 0x3c, 0x83, 0x53, 0x99, 0x61,
        0x17, 0x2b, 0x04, 0x7e, 0xba, 0x77, 0xd6, 0x26,
        0xe1, 0x69, 0x14, 0x63, 0x55, 0x21, 0x0c, 0x7d
    );


    /**
     * Log da tabela baseado no  0xe5.
     *
     * @var array $ltable
     *
     */
    private static $ltable = array(
        0x00, 0xff, 0xc8, 0x08, 0x91, 0x10, 0xd0, 0x36,
        0x5a, 0x3e, 0xd8, 0x43, 0x99, 0x77, 0xfe, 0x18,
        0x23, 0x20, 0x07, 0x70, 0xa1, 0x6c, 0x0c, 0x7f,
        0x62, 0x8b, 0x40, 0x46, 0xc7, 0x4b, 0xe0, 0x0e,
        0xeb, 0x16, 0xe8, 0xad, 0xcf, 0xcd, 0x39, 0x53,
        0x6a, 0x27, 0x35, 0x93, 0xd4, 0x4e, 0x48, 0xc3,
        0x2b, 0x79, 0x54, 0x28, 0x09, 0x78, 0x0f, 0x21,
        0x90, 0x87, 0x14, 0x2a, 0xa9, 0x9c, 0xd6, 0x74,
        0xb4, 0x7c, 0xde, 0xed, 0xb1, 0x86, 0x76, 0xa4,
        0x98, 0xe2, 0x96, 0x8f, 0x02, 0x32, 0x1c, 0xc1,
        0x33, 0xee, 0xef, 0x81, 0xfd, 0x30, 0x5c, 0x13,
        0x9d, 0x29, 0x17, 0xc4, 0x11, 0x44, 0x8c, 0x80,
        0xf3, 0x73, 0x42, 0x1e, 0x1d, 0xb5, 0xf0, 0x12,
        0xd1, 0x5b, 0x41, 0xa2, 0xd7, 0x2c, 0xe9, 0xd5,
        0x59, 0xcb, 0x50, 0xa8, 0xdc, 0xfc, 0xf2, 0x56,
        0x72, 0xa6, 0x65, 0x2f, 0x9f, 0x9b, 0x3d, 0xba,
        0x7d, 0xc2, 0x45, 0x82, 0xa7, 0x57, 0xb6, 0xa3,
        0x7a, 0x75, 0x4f, 0xae, 0x3f, 0x37, 0x6d, 0x47,
        0x61, 0xbe, 0xab, 0xd3, 0x5f, 0xb0, 0x58, 0xaf,
        0xca, 0x5e, 0xfa, 0x85, 0xe4, 0x4d, 0x8a, 0x05,
        0xfb, 0x60, 0xb7, 0x7b, 0xb8, 0x26, 0x4a, 0x67,
        0xc6, 0x1a, 0xf8, 0x69, 0x25, 0xb3, 0xdb, 0xbd,
        0x66, 0xdd, 0xf1, 0xd2, 0xdf, 0x03, 0x8d, 0x34,
        0xd9, 0x92, 0x0d, 0x63, 0x55, 0xaa, 0x49, 0xec,
        0xbc, 0x95, 0x3c, 0x84, 0x0b, 0xf5, 0xe6, 0xe7,
        0xe5, 0xac, 0x7e, 0x6e, 0xb9, 0xf9, 0xda, 0x8e,
        0x9a, 0xc9, 0x24, 0xe1, 0x0a, 0x15, 0x6b, 0x3a,
        0xa0, 0x51, 0xf4, 0xea, 0xb2, 0x97, 0x9e, 0x5d,
        0x22, 0x88, 0x94, 0xce, 0x19, 0x01, 0x71, 0x4c,
        0xa5, 0xe3, 0xc5, 0x31, 0xbb, 0xcc, 0x1f, 0x2d,
        0x3b, 0x52, 0x6f, 0xf6, 0x2e, 0x89, 0xf7, 0xc0,
        0x68, 0x1b, 0x64, 0x04, 0x06, 0xbf, 0x83, 0x38
    );


    /**
     * Log Inverso da tabela
     *
     * @var array $atable
     *
     */
    private static $atable = array(
        0x01, 0xe5, 0x4c, 0xb5, 0xfb, 0x9f, 0xfc, 0x12,
        0x03, 0x34, 0xd4, 0xc4, 0x16, 0xba, 0x1f, 0x36,
        0x05, 0x5c, 0x67, 0x57, 0x3a, 0xd5, 0x21, 0x5a,
        0x0f, 0xe4, 0xa9, 0xf9, 0x4e, 0x64, 0x63, 0xee,
        0x11, 0x37, 0xe0, 0x10, 0xd2, 0xac, 0xa5, 0x29,
        0x33, 0x59, 0x3b, 0x30, 0x6d, 0xef, 0xf4, 0x7b,
        0x55, 0xeb, 0x4d, 0x50, 0xb7, 0x2a, 0x07, 0x8d,
        0xff, 0x26, 0xd7, 0xf0, 0xc2, 0x7e, 0x09, 0x8c,
        0x1a, 0x6a, 0x62, 0x0b, 0x5d, 0x82, 0x1b, 0x8f,
        0x2e, 0xbe, 0xa6, 0x1d, 0xe7, 0x9d, 0x2d, 0x8a,
        0x72, 0xd9, 0xf1, 0x27, 0x32, 0xbc, 0x77, 0x85,
        0x96, 0x70, 0x08, 0x69, 0x56, 0xdf, 0x99, 0x94,
        0xa1, 0x90, 0x18, 0xbb, 0xfa, 0x7a, 0xb0, 0xa7,
        0xf8, 0xab, 0x28, 0xd6, 0x15, 0x8e, 0xcb, 0xf2,
        0x13, 0xe6, 0x78, 0x61, 0x3f, 0x89, 0x46, 0x0d,
        0x35, 0x31, 0x88, 0xa3, 0x41, 0x80, 0xca, 0x17,
        0x5f, 0x53, 0x83, 0xfe, 0xc3, 0x9b, 0x45, 0x39,
        0xe1, 0xf5, 0x9e, 0x19, 0x5e, 0xb6, 0xcf, 0x4b,
        0x38, 0x04, 0xb9, 0x2b, 0xe2, 0xc1, 0x4a, 0xdd,
        0x48, 0x0c, 0xd0, 0x7d, 0x3d, 0x58, 0xde, 0x7c,
        0xd8, 0x14, 0x6b, 0x87, 0x47, 0xe8, 0x79, 0x84,
        0x73, 0x3c, 0xbd, 0x92, 0xc9, 0x23, 0x8b, 0x97,
        0x95, 0x44, 0xdc, 0xad, 0x40, 0x65, 0x86, 0xa2,
        0xa4, 0xcc, 0x7f, 0xec, 0xc0, 0xaf, 0x91, 0xfd,
        0xf7, 0x4f, 0x81, 0x2f, 0x5b, 0xea, 0xa8, 0x1c,
        0x02, 0xd1, 0x98, 0x71, 0xed, 0x25, 0xe3, 0x24,
        0x06, 0x68, 0xb3, 0x93, 0x2c, 0x6f, 0x3e, 0x6c,
        0x0a, 0xb8, 0xce, 0xae, 0x74, 0xb1, 0x42, 0xb4,
        0x1e, 0xd3, 0x49, 0xe9, 0x9c, 0xc8, 0xc6, 0xc7,
        0x22, 0x6e, 0xdb, 0x20, 0xbf, 0x43, 0x51, 0x52,
        0x66, 0xb2, 0x76, 0x60, 0xda, 0xc5, 0xf3, 0xf6,
        0xaa, 0xcd, 0x9a, 0xa0, 0x75, 0x54, 0x0e, 0x01
    );


    /**
     * Chave Escalonadora da cifra AES.
     *
     * @var mixed $w
     *
     */
    private $w;


    /**
     * O estado da matriz da cifra AES com Nb colunas e 4 linhas
     *
     * @var array $s
     *
     */
    private $s;


    /**
     * Determina o tamanho da chave z
     *
     * @var integer $keyLength
     *
     */
    private $keyLength;


    /**
     * Construtor do objeto AES com especificaÃ§Ã£o da chave de codificaÃ§Ã£o.
     * Permitindo chaves de 128-bits | 192-bits | 256-bits.
     *
     * @method __construct()
     * @param string $keyCode
     * @return void
     * @since 1.0.0
     *
     */

    public function __construct($key = NULL, $separator = NULL) {

        if( $key == NULL or $separator == NULL ) exit('No set all attributes in class Encryption');

        $this->separator = $this->filterSeparator( $separator );

        $getIvSize = mcrypt_get_iv_size( $this->MCRYPT['CIPHER'], $this->MCRYPT['MODE'] );

        $this->key = hash('ripemd256', $key, true );
        $this->iv = mcrypt_create_iv( $getIvSize, MCRYPT_RAND );


        $this->Nk = strlen($key)/4;
        $this->Nr = $this->Nk + self::$Nb + 2;

        if ( $this->Nk != 4 && $this->Nk != 6 && $this->Nk != 8 ){
            echo "<font color='red'>&#8709</font> ".
                "A Chave configurada: " . ($this->Nk*32) . " bits long, &eacute;".
                " inv&aacute;lida<br />Chaves v&aacute;lidas ".
                "devem ser de <b>[128-bits]</b>,<b>[192-bits]</b> ou <b>[256-bits]</b>.";
        }

        $this->Nr = $this->Nk+self::$Nb+2;
        $this->w = array();
        $this->s = array(array());

        $this->keyExpansion( $key );

    }

    /**
     * Destrutor de base nÃ£o parametrizado.
     *
     * @method __destruct()
     * @param void
     * @return void
     * @since 1.0.0
     *
     */
    public function __destruct() {
        unset($this->w);
        unset($this->s);
    }


    /**
     * Executa a Criptografia com o algoritmo AES no texto pleno
     * passado pelo parametro $text
     *
     * @method encrypt()
     * @param string $text
     * @return string
     * @since 1.0.0
     *
     */
    public function encrypt($text)
    {
        $t = ""; // 16-byte bloco
        $y = ""; // Para retorno do bloco cifrado.


        $xsize = strlen($text);
        for ($i = 0; $i < $xsize; $i += 16){
            for ($j = 0; $j < 16; $j++){
                if (($i+$j) < $xsize){
                    $t[$j] = $text[$i+$j];
                }else{
                    $t[$j] = chr(0);
                }
            }

            $y .= $this->encryptBlock($t);
        }

        return $y;
    }

    /**
     * Desencripta o texto pleno excriptado com o algoritmo AES
     * pelo mÃ©todo encript o objeto.
     *
     * @method decrypt()
     * @param string $decodeText
     * @return string
     * @since 1.0.0
     *
     */
    public function decrypt($decodeText)
    {
        // 16-byte bloco
        $t = "";

        // retorna o texto decodificado.
        $x = "";


        // Executa o algoritmo em blocos de 16-byte
        $ysize = strlen($decodeText);
        for($i = 0; $i < $ysize; $i += 16){
            for ($j = 0; $j < 16; $j++){
                if (($i+$j)<$ysize){
                    $t[$j] = $decodeText[$i+$j];
                }else{
                    $t[$j] = chr(0);
                }
            }

            $x .= $this->decryptBlock($t);
        }

        return $x;
    }


    /**
     * Encripta um bloco de texto de 16-bytes.
     *
     * @method encryptBlock();
     * @params string $blockText
     * @returns string
     * @since 1.0.0
     *
     */
    public function encryptBlock($blockText)
    {
        // String de 16-bytes
        $y = "";

        // entrada local para o estado inicial x matriz do fim da coluna
        for ($i = 0; $i < 4 * self::$Nb; $i++){
            $this->s[$i % 4][($i - $i % self::$Nb) / self::$Nb] = ord($blockText[$i]);
        }

        // Adiciona um etapa a chave
        $this->addRoundKey(0);

        for ($i = 1; $i < $this->Nr; $i++) {
            // substitui bytes
            $this->subBytes();

            // eleva as linhas
            $this->shiftRows();

            // embaralha as linhas
            $this->mixColumns();

            // Adiciona uma etapa a chave.
            $this->addRoundKey($i);
        }

        // Substitui bytes
        $this->subBytes();

        // eleva as linhas
        $this->shiftRows();

        // Adiciona uma etapa a chave.
        $this->addRoundKey($i);

        for ($i = 0; $i < 4 * self::$Nb; $i++){
            $y .= chr($this->s[$i % 4][($i - $i % self::$Nb) / self::$Nb]);
        }

        return $y;
    }


    /**
     * Desencripta um bloco de texto de 16-bytes codificado pelo mÃ©todo
     * encryptBlock.
     *
     * @method decryptBlock();
     * @params string $blockDecodeText
     * @returns string
     * @since 1.0.0
     *
     */
    public function decryptBlock($blockDecodeText)
    {
        // String 16 bytes
        $x = "";


        // entrada local para o estado inicial x matriz do fim da coluna
        for($i = 0; $i < 4 * self::$Nb; $i++){
            $this->s[$i % 4][($i - $i % self::$Nb) / self::$Nb] = ord($blockDecodeText[$i]);
        }


        // Adiciona uma etapa a chave
        $this->addRoundKey($this->Nr);

        for ($i = $this->Nr - 1; $i > 0; $i--){

            // Inverte a elevaÃ§Ã£o da linha.
            $this->invShiftRows();

            // inverte o sub byte.
            $this->invSubBytes();

            // adiciona uma etapa a chave.
            $this->addRoundKey($i);

            // Inverte o embaralhamento das linhas
            $this->invMixColumns();
        }


        // Inverte a elevaÃ§Ã£o das linhas.
        $this->invShiftRows();

        // Inverte sub byte.
        $this->invSubBytes();

        // Adiciona uma etapa
        $this->addRoundKey($i);

        for($i = 0; $i < 4 * self::$Nb; $i++){
            $x .= ($this->s[$i % 4][($i - $i % self::$Nb) / self::$Nb] == chr(0) ?
                "" :
                chr($this->s[$i % 4][($i - $i % self::$Nb) / self::$Nb]));
        }

        return $x;
    }


    /**
     * Cria uma grande chave de uma pequena string.
     *
     * @method keyExpansion
     * @param string $z
     * @returns void
     * @since 1.0.0
     *
     */
    private function keyExpansion($z)
    {
        static $Rcon = array(
            0x00000000,
            0x01000000,
            0x02000000,
            0x04000000,
            0x08000000,
            0x10000000,
            0x20000000,
            0x40000000,
            0x80000000,
            0x1b000000,
            0x36000000,
            0x6c000000,
            0xd8000000,
            0xab000000,
            0x4d000000,
            0x9a000000,
            0x2f000000
        );

        $temp = 0;


        for ($i = 0; $i < $this->Nk; $i++){
            $this->w[$i] = 0;
            $this->w[$i] = ord($z[4*$i]);
            $this->w[$i] <<= 8;
            $this->w[$i] += ord($z[4*$i+1]);
            $this->w[$i] <<= 8;
            $this->w[$i] += ord($z[4*$i+2]);
            $this->w[$i] <<= 8;
            $this->w[$i] += ord($z[4*$i+3]);
        }


        for (; $i < self::$Nb *($this->Nr + 1); $i++){
            $temp = $this->w[$i-1];

            if($i % $this->Nk == 0){
                $temp = $this->subWord($this->rotWord($temp)) ^ $Rcon[$i/$this->Nk];
            }else if ($this->Nk > 6 && $i%$this->Nk == 4){
                $temp = $this->subWord($temp);
            }

            $this->w[$i] = $this->w[$i-$this->Nk] ^ $temp;

            self::make32BitWord($this->w[$i]);
        }
    }


    /**
     * Adiciona a chave um escalonador a etapa da chave.
     *
     * @method addRoundKey()
     * @param mixed $round
     * @returns void
     * @since 1.0.0
     *
     */
    private function addRoundKey($round)
    {
        $temp = "";

        for($i = 0; $i < 4; $i++){
            for($j = 0; $j < self::$Nb; $j++){
                $temp = $this->w[$round*self::$Nb+$j] >> (3-$i)*8;
                $temp %= 256;
                $temp = ($temp < 0 ? (256 + $temp) : $temp);
                $this->s[$i][$j] ^= $temp;
            }
        }
    }


    /**
     * Desenbaralha cada coluna do estado da matrix.
     *
     * @method invMixColumns()
     * @param void
     * @returns void
     * @since 1.0.0
     *
     */
    private function invMixColumns()
    {
        $s0 = $s1 = $s2 = $s3= '';

        for($i = 0; $i < self::$Nb; $i++){
            $s0 = $this->s[0][$i];
            $s1 = $this->s[1][$i];
            $s2 = $this->s[2][$i];
            $s3 = $this->s[3][$i];

            $this->s[0][$i] = $this->mult(0x0e, $s0) ^ $this->mult(0x0b, $s1) ^
                $this->mult(0x0d, $s2) ^ $this->mult(0x09, $s3);

            $this->s[1][$i] = $this->mult(0x09, $s0) ^ $this->mult(0x0e, $s1) ^
                $this->mult(0x0b, $s2) ^ $this->mult(0x0d, $s3);

            $this->s[2][$i] = $this->mult(0x0d, $s0) ^ $this->mult(0x09, $s1) ^
                $this->mult(0x0e, $s2) ^ $this->mult(0x0b, $s3);

            $this->s[3][$i] = $this->mult(0x0b, $s0) ^ $this->mult(0x0d, $s1) ^
                $this->mult(0x09, $s2) ^ $this->mult(0x0e, $s3);

        }
    }


    /** applies an inverse cyclic shift to the last 3 rows of a state matrix.
     *   @returns void
     **/
    private function invShiftRows()
    {
        $temp = "";

        for($i = 1; $i < 4; $i++){
            for ($j=0; $j<self::$Nb; $j++){
                $temp[($i+$j)%self::$Nb] = $this->s[$i][$j];
            }

            for ($j=0; $j<self::$Nb; $j++){
                $this->s[$i][$j] = $temp[$j];
            }
        }
    }

    /**
     * S inverso aplica-Box substituiÃ§Ã£o a cada byte de um estado matriz.
     *
     * @method invSubBytes()
     * @param void
     * @returns void
     * @since 1.0.0
     *
     */
    private function invSubBytes()
    {
        for($i = 0; $i < 4; $i++){
            for ($j = 0; $j < self::$Nb; $j++){
                $this->s[$i][$j] = self::$invSBox[$this->s[$i][$j]];
            }
        }
    }


    /**
     * Misturas cada coluna de um estado matriz.
     *
     * @method mixColumns()
     * @param void
     * @returns void
     * @since 1.0.0
     *
     */
    private function mixColumns()
    {
        $s0 = $s1 = $s2 = $s3= '';

        for($i = 0; $i < self::$Nb; $i++){
            $s0 = $this->s[0][$i]; $s1 = $this->s[1][$i]; $s2 =
                $this->s[2][$i]; $s3 = $this->s[3][$i];

            $this->s[0][$i] = $this->mult(0x02, $s0) ^
                $this->mult(0x03, $s1) ^
                $this->mult(0x01, $s2) ^
                $this->mult(0x01, $s3);

            $this->s[1][$i] = $this->mult(0x01, $s0) ^
                $this->mult(0x02, $s1) ^
                $this->mult(0x03, $s2) ^
                $this->mult(0x01, $s3);

            $this->s[2][$i] = $this->mult(0x01, $s0) ^
                $this->mult(0x01, $s1) ^
                $this->mult(0x02, $s2) ^
                $this->mult(0x03, $s3);

            $this->s[3][$i] = $this->mult(0x03, $s0) ^
                $this->mult(0x01, $s1) ^
                $this->mult(0x01, $s2) ^
                $this->mult(0x02, $s3);
        }
    }


    /**
     * Aplica uma mudanÃ§a cÃ­clica para as Ãºltimas 3 fileiras
     * de um estado matriz.
     *
     * @method shiftRows()
     * @param void
     * @returns void
     * @since 1.0.0
     *
     */
    private function shiftRows()
    {
        $temp = "";

        for($i = 1; $i < 4; $i++){
            for($j = 0; $j < self::$Nb; $j++){
                $temp[$j] = $this->s[$i][($j+$i) % self::$Nb];
            }

            for($j = 0; $j < self::$Nb; $j++){
                $this->s[$i][$j] = $temp[$j];
            }
        }
    }


    /**
     * Aplica S-Box substituiÃ§Ã£o a cada byte de um estado matriz.
     *
     * @method subBytes()
     * @param void
     * @returns void
     * @since
     *
     */
    private function subBytes()
    {
        for ($i = 0; $i < 4; $i++) {
            for ($j = 0; $j < self::$Nb; $j++){
                $this->s[$i][$j] = self::$sBox[$this->s[$i][$j]];
            }
        }
    }


    /**
     * Multiplica dois polinomios a(x), b(x) em GF(2^8) modulo
     * de irreducible irredutÃ­vel polinomial m(x) = x^8+x^4+x^3+x+1
     *
     * @method mult()
     * @param mixed $a
     * @param mixed $b
     * @returns string
     * @since 1.0.0
     *
     */
    private static function mult($a, $b)
    {
        $sum = self::$ltable[$a] + self::$ltable[$b];
        $sum %= 255;
        $sum = self::$atable[$sum];

        return ($a == 0 ? 0 : ($b == 0 ? 0 : $sum));
    }


    /**
     * Aplica uma permitaÃ§Ã£o ciclica para os 4 bytes inteiros.
     *
     * @method rotWord()
     * @param mixed $w
     * @returns integer
     * @since 1.0.0
     *
     */
    private static function rotWord($w)
    {
        $temp = $w >> 24;
        $w <<= 8;

        self::make32BitWord($w);

        $temp = ($temp < 0 ? (256 + $temp) : $temp);
        $w += $temp;

        return $w;
    }


    /**
     * aplica S-box substituiÃ§Ã£o cada byte dos 4 bytes word.
     *
     * @method subWord()
     * @param integer $w
     * @returns integer
     * @since 1.0.0
     *
     */
    private static function subWord($w)
    {
        $temp = 0;

        for ($i = 0; $i < 4; $i++){
            $temp = $w >> 24;

            $temp = ($temp < 0 ? (256 + $temp) : $temp);
            $w <<= 8;

            self::make32BitWord($w);
            $w += self::$sBox[$temp];
        }

        self::make32BitWord($w);

        return $w;
    }


    /**
     * reduces a 64-bit word to a 32-bit word
     *
     * @method make32BitWord()
     * @param mixed &$w
     * @returns void
     * @since 1.0.0
     *
     */
    private static function make32BitWord(&$w)
    {
        $w &= 0x00000000FFFFFFFF;
    }


    /**
     * Gera uma chave criptografica com o tamanho especificado
     * pelo parametro $key_size Ex.: AES::KEYGEN_128_BITS,
     *                               AES::KEYGEN_192_BITS,
     *                               AES::KEYGEN_256_BITS.
     *
     * @method keygen()
     * @param integer $key_size
     * @param string $sal       Incremento para geraÃ§Ã£o da chave criptogrÃ¡fica.
     * @return string
     * @since 1.0.0
     *
     */
    public function keygen($key_size, $sal = null)
    {
        $key = "";


        if($key_size == AES::KEYGEN_192_BITS){
            $x = (! is_null($sal) ? date('YmdHis'.$sal) : date('YmdHms'));
            $key = substr(md5($x), 0, AES::KEYGEN_192_BITS);

            //
            // 256 Bits
            //
        }else if($key_size == AES::KEYGEN_256_BITS){
            $x = (! is_null($sal) ? date('YmdHis'.$sal) : date('YmdHms'));
            $key = substr(md5($x), 0, AES::KEYGEN_256_BITS);

            //
            // 128 Bits
            //
        }else{
            $x = (! is_null($sal) ? date('YmdHis'.$sal) : date('YmdHms'));
            $key = substr(md5($x), 0, AES::KEYGEN_128_BITS);
        }


        return $key;
    }

    public function encode($value) {

        if($value == '') return false;

        $encrypted = strtr(base64_encode(mcrypt_encrypt($this->MCRYPT['CIPHER'], $this->key, $value, $this->MCRYPT['MODE'], $this->iv)), '+/=', '-_,');

        return $this->inverseEncryption($encrypted);

    }


    public function decode($value) {

        if($value == '') return false;

        $value = $this->reverseEncryption($value);

        $decrypted = trim(mcrypt_decrypt($this->MCRYPT['CIPHER'], $this->key, base64_decode(strtr($value, '-_,', '+/=')), $this->MCRYPT['MODE'], $this->iv));

        return $decrypted;
    }


    private function inverseEncryption($e){

        $replaceA = str_replace(',', '', $e);

        $strrev = strrev($replaceA);

        $substrA = substr($strrev, 0,15);
        $substrB = substr($strrev, 15,15);
        $substrC = substr($strrev, 30);

        $variableMounting = $substrB . $this->separator . $substrC . $this->separator . $substrA;

        return $variableMounting;
    }


    private function reverseEncryption($e){

        $exVariable = explode($this->separator, $e);

        $varA = $exVariable[0];
        $varB = $exVariable[1];
        $varC = $exVariable[2];

        $variableMounting = $varC.$varA.$varB;

        $strrev = strrev($variableMounting);

        return $strrev;
    }


    private function filterSeparator($val = NULL){

        $allowedSeparator = array(
            '!',
            '@',
            '#',
            '%',
            '&',
            '*',
            '/',
            '+',
            '=',
            '~',
            ':',
            '?'
        );

        if(in_array($val, $allowedSeparator)):
            return $val;
        else:
            return '/';
        endif;

    }

    public function EncryptAndEncode($val = NULL)
    {
        $encrypted = $this->encrypt($val);
        $encoded = $this->encode($encrypted);
        return $encoded;
    }

    public function DecryptAndDecode($val = NULL)
    {
        $decoded = $this->decode($val);
        $decrypted = $this->decrypt($decoded);
        return $decrypted;
    }


}

class RevAlgoDebug
{
    public function GetSizeOfVar($var)
    {
        $start_memory = memory_get_usage();
        $var = unserialize(serialize($var));
        return memory_get_usage() - $start_memory - PHP_INT_SIZE * 8;
    }

    public function GetKeySize($key)
    {
        return strlen($key)*32/4;
    }

    public function GetStringProportion($string1, $string2)
    {
        $len1 = strlen($string1);
        $len2 = strlen($string2);

        return $len1/$len2;
    }

    public function RandomInput($class)
    {
        switch($class)
        {
            case 1:
                return uniqid(rand(001, 999));
                break;
            case 2:
                return uniqid(rand(0001, 9999), true);
                break;
            case 3:
                return uniqid(rand(0001, 9999).microtime(true), true);
                break;
        }
    }
}