<?php
/**
 * @file
 * sprowt_views_feature.features.inc
 */

/**
 * Implements hook_views_api().
 */
function sprowt_views_feature_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}

/**
 * Implements hook_views_default_views_alter().
 */
function sprowt_views_feature_views_default_views_alter(&$data) {
  if (isset($data['admin_views_node'])) {
    $data['admin_views_node']->display['default']->display_options['fields']['views_bulk_operations']['table'] = 'views_entity_node'; /* WAS: 'node' */
    $data['admin_views_node']->display['system_1']->display_options['defaults']['fields'] = FALSE; /* WAS: '' */
    $data['admin_views_node']->display['system_1']->display_options['defaults']['sorts'] = FALSE; /* WAS: '' */
    $data['admin_views_node']->display['system_1']->display_options['fields'] = array(
      'views_bulk_operations' => array(
        'id' => 'views_bulk_operations',
        'table' => 'views_entity_node',
        'field' => 'views_bulk_operations',
        'label' => '',
        'element_label_colon' => FALSE,
        'hide_alter_empty' => FALSE,
        'vbo_settings' => array(
          'display_type' => 0,
          'enable_select_all_pages' => 1,
          'row_clickable' => 1,
          'force_single' => 0,
          'entity_load_capacity' => 10,
        ),
        'vbo_operations' => array(
          'action::node_assign_owner_action' => array(
            'selected' => 1,
            'postpone_processing' => 0,
            'skip_confirmation' => 1,
            'skip_permission_check' => 0,
            'override_label' => 1,
            'label' => 'Change author',
          ),
          'action::views_bulk_operations_delete_item' => array(
            'selected' => 1,
            'postpone_processing' => 0,
            'skip_confirmation' => 0,
            'skip_permission_check' => 0,
            'override_label' => 1,
            'label' => 'Delete',
            'settings' => array(
              'log' => 0,
            ),
          ),
          'action::node_make_sticky_action' => array(
            'selected' => 1,
            'postpone_processing' => 0,
            'skip_confirmation' => 1,
            'skip_permission_check' => 0,
            'override_label' => 1,
            'label' => 'Stick',
          ),
          'action::node_make_unsticky_action' => array(
            'selected' => 1,
            'postpone_processing' => 0,
            'skip_confirmation' => 1,
            'skip_permission_check' => 0,
            'override_label' => 1,
            'label' => 'Unstick',
          ),
          'action::views_bulk_operations_modify_action' => array(
            'selected' => 1,
            'postpone_processing' => 0,
            'skip_confirmation' => 1,
            'skip_permission_check' => 0,
            'override_label' => 1,
            'label' => 'Change value',
            'settings' => array(
              'show_all_tokens' => 1,
              'display_values' => array(
                '_all_' => '_all_',
              ),
            ),
          ),
          'action::node_export_drupal_action' => array(
            'selected' => 1,
            'postpone_processing' => 0,
            'skip_confirmation' => 0,
            'skip_permission_check' => 0,
            'override_label' => 1,
            'label' => 'Node Export',
          ),
          'action::node_promote_action' => array(
            'selected' => 1,
            'postpone_processing' => 0,
            'skip_confirmation' => 1,
            'skip_permission_check' => 0,
            'override_label' => 1,
            'label' => 'Promote to front page',
          ),
          'action::node_publish_action' => array(
            'selected' => 1,
            'postpone_processing' => 0,
            'skip_confirmation' => 1,
            'skip_permission_check' => 0,
            'override_label' => 1,
            'label' => 'Publish',
          ),
          'action::node_unpromote_action' => array(
            'selected' => 1,
            'postpone_processing' => 0,
            'skip_confirmation' => 1,
            'skip_permission_check' => 0,
            'override_label' => 1,
            'label' => 'Demote from front page',
          ),
          'action::node_unpublish_action' => array(
            'selected' => 1,
            'postpone_processing' => 0,
            'skip_confirmation' => 1,
            'skip_permission_check' => 0,
            'override_label' => 1,
            'label' => 'Unpublish',
          ),
        ),
      ),
      'title' => array(
        'id' => 'title',
        'table' => 'node',
        'field' => 'title',
      ),
      'timestamp' => array(
        'id' => 'timestamp',
        'table' => 'history',
        'field' => 'timestamp',
        'label' => '',
        'element_label_colon' => FALSE,
      ),
      'type' => array(
        'id' => 'type',
        'table' => 'node',
        'field' => 'type',
      ),
      'name' => array(
        'id' => 'name',
        'table' => 'users',
        'field' => 'name',
        'relationship' => 'uid',
        'label' => 'Author',
        'hide_alter_empty' => FALSE,
      ),
      'status' => array(
        'id' => 'status',
        'table' => 'node',
        'field' => 'status',
        'not' => 0,
      ),
      'changed' => array(
        'id' => 'changed',
        'table' => 'node',
        'field' => 'changed',
        'label' => 'Updated',
        'date_format' => 'short',
      ),
      'edit_node' => array(
        'id' => 'edit_node',
        'table' => 'views_entity_node',
        'field' => 'edit_node',
        'label' => 'Operations',
      ),
      'delete_node' => array(
        'id' => 'delete_node',
        'table' => 'views_entity_node',
        'field' => 'delete_node',
        'label' => '',
      ),
    ); /* WAS: '' */
    unset($data['admin_views_node']->display['default']->display_options['fields']['views_bulk_operations']['vbo_operations']['action::node_save_action']);
    unset($data['admin_views_node']->display['default']->display_options['fields']['views_bulk_operations']['vbo_operations']['action::node_unpublish_by_keyword_action']);
    unset($data['admin_views_node']->display['default']->display_options['fields']['views_bulk_operations']['vbo_operations']['action::system_goto_action']);
    unset($data['admin_views_node']->display['default']->display_options['fields']['views_bulk_operations']['vbo_operations']['action::system_message_action']);
    unset($data['admin_views_node']->display['default']->display_options['fields']['views_bulk_operations']['vbo_operations']['action::system_send_email_action']);
    unset($data['admin_views_node']->display['default']->display_options['fields']['views_bulk_operations']['vbo_operations']['action::views_bulk_operations_argument_selector_action']);
    unset($data['admin_views_node']->display['default']->display_options['fields']['views_bulk_operations']['vbo_operations']['action::views_bulk_operations_script_action']);
  }
  if (isset($data['admin_views_user'])) {
    $data['admin_views_user']->display['default']->display_options['fields']['views_bulk_operations']['table'] = 'views_entity_user'; /* WAS: 'users' */
    unset($data['admin_views_user']->display['default']->display_options['fields']['views_bulk_operations']['vbo_operations']['action::system_block_ip_action']);
    unset($data['admin_views_user']->display['default']->display_options['fields']['views_bulk_operations']['vbo_operations']['action::system_goto_action']);
    unset($data['admin_views_user']->display['default']->display_options['fields']['views_bulk_operations']['vbo_operations']['action::system_message_action']);
    unset($data['admin_views_user']->display['default']->display_options['fields']['views_bulk_operations']['vbo_operations']['action::user_block_user_action']);
    unset($data['admin_views_user']->display['default']->display_options['fields']['views_bulk_operations']['vbo_operations']['action::views_bulk_operations_argument_selector_action']);
    unset($data['admin_views_user']->display['default']->display_options['fields']['views_bulk_operations']['vbo_operations']['action::views_bulk_operations_delete_item']);
    unset($data['admin_views_user']->display['default']->display_options['fields']['views_bulk_operations']['vbo_operations']['action::views_bulk_operations_script_action']);
  }
  if (isset($data['weight'])) {
    $data['weight']->display['default']->display_options['fields']['title']['alter']['ellipsis'] = FALSE; /* WAS: 0 */
    $data['weight']->display['default']->display_options['fields']['title']['alter']['word_boundary'] = FALSE; /* WAS: 0 */
    $data['weight']->display['default']->display_options['filters']['status']['exposed'] = TRUE; /* WAS: '' */
    $data['weight']->display['default']->display_options['filters']['status']['expose']['identifier'] = 'status'; /* WAS: '' */
    $data['weight']->display['default']->display_options['filters']['status']['expose']['label'] = 'Published'; /* WAS: '' */
    $data['weight']->display['default']->display_options['filters']['status']['expose']['operator'] = 'status_op'; /* WAS: FALSE */
    $data['weight']->display['default']->display_options['filters']['status']['expose']['operator_id'] = ''; /* WAS: '' */
    $data['weight']->display['default']->display_options['filters']['status']['expose']['remember_roles'] = array(
      2 => 2,
      1 => 0,
      3 => 0,
      5 => 0,
      4 => 0,
    ); /* WAS: '' */
    $data['weight']->display['default']->display_options['filters']['status']['expose']['required'] = TRUE; /* WAS: '' */
    $data['weight']->display['default']->display_options['filters']['title'] = array(
      'id' => 'title',
      'table' => 'node',
      'field' => 'title',
      'operator' => 'contains',
      'exposed' => TRUE,
      'expose' => array(
        'operator_id' => 'title_op',
        'label' => 'Title',
        'operator' => 'title_op',
        'identifier' => 'title',
        'remember_roles' => array(
          2 => 2,
          1 => 0,
          3 => 0,
          5 => 0,
          4 => 0,
        ),
      ),
    ); /* WAS: '' */
    $data['weight']->display['default']->display_options['filters']['type'] = array(
      'id' => 'type',
      'table' => 'node',
      'field' => 'type',
      'exposed' => TRUE,
      'expose' => array(
        'operator_id' => 'type_op',
        'label' => 'Type',
        'operator' => 'type_op',
        'identifier' => 'type',
        'remember_roles' => array(
          2 => 2,
          1 => 0,
          3 => 0,
          5 => 0,
          4 => 0,
        ),
      ),
    ); /* WAS: '' */
    $data['weight']->display['default']->display_options['pager']['options']['id'] = 0; /* WAS: '' */
    $data['weight']->display['default']->display_options['pager']['options']['items_per_page'] = 50; /* WAS: 10 */
    $data['weight']->display['default']->display_options['pager']['options']['offset'] = 0; /* WAS: '' */
    $data['weight']->display['default']->display_options['pager']['options']['quantity'] = 9; /* WAS: '' */
    $data['weight']->display['default']->display_options['use_more_always'] = FALSE; /* WAS: '' */
    $data['weight']->display['page_1'] = unserialize('O:13:"views_display":7:{s:15:"display_options";a:5:{s:5:"query";a:2:{s:4:"type";s:11:"views_query";s:7:"options";a:0:{}}s:8:"defaults";a:1:{s:6:"fields";b:0;}s:6:"fields";a:4:{s:5:"title";a:4:{s:2:"id";s:5:"title";s:5:"table";s:4:"node";s:5:"field";s:5:"title";s:5:"alter";a:2:{s:13:"word_boundary";b:0;s:8:"ellipsis";b:0;}}s:4:"type";a:3:{s:2:"id";s:4:"type";s:5:"table";s:4:"node";s:5:"field";s:4:"type";}s:6:"status";a:4:{s:2:"id";s:6:"status";s:5:"table";s:4:"node";s:5:"field";s:6:"status";s:3:"not";i:0;}s:6:"weight";a:5:{s:2:"id";s:6:"weight";s:5:"table";s:14:"weight_weights";s:5:"field";s:6:"weight";s:5:"label";s:0:"";s:19:"element_label_colon";b:0;}}s:4:"path";s:20:"admin/content/weight";s:4:"menu";a:6:{s:4:"type";s:3:"tab";s:5:"title";s:6:"Weight";s:6:"weight";s:1:"0";s:4:"name";s:10:"management";s:7:"context";i:0;s:19:"context_only_inline";i:0;}}s:8:"db_table";s:13:"views_display";s:3:"vid";i:0;s:2:"id";s:6:"page_1";s:13:"display_title";s:5:"Admin";s:14:"display_plugin";s:4:"page";s:8:"position";i:0;}'); /* WAS: '' */
    unset($data['weight']->display['default']->display_options['fields']['title']['alter']['absolute']);
    unset($data['weight']->display['default']->display_options['fields']['title']['alter']['alter_text']);
    unset($data['weight']->display['default']->display_options['fields']['title']['alter']['html']);
    unset($data['weight']->display['default']->display_options['fields']['title']['alter']['make_link']);
    unset($data['weight']->display['default']->display_options['fields']['title']['alter']['strip_tags']);
    unset($data['weight']->display['default']->display_options['fields']['title']['alter']['trim']);
    unset($data['weight']->display['default']->display_options['fields']['title']['empty_zero']);
    unset($data['weight']->display['default']->display_options['fields']['title']['hide_empty']);
    unset($data['weight']->display['default']->display_options['fields']['title']['link_to_node']);
    unset($data['weight']->display['default']->display_options['fields']['weight']['alter']);
    unset($data['weight']->display['default']->display_options['fields']['weight']['element_default_classes']);
    unset($data['weight']->display['default']->display_options['fields']['weight']['empty_zero']);
    unset($data['weight']->display['default']->display_options['fields']['weight']['hide_alter_empty']);
    unset($data['weight']->display['default']->display_options['fields']['weight']['hide_empty']);
    unset($data['weight']->display['default']->display_options['filters']['status']['group']);
    unset($data['weight']->display['default']->display_options['filters']['status']['value']);
    unset($data['weight']->display['default']->display_options['style_options']['empty_table']);
    unset($data['weight']->display['default']->display_options['style_options']['override']);
    unset($data['weight']->display['default']->display_options['style_options']['sticky']);
  }
}
