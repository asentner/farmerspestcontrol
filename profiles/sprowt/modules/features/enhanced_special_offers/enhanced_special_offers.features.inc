<?php
/**
 * @file
 * enhanced_special_offers.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function enhanced_special_offers_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "context" && $api == "context") {
    return array("version" => "3");
  }
}
