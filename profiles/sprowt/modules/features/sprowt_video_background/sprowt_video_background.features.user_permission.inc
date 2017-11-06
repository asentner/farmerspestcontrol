<?php
/**
 * @file
 * sprowt_video_background.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function sprowt_video_background_user_default_permissions() {
  $permissions = array();

  // Exported permission: 'create video_background content'.
  $permissions['create video_background content'] = array(
    'name' => 'create video_background content',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete any video_background content'.
  $permissions['delete any video_background content'] = array(
    'name' => 'delete any video_background content',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete own video_background content'.
  $permissions['delete own video_background content'] = array(
    'name' => 'delete own video_background content',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit any video_background content'.
  $permissions['edit any video_background content'] = array(
    'name' => 'edit any video_background content',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit own video_background content'.
  $permissions['edit own video_background content'] = array(
    'name' => 'edit own video_background content',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  return $permissions;
}
