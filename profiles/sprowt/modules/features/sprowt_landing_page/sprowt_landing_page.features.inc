<?php
/**
 * @file
 * sprowt_landing_page.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function sprowt_landing_page_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "field_group" && $api == "field_group") {
    return array("version" => "1");
  }
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_node_info().
 */
function sprowt_landing_page_node_info() {
  $items = array(
    'landing_page' => array(
      'name' => t('Landing page'),
      'base' => 'node_content',
      'description' => t('<em>Landing pages</em> are associated with a special offer, market, and service. They include a call tracking number.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}

/**
 * Implements hook_paragraphs_info().
 */
function sprowt_landing_page_paragraphs_info() {
  $items = array(
    'landing_page_areas_we_service' => array(
      'name' => 'Landing Page: Areas We Service',
      'bundle' => 'landing_page_areas_we_service',
      'locked' => '1',
    ),
    'landing_page_benefits' => array(
      'name' => 'Landing Page: Benefits',
      'bundle' => 'landing_page_benefits',
      'locked' => '1',
    ),
    'landing_page_features' => array(
      'name' => 'Landing Page: Features',
      'bundle' => 'landing_page_features',
      'locked' => '1',
    ),
    'landing_page_header_footer' => array(
      'name' => 'Landing Page: Header/Footer',
      'bundle' => 'landing_page_header_footer',
      'locked' => '1',
    ),
    'landing_page_hero' => array(
      'name' => 'Landing Page: Hero',
      'bundle' => 'landing_page_hero',
      'locked' => '1',
    ),
    'landing_page_package' => array(
      'name' => 'Landing Page: Package',
      'bundle' => 'landing_page_package',
      'locked' => '1',
    ),
    'landing_page_packages' => array(
      'name' => 'Landing Page: Packages',
      'bundle' => 'landing_page_packages',
      'locked' => '1',
    ),
    'landing_page_special_offer' => array(
      'name' => 'Landing Page: Special Offer',
      'bundle' => 'landing_page_special_offer',
      'locked' => '1',
    ),
    'landing_page_testimonial' => array(
      'name' => 'Landing Page: Testimonial',
      'bundle' => 'landing_page_testimonial',
      'locked' => '1',
    ),
  );
  return $items;
}

/**
 * Implements hook_themekey_features_rule_chain().
 */
function sprowt_landing_page_themekey_features_rule_chain() {
if (!defined('THEMEKEY_PAGECACHE_UNSUPPORTED')) {
    define('THEMEKEY_PAGECACHE_UNSUPPORTED', 0);
    define('THEMEKEY_PAGECACHE_SUPPORTED', 1);
    define('THEMEKEY_PAGECACHE_TIMEBASED', 2);
  }
$rules = array(
  0 => array(
    'rule' => array(
      'property' => 'node:type',
      'operator' => '=',
      'value' => 'landing_page',
      'theme' => 'landing_page',
      'enabled' => 1,
      'wildcards' => 'a:0:{}',
      'module' => 'sprowt_landing_page',
    ),
    'string' => '"node:type = landing_page >>> landing_page"',
    'childs' => array(),
  ),
);

return $rules;
}

/**
 * Implements hook_weight_features_default_settings().
 */
function sprowt_landing_page_weight_features_default_settings() {
  $settings = array();

  $settings['landing_page'] = array(
    'enabled' => 0,
    'range' => 20,
    'menu_weight' => 0,
    'default' => 0,
    'sync_translations' => 0,
  );

  return $settings;
}
