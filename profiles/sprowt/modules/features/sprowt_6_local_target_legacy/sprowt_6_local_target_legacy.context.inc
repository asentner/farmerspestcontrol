<?php

/**
 * @file
 * sprowt_6_local_target_legacy.context.inc
 */

/**
 * Implements hook_context_default_contexts().
 */
function sprowt_6_local_target_legacy_context_default_contexts() {
  $export = array();

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'local_target';
  $context->description = 'Block placement for LTP';
  $context->tag = 'Page';
  $context->conditions = array(
    'node' => array(
      'values' => array(
        'localtarget' => 'localtarget',
      ),
      'options' => array(
        'node_form' => '1',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'views-slideshow-localtarget' => array(
          'module' => 'views',
          'delta' => 'slideshow-localtarget',
          'region' => 'preface_first',
          'weight' => '-9',
        ),
        'views-referenced_hero_block-block' => array(
          'module' => 'views',
          'delta' => 'referenced_hero_block-block',
          'region' => 'preface_first',
          'weight' => '-8',
        ),
        'bean-benefits-intro-block-ltp' => array(
          'module' => 'bean',
          'delta' => 'benefits-intro-block-ltp',
          'region' => 'preface_third',
          'weight' => '-9',
        ),
        'views-benefits-front' => array(
          'module' => 'views',
          'delta' => 'benefits-front',
          'region' => 'preface_third',
          'weight' => '-8',
        ),
        'views-localtarget-ltp_local' => array(
          'module' => 'views',
          'delta' => 'localtarget-ltp_local',
          'region' => 'preface_fourth',
          'weight' => '-10',
        ),
        'views-ref_seas_blocks-seasonal_block' => array(
          'module' => 'views',
          'delta' => 'ref_seas_blocks-seasonal_block',
          'region' => 'preface_fourth',
          'weight' => '-9',
        ),
        'views-locations-ltp_location_map' => array(
          'module' => 'views',
          'delta' => 'locations-ltp_location_map',
          'region' => 'preface_fourth',
          'weight' => '-8',
        ),
        'views-localtarget-other_services' => array(
          'module' => 'views',
          'delta' => 'localtarget-other_services',
          'region' => 'sidebar',
          'weight' => '-10',
        ),
        'views-special_offers-front2' => array(
          'module' => 'views',
          'delta' => 'special_offers-front2',
          'region' => 'postscript_second',
          'weight' => '-10',
        ),
        'views-special_offers-front3' => array(
          'module' => 'views',
          'delta' => 'special_offers-front3',
          'region' => 'postscript_second',
          'weight' => '-9',
        ),
        'views-affiliates-list' => array(
          'module' => 'views',
          'delta' => 'affiliates-list',
          'region' => 'postscript_fifth',
          'weight' => '-10',
        ),
        'webform-client-block-' => array(
          'module' => 'webform',
          'delta' => 'client-block-',
          'region' => 'postscript_fourth',
          'weight' => '-10',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('Block placement for LTP');
  t('Page');
  $export['local_target'] = $context;

  return $export;
}
