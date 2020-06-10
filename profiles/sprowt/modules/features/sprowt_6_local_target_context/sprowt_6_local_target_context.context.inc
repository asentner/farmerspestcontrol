<?php

/**
 * @file
 * sprowt_6_local_target_context.context.inc
 */

/**
 * Implements hook_context_default_contexts().
 */
function sprowt_6_local_target_context_context_default_contexts() {
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
        'views-localtarget-hero' => array(
          'module' => 'views',
          'delta' => 'localtarget-hero',
          'region' => 'preface_first',
          'weight' => '-10',
        ),
        'views-localtarget-ltp_local' => array(
          'module' => 'views',
          'delta' => 'localtarget-ltp_local',
          'region' => 'preface_second',
          'weight' => '-10',
        ),
        'webform-client-block-78' => array(
          'module' => 'webform',
          'delta' => 'client-block-78',
          'region' => 'preface_third',
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
