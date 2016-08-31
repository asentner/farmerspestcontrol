<?php

set_time_limit(0);
ignore_user_abort();

if(!defined('DRUPAL_ROOT')){
    define('DRUPAL_ROOT', str_replace("/profiles/sprout", "", getcwd()));
    require_once DRUPAL_ROOT . '/includes/bootstrap.inc';
    drupal_bootstrap(DRUPAL_BOOTSTRAP_FULL);
}

//set profile because it's not set for some reason

variable_set('install_profile', 'sprout');

if(!db_table_exists('sprout_progress')){
    $sprout_progress_schema = array(
      'description' => 'The initial setup for this leadbuilder site',
      'fields' => array(
        'id' => array('type' => 'serial', 'unsigned' => true, 'not null' => true),
        'function' => array('type'=> 'varchar', 'length' => 255, 'not null' => true, 'default' => ''),
        'progress' => array('type'=> 'int', 'default' => '0'),
        'message' =>  array('type'=> 'text'),
        'actions' => array('type'=> 'int', 'default' => '0'),
        'complete' => array('type'=> 'int','not null' => true, 'default' => '0'),
      ),
      'primary key' => array('id')
    );
    
    db_create_table('sprout_progress', $sprout_progress_schema);
    
    global $base_url;
    $progress_id = db_insert('sprout_progress')
        ->fields(array(
            'function' => 'init',
            'progress' => 0
        ))
        ->execute();
}

$progress = db_query("SELECT * FROM sprout_progress")->fetchAssoc();


function update_progress($function, $perc, $message, $actions, $id) {
    $updated = db_update('sprout_progress') // Table name no longer needs {}
      ->fields(array(
        'function' => $function,
        'progress' => floor($perc * 100),
        'message' => $message,
        'actions' => $actions,
      ))
      ->condition('id', $id, '=');
      
    $updated->execute();
}

$sb = new SproutBuilder();


$actions = array(
    'getData' => "Getting Sprout Data...",
    'addUsers' => "Adding Users...",
    'addBranding' => "Adding Branding...",
    'addNodes' => "Adding Default Nodes...",
    'addCompanyInfo' => "Adding Company Info...",
    'addReview' => "Adding Review Sites...",
    'addMarketsServices' => "Adding Markets and Services...",
    'addLocations' => "Adding Locations...",
    'addSocial' => "Adding Social Media...",
    'addIntegrations' => "Adding Integrations...",
);

$i = 0;

foreach($actions as $method => $message) {
    if(empty($i)) {
        update_progress($method, 0 , $message, count($actions), $progress['id']);
    }
    else {
        update_progress($method, $i/count($actions) , $message, count($actions), $progress['id']);
    }
    $sb->$method();
    $i++;
}


$updated = db_update('sprout_progress') // Table name no longer needs {}
  ->fields(array(
    'function' => 'Done',
    'progress' => 100,
    'message' => 'Finished!',
    'complete' => 1
  ))
  ->condition('id', $progress['id'], '=')
  ->execute();
  
echo "Sprout Setup Done!";