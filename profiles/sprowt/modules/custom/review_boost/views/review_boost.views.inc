<?php

use ReviewBoost\ReviewBoost as ReviewBoost;
/**
 * Implements hook_views_data
 */

function review_boost_views_data(){

  $data['review_boost_callback'] = callbackTable();
  $data['review_boost_token'] = tokenTable();
  $data['review_boost_review_customer_clicks'] = customerClicksTable();


  return $data;

}

/**
 *
 * Defines the review_boost_callback table fields in views
 *
 * @return mixed
 */
function callbackTable(){
  $data['table']['group'] = t('Review Boost Callback');


  $data['table']['base'] = array(
    'field' => 'id',
    'title' => t('Review Boost Callback'),
    'help' => t('This table contains callbacks for the Review Boost module'),
    'weight' => -10,
  );

  $data['table']['join'] = array(

    'review_boost_token' => array(
      'left_field' => 'tid',
      'field' => 'tid',
    ),
  );

  $data['id'] = array(
    'title' => t('id'),
    'help' => t('The id of the row'),
    'field' => array(
      'handler' => 'views_handler_field_numeric',
      'click sortable' => TRUE,
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_numeric',
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
  );

  $data['sms_delivered'] = array(
    'title' => t('sms delivered'),
    'help' => t('Field for displaying if an sms was delivered'),
    'field' => array(
      'handler' => 'views_handler_field_boolean',
      'click sortable' => TRUE,
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_boolean_operator',
      'label' => t('Published'),
      'type' => 'yes-no',
      'use equal' => TRUE,
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
  );

  $data['email_delivered'] = array(
    'title' => t('email delivered'),
    'help' => t('Field for displaying if an email was delivered'),
    'field' => array(
      'handler' => 'views_handler_field_boolean',
      'click sortable' => TRUE,
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_boolean_operator',
      'label' => t('Published'),
      'type' => 'yes-no',
      'use equal' => TRUE,
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
  );

  $data['error_code'] = array(
    'title' => t('error code'),
    'help' => t('NOTE: Avoid using for now. Field is not currently getting populated. Displays the error code associated with a twilio callback error response'),
    'field' => array(
      'handler' => 'views_handler_field',
      'click sortable' => TRUE,
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_string',
    ),
    'argument' => array(
      'handler' => 'views_handler_argument_string',
    ),
  );

  $data['reviewed'] = array(
    'title' => t('reviewed'),
    'help' => t('NOTE: Avoid using for now. Field is not currently getting populated. Displays if an administrator has viewed the callback response'),
    'field' => array(
      'handler' => 'views_handler_field_boolean',
      'click sortable' => TRUE,
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_boolean_operator',
      'label' => t('Published'),
      'type' => 'yes-no',
      'use equal' => TRUE,
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
  );

  $data['tid'] = array(
    'title' => t('tid'),
    'help' => t('The tid for the row. This is used to relate to the main token table.'),
    'relationship' => array(
      'base' => 'review_boost_token',
      'base field' => 'tid',
      'handler' => 'views_handler_relationship',
      'label' => t('Reviewboost Callback Token Relationship'),
      'title' => t('Reviewboost Callback Token Relationship'),
      'help' => t('This adds a relationship to the review_boost_token table.'),
    ),
    'field' => array(
      'handler' => 'views_handler_field_numeric',
      'click sortable' => TRUE,
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_numeric',
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),

  );

  return $data;
}

/**
 *
 * Defines the review_boost_token table in views
 *
 * @return mixed
 */
function tokenTable(){
  $data['table']['group'] = t('Review Boost Token');

  $data['table']['base'] = array(
    'field' => 'id', // This is the identifier field for the view.
    'title' => t('Review Boost Token'),
    'help' => t('This table contains base information for each user'),
    'weight' => -9,
  );


  $data['token'] = array(
    'title' => t('Token'),
    'help' => t('The token of the customer'),
    'field' => array(
      'handler' => 'views_handler_field',
      'click sortable' => TRUE,
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_string',
    ),
    'argument' => array(
      'handler' => 'views_handler_argument_string',
    ),
  );

  $data['customer_id'] = array(
    'title' => t('Customer Id'),
    'help' => t('Displays customers id'),
    'field' => array(
      'handler' => 'views_handler_field',
      'click sortable' => TRUE,
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_string',
    ),
    'argument' => array(
      'handler' => 'views_handler_argument_string',
    ),
  );

  $data['first_name'] = array(
    'title' => t('First Name'),
    'help' => t('The first name of the customer'),
    'field' => array(
      'handler' => 'views_handler_field',
      'click sortable' => TRUE,
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_string',
    ),
    'argument' => array(
      'handler' => 'views_handler_argument_string',
    ),
  );

  $data['last_name'] = array(
    'title' => t('Last Name'),
    'help' => t('The last name of the customer'),
    'field' => array(
      'handler' => 'views_handler_field',
      'click sortable' => TRUE,
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_string',
    ),
    'argument' => array(
      'handler' => 'views_handler_argument_string',
    ),
  );

  $data['email'] = array(
    'title' => t('Email'),
    'help' => t('The email of the customer'),
    'field' => array(
      'handler' => 'views_handler_field',
      'click sortable' => TRUE,
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_string',
    ),
    'argument' => array(
      'handler' => 'views_handler_argument_string',
    ),
  );

  $data['customer_phone'] = array(
    'title' => t('Customer Phone'),
    'help' => t('The phone number of the customer'),
    'field' => array(
      'handler' => 'views_handler_field',
      'click sortable' => TRUE,
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_string',
    ),
    'argument' => array(
      'handler' => 'views_handler_argument_string',
    ),
  );

  $data['tech'] = array(
    'title' => t('Tech'),
    'help' => t('The tech who serviced the customer'),
    'field' => array(
      'handler' => 'views_handler_field',
      'click sortable' => TRUE,
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_string',
    ),
    'argument' => array(
      'handler' => 'views_handler_argument_string',
    ),
  );

  $data['branch'] = array(
    'title' => t('Branch'),
    'help' => t('The branch of the company who serviced the customer'),
    'field' => array(
      'handler' => 'views_handler_field',
      'click sortable' => TRUE,
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_string',
    ),
    'argument' => array(
      'handler' => 'views_handler_argument_string',
    ),
  );

  $data['service'] = array(

    'title' => t('Service'),
    'help' => t('The type of service received by the customer'),
    'field' => array(
      'handler' => 'views_handler_field',
      'click sortable' => TRUE,
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_string',
    ),
    'argument' => array(
      'handler' => 'views_handler_argument_string',
    ),

  );

  $data['service_date'] = array(
    'title' => t('Service Date'),
    'help' => t('The date the customer was serviced. Note this is displayed in UNIX time.'),
    'field' => array(
      'handler' => 'views_handler_field_date',
      'click sortable' => TRUE,
    ),
    'sort' => array(
      'handler' => 'views_handler_sort_date',
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_date',
    ),
  );

  $data['creation_date'] = array(
    'title' => t('Creation Date'),
    'help' => t('The date/time this row was added to the database'),
    'field' => array(
      'handler' => 'views_handler_field_date',
      'click sortable' => TRUE,
    ),
    'sort' => array(
      'handler' => 'views_handler_sort_date',
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_date',
    ),
  );

  $data['email_sent'] = array(
    'title' => t('Email Sent'),
    'help' => t('Field for displaying if an email was sent to the customer or not'),
    'field' => array(
      'handler' => 'views_handler_field_boolean',
      'click sortable' => TRUE,
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_boolean_operator',
      'label' => t('Published'),
      'type' => 'yes-no',
      'use equal' => TRUE,
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
  );

  $data['text_sent'] = array(
    'title' => t('Text Sent'),
    'help' => t('Field for displaying if a text was sent to the customer for not'),
    'field' => array(
      'handler' => 'views_handler_field_boolean',
      'click sortable' => TRUE,
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_boolean_operator',
      'label' => t('Published'),
      'type' => 'yes-no',
      'use equal' => TRUE,
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
  );


  return $data;

}

/**
 *
 * Defines the review_boost_review_customer_clicks table in views
 *
 * @return mixed
 */
function customerClicksTable(){

  $data['table']['group'] = t('Review Boost Customer Clicks');


  $data['table']['base'] = array(
    'field' => 'id',
    'title' => t('Review Boost Customer Clicks'),
    'help' => t('This table contains clicks by the customer for the Review Boost module'),
    'weight' => -11,
  );

  $data['table']['join'] = array(

    'review_boost_token' => array(
      'left_field' => 'tid',
      'field' => 'tid',
    ),
  );

  $rb = new ReviewBoost();

  $links = $rb->getReviewLinks();

  foreach($links as $link => $value){
    $data[$value['id']] = array(
      'title' => t($value['title']),
      'help' => t('Field for displaying customer '. $value['title']. ' clicks'),
      'field' => array(
        'handler' => 'views_handler_field_boolean',
        'click sortable' => TRUE,
      ),
      'filter' => array(
        'handler' => 'views_handler_filter_boolean_operator',
        'label' => t('Published'),
        'type' => 'yes-no',
        'use equal' => TRUE,
      ),
      'sort' => array(
        'handler' => 'views_handler_sort',
      ),
    );
  }

  $data['click_date'] = array(
    'title' => t('Click Date'),
    'help' => t('Field for displaying last click date'),
    'field' => array(
      'handler' => 'views_handler_field_date',
      'click sortable' => TRUE,
    ),
    'sort' => array(
      'handler' => 'views_handler_sort_date',
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_date',
    ),
  );

  $data['tid'] = array(
    'title' => t('tid'),
    'help' => t('The tid for the row. This is used to relate to the main token table.'),
    'relationship' => array(
      'base' => 'review_boost_token',
      'base field' => 'tid',
      'handler' => 'views_handler_relationship',
      'label' => t('Reviewboost Customer Clicks Token Relationship'),
      'title' => t('Reviewboost Customer Clicks Token Relationship'),
      'help' => t('This adds a relationship to the review_boost_token table.'),
    ),
    'field' => array(
      'handler' => 'views_handler_field_numeric',
      'click sortable' => TRUE,
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_numeric',
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),

  );

  return $data;

}