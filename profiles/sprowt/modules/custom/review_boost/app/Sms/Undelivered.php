<?php
/**
 * Created by PhpStorm.
 * User: michael
 * Date: 2/15/18
 * Time: 2:45 PM
 */

namespace ReviewBoost\Sms;

/**
 *
 * Base Model for Undelivered Table.
 *
 * Class Undelivered
 *
 * @package ReviewBoost\Sms
 */
class Undelivered {

  private $fields = ['phone', 'error_code', 'reviewed', 'tid'];

  public function __construct() {

  }

  public function store($row) {
   return db_insert('review_boost_undelivered')
      ->fields($row)
      ->execute();
  }
}
