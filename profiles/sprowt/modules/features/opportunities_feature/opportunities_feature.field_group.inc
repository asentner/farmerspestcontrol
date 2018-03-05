<?php
/**
 * @file
 * opportunities_feature.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function opportunities_feature_field_group_info() {
  $field_groups = array();

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_content|node|opportunity|form';
  $field_group->group_name = 'group_content';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'opportunity';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Content',
    'weight' => '2',
    'children' => array(
      0 => 'body',
      1 => 'field_application_link',
      2 => 'field_benefits',
      3 => 'field_category',
      4 => 'field_weight',
      5 => 'field_location',
      6 => 'field_employment_types',
      7 => 'title',
      8 => 'group_salary',
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
  $field_groups['group_content|node|opportunity|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_salary|node|opportunity|form';
  $field_group->group_name = 'group_salary';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'opportunity';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_content';
  $field_group->data = array(
    'label' => 'Salary Range',
    'weight' => '10',
    'children' => array(
      0 => 'field_salary_range_from',
      1 => 'field_salary_range_to',
      2 => 'field_salary_range_unit',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-salary field-group-fieldset',
        'required_fields' => 1,
        'id' => '',
      ),
    ),
  );
  $field_groups['group_salary|node|opportunity|form'] = $field_group;

  // Translatables
  // Included for use with string extractors like potx.
  t('Content');
  t('Salary Range');

  return $field_groups;
}
