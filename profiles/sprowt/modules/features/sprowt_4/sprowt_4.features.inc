<?php
/**
 * @file
 * sprowt_4.features.inc
 */

/**
 * Implements hook_default_fe_block_settings_alter().
 */
function sprowt_4_default_fe_block_settings_alter(&$data) {
  if (isset($data['addtoany-addtoany_button'])) {
    $data['addtoany-addtoany_button']['themes']['adminimal']['weight'] = -37; /* WAS: 0 */
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
 * Implements hook_field_group_info_alter().
 */
function sprowt_4_field_group_info_alter(&$data) {
  if (isset($data['group_content|node|special_offer|form'])) {
    $data['group_content|node|special_offer|form']->data['children'][10] = 'title'; /* WAS: '' */
    $data['group_content|node|special_offer|form']->data['children'][11] = 'field_offer_subheadline'; /* WAS: '' */
    $data['group_content|node|special_offer|form']->data['children'][2] = 'field_content_edited'; /* WAS: 'field_expiration_date' */
    $data['group_content|node|special_offer|form']->data['children'][3] = 'field_expiration_date'; /* WAS: 'field_image' */
    $data['group_content|node|special_offer|form']->data['children'][4] = 'field_image'; /* WAS: 'field_offer_price' */
    $data['group_content|node|special_offer|form']->data['children'][5] = 'field_offer_price'; /* WAS: 'field_original_price' */
    $data['group_content|node|special_offer|form']->data['children'][6] = 'field_original_price'; /* WAS: 'field_package' */
    $data['group_content|node|special_offer|form']->data['children'][7] = 'field_package'; /* WAS: 'field_services' */
    $data['group_content|node|special_offer|form']->data['children'][8] = 'field_services'; /* WAS: 'field_content_edited' */
    $data['group_content|node|special_offer|form']->data['children'][9] = 'field_offer_headline'; /* WAS: 'title' */
  }
}

/**
 * Implements hook_field_default_field_instances_alter().
 */
function sprowt_4_field_default_field_instances_alter(&$data) {
  if (isset($data['node-affiliation-body'])) {
    $data['node-affiliation-body']['display']['secondary_teaser'] = array(
      'label' => 'above',
      'module' => 'text',
      'settings' => array(),
      'type' => 'text_default',
      'weight' => 1,
    ); /* WAS: '' */
  }
  if (isset($data['node-affiliation-field_content_edited'])) {
    $data['node-affiliation-field_content_edited']['display']['secondary_teaser'] = array(
      'label' => 'above',
      'settings' => array(),
      'type' => 'hidden',
      'weight' => 2,
    ); /* WAS: '' */
  }
  if (isset($data['node-affiliation-field_image'])) {
    $data['node-affiliation-field_image']['display']['secondary_teaser'] = array(
      'label' => 'hidden',
      'module' => 'image_link_formatter',
      'settings' => array(
        'image_link' => 'field_link',
        'image_style' => '',
      ),
      'type' => 'image_link_formatter',
      'weight' => 0,
    ); /* WAS: '' */
  }
  if (isset($data['node-affiliation-field_link'])) {
    $data['node-affiliation-field_link']['display']['secondary_teaser'] = array(
      'label' => 'hidden',
      'settings' => array(),
      'type' => 'hidden',
      'weight' => 3,
    ); /* WAS: '' */
  }
  if (isset($data['node-article-body'])) {
    $data['node-article-body']['display']['secondary_teaser'] = array(
      'label' => 'above',
      'settings' => array(),
      'type' => 'hidden',
      'weight' => 0,
    ); /* WAS: '' */
  }
  if (isset($data['node-article-field_image'])) {
    $data['node-article-field_image']['display']['secondary_teaser'] = array(
      'label' => 'above',
      'settings' => array(),
      'type' => 'hidden',
      'weight' => 0,
    ); /* WAS: '' */
  }
  if (isset($data['node-article-field_tags'])) {
    $data['node-article-field_tags']['display']['secondary_teaser'] = array(
      'label' => 'above',
      'settings' => array(),
      'type' => 'hidden',
      'weight' => 0,
    ); /* WAS: '' */
  }
  if (isset($data['node-benefit-body'])) {
    $data['node-benefit-body']['display']['secondary_teaser'] = array(
      'label' => 'hidden',
      'settings' => array(),
      'type' => 'hidden',
      'weight' => 1,
    ); /* WAS: '' */
  }
  if (isset($data['node-benefit-field_content_edited'])) {
    $data['node-benefit-field_content_edited']['display']['secondary_teaser'] = array(
      'label' => 'above',
      'settings' => array(),
      'type' => 'hidden',
      'weight' => 6,
    ); /* WAS: '' */
  }
  if (isset($data['node-benefit-field_display_title'])) {
    $data['node-benefit-field_display_title']['display']['secondary_teaser'] = array(
      'label' => 'above',
      'settings' => array(),
      'type' => 'hidden',
      'weight' => 5,
    ); /* WAS: '' */
  }
  if (isset($data['node-benefit-field_image'])) {
    $data['node-benefit-field_image']['display']['secondary_teaser'] = array(
      'label' => 'hidden',
      'module' => 'image_link_formatter',
      'settings' => array(
        'image_link' => 'field_link',
        'image_style' => 'benefits__front_page_',
      ),
      'type' => 'image_link_formatter',
      'weight' => 0,
    ); /* WAS: '' */
    $data['node-benefit-field_image']['settings']['default_image'] = 3; /* WAS: 0 */
  }
  if (isset($data['node-benefit-field_link'])) {
    $data['node-benefit-field_link']['display']['secondary_teaser'] = array(
      'label' => 'hidden',
      'module' => 'link',
      'settings' => array(),
      'type' => 'link_plain',
      'weight' => 2,
    ); /* WAS: '' */
  }
  if (isset($data['node-benefit-field_market'])) {
    $data['node-benefit-field_market']['display']['secondary_teaser'] = array(
      'label' => 'above',
      'settings' => array(),
      'type' => 'hidden',
      'weight' => 4,
    ); /* WAS: '' */
  }
  if (isset($data['node-benefit-field_service'])) {
    $data['node-benefit-field_service']['display']['secondary_teaser'] = array(
      'label' => 'above',
      'settings' => array(),
      'type' => 'hidden',
      'weight' => 3,
    ); /* WAS: '' */
  }
  if (isset($data['node-blog-body'])) {
    $data['node-blog-body']['display']['secondary_teaser'] = array(
      'label' => 'above',
      'settings' => array(),
      'type' => 'hidden',
      'weight' => 0,
    ); /* WAS: '' */
  }
  if (isset($data['node-blog-field_attachments'])) {
    $data['node-blog-field_attachments']['display']['secondary_teaser'] = array(
      'label' => 'above',
      'settings' => array(),
      'type' => 'hidden',
      'weight' => 0,
    ); /* WAS: '' */
  }
  if (isset($data['node-blog-field_call_out'])) {
    $data['node-blog-field_call_out']['display']['secondary_teaser'] = array(
      'label' => 'above',
      'settings' => array(),
      'type' => 'hidden',
      'weight' => 0,
    ); /* WAS: '' */
  }
  if (isset($data['node-blog-field_content_edited'])) {
    $data['node-blog-field_content_edited']['display']['secondary_teaser'] = array(
      'label' => 'above',
      'settings' => array(),
      'type' => 'hidden',
      'weight' => 0,
    ); /* WAS: '' */
  }
  if (isset($data['node-blog-field_image'])) {
    $data['node-blog-field_image']['display']['secondary_teaser'] = array(
      'label' => 'above',
      'settings' => array(),
      'type' => 'hidden',
      'weight' => 0,
    ); /* WAS: '' */
  }
  if (isset($data['node-blog-field_market'])) {
    $data['node-blog-field_market']['display']['secondary_teaser'] = array(
      'label' => 'above',
      'settings' => array(),
      'type' => 'hidden',
      'weight' => 0,
    ); /* WAS: '' */
  }
  if (isset($data['node-blog-field_service'])) {
    $data['node-blog-field_service']['display']['secondary_teaser'] = array(
      'label' => 'above',
      'settings' => array(),
      'type' => 'hidden',
      'weight' => 0,
    ); /* WAS: '' */
  }
  if (isset($data['node-cta-body'])) {
    $data['node-cta-body']['display']['secondary_teaser'] = array(
      'label' => 'above',
      'settings' => array(),
      'type' => 'hidden',
      'weight' => 0,
    ); /* WAS: '' */
  }
  if (isset($data['node-cta-field_content_edited'])) {
    $data['node-cta-field_content_edited']['display']['secondary_teaser'] = array(
      'label' => 'above',
      'settings' => array(),
      'type' => 'hidden',
      'weight' => 0,
    ); /* WAS: '' */
  }
  if (isset($data['node-faq-body'])) {
    $data['node-faq-body']['display']['secondary_teaser'] = array(
      'label' => 'above',
      'settings' => array(),
      'type' => 'hidden',
      'weight' => 0,
    ); /* WAS: '' */
  }
  if (isset($data['node-faq-field_content_edited'])) {
    $data['node-faq-field_content_edited']['display']['secondary_teaser'] = array(
      'label' => 'above',
      'settings' => array(),
      'type' => 'hidden',
      'weight' => 0,
    ); /* WAS: '' */
  }
  if (isset($data['node-gallery_image-field_content_edited'])) {
    $data['node-gallery_image-field_content_edited']['display']['secondary_teaser'] = array(
      'label' => 'above',
      'settings' => array(),
      'type' => 'hidden',
      'weight' => 0,
    ); /* WAS: '' */
  }
  if (isset($data['node-gallery_image-field_image'])) {
    $data['node-gallery_image-field_image']['display']['secondary_teaser'] = array(
      'label' => 'above',
      'settings' => array(),
      'type' => 'hidden',
      'weight' => 0,
    ); /* WAS: '' */
  }
  if (isset($data['node-gallery_image-field_project'])) {
    $data['node-gallery_image-field_project']['display']['secondary_teaser'] = array(
      'label' => 'above',
      'settings' => array(),
      'type' => 'hidden',
      'weight' => 0,
    ); /* WAS: '' */
  }
  if (isset($data['node-landing_page-body'])) {
    $data['node-landing_page-body']['display']['secondary_teaser'] = array(
      'label' => 'above',
      'settings' => array(),
      'type' => 'hidden',
      'weight' => 0,
    ); /* WAS: '' */
  }
  if (isset($data['node-landing_page-field_call_out'])) {
    $data['node-landing_page-field_call_out']['display']['secondary_teaser'] = array(
      'label' => 'above',
      'settings' => array(),
      'type' => 'hidden',
      'weight' => 0,
    ); /* WAS: '' */
  }
  if (isset($data['node-landing_page-field_content_edited'])) {
    $data['node-landing_page-field_content_edited']['display']['secondary_teaser'] = array(
      'label' => 'above',
      'settings' => array(),
      'type' => 'hidden',
      'weight' => 0,
    ); /* WAS: '' */
  }
  if (isset($data['node-landing_page-field_image'])) {
    $data['node-landing_page-field_image']['display']['secondary_teaser'] = array(
      'label' => 'above',
      'settings' => array(),
      'type' => 'hidden',
      'weight' => 0,
    ); /* WAS: '' */
  }
  if (isset($data['node-landing_page-field_market'])) {
    $data['node-landing_page-field_market']['display']['secondary_teaser'] = array(
      'label' => 'above',
      'settings' => array(),
      'type' => 'hidden',
      'weight' => 0,
    ); /* WAS: '' */
  }
  if (isset($data['node-landing_page-field_offer'])) {
    $data['node-landing_page-field_offer']['display']['secondary_teaser'] = array(
      'label' => 'above',
      'settings' => array(),
      'type' => 'hidden',
      'weight' => 0,
    ); /* WAS: '' */
  }
  if (isset($data['node-landing_page-field_phone_number'])) {
    $data['node-landing_page-field_phone_number']['display']['secondary_teaser'] = array(
      'label' => 'above',
      'settings' => array(),
      'type' => 'hidden',
      'weight' => 0,
    ); /* WAS: '' */
  }
  if (isset($data['node-landing_page-field_seo_title'])) {
    $data['node-landing_page-field_seo_title']['display']['secondary_teaser'] = array(
      'label' => 'above',
      'settings' => array(),
      'type' => 'hidden',
      'weight' => 0,
    ); /* WAS: '' */
  }
  if (isset($data['node-landing_page-field_service'])) {
    $data['node-landing_page-field_service']['display']['secondary_teaser'] = array(
      'label' => 'above',
      'settings' => array(),
      'type' => 'hidden',
      'weight' => 0,
    ); /* WAS: '' */
  }
  if (isset($data['node-landing_page-field_service_description'])) {
    $data['node-landing_page-field_service_description']['display']['secondary_teaser'] = array(
      'label' => 'above',
      'settings' => array(),
      'type' => 'hidden',
      'weight' => 0,
    ); /* WAS: '' */
  }
  if (isset($data['node-landing_page-field_special_offer'])) {
    $data['node-landing_page-field_special_offer']['display']['secondary_teaser'] = array(
      'label' => 'above',
      'settings' => array(),
      'type' => 'hidden',
      'weight' => 0,
    ); /* WAS: '' */
    $data['node-landing_page-field_special_offer']['display']['sidebar']['settings']['use_content_language'] = TRUE; /* WAS: '' */
  }
  if (isset($data['node-localtarget-body'])) {
    $data['node-localtarget-body']['display']['secondary_teaser'] = array(
      'label' => 'above',
      'settings' => array(),
      'type' => 'hidden',
      'weight' => 0,
    ); /* WAS: '' */
  }
  if (isset($data['node-localtarget-field_call_out'])) {
    $data['node-localtarget-field_call_out']['display']['secondary_teaser'] = array(
      'label' => 'above',
      'settings' => array(),
      'type' => 'hidden',
      'weight' => 0,
    ); /* WAS: '' */
  }
  if (isset($data['node-localtarget-field_content_edited'])) {
    $data['node-localtarget-field_content_edited']['display']['secondary_teaser'] = array(
      'label' => 'above',
      'settings' => array(),
      'type' => 'hidden',
      'weight' => 0,
    ); /* WAS: '' */
  }
  if (isset($data['node-localtarget-field_display_title'])) {
    $data['node-localtarget-field_display_title']['display']['secondary_teaser'] = array(
      'label' => 'above',
      'settings' => array(),
      'type' => 'hidden',
      'weight' => 0,
    ); /* WAS: '' */
  }
  if (isset($data['node-localtarget-field_hero_image'])) {
    $data['node-localtarget-field_hero_image']['display']['secondary_teaser'] = array(
      'label' => 'above',
      'settings' => array(),
      'type' => 'hidden',
      'weight' => 0,
    ); /* WAS: '' */
  }
  if (isset($data['node-localtarget-field_image'])) {
    $data['node-localtarget-field_image']['display']['secondary_teaser'] = array(
      'label' => 'above',
      'settings' => array(),
      'type' => 'hidden',
      'weight' => 0,
    ); /* WAS: '' */
  }
  if (isset($data['node-localtarget-field_intro'])) {
    $data['node-localtarget-field_intro']['display']['secondary_teaser'] = array(
      'label' => 'above',
      'settings' => array(),
      'type' => 'hidden',
      'weight' => 0,
    ); /* WAS: '' */
  }
  if (isset($data['node-localtarget-field_local_content'])) {
    $data['node-localtarget-field_local_content']['display']['secondary_teaser'] = array(
      'label' => 'above',
      'settings' => array(),
      'type' => 'hidden',
      'weight' => 0,
    ); /* WAS: '' */
  }
  if (isset($data['node-localtarget-field_market'])) {
    $data['node-localtarget-field_market']['display']['secondary_teaser'] = array(
      'label' => 'above',
      'settings' => array(),
      'type' => 'hidden',
      'weight' => 0,
    ); /* WAS: '' */
  }
  if (isset($data['node-localtarget-field_packages_intro'])) {
    $data['node-localtarget-field_packages_intro']['display']['secondary_teaser'] = array(
      'label' => 'above',
      'settings' => array(),
      'type' => 'hidden',
      'weight' => 0,
    ); /* WAS: '' */
  }
  if (isset($data['node-localtarget-field_packages_title'])) {
    $data['node-localtarget-field_packages_title']['display']['secondary_teaser'] = array(
      'label' => 'above',
      'settings' => array(),
      'type' => 'hidden',
      'weight' => 0,
    ); /* WAS: '' */
  }
  if (isset($data['node-localtarget-field_seo_title'])) {
    $data['node-localtarget-field_seo_title']['display']['secondary_teaser'] = array(
      'label' => 'above',
      'settings' => array(),
      'type' => 'hidden',
      'weight' => 0,
    ); /* WAS: '' */
  }
  if (isset($data['node-localtarget-field_service'])) {
    $data['node-localtarget-field_service']['display']['secondary_teaser'] = array(
      'label' => 'above',
      'settings' => array(),
      'type' => 'hidden',
      'weight' => 0,
    ); /* WAS: '' */
  }
  if (isset($data['node-location-field_content_edited'])) {
    $data['node-location-field_content_edited']['display']['secondary_teaser'] = array(
      'label' => 'above',
      'settings' => array(),
      'type' => 'hidden',
      'weight' => 0,
    ); /* WAS: '' */
  }
  if (isset($data['node-location-field_email'])) {
    $data['node-location-field_email']['display']['secondary_teaser'] = array(
      'label' => 'above',
      'settings' => array(),
      'type' => 'hidden',
      'weight' => 0,
    ); /* WAS: '' */
  }
  if (isset($data['node-location-field_google_url'])) {
    $data['node-location-field_google_url']['display']['secondary_teaser'] = array(
      'label' => 'above',
      'settings' => array(),
      'type' => 'hidden',
      'weight' => 0,
    ); /* WAS: '' */
  }
  if (isset($data['node-location-field_locality'])) {
    $data['node-location-field_locality']['display']['secondary_teaser'] = array(
      'label' => 'above',
      'settings' => array(),
      'type' => 'hidden',
      'weight' => 0,
    ); /* WAS: '' */
  }
  if (isset($data['node-location-field_market'])) {
    $data['node-location-field_market']['display']['secondary_teaser'] = array(
      'label' => 'above',
      'settings' => array(),
      'type' => 'hidden',
      'weight' => 0,
    ); /* WAS: '' */
  }
  if (isset($data['node-location-field_phone_number'])) {
    $data['node-location-field_phone_number']['display']['secondary_teaser'] = array(
      'label' => 'above',
      'settings' => array(),
      'type' => 'hidden',
      'weight' => 0,
    ); /* WAS: '' */
  }
  if (isset($data['node-location-field_postal_code'])) {
    $data['node-location-field_postal_code']['display']['secondary_teaser'] = array(
      'label' => 'above',
      'settings' => array(),
      'type' => 'hidden',
      'weight' => 0,
    ); /* WAS: '' */
  }
  if (isset($data['node-location-field_state'])) {
    $data['node-location-field_state']['display']['secondary_teaser'] = array(
      'label' => 'above',
      'settings' => array(),
      'type' => 'hidden',
      'weight' => 0,
    ); /* WAS: '' */
  }
  if (isset($data['node-location-field_street_address'])) {
    $data['node-location-field_street_address']['display']['secondary_teaser'] = array(
      'label' => 'above',
      'settings' => array(),
      'type' => 'hidden',
      'weight' => 0,
    ); /* WAS: '' */
  }
  if (isset($data['node-market-body'])) {
    $data['node-market-body']['display']['secondary_teaser'] = array(
      'label' => 'above',
      'settings' => array(),
      'type' => 'hidden',
      'weight' => 0,
    ); /* WAS: '' */
  }
  if (isset($data['node-market-field_content_edited'])) {
    $data['node-market-field_content_edited']['display']['secondary_teaser'] = array(
      'label' => 'above',
      'settings' => array(),
      'type' => 'hidden',
      'weight' => 0,
    ); /* WAS: '' */
  }
  if (isset($data['node-market-field_image'])) {
    $data['node-market-field_image']['display']['secondary_teaser'] = array(
      'label' => 'above',
      'settings' => array(),
      'type' => 'hidden',
      'weight' => 0,
    ); /* WAS: '' */
  }
  if (isset($data['node-market-field_market'])) {
    $data['node-market-field_market']['display']['secondary_teaser'] = array(
      'label' => 'above',
      'settings' => array(),
      'type' => 'hidden',
      'weight' => 0,
    ); /* WAS: '' */
  }
  if (isset($data['node-package-body'])) {
    $data['node-package-body']['display']['secondary_teaser'] = array(
      'label' => 'above',
      'settings' => array(),
      'type' => 'hidden',
      'weight' => 0,
    ); /* WAS: '' */
  }
  if (isset($data['node-package-field_call_out'])) {
    $data['node-package-field_call_out']['display']['secondary_teaser'] = array(
      'label' => 'above',
      'settings' => array(),
      'type' => 'hidden',
      'weight' => 0,
    ); /* WAS: '' */
  }
  if (isset($data['node-package-field_content_edited'])) {
    $data['node-package-field_content_edited']['display']['secondary_teaser'] = array(
      'label' => 'above',
      'settings' => array(),
      'type' => 'hidden',
      'weight' => 0,
    ); /* WAS: '' */
  }
  if (isset($data['node-package-field_display_title'])) {
    $data['node-package-field_display_title']['display']['secondary_teaser'] = array(
      'label' => 'above',
      'settings' => array(),
      'type' => 'hidden',
      'weight' => 0,
    ); /* WAS: '' */
  }
  if (isset($data['node-package-field_icon'])) {
    $data['node-package-field_icon']['display']['secondary_teaser'] = array(
      'label' => 'above',
      'settings' => array(),
      'type' => 'hidden',
      'weight' => 0,
    ); /* WAS: '' */
  }
  if (isset($data['node-package-field_image'])) {
    $data['node-package-field_image']['display']['secondary_teaser'] = array(
      'label' => 'above',
      'settings' => array(),
      'type' => 'hidden',
      'weight' => 0,
    ); /* WAS: '' */
  }
  if (isset($data['node-package-field_intro'])) {
    $data['node-package-field_intro']['display']['secondary_teaser'] = array(
      'label' => 'above',
      'settings' => array(),
      'type' => 'hidden',
      'weight' => 0,
    ); /* WAS: '' */
  }
  if (isset($data['node-package-field_services'])) {
    $data['node-package-field_services']['display']['secondary_teaser'] = array(
      'label' => 'above',
      'settings' => array(),
      'type' => 'hidden',
      'weight' => 0,
    ); /* WAS: '' */
  }
  if (isset($data['node-page-body'])) {
    $data['node-page-body']['display']['secondary_teaser'] = array(
      'label' => 'above',
      'settings' => array(),
      'type' => 'hidden',
      'weight' => 0,
    ); /* WAS: '' */
  }
  if (isset($data['node-page-field_attachments'])) {
    $data['node-page-field_attachments']['display']['secondary_teaser'] = array(
      'label' => 'above',
      'settings' => array(),
      'type' => 'hidden',
      'weight' => 0,
    ); /* WAS: '' */
  }
  if (isset($data['node-page-field_content_edited'])) {
    $data['node-page-field_content_edited']['display']['secondary_teaser'] = array(
      'label' => 'above',
      'settings' => array(),
      'type' => 'hidden',
      'weight' => 0,
    ); /* WAS: '' */
  }
  if (isset($data['node-page-field_display_title'])) {
    $data['node-page-field_display_title']['display']['secondary_teaser'] = array(
      'label' => 'above',
      'settings' => array(),
      'type' => 'hidden',
      'weight' => 0,
    ); /* WAS: '' */
  }
  if (isset($data['node-page-field_image'])) {
    $data['node-page-field_image']['display']['secondary_teaser'] = array(
      'label' => 'above',
      'settings' => array(),
      'type' => 'hidden',
      'weight' => 0,
    ); /* WAS: '' */
  }
  if (isset($data['node-page-field_intro'])) {
    $data['node-page-field_intro']['display']['secondary_teaser'] = array(
      'label' => 'above',
      'settings' => array(),
      'type' => 'hidden',
      'weight' => 0,
    ); /* WAS: '' */
  }
  if (isset($data['node-page-field_seo_title'])) {
    $data['node-page-field_seo_title']['display']['secondary_teaser'] = array(
      'label' => 'above',
      'settings' => array(),
      'type' => 'hidden',
      'weight' => 0,
    ); /* WAS: '' */
  }
  if (isset($data['node-profile-body'])) {
    $data['node-profile-body']['display']['secondary_teaser'] = array(
      'label' => 'above',
      'settings' => array(),
      'type' => 'hidden',
      'weight' => 0,
    ); /* WAS: '' */
  }
  if (isset($data['node-profile-field_content_edited'])) {
    $data['node-profile-field_content_edited']['display']['secondary_teaser'] = array(
      'label' => 'above',
      'settings' => array(),
      'type' => 'hidden',
      'weight' => 0,
    ); /* WAS: '' */
  }
  if (isset($data['node-profile-field_image'])) {
    $data['node-profile-field_image']['display']['secondary_teaser'] = array(
      'label' => 'above',
      'settings' => array(),
      'type' => 'hidden',
      'weight' => 0,
    ); /* WAS: '' */
  }
  if (isset($data['node-profile-field_position'])) {
    $data['node-profile-field_position']['display']['secondary_teaser'] = array(
      'label' => 'above',
      'settings' => array(),
      'type' => 'hidden',
      'weight' => 0,
    ); /* WAS: '' */
  }
  if (isset($data['node-region-body'])) {
    $data['node-region-body']['display']['secondary_teaser'] = array(
      'label' => 'above',
      'settings' => array(),
      'type' => 'hidden',
      'weight' => 0,
    ); /* WAS: '' */
  }
  if (isset($data['node-region-field_content_edited'])) {
    $data['node-region-field_content_edited']['display']['secondary_teaser'] = array(
      'label' => 'above',
      'settings' => array(),
      'type' => 'hidden',
      'weight' => 0,
    ); /* WAS: '' */
  }
  if (isset($data['node-region-field_image'])) {
    $data['node-region-field_image']['display']['secondary_teaser'] = array(
      'label' => 'above',
      'settings' => array(),
      'type' => 'hidden',
      'weight' => 0,
    ); /* WAS: '' */
  }
  if (isset($data['node-region-field_region'])) {
    $data['node-region-field_region']['display']['secondary_teaser'] = array(
      'label' => 'above',
      'settings' => array(),
      'type' => 'hidden',
      'weight' => 0,
    ); /* WAS: '' */
  }
  if (isset($data['node-service-body'])) {
    $data['node-service-body']['display']['secondary_teaser'] = array(
      'label' => 'above',
      'settings' => array(),
      'type' => 'hidden',
      'weight' => 0,
    ); /* WAS: '' */
  }
  if (isset($data['node-service-field_call_out'])) {
    $data['node-service-field_call_out']['display']['secondary_teaser'] = array(
      'label' => 'above',
      'settings' => array(),
      'type' => 'hidden',
      'weight' => 0,
    ); /* WAS: '' */
  }
  if (isset($data['node-service-field_content_edited'])) {
    $data['node-service-field_content_edited']['display']['secondary_teaser'] = array(
      'label' => 'above',
      'settings' => array(),
      'type' => 'hidden',
      'weight' => 0,
    ); /* WAS: '' */
  }
  if (isset($data['node-service-field_display_title'])) {
    $data['node-service-field_display_title']['display']['secondary_teaser'] = array(
      'label' => 'above',
      'settings' => array(),
      'type' => 'hidden',
      'weight' => 0,
    ); /* WAS: '' */
  }
  if (isset($data['node-service-field_icon'])) {
    $data['node-service-field_icon']['display']['secondary_teaser'] = array(
      'label' => 'above',
      'settings' => array(),
      'type' => 'hidden',
      'weight' => 0,
    ); /* WAS: '' */
    $data['node-service-field_icon']['settings']['default_image'] = 3; /* WAS: 0 */
  }
  if (isset($data['node-service-field_image'])) {
    $data['node-service-field_image']['display']['secondary_teaser'] = array(
      'label' => 'above',
      'settings' => array(),
      'type' => 'hidden',
      'weight' => 0,
    ); /* WAS: '' */
    $data['node-service-field_image']['settings']['default_image'] = 5; /* WAS: 0 */
  }
  if (isset($data['node-service-field_intro'])) {
    $data['node-service-field_intro']['display']['secondary_teaser'] = array(
      'label' => 'above',
      'settings' => array(),
      'type' => 'hidden',
      'weight' => 0,
    ); /* WAS: '' */
  }
  if (isset($data['node-service-field_package_intro'])) {
    $data['node-service-field_package_intro']['display']['secondary_teaser'] = array(
      'label' => 'above',
      'settings' => array(),
      'type' => 'hidden',
      'weight' => 0,
    ); /* WAS: '' */
  }
  if (isset($data['node-service-field_seo_title'])) {
    $data['node-service-field_seo_title']['display']['secondary_teaser'] = array(
      'label' => 'above',
      'settings' => array(),
      'type' => 'hidden',
      'weight' => 0,
    ); /* WAS: '' */
  }
  if (isset($data['node-service-field_service'])) {
    $data['node-service-field_service']['display']['secondary_teaser'] = array(
      'label' => 'above',
      'settings' => array(),
      'type' => 'hidden',
      'weight' => 0,
    ); /* WAS: '' */
  }
  if (isset($data['node-slide-body'])) {
    $data['node-slide-body']['display']['secondary_teaser'] = array(
      'label' => 'above',
      'settings' => array(),
      'type' => 'hidden',
      'weight' => 0,
    ); /* WAS: '' */
  }
  if (isset($data['node-slide-field_color'])) {
    $data['node-slide-field_color']['display']['alt_teaser']['weight'] = 5; /* WAS: 0 */
    $data['node-slide-field_color']['display']['secondary_teaser'] = array(
      'label' => 'above',
      'settings' => array(),
      'type' => 'hidden',
      'weight' => 0,
    ); /* WAS: '' */
  }
  if (isset($data['node-slide-field_content_edited'])) {
    $data['node-slide-field_content_edited']['display']['alt_teaser']['weight'] = 4; /* WAS: 0 */
    $data['node-slide-field_content_edited']['display']['secondary_teaser'] = array(
      'label' => 'above',
      'settings' => array(),
      'type' => 'hidden',
      'weight' => 0,
    ); /* WAS: '' */
  }
  if (isset($data['node-slide-field_image'])) {
    $data['node-slide-field_image']['display']['alt_teaser']['weight'] = 1; /* WAS: 0 */
    $data['node-slide-field_image']['display']['secondary_teaser'] = array(
      'label' => 'above',
      'settings' => array(),
      'type' => 'hidden',
      'weight' => 0,
    ); /* WAS: '' */
  }
  if (isset($data['node-slide-field_market'])) {
    $data['node-slide-field_market']['display']['alt_teaser']['weight'] = 2; /* WAS: 0 */
    $data['node-slide-field_market']['display']['secondary_teaser'] = array(
      'label' => 'above',
      'settings' => array(),
      'type' => 'hidden',
      'weight' => 0,
    ); /* WAS: '' */
  }
  if (isset($data['node-slide-field_service'])) {
    $data['node-slide-field_service']['display']['alt_teaser']['weight'] = 3; /* WAS: 0 */
    $data['node-slide-field_service']['display']['secondary_teaser'] = array(
      'label' => 'above',
      'settings' => array(),
      'type' => 'hidden',
      'weight' => 0,
    ); /* WAS: '' */
  }
  if (isset($data['node-special_offer-body'])) {
    $data['node-special_offer-body']['display']['secondary_teaser'] = array(
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
    ); /* WAS: '' */
  }
  if (isset($data['node-special_offer-field_button'])) {
    $data['node-special_offer-field_button']['display']['default']['label'] = 'hidden'; /* WAS: 'above' */
    $data['node-special_offer-field_button']['display']['default']['type'] = 'hidden'; /* WAS: 'link_default' */
    $data['node-special_offer-field_button']['display']['secondary_teaser'] = array(
      'label' => 'hidden',
      'module' => 'link',
      'settings' => array(),
      'type' => 'link_default',
      'weight' => 3,
    ); /* WAS: '' */
    $data['node-special_offer-field_button']['widget']['weight'] = 53; /* WAS: 51 */
    unset($data['node-special_offer-field_button']['display']['default']['module']);
  }
  if (isset($data['node-special_offer-field_content_edited'])) {
    $data['node-special_offer-field_content_edited']['display']['secondary_teaser'] = array(
      'label' => 'above',
      'settings' => array(),
      'type' => 'hidden',
      'weight' => 10,
    ); /* WAS: '' */
  }
  if (isset($data['node-special_offer-field_expiration_date'])) {
    $data['node-special_offer-field_expiration_date']['display']['secondary_teaser'] = array(
      'label' => 'above',
      'settings' => array(),
      'type' => 'hidden',
      'weight' => 8,
    ); /* WAS: '' */
    $data['node-special_offer-field_expiration_date']['widget']['weight'] = 52; /* WAS: 50 */
  }
  if (isset($data['node-special_offer-field_image'])) {
    $data['node-special_offer-field_image']['display']['secondary_teaser'] = array(
      'label' => 'above',
      'settings' => array(),
      'type' => 'hidden',
      'weight' => 9,
    ); /* WAS: '' */
  }
  if (isset($data['node-special_offer-field_offer_price'])) {
    $data['node-special_offer-field_offer_price']['display']['secondary_teaser'] = array(
      'label' => 'above',
      'settings' => array(),
      'type' => 'hidden',
      'weight' => 7,
    ); /* WAS: '' */
    $data['node-special_offer-field_offer_price']['widget']['weight'] = 49; /* WAS: 47 */
  }
  if (isset($data['node-special_offer-field_original_price'])) {
    $data['node-special_offer-field_original_price']['display']['secondary_teaser'] = array(
      'label' => 'above',
      'settings' => array(),
      'type' => 'hidden',
      'weight' => 6,
    ); /* WAS: '' */
    $data['node-special_offer-field_original_price']['widget']['weight'] = 48; /* WAS: 46 */
  }
  if (isset($data['node-special_offer-field_package'])) {
    $data['node-special_offer-field_package']['display']['secondary_teaser'] = array(
      'label' => 'above',
      'settings' => array(),
      'type' => 'hidden',
      'weight' => 4,
    ); /* WAS: '' */
    $data['node-special_offer-field_package']['widget']['weight'] = 51; /* WAS: 49 */
  }
  if (isset($data['node-special_offer-field_services'])) {
    $data['node-special_offer-field_services']['display']['default']['type'] = 'hidden'; /* WAS: 'taxonomy_term_reference_link' */
    $data['node-special_offer-field_services']['display']['secondary_teaser'] = array(
      'label' => 'above',
      'settings' => array(),
      'type' => 'hidden',
      'weight' => 5,
    ); /* WAS: '' */
    $data['node-special_offer-field_services']['widget']['weight'] = 50; /* WAS: 48 */
    unset($data['node-special_offer-field_services']['display']['default']['module']);
  }
  if (isset($data['node-testimonial-body'])) {
    $data['node-testimonial-body']['display']['secondary_teaser'] = array(
      'label' => 'above',
      'settings' => array(),
      'type' => 'hidden',
      'weight' => 0,
    ); /* WAS: '' */
  }
  if (isset($data['node-testimonial-field_content_edited'])) {
    $data['node-testimonial-field_content_edited']['display']['secondary_teaser'] = array(
      'label' => 'above',
      'settings' => array(),
      'type' => 'hidden',
      'weight' => 0,
    ); /* WAS: '' */
  }
  if (isset($data['node-testimonial-field_market'])) {
    $data['node-testimonial-field_market']['display']['secondary_teaser'] = array(
      'label' => 'above',
      'settings' => array(),
      'type' => 'hidden',
      'weight' => 0,
    ); /* WAS: '' */
  }
  if (isset($data['node-testimonial-field_service'])) {
    $data['node-testimonial-field_service']['display']['secondary_teaser'] = array(
      'label' => 'above',
      'settings' => array(),
      'type' => 'hidden',
      'weight' => 0,
    ); /* WAS: '' */
  }
  if (isset($data['node-webform-body'])) {
    $data['node-webform-body']['display']['secondary_teaser'] = array(
      'label' => 'above',
      'settings' => array(),
      'type' => 'hidden',
      'weight' => 0,
    ); /* WAS: '' */
  }
}

/**
 * Implements hook_flexslider_default_presets_alter().
 */
function sprowt_4_flexslider_default_presets_alter(&$data) {
  if (isset($data['default'])) {
    unset($data['default']->export_type);
    unset($data['default']->type);
  }
}

/**
 * Implements hook_image_styles_alter().
 */
function sprowt_4_image_styles_alter(&$data) {
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
function sprowt_4_strongarm_alter(&$data) {
  if (isset($data['entity_view_modes'])) {
    $data['entity_view_modes']->value['node']['secondary_teaser'] = array(
      'label' => 'Secondary teaser',
      'custom settings' => 1,
    ); /* WAS: '' */
  }
  if (isset($data['field_bundle_settings_node__affiliation'])) {
    $data['field_bundle_settings_node__affiliation']->value['view_modes']['secondary_teaser'] = array(
      'custom_settings' => TRUE,
    ); /* WAS: '' */
  }
  if (isset($data['field_bundle_settings_node__benefit'])) {
    $data['field_bundle_settings_node__benefit']->value['view_modes']['secondary_teaser'] = array(
      'custom_settings' => TRUE,
    ); /* WAS: '' */
  }
  if (isset($data['field_bundle_settings_node__blog'])) {
    $data['field_bundle_settings_node__blog']->value['view_modes']['secondary_teaser'] = array(
      'custom_settings' => TRUE,
    ); /* WAS: '' */
  }
  if (isset($data['field_bundle_settings_node__cta'])) {
    $data['field_bundle_settings_node__cta']->value['view_modes']['secondary_teaser'] = array(
      'custom_settings' => TRUE,
    ); /* WAS: '' */
  }
  if (isset($data['field_bundle_settings_node__faq'])) {
    $data['field_bundle_settings_node__faq']->value['view_modes']['secondary_teaser'] = array(
      'custom_settings' => TRUE,
    ); /* WAS: '' */
  }
  if (isset($data['field_bundle_settings_node__gallery_image'])) {
    $data['field_bundle_settings_node__gallery_image']->value['view_modes']['secondary_teaser'] = array(
      'custom_settings' => TRUE,
    ); /* WAS: '' */
  }
  if (isset($data['field_bundle_settings_node__landing_page'])) {
    $data['field_bundle_settings_node__landing_page']->value['view_modes']['secondary_teaser'] = array(
      'custom_settings' => TRUE,
    ); /* WAS: '' */
  }
  if (isset($data['field_bundle_settings_node__localtarget'])) {
    $data['field_bundle_settings_node__localtarget']->value['view_modes']['secondary_teaser'] = array(
      'custom_settings' => TRUE,
    ); /* WAS: '' */
  }
  if (isset($data['field_bundle_settings_node__location'])) {
    $data['field_bundle_settings_node__location']->value['view_modes']['secondary_teaser'] = array(
      'custom_settings' => TRUE,
    ); /* WAS: '' */
  }
  if (isset($data['field_bundle_settings_node__market'])) {
    $data['field_bundle_settings_node__market']->value['view_modes']['secondary_teaser'] = array(
      'custom_settings' => TRUE,
    ); /* WAS: '' */
  }
  if (isset($data['field_bundle_settings_node__package'])) {
    $data['field_bundle_settings_node__package']->value['view_modes']['secondary_teaser'] = array(
      'custom_settings' => TRUE,
    ); /* WAS: '' */
  }
  if (isset($data['field_bundle_settings_node__page'])) {
    $data['field_bundle_settings_node__page']->value['view_modes']['secondary_teaser'] = array(
      'custom_settings' => TRUE,
    ); /* WAS: '' */
  }
  if (isset($data['field_bundle_settings_node__profile'])) {
    $data['field_bundle_settings_node__profile']->value['view_modes']['secondary_teaser'] = array(
      'custom_settings' => TRUE,
    ); /* WAS: '' */
  }
  if (isset($data['field_bundle_settings_node__region'])) {
    $data['field_bundle_settings_node__region']->value['view_modes']['secondary_teaser'] = array(
      'custom_settings' => TRUE,
    ); /* WAS: '' */
  }
  if (isset($data['field_bundle_settings_node__service'])) {
    $data['field_bundle_settings_node__service']->value['view_modes']['secondary_teaser'] = array(
      'custom_settings' => TRUE,
    ); /* WAS: '' */
  }
  if (isset($data['field_bundle_settings_node__slide'])) {
    $data['field_bundle_settings_node__slide']->value['view_modes']['secondary_teaser'] = array(
      'custom_settings' => TRUE,
    ); /* WAS: '' */
  }
  if (isset($data['field_bundle_settings_node__special_offer'])) {
    $data['field_bundle_settings_node__special_offer']->value['view_modes']['secondary_teaser'] = array(
      'custom_settings' => TRUE,
    ); /* WAS: '' */
  }
  if (isset($data['field_bundle_settings_node__testimonial'])) {
    $data['field_bundle_settings_node__testimonial']->value['view_modes']['secondary_teaser'] = array(
      'custom_settings' => TRUE,
    ); /* WAS: '' */
  }
  if (isset($data['field_bundle_settings_node__webform'])) {
    $data['field_bundle_settings_node__webform']->value['view_modes']['secondary_teaser'] = array(
      'custom_settings' => TRUE,
    ); /* WAS: '' */
  }
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
function sprowt_4_views_default_views_alter(&$data) {
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
  if (isset($data['benefits'])) {
    $data['benefits']->display['front_s4'] = unserialize('O:13:"views_display":7:{s:15:"display_options";a:6:{s:5:"query";a:2:{s:4:"type";s:11:"views_query";s:7:"options";a:0:{}}s:8:"defaults";a:6:{s:12:"style_plugin";b:0;s:13:"style_options";b:0;s:10:"row_plugin";b:0;s:11:"row_options";b:0;s:13:"filter_groups";b:0;s:7:"filters";b:0;}s:12:"style_plugin";s:7:"default";s:10:"row_plugin";s:4:"node";s:11:"row_options";a:2:{s:9:"view_mode";s:16:"secondary_teaser";s:5:"links";b:0;}s:7:"filters";a:3:{s:6:"status";a:6:{s:2:"id";s:6:"status";s:5:"table";s:4:"node";s:5:"field";s:6:"status";s:5:"value";i:1;s:5:"group";i:1;s:6:"expose";a:1:{s:8:"operator";b:0;}}s:4:"type";a:4:{s:2:"id";s:4:"type";s:5:"table";s:4:"node";s:5:"field";s:4:"type";s:5:"value";a:1:{s:7:"benefit";s:7:"benefit";}}s:7:"promote";a:4:{s:2:"id";s:7:"promote";s:5:"table";s:4:"node";s:5:"field";s:7:"promote";s:5:"value";s:1:"1";}}}s:8:"db_table";s:13:"views_display";s:3:"vid";i:0;s:2:"id";s:8:"front_s4";s:13:"display_title";s:24:"Front page benefits (S4)";s:14:"display_plugin";s:5:"block";s:8:"position";i:0;}'); /* WAS: '' */
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
  if (isset($data['localtarget'])) {
    $data['localtarget']->display['title_s4'] = unserialize('O:13:"views_display":7:{s:15:"display_options";a:6:{s:5:"query";a:2:{s:4:"type";s:11:"views_query";s:7:"options";a:0:{}}s:8:"defaults";a:3:{s:5:"title";b:0;s:6:"fields";b:0;s:9:"arguments";b:0;}s:5:"title";s:6:"<none>";s:6:"fields";a:1:{s:5:"title";a:7:{s:2:"id";s:5:"title";s:5:"table";s:4:"node";s:5:"field";s:5:"title";s:5:"label";s:0:"";s:5:"alter";a:4:{s:10:"alter_text";b:1;s:4:"text";s:16:"<h1>[title]</h1>";s:13:"word_boundary";b:0;s:8:"ellipsis";b:0;}s:19:"element_label_colon";b:0;s:12:"link_to_node";b:0;}}s:9:"arguments";a:1:{s:3:"nid";a:7:{s:2:"id";s:3:"nid";s:5:"table";s:4:"node";s:5:"field";s:3:"nid";s:14:"default_action";s:7:"default";s:21:"default_argument_type";s:4:"node";s:7:"summary";a:2:{s:17:"number_of_records";s:1:"0";s:6:"format";s:15:"default_summary";}s:15:"summary_options";a:1:{s:14:"items_per_page";s:2:"25";}}}s:17:"block_description";s:23:"Local Target Title (S4)";}s:8:"db_table";s:13:"views_display";s:3:"vid";i:0;s:2:"id";s:8:"title_s4";s:13:"display_title";s:23:"Local Target Title (S4)";s:14:"display_plugin";s:5:"block";s:8:"position";i:0;}'); /* WAS: '' */
  }
  if (isset($data['services'])) {
    $data['services']->display['front_s4'] = unserialize('O:13:"views_display":7:{s:15:"display_options";a:5:{s:5:"query";a:2:{s:4:"type";s:11:"views_query";s:7:"options";a:0:{}}s:8:"defaults";a:4:{s:12:"style_plugin";b:0;s:13:"style_options";b:0;s:10:"row_plugin";b:0;s:11:"row_options";b:0;}s:12:"style_plugin";s:7:"default";s:10:"row_plugin";s:4:"node";s:17:"block_description";s:24:"Front Page Services (S4)";}s:8:"db_table";s:13:"views_display";s:3:"vid";i:0;s:2:"id";s:8:"front_s4";s:13:"display_title";s:24:"Front Page Services (S4)";s:14:"display_plugin";s:5:"block";s:8:"position";i:0;}'); /* WAS: '' */
  }
  if (isset($data['special_offers'])) {
    $data['special_offers']->display['front_s4'] = unserialize('O:13:"views_display":7:{s:15:"display_options";a:7:{s:5:"query";a:2:{s:4:"type";s:11:"views_query";s:7:"options";a:0:{}}s:8:"defaults";a:7:{s:5:"title";b:0;s:5:"pager";b:0;s:12:"style_plugin";b:0;s:13:"style_options";b:0;s:10:"row_plugin";b:0;s:11:"row_options";b:0;s:5:"sorts";b:0;}s:5:"pager";a:2:{s:4:"type";s:4:"some";s:7:"options";a:2:{s:14:"items_per_page";s:1:"1";s:6:"offset";s:1:"0";}}s:12:"style_plugin";s:7:"default";s:10:"row_plugin";s:4:"node";s:11:"row_options";a:2:{s:9:"view_mode";s:16:"secondary_teaser";s:5:"links";b:0;}s:5:"sorts";a:1:{s:6:"random";a:3:{s:2:"id";s:6:"random";s:5:"table";s:5:"views";s:5:"field";s:6:"random";}}}s:8:"db_table";s:13:"views_display";s:3:"vid";i:0;s:2:"id";s:8:"front_s4";s:13:"display_title";s:13:"Homepage (S4)";s:14:"display_plugin";s:5:"block";s:8:"position";i:0;}'); /* WAS: '' */
    $data['special_offers']->display['ltp_s4'] = unserialize('O:13:"views_display":7:{s:15:"display_options";a:8:{s:5:"query";a:2:{s:4:"type";s:11:"views_query";s:7:"options";a:0:{}}s:8:"defaults";a:8:{s:5:"title";b:0;s:5:"pager";b:0;s:12:"style_plugin";b:0;s:13:"style_options";b:0;s:10:"row_plugin";b:0;s:11:"row_options";b:0;s:5:"sorts";b:0;s:9:"arguments";b:0;}s:5:"pager";a:2:{s:4:"type";s:4:"some";s:7:"options";a:2:{s:14:"items_per_page";s:1:"1";s:6:"offset";s:1:"0";}}s:12:"style_plugin";s:7:"default";s:10:"row_plugin";s:4:"node";s:11:"row_options";a:1:{s:5:"links";b:0;}s:5:"sorts";a:1:{s:6:"random";a:3:{s:2:"id";s:6:"random";s:5:"table";s:5:"views";s:5:"field";s:6:"random";}}s:9:"arguments";a:2:{s:3:"tid";a:8:{s:2:"id";s:3:"tid";s:5:"table";s:14:"taxonomy_index";s:5:"field";s:3:"tid";s:14:"default_action";s:7:"default";s:21:"default_argument_type";s:12:"taxonomy_tid";s:24:"default_argument_options";a:4:{s:4:"node";b:1;s:6:"anyall";s:1:"+";s:5:"limit";b:1;s:12:"vocabularies";a:1:{s:8:"services";s:8:"services";}}s:7:"summary";a:2:{s:17:"number_of_records";s:1:"0";s:6:"format";s:15:"default_summary";}s:15:"summary_options";a:1:{s:14:"items_per_page";s:2:"25";}}s:3:"nid";a:8:{s:2:"id";s:3:"nid";s:5:"table";s:4:"node";s:5:"field";s:3:"nid";s:14:"default_action";s:7:"default";s:21:"default_argument_type";s:4:"node";s:7:"summary";a:2:{s:17:"number_of_records";s:1:"0";s:6:"format";s:15:"default_summary";}s:15:"summary_options";a:1:{s:14:"items_per_page";s:2:"25";}s:3:"not";b:1;}}}s:8:"db_table";s:13:"views_display";s:3:"vid";i:0;s:2:"id";s:6:"ltp_s4";s:13:"display_title";s:16:"LTP Content (S4)";s:14:"display_plugin";s:5:"block";s:8:"position";i:0;}'); /* WAS: '' */
    $data['special_offers']->display['related_s4'] = unserialize('O:13:"views_display":7:{s:15:"display_options";a:8:{s:5:"query";a:2:{s:4:"type";s:11:"views_query";s:7:"options";a:0:{}}s:8:"defaults";a:8:{s:5:"title";b:0;s:5:"pager";b:0;s:12:"style_plugin";b:0;s:13:"style_options";b:0;s:10:"row_plugin";b:0;s:11:"row_options";b:0;s:5:"sorts";b:0;s:9:"arguments";b:0;}s:5:"pager";a:2:{s:4:"type";s:4:"some";s:7:"options";a:2:{s:14:"items_per_page";s:1:"1";s:6:"offset";s:1:"0";}}s:12:"style_plugin";s:7:"default";s:10:"row_plugin";s:4:"node";s:11:"row_options";a:2:{s:9:"view_mode";s:16:"secondary_teaser";s:5:"links";b:0;}s:5:"sorts";a:1:{s:6:"random";a:3:{s:2:"id";s:6:"random";s:5:"table";s:5:"views";s:5:"field";s:6:"random";}}s:9:"arguments";a:2:{s:3:"tid";a:8:{s:2:"id";s:3:"tid";s:5:"table";s:14:"taxonomy_index";s:5:"field";s:3:"tid";s:14:"default_action";s:7:"default";s:21:"default_argument_type";s:12:"taxonomy_tid";s:24:"default_argument_options";a:4:{s:4:"node";b:1;s:6:"anyall";s:1:"+";s:5:"limit";b:1;s:12:"vocabularies";a:1:{s:8:"services";s:8:"services";}}s:7:"summary";a:2:{s:17:"number_of_records";s:1:"0";s:6:"format";s:15:"default_summary";}s:15:"summary_options";a:1:{s:14:"items_per_page";s:2:"25";}}s:3:"nid";a:8:{s:2:"id";s:3:"nid";s:5:"table";s:4:"node";s:5:"field";s:3:"nid";s:14:"default_action";s:7:"default";s:21:"default_argument_type";s:4:"node";s:7:"summary";a:2:{s:17:"number_of_records";s:1:"0";s:6:"format";s:15:"default_summary";}s:15:"summary_options";a:1:{s:14:"items_per_page";s:2:"25";}s:3:"not";b:1;}}}s:8:"db_table";s:13:"views_display";s:3:"vid";i:0;s:2:"id";s:10:"related_s4";s:13:"display_title";s:12:"Related (S4)";s:14:"display_plugin";s:5:"block";s:8:"position";i:0;}'); /* WAS: '' */
    unset($data['special_offers']->display['list']->display_options['block_description']);
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
  if (isset($data['testimonials'])) {
    $data['testimonials']->display['front_s4'] = unserialize('O:13:"views_display":7:{s:15:"display_options";a:4:{s:5:"query";a:2:{s:4:"type";s:11:"views_query";s:7:"options";a:0:{}}s:8:"defaults";a:3:{s:5:"title";b:0;s:13:"filter_groups";b:0;s:7:"filters";b:0;}s:5:"title";s:29:"What Our Customers Are Saying";s:7:"filters";a:3:{s:6:"status";a:6:{s:2:"id";s:6:"status";s:5:"table";s:4:"node";s:5:"field";s:6:"status";s:5:"value";i:1;s:5:"group";i:1;s:6:"expose";a:1:{s:8:"operator";b:0;}}s:4:"type";a:4:{s:2:"id";s:4:"type";s:5:"table";s:4:"node";s:5:"field";s:4:"type";s:5:"value";a:1:{s:11:"testimonial";s:11:"testimonial";}}s:7:"promote";a:4:{s:2:"id";s:7:"promote";s:5:"table";s:4:"node";s:5:"field";s:7:"promote";s:5:"value";s:1:"1";}}}s:8:"db_table";s:13:"views_display";s:3:"vid";i:0;s:2:"id";s:8:"front_s4";s:13:"display_title";s:27:"Front page testimonial (S4)";s:14:"display_plugin";s:5:"block";s:8:"position";i:0;}'); /* WAS: '' */
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
