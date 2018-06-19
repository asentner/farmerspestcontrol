<?php
/**
 * @file
 * sprowt_solution_finder.context.inc
 */

/**
 * Implements hook_context_default_contexts().
 */
function sprowt_solution_finder_context_default_contexts() {
  $export = array();

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'solutions_finder_front';
  $context->description = 'Solutions finder block placement';
  $context->tag = 'Solutions Finder';
  $context->conditions = array(
    'path' => array(
      'values' => array(
        '<front>' => '<front>',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'sprowt_solution_finder-solution_finder' => array(
          'module' => 'sprowt_solution_finder',
          'delta' => 'solution_finder',
          'region' => 'preface_second',
          'weight' => '-10',
        ),
      ),
    ),
    'theme_html' => array(
      'class' => 'front--solutions-finder',
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('Solutions Finder');
  t('Solutions finder block placement');
  $export['solutions_finder_front'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'solutions_finder_ltp';
  $context->description = 'Solutions finder block placement';
  $context->tag = 'Solutions Finder';
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
        'sprowt_solution_finder-solution_finder' => array(
          'module' => 'sprowt_solution_finder',
          'delta' => 'solution_finder',
          'region' => 'preface_second',
          'weight' => '-10',
        ),
      ),
    ),
    'theme_html' => array(
      'class' => 'ltp--solutions-finder',
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('Solutions Finder');
  t('Solutions finder block placement');
  $export['solutions_finder_ltp'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'solutions_header';
  $context->description = 'Header for solutions page';
  $context->tag = 'Solutions Finder';
  $context->conditions = array(
    'node' => array(
      'values' => array(
        'solution' => 'solution',
      ),
      'options' => array(
        'node_form' => '1',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'logo_block-logo' => array(
          'module' => 'logo_block',
          'delta' => 'logo',
          'region' => 'header_third',
          'weight' => '-10',
        ),
        'menu-menu-ctm-utility-menu' => array(
          'module' => 'menu',
          'delta' => 'menu-ctm-utility-menu',
          'region' => 'header_third',
          'weight' => '-9',
        ),
        'block-4' => array(
          'module' => 'block',
          'delta' => '4',
          'region' => 'header_third',
          'weight' => '-8',
        ),
        'menu_block-2' => array(
          'module' => 'menu_block',
          'delta' => '2',
          'region' => 'header_fourth',
          'weight' => '-10',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('Header for solutions page');
  t('Solutions Finder');
  $export['solutions_header'] = $context;

  return $export;
}
