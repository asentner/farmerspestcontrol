<?php

function sprowt_theme_preprocess_page(&$variables) {

	/*
	if(strpos($_SERVER['HTTP_HOST'], ".dev") !== false) {
		drupal_add_js("document.write('<script src=\"http://' + (location.host || 'localhost').split(':')[0] + ':35729/livereload.js?snipver=1\"></' + 'script>')", array('type' => 'inline'));
	}
	*/

	drupal_add_css(drupal_get_path('module', 'sprowt_theme') . '/css/global.css');
	
	if (!empty($variables['node']) && !empty($variables['node']->type)) {
		$variables['theme_hook_suggestions'][] = 'page__node__' . $variables['node']->type;
	}
}

