<?php

function tailormade_preprocess_html(&$variables, $hook) {
  if (!empty($variables['page']['sidebar_first']) && !empty($variables['page']['sidebar_second'])) {
      $variables['classes_array'][] = 'two-sidebars';
    }
    elseif (!empty($variables['page']['sidebar_first'])) {
      $variables['classes_array'][] = 'one-sidebar sidebar-first';
    }
    elseif (!empty($variables['page']['sidebar_second'])) {
      $variables['classes_array'][] = 'one-sidebar sidebar-second';
    }
    else {
      $variables['classes_array'][] = 'no-sidebars';
    } 
}