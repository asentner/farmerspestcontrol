<?php
/**
 * @file
 * sprowt_ebooking_features.strongarm.inc
 */

/**
 * Implements hook_strongarm().
 */
function sprowt_ebooking_features_strongarm() {
  $export = array();

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'optionsmarkup_input_format';
  $strongarm->value = 'webform_options';
  $export['optionsmarkup_input_format'] = $strongarm;

  return $export;
}
