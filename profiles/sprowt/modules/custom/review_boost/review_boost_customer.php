<?php
/**
 * Created by PhpStorm.
 * User: michael
 * Date: 9/7/17
 * Time: 4:34 PM
 */

class ReviewBoostCustomer {

  private $email_optout_status,
          $sms_optout_status,
          $customer_phone_exists,
          $customer_email_exists,
          $errors = array();
  public function __construct(){

  }

  /**
   * @param $email
   * Updates the table review_boost_customer, sets email_optout to TRUE based on email and prints message to screen.
   */
  function updateEmailOptOut($email){
    $query = db_query("UPDATE {review_boost_customer} SET email_optout = :optout WHERE email = :email",
      array(
        ':optout' => 1,
        ':email' => $email
      ));

    if($query){
      drupal_set_message(t('Updated successfully!'));
    }else{
      drupal_set_message(t('Something went wrong.'));
    }
  }

  /**
   * @param $phone
   * @param $optoutStatus
   *
   * @return bool
   */
  function updateSMSOptStatus($phone,$optoutStatus){
    $query = db_query("UPDATE {review_boost_customer} SET sms_optout = :optout WHERE customer_phone = :phone",
      array(
        ':optout' => $optoutStatus,
        ':phone' => $phone
      ));

    if($query){
      return TRUE;
    }
    else{
      return FALSE;
    }
  }

  function getCustomerByPhone($phone){
    $result = db_query("SELECT distinct(customer_phone), sms_optout FROM {review_boost_customer}
          WHERE customer_phone = :phone",
      array(
        ':phone' => $phone
      ))->fetchAssoc();
    if($result && $phone != "" && $phone != null){
      return $result;
    }
    return false;
  }

  function getCustomerByEmail($email){
    $result = db_query("SELECT distinct(email), email_optout FROM {review_boost_customer}
          WHERE email = :email",
      array(
        ':email' => $email
      ))->fetchAssoc();
    if($result && $email != "" && $email != null){
      return $result;
    }
    return false;
  }

  /**
   * @param $value
   *
   * @return bool
   */
  public function optOutStatus($value){
    return $value === 1 ? true : false;
  }



  /**
   * @param $email
   *
   * @return bool
   * returns true if customer email is valid and optout is 1
   */
  function checkEmailOptOut($email){
    $result = db_query("SELECT distinct(email), email_optout FROM {review_boost_customer}
          WHERE email = :email AND email_optout = :optout",
      array(
        ':email' => $email,
        ':optout' => 1
      ))->fetchField();

    if($result){
      return TRUE;
    }
    return FALSE;
  }

  /**
   * @param $phone
   *
   * @return bool
   * returns true if customer phone is valid and optout is 1
   */
  function checkSMSOptOut($phone){
    $result = db_query("SELECT distinct(customer_phone), sms_optout FROM {review_boost_customer}
          WHERE customer_phone = :phone AND sms_optout = :optout",
      array(
        ':phone' => $phone,
        ':optout' => 1
      ))->fetchField();

    if($result){
      return TRUE;
    }
    return FALSE;
  }

  /**
   * Called after db query to lazy load variable.
   *
   * @return bool
   * returns private bool $email_optout_status
   *
   *
   */
  function getEmailOptOutStatus(){
    return $this->email_optout_status;
  }

  /**
   * Called after db query to lazy load variable.
   *
   * @return bool
   * returns private bool $sms_optout_status
   *
   *
   */
  function getSMSOptOutStatus(){
    return $this->sms_optout_status;
  }

  function getAll(){
    $query = db_query('SELECT * FROM {review_boost_customer}')->fetchAllAssoc('id');
    return $query;
  }

  /**
   * Defines error messages for customer survey opt out's.
   *
   * @param $cID
   * The customer id
   * @param $emailOptStatus
   * The current email optout status. Must be set before.
   * @param $SMSOptStatus
   * The current SMS optout status. Must be set before.
   */
  function setErrors($cID, $emailOptStatus, $SMSOptStatus){

    if($emailOptStatus && $SMSOptStatus){
      $this->errors['optout_all'] = 'Customer '. $cID . ' has requested to opt out of all survey\'s.';
    }elseif($SMSOptStatus){
      $this->errors['optout_sms'] = 'Customer '. $cID . ' has requested to opt out of SMS survey\'s.';
    }elseif($emailOptStatus){
      $this->errors['optout_email'] = 'Customer '. $cID . ' has requested to opt out of Email survey\'s.';
    }
  }

  /**
   * @return array
   */
  function getErrors(){
    return $this->errors;
  }
}