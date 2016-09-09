<?php
/**
 * @file
 * sprowt_user_settings.features.user_role.inc
 */

/**
 * Implements hook_user_default_roles().
 */
function sprowt_user_settings_user_default_roles() {
  $roles = array();

  // Exported role: administrator.
  $roles['administrator'] = array(
    'name' => 'administrator',
    'weight' => 2,
  );

  // Exported role: client.
  $roles['client'] = array(
    'name' => 'client',
    'weight' => 4,
  );

  // Exported role: content admin.
  $roles['content admin'] = array(
    'name' => 'content admin',
    'weight' => 3,
  );

  return $roles;
}
