<?php

function leadbuilder_theme_preprocess_block(&$variables) {
  
  if ( ($variables['block']->region == 'sidebar_second') || ($variables['block']->region == 'sidebar_first') ) {
    $variables['classes_array'][] = 'block-sidebar';
  }
  
}