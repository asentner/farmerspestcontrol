<?php
/**
 * @file
 * sprowt_flippy_settings.features.fe_block_settings.inc
 */

/**
 * Implements hook_default_fe_block_settings().
 */
function sprowt_flippy_settings_default_fe_block_settings() {
  $export = array();

  $export['version'] = '2.0';

  $export['flippy-flippy_pager'] = array(
    'cache' => -1,
    'css_class' => '',
    'custom' => 0,
    'delta' => 'flippy_pager',
    'module' => 'flippy',
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
        'weight' => -29,
      ),
    ),
    'title' => '',
    'visibility' => 0,
  );

  $export['flippy-flippy_pager-node_type-profile'] = array(
    'cache' => -1,
    'css_class' => '',
    'custom' => 0,
    'delta' => 'flippy_pager-node_type-profile',
    'module' => 'flippy',
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
        'weight' => 0,
      ),
    ),
    'title' => '',
    'visibility' => 0,
  );

  return $export;
}
