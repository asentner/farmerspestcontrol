<?php
/**
 * @file
 * sprowt_package_comparison.context.inc
 */

/**
 * Implements hook_context_default_contexts().
 */
function sprowt_package_comparison_context_default_contexts() {
  $export = array();

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'package_comparison';
  $context->description = 'Package Comparison feature block placement';
  $context->tag = 'Page';
  $context->conditions = array(
    'node' => array(
      'values' => array(
        'package_comparison' => 'package_comparison',
      ),
      'options' => array(
        'node_form' => '1',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'views-package_comparison-hero' => array(
          'module' => 'views',
          'delta' => 'package_comparison-hero',
          'region' => 'preface_first',
          'weight' => '-10',
        ),
        'views-a7f3879ed631c4af4c738158eff61094' => array(
          'module' => 'views',
          'delta' => 'a7f3879ed631c4af4c738158eff61094',
          'region' => 'content',
          'weight' => '1',
        ),
        'views-package_comparison-cta' => array(
          'module' => 'views',
          'delta' => 'package_comparison-cta',
          'region' => 'content',
          'weight' => '2',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('Package Comparison feature block placement');
  t('Page');
  $export['package_comparison'] = $context;

  return $export;
}
