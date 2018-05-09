<?php
/**
 * Created by PhpStorm.
 * User: michael
 * Date: 2/14/18
 * Time: 5:09 PM
 */

namespace ReviewBoost\Rest\Message;
class Message {

  public static
    $to =  'To',
    $from = 'From',
    $msgStatus = 'MessageStatus',
    $errorCode = 'ErrorCode',
    $accountId = 'AccountSid',
    $body = 'Body';

  public function __construct(){
  }

  public static function to(){
    return self::$to;
  }

  public static function from(){
    return self::$from;
  }

  public static function msgStatus(){
    return self::$msgStatus;
  }
  public static function errorCode(){
    return self::$errorCode;
  }

  public static function accountId(){
    return self::$accountId;
  }

  public static function body(){
    return self::$body;
  }


}