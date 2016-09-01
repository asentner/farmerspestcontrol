<?php 
/**
  * Social Panel
  */
 function sprowt_review($form, &$form_state, &$install_state){
  drupal_set_title(st('Configure Review Sites'));
  
  $form['review']['sprowt_settings_yelp_url'] = array(
    '#type' => 'textfield',
    '#title' => 'Yelp URL',
    '#default_value' => _sprowt_form_default('sprowt_settings_yelp_url')
  );
  
  $form['review']['sprowt_settings_bbb_url'] = array(
    '#type' => 'textfield',
    '#title' => 'Better Business Bureau URL',
    '#default_value' => _sprowt_form_default('sprowt_settings_bbb_url')
  );
  
  $form['review']['sprowt_settings_angie_url'] = array(
    '#type' => 'textfield',
    '#title' => "Angie's List URL",
    '#default_value' => _sprowt_form_default('sprowt_settings_angie_url')
  );
  
  $form['review']['sprowt_settings_yp_url'] = array(
    '#type' => 'textfield',
    '#title' => 'Yellow Pages URL',
    '#default_value' => _sprowt_form_default('sprowt_settings_yp_url')
  );
  
  $form['actions']['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Save'),
  );
  
  return $form;
 }
 
 function sprowt_review_submit($form, &$form_state){
  $fields = array(
    'sprowt_settings_yelp_url' => $form['review']['sprowt_settings_yelp_url']['#value'],
    'sprowt_settings_bbb_url' => $form['review']['sprowt_settings_bbb_url']['#value'],
    'sprowt_settings_angie_url' => $form['review']['sprowt_settings_angie_url']['#value'],
    'sprowt_settings_yp_url' => $form['review']['sprowt_settings_yp_url']['#value'],
  );
  
  foreach($fields as $index=>$value){
    if(empty($value)){
      unset($fields[$index]);
    }
  }
  
  _sprowt_save_to_table('review', $fields);
  
 }