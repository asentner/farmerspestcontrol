<?php
/**
 * @file
 * sprowt_image_galleries.context.inc
 */

/**
 * Implements hook_context_default_contexts().
 */
function sprowt_image_galleries_context_default_contexts() {
  $export = array();

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'image_gallery';
  $context->description = 'Image gallery full listing';
  $context->tag = 'Media Library';
  $context->conditions = array(
    'path' => array(
      'values' => array(
        'image-gallery' => 'image-gallery',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'views-galleries-gallery_list' => array(
          'module' => 'views',
          'delta' => 'galleries-gallery_list',
          'region' => 'content',
          'weight' => '-10',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('Image gallery full listing');
  t('Media Library');
  $export['image_gallery'] = $context;

  return $export;
}
