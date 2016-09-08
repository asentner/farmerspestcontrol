<?php
/**
 * @file
 * sprowt_social_sharing.features.fe_block_settings.inc
 */

/**
 * Implements hook_default_fe_block_settings().
 */
function sprowt_social_sharing_default_fe_block_settings() {
  $export = array();

  $export['version'] = '2.0';

  $export['addtoany-addtoany_button'] = array(
    'cache' => -1,
    'css_class' => '',
    'custom' => 0,
    'delta' => 'addtoany_button',
    'module' => 'addtoany',
    'node_types' => array(),
    'pages' => '',
    'roles' => array(),
    'themes' => array(
      'adminimal' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'adminimal',
        'weight' => 0,
      ),
      'sprowt_1' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'sprowt_1',
        'weight' => -37,
      ),
    ),
    'title' => '',
    'visibility' => 0,
  );

  return $export;
}
