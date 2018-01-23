<?php
/**
 * @file
 * sprowt_concerns.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function sprowt_concerns_field_group_info() {
  $field_groups = array();

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_content|node|concern|form';
  $field_group->group_name = 'group_content';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'concern';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Content',
    'weight' => '0',
    'children' => array(
      0 => 'body',
      1 => 'field_icon_file',
      2 => 'field_concern_steps',
      3 => 'field_concern_treatment',
      4 => 'field_intro',
      5 => 'field_call_out',
      6 => 'title',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-content field-group-tab',
        'required_fields' => 1,
      ),
    ),
  );
  $field_groups['group_content|node|concern|form'] = $field_group;

  // Translatables
  // Included for use with string extractors like potx.
  t('Content');

  return $field_groups;
}
