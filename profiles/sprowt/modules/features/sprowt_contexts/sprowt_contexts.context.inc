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
        'views-495a0e2c2c156e9bd9ea47b5a8089791' => array(
          'module' => 'views',
          'delta' => '495a0e2c2c156e9bd9ea47b5a8089791',
          'region' => 'sidebar',
          'weight' => '-9',
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
  $context->description = 'Special offers random sidebar block';
  $context->tag = 'Sidebar';
  $context->conditions = array(
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
        '~special-offers' => '~special-offers',
        '~media-library' => '~media-library',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'views-7326d8f601c5b501332596fab1886280' => array(
          'module' => 'views',
          'delta' => '7326d8f601c5b501332596fab1886280',
          'region' => 'sidebar',
          'weight' => '-9',
        ),
      ),
    ),
  );
  $context->condition_mode = 1;

  // Translatables
  // Included for use with string extractors like potx.
  t('Sidebar');
  t('Special offers random sidebar block');
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
