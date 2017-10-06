<?php
/**
 * Created by PhpStorm.
 * User: michael
 * Date: 9/4/17
 * Time: 1:35 AM
 */

require __DIR__ . '/vendor/autoload.php';
require_once drupal_get_path('module','review_boost') . '/review_boost.php';
require_once drupal_get_path('module','review_boost') . '/google_url_api.php';

use Twilio\Rest\Client;

class ReviewBoostSMS {

  private $message,
    $disabled = false,
    $auth_token,
    $account_id,
    $phone,
    $twilio_admin_phone,
    $googleAPIKey,
    $formToken;

  public function __construct($formToken = ''){
    $this->account_id = variable_get('twilio_admin_account_id');
    $this->auth_token = variable_get('twilio_admin_auth_token');
    $this->twilio_admin_phone = variable_get('twilio_admin_phone');
    $this->googleAPIKey = 'AIzaSyDbpRFE6lP5WGIT07GlcAe-3XQ7MZS9AnI';
    $this->formToken = $formToken;
  }

  //Default Twilio template.
  public function sendSMS($customerPhone){

    $client = new Client($this->account_id, $this->auth_token);
    $messages = $client->messages->create($customerPhone, array(
      'From' => $this->twilio_admin_phone,
      'mediaUrl' => $this->fetchImageURI('twilio_image'),
      'Body' => $this->getTokenizedMsg(),
    ));
  }

  public function sendReply($phone,$msg){

    $client = new Client($this->account_id, $this->auth_token);

    $messages = $client->messages->create($phone, array(
      'From' => $this->twilio_admin_phone,
      'Body' => $msg
    ));
  }

  /**
   * @return mixed
   *
   * Calls Review Boost Class to map values based on tokens and customer csv data
   */
  public function getTokenizedMsg(){
    $RB = new ReviewBoost($this->formToken);
    $message = $RB->translateValues(variable_get('twilio_admin_message'),array(),TRUE);
    return $message;
}

  //not sure if we'll be needing this, but it'll be useful to have.
  public function sanitizeMessage($msg){
    $clear = trim(preg_replace('/ +/', ' ',
      preg_replace('/[^A-Za-z0-9 ]/', ' ',
        urldecode(html_entity_decode(strip_tags($msg))))));
    return $clear;
  }

  /**
   * @param $phone
   *
   * @return mixed
   *
   * Returns phone number stripped of all characters and any leading "1"
   */
  public function validatePhone($phone){
    if(empty($phone)){
      return false;
    }
    $sanitizeNum = preg_replace('/\D/',"",$phone);
    $newPhone = preg_replace('/^1/', "", $sanitizeNum); //who dis
    return $newPhone;
  }

  /**
   * @param $phone
   * adds +1 to a formatted phone number for twilio messaging
   */
  public function setPhone($phone){
    $this->phone = "+1".$phone;
  }
  /**
   * @return mixed
   * returns full phone number
   */
  public function getPhone(){
    return $this->phone;
  }

  /**
   * @param $imgVarName
   *
   * @return bool|string
   *
   * Returns url of an image
   */
  public function fetchImageURI($imgVarName){

    if(!empty(variable_get($imgVarName))){
      $img_id = variable_get($imgVarName);
      $img = file_load($img_id);
      $url = file_create_url($img->uri);
      return $url;
    }
    return false;
  }

  /**
   * @param $url
   *
   * @return bool
   *
   * Shortens URL
   */
  public function shortenURL($url){
    $googer = new GoogleUrlApi($this->googleAPIKey);
    $shortUrl = $googer->shorten($url);
    return $shortUrl;
  }
}