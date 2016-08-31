<?php
/**
 * Market Setup
 */

function sprout_market_setup($form, &$form_state, &$install_state){
  drupal_set_title(st('Configure Markets'));

  //Adding scripts
  $form['#attached']['js'][] = "https://code.jquery.com/jquery-1.11.2.min.js"; //I don't wanna use drupal's old as dirt jQuery
  //drupal_add_js("https://code.jquery.com/ui/1.11.3/jquery-ui.min.js"); Don't need this as we aren't going to o drag and drop
  $form['#attached']['js'][] = drupal_get_path('profile', 'sprout') . "/js/jsrender.min.js";
  
  $form['#attached']['js'][] = drupal_get_path('profile', 'sprout') . "/js/market.js";//custom jQuery
  
  //Adding styles
  $form['#attached']['css'][] = drupal_get_path('profile', 'sprout') . "/css/sprout.css";
  
  ob_start();
  include drupal_get_path('profile', 'sprout') .'/includes/market_setup.tpl.php';
  $market_form = ob_get_clean();
  
  ob_start();
  include drupal_get_path('profile', 'sprout') .'/includes/service_setup.tpl.php';
  $service_form = ob_get_clean();
  
  $form['service_setup'] = array(
    '#type' => 'fieldset',
    '#title' => 'Setup Services',
    '#description' => 'Add services here.',
    'custom_form' => array(
      '#prefix' => $service_form,
    )
  );
  $form['service_setup']['hidden_values'] = array(
    'services' => array(
      '#type' => 'hidden',
      '#default_value' => _sprout_form_default('services', '[]'),
      '#attributes' => array(
        'id' => 'services_hidden'
      ),
    ),
  );
 
  $form['market_setup'] = array(
    '#type' => 'fieldset',
    '#title' => 'Setup Markets',
    '#description' => 'Add regions then add markets under regions',
    'custom_form' => array(
      '#prefix' => $market_form,
    ),
  );
  $form['market_setup']['hidden_values']=array(
   'region_markets' => array(
    '#type' => 'hidden',
    '#default_value' => _sprout_form_default('region_markets', '{}'),
    '#attributes' => array(
     'id' => 'region_markets'
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
  
  if(!empty($install_state['forms']['sprout_market_setup'])){
    if(!empty($install_state['forms']['sprout_market_setup']['region_markets'])){
      $form['market_setup']['hidden_values']['region_markets']['#default_value'] = $install_state['forms']['sprout_market_setup']['region_markets'];
    }
    if(!empty($install_state['forms']['sprout_market_setup']['services'])){
      $form['service_setup']['hidden_values']['services']['#default_value'] = $install_state['forms']['sprout_market_setup']['services'];
    }
  }
  
  return $form;
}

function sprout_market_setup_validate($form, &$form_state){
  $services = json_decode($form['service_setup']['hidden_values']['services']['#value'], true);
  
  $hidden_errors = array();
  
  $one_s_error = true;
  $service_names = array();
  foreach($services as $service){
    $serviceId = array_keys($service);
    $serviceName = array_values($service);
    
    $serviceId = $serviceId[0];
    $serviceName = $serviceName[0];
    
    if(strpos($serviceName, " in ") !== false){
      if(empty($service_in)){
        $service_in = true;
        drupal_set_message('Service name must not contain [space]in[space]', 'error');
      }
      $hidden_errors[] = '#' .$serviceId . " .serviceName";
    }
    
    
    if(in_array($serviceName, $service_names)){
      if(empty($service_multi)){
        drupal_set_message('Service name must be unique', 'error');
        $service_multi = true;
      }
      $hidden_errors[] = '#' .$serviceId . " .serviceName";
    }
    
    $service_names[] = $serviceName;
    if(empty($serviceName)){
      $hidden_errors[] = '#' .$serviceId . " .serviceName";
      if($one_s_error){
        $one_s_error = false;
        drupal_set_message('Services must be named', 'error');
      }
    }
  }
  
  $regions = json_decode($form['market_setup']['hidden_values']['region_markets']['#value'], true);
  
  $one_r_error = true;
  $market_names = array();
  $region_names = array();
  foreach($regions as $regionId => $props){
    if(empty($props['regionName'])){
      $hidden_errors[] = '#' .$regionId . " .regionName";
      if($one_r_error){
        $one_r_error = false;
        drupal_set_message('Regions must be named', 'error');
      }
    }
    
    if(in_array($props['regionName'], $region_names)){
      if(empty($region_multi)){
        $region_multi = true;
        drupal_set_message('Regions names must be unique', 'error');
      }
      $hidden_errors[] = '#' .$regionId . " .regionName";
    }
    $region_names[] = $props['regionName'];
    
    if(strpos($props['regionName'], " in ") !== false){
      if(empty($region_in)){
        $region_in = true;
        drupal_set_message('Region name must not contain [space]in[space]', 'error');
      }
      $hidden_errors[] = '#' .$regionId . " .regionName";
    }
    
    $one_m_error = true;
    foreach($props['markets'] as $market){
      $marketId = array_keys($market);
      $marketName = array_values($market);
      
      $marketId = $marketId[0];
      $marketName = $marketName[0];
      
      if(in_array($marketName, $market_names)){
        if(empty($market_multi)){
          drupal_set_message('Market names must be unique', 'error');
          $market_multi = true;
        }
        $hidden_errors[] = '#' .$regionId . " #" . $marketId . " .marketName";
      }
      $market_names[] = $marketName;
      
      if(empty($marketName)){
        $hidden_errors[] = '#' .$regionId . " #" . $marketId . " .marketName";
        if($one_m_error){
          $one_m_error = false;
          drupal_set_message('Markets must be named', 'error');
        }
      }
      
      if(strpos($marketName, " in ") !== false){
        if(empty($market_in)){
          $market_in = true;
          drupal_set_message('Market name must not contain [space]in[space]', 'error');
        }
        $hidden_errors[] = '#' .$regionId . " #" . $marketId . " .marketName";
      }
    }
  }
  
  if(!empty($hidden_errors)){
    $form_state['hidden_errors'] = json_encode($hidden_errors);
    $form_state['rebuild'] = true;
  }
}

function sprout_market_setup_submit($form, $form_state){
  $service_map = json_decode($form['service_setup']['hidden_values']['services']['#value'], true);
  $region_map = json_decode($form['market_setup']['hidden_values']['region_markets']['#value'], true);
  
  $services = array();
  $regions = array();
  
  foreach($service_map as $service){
    $serviceName = array_values($service);
    $services[] = $serviceName[0];
  }
  
  foreach($region_map as $regionId => $props){
    
    $regions[$props['regionName']] = array();
    
    foreach($props['markets'] as $market){
      $marketName = array_values($market);
      $regions[$props['regionName']][] = $marketName[0];
    }
  }
  
  $fields = array(
    'services' => json_encode($services),
    'regions' => json_encode($regions),
  );
  
  _sprout_save_to_table('market_setup', $fields);
  
}