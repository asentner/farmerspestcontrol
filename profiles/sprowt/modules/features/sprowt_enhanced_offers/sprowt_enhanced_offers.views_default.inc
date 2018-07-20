<?php
/**
 * @file
 * sprowt_enhanced_offers.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function sprowt_enhanced_offers_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'special_offers_enhanced_';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Special Offers (Enhanced)';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'All Offers (Enhanced)';
  $handler->display->display_options['use_ajax'] = TRUE;
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'node';
  $handler->display->display_options['row_options']['view_mode'] = 'tertiary_teaser';
  $handler->display->display_options['row_options']['links'] = FALSE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  /* Sort criterion: Content: Featured Offer (field_featured_offer) */
  $handler->display->display_options['sorts']['field_featured_offer_value']['id'] = 'field_featured_offer_value';
  $handler->display->display_options['sorts']['field_featured_offer_value']['table'] = 'field_data_field_featured_offer';
  $handler->display->display_options['sorts']['field_featured_offer_value']['field'] = 'field_featured_offer_value';
  $handler->display->display_options['sorts']['field_featured_offer_value']['order'] = 'DESC';
  /* Sort criterion: Draggableviews: Weight */
  $handler->display->display_options['sorts']['weight']['id'] = 'weight';
  $handler->display->display_options['sorts']['weight']['table'] = 'draggableviews_structure';
  $handler->display->display_options['sorts']['weight']['field'] = 'weight';
  $handler->display->display_options['sorts']['weight']['draggableviews_setting_view'] = 'special_offer_list_sort:page';
  $handler->display->display_options['sorts']['weight']['draggableviews_setting_new_items_bottom_list'] = 1;
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'special_offer' => 'special_offer',
  );
  /* Filter criterion: Content: Services (field_services) */
  $handler->display->display_options['filters']['field_services_tid']['id'] = 'field_services_tid';
  $handler->display->display_options['filters']['field_services_tid']['table'] = 'field_data_field_services';
  $handler->display->display_options['filters']['field_services_tid']['field'] = 'field_services_tid';
  $handler->display->display_options['filters']['field_services_tid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_services_tid']['expose']['operator_id'] = 'field_services_tid_op';
  $handler->display->display_options['filters']['field_services_tid']['expose']['label'] = 'Let us help you find savings!';
  $handler->display->display_options['filters']['field_services_tid']['expose']['description'] = 'What is your pest issue?';
  $handler->display->display_options['filters']['field_services_tid']['expose']['operator'] = 'field_services_tid_op';
  $handler->display->display_options['filters']['field_services_tid']['expose']['identifier'] = 'field_services_tid';
  $handler->display->display_options['filters']['field_services_tid']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    5 => 0,
    4 => 0,
  );
  $handler->display->display_options['filters']['field_services_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_services_tid']['vocabulary'] = 'services';

  /* Display: All Offers (Enhanced) */
  $handler = $view->new_display('block', 'All Offers (Enhanced)', 'all_enhanced');
  $export['special_offers_enhanced_'] = $view;

  return $export;
}
