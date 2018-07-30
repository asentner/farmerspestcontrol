<?php
/**
 * @file
 * sprowt_video_library.context.inc
 */

/**
 * Implements hook_context_default_contexts().
 */
function sprowt_video_library_context_default_contexts() {
  $export = array();

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'video_library';
  $context->description = 'All videos listing';
  $context->tag = 'Media Library';
  $context->conditions = array(
    'path' => array(
      'values' => array(
        'video-library' => 'video-library',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'views-video_library-all_videos' => array(
          'module' => 'views',
          'delta' => 'video_library-all_videos',
          'region' => 'content',
          'weight' => '-10',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('All videos listing');
  t('Media Library');
  $export['video_library'] = $context;

  return $export;
}
