<?php
/**
 * @file
 * sprowt_bean_types.bean.inc
 */

/**
 * Implements hook_bean_admin_ui_types().
 */
function sprowt_bean_types_bean_admin_ui_types() {
  $export = array();

  $bean_type = new stdClass();
  $bean_type->disabled = FALSE; /* Edit this to true to make a default bean_type disabled initially */
  $bean_type->api_version = 5;
  $bean_type->name = 'benefits_bean';
  $bean_type->label = 'Benefits bean';
  $bean_type->options = '';
  $bean_type->description = '';
  $export['benefits_bean'] = $bean_type;

  $bean_type = new stdClass();
  $bean_type->disabled = FALSE; /* Edit this to true to make a default bean_type disabled initially */
  $bean_type->api_version = 5;
  $bean_type->name = 'call_out_bean';
  $bean_type->label = 'Call Out Bean';
  $bean_type->options = '';
  $bean_type->description = '';
  $export['call_out_bean'] = $bean_type;

  $bean_type = new stdClass();
  $bean_type->disabled = FALSE; /* Edit this to true to make a default bean_type disabled initially */
  $bean_type->api_version = 5;
  $bean_type->name = 'fqa_embed';
  $bean_type->label = 'FQA Embed';
  $bean_type->options = '';
  $bean_type->description = 'Embed a set of Questions and Answers on a page.';
  $export['fqa_embed'] = $bean_type;

  $bean_type = new stdClass();
  $bean_type->disabled = FALSE; /* Edit this to true to make a default bean_type disabled initially */
  $bean_type->api_version = 5;
  $bean_type->name = 'generic_bean';
  $bean_type->label = 'Generic Bean';
  $bean_type->options = '';
  $bean_type->description = '';
  $export['generic_bean'] = $bean_type;

  $bean_type = new stdClass();
  $bean_type->disabled = FALSE; /* Edit this to true to make a default bean_type disabled initially */
  $bean_type->api_version = 5;
  $bean_type->name = 'h1_bean';
  $bean_type->label = 'H1 Bean';
  $bean_type->options = '';
  $bean_type->description = 'Title field is an H1 for this block';
  $export['h1_bean'] = $bean_type;

  $bean_type = new stdClass();
  $bean_type->disabled = FALSE; /* Edit this to true to make a default bean_type disabled initially */
  $bean_type->api_version = 5;
  $bean_type->name = 'image_only_bean';
  $bean_type->label = 'Image Only Bean';
  $bean_type->options = '';
  $bean_type->description = '';
  $export['image_only_bean'] = $bean_type;

  $bean_type = new stdClass();
  $bean_type->disabled = FALSE; /* Edit this to true to make a default bean_type disabled initially */
  $bean_type->api_version = 5;
  $bean_type->name = 'image_text_bean';
  $bean_type->label = 'Image and Text Bean';
  $bean_type->options = '';
  $bean_type->description = '';
  $export['image_text_bean'] = $bean_type;

  $bean_type = new stdClass();
  $bean_type->disabled = FALSE; /* Edit this to true to make a default bean_type disabled initially */
  $bean_type->api_version = 5;
  $bean_type->name = 'multi_image_bean';
  $bean_type->label = 'Multi-Image Bean';
  $bean_type->options = '';
  $bean_type->description = '';
  $export['multi_image_bean'] = $bean_type;

  return $export;
}
