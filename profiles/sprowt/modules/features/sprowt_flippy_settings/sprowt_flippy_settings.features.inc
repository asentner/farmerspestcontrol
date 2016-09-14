<?php
/**
 * @file
 * sprowt_flippy_settings.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function sprowt_flippy_settings_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}
