<?php

set_time_limit(0);
ini_set('max_execution_time', 0); //0=NOLIMIT
ignore_user_abort();

if(!defined('DRUPAL_ROOT')){
    define('DRUPAL_ROOT', str_replace("/profiles/sprowt", "", getcwd()));
    chdir(DRUPAL_ROOT);
    require_once DRUPAL_ROOT . '/includes/bootstrap.inc';
    drupal_bootstrap(DRUPAL_BOOTSTRAP_FULL);
}

//set profile because it's not set for some reason

variable_set('install_profile', 'sprowt');

if(!db_table_exists('sprowt_progress')){
    $sprowt_progress_schema = array(
      'description' => 'The initial setup for this sprowt site',
      'fields' => array(
        'id' => array('type' => 'serial', 'unsigned' => true, 'not null' => true),
        'function' => array('type'=> 'varchar', 'length' => 255, 'not null' => true, 'default' => ''),
        'progress' => array('type'=> 'int', 'default' => '0'),
        'message' =>  array('type'=> 'text'),
        'actions' => array('type'=> 'int', 'default' => '0'),
          'current_action' => array('type'=> 'int', 'default' => '0'),
        'complete' => array('type'=> 'int','not null' => true, 'default' => '0'),
      ),
      'primary key' => array('id')
    );
    
    db_create_table('sprowt_progress', $sprowt_progress_schema);
    
    global $base_url;
    $progress_id = db_insert('sprowt_progress')
        ->fields(array(
            'function' => 'init',
            'progress' => 0
        ))
        ->execute();
}

$progress = db_query("SELECT * FROM sprowt_progress")->fetchAssoc();


function update_progress($function, $perc, $message, $actions, $current, $id) {
    $updated = db_update('sprowt_progress') // Table name no longer needs {}
      ->fields(array(
        'function' => $function,
        'progress' => floor($perc * 100),
        'message' => $message,
        'actions' => $actions,
        'current_action' => $current
      ))
      ->condition('id', $id, '=');
      
    $updated->execute();
}

$sb = new SprowtBuilder();


$actions = array(
    'getData' => "Getting Sprowt Data...",
    'addUsers' => "Adding Users...",
    'addNodes' => "Adding Default Nodes...",
    'addCompanyInfo' => "Adding Company Info...",
    'addReview' => "Adding Review Sites...",
    'addMarketsServices' => "Adding Markets and Services...",
    'addLocations' => "Adding Locations...",
    'addBranding' => "Adding Branding...",
    'addSocial' => "Adding Social Media...",
    'addIntegrations' => "Adding Integrations...",
    'revertFeatures' => "Revert Features...",
    'addNodeDefaultImages' => "Updating Default Images..."
);

if(variable_get('sprowt_is_starter', false)) {
    $actions['setUpSprowtStarter'] = 'Setting Up Sprowt Starter Specific Settings...';
}

$i = 0;

foreach($actions as $method => $message) {
    if(empty($i)) {
        update_progress($method, 0 , $message, count($actions), $i, $progress['id']);
    }
    else {
        update_progress($method, $i/count($actions) , $message, count($actions), $i, $progress['id']);
    }
    $sb->$method();
    $i++;
}


$updated = db_update('sprowt_progress') // Table name no longer needs {}
  ->fields(array(
    'function' => 'Done',
    'progress' => 100,
    'message' => 'Finished!',
    'complete' => 1
  ))
  ->condition('id', $progress['id'], '=')
  ->execute();
  
echo "Sprowt Setup Done!";
