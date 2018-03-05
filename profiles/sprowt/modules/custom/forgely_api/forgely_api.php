<?php

require_once drupal_get_path('module', 'forgely') . '/forgely_node.php';

class ForgelyApi {

    private $api_url;
    private $webhook_url;
    private $access_key;
    private $secret_key;

    function __construct() {
        $this->api_url = variable_get('forgely_base_url','https://forge.ly') . '/api/v1/jobs/teambuilder';
        $this->webhook_url = FORGELY_WEBHOOK_URL;
        $this->access_key = variable_get('forgely_access_key', '');
        $this->secret_key = variable_get('forgely_secret_key', '');
    }
    
    /**
     * @return string
     */
    public function getApiUrl() {
        return $this->api_url;
    }
    
    /**
     * @param string $api_url
     */
    public function setApiUrl($api_url) {
        $this->api_url = $api_url;
    }
    
    /**
     * @return string
     */
    public function getWebhookUrl() {
        return $this->webhook_url;
    }
    
    /**
     * @param string $webhook_url
     */
    public function setWebhookUrl($webhook_url) {
        $this->webhook_url = $webhook_url;
    }
    
    /**
     * @return null
     */
    public function getAccessKey() {
        return $this->access_key;
    }
    
    /**
     * @param null $access_key
     */
    public function setAccessKey($access_key) {
        $this->access_key = $access_key;
    }
    
    /**
     * @return null
     */
    public function getSecretKey() {
        return $this->secret_key;
    }
    
    /**
     * @param null $secret_key
     */
    public function setSecretKey($secret_key) {
        $this->secret_key = $secret_key;
    }

    
    
    function curl($url, $payload = array()) {
        $ch = curl_init();

        curl_setopt($ch, CURLOPT_URL, $url);
        curl_setopt($ch, CURLOPT_RETURNTRANSFER, true);
        curl_setopt($ch, CURLOPT_FOLLOWLOCATION, true);
        curl_setopt($ch, CURLOPT_MAXREDIRS, 5);
        curl_setopt($ch, CURLOPT_CONNECTTIMEOUT, 30);
        curl_setopt($ch, CURLOPT_TIMEOUT, 30);
        curl_setopt($ch, CURLOPT_USERPWD, $this->access_key . ':' . $this->secret_key);

        //curl_setopt($ch, CURLOPT_COOKIE, 'XDEBUG_SESSION=forgelyapitest');

        if (count($payload)) {
            curl_setopt($ch, CURLOPT_POSTFIELDS, http_build_query($payload, '', '&'));
        }

        $output = curl_exec($ch);

        $httpInfo = curl_getinfo($ch);
        $httpcode = curl_getinfo($ch, CURLINFO_HTTP_CODE);

        curl_close($ch);

        return array(
            'info' => $httpInfo,
            'code' => $httpcode,
            'result' => $output
        );
    }
    
    function getData() {
        $url = $this->api_url;
        $result = $this->curl($url);

        $data = json_decode($result['result'], true);

        return $data;
    }

    function syncData($feed) {
        foreach ($feed as $job) {
            $node = new ForgelyNode($job);

            try {
                $do_not_delete = $node->field_do_not_delete->value();
                if(empty($do_not_delete)) {
                  $node->save();
                }
            }
            catch(NodeBuilderException $e) {
                watchdog_exception('Forgely', $e);
            }
        }
    }
}