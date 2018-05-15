<?php

class ApRole extends DrupalRole7Migration {

    function __construct(array $arguments)
    {
        parent::__construct($arguments);
    }
}

class CoalmarchUser extends DrupalUser7Migration {
    function __construct(array $arguments)
    {
        $this->sourceFields += $this->addMetatagToSource();
        parent::__construct($arguments);
        $this->addFieldMapping('roles', 'roles')
            ->sourceMigration('Role');

        $this->autoMap();

        $this->addFieldMapping('field_first_name', 'field_full_name')
            ->callbacks(array($this, 'fixFirstName'));
        $this->addFieldMapping('field_last_name', 'field_full_name')
            ->callbacks(array($this, 'fixLastName'));

    }

    function fixFirstName($value) {
        $name = explode(" ", $value);
        if(!empty($name)) {
            if(is_array($name)) {
                return array_shift($name);
            }
            return $name;
        }
    }

    function fixLastName($value) {
        $name = explode(" ", $value);
        if(!empty($name)) {
            if(is_array($name)) {
                $first = array_shift($name);
                $last = implode(" ", $name);
                return $last;
            }
        }
    }

    function prepareRow($row)
    {
        if(empty($row->uid)) {
            return false;
        }

        if($row->uid == 1) {
            return false;
        }

        $map = _migrate_antipesto_user_email_map();
        if(in_array($row->mail, array_keys($map))) {
            return false;
        }

        parent::prepareRow($row);
        $query = Database::getConnection('default', $this->sourceConnection)
            ->select('metatag', 'm')
            ->fields('m')
            ->condition('m.entity_type', 'user')
            ->condition('m.entity_id', $row->uid)
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
            'uid',
        );
    }

    public function complete($account, $row)
    {
        $map = _migrate_antipesto_user_email_map(true);
        parent::complete($account, $row);
    }
}