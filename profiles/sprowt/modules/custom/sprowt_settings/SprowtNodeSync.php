<?php


class SprowtNodeSyncError extends Exception {
    
    public function __construct($message = "", $code = 0, $previous = null) {
        parent::__construct($message, $code, $previous);
    }
}

class SprowtNodeSync {
    private $nids = [];
    private $types = [];
    private $uuids = [];
    
    const SPROWT_DATA_URL = 'https://dev-sprowt-dummy.pantheonsite.io';
    const SPROWT_SECRET = 'Roads... where we\'re going we don\'t NEED roads.';
    
    function __construct($opts = []) {
        $this->nids = $this->testSet($opts['nids']);
        $this->types = $this->testSet($opts['types']);
        $this->uuids = $this->testSet($opts['uuids']);
    
        $this->addNidsByUuids($this->uuids);
        $this->addNidsByTypes($this->types);
    }
    
    private function testSet($val) {
        if(empty($val)) {
            return [];
        }
        
        return $val;
    }

    //from here: https://gist.github.com/joashp/a1ae9cb30fa533f4ad94
    function encrypt_decrypt($action, $string) {
        $output = false;
        $encrypt_method = "AES-256-CBC";
        $secret_key = 'Good morning agent Hunt.';
        $secret_iv = 'This message will self destruct in 5 seconds...';
        // hash
        $key = hash('sha256', $secret_key);

        // iv - encrypt method AES-256-CBC expects 16 bytes - else you will get a warning
        $iv = substr(hash('sha256', $secret_iv), 0, 16);
        if ( $action == 'encrypt' ) {
            $output = openssl_encrypt($string, $encrypt_method, $key, 0, $iv);
            $output = base64_encode($output);
        }
        else if( $action == 'decrypt' ) {
            $output = openssl_decrypt(base64_decode($string), $encrypt_method, $key, 0, $iv);
        }

        return $output;
    }

    function validate($encrypted) {
        if(!empty($_GET['debug']) && $_SERVER['SERVER_ADDR'] == '127.0.0.1') {
            return true;
        }


        $test = $this->encrypt_decrypt('decrypt', $encrypted);

        return $test == self::SPROWT_SECRET;
    }

    /**
     * @return array
     */
    public function getNids() {
        return $this->nids;
    }
    
    /**
     * @param array $nids
     *
     * @return SprowtNodeSync
     */
    public function setNids(array $nids) {
        $this->nids = $nids;
        return $this;
    }
    
    /**
     * @return array
     */
    public function getTypes() {
        return $this->types;
    }
    
    /**
     * @param array $types
     *
     * @return SprowtNodeSync
     */
    public function setTypes(array $types) {
        $this->types = $types;
        return $this;
    }
    
    /**
     * @return array
     */
    public function getUuids() {
        return $this->uuids;
    }
    
    /**
     * @param array $uuids
     *
     * @return SprowtNodeSync
     */
    public function setUuids(array $uuids) {
        $this->uuids = $uuids;
        return $this;
    }
    
    function addNidsByUuids($uuids = []) {
        if(empty($uuids)) {
            return;
        }
        try {
            $nidArray = entity_get_id_by_uuid('node', $uuids);
        }
        catch(Exception $e) {
            throw new SprowtNodeSyncError($e->getMessage(), $e->getCode(), $e);
        }
        
        $this->nids = array_merge($this->nids, array_values($nidArray));
    }
    
    function addNidsByNids($nids = []) {
        if(empty($nids)) {
            return;
        }
        $this->nids = array_merge($this->nids, $nids);
    }
    
