<?php

/**
 * Implements hook_preprocess_page().
 */
function sprowt_starter_preprocess_page(&$variables) {
  if (isset($vars['node']->type)) {
		$vars['theme_hook_suggestions'][] = 'page__' . $vars['node']->type;
	}
}
