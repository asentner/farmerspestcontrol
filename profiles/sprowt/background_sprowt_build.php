<?php

function curl_request_async($url, $params, $type='POST')
{
    $post_params = [];
    
    foreach ($params as $key => &$val) {
        if (is_array($val)) $val = implode(',', $val);
        $post_params[] = $key.'='.rawurlencode($val);
    }
    $post_string = implode('&', $post_params);
    
    $parts = parse_url($url);
    
    if(empty($parts['path'])) {
        $parts['path'] = '/';
    }
    
    if($parts['scheme'] == 'https') {
        $parts['port'] = 443;
        $parts['host'] = "ssl://{$parts['host']}";
    }
    
    $fp = fsockopen($parts['host'],
        isset($parts['port']) ? $parts['port'] : 80,
        $errno, $errstr, 30);
    
    // Data goes in the path for a GET request
    if('GET' == $type) $parts['path'] .= '?'.$post_string;
    
    $out = "$type ".$parts['path']." HTTP/1.1\r\n";
    $out.= "Host: ".$parts['host']."\r\n";
    $out.= "Content-Type: application/x-www-form-urlencoded\r\n";
    $out.= "Content-Length: ".strlen($post_string)."\r\n";
    $out.= "Connection: Close\r\n\r\n";
    // Data goes in the request body for a POST request
    if ('POST' == $type && isset($post_string)) $out.= $post_string;
    
    fwrite($fp, $out);
    fclose($fp);
}

$actual_link = (isset($_SERVER['HTTPS']) ? "https" : "http") . "://{$_SERVER['HTTP_HOST']}{$_SERVER['REQUEST_URI']}";
$base = str_replace(basename($actual_link), '', $actual_link);
$url = $base . 'BackgroundBuilder.php';
if(!empty($_GET['XDEBUG_SESSION_START'])) {
    $url .= '?XDEBUG_SESSION_START=1';
}

curl_request_async($url, []);

echo json_encode(array(
    'success' => true,
    'message' => 'Sprowt Setup Started!'
));