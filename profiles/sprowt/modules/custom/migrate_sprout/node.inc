<?php

class BaseNodeMigration extends DrupalNode7Migration {
    public function __construct(array $arguments) {
        parent::__construct($arguments);
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

    public function mapFileField($sourceField, $destField = null) {
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
        $this->addFieldMapping($destField . ':alt', $sourceField . ':alt')
            ->sourceMigration('File');
        $this->addFieldMapping($destField . ':title', $sourceField . ':title')
            ->sourceMigration('File');
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
        $this->mapTermField('ServiceTerms', 'field_service');
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
        $this->mapFileField('field_attachments');
        $this->mapTermField('MarketTerms', 'field_market');
        $this->mapTermField('ServiceTerms', 'field_service');
        $this->autoMap();
    }


    function fixPostDate($value) {
        $value = date('Y-m-d H:i:s', $value);
    }

}