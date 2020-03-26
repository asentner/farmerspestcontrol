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
  $field_group->parent_name = '_add_new_group';
  $field_group->data = array(
    'label' => 'Anchor Block',
    'weight' => '9',
    'children' => array(
      0 => 'field_anchor_link',
      1 => 'field_anchor_title',
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

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_content|node|city_page|form';
  $field_group->group_name = 'group_content';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'city_page';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Content',
    'weight' => '0',
    'children' => array(
      0 => 'body',
      1 => 'field_call_out',
      2 => 'field_city_services',
      3 => 'field_display_title',
      4 => 'field_hero_image',
      5 => 'field_image',
      6 => 'field_intro',
      7 => 'field_market',
      8 => 'field_seo_title',
      9 => 'title',
      10 => 'group_anchor_block',
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
  $field_groups['group_content|node|city_page|form'] = $field_group;

  // Translatables
  // Included for use with string extractors like potx.
  t('Anchor Block');
  t('Content');

  return $field_groups;
}
