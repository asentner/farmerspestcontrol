<?php

class NodeBuilderException extends EntityMetadataWrapperException {
    public function __construct($message = "", $code = 0, Throwable $previous = null)
    {
        parent::__construct($message, $code, $previous);
    }
}

/**
Building a better nodebuilder by taking advantage of the entity api wrapper classes
 */

class NodeBuilder extends EntityDrupalWrapper {

    public $node_info;

    function __construct($data = null, $info = array()){

        if(is_int($data) || ctype_digit($data)) {
            $data = node_load($data);
        }

        if(is_string($data) && !ctype_digit($data)){
            $data = entity_create('node', array('type' => $data));
        }

        parent::__construct('node',$data, $info);

        $this->node_info = $this->getPropertyInfo();
    }

    public function setField($field, $value) {
        try {
            $this->$field->set($value);
        }
        catch (EntityMetadataWrapperException $e) {
            throw new NodeBuilderException("Problem setting field, $field: " . $e->getMessage(), $e->getCode(), $e);
        }
    }

    public function save() {
        try {
            return parent::save();
        }
        catch (EntityMetadataWrapperException $e) {
            throw new NodeBuilderException("Problem saving node of type {$this->raw()->type}: " . $e->getMessage(), $e->getCode(), $e);
        }
    }
}

class ForgelyNode extends NodeBuilder {

    private $uuid;
    private $feed;

    public function __construct($data)
    {
        if(is_array($data)) {
            $this->feed = $data;
            $nid = $this->nidFromFeed($data);
        }
        elseif (is_string($data)) {
            $this->uuid = $data;
            $nid = $this->nidFromUUID($data);
        }

        if(!empty($nid)) {
           $data = node_load($nid);
        }

        if(!is_object($data) && !is_int($data) && !ctype_digit($data)) {
            $data = 'opportunity';
        }


        parent::__construct($data);

        if(!empty($this->uuid)) {
            $this->setField('field_external_id', $this->uuid);
        }

        if(!empty($this->feed)) {
            $this->parseFeed($this->feed);
        }
    }

    public function nidFromFeed($feed) {
        $this->uuid = $feed['jobId'];
        return $this->nidFromUUID($feed['jobId']);
    }

    public function nidFromUUID($uuid) {
        $map = _forgely_uuid_map();

        if(empty($map[$uuid])) {
            return false;
        }

        return $map[$uuid];
    }

    public function handleCategory($category) {
        $term_names = _forgely_get_category_names();
        if(empty($term_names[$category])) {
            $v = taxonomy_vocabulary_machine_name_load('opportunity_categories');
            $term = new stdClass();
            $term->name = $category;
            $term->vid = $v->vid;
            taxonomy_term_save($term);
            $term_names = _forgely_get_category_names(array($term->name => $term->tid));
        }

        $tid = $term_names[$category];

        $this->setField('field_category', $tid);
    }
    
    public function handleEmploymentTypes($types) {
        $term_map = _forgely_get_employment_types();
        $tids = array();
        foreach($types as $type) {
            if(!empty($term_map[$type])) {
                $tids[] = $term_map[$type];
            }
            else {
                watchdog('FORGELY', 'Employment Type not found! Type: ' . $type,array(), WATCHDOG_ERROR);
            }
        }
        if(!empty($tids)) {
            $this->setField('field_employment_types', $tids);
        }
        else {
            $this->setField('field_employment_types', null);
        }
        
    }
    
    public function handleLocation($location) {
        $currentLocation = $this->field_location->value();
        $hash_array = array(
            !empty($currentLocation['street']) ? $currentLocation['street'] : '',
            !empty($currentLocation['city']) ? $currentLocation['city'] : '',
            !empty($currentLocation['province']) ? $currentLocation['province'] : '',
            !empty($currentLocation['postal_code']) ? $currentLocation['postal_code'] : '',
            !empty($currentLocation['phone']) ? $currentLocation['phone'] : '',
            !empty($currentLocation['name']) ? $currentLocation['name'] : ''
        );
        
        foreach($hash_array as $k => $v) {
            $hash_array[$k] = trim(preg_replace('/[^a-z0-9]/', '', strtolower($v)));
        }
        
        $hash = md5(json_encode($hash_array));
        
        $new_hash_array = array();
        $location_array = array();
        foreach($location as $key => $value) {
            switch($key) {
                case 'address':
                    $new_hash_array[0] = $value;
                    $location_array['street'] = trim($value);
                    break;
                case 'city':
                    $new_hash_array[1] = $value;
                    $location_array['city'] = trim($value);
                    break;
                case 'state':
                    $new_hash_array[2] = $value;
                    $location_array['province'] = trim($value);
                    break;
                case 'zip':
                    $new_hash_array[3] = $value;
                    $location_array['postal_code'] = trim($value);
                    break;
                case 'phone':
                    $new_hash_array[4] = $value;
                    $location_array['phone'] = trim(preg_replace('/[^0-9]/', '', $value));
                    break;
                case 'name':
                    $new_hash_array[5] = $value;
                    $location_array['name'] = trim($value);
            }
        }
    
        foreach($new_hash_array as $k => $v) {
            $new_hash_array[$k] = trim(preg_replace('/[^a-z0-9]/', '', strtolower($v)));
        }
        
        $new_hash = md5(json_encode($new_hash_array));
        
        if($hash != $new_hash) {
            $geo = $this->geocode($location_array);
            if(!empty($geo) && !empty($geo['lat']) && !empty($geo['lon'])) {
                $location_array['locpick'] = array(
                    'user_latitude' => $geo['lat'],
                    'user_longitude' => $geo['lon']
                );
            }
            
            $this->setField('field_location', $location_array);
        }
        
        
    }
    
