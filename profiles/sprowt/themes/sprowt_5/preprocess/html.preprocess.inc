<?php

/**
 * Implements hook_preprocess_html().
 */
function sprowt_5_preprocess_html(&$variables, $hook) {
  if (!empty($variables['page']['sidebar'])) {
    $variables['classes_array'][] = 'sidebar';
  }
  else {
    $variables['classes_array'][] = 'no-sidebar';
  }
}