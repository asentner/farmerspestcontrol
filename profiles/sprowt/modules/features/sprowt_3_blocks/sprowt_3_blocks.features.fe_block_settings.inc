<?php
/**
 * @file
 * sprowt_3_blocks.features.fe_block_settings.inc
 */

/**
 * Implements hook_default_fe_block_settings().
 */
function sprowt_3_blocks_default_fe_block_settings() {
  $export = array();

  $export['version'] = '2.0';

  $export['block-services_intro'] = array(
    'cache' => -1,
    'css_class' => 'service-intro',
    'custom' => 0,
    'machine_name' => 'services_intro',
    'module' => 'block',
    'node_types' => array(),
    'pages' => '<front>',
    'roles' => array(),
    'themes' => array(
      'adminimal' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'adminimal',
        'weight' => 0,
      ),
      'sprowt_3' => array(
        'region' => 'postscript_first',
        'status' => 1,
        'theme' => 'sprowt_3',
        'weight' => -41,
      ),
    ),
    'title' => '<none>',
    'visibility' => 1,
  );

  $export['logo_block-logo'] = array(
    'cache' => -1,
    'css_class' => '',
    'custom' => 0,
    'delta' => 'logo',
    'module' => 'logo_block',
    'node_types' => array(),
    'pages' => '',
    'roles' => array(),
    'themes' => array(
      'adminimal' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'adminimal',
        'weight' => -38,
      ),
      'sprowt_3' => array(
        'region' => 'header_first',
        'status' => 1,
        'theme' => 'sprowt_3',
        'weight' => -38,
      ),
    ),
    'title' => '',
    'visibility' => 0,
  );

  $export['menu-menu-mobile-callout'] = array(
    'cache' => -1,
    'css_class' => '',
    'custom' => 0,
    'delta' => 'menu-mobile-callout',
    'module' => 'menu',
    'node_types' => array(),
    'pages' => '',
    'roles' => array(),
    'themes' => array(
      'adminimal' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'adminimal',
        'weight' => -14,
      ),
      'sprowt_3' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'sprowt_3',
        'weight' => -22,
      ),
    ),
    'title' => '',
    'visibility' => 0,
  );

  $export['menu-menu-mobile-footer'] = array(
    'cache' => -1,
    'css_class' => 'block--nav-utility-footer',
    'custom' => 0,
    'delta' => 'menu-mobile-footer',
    'module' => 'menu',
    'node_types' => array(),
    'pages' => '',
    'roles' => array(),
    'themes' => array(
      'adminimal' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'adminimal',
        'weight' => -39,
      ),
      'sprowt_3' => array(
        'region' => 'footer_third',
        'status' => 1,
        'theme' => 'sprowt_3',
        'weight' => -36,
      ),
    ),
    'title' => '<none>',
    'visibility' => 0,
  );

  $export['menu-menu-mobile-menu'] = array(
    'cache' => -1,
    'css_class' => '',
    'custom' => 0,
    'delta' => 'menu-mobile-menu',
    'module' => 'menu',
    'node_types' => array(),
    'pages' => '',
    'roles' => array(),
    'themes' => array(
      'adminimal' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'adminimal',
        'weight' => -13,
      ),
      'sprowt_3' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'sprowt_3',
        'weight' => -21,
      ),
    ),
    'title' => '',
    'visibility' => 0,
  );

  $export['menu-menu-mobile-utility'] = array(
    'cache' => -1,
    'css_class' => 'block--nav-mobile-utility',
    'custom' => 0,
    'delta' => 'menu-mobile-utility',
    'module' => 'menu',
    'node_types' => array(),
    'pages' => '',
    'roles' => array(),
    'themes' => array(
      'adminimal' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'adminimal',
        'weight' => -39,
      ),
      'sprowt_3' => array(
        'region' => 'header_first',
        'status' => 1,
        'theme' => 'sprowt_3',
        'weight' => -39,
      ),
    ),
    'title' => '<none>',
    'visibility' => 0,
  );

  $export['menu-menu-utility-menu'] = array(
    'cache' => -1,
    'css_class' => '',
    'custom' => 0,
    'delta' => 'menu-utility-menu',
    'module' => 'menu',
    'node_types' => array(),
    'pages' => '',
    'roles' => array(),
    'themes' => array(
      'adminimal' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'adminimal',
        'weight' => 12,
      ),
      'sprowt_3' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'sprowt_3',
        'weight' => 3,
      ),
    ),
    'title' => '',
    'visibility' => 0,
  );

  $export['menu_block-1'] = array(
    'cache' => -1,
    'css_class' => 'block--nav-utility',
    'custom' => 0,
    'delta' => 1,
    'module' => 'menu_block',
    'node_types' => array(),
    'pages' => '',
    'roles' => array(),
    'themes' => array(
      'adminimal' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'adminimal',
        'weight' => -37,
      ),
      'sprowt_3' => array(
        'region' => 'header_first',
        'status' => 1,
        'theme' => 'sprowt_3',
        'weight' => -37,
      ),
    ),
    'title' => '<none>',
    'visibility' => 0,
  );

  $export['menu_block-2'] = array(
    'cache' => -1,
    'css_class' => 'block--nav-main',
    'custom' => 0,
    'delta' => 2,
    'module' => 'menu_block',
    'node_types' => array(),
    'pages' => '',
    'roles' => array(),
    'themes' => array(
      'adminimal' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'adminimal',
        'weight' => -36,
      ),
      'sprowt_3' => array(
        'region' => 'header_second',
        'status' => 1,
        'theme' => 'sprowt_3',
        'weight' => -36,
      ),
    ),
    'title' => 'Menu',
    'visibility' => 0,
  );

  $export['menu_block-3'] = array(
    'cache' => -1,
    'css_class' => 'block--nav-submenu',
    'custom' => 0,
    'delta' => 3,
    'module' => 'menu_block',
    'node_types' => array(
      0 => 'benefit',
      1 => 'blog',
      2 => 'market',
      3 => 'package',
      4 => 'page',
      5 => 'profile',
      6 => 'region',
      7 => 'service',
      8 => 'webform',
    ),
    'pages' => '<front>
node/28',
    'roles' => array(),
    'themes' => array(
      'adminimal' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'adminimal',
        'weight' => -37,
      ),
      'sprowt_3' => array(
        'region' => 'sidebar',
        'status' => 1,
        'theme' => 'sprowt_3',
        'weight' => -37,
      ),
    ),
    'title' => '<none>',
    'visibility' => 0,
  );

  $export['multiblock-1'] = array(
    'cache' => -1,
    'css_class' => 'block--logo sprowt-block-imported',
    'custom' => 0,
    'delta' => 1,
    'module' => 'multiblock',
    'node_types' => array(),
    'pages' => '',
    'roles' => array(),
    'themes' => array(
      'adminimal' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'adminimal',
        'weight' => -39,
      ),
      'sprowt_3' => array(
        'region' => 'footer_third',
        'status' => 1,
        'theme' => 'sprowt_3',
        'weight' => -41,
      ),
    ),
    'title' => '',
    'visibility' => 0,
  );

  $export['node-recent'] = array(
    'cache' => 1,
    'css_class' => '',
    'custom' => 0,
    'delta' => 'recent',
    'module' => 'node',
    'node_types' => array(),
    'pages' => '',
    'roles' => array(),
    'themes' => array(
      'adminimal' => array(
        'region' => 'dashboard_inactive',
        'status' => 1,
        'theme' => 'adminimal',
        'weight' => -9,
      ),
      'sprowt_3' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'sprowt_3',
        'weight' => -17,
      ),
    ),
    'title' => '',
    'visibility' => 0,
  );

  $export['node-syndicate'] = array(
    'cache' => -1,
    'css_class' => '',
    'custom' => 0,
    'delta' => 'syndicate',
    'module' => 'node',
    'node_types' => array(),
    'pages' => '',
    'roles' => array(),
    'themes' => array(
      'adminimal' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'adminimal',
        'weight' => 6,
      ),
      'sprowt_3' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'sprowt_3',
        'weight' => -3,
      ),
    ),
    'title' => '',
    'visibility' => 0,
  );

  $export['search-form'] = array(
    'cache' => -1,
    'css_class' => '',
    'custom' => 0,
    'delta' => 'form',
    'module' => 'search',
    'node_types' => array(),
    'pages' => '',
    'roles' => array(),
    'themes' => array(
      'adminimal' => array(
        'region' => 'dashboard_inactive',
        'status' => 1,
        'theme' => 'adminimal',
        'weight' => -5,
      ),
      'sprowt_3' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'sprowt_3',
        'weight' => -11,
      ),
    ),
    'title' => '',
    'visibility' => 0,
  );

  $export['shortcut-shortcuts'] = array(
    'cache' => -1,
    'css_class' => '',
    'custom' => 0,
    'delta' => 'shortcuts',
    'module' => 'shortcut',
    'node_types' => array(),
    'pages' => '',
    'roles' => array(),
    'themes' => array(
      'adminimal' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'adminimal',
        'weight' => -4,
      ),
      'sprowt_3' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'sprowt_3',
        'weight' => -10,
      ),
    ),
    'title' => '',
    'visibility' => 0,
  );

  $export['site_map-syndicate'] = array(
    'cache' => 1,
    'css_class' => '',
    'custom' => 0,
    'delta' => 'syndicate',
    'module' => 'site_map',
    'node_types' => array(),
    'pages' => '',
    'roles' => array(),
    'themes' => array(
      'adminimal' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'adminimal',
        'weight' => 7,
      ),
      'sprowt_3' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'sprowt_3',
        'weight' => -2,
      ),
    ),
    'title' => '',
    'visibility' => 0,
  );

  $export['sprowt_block_cta-sprowt_block_cta_15'] = array(
    'cache' => 1,
    'css_class' => ' sprowt-block-imported block--sprowt-block-cta-sprowt-block-cta-12',
    'custom' => 0,
    'delta' => 'sprowt_block_cta_15',
    'module' => 'sprowt_block_cta',
    'node_types' => array(),
    'pages' => '',
    'roles' => array(),
    'themes' => array(
      'adminimal' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'adminimal',
        'weight' => 2,
      ),
      'sprowt_3' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'sprowt_3',
        'weight' => -5,
      ),
    ),
    'title' => '',
    'visibility' => 0,
  );

  $export['sprowt_block_cta-sprowt_block_cta_16'] = array(
    'cache' => 1,
    'css_class' => ' sprowt-block-imported block--sprowt-block-cta-sprowt-block-cta-13',
    'custom' => 0,
    'delta' => 'sprowt_block_cta_16',
    'module' => 'sprowt_block_cta',
    'node_types' => array(
      0 => 'article',
      1 => 'blog',
      2 => 'package',
      3 => 'page',
      4 => 'profile',
      5 => 'service',
    ),
    'pages' => '',
    'roles' => array(),
    'themes' => array(
      'adminimal' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'adminimal',
        'weight' => -37,
      ),
      'sprowt_3' => array(
        'region' => 'footer_second',
        'status' => 1,
        'theme' => 'sprowt_3',
        'weight' => -39,
      ),
    ),
    'title' => '',
    'visibility' => 0,
  );

  $export['sprowt_block_cta-sprowt_block_cta_17'] = array(
    'cache' => 1,
    'css_class' => ' sprowt-block-imported block--sprowt-block-cta-sprowt-block-cta-14',
    'custom' => 0,
    'delta' => 'sprowt_block_cta_17',
    'module' => 'sprowt_block_cta',
    'node_types' => array(),
    'pages' => '',
    'roles' => array(),
    'themes' => array(
      'adminimal' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'adminimal',
        'weight' => 0,
      ),
      'sprowt_3' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'sprowt_3',
        'weight' => -7,
      ),
    ),
    'title' => '',
    'visibility' => 0,
  );

  $export['sprowt_block_cta-sprowt_block_cta_18'] = array(
    'cache' => 1,
    'css_class' => ' sprowt-block-imported block--sprowt-block-cta-sprowt-block-cta-15',
    'custom' => 0,
    'delta' => 'sprowt_block_cta_18',
    'module' => 'sprowt_block_cta',
    'node_types' => array(),
    'pages' => '',
    'roles' => array(),
    'themes' => array(
      'adminimal' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'adminimal',
        'weight' => 1,
      ),
      'sprowt_3' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'sprowt_3',
        'weight' => -6,
      ),
    ),
    'title' => '',
    'visibility' => 0,
  );

  $export['sprowt_settings-sprowt_copyright'] = array(
    'cache' => 1,
    'css_class' => '',
    'custom' => 0,
    'delta' => 'sprowt_copyright',
    'module' => 'sprowt_settings',
    'node_types' => array(),
    'pages' => '',
    'roles' => array(),
    'themes' => array(
      'adminimal' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'adminimal',
        'weight' => -38,
      ),
      'sprowt_3' => array(
        'region' => 'footer_third',
        'status' => 1,
        'theme' => 'sprowt_3',
        'weight' => -37,
      ),
    ),
    'title' => '',
    'visibility' => 0,
  );

  $export['sprowt_settings-sprowt_social_media'] = array(
    'cache' => 1,
    'css_class' => '',
    'custom' => 0,
    'delta' => 'sprowt_social_media',
    'module' => 'sprowt_settings',
    'node_types' => array(),
    'pages' => '',
    'roles' => array(),
    'themes' => array(
      'adminimal' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'adminimal',
        'weight' => -37,
      ),
      'sprowt_3' => array(
        'region' => 'footer_third',
        'status' => 1,
        'theme' => 'sprowt_3',
        'weight' => -38,
      ),
    ),
    'title' => '',
    'visibility' => 0,
  );

  $export['sprowt_views-sprowt_views_lt_benefits'] = array(
    'cache' => 1,
    'css_class' => 'local-target-benefits',
    'custom' => 0,
    'delta' => 'sprowt_views_lt_benefits',
    'module' => 'sprowt_views',
    'node_types' => array(
      0 => 'localtarget',
    ),
    'pages' => '',
    'roles' => array(),
    'themes' => array(
      'adminimal' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'adminimal',
        'weight' => 3,
      ),
      'sprowt_3' => array(
        'region' => 'preface_second',
        'status' => 1,
        'theme' => 'sprowt_3',
        'weight' => 3,
      ),
    ),
    'title' => '',
    'visibility' => 0,
  );

  $export['sprowt_views-sprowt_views_testimonials'] = array(
    'cache' => 1,
    'css_class' => 'local-target-testimonial',
    'custom' => 0,
    'delta' => 'sprowt_views_testimonials',
    'module' => 'sprowt_views',
    'node_types' => array(
      0 => 'localtarget',
    ),
    'pages' => '',
    'roles' => array(),
    'themes' => array(
      'adminimal' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'adminimal',
        'weight' => 4,
      ),
      'sprowt_3' => array(
        'region' => 'preface_third',
        'status' => 1,
        'theme' => 'sprowt_3',
        'weight' => 4,
      ),
    ),
    'title' => '',
    'visibility' => 0,
  );

  $export['views-affiliates-list'] = array(
    'cache' => -1,
    'css_class' => '',
    'custom' => 0,
    'delta' => 'affiliates-list',
    'module' => 'views',
    'node_types' => array(),
    'pages' => '<front>',
    'roles' => array(),
    'themes' => array(
      'adminimal' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'adminimal',
        'weight' => -38,
      ),
      'sprowt_3' => array(
        'region' => 'footer_first',
        'status' => 1,
        'theme' => 'sprowt_3',
        'weight' => -36,
      ),
    ),
    'title' => 'Affiliations',
    'visibility' => 1,
  );

  $export['views-affiliates-simple'] = array(
    'cache' => -1,
    'css_class' => '',
    'custom' => 0,
    'delta' => 'affiliates-simple',
    'module' => 'views',
    'node_types' => array(),
    'pages' => '',
    'roles' => array(),
    'themes' => array(
      'adminimal' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'adminimal',
        'weight' => -3,
      ),
      'sprowt_3' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'sprowt_3',
        'weight' => -9,
      ),
    ),
    'title' => '',
    'visibility' => 0,
  );

  $export['views-benefits-front'] = array(
    'cache' => -1,
    'css_class' => 'benefits-hero',
    'custom' => 0,
    'delta' => 'benefits-front',
    'module' => 'views',
    'node_types' => array(),
    'pages' => '<front>',
    'roles' => array(),
    'themes' => array(
      'adminimal' => array(
        'region' => '',
        'status' => 1,
        'theme' => 'adminimal',
        'weight' => -38,
      ),
      'sprowt_3' => array(
        'region' => 'content',
        'status' => 1,
        'theme' => 'sprowt_3',
        'weight' => -38,
      ),
    ),
    'title' => '',
    'visibility' => 1,
  );

  $export['views-benefits-list'] = array(
    'cache' => -1,
    'css_class' => '',
    'custom' => 0,
    'delta' => 'benefits-list',
    'module' => 'views',
    'node_types' => array(),
    'pages' => '',
    'roles' => array(),
    'themes' => array(
      'adminimal' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'adminimal',
        'weight' => -19,
      ),
      'sprowt_3' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'sprowt_3',
        'weight' => -27,
      ),
    ),
    'title' => '',
    'visibility' => 0,
  );

  $export['views-blog-list'] = array(
    'cache' => -1,
    'css_class' => 'block--list',
    'custom' => 0,
    'delta' => 'blog-list',
    'module' => 'views',
    'node_types' => array(),
    'pages' => 'node/34',
    'roles' => array(),
    'themes' => array(
      'adminimal' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'adminimal',
        'weight' => -37,
      ),
      'sprowt_3' => array(
        'region' => 'content',
        'status' => 1,
        'theme' => 'sprowt_3',
        'weight' => -37,
      ),
    ),
    'title' => '',
    'visibility' => 1,
  );

  $export['views-blog-localtarget'] = array(
    'cache' => -1,
    'css_class' => '',
    'custom' => 0,
    'delta' => 'blog-localtarget',
    'module' => 'views',
    'node_types' => array(),
    'pages' => '',
    'roles' => array(),
    'themes' => array(
      'adminimal' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'adminimal',
        'weight' => -8,
      ),
      'sprowt_3' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'sprowt_3',
        'weight' => -16,
      ),
    ),
    'title' => '',
    'visibility' => 0,
  );

  $export['views-blog-related'] = array(
    'cache' => -1,
    'css_class' => '',
    'custom' => 0,
    'delta' => 'blog-related',
    'module' => 'views',
    'node_types' => array(),
    'pages' => '',
    'roles' => array(),
    'themes' => array(
      'adminimal' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'adminimal',
        'weight' => -7,
      ),
      'sprowt_3' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'sprowt_3',
        'weight' => -15,
      ),
    ),
    'title' => '',
    'visibility' => 0,
  );

  $export['views-call_out-block_1'] = array(
    'cache' => -1,
    'css_class' => '',
    'custom' => 0,
    'delta' => 'call_out-block_1',
    'module' => 'views',
    'node_types' => array(),
    'pages' => '',
    'roles' => array(),
    'themes' => array(
      'adminimal' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'adminimal',
        'weight' => -33,
      ),
      'sprowt_3' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'sprowt_3',
        'weight' => -36,
      ),
    ),
    'title' => '',
    'visibility' => 0,
  );

  $export['views-call_out-block_2'] = array(
    'cache' => -1,
    'css_class' => '',
    'custom' => 0,
    'delta' => 'call_out-block_2',
    'module' => 'views',
    'node_types' => array(),
    'pages' => '',
    'roles' => array(),
    'themes' => array(
      'adminimal' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'adminimal',
        'weight' => -36,
      ),
      'sprowt_3' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'sprowt_3',
        'weight' => -40,
      ),
    ),
    'title' => '',
    'visibility' => 0,
  );

  $export['views-call_out-localblog'] = array(
    'cache' => -1,
    'css_class' => '',
    'custom' => 0,
    'delta' => 'call_out-localblog',
    'module' => 'views',
    'node_types' => array(),
    'pages' => '',
    'roles' => array(),
    'themes' => array(
      'adminimal' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'adminimal',
        'weight' => -35,
      ),
      'sprowt_3' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'sprowt_3',
        'weight' => -39,
      ),
    ),
    'title' => '',
    'visibility' => 0,
  );

  $export['views-call_out-localtarget'] = array(
    'cache' => -1,
    'css_class' => '',
    'custom' => 0,
    'delta' => 'call_out-localtarget',
    'module' => 'views',
    'node_types' => array(),
    'pages' => '',
    'roles' => array(),
    'themes' => array(
      'adminimal' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'adminimal',
        'weight' => -34,
      ),
      'sprowt_3' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'sprowt_3',
        'weight' => -37,
      ),
    ),
    'title' => '',
    'visibility' => 0,
  );

  $export['views-call_out-services'] = array(
    'cache' => -1,
    'css_class' => '',
    'custom' => 0,
    'delta' => 'call_out-services',
    'module' => 'views',
    'node_types' => array(),
    'pages' => '',
    'roles' => array(),
    'themes' => array(
      'adminimal' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'adminimal',
        'weight' => -32,
      ),
      'sprowt_3' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'sprowt_3',
        'weight' => -35,
      ),
    ),
    'title' => '',
    'visibility' => 0,
  );

  $export['views-faqs-list'] = array(
    'cache' => -1,
    'css_class' => '',
    'custom' => 0,
    'delta' => 'faqs-list',
    'module' => 'views',
    'node_types' => array(),
    'pages' => '',
    'roles' => array(),
    'themes' => array(
      'adminimal' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'adminimal',
        'weight' => -22,
      ),
      'sprowt_3' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'sprowt_3',
        'weight' => -29,
      ),
    ),
    'title' => '',
    'visibility' => 0,
  );

  $export['views-gallery-grid'] = array(
    'cache' => -1,
    'css_class' => '',
    'custom' => 0,
    'delta' => 'gallery-grid',
    'module' => 'views',
    'node_types' => array(),
    'pages' => '',
    'roles' => array(),
    'themes' => array(
      'adminimal' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'adminimal',
        'weight' => -24,
      ),
      'sprowt_3' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'sprowt_3',
        'weight' => -31,
      ),
    ),
    'title' => '',
    'visibility' => 0,
  );

  $export['views-gallery-slideshow'] = array(
    'cache' => -1,
    'css_class' => '',
    'custom' => 0,
    'delta' => 'gallery-slideshow',
    'module' => 'views',
    'node_types' => array(),
    'pages' => '',
    'roles' => array(),
    'themes' => array(
      'adminimal' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'adminimal',
        'weight' => 13,
      ),
      'sprowt_3' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'sprowt_3',
        'weight' => 4,
      ),
    ),
    'title' => '',
    'visibility' => 0,
  );

  $export['views-localtarget-list'] = array(
    'cache' => -1,
    'css_class' => '',
    'custom' => 0,
    'delta' => 'localtarget-list',
    'module' => 'views',
    'node_types' => array(),
    'pages' => '',
    'roles' => array(),
    'themes' => array(
      'adminimal' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'adminimal',
        'weight' => 9,
      ),
      'sprowt_3' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'sprowt_3',
        'weight' => 0,
      ),
    ),
    'title' => '',
    'visibility' => 0,
  );

  $export['views-localtarget-office'] = array(
    'cache' => -1,
    'css_class' => '',
    'custom' => 0,
    'delta' => 'localtarget-office',
    'module' => 'views',
    'node_types' => array(),
    'pages' => '',
    'roles' => array(),
    'themes' => array(
      'adminimal' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'adminimal',
        'weight' => -11,
      ),
      'sprowt_3' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'sprowt_3',
        'weight' => -19,
      ),
    ),
    'title' => '',
    'visibility' => 0,
  );

  $export['views-localtarget-value_prop'] = array(
    'cache' => -1,
    'css_class' => '',
    'custom' => 0,
    'delta' => 'localtarget-value_prop',
    'module' => 'views',
    'node_types' => array(
      0 => 'localtarget',
    ),
    'pages' => '',
    'roles' => array(),
    'themes' => array(
      'adminimal' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'adminimal',
        'weight' => 14,
      ),
      'sprowt_3' => array(
        'region' => 'preface_first',
        'status' => 1,
        'theme' => 'sprowt_3',
        'weight' => 14,
      ),
    ),
    'title' => '',
    'visibility' => 0,
  );

  $export['views-locations-list'] = array(
    'cache' => -1,
    'css_class' => '',
    'custom' => 0,
    'delta' => 'locations-list',
    'module' => 'views',
    'node_types' => array(),
    'pages' => '',
    'roles' => array(),
    'themes' => array(
      'adminimal' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'adminimal',
        'weight' => -38,
      ),
      'sprowt_3' => array(
        'region' => 'footer_third',
        'status' => 1,
        'theme' => 'sprowt_3',
        'weight' => -40,
      ),
    ),
    'title' => '',
    'visibility' => 0,
  );

  $export['views-markets-list'] = array(
    'cache' => -1,
    'css_class' => '',
    'custom' => 0,
    'delta' => 'markets-list',
    'module' => 'views',
    'node_types' => array(),
    'pages' => '',
    'roles' => array(),
    'themes' => array(
      'adminimal' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'adminimal',
        'weight' => -18,
      ),
      'sprowt_3' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'sprowt_3',
        'weight' => -26,
      ),
    ),
    'title' => '',
    'visibility' => 0,
  );

  $export['views-packages-localtarget'] = array(
    'cache' => -1,
    'css_class' => '',
    'custom' => 0,
    'delta' => 'packages-localtarget',
    'module' => 'views',
    'node_types' => array(),
    'pages' => '',
    'roles' => array(),
    'themes' => array(
      'adminimal' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'adminimal',
        'weight' => -31,
      ),
      'sprowt_3' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'sprowt_3',
        'weight' => -14,
      ),
    ),
    'title' => '',
    'visibility' => 0,
  );

  $export['views-packages-services'] = array(
    'cache' => -1,
    'css_class' => 'block--list',
    'custom' => 0,
    'delta' => 'packages-services',
    'module' => 'views',
    'node_types' => array(
      0 => 'service',
    ),
    'pages' => '',
    'roles' => array(),
    'themes' => array(
      'adminimal' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'adminimal',
        'weight' => -32,
      ),
      'sprowt_3' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'sprowt_3',
        'weight' => -12,
      ),
    ),
    'title' => 'Our [node-service] Packages',
    'visibility' => 0,
  );

  $export['views-packages-services_sidebar'] = array(
    'cache' => -1,
    'css_class' => '',
    'custom' => 0,
    'delta' => 'packages-services_sidebar',
    'module' => 'views',
    'node_types' => array(),
    'pages' => '',
    'roles' => array(),
    'themes' => array(
      'adminimal' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'adminimal',
        'weight' => -6,
      ),
      'sprowt_3' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'sprowt_3',
        'weight' => -13,
      ),
    ),
    'title' => '',
    'visibility' => 0,
  );

  $export['views-services-all'] = array(
    'cache' => -1,
    'css_class' => 'block--list',
    'custom' => 0,
    'delta' => 'services-all',
    'module' => 'views',
    'node_types' => array(),
    'pages' => 'node/27',
    'roles' => array(),
    'themes' => array(
      'adminimal' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'adminimal',
        'weight' => -36,
      ),
      'sprowt_3' => array(
        'region' => 'content',
        'status' => 1,
        'theme' => 'sprowt_3',
        'weight' => -39,
      ),
    ),
    'title' => '',
    'visibility' => 1,
  );

  $export['views-services-homepage'] = array(
    'cache' => -1,
    'css_class' => '',
    'custom' => 0,
    'delta' => 'services-homepage',
    'module' => 'views',
    'node_types' => array(),
    'pages' => '<front>',
    'roles' => array(),
    'themes' => array(
      'adminimal' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'adminimal',
        'weight' => 0,
      ),
      'sprowt_3' => array(
        'region' => 'postscript_first',
        'status' => 1,
        'theme' => 'sprowt_3',
        'weight' => -40,
      ),
    ),
    'title' => '',
    'visibility' => 0,
  );

  $export['views-slideshow-front'] = array(
    'cache' => -1,
    'css_class' => '',
    'custom' => 0,
    'delta' => 'slideshow-front',
    'module' => 'views',
    'node_types' => array(),
    'pages' => '<front>',
    'roles' => array(),
    'themes' => array(
      'adminimal' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'adminimal',
        'weight' => -27,
      ),
      'sprowt_3' => array(
        'region' => 'preface_first',
        'status' => 1,
        'theme' => 'sprowt_3',
        'weight' => -27,
      ),
    ),
    'title' => '',
    'visibility' => 1,
  );

  $export['views-slideshow-localtarget'] = array(
    'cache' => -1,
    'css_class' => '',
    'custom' => 0,
    'delta' => 'slideshow-localtarget',
    'module' => 'views',
    'node_types' => array(
      0 => 'localtarget',
    ),
    'pages' => '',
    'roles' => array(),
    'themes' => array(
      'adminimal' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'adminimal',
        'weight' => -17,
      ),
      'sprowt_3' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'sprowt_3',
        'weight' => -25,
      ),
    ),
    'title' => '',
    'visibility' => 0,
  );

  $export['views-special_offers-front'] = array(
    'cache' => -1,
    'css_class' => '',
    'custom' => 0,
    'delta' => 'special_offers-front',
    'module' => 'views',
    'node_types' => array(),
    'pages' => '',
    'roles' => array(),
    'themes' => array(
      'adminimal' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'adminimal',
        'weight' => -37,
      ),
      'sprowt_3' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'sprowt_3',
        'weight' => -8,
      ),
    ),
    'title' => '<none>',
    'visibility' => 1,
  );

  $export['views-special_offers-front_slideshow'] = array(
    'cache' => -1,
    'css_class' => '',
    'custom' => 0,
    'delta' => 'special_offers-front_slideshow',
    'module' => 'views',
    'node_types' => array(),
    'pages' => '<front>',
    'roles' => array(),
    'themes' => array(
      'adminimal' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'adminimal',
        'weight' => -2,
      ),
      'sprowt_3' => array(
        'region' => 'postscript_second',
        'status' => 1,
        'theme' => 'sprowt_3',
        'weight' => -2,
      ),
    ),
    'title' => '<none>',
    'visibility' => 1,
  );

  $export['views-special_offers-list'] = array(
    'cache' => -1,
    'css_class' => 'block--list',
    'custom' => 0,
    'delta' => 'special_offers-list',
    'module' => 'views',
    'node_types' => array(),
    'pages' => 'node/29',
    'roles' => array(),
    'themes' => array(
      'adminimal' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'adminimal',
        'weight' => -34,
      ),
      'sprowt_3' => array(
        'region' => 'content',
        'status' => 1,
        'theme' => 'sprowt_3',
        'weight' => -34,
      ),
    ),
    'title' => '',
    'visibility' => 1,
  );

  $export['views-special_offers-ltp_slideshow'] = array(
    'cache' => -1,
    'css_class' => 'local-target-special-offer-slideshow',
    'custom' => 0,
    'delta' => 'special_offers-ltp_slideshow',
    'module' => 'views',
    'node_types' => array(
      0 => 'localtarget',
    ),
    'pages' => '',
    'roles' => array(),
    'themes' => array(
      'adminimal' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'adminimal',
        'weight' => 0,
      ),
      'sprowt_3' => array(
        'region' => 'postscript_second',
        'status' => 1,
        'theme' => 'sprowt_3',
        'weight' => 0,
      ),
    ),
    'title' => 'Money Saving Special Offers!',
    'visibility' => 0,
  );

  $export['views-special_offers-related'] = array(
    'cache' => -1,
    'css_class' => 'local-target-special-offer',
    'custom' => 0,
    'delta' => 'special_offers-related',
    'module' => 'views',
    'node_types' => array(
      0 => 'localtarget',
    ),
    'pages' => '',
    'roles' => array(),
    'themes' => array(
      'adminimal' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'adminimal',
        'weight' => 15,
      ),
      'sprowt_3' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'sprowt_3',
        'weight' => -38,
      ),
    ),
    'title' => 'Money Saving Special Offers!',
    'visibility' => 0,
  );

  $export['views-special_offers-sidebar'] = array(
    'cache' => -1,
    'css_class' => '',
    'custom' => 0,
    'delta' => 'special_offers-sidebar',
    'module' => 'views',
    'node_types' => array(
      0 => 'package',
      1 => 'page',
      2 => 'service',
    ),
    'pages' => '<front>
node/29',
    'roles' => array(),
    'themes' => array(
      'adminimal' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'adminimal',
        'weight' => -35,
      ),
      'sprowt_3' => array(
        'region' => 'sidebar',
        'status' => 1,
        'theme' => 'sprowt_3',
        'weight' => -35,
      ),
    ),
    'title' => '',
    'visibility' => 0,
  );

  $export['views-team-list'] = array(
    'cache' => -1,
    'css_class' => 'block--grid',
    'custom' => 0,
    'delta' => 'team-list',
    'module' => 'views',
    'node_types' => array(),
    'pages' => 'node/26',
    'roles' => array(),
    'themes' => array(
      'adminimal' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'adminimal',
        'weight' => -33,
      ),
      'sprowt_3' => array(
        'region' => 'content',
        'status' => 1,
        'theme' => 'sprowt_3',
        'weight' => -33,
      ),
    ),
    'title' => '',
    'visibility' => 1,
  );

  $export['views-testimonials-front'] = array(
    'cache' => -1,
    'css_class' => '',
    'custom' => 0,
    'delta' => 'testimonials-front',
    'module' => 'views',
    'node_types' => array(),
    'pages' => '<front>',
    'roles' => array(),
    'themes' => array(
      'adminimal' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'adminimal',
        'weight' => -35,
      ),
      'sprowt_3' => array(
        'region' => 'postscript_first',
        'status' => 1,
        'theme' => 'sprowt_3',
        'weight' => -39,
      ),
    ),
    'title' => '',
    'visibility' => 1,
  );

  $export['views-testimonials-list'] = array(
    'cache' => -1,
    'css_class' => '',
    'custom' => 0,
    'delta' => 'testimonials-list',
    'module' => 'views',
    'node_types' => array(),
    'pages' => '',
    'roles' => array(),
    'themes' => array(
      'adminimal' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'adminimal',
        'weight' => -20,
      ),
      'sprowt_3' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'sprowt_3',
        'weight' => -28,
      ),
    ),
    'title' => '',
    'visibility' => 0,
  );

  $export['views-testimonials-random'] = array(
    'cache' => -1,
    'css_class' => '',
    'custom' => 0,
    'delta' => 'testimonials-random',
    'module' => 'views',
    'node_types' => array(
      0 => 'blog',
      1 => 'package',
      2 => 'page',
      3 => 'profile',
      4 => 'service',
    ),
    'pages' => '<front>',
    'roles' => array(),
    'themes' => array(
      'adminimal' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'adminimal',
        'weight' => -36,
      ),
      'sprowt_3' => array(
        'region' => 'sidebar',
        'status' => 1,
        'theme' => 'sprowt_3',
        'weight' => -36,
      ),
    ),
    'title' => 'What Our Customers Are Saying',
    'visibility' => 0,
  );

  $export['webform-client-block-52'] = array(
    'cache' => -1,
    'css_class' => 'block--form-sidebar',
    'custom' => 0,
    'delta' => 'client-block-52',
    'module' => 'webform',
    'node_types' => array(
      0 => 'service',
    ),
    'pages' => '',
    'roles' => array(),
    'themes' => array(
      'adminimal' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'adminimal',
        'weight' => 16,
      ),
      'sprowt_3' => array(
        'region' => 'sidebar',
        'status' => 1,
        'theme' => 'sprowt_3',
        'weight' => 16,
      ),
    ),
    'title' => '',
    'visibility' => 0,
  );

  $export['webform-client-block-56'] = array(
    'cache' => -1,
    'css_class' => 'local-target-webform',
    'custom' => 0,
    'delta' => 'client-block-56',
    'module' => 'webform',
    'node_types' => array(
      0 => 'localtarget',
    ),
    'pages' => '',
    'roles' => array(),
    'themes' => array(
      'adminimal' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'adminimal',
        'weight' => -39,
      ),
      'sprowt_3' => array(
        'region' => 'postscript_third',
        'status' => 1,
        'theme' => 'sprowt_3',
        'weight' => -40,
      ),
    ),
    'title' => '<none>',
    'visibility' => 0,
  );

  return $export;
}
