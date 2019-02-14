<?php
/**
 * @file
 * sprowt_1_contexts.context.inc
 */

/**
 * Implements hook_context_default_contexts().
 */
function sprowt_1_contexts_context_default_contexts() {
  $export = array();

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'front_sprowt_1';
  $context->description = 'Hydrogen theme front block placement';
  $context->tag = 'Page';
  $context->conditions = array(
    'path' => array(
      'values' => array(
        '<front>' => '<front>',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'block-2' => array(
          'module' => 'block',
          'delta' => '2',
          'region' => 'postscript_first',
          'weight' => '1',
        ),
        'views-4af2dddc855c0a4c641c4e54be140c8d' => array(
          'module' => 'views',
          'delta' => '4af2dddc855c0a4c641c4e54be140c8d',
          'region' => 'postscript_first',
          'weight' => '2',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('Hydrogen theme front block placement');
  t('Page');
  $export['front_sprowt_1'] = $context;

  return $export;
}