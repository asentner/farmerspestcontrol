<?php
/**
 * @file
 * sprowt_concerns.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function sprowt_concerns_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "field_group" && $api == "field_group") {
    return array("version" => "1");
  }
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_node_info().
 */
function sprowt_concerns_node_info() {
  $items = array(
    'concern' => array(
      'name' => t('Concern'),
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
