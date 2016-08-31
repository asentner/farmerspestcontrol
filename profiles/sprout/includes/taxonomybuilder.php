<?php

class TaxonomyBuilder {
    public $vocabs = array();
    public $vocab;
    
    function __construct($vocab = null) {
        
        $this->vocabs = taxonomy_get_vocabularies();
        
        if(!empty($vocab)) {
            if($this->is_set($vocab)){
                $this->vocab = taxonomy_vocabulary_machine_name_load($vocab);
            }
            else {
                $this->add_vocab($vocab);   
            }
        }
    }
    
    function add_vocab($vocabs){
        if(!is_array($vocabs)
           || (array_keys($vocabs) !== range(0, count($vocabs) - 1))
           )
        {
            $vocabs = array($vocabs);
        }
        
        foreach($vocabs as $vocab){
            $this->add_one_vocab($vocab);
        }
    }
    
    function is_set($vocab_machine_name){
        $set = false;
        foreach($this->vocabs as $vocab) {
            if($vocab_machine_name == $vocab->machine_name){
                $set = true;
            }
        }
        
        return $set;
    }
    
    function name_to_machine($name) {
        $array = str_split($name);
        $machine_name = '';
        foreach($array as $char){
            if(preg_match('/[a-z]/', $char)){
                $machine_name .= $char;
            }
            elseif(preg_match('/[\s\-\_]/', $char)){
                $machine_name .= "_";
            }
        }
        
        return $machine_name;
    }
    
    function add_one_vocab($vocab){
        if(is_string($vocab)){
            $vocab = array('name' => $vocab);
        }
        
        if(empty($vocab['machine_name'])) {
            $vocab['machine_name'] = $this->name_to_machine($vocab['name']);
        }
        
        if($this->is_set($vocab['machine_name'])){
            $old_vocab = taxonomy_vocabulary_machine_name_load($vocab['machine_name']);
            $vocab['vid'] = $old_vocab->vid;
        }
        
        taxonomy_vocabulary_save((object) $vocab);   
        
        $output = taxonomy_vocabulary_machine_name_load($vocab['machine_name']);
        $this->vocabs[$output->vid] = $output;
        $this->vocab = $output;
        
        return $output;
    }
    
    function add_term($term) {
        if(is_string($term)) {
            $term = array('name' => $term);
        }
        
        if(empty($term['vid'])) {
            if(!empty($term['vocabulary_machine_name'])) {
                $vocab = taxonomy_vocabulary_machine_name_load($term['vocabulary_machine_name']);
                $term['vid'] = $vocab->vid;
            }
            else {
                if(empty($this->vocab)) {
                    $vids = array_keys($this->vocabs);
                    $this->vocab = $this->vocabs[$vids[0]];
                }
                $term['vid'] = $this->vocab->vid;
            }
        }
        
        $term = (object) $term;
        
        taxonomy_term_save($term);
        
        return $term;
    }
    
}
