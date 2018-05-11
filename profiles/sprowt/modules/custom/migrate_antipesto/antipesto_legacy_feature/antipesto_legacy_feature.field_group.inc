<?php
/**
 * @file
 * antipesto_legacy_feature.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function antipesto_legacy_feature_field_group_info() {
  $field_groups = array();

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_ap_legacy|node|service|form';
  $field_group->group_name = 'group_ap_legacy';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'service';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Legacy Fields',
    'weight' => '1',
    'children' => array(
      0 => 'field_ap_short_title',
      1 => 'field_ap_services_title',
      2 => 'field_ap_service_type',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-ap-legacy field-group-tab',
        'required_fields' => 1,
      ),
    ),
  );
  $field_groups['group_ap_legacy|node|service|form'] = $field_group;

  // Translatables
  // Included for use with string extractors like potx.
  t('Legacy Fields');

  return $field_groups;
}
