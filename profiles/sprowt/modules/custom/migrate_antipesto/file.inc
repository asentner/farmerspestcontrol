<?php

class FocalPointDestinationHandler extends MigrateDestinationHandler {
    function __construct() {
        $this->registerTypes(array('file'));
    }
    
    public function fields() {
        return array(
            'focal_point' => t('Focal Points attached to the image')
        );
    }
    
    public function complete($entity, stdClass $row){
        if(!empty($entity->focal_point)) {
            focal_point_save($entity->fid, $entity->focal_point);
        }
    }
}

class FocalPointFile extends DrupalFile7Migration {
    function __construct(array $arguments) {
        parent::__construct($arguments);
        if($this->moduleExists('focal_point')) {
            $this->addFieldMapping('focal_point', 'focal_point');
        }
    }
    
    function query() {
        $query = parent::query();
        if($this->moduleExists('focal_point')) {
            $query->leftJoin('focal_point', 'p', 'p.fid=f.fid');
            $query->addField('p', 'focal_point');
        }
        return $query;
    }
}