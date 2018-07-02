<?php

function sprowt_theme_preprocess_node(&$variables) {
  
  if ($variables['view_mode'] != 'full') {
    $variables['theme_hook_suggestions'][] = 'node__'.$variables['view_mode'];
    $variables['theme_hook_suggestions'][] = 'node__'.$variables['type'].'__'.$variables['view_mode'];
    $variables['theme_hook_suggestions'][] = 'node__'.$variables['type'].'__'.$variables['view_mode'].'__'.$variables['nid'];
  }

  if ($variables['type'] == 'blog') {
    $user = user_load($variables['uid']);
    $variables['display_submitted'] = TRUE;
    if (!empty($user->field_full_name['und'][0]['safe_value'])) {
      $variables['submitted'] = 'By ' . $user->field_full_name['und'][0]['safe_value'];
    } else {
      $variables['submitted'] = 'By ' . variable_get('coal_admin_company_name');
    }
  }
  else if ($variables['type'] == 'service_category') {
    $variables['classes_array'][] = 'node-'.$variables['nid'];
  }

  $node = $variables['node'];

  if($node->type == 'location') {
      if(!empty($variables['field_phone_number'])) {
          $phone = (!empty($variables['field_phone_number'][LANGUAGE_NONE])) ?
              $variables['field_phone_number'][LANGUAGE_NONE][0] :
              $variables['field_phone_number'][0];

          $phone['value'] = sprowt_settings_format_phone($phone['value']);

          if(!empty($variables['field_phone_number'][LANGUAGE_NONE])) {
              $variables['field_phone_number'][LANGUAGE_NONE][0] = $phone;
          }
          else {
              $variables['field_phone_number'][0] = $phone;
          }
      }
  }

    if($node->type == 'special_offer') {
      if(empty($variables['field_expiration_date'])) {
          $N = entity_metadata_wrapper('node', $node);
          $date = new DateTime(date('Y-m-t 12:00:00'));
          $N->field_expiration_date = $date->getTimestamp();


          $array = field_view_field(
              'node',
              $N->value(),
              'field_expiration_date',
              $variables['view_mode'] == 'full' ? 'default' : $variables['view_mode']
              );

          $variables['content']['field_expiration_date'] = $array;
      }
    }

    if($node->type == 'location') {
      if(!$variables['themed']) {
          $variables['themed'] = true;
          $html = theme('node', $variables);
      }
      $n = entity_metadata_wrapper('node', $node);
      $skip = $n->field_structured_data_disable->value();
      if(strpos($html, 'http://schema.org') === false && empty($skip)) {
          $data = _sprowt_theme_location_structured_data($node);
          $scriptHtml = '<script type="application/ld+json">' . "\n";
          $scriptHtml .= json_encode($data, JSON_PRETTY_PRINT) . "\n";
          $scriptHtml .= '</script>';
          $variables['content']['json_ld'] = array(
              '#type' => 'markup',
              '#markup' => $scriptHtml
          );
      }
    }
    
}
