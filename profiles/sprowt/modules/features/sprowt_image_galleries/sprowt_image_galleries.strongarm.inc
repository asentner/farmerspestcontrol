<?php
/**
 * @file
 * sprowt_image_galleries.strongarm.inc
 */

/**
 * Implements hook_strongarm().
 */
function sprowt_image_galleries_strongarm() {
  $export = array();

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'diff_enable_revisions_page_node_image_gallery';
  $strongarm->value = 1;
  $export['diff_enable_revisions_page_node_image_gallery'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'diff_show_preview_changes_node_image_gallery';
  $strongarm->value = 1;
  $export['diff_show_preview_changes_node_image_gallery'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'diff_view_mode_preview_node_image_gallery';
  $strongarm->value = 'full';
  $export['diff_view_mode_preview_node_image_gallery'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'field_bundle_settings_node__image_gallery';
  $strongarm->value = array(
    'view_modes' => array(
      'teaser' => array(
        'custom_settings' => TRUE,
      ),
      'alt_teaser' => array(
        'custom_settings' => TRUE,
      ),
      'secondary_teaser' => array(
        'custom_settings' => TRUE,
      ),
      'tertiary_teaser' => array(
        'custom_settings' => TRUE,
      ),
      'quaternary_teaser' => array(
        'custom_settings' => TRUE,
      ),
      'full' => array(
        'custom_settings' => FALSE,
      ),
      'rss' => array(
        'custom_settings' => FALSE,
      ),
      'search_index' => array(
        'custom_settings' => FALSE,
      ),
      'search_result' => array(
        'custom_settings' => FALSE,
      ),
      'diff_standard' => array(
        'custom_settings' => FALSE,
      ),
      'token' => array(
        'custom_settings' => FALSE,
      ),
    ),
    'extra_fields' => array(
      'form' => array(
        'metatags' => array(
          'weight' => '6',
        ),
        'title' => array(
          'weight' => '0',
        ),
        'path' => array(
          'weight' => '3',
        ),
        'rabbit_hole' => array(
          'weight' => '2',
        ),
        'xmlsitemap' => array(
          'weight' => '4',
        ),
      ),
      'display' => array(),
    ),
  );
  $export['field_bundle_settings_node__image_gallery'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'menu_options_image_gallery';
  $strongarm->value = array(
    0 => 'main-menu',
  );
  $export['menu_options_image_gallery'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'menu_parent_image_gallery';
  $strongarm->value = 'main-menu:0';
  $export['menu_parent_image_gallery'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_options_image_gallery';
  $strongarm->value = array();
  $export['node_options_image_gallery'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_preview_image_gallery';
  $strongarm->value = '1';
  $export['node_preview_image_gallery'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_submitted_image_gallery';
  $strongarm->value = 1;
  $export['node_submitted_image_gallery'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'xmlsitemap_settings_node_image_gallery';
  $strongarm->value = array(
    'status' => '0',
    'priority' => '0.5',
  );
  $export['xmlsitemap_settings_node_image_gallery'] = $strongarm;

  return $export;
}
