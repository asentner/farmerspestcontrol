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
}
