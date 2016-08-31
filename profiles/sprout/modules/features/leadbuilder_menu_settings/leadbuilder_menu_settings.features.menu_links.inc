<?php
/**
 * @file
 * leadbuilder_menu_settings.features.menu_links.inc
 */

/**
 * Implements hook_menu_default_menu_links().
 */
function leadbuilder_menu_settings_menu_default_menu_links() {
  $menu_links = array();

  // Exported menu link: main-menu_about:node/4
  $menu_links['main-menu_about:node/4'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'node/4',
    'router_path' => 'node/%',
    'link_title' => 'About',
    'options' => array(
      'identifier' => 'main-menu_about:node/4',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 1,
    'expanded' => 0,
    'weight' => -49,
    'customized' => 1,
  );
  // Exported menu link: main-menu_affilations:node/36
  $menu_links['main-menu_affilations:node/36'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'node/36',
    'router_path' => 'node/%',
    'link_title' => 'Affilations',
    'options' => array(
      'identifier' => 'main-menu_affilations:node/36',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -47,
    'customized' => 1,
    'parent_identifier' => 'main-menu_about:node/4',
  );
  // Exported menu link: main-menu_benefits:node/40
  $menu_links['main-menu_benefits:node/40'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'node/40',
    'router_path' => 'node/%',
    'link_title' => 'Benefits',
    'options' => array(
      'identifier' => 'main-menu_benefits:node/40',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -48,
    'customized' => 1,
    'parent_identifier' => 'main-menu_about:node/4',
  );
  // Exported menu link: main-menu_careers:node/8
  $menu_links['main-menu_careers:node/8'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'node/8',
    'router_path' => 'node/%',
    'link_title' => 'Careers',
    'options' => array(
      'identifier' => 'main-menu_careers:node/8',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -47,
    'customized' => 1,
    'parent_identifier' => 'main-menu_contact:node/5',
  );
  // Exported menu link: main-menu_contact:node/5
  $menu_links['main-menu_contact:node/5'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'node/5',
    'router_path' => 'node/%',
    'link_title' => 'Contact',
    'options' => array(
      'identifier' => 'main-menu_contact:node/5',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 1,
    'expanded' => 0,
    'weight' => -44,
    'customized' => 1,
  );
  // Exported menu link: main-menu_coupons:node/25
  $menu_links['main-menu_coupons:node/25'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'node/25',
    'router_path' => 'node/%',
    'link_title' => 'Coupons',
    'options' => array(
      'identifier' => 'main-menu_coupons:node/25',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -48,
    'customized' => 1,
    'parent_identifier' => 'main-menu_contact:node/5',
  );
  // Exported menu link: main-menu_current-customers:node/9
  $menu_links['main-menu_current-customers:node/9'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'node/9',
    'router_path' => 'node/%',
    'link_title' => 'Current Customers',
    'options' => array(
      'identifier' => 'main-menu_current-customers:node/9',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 1,
    'expanded' => 0,
    'weight' => -49,
    'customized' => 1,
    'parent_identifier' => 'main-menu_contact:node/5',
  );
  // Exported menu link: main-menu_gallery:node/34
  $menu_links['main-menu_gallery:node/34'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'node/34',
    'router_path' => 'node/%',
    'link_title' => 'Gallery',
    'options' => array(
      'identifier' => 'main-menu_gallery:node/34',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -46,
    'customized' => 1,
    'parent_identifier' => 'main-menu_about:node/4',
  );
  // Exported menu link: main-menu_get-a-free-estimate:node/6
  $menu_links['main-menu_get-a-free-estimate:node/6'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'node/6',
    'router_path' => 'node/%',
    'link_title' => 'Get a free estimate',
    'options' => array(
      'identifier' => 'main-menu_get-a-free-estimate:node/6',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -50,
    'customized' => 1,
    'parent_identifier' => 'main-menu_contact:node/5',
  );
  // Exported menu link: main-menu_home:<front>
  $menu_links['main-menu_home:<front>'] = array(
    'menu_name' => 'main-menu',
    'link_path' => '<front>',
    'router_path' => '',
    'link_title' => 'Home',
    'options' => array(
      'identifier' => 'main-menu_home:<front>',
    ),
    'module' => 'menu',
    'hidden' => 1,
    'external' => 1,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -50,
    'customized' => 1,
  );
  // Exported menu link: main-menu_leave-a-review:node/33
  $menu_links['main-menu_leave-a-review:node/33'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'node/33',
    'router_path' => 'node/%',
    'link_title' => 'Leave a Review',
    'options' => array(
      'identifier' => 'main-menu_leave-a-review:node/33',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -48,
    'customized' => 1,
    'parent_identifier' => 'main-menu_current-customers:node/9',
  );
  // Exported menu link: main-menu_market-1:node/71
  $menu_links['main-menu_market-1:node/71'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'node/71',
    'router_path' => 'node/%',
    'link_title' => 'Market 1',
    'options' => array(
      'identifier' => 'main-menu_market-1:node/71',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -50,
    'customized' => 1,
    'parent_identifier' => 'main-menu_service-areas:node/13',
  );
  // Exported menu link: main-menu_market-2:node/64
  $menu_links['main-menu_market-2:node/64'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'node/64',
    'router_path' => 'node/%',
    'link_title' => 'Market 2',
    'options' => array(
      'identifier' => 'main-menu_market-2:node/64',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -49,
    'customized' => 1,
    'parent_identifier' => 'main-menu_service-areas:node/13',
  );
  // Exported menu link: main-menu_market-3:node/77
  $menu_links['main-menu_market-3:node/77'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'node/77',
    'router_path' => 'node/%',
    'link_title' => 'Market 3',
    'options' => array(
      'identifier' => 'main-menu_market-3:node/77',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -48,
    'customized' => 1,
    'parent_identifier' => 'main-menu_service-areas:node/13',
  );
  // Exported menu link: main-menu_market-4:node/78
  $menu_links['main-menu_market-4:node/78'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'node/78',
    'router_path' => 'node/%',
    'link_title' => 'Market 4',
    'options' => array(
      'identifier' => 'main-menu_market-4:node/78',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -47,
    'customized' => 1,
    'parent_identifier' => 'main-menu_service-areas:node/13',
  );
  // Exported menu link: main-menu_meet-the-team:node/11
  $menu_links['main-menu_meet-the-team:node/11'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'node/11',
    'router_path' => 'node/%',
    'link_title' => 'Meet the Team',
    'options' => array(
      'identifier' => 'main-menu_meet-the-team:node/11',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -50,
    'customized' => 1,
    'parent_identifier' => 'main-menu_about:node/4',
  );
  // Exported menu link: main-menu_my-account:https://www.google.com
  $menu_links['main-menu_my-account:https://www.google.com'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'https://www.google.com',
    'router_path' => '',
    'link_title' => 'My Account',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
      'identifier' => 'main-menu_my-account:https://www.google.com',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 1,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -50,
    'customized' => 1,
    'parent_identifier' => 'main-menu_current-customers:node/9',
  );
  // Exported menu link: main-menu_our-blog:node/35
  $menu_links['main-menu_our-blog:node/35'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'node/35',
    'router_path' => 'node/%',
    'link_title' => 'Our Blog',
    'options' => array(
      'identifier' => 'main-menu_our-blog:node/35',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -45,
    'customized' => 1,
  );
  // Exported menu link: main-menu_our-story:node/31
  $menu_links['main-menu_our-story:node/31'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'node/31',
    'router_path' => 'node/%',
    'link_title' => 'Our Story',
    'options' => array(
      'identifier' => 'main-menu_our-story:node/31',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -49,
    'customized' => 1,
    'parent_identifier' => 'main-menu_about:node/4',
  );
  // Exported menu link: main-menu_refer-a-friend:node/10
  $menu_links['main-menu_refer-a-friend:node/10'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'node/10',
    'router_path' => 'node/%',
    'link_title' => 'Refer a Friend',
    'options' => array(
      'identifier' => 'main-menu_refer-a-friend:node/10',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -49,
    'customized' => 1,
    'parent_identifier' => 'main-menu_current-customers:node/9',
  );
  // Exported menu link: main-menu_service-1:node/17
  $menu_links['main-menu_service-1:node/17'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'node/17',
    'router_path' => 'node/%',
    'link_title' => 'Service 1',
    'options' => array(
      'identifier' => 'main-menu_service-1:node/17',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 0,
    'customized' => 0,
    'parent_identifier' => 'main-menu_services:node/12',
  );
  // Exported menu link: main-menu_service-2:node/87
  $menu_links['main-menu_service-2:node/87'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'node/87',
    'router_path' => 'node/%',
    'link_title' => 'Service 2',
    'options' => array(
      'identifier' => 'main-menu_service-2:node/87',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 0,
    'customized' => 0,
    'parent_identifier' => 'main-menu_services:node/12',
  );
  // Exported menu link: main-menu_service-3:node/19
  $menu_links['main-menu_service-3:node/19'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'node/19',
    'router_path' => 'node/%',
    'link_title' => 'Service 3',
    'options' => array(
      'identifier' => 'main-menu_service-3:node/19',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 0,
    'customized' => 0,
    'parent_identifier' => 'main-menu_services:node/12',
  );
  // Exported menu link: main-menu_service-areas:node/13
  $menu_links['main-menu_service-areas:node/13'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'node/13',
    'router_path' => 'node/%',
    'link_title' => 'Service Areas',
    'options' => array(
      'identifier' => 'main-menu_service-areas:node/13',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 1,
    'expanded' => 0,
    'weight' => -47,
    'customized' => 1,
  );
  // Exported menu link: main-menu_services:node/12
  $menu_links['main-menu_services:node/12'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'node/12',
    'router_path' => 'node/%',
    'link_title' => 'Services',
    'options' => array(
      'identifier' => 'main-menu_services:node/12',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 1,
    'expanded' => 0,
    'weight' => -48,
    'customized' => 1,
  );
  // Exported menu link: main-menu_testimonials:node/32
  $menu_links['main-menu_testimonials:node/32'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'node/32',
    'router_path' => 'node/%',
    'link_title' => 'Testimonials',
    'options' => array(
      'identifier' => 'main-menu_testimonials:node/32',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -46,
    'customized' => 1,
    'parent_identifier' => 'main-menu_about:node/4',
  );
  // Exported menu link: management_recent-log-messages:admin/reports/dblog
  $menu_links['management_recent-log-messages:admin/reports/dblog'] = array(
    'menu_name' => 'management',
    'link_path' => 'admin/reports/dblog',
    'router_path' => 'admin/reports/dblog',
    'link_title' => 'Recent log messages',
    'options' => array(
      'attributes' => array(
        'title' => 'View events that have recently been logged.',
      ),
      'identifier' => 'management_recent-log-messages:admin/reports/dblog',
    ),
    'module' => 'system',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -1,
    'customized' => 0,
    'parent_identifier' => 'management_reports:admin/reports',
  );
  // Translatables
  // Included for use with string extractors like potx.
  t('About');
  t('Affilations');
  t('Benefits');
  t('Careers');
  t('Contact');
  t('Coupons');
  t('Current Customers');
  t('Gallery');
  t('Get a free estimate');
  t('Home');
  t('Leave a Review');
  t('Market 1');
  t('Market 2');
  t('Market 3');
  t('Market 4');
  t('Meet the Team');
  t('My Account');
  t('Our Blog');
  t('Our Story');
  t('Recent log messages');
  t('Refer a Friend');
  t('Service 1');
  t('Service 2');
  t('Service 3');
  t('Service Areas');
  t('Services');
  t('Testimonials');


  return $menu_links;
}
