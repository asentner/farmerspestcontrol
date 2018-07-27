<?php
/**
 * @file
 * sprowt_media_library.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function sprowt_media_library_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "context" && $api == "context") {
    return array("version" => "3");
  }
}
