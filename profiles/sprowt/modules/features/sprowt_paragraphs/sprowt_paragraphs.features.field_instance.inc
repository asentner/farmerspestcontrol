<?php
/**
 * @file
 * sprowt_paragraphs.features.field_instance.inc
 */

/**
 * Implements hook_field_default_field_instances().
 */
function sprowt_paragraphs_field_default_field_instances() {
  $field_instances = array();

  // Exported field_instance:
  // 'paragraphs_item-block_embed-field_block_reference'.
  $field_instances['paragraphs_item-block_embed-field_block_reference'] = array(
    'bundle' => 'block_embed',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'blockreference',
        'settings' => array(
          'show_empty_blocks' => FALSE,
        ),
        'type' => 'blockreference_default',
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
    'field_name' => 'field_block_reference',
    'label' => 'Block Reference',
    'required' => 0,
    'settings' => array(
      'blockreference_modules' => array(
        'addtoany' => 0,
        'bean' => 0,
        'block' => 0,
        'context_ui' => 0,
        'devel' => 0,
        'diff' => 0,
        'flippy' => 0,
        'logo_block' => 0,
        'menu' => 0,
        'menu_block' => 0,
        'multiblock' => 0,
        'node' => 0,
        'quicktabs' => 0,
        'search' => 0,
        'shortcut' => 0,
        'site_map' => 0,
        'sprowt_block_cta' => 0,
        'sprowt_settings' => 0,
        'sprowt_solution_finder' => 0,
        'sprowt_views' => 0,
        'system' => 0,
        'user' => 0,
        'views' => 0,
        'webform' => 0,
      ),
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

  // Exported field_instance: 'paragraphs_item-block_embed-field_custom_class'.
  $field_instances['paragraphs_item-block_embed-field_custom_class'] = array(
    'bundle' => 'block_embed',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
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
    'field_name' => 'field_custom_class',
    'label' => 'Custom Class',
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
      'weight' => 4,
    ),
  );

  // Exported field_instance: 'paragraphs_item-block_embed-field_label'.
  $field_instances['paragraphs_item-block_embed-field_label'] = array(
    'bundle' => 'block_embed',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
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
    'field_name' => 'field_label',
    'label' => 'Label',
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
      'weight' => 3,
    ),
  );

  // Exported field_instance: 'paragraphs_item-body-field_body_text'.
  $field_instances['paragraphs_item-body-field_body_text'] = array(
    'bundle' => 'body',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'hidden',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 2,
      ),
      'paragraphs_editor_preview' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 2,
      ),
    ),
    'entity_type' => 'paragraphs_item',
    'field_name' => 'field_body_text',
    'label' => 'Body',
    'required' => 0,
    'settings' => array(
      'text_processing' => 1,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'text',
      'settings' => array(
        'rows' => 5,
        'show_token_tree' => 0,
      ),
      'type' => 'text_textarea',
      'weight' => 3,
    ),
  );

  // Exported field_instance: 'paragraphs_item-body-field_custom_class'.
  $field_instances['paragraphs_item-body-field_custom_class'] = array(
    'bundle' => 'body',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'Custom class applied to paragraph',
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
        'weight' => 1,
      ),
    ),
    'entity_type' => 'paragraphs_item',
    'field_name' => 'field_custom_class',
    'label' => 'Custom Class',
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
      'weight' => 1,
    ),
  );

  // Exported field_instance: 'paragraphs_item-body-field_header'.
  $field_instances['paragraphs_item-body-field_header'] = array(
    'bundle' => 'body',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'hidden',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 0,
      ),
      'paragraphs_editor_preview' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 4,
      ),
    ),
    'entity_type' => 'paragraphs_item',
    'field_name' => 'field_header',
    'label' => 'Header',
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
      'weight' => 1,
    ),
  );

  // Exported field_instance: 'paragraphs_item-body-field_intro'.
  $field_instances['paragraphs_item-body-field_intro'] = array(
    'bundle' => 'body',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'hidden',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 1,
      ),
      'paragraphs_editor_preview' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 3,
      ),
    ),
    'entity_type' => 'paragraphs_item',
    'field_name' => 'field_intro',
    'label' => 'Intro',
    'required' => 0,
    'settings' => array(
      'text_processing' => 1,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'text',
      'settings' => array(
        'rows' => 5,
        'show_token_tree' => 0,
      ),
      'type' => 'text_textarea',
      'weight' => 2,
    ),
  );

  // Exported field_instance: 'paragraphs_item-body-field_label'.
  $field_instances['paragraphs_item-body-field_label'] = array(
    'bundle' => 'body',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'Paragraph label',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 3,
      ),
      'paragraphs_editor_preview' => array(
        'label' => 'inline',
        'module' => 'advanced_text_formatter',
        'settings' => array(
          'allowed_html' => array(
            0 => 'a',
            1 => 'b',
            2 => 'br',
            3 => 'dd',
            4 => 'dl',
            5 => 'dt',
            6 => 'em',
            7 => 'i',
            8 => 'li',
            9 => 'ol',
            10 => 'p',
            11 => 'strong',
            12 => 'u',
            13 => 'ul',
          ),
          'autop' => 0,
          'ellipsis' => 1,
          'filter' => 'input',
          'format' => 'plain_text',
          'token_replace' => 0,
          'trim_length' => 600,
          'use_summary' => 0,
          'word_boundary' => 1,
        ),
        'type' => 'advanced_text',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'paragraphs_item',
    'field_name' => 'field_label',
    'label' => 'Label',
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

  // Exported field_instance: 'paragraphs_item-image_break-field_custom_class'.
  $field_instances['paragraphs_item-image_break-field_custom_class'] = array(
    'bundle' => 'image_break',
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
        'weight' => 1,
      ),
    ),
    'entity_type' => 'paragraphs_item',
    'field_name' => 'field_custom_class',
    'label' => 'Custom Class',
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
      'weight' => 5,
    ),
  );

  // Exported field_instance: 'paragraphs_item-image_break-field_icons'.
  $field_instances['paragraphs_item-image_break-field_icons'] = array(
    'bundle' => 'image_break',
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'hidden',
        'module' => 'image',
        'settings' => array(
          'image_link' => '',
          'image_style' => '',
        ),
        'type' => 'image',
        'weight' => 0,
      ),
      'paragraphs_editor_preview' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 2,
      ),
    ),
    'entity_type' => 'paragraphs_item',
    'field_name' => 'field_icons',
    'label' => 'Images',
    'required' => 0,
    'settings' => array(
      'alt_field' => 1,
      'default_image' => 0,
      'file_directory' => '',
      'file_extensions' => 'png gif jpg jpeg',
      'max_filesize' => '',
      'max_resolution' => '',
      'min_resolution' => '',
      'title_field' => 1,
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
      'weight' => 0,
    ),
  );

  // Exported field_instance: 'paragraphs_item-image_break-field_label'.
  $field_instances['paragraphs_item-image_break-field_label'] = array(
    'bundle' => 'image_break',
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
        'label' => 'inline',
        'module' => 'advanced_text_formatter',
        'settings' => array(
          'allowed_html' => array(
            0 => 'a',
            1 => 'b',
            2 => 'br',
            3 => 'dd',
            4 => 'dl',
            5 => 'dt',
            6 => 'em',
            7 => 'i',
            8 => 'li',
            9 => 'ol',
            10 => 'p',
            11 => 'strong',
            12 => 'u',
            13 => 'ul',
          ),
          'autop' => 0,
          'ellipsis' => 1,
          'filter' => 'input',
          'format' => 'plain_text',
          'token_replace' => 0,
          'trim_length' => 600,
          'use_summary' => 0,
          'word_boundary' => 1,
        ),
        'type' => 'advanced_text',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'paragraphs_item',
    'field_name' => 'field_label',
    'label' => 'Label',
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
      'weight' => 4,
    ),
  );

  // Exported field_instance: 'paragraphs_item-linked_image-field_custom_class'.
  $field_instances['paragraphs_item-linked_image-field_custom_class'] = array(
    'bundle' => 'linked_image',
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
        'weight' => 2,
      ),
    ),
    'entity_type' => 'paragraphs_item',
    'field_name' => 'field_custom_class',
    'label' => 'Custom Class',
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
      'weight' => 7,
    ),
  );

  // Exported field_instance: 'paragraphs_item-linked_image-field_image'.
  $field_instances['paragraphs_item-linked_image-field_image'] = array(
    'bundle' => 'linked_image',
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'hidden',
        'module' => 'image_link_formatter',
        'settings' => array(
          'image_link' => 'field_link',
          'image_style' => '',
        ),
        'type' => 'image_link_formatter',
        'weight' => 0,
      ),
      'paragraphs_editor_preview' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 3,
      ),
    ),
    'entity_type' => 'paragraphs_item',
    'field_name' => 'field_image',
    'label' => 'Image',
    'required' => 0,
    'settings' => array(
      'alt_field' => 1,
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
      'module' => 'image',
      'settings' => array(
        'filefield_sources' => array(
          'filefield_sources' => array(
            'attach' => 0,
            'clipboard' => 0,
            'imce' => 0,
            'reference' => 0,
            'remote' => 0,
            'upload' => 'upload',
          ),
          'source_attach' => array(
            'absolute' => 0,
            'attach_mode' => 'move',
            'path' => 'file_attach',
          ),
          'source_imce' => array(
            'imce_mode' => 0,
          ),
          'source_reference' => array(
            'autocomplete' => 0,
            'search_all_fields' => 0,
          ),
        ),
        'insert' => 0,
        'insert_absolute' => 0,
        'insert_class' => '',
        'insert_default' => 'auto',
        'insert_styles' => array(
          'auto' => 'auto',
          'icon_link' => 0,
          'image' => 0,
          'image_affiliation_image' => 0,
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
      'type' => 'image_image',
      'weight' => 2,
    ),
  );

  // Exported field_instance: 'paragraphs_item-linked_image-field_label'.
  $field_instances['paragraphs_item-linked_image-field_label'] = array(
    'bundle' => 'linked_image',
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
        'label' => 'inline',
        'module' => 'advanced_text_formatter',
        'settings' => array(
          'allowed_html' => array(
            0 => 'a',
            1 => 'b',
            2 => 'br',
            3 => 'dd',
            4 => 'dl',
            5 => 'dt',
            6 => 'em',
            7 => 'i',
            8 => 'li',
            9 => 'ol',
            10 => 'p',
            11 => 'strong',
            12 => 'u',
            13 => 'ul',
          ),
          'autop' => 0,
          'ellipsis' => 1,
          'filter' => 'input',
          'format' => 'plain_text',
          'token_replace' => 0,
          'trim_length' => 600,
          'use_summary' => 0,
          'word_boundary' => 1,
        ),
        'type' => 'advanced_text',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'paragraphs_item',
    'field_name' => 'field_label',
    'label' => 'Label',
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
      'weight' => 6,
    ),
  );

  // Exported field_instance: 'paragraphs_item-linked_image-field_link'.
  $field_instances['paragraphs_item-linked_image-field_link'] = array(
    'bundle' => 'linked_image',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'hidden',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 4,
      ),
      'paragraphs_editor_preview' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 4,
      ),
    ),
    'entity_type' => 'paragraphs_item',
    'field_name' => 'field_link',
    'label' => 'Link',
    'required' => 0,
    'settings' => array(
      'absolute_url' => 1,
      'attributes' => array(
        'class' => '',
        'configurable_class' => 0,
        'configurable_title' => 0,
        'rel' => '',
        'target' => 'user',
        'title' => '',
      ),
      'display' => array(
        'url_cutoff' => 80,
      ),
      'enable_tokens' => 1,
      'rel_remove' => 'default',
      'title' => 'optional',
      'title_label_use_field_label' => 0,
      'title_maxlength' => 128,
      'title_value' => '',
      'url' => 0,
      'user_register_form' => FALSE,
      'validate_url' => 1,
    ),
    'widget' => array(
      'active' => 0,
      'module' => 'link',
      'settings' => array(),
      'type' => 'link_field',
      'weight' => 1,
    ),
  );

  // Exported field_instance: 'paragraphs_item-paragraphs-field_content'.
  $field_instances['paragraphs_item-paragraphs-field_content'] = array(
    'bundle' => 'paragraphs',
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
        'weight' => 0,
      ),
      'paragraphs_editor_preview' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 2,
      ),
    ),
    'entity_type' => 'paragraphs_item',
    'field_name' => 'field_content',
    'label' => 'Content',
    'required' => 0,
    'settings' => array(
      'add_mode' => 'select',
      'allowed_bundles' => array(
        'body' => -1,
        'linked_image' => -1,
        'paragraphs' => -1,
      ),
      'bundle_weights' => array(
        'body' => 2,
        'linked_image' => 3,
        'paragraphs' => 4,
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
      'weight' => 0,
    ),
  );

  // Exported field_instance: 'paragraphs_item-paragraphs-field_custom_class'.
  $field_instances['paragraphs_item-paragraphs-field_custom_class'] = array(
    'bundle' => 'paragraphs',
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
        'weight' => 1,
      ),
    ),
    'entity_type' => 'paragraphs_item',
    'field_name' => 'field_custom_class',
    'label' => 'Custom Class',
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
      'weight' => 3,
    ),
  );

  // Exported field_instance: 'paragraphs_item-paragraphs-field_label'.
  $field_instances['paragraphs_item-paragraphs-field_label'] = array(
    'bundle' => 'paragraphs',
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
        'label' => 'inline',
        'module' => 'advanced_text_formatter',
        'settings' => array(
          'allowed_html' => array(
            0 => 'a',
            1 => 'b',
            2 => 'br',
            3 => 'dd',
            4 => 'dl',
            5 => 'dt',
            6 => 'em',
            7 => 'i',
            8 => 'li',
            9 => 'ol',
            10 => 'p',
            11 => 'strong',
            12 => 'u',
            13 => 'ul',
          ),
          'autop' => 0,
          'ellipsis' => 1,
          'filter' => 'input',
          'format' => 'plain_text',
          'token_replace' => 0,
          'trim_length' => 600,
          'use_summary' => 0,
          'word_boundary' => 1,
        ),
        'type' => 'advanced_text',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'paragraphs_item',
    'field_name' => 'field_label',
    'label' => 'Label',
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

  // Translatables
  // Included for use with string extractors like potx.
  t('Block Reference');
  t('Body');
  t('Content');
  t('Custom Class');
  t('Custom class applied to paragraph');
  t('Header');
  t('Image');
  t('Images');
  t('Intro');
  t('Label');
  t('Link');
  t('Paragraph label');

  return $field_instances;
}
