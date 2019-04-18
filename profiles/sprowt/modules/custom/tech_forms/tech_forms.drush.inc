<?php

function tech_forms_drush_command(){
  $items = array();

  $access = ($_SERVER['REMOTE_ADDR'] == '127.0.0.1');
  if($access){
    $items['fetch-form-components'] = [
      'description' => 'Returns an array of a specified webforms components',
      'arguments' => [
        'nid' => 'The Node ID of the webform'
      ],
      'examples' => [
        'drush fetch-form-components 730',
        'drush ffc 730'
      ],
      'aliases' => ['ffc']
    ];
  }
  return $items;
}

function drush_tech_forms_fetch_form_components($nid){
  $node = node_load($nid);
  if(!empty($node)){
    $components = $node->webform['components'];
    $newComponents = techFormComponentsList();

    foreach($newComponents as $nKey => $nVal){
      $found = false;
      foreach($components as $cKey => $cVal){
        if($nVal["form_key"] === $cVal["form_key"]){
          $found = true;
        }
      }
      if(!$found){
        $nVal['nid'] = $nid;
        $nVal['machine_name'] = "__".$nVal["form_key"];
        $node->webform['components'][] = $nVal;
        $test = webform_component_insert($nVal);

      }
    }

   return print_r($test,true);



  }else{
    return "Invalid nid!";
  }
}

function techFormComponentsList(){
  $components = [
    [
      'name' => 'LocationID',
      'form_key' => 'locationid',
      'type' => 'textfield',
      'mandatory' => 0,
      'weight' => 0,
      'pid' => 0,
      'value' => '',
    ],
    [
      'name' => 'First Name',
      'form_key' => 'first_name',
      'type' => 'textfield',
      'mandatory' => 0,
      'weight' => 0,
      'pid' => 0,
      'value' => '',
    ],
    [
      'name' => 'Email',
      'form_key' => 'email',
      'type' => 'email',
      'mandatory' => 0,
      'weight' => 0,
      'pid' => 0,
      'value' => '',
    ]
  ];

  return $components;

}