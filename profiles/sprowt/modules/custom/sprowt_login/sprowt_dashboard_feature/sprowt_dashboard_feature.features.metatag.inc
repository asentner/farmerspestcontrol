<?php
/**
 * @file
 * sprowt_dashboard_feature.features.metatag.inc
 */

/**
 * Implements hook_metatag_export_default().
 */
function sprowt_dashboard_feature_metatag_export_default() {
  $config = array();

  // Exported Metatag config instance: node:sprowt_dashboard.
  $config['node:sprowt_dashboard'] = array(
    'instance' => 'node:sprowt_dashboard',
    'config' => array(
      'robots' => array(
        'value' => array(
          'noindex' => 'noindex',
          'nofollow' => 'nofollow',
          'noydir' => 'noydir',
          'index' => 0,
          'follow' => 0,
          'noarchive' => 0,
          'nosnippet' => 0,
          'noodp' => 0,
          'noimageindex' => 0,
          'notranslate' => 0,
        ),
      ),
    ),
  );

  return $config;
}
