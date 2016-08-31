<?php

/**
 * @file
 * Contains a pre-process hook for 'node'.
 */

/**
 * Implements hook_preprocess_node().
 */
function fresh_light_preprocess_node(&$variables) {
  // IMAGE STYLES
  // Naming Convention: {field_name}_displaymode
  if ($variables['type'] == 'service' && $variables['view_mode'] == 'teaser' && isset($variables['field_image'])) {
    if(!empty($variables['field_image'][0])){
      $service_image = array(
        'style_name' => 'fresh_light_service',
        'path' => $variables['field_image'][0]['uri'],
        'width' => '',
        'height' => '',
        'alt' => $variables['field_image'][0]['alt'],
        'title' => $variables['field_image'][0]['title']
      );
      $variables['field_image_teaser'] = '<div class="field--name-field-image">'.theme('image_style', $service_image).'</div>';
    }
    else {
      $variables['field_image_teaser'] = "";
    }
  }
}
