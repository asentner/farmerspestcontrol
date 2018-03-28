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
}

function landing_page_preprocess_paragraphs_item(&$variables) {

}