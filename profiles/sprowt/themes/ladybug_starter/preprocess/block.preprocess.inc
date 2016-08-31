<?php

function ladybug_starter_preprocess_block(&$variables) {

  // adds class to sidebar regions
  if ($variables['block']->region == 'sidebar') {
    $variables['classes_array'][] = 'block-sidebar';
  }

}