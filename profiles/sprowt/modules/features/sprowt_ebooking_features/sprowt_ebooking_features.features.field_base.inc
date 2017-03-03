<?php
/**
 * @file
 * sprowt_ebooking_features.features.field_base.inc
 */

/**
 * Implements hook_field_default_field_bases().
 */
function sprowt_ebooking_features_field_default_field_bases() {
  $field_bases = array();

  // Exported field_base: 'field_ebooking'.
  $field_bases['field_ebooking'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_ebooking',
    'indexes' => array(
      'value' => array(
        0 => 'value',
      ),
    ),
    'locked' => 0,
    'module' => 'list',
    'settings' => array(
      'allowed_values' => array(
        'no' => 'No',
        'yes' => 'yes',
      ),
      'allowed_values_function' => '',
    ),
    'translatable' => 0,
    'type' => 'list_text',
  );

  return $field_bases;
}
