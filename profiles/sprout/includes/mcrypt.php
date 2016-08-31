<?php

Class Mcrypt {
    
    private $td;
    private $ks;
    private $key;
    private $iv;
    private $iv_size;
    
    function __construct(){
        $td = $this->td = mcrypt_module_open('rijndael-256', '', 'ofb', '');
        $ks = $this->ks = mcrypt_enc_get_key_size($td);
        $key = $this->key = substr(md5('Mumford and Sons sing the Boxer'), 0, $ks);
        
        $iv_size = $this->iv_size = mcrypt_enc_get_iv_size($td);
        
        $iv = $this->iv = mcrypt_create_iv($iv_size);
    }
    
    function encrypt($str){
        mcrypt_generic_init($this->td, $this->key, $this->iv);
        $encrypted = mcrypt_generic($this->td, $str);
        
        return base64_encode($encrypted . $this->iv);
    }
    
    function decrypt($base64str){
        $basestr = base64_decode($base64str);
        $iv = substr($basestr, 0 - $this->iv_size);
        $encrypted = substr($basestr, 0, strlen($basestr) - $this->iv_size);
        
        mcrypt_generic_init($this->td, $this->key, $iv);
        
        $decrypted = mdecrypt_generic($this->td, $encrypted);
        
        return trim($decrypted);
    }
}