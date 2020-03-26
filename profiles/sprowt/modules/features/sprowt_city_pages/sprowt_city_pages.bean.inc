<?php

/**
 * @file
 * sprowt_city_pages.bean.inc
 */

/**
 * Implements hook_bean_admin_ui_types().
 */
function sprowt_city_pages_bean_admin_ui_types() {
  $export = array();

  $bean_type = new stdClass();
  $bean_type->disabled = FALSE; /* Edit this to true to make a default bean_type disabled initially */
  $bean_type->api_version = 5;
  $bean_type->name = 'anchor_link_bean';
  $bean_type->label = 'Anchor Link Bean';
  $bean_type->options = '';
  $bean_type->description = 'Formatted list of anchor links for pages with long content.';
  $export['anchor_link_bean'] = $bean_type;

  return $export;
}
