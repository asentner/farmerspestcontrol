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

  // Exported overrides for: field_group
  $overrides["field_group.group_content|node|special_offer|form.data|children|10"] = 'title';
  $overrides["field_group.group_content|node|special_offer|form.data|children|11"] = 'field_offer_subheadline';
  $overrides["field_group.group_content|node|special_offer|form.data|children|2"] = 'field_content_edited';
  $overrides["field_group.group_content|node|special_offer|form.data|children|3"] = 'field_expiration_date';
  $overrides["field_group.group_content|node|special_offer|form.data|children|4"] = 'field_image';
  $overrides["field_group.group_content|node|special_offer|form.data|children|5"] = 'field_offer_price';
  $overrides["field_group.group_content|node|special_offer|form.data|children|6"] = 'field_original_price';
  $overrides["field_group.group_content|node|special_offer|form.data|children|7"] = 'field_package';
  $overrides["field_group.group_content|node|special_offer|form.data|children|8"] = 'field_services';
  $overrides["field_group.group_content|node|special_offer|form.data|children|9"] = 'field_offer_headline';

  // Exported overrides for: field_instance
  $overrides["field_instance.node-affiliation-body.display|secondary_teaser"] = array(
    'label' => 'above',
    'module' => 'text',
    'settings' => array(),
    'type' => 'text_default',
    'weight' => 1,
  );
  $overrides["field_instance.node-affiliation-field_content_edited.display|secondary_teaser"] = array(
    'label' => 'above',
    'settings' => array(),
    'type' => 'hidden',
    'weight' => 2,
  );
  $overrides["field_instance.node-affiliation-field_image.display|secondary_teaser"] = array(
    'label' => 'hidden',
    'module' => 'image_link_formatter',
    'settings' => array(
      'image_link' => 'field_link',
      'image_style' => '',
    ),
    'type' => 'image_link_formatter',
    'weight' => 0,
  );
  $overrides["field_instance.node-affiliation-field_link.display|secondary_teaser"] = array(
    'label' => 'hidden',
    'settings' => array(),
    'type' => 'hidden',
    'weight' => 3,
  );
  $overrides["field_instance.node-article-body.display|secondary_teaser"] = array(
    'label' => 'above',
    'settings' => array(),
    'type' => 'hidden',
    'weight' => 0,
  );
  $overrides["field_instance.node-article-field_image.display|secondary_teaser"] = array(
    'label' => 'above',
    'settings' => array(),
    'type' => 'hidden',
    'weight' => 0,
  );
  $overrides["field_instance.node-article-field_tags.display|secondary_teaser"] = array(
    'label' => 'above',
    'settings' => array(),
    'type' => 'hidden',
    'weight' => 0,
  );
  $overrides["field_instance.node-benefit-body.display|secondary_teaser"] = array(
    'label' => 'hidden',
    'settings' => array(),
    'type' => 'hidden',
    'weight' => 1,
  );
  $overrides["field_instance.node-benefit-field_content_edited.display|secondary_teaser"] = array(
    'label' => 'above',
    'settings' => array(),
    'type' => 'hidden',
    'weight' => 6,
  );
  $overrides["field_instance.node-benefit-field_display_title.display|secondary_teaser"] = array(
    'label' => 'above',
    'settings' => array(),
    'type' => 'hidden',
    'weight' => 5,
  );
  $overrides["field_instance.node-benefit-field_image.display|secondary_teaser"] = array(
    'label' => 'hidden',
    'module' => 'image_link_formatter',
    'settings' => array(
      'image_link' => 'field_link',
      'image_style' => 'benefits__front_page_',
    ),
    'type' => 'image_link_formatter',
    'weight' => 0,
  );
  $overrides["field_instance.node-benefit-field_image.settings|default_image"] = 3;
  $overrides["field_instance.node-benefit-field_link.display|secondary_teaser"] = array(
    'label' => 'hidden',
    'module' => 'link',
    'settings' => array(),
    'type' => 'link_plain',
    'weight' => 2,
  );
  $overrides["field_instance.node-benefit-field_market.display|secondary_teaser"] = array(
    'label' => 'above',
    'settings' => array(),
    'type' => 'hidden',
    'weight' => 4,
  );
  $overrides["field_instance.node-benefit-field_service.display|secondary_teaser"] = array(
    'label' => 'above',
    'settings' => array(),
    'type' => 'hidden',
    'weight' => 3,
  );
  $overrides["field_instance.node-blog-body.display|secondary_teaser"] = array(
    'label' => 'above',
    'settings' => array(),
    'type' => 'hidden',
    'weight' => 0,
  );
  $overrides["field_instance.node-blog-field_attachments.display|secondary_teaser"] = array(
    'label' => 'above',
    'settings' => array(),
    'type' => 'hidden',
    'weight' => 0,
  );
  $overrides["field_instance.node-blog-field_call_out.display|secondary_teaser"] = array(
    'label' => 'above',
    'settings' => array(),
    'type' => 'hidden',
    'weight' => 0,
  );
  $overrides["field_instance.node-blog-field_content_edited.display|secondary_teaser"] = array(
    'label' => 'above',
    'settings' => array(),
    'type' => 'hidden',
    'weight' => 0,
  );
  $overrides["field_instance.node-blog-field_image.display|secondary_teaser"] = array(
    'label' => 'above',
    'settings' => array(),
    'type' => 'hidden',
    'weight' => 0,
  );
  $overrides["field_instance.node-blog-field_market.display|secondary_teaser"] = array(
    'label' => 'above',
    'settings' => array(),
    'type' => 'hidden',
    'weight' => 0,
  );
  $overrides["field_instance.node-blog-field_service.display|secondary_teaser"] = array(
    'label' => 'above',
    'settings' => array(),
    'type' => 'hidden',
    'weight' => 0,
  );
  $overrides["field_instance.node-cta-body.display|secondary_teaser"] = array(
    'label' => 'above',
    'settings' => array(),
    'type' => 'hidden',
    'weight' => 0,
  );
  $overrides["field_instance.node-cta-field_content_edited.display|secondary_teaser"] = array(
    'label' => 'above',
    'settings' => array(),
    'type' => 'hidden',
    'weight' => 0,
  );
  $overrides["field_instance.node-faq-body.display|secondary_teaser"] = array(
    'label' => 'above',
    'settings' => array(),
    'type' => 'hidden',
    'weight' => 0,
  );
  $overrides["field_instance.node-faq-field_content_edited.display|secondary_teaser"] = array(
    'label' => 'above',
    'settings' => array(),
    'type' => 'hidden',
    'weight' => 0,
  );
  $overrides["field_instance.node-gallery_image-field_content_edited.display|secondary_teaser"] = array(
    'label' => 'above',
    'settings' => array(),
    'type' => 'hidden',
    'weight' => 0,
  );
  $overrides["field_instance.node-gallery_image-field_image.display|secondary_teaser"] = array(
    'label' => 'above',
    'settings' => array(),
    'type' => 'hidden',
    'weight' => 0,
  );
  $overrides["field_instance.node-gallery_image-field_project.display|secondary_teaser"] = array(
    'label' => 'above',
    'settings' => array(),
    'type' => 'hidden',
    'weight' => 0,
  );
  $overrides["field_instance.node-landing_page-body.display|secondary_teaser"] = array(
    'label' => 'above',
    'settings' => array(),
    'type' => 'hidden',
    'weight' => 0,
  );
  $overrides["field_instance.node-landing_page-field_call_out.display|secondary_teaser"] = array(
    'label' => 'above',
    'settings' => array(),
    'type' => 'hidden',
    'weight' => 0,
  );
  $overrides["field_instance.node-landing_page-field_content_edited.display|secondary_teaser"] = array(
    'label' => 'above',
    'settings' => array(),
    'type' => 'hidden',
    'weight' => 0,
  );
  $overrides["field_instance.node-landing_page-field_image.display|secondary_teaser"] = array(
    'label' => 'above',
    'settings' => array(),
    'type' => 'hidden',
    'weight' => 0,
  );
  $overrides["field_instance.node-landing_page-field_market.display|secondary_teaser"] = array(
    'label' => 'above',
    'settings' => array(),
    'type' => 'hidden',
    'weight' => 0,
  );
  $overrides["field_instance.node-landing_page-field_offer.display|secondary_teaser"] = array(
    'label' => 'above',
    'settings' => array(),
    'type' => 'hidden',
    'weight' => 0,
  );
  $overrides["field_instance.node-landing_page-field_phone_number.display|secondary_teaser"] = array(
    'label' => 'above',
    'settings' => array(),
    'type' => 'hidden',
    'weight' => 0,
  );
  $overrides["field_instance.node-landing_page-field_seo_title.display|secondary_teaser"] = array(
    'label' => 'above',
    'settings' => array(),
    'type' => 'hidden',
    'weight' => 0,
  );
  $overrides["field_instance.node-landing_page-field_service.display|secondary_teaser"] = array(
    'label' => 'above',
    'settings' => array(),
    'type' => 'hidden',
    'weight' => 0,
  );
  $overrides["field_instance.node-landing_page-field_service_description.display|secondary_teaser"] = array(
    'label' => 'above',
    'settings' => array(),
    'type' => 'hidden',
    'weight' => 0,
  );
  $overrides["field_instance.node-landing_page-field_special_offer.display|secondary_teaser"] = array(
    'label' => 'above',
    'settings' => array(),
    'type' => 'hidden',
    'weight' => 0,
  );
  $overrides["field_instance.node-landing_page-field_special_offer.display|sidebar|settings|use_content_language"] = TRUE;
  $overrides["field_instance.node-localtarget-body.display|secondary_teaser"] = array(
    'label' => 'above',
    'settings' => array(),
    'type' => 'hidden',
    'weight' => 0,
  );
  $overrides["field_instance.node-localtarget-field_call_out.display|secondary_teaser"] = array(
    'label' => 'above',
    'settings' => array(),
    'type' => 'hidden',
    'weight' => 0,
  );
  $overrides["field_instance.node-localtarget-field_content_edited.display|secondary_teaser"] = array(
    'label' => 'above',
    'settings' => array(),
    'type' => 'hidden',
    'weight' => 0,
  );
  $overrides["field_instance.node-localtarget-field_display_title.display|secondary_teaser"] = array(
    'label' => 'above',
    'settings' => array(),
    'type' => 'hidden',
    'weight' => 0,
  );
  $overrides["field_instance.node-localtarget-field_hero_image.display|secondary_teaser"] = array(
    'label' => 'above',
    'settings' => array(),
    'type' => 'hidden',
    'weight' => 0,
  );
  $overrides["field_instance.node-localtarget-field_image.display|secondary_teaser"] = array(
    'label' => 'above',
    'settings' => array(),
    'type' => 'hidden',
    'weight' => 0,
  );
  $overrides["field_instance.node-localtarget-field_intro.display|secondary_teaser"] = array(
    'label' => 'above',
    'settings' => array(),
    'type' => 'hidden',
    'weight' => 0,
  );
  $overrides["field_instance.node-localtarget-field_local_content.display|secondary_teaser"] = array(
    'label' => 'above',
    'settings' => array(),
    'type' => 'hidden',
    'weight' => 0,
  );
  $overrides["field_instance.node-localtarget-field_market.display|secondary_teaser"] = array(
    'label' => 'above',
    'settings' => array(),
    'type' => 'hidden',
    'weight' => 0,
  );
  $overrides["field_instance.node-localtarget-field_packages_intro.display|secondary_teaser"] = array(
    'label' => 'above',
    'settings' => array(),
    'type' => 'hidden',
    'weight' => 0,
  );
  $overrides["field_instance.node-localtarget-field_packages_title.display|secondary_teaser"] = array(
    'label' => 'above',
    'settings' => array(),
    'type' => 'hidden',
    'weight' => 0,
  );
  $overrides["field_instance.node-localtarget-field_seo_title.display|secondary_teaser"] = array(
    'label' => 'above',
    'settings' => array(),
    'type' => 'hidden',
    'weight' => 0,
  );
  $overrides["field_instance.node-localtarget-field_service.display|secondary_teaser"] = array(
    'label' => 'above',
    'settings' => array(),
    'type' => 'hidden',
    'weight' => 0,
  );
  $overrides["field_instance.node-location-field_content_edited.display|secondary_teaser"] = array(
    'label' => 'above',
    'settings' => array(),
    'type' => 'hidden',
    'weight' => 0,
  );
  $overrides["field_instance.node-location-field_email.display|secondary_teaser"] = array(
    'label' => 'above',
    'settings' => array(),
    'type' => 'hidden',
    'weight' => 0,
  );
  $overrides["field_instance.node-location-field_google_url.display|secondary_teaser"] = array(
    'label' => 'above',
    'settings' => array(),
    'type' => 'hidden',
    'weight' => 0,
  );
  $overrides["field_instance.node-location-field_locality.display|secondary_teaser"] = array(
    'label' => 'above',
    'settings' => array(),
    'type' => 'hidden',
    'weight' => 0,
  );
  $overrides["field_instance.node-location-field_market.display|secondary_teaser"] = array(
    'label' => 'above',
    'settings' => array(),
    'type' => 'hidden',
    'weight' => 0,
  );
  $overrides["field_instance.node-location-field_phone_number.display|secondary_teaser"] = array(
    'label' => 'above',
    'settings' => array(),
    'type' => 'hidden',
    'weight' => 0,
  );
  $overrides["field_instance.node-location-field_postal_code.display|secondary_teaser"] = array(
    'label' => 'above',
    'settings' => array(),
    'type' => 'hidden',
    'weight' => 0,
  );
  $overrides["field_instance.node-location-field_state.display|secondary_teaser"] = array(
    'label' => 'above',
    'settings' => array(),
    'type' => 'hidden',
    'weight' => 0,
  );
  $overrides["field_instance.node-location-field_street_address.display|secondary_teaser"] = array(
    'label' => 'above',
    'settings' => array(),
    'type' => 'hidden',
    'weight' => 0,
  );
  $overrides["field_instance.node-market-body.display|secondary_teaser"] = array(
    'label' => 'above',
    'settings' => array(),
    'type' => 'hidden',
    'weight' => 0,
  );
  $overrides["field_instance.node-market-field_content_edited.display|secondary_teaser"] = array(
    'label' => 'above',
    'settings' => array(),
    'type' => 'hidden',
    'weight' => 0,
  );
  $overrides["field_instance.node-market-field_image.display|secondary_teaser"] = array(
    'label' => 'above',
    'settings' => array(),
    'type' => 'hidden',
    'weight' => 0,
  );
  $overrides["field_instance.node-market-field_market.display|secondary_teaser"] = array(
    'label' => 'above',
    'settings' => array(),
    'type' => 'hidden',
    'weight' => 0,
  );
  $overrides["field_instance.node-package-body.display|secondary_teaser"] = array(
    'label' => 'above',
    'settings' => array(),
    'type' => 'hidden',
    'weight' => 0,
  );
  $overrides["field_instance.node-package-field_call_out.display|secondary_teaser"] = array(
    'label' => 'above',
    'settings' => array(),
    'type' => 'hidden',
    'weight' => 0,
  );
  $overrides["field_instance.node-package-field_content_edited.display|secondary_teaser"] = array(
    'label' => 'above',
    'settings' => array(),
    'type' => 'hidden',
    'weight' => 0,
  );
  $overrides["field_instance.node-package-field_display_title.display|secondary_teaser"] = array(
    'label' => 'above',
    'settings' => array(),
    'type' => 'hidden',
    'weight' => 0,
  );
  $overrides["field_instance.node-package-field_icon.display|secondary_teaser"] = array(
    'label' => 'above',
    'settings' => array(),
    'type' => 'hidden',
    'weight' => 0,
  );
  $overrides["field_instance.node-package-field_image.display|secondary_teaser"] = array(
    'label' => 'above',
    'settings' => array(),
    'type' => 'hidden',
    'weight' => 0,
  );
  $overrides["field_instance.node-package-field_intro.display|secondary_teaser"] = array(
    'label' => 'above',
    'settings' => array(),
    'type' => 'hidden',
    'weight' => 0,
  );
  $overrides["field_instance.node-package-field_services.display|secondary_teaser"] = array(
    'label' => 'above',
    'settings' => array(),
    'type' => 'hidden',
    'weight' => 0,
  );
  $overrides["field_instance.node-page-body.display|secondary_teaser"] = array(
    'label' => 'above',
    'settings' => array(),
    'type' => 'hidden',
    'weight' => 0,
  );
  $overrides["field_instance.node-page-field_attachments.display|secondary_teaser"] = array(
    'label' => 'above',
    'settings' => array(),
    'type' => 'hidden',
    'weight' => 0,
  );
  $overrides["field_instance.node-page-field_content_edited.display|secondary_teaser"] = array(
    'label' => 'above',
    'settings' => array(),
    'type' => 'hidden',
    'weight' => 0,
  );
  $overrides["field_instance.node-page-field_display_title.display|secondary_teaser"] = array(
    'label' => 'above',
    'settings' => array(),
    'type' => 'hidden',
    'weight' => 0,
  );
  $overrides["field_instance.node-page-field_image.display|secondary_teaser"] = array(
    'label' => 'above',
    'settings' => array(),
    'type' => 'hidden',
    'weight' => 0,
  );
  $overrides["field_instance.node-page-field_intro.display|secondary_teaser"] = array(
    'label' => 'above',
    'settings' => array(),
    'type' => 'hidden',
    'weight' => 0,
  );
  $overrides["field_instance.node-page-field_seo_title.display|secondary_teaser"] = array(
    'label' => 'above',
    'settings' => array(),
    'type' => 'hidden',
    'weight' => 0,
  );
  $overrides["field_instance.node-profile-body.display|secondary_teaser"] = array(
    'label' => 'above',
    'settings' => array(),
    'type' => 'hidden',
    'weight' => 0,
  );
  $overrides["field_instance.node-profile-field_content_edited.display|secondary_teaser"] = array(
    'label' => 'above',
    'settings' => array(),
    'type' => 'hidden',
    'weight' => 0,
  );
  $overrides["field_instance.node-profile-field_image.display|secondary_teaser"] = array(
    'label' => 'above',
    'settings' => array(),
    'type' => 'hidden',
    'weight' => 0,
  );
  $overrides["field_instance.node-profile-field_position.display|secondary_teaser"] = array(
    'label' => 'above',
    'settings' => array(),
    'type' => 'hidden',
    'weight' => 0,
  );
  $overrides["field_instance.node-region-body.display|secondary_teaser"] = array(
    'label' => 'above',
    'settings' => array(),
    'type' => 'hidden',
    'weight' => 0,
  );
  $overrides["field_instance.node-region-field_content_edited.display|secondary_teaser"] = array(
    'label' => 'above',
    'settings' => array(),
    'type' => 'hidden',
    'weight' => 0,
  );
  $overrides["field_instance.node-region-field_image.display|secondary_teaser"] = array(
    'label' => 'above',
    'settings' => array(),
    'type' => 'hidden',
    'weight' => 0,
  );
  $overrides["field_instance.node-region-field_region.display|secondary_teaser"] = array(
    'label' => 'above',
    'settings' => array(),
    'type' => 'hidden',
    'weight' => 0,
  );
  $overrides["field_instance.node-service-body.display|alt_teaser|label"] = 'hidden';
  $overrides["field_instance.node-service-body.display|alt_teaser|module"] = 'smart_trim';
  $overrides["field_instance.node-service-body.display|alt_teaser|settings|more_link"] = 1;
  $overrides["field_instance.node-service-body.display|alt_teaser|settings|more_text"] = 'Learn More';
  $overrides["field_instance.node-service-body.display|alt_teaser|settings|summary_handler"] = 'full';
  $overrides["field_instance.node-service-body.display|alt_teaser|settings|trim_length"] = 200;
  $overrides["field_instance.node-service-body.display|alt_teaser|settings|trim_link"] = 0;
  $overrides["field_instance.node-service-body.display|alt_teaser|settings|trim_options"] = array(
    'text' => 'text',
  );
  $overrides["field_instance.node-service-body.display|alt_teaser|settings|trim_preserve_tags"] = '';
  $overrides["field_instance.node-service-body.display|alt_teaser|settings|trim_suffix"] = '...';
  $overrides["field_instance.node-service-body.display|alt_teaser|settings|trim_type"] = 'chars';
  $overrides["field_instance.node-service-body.display|alt_teaser|type"] = 'smart_trim_format';
  $overrides["field_instance.node-service-body.display|alt_teaser|weight"] = 1;
  $overrides["field_instance.node-service-body.display|secondary_teaser"] = array(
    'label' => 'above',
    'settings' => array(),
    'type' => 'hidden',
    'weight' => 0,
  );
  $overrides["field_instance.node-service-field_call_out.display|alt_teaser|weight"] = 7;
  $overrides["field_instance.node-service-field_call_out.display|secondary_teaser"] = array(
    'label' => 'above',
    'settings' => array(),
    'type' => 'hidden',
    'weight' => 0,
  );
  $overrides["field_instance.node-service-field_content_edited.display|alt_teaser|weight"] = 8;
  $overrides["field_instance.node-service-field_content_edited.display|secondary_teaser"] = array(
    'label' => 'above',
    'settings' => array(),
    'type' => 'hidden',
    'weight' => 0,
  );
  $overrides["field_instance.node-service-field_display_title.display|alt_teaser|weight"] = 9;
  $overrides["field_instance.node-service-field_display_title.display|secondary_teaser"] = array(
    'label' => 'above',
    'settings' => array(),
    'type' => 'hidden',
    'weight' => 0,
  );
  $overrides["field_instance.node-service-field_icon.display|alt_teaser|weight"] = 6;
  $overrides["field_instance.node-service-field_icon.display|secondary_teaser"] = array(
    'label' => 'above',
    'settings' => array(),
    'type' => 'hidden',
    'weight' => 0,
  );
  $overrides["field_instance.node-service-field_icon.settings|default_image"] = 3;
  $overrides["field_instance.node-service-field_image.display|alt_teaser|label"] = 'hidden';
  $overrides["field_instance.node-service-field_image.display|alt_teaser|module"] = 'image';
  $overrides["field_instance.node-service-field_image.display|alt_teaser|settings|image_link"] = 'content';
  $overrides["field_instance.node-service-field_image.display|alt_teaser|settings|image_style"] = 'focal_point_scale_and_crop_185x150';
  $overrides["field_instance.node-service-field_image.display|alt_teaser|type"] = 'image';
  $overrides["field_instance.node-service-field_image.display|secondary_teaser"] = array(
    'label' => 'above',
    'settings' => array(),
    'type' => 'hidden',
    'weight' => 0,
  );
  $overrides["field_instance.node-service-field_image.settings|default_image"] = 5;
  $overrides["field_instance.node-service-field_intro.display|alt_teaser|weight"] = 2;
  $overrides["field_instance.node-service-field_intro.display|secondary_teaser"] = array(
    'label' => 'above',
    'settings' => array(),
    'type' => 'hidden',
    'weight' => 0,
  );
  $overrides["field_instance.node-service-field_package_intro.display|alt_teaser|weight"] = 3;
  $overrides["field_instance.node-service-field_package_intro.display|secondary_teaser"] = array(
    'label' => 'above',
    'settings' => array(),
    'type' => 'hidden',
    'weight' => 0,
  );
  $overrides["field_instance.node-service-field_seo_title.display|alt_teaser|weight"] = 4;
  $overrides["field_instance.node-service-field_seo_title.display|secondary_teaser"] = array(
    'label' => 'above',
    'settings' => array(),
    'type' => 'hidden',
    'weight' => 0,
  );
  $overrides["field_instance.node-service-field_service.display|alt_teaser|weight"] = 5;
  $overrides["field_instance.node-service-field_service.display|secondary_teaser"] = array(
    'label' => 'above',
    'settings' => array(),
    'type' => 'hidden',
    'weight' => 0,
  );
  $overrides["field_instance.node-slide-body.display|secondary_teaser"] = array(
    'label' => 'above',
    'settings' => array(),
    'type' => 'hidden',
    'weight' => 0,
  );
  $overrides["field_instance.node-slide-field_color.display|alt_teaser|weight"] = 5;
  $overrides["field_instance.node-slide-field_color.display|secondary_teaser"] = array(
    'label' => 'above',
    'settings' => array(),
    'type' => 'hidden',
    'weight' => 0,
  );
  $overrides["field_instance.node-slide-field_content_edited.display|alt_teaser|weight"] = 4;
  $overrides["field_instance.node-slide-field_content_edited.display|secondary_teaser"] = array(
    'label' => 'above',
    'settings' => array(),
    'type' => 'hidden',
    'weight' => 0,
  );
  $overrides["field_instance.node-slide-field_image.display|alt_teaser|weight"] = 1;
  $overrides["field_instance.node-slide-field_image.display|secondary_teaser"] = array(
    'label' => 'above',
    'settings' => array(),
    'type' => 'hidden',
    'weight' => 0,
  );
  $overrides["field_instance.node-slide-field_market.display|alt_teaser|weight"] = 2;
  $overrides["field_instance.node-slide-field_market.display|secondary_teaser"] = array(
    'label' => 'above',
    'settings' => array(),
    'type' => 'hidden',
    'weight' => 0,
  );
  $overrides["field_instance.node-slide-field_service.display|alt_teaser|weight"] = 3;
  $overrides["field_instance.node-slide-field_service.display|secondary_teaser"] = array(
    'label' => 'above',
    'settings' => array(),
    'type' => 'hidden',
    'weight' => 0,
  );
  $overrides["field_instance.node-special_offer-body.display|secondary_teaser"] = array(
    'label' => 'hidden',
    'module' => 'smart_trim',
    'settings' => array(
      'more_link' => 0,
      'more_text' => 'Read more',
      'summary_handler' => 'full',
      'trim_length' => 300,
      'trim_link' => 0,
      'trim_options' => array(
        'text' => 'text',
      ),
      'trim_preserve_tags' => '',
      'trim_suffix' => '...',
      'trim_type' => 'chars',
    ),
    'type' => 'smart_trim_format',
    'weight' => 2,
  );
  $overrides["field_instance.node-special_offer-field_button.display|default|label"] = 'hidden';
  $overrides["field_instance.node-special_offer-field_button.display|default|module"]["DELETED"] = TRUE;
  $overrides["field_instance.node-special_offer-field_button.display|default|type"] = 'hidden';
  $overrides["field_instance.node-special_offer-field_button.display|secondary_teaser"] = array(
    'label' => 'hidden',
    'module' => 'link',
    'settings' => array(),
    'type' => 'link_default',
    'weight' => 3,
  );
  $overrides["field_instance.node-special_offer-field_button.widget|weight"] = 53;
  $overrides["field_instance.node-special_offer-field_content_edited.display|secondary_teaser"] = array(
    'label' => 'above',
    'settings' => array(),
    'type' => 'hidden',
    'weight' => 10,
  );
  $overrides["field_instance.node-special_offer-field_expiration_date.display|secondary_teaser"] = array(
    'label' => 'above',
    'settings' => array(),
    'type' => 'hidden',
    'weight' => 8,
  );
  $overrides["field_instance.node-special_offer-field_expiration_date.widget|weight"] = 52;
  $overrides["field_instance.node-special_offer-field_image.display|secondary_teaser"] = array(
    'label' => 'above',
    'settings' => array(),
    'type' => 'hidden',
    'weight' => 9,
  );
  $overrides["field_instance.node-special_offer-field_offer_price.display|secondary_teaser"] = array(
    'label' => 'above',
    'settings' => array(),
    'type' => 'hidden',
    'weight' => 7,
  );
  $overrides["field_instance.node-special_offer-field_offer_price.widget|weight"] = 49;
  $overrides["field_instance.node-special_offer-field_original_price.display|secondary_teaser"] = array(
    'label' => 'above',
    'settings' => array(),
    'type' => 'hidden',
    'weight' => 6,
  );
  $overrides["field_instance.node-special_offer-field_original_price.widget|weight"] = 48;
  $overrides["field_instance.node-special_offer-field_package.display|secondary_teaser"] = array(
    'label' => 'above',
    'settings' => array(),
    'type' => 'hidden',
    'weight' => 4,
  );
  $overrides["field_instance.node-special_offer-field_package.widget|weight"] = 51;
  $overrides["field_instance.node-special_offer-field_services.display|default|module"]["DELETED"] = TRUE;
  $overrides["field_instance.node-special_offer-field_services.display|default|type"] = 'hidden';
  $overrides["field_instance.node-special_offer-field_services.display|secondary_teaser"] = array(
    'label' => 'above',
    'settings' => array(),
    'type' => 'hidden',
    'weight' => 5,
  );
  $overrides["field_instance.node-special_offer-field_services.widget|weight"] = 50;
  $overrides["field_instance.node-testimonial-body.display|secondary_teaser"] = array(
    'label' => 'above',
    'settings' => array(),
    'type' => 'hidden',
    'weight' => 0,
  );
  $overrides["field_instance.node-testimonial-field_content_edited.display|secondary_teaser"] = array(
    'label' => 'above',
    'settings' => array(),
    'type' => 'hidden',
    'weight' => 0,
  );
  $overrides["field_instance.node-testimonial-field_market.display|secondary_teaser"] = array(
    'label' => 'above',
    'settings' => array(),
    'type' => 'hidden',
    'weight' => 0,
  );
  $overrides["field_instance.node-testimonial-field_service.display|secondary_teaser"] = array(
    'label' => 'above',
    'settings' => array(),
    'type' => 'hidden',
    'weight' => 0,
  );
  $overrides["field_instance.node-webform-body.display|secondary_teaser"] = array(
    'label' => 'above',
    'settings' => array(),
    'type' => 'hidden',
    'weight' => 0,
  );

  // Exported overrides for: flexslider_optionset
  $overrides["flexslider_optionset.default.export_type"]["DELETED"] = TRUE;
  $overrides["flexslider_optionset.default.type"]["DELETED"] = TRUE;

  // Exported overrides for: image
  $overrides["image.flexslider_full.label"] = 'flexslider_full';
  $overrides["image.flexslider_thumbnail.label"] = 'flexslider_thumbnail';
  $overrides["image.menu_icon.label"] = 'menu_icon';

  // Exported overrides for: variable
  $overrides["variable.entity_view_modes.value|node|secondary_teaser"] = array(
    'label' => 'Secondary teaser',
    'custom settings' => 1,
  );
  $overrides["variable.field_bundle_settings_node__affiliation.value|view_modes|secondary_teaser"] = array(
    'custom_settings' => TRUE,
  );
  $overrides["variable.field_bundle_settings_node__benefit.value|view_modes|secondary_teaser"] = array(
    'custom_settings' => TRUE,
  );
  $overrides["variable.field_bundle_settings_node__blog.value|view_modes|secondary_teaser"] = array(
    'custom_settings' => TRUE,
  );
  $overrides["variable.field_bundle_settings_node__cta.value|view_modes|secondary_teaser"] = array(
    'custom_settings' => TRUE,
  );
  $overrides["variable.field_bundle_settings_node__faq.value|view_modes|secondary_teaser"] = array(
    'custom_settings' => TRUE,
  );
  $overrides["variable.field_bundle_settings_node__gallery_image.value|view_modes|secondary_teaser"] = array(
    'custom_settings' => TRUE,
  );
  $overrides["variable.field_bundle_settings_node__landing_page.value|view_modes|secondary_teaser"] = array(
    'custom_settings' => TRUE,
  );
  $overrides["variable.field_bundle_settings_node__localtarget.value|view_modes|secondary_teaser"] = array(
    'custom_settings' => TRUE,
  );
  $overrides["variable.field_bundle_settings_node__location.value|view_modes|secondary_teaser"] = array(
    'custom_settings' => TRUE,
  );
  $overrides["variable.field_bundle_settings_node__market.value|view_modes|secondary_teaser"] = array(
    'custom_settings' => TRUE,
  );
  $overrides["variable.field_bundle_settings_node__package.value|view_modes|secondary_teaser"] = array(
    'custom_settings' => TRUE,
  );
  $overrides["variable.field_bundle_settings_node__page.value|view_modes|secondary_teaser"] = array(
    'custom_settings' => TRUE,
  );
  $overrides["variable.field_bundle_settings_node__profile.value|view_modes|secondary_teaser"] = array(
    'custom_settings' => TRUE,
  );
  $overrides["variable.field_bundle_settings_node__region.value|view_modes|secondary_teaser"] = array(
    'custom_settings' => TRUE,
  );
  $overrides["variable.field_bundle_settings_node__service.value|view_modes|secondary_teaser"] = array(
    'custom_settings' => TRUE,
  );
  $overrides["variable.field_bundle_settings_node__slide.value|view_modes|secondary_teaser"] = array(
    'custom_settings' => TRUE,
  );
  $overrides["variable.field_bundle_settings_node__special_offer.value|view_modes|secondary_teaser"] = array(
    'custom_settings' => TRUE,
  );
  $overrides["variable.field_bundle_settings_node__testimonial.value|view_modes|secondary_teaser"] = array(
    'custom_settings' => TRUE,
  );
  $overrides["variable.field_bundle_settings_node__webform.value|view_modes|secondary_teaser"] = array(
    'custom_settings' => TRUE,
  );
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
  $overrides["views_view.benefits.display|front_s4"] = unserialize('O:13:"views_display":7:{s:15:"display_options";a:6:{s:5:"query";a:2:{s:4:"type";s:11:"views_query";s:7:"options";a:0:{}}s:8:"defaults";a:6:{s:12:"style_plugin";b:0;s:13:"style_options";b:0;s:10:"row_plugin";b:0;s:11:"row_options";b:0;s:13:"filter_groups";b:0;s:7:"filters";b:0;}s:12:"style_plugin";s:7:"default";s:10:"row_plugin";s:4:"node";s:11:"row_options";a:2:{s:9:"view_mode";s:16:"secondary_teaser";s:5:"links";b:0;}s:7:"filters";a:3:{s:6:"status";a:6:{s:2:"id";s:6:"status";s:5:"table";s:4:"node";s:5:"field";s:6:"status";s:5:"value";i:1;s:5:"group";i:1;s:6:"expose";a:1:{s:8:"operator";b:0;}}s:4:"type";a:4:{s:2:"id";s:4:"type";s:5:"table";s:4:"node";s:5:"field";s:4:"type";s:5:"value";a:1:{s:7:"benefit";s:7:"benefit";}}s:7:"promote";a:4:{s:2:"id";s:7:"promote";s:5:"table";s:4:"node";s:5:"field";s:7:"promote";s:5:"value";s:1:"1";}}}s:8:"db_table";s:13:"views_display";s:3:"vid";i:0;s:2:"id";s:8:"front_s4";s:13:"display_title";s:24:"Front page benefits (S4)";s:14:"display_plugin";s:5:"block";s:8:"position";i:0;}');
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
  $overrides["views_view.localtarget.display|title_s4"] = unserialize('O:13:"views_display":7:{s:15:"display_options";a:6:{s:5:"query";a:2:{s:4:"type";s:11:"views_query";s:7:"options";a:0:{}}s:8:"defaults";a:3:{s:5:"title";b:0;s:6:"fields";b:0;s:9:"arguments";b:0;}s:5:"title";s:6:"<none>";s:6:"fields";a:1:{s:5:"title";a:7:{s:2:"id";s:5:"title";s:5:"table";s:4:"node";s:5:"field";s:5:"title";s:5:"label";s:0:"";s:5:"alter";a:4:{s:10:"alter_text";b:1;s:4:"text";s:16:"<h1>[title]</h1>";s:13:"word_boundary";b:0;s:8:"ellipsis";b:0;}s:19:"element_label_colon";b:0;s:12:"link_to_node";b:0;}}s:9:"arguments";a:1:{s:3:"nid";a:7:{s:2:"id";s:3:"nid";s:5:"table";s:4:"node";s:5:"field";s:3:"nid";s:14:"default_action";s:7:"default";s:21:"default_argument_type";s:4:"node";s:7:"summary";a:2:{s:17:"number_of_records";s:1:"0";s:6:"format";s:15:"default_summary";}s:15:"summary_options";a:1:{s:14:"items_per_page";s:2:"25";}}}s:17:"block_description";s:23:"Local Target Title (S4)";}s:8:"db_table";s:13:"views_display";s:3:"vid";i:0;s:2:"id";s:8:"title_s4";s:13:"display_title";s:23:"Local Target Title (S4)";s:14:"display_plugin";s:5:"block";s:8:"position";i:0;}');
  $overrides["views_view.services.display|front_s4"] = unserialize('O:13:"views_display":7:{s:15:"display_options";a:6:{s:5:"query";a:2:{s:4:"type";s:11:"views_query";s:7:"options";a:0:{}}s:8:"defaults";a:4:{s:12:"style_plugin";b:0;s:13:"style_options";b:0;s:10:"row_plugin";b:0;s:11:"row_options";b:0;}s:12:"style_plugin";s:7:"default";s:10:"row_plugin";s:4:"node";s:11:"row_options";a:1:{s:9:"view_mode";s:10:"alt_teaser";}s:17:"block_description";s:24:"Front Page Services (S4)";}s:8:"db_table";s:13:"views_display";s:3:"vid";i:0;s:2:"id";s:8:"front_s4";s:13:"display_title";s:24:"Front Page Services (S4)";s:14:"display_plugin";s:5:"block";s:8:"position";i:0;}');
  $overrides["views_view.special_offers.display|front_s4"] = unserialize('O:13:"views_display":7:{s:15:"display_options";a:7:{s:5:"query";a:2:{s:4:"type";s:11:"views_query";s:7:"options";a:0:{}}s:8:"defaults";a:7:{s:5:"title";b:0;s:5:"pager";b:0;s:12:"style_plugin";b:0;s:13:"style_options";b:0;s:10:"row_plugin";b:0;s:11:"row_options";b:0;s:5:"sorts";b:0;}s:5:"pager";a:2:{s:4:"type";s:4:"some";s:7:"options";a:2:{s:14:"items_per_page";s:1:"1";s:6:"offset";s:1:"0";}}s:12:"style_plugin";s:7:"default";s:10:"row_plugin";s:4:"node";s:11:"row_options";a:2:{s:9:"view_mode";s:16:"secondary_teaser";s:5:"links";b:0;}s:5:"sorts";a:1:{s:6:"random";a:3:{s:2:"id";s:6:"random";s:5:"table";s:5:"views";s:5:"field";s:6:"random";}}}s:8:"db_table";s:13:"views_display";s:3:"vid";i:0;s:2:"id";s:8:"front_s4";s:13:"display_title";s:13:"Homepage (S4)";s:14:"display_plugin";s:5:"block";s:8:"position";i:0;}');
  $overrides["views_view.special_offers.display|list|display_options|block_description"]["DELETED"] = TRUE;
  $overrides["views_view.special_offers.display|ltp_s4"] = unserialize('O:13:"views_display":7:{s:15:"display_options";a:8:{s:5:"query";a:2:{s:4:"type";s:11:"views_query";s:7:"options";a:0:{}}s:8:"defaults";a:8:{s:5:"title";b:0;s:5:"pager";b:0;s:12:"style_plugin";b:0;s:13:"style_options";b:0;s:10:"row_plugin";b:0;s:11:"row_options";b:0;s:5:"sorts";b:0;s:9:"arguments";b:0;}s:5:"pager";a:2:{s:4:"type";s:4:"some";s:7:"options";a:2:{s:14:"items_per_page";s:1:"1";s:6:"offset";s:1:"0";}}s:12:"style_plugin";s:7:"default";s:10:"row_plugin";s:4:"node";s:11:"row_options";a:1:{s:5:"links";b:0;}s:5:"sorts";a:1:{s:6:"random";a:3:{s:2:"id";s:6:"random";s:5:"table";s:5:"views";s:5:"field";s:6:"random";}}s:9:"arguments";a:2:{s:3:"tid";a:8:{s:2:"id";s:3:"tid";s:5:"table";s:14:"taxonomy_index";s:5:"field";s:3:"tid";s:14:"default_action";s:7:"default";s:21:"default_argument_type";s:12:"taxonomy_tid";s:24:"default_argument_options";a:4:{s:4:"node";b:1;s:6:"anyall";s:1:"+";s:5:"limit";b:1;s:12:"vocabularies";a:1:{s:8:"services";s:8:"services";}}s:7:"summary";a:2:{s:17:"number_of_records";s:1:"0";s:6:"format";s:15:"default_summary";}s:15:"summary_options";a:1:{s:14:"items_per_page";s:2:"25";}}s:3:"nid";a:8:{s:2:"id";s:3:"nid";s:5:"table";s:4:"node";s:5:"field";s:3:"nid";s:14:"default_action";s:7:"default";s:21:"default_argument_type";s:4:"node";s:7:"summary";a:2:{s:17:"number_of_records";s:1:"0";s:6:"format";s:15:"default_summary";}s:15:"summary_options";a:1:{s:14:"items_per_page";s:2:"25";}s:3:"not";b:1;}}}s:8:"db_table";s:13:"views_display";s:3:"vid";i:0;s:2:"id";s:6:"ltp_s4";s:13:"display_title";s:16:"LTP Content (S4)";s:14:"display_plugin";s:5:"block";s:8:"position";i:0;}');
  $overrides["views_view.special_offers.display|related_s4"] = unserialize('O:13:"views_display":7:{s:15:"display_options";a:8:{s:5:"query";a:2:{s:4:"type";s:11:"views_query";s:7:"options";a:0:{}}s:8:"defaults";a:8:{s:5:"title";b:0;s:5:"pager";b:0;s:12:"style_plugin";b:0;s:13:"style_options";b:0;s:10:"row_plugin";b:0;s:11:"row_options";b:0;s:5:"sorts";b:0;s:9:"arguments";b:0;}s:5:"pager";a:2:{s:4:"type";s:4:"some";s:7:"options";a:2:{s:14:"items_per_page";s:1:"1";s:6:"offset";s:1:"0";}}s:12:"style_plugin";s:7:"default";s:10:"row_plugin";s:4:"node";s:11:"row_options";a:2:{s:9:"view_mode";s:16:"secondary_teaser";s:5:"links";b:0;}s:5:"sorts";a:1:{s:6:"random";a:3:{s:2:"id";s:6:"random";s:5:"table";s:5:"views";s:5:"field";s:6:"random";}}s:9:"arguments";a:2:{s:3:"tid";a:8:{s:2:"id";s:3:"tid";s:5:"table";s:14:"taxonomy_index";s:5:"field";s:3:"tid";s:14:"default_action";s:7:"default";s:21:"default_argument_type";s:12:"taxonomy_tid";s:24:"default_argument_options";a:4:{s:4:"node";b:1;s:6:"anyall";s:1:"+";s:5:"limit";b:1;s:12:"vocabularies";a:1:{s:8:"services";s:8:"services";}}s:7:"summary";a:2:{s:17:"number_of_records";s:1:"0";s:6:"format";s:15:"default_summary";}s:15:"summary_options";a:1:{s:14:"items_per_page";s:2:"25";}}s:3:"nid";a:8:{s:2:"id";s:3:"nid";s:5:"table";s:4:"node";s:5:"field";s:3:"nid";s:14:"default_action";s:7:"default";s:21:"default_argument_type";s:4:"node";s:7:"summary";a:2:{s:17:"number_of_records";s:1:"0";s:6:"format";s:15:"default_summary";}s:15:"summary_options";a:1:{s:14:"items_per_page";s:2:"25";}s:3:"not";b:1;}}}s:8:"db_table";s:13:"views_display";s:3:"vid";i:0;s:2:"id";s:10:"related_s4";s:13:"display_title";s:12:"Related (S4)";s:14:"display_plugin";s:5:"block";s:8:"position";i:0;}');
  $overrides["views_view.taxonomy_term.display|default|display_options|access|perm"]["DELETED"] = TRUE;
  $overrides["views_view.taxonomy_term.display|default|display_options|arguments|term_node_tid_depth_modifier|exception|title_enable"] = TRUE;
  $overrides["views_view.taxonomy_term.display|default|display_options|arguments|term_node_tid_depth_modifier|specify_validation"] = TRUE;
  $overrides["views_view.taxonomy_term.display|default|display_options|arguments|term_node_tid_depth|break_phrase"] = TRUE;
  $overrides["views_view.taxonomy_term.display|default|display_options|arguments|term_node_tid_depth|exception|title_enable"] = TRUE;
  $overrides["views_view.taxonomy_term.display|default|display_options|arguments|term_node_tid_depth|specify_validation"] = TRUE;
  $overrides["views_view.taxonomy_term.display|default|display_options|arguments|term_node_tid_depth|title_enable"] = TRUE;
  $overrides["views_view.taxonomy_term.display|default|display_options|use_more_always"] = FALSE;
  $overrides["views_view.testimonials.display|front_s4"] = unserialize('O:13:"views_display":7:{s:15:"display_options";a:4:{s:5:"query";a:2:{s:4:"type";s:11:"views_query";s:7:"options";a:0:{}}s:8:"defaults";a:3:{s:5:"title";b:0;s:13:"filter_groups";b:0;s:7:"filters";b:0;}s:5:"title";s:29:"What Our Customers Are Saying";s:7:"filters";a:3:{s:6:"status";a:6:{s:2:"id";s:6:"status";s:5:"table";s:4:"node";s:5:"field";s:6:"status";s:5:"value";i:1;s:5:"group";i:1;s:6:"expose";a:1:{s:8:"operator";b:0;}}s:4:"type";a:4:{s:2:"id";s:4:"type";s:5:"table";s:4:"node";s:5:"field";s:4:"type";s:5:"value";a:1:{s:11:"testimonial";s:11:"testimonial";}}s:7:"promote";a:4:{s:2:"id";s:7:"promote";s:5:"table";s:4:"node";s:5:"field";s:7:"promote";s:5:"value";s:1:"1";}}}s:8:"db_table";s:13:"views_display";s:3:"vid";i:0;s:2:"id";s:8:"front_s4";s:13:"display_title";s:27:"Front page testimonial (S4)";s:14:"display_plugin";s:5:"block";s:8:"position";i:0;}');
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
