<?php
/**
 * Created by PhpStorm.
 * User: michael
 * Date: 3/27/18
 * Time: 4:54 PM
 */

namespace ReviewBoost\Review;
use ReviewBoost\ReviewBoost;
use Exception;

class ReviewBoostReview {

  function __construct(){}

  /**
   * Fetches the class name of all review links set in Review Boost Review Settings
   *
   * @return array
   */
  public function getAllReviewLinks(){

    $rb = new ReviewBoost();
    $links = $rb->getReviewLinks();
    $linkClass = [];
    foreach($links as $link => $value){
      $linkClass[] = $value['class'];
    }
    return $linkClass;

  }

  /**
   *
   * Inserts an array of values into a row
   *
   * @param $row
   */
  function insert($row){

      try{
        db_insert('review_boost_review_customer_clicks')->fields($row)->execute();
      }
      catch(Exception $e){
        watchdog_exception('Review Boost Insert Exception', $e, 'Error inserting row into review_boost_customer_clicked_links database for customer with tid: %tid',
          array(
            '%tid'=>$row['tid']
          ));
      }
  }

  //todo make this less coupled. Maybe iterate over the row array
  function update($row){
    try{
      db_update('review_boost_review_customer_clicks')
        ->fields(array(
          $row['link']=>1
        ))
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

  /**
   * Queries the review_boost_review_customer_clicks table for a tid and returns true/false if exists
   *
   * @param $tid
   *
   * @return bool
   */
  function checkUserExists($tid){
    $user = db_query("SELECT tid FROM {review_boost_review_customer_clicks}
      WHERE tid = :tid",
    array(
      ':tid'=>$tid
    ))->fetchField();
    if(empty($user)){
      return false;
    }
    return true;
  }

  function logUserClick($token,$link){

  }

}