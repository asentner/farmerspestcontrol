<?php
/**
 * @file
 * sprowt_solution_finder.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function sprowt_solution_finder_ctools_plugin_api($module = NULL, $api = NULL) {
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
function sprowt_solution_finder_node_info() {
  $items = array(
    'solution' => array(
      'name' => t('Solution'),
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

/**
 * Implements hook_paragraphs_info().
 */
function sprowt_solution_finder_paragraphs_info() {
  $items = array(
    'plan_information' => array(
      'name' => 'Plan Information',
      'bundle' => 'plan_information',
      'locked' => '1',
    ),
  );
  return $items;
}
