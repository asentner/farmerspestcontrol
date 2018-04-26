<?php
/**
 * Created by PhpStorm.
 * User: michael
 * Date: 9/4/17
 * Time: 1:35 AM
 */

namespace ReviewBoost\Sms;

use ReviewBoost\Libs\ReviewBoostUrlApi;
use ReviewBoost\ReviewBoost;
use Twilio\Rest\Client;

class ReviewBoostSMS {

  private
    $message,
    $auth_token,
    $account_id,
    $phone,
    $twilio_admin_phone,
    $googleAPIKey,
    $formToken;

  public function __construct($formToken = '') {
    $this->account_id = variable_get('twilio_admin_account_id');
    $this->auth_token = variable_get('twilio_admin_auth_token');
    $this->twilio_admin_phone = variable_get('twilio_admin_phone');
    $this->googleAPIKey = 'AIzaSyDbpRFE6lP5WGIT07GlcAe-3XQ7MZS9AnI'; //limited to 1,000,000 requests per day.
    $this->formToken = $formToken;
  }

  public function testCallback(){
    $url = (!empty($_SERVER['HTTPS']) ? 'https' : 'http') . '://' . $_SERVER['HTTP_HOST'] . '/';
    return $url . 'sms/callback';
  }

  /**
   * @param $customerPhone
   *
   * Sends message to client via Twilio API
   */
  public function sendSMS($customerPhone) {
    $url = (!empty($_SERVER['HTTPS']) ? 'https' : 'http') . '://' . $_SERVER['HTTP_HOST'] . '/';

    $msgContent = [
      'From' => $this->twilio_admin_phone,
      'Body' => $this->getTokenizedMsg(),
      'statusCallback' => $url . 'sms/callback',
    ];
    //check if image has been uploaded and include with sms button checked
    if (!empty($this->fetchImageURI('twilio_image'))) {
      if ($this->getImageToggleStatus()) {
        $msgContent['mediaUrl'] = $this->fetchImageURI('twilio_image');
      }
    };
    $client = new Client($this->account_id, $this->auth_token);
    $messages = $client->messages->create($customerPhone, $msgContent);//send
  }

  /**
   * @param $phone
   * @param $msg
   *
   * Sends a reply back to a client
   */
  public function sendReply($phone, $msg) {
    $client = new Client($this->account_id, $this->auth_token);
    $messages = $client->messages->create($phone, [
      'From' => $this->twilio_admin_phone,
      'Body' => $msg,
    ]);
  }

  /**
   * @return mixed
   *
   * Calls Review Boost Class to map values based on tokens and customer csv
   *   data
   */
  public function getTokenizedMsg() {
    $RB = new ReviewBoost($this->formToken);
    $message = $RB->translateValues(variable_get('twilio_admin_message'), [], TRUE);
    return $message;
  }

  /**
   * @param $msg
   *
   * @return string
   *
   * Returns a string stripped of everything but numbers.
   */
  //I don't think we will be using this, but it could be useful to have in the future
  public function sanitizeMessage($msg) {
    $clear = trim(preg_replace('/ +/', ' ',
      preg_replace('/[^A-Za-z0-9 ]/', ' ',
        urldecode(html_entity_decode(strip_tags($msg))))));
    return $clear;
  }

  /**
   * @param $phonegoogle_url_api
   *
   * @return mixed
   *
   * Returns phone number stripped of all characters and any leading "1"
   */
  public function validatePhone($phone) {
    if (empty($phone)) {
      return FALSE;
    }
    $sanitizeNum = preg_replace('/\D/', "", $phone);
    $newPhone = preg_replace('/^1/', "", $sanitizeNum); //who dis
    return $newPhone;
  }

  /**
   * @param $phone
   * adds +1 to a formatted phone number for twilio messaging
   */
  public function setPhone($phone) {
    $this->phone = "+1" . $phone;
  }

  /**
   * @return mixed
   * returns full phone number
   */
  public function getPhone() {
    return $this->phone;
  }

  /**
   * @param $imgVarName
   *
   * @return bool|string
   *
   * Returns url of an image
   */
  public function fetchImageURI($imgVarName) {

    if (!empty(variable_get($imgVarName))) {
      $img_id = variable_get($imgVarName);
      $img = file_load($img_id);
      $url = file_create_url($img->uri);
      return $url;
    }
    return FALSE;
  }

  /**
   * @param $url
   *
   * @return bool
   *
   * Shortens URL
   */
  public function shortenURL($url) {
    $googer = new ReviewBoostUrlApi($this->googleAPIKey);
    $shortUrl = $googer->shorten($url);
    return $shortUrl;
  }

  public function getImageToggleStatus() {
    return variable_get('twilio_admin_toggle_image');
  }
}