<?php
/**
 * @file
 * sprowt_2.features.inc
 */

/**
 * Implements hook_default_fe_block_settings_alter().
 */
function sprowt_2_default_fe_block_settings_alter(&$data) {
  if (isset($data['addtoany-addtoany_button'])) {
    $data['addtoany-addtoany_button']['themes']['adminimal']['weight'] = -37; /* WAS: 0 */
  }
  if (isset($data['flippy-flippy_pager-node_type-profile'])) {
    $data['flippy-flippy_pager-node_type-profile']['themes']['sprowt_2'] = array(
      'region' => '',
      'status' => 0,
      'theme' => 'sprowt_2',
      'weight' => 0,
    ); /* WAS: '' */
    unset($data['flippy-flippy_pager-node_type-profile']['themes']['sprowt_1']);
  }
  if (isset($data['flippy-flippy_pager'])) {
    $data['flippy-flippy_pager']['themes']['sprowt_2'] = array(
      'region' => '',
      'status' => 0,
      'theme' => 'sprowt_2',
      'weight' => -29,
    ); /* WAS: '' */
    unset($data['flippy-flippy_pager']['themes']['sprowt_1']);
  }
}

/**
 * Implements hook_field_default_field_instances_alter().
 */
function sprowt_2_field_default_field_instances_alter(&$data) {
  if (isset($data['node-benefit-field_image'])) {
    $data['node-benefit-field_image']['display']['teaser']['settings']['image_style'] = 'focal_point_scale_and_crop_100x100'; /* WAS: 'benefits__front_page_' */
  }
  if (isset($data['node-service-body'])) {
    $data['node-service-body']['display']['alt_teaser']['label'] = 'hidden'; /* WAS: 'above' */
    $data['node-service-body']['display']['alt_teaser']['module'] = 'smart_trim'; /* WAS: '' */
    $data['node-service-body']['display']['alt_teaser']['settings']['more_link'] = 1; /* WAS: '' */
    $data['node-service-body']['display']['alt_teaser']['settings']['more_text'] = 'Learn More'; /* WAS: '' */
    $data['node-service-body']['display']['alt_teaser']['settings']['summary_handler'] = 'trim'; /* WAS: '' */
    $data['node-service-body']['display']['alt_teaser']['settings']['trim_length'] = 150; /* WAS: '' */
    $data['node-service-body']['display']['alt_teaser']['settings']['trim_link'] = 0; /* WAS: '' */
    $data['node-service-body']['display']['alt_teaser']['settings']['trim_options'] = array(
      'text' => 0,
    ); /* WAS: '' */
    $data['node-service-body']['display']['alt_teaser']['settings']['trim_preserve_tags'] = ''; /* WAS: '' */
    $data['node-service-body']['display']['alt_teaser']['settings']['trim_suffix'] = '...'; /* WAS: '' */
    $data['node-service-body']['display']['alt_teaser']['settings']['trim_type'] = 'chars'; /* WAS: '' */
    $data['node-service-body']['display']['alt_teaser']['type'] = 'smart_trim_format'; /* WAS: 'hidden' */
    $data['node-service-body']['display']['alt_teaser']['weight'] = 1; /* WAS: 0 */
    $data['node-service-body']['display']['teaser']['settings']['summary_handler'] = 'trim'; /* WAS: 'full' */
  }
  if (isset($data['node-service-field_call_out'])) {
    $data['node-service-field_call_out']['display']['alt_teaser']['weight'] = 7; /* WAS: 0 */
  }
  if (isset($data['node-service-field_content_edited'])) {
    $data['node-service-field_content_edited']['display']['alt_teaser']['weight'] = 8; /* WAS: 0 */
  }
  if (isset($data['node-service-field_display_title'])) {
    $data['node-service-field_display_title']['display']['alt_teaser']['weight'] = 9; /* WAS: 0 */
  }
  if (isset($data['node-service-field_icon'])) {
    $data['node-service-field_icon']['display']['alt_teaser']['weight'] = 6; /* WAS: 0 */
  }
  if (isset($data['node-service-field_image'])) {
    $data['node-service-field_image']['display']['alt_teaser']['label'] = 'hidden'; /* WAS: 'above' */
    $data['node-service-field_image']['display']['alt_teaser']['module'] = 'image'; /* WAS: '' */
    $data['node-service-field_image']['display']['alt_teaser']['settings']['image_link'] = ''; /* WAS: '' */
    $data['node-service-field_image']['display']['alt_teaser']['settings']['image_style'] = 'focal_point_scale_and_crop_470x400'; /* WAS: '' */
    $data['node-service-field_image']['display']['alt_teaser']['type'] = 'image'; /* WAS: 'hidden' */
  }
  if (isset($data['node-service-field_intro'])) {
    $data['node-service-field_intro']['display']['alt_teaser']['weight'] = 2; /* WAS: 0 */
  }
  if (isset($data['node-service-field_package_intro'])) {
    $data['node-service-field_package_intro']['display']['alt_teaser']['weight'] = 3; /* WAS: 0 */
  }
  if (isset($data['node-service-field_seo_title'])) {
    $data['node-service-field_seo_title']['display']['alt_teaser']['weight'] = 4; /* WAS: 0 */
  }
  if (isset($data['node-service-field_service'])) {
    $data['node-service-field_service']['display']['alt_teaser']['weight'] = 5; /* WAS: 0 */
  }
  if (isset($data['node-special_offer-body'])) {
    $data['node-special_offer-body']['display']['alt_teaser']['weight'] = 0; /* WAS: 1 */
  }
  if (isset($data['node-special_offer-field_button'])) {
    $data['node-special_offer-field_button']['display']['alt_teaser']['label'] = 'hidden'; /* WAS: 'above' */
    $data['node-special_offer-field_button']['display']['alt_teaser']['module'] = 'link'; /* WAS: '' */
    $data['node-special_offer-field_button']['display']['alt_teaser']['type'] = 'link_default'; /* WAS: 'hidden' */
    $data['node-special_offer-field_button']['display']['alt_teaser']['weight'] = 1; /* WAS: 0 */
  }
  if (isset($data['node-special_offer-field_content_edited'])) {
    $data['node-special_offer-field_content_edited']['display']['alt_teaser']['weight'] = 4; /* WAS: 0 */
  }
  if (isset($data['node-special_offer-field_expiration_date'])) {
    $data['node-special_offer-field_expiration_date']['display']['alt_teaser']['type'] = 'hidden'; /* WAS: 'date_default' */
    unset($data['node-special_offer-field_expiration_date']['display']['alt_teaser']['module']);
    unset($data['node-special_offer-field_expiration_date']['display']['alt_teaser']['settings']['format_type']);
    unset($data['node-special_offer-field_expiration_date']['display']['alt_teaser']['settings']['fromto']);
    unset($data['node-special_offer-field_expiration_date']['display']['alt_teaser']['settings']['multiple_from']);
    unset($data['node-special_offer-field_expiration_date']['display']['alt_teaser']['settings']['multiple_number']);
    unset($data['node-special_offer-field_expiration_date']['display']['alt_teaser']['settings']['multiple_to']);
    unset($data['node-special_offer-field_expiration_date']['display']['alt_teaser']['settings']['show_remaining_days']);
  }
  if (isset($data['node-special_offer-field_image'])) {
    $data['node-special_offer-field_image']['display']['alt_teaser']['type'] = 'hidden'; /* WAS: 'image' */
    $data['node-special_offer-field_image']['display']['alt_teaser']['weight'] = 3; /* WAS: 0 */
    unset($data['node-special_offer-field_image']['display']['alt_teaser']['module']);
    unset($data['node-special_offer-field_image']['display']['alt_teaser']['settings']['image_link']);
    unset($data['node-special_offer-field_image']['display']['alt_teaser']['settings']['image_style']);
  }
  if (isset($data['node-special_offer-field_offer_price'])) {
    $data['node-special_offer-field_offer_price']['display']['alt_teaser']['weight'] = 7; /* WAS: 4 */
  }
  if (isset($data['node-special_offer-field_original_price'])) {
    $data['node-special_offer-field_original_price']['display']['alt_teaser']['weight'] = 6; /* WAS: 3 */
  }
  if (isset($data['node-special_offer-field_package'])) {
    $data['node-special_offer-field_package']['display']['alt_teaser']['weight'] = 8; /* WAS: 5 */
  }
  if (isset($data['node-special_offer-field_services'])) {
    $data['node-special_offer-field_services']['display']['alt_teaser']['weight'] = 5; /* WAS: 0 */
  }
}

