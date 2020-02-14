<?php

function _sprowt_admin_menu_block(){
    $item = menu_get_item();
    if ($content = system_admin_menu_block($item)) {
        $output = theme('admin_block_content', array('content' => $content));
    }
    else {
        $output = t('You do not have any administrative items.');
    }
    return $output;
}

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

    $form['company_info']['sprowt_settings_webform_to_email'] = array(
        '#type' => 'textfield',
        '#title' => t('Webform Email'),
        '#default_value' => variable_get('sprowt_settings_webform_to_email'),
        '#size' => 60,
        '#maxlength' => 1000,
        '#description' => t("Email typically used as the 'to' email in webforms."),
    );

    $form['company_info']['sprowt_settings_company_type'] = array(
        '#type' => 'radios',
        '#title' => t('Company Type'),
        '#required' => true,
        '#description' => 'The type of services this Sprowt company provides',
        '#default_value' => variable_get('sprowt_settings_company_type', 'home_services'),
        '#options' => _sprowt_company_types()
    );

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

    $form['company_info']['sprowt_customer_login'] = array(
        '#type' => 'textfield',
        '#title' => t('Customer Login/My Account link'),
        '#default_value' => variable_get('sprowt_customer_login'),
        '#size' => 60,
        '#maxlength' => 1000,
        '#description' => t("Customer login link used throughout site."),
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

    if(!module_exists('ctm_api')) {


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
    }
    else {
        $form['sprowt_ctm']['ctm_setup_link'] = array(
            '#type' => 'markup',
            '#title' => t('CTM API Module Installed'),
            '#markup' => '<p>Go <a href="/admin/config/services/ctm-settings">here</a> to set up.</p>'
        );
    }

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

    $form['sprowt_settings_social'] = _sprowt_settings_socialmedia_form($form['sprowt_settings_social'], []);
    $form['#validate'] = is_array($form['#validate']) ? array_merge($form['#validate'], $form['sprowt_settings_social']['#validate']) : $form['sprowt_settings_social']['#validate'];
    $form['#submit'] = is_array($form['#submit']) ? array_merge($form['#submit'], $form['sprowt_settings_social']['#submit']) : $form['sprowt_settings_social']['#submit'];
    unset($form['sprowt_settings_social']['#validate']);
    unset($form['sprowt_settings_social']['#submit']);
//    $form['sprowt_settings_social']['sprowt_settings_social_template'] = array(
//        '#type' => 'fieldset',
//        '#title' => t('Facebook'),
//        '#prefix' => '<script type="text/html-template" id="socialTemplate">',
//        '#suffix' => '</script>',
//    );
//
//    $form['sprowt_settings_social']['sprowt_settings_social_template']['sprowt_settings_facebook_url'] = array(
//        '#type' => 'textfield',
//        '#title' => t('Company Facebook URL'),
//        '#default_value' => variable_get('sprowt_settings_facebook_url'),
//        '#size' => 60,
//        '#maxlength' => 255,
//        '#description' => t("Begins with \"http\"."),
//    );
//
//    $form['sprowt_settings_social']['sprowt_settings_social_template']['sprowt_settings_facebook_description'] = array(
//        '#type' => 'textfield',
//        '#title' => t('Link Description'),
//        '#default_value' => variable_get('sprowt_settings_facebook_description'),
//        '#size' => 60,
//        '#maxlength' => 255,
//        '#description' => t("Descriptive text for Facebook link. Ex. 'Be our friend'"),
//    );
//
//    $form['sprowt_settings_social']['sprowt_settings_social_facebook'] = array(
//        '#type' => 'fieldset',
//        '#title' => t('Facebook'),
//    );
//
//    $form['sprowt_settings_social']['sprowt_settings_social_facebook']['sprowt_settings_facebook_url'] = array(
//        '#type' => 'textfield',
//        '#title' => t('Company Facebook URL'),
//        '#default_value' => variable_get('sprowt_settings_facebook_url'),
//        '#size' => 60,
//        '#maxlength' => 255,
//        '#description' => t("Begins with \"http\"."),
//    );
//
//    $form['sprowt_settings_social']['sprowt_settings_social_facebook']['sprowt_settings_facebook_description'] = array(
//        '#type' => 'textfield',
//        '#title' => t('Link Description'),
//        '#default_value' => variable_get('sprowt_settings_facebook_description'),
//        '#size' => 60,
//        '#maxlength' => 255,
//        '#description' => t("Descriptive text for Facebook link. Ex. 'Be our friend'"),
//    );
//
//    $form['sprowt_settings_social']['sprowt_settings_social_twitter'] = array(
//        '#type' => 'fieldset',
//        '#title' => t('Twitter'),
//    );
//
//    $form['sprowt_settings_social']['sprowt_settings_social_twitter']['sprowt_settings_twitter_handle'] = array(
//        '#type' => 'textfield',
//        '#title' => t('Company Twitter Handle'),
//        '#default_value' => variable_get('sprowt_settings_twitter_handle'),
//        '#size' => 60,
//        '#maxlength' => 255,
//        '#description' => t("Company twitter handle (do not include the @)."),
//    );
//
//    $form['sprowt_settings_social']['sprowt_settings_social_twitter']['sprowt_settings_twitter_description'] = array(
//        '#type' => 'textfield',
//        '#title' => t('Link Description'),
//        '#default_value' => variable_get('sprowt_settings_twitter_description'),
//        '#size' => 60,
//        '#maxlength' => 255,
//        '#description' => t("Descriptive text for Twitter link. Ex. 'Follow us'"),
//    );
//
//    $form['sprowt_settings_social']['sprowt_settings_social_gplus'] = array(
//        '#type' => 'fieldset',
//        '#title' => t('Google+'),
//    );
//
//    $form['sprowt_settings_social']['sprowt_settings_social_gplus']['sprowt_settings_gplus_url'] = array(
//        '#type' => 'textfield',
//        '#title' => t('Company Google+ URL'),
//        '#default_value' => variable_get('sprowt_settings_gplus_url'),
//        '#size' => 60,
//        '#maxlength' => 255,
//        '#description' => t("Begins with \"http\"."),
//    );
//
//    $form['sprowt_settings_social']['sprowt_settings_social_gplus']['sprowt_settings_gplus_description'] = array(
//        '#type' => 'textfield',
//        '#title' => t('Link Description'),
//        '#default_value' => variable_get('sprowt_settings_gplus_description'),
//        '#size' => 60,
//        '#maxlength' => 255,
//        '#description' => t("Descriptive text for Google+ link. Ex. 'Add to circles'"),
//    );
//
//    $form['sprowt_settings_social']['sprowt_settings_social_linkedin'] = array(
//        '#type' => 'fieldset',
//        '#title' => t('LinkedIn'),
//    );
//
//    $form['sprowt_settings_social']['sprowt_settings_social_linkedin']['sprowt_settings_linkedin_url'] = array(
//        '#type' => 'textfield',
//        '#title' => t('Company LinkedIn URL'),
//        '#default_value' => variable_get('sprowt_settings_linkedin_url'),
//        '#size' => 60,
//        '#maxlength' => 255,
//        '#description' => t("Begins with \"http\"."),
//    );
//
//    $form['sprowt_settings_social']['sprowt_settings_social_linkedin']['sprowt_settings_linkedin_description'] = array(
//        '#type' => 'textfield',
//        '#title' => t('Link Description'),
//        '#default_value' => variable_get('sprowt_settings_linkedin_description'),
//        '#size' => 60,
//        '#maxlength' => 255,
//        '#description' => t("Descriptive text for LinkedIn link. Ex. 'Connect with us'"),
//    );
//
//    $form['sprowt_settings_social']['sprowt_settings_social_instagram'] = array(
//        '#type' => 'fieldset',
//        '#title' => t('Instagram'),
//    );
//
//    $form['sprowt_settings_social']['sprowt_settings_social_instagram']['sprowt_settings_instagram_handle'] = array(
//        '#type' => 'textfield',
//        '#title' => t('Company Instagram Handle'),
//        '#default_value' => variable_get('sprowt_settings_instagram_handle'),
//        '#size' => 60,
//        '#maxlength' => 255,
//        '#description' => t("Company instagram handle (do not include the @)."),
//    );
//
//    $form['sprowt_settings_social']['sprowt_settings_social_instagram']['sprowt_settings_instagram_description'] = array(
//        '#type' => 'textfield',
//        '#title' => t('Link Description'),
//        '#default_value' => variable_get('sprowt_settings_instagram_description'),
//        '#size' => 60,
//        '#maxlength' => 255,
//        '#description' => t("Descriptive text for Instagram link. Ex. 'Follow us'"),
//    );

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

function _sprowt_settings_config_validate(&$form, &$form_state) {
    $values = $form_state['values'];

    $map = $values['sprowt_settings_map_embed'];

    if(preg_match('/<iframe.*src="([^"]+)"/', $map, $i)) {
        $form_state['values']['sprowt_settings_map_embed'] = $i[1];
    }

    $customer_login = $values['sprowt_customer_login'];
    if(!empty($customer_login)) {
        if (!drupal_valid_path($customer_login)) {
            $el = &$form['company_info']['sprowt_customer_login'];
            form_error($el, 'Customer login must be a valid url or drupal path.');
        }
    }
}

function sprowt_settings_add_coalmarch_user($form, &$form_state) {

}

function sprowt_install_file() {
    require_once drupal_get_path('profile', 'sprowt') . '/sprowtbuilder.php';
    $sprowtbuilder = new SprowtBuilder();

    $data = $sprowtbuilder->getData();


    $filename = strtolower($data['company_info']['company_name']);
    $filename = preg_replace('/[^a-z0-9_]+/', '_', $filename);
    trim($filename, '_');
    $filename .= "__sprowt_setup.json";

    header('Content-disposition: attachment; filename=' . $filename);
    header('Content-type: application/json');

    echo json_encode($data, JSON_PRETTY_PRINT);
}
