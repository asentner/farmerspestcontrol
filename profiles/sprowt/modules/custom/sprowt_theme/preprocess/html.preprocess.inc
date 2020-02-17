<?php

function sprowt_theme_preprocess_html(&$variables) {
	if (isset($variables['page'])) {
    if (isset($variables['page']['sidebar_first']) && isset($variables['page']['sidebar_second'])) {
      $variables['classes_array'][] = 'has-two-sidebars';
    } else if (isset($variables['page']['sidebar_first'])) {
      $variables['classes_array'][] = 'has-sidebar-first';
    } else if (isset($variables['page']['sidebar_second'])) {
      $variables['classes_array'][] = 'has-sidebar-second';
    }
  }

	$variables['base_path'] = base_path() . path_to_theme();

	$path = current_path();
	if(preg_match('#^user(/|$)#', $path)) {
	    $noIndexUser = [
	        '#type' => 'html_tag',
            '#tag' => 'meta',
            '#attributes' => [
                'name' => 'robots',
                'content' => 'noindex'
            ]
        ];

	    drupal_add_html_head($noIndexUser, 'sprowt_user_noindex');
    }
}
