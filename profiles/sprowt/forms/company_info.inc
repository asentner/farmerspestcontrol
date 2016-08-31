<?php
/**
 * Company Info form
 */

function sprowt_company_info($form, &$form_state, &$install_state){

    drupal_set_title(st('Configure Company Input'));
    $form['company_info'] = array(
        'company_name' => array(
            '#type' => 'textfield',
            '#title' => t('Company Name'),
            '#required' => true,
            '#default_value' => _sprowt_form_default('company_name')
        ),
        'company_phone' => array(
            '#type' => 'textfield',
            '#title' => t('Company Phone'),
            '#required' => true,
            '#description' => 'Phone number used to throughout the site. Should be 10 digits and all numbers. e.g.: 9195555555',
            '#default_value' => _sprowt_form_default('company_phone')
        ),
        'webform' => array(
            '#type' => 'fieldset',
            '#title' => t('Webform Settings'),
            '#description' => 'These are the settings for the from name and from email that all webforms added by the installer will use',
            '#collapsible' => false,
            '#collapsed' => false,
            'webform_to_email' => array(
                '#type' => 'textfield',
                '#title' => t('To Email'),
                '#required' => true,
                '#description' => 'This is the email all webform submissions are sent <strong>to</strong>. This should be an email at the domain the site is at (example@thissite.com) not a gmail, yahoo, or other account. This is so that emails don\'t get flagged as spam. This can be a comma seperated list.',
                '#default_value' => _sprowt_form_default('webform_to_email')
            ),
            'webform_from_email' => array(
                '#type' => 'textfield',
                '#title' => t('From Email'),
                '#required' => true,
                '#description' => 'This is the email all webform submissions are sent <strong>from</strong>. This should be an email at the domain the site is at (example@thissite.com) not a gmail, yahoo, or other account. This is so that emails don\'t get flagged as spam. This can be a comma seperated list.',
                '#default_value' => _sprowt_form_default('webform_from_email')
            ),
            'webform_from_name' => array(
                '#type' => 'textfield',
                '#title' => t('From Name'),
                '#required' => true,
                '#description' => 'This is the <strong>from name</strong> all emails are sent from.',
                '#default_value' => _sprowt_form_default('webform_from_name')
            ),
        ),
        'contact' => array(
            '#type' => 'fieldset',
            '#title' => t('Point of Contact'),
            '#collapsible' => false,
            '#collapsed' => false,
            '#description' => 'This is the company contact. This info isn\'t currently used anywhere on the site, but simply stored in the database and displayed in Sprowt Settings',
            'contact_name' => array(
                '#type' => 'textfield',
                '#title' => t('Contact Name'),
                '#default_value' => _sprowt_form_default('contact_name')
            ),
            'contact_email' => array(
                '#type' => 'textfield',
                '#title' => t('Contact Email'),
                '#default_value' => _sprowt_form_default('contact_email')
            ),
            'contact_phone' => array(
                '#type' => 'textfield',
                '#title' => t('Contact Phone'),
                '#default_value' => _sprowt_form_default('contact_phone')
            ),
        ),
    );

    $form['actions']['submit'] = array(
        '#type' => 'submit',
        '#value' => t('Save'),
    );

    return $form;

}

function sprowt_company_info_validate($form, &$form_state){
    $values = $form_state['values'];
    $field_names = array(
        'company_name',
        'company_phone',
        'contact_name',
        'contact_email',
        'contact_phone',
        'webform_from_email',
        'webform_from_name',
        'webform_to_email'
    );
    $fields = array();
    foreach($field_names as $fn) {
        $fields[$fn] = $values[$fn];
    }

    $form_state['values']['webform_from_email'] = _sprowt_check_email('webform_from_email', $fields['webform_from_email']);
    $form_state['values']['webform_to_email'] = _sprowt_check_email('webform_to_email', $fields['webform_to_email']);

    if(!empty($fields['contact_email'])){
        $form_state['values']['contact_email'] = _sprowt_check_email('contact_email', $fields['contact_email']);
    }

    if(!preg_match('/^[\d]{10}$/',$fields['company_phone'])) {
        form_set_error('company_phone', 'Please enter a valid phone number.');
    }

    if(!empty($fields['contact_phone']) && !preg_match('/^[\d]{10}$/',$fields['contact_phone'])) {
        form_set_error('contact_phone', 'Please enter a valid phone number.');
    }
}

function _sprowt_check_email($field_name, &$emails) {
    $emails = explode(',', $emails);

    if(!is_array($emails)) {
        $emails = array($emails);
    }

    foreach ($emails as &$email) {
        $email = trim($email);
        if(!valid_email_address($email)) {
            form_set_error($field_name, 'Please enter a valid email for field.');
        }
    }

    $emails = implode(',',$emails);

    return $emails;
}

function sprowt_company_info_submit($form, &$form_state){
    $values = $form_state['values'];
    $field_names = array(
        'company_name',
        'company_phone',
        'contact_name',
        'contact_email',
        'contact_phone',
        'webform_from_email',
        'webform_from_name',
        'webform_to_email'
    );
    $fields = array();
    foreach($field_names as $fn) {
        $fields[$fn] = $values[$fn];
    }

    _sprowt_save_to_table('company_info', $fields);
}