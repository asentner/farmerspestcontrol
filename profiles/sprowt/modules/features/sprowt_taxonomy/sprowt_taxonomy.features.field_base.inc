<?php
/**
 * @file
 * sprowt_taxonomy.features.field_base.inc
 */

/**
 * Implements hook_field_default_field_bases().
 */
function sprowt_taxonomy_field_default_field_bases() {
  $field_bases = array();

  // Exported field_base: 'field_markets'.
  $field_bases['field_markets'] = array(
    'active' => 1,
    'cardinality' => -1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_markets',
    'indexes' => array(
      'tid' => array(
        0 => 'tid',
      ),
    ),
    'locked' => 0,
    'module' => 'taxonomy',
    'settings' => array(
      'allowed_values' => array(
        0 => array(
          'vocabulary' => 'markets',
          'parent' => 0,
        ),
      ),
    ),
    'translatable' => 0,
    'type' => 'taxonomy_term_reference',
  );

  return $field_bases;
}
