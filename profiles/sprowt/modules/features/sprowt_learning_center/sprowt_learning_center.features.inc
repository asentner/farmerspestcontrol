<?php
/**
 * @file
 * sprowt_learning_center.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function sprowt_learning_center_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "bean_admin_ui" && $api == "bean") {
    return array("version" => "5");
  }
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
function sprowt_learning_center_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}

/**
 * Implements hook_custom_breadcrumb_features_default_settings().
 */
function sprowt_learning_center_custom_breadcrumb_features_default_settings() {
  $custom_breadcrumbs = array();

  // Exported custom breadcrumb: concern.
  $custom_breadcrumbs['concern'] = array(
    'name' => 'Concern',
    'titles' => 'Learning Center',
    'paths' => 'learning-center',
    'visibility_php' => '',
    'node_type' => 'concern',
    'language' => '',
    'machine_name' => 'concern',
  );

  // Exported custom breadcrumb: issue.
  $custom_breadcrumbs['issue'] = array(
    'name' => 'Issue',
    'titles' => 'Learning Center
<concern>',
    'paths' => 'learning-center
<concern>',
    'visibility_php' => '',
    'node_type' => 'issue',
    'language' => '',
    'machine_name' => 'issue',
  );

  return $custom_breadcrumbs;
}

/**
 * Implements hook_node_info().
 */
function sprowt_learning_center_node_info() {
  $items = array(
    'issue' => array(
      'name' => t('Issue'),
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
