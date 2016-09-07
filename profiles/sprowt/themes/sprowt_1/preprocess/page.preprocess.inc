<?php

/**
 * Implements hook_preprocess_page().
 */
function sprowt_1_preprocess_page(&$variables) {
  if (isset($vars['node']->type)) {
		$vars['theme_hook_suggestions'][] = 'page__' . $vars['node']->type;
	}
}
