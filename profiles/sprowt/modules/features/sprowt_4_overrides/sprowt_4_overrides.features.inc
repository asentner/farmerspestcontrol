<?php
/**
 * @file
 * sprowt_4_overrides.features.inc
 */

/**
 * Implements hook_default_fe_block_settings_alter().
 */
function sprowt_4_overrides_default_fe_block_settings_alter(&$data) {
  if (isset($data['addtoany-addtoany_button'])) {
    $data['addtoany-addtoany_button']['themes']['sprowt_4'] = array(
      'region' => '',
      'status' => 0,
      'theme' => 'sprowt_4',
      'weight' => -37,
    ); /* WAS: '' */
    unset($data['addtoany-addtoany_button']['themes']['sprowt_1']);
  }
  if (isset($data['flippy-flippy_pager-node_type-profile'])) {
    $data['flippy-flippy_pager-node_type-profile']['themes']['sprowt_4'] = array(
      'region' => '',
      'status' => 0,
      'theme' => 'sprowt_4',
      'weight' => 0,
    ); /* WAS: '' */
    unset($data['flippy-flippy_pager-node_type-profile']['themes']['sprowt_1']);
  }
  if (isset($data['flippy-flippy_pager'])) {
    $data['flippy-flippy_pager']['themes']['sprowt_4'] = array(
      'region' => '',
      'status' => 0,
      'theme' => 'sprowt_4',
      'weight' => -29,
    ); /* WAS: '' */
    unset($data['flippy-flippy_pager']['themes']['sprowt_1']);
  }
}

/**
 * Implements hook_flexslider_default_presets_alter().
 */
function sprowt_4_overrides_flexslider_default_presets_alter(&$data) {
  if (isset($data['default'])) {
    unset($data['default']->export_type);
    unset($data['default']->type);
  }
}

/**
 * Implements hook_image_styles_alter().
 */
function sprowt_4_overrides_image_styles_alter(&$data) {
  if (isset($data['flexslider_full'])) {

  if (!isset($data['flexslider_full']['storage']) || $data['flexslider_full']['storage'] == IMAGE_STORAGE_DEFAULT) {
    $data['flexslider_full']['effects'] = array_values($data['flexslider_full']['effects']);
    $data['flexslider_full']['label'] = 'flexslider_full';
  }
  }
  if (isset($data['flexslider_thumbnail'])) {

  if (!isset($data['flexslider_thumbnail']['storage']) || $data['flexslider_thumbnail']['storage'] == IMAGE_STORAGE_DEFAULT) {
    $data['flexslider_thumbnail']['effects'] = array_values($data['flexslider_thumbnail']['effects']);
    $data['flexslider_thumbnail']['label'] = 'flexslider_thumbnail';
  }
  }
  if (isset($data['menu_icon'])) {

  if (!isset($data['menu_icon']['storage']) || $data['menu_icon']['storage'] == IMAGE_STORAGE_DEFAULT) {
    $data['menu_icon']['effects'] = array_values($data['menu_icon']['effects']);
    $data['menu_icon']['label'] = 'menu_icon';
  }
  }
}

/**
 * Implements hook_strongarm_alter().
 */
