<?php

require_once('sprowtbuilder.php');

$sprowtbuilder = new SprowtBuilder();

$data = $sprowtbuilder->getData();


$filename = strtolower($data['company_info']['company_name']);
$filename = preg_replace('/[^a-z0-9_]+/', '_', $filename);
trim($filename, '_');
$filename .= "__sprowt_setup.json";

header('Content-disposition: attachment; filename=' . $filename);
header('Content-type: application/json');

echo json_encode($data, JSON_PRETTY_PRINT);