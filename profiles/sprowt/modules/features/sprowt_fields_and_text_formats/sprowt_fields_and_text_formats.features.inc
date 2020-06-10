<?php

/**
 * @file
 * sprowt_fields_and_text_formats.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function sprowt_fields_and_text_formats_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "flexslider" && $api == "flexslider_default_preset") {
    return array("version" => "1");
  }
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
  if ($module == "video_embed_field" && $api == "default_video_embed_styles") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_image_default_styles().
 */
function sprowt_fields_and_text_formats_image_default_styles() {
  $styles = array();

  // Exported image style: annotated_image.
  $styles['annotated_image'] = array(
    'label' => 'Annotated Image (764x613)',
    'effects' => array(
      2 => array(
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 764,
          'height' => 613,
        ),
        'weight' => 1,
      ),
    ),
  );

  return $styles;
}
