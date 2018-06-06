<?php
/**
 * @file
 * sprowt_custom_colors.features.field_instance.inc
 */

/**
 * Implements hook_field_default_field_instances().
 */
function sprowt_custom_colors_field_default_field_instances() {
  $field_instances = array();

  // Exported field_instance:
  // 'field_collection_item-field_box_shadow-field_shadow_blur_radius'.
  $field_instances['field_collection_item-field_box_shadow-field_shadow_blur_radius'] = array(
    'bundle' => 'field_box_shadow',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'number',
        'settings' => array(
          'decimal_separator' => '.',
          'prefix_suffix' => TRUE,
          'scale' => 0,
          'thousand_separator' => '',
        ),
        'type' => 'number_integer',
        'weight' => 2,
      ),
    ),
    'entity_type' => 'field_collection_item',
    'field_name' => 'field_shadow_blur_radius',
    'label' => 'Blur Radius',
    'required' => 0,
    'settings' => array(
      'max' => '',
      'min' => '',
      'prefix' => '',
      'suffix' => 'px',
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 0,
      'module' => 'number',
      'settings' => array(),
      'type' => 'number',
      'weight' => 3,
    ),
  );

  // Exported field_instance:
  // 'field_collection_item-field_box_shadow-field_shadow_color'.
  $field_instances['field_collection_item-field_box_shadow-field_shadow_color'] = array(
    'bundle' => 'field_box_shadow',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'taxonomy',
        'settings' => array(),
        'type' => 'taxonomy_term_reference_link',
        'weight' => 4,
      ),
    ),
    'entity_type' => 'field_collection_item',
    'field_name' => 'field_shadow_color',
    'label' => 'Color',
    'required' => 0,
    'settings' => array(
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'options',
      'settings' => array(),
      'type' => 'options_select',
      'weight' => 5,
    ),
  );

  // Exported field_instance:
  // 'field_collection_item-field_box_shadow-field_shadow_inset'.
  $field_instances['field_collection_item-field_box_shadow-field_shadow_inset'] = array(
    'bundle' => 'field_box_shadow',
    'default_value' => array(
      0 => array(
        'value' => 0,
      ),
    ),
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'list',
        'settings' => array(),
        'type' => 'list_default',
        'weight' => 5,
      ),
    ),
    'entity_type' => 'field_collection_item',
    'field_name' => 'field_shadow_inset',
    'label' => 'Inset?',
    'required' => 0,
    'settings' => array(
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'options',
      'settings' => array(
        'display_label' => 1,
      ),
      'type' => 'options_onoff',
      'weight' => 0,
    ),
  );

  // Exported field_instance:
  // 'field_collection_item-field_box_shadow-field_shadow_offset_x'.
  $field_instances['field_collection_item-field_box_shadow-field_shadow_offset_x'] = array(
    'bundle' => 'field_box_shadow',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'number',
        'settings' => array(
          'decimal_separator' => '.',
          'prefix_suffix' => TRUE,
          'scale' => 0,
          'thousand_separator' => '',
        ),
        'type' => 'number_integer',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'field_collection_item',
    'field_name' => 'field_shadow_offset_x',
    'label' => 'Offset X',
    'required' => 0,
    'settings' => array(
      'max' => '',
      'min' => '',
      'prefix' => '',
      'suffix' => 'px',
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 0,
      'module' => 'number',
      'settings' => array(),
      'type' => 'number',
      'weight' => 1,
    ),
  );

  // Exported field_instance:
  // 'field_collection_item-field_box_shadow-field_shadow_offset_y'.
  $field_instances['field_collection_item-field_box_shadow-field_shadow_offset_y'] = array(
    'bundle' => 'field_box_shadow',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'number',
        'settings' => array(
          'decimal_separator' => '.',
          'prefix_suffix' => TRUE,
          'scale' => 0,
          'thousand_separator' => '',
        ),
        'type' => 'number_integer',
        'weight' => 1,
      ),
    ),
    'entity_type' => 'field_collection_item',
    'field_name' => 'field_shadow_offset_y',
    'label' => 'Offset Y',
    'required' => 0,
    'settings' => array(
      'max' => '',
      'min' => '',
      'prefix' => '',
      'suffix' => 'px',
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 0,
      'module' => 'number',
      'settings' => array(),
      'type' => 'number',
      'weight' => 2,
    ),
  );

  // Exported field_instance:
  // 'field_collection_item-field_box_shadow-field_shadow_spread_radius'.
  $field_instances['field_collection_item-field_box_shadow-field_shadow_spread_radius'] = array(
    'bundle' => 'field_box_shadow',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'number',
        'settings' => array(
          'decimal_separator' => '.',
          'prefix_suffix' => TRUE,
          'scale' => 0,
          'thousand_separator' => '',
        ),
        'type' => 'number_integer',
        'weight' => 3,
      ),
    ),
    'entity_type' => 'field_collection_item',
    'field_name' => 'field_shadow_spread_radius',
    'label' => 'Spread Radius',
    'required' => 0,
    'settings' => array(
      'max' => '',
      'min' => '',
      'prefix' => '',
      'suffix' => 'px',
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 0,
      'module' => 'number',
      'settings' => array(),
      'type' => 'number',
      'weight' => 4,
    ),
  );

  // Exported field_instance:
  // 'field_collection_item-field_button_colors-field_color_background'.
  $field_instances['field_collection_item-field_button_colors-field_color_background'] = array(
    'bundle' => 'field_button_colors',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'taxonomy',
        'settings' => array(),
        'type' => 'taxonomy_term_reference_link',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'field_collection_item',
    'field_name' => 'field_color_background',
    'label' => 'Background',
    'required' => 0,
    'settings' => array(
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'options',
      'settings' => array(),
      'type' => 'options_select',
      'weight' => 0,
    ),
  );

  // Exported field_instance:
  // 'field_collection_item-field_button_colors-field_color_border'.
  $field_instances['field_collection_item-field_button_colors-field_color_border'] = array(
    'bundle' => 'field_button_colors',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'taxonomy',
        'settings' => array(),
        'type' => 'taxonomy_term_reference_link',
        'weight' => 2,
      ),
    ),
    'entity_type' => 'field_collection_item',
    'field_name' => 'field_color_border',
    'label' => 'Border',
    'required' => 0,
    'settings' => array(
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'options',
      'settings' => array(),
      'type' => 'options_select',
      'weight' => 2,
    ),
  );

  // Exported field_instance:
  // 'field_collection_item-field_button_colors-field_color_text'.
  $field_instances['field_collection_item-field_button_colors-field_color_text'] = array(
    'bundle' => 'field_button_colors',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'taxonomy',
        'settings' => array(),
        'type' => 'taxonomy_term_reference_link',
        'weight' => 1,
      ),
    ),
    'entity_type' => 'field_collection_item',
    'field_name' => 'field_color_text',
    'label' => 'Text',
    'required' => 0,
    'settings' => array(
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'options',
      'settings' => array(),
      'type' => 'options_select',
      'weight' => 1,
    ),
  );

  // Exported field_instance:
  // 'field_collection_item-field_button_hover_colors-field_color_background'.
  $field_instances['field_collection_item-field_button_hover_colors-field_color_background'] = array(
    'bundle' => 'field_button_hover_colors',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'taxonomy',
        'settings' => array(),
        'type' => 'taxonomy_term_reference_link',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'field_collection_item',
    'field_name' => 'field_color_background',
    'label' => 'Background',
    'required' => 0,
    'settings' => array(
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'options',
      'settings' => array(),
      'type' => 'options_select',
      'weight' => 0,
    ),
  );

  // Exported field_instance:
  // 'field_collection_item-field_button_hover_colors-field_color_border'.
  $field_instances['field_collection_item-field_button_hover_colors-field_color_border'] = array(
    'bundle' => 'field_button_hover_colors',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'taxonomy',
        'settings' => array(),
        'type' => 'taxonomy_term_reference_link',
        'weight' => 2,
      ),
    ),
    'entity_type' => 'field_collection_item',
    'field_name' => 'field_color_border',
    'label' => 'Border',
    'required' => 0,
    'settings' => array(
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'options',
      'settings' => array(),
      'type' => 'options_select',
      'weight' => 2,
    ),
  );

  // Exported field_instance:
  // 'field_collection_item-field_button_hover_colors-field_color_text'.
  $field_instances['field_collection_item-field_button_hover_colors-field_color_text'] = array(
    'bundle' => 'field_button_hover_colors',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'taxonomy',
        'settings' => array(),
        'type' => 'taxonomy_term_reference_link',
        'weight' => 1,
      ),
    ),
    'entity_type' => 'field_collection_item',
    'field_name' => 'field_color_text',
    'label' => 'Text',
    'required' => 0,
    'settings' => array(
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'options',
      'settings' => array(),
      'type' => 'options_select',
      'weight' => 1,
    ),
  );

  // Exported field_instance:
  // 'field_collection_item-field_custom_color-field_css_color'.
  $field_instances['field_collection_item-field_custom_color-field_css_color'] = array(
    'bundle' => 'field_custom_color',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'taxonomy',
        'settings' => array(),
        'type' => 'taxonomy_term_reference_link',
        'weight' => 2,
      ),
    ),
    'entity_type' => 'field_collection_item',
    'field_name' => 'field_css_color',
    'label' => 'Color',
    'required' => 0,
    'settings' => array(
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'options',
      'settings' => array(),
      'type' => 'options_select',
      'weight' => 2,
    ),
  );

  // Exported field_instance:
  // 'field_collection_item-field_custom_color-field_css_property'.
  $field_instances['field_collection_item-field_custom_color-field_css_property'] = array(
    'bundle' => 'field_custom_color',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'list',
        'settings' => array(),
        'type' => 'list_default',
        'weight' => 3,
      ),
    ),
    'entity_type' => 'field_collection_item',
    'field_name' => 'field_css_property',
    'label' => 'CSS Property',
    'required' => 0,
    'settings' => array(
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'options',
      'settings' => array(),
      'type' => 'options_select',
      'weight' => 1,
    ),
  );

  // Exported field_instance:
  // 'field_collection_item-field_custom_color-field_css_selector'.
  $field_instances['field_collection_item-field_custom_color-field_css_selector'] = array(
    'bundle' => 'field_custom_color',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'field_collection_item',
    'field_name' => 'field_css_selector',
    'label' => 'CSS Selector',
    'required' => 0,
    'settings' => array(
      'text_processing' => 0,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'text',
      'settings' => array(
        'show_token_tree' => 0,
        'size' => 60,
      ),
      'type' => 'text_textfield',
      'weight' => 0,
    ),
  );

  // Exported field_instance:
  // 'field_collection_item-field_header_color-field_color_header'.
  $field_instances['field_collection_item-field_header_color-field_color_header'] = array(
    'bundle' => 'field_header_color',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'taxonomy',
        'settings' => array(),
        'type' => 'taxonomy_term_reference_link',
        'weight' => 1,
      ),
    ),
    'entity_type' => 'field_collection_item',
    'field_name' => 'field_color_header',
    'label' => 'Color Header',
    'required' => 0,
    'settings' => array(
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'options',
      'settings' => array(),
      'type' => 'options_select',
      'weight' => 2,
    ),
  );

  // Exported field_instance:
  // 'field_collection_item-field_header_color-field_header_selector'.
  $field_instances['field_collection_item-field_header_color-field_header_selector'] = array(
    'bundle' => 'field_header_color',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'Which headers will be this color',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'list',
        'settings' => array(),
        'type' => 'list_default',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'field_collection_item',
    'field_name' => 'field_header_selector',
    'label' => 'Header',
    'required' => 0,
    'settings' => array(
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'options',
      'settings' => array(),
      'type' => 'options_buttons',
      'weight' => 1,
    ),
  );

  // Exported field_instance:
  // 'field_collection_item-field_text_shadow-field_no_shadow'.
  $field_instances['field_collection_item-field_text_shadow-field_no_shadow'] = array(
    'bundle' => 'field_text_shadow',
    'default_value' => array(
      0 => array(
        'value' => 0,
      ),
    ),
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'list',
        'settings' => array(),
        'type' => 'list_default',
        'weight' => 4,
      ),
    ),
    'entity_type' => 'field_collection_item',
    'field_name' => 'field_no_shadow',
    'label' => 'None',
    'required' => 0,
    'settings' => array(
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'options',
      'settings' => array(
        'display_label' => 1,
      ),
      'type' => 'options_onoff',
      'weight' => 0,
    ),
  );

  // Exported field_instance:
  // 'field_collection_item-field_text_shadow-field_shadow_blur_radius'.
  $field_instances['field_collection_item-field_text_shadow-field_shadow_blur_radius'] = array(
    'bundle' => 'field_text_shadow',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'number',
        'settings' => array(
          'decimal_separator' => '.',
          'prefix_suffix' => TRUE,
          'scale' => 0,
          'thousand_separator' => '',
        ),
        'type' => 'number_integer',
        'weight' => 2,
      ),
    ),
    'entity_type' => 'field_collection_item',
    'field_name' => 'field_shadow_blur_radius',
    'label' => 'Blur Radius',
    'required' => 0,
    'settings' => array(
      'max' => '',
      'min' => '',
      'prefix' => '',
      'suffix' => 'px',
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 0,
      'module' => 'number',
      'settings' => array(),
      'type' => 'number',
      'weight' => 3,
    ),
  );

  // Exported field_instance:
  // 'field_collection_item-field_text_shadow-field_shadow_color'.
  $field_instances['field_collection_item-field_text_shadow-field_shadow_color'] = array(
    'bundle' => 'field_text_shadow',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'taxonomy',
        'settings' => array(),
        'type' => 'taxonomy_term_reference_link',
        'weight' => 3,
      ),
    ),
    'entity_type' => 'field_collection_item',
    'field_name' => 'field_shadow_color',
    'label' => 'Color',
    'required' => 0,
    'settings' => array(
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'options',
      'settings' => array(),
      'type' => 'options_select',
      'weight' => 4,
    ),
  );

  // Exported field_instance:
  // 'field_collection_item-field_text_shadow-field_shadow_offset_x'.
  $field_instances['field_collection_item-field_text_shadow-field_shadow_offset_x'] = array(
    'bundle' => 'field_text_shadow',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'number',
        'settings' => array(
          'decimal_separator' => '.',
          'prefix_suffix' => TRUE,
          'scale' => 0,
          'thousand_separator' => '',
        ),
        'type' => 'number_integer',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'field_collection_item',
    'field_name' => 'field_shadow_offset_x',
    'label' => 'Offset X',
    'required' => 0,
    'settings' => array(
      'max' => '',
      'min' => '',
      'prefix' => '',
      'suffix' => 'px',
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 0,
      'module' => 'number',
      'settings' => array(),
      'type' => 'number',
      'weight' => 1,
    ),
  );

  // Exported field_instance:
  // 'field_collection_item-field_text_shadow-field_shadow_offset_y'.
  $field_instances['field_collection_item-field_text_shadow-field_shadow_offset_y'] = array(
    'bundle' => 'field_text_shadow',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'number',
        'settings' => array(
          'decimal_separator' => '.',
          'prefix_suffix' => TRUE,
          'scale' => 0,
          'thousand_separator' => '',
        ),
        'type' => 'number_integer',
        'weight' => 1,
      ),
    ),
    'entity_type' => 'field_collection_item',
    'field_name' => 'field_shadow_offset_y',
    'label' => 'Offset Y',
    'required' => 0,
    'settings' => array(
      'max' => '',
      'min' => '',
      'prefix' => '',
      'suffix' => 'px',
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 0,
      'module' => 'number',
      'settings' => array(),
      'type' => 'number',
      'weight' => 2,
    ),
  );

  // Exported field_instance: 'node-landing_page-field_colors'.
  $field_instances['node-landing_page-field_colors'] = array(
    'bundle' => 'landing_page',
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
        'module' => 'paragraphs',
        'settings' => array(
          'view_mode' => 'full',
        ),
        'type' => 'paragraphs_view',
        'weight' => 3,
      ),
      'quinary_teaser' => array(
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
    ),
    'entity_type' => 'node',
    'field_name' => 'field_colors',
    'label' => 'Colors',
    'required' => 0,
    'settings' => array(
      'add_mode' => 'button',
      'allowed_bundles' => array(
        'annotated_image' => -1,
        'block_embed' => -1,
        'body' => -1,
        'colors' => 'colors',
        'image_break' => -1,
        'landing_page_header_footer' => -1,
        'linked_image' => -1,
        'paragraphs' => -1,
        'table' => -1,
        'table_cell' => -1,
        'table_row' => -1,
      ),
      'bundle_weights' => array(
        'annotated_image' => 2,
        'block_embed' => 3,
        'body' => 4,
        'colors' => 5,
        'image_break' => 6,
        'landing_page_header_footer' => 7,
        'linked_image' => 8,
        'paragraphs' => 9,
        'table' => 10,
        'table_cell' => 11,
        'table_row' => 12,
      ),
      'default_edit_mode' => 'preview',
      'title' => 'Paragraph',
      'title_multiple' => 'Paragraphs',
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 0,
      'module' => 'paragraphs',
      'settings' => array(),
      'type' => 'paragraphs_embed',
      'weight' => 1,
    ),
  );

  // Exported field_instance: 'paragraphs_item-block_embed-field_colors'.
  $field_instances['paragraphs_item-block_embed-field_colors'] = array(
    'bundle' => 'block_embed',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'paragraphs',
        'settings' => array(
          'view_mode' => 'full',
        ),
        'type' => 'paragraphs_view',
        'weight' => 3,
      ),
      'paragraphs_editor_preview' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'paragraphs_item',
    'field_name' => 'field_colors',
    'label' => 'Colors',
    'required' => 0,
    'settings' => array(
      'add_mode' => 'button',
      'allowed_bundles' => array(
        'annotated_image' => -1,
        'block_embed' => -1,
        'body' => -1,
        'colors' => 'colors',
        'image_break' => -1,
        'landing_page_areas_we_service' => -1,
        'landing_page_benefits' => -1,
        'landing_page_features' => -1,
        'landing_page_header_footer' => -1,
        'landing_page_hero' => -1,
        'landing_page_package' => -1,
        'landing_page_packages' => -1,
        'landing_page_special_offer' => -1,
        'landing_page_testimonial' => -1,
        'linked_image' => -1,
        'modal' => -1,
        'paragraphs' => -1,
        'table' => -1,
        'table_cell' => -1,
        'table_row' => -1,
      ),
      'bundle_weights' => array(
        'annotated_image' => 2,
        'block_embed' => 3,
        'body' => 4,
        'colors' => 5,
        'image_break' => 6,
        'landing_page_areas_we_service' => 7,
        'landing_page_benefits' => 8,
        'landing_page_features' => 9,
        'landing_page_header_footer' => 10,
        'landing_page_hero' => 11,
        'landing_page_package' => 12,
        'landing_page_packages' => 13,
        'landing_page_special_offer' => 14,
        'landing_page_testimonial' => 15,
        'linked_image' => 16,
        'modal' => 17,
        'paragraphs' => 18,
        'table' => 19,
        'table_cell' => 20,
        'table_row' => 21,
      ),
      'default_edit_mode' => 'closed',
      'title' => 'Paragraph',
      'title_multiple' => 'Paragraphs',
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 0,
      'module' => 'paragraphs',
      'settings' => array(),
      'type' => 'paragraphs_embed',
      'weight' => 6,
    ),
  );

  // Exported field_instance: 'paragraphs_item-body-field_colors'.
  $field_instances['paragraphs_item-body-field_colors'] = array(
    'bundle' => 'body',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'paragraphs',
        'settings' => array(
          'view_mode' => 'full',
        ),
        'type' => 'paragraphs_view',
        'weight' => 7,
      ),
      'paragraphs_editor_preview' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'paragraphs_item',
    'field_name' => 'field_colors',
    'label' => 'Colors',
    'required' => 0,
    'settings' => array(
      'add_mode' => 'button',
      'allowed_bundles' => array(
        'annotated_image' => -1,
        'block_embed' => -1,
        'body' => -1,
        'colors' => 'colors',
        'image_break' => -1,
        'landing_page_benefits' => -1,
        'landing_page_features' => -1,
        'landing_page_header_footer' => -1,
        'landing_page_hero' => -1,
        'linked_image' => -1,
        'modal' => -1,
        'paragraphs' => -1,
        'table' => -1,
        'table_cell' => -1,
        'table_row' => -1,
      ),
      'bundle_weights' => array(
        'annotated_image' => 2,
        'block_embed' => 3,
        'body' => 4,
        'colors' => 5,
        'image_break' => 6,
        'landing_page_benefits' => 7,
        'landing_page_features' => 8,
        'landing_page_header_footer' => 9,
        'landing_page_hero' => 10,
        'linked_image' => 11,
        'modal' => 12,
        'paragraphs' => 13,
        'table' => 14,
        'table_cell' => 15,
        'table_row' => 16,
      ),
      'default_edit_mode' => 'closed',
      'title' => 'Paragraph',
      'title_multiple' => 'Paragraphs',
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 0,
      'module' => 'paragraphs',
      'settings' => array(),
      'type' => 'paragraphs_embed',
      'weight' => 6,
    ),
  );

  // Exported field_instance:
  // 'paragraphs_item-colors-field_background_overlay_opacity'.
  $field_instances['paragraphs_item-colors-field_background_overlay_opacity'] = array(
    'bundle' => 'colors',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '0 = transparent, 100 = solid.',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 7,
      ),
      'paragraphs_editor_preview' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'paragraphs_item',
    'field_name' => 'field_background_overlay_opacity',
    'label' => 'Background Overlay Opacity',
    'required' => 0,
    'settings' => array(
      'max' => 100,
      'min' => 0,
      'prefix' => '',
      'suffix' => '%',
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 0,
      'module' => 'number',
      'settings' => array(),
      'type' => 'number',
      'weight' => 3,
    ),
  );

  // Exported field_instance: 'paragraphs_item-colors-field_border_size'.
  $field_instances['paragraphs_item-colors-field_border_size'] = array(
    'bundle' => 'colors',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'number',
        'settings' => array(
          'decimal_separator' => '.',
          'prefix_suffix' => TRUE,
          'scale' => 0,
          'thousand_separator' => '',
        ),
        'type' => 'number_integer',
        'weight' => 21,
      ),
      'paragraphs_editor_preview' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'paragraphs_item',
    'field_name' => 'field_border_size',
    'label' => 'Size',
    'required' => 0,
    'settings' => array(
      'max' => '',
      'min' => 0,
      'prefix' => '',
      'suffix' => 'px',
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 0,
      'module' => 'number',
      'settings' => array(),
      'type' => 'number',
      'weight' => 7,
    ),
  );

  // Exported field_instance: 'paragraphs_item-colors-field_border_style'.
  $field_instances['paragraphs_item-colors-field_border_style'] = array(
    'bundle' => 'colors',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'list',
        'settings' => array(),
        'type' => 'list_default',
        'weight' => 20,
      ),
      'paragraphs_editor_preview' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'paragraphs_item',
    'field_name' => 'field_border_style',
    'label' => 'Style',
    'required' => 0,
    'settings' => array(
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'options',
      'settings' => array(),
      'type' => 'options_select',
      'weight' => 8,
    ),
  );

  // Exported field_instance: 'paragraphs_item-colors-field_box_shadow'.
  $field_instances['paragraphs_item-colors-field_box_shadow'] = array(
    'bundle' => 'colors',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'Go <a href="https://developer.mozilla.org/en-US/docs/Web/CSS/box-shadow#Values" target="_blank">here</a> for more info on the different box shadow fields',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'field_collection',
        'settings' => array(
          'add' => 'Add',
          'delete' => 'Delete',
          'description' => TRUE,
          'edit' => 'Edit',
          'view_mode' => 'full',
        ),
        'type' => 'field_collection_view',
        'weight' => 22,
      ),
      'paragraphs_editor_preview' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'paragraphs_item',
    'field_name' => 'field_box_shadow',
    'label' => 'Box Shadow',
    'required' => 0,
    'settings' => array(
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 0,
      'module' => 'field_collection',
      'settings' => array(),
      'type' => 'field_collection_embed',
      'weight' => 22,
    ),
  );

  // Exported field_instance: 'paragraphs_item-colors-field_button_colors'.
  $field_instances['paragraphs_item-colors-field_button_colors'] = array(
    'bundle' => 'colors',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'field_collection',
        'settings' => array(
          'add' => 'Add',
          'delete' => 'Delete',
          'description' => TRUE,
          'edit' => 'Edit',
          'view_mode' => 'full',
        ),
        'type' => 'field_collection_view',
        'weight' => 14,
      ),
      'paragraphs_editor_preview' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'paragraphs_item',
    'field_name' => 'field_button_colors',
    'label' => 'Button Colors',
    'required' => 0,
    'settings' => array(
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 0,
      'module' => 'field_collection',
      'settings' => array(),
      'type' => 'field_collection_embed',
      'weight' => 18,
    ),
  );

  // Exported field_instance:
  // 'paragraphs_item-colors-field_button_hover_colors'.
  $field_instances['paragraphs_item-colors-field_button_hover_colors'] = array(
    'bundle' => 'colors',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'field_collection',
        'settings' => array(
          'add' => 'Add',
          'delete' => 'Delete',
          'description' => TRUE,
          'edit' => 'Edit',
          'view_mode' => 'full',
        ),
        'type' => 'field_collection_view',
        'weight' => 15,
      ),
      'paragraphs_editor_preview' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'paragraphs_item',
    'field_name' => 'field_button_hover_colors',
    'label' => 'Button Hover Colors',
    'required' => 0,
    'settings' => array(
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 0,
      'module' => 'field_collection',
      'settings' => array(),
      'type' => 'field_collection_embed',
      'weight' => 19,
    ),
  );

  // Exported field_instance: 'paragraphs_item-colors-field_color_background'.
  $field_instances['paragraphs_item-colors-field_color_background'] = array(
    'bundle' => 'colors',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'paragraphs_editor_preview' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'paragraphs_item',
    'field_name' => 'field_color_background',
    'label' => 'Background Color',
    'required' => 0,
    'settings' => array(
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'options',
      'settings' => array(),
      'type' => 'options_select',
      'weight' => 1,
    ),
  );

  // Exported field_instance:
  // 'paragraphs_item-colors-field_color_background_overlay'.
  $field_instances['paragraphs_item-colors-field_color_background_overlay'] = array(
    'bundle' => 'colors',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 6,
      ),
      'paragraphs_editor_preview' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'paragraphs_item',
    'field_name' => 'field_color_background_overlay',
    'label' => 'Background Overlay Color',
    'required' => 0,
    'settings' => array(
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'options',
      'settings' => array(),
      'type' => 'options_select',
      'weight' => 2,
    ),
  );

  // Exported field_instance: 'paragraphs_item-colors-field_color_border'.
  $field_instances['paragraphs_item-colors-field_color_border'] = array(
    'bundle' => 'colors',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 10,
      ),
      'paragraphs_editor_preview' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'paragraphs_item',
    'field_name' => 'field_color_border',
    'label' => 'Color',
    'required' => 0,
    'settings' => array(
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'options',
      'settings' => array(),
      'type' => 'options_select',
      'weight' => 9,
    ),
  );

  // Exported field_instance: 'paragraphs_item-colors-field_color_link'.
  $field_instances['paragraphs_item-colors-field_color_link'] = array(
    'bundle' => 'colors',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 2,
      ),
      'paragraphs_editor_preview' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'paragraphs_item',
    'field_name' => 'field_color_link',
    'label' => 'Link',
    'required' => 0,
    'settings' => array(
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'options',
      'settings' => array(),
      'type' => 'options_select',
      'weight' => 3,
    ),
  );

  // Exported field_instance: 'paragraphs_item-colors-field_color_link_hover'.
  $field_instances['paragraphs_item-colors-field_color_link_hover'] = array(
    'bundle' => 'colors',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 3,
      ),
      'paragraphs_editor_preview' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'paragraphs_item',
    'field_name' => 'field_color_link_hover',
    'label' => 'Link Hover',
    'required' => 0,
    'settings' => array(
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'options',
      'settings' => array(),
      'type' => 'options_select',
      'weight' => 4,
    ),
  );

  // Exported field_instance:
  // 'paragraphs_item-colors-field_color_list_item_bullets'.
  $field_instances['paragraphs_item-colors-field_color_list_item_bullets'] = array(
    'bundle' => 'colors',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'This is for the bullets or checks or what have you that come before list items.',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'taxonomy',
        'settings' => array(),
        'type' => 'taxonomy_term_reference_link',
        'weight' => 13,
      ),
      'paragraphs_editor_preview' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'paragraphs_item',
    'field_name' => 'field_color_list_item_bullets',
    'label' => 'List Item Bullets',
    'required' => 0,
    'settings' => array(
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'options',
      'settings' => array(),
      'type' => 'options_select',
      'weight' => 6,
    ),
  );

  // Exported field_instance: 'paragraphs_item-colors-field_color_stars'.
  $field_instances['paragraphs_item-colors-field_color_stars'] = array(
    'bundle' => 'colors',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'This will change the color of any stars',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'taxonomy',
        'settings' => array(),
        'type' => 'taxonomy_term_reference_link',
        'weight' => 12,
      ),
      'paragraphs_editor_preview' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'paragraphs_item',
    'field_name' => 'field_color_stars',
    'label' => 'Stars',
    'required' => 0,
    'settings' => array(
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'options',
      'settings' => array(),
      'type' => 'options_select',
      'weight' => 5,
    ),
  );

  // Exported field_instance: 'paragraphs_item-colors-field_color_text'.
  $field_instances['paragraphs_item-colors-field_color_text'] = array(
    'bundle' => 'colors',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 1,
      ),
      'paragraphs_editor_preview' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'paragraphs_item',
    'field_name' => 'field_color_text',
    'label' => 'Body Text',
    'required' => 0,
    'settings' => array(
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'options',
      'settings' => array(),
      'type' => 'options_select',
      'weight' => 2,
    ),
  );

  // Exported field_instance: 'paragraphs_item-colors-field_custom_color'.
  $field_instances['paragraphs_item-colors-field_custom_color'] = array(
    'bundle' => 'colors',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 9,
      ),
      'paragraphs_editor_preview' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'paragraphs_item',
    'field_name' => 'field_custom_color',
    'label' => 'Custom Color',
    'required' => 0,
    'settings' => array(
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 0,
      'module' => 'field_collection',
      'settings' => array(),
      'type' => 'field_collection_embed',
      'weight' => 10,
    ),
  );

  // Exported field_instance: 'paragraphs_item-colors-field_header_color'.
  $field_instances['paragraphs_item-colors-field_header_color'] = array(
    'bundle' => 'colors',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 8,
      ),
      'paragraphs_editor_preview' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'paragraphs_item',
    'field_name' => 'field_header_color',
    'label' => 'Header Color',
    'required' => 0,
    'settings' => array(
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 0,
      'module' => 'field_collection',
      'settings' => array(),
      'type' => 'field_collection_embed',
      'weight' => 21,
    ),
  );

  // Exported field_instance: 'paragraphs_item-colors-field_image_background'.
  $field_instances['paragraphs_item-colors-field_image_background'] = array(
    'bundle' => 'colors',
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 4,
      ),
      'paragraphs_editor_preview' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'paragraphs_item',
    'field_name' => 'field_image_background',
    'label' => 'Background Image',
    'required' => 0,
    'settings' => array(
      'alt_field' => 0,
      'default_image' => 0,
      'file_directory' => '',
      'file_extensions' => 'png gif jpg jpeg',
      'max_filesize' => '',
      'max_resolution' => '',
      'min_resolution' => '',
      'title_field' => 0,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'multiupload_imagefield_widget',
      'settings' => array(
        'insert' => 0,
        'insert_absolute' => 0,
        'insert_class' => '',
        'insert_default' => 'auto',
        'insert_styles' => array(
          'auto' => 'auto',
          'icon_link' => 0,
          'image' => 0,
          'image_affiliation_image' => 0,
          'image_annotated_image' => 0,
          'image_benefits' => 0,
          'image_benefits__front_page_' => 0,
          'image_flexslider_full' => 0,
          'image_flexslider_thumbnail' => 0,
          'image_focal_point_preview' => 0,
          'image_focal_point_scale_and_crop_80x80' => 0,
          'image_focal_point_scale_and_crop_100x100' => 0,
          'image_focal_point_scale_and_crop_185x150' => 0,
          'image_focal_point_scale_and_crop_250x250' => 0,
          'image_focal_point_scale_and_crop_470x400' => 0,
          'image_focal_point_scale_and_crop_500x325' => 0,
          'image_focal_point_scale_and_crop_600x475' => 0,
          'image_focal_point_scale_and_crop_800x600' => 0,
          'image_fresh_light_service' => 0,
          'image_large' => 0,
          'image_markets' => 0,
          'image_medium' => 0,
          'image_menu_icon' => 0,
          'image_package_icon' => 0,
          'image_primary__800x400_' => 0,
          'image_profile' => 0,
          'image_scale_60x60' => 0,
          'image_scale_235' => 0,
          'image_service' => 0,
          'image_service_primary' => 0,
          'image_slideshow_homepage' => 0,
          'image_special_offers_slideshow' => 0,
          'image_thumbnail' => 0,
          'link' => 0,
        ),
        'insert_width' => '',
        'preview_image_style' => 'thumbnail',
        'progress_indicator' => 'throbber',
      ),
      'type' => 'image_miw',
      'weight' => 4,
    ),
  );

  // Exported field_instance:
  // 'paragraphs_item-colors-field_image_background_style'.
  $field_instances['paragraphs_item-colors-field_image_background_style'] = array(
    'bundle' => 'colors',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 5,
      ),
      'paragraphs_editor_preview' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'paragraphs_item',
    'field_name' => 'field_image_background_style',
    'label' => 'Background Image Style',
    'required' => 0,
    'settings' => array(
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'options',
      'settings' => array(),
      'type' => 'options_select',
      'weight' => 5,
    ),
  );

  // Exported field_instance:
  // 'paragraphs_item-colors-field_input_background_color'.
  $field_instances['paragraphs_item-colors-field_input_background_color'] = array(
    'bundle' => 'colors',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'taxonomy',
        'settings' => array(),
        'type' => 'taxonomy_term_reference_link',
        'weight' => 16,
      ),
      'paragraphs_editor_preview' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'paragraphs_item',
    'field_name' => 'field_input_background_color',
    'label' => 'Input Background',
    'required' => 0,
    'settings' => array(
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'options',
      'settings' => array(),
      'type' => 'options_select',
      'weight' => 24,
    ),
  );

  // Exported field_instance: 'paragraphs_item-colors-field_input_border_color'.
  $field_instances['paragraphs_item-colors-field_input_border_color'] = array(
    'bundle' => 'colors',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'taxonomy',
        'settings' => array(),
        'type' => 'taxonomy_term_reference_link',
        'weight' => 17,
      ),
      'paragraphs_editor_preview' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'paragraphs_item',
    'field_name' => 'field_input_border_color',
    'label' => 'Input Border',
    'required' => 0,
    'settings' => array(
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'options',
      'settings' => array(),
      'type' => 'options_select',
      'weight' => 25,
    ),
  );

  // Exported field_instance: 'paragraphs_item-colors-field_input_text_color'.
  $field_instances['paragraphs_item-colors-field_input_text_color'] = array(
    'bundle' => 'colors',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'taxonomy',
        'settings' => array(),
        'type' => 'taxonomy_term_reference_link',
        'weight' => 19,
      ),
      'paragraphs_editor_preview' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'paragraphs_item',
    'field_name' => 'field_input_text_color',
    'label' => 'Input Text',
    'required' => 0,
    'settings' => array(
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'options',
      'settings' => array(),
      'type' => 'options_select',
      'weight' => 26,
    ),
  );

  // Exported field_instance: 'paragraphs_item-colors-field_label_color'.
  $field_instances['paragraphs_item-colors-field_label_color'] = array(
    'bundle' => 'colors',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'taxonomy',
        'settings' => array(),
        'type' => 'taxonomy_term_reference_link',
        'weight' => 18,
      ),
      'paragraphs_editor_preview' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'paragraphs_item',
    'field_name' => 'field_label_color',
    'label' => 'Label',
    'required' => 0,
    'settings' => array(
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'options',
      'settings' => array(),
      'type' => 'options_select',
      'weight' => 27,
    ),
  );

  // Exported field_instance: 'paragraphs_item-colors-field_text_shadow'.
  $field_instances['paragraphs_item-colors-field_text_shadow'] = array(
    'bundle' => 'colors',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'field_collection',
        'settings' => array(
          'add' => 'Add',
          'delete' => 'Delete',
          'description' => TRUE,
          'edit' => 'Edit',
          'view_mode' => 'full',
        ),
        'type' => 'field_collection_view',
        'weight' => 23,
      ),
      'paragraphs_editor_preview' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'paragraphs_item',
    'field_name' => 'field_text_shadow',
    'label' => 'Text Shadow',
    'required' => 0,
    'settings' => array(
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 0,
      'module' => 'field_collection',
      'settings' => array(),
      'type' => 'field_collection_embed',
      'weight' => 23,
    ),
  );

  // Exported field_instance:
  // 'paragraphs_item-landing_page_benefits-field_colors'.
  $field_instances['paragraphs_item-landing_page_benefits-field_colors'] = array(
    'bundle' => 'landing_page_benefits',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'hidden',
        'module' => 'paragraphs',
        'settings' => array(
          'view_mode' => 'full',
        ),
        'type' => 'paragraphs_view',
        'weight' => 1,
      ),
      'paragraphs_editor_preview' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 1,
      ),
    ),
    'entity_type' => 'paragraphs_item',
    'field_name' => 'field_colors',
    'label' => 'Colors',
    'required' => 0,
    'settings' => array(
      'add_mode' => 'button',
      'allowed_bundles' => array(
        'annotated_image' => -1,
        'block_embed' => -1,
        'body' => -1,
        'colors' => 'colors',
        'image_break' => -1,
        'landing_page_benefits' => -1,
        'landing_page_features' => -1,
        'landing_page_header_footer' => -1,
        'landing_page_hero' => -1,
        'linked_image' => -1,
        'modal' => -1,
        'paragraphs' => -1,
        'table' => -1,
        'table_cell' => -1,
        'table_row' => -1,
      ),
      'bundle_weights' => array(
        'annotated_image' => 2,
        'block_embed' => 3,
        'body' => 4,
        'colors' => 5,
        'image_break' => 6,
        'landing_page_benefits' => 7,
        'landing_page_features' => 8,
        'landing_page_header_footer' => 9,
        'landing_page_hero' => 10,
        'linked_image' => 11,
        'modal' => 12,
        'paragraphs' => 13,
        'table' => 14,
        'table_cell' => 15,
        'table_row' => 16,
      ),
      'default_edit_mode' => 'closed',
      'title' => 'Paragraph',
      'title_multiple' => 'Paragraphs',
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 0,
      'module' => 'paragraphs',
      'settings' => array(),
      'type' => 'paragraphs_embed',
      'weight' => 6,
    ),
  );

  // Exported field_instance:
  // 'paragraphs_item-landing_page_features-field_colors'.
  $field_instances['paragraphs_item-landing_page_features-field_colors'] = array(
    'bundle' => 'landing_page_features',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'paragraphs',
        'settings' => array(
          'view_mode' => 'full',
        ),
        'type' => 'paragraphs_view',
        'weight' => 4,
      ),
      'paragraphs_editor_preview' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'paragraphs_item',
    'field_name' => 'field_colors',
    'label' => 'Colors',
    'required' => 0,
    'settings' => array(
      'add_mode' => 'button',
      'allowed_bundles' => array(
        'annotated_image' => -1,
        'block_embed' => -1,
        'body' => -1,
        'colors' => 'colors',
        'image_break' => -1,
        'landing_page_areas_we_service' => -1,
        'landing_page_benefits' => -1,
        'landing_page_features' => -1,
        'landing_page_header_footer' => -1,
        'landing_page_hero' => -1,
        'landing_page_package' => -1,
        'landing_page_packages' => -1,
        'landing_page_special_offer' => -1,
        'landing_page_testimonial' => -1,
        'linked_image' => -1,
        'modal' => -1,
        'paragraphs' => -1,
        'table' => -1,
        'table_cell' => -1,
        'table_row' => -1,
      ),
      'bundle_weights' => array(
        'annotated_image' => 2,
        'block_embed' => 3,
        'body' => 4,
        'colors' => 5,
        'image_break' => 6,
        'landing_page_areas_we_service' => 7,
        'landing_page_benefits' => 8,
        'landing_page_features' => 9,
        'landing_page_header_footer' => 10,
        'landing_page_hero' => 11,
        'landing_page_package' => 12,
        'landing_page_packages' => 13,
        'landing_page_special_offer' => 14,
        'landing_page_testimonial' => 15,
        'linked_image' => 16,
        'modal' => 17,
        'paragraphs' => 18,
        'table' => 19,
        'table_cell' => 20,
        'table_row' => 21,
      ),
      'default_edit_mode' => 'closed',
      'title' => 'Paragraph',
      'title_multiple' => 'Paragraphs',
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 0,
      'module' => 'paragraphs',
      'settings' => array(),
      'type' => 'paragraphs_embed',
      'weight' => 6,
    ),
  );

  // Exported field_instance:
  // 'paragraphs_item-landing_page_header_footer-field_colors'.
  $field_instances['paragraphs_item-landing_page_header_footer-field_colors'] = array(
    'bundle' => 'landing_page_header_footer',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'paragraphs',
        'settings' => array(
          'view_mode' => 'full',
        ),
        'type' => 'paragraphs_view',
        'weight' => 4,
      ),
      'paragraphs_editor_preview' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'paragraphs_item',
    'field_name' => 'field_colors',
    'label' => 'Colors',
    'required' => 0,
    'settings' => array(
      'add_mode' => 'button',
      'allowed_bundles' => array(
        'annotated_image' => -1,
        'block_embed' => -1,
        'body' => -1,
        'colors' => 'colors',
        'image_break' => -1,
        'landing_page_header_footer' => -1,
        'linked_image' => -1,
        'paragraphs' => -1,
        'table' => -1,
        'table_cell' => -1,
        'table_row' => -1,
      ),
      'bundle_weights' => array(
        'annotated_image' => 2,
        'block_embed' => 3,
        'body' => 4,
        'colors' => 5,
        'image_break' => 6,
        'landing_page_header_footer' => 7,
        'linked_image' => 8,
        'paragraphs' => 9,
        'table' => 10,
        'table_cell' => 11,
        'table_row' => 12,
      ),
      'default_edit_mode' => 'preview',
      'title' => 'Paragraph',
      'title_multiple' => 'Paragraphs',
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 0,
      'module' => 'paragraphs',
      'settings' => array(),
      'type' => 'paragraphs_embed',
      'weight' => 6,
    ),
  );

  // Exported field_instance: 'paragraphs_item-landing_page_hero-field_colors'.
  $field_instances['paragraphs_item-landing_page_hero-field_colors'] = array(
    'bundle' => 'landing_page_hero',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'hidden',
        'module' => 'paragraphs',
        'settings' => array(
          'view_mode' => 'full',
        ),
        'type' => 'paragraphs_view',
        'weight' => 3,
      ),
      'paragraphs_editor_preview' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 2,
      ),
    ),
    'entity_type' => 'paragraphs_item',
    'field_name' => 'field_colors',
    'label' => 'Colors',
    'required' => 0,
    'settings' => array(
      'add_mode' => 'button',
      'allowed_bundles' => array(
        'annotated_image' => -1,
        'block_embed' => -1,
        'body' => -1,
        'colors' => 'colors',
        'image_break' => -1,
        'landing_page_features' => -1,
        'landing_page_header_footer' => -1,
        'landing_page_hero' => -1,
        'linked_image' => -1,
        'modal' => -1,
        'paragraphs' => -1,
        'table' => -1,
        'table_cell' => -1,
        'table_row' => -1,
      ),
      'bundle_weights' => array(
        'annotated_image' => 2,
        'block_embed' => 3,
        'body' => 4,
        'colors' => 5,
        'image_break' => 6,
        'landing_page_features' => 7,
        'landing_page_header_footer' => 8,
        'landing_page_hero' => 9,
        'linked_image' => 10,
        'modal' => 11,
        'paragraphs' => 12,
        'table' => 13,
        'table_cell' => 14,
        'table_row' => 15,
      ),
      'default_edit_mode' => 'preview',
      'title' => 'Paragraph',
      'title_multiple' => 'Paragraphs',
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 0,
      'module' => 'paragraphs',
      'settings' => array(),
      'type' => 'paragraphs_embed',
      'weight' => 7,
    ),
  );

  // Exported field_instance:
  // 'paragraphs_item-landing_page_package-field_colors'.
  $field_instances['paragraphs_item-landing_page_package-field_colors'] = array(
    'bundle' => 'landing_page_package',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'hidden',
        'module' => 'paragraphs',
        'settings' => array(
          'view_mode' => 'full',
        ),
        'type' => 'paragraphs_view',
        'weight' => 3,
      ),
      'paragraphs_editor_preview' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 2,
      ),
    ),
    'entity_type' => 'paragraphs_item',
    'field_name' => 'field_colors',
    'label' => 'Colors',
    'required' => 0,
    'settings' => array(
      'add_mode' => 'button',
      'allowed_bundles' => array(
        'annotated_image' => -1,
        'block_embed' => -1,
        'body' => -1,
        'colors' => 'colors',
        'image_break' => -1,
        'landing_page_areas_we_service' => -1,
        'landing_page_benefits' => -1,
        'landing_page_features' => -1,
        'landing_page_header_footer' => -1,
        'landing_page_hero' => -1,
        'landing_page_package' => -1,
        'landing_page_special_offer' => -1,
        'landing_page_testimonial' => -1,
        'linked_image' => -1,
        'modal' => -1,
        'paragraphs' => -1,
        'table' => -1,
        'table_cell' => -1,
        'table_row' => -1,
      ),
      'bundle_weights' => array(
        'annotated_image' => 2,
        'block_embed' => 3,
        'body' => 4,
        'colors' => 5,
        'image_break' => 6,
        'landing_page_areas_we_service' => 7,
        'landing_page_benefits' => 8,
        'landing_page_features' => 9,
        'landing_page_header_footer' => 10,
        'landing_page_hero' => 11,
        'landing_page_package' => 12,
        'landing_page_special_offer' => 13,
        'landing_page_testimonial' => 14,
        'linked_image' => 15,
        'modal' => 16,
        'paragraphs' => 17,
        'table' => 18,
        'table_cell' => 19,
        'table_row' => 20,
      ),
      'default_edit_mode' => 'closed',
      'title' => 'Paragraph',
      'title_multiple' => 'Paragraphs',
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 0,
      'module' => 'paragraphs',
      'settings' => array(),
      'type' => 'paragraphs_embed',
      'weight' => 4,
    ),
  );

  // Exported field_instance:
  // 'paragraphs_item-landing_page_packages-field_colors'.
  $field_instances['paragraphs_item-landing_page_packages-field_colors'] = array(
    'bundle' => 'landing_page_packages',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'hidden',
        'module' => 'paragraphs',
        'settings' => array(
          'view_mode' => 'full',
        ),
        'type' => 'paragraphs_view',
        'weight' => 1,
      ),
      'paragraphs_editor_preview' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 1,
      ),
    ),
    'entity_type' => 'paragraphs_item',
    'field_name' => 'field_colors',
    'label' => 'Colors',
    'required' => 0,
    'settings' => array(
      'add_mode' => 'button',
      'allowed_bundles' => array(
        'annotated_image' => -1,
        'block_embed' => -1,
        'body' => -1,
        'colors' => 'colors',
        'image_break' => -1,
        'landing_page_areas_we_service' => -1,
        'landing_page_benefits' => -1,
        'landing_page_features' => -1,
        'landing_page_header_footer' => -1,
        'landing_page_hero' => -1,
        'landing_page_package' => -1,
        'landing_page_packages' => -1,
        'landing_page_special_offer' => -1,
        'landing_page_testimonial' => -1,
        'linked_image' => -1,
        'modal' => -1,
        'paragraphs' => -1,
        'table' => -1,
        'table_cell' => -1,
        'table_row' => -1,
      ),
      'bundle_weights' => array(
        'annotated_image' => 2,
        'block_embed' => 3,
        'body' => 4,
        'colors' => 5,
        'image_break' => 6,
        'landing_page_areas_we_service' => 7,
        'landing_page_benefits' => 8,
        'landing_page_features' => 9,
        'landing_page_header_footer' => 10,
        'landing_page_hero' => 11,
        'landing_page_package' => 12,
        'landing_page_packages' => 13,
        'landing_page_special_offer' => 14,
        'landing_page_testimonial' => 15,
        'linked_image' => 16,
        'modal' => 17,
        'paragraphs' => 18,
        'table' => 19,
        'table_cell' => 20,
        'table_row' => 21,
      ),
      'default_edit_mode' => 'closed',
      'title' => 'Paragraph',
      'title_multiple' => 'Paragraphs',
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 0,
      'module' => 'paragraphs',
      'settings' => array(),
      'type' => 'paragraphs_embed',
      'weight' => 4,
    ),
  );

  // Exported field_instance:
  // 'paragraphs_item-landing_page_packages-field_lp_package_colors'.
  $field_instances['paragraphs_item-landing_page_packages-field_lp_package_colors'] = array(
    'bundle' => 'landing_page_packages',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'Colors applied to the individual package paragraph items.',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'paragraphs',
        'settings' => array(
          'view_mode' => 'full',
        ),
        'type' => 'paragraphs_view',
        'weight' => 4,
      ),
      'paragraphs_editor_preview' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'paragraphs_item',
    'field_name' => 'field_lp_package_colors',
    'label' => 'Package Colors',
    'required' => 0,
    'settings' => array(
      'add_mode' => 'button',
      'allowed_bundles' => array(
        'annotated_image' => -1,
        'block_embed' => -1,
        'body' => -1,
        'colors' => 'colors',
        'image_break' => -1,
        'landing_page_areas_we_service' => -1,
        'landing_page_benefits' => -1,
        'landing_page_features' => -1,
        'landing_page_header_footer' => -1,
        'landing_page_hero' => -1,
        'landing_page_package' => -1,
        'landing_page_packages' => -1,
        'landing_page_special_offer' => -1,
        'landing_page_testimonial' => -1,
        'linked_image' => -1,
        'modal' => -1,
        'paragraphs' => -1,
        'table' => -1,
        'table_cell' => -1,
        'table_row' => -1,
      ),
      'bundle_weights' => array(
        'annotated_image' => 2,
        'block_embed' => 3,
        'body' => 4,
        'colors' => 5,
        'image_break' => 6,
        'landing_page_areas_we_service' => 7,
        'landing_page_benefits' => 8,
        'landing_page_features' => 9,
        'landing_page_header_footer' => 10,
        'landing_page_hero' => 11,
        'landing_page_package' => 12,
        'landing_page_packages' => 13,
        'landing_page_special_offer' => 14,
        'landing_page_testimonial' => 15,
        'linked_image' => 16,
        'modal' => 17,
        'paragraphs' => 18,
        'table' => 19,
        'table_cell' => 20,
        'table_row' => 21,
      ),
      'default_edit_mode' => 'closed',
      'title' => 'Paragraph',
      'title_multiple' => 'Paragraphs',
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 0,
      'module' => 'paragraphs',
      'settings' => array(),
      'type' => 'paragraphs_embed',
      'weight' => 5,
    ),
  );

  // Exported field_instance:
  // 'paragraphs_item-landing_page_testimonial-field_colors'.
  $field_instances['paragraphs_item-landing_page_testimonial-field_colors'] = array(
    'bundle' => 'landing_page_testimonial',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'hidden',
        'module' => 'paragraphs',
        'settings' => array(
          'view_mode' => 'full',
        ),
        'type' => 'paragraphs_view',
        'weight' => 4,
      ),
      'paragraphs_editor_preview' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'paragraphs_item',
    'field_name' => 'field_colors',
    'label' => 'Colors',
    'required' => 0,
    'settings' => array(
      'add_mode' => 'button',
      'allowed_bundles' => array(
        'annotated_image' => -1,
        'block_embed' => -1,
        'body' => -1,
        'colors' => 'colors',
        'image_break' => -1,
        'landing_page_benefits' => -1,
        'landing_page_features' => -1,
        'landing_page_header_footer' => -1,
        'landing_page_hero' => -1,
        'landing_page_testimonial' => -1,
        'linked_image' => -1,
        'modal' => -1,
        'paragraphs' => -1,
        'table' => -1,
        'table_cell' => -1,
        'table_row' => -1,
      ),
      'bundle_weights' => array(
        'annotated_image' => 2,
        'block_embed' => 3,
        'body' => 4,
        'colors' => 5,
        'image_break' => 6,
        'landing_page_benefits' => 7,
        'landing_page_features' => 8,
        'landing_page_header_footer' => 9,
        'landing_page_hero' => 10,
        'landing_page_testimonial' => 11,
        'linked_image' => 12,
        'modal' => 13,
        'paragraphs' => 14,
        'table' => 15,
        'table_cell' => 16,
        'table_row' => 17,
      ),
      'default_edit_mode' => 'closed',
      'title' => 'Paragraph',
      'title_multiple' => 'Paragraphs',
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 0,
      'module' => 'paragraphs',
      'settings' => array(),
      'type' => 'paragraphs_embed',
      'weight' => 6,
    ),
  );

  // Exported field_instance: 'paragraphs_item-modal-field_colors'.
  $field_instances['paragraphs_item-modal-field_colors'] = array(
    'bundle' => 'modal',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'hidden',
        'module' => 'paragraphs',
        'settings' => array(
          'view_mode' => 'full',
        ),
        'type' => 'paragraphs_view',
        'weight' => 1,
      ),
      'paragraphs_editor_preview' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 1,
      ),
    ),
    'entity_type' => 'paragraphs_item',
    'field_name' => 'field_colors',
    'label' => 'Colors',
    'required' => 0,
    'settings' => array(
      'add_mode' => 'button',
      'allowed_bundles' => array(
        'annotated_image' => -1,
        'block_embed' => -1,
        'body' => -1,
        'colors' => 'colors',
        'image_break' => -1,
        'landing_page_features' => -1,
        'landing_page_header_footer' => -1,
        'linked_image' => -1,
        'modal' => -1,
        'paragraphs' => -1,
        'table' => -1,
        'table_cell' => -1,
        'table_row' => -1,
      ),
      'bundle_weights' => array(
        'annotated_image' => 2,
        'block_embed' => 3,
        'body' => 4,
        'colors' => 5,
        'image_break' => 6,
        'landing_page_features' => 7,
        'landing_page_header_footer' => 8,
        'linked_image' => 9,
        'modal' => 10,
        'paragraphs' => 11,
        'table' => 12,
        'table_cell' => 13,
        'table_row' => 14,
      ),
      'default_edit_mode' => 'preview',
      'title' => 'Paragraph',
      'title_multiple' => 'Paragraphs',
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 0,
      'module' => 'paragraphs',
      'settings' => array(),
      'type' => 'paragraphs_embed',
      'weight' => 6,
    ),
  );

  // Exported field_instance: 'paragraphs_item-paragraphs-field_colors'.
  $field_instances['paragraphs_item-paragraphs-field_colors'] = array(
    'bundle' => 'paragraphs',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'paragraphs',
        'settings' => array(
          'view_mode' => 'full',
        ),
        'type' => 'paragraphs_view',
        'weight' => 5,
      ),
      'paragraphs_editor_preview' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'paragraphs_item',
    'field_name' => 'field_colors',
    'label' => 'Colors',
    'required' => 0,
    'settings' => array(
      'add_mode' => 'button',
      'allowed_bundles' => array(
        'annotated_image' => -1,
        'block_embed' => -1,
        'body' => -1,
        'colors' => 'colors',
        'image_break' => -1,
        'landing_page_areas_we_service' => -1,
        'landing_page_benefits' => -1,
        'landing_page_features' => -1,
        'landing_page_header_footer' => -1,
        'landing_page_hero' => -1,
        'landing_page_package' => -1,
        'landing_page_packages' => -1,
        'landing_page_special_offer' => -1,
        'landing_page_testimonial' => -1,
        'linked_image' => -1,
        'modal' => -1,
        'paragraphs' => -1,
        'table' => -1,
        'table_cell' => -1,
        'table_row' => -1,
      ),
      'bundle_weights' => array(
        'annotated_image' => 2,
        'block_embed' => 3,
        'body' => 4,
        'colors' => 5,
        'image_break' => 6,
        'landing_page_areas_we_service' => 7,
        'landing_page_benefits' => 8,
        'landing_page_features' => 9,
        'landing_page_header_footer' => 10,
        'landing_page_hero' => 11,
        'landing_page_package' => 12,
        'landing_page_packages' => 13,
        'landing_page_special_offer' => 14,
        'landing_page_testimonial' => 15,
        'linked_image' => 16,
        'modal' => 17,
        'paragraphs' => 18,
        'table' => 19,
        'table_cell' => 20,
        'table_row' => 21,
      ),
      'default_edit_mode' => 'closed',
      'title' => 'Paragraph',
      'title_multiple' => 'Paragraphs',
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 0,
      'module' => 'paragraphs',
      'settings' => array(),
      'type' => 'paragraphs_embed',
      'weight' => 5,
    ),
  );

  // Exported field_instance: 'taxonomy_term-colors-field_color_text_value'.
  $field_instances['taxonomy_term-colors-field_color_text_value'] = array(
    'bundle' => 'colors',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'Can be rgb(), hsl(), rgba(), etc. Or a valid <a href="https://developer.mozilla.org/en-US/docs/Web/CSS/color_value#Color_keywords" target="_blank">named color</a> (e.g. "red", "blue", "transparent").
This overrides the hex code.',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 1,
      ),
    ),
    'entity_type' => 'taxonomy_term',
    'field_name' => 'field_color_text_value',
    'label' => 'Color Text Value',
    'required' => 0,
    'settings' => array(
      'text_processing' => 0,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'text',
      'settings' => array(
        'show_token_tree' => 0,
        'size' => 60,
      ),
      'type' => 'text_textfield',
      'weight' => 2,
    ),
  );

  // Exported field_instance: 'taxonomy_term-colors-field_hex'.
  $field_instances['taxonomy_term-colors-field_hex'] = array(
    'bundle' => 'colors',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'color_field',
        'settings' => array(),
        'type' => 'color_field_default_formatter',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'taxonomy_term',
    'field_name' => 'field_hex',
    'label' => 'Hex',
    'required' => 0,
    'settings' => array(
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 0,
      'module' => 'color_field',
      'settings' => array(),
      'type' => 'color_field_plain_text',
      'weight' => 1,
    ),
  );

  // Translatables
  // Included for use with string extractors like potx.
  t('0 = transparent, 100 = solid.');
  t('Background');
  t('Background Color');
  t('Background Image');
  t('Background Image Style');
  t('Background Overlay Color');
  t('Background Overlay Opacity');
  t('Blur Radius');
  t('Body Text');
  t('Border');
  t('Box Shadow');
  t('Button Colors');
  t('Button Hover Colors');
  t('CSS Property');
  t('CSS Selector');
  t('Can be rgb(), hsl(), rgba(), etc. Or a valid <a href="https://developer.mozilla.org/en-US/docs/Web/CSS/color_value#Color_keywords" target="_blank">named color</a> (e.g. "red", "blue", "transparent").
This overrides the hex code.');
  t('Color');
  t('Color Header');
  t('Color Text Value');
  t('Colors');
  t('Colors applied to the individual package paragraph items.');
  t('Custom Color');
  t('Go <a href="https://developer.mozilla.org/en-US/docs/Web/CSS/box-shadow#Values" target="_blank">here</a> for more info on the different box shadow fields');
  t('Header');
  t('Header Color');
  t('Hex');
  t('Input Background');
  t('Input Border');
  t('Input Text');
  t('Inset?');
  t('Label');
  t('Link');
  t('Link Hover');
  t('List Item Bullets');
  t('None');
  t('Offset X');
  t('Offset Y');
  t('Package Colors');
  t('Size');
  t('Spread Radius');
  t('Stars');
  t('Style');
  t('Text');
  t('Text Shadow');
  t('This is for the bullets or checks or what have you that come before list items.');
  t('This will change the color of any stars');
  t('Which headers will be this color');

  return $field_instances;
}
