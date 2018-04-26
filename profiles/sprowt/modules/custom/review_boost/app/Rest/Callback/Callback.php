<?php
/**
 * Created by PhpStorm.
 * User: michael
 * Date: 2/13/18
 * Time: 4:57 PM
 */

namespace ReviewBoost\Rest\Callback;

use ReviewBoost\ReviewBoost;
use ReviewBoost\Sms\ReviewBoostSMS;
use ReviewBoost\Customer\ReviewBoostCustomer;
use ReviewBoost\Rest\Respond\Respond;
use ReviewBoost\Rest\Message\Message;
use Exception;
//todo Refactor callbacks from module file to here. Make less coupled
class Callback {

  private $request;



  public function __construct(){
    //$this->request = $request;
  }

  public function handleCallback($data,$callbackType){
    if($callbackType === 'email'){

    }
  }

  public function getRequest(){
    return $this->request;
  }

  public function testRequest(){
    return Message::to();
  }


  public function getCallbackType(){
    return $this->request[Message::msgStatus()];
  }

  public function checkIfUndelivered(){

    if(!empty($this->request[Message::errorCode()])){
      return true;
    }
    return false;
  }

  public function storeUndelivered(){
    $undelivered = array(
      Message::to() => $this->request[Message::to()],
      Message::from() => $this->request[Message::from()],
      Message::msgStatus() => $this->request[Message::msgStatus()],
      Message::errorCode() => $this->request[Message::errorCode()],
      Message::accountId() => $this->request[Message::accountId()]
    );
    variable_set('undeliveredMessage',$undelivered);

    watchdog('review_boost_sms','A message was not delivered to the phone %phone. %error',array(
      '%phone' => $this->request[Message::to()],
      '%error' => json_encode($undelivered)
    ));
  }

  /**
   *
   * Inserts an array of values into a row
   *
   * @param $row
   */
  function insert($row){

    try{
      db_insert('review_boost_callback')->fields($row)->execute();
    }
    catch(Exception $e){
      watchdog_exception('Review Boost Insert Exception', $e, 'Error inserting row into review_boost_callback database for customer with tid: %tid',
        array(
          '%tid'=>$row['tid']
        ));
    }

  }

  function update($row){
    try{
      db_update('review_boost_callback')
        ->fields($row)
        ->condition('tid', $row['tid'])
        ->execute();
    }
    catch(Exception $e){
      watchdog_exception('Review Boost Update Exception', $e, 'Error updating column %column into review_boost_customer_clicked_links database for customer with tid: %tid',
        array(
          '%column'=>$row['link'],
          '%tid'=>$row['tid']
        ));
    }

  }

  function checkIfExists($tid){

    try{
      $tid = db_query("SELECT tid FROM {review_boost_callback}
          WHERE tid = :tid",
        array(
          ':tid' => $tid
        ))->fetchField();
    }
    catch(Exception $e){

    }

    return $tid;
  }

}