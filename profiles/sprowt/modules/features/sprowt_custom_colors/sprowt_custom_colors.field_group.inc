<?php
/**
 * @file
 * sprowt_custom_colors.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function sprowt_custom_colors_field_group_info() {
  $field_groups = array();

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_background|paragraphs_item|colors|form';
  $field_group->group_name = 'group_background';
  $field_group->entity_type = 'paragraphs_item';
  $field_group->bundle = 'colors';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Background',
    'weight' => '0',
    'children' => array(
      0 => 'field_color_background',
      1 => 'field_image_background',
      2 => 'field_image_background_style',
      3 => 'field_color_background_overlay',
      4 => 'field_background_overlay_opacity',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'Background',
      'instance_settings' => array(
        'required_fields' => 1,
        'id' => '',
        'classes' => '',
        'description' => '',
      ),
      'formatter' => 'collapsed',
    ),
  );
  $field_groups['group_background|paragraphs_item|colors|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_body|paragraphs_item|colors|form';
  $field_group->group_name = 'group_body';
  $field_group->entity_type = 'paragraphs_item';
  $field_group->bundle = 'colors';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Body',
    'weight' => '2',
    'children' => array(
      0 => 'field_color_text',
      1 => 'field_color_link',
      2 => 'field_color_link_hover',
      3 => 'field_color_stars',
      4 => 'field_color_list_item_bullets',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'Body',
      'instance_settings' => array(
        'required_fields' => 1,
        'id' => '',
        'classes' => '',
        'description' => '',
      ),
      'formatter' => 'collapsed',
    ),
  );
  $field_groups['group_body|paragraphs_item|colors|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_border|paragraphs_item|colors|form';
  $field_group->group_name = 'group_border';
  $field_group->entity_type = 'paragraphs_item';
  $field_group->bundle = 'colors';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Border',
    'weight' => '1',
    'children' => array(
      0 => 'field_color_border',
      1 => 'field_border_style',
      2 => 'field_border_size',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'Border',
      'instance_settings' => array(
        'required_fields' => 1,
        'id' => '',
        'classes' => 'group-border field-group-fieldset',
        'description' => '',
      ),
      'formatter' => 'collapsed',
    ),
  );
  $field_groups['group_border|paragraphs_item|colors|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_buttons|paragraphs_item|colors|form';
  $field_group->group_name = 'group_buttons';
  $field_group->entity_type = 'paragraphs_item';
  $field_group->bundle = 'colors';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Buttons',
    'weight' => '3',
    'children' => array(
      0 => 'field_button_colors',
      1 => 'field_button_hover_colors',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'Buttons',
      'instance_settings' => array(
        'required_fields' => 1,
        'id' => '',
        'classes' => '',
        'description' => '',
      ),
      'formatter' => 'collapsed',
    ),
  );
  $field_groups['group_buttons|paragraphs_item|colors|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_custom|paragraphs_item|colors|form';
  $field_group->group_name = 'group_custom';
  $field_group->entity_type = 'paragraphs_item';
  $field_group->bundle = 'colors';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Custom',
    'weight' => '7',
    'children' => array(
      0 => 'field_custom_color',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'Custom',
      'instance_settings' => array(
        'required_fields' => 1,
        'id' => '',
        'classes' => '',
        'description' => '',
      ),
      'formatter' => 'collapsed',
    ),
  );
  $field_groups['group_custom|paragraphs_item|colors|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_forms|paragraphs_item|colors|form';
  $field_group->group_name = 'group_forms';
  $field_group->entity_type = 'paragraphs_item';
  $field_group->bundle = 'colors';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Forms',
    'weight' => '5',
    'children' => array(
      0 => 'field_input_background_color',
      1 => 'field_input_border_color',
      2 => 'field_label_color',
      3 => 'field_input_text_color',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'Forms',
      'instance_settings' => array(
        'required_fields' => 1,
        'id' => '',
        'classes' => '',
        'description' => '',
      ),
      'formatter' => 'collapsed',
    ),
  );
  $field_groups['group_forms|paragraphs_item|colors|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_headers|paragraphs_item|colors|form';
  $field_group->group_name = 'group_headers';
  $field_group->entity_type = 'paragraphs_item';
  $field_group->bundle = 'colors';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Headers',
    'weight' => '6',
    'children' => array(
      0 => 'field_header_color',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'Headers',
      'instance_settings' => array(
        'required_fields' => 1,
        'id' => '',
        'classes' => '',
        'description' => '',
      ),
      'formatter' => 'collapsed',
    ),
  );
  $field_groups['group_headers|paragraphs_item|colors|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_shadow|paragraphs_item|colors|form';
  $field_group->group_name = 'group_shadow';
  $field_group->entity_type = 'paragraphs_item';
  $field_group->bundle = 'colors';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Shadow',
    'weight' => '4',
    'children' => array(
      0 => 'field_box_shadow',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'Shadow',
      'instance_settings' => array(
        'required_fields' => 1,
        'id' => '',
        'classes' => 'group-shadow field-group-fieldset',
        'description' => '',
      ),
      'formatter' => 'collapsed',
    ),
  );
  $field_groups['group_shadow|paragraphs_item|colors|form'] = $field_group;

  // Translatables
  // Included for use with string extractors like potx.
  t('Background');
  t('Body');
  t('Border');
  t('Buttons');
  t('Custom');
  t('Forms');
  t('Headers');
  t('Shadow');

  return $field_groups;
}