    public function geocode($location_address) {
        $url = 'https://geocoding.geo.census.gov/geocoder/locations/address';
        
        $params = array();
        foreach($location_address as $k => $v) {
            switch($k) {
                case 'street':
                    $params['street'] = $v;
                    break;
                case 'city':
                    $params['city'] = $v;
                    break;
                case 'province':
                    $params['state'] = $v;
                    break;
                case 'postal_code':
                    $params['zip'] = $v;
                    break;
            }
        }
        
        if(!empty($params)) {
            $params['format'] = 'json';
            $params['benchmark'] = 'Public_AR_Current';
        }
    
        $param_string = http_build_query($params, '', '&');
        
        $url = $url . "?$param_string";
        
        $ch = curl_init();
    
        curl_setopt($ch, CURLOPT_URL, $url);
        curl_setopt($ch, CURLOPT_RETURNTRANSFER, true);
        curl_setopt($ch, CURLOPT_FOLLOWLOCATION, true);
        curl_setopt($ch, CURLOPT_MAXREDIRS, 5);
        curl_setopt($ch, CURLOPT_CONNECTTIMEOUT, 30);
        curl_setopt($ch, CURLOPT_TIMEOUT, 30);
        
    
        $output = curl_exec($ch);
    
        $httpInfo = curl_getinfo($ch);
        $httpcode = curl_getinfo($ch, CURLINFO_HTTP_CODE);
    
        curl_close($ch);
    
        
        if($httpcode == 200) {
            $output = json_decode($output, true);
            if(!empty($output['result']['addressMatches'][0]['coordinates'])) {
                $coordinates = $output['result']['addressMatches'][0]['coordinates'];
                return array(
                    'lat' => $coordinates['x'],
                    'lon' => $coordinates['y']
                );
            }
        }
        
        return false;
        
    }


    private function fieldEmpty($field) {
        return (empty($field) || $this->preserveField($field));
    }

    private function preserveField($field) {
        $preserve = md5('preserve field');
        return ($field == $preserve);
    }

    public function parseFeed($feed) {
        $preserve = md5('preserve field');
        $this->setField('title', $feed['title']);
        $body = array();
        if(!$this->fieldEmpty($feed['description'])) {
            $body['value'] = $feed['description'];
        }
        elseif (!$this->preserveField($feed['description'])){
            $body['value'] = '';
        }

        if(!$this->fieldEmpty($feed['teaser'])) {
            $body['summary'] = $feed['teaser'];
        }
        elseif (!$this->preserveField($feed['teaser'])){
            $body['summary'] = '';
        }

        if($body['value'] === '' && $body['summary'] === '') {
            $this->setField('body', null);
        }
        elseif (!empty($body)) {
            $body['format'] = 'full_html';
            $this->setField('body', $body);
        }

        if(!$this->fieldEmpty($feed['benefits'])) {
            $this->setField('field_benefits', array(
                'format' => 'full_html',
                'value' => $feed['benefits']
            ));
        }
        elseif (!$this->preserveField($feed['benefits'])) {
            $this->setField('field_benefits', null);
        }

        if(!$this->fieldEmpty($feed['category'])) {
            $this->handleCategory($feed['category']);
        }
        elseif (!$this->preserveField($feed['category'])) {
            $this->setField('field_category', null);
        }

        if(!$this->fieldEmpty($feed['application_link'])) {
            $this->setField('field_application_link', array('url' => $feed['application_link']));
        }
        elseif (!$this->preserveField($feed['application_link'])) {
            $this->setField('field_application_link', null);
        }
        
        if(!empty($feed['location'])) {
            $this->handleLocation($feed['location']);
        }
        elseif (!$this->preserveField($feed['location'])) {
            $this->setField('field_location', null);
        }
        
        if(!$this->fieldEmpty($feed['employment_types'])) {
            $this->handleEmploymentTypes($feed['employment_types']);
        }
        elseif (!$this->preserveField($feed['employment_types'])) {
            $this->setField('field_employment_types', null);
        }
        
        if(!$this->fieldEmpty($feed['salary_range'])) {
            $this->setField('field_salary_range_from', $feed['salary_range']['minValue']);
            $this->setField('field_salary_range_to', $feed['salary_range']['maxValue']);
            $this->setField('field_salary_range_unit', $feed['salary_range']['unitText']);
        }
        elseif (!$this->preserveField($feed['salary_range'])) {
            $this->setField('field_salary_range_from', null);
            $this->setField('field_salary_range_to', null);
            $this->setField('field_salary_range_unit', null);
        }
        
    }

    public function save()
    {
        $uuid = $this->field_external_id->value();
        try {
            parent::save();
            $map = _forgely_uuid_map(array( $uuid => $this->raw()->nid));
            return $this;
        }
        catch(NodeBuilderException $e) {
            throw new NodeBuilderException("Problem saving Forgely Node with UUID [$uuid]: " . $e->getMessage(), $e->getCode(), $e);
        }
    }
}