<?php
/**
 * @file
 * sprowt_dashboard_feature.features.field_instance.inc
 */

/**
 * Implements hook_field_default_field_instances().
 */
function sprowt_dashboard_feature_field_default_field_instances() {
  $field_instances = array();

  // Exported field_instance: 'node-sprowt_dashboard-body'.
  $field_instances['node-sprowt_dashboard-body'] = array(
    'bundle' => 'sprowt_dashboard',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'alt_teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'default' => array(
        'label' => 'hidden',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 0,
      ),
      'quaternary_teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'secondary_teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'teaser' => array(
        'label' => 'hidden',
        'module' => 'text',
        'settings' => array(
          'trim_length' => 600,
        ),
        'type' => 'text_summary_or_trimmed',
        'weight' => 0,
      ),
      'tertiary_teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'body',
    'label' => 'Body',
    'required' => FALSE,
    'settings' => array(
      'display_summary' => TRUE,
      'text_processing' => 1,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'module' => 'text',
      'settings' => array(
        'rows' => 20,
        'show_token_tree' => FALSE,
        'summary_rows' => 5,
      ),
      'type' => 'text_textarea_with_summary',
      'weight' => 5,
    ),
  );

  // Exported field_instance: 'node-sprowt_dashboard-field_dashboard'.
  $field_instances['node-sprowt_dashboard-field_dashboard'] = array(
    'bundle' => 'sprowt_dashboard',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'alt_teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'default' => array(
        'label' => 'hidden',
        'module' => 'iframe',
        'settings' => array(),
        'type' => 'iframe_formatter_only',
        'weight' => 1,
      ),
      'quaternary_teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'secondary_teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'tertiary_teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_dashboard',
    'label' => 'Dashboard',
    'required' => 0,
    'settings' => array(
      'class' => 'field-iframe-instance',
      'expose_class' => 1,
      'frameborder' => 0,
      'height' => 1200,
      'scrolling' => 'auto',
      'tokensupport' => 0,
      'transparency' => 0,
      'user_register_form' => FALSE,
      'width' => '100%',
    ),
    'widget' => array(
      'active' => 0,
      'module' => 'iframe',
      'settings' => array(
        'size' => 255,
      ),
      'type' => 'iframe_widget_url',
      'weight' => 1,
    ),
  );

  // Translatables
  // Included for use with string extractors like potx.
  t('Body');
  t('Dashboard');

  return $field_instances;
}
