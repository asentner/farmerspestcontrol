<?php
/**
 * @file
 * sprowt_menu_settings.features.menu_custom.inc
 */

/**
 * Implements hook_menu_default_menu_custom().
 */
function sprowt_menu_settings_menu_default_menu_custom() {
  $menus = array();

  // Exported menu: menu-ctm-utility-menu.
  $menus['menu-ctm-utility-menu'] = array(
    'menu_name' => 'menu-ctm-utility-menu',
    'title' => 'CTM Utility Menu',
    'description' => '',
  );
  // Exported menu: menu-mobile-callout.
  $menus['menu-mobile-callout'] = array(
    'menu_name' => 'menu-mobile-callout',
    'title' => 'Mobile callout',
    'description' => '',
  );
  // Exported menu: menu-mobile-footer.
  $menus['menu-mobile-footer'] = array(
    'menu_name' => 'menu-mobile-footer',
    'title' => 'Mobile Footer',
    'description' => '',
  );
  // Exported menu: menu-mobile-menu.
  $menus['menu-mobile-menu'] = array(
    'menu_name' => 'menu-mobile-menu',
    'title' => 'Mobile menu',
    'description' => 'The <em>Mobile</em> menu should be a simplified version of the <em>Main</em> menu. It should include top-level links only, and it will only be displayed for small screens.',
  );
  // Exported menu: menu-mobile-utility.
  $menus['menu-mobile-utility'] = array(
    'menu_name' => 'menu-mobile-utility',
    'title' => 'Mobile Utility',
    'description' => '',
  );
  // Exported menu: menu-utility-menu.
  $menus['menu-utility-menu'] = array(
    'menu_name' => 'menu-utility-menu',
    'title' => 'Utility Menu',
    'description' => '',
  );
  // Translatables
  // Included for use with string extractors like potx.
  t('CTM Utility Menu');
  t('Mobile Footer');
  t('Mobile Utility');
  t('Mobile callout');
  t('Mobile menu');
  t('The <em>Mobile</em> menu should be a simplified version of the <em>Main</em> menu. It should include top-level links only, and it will only be displayed for small screens.');
  t('Utility Menu');

  return $menus;
}
