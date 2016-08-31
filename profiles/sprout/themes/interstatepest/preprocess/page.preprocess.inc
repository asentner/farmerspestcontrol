<?php

function interstatepest_preprocess_page(&$vars) {
	if (isset($vars['node']->type)) {
		$vars['theme_hook_suggestions'][] = 'page__' . $vars['node']->type;
	}

	if (empty($variables['page']['sidebar'])) {
    $variables['classes_array'][] = 'no-sidebars';
  }
}