    function addNidsByTypes($types = []) {
        if(empty($types)) {
            return;
        }
        
        $dbTypes = db_query("
            SELECT type
            FROM node_type
        ")->fetchCol();
        
        $notFound = [];
        foreach($types as $type) {
            if(!in_array($type, $dbTypes)) {
                $notFound[] = $type;
            }
        }
        
        if(!empty($notFound)) {
            throw new SprowtNodeSyncError('Node type(s) not found! Types: ' . implode(', ', $notFound));
        }
        
        $nids = db_query("
            SELECT nid
            FROM node
            WHERE type in (:types)
        ",[
            ':types' => $types
        ])->fetchCol();
        
        if(!empty($nids)) {
            $this->nids = array_merge($this->nids, $nids);
        }
    }
    
    function filterByStatus($status = 1) {
        $nids = db_query("
            SELECT nid
            FROM node
            WHERE status = :status
            AND nid IN (:nids)
        ", [
            ':status' => $status,
            ':nids' => $this->nids
        ])->fetchCol();
        
        $this->nids = $nids;
    }
    
    function export($format = 'json') {
        $isSync = &drupal_static('sprowt_sync', false);
        $isSync = true;
    
        $export_mode = variable_get('node_export_file_mode', 'inline');
        variable_set('node_export_file_mode', 'inline');
        
        try {
            $output = node_export($this->nids, $format);
        }
        catch(Exception $e) {
            $isSync = false;
            variable_set('node_export_file_mode', $export_mode);
            throw new SprowtNodeSyncError($e->getMessage(), $e->getCode(), $e);
        }
        variable_set('node_export_file_mode', $export_mode);
        $isSync = false;
        
        if(empty($output['success'])) {
            throw new SprowtNodeSyncError('Error with export: ' . print_r($output, true));
        }
        
        return $output['output'];
    }
    
    function import($code, $importSetting = 'new') {
        $isSync = &drupal_static('sprowt_sync', false);
        $isSync = true;
    
        $existing = variable_get('node_export_existing', 'new');
        variable_set('node_export_existing', $importSetting);
        
        try {
            $ret = node_export_import($code);
        }
        catch(Exception $e) {
            $isSync = false;
            variable_set('node_export_existing', $existing);
            throw new SprowtNodeSyncError($e->getMessage(), $e->getCode(), $e);
        }
    
        $isSync = false;
        variable_set('node_export_existing', $existing);
        
        if(empty($ret['success'])) {
            throw new SprowtNodeSyncError('Sprowt sync import error: ' . print_r($ret, true));
        }
        
        return $ret;
    }
    
    
    function curl($url, $payload = array()) {
        $ch = curl_init();
        
        curl_setopt($ch, CURLOPT_URL, $url);
        curl_setopt($ch, CURLOPT_RETURNTRANSFER, true);
        curl_setopt($ch, CURLOPT_FOLLOWLOCATION, true);
        curl_setopt($ch, CURLOPT_MAXREDIRS, 5);
        curl_setopt($ch, CURLOPT_CONNECTTIMEOUT, 100);
        curl_setopt($ch, CURLOPT_TIMEOUT, 100);
        curl_setopt($ch, CURLOPT_POST, true);
        
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
    
    function fetch($opts = [], $rollout = false) {
        $url = variable_get('sprowt_data_url', self::SPROWT_DATA_URL);
        
        $uri = 'sprowt/request-nodes';

        if($rollout) {
            $opts = [];
            $uri = 'sprowt/request-nodes/rollout';
        }
        
        $opts['secret'] = $this->encrypt_decrypt('encrypt', self::SPROWT_SECRET);
        
        try {
            $response = $this->curl($url . '/' . $uri, $opts);
        }
        catch(Exception $e) {
            throw new SprowtNodeSyncError($e->getMessage(), $e->getCode(), $e);
        }

        if($response['code'] != 200) {
            throw new SprowtNodeSyncError('Error retrieving data: ' . print_r($response));
        }


        $result = json_decode($response['result'], true);

        return $result['code'];
    }
    
    function addNodes($opts, $importSetting = 'new') {
        $code = $this->fetch($opts);
        $this->import($code, $importSetting);
    }

    function sprowtRollout() {
        $code = $this->fetch([], true);
        $this->import($code, 'revision');
    }
    
}