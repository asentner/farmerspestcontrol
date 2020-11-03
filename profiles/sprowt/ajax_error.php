<?php

if(!defined('DRUPAL_ROOT')){
    define('DRUPAL_ROOT', str_replace("/profiles/sprowt", "", getcwd()));
    require_once DRUPAL_ROOT . '/includes/bootstrap.inc';
    drupal_bootstrap(DRUPAL_BOOTSTRAP_DATABASE);
}

$dir = sys_get_temp_dir();
$outputfile = $dir . '/sprowtoutput.log';
$pidfile = $dir . '/sprowtpid';

function isRunning($pid){
    try{
        $result = shell_exec('ps aux | grep php');
        if( strpos($result, 'BackgroundBuilder.php') !== false){
            return true;
        }
    }catch(Exception $e){}

    return false;
}

if(!isRunning(file_get_contents($pidfile))) {
    $log = file_get_contents($outputfile);
    if(strpos($log, 'Sprowt Setup Done!') === false) {
        $return = array(
            'status' => 0,
            'data' => $log
        );
    }
}
else {
    $log = file_get_contents($outputfile);
    $return = [
        'status' => 1,
        'data' => $log
    ];
}

echo json_encode($return);
