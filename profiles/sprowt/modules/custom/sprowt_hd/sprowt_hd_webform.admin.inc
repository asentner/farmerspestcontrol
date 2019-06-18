<?php

/**
 * Implements hook_webform_form_settings()
 *
 * @param array $form
 * @param array $form_state
 * @param object $node
 * @return array
 */
function sprowt_hd_webform_form_settings($form, $form_state, $node)
{
    $account_id = variable_get('sprowt_ctm_account_id');
    $access_key = variable_get('sprowt_ctm_access_key');
    $secret_key = variable_get('sprowt_ctm_secret_key');

    if (empty($account_id) || empty($access_key) || empty($secret_key)) {
        // Compatibility with older Sprowt sites. If older site, use drush to set the variables! The three above are the required vars for this module.
        // Can be set under Sprowt Settings for sprowt upstream sites
        // eg. drush vset --exact sprowt_ctm_account_id 123456
        if (module_exists('sprowt_settings')) {
            $message = 'WARNING! Don\'t forget to set the CTM Account ID, API Access Key, and Secret Key in <a href="/admin/config/system/sprowt-settings">Sprowt Settings</a>. The API credentials are required for the form reactor to function.';
        } else {
            $message = 'WARNING! Don\'t forget to set the CTM Account ID, API Access Key, and Secret Key with Drush.';
        }
        drupal_set_message($message, 'warning');
    }

    $formData = db_query('SELECT * FROM sprowt_hd_webform WHERE nid = :nid', array(
        ':nid' => $node->nid,
    ))->fetchAssoc();

    if (false === $formData) {
        $formData = array();
    }

    // Grab the current webform components
    $options = array();
    if (count($node->webform['components'])) {
        foreach($node->webform['components'] as $component) {
            $options[$component['form_key']] = t($component['name']);
        }
    }

    $form['nid'] = array(
        '#type' => 'hidden',
        '#value' => $node->nid,
    );

    $form['form_reactor_enabled'] = array(
        '#title' => t('Enable Form Reactor'),
        '#type' => 'checkbox',
        '#weight' => 0,
        '#default_value' => (array_key_exists('form_reactor_enabled', $formData)) ? $formData['form_reactor_enabled'] : null,
    );

    $form['form_reactor'] = array(
        '#type' => 'fieldset',
        '#title' => 'CTM Form Reactor',
        '#weight' => 1,
        '#states' => array(
            'disabled' => array(
                'input[name=\'form_reactor_enabled\']' => array('checked' => false)
            ),
        ),
    );

    $form['form_reactor']['form_reactor_id'] = array(
        '#type' => 'textfield',
        '#title' => 'Form Reactor ID',
        '#default_value' => (array_key_exists('form_reactor_id', $formData)) ? $formData['form_reactor_id'] : null,
    );

    $form['form_reactor']['first_name_field'] = array(
        '#type' => 'select',
        '#title' => 'First/Full Name Field',
        '#description' => 'Select the webform component you use for the first name (or full name)',
        '#options' => array_merge(
            array(
                '' => '- Select -'
            ), $options
        ),
        '#default_value' => (array_key_exists('form_reactor_first_name_field', $formData)) ? $formData['form_reactor_first_name_field'] : null,
    );

    $form['form_reactor']['last_name_field'] = array(
        '#type' => 'select',
        '#title' => 'Last Name Field (Optional)',
        '#description' => 'Select the webform component you use for the last name (leave blank if this field does not exist)',
        '#options' => array_merge(
            array(
                '' => '- Select -'
            ), $options
        ),
        '#default_value' => (array_key_exists('form_reactor_last_name_field', $formData)) ? $formData['form_reactor_last_name_field'] : null,
    );

    $form['form_reactor']['email_field'] = array(
        '#type' => 'select',
        '#title' => 'Email Field',
        '#description' => 'Select the webform component you use for the email address',
        '#options' => array_merge(
            array(
                '' => '- Select -'
            ), $options
        ),
        '#default_value' => (array_key_exists('form_reactor_email_field', $formData)) ? $formData['form_reactor_email_field'] : null,
    );

    $form['form_reactor']['phone_field'] = array(
        '#type' => 'select',
        '#title' => 'Phone Field',
        '#description' => 'Select the webform component you use for the phone number',
        '#options' => array_merge(
            array(
                '' => '- Select -'
            ), $options
        ),
        '#default_value' => (array_key_exists('form_reactor_phone_field', $formData)) ? $formData['form_reactor_phone_field'] : null,
    );

  $form['form_reactor']['address_field'] = array(
    '#type' => 'select',
    '#title' => 'Address Field',
    '#description' => 'Select the webform component you use for the address',
    '#options' => array_merge(
      array(
        '' => '- Select -'
      ), $options
    ),
    '#default_value' => (array_key_exists('form_reactor_address_field', $formData)) ? $formData['form_reactor_address_field'] : null,
  );

  $form['form_reactor']['city_field'] = array(
    '#type' => 'select',
    '#title' => 'City Field',
    '#description' => 'Select the webform component you use for the city',
    '#options' => array_merge(
      array(
        '' => '- Select -'
      ), $options
    ),
    '#default_value' => (array_key_exists('form_reactor_city_field', $formData)) ? $formData['form_reactor_city_field'] : null,
  );

  $form['form_reactor']['state_field'] = array(
    '#type' => 'select',
    '#title' => 'State Field',
    '#description' => 'Select the webform component you use for the State',
    '#options' => array_merge(
      array(
        '' => '- Select -'
      ), $options
    ),
    '#default_value' => (array_key_exists('form_reactor_state_field', $formData)) ? $formData['form_reactor_state_field'] : null,
  );

  $form['form_reactor']['zip_field'] = array(
    '#type' => 'select',
    '#title' => 'Zip Field',
    '#description' => 'Select the webform component you use for the Zip',
    '#options' => array_merge(
      array(
        '' => '- Select -'
      ), $options
    ),
    '#default_value' => (array_key_exists('form_reactor_zip_field', $formData)) ? $formData['form_reactor_zip_field'] : null,
  );

    $customFields = _sprowt_hd_get_custom_fields($node->nid);

    $form['form_reactor']['custom_fields_wrap'] = [
        '#type' => 'fieldset',
        '#title' => 'Custom Fields',
        'custom_fields' => [
            '#type' => 'hidden',
            '#attributes' => [
                'id' => 'customFields'
            ],
            '#default_value' => json_encode($customFields)
        ],
        'custom_fields_display' => [
            '#type' => 'markup',
            '#markup' => '<div id="customFieldsDisplay"></div>'
        ],
        'add_custom_field' => [
            '#type' => 'button',
            '#value' => 'Add Custom Field',
            '#attributes' => [
                'id' => 'addCustomField'
            ]
        ]
    ];

    $form['custom_field_template'] = [
        '#type' => 'fieldset',
        '#collapsible' => false,
        '#prefix' => '<script type="javascript/template" id="customFieldTemplate">',
        '#suffix' => '</script>',
        '#attributes' => [
            'class' => ['custom-field-fieldset']
        ],
        'fieldId' => [
            '#type' => 'textfield',
            '#title' => 'Custom Field ID',
            '#description' => 'Custom field id set in the Form Reactor settings. Everything after the hash (e.g. \'field_123456\')',
            '#attributes' => [
                'name' => '',
                'class' => ['field-id']
            ]
        ],
        'customFieldField' => [
            '#type' => 'select',
            '#title' => 'Webform Field',
            '#description' => 'Select the webform component you want to use to fill this field',
            '#options' => array_merge(
                [
                    '' => '- Select -'
                ], $options
            ),
            '#attributes' => [
                'name' => '',
                'class' => ['field-field']
            ]
        ],
        'removeCustomField' => [
            '#type' => 'button',
            '#value' => 'Remove',
            '#attributes' => [
                'class' => ['field-remove']
            ]
        ]
    ];

    $form['submit'] = array(
        '#weight' => 100,
        '#type' => 'submit',
        '#value' => ('Save Configuration'),
    );

    $form['#attached']['js'][] = drupal_get_path('module', 'sprowt_hd') . '/js/webform_form.js';

    $form['#validate'][] = 'sprowt_hd_webform_form_settings_validate';
    $form['#limit_validation_errors'] = array();

    return $form;
}

