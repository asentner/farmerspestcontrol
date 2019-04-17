<?php
/**
 * Created by PhpStorm.
 * User: michael
 * Date: 6/20/18
 * Time: 4:53 PM
 */



class PestPacOauth{

  protected $grantType;
  protected $wwidUser;
  protected $wwidPass;
  protected $clientId;
  protected $secret;
  protected $authUrl;
  protected $cookie_name='pp_token';

  public function __construct($grantType = 'password'){
    $this->wwidUser = variable_get('pestpac_wwid');
    $this->wwidPass = variable_get('pestpac_wwidpass');
    $this->clientId = variable_get('pestpac_client_id');
    $this->secret   = variable_get('pestpac_client_secret');
    $this->authUrl = 'https://is.workwave.com/oauth2/token?scope=openid';
    $this->grantType = $grantType;
  }

  function encodeToken(){
    $clientId = $this->clientId;
    $secret = $this->secret;
    return base64_encode("$clientId:$secret");
  }

  function getGrantType(){
    return $this->grantType;
  }

  function getData(){
    return
      $data = array(
      'grant_type' => $this->getGrantType(),
      'username' => $this->wwidUser,
      'password' => $this->wwidPass
    );
  }

  function authenticate(){

    $headers = array(
      'Content-Type' =>  'application/x-www-form-urlencoded; charset=utf-8',
      'Authorization' => 'Bearer ' . $this->encodeToken()
    );
    $pp = new PestPacApi();

    $response = $pp->curl($this->authUrl,$this->getData(),$headers,'post');
    if($response['code'] === 200){
      $jsonOutput = json_decode($response['response'],true);
      $token = $jsonOutput["access_token"];
      variable_set('pestpac_access_token',$token);
      return true; //authenticated
    }

    return false;
  }


}