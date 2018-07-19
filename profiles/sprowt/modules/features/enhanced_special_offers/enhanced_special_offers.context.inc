<?php
/**
 * @file
 * enhanced_special_offers.context.inc
 */

/**
 * Implements hook_context_default_contexts().
 */
function enhanced_special_offers_context_default_contexts() {
  $export = array();

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'enhanced_special_offers';
  $context->description = 'Enhanced special offers block placement';
  $context->tag = 'Page';
  $context->conditions = array(
    'path' => array(
      'values' => array(
        'special-offers' => 'special-offers',
        'node/32' => 'node/32',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'views-special_offers-all_enhanced' => array(
          'module' => 'views',
          'delta' => 'special_offers-all_enhanced',
          'region' => 'content',
          'weight' => '-10',
        ),
      ),
    ),
    'theme_html' => array(
      'class' => 'enhanced',
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('Enhanced special offers block placement');
  t('Page');
  $export['enhanced_special_offers'] = $context;

  return $export;
}
