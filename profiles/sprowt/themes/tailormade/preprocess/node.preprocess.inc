<?php

function tailormade_preprocess_node(&$variables) {
  if(drupal_is_front_page() && $variables['page']) {
    $variables['theme_hook_suggestions'][] = 'node__front';
  }
  
  if(drupal_is_front_page() && $variables['node']->type == 'special_offer') {
    $variables['title'] = str_replace('$', '<sup class="dollar-sign">$</sup>', $variables['title']);
  }
}
