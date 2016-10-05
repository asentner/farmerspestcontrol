<?php

/**
 * Implements hook_preprocess_node().
 */
function sprowt_3_preprocess_node(&$variables) {
  // remove role attribute
  unset($variables['attributes_array']['role']);
  if (isset($vars['node']->type)) {
		$vars['theme_hook_suggestions'][] = 'page__' . $vars['node']->type;
	}

  $variables['intro_title'] = FALSE;

  if (
    (!empty($variables['content']['field_display_title'][LANGUAGE_NONE][0])
      && !empty($variables['content']['field_intro'][LANGUAGE_NONE][0]))
    || (!empty($variables['content']['field_display_title'][0])
      && !empty($variables['content']['field_intro'][0]))
  )
  {
    $variables['intro_title'] = TRUE;
  }
}
