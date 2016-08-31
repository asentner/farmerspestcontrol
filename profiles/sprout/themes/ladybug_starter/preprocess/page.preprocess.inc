<?php

function ladybug_starter_preprocess_page(&$vars) {
	if (isset($vars['node']->type)) {
		$vars['theme_hook_suggestions'][] = 'page__' . $vars['node']->type;
	}
}
