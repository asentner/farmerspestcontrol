<?php
/**
 * Created by PhpStorm.
 * User: michael
 * Date: 2/15/18
 * Time: 10:21 AM
 */

namespace ReviewBoost\Customer;

use ReviewBoost\Sms\ReviewBoostSMS;

class ReviewBoostToken {

  public function __construct(){

  }


  /**
   * Retrieves a row from the Token table based on email.
   *
   * @param $email
   *
   * @return bool
   */
  public function getByEmail($email){

    $result = db_query("SELECT * FROM {review_boost_token}
        WHERE email = :email",
      array(
        ':email' => $email
      ))->fetchAssoc();
    if($result && $email != "" && $email != null){
      return $result;
    }
    return false;

  }

  public function getByPhone($phone){
    $sms = new ReviewBoostSMS();
    $phone = $sms->validatePhone($phone);
    $result = db_query("SELECT * FROM {review_boost_token}
        WHERE customer_phone = :customer_phone",
      array(
        ':customer_phone' => $phone
      ))->fetchAssoc();
    if($result && $phone != "" && $phone != null){
      return $result;
    }
    return false;
  }

  /**
   * Fetch a user's tid by their token
   *
   * @param $token
   *
   * @return string
   */
  public static function fetchUserTid($token){
    $tid = '';
    try{
      $tid = db_query("SELECT tid FROM {review_boost_token}
          WHERE token = :token",
        array(
          ':token' => $token
        ))->fetchField();
    }
    catch(Exception $e){
      watchdog_exception('Review Boost Query Exception', $e, 'The token was not found in the database: %token',
        array(
          '%token'=>$token
        ));
    }

    return $tid;
  }
}