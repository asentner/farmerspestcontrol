<?php

function tailormade_preprocess_page(&$vars) {
	
	if($_SERVER['SERVER_ADDR'] == '127.0.0.1') {
		drupal_add_js("document.write('<script src=\"http://' + (location.host || 'localhost').split(':')[0] + ':35729/livereload.js?snipver=1\"></' + 'script>')", 'inline');
	}
	
	if (isset($vars['node']->type)) {
		$vars['theme_hook_suggestions'][] = 'page__' . $vars['node']->type;
	}
	
	$node = menu_get_object();
	
	if($node && drupal_is_front_page()) {
		if(!empty($node->field_image)) {
			$top = file_create_url($node->field_image[LANGUAGE_NONE][0]['uri']);
		}
		else {
			$top = '/' . path_to_theme() . '/images/home-bg.jpg';
		}
		$vars['top_image'] = $top;
	}
}
