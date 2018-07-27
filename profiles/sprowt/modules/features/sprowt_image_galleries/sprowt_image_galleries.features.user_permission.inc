<?php
/**
 * @file
 * sprowt_image_galleries.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function sprowt_image_galleries_user_default_permissions() {
  $permissions = array();

  // Exported permission: 'create image_gallery content'.
  $permissions['create image_gallery content'] = array(
    'name' => 'create image_gallery content',
    'roles' => array(
      'client' => 'client',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete any image_gallery content'.
  $permissions['delete any image_gallery content'] = array(
    'name' => 'delete any image_gallery content',
    'roles' => array(
      'client' => 'client',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete own image_gallery content'.
  $permissions['delete own image_gallery content'] = array(
    'name' => 'delete own image_gallery content',
    'roles' => array(
      'client' => 'client',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit any image_gallery content'.
  $permissions['edit any image_gallery content'] = array(
    'name' => 'edit any image_gallery content',
    'roles' => array(
      'client' => 'client',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit own image_gallery content'.
  $permissions['edit own image_gallery content'] = array(
    'name' => 'edit own image_gallery content',
    'roles' => array(
      'client' => 'client',
    ),
    'module' => 'node',
  );

  return $permissions;
}
