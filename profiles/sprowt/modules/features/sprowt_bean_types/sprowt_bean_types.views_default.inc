<?php

/**
 * @file
 * sprowt_bean_types.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function sprowt_bean_types_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'referenced_hero_block';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'bean';
  $view->human_name = 'Referenced Hero Block';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'none';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '1';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'entity';
  /* Field: Block: Internal, numeric block ID */
  $handler->display->display_options['fields']['bid']['id'] = 'bid';
  $handler->display->display_options['fields']['bid']['table'] = 'bean';
  $handler->display->display_options['fields']['bid']['field'] = 'bid';
  /* Contextual filter: Field: Service (field_service) */
  $handler->display->display_options['arguments']['field_service_tid']['id'] = 'field_service_tid';
  $handler->display->display_options['arguments']['field_service_tid']['table'] = 'field_data_field_service';
  $handler->display->display_options['arguments']['field_service_tid']['field'] = 'field_service_tid';
  $handler->display->display_options['arguments']['field_service_tid']['default_action'] = 'default';
  $handler->display->display_options['arguments']['field_service_tid']['default_argument_type'] = 'taxonomy_tid';
  $handler->display->display_options['arguments']['field_service_tid']['default_argument_options']['term_page'] = FALSE;
  $handler->display->display_options['arguments']['field_service_tid']['default_argument_options']['node'] = TRUE;
  $handler->display->display_options['arguments']['field_service_tid']['default_argument_options']['anyall'] = '+';
  $handler->display->display_options['arguments']['field_service_tid']['default_argument_options']['limit'] = TRUE;
  $handler->display->display_options['arguments']['field_service_tid']['default_argument_options']['vocabularies'] = array(
    'services' => 'services',
  );
  $handler->display->display_options['arguments']['field_service_tid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['field_service_tid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_service_tid']['summary_options']['items_per_page'] = '25';
  /* Contextual filter: Field: Market (field_market) */
  $handler->display->display_options['arguments']['field_market_tid']['id'] = 'field_market_tid';
  $handler->display->display_options['arguments']['field_market_tid']['table'] = 'field_data_field_market';
  $handler->display->display_options['arguments']['field_market_tid']['field'] = 'field_market_tid';
  $handler->display->display_options['arguments']['field_market_tid']['default_action'] = 'default';
  $handler->display->display_options['arguments']['field_market_tid']['default_argument_type'] = 'taxonomy_tid';
  $handler->display->display_options['arguments']['field_market_tid']['default_argument_options']['term_page'] = FALSE;
  $handler->display->display_options['arguments']['field_market_tid']['default_argument_options']['node'] = TRUE;
  $handler->display->display_options['arguments']['field_market_tid']['default_argument_options']['anyall'] = '+';
  $handler->display->display_options['arguments']['field_market_tid']['default_argument_options']['limit'] = TRUE;
  $handler->display->display_options['arguments']['field_market_tid']['default_argument_options']['vocabularies'] = array(
    'markets' => 'markets',
  );
  $handler->display->display_options['arguments']['field_market_tid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['field_market_tid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_market_tid']['summary_options']['items_per_page'] = '25';
  /* Filter criterion: Block: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'bean';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'hero' => 'hero',
  );

  /* Display: Referenced Hero Block */
  $handler = $view->new_display('block', 'Referenced Hero Block', 'block');
  $handler->display->display_options['block_description'] = 'Referenced Hero Block';
  $export['referenced_hero_block'] = $view;

  return $export;
}
