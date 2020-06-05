<?php

/**
 * @file
 * sprowt_6_contexts.context.inc
 */

/**
 * Implements hook_context_default_contexts().
 */
function sprowt_6_contexts_context_default_contexts() {
  $export = array();

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'blog_listing';
  $context->description = 'Blog list page settings';
  $context->tag = 'Page';
  $context->conditions = array(
    'path' => array(
      'values' => array(
        'our-blog' => 'our-blog',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'views-blog-list' => array(
          'module' => 'views',
          'delta' => 'blog-list',
          'region' => 'content',
          'weight' => '-10',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('Blog list page settings');
  t('Page');
  $export['blog_listing'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'city_page_add';
  $context->description = 'Theme specific block placement for City Page';
  $context->tag = 'Page';
  $context->conditions = array(
    'node' => array(
      'values' => array(
        'city_page' => 'city_page',
      ),
      'options' => array(
        'node_form' => '1',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
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
        'webform-client-block-' => array(
          'module' => 'webform',
          'delta' => 'client-block-',
          'region' => 'postscript_fourth',
          'weight' => '-10',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('Page');
  t('Theme specific block placement for City Page');
  $export['city_page_add'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'content';
  $context->description = 'Main page content placement';
  $context->tag = 'Sitewide';
  $context->conditions = array();
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'system-main' => array(
          'module' => 'system',
          'delta' => 'main',
          'region' => 'content',
          'weight' => '-10',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('Main page content placement');
  t('Sitewide');
  $export['content'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'flippy';
  $context->description = 'Flippy placement';
  $context->tag = 'Sitewide';
  $context->conditions = array();
  $context->reactions = array();
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('Flippy placement');
  t('Sitewide');
  $export['flippy'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'footer';
  $context->description = 'Footer settings';
  $context->tag = 'Sitewide';
  $context->conditions = array(
    'sitewide' => array(
      'values' => array(
        1 => 1,
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'views-affiliates-list' => array(
          'module' => 'views',
          'delta' => 'affiliates-list',
          'region' => 'postscript_fifth',
          'weight' => '-10',
        ),
        'bean-footer-logo' => array(
          'module' => 'bean',
          'delta' => 'footer-logo',
          'region' => 'footer_first',
          'weight' => '-10',
        ),
        'views-locations-list' => array(
          'module' => 'views',
          'delta' => 'locations-list',
          'region' => 'footer_first',
          'weight' => '-9',
        ),
        'menu_block-5' => array(
          'module' => 'menu_block',
          'delta' => '5',
          'region' => 'footer_second',
          'weight' => '-10',
        ),
        'sprowt_settings-sprowt_social_media' => array(
          'module' => 'sprowt_settings',
          'delta' => 'sprowt_social_media',
          'region' => 'footer_third',
          'weight' => '-10',
        ),
        'menu-menu-mobile-footer' => array(
          'module' => 'menu',
          'delta' => 'menu-mobile-footer',
          'region' => 'footer_third',
          'weight' => '-9',
        ),
        'bean-credit-cards' => array(
          'module' => 'bean',
          'delta' => 'credit-cards',
          'region' => 'footer_fourth',
          'weight' => '-10',
        ),
        'sprowt_settings-sprowt_copyright' => array(
          'module' => 'sprowt_settings',
          'delta' => 'sprowt_copyright',
          'region' => 'footer_fourth',
          'weight' => '-9',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('Footer settings');
  t('Sitewide');
  $export['footer'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'front';
  $context->description = 'Front page blocks';
  $context->tag = 'Page';
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
        'bean-hero-front' => array(
          'module' => 'bean',
          'delta' => 'hero-front',
          'region' => 'preface_first',
          'weight' => '-9',
        ),
        'bean-benefits-intro-block-front' => array(
          'module' => 'bean',
          'delta' => 'benefits-intro-block-front',
          'region' => 'preface_third',
          'weight' => '-10',
        ),
        'views-benefits-front' => array(
          'module' => 'views',
          'delta' => 'benefits-front',
          'region' => 'preface_third',
          'weight' => '-9',
        ),
        'views-services-all_mobile' => array(
          'module' => 'views',
          'delta' => 'services-all_mobile',
          'region' => 'preface_fourth',
          'weight' => '-10',
        ),
        'views-services-all' => array(
          'module' => 'views',
          'delta' => 'services-all',
          'region' => 'preface_fourth',
          'weight' => '-9',
        ),
        'system-main' => array(
          'module' => 'system',
          'delta' => 'main',
          'region' => 'content',
          'weight' => '-10',
        ),
        'bean-front-body-call-out' => array(
          'module' => 'bean',
          'delta' => 'front-body-call-out',
          'region' => 'postscript_first',
          'weight' => '-10',
        ),
        'views-fac871172037ab5ebd3707c9011e9b99' => array(
          'module' => 'views',
          'delta' => 'fac871172037ab5ebd3707c9011e9b99',
          'region' => 'postscript_first',
          'weight' => '-9',
        ),
        'views-470e1eb68c88acdd23c3dc2a5b032ab4' => array(
          'module' => 'views',
          'delta' => '470e1eb68c88acdd23c3dc2a5b032ab4',
          'region' => 'postscript_first',
          'weight' => '-8',
        ),
        'views-a0a41c55aab71590c5efcbb267f42ae1' => array(
          'module' => 'views',
          'delta' => 'a0a41c55aab71590c5efcbb267f42ae1',
          'region' => 'postscript_first',
          'weight' => '-7',
        ),
        'bean-reviews-call-out-front' => array(
          'module' => 'bean',
          'delta' => 'reviews-call-out-front',
          'region' => 'postscript_first',
          'weight' => '-6',
        ),
        'views-special_offers-front3' => array(
          'module' => 'views',
          'delta' => 'special_offers-front3',
          'region' => 'postscript_second',
          'weight' => '-10',
        ),
        'views-special_offers-front2' => array(
          'module' => 'views',
          'delta' => 'special_offers-front2',
          'region' => 'postscript_second',
          'weight' => '-9',
        ),
        'block-1' => array(
          'module' => 'block',
          'delta' => '1',
          'region' => 'postscript_third',
          'weight' => '-10',
        ),
        'bean-careers-block-front' => array(
          'module' => 'bean',
          'delta' => 'careers-block-front',
          'region' => 'postscript_third',
          'weight' => '-9',
        ),
        'webform-client-block-57' => array(
          'module' => 'webform',
          'delta' => 'client-block-57',
          'region' => 'postscript_fourth',
          'weight' => '-10',
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
  t('Front page blocks');
  t('Page');
  $export['front'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'header';
  $context->description = 'Header settings (not solutions page)';
  $context->tag = 'Sitewide';
  $context->conditions = array(
    'sitewide' => array(
      'values' => array(
        1 => 1,
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
  t('Header settings (not solutions page)');
  t('Sitewide');
  $export['header'] = $context;

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
        'views-slideshow-localtarget' => array(
          'module' => 'views',
          'delta' => 'slideshow-localtarget',
          'region' => 'preface_first',
          'weight' => '-9',
        ),
        'views-referenced_hero_block-block' => array(
          'module' => 'views',
          'delta' => 'referenced_hero_block-block',
          'region' => 'preface_first',
          'weight' => '-8',
        ),
        'bean-benefits-intro-block-ltp' => array(
          'module' => 'bean',
          'delta' => 'benefits-intro-block-ltp',
          'region' => 'preface_third',
          'weight' => '-9',
        ),
        'views-benefits-front' => array(
          'module' => 'views',
          'delta' => 'benefits-front',
          'region' => 'preface_third',
          'weight' => '-8',
        ),
        'views-localtarget-ltp_local' => array(
          'module' => 'views',
          'delta' => 'localtarget-ltp_local',
          'region' => 'preface_fourth',
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
        'webform-client-block-' => array(
          'module' => 'webform',
          'delta' => 'client-block-',
          'region' => 'postscript_fourth',
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

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'meet_team';
  $context->description = 'Meet the Team page';
  $context->tag = 'Page';
  $context->conditions = array(
    'path' => array(
      'values' => array(
        'meet-our-trusted-team' => 'meet-our-trusted-team',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'views-team-list' => array(
          'module' => 'views',
          'delta' => 'team-list',
          'region' => 'content',
          'weight' => '-10',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('Meet the Team page');
  t('Page');
  $export['meet_team'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'service';
  $context->description = 'Service node block placement';
  $context->tag = 'Page';
  $context->conditions = array();
  $context->reactions = array();
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('Page');
  t('Service node block placement');
  $export['service'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'service_listing';
  $context->description = 'Service listing page settings';
  $context->tag = 'Page';
  $context->conditions = array(
    'path' => array(
      'values' => array(
        'our-pest-control-services' => 'our-pest-control-services',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'views-services-our_services' => array(
          'module' => 'views',
          'delta' => 'services-our_services',
          'region' => 'content',
          'weight' => '-9',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('Page');
  t('Service listing page settings');
  $export['service_listing'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'services_sidebar';
  $context->description = 'Sidebar specific to services';
  $context->tag = 'Sidebar';
  $context->conditions = array(
    'node' => array(
      'values' => array(
        'service' => 'service',
      ),
      'options' => array(
        'node_form' => '1',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'menu_block-4' => array(
          'module' => 'menu_block',
          'delta' => '4',
          'region' => 'sidebar',
          'weight' => '-10',
        ),
        'views-096cf025523abc0c052989875f4f93fe' => array(
          'module' => 'views',
          'delta' => '096cf025523abc0c052989875f4f93fe',
          'region' => 'sidebar',
          'weight' => '-7',
        ),
        'webform-client-block-40' => array(
          'module' => 'webform',
          'delta' => 'client-block-40',
          'region' => 'sidebar',
          'weight' => '-6',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('Sidebar');
  t('Sidebar specific to services');
  $export['services_sidebar'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'sidebar_menu';
  $context->description = 'Submenu for sidebars';
  $context->tag = 'Sidebar';
  $context->conditions = array(
    'node' => array(
      'values' => array(
        'benefit' => 'benefit',
        'blog' => 'blog',
        'concern' => 'concern',
        'market' => 'market',
        'package' => 'package',
        'page' => 'page',
        'profile' => 'profile',
        'region' => 'region',
        'webform' => 'webform',
      ),
      'options' => array(
        'node_form' => '1',
      ),
    ),
    'path' => array(
      'values' => array(
        '~<front>' => '~<front>',
        '~learning-center' => '~learning-center',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'menu_block-3' => array(
          'module' => 'menu_block',
          'delta' => '3',
          'region' => 'sidebar',
          'weight' => '-10',
        ),
      ),
    ),
  );
  $context->condition_mode = 1;

  // Translatables
  // Included for use with string extractors like potx.
  t('Sidebar');
  t('Submenu for sidebars');
  $export['sidebar_menu'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'sitewide';
  $context->description = 'Sitewide settings - not front';
  $context->tag = 'Sitewide';
  $context->conditions = array(
    'path' => array(
      'values' => array(
        '~<front>' => '~<front>',
      ),
    ),
  );
  $context->reactions = array();
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('Sitewide');
  t('Sitewide settings - not front');
  $export['sitewide'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'special_offers';
  $context->description = 'Special Offers sidebar block';
  $context->tag = 'Sidebar';
  $context->conditions = array(
    'node' => array(
      'values' => array(
        'package' => 'package',
        'page' => 'page',
        'webform' => 'webform',
      ),
      'options' => array(
        'node_form' => '1',
      ),
    ),
    'path' => array(
      'values' => array(
        '~<front>' => '~<front>',
        '~learning-center' => '~learning-center',
        '~special-offers' => '~special-offers',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'views-special_offers-sidebar_sec' => array(
          'module' => 'views',
          'delta' => 'special_offers-sidebar_sec',
          'region' => 'sidebar',
          'weight' => '-7',
        ),
      ),
    ),
  );
  $context->condition_mode = 1;

  // Translatables
  // Included for use with string extractors like potx.
  t('Sidebar');
  t('Special Offers sidebar block');
  $export['special_offers'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'special_offers_list';
  $context->description = 'Special offers listing page';
  $context->tag = 'Page';
  $context->conditions = array(
    'path' => array(
      'values' => array(
        'node/34' => 'node/11',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'views-special_offers-list' => array(
          'module' => 'views',
          'delta' => 'special_offers-list',
          'region' => 'content',
          'weight' => '-10',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('Page');
  t('Special offers listing page');
  $export['special_offers_list'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'testimonials_sidebar';
  $context->description = 'Testimonials sidebar block';
  $context->tag = 'Sidebar';
  $context->conditions = array(
    'node' => array(
      'values' => array(
        'blog' => 'blog',
        'localtarget' => 'localtarget',
        'package' => 'package',
        'page' => 'page',
        'profile' => 'profile',
        'service' => 'service',
      ),
      'options' => array(
        'node_form' => '1',
      ),
    ),
    'path' => array(
      'values' => array(
        '~<front>' => '~<front>',
        '~learning-center' => '~learning-center',
        '~special-offers' => '~special-offers',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'views-testimonials-random' => array(
          'module' => 'views',
          'delta' => 'testimonials-random',
          'region' => 'sidebar',
          'weight' => '-9',
        ),
        'bean-sidebar-review-links' => array(
          'module' => 'bean',
          'delta' => 'sidebar-review-links',
          'region' => 'sidebar',
          'weight' => '-8',
        ),
      ),
    ),
  );
  $context->condition_mode = 1;

  // Translatables
  // Included for use with string extractors like potx.
  t('Sidebar');
  t('Testimonials sidebar block');
  $export['testimonials_sidebar'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'utility';
  $context->description = 'Utility menu';
  $context->tag = 'Sitewide';
  $context->conditions = array(
    'sitewide' => array(
      'values' => array(
        1 => 1,
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'bean-google-reviews-block' => array(
          'module' => 'bean',
          'delta' => 'google-reviews-block',
          'region' => 'header_first',
          'weight' => '-10',
        ),
        'bean-bbb-accredited' => array(
          'module' => 'bean',
          'delta' => 'bbb-accredited',
          'region' => 'header_first',
          'weight' => '-9',
        ),
        'menu-menu-mobile-utility' => array(
          'module' => 'menu',
          'delta' => 'menu-mobile-utility',
          'region' => 'header_first',
          'weight' => '-8',
        ),
        'menu_block-1' => array(
          'module' => 'menu_block',
          'delta' => '1',
          'region' => 'header_first',
          'weight' => '-7',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('Sitewide');
  t('Utility menu');
  $export['utility'] = $context;

  return $export;
}
