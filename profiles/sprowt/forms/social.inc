<?php 
/**
  * Social Panel
  */
 
 function sprout_social($form, &$form_state, &$install_state){
  drupal_set_title(st('Configure Social Media'));
  
  $form['social_media']['facebook'] = array(
    '#type' => 'textfield',
    '#title' => 'Facebook URL',
    '#default_value' => _sprout_form_default('facebook')
  );
  
  $form['social_media']['twitter'] = array(
    '#type' => 'textfield',
    '#title' => 'Twitter Handle',
    '#default_value' => _sprout_form_default('twitter')
  );
  
  $form['social_media']['linkedin'] = array(
    '#type' => 'textfield',
    '#title' => 'Linked In URL',
    '#default_value' => _sprout_form_default('linkedin')
  );
  
  $form['social_media']['gplus'] = array(
    '#type' => 'textfield',
    '#title' => 'Google+ URL',
    '#description' => 'Site wide Google+ URL. Also used for site Publisher markup',
    '#default_value' => _sprout_form_default('gplus')
  );
  
  $form['actions']['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Save'),
  );
  
  return $form;
 }
 
 function sprout_social_submit($form, &$form_state){
  $fields = array(
    'facebook' => $form['social_media']['facebook']['#value'],
    'twitter' => $form['social_media']['twitter']['#value'],
    'linkedin' => $form['social_media']['linkedin']['#value'],
    'gplus' => $form['social_media']['gplus']['#value'],
  );
  
  foreach($fields as $index=>$value){
    if(empty($value)){
      unset($fields[$index]);
    }
  }
  
  _sprout_save_to_table('social_media', $fields);
  
 }