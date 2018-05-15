<?php
/**
 * @file
 * antipesto_legacy_feature.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function antipesto_legacy_feature_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "field_group" && $api == "field_group") {
    return array("version" => "1");
  }
}
