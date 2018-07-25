<?php

/**
 * Implements hook_preprocess_page().
 */
function landing_page_preprocess_page(&$variables) {
  // You can use preprocess hooks to modify the variables before they are passed
  // to the theme function or template file.

    $theme_css_override = drupal_get_path('theme', variable_get('theme_default')) . '/css/landing_page.css';
    $theme_css_override = variable_get('sprowt_landing_page_css_override_file', $theme_css_override);
    drupal_add_css($theme_css_override);
}
