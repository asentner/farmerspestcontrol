<?php
/**
 * @file
 * sprowt_video_library.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function sprowt_video_library_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "context" && $api == "context") {
    return array("version" => "3");
  }
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_views_api().
 */
function sprowt_video_library_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}

/**
 * Implements hook_image_default_styles().
 */
function sprowt_video_library_image_default_styles() {
  $styles = array();

  // Exported image style: video_thumbnail.
  $styles['video_thumbnail'] = array(
    'label' => 'Video Thumbnail',
    'effects' => array(
      2 => array(
        'name' => 'focal_point_scale_and_crop',
        'data' => array(
          'width' => 375,
          'height' => 200,
          'focal_point_advanced' => array(
            'shift_x' => '',
            'shift_y' => '',
          ),
        ),
        'weight' => 2,
      ),
    ),
  );

  return $styles;
}

/**
 * Implements hook_node_info().
 */
function sprowt_video_library_node_info() {
  $items = array(
    'video' => array(
      'name' => t('Video'),
      'base' => 'node_content',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}
