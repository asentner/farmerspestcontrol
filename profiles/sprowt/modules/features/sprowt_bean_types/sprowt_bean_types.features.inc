<?php

/**
 * @file
 * sprowt_bean_types.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function sprowt_bean_types_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "bean_admin_ui" && $api == "bean") {
    return array("version" => "5");
  }
}

/**
 * Implements hook_views_api().
 */
function sprowt_bean_types_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}

/**
 * Implements hook_image_default_styles().
 */
function sprowt_bean_types_image_default_styles() {
  $styles = array();

  // Exported image style: video_bean.
  $styles['video_bean'] = array(
    'label' => 'Video Bean',
    'effects' => array(
      1 => array(
        'name' => 'focal_point_scale_and_crop',
        'data' => array(
          'width' => 1600,
          'height' => 500,
          'focal_point_advanced' => array(
            'shift_x' => '',
            'shift_y' => '',
          ),
        ),
        'weight' => 1,
      ),
    ),
  );

  return $styles;
}
