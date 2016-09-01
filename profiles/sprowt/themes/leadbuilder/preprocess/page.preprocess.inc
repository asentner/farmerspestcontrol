<?php

function leadbuilder_preprocess_page(&$vars) {
	if (isset($vars['node']->type)) {
		$vars['theme_hook_suggestions'][] = 'page__' . $vars['node']->type;
	}
}