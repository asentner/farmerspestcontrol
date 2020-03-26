<?php

/**
 * @file
 * sprowt_city_pages.context.inc
 */

/**
 * Implements hook_context_default_contexts().
 */
function sprowt_city_pages_context_default_contexts() {
  $export = array();

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'city_page';
  $context->description = 'Block placement for City Pages';
  $context->tag = 'Page';
  $context->conditions = array(
    'node' => array(
      'values' => array(
        'city_page' => 'city_page',
      ),
      'options' => array(
        'node_form' => '1',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'views-city_pages-city_hero' => array(
          'module' => 'views',
          'delta' => 'city_pages-city_hero',
          'region' => 'preface_first',
          'weight' => '-10',
        ),
        'views-city_pages-benefits' => array(
          'module' => 'views',
          'delta' => 'city_pages-benefits',
          'region' => 'preface_second',
          'weight' => '-10',
        ),
        'views-city_pages-city_anchors' => array(
          'module' => 'views',
          'delta' => 'city_pages-city_anchors',
          'region' => 'preface_second',
          'weight' => '-9',
        ),
        'sprowt_views-sprowt_views_testimonials' => array(
          'module' => 'sprowt_views',
          'delta' => 'sprowt_views_testimonials',
          'region' => 'preface_third',
          'weight' => '-10',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('Block placement for City Pages');
  t('Page');
  $export['city_page'] = $context;

  return $export;
}
