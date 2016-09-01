<?php

function sprowt_settings_admin()
{
    $form = array();
    
    $form['sprowt_settings'] = array(
        '#type' => 'vertical_tabs'
    );
    
    $form['company_info'] = array(
        '#type' => 'fieldset',
        '#title' => 'Company Info',
        '#collapsible' => true,
        '#collapsed' => false,
        '#group' => 'sprowt_settings'
    );
    
    $form['company_info']['sprowt_settings_company_name'] = array(
        '#type' => 'textfield',
        '#title' => t('Company Name'),
        '#default_value' => variable_get('sprowt_settings_company_name'),
        '#size' => 60,
        '#maxlength' => 255,
        '#description' => t("Name of the company to display on the site."),
        '#required' => TRUE,
    );
    /*
     * We no longer use site wide locations
     *
    $form['sprowt_settings_address'] = array(
      '#type' => 'fieldset',
      '#title' => t('Company Address'),
    );
    $form['sprowt_settings_address']['sprowt_settings_address_street'] = array(
      '#type' => 'textfield',
      '#title' => t('Address 1'),
      '#default_value' => variable_get('sprowt_settings_address_street'),
      '#size' => 60,
      '#maxlength' => 255,
    );

    $form['sprowt_settings_address']['sprowt_settings_address_additional'] = array(
      '#type' => 'textfield',
      '#title' => t('Address 2'),
      '#default_value' => variable_get('sprowt_settings_address_additional'),
      '#size' => 60,
      '#maxlength' => 255,
    );
    $form['sprowt_settings_address']['sprowt_settings_address_locality'] = array(
      '#type' => 'textfield',
      '#title' => t('City'),
      '#default_value' => variable_get('sprowt_settings_address_locality'),
      '#size' => 20,
      '#maxlength' => 255,
    );
    $form['sprowt_settings_address']['sprowt_settings_address_province'] = array(
      '#type' => 'select',
      '#title' => t('State'),
      '#default_value' => variable_get('sprowt_settings_address_province'),
      '#options' => ___get_states(),
    );

    $form['sprowt_settings_address']['sprowt_settings_address_postal_code'] = array(
      '#type' => 'textfield',
      '#title' => t('Zip Code'),
      '#default_value' => variable_get('sprowt_settings_address_postal_code'),
      '#size' => 5,
      '#maxlength' => 10,
    );

    drupal_add_css(".form-item-coal-admin-address-locality, .form-item-coal-admin-address-province, .form-item-coal-admin-address-postal-code { float: left; margin: 0 10px 10px 0 !important; } .form-item-coal-admin-phone-number { clear: both; }", 'inline');

    */

    $form['company_info']['sprowt_settings_phone_number'] = array(
        '#type' => 'textfield',
        '#title' => t('Company Phone Number'),
        '#default_value' => variable_get('sprowt_settings_phone_number'),
        '#size' => 10,
        '#maxlength' => 10,
        '#description' => t("Phone number to display site-wide."),
        '#required' => TRUE,
        '#element_validate' => array('element_validate_integer_positive'),
    );

    $form['company_info']['sprowt_settings_map_embed'] = array(
        '#type' => 'textarea',
        '#title' => t('Company Area Map Embed URL'),
        '#default_value' => variable_get('sprowt_settings_map_embed'),
        '#description' => t("The embed url for the service area map"),
    );
    
    $form['sprowt_ctm'] = array(
        '#type' => 'fieldset',
        '#title' => t('Call Tracking Metrics Integration'),
        '#collapsible' => true,
        '#collapsed' => false,
        '#group' => 'sprowt_settings'
    );

    $form['sprowt_ctm']['sprowt_ctm_account_id'] = array(
        '#type' => 'textfield',
        '#title' => t('Account ID'),
        '#default_value' => variable_get('sprowt_ctm_account_id'),
        '#size' => 10,
        '#maxlength' => 6,
        '#description' => t("CTM Account ID for the customer. Entering the account number will automatically generate the tracking code for you. Leave blank to disable tracking code."),
    );

    $form['sprowt_ctm']['sprowt_ctm_access_key'] = array(
        '#type' => 'textfield',
        '#title' => t('Access Key'),
        '#default_value' => variable_get('sprowt_ctm_access_key'),
        '#size' => 60,
        '#maxlength' => 128,
        '#description' => t("API credentials required for Sprowt HD to work. The access key can be found under account settings in CTM."),
    );

    $form['sprowt_ctm']['sprowt_ctm_secret_key'] = array(
        '#type' => 'textfield',
        '#title' => t('Secret Key'),
        '#default_value' => variable_get('sprowt_ctm_secret_key'),
        '#size' => 60,
        '#maxlength' => 128,
        '#description' => t("API credentials required for Sprowt HD to work. The secret key can be found under account settings in CTM."),
    );

    $form['company_info']['sprowt_settings_contact'] = array(
        '#type' => 'fieldset',
        '#title' => t('Point of Contact'),
    );

    $form['company_info']['sprowt_settings_contact']['sprowt_settings_contact_name'] = array(
        '#type' => 'textfield',
        '#title' => t('Contact Name'),
        '#default_value' => variable_get('sprowt_settings_contact_name'),
        '#size' => 60,
        '#maxlength' => 255,
        '#description' => t("Full name of the point of contact"),
    );

    $form['company_info']['sprowt_settings_contact']['sprowt_settings_contact_email'] = array(
        '#type' => 'textfield',
        '#title' => t('Contact Email'),
        '#default_value' => variable_get('sprowt_settings_contact_email'),
        '#size' => 60,
        '#maxlength' => 255,
        '#description' => t("Email for the point of contact"),
    );

    $form['company_info']['sprowt_settings_contact']['sprowt_settings_contact_phone'] = array(
        '#type' => 'textfield',
        '#title' => t('Contact Phone'),
        '#default_value' => variable_get('sprowt_settings_contact_phone'),
        '#size' => 60,
        '#maxlength' => 255,
        '#description' => t("Phone for the point of contact"),
    );


    $form['sprowt_settings_social'] = array(
        '#type' => 'fieldset',
        '#title' => t('Social Settings'),
        '#collapsible' => true,
        '#collapsed' => false,
        '#group' => 'sprowt_settings'
    );

    $form['sprowt_settings_social']['sprowt_settings_social_facebook'] = array(
        '#type' => 'fieldset',
        '#title' => t('Facebook'),
    );

    $form['sprowt_settings_social']['sprowt_settings_social_facebook']['sprowt_settings_facebook_url'] = array(
        '#type' => 'textfield',
        '#title' => t('Company Facebook URL'),
        '#default_value' => variable_get('sprowt_settings_facebook_url'),
        '#size' => 60,
        '#maxlength' => 255,
        '#description' => t("Begins with \"http\"."),
    );

    $form['sprowt_settings_social']['sprowt_settings_social_facebook']['sprowt_settings_facebook_description'] = array(
        '#type' => 'textfield',
        '#title' => t('Link Description'),
        '#default_value' => variable_get('sprowt_settings_facebook_description'),
        '#size' => 60,
        '#maxlength' => 255,
        '#description' => t("Descriptive text for Facebook link. Ex. 'Be our friend'"),
    );

    $form['sprowt_settings_social']['sprowt_settings_social_twitter'] = array(
        '#type' => 'fieldset',
        '#title' => t('Twitter'),
    );

    $form['sprowt_settings_social']['sprowt_settings_social_twitter']['sprowt_settings_twitter_handle'] = array(
        '#type' => 'textfield',
        '#title' => t('Company Twitter Handle'),
        '#default_value' => variable_get('sprowt_settings_twitter_handle'),
        '#size' => 60,
        '#maxlength' => 255,
        '#description' => t("Company twitter handle (do not include the @)."),
    );

    $form['sprowt_settings_social']['sprowt_settings_social_twitter']['sprowt_settings_twitter_description'] = array(
        '#type' => 'textfield',
        '#title' => t('Link Description'),
        '#default_value' => variable_get('sprowt_settings_twitter_description'),
        '#size' => 60,
        '#maxlength' => 255,
        '#description' => t("Descriptive text for Twitter link. Ex. 'Follow us'"),
    );

    $form['sprowt_settings_social']['sprowt_settings_social_gplus'] = array(
        '#type' => 'fieldset',
        '#title' => t('Google+'),
    );

    $form['sprowt_settings_social']['sprowt_settings_social_gplus']['sprowt_settings_gplus_url'] = array(
        '#type' => 'textfield',
        '#title' => t('Company Google+ URL'),
        '#default_value' => variable_get('sprowt_settings_gplus_url'),
        '#size' => 60,
        '#maxlength' => 255,
        '#description' => t("Begins with \"http\"."),
    );

    $form['sprowt_settings_social']['sprowt_settings_social_gplus']['sprowt_settings_gplus_description'] = array(
        '#type' => 'textfield',
        '#title' => t('Link Description'),
        '#default_value' => variable_get('sprowt_settings_gplus_description'),
        '#size' => 60,
        '#maxlength' => 255,
        '#description' => t("Descriptive text for Google+ link. Ex. 'Add to circles'"),
    );

    $form['sprowt_settings_social']['sprowt_settings_social_linkedin'] = array(
        '#type' => 'fieldset',
        '#title' => t('LinkedIn'),
    );

    $form['sprowt_settings_social']['sprowt_settings_social_linkedin']['sprowt_settings_linkedin_url'] = array(
        '#type' => 'textfield',
        '#title' => t('Company LinkedIn URL'),
        '#default_value' => variable_get('sprowt_settings_linkedin_url'),
        '#size' => 60,
        '#maxlength' => 255,
        '#description' => t("Begins with \"http\"."),
    );

    $form['sprowt_settings_social']['sprowt_settings_social_linkedin']['sprowt_settings_linkedin_description'] = array(
        '#type' => 'textfield',
        '#title' => t('Link Description'),
        '#default_value' => variable_get('sprowt_settings_linkedin_description'),
        '#size' => 60,
        '#maxlength' => 255,
        '#description' => t("Descriptive text for LinkedIn link. Ex. 'Connect with us'"),
    );

    $form['sprowt_settings_reviews'] = array(
        '#type' => 'fieldset',
        '#title' => t('Review Sites Settings'),
        '#collapsible' => true,
        '#collapsed' => false,
        '#group' => 'sprowt_settings'
    );

    $form['sprowt_settings_reviews']['sprowt_settings_review_yelp'] = array(
        '#type' => 'fieldset',
        '#title' => t('Yelp'),
    );

    $form['sprowt_settings_reviews']['sprowt_settings_review_yelp']['sprowt_settings_yelp_url'] = array(
        '#type' => 'textfield',
        '#title' => t('Company Yelp URL'),
        '#default_value' => variable_get('sprowt_settings_yelp_url'),
        '#size' => 60,
        '#maxlength' => 255,
        '#description' => t("Begins with \"http\"."),
    );

    $form['sprowt_settings_reviews']['sprowt_settings_review_yelp']['sprowt_settings_yelp_description'] = array(
        '#type' => 'textfield',
        '#title' => t('Link Description'),
        '#default_value' => variable_get('sprowt_settings_yelp_description'),
        '#size' => 60,
        '#maxlength' => 255,
        '#description' => t("Descriptive text for Yelp link. Ex. 'Read our reviews on Yelp'"),
    );

    $form['sprowt_settings_reviews']['sprowt_settings_review_bbb'] = array(
        '#type' => 'fieldset',
        '#title' => t('Better Business Bureau'),
    );

    $form['sprowt_settings_reviews']['sprowt_settings_review_bbb']['sprowt_settings_bbb_url'] = array(
        '#type' => 'textfield',
        '#title' => t('Company Better Business Bureau URL'),
        '#default_value' => variable_get('sprowt_settings_bbb_url'),
        '#size' => 60,
        '#maxlength' => 255,
        '#description' => t("Begins with \"http\"."),
    );

    $form['sprowt_settings_reviews']['sprowt_settings_review_bbb']['sprowt_settings_bbb_description'] = array(
        '#type' => 'textfield',
        '#title' => t('Link Description'),
        '#default_value' => variable_get('sprowt_settings_bbb_description'),
        '#size' => 60,
        '#maxlength' => 255,
        '#description' => t("Descriptive text for BBB link. Ex. 'Read our reviews on BBB'"),
    );

    $form['sprowt_settings_reviews']['sprowt_settings_review_angie'] = array(
        '#type' => 'fieldset',
        '#title' => t("Angie's List"),
    );

    $form['sprowt_settings_reviews']['sprowt_settings_review_angie']['sprowt_settings_angie_url'] = array(
        '#type' => 'textfield',
        '#title' => t('Company Angie\'s List URL'),
        '#default_value' => variable_get('sprowt_settings_angie_url'),
        '#size' => 60,
        '#maxlength' => 255,
        '#description' => t("Begins with \"http\"."),
    );

    $form['sprowt_settings_reviews']['sprowt_settings_review_angie']['sprowt_settings_angie_description'] = array(
        '#type' => 'textfield',
        '#title' => t('Link Description'),
        '#default_value' => variable_get('sprowt_settings_angie_description'),
        '#size' => 60,
        '#maxlength' => 255,
        '#description' => t("Descriptive text for Yelp link. Ex. \"Read our reviews on Angie's List\""),
    );

    $form['sprowt_settings_reviews']['sprowt_settings_review_yp'] = array(
        '#type' => 'fieldset',
        '#title' => t("Yellow Pages"),
    );

    $form['sprowt_settings_reviews']['sprowt_settings_review_yp']['sprowt_settings_yp_url'] = array(
        '#type' => 'textfield',
        '#title' => t('Company Yellow Pages URL'),
        '#default_value' => variable_get('sprowt_settings_yp_url'),
        '#size' => 60,
        '#maxlength' => 255,
        '#description' => t("Begins with \"http\"."),
    );

    $form['sprowt_settings_reviews']['sprowt_settings_review_yp']['sprowt_settings_yp_description'] = array(
        '#type' => 'textfield',
        '#title' => t('Link Description'),
        '#default_value' => variable_get('sprowt_settings_yp_description'),
        '#size' => 60,
        '#maxlength' => 255,
        '#description' => t("Descriptive text for Yelp link. Ex. \"Read our reviews on the Yellow Pages\""),
    );

    $form['#validate'][] = '_sprowt_settings_config_validate';

    return system_settings_form($form);
}

function _sprowt_settings_config_validate($form, &$form_state) {
    $values = $form_state['values'];

    $map = $values['sprowt_settings_map_embed'];

    if(preg_match('/<iframe.*src="([^"]+)"/', $map, $i)) {
        $form_state['values']['sprowt_settings_map_embed'] = $i[1];
    }
}