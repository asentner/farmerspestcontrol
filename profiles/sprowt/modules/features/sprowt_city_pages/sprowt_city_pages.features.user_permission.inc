<?php

/**
 * @file
 * sprowt_city_pages.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function sprowt_city_pages_user_default_permissions() {
  $permissions = array();

  // Exported permission: 'create city_page content'.
  $permissions['create city_page content'] = array(
    'name' => 'create city_page content',
    'roles' => array(
      'administrator' => 'administrator',
      'content admin' => 'content admin',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete any city_page content'.
  $permissions['delete any city_page content'] = array(
    'name' => 'delete any city_page content',
    'roles' => array(
      'administrator' => 'administrator',
      'content admin' => 'content admin',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete own city_page content'.
  $permissions['delete own city_page content'] = array(
    'name' => 'delete own city_page content',
    'roles' => array(
      'administrator' => 'administrator',
      'content admin' => 'content admin',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit any city_page content'.
  $permissions['edit any city_page content'] = array(
    'name' => 'edit any city_page content',
    'roles' => array(
      'administrator' => 'administrator',
      'content admin' => 'content admin',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit own city_page content'.
  $permissions['edit own city_page content'] = array(
    'name' => 'edit own city_page content',
    'roles' => array(
      'administrator' => 'administrator',
      'content admin' => 'content admin',
    ),
    'module' => 'node',
  );

  // Exported permission: 'view any anchor_link_bean bean'.
  $permissions['view any anchor_link_bean bean'] = array(
    'name' => 'view any anchor_link_bean bean',
    'roles' => array(
      'anonymous user' => 'anonymous user',
    ),
    'module' => 'bean',
  );

  return $permissions;
}
