<?php
/**
 * @file
 * sprowt_breadcrumbs.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function sprowt_breadcrumbs_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_custom_breadcrumb_features_default_settings().
 */
function sprowt_breadcrumbs_custom_breadcrumb_features_default_settings() {
  $custom_breadcrumbs = array();

  // Exported custom breadcrumb: areas_we_service.
  $custom_breadcrumbs['areas_we_service'] = array(
    'name' => 'Areas We Service',
    'titles' => '<none>',
    'paths' => '<none>',
    'visibility_php' => 'if($node->uuid == \'2b054fc1-1268-405d-9d93-9829b7c4a20c\') {return TRUE;}',
    'node_type' => 'page',
    'language' => '',
    'machine_name' => 'areas_we_service',
  );

  // Exported custom breadcrumb: blog.
  $custom_breadcrumbs['blog'] = array(
    'name' => 'blog',
    'titles' => 'About
Our Blog',
    'paths' => '<about>
<our_blog>',
    'visibility_php' => '',
    'node_type' => 'blog',
    'language' => '',
    'machine_name' => 'blog',
  );

  // Exported custom breadcrumb: profile.
  $custom_breadcrumbs['profile'] = array(
    'name' => 'profile',
    'titles' => 'About
Meet the Team',
    'paths' => '<about>
<meet_our_trusted_team>',
    'visibility_php' => '',
    'node_type' => 'profile',
    'language' => '',
    'machine_name' => 'profile',
  );

  return $custom_breadcrumbs;
}
