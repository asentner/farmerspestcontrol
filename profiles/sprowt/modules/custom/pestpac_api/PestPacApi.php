<?php
/**
 * Created by PhpStorm.
 * User: michael
 * Date: 8/22/18
 * Time: 2:44 PM
 */

require_once drupal_get_path('module', 'pestpac_api') . '/PestPacOauth.php';

class PestPacApi extends PestPacOauth {

  protected $wwidUser;
  protected $wwidPass;
  protected $clientId;
  protected $secret;
  protected $apiKey;
  protected $baseUrl;
  protected $tenantId;

  function __construct(){

    parent::__construct();
    $this->apiKey = variable_get('pestpac_api_key');
    $this->baseUrl = "https://api.workwave.com/pestpac/v1";
    $this->tenantId = variable_get('pestpac_tenant_id');
  }

  function getUser(){
    return $this->wwidUser;
  }

  function getPass(){
    return $this->wwidPass;
  }

  function getClientId(){
    return $this->clientId;
  }

  function getSecret(){
    return $this->secret;
  }

  function getToken(){
    if(variable_get('pestpac_access_token')){
      return variable_get('pestpac_access_token');
    }
    return false;
  }


  function curl($url, $data = array(), $headers = array(), $method = 'get', $debug = false,$json = false){
    if(!empty($data)) {
      if($json){
        $param_string = json_encode($data);
      }else{
        $param_string = http_build_query($data, null, '&');
      }
    }
    else {
      $param_string = '';
    }

    $ch = curl_init();
    curl_setopt($ch, CURLOPT_URL, $url);
    curl_setopt($ch, CURLOPT_CONNECTTIMEOUT, 10);
    curl_setopt($ch, CURLOPT_TIMEOUT, 15);

    curl_setopt($ch, CURLOPT_RETURNTRANSFER, true);

    if(!empty($headers)) {
      $headersStringArray = array();
      foreach($headers as $k => $v) {
        $headersStringArray[] = "$k: $v";
      }
      curl_setopt($ch, CURLOPT_HTTPHEADER, $headersStringArray);
    }

    if($debug) {
      curl_setopt($ch, CURLOPT_COOKIE, 'XDEBUG_SESSION=PHPSTORM');
    }
    switch($method) {
      case 'post':
        curl_setopt($ch, CURLOPT_POST, 1);
        curl_setopt($ch, CURLOPT_POSTFIELDS, $param_string);
        break;
      case 'put':
        curl_setopt($ch, CURLOPT_RETURNTRANSFER, true);
        curl_setopt($ch, CURLOPT_CUSTOMREQUEST, "PUT");
        curl_setopt($ch, CURLOPT_POSTFIELDS, $param_string);
        break;
      case 'patch':
        curl_setopt($ch, CURLOPT_RETURNTRANSFER, true);
        curl_setopt($ch, CURLOPT_CUSTOMREQUEST, "PATCH");
        curl_setopt($ch, CURLOPT_POSTFIELDS, $param_string);
        break;
      case 'delete':
        curl_setopt($ch, CURLOPT_CUSTOMREQUEST, "DELETE");
        curl_setopt($ch, CURLOPT_POSTFIELDS, $param_string);
        break;
      default:
        curl_setopt($ch, CURLOPT_CUSTOMREQUEST, "GET");
    }


    curl_setopt($ch, CURLOPT_SSL_VERIFYPEER, false);

    $result = curl_exec($ch);
    $httpcode = curl_getinfo($ch, CURLINFO_HTTP_CODE);
    curl_close($ch);
    if($httpcode === 401){
      $auth = $this->authenticate();

      if($auth){
        watchdog("CTM_PestPac_Sync_Error","Error authenticating PestPac credentials! API was re-authenticated! Here's the data that was coming in: %d",array(
          "%d" => print_r($result,true)
        ));
      }else{
        watchdog("CTM_PestPac_Sync_Error","Error authenticating PestPac credentials! API was NOT re-authenticated! Here's the data that was coming in: %d",array(
          "%d" => print_r($result,true)
        ));
      }
      return $this->curl($url,$data,$headers,$method,$debug,$json);

    }
    else{
      if($httpcode === 500){
        $auth = $this->authenticate();
        return $this->curl($url,$data,$headers,$method,$debug,$json);
        //watchdog("CTM_PestPac_Sync_Error","500 Error while attempting a curl resource.");
      }else{
        return array(
          'code' => $httpcode,
          'response' => $result
        );
      }
    }
  }

  /**
   * @param $entity
   *  Array containing:
   *  "id" => (optional) the id for the entity
   *  "name" => (optional) the name for the entity
   *  "entityUrl" => (optional, but required if not including id & name) the complete entity url (includes name and id)
   *
   * @return array|mixed
   *  Array containing the requested entity
   *
   * Get an entity from PestPac
   */
  function get($entity,$all = false){

    if(!empty($entity["entityUrl"])){
      $url = $entity["entityUrl"];
    }else if($all){
      $url = $this->baseUrl."/".$entity["name"];
    }
    else{
      $url = $this->baseUrl."/".$entity["name"]."/".$entity["id"];
    }

    $headers = array(
      'Content-Type' => 'application/json',
      'Apikey' => $this->apiKey,
      'tenant-id' => $this->tenantId,
      'Authorization' => 'Bearer ' . $this->getToken()
    );

    try{
      $response = $this->curl($url,array(),$headers,'get',true,true);
    }catch(Exception $e){
      watchdog('CTM_PestPac_Exception','Error fetching entity: %e',array(
        '%e' => $e
      ));
    }

    if($response['code'] == 200) {
      $json_output = json_decode($response['response'], true);
      return $json_output;
    }
    return $response;
  }

