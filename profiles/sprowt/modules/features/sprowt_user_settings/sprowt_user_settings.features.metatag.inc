<?php
/**
 * @file
 * sprowt_user_settings.features.metatag.inc
 */

/**
 * Implements hook_metatag_export_default().
 */
function sprowt_user_settings_metatag_export_default() {
  $config = array();

  // Exported Metatag config instance: user.
  $config['user'] = array(
    'instance' => 'user',
    'disabled' => FALSE,
    'config' => array(
      'title' => array(
        'value' => '[user:name] | [site:name]',
      ),
      'image' => array(
        'value' => '[user:picture:url]',
      ),
    ),
  );

  return $config;
}