function sprowt_4_overrides_strongarm_alter(&$data) {
  if (isset($data['menu_main_links_source'])) {
    unset($data['menu_main_links_source']);
  }
  if (isset($data['menu_masks'])) {
    $data['menu_masks']->value[1] = 253; /* WAS: 255 */
    $data['menu_masks']->value[26] = 24; /* WAS: 26 */
    $data['menu_masks']->value[27] = 23; /* WAS: 24 */
    $data['menu_masks']->value[4] = 126; /* WAS: 127 */
  }
  if (isset($data['menu_secondary_links_source'])) {
    unset($data['menu_secondary_links_source']);
  }
  if (isset($data['menu_target_enabled'])) {
    unset($data['menu_target_enabled']);
  }
  if (isset($data['menu_target_type'])) {
    unset($data['menu_target_type']);
  }
  if (isset($data['weight_menu_affiliation'])) {
    unset($data['weight_menu_affiliation']);
  }
  if (isset($data['weight_menu_benefit'])) {
    unset($data['weight_menu_benefit']);
  }
  if (isset($data['weight_menu_blog'])) {
    unset($data['weight_menu_blog']);
  }
  if (isset($data['weight_menu_cta'])) {
    unset($data['weight_menu_cta']);
  }
  if (isset($data['weight_menu_faq'])) {
    unset($data['weight_menu_faq']);
  }
  if (isset($data['weight_menu_gallery_image'])) {
    unset($data['weight_menu_gallery_image']);
  }
  if (isset($data['weight_menu_landing_page'])) {
    unset($data['weight_menu_landing_page']);
  }
  if (isset($data['weight_menu_localtarget'])) {
    unset($data['weight_menu_localtarget']);
  }
  if (isset($data['weight_menu_location'])) {
    unset($data['weight_menu_location']);
  }
  if (isset($data['weight_menu_market'])) {
    unset($data['weight_menu_market']);
  }
  if (isset($data['weight_menu_package'])) {
    unset($data['weight_menu_package']);
  }
  if (isset($data['weight_menu_page'])) {
    unset($data['weight_menu_page']);
  }
  if (isset($data['weight_menu_region'])) {
    unset($data['weight_menu_region']);
  }
  if (isset($data['weight_menu_service'])) {
    unset($data['weight_menu_service']);
  }
  if (isset($data['weight_menu_slide'])) {
    unset($data['weight_menu_slide']);
  }
  if (isset($data['weight_menu_special_offer'])) {
    unset($data['weight_menu_special_offer']);
  }
  if (isset($data['weight_menu_testimonial'])) {
    unset($data['weight_menu_testimonial']);
  }
  if (isset($data['weight_menu_webform'])) {
    unset($data['weight_menu_webform']);
  }
}

/**
 * Implements hook_views_default_views_alter().
 */
