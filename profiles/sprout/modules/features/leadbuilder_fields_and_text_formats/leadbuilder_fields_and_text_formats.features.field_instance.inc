<?php
/**
 * @file
 * leadbuilder_fields_and_text_formats.features.field_instance.inc
 */

/**
 * Implements hook_field_default_field_instances().
 */
function leadbuilder_fields_and_text_formats_field_default_field_instances() {
  $field_instances = array();

  // Exported field_instance: 'taxonomy_term-regions-field_markets'
  $field_instances['taxonomy_term-regions-field_markets'] = array(
    'bundle' => 'regions',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'taxonomy',
        'settings' => array(),
        'type' => 'taxonomy_term_reference_link',
        'weight' => 1,
      ),
    ),
    'entity_type' => 'taxonomy_term',
    'field_name' => 'field_markets',
    'label' => 'Markets',
    'required' => 0,
    'settings' => array(
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'options',
      'settings' => array(),
      'type' => 'options_buttons',
      'weight' => 5,
    ),
  );

  // Translatables
  // Included for use with string extractors like potx.
  t('Markets');

  return $field_instances;
}
