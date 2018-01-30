<?php
/**
 * @file
 * sprowt_views_feature.features.features_overrides.inc
 */

/**
 * Implements hook_features_override_default_overrides().
 */
function sprowt_views_feature_features_override_default_overrides() {
  // This code is only used for UI in features. Exported alters hooks do the magic.
  $overrides = array();

  // Exported overrides for: views_view
  $overrides["views_view.admin_views_node.display|default|display_options|fields|views_bulk_operations|table"] = 'views_entity_node';
  $overrides["views_view.admin_views_node.display|default|display_options|fields|views_bulk_operations|vbo_operations|action::node_save_action"]["DELETED"] = TRUE;
  $overrides["views_view.admin_views_node.display|default|display_options|fields|views_bulk_operations|vbo_operations|action::node_unpublish_by_keyword_action"]["DELETED"] = TRUE;
  $overrides["views_view.admin_views_node.display|default|display_options|fields|views_bulk_operations|vbo_operations|action::system_goto_action"]["DELETED"] = TRUE;
  $overrides["views_view.admin_views_node.display|default|display_options|fields|views_bulk_operations|vbo_operations|action::system_message_action"]["DELETED"] = TRUE;
  $overrides["views_view.admin_views_node.display|default|display_options|fields|views_bulk_operations|vbo_operations|action::system_send_email_action"]["DELETED"] = TRUE;
  $overrides["views_view.admin_views_node.display|default|display_options|fields|views_bulk_operations|vbo_operations|action::views_bulk_operations_argument_selector_action"]["DELETED"] = TRUE;
  $overrides["views_view.admin_views_node.display|default|display_options|fields|views_bulk_operations|vbo_operations|action::views_bulk_operations_script_action"]["DELETED"] = TRUE;
  $overrides["views_view.admin_views_node.display|system_1|display_options|defaults|fields"] = FALSE;
  $overrides["views_view.admin_views_node.display|system_1|display_options|defaults|sorts"] = FALSE;
  $overrides["views_view.admin_views_node.display|system_1|display_options|fields"] = array(
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
  );
  $overrides["views_view.admin_views_user.display|default|display_options|fields|views_bulk_operations|table"] = 'views_entity_user';
  $overrides["views_view.admin_views_user.display|default|display_options|fields|views_bulk_operations|vbo_operations|action::system_block_ip_action"]["DELETED"] = TRUE;
  $overrides["views_view.admin_views_user.display|default|display_options|fields|views_bulk_operations|vbo_operations|action::system_goto_action"]["DELETED"] = TRUE;
  $overrides["views_view.admin_views_user.display|default|display_options|fields|views_bulk_operations|vbo_operations|action::system_message_action"]["DELETED"] = TRUE;
  $overrides["views_view.admin_views_user.display|default|display_options|fields|views_bulk_operations|vbo_operations|action::user_block_user_action"]["DELETED"] = TRUE;
  $overrides["views_view.admin_views_user.display|default|display_options|fields|views_bulk_operations|vbo_operations|action::views_bulk_operations_argument_selector_action"]["DELETED"] = TRUE;
  $overrides["views_view.admin_views_user.display|default|display_options|fields|views_bulk_operations|vbo_operations|action::views_bulk_operations_delete_item"]["DELETED"] = TRUE;
  $overrides["views_view.admin_views_user.display|default|display_options|fields|views_bulk_operations|vbo_operations|action::views_bulk_operations_script_action"]["DELETED"] = TRUE;
  $overrides["views_view.weight.display|default|display_options|fields|title|alter|absolute"]["DELETED"] = TRUE;
  $overrides["views_view.weight.display|default|display_options|fields|title|alter|alter_text"]["DELETED"] = TRUE;
  $overrides["views_view.weight.display|default|display_options|fields|title|alter|ellipsis"] = FALSE;
  $overrides["views_view.weight.display|default|display_options|fields|title|alter|html"]["DELETED"] = TRUE;
  $overrides["views_view.weight.display|default|display_options|fields|title|alter|make_link"]["DELETED"] = TRUE;
  $overrides["views_view.weight.display|default|display_options|fields|title|alter|strip_tags"]["DELETED"] = TRUE;
  $overrides["views_view.weight.display|default|display_options|fields|title|alter|trim"]["DELETED"] = TRUE;
  $overrides["views_view.weight.display|default|display_options|fields|title|alter|word_boundary"] = FALSE;
  $overrides["views_view.weight.display|default|display_options|fields|title|empty_zero"]["DELETED"] = TRUE;
  $overrides["views_view.weight.display|default|display_options|fields|title|hide_empty"]["DELETED"] = TRUE;
  $overrides["views_view.weight.display|default|display_options|fields|title|link_to_node"]["DELETED"] = TRUE;
  $overrides["views_view.weight.display|default|display_options|fields|weight|alter"]["DELETED"] = TRUE;
  $overrides["views_view.weight.display|default|display_options|fields|weight|element_default_classes"]["DELETED"] = TRUE;
  $overrides["views_view.weight.display|default|display_options|fields|weight|empty_zero"]["DELETED"] = TRUE;
  $overrides["views_view.weight.display|default|display_options|fields|weight|hide_alter_empty"]["DELETED"] = TRUE;
  $overrides["views_view.weight.display|default|display_options|fields|weight|hide_empty"]["DELETED"] = TRUE;
  $overrides["views_view.weight.display|default|display_options|filters|status|exposed"] = TRUE;
  $overrides["views_view.weight.display|default|display_options|filters|status|expose|identifier"] = 'status';
  $overrides["views_view.weight.display|default|display_options|filters|status|expose|label"] = 'Published';
  $overrides["views_view.weight.display|default|display_options|filters|status|expose|operator"] = 'status_op';
  $overrides["views_view.weight.display|default|display_options|filters|status|expose|operator_id"] = '';
  $overrides["views_view.weight.display|default|display_options|filters|status|expose|remember_roles"] = array(
    2 => 2,
    1 => 0,
    3 => 0,
    5 => 0,
    4 => 0,
  );
  $overrides["views_view.weight.display|default|display_options|filters|status|expose|required"] = TRUE;
  $overrides["views_view.weight.display|default|display_options|filters|status|group"]["DELETED"] = TRUE;
  $overrides["views_view.weight.display|default|display_options|filters|status|value"]["DELETED"] = TRUE;
  $overrides["views_view.weight.display|default|display_options|filters|title"] = array(
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
  );
  $overrides["views_view.weight.display|default|display_options|filters|type"] = array(
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
  );
  $overrides["views_view.weight.display|default|display_options|pager|options|id"] = 0;
  $overrides["views_view.weight.display|default|display_options|pager|options|items_per_page"] = 50;
  $overrides["views_view.weight.display|default|display_options|pager|options|offset"] = 0;
  $overrides["views_view.weight.display|default|display_options|pager|options|quantity"] = 9;
  $overrides["views_view.weight.display|default|display_options|style_options|empty_table"]["DELETED"] = TRUE;
  $overrides["views_view.weight.display|default|display_options|style_options|override"]["DELETED"] = TRUE;
  $overrides["views_view.weight.display|default|display_options|style_options|sticky"]["DELETED"] = TRUE;
  $overrides["views_view.weight.display|default|display_options|use_more_always"] = FALSE;
  $overrides["views_view.weight.display|page_1"] = unserialize('O:13:"views_display":7:{s:15:"display_options";a:5:{s:5:"query";a:2:{s:4:"type";s:11:"views_query";s:7:"options";a:0:{}}s:8:"defaults";a:1:{s:6:"fields";b:0;}s:6:"fields";a:4:{s:5:"title";a:4:{s:2:"id";s:5:"title";s:5:"table";s:4:"node";s:5:"field";s:5:"title";s:5:"alter";a:2:{s:13:"word_boundary";b:0;s:8:"ellipsis";b:0;}}s:4:"type";a:3:{s:2:"id";s:4:"type";s:5:"table";s:4:"node";s:5:"field";s:4:"type";}s:6:"status";a:4:{s:2:"id";s:6:"status";s:5:"table";s:4:"node";s:5:"field";s:6:"status";s:3:"not";i:0;}s:6:"weight";a:5:{s:2:"id";s:6:"weight";s:5:"table";s:14:"weight_weights";s:5:"field";s:6:"weight";s:5:"label";s:0:"";s:19:"element_label_colon";b:0;}}s:4:"path";s:20:"admin/content/weight";s:4:"menu";a:6:{s:4:"type";s:3:"tab";s:5:"title";s:6:"Weight";s:6:"weight";s:1:"0";s:4:"name";s:10:"management";s:7:"context";i:0;s:19:"context_only_inline";i:0;}}s:8:"db_table";s:13:"views_display";s:3:"vid";i:0;s:2:"id";s:6:"page_1";s:13:"display_title";s:5:"Admin";s:14:"display_plugin";s:4:"page";s:8:"position";i:0;}');

 return $overrides;
}
