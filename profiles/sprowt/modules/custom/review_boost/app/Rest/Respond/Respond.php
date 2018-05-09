<?php
/**
 * Created by PhpStorm.
 * User: michael
 * Date: 2/13/18
 * Time: 4:57 PM
 */

namespace ReviewBoost\Rest\Respond;

use ReviewBoost\ReviewBoost;
use ReviewBoost\Sms\ReviewBoostSMS;
use ReviewBoost\Customer\ReviewBoostCustomer;
use ReviewBoost\Rest\Message\Message;
class Respond {

  private $request;

  public function __construct($request){
    $this->request = $request;
  }

  public function verifyAccountId(){
    $id = $this->request[Message::accountId()];
    if($id === variable_get('twilio_admin_account_id')){
      return true;
    }
    return false;
  }

  public function getCustomerPhone(){
    return $this->request[Message::from()];
  }

  public function getResponseBody(){
    return $this->request[Message::body()];
  }

  public function formatResponseBody(){
    return strtolower(trim($this->getResponseBody()));
  }

  public function responseError(){
    return watchdog('review_boost_sms','Error processing response for phone: %phone. Twilio Account sID does not match.',array(
      '%phone'=>$this->request[Message::from()]
    ));
  }
}