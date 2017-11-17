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


function _review_boost_sms_admin_form($form, &$form_state){
  //sms settings fieldset
  $twilio_settings = array();

  $twilio_settings['twilio_account_id'] = array(
    '#title' => t('Twilio Account ID'),
    '#type' => 'textfield',
    '#default_value' => variable_get('twilio_admin_account_id'),
    '#required' => TRUE,
    '#description' => 'Insert your Twilio Account ID'
  );

  $twilio_settings['twilio_auth_token'] = array(
    '#title' => t('Twilio Auth ID'),
    '#type' => 'textfield',
    '#default_value' => variable_get('twilio_admin_auth_token'),
    '#required' => TRUE
  );

  $twilio_settings['twilio_phone'] = array(
    '#title' => t('Twilio Phone Number'),
    '#default_value' => variable_get('twilio_admin_phone'),
    '#type' => 'textfield',
    '#required' => TRUE,
  );

  $msg = variable_get('twilio_admin_message');
  if(empty($msg) || $msg = ''){
    variable_set('twilio_admin_message','Hi %customer_first_name! This is %technician. Thanks again for choosing us. Can you take 30 seconds to fill out this short survey? %survey_link Thank you!');
  }
  $twilio_settings['twilio_message'] = array(
    '#title' => t('Message'),
    '#default_value' => variable_get('twilio_admin_message'),
    '#type' => 'textarea',
    '#required' => FALSE,
    '#description' => t("Enter the message you want to send to your customers.")
  );

  $twilio_settings['tokens'] = array(
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

  $twilio_settings['twilio_mms_image'] = array(
    '#type'   => "managed_file",
    '#title'  => t("Brand Image"),
    '#description' => t("Upload an image that will be sent with the text message to customers."),
    '#size' => "2 MB", //todo change this to something smaller or incorporate auto resizing if too big
    '#default_value' => variable_get('twilio_image'),
    '#upload_location'    => "public://review_boost/",
    "#upload_validators"  => array("file_validate_extensions" => array("png gif jpg")),
  );

  $twilio_settings['twilio_toggle_image'] = array(
      '#type' => 'checkbox',
      '#title' => 'Include Image with Text Message?',
      '#description' => t("Check to include this image when sending text messages."),
      '#default_value' => variable_get('twilio_admin_toggle_image',1),
  );

  //auto response fieldset
  $twilio_responder = array();

  $response = variable_get('twilio_admin_auto_response');
  if(empty($response) || $response == ''){
    variable_set('twilio_admin_auto_response','To opt-out, reply with opt-out. To opt back in, reply opt-in');
  }

  $twilio_responder['twilio_auto_response'] = array(
    '#type' => 'textarea',
    '#title' => t("Auto Respond Message"),
    '#description' => t("Enter a custom auto-response that is sent whenever a customer texts back."),
    '#format' => 'full_html',
    '#default_value' => variable_get('twilio_admin_auto_response'),
  );

  $form['sms_settings'] = array(
    '#type' => 'fieldset',
    '#title' => 'Twilio SMS/MMS Settings',
    $twilio_settings
  );
  $form['responder_settings'] = array(
    '#type' => 'fieldset',
    '#title' => 'SMS Response Settings',
    $twilio_responder
  );
  $form['#validate'][] = '_review_boost_sms_admin_form_validate';
  $form['#validate'][] = '_review_boost_sms_admin_form_submit';

  return system_settings_form($form);
}
function _review_boost_sms_admin_form_validate($form, &$form_state){

  $sms = new ReviewBoostSMS();

  if(!empty($form_state['values']['twilio_phone'])){
    $formattedPhone = $sms->validatePhone($form_state['values']['twilio_phone']);
    $form_state['values']['twilio_phone'] = $formattedPhone;
  }

  //check length of outgoing text message and auto responder message
  $twilio_msg = $form_state['values']['twilio_message'];
  $auto_response = $form_state['values']['twilio_auto_response'];

  if(!empty($twilio_msg)){
    $form_state['values']['twilio_message'] = validate_length($twilio_msg,'Message');
  }
  if(!empty($auto_response)){
    $form_state['values']['twilio_auto_response'] = validate_length($auto_response,'Auto Respond Message');
  }
}

function _review_boost_sms_admin_form_submit($form, &$form_state){

    //save default values to access later.
    variable_set('twilio_admin_phone',$form_state['values']['twilio_phone']);
    variable_set('twilio_admin_message',$form_state['values']['twilio_message']);
    variable_set('twilio_admin_auth_token',$form_state['values']['twilio_auth_token']);
    variable_set('twilio_admin_account_id',$form_state['values']['twilio_account_id']);
    variable_set('twilio_admin_auto_response',$form_state['values']['twilio_auto_response']);
    variable_set('twilio_admin_toggle_image', $form_state['values']['twilio_toggle_image']);

    //logic for saving the image
    $file = file_load($form_state['values']['twilio_mms_image']);
    if($file === false){
      variable_set('twilio_image','');
    }else{
      $file->status = FILE_STATUS_PERMANENT;
      $file_saved = file_save($file);
      variable_set('twilio_image',$file_saved->fid); //save fid of image to variable so image is not added twice
      file_usage_add($file_saved, 'review_boost_sms_admin_form', 'twilio_mms_image', $file_saved->fid);
      $form_state['rebuild'] = TRUE;
    }
    if(!form_get_errors()){
      drupal_set_message('Configuration Saved!');
    }

  }

function _review_boost_generate_token_help($addtl = array()){
  $RB = new ReviewBoost();
  $RB->addTokenDescriptions($addtl);
  return $RB->getTokenHelp();
}

function validate_length($item,$type){
    $msg = $item;
    if(strlen($msg) > 160){
      $currMsgLength = strlen($msg) - 160;
      form_set_error('Validation Error!',$type.' is too long by: ' . $currMsgLength . ' characters. SMS messages are limited to 160 characters.');
      $originalMsg = substr($item,0,160);
      $item = $originalMsg;
      return $item;
    }
  return $item;
}