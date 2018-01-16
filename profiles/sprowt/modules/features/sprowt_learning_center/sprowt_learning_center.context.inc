<?php
/**
 * @file
 * sprowt_learning_center.context.inc
 */

/**
 * Implements hook_context_default_contexts().
 */
function sprowt_learning_center_context_default_contexts() {
  $export = array();

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'learning_center';
  $context->description = 'Learning center context';
  $context->tag = 'Page';
  $context->conditions = array(
    'path' => array(
      'values' => array(
        'learning-center' => 'learning-center',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'views-learning_center-learning_list' => array(
          'module' => 'views',
          'delta' => 'learning_center-learning_list',
          'region' => 'content',
          'weight' => '-10',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('Learning center context');
  t('Page');
  $export['learning_center'] = $context;

  return $export;
}
