<?php
/**
 * @file
 * sprowt_bean_types.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function sprowt_bean_types_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "bean_admin_ui" && $api == "bean") {
    return array("version" => "5");
  }
}
