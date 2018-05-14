<?php

class BaseNodeMigration extends DrupalNode7Migration {
    public function __construct(array $arguments) {
        $this->sourceFields += $this->addMetatagToSource();
        parent::__construct($arguments);
    }
    
    function addMetatagToSource() {
        $fields = array();
        if($this->moduleExists('metatag')) {
            $elements = metatag_get_info();
    
            foreach ($elements['tags'] as $value) {
                $metatag_field = 'metatag_' . $value['name'];
                $fields[$metatag_field] = $value['description'];
            }
        }
        
        return $fields;
    }
    
    function prepareRow($row) {
        parent::prepareRow($row);
        $query = Database::getConnection('default', $this->sourceConnection)
            ->select('metatag', 'm')
            ->fields('m')
            ->condition('m.entity_type', 'node')
            ->condition('m.entity_id', $row->nid)
            ->condition('m.revision_id', $row->vid);
    
        $result = $query->execute();
        
        foreach($result as $r) {
            $data = unserialize($r->data);
            foreach($data as $mField => $value) {
                $index = "metatag_{$mField}";
                $row->$index = $value['value'];
            }
        }
        
        return $row;
    }
    
    public function autoMap() {
        $sourceFields = $this->getSource()->fields();
        $destFields = $this->getDestination()->fields();

        $missingSources = array();

        $used_sources = array();
        $used_destinations = array();
        $field_mappings = $this->getFieldMappings();
        foreach ($field_mappings as $mapping) {
            $source_field = $mapping->getSourceField();
            $destination_field = $mapping->getDestinationField();
            $used_sources[$source_field] = true;
            $used_destinations[$destination_field] = true;
        }

        $excluded = $this->getExcludeFields();

        foreach($sourceFields as $field => $description) {
            if(!in_array($field, $excluded)) {
                if(!empty($destFields[$field]) && empty($used_sources[$field])) {
                    $this->addFieldMapping($field, $field);
                    $used_sources[$field] = true;
                }
            }

            if(strpos($field, ':language') !== false && empty($used_sources[$field])) {
                $this->addFieldMapping($field)
                    ->defaultValue(LANGUAGE_NONE);
            }

        }
    }

    public function getExcludeFields() {
        return array(
            'nid',
            'uid',
            'revision_uid',
            'pathauto',
            'path',
            'revision',
        );
    }

    public function isImagefield($field, $type = 'destination') {
        switch($type) {
            case 'destination':
                $info = field_info_field($field);
                return $info['type'] == 'image';
                break;
            case 'source':
                $sourceFieldInfo = $this->version->getSourceFieldInfo();
                if(!empty($sourceFieldInfo[$field])) {
                    return $sourceFieldInfo[$field][$type] == 'image';
                }
                break;
        }
        
        return false;
    }
    
    public function mapFileField($sourceField, $destField
    = null) {
        if(empty($destField)) {
            $destField = $sourceField;
        }

        $this->addFieldMapping($destField, $sourceField)
            ->sourceMigration('File');
        $this->addFieldMapping($destField . ':file_class')
            ->defaultValue('MigrateFileFid');
        $this->addFieldMapping($destField . ':preserve_files')
            ->defaultValue(TRUE);
        $this->addFieldMapping($destField . ':language')
            ->defaultValue(LANGUAGE_NONE);
        if($this->isImagefield($destField) && $this->isImagefield($sourceField, 'source')) {
            $this->addFieldMapping($destField . ':alt', $sourceField . ':alt');
            $this->addFieldMapping($destField . ':title', $sourceField . ':title');
        }
    }

    public function mapTermField($sourceMigration, $sourceField, $destField = null) {
        if(empty($destField)) {
            $destField = $sourceField;
        }

        $this->addFieldMapping($destField, $sourceField)
            ->sourceMigration($sourceMigration);
        $this->addFieldMapping($destField . ':source_type')
            ->defaultValue('tid');
    }
}

class AffiliationMigration extends BaseNodeMigration {
    public function __construct(array $arguments)
    {
        parent::__construct($arguments);
        $this->mapFileField('field_image');
        $this->autoMap();
    }
}

class BenefitMigration extends BaseNodeMigration {
    public function __construct(array $arguments)
    {
        parent::__construct($arguments);
        $this->mapFileField('field_image');
        $this->mapTermField('MarketTerms', 'field_market');
        $this->mapTermField('ServiceTerms', 'field_services');
        $this->autoMap();
    }
}

class BlogMigration extends BaseNodeMigration
{
    public function __construct(array $arguments)
    {
        parent::__construct($arguments);
        $this->addFieldMapping('field_post_date', 'created')
            ->callbacks(array($this, 'fixPostDate'));
        $this->addFieldMapping('field_post_date:to', 'created')
            ->callbacks(array($this, 'fixPostDate'));

        $info = field_info_field('field_post_date');
        $this->addFieldMapping('field_post_date:timezone')
            ->defaultValue(empty($info['settings']['timezone_db']) ? date_default_timezone(false) : $info['settings']['timezone_db']);
        $this->mapFileField('field_image');
        $this->mapTermField('MarketTerms', 'field_market');
        $this->mapTermField('ServiceTerms', 'field_service_category', 'field_service');
        $this->autoMap();
    }

