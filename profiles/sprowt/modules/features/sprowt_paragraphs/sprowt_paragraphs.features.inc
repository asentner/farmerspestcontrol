<?php
/**
 * @file
 * sprowt_paragraphs.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function sprowt_paragraphs_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "field_group" && $api == "field_group") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_paragraphs_info().
 */
function sprowt_paragraphs_paragraphs_info() {
  $items = array(
    'block_embed' => array(
      'name' => 'Block Embed',
      'bundle' => 'block_embed',
      'locked' => '1',
    ),
    'body' => array(
      'name' => 'Body',
      'bundle' => 'body',
      'locked' => '1',
    ),
    'image_break' => array(
      'name' => 'Image Break',
      'bundle' => 'image_break',
      'locked' => '1',
    ),
    'linked_image' => array(
      'name' => 'Linked Image',
      'bundle' => 'linked_image',
      'locked' => '1',
    ),
    'paragraphs' => array(
      'name' => 'Paragraphs',
      'bundle' => 'paragraphs',
      'locked' => '1',
    ),
  );
  return $items;
}
