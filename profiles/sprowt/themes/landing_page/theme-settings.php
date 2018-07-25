<?php

/**
 * @file
 * Theme settings file for the Landing Page Theme theme.
 */

require_once dirname(__FILE__) . '/template.php';

/**
 * Implements hook_form_FORM_alter().
 */
function landing_page_form_system_theme_settings_alter(&$form, &$form_state) {
  // You can use this hook to append your own theme settings to the theme
  // settings form for your subtheme. You should also take a look at the
  // 'extensions' concept in the Omega base theme.

    $theme_css_override = drupal_get_path('theme', variable_get('theme_default')) . '/css/landing_page.css';
    $theme_css_override = variable_get('sprowt_landing_page_css_override_file', $theme_css_override);

    $form['sprowt_landing_page_css_override_file'] = array(
        '#type' => 'textfield',
        '#title' => 'Override css file location',
        '#description' => 'location and name of the css file that can override styles on this theme.',
        '#default_value' => $theme_css_override
    );

    $form['#submit'][] = 'landing_page_theme_settings_submit';


    $form_state['build_info']['files'][] = drupal_get_path('theme', 'landing_page') . '/theme-settings.php';
}

function landing_page_theme_settings_submit($form, &$form_state) {
    $css_override = $form_state['values']['sprowt_landing_page_css_override_file'];
    variable_set('sprowt_landing_page_css_override_file', $css_override);
}
