<?php
/**
 * @file
 * sprowt_image_galleries.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function sprowt_image_galleries_ctools_plugin_api($module = NULL, $api = NULL) {
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
function sprowt_image_galleries_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}

/**
 * Implements hook_node_info().
 */
function sprowt_image_galleries_node_info() {
  $items = array(
    'image_gallery' => array(
      'name' => t('Image Gallery'),
      'base' => 'node_content',
      'description' => t('Create a page of images that can be clicked and enlarged via colorbox.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}

/**
 * Implements hook_weight_features_default_settings().
 */
function sprowt_image_galleries_weight_features_default_settings() {
  $settings = array();

  $settings['gallery_image'] = array(
    'enabled' => 1,
    'range' => 100,
    'menu_weight' => 0,
    'default' => 0,
    'sync_translations' => 0,
  );

  $settings['image_gallery'] = array(
    'enabled' => 0,
    'range' => 20,
    'menu_weight' => 0,
    'default' => 0,
    'sync_translations' => 0,
  );

  return $settings;
}