/**
 * Implements hook_flexslider_default_presets_alter().
 */
function sprowt_2_flexslider_default_presets_alter(&$data) {
  if (isset($data['default'])) {
    unset($data['default']->export_type);
    unset($data['default']->type);
  }
}

/**
 * Implements hook_image_styles_alter().
 */
function sprowt_2_image_styles_alter(&$data) {
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
function sprowt_2_strongarm_alter(&$data) {
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
  if (isset($data['weight_menu_profile'])) {
    unset($data['weight_menu_profile']);
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
function sprowt_2_views_default_views_alter(&$data) {
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
    $data['services']->display['homepage'] = unserialize('O:13:"views_display":7:{s:15:"display_options";a:6:{s:5:"query";a:2:{s:4:"type";s:11:"views_query";s:7:"options";a:0:{}}s:8:"defaults";a:4:{s:12:"style_plugin";b:0;s:13:"style_options";b:0;s:10:"row_plugin";b:0;s:11:"row_options";b:0;}s:12:"style_plugin";s:7:"default";s:10:"row_plugin";s:4:"node";s:11:"row_options";a:1:{s:9:"view_mode";s:10:"alt_teaser";}s:17:"block_description";s:22:"Homepage Services list";}s:8:"db_table";s:13:"views_display";s:3:"vid";i:0;s:2:"id";s:8:"homepage";s:13:"display_title";s:8:"Homepage";s:14:"display_plugin";s:5:"block";s:8:"position";i:0;}'); /* WAS: '' */
  }
  if (isset($data['special_offers'])) {
    $data['special_offers']->display['front']->display_options['defaults']['row_options'] = FALSE; /* WAS: '' */
    $data['special_offers']->display['front']->display_options['defaults']['row_plugin'] = FALSE; /* WAS: '' */
    $data['special_offers']->display['front']->display_options['defaults']['style_options'] = FALSE; /* WAS: '' */
    $data['special_offers']->display['front']->display_options['defaults']['style_plugin'] = FALSE; /* WAS: '' */
    $data['special_offers']->display['front']->display_options['pager']['options']['items_per_page'] = 0; /* WAS: 2 */
    $data['special_offers']->display['front']->display_options['row_options'] = array(
      'view_mode' => 'alt_teaser',
      'links' => FALSE,
    ); /* WAS: '' */
    $data['special_offers']->display['front']->display_options['row_plugin'] = 'node'; /* WAS: '' */
    $data['special_offers']->display['front']->display_options['style_options'] = array(
      'optionset' => 'special_offers_slideshow',
    ); /* WAS: '' */
    $data['special_offers']->display['front']->display_options['style_plugin'] = 'flexslider'; /* WAS: '' */
    $data['special_offers']->display['ltp_slideshow'] = unserialize('O:13:"views_display":7:{s:15:"display_options";a:9:{s:5:"query";a:2:{s:4:"type";s:11:"views_query";s:7:"options";a:0:{}}s:8:"defaults";a:8:{s:5:"title";b:0;s:5:"pager";b:0;s:12:"style_plugin";b:0;s:13:"style_options";b:0;s:10:"row_plugin";b:0;s:11:"row_options";b:0;s:5:"sorts";b:0;s:9:"arguments";b:0;}s:5:"pager";a:2:{s:4:"type";s:4:"none";s:7:"options";a:1:{s:6:"offset";s:1:"0";}}s:12:"style_plugin";s:10:"flexslider";s:13:"style_options";a:1:{s:9:"optionset";s:24:"special_offers_slideshow";}s:10:"row_plugin";s:4:"node";s:11:"row_options";a:2:{s:9:"view_mode";s:10:"alt_teaser";s:5:"links";b:0;}s:5:"sorts";a:1:{s:6:"random";a:3:{s:2:"id";s:6:"random";s:5:"table";s:5:"views";s:5:"field";s:6:"random";}}s:9:"arguments";a:2:{s:3:"tid";a:8:{s:2:"id";s:3:"tid";s:5:"table";s:14:"taxonomy_index";s:5:"field";s:3:"tid";s:14:"default_action";s:7:"default";s:21:"default_argument_type";s:12:"taxonomy_tid";s:24:"default_argument_options";a:4:{s:4:"node";b:1;s:6:"anyall";s:1:"+";s:5:"limit";b:1;s:12:"vocabularies";a:1:{s:8:"services";s:8:"services";}}s:7:"summary";a:2:{s:17:"number_of_records";s:1:"0";s:6:"format";s:15:"default_summary";}s:15:"summary_options";a:1:{s:14:"items_per_page";s:2:"25";}}s:3:"nid";a:8:{s:2:"id";s:3:"nid";s:5:"table";s:4:"node";s:5:"field";s:3:"nid";s:14:"default_action";s:7:"default";s:21:"default_argument_type";s:4:"node";s:7:"summary";a:2:{s:17:"number_of_records";s:1:"0";s:6:"format";s:15:"default_summary";}s:15:"summary_options";a:1:{s:14:"items_per_page";s:2:"25";}s:3:"not";b:1;}}}s:8:"db_table";s:13:"views_display";s:3:"vid";i:0;s:2:"id";s:13:"ltp_slideshow";s:13:"display_title";s:17:"Related Slideshow";s:14:"display_plugin";s:5:"block";s:8:"position";i:0;}'); /* WAS: '' */
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
