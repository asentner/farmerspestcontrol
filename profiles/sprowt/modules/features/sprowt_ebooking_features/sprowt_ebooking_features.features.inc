<?php
/**
 * @file
 * sprowt_ebooking_features.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function sprowt_ebooking_features_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}
