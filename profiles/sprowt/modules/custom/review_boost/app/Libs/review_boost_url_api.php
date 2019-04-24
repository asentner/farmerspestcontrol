<?php
/**
 * Created by PhpStorm.
 * User: michael
 * Date: 9/25/17
 * Time: 11:22 PM
 */

namespace ReviewBoost\Libs;



class ReviewBoostUrlApi {
  // Constructor
  protected $apiUrl;
  protected $key;
  public function __construct($key,$apiURL = 'https://api.rebrandly.com/v1/links') {
    // Keep the API Url
    $this->apiURL = $apiURL;
    $this->key = $key;
  }

  // Shorten a URL
  public function shorten($url) {
    $headers = array(
      "apiKey" => $this->key,
      "Content-Type" => "application/json",
    );
    $response = $this->send($url,$headers);
    // Return the result
    return $response;
  }

  // Send information to rebrand.ly
  public function send($url,$headers,$shorten = true) {
    // Create cURL
    $ch = curl_init();
    // If we're shortening a URL...
    if($shorten) {
      if(!empty($headers)) {
        $headersStringArray = array();
        foreach($headers as $k => $v) {
          $headersStringArray[] = "$k: $v";
        }
        curl_setopt($ch, CURLOPT_HTTPHEADER, $headersStringArray);
      }
      $post_data = array(
        "fullName" > variable_get("site_name"),
        "destination" => $url,
        "domain" => variable_get("site_name"),
      );
      curl_setopt($ch,CURLOPT_URL,$this->apiURL);
      curl_setopt($ch,CURLOPT_POST,1);
      curl_setopt($ch,CURLOPT_POSTFIELDS,json_encode($post_data));
    }
    curl_setopt($ch,CURLOPT_RETURNTRANSFER,1);
    // Execute the post
    $result = curl_exec($ch);
    // Close the connection
    curl_close($ch);
    // Return the result
    return json_decode($result,true);
  }
}