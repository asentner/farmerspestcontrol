<?php

function leadbuilder_spotlight_admin() {
    $form = array();

    $form['leadbuilder_spotlight_api_url'] = array(
        '#type' => 'textfield',
        '#title' => t('Spotlight Service URL'),
        '#default_value' => (variable_get('leadbuilder_spotlight_api_url', false)) ? variable_get('leadbuilder_spotlight_api_url') : 'http://spotlight.coalmarch.com/api/v1',
        '#size' => 40,
        '#maxlength' => 255,
        '#description' => t("This can be found when editing a customer in the Spotlight web service"),
        '#required' => TRUE,
    );

    $form['leadbuilder_spotlight_api_access_key'] = array(
        '#type' => 'textfield',
        '#title' => t('API Access Key'),
        '#default_value' => variable_get('leadbuilder_spotlight_api_access_key'),
        '#size' => 40,
        '#maxlength' => 255,
        '#description' => t("This can be found when editing a customer in the Spotlight web service"),
        '#required' => TRUE,
    );

    $form['leadbuilder_spotlight_api_secret_key'] = array(
        '#type' => 'textfield',
        '#title' => t('API Secret Key'),
        '#default_value' => variable_get('leadbuilder_spotlight_api_secret_key'),
        '#size' => 36,
        '#maxlength' => 255,
        '#description' => t("This can be found when editing a customer in the Spotlight web service"),
        '#required' => TRUE,
    );

    return system_settings_form($form);
}