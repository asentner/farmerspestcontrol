<?php

if(!defined('DRUPAL_ROOT')){
    define('DRUPAL_ROOT', str_replace("/profiles/sprowt", "", getcwd()));
    require_once DRUPAL_ROOT . '/includes/bootstrap.inc';
    drupal_bootstrap(DRUPAL_BOOTSTRAP_DATABASE);
}

global $base_url;

if(!db_table_exists('sprowt_progress')){
    $return = array(
        'status' => 1,
        'percentage' => 0,
        'message' => 'Initializing...',
    );
    
    echo json_encode($return);
    
    exit();
}

$progress = db_query("SELECT * FROM sprowt_progress")->fetchAssoc();

$current = $progress['progress'];
$count = $progress['count'];
$actions = $progress['actions'];

//if($current != 100) {
//    $next = floor((($progress['current_action'] + 1)/$actions) * 100);
//    $diff = $next - $current;
//    for ($i = 1; $i <= $count; ++$i) {
//        $diff = floor($diff / 2);
//        $current += $diff;
//    }
//    ++$count;
//    $updated = db_update('sprowt_progress') // Table name no longer needs {}
//    ->fields(array(
//        'count' => $count,
//    ))
//        ->condition('id', $progress['id'], '=');
//
//    $updated->execute();
//}

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
    'percentage' => $current,
    'message' => $progress['message'],
);

echo json_encode($return);
