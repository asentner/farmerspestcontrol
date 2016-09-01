<?php

function sprowt_theme_preprocess_block(&$variables) {
  
  if ( ($variables['block']->region == 'sidebar_second') || ($variables['block']->region == 'sidebar_first') ) {
    $variables['classes_array'][] = 'block-sidebar';
  }
  
}