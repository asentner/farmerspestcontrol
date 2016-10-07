<?php
/**
 * @file
 * sprowt_3_overrides.features.features_overrides.inc
 */

/**
 * Implements hook_features_override_default_overrides().
 */
function sprowt_3_features_override_default_overrides() {
  // This code is only used for UI in features. Exported alters hooks do the magic.
  $overrides = array();

  // Exported overrides for: fe_block_settings
  $overrides["fe_block_settings.addtoany-addtoany_button.themes|adminimal|weight"] = -37;
  $overrides["fe_block_settings.addtoany-addtoany_button.themes|sprowt_1"]["DELETED"] = TRUE;
  $overrides["fe_block_settings.addtoany-addtoany_button.themes|sprowt_3"] = array(
    'region' => '',
    'status' => 0,
    'theme' => 'sprowt_3',
    'weight' => -41,
  );
  $overrides["fe_block_settings.flippy-flippy_pager-node_type-profile.themes|sprowt_1"]["DELETED"] = TRUE;
  $overrides["fe_block_settings.flippy-flippy_pager-node_type-profile.themes|sprowt_3"] = array(
    'region' => '',
    'status' => 0,
    'theme' => 'sprowt_3',
    'weight' => 0,
  );
  $overrides["fe_block_settings.flippy-flippy_pager.themes|sprowt_1"]["DELETED"] = TRUE;
  $overrides["fe_block_settings.flippy-flippy_pager.themes|sprowt_3"] = array(
    'region' => '',
    'status' => 0,
    'theme' => 'sprowt_3',
    'weight' => -32,
  );

  // Exported overrides for: field_instance
  $overrides["field_instance.node-benefit-field_image.display|teaser|settings|image_style"] = 'sprowt_3_icon';
  $overrides["field_instance.node-benefit-field_image.settings|default_image"] = 3;
  $overrides["field_instance.node-profile-field_image.display|default|settings|image_style"] = 'profile';
  $overrides["field_instance.node-service-body.display|alt_teaser|label"] = 'hidden';
  $overrides["field_instance.node-service-body.display|alt_teaser|module"] = 'smart_trim';
  $overrides["field_instance.node-service-body.display|alt_teaser|settings|more_link"] = 0;
  $overrides["field_instance.node-service-body.display|alt_teaser|settings|more_text"] = 'Read more';
  $overrides["field_instance.node-service-body.display|alt_teaser|settings|summary_handler"] = 'trim';
  $overrides["field_instance.node-service-body.display|alt_teaser|settings|trim_length"] = 75;
  $overrides["field_instance.node-service-body.display|alt_teaser|settings|trim_link"] = 0;
  $overrides["field_instance.node-service-body.display|alt_teaser|settings|trim_options"] = array(
    'text' => 0,
  );
  $overrides["field_instance.node-service-body.display|alt_teaser|settings|trim_preserve_tags"] = '';
  $overrides["field_instance.node-service-body.display|alt_teaser|settings|trim_suffix"] = '...';
  $overrides["field_instance.node-service-body.display|alt_teaser|settings|trim_type"] = 'chars';
  $overrides["field_instance.node-service-body.display|alt_teaser|type"] = 'smart_trim_format';
  $overrides["field_instance.node-service-body.display|alt_teaser|weight"] = 1;
  $overrides["field_instance.node-service-field_call_out.display|alt_teaser|weight"] = 7;
  $overrides["field_instance.node-service-field_call_out.display|teaser|weight"] = 4;
  $overrides["field_instance.node-service-field_content_edited.display|alt_teaser|weight"] = 8;
  $overrides["field_instance.node-service-field_content_edited.display|teaser|weight"] = 5;
  $overrides["field_instance.node-service-field_display_title.display|alt_teaser|weight"] = 9;
  $overrides["field_instance.node-service-field_display_title.display|teaser|weight"] = 9;
  $overrides["field_instance.node-service-field_icon.display|alt_teaser|label"] = 'hidden';
  $overrides["field_instance.node-service-field_icon.display|alt_teaser|module"] = 'image_link_formatter';
  $overrides["field_instance.node-service-field_icon.display|alt_teaser|settings|image_link"] = 'content';
  $overrides["field_instance.node-service-field_icon.display|alt_teaser|settings|image_style"] = 'scale_60x60';
  $overrides["field_instance.node-service-field_icon.display|alt_teaser|type"] = 'image_link_formatter';
  $overrides["field_instance.node-service-field_icon.display|teaser|label"] = 'hidden';
  $overrides["field_instance.node-service-field_icon.display|teaser|weight"] = 2;
  $overrides["field_instance.node-service-field_icon.settings|default_image"] = 3;
  $overrides["field_instance.node-service-field_image.display|alt_teaser|weight"] = 6;
  $overrides["field_instance.node-service-field_image.display|teaser|module"] = 'image_link_formatter';
  $overrides["field_instance.node-service-field_image.display|teaser|type"] = 'image_link_formatter';
  $overrides["field_instance.node-service-field_image.settings|default_image"] = 5;
  $overrides["field_instance.node-service-field_intro.display|alt_teaser|weight"] = 2;
  $overrides["field_instance.node-service-field_intro.display|teaser|weight"] = 6;
  $overrides["field_instance.node-service-field_package_intro.display|alt_teaser|weight"] = 3;
  $overrides["field_instance.node-service-field_package_intro.display|teaser|weight"] = 3;
  $overrides["field_instance.node-service-field_seo_title.display|alt_teaser|weight"] = 4;
  $overrides["field_instance.node-service-field_seo_title.display|teaser|weight"] = 8;
  $overrides["field_instance.node-service-field_service.display|alt_teaser|weight"] = 5;
  $overrides["field_instance.node-service-field_service.display|teaser|weight"] = 7;
  $overrides["field_instance.node-special_offer-field_button.display|alt_teaser|label"] = 'hidden';
  $overrides["field_instance.node-special_offer-field_button.display|alt_teaser|module"] = 'link';
  $overrides["field_instance.node-special_offer-field_button.display|alt_teaser|type"] = 'link_default';
  $overrides["field_instance.node-special_offer-field_button.display|alt_teaser|weight"] = 2;
  $overrides["field_instance.node-special_offer-field_content_edited.display|alt_teaser|weight"] = 4;
  $overrides["field_instance.node-special_offer-field_expiration_date.display|alt_teaser|module"]["DELETED"] = TRUE;
  $overrides["field_instance.node-special_offer-field_expiration_date.display|alt_teaser|settings|format_type"]["DELETED"] = TRUE;
  $overrides["field_instance.node-special_offer-field_expiration_date.display|alt_teaser|settings|fromto"]["DELETED"] = TRUE;
  $overrides["field_instance.node-special_offer-field_expiration_date.display|alt_teaser|settings|multiple_from"]["DELETED"] = TRUE;
  $overrides["field_instance.node-special_offer-field_expiration_date.display|alt_teaser|settings|multiple_number"]["DELETED"] = TRUE;
  $overrides["field_instance.node-special_offer-field_expiration_date.display|alt_teaser|settings|multiple_to"]["DELETED"] = TRUE;
  $overrides["field_instance.node-special_offer-field_expiration_date.display|alt_teaser|settings|show_remaining_days"]["DELETED"] = TRUE;
  $overrides["field_instance.node-special_offer-field_expiration_date.display|alt_teaser|type"] = 'hidden';
  $overrides["field_instance.node-special_offer-field_expiration_date.display|alt_teaser|weight"] = 3;
  $overrides["field_instance.node-special_offer-field_image.display|alt_teaser|settings|image_style"] = 'focal_point_scale_and_crop_250x250';
  $overrides["field_instance.node-special_offer-field_image.display|teaser|settings|image_link"] = 'field_button';
  $overrides["field_instance.node-special_offer-field_offer_price.display|alt_teaser|weight"] = 7;
  $overrides["field_instance.node-special_offer-field_original_price.display|alt_teaser|weight"] = 6;
  $overrides["field_instance.node-special_offer-field_package.display|alt_teaser|weight"] = 8;
  $overrides["field_instance.node-special_offer-field_services.display|alt_teaser|weight"] = 5;

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
  $overrides["variable.weight_menu_profile.weight_menu_profile"]["DELETED"] = TRUE;
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
  $overrides["views_view.services.display|homepage"] = unserialize('O:13:"views_display":7:{s:15:"display_options";a:6:{s:5:"query";a:2:{s:4:"type";s:11:"views_query";s:7:"options";a:0:{}}s:8:"defaults";a:4:{s:12:"style_plugin";b:0;s:13:"style_options";b:0;s:10:"row_plugin";b:0;s:11:"row_options";b:0;}s:12:"style_plugin";s:7:"default";s:10:"row_plugin";s:4:"node";s:11:"row_options";a:1:{s:9:"view_mode";s:10:"alt_teaser";}s:17:"block_description";s:22:"Homepage Services list";}s:8:"db_table";s:13:"views_display";s:3:"vid";i:0;s:2:"id";s:8:"homepage";s:13:"display_title";s:8:"Homepage";s:14:"display_plugin";s:5:"block";s:8:"position";i:0;}');
  $overrides["views_view.special_offers.display|front_slideshow|display_options|pager|options|items_per_page"]["DELETED"] = TRUE;
  $overrides["views_view.special_offers.display|front_slideshow|display_options|pager|type"] = 'none';
  $overrides["views_view.special_offers.display|ltp_slideshow"] = unserialize('O:13:"views_display":7:{s:15:"display_options";a:10:{s:5:"query";a:2:{s:4:"type";s:11:"views_query";s:7:"options";a:0:{}}s:8:"defaults";a:8:{s:5:"title";b:0;s:5:"pager";b:0;s:12:"style_plugin";b:0;s:13:"style_options";b:0;s:10:"row_plugin";b:0;s:11:"row_options";b:0;s:5:"sorts";b:0;s:9:"arguments";b:0;}s:5:"title";s:4:"none";s:5:"pager";a:2:{s:4:"type";s:4:"none";s:7:"options";a:1:{s:6:"offset";s:1:"0";}}s:12:"style_plugin";s:10:"flexslider";s:13:"style_options";a:1:{s:9:"optionset";s:24:"special_offers_slideshow";}s:10:"row_plugin";s:4:"node";s:11:"row_options";a:2:{s:9:"view_mode";s:10:"alt_teaser";s:5:"links";b:0;}s:5:"sorts";a:1:{s:6:"random";a:3:{s:2:"id";s:6:"random";s:5:"table";s:5:"views";s:5:"field";s:6:"random";}}s:9:"arguments";a:2:{s:3:"tid";a:8:{s:2:"id";s:3:"tid";s:5:"table";s:14:"taxonomy_index";s:5:"field";s:3:"tid";s:14:"default_action";s:7:"default";s:21:"default_argument_type";s:12:"taxonomy_tid";s:24:"default_argument_options";a:4:{s:4:"node";b:1;s:6:"anyall";s:1:"+";s:5:"limit";b:1;s:12:"vocabularies";a:1:{s:8:"services";s:8:"services";}}s:7:"summary";a:2:{s:17:"number_of_records";s:1:"0";s:6:"format";s:15:"default_summary";}s:15:"summary_options";a:1:{s:14:"items_per_page";s:2:"25";}}s:3:"nid";a:8:{s:2:"id";s:3:"nid";s:5:"table";s:4:"node";s:5:"field";s:3:"nid";s:14:"default_action";s:7:"default";s:21:"default_argument_type";s:4:"node";s:7:"summary";a:2:{s:17:"number_of_records";s:1:"0";s:6:"format";s:15:"default_summary";}s:15:"summary_options";a:1:{s:14:"items_per_page";s:2:"25";}s:3:"not";b:1;}}}s:8:"db_table";s:13:"views_display";s:3:"vid";i:0;s:2:"id";s:13:"ltp_slideshow";s:13:"display_title";s:17:"Related Slideshow";s:14:"display_plugin";s:5:"block";s:8:"position";i:0;}');
  $overrides["views_view.special_offers.display|related|display_options|title"] = 'none';
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
