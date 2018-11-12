<?php
/**
 * @file
 * sprowt_4_contexts.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function sprowt_4_contexts_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "context" && $api == "context") {
    return array("version" => "3");
  }
}
