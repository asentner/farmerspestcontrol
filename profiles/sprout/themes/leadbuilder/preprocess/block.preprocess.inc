<?php

function leadbuilder_preprocess_block(&$variables) {

  // adds class to sidebar regions
  if ( ($variables['block']->region == 'sidebar_second') || ($variables['block']->region == 'sidebar_first') ) {
    $variables['classes_array'][] = 'block-sidebar';
  }

}