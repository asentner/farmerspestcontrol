<?php

function sprout_starter_breadcrumb($variables) {
  $breadcrumb = $variables['breadcrumb'];

  $returnString = function($string) {
    return $string;
  };

  $replace = (function_exists('_leadbuilder_settings_shortcode_replace')) ? '_leadbuilder_settings_shortcode_replace' : $returnString;

  if (drupal_is_front_page()) {
    $breadcrumb = array();
  }
  else if ($node = menu_get_object()) {
    if ($node->type == 'localtarget') {
      $breadcrumb = array();
    }
    else {
      if ($node->type == 'blog') {
        $localtarget = db_query("SELECT nid, title FROM {node} n
          LEFT JOIN {field_data_field_market} m ON n.nid=m.entity_id
          LEFT JOIN {field_data_field_service} s ON n.nid=s.entity_id
          WHERE field_market_tid=:mtid AND field_service_tid=:stid AND type='localtarget'",
          array(':mtid' => $node->field_market['und'][0]['tid'], ':stid' => $node->field_service['und'][0]['tid']))->fetchObject();

        $breadcrumb[] = l('Services', 'services');
        $breadcrumb[] = l($localtarget->title, 'node/'.$localtarget->nid);
      }
      // else if ($node->type == 'service') {
      //   $breadcrumb = array(l('Home', '')); //Reset breadcrumb due to fly-out menu
      //   $breadcrumb[] = l('Services', 'services');
      // }
      // else if ($node->type == 'profile') {
      //   $breadcrumb[] = l('About', 'about');
      //   $breadcrumb[] = l('Team', 'about/team');
      // }

      $breadcrumb[] = $replace($node->title);
    }
  }

  if (!empty($breadcrumb)) {
    // Provide a navigational heading to give context for breadcrumb links to
    // screen-reader users. Make the heading invisible with .element-invisible.
    //$output = '<h2 class="element-invisible">' . t('You are here') . '</h2>';

    // Override Drupal core breadcrumb item imploding (no arrow).
    $output = '<ul class="breadcrumb"><li>' . implode('</li><li>', $breadcrumb) . '</li></ul>';
    return $output;
  }
}
