<?php 
/**
 * Locations Form
 */

 function sprowt_locations($form, &$form_state, &$install_state){
  drupal_set_title(st('Configure Locations'));

  //Adding scripts
  $form['#attached']['js'][] = "https://code.jquery.com/jquery-1.11.2.min.js"; //I don't wanna use drupal's old as dirt jQuery
  $form['#attached']['js'][] = drupal_get_path('profile', 'sprowt') . "/js/jsrender.min.js";
  
  $form['#attached']['js'][] = drupal_get_path('profile', 'sprowt') . "/js/locations.js";//custom jQuery
  
  //Adding styles
  $form['#attached']['css'][] = drupal_get_path('profile', 'sprowt') . "/css/sprowt.css";
  
  
  ob_start();
  include drupal_get_path('profile', 'sprowt') . '/includes/locations.tpl.php';
  $location_form = ob_get_clean();
  
  
  $form['add_locations'] = array(
   '#prefix' => $location_form,
  );

  $form['hidden_values'] = array(
   'locations' => array(
     '#type' => 'hidden',
     '#default_value' => _sprowt_form_default('locations', '[]'),
     '#attributes' => array(
       'id' => 'locations_hidden',
      ),
    ),
  );
  
  
  $form['hidden_errors'] = array(
    '#type' => 'hidden',
    '#attributes' => array(
     'id' => 'hidden_errors'
    ),
  );
  
  if(!empty($form_state['hidden_errors'])){
    $form['hidden_errors']['#value'] = $form_state['hidden_errors'];
  }
  else {
    $form['hidden_errors']['#value'] = '';
  }
  
  $form['actions']['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Save'),
  );
  
  return $form;
 }
 
 function sprowt_locations_validate($form, &$form_state){
  $locations = json_decode($form['hidden_values']['locations']['#value'], true);
  
  $hidden_errors = array();
  
  $required = array(
    'name' => "Location Name",
    'address' => "Street Address",
    'city' => "Locality",
    'state' => "State or Provence",
    'zip' => "Postal Code",
    'phone' => "Phone"
  );
  
  foreach($locations as $location) {
    $location_id = $location['id'];
    
    foreach($required as $name=>$value){
      if(empty($location[$name])){
        $hidden_errors[] = "#$location_id-$name";
        $variableName = $name . "_message";
        if(empty($$variableName)){
          $$variableName = true;
          drupal_set_message("$value is required", 'error');
        }
      }  
    }
  }
  
  
  if(!empty($hidden_errors)){
    $form_state['hidden_errors'] = json_encode($hidden_errors);
    $form_state['rebuild'] = true;
  }
}
 
 function sprowt_locations_submit($form, &$form_state){
  $fields = array();
  $locations = json_decode($form['hidden_values']['locations']['#value'], true);

  foreach($locations as $location){
    $location_id = $location['id'];
    unset($location['id']);
    $fields[$location_id] = json_encode($location);
  }
  
  _sprowt_save_to_table('locations', $fields);
  
 }