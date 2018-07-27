<?php
/**
 * @file
 * sprowt_media_library.context.inc
 */

/**
 * Implements hook_context_default_contexts().
 */
function sprowt_media_library_context_default_contexts() {
  $export = array();

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'media_library';
  $context->description = 'Media library block placements';
  $context->tag = 'Media Library';
  $context->conditions = array(
    'path' => array(
      'values' => array(
        'media-library' => 'media-library',
        'resource-center' => 'resource-center',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'views-galleries-media_library' => array(
          'module' => 'views',
          'delta' => 'galleries-media_library',
          'region' => 'content',
          'weight' => '1',
        ),
        'views-video_library-media_library' => array(
          'module' => 'views',
          'delta' => 'video_library-media_library',
          'region' => 'content',
          'weight' => '2',
        ),
        'views-file_library-media_library' => array(
          'module' => 'views',
          'delta' => 'file_library-media_library',
          'region' => 'content',
          'weight' => '3',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('Media Library');
  t('Media library block placements');
  $export['media_library'] = $context;

  return $export;
}
