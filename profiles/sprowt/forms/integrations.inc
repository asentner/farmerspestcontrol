<?php 
/**
  * Integrations Setup
  */
 
 function sprowt_integrations($form, &$form_state, &$install_state){
  drupal_set_title(st('Configure Integrations'));
  
  $form['integrations']['google_analytics'] = array(
    '#type' => 'textfield',
    '#title' => 'Google Analytics Code',
    '#default_value' => _sprowt_form_default('google_analytics'),
    '#attributes' => array(
      'placeholder' => 'UA-xxxxxxxx-x'
    ),
  );
  
  $form['integrations']['gtm'] = array(
    '#type' => 'textfield',
    '#title' => 'Google Tag Manager Code',
    '#attributes' => array(
      'placeholder' => 'GTM-xxxxxx'
    ),
    '#default_value' => _sprowt_form_default('gtm')
  );
  
  $form['integrations']['optimizely_id'] = array(
    '#type' => 'textfield',
    '#title' => t('Optimizely ID Number'),
    '#description' => t('Your Optimizely account ID. This is the number after "/js/" in the Optimizely Tracking Code found in your account on the Optimizely website.'),
    '#default_value' => _sprowt_form_default('optimizely_id')
  );
  
  $form['integrations']['ac_newsletter_api_url'] = array(
    '#type' => 'textfield',
    '#title' => t('ActiveCampaign API URL'),
    '#description' => t('API url of your ActiveCampaign Account. ex: https://ACCOUNT.api-us1.com'),
    '#default_value' => _sprowt_form_default('ac_newsletter_api_url')
  );

  $form['integrations']['ac_newsletter_api_key'] = array(
    '#type' => 'textfield',
    '#title' => t('ActiveCampaign API KEY'),
    '#default_value' => _sprowt_form_default('ac_newsletter_api_key'),
    '#description' => t('API key of your ActiveCampaign Account. you can find in the !api of your account.', array(
      '!api' => str_replace('?q=', '', l(t('API tab'), drupal_get_path('module', 'ac_newsletter') . '/images/ac-api-tab.png', array(
        'attributes' => array('target' => '_blank')))))),
  );
  
  $form['actions']['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Save'),
  );
  
  return $form;
 }
 
 function sprowt_integrations_submit($form, &$form_state){
  $fields = array(
    'google_analytics' => $form['integrations']['google_analytics']['#value'],
    'gtm' => $form['integrations']['gtm']['#value'],
    'optimizely_id' => $form['integrations']['optimizely_id']['#value'],
    'ac_newsletter_api_url' => $form['integrations']['ac_newsletter_api_url']['#value'],
    'ac_newsletter_api_key' => $form['integrations']['ac_newsletter_api_key']['#value'],
  );
  
  foreach($fields as $index=>$value){
    if(empty($value)){
      unset($fields[$index]);
    }
  }
  
  _sprowt_save_to_table('integrations', $fields);
  
 }