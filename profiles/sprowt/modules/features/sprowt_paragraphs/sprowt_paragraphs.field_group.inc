<?php

/**
 * @file
 * sprowt_paragraphs.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function sprowt_paragraphs_field_group_info() {
  $field_groups = array();

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_advanced|paragraphs_item|aggregate_review_testimonial|form';
  $field_group->group_name = 'group_advanced';
  $field_group->entity_type = 'paragraphs_item';
  $field_group->bundle = 'aggregate_review_testimonial';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Advanced',
    'weight' => '5',
    'children' => array(
      0 => 'field_label',
      1 => 'field_custom_class',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-advanced field-group-fieldset',
        'required_fields' => 1,
        'id' => '',
      ),
    ),
  );
  $field_groups['group_advanced|paragraphs_item|aggregate_review_testimonial|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_advanced|paragraphs_item|block_embed|form';
  $field_group->group_name = 'group_advanced';
  $field_group->entity_type = 'paragraphs_item';
  $field_group->bundle = 'block_embed';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Advanced',
    'weight' => '1',
    'children' => array(
      0 => 'field_label',
      1 => 'field_custom_class',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-advanced field-group-fieldset',
        'required_fields' => 1,
        'id' => '',
      ),
    ),
  );
  $field_groups['group_advanced|paragraphs_item|block_embed|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_advanced|paragraphs_item|body|form';
  $field_group->group_name = 'group_advanced';
  $field_group->entity_type = 'paragraphs_item';
  $field_group->bundle = 'body';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Advanced',
    'weight' => '5',
    'children' => array(
      0 => 'field_custom_class',
      1 => 'field_label',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => '',
        'required_fields' => 1,
        'id' => '',
      ),
    ),
  );
  $field_groups['group_advanced|paragraphs_item|body|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_advanced|paragraphs_item|cta|form';
  $field_group->group_name = 'group_advanced';
  $field_group->entity_type = 'paragraphs_item';
  $field_group->bundle = 'cta';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Advanced',
    'weight' => '3',
    'children' => array(
      0 => 'field_label',
      1 => 'field_custom_class',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-advanced field-group-fieldset',
        'required_fields' => 1,
        'id' => '',
      ),
    ),
  );
  $field_groups['group_advanced|paragraphs_item|cta|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_advanced|paragraphs_item|image_break|form';
  $field_group->group_name = 'group_advanced';
  $field_group->entity_type = 'paragraphs_item';
  $field_group->bundle = 'image_break';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Advanced',
    'weight' => '1',
    'children' => array(
      0 => 'field_custom_class',
      1 => 'field_label',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-advanced field-group-fieldset',
        'required_fields' => 1,
        'id' => '',
      ),
    ),
  );
  $field_groups['group_advanced|paragraphs_item|image_break|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_advanced|paragraphs_item|linked_image|form';
  $field_group->group_name = 'group_advanced';
  $field_group->entity_type = 'paragraphs_item';
  $field_group->bundle = 'linked_image';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Advanced',
    'weight' => '3',
    'children' => array(
      0 => 'field_custom_class',
      1 => 'field_label',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-advanced field-group-fieldset',
        'required_fields' => 1,
        'id' => '',
      ),
    ),
  );
  $field_groups['group_advanced|paragraphs_item|linked_image|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_advanced|paragraphs_item|modal|form';
  $field_group->group_name = 'group_advanced';
  $field_group->entity_type = 'paragraphs_item';
  $field_group->bundle = 'modal';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Advanced',
    'weight' => '1',
    'children' => array(
      0 => 'field_label',
      1 => 'field_custom_class',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-advanced field-group-fieldset',
        'required_fields' => 1,
        'id' => '',
      ),
    ),
  );
  $field_groups['group_advanced|paragraphs_item|modal|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_advanced|paragraphs_item|overlap|form';
  $field_group->group_name = 'group_advanced';
  $field_group->entity_type = 'paragraphs_item';
  $field_group->bundle = 'overlap';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Advanced',
    'weight' => '1',
    'children' => array(
      0 => 'field_label',
      1 => 'field_custom_class',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-advanced field-group-fieldset',
        'required_fields' => 1,
        'id' => '',
      ),
    ),
  );
  $field_groups['group_advanced|paragraphs_item|overlap|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_advanced|paragraphs_item|paragraphs|form';
  $field_group->group_name = 'group_advanced';
  $field_group->entity_type = 'paragraphs_item';
  $field_group->bundle = 'paragraphs';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Advanced',
    'weight' => '3',
    'children' => array(
      0 => 'field_custom_class',
      1 => 'field_label',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => '',
        'required_fields' => 1,
        'id' => '',
      ),
    ),
  );
  $field_groups['group_advanced|paragraphs_item|paragraphs|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_advanced|paragraphs_item|table|form';
  $field_group->group_name = 'group_advanced';
  $field_group->entity_type = 'paragraphs_item';
  $field_group->bundle = 'table';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Advanced',
    'weight' => '3',
    'children' => array(
      0 => 'field_label',
      1 => 'field_custom_class',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-advanced field-group-fieldset',
        'required_fields' => 1,
        'id' => '',
      ),
    ),
  );
  $field_groups['group_advanced|paragraphs_item|table|form'] = $field_group;

  // Translatables
  // Included for use with string extractors like potx.
  t('Advanced');

  return $field_groups;
}
