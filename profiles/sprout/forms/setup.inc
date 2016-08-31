<?php
/**
 * sprout Setup
 */

 function sprout_setup_form($form, &$form_state, &$install_state) {
    drupal_add_library('system', 'drupal.progress');
    $form['#attached']['js'][] = drupal_get_path('profile', 'sprout') . "/js/setup.js";
    
    $form['#suffix'] = '<div id="progress"></div>';
    
    $form['submit'] = array(
      '#type' => 'submit',
      '#value' => 'hidden_submit',
      '#prefix' => '<div style="display:none;">',
      '#suffix' => '</div>',
   );
    
    return $form;
 }