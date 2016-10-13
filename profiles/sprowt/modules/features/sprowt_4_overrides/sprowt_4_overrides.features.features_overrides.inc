<?php
/**
 * @file
 * sprowt_4_overrides.features.features_overrides.inc
 */

/**
 * Implements hook_features_override_default_overrides().
 */
function sprowt_4_overrides_features_override_default_overrides() {
  // This code is only used for UI in features. Exported alters hooks do the magic.
  $overrides = array();

  // Exported overrides for: fe_block_settings
  $overrides["fe_block_settings.addtoany-addtoany_button.themes|sprowt_1"]["DELETED"] = TRUE;
  $overrides["fe_block_settings.addtoany-addtoany_button.themes|sprowt_4"] = array(
    'region' => '',
    'status' => 0,
    'theme' => 'sprowt_4',
    'weight' => -37,
  );
  $overrides["fe_block_settings.flippy-flippy_pager-node_type-profile.themes|sprowt_1"]["DELETED"] = TRUE;
  $overrides["fe_block_settings.flippy-flippy_pager-node_type-profile.themes|sprowt_4"] = array(
    'region' => '',
    'status' => 0,
    'theme' => 'sprowt_4',
    'weight' => 0,
  );
  $overrides["fe_block_settings.flippy-flippy_pager.themes|sprowt_1"]["DELETED"] = TRUE;
  $overrides["fe_block_settings.flippy-flippy_pager.themes|sprowt_4"] = array(
    'region' => '',
    'status' => 0,
    'theme' => 'sprowt_4',
    'weight' => -29,
  );

  // Exported overrides for: flexslider_optionset
  $overrides["flexslider_optionset.default.export_type"]["DELETED"] = TRUE;
  $overrides["flexslider_optionset.default.type"]["DELETED"] = TRUE;

  // Exported overrides for: image
  $overrides["image.flexslider_full.label"] = 'flexslider_full';
  $overrides["image.flexslider_thumbnail.label"] = 'flexslider_thumbnail';
  $overrides["image.menu_icon.label"] = 'menu_icon';

  // Exported overrides for: variable
  $overrides["variable.menu_main_links_source.menu_main_links_source"]["DELETED"] = TRUE;
  $overrides["variable.menu_masks.value|1"] = 253;
  $overrides["variable.menu_masks.value|26"] = 24;
  $overrides["variable.menu_masks.value|27"] = 23;
  $overrides["variable.menu_masks.value|4"] = 126;
  $overrides["variable.menu_secondary_links_source.menu_secondary_links_source"]["DELETED"] = TRUE;
  $overrides["variable.menu_target_enabled.menu_target_enabled"]["DELETED"] = TRUE;
  $overrides["variable.menu_target_type.menu_target_type"]["DELETED"] = TRUE;
  $overrides["variable.weight_menu_affiliation.weight_menu_affiliation"]["DELETED"] = TRUE;
  $overrides["variable.weight_menu_benefit.weight_menu_benefit"]["DELETED"] = TRUE;
  $overrides["variable.weight_menu_blog.weight_menu_blog"]["DELETED"] = TRUE;
  $overrides["variable.weight_menu_cta.weight_menu_cta"]["DELETED"] = TRUE;
  $overrides["variable.weight_menu_faq.weight_menu_faq"]["DELETED"] = TRUE;
  $overrides["variable.weight_menu_gallery_image.weight_menu_gallery_image"]["DELETED"] = TRUE;
  $overrides["variable.weight_menu_landing_page.weight_menu_landing_page"]["DELETED"] = TRUE;
  $overrides["variable.weight_menu_localtarget.weight_menu_localtarget"]["DELETED"] = TRUE;
  $overrides["variable.weight_menu_location.weight_menu_location"]["DELETED"] = TRUE;
  $overrides["variable.weight_menu_market.weight_menu_market"]["DELETED"] = TRUE;
  $overrides["variable.weight_menu_package.weight_menu_package"]["DELETED"] = TRUE;
  $overrides["variable.weight_menu_page.weight_menu_page"]["DELETED"] = TRUE;
  $overrides["variable.weight_menu_region.weight_menu_region"]["DELETED"] = TRUE;
  $overrides["variable.weight_menu_service.weight_menu_service"]["DELETED"] = TRUE;
  $overrides["variable.weight_menu_slide.weight_menu_slide"]["DELETED"] = TRUE;
  $overrides["variable.weight_menu_special_offer.weight_menu_special_offer"]["DELETED"] = TRUE;
  $overrides["variable.weight_menu_testimonial.weight_menu_testimonial"]["DELETED"] = TRUE;
  $overrides["variable.weight_menu_webform.weight_menu_webform"]["DELETED"] = TRUE;

  // Exported overrides for: views_view
  $overrides["views_view.archive.display|block|display_options|arguments|created_year_month|exception|title_enable"] = TRUE;
  $overrides["views_view.archive.display|block|display_options|arguments|created_year_month|specify_validation"] = TRUE;
  $overrides["views_view.archive.display|block|display_options|arguments|created_year_month|title_enable"] = TRUE;
  $overrides["views_view.archive.display|default|display_options|access|perm"]["DELETED"] = TRUE;
  $overrides["views_view.archive.display|default|display_options|arguments|created_year_month|exception|title_enable"] = TRUE;
  $overrides["views_view.archive.display|default|display_options|arguments|created_year_month|specify_validation"] = TRUE;
  $overrides["views_view.archive.display|default|display_options|arguments|created_year_month|title_enable"] = TRUE;
  $overrides["views_view.archive.display|default|display_options|use_more_always"] = FALSE;
  $overrides["views_view.backlinks.display|block|display_options|arguments|nid|specify_validation"] = TRUE;
  $overrides["views_view.backlinks.display|block|display_options|arguments|nid|title_enable"] = TRUE;
  $overrides["views_view.backlinks.display|default|display_options|access|perm"]["DELETED"] = TRUE;
  $overrides["views_view.backlinks.display|default|display_options|arguments|nid|specify_validation"] = TRUE;
  $overrides["views_view.backlinks.display|default|display_options|arguments|nid|title_enable"] = TRUE;
  $overrides["views_view.backlinks.display|default|display_options|empty|text|empty"]["DELETED"] = TRUE;
  $overrides["views_view.backlinks.display|default|display_options|fields|title|link_to_node"]["DELETED"] = TRUE;
  $overrides["views_view.backlinks.display|default|display_options|use_more_always"] = FALSE;
  $overrides["views_view.frontpage.display|default|display_options|access|perm"]["DELETED"] = TRUE;
  $overrides["views_view.frontpage.display|default|display_options|row_options"]["DELETED"] = TRUE;
  $overrides["views_view.frontpage.display|default|display_options|use_more_always"] = FALSE;
  $overrides["views_view.glossary.display|attachment|display_options|arguments|title|exception|title_enable"] = TRUE;
  $overrides["views_view.glossary.display|attachment|display_options|arguments|title|glossary"] = TRUE;
  $overrides["views_view.glossary.display|attachment|display_options|arguments|title|specify_validation"] = TRUE;
  $overrides["views_view.glossary.display|attachment|display_options|arguments|title|summary_options|inline"] = TRUE;
  $overrides["views_view.glossary.display|attachment|display_options|arguments|title|transform_dash"]["DELETED"] = TRUE;
  $overrides["views_view.glossary.display|attachment|display_options|inherit_arguments"] = FALSE;
  $overrides["views_view.glossary.display|default|display_options|access|perm"]["DELETED"] = TRUE;
  $overrides["views_view.glossary.display|default|display_options|arguments|title|exception|title_enable"] = TRUE;
  $overrides["views_view.glossary.display|default|display_options|arguments|title|glossary"] = TRUE;
  $overrides["views_view.glossary.display|default|display_options|arguments|title|specify_validation"] = TRUE;
  $overrides["views_view.glossary.display|default|display_options|arguments|title|transform_dash"]["DELETED"] = TRUE;
  $overrides["views_view.glossary.display|default|display_options|fields|name|link_to_user"]["DELETED"] = TRUE;
  $overrides["views_view.glossary.display|default|display_options|fields|title|link_to_node"]["DELETED"] = TRUE;
  $overrides["views_view.glossary.display|default|display_options|style_options|override"]["DELETED"] = TRUE;
  $overrides["views_view.glossary.display|default|display_options|style_options|sticky"]["DELETED"] = TRUE;
  $overrides["views_view.glossary.display|default|display_options|use_more_always"] = FALSE;
  $overrides["views_view.services.display|front_s4"] = unserialize('O:13:"views_display":7:{s:15:"display_options";a:6:{s:5:"query";a:2:{s:4:"type";s:11:"views_query";s:7:"options";a:0:{}}s:8:"defaults";a:4:{s:12:"style_plugin";b:0;s:13:"style_options";b:0;s:10:"row_plugin";b:0;s:11:"row_options";b:0;}s:12:"style_plugin";s:7:"default";s:10:"row_plugin";s:4:"node";s:11:"row_options";a:1:{s:9:"view_mode";s:10:"alt_teaser";}s:17:"block_description";s:24:"Front Page Services (S4)";}s:8:"db_table";s:13:"views_display";s:3:"vid";i:0;s:2:"id";s:8:"front_s4";s:13:"display_title";s:24:"Front Page Services (S4)";s:14:"display_plugin";s:5:"block";s:8:"position";i:0;}');
  $overrides["views_view.taxonomy_term.display|default|display_options|access|perm"]["DELETED"] = TRUE;
  $overrides["views_view.taxonomy_term.display|default|display_options|arguments|term_node_tid_depth_modifier|exception|title_enable"] = TRUE;
  $overrides["views_view.taxonomy_term.display|default|display_options|arguments|term_node_tid_depth_modifier|specify_validation"] = TRUE;
  $overrides["views_view.taxonomy_term.display|default|display_options|arguments|term_node_tid_depth|break_phrase"] = TRUE;
  $overrides["views_view.taxonomy_term.display|default|display_options|arguments|term_node_tid_depth|exception|title_enable"] = TRUE;
  $overrides["views_view.taxonomy_term.display|default|display_options|arguments|term_node_tid_depth|specify_validation"] = TRUE;
  $overrides["views_view.taxonomy_term.display|default|display_options|arguments|term_node_tid_depth|title_enable"] = TRUE;
  $overrides["views_view.taxonomy_term.display|default|display_options|use_more_always"] = FALSE;
  $overrides["views_view.webform_submissions.display|default|display_options|fields|delete_submission|label"]["DELETED"] = TRUE;
  $overrides["views_view.webform_submissions.display|default|display_options|fields|edit_submission|label"]["DELETED"] = TRUE;
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
  $overrides["views_view.weight.display|default|display_options|style_options|empty_table"]["DELETED"] = TRUE;
  $overrides["views_view.weight.display|default|display_options|style_options|override"]["DELETED"] = TRUE;
  $overrides["views_view.weight.display|default|display_options|style_options|sticky"]["DELETED"] = TRUE;
  $overrides["views_view.weight.display|default|display_options|use_more_always"] = FALSE;

 return $overrides;
}
