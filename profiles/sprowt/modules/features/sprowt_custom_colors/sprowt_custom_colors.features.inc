<?php
/**
 * @file
 * sprowt_custom_colors.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function sprowt_custom_colors_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "field_group" && $api == "field_group") {
    return array("version" => "1");
  }
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_paragraphs_info().
 */
function sprowt_custom_colors_paragraphs_info() {
  $items = array(
    'colors' => array(
      'name' => 'Colors',
      'bundle' => 'colors',
      'locked' => '1',
    ),
  );
  return $items;
}
