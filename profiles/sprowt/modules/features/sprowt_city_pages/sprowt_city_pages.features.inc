<?php

/**
 * @file
 * sprowt_city_pages.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function sprowt_city_pages_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "bean_admin_ui" && $api == "bean") {
    return array("version" => "5");
  }
  if ($module == "context" && $api == "context") {
    return array("version" => "3");
  }
  if ($module == "field_group" && $api == "field_group") {
    return array("version" => "1");
  }
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_views_api().
 */
function sprowt_city_pages_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}

/**
 * Implements hook_node_info().
 */
function sprowt_city_pages_node_info() {
  $items = array(
    'city_page' => array(
      'name' => t('City Page'),
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
function sprowt_city_pages_paragraphs_info() {
  $items = array(
    'city_service' => array(
      'name' => 'Service Details',
      'bundle' => 'city_service',
      'locked' => '1',
    ),
  );
  return $items;
}
