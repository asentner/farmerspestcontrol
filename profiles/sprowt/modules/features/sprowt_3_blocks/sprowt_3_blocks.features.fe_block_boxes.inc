<?php
/**
 * @file
 * sprowt_3_blocks.features.fe_block_boxes.inc
 */

/**
 * Implements hook_default_fe_block_boxes().
 */
function sprowt_3_blocks_default_fe_block_boxes() {
  $export = array();

  $fe_block_boxes = new stdClass();
  $fe_block_boxes->info = 'Services Intro';
  $fe_block_boxes->format = 'filtered_html';
  $fe_block_boxes->machine_name = 'services_intro';
  $fe_block_boxes->body = '<h2>Services Title Goes Here</h2>

<p>Lorem ipsum dolor sit amet, consectetur adipiscing elit. Integer vitae arcu nulla. Donec gravida tempus viverra. Sed venenatis ex vel erat malesuada.</p>
';

  $export['services_intro'] = $fe_block_boxes;

  return $export;
}
