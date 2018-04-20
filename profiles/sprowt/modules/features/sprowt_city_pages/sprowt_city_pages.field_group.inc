<?php
/**
 * @file
 * sprowt_city_pages.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function sprowt_city_pages_field_group_info() {
  $field_groups = array();

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_anchor_block|node|city_page|form';
  $field_group->group_name = 'group_anchor_block';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'city_page';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Anchor Block',
    'weight' => '8',
    'children' => array(
      0 => 'field_anchor_title',
      1 => 'field_anchor_link',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-anchor-block field-group-fieldset',
        'required_fields' => 1,
        'id' => '',
      ),
    ),
  );
  $field_groups['group_anchor_block|node|city_page|form'] = $field_group;

  // Translatables
  // Included for use with string extractors like potx.
  t('Anchor Block');

  return $field_groups;
}
