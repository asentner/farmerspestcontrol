<?php
/**
 * @file
 * sprowt_package_comparison.bean.inc
 */

/**
 * Implements hook_bean_admin_ui_types().
 */
function sprowt_package_comparison_bean_admin_ui_types() {
  $export = array();

  $bean_type = new stdClass();
  $bean_type->disabled = FALSE; /* Edit this to true to make a default bean_type disabled initially */
  $bean_type->api_version = 5;
  $bean_type->name = 'package_comparison';
  $bean_type->label = 'Package comparison';
  $bean_type->options = '';
  $bean_type->description = 'This creates a block that allows you to choose packages to compare and place them as blocked elements on a page.';
  $export['package_comparison'] = $bean_type;

  $bean_type = new stdClass();
  $bean_type->disabled = FALSE; /* Edit this to true to make a default bean_type disabled initially */
  $bean_type->api_version = 5;
  $bean_type->name = 'package_comparison_table';
  $bean_type->label = 'Package comparison table';
  $bean_type->options = '';
  $bean_type->description = 'This creates a block that allows you to choose packages to compare and place them as blocked elements on a page as a table view.';
  $export['package_comparison_table'] = $bean_type;

  return $export;
}
