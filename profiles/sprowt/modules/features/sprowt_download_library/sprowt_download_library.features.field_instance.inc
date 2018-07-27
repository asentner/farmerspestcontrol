<?php
/**
 * @file
 * sprowt_download_library.features.field_instance.inc
 */

/**
 * Implements hook_field_default_field_instances().
 */
function sprowt_download_library_field_default_field_instances() {
  $field_instances = array();

  // Exported field_instance: 'node-file_download-field_file'.
  $field_instances['node-file_download-field_file'] = array(
    'bundle' => 'file_download',
    'deleted' => 0,
    'description' => 'Use the description field for the file name shown on the website. Recommend keeping it less than 35 characters.',
    'display' => array(
      'default' => array(
        'label' => 'hidden',
        'module' => 'file',
        'settings' => array(),
        'type' => 'file_default',
        'weight' => 1,
      ),
      'secondary_teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'teaser' => array(
        'label' => 'hidden',
        'module' => 'file',
        'settings' => array(),
        'type' => 'file_default',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_file',
    'label' => 'File',
    'required' => 0,
    'settings' => array(
      'description_field' => 1,
      'file_directory' => '',
      'file_extensions' => 'txt pdf doc docx xls xlsx png jpg jpeg',
      'max_filesize' => '',
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'file',
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
          'colorbox__affiliation_image' => 0,
          'colorbox__annotated_image' => 0,
          'colorbox__benefits' => 0,
          'colorbox__benefits__front_page_' => 0,
          'colorbox__flexslider_full' => 0,
          'colorbox__flexslider_thumbnail' => 0,
          'colorbox__focal_point_preview' => 0,
          'colorbox__focal_point_scale_and_crop_80x80' => 0,
          'colorbox__focal_point_scale_and_crop_100x100' => 0,
          'colorbox__focal_point_scale_and_crop_185x150' => 0,
          'colorbox__focal_point_scale_and_crop_250x250' => 0,
          'colorbox__focal_point_scale_and_crop_460_x_330' => 0,
          'colorbox__focal_point_scale_and_crop_470x400' => 0,
          'colorbox__focal_point_scale_and_crop_500x325' => 0,
          'colorbox__focal_point_scale_and_crop_600x475' => 0,
          'colorbox__focal_point_scale_and_crop_800x600' => 0,
          'colorbox__fresh_light_service' => 0,
          'colorbox__large' => 0,
          'colorbox__ltp_local_image' => 0,
          'colorbox__markets' => 0,
          'colorbox__medium' => 0,
          'colorbox__menu_icon' => 0,
          'colorbox__package_icon' => 0,
          'colorbox__primary__800x400_' => 0,
          'colorbox__profile' => 0,
          'colorbox__scale_60x60' => 0,
          'colorbox__scale_235' => 0,
          'colorbox__service' => 0,
          'colorbox__service_primary' => 0,
          'colorbox__slideshow_homepage' => 0,
          'colorbox__special_offers_slideshow' => 0,
          'colorbox__thumbnail' => 0,
          'colorbox__video_thumbnail' => 0,
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
          'image_focal_point_scale_and_crop_460_x_330' => 0,
          'image_focal_point_scale_and_crop_470x400' => 0,
          'image_focal_point_scale_and_crop_500x325' => 0,
          'image_focal_point_scale_and_crop_600x475' => 0,
          'image_focal_point_scale_and_crop_800x600' => 0,
          'image_fresh_light_service' => 0,
          'image_large' => 0,
          'image_ltp_local_image' => 0,
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
          'image_video_thumbnail' => 0,
          'link' => 0,
        ),
        'insert_width' => '',
        'progress_indicator' => 'throbber',
      ),
      'type' => 'file_generic',
      'weight' => 2,
    ),
  );

  // Translatables
  // Included for use with string extractors like potx.
  t('File');
  t('Use the description field for the file name shown on the website. Recommend keeping it less than 35 characters.');

  return $field_instances;
}
