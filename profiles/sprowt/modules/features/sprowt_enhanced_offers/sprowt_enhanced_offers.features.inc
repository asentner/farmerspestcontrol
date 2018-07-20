<?php
/**
 * @file
 * sprowt_enhanced_offers.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function sprowt_enhanced_offers_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "context" && $api == "context") {
    return array("version" => "3");
  }
}

/**
 * Implements hook_views_api().
 */
function sprowt_enhanced_offers_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}