    function fixPostDate($value) {
        return date('Y-m-d H:i:s', $value);
    }

}

class PackageMigration extends BaseNodeMigration {
    public function __construct(array $arguments)
    {
        parent::__construct($arguments);
        $this->mapFileField('field_image');
        $this->mapFileField('field_teaser_image', 'field_icon');
        $this->mapTermField('ServiceTerms', 'field_service_category', 'field_services');
        $this->addFieldMapping('field_starting_price', 'field_teaser_price')
            ->callbacks(array($this, 'extractPrice'));

        $this->autoMap();
    }

    function extractPrice($value) {
        if(!empty($value[0])) {
            preg_match('/\$([\d\.]+)/', $value[0], $matches);
            if (!empty($matches[1])) {
                return round($matches[1]);
            }
        }

        return null;
    }
}

class ServiceMigration extends BaseNodeMigration {
    
    public function __construct(array $arguments)
    {
        parent::__construct($arguments);
        $this->mapFileField('field_image');
        $this->mapFileField('field_icon');
        $this->mapTermField('ServiceTerms', 'field_service_category', 'field_service');
        $this->addFieldMapping('field_intro', 'field_emotional_intro');
        $this->addFieldMapping('field_intro:format')
            ->defaultValue('filtered_html');
        $this->addFieldMapping('field_display_title', 'field_emotional_title');
        $this->addFieldMapping('field_package_intro', 'field_services_intro');
        $this->addFieldMapping('field_package_intro:format')
            ->defaultValue('filtered_html');
        
        $this->addFieldMapping('field_ap_short_title', 'field_short_title');
        $this->addFieldMapping('field_ap_services_title', 'field_services_title');
        $this->addFieldMapping('field_ap_service_type', 'field_service_type');
        
        $this->autoMap();
    }
    
}

class WebformMigration extends BaseNodeMigration {
    
    public function __construct(array $arguments)
    {
        parent::__construct($arguments);
        $this->autoMap();
    }
    
    public function complete($entity, stdClass $row) {
        /**
         * Once the webform nodes are created, then update the rest of the tables
         */
        //Components
        $this->component($row->nid, $entity->nid);
        //Submissions
        $this->submissions($row->nid, $entity->nid);
        //Submitted data
        $this->submitted_data($row->nid, $entity->nid);
        //Conditional
        $this->conditional($row->nid, $entity->nid);
        //Conditional rules
        $this->conditional_rules($row->nid, $entity->nid);
        //Emails
        $this->emails($row->nid, $entity->nid);
        //Last download
        $this->last_download($row->nid, $entity->nid);
    }
    public function component($old_id, $new_id) {
        $this->set_new_values('webform_component', 'wc', $old_id, $new_id);
    }
    public function submissions($old_id, $new_id) {
        $this->set_new_values('webform_submissions', 'ws', $old_id, $new_id, function(&$row){
            if(empty($row->serial)) {
                $row->serial = $row->sid;
            }
            
            if(empty($row->highest_valid_page)) {
                $row->highest_valid_page = 0;
            }
            
            if(empty($row->completed)) {
                $row->completed = $row->submitted;
            }
            if(empty($row->modified)) {
                $row->modified = $row->submitted;
            }
        });
    }
    public function submitted_data($old_id, $new_id) {
        $this->set_new_values('webform_submitted_data', 'wsd', $old_id, $new_id);
    }
    public function conditional($old_id, $new_id) {
        $this->set_new_values('webform_conditional', 'wc', $old_id, $new_id);
    }
    public function conditional_rules($old_id, $new_id) {
        $this->set_new_values('webform_conditional_rules', 'wcr', $old_id, $new_id);
    }
    public function emails($old_id, $new_id) {
        $this->set_new_values('webform_emails', 'we', $old_id, $new_id, function(&$row){
            if(!isset($row->status)) {
                $row->status = 1;
            }
        });
    }
    public function last_download($old_id, $new_id) {
        $this->set_new_values('webform_last_download', 'wld', $old_id, $new_id);
    }
    //Function to set new values
    public function set_new_values($table, $alias,  $old_id, $new_id, $adjust) {
        if(empty($adjust)) {
            $adjust = function(&$row) {
                //do nothing
            };
        }
        try {
            $rows = Database::getConnection('default', $this->sourceConnection)
                ->select($table, $alias)
                ->fields($alias)
                ->condition($alias . '.nid', $old_id)
                ->execute()->fetchAll();
        }
        catch (Exception $e) {
            watchdog_exception('Webform Migration Exception', $e);
            $rows = array();
        }
        
        foreach ($rows as $row) {
            $adjust($row);
            $row->nid = $new_id;
            drupal_write_record($table, $row);
        }
    }
    
}