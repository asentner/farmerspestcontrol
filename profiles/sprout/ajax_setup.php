<?php

if(!defined('DRUPAL_ROOT')){
    define('DRUPAL_ROOT', str_replace("/profiles/sprout", "", getcwd()));
    require_once DRUPAL_ROOT . '/includes/bootstrap.inc';
    drupal_bootstrap(DRUPAL_BOOTSTRAP_DATABASE);
}

global $base_url;

if(!db_table_exists('sprout_progress')){
    $return = array(
        'status' => 1,
        'percentage' => 0,
        'message' => 'Initializing...',
    );
    
    echo json_encode($return);
    
    exit();
}

$progress = db_query("SELECT * FROM sprout_progress")->fetchAssoc();

if(empty($progress)) {    
    $progress = array(
        'id' => 0,
        'function' => 'init',
        'progress' => 0,
    );
}

if($progress['function'] == 'init') {
    $progress['message'] = 'Initializing...';
}

$progress_id = $progress['id'];

$return = array(
    'status' => 1,
    'percentage' => $progress['progress'],
    'message' => $progress['message'],
);

echo json_encode($return);