function sprowt_hd_webform_form_settings_validate($form, &$form_state)
{
    //form_set_error('email_field', t('You must select an email component.'));
    if ($form_state['values']['form_reactor_id'] == '') {
        form_set_error('form_reactor_id', t('You must enter the form reactor id for this to work!'));
    }
}

/**
 * @param $form
 * @param $form_state
 */
function sprowt_hd_webform_form_settings_submit($form, &$form_state)
{
    db_delete('sprowt_hd_webform')->condition('nid', $form_state['values']['nid'])->execute();

    $fields = array(
        'nid' => $form_state['values']['nid'],
        'form_reactor_enabled' => $form_state['values']['form_reactor_enabled'],
        'form_reactor_id' => $form_state['values']['form_reactor_id'],
        'form_reactor_first_name_field' => $form_state['values']['first_name_field'],
        'form_reactor_last_name_field' => $form_state['values']['last_name_field'],
        'form_reactor_email_field' => $form_state['values']['email_field'],
        'form_reactor_phone_field' => $form_state['values']['phone_field'],
        'form_reactor_address_field' => $form_state['values']['address_field'],
        'form_reactor_city_field' => $form_state['values']['city_field'],
        'form_reactor_state_field' => $form_state['values']['state_field'],
        'form_reactor_zip_field' => $form_state['values']['zip_field'],
    );

    db_insert('sprowt_hd_webform')->fields($fields)->execute();
    drupal_set_message('Form Reactor information has been saved!');

    if(!empty($form_state["values"]["custom_fields"])) {
        $fields = json_decode($form_state["values"]["custom_fields"], true);
        if(!empty($fields)) {
            _sprowt_hd_add_custom_fields($form_state['values']['nid'], $fields);
        }
    }

}

function _sprowt_hd_add_custom_fields($nid, $fields) {
    db_delete('sprowt_hd_webform_custom_fields')->condition('nid', $nid)->execute();
    foreach($fields as $field) {
        $record = [
            'nid' => $nid,
            'field_id' => trim($field['fieldId']),
            'webform_field' => $field['field']
        ];
        if(!empty($record['field_id']) && !empty($record['webform_field'])) {
            drupal_write_record('sprowt_hd_webform_custom_fields', $record);
        }
    }
}