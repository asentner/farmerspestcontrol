<?php
/**
 * @file
 * sprowt_contexts.context.inc
 */

/**
 * Implements hook_context_default_contexts().
 */
function sprowt_contexts_context_default_contexts() {
  $export = array();

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'services_sidebar';
  $context->description = 'Service page specific sidebar';
  $context->tag = 'Sidebar';
  $context->conditions = array(
    'node' => array(
      'values' => array(
        'service' => 'service',
      ),
      'options' => array(
        'node_form' => '1',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'views-special_offers-sidebar_service' => array(
          'module' => 'views',
          'delta' => 'special_offers-sidebar_service',
          'region' => 'sidebar',
          'weight' => '-10',
        ),
      ),
    ),
  );
  $context->condition_mode = 1;

  // Translatables
  // Included for use with string extractors like potx.
  t('Service page specific sidebar');
  t('Sidebar');
  $export['services_sidebar'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'special_offers';
  $context->description = 'Special offers sidebar block';
  $context->tag = 'Sidebar';
  $context->conditions = array(
    'context_all' => array(
      'values' => array(
        '~special_offers_page' => '~special_offers_page',
      ),
    ),
    'node' => array(
      'values' => array(
        'package' => 'package',
        'page' => 'page',
        'webform' => 'webform',
      ),
      'options' => array(
        'node_form' => '1',
      ),
    ),
    'path' => array(
      'values' => array(
        '~<front>' => '~<front>',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'views-special_offers-sidebar' => array(
          'module' => 'views',
          'delta' => 'special_offers-sidebar',
          'region' => 'sidebar',
          'weight' => '-10',
        ),
      ),
    ),
  );
  $context->condition_mode = 1;

  // Translatables
  // Included for use with string extractors like potx.
  t('Sidebar');
  t('Special offers sidebar block');
  $export['special_offers'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'special_offers_page';
  $context->description = 'True if on special offers page';
  $context->tag = 'Page';
  $context->conditions = array(
    'context_uuid' => array(
      'values' => array(
        'node:9a595fe4-7ecf-4198-82b5-4b3499eb1d30' => 'node:9a595fe4-7ecf-4198-82b5-4b3499eb1d30',
      ),
    ),
  );
  $context->reactions = array();
  $context->condition_mode = 1;

  // Translatables
  // Included for use with string extractors like potx.
  t('Page');
  t('True if on special offers page');
  $export['special_offers_page'] = $context;

  return $export;
}
