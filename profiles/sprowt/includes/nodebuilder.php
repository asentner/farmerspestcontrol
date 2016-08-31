<?php


/*
 * Deprecated
 *
 *
class NodeBuilder {
    
    private $node;
    
    function __construct(){
        $this->node_reset();
    }
    
    function node_reset(){
        $this->node = new stdClass();
        $this->node->language = LANGUAGE_NONE;
        $this->node->uid = 1;
        $this->node->status = 1;
        $this->node->promote = 0;
        $this->node->comment = 1;
    }
    
    function get_node(){
        return $this->node;
    }
    
    function build_node($fields){
        
        foreach($fields as $field => $value) {
            if(strpos($field, 'field_') !== false || $field == 'body') {
                $l = $this->node->language;
                
                if(array_keys($value) === range(0, count($value) - 1)
                   )
                {
                    $this->node->$field = array(
                        $l => $value
                    );
                }
                else {
                    $this->node->$field = array(
                        $l => array($value)
                    );
                }
            }
            else {
                $this->node->$field = $value;
            }
        }
    }
    
    function save() {
        node_object_prepare($this->node);
        $node = node_submit($this->node);
        node_save($node);
        $this->node_reset();
        return $node->nid;
    }
    
    function add_node($fields) {
        $this->node_reset();
        $this->build_node($fields);
        return $this->save();
    }
    
}
*/

if(!defined('DRUPAL_ROOT')){
    define('DRUPAL_ROOT', str_replace("/profiles/sprowt", "", getcwd()));
    require_once DRUPAL_ROOT . '/includes/bootstrap.inc';
    drupal_bootstrap(DRUPAL_BOOTSTRAP_FULL);
}

if(!function_exists('entity_metadata_wrapper')) {
    module_enable(array('entity'));
}

/**
  Building a better nodebuilder by taking advantage of the entity api wrapper classes
 */

class NodeBuilder extends EntityDrupalWrapper {
    
    public $node_info;
    
    function __construct($data = null, $info = array()){
        
        if(is_string($data)){
            $data = entity_create('node', array('type' => $data));
        }
        
        parent::__construct('node',$data, $info);
        
        $this->node_info = $this->getPropertyInfo();
    }
}