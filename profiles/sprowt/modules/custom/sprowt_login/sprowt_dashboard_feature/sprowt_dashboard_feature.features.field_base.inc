<?php
/**
 * @file
 * sprowt_dashboard_feature.features.field_base.inc
 */

/**
 * Implements hook_field_default_field_bases().
 */
function sprowt_dashboard_feature_field_default_field_bases() {
  $field_bases = array();

  // Exported field_base: 'field_dashboard'.
  $field_bases['field_dashboard'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_dashboard',
    'indexes' => array(),
    'locked' => 0,
    'module' => 'iframe',
    'settings' => array(
      'class' => 'field-iframe',
      'frameborder' => 0,
      'scrolling' => 'auto',
      'tokensupport' => 0,
      'transparency' => 0,
    ),
    'translatable' => 0,
    'type' => 'iframe',
  );

  return $field_bases;
}
