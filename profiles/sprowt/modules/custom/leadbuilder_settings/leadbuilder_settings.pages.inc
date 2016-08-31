<?php

function leadbuilder_settings_admin()
{
    $form = array();
    
    $form['leadbuilder_settings'] = array(
        '#type' => 'vertical_tabs'
    );
    
    $form['company_info'] = array(
        '#type' => 'fieldset',
        '#title' => 'Company Info',
        '#collapsible' => true,
        '#collapsed' => false,
        '#group' => 'leadbuilder_settings'
    );
    
    $form['company_info']['leadbuilder_settings_company_name'] = array(
        '#type' => 'textfield',
        '#title' => t('Company Name'),
        '#default_value' => variable_get('leadbuilder_settings_company_name'),
        '#size' => 60,
        '#maxlength' => 255,
        '#description' => t("Name of the company to display on the site."),
        '#required' => TRUE,
    );
    /*
     * We no longer use site wide locations
     *
    $form['leadbuilder_settings_address'] = array(
      '#type' => 'fieldset',
      '#title' => t('Company Address'),
    );
    $form['leadbuilder_settings_address']['leadbuilder_settings_address_street'] = array(
      '#type' => 'textfield',
      '#title' => t('Address 1'),
      '#default_value' => variable_get('leadbuilder_settings_address_street'),
      '#size' => 60,
      '#maxlength' => 255,
    );

    $form['leadbuilder_settings_address']['leadbuilder_settings_address_additional'] = array(
      '#type' => 'textfield',
      '#title' => t('Address 2'),
      '#default_value' => variable_get('leadbuilder_settings_address_additional'),
      '#size' => 60,
      '#maxlength' => 255,
    );
    $form['leadbuilder_settings_address']['leadbuilder_settings_address_locality'] = array(
      '#type' => 'textfield',
      '#title' => t('City'),
      '#default_value' => variable_get('leadbuilder_settings_address_locality'),
      '#size' => 20,
      '#maxlength' => 255,
    );
    $form['leadbuilder_settings_address']['leadbuilder_settings_address_province'] = array(
      '#type' => 'select',
      '#title' => t('State'),
      '#default_value' => variable_get('leadbuilder_settings_address_province'),
      '#options' => ___get_states(),
    );

    $form['leadbuilder_settings_address']['leadbuilder_settings_address_postal_code'] = array(
      '#type' => 'textfield',
      '#title' => t('Zip Code'),
      '#default_value' => variable_get('leadbuilder_settings_address_postal_code'),
      '#size' => 5,
      '#maxlength' => 10,
    );

    drupal_add_css(".form-item-coal-admin-address-locality, .form-item-coal-admin-address-province, .form-item-coal-admin-address-postal-code { float: left; margin: 0 10px 10px 0 !important; } .form-item-coal-admin-phone-number { clear: both; }", 'inline');

    */

    $form['company_info']['leadbuilder_settings_phone_number'] = array(
        '#type' => 'textfield',
        '#title' => t('Company Phone Number'),
        '#default_value' => variable_get('leadbuilder_settings_phone_number'),
        '#size' => 10,
        '#maxlength' => 10,
        '#description' => t("Phone number to display site-wide."),
        '#required' => TRUE,
        '#element_validate' => array('element_validate_integer_positive'),
    );

    $form['company_info']['leadbuilder_settings_map_embed'] = array(
        '#type' => 'textarea',
        '#title' => t('Company Area Map Embed URL'),
        '#default_value' => variable_get('leadbuilder_settings_map_embed'),
        '#description' => t("The embed url for the service area map"),
    );
    
    $form['leadbuilder_ctm'] = array(
        '#type' => 'fieldset',
        '#title' => t('Call Tracking Metrics Integration'),
        '#collapsible' => true,
        '#collapsed' => false,
        '#group' => 'leadbuilder_settings'
    );

    $form['leadbuilder_ctm']['leadbuilder_ctm_account_id'] = array(
        '#type' => 'textfield',
        '#title' => t('Account ID'),
        '#default_value' => variable_get('leadbuilder_ctm_account_id'),
        '#size' => 10,
        '#maxlength' => 6,
        '#description' => t("CTM Account ID for the customer. Entering the account number will automatically generate the tracking code for you. Leave blank to disable tracking code."),
    );

    $form['leadbuilder_ctm']['leadbuilder_ctm_access_key'] = array(
        '#type' => 'textfield',
        '#title' => t('Access Key'),
        '#default_value' => variable_get('leadbuilder_ctm_access_key'),
        '#size' => 60,
        '#maxlength' => 128,
        '#description' => t("API credentials required for Sprowt HD to work. The access key can be found under account settings in CTM."),
    );

    $form['leadbuilder_ctm']['leadbuilder_ctm_secret_key'] = array(
        '#type' => 'textfield',
        '#title' => t('Secret Key'),
        '#default_value' => variable_get('leadbuilder_ctm_secret_key'),
        '#size' => 60,
        '#maxlength' => 128,
        '#description' => t("API credentials required for Sprowt HD to work. The secret key can be found under account settings in CTM."),
    );

    $form['company_info']['leadbuilder_settings_contact'] = array(
        '#type' => 'fieldset',
        '#title' => t('Point of Contact'),
    );

    $form['company_info']['leadbuilder_settings_contact']['leadbuilder_settings_contact_name'] = array(
        '#type' => 'textfield',
        '#title' => t('Contact Name'),
        '#default_value' => variable_get('leadbuilder_settings_contact_name'),
        '#size' => 60,
        '#maxlength' => 255,
        '#description' => t("Full name of the point of contact"),
    );

    $form['company_info']['leadbuilder_settings_contact']['leadbuilder_settings_contact_email'] = array(
        '#type' => 'textfield',
        '#title' => t('Contact Email'),
        '#default_value' => variable_get('leadbuilder_settings_contact_email'),
        '#size' => 60,
        '#maxlength' => 255,
        '#description' => t("Email for the point of contact"),
    );

    $form['company_info']['leadbuilder_settings_contact']['leadbuilder_settings_contact_phone'] = array(
        '#type' => 'textfield',
        '#title' => t('Contact Phone'),
        '#default_value' => variable_get('leadbuilder_settings_contact_phone'),
        '#size' => 60,
        '#maxlength' => 255,
        '#description' => t("Phone for the point of contact"),
    );


    $form['leadbuilder_settings_social'] = array(
        '#type' => 'fieldset',
        '#title' => t('Social Settings'),
        '#collapsible' => true,
        '#collapsed' => false,
        '#group' => 'leadbuilder_settings'
    );

    $form['leadbuilder_settings_social']['leadbuilder_settings_social_facebook'] = array(
        '#type' => 'fieldset',
        '#title' => t('Facebook'),
    );

    $form['leadbuilder_settings_social']['leadbuilder_settings_social_facebook']['leadbuilder_settings_facebook_url'] = array(
        '#type' => 'textfield',
        '#title' => t('Company Facebook URL'),
        '#default_value' => variable_get('leadbuilder_settings_facebook_url'),
        '#size' => 60,
        '#maxlength' => 255,
        '#description' => t("Begins with \"http\"."),
    );

    $form['leadbuilder_settings_social']['leadbuilder_settings_social_facebook']['leadbuilder_settings_facebook_description'] = array(
        '#type' => 'textfield',
        '#title' => t('Link Description'),
        '#default_value' => variable_get('leadbuilder_settings_facebook_description'),
        '#size' => 60,
        '#maxlength' => 255,
        '#description' => t("Descriptive text for Facebook link. Ex. 'Be our friend'"),
    );

    $form['leadbuilder_settings_social']['leadbuilder_settings_social_twitter'] = array(
        '#type' => 'fieldset',
        '#title' => t('Twitter'),
    );

    $form['leadbuilder_settings_social']['leadbuilder_settings_social_twitter']['leadbuilder_settings_twitter_handle'] = array(
        '#type' => 'textfield',
        '#title' => t('Company Twitter Handle'),
        '#default_value' => variable_get('leadbuilder_settings_twitter_handle'),
        '#size' => 60,
        '#maxlength' => 255,
        '#description' => t("Company twitter handle (do not include the @)."),
    );

    $form['leadbuilder_settings_social']['leadbuilder_settings_social_twitter']['leadbuilder_settings_twitter_description'] = array(
        '#type' => 'textfield',
        '#title' => t('Link Description'),
        '#default_value' => variable_get('leadbuilder_settings_twitter_description'),
        '#size' => 60,
        '#maxlength' => 255,
        '#description' => t("Descriptive text for Twitter link. Ex. 'Follow us'"),
    );

    $form['leadbuilder_settings_social']['leadbuilder_settings_social_gplus'] = array(
        '#type' => 'fieldset',
        '#title' => t('Google+'),
    );

    $form['leadbuilder_settings_social']['leadbuilder_settings_social_gplus']['leadbuilder_settings_gplus_url'] = array(
        '#type' => 'textfield',
        '#title' => t('Company Google+ URL'),
        '#default_value' => variable_get('leadbuilder_settings_gplus_url'),
        '#size' => 60,
        '#maxlength' => 255,
        '#description' => t("Begins with \"http\"."),
    );

    $form['leadbuilder_settings_social']['leadbuilder_settings_social_gplus']['leadbuilder_settings_gplus_description'] = array(
        '#type' => 'textfield',
        '#title' => t('Link Description'),
        '#default_value' => variable_get('leadbuilder_settings_gplus_description'),
        '#size' => 60,
        '#maxlength' => 255,
        '#description' => t("Descriptive text for Google+ link. Ex. 'Add to circles'"),
    );

    $form['leadbuilder_settings_social']['leadbuilder_settings_social_linkedin'] = array(
        '#type' => 'fieldset',
        '#title' => t('LinkedIn'),
    );

    $form['leadbuilder_settings_social']['leadbuilder_settings_social_linkedin']['leadbuilder_settings_linkedin_url'] = array(
        '#type' => 'textfield',
        '#title' => t('Company LinkedIn URL'),
        '#default_value' => variable_get('leadbuilder_settings_linkedin_url'),
        '#size' => 60,
        '#maxlength' => 255,
        '#description' => t("Begins with \"http\"."),
    );

    $form['leadbuilder_settings_social']['leadbuilder_settings_social_linkedin']['leadbuilder_settings_linkedin_description'] = array(
        '#type' => 'textfield',
        '#title' => t('Link Description'),
        '#default_value' => variable_get('leadbuilder_settings_linkedin_description'),
        '#size' => 60,
        '#maxlength' => 255,
        '#description' => t("Descriptive text for LinkedIn link. Ex. 'Connect with us'"),
    );

    $form['leadbuilder_settings_reviews'] = array(
        '#type' => 'fieldset',
        '#title' => t('Review Sites Settings'),
        '#collapsible' => true,
        '#collapsed' => false,
        '#group' => 'leadbuilder_settings'
    );

    $form['leadbuilder_settings_reviews']['leadbuilder_settings_review_yelp'] = array(
        '#type' => 'fieldset',
        '#title' => t('Yelp'),
    );

    $form['leadbuilder_settings_reviews']['leadbuilder_settings_review_yelp']['leadbuilder_settings_yelp_url'] = array(
        '#type' => 'textfield',
        '#title' => t('Company Yelp URL'),
        '#default_value' => variable_get('leadbuilder_settings_yelp_url'),
        '#size' => 60,
        '#maxlength' => 255,
        '#description' => t("Begins with \"http\"."),
    );

    $form['leadbuilder_settings_reviews']['leadbuilder_settings_review_yelp']['leadbuilder_settings_yelp_description'] = array(
        '#type' => 'textfield',
        '#title' => t('Link Description'),
        '#default_value' => variable_get('leadbuilder_settings_yelp_description'),
        '#size' => 60,
        '#maxlength' => 255,
        '#description' => t("Descriptive text for Yelp link. Ex. 'Read our reviews on Yelp'"),
    );

    $form['leadbuilder_settings_reviews']['leadbuilder_settings_review_bbb'] = array(
        '#type' => 'fieldset',
        '#title' => t('Better Business Bureau'),
    );

    $form['leadbuilder_settings_reviews']['leadbuilder_settings_review_bbb']['leadbuilder_settings_bbb_url'] = array(
        '#type' => 'textfield',
        '#title' => t('Company Better Business Bureau URL'),
        '#default_value' => variable_get('leadbuilder_settings_bbb_url'),
        '#size' => 60,
        '#maxlength' => 255,
        '#description' => t("Begins with \"http\"."),
    );

    $form['leadbuilder_settings_reviews']['leadbuilder_settings_review_bbb']['leadbuilder_settings_bbb_description'] = array(
        '#type' => 'textfield',
        '#title' => t('Link Description'),
        '#default_value' => variable_get('leadbuilder_settings_bbb_description'),
        '#size' => 60,
        '#maxlength' => 255,
        '#description' => t("Descriptive text for BBB link. Ex. 'Read our reviews on BBB'"),
    );

    $form['leadbuilder_settings_reviews']['leadbuilder_settings_review_angie'] = array(
        '#type' => 'fieldset',
        '#title' => t("Angie's List"),
    );

    $form['leadbuilder_settings_reviews']['leadbuilder_settings_review_angie']['leadbuilder_settings_angie_url'] = array(
        '#type' => 'textfield',
        '#title' => t('Company Angie\'s List URL'),
        '#default_value' => variable_get('leadbuilder_settings_angie_url'),
        '#size' => 60,
        '#maxlength' => 255,
        '#description' => t("Begins with \"http\"."),
    );

    $form['leadbuilder_settings_reviews']['leadbuilder_settings_review_angie']['leadbuilder_settings_angie_description'] = array(
        '#type' => 'textfield',
        '#title' => t('Link Description'),
        '#default_value' => variable_get('leadbuilder_settings_angie_description'),
        '#size' => 60,
        '#maxlength' => 255,
        '#description' => t("Descriptive text for Yelp link. Ex. \"Read our reviews on Angie's List\""),
    );

    $form['leadbuilder_settings_reviews']['leadbuilder_settings_review_yp'] = array(
        '#type' => 'fieldset',
        '#title' => t("Yellow Pages"),
    );

    $form['leadbuilder_settings_reviews']['leadbuilder_settings_review_yp']['leadbuilder_settings_yp_url'] = array(
        '#type' => 'textfield',
        '#title' => t('Company Yellow Pages URL'),
        '#default_value' => variable_get('leadbuilder_settings_yp_url'),
        '#size' => 60,
        '#maxlength' => 255,
        '#description' => t("Begins with \"http\"."),
    );

    $form['leadbuilder_settings_reviews']['leadbuilder_settings_review_yp']['leadbuilder_settings_yp_description'] = array(
        '#type' => 'textfield',
        '#title' => t('Link Description'),
        '#default_value' => variable_get('leadbuilder_settings_yp_description'),
        '#size' => 60,
        '#maxlength' => 255,
        '#description' => t("Descriptive text for Yelp link. Ex. \"Read our reviews on the Yellow Pages\""),
    );

    $form['#validate'][] = '_leadbuilder_settings_config_validate';

    return system_settings_form($form);
}

function _leadbuilder_settings_config_validate($form, &$form_state) {
    $values = $form_state['values'];

    $map = $values['leadbuilder_settings_map_embed'];

    if(preg_match('/<iframe.*src="([^"]+)"/', $map, $i)) {
        $form_state['values']['leadbuilder_settings_map_embed'] = $i[1];
    }
}