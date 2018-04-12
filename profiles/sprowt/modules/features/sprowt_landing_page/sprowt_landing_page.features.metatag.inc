<?php
/**
 * @file
 * sprowt_landing_page.features.metatag.inc
 */

/**
 * Implements hook_metatag_export_default().
 */
function sprowt_landing_page_metatag_export_default() {
  $config = array();

  // Exported Metatag config instance: node:landing_page.
  $config['node:landing_page'] = array(
    'instance' => 'node:landing_page',
    'disabled' => FALSE,
    'config' => array(
      'robots' => array(
        'value' => array(
          'noindex' => 'noindex',
          'nofollow' => 'nofollow',
          'noarchive' => 'noarchive',
          'nosnippet' => 'nosnippet',
          'index' => 0,
          'follow' => 0,
          'noodp' => 0,
          'noydir' => 0,
          'noimageindex' => 0,
          'notranslate' => 0,
        ),
      ),
    ),
  );

  return $config;
}
