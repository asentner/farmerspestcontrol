<?php

/**
 * @file
 * Template overrides as well as (pre-)process and alter hooks for the
 * Landing Page Theme theme.
 */

/**
 * Implements hook_css_alter()
 */
function landing_page_css_alter(&$css) {
    $override = drupal_get_path('theme', 'landing_page') . '/css/landing-page.styles-override.css';
    $css[$override]['every_page'] = false;
    $css[$override]['weight'] = 10;

    $theme_css_override = drupal_get_path('theme', variable_get('theme_default')) . '/css/landing_page.css';
    $theme_css_override = variable_get('sprowt_landing_page_css_override_file', $theme_css_override);
    $css[$theme_css_override]['group'] = 100;
    $css[$theme_css_override]['every_page'] = false;
    $css[$theme_css_override]['weight'] = 10;
}

function landing_page_preprocess_paragraphs_item(&$variables) {

}