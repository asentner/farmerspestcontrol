<?php
/**
 * @file
 * antipesto_legacy_feature.features.field_base.inc
 */

/**
 * Implements hook_field_default_field_bases().
 */
function antipesto_legacy_feature_field_default_field_bases() {
  $field_bases = array();

  // Exported field_base: 'field_ap_service_type'.
  $field_bases['field_ap_service_type'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_ap_service_type',
    'indexes' => array(
      'value' => array(
        0 => 'value',
      ),
    ),
    'locked' => 0,
    'module' => 'list',
    'settings' => array(
      'allowed_values' => array(
        'residential' => 'Residential',
        'commercial' => 'Commercial',
      ),
      'allowed_values_function' => '',
    ),
    'translatable' => 0,
    'type' => 'list_text',
  );

  // Exported field_base: 'field_ap_services_title'.
  $field_bases['field_ap_services_title'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_ap_services_title',
    'indexes' => array(
      'format' => array(
        0 => 'format',
      ),
    ),
    'locked' => 0,
    'module' => 'text',
    'settings' => array(
      'max_length' => 255,
      'required_summary' => 0,
      'show_summary' => 0,
    ),
    'translatable' => 0,
    'type' => 'text',
  );

  // Exported field_base: 'field_ap_short_title'.
  $field_bases['field_ap_short_title'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_ap_short_title',
    'indexes' => array(
      'format' => array(
        0 => 'format',
      ),
    ),
    'locked' => 0,
    'module' => 'text',
    'settings' => array(
      'max_length' => 255,
      'required_summary' => 0,
      'show_summary' => 0,
    ),
    'translatable' => 0,
    'type' => 'text',
  );

  return $field_bases;
}
