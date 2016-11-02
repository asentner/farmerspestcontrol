<?php
/**
 * @file
 * sprowt_content_authoring_features.strongarm.inc
 */

/**
 * Implements hook_strongarm().
 */
function sprowt_content_authoring_features_strongarm() {
  $export = array();

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'html_title_allowed_elements';
  $strongarm->value = array(
    'abbr' => 'abbr',
    'b' => 'b',
    'bdi' => 'bdi',
    'cite' => 'cite',
    'em' => 'em',
    'i' => 'i',
    'strong' => 'strong',
    'sub' => 'sub',
    'sup' => 'sup',
    'wbr' => 'wbr',
    'code' => 0,
  );
  $export['html_title_allowed_elements'] = $strongarm;

  return $export;
}
