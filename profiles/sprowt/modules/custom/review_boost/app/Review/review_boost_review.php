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

  private $table_name;

  function __construct(){
    $this->table_name = 'review_boost_review_customer_clicks';
  }

  /**
   * Fetches the class name of all review links set in Review Boost Review Settings
   *
   * @return array
   */
  public function getAllReviewLinkClasses(){

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
    $link = $row['link'];
    try{
      db_update('review_boost_review_customer_clicks')
        ->fields(array(
          "\"".trim($link)."\""=>1
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

  /**
   * @string $link
   *
   * @return bool
   *
   * Searches review_boost_review_customer_clicks for the link column name. Link must be the machine id of the custom link
   *
   */
  function checkLinkExists($link){
    $column = db_query("SELECT * FROM {information_schema.COLUMNS}
      WHERE TABLE_NAME = :tName
      AND COLUMN_NAME = :cName",
      array(
        ':tName' => 'review_boost_review_customer_clicks',
        ':cName' => $link,
      )
      )->fetchField();
    if(empty($column)){
      return false;
    }
    return true;
  }

  /**
   * @string $link
   *
   * Adds a link to a column in the review_boost_review_customer_clicks database
   *
   */
  function addLinkToTable($link){

    $field = array(
      'type' => 'int',
      'size' => 'tiny',
      'not null' => true,
      'default' => 0
    );

    db_add_field('review_boost_review_customer_clicks', $link, $field);

  }

  function updateLinkColumn($oldVal, $newVal){

    try{
      db_change_field('review_boost_review_customer_clicks',$oldVal,$newVal,array(
        'type' => 'int',
        'size' => 'tiny',
        'not null' => true,
        'default' => 0
      ));
    }catch(Exception $e){
      watchdog('Review Boost Review Error','Error updating %oldval to %newval from %table with %exception',array(
        '%oldval' => $oldVal,
        '%newval' => $newVal,
        '%table' => $this->table_name,
        '%exception' => $e
      ));
    }


  }

  function deleteLinkColumn($column){
    try{
      db_drop_field($this->table_name,$column);
    }
    catch(Exception $e){
      watchdog('Review Boost Review Error','Error deleting %column from %table with %exception',array(
        '%column' => $column,
        '%table' => $this->table_name,
        '%exception' => $e
      ));
    }
  }

  function mapLinksToToken(){
    $rb = new ReviewBoost();
    $links = $rb->getReviewLinks();
    $linkTokens = [];
    foreach($links as $link => $value){
      $token = '%'.$value['id'];
      $linkTokens[$token] = $value;
    }

    return $linkTokens;
  }

}