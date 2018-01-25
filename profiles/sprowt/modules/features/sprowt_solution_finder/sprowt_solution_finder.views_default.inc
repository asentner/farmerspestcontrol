<?php
/**
 * @file
 * sprowt_solution_finder.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function sprowt_solution_finder_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'solution_finder';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Solution Finder';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Solution Finder Order';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['style_plugin'] = 'table';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
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
    'concern' => 'concern',
  );
  /* Filter criterion: Content: Include In Solution Finder (field_include_in_solution_finder) */
  $handler->display->display_options['filters']['field_include_in_solution_finder_value']['id'] = 'field_include_in_solution_finder_value';
  $handler->display->display_options['filters']['field_include_in_solution_finder_value']['table'] = 'field_data_field_include_in_solution_finder';
  $handler->display->display_options['filters']['field_include_in_solution_finder_value']['field'] = 'field_include_in_solution_finder_value';
  $handler->display->display_options['filters']['field_include_in_solution_finder_value']['value'] = array(
    1 => '1',
  );

  /* Display: Draggable Sort */
  $handler = $view->new_display('page', 'Draggable Sort', 'order');
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  /* Field: Draggableviews: Content */
  $handler->display->display_options['fields']['draggableviews']['id'] = 'draggableviews';
  $handler->display->display_options['fields']['draggableviews']['table'] = 'node';
  $handler->display->display_options['fields']['draggableviews']['field'] = 'draggableviews';
  $handler->display->display_options['fields']['draggableviews']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['draggableviews']['hide_alter_empty'] = FALSE;
  $handler->display->display_options['fields']['draggableviews']['draggableviews']['ajax'] = 0;
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  /* Sort criterion: Draggableviews: Weight */
  $handler->display->display_options['sorts']['weight_1']['id'] = 'weight_1';
  $handler->display->display_options['sorts']['weight_1']['table'] = 'draggableviews_structure';
  $handler->display->display_options['sorts']['weight_1']['field'] = 'weight';
  $handler->display->display_options['sorts']['weight_1']['draggableviews_setting_view'] = 'solution_finder:order';
  $handler->display->display_options['sorts']['weight_1']['draggableviews_setting_new_items_bottom_list'] = 1;
  $handler->display->display_options['path'] = 'admin/content/solution-finder-sort';
  $handler->display->display_options['menu']['type'] = 'normal';
  $handler->display->display_options['menu']['title'] = 'Solution Finder Order';
  $handler->display->display_options['menu']['description'] = 'Solution Finder Order';
  $handler->display->display_options['menu']['weight'] = '0';
  $handler->display->display_options['menu']['name'] = 'management';
  $handler->display->display_options['menu']['context'] = 0;
  $handler->display->display_options['menu']['context_only_inline'] = 0;
  $export['solution_finder'] = $view;

  return $export;
}
