<?php
/**
 * @file
 * sprowt_ebooking_features.features.filter.inc
 */

/**
 * Implements hook_filter_default_formats().
 */
function sprowt_ebooking_features_filter_default_formats() {
  $formats = array();

  // Exported format: Webform options.
  $formats['webform_options'] = array(
    'format' => 'webform_options',
    'name' => 'Webform options',
    'cache' => 1,
    'status' => 1,
    'weight' => 0,
    'filters' => array(
      'filter_htmlcorrector' => array(
        'weight' => 10,
        'status' => 1,
        'settings' => array(),
      ),
    ),
  );

  return $formats;
}
