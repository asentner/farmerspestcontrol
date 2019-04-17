<?php

function _pestpac_api_menu_block(){
  $item = menu_get_item();
  if ($content = system_admin_menu_block($item)) {
    $output = theme('admin_block_content', array('content' => $content));
  }
  else {
    $output = t('You do not have any administrative items.');
  }
  return $output;
}

function pestpac_api_admin(){
  $form = array();
  
  $form['pestpac_tenant_id'] = array(
    '#type' => 'textfield',
    '#title' => t('PestPac Tenant ID'),
    '#default_value' => variable_get('pestpac_tenant_id'),
    '#size' => 10,
    '#maxlength' => 60,
    '#description' => t("Tenant ID for PestPac API."),
  );
  $form['pestpac_wwid'] = array(
    '#type' => 'textfield',
    '#title' => t('Work Wave Account ID'),
    '#default_value' => variable_get('pestpac_wwid'),
    '#size' => 60,
    '#maxlength' => 1000,
    '#description' => t("Work Wave ID (username/email) for PestPac API."),
  );
  $form['pestpac_wwidpass'] = array(
    '#type' => 'textfield',
    '#title' => t('Work Wave ID Password'),
    '#default_value' => variable_get('pestpac_wwidpass'),
    '#size' => 60,
    '#maxlength' => 1000,
    '#description' => t("Work Wave ID Password for PestPac API."),
  );
  $form['pestpac_client_id'] = array(
    '#type' => 'textfield',
    '#title' => t('PestPac Client ID'),
    '#default_value' => variable_get('pestpac_client_id'),
    '#size' => 60,
    '#maxlength' => 128,
    '#description' => t("Client ID for PestPac API."),
  );
  $form['pestpac_client_secret'] = array(
    '#type' => 'textfield',
    '#title' => t('PestPac Client Secret'),
    '#default_value' => variable_get('pestpac_client_secret'),
    '#size' => 60,
    '#maxlength' => 128,
    '#description' => t("Client Secret for PestPac API."),
  );
  $form['pestpac_api_key'] = array(
    '#type' => 'textfield',
    '#title' => t('PestPac API Key'),
    '#default_value' => variable_get('pestpac_api_key'),
    '#size' => 60,
    '#maxlength' => 128,
    '#description' => t("API Key for PestPac API."),
  );
    $form['pestpac_default_branch'] = array(
        '#type' => 'textfield',
        '#title' => t('Default Branch'),
        '#default_value' => variable_get('pestpac_default_branch'),
        '#size' => 60,
        '#maxlength' => 128,
        '#description' => t("OPTIONAL- Enter a custom branch here to default to this branch for all initial call creations in PestPac."),
    );


  return system_settings_form($form);
}