<?php
/**
 * @file
 * sprowt_fields_and_text_formats.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function sprowt_fields_and_text_formats_user_default_permissions() {
  $permissions = array();

  // Exported permission: 'use text format webform_options'.
  $permissions['use text format webform_options'] = array(
    'name' => 'use text format webform_options',
    'roles' => array(
      'administrator' => 'administrator',
      'anonymous user' => 'anonymous user',
    ),
    'module' => 'filter',
  );

  return $permissions;
}
