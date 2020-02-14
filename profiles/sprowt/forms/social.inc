<?php
/**
  * Social Panel
  */

require_once drupal_get_path('module', 'sprowt_settings') . '/sprowt_settings.module';

 function sprowt_social($form, &$form_state, &$install_state){
  drupal_set_title(st('Configure Social Media'));

     $form['#attached']['js'][] = "https://code.jquery.com/jquery-1.11.2.min.js"; //I don't wanna use drupal's old as dirt jQuery

  $form = _sprowt_settings_socialmedia_form($form, $form_state);
  $default = _sprowt_form_default('social_media_accounts');

  $form['sprowt_settings_social_media']['#default_value'] = !empty($default) ? json_encode($default) : '[]';

     $form['actions']['submit'] = array(
         '#type' => 'submit',
         '#value' => t('Save'),
     );

     $form['#submit'] = ['sprowt_social_submit'];

  return $form;
 }

 function sprowt_social_submit($form, &$form_state){
     $values = $form_state['values'];
     $accounts = $values['sprowt_settings_social_media'];
     _sprowt_save_to_table('social_media', [
         'accounts' => json_encode($accounts, true)
     ]);
 }
