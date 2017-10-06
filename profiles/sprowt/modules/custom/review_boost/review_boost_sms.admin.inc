<?php
require_once drupal_get_path('module', 'system') . '/system.admin.inc';
require_once drupal_get_path('module','review_boost') . '/review_boost_sms.php';
require_once drupal_get_path('module','review_boost') . '/review_boost.php';

function _review_boost_sms_admin_menu_block_page() {
  $item = menu_get_item();
  if ($content = system_admin_menu_block($item)) {
    $output = theme('admin_block_content', array('content' => $content));
  }
  else {
    $output = t('You do not have any administrative items.');
  }
  return $output;
}

function _review_boost_sms_admin(){
  return theme('review_boost_sms_admin', array(
    'form' => drupal_get_form('_review_boost_sms_admin_form')
  ));
}

//todo fix issue where form is only saving original value
function _review_boost_sms_admin_form($form, &$form_state){
  $form['twilio_account_id'] = array(
    '#title' => t('Twilio Account ID'),
    '#type' => 'textfield',
    '#default_value' => variable_get('twilio_admin_account_id'),
    '#required' => TRUE,
    '#description' => 'Insert your Twilio Account ID'
  );

  $form['twilio_auth_token'] = array(
    '#title' => t('Twilio Auth ID'),
    '#type' => 'textfield',
    '#default_value' => variable_get('twilio_admin_auth_token'),
    '#required' => TRUE

  );

  $form['twilio_phone'] = array(
    '#title' => t('Twilio Phone Number'),
    '#default_value' => variable_get('twilio_admin_phone'),
    '#type' => 'textfield',
    '#required' => TRUE,
  );

  $form['twilio_message'] = array(
    '#title' => t('Message'),
    '#default_value' => variable_get('twilio_admin_message'),
    '#type' => 'textarea',
    '#required' => FALSE,
    '#description' => t("Enter the message you want to send to your customers.")
  );
  $form['tokens'] = array(
    '#type' => 'fieldset',
    '#title' => 'Available Tokens',
    '#description' => 'Can be used in Subject and Body',
    '#collapsible' => true,
    '#collapsed' => true,
    'token_markup' => array(
      '#type' => 'markup',
      '#markup' => _review_boost_generate_token_help()
    )
  );

  $form['twilio_mms_image'] = array(
    '#type'   => "managed_file",
    '#title'  => t("Upload Image"),
    '#descripion' => t("Upload an image to be sent to customers."),
    '#size' => "2 MB", //todo change this to something smaller or incorporate auto resizing if too big
    '#default_value' => variable_get('twilio_image'),
    '#upload_location'    => "public://review_boost/",
    "#upload_validators"  => array("file_validate_extensions" => array("png gif jpg")),
  );

  $form['submit_sms_settings'] = array(
    '#type' => 'submit',
    '#value' => t('Save Configuration')
  );

  return $form;
}
//todo add message that informs admin that the sms message is too long
function _review_boost_sms_admin_form_validate($form, &$form_state){

  $sms = new ReviewBoostSMS();

  if(!empty($form_state['values']['twilio_phone'])){
    $formattedPhone = $sms->validatePhone($form_state['values']['twilio_phone']);
    $form_state['values']['twilio_phone'] = $formattedPhone;
  }

  //Sanitize and escape message b/c we can't send anything besides raw text/numbers via sms
  if(!empty($form_state['values']['twilio_message'])){
    $msg = $form_state['values']['twilio_message'];

    if(strlen($msg) > 160){
      $currMsgLength = strlen($msg) - 160;
      form_set_error('Message is too long.','Message is too long by: ' . $currMsgLength . ' characters. SMS messages are limited to 160 characters.');
    }

  }
}

function _review_boost_sms_admin_form_submit($form, &$form_state){

  //save default values to access later.
  variable_set('twilio_admin_phone',$form_state['values']['twilio_phone']);
  variable_set('twilio_admin_message',$form_state['values']['twilio_message']);
  variable_set('twilio_admin_auth_token',$form_state['values']['twilio_auth_token']);
  variable_set('twilio_admin_account_id',$form_state['values']['twilio_account_id']);

  //logic for saving the image
  $file = file_load($form_state['values']['twilio_mms_image']);
  $file->status = FILE_STATUS_PERMANENT;
  $file_saved = file_save($file);
  variable_set('twilio_image',$file_saved->fid); //save fid of image to variable so image is not added twice
  file_usage_add($file_saved, 'review_boost_sms_admin_form', 'twilio_mms_image', $file_saved->fid);
  $form_state['rebuild'] = TRUE;
  drupal_set_message(t('Form configuration saved!'));
}

function _review_boost_generate_token_help($addtl = array()){
  $RB = new ReviewBoost();
  $RB->addTokenDescriptions($addtl);
  return $RB->getTokenHelp();
}