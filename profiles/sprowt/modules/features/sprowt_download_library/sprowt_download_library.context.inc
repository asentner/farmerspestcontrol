<?php
/**
 * @file
 * sprowt_download_library.context.inc
 */

/**
 * Implements hook_context_default_contexts().
 */
function sprowt_download_library_context_default_contexts() {
  $export = array();

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'file_downloads';
  $context->description = 'Full list of downloadable documents';
  $context->tag = 'Media Library';
  $context->conditions = array(
    'path' => array(
      'values' => array(
        'documents-download' => 'documents-download',
        'document-library' => 'document-library',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'views-file_library-all_files' => array(
          'module' => 'views',
          'delta' => 'file_library-all_files',
          'region' => 'content',
          'weight' => '-10',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('Full list of downloadable documents');
  t('Media Library');
  $export['file_downloads'] = $context;

  return $export;
}
