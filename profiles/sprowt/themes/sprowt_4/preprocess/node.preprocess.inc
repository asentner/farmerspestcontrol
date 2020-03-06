<?php

/**
 * Implements hook_preprocess_node().
 */
function sprowt_4_preprocess_node(&$variables) {
  // remove role attribute
  unset($variables['attributes_array']['role']);
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

    if($variables['view_mode'] == 'full' && empty($variables['page'])) {
        $variables['page'] = true; //this is false when logged in for some reason
    }
}
