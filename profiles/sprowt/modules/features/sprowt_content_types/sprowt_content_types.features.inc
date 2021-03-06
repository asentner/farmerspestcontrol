<?php

/**
 * @file
 * sprowt_content_types.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function sprowt_content_types_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "field_group" && $api == "field_group") {
    return array("version" => "1");
  }
  if ($module == "flexslider" && $api == "flexslider_default_preset") {
    return array("version" => "1");
  }
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_node_info().
 */
function sprowt_content_types_node_info() {
  $items = array(
    'affiliation' => array(
      'name' => t('Affiliation'),
      'base' => 'node_content',
      'description' => t('An <em>affiliation</em> is an organization your company is associated with or an award your company has won.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
    'benefit' => array(
      'name' => t('Benefit'),
      'base' => 'node_content',
      'description' => t('Use <em>benefits</em> to show your customers how your product will make their lives easier.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
    'blog' => array(
      'name' => t('Blog'),
      'base' => 'node_content',
      'description' => t('Blog posts are associated with both a <em>service area</em> and <em>service</em>.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
    'cta' => array(
      'name' => t('Call to action'),
      'base' => 'node_content',
      'description' => t('Create a callout to call a user\'s attention. Typically used in the sidebar or at the end of content.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
    'faq' => array(
      'name' => t('FAQ'),
      'base' => 'node_content',
      'description' => t('Add a question and answer about your services.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
    'localtarget' => array(
      'name' => t('LocalTarget'),
      'base' => 'node_content',
      'description' => t('To add a LocalTarget page, please add a <a href="/admin/structure/taxonomy/markets/add">market term</a> and a <a href="/admin/structure/taxonomy/services/add">service term</a> and a node will be generated automatically.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
    'location' => array(
      'name' => t('Location'),
      'base' => 'node_content',
      'description' => t('Use <em>locations</em> to add office locations. This is different from <em>service area</em> and should only include physical offices.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
    'market' => array(
      'name' => t('Market'),
      'base' => 'node_content',
      'description' => t('To add a market, please <a href="/admin/structure/taxonomy/markets/add">add a market term</a> and a node will be generated automatically.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
    'package' => array(
      'name' => t('Package'),
      'base' => 'node_content',
      'description' => t('Packages are associated with a <em>service</em>.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
    'page' => array(
      'name' => t('Basic page'),
      'base' => 'node_content',
      'description' => t('Use <em>basic pages</em> for your static content, such as an \'About us\' page.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
    'profile' => array(
      'name' => t('Profile'),
      'base' => 'node_content',
      'description' => t('Add a <em>profile</em> for each member on your company\'s team.'),
      'has_title' => '1',
      'title_label' => t('Name'),
      'help' => '',
    ),
    'region' => array(
      'name' => t('Region'),
      'base' => 'node_content',
      'description' => t('To add a region, please <a href="/admin/structure/taxonomy/regions/add">add a region term</a> and a node will be generated automatically.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
    'service' => array(
      'name' => t('Service'),
      'base' => 'node_content',
      'description' => t('To add a service, please <a href="/admin/structure/taxonomy/services/add">add a service term</a> and a node will be generated automatically.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
    'slide' => array(
      'name' => t('Slideshow slide'),
      'base' => 'node_content',
      'description' => t('Use a <em>slideshow slide</em> to create a front-and-center callout on the front page.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
    'special_offer' => array(
      'name' => t('Special offer'),
      'base' => 'node_content',
      'description' => t('Create <em>special offers</em> to highlight an excellent deal on a <em>package</em>.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
    'testimonial' => array(
      'name' => t('Testimonial'),
      'base' => 'node_content',
      'description' => t('Show your customer social proof with <em>testimonials</em> from previous clients.'),
      'has_title' => '1',
      'title_label' => t('Name of reviewer'),
      'help' => '',
    ),
    'webform' => array(
      'name' => t('Webform'),
      'base' => 'node_content',
      'description' => t('Create a new form or questionnaire accessible to users. Submission results and statistics are recorded and accessible to privileged users.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}
