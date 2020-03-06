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
}
