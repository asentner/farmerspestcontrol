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
