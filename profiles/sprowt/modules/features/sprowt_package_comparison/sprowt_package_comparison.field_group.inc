<?php
/**
 * @file
 * sprowt_package_comparison.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function sprowt_package_comparison_field_group_info() {
  $field_groups = array();

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_main_content|node|package_comparison|form';
  $field_group->group_name = 'group_main_content';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'package_comparison';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Content',
    'weight' => '0',
    'children' => array(
      0 => 'body',
      1 => 'field_hero_image',
      2 => 'field_content_edited',
      3 => 'field_display_title',
      4 => 'field_intro',
      5 => 'field_features',
      6 => 'field_packages',
      7 => 'field_call_out',
      8 => 'title',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-main-content field-group-tab',
        'required_fields' => 1,
      ),
    ),
  );
  $field_groups['group_main_content|node|package_comparison|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_package_comparison|node|package|form';
  $field_group->group_name = 'group_package_comparison';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'package';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Package Comparison',
    'weight' => '1',
    'children' => array(
      0 => 'field_package_colors',
      1 => 'field_package_features',
      2 => 'field_starting_price',
      3 => 'field_block_link',
      4 => 'field_table_link',
      5 => 'field_initial_fee',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-package-comparison field-group-tab',
        'required_fields' => 1,
      ),
    ),
  );
  $field_groups['group_package_comparison|node|package|form'] = $field_group;

  // Translatables
  // Included for use with string extractors like potx.
  t('Content');
  t('Package Comparison');

  return $field_groups;
}
