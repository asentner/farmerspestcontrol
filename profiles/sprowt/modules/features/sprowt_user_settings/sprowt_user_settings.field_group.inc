<?php

/**
 * @file
 * sprowt_user_settings.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function sprowt_user_settings_field_group_info() {
  $field_groups = array();

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_credentials|user|user|form';
  $field_group->group_name = 'group_credentials';
  $field_group->entity_type = 'user';
  $field_group->bundle = 'user';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'User Credentials',
    'weight' => '1',
    'children' => array(
      0 => 'account',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-credentials field-group-tab',
        'required_fields' => 1,
      ),
    ),
  );
  $field_groups['group_credentials|user|user|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_settings|user|user|form';
  $field_group->group_name = 'group_settings';
  $field_group->entity_type = 'user';
  $field_group->bundle = 'user';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'User Settings',
    'weight' => '2',
    'children' => array(
      0 => 'ckeditor',
      1 => 'metatags',
      2 => 'timezone',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-settings field-group-tab',
        'required_fields' => 1,
      ),
    ),
  );
  $field_groups['group_settings|user|user|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_user_info|user|user|form';
  $field_group->group_name = 'group_user_info';
  $field_group->entity_type = 'user';
  $field_group->bundle = 'user';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'User Info',
    'weight' => '0',
    'children' => array(
      0 => 'field_google_plus_id',
      1 => 'field_position',
      2 => 'field_description',
      3 => 'field_first_name',
      4 => 'field_last_name',
      5 => 'picture',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => '',
        'required_fields' => 1,
      ),
    ),
  );
  $field_groups['group_user_info|user|user|form'] = $field_group;

  // Translatables
  // Included for use with string extractors like potx.
  t('User Credentials');
  t('User Info');
  t('User Settings');

  return $field_groups;
}
