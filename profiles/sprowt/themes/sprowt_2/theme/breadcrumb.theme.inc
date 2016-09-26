<?php

function sprowt_2_breadcrumb($variables) {
  $breadcrumb = $variables['breadcrumb'];

  $returnString = function($string) {
    return $string;
  };

  $replace = (function_exists('_sprowt_settings_shortcode_replace')) ? '_sprowt_settings_shortcode_replace' : $returnString;

  if (drupal_is_front_page()) {
    $breadcrumb = array();
  }
  else if ($node = menu_get_object()) {
    if ($node->type == 'localtarget') {
      $breadcrumb = array();
    }
    else {
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
