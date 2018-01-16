<?php
/**
 * @file
 * sprowt_learning_center.bean.inc
 */

/**
 * Implements hook_bean_admin_ui_types().
 */
function sprowt_learning_center_bean_admin_ui_types() {
  $export = array();

  $bean_type = new stdClass();
  $bean_type->disabled = FALSE; /* Edit this to true to make a default bean_type disabled initially */
  $bean_type->api_version = 5;
  $bean_type->name = 'cta_learning_center';
  $bean_type->label = 'CTA - Learning Center';
  $bean_type->options = '';
  $bean_type->description = 'Create a CTA that points to the learning center by choosing common concerns to promote.';
  $export['cta_learning_center'] = $bean_type;

  return $export;
}