  function webhookResource($method,$postfields=array(),$webhookUri = ""){
    if(!empty($webhookUri)){
      $url = $this->baseUrl."/webhooks".$webhookUri;
    }else{
      $url = $this->baseUrl."/webhooks";
    }

    $headers = array(
      'Content-Type' => 'application/json',
      'Apikey' => $this->apiKey,
      'tenant-id' => $this->tenantId,
      'Authorization' => 'Bearer ' . $this->getToken()
    );

    try{
      $response = $this->curl($url,$postfields,$headers,$method,true,true);
    }catch(Exception $e){
      watchdog('CTM_PestPac_Exception','Error with webhook resource: %e',array(
        '%e' => $e
      ));
    }

    //for validation purposes, return full response if creating (post) webhook
    if($method === 'post'){
      return $response;
    }

    if($response['code'] == 200) {
      $json_output = json_decode($response['response'], true);
      return $json_output;
    }
    return $response;
  }

  /**
   * @param $uri
   * @param string $method
   * @param array $postfields
   *
   * @return array|mixed
   *
   * CRUD handler for PestPac Calls.
   */
  function callResource($uri, $postfields=array(), $method='post'){
    $url = $this->baseUrl . $uri;
    $headers = array(
      'Content-Type' => 'application/json',
      'Apikey' => $this->apiKey,
      'tenant-id' => $this->tenantId,
      'Authorization' => 'Bearer ' . $this->getToken()
    );

    try{
      $response = $this->curl($url,$postfields,$headers,$method,true,true);
    }catch(Exception $e){
      watchdog('CTM_PestPac_Exception','Error Creating Call: %e',array(
        '%e' => $e
      ));
    }

    if($response['code'] == 200) {
      $json_output = json_decode($response['response'], true);
      return $json_output;
    }
    return $response;

  }

  function leadResource($uri, $postfields,$method='post'){
    $url = $this->baseUrl . $uri;
    $headers = array(
      'Content-Type' => 'application/json',
      'Apikey' => $this->apiKey,
      'tenant-id' => $this->tenantId,
      'Authorization' => 'Bearer ' . $this->getToken()
    );

    $response = $this->curl($url,$postfields,$headers,$method,true,true);
    if($response['code'] == 200) {
      $json_output = json_decode($response['response'], true);
      return $json_output;
    }
    return $response;
  }

  function createLocation($postfields,$method='post'){
    $endpoint = '/Locations';
    $url = $this->baseUrl . $endpoint;
    $headers = array(
      'Content-Type' => 'application/json',
      'Apikey' => $this->apiKey,
      'tenant-id' => $this->tenantId,
      'Authorization' => 'Bearer ' . $this->getToken()
    );

    $response = $this->curl($url,$postfields,$headers,$method,true,true);
    if($response['code'] == 200) {
      $json_output = json_decode($response['response'], true);
      return $json_output;
    }
    return false;
  }

  function checkLocationExists($phone){
    $endpoint = '/Locations?q='.$phone;
    $url = $this->baseUrl.$endpoint;
    $headers = array(
      'Apikey' => $this->apiKey,
      'tenant-id' => $this->tenantId,
      'Authorization' => 'Bearer ' . $this->getToken()
    );
    $data = [];
    $response = $this->curl($url,$data,$headers,'get',true);
    if($response['code'] == 200) {
      $json_output = json_decode($response['response'], true);
      return $json_output;
    }
    return false;
  }

  function checkBillTosExists($phone){
    $endpoint = '/BillTos?q='.$phone;
    $url = $this->baseUrl.$endpoint;
    $headers = array(
      'Apikey' => $this->apiKey,
      'tenant-id' => $this->tenantId,
      'Authorization' => 'Bearer ' . $this->getToken()
    );
    $data = [];
    $response = $this->curl($url,$data,$headers,'get',true);
    if($response['code'] == 200) {
      $json_output = json_decode($response['response'], true);
      return $json_output;
    }
    return false;
  }

  //todo add method validation
  //
  function invoiceResource($options = array()){
    $endpoint = '/Invoices';
    $url = $this->baseUrl.$endpoint;
    $headers = array(
      'Apikey' => $this->apiKey,
      'tenant-id' => $this->tenantId,
      'Authorization' => 'Bearer ' . $this->getToken()
    );
    $data = [];
    $response = $this->curl($url,$data,$headers,'get',true);
    if($response['code'] == 200) {
      $json_output = json_decode($response['response'], true);
      return $json_output;
    }
    return false;
  }

  function billToResource($uri, $postfields=array(), $method='get'){
    $url = $this->baseUrl . $uri;
    $headers = array(
      'Content-Type' => 'application/json',
      'Apikey' => $this->apiKey,
      'tenant-id' => $this->tenantId,
      'Authorization' => 'Bearer ' . $this->getToken()
    );
    $response = $this->curl($url,$postfields,$headers,$method,true,true);

    if($response['code'] == 200) {
      $json_output = json_decode($response['response'], true);
      return $json_output;
    }
    return $response;
  }

  function locationResource($uri,$postfields=array(),$method='get'){
    $url = $this->baseUrl . $uri;
    $headers = array(
      'Content-Type' => 'application/json',
      'Apikey' => $this->apiKey,
      'tenant-id' => $this->tenantId,
      'Authorization' => 'Bearer ' . $this->getToken()
    );
    $response = $this->curl($url,$postfields,$headers,$method,true,true);

    if($response['code'] == 200) {
      $json_output = json_decode($response['response'], true);
      return $json_output;
    }
    return $response;
  }

}