function sprowt_4_overrides_views_default_views_alter(&$data) {
  if (isset($data['archive'])) {
    $data['archive']->display['block']->display_options['arguments']['created_year_month']['exception']['title_enable'] = TRUE; /* WAS: 1 */
    $data['archive']->display['block']->display_options['arguments']['created_year_month']['specify_validation'] = TRUE; /* WAS: 1 */
    $data['archive']->display['block']->display_options['arguments']['created_year_month']['title_enable'] = TRUE; /* WAS: 1 */
    $data['archive']->display['default']->display_options['arguments']['created_year_month']['exception']['title_enable'] = TRUE; /* WAS: 1 */
    $data['archive']->display['default']->display_options['arguments']['created_year_month']['specify_validation'] = TRUE; /* WAS: 1 */
    $data['archive']->display['default']->display_options['arguments']['created_year_month']['title_enable'] = TRUE; /* WAS: 1 */
    $data['archive']->display['default']->display_options['use_more_always'] = FALSE; /* WAS: '' */
    unset($data['archive']->display['default']->display_options['access']['perm']);
  }
  if (isset($data['backlinks'])) {
    $data['backlinks']->display['block']->display_options['arguments']['nid']['specify_validation'] = TRUE; /* WAS: 1 */
    $data['backlinks']->display['block']->display_options['arguments']['nid']['title_enable'] = TRUE; /* WAS: 1 */
    $data['backlinks']->display['default']->display_options['arguments']['nid']['specify_validation'] = TRUE; /* WAS: 1 */
    $data['backlinks']->display['default']->display_options['arguments']['nid']['title_enable'] = TRUE; /* WAS: 1 */
    $data['backlinks']->display['default']->display_options['use_more_always'] = FALSE; /* WAS: '' */
    unset($data['backlinks']->display['default']->display_options['access']['perm']);
    unset($data['backlinks']->display['default']->display_options['empty']['text']['empty']);
    unset($data['backlinks']->display['default']->display_options['fields']['title']['link_to_node']);
  }
  if (isset($data['frontpage'])) {
    $data['frontpage']->display['default']->display_options['use_more_always'] = FALSE; /* WAS: '' */
    unset($data['frontpage']->display['default']->display_options['access']['perm']);
    unset($data['frontpage']->display['default']->display_options['row_options']);
  }
  if (isset($data['glossary'])) {
    $data['glossary']->display['attachment']->display_options['arguments']['title']['exception']['title_enable'] = TRUE; /* WAS: 1 */
    $data['glossary']->display['attachment']->display_options['arguments']['title']['glossary'] = TRUE; /* WAS: 1 */
    $data['glossary']->display['attachment']->display_options['arguments']['title']['specify_validation'] = TRUE; /* WAS: 1 */
    $data['glossary']->display['attachment']->display_options['arguments']['title']['summary_options']['inline'] = TRUE; /* WAS: 1 */
    $data['glossary']->display['attachment']->display_options['inherit_arguments'] = FALSE; /* WAS: 0 */
    $data['glossary']->display['default']->display_options['arguments']['title']['exception']['title_enable'] = TRUE; /* WAS: 1 */
    $data['glossary']->display['default']->display_options['arguments']['title']['glossary'] = TRUE; /* WAS: 1 */
    $data['glossary']->display['default']->display_options['arguments']['title']['specify_validation'] = TRUE; /* WAS: 1 */
    $data['glossary']->display['default']->display_options['use_more_always'] = FALSE; /* WAS: '' */
    unset($data['glossary']->display['attachment']->display_options['arguments']['title']['transform_dash']);
    unset($data['glossary']->display['default']->display_options['access']['perm']);
    unset($data['glossary']->display['default']->display_options['arguments']['title']['transform_dash']);
    unset($data['glossary']->display['default']->display_options['fields']['name']['link_to_user']);
    unset($data['glossary']->display['default']->display_options['fields']['title']['link_to_node']);
    unset($data['glossary']->display['default']->display_options['style_options']['override']);
    unset($data['glossary']->display['default']->display_options['style_options']['sticky']);
  }
  if (isset($data['services'])) {
    $data['services']->display['front_s4'] = unserialize('O:13:"views_display":7:{s:15:"display_options";a:6:{s:5:"query";a:2:{s:4:"type";s:11:"views_query";s:7:"options";a:0:{}}s:8:"defaults";a:4:{s:12:"style_plugin";b:0;s:13:"style_options";b:0;s:10:"row_plugin";b:0;s:11:"row_options";b:0;}s:12:"style_plugin";s:7:"default";s:10:"row_plugin";s:4:"node";s:11:"row_options";a:1:{s:9:"view_mode";s:10:"alt_teaser";}s:17:"block_description";s:24:"Front Page Services (S4)";}s:8:"db_table";s:13:"views_display";s:3:"vid";i:0;s:2:"id";s:8:"front_s4";s:13:"display_title";s:24:"Front Page Services (S4)";s:14:"display_plugin";s:5:"block";s:8:"position";i:0;}'); /* WAS: '' */
  }
  if (isset($data['taxonomy_term'])) {
    $data['taxonomy_term']->display['default']->display_options['arguments']['term_node_tid_depth_modifier']['exception']['title_enable'] = TRUE; /* WAS: 1 */
    $data['taxonomy_term']->display['default']->display_options['arguments']['term_node_tid_depth_modifier']['specify_validation'] = TRUE; /* WAS: 1 */
    $data['taxonomy_term']->display['default']->display_options['arguments']['term_node_tid_depth']['break_phrase'] = TRUE; /* WAS: 1 */
    $data['taxonomy_term']->display['default']->display_options['arguments']['term_node_tid_depth']['exception']['title_enable'] = TRUE; /* WAS: 1 */
    $data['taxonomy_term']->display['default']->display_options['arguments']['term_node_tid_depth']['specify_validation'] = TRUE; /* WAS: 1 */
    $data['taxonomy_term']->display['default']->display_options['arguments']['term_node_tid_depth']['title_enable'] = TRUE; /* WAS: 1 */
    $data['taxonomy_term']->display['default']->display_options['use_more_always'] = FALSE; /* WAS: '' */
    unset($data['taxonomy_term']->display['default']->display_options['access']['perm']);
  }
  if (isset($data['webform_submissions'])) {
    unset($data['webform_submissions']->display['default']->display_options['fields']['delete_submission']['label']);
    unset($data['webform_submissions']->display['default']->display_options['fields']['edit_submission']['label']);
  }
  if (isset($data['weight'])) {
    $data['weight']->display['default']->display_options['fields']['title']['alter']['ellipsis'] = FALSE; /* WAS: 0 */
    $data['weight']->display['default']->display_options['fields']['title']['alter']['word_boundary'] = FALSE; /* WAS: 0 */
    $data['weight']->display['default']->display_options['use_more_always'] = FALSE; /* WAS: '' */
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
    unset($data['weight']->display['default']->display_options['style_options']['empty_table']);
    unset($data['weight']->display['default']->display_options['style_options']['override']);
    unset($data['weight']->display['default']->display_options['style_options']['sticky']);
  }
}
