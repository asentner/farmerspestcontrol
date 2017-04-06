<?php

/**
 * @file
 * Webform module textfield component.
 */

/**
 * Implements _webform_defaults_component().
 */
function _webform_defaults_zipcode() {
    return array(
        'name' => '',
        'form_key' => NULL,
        'pid' => 0,
        'weight' => 0,
        'value' => '',
        'required' => 0,
        'extra' => array(
            'format' => '00000',
            'field_prefix' => '',
            'field_suffix' => '',
            'disabled' => 0,
            'unique' => 0,
            'restrictions' => '',
            'restriction_error_message' => 'Zip code is restricted.',
            'title_display' => 0,
            'description' => '',
            'description_above' => FALSE,
            'placeholder' => '',
            'attributes' => array(),
            'private' => FALSE,
            'analysis' => FALSE,
        ),
    );
}

/**
 * Implements _webform_theme_component().
 */
function _webform_theme_zipcode() {
    return array(
        'webform_display_zipcode' => array(
            'render element' => 'element',
            //'file' => 'zip.inc',
        ),
    );
}

/**
 * Implements _webform_edit_component().
 */
function _webform_edit_zipcode($component) {
    $form = array();
    $form['value'] = array(
        '#type' => 'textfield',
        '#title' => t('Default value'),
        '#default_value' => $component['value'],
        '#description' => t('The default value of the field.') . ' ' . theme('webform_token_help'),
        '#size' => 60,
        '#maxlength' => 1024,
        '#weight' => 0,
    );
    $form['display']['format'] = array(
        '#type' => 'textfield',
        '#title' => t('Format'),
        '#default_value' => $component['extra']['format'],
        '#description' => t('The format of the zipcode. Use "A" for an alpha character and 0 for an integer. Spaces and dashes (-) are also allowed.'),
        '#size' => 10,
        '#maxlength' => 10,
        '#weight' => 0,
        '#parents' => array('extra', 'format'),
        '#required' => true
    );
    $form['display']['placeholder'] = array(
        '#type' => 'textfield',
        '#title' => t('Placeholder'),
        '#default_value' => $component['extra']['placeholder'],
        '#description' => t('The placeholder will be shown in the field until the user starts entering a value.'),
        '#weight' => 1,
        '#parents' => array('extra', 'placeholder'),
    );
    $form['display']['field_prefix'] = array(
        '#type' => 'textfield',
        '#title' => t('Prefix text placed to the left of the textfield'),
        '#default_value' => $component['extra']['field_prefix'],
        '#description' => t('Examples: $, #, -.'),
        '#size' => 20,
        '#maxlength' => 127,
        '#weight' => 2.1,
        '#parents' => array('extra', 'field_prefix'),
    );
    $form['display']['field_suffix'] = array(
        '#type' => 'textfield',
        '#title' => t('Postfix text placed to the right of the textfield'),
        '#default_value' => $component['extra']['field_suffix'],
        '#description' => t('Examples: lb, kg, %.'),
        '#size' => 20,
        '#maxlength' => 127,
        '#weight' => 2.2,
        '#parents' => array('extra', 'field_suffix'),
    );
    $form['display']['disabled'] = array(
        '#type' => 'checkbox',
        '#title' => t('Disabled'),
        '#return_value' => 1,
        '#description' => t('Make this field non-editable. Useful for displaying default value. Changeable via JavaScript or developer tools.'),
        '#weight' => 11,
        '#default_value' => $component['extra']['disabled'],
        '#parents' => array('extra', 'disabled'),
    );
    $form['validation']['unique'] = array(
        '#type' => 'checkbox',
        '#title' => t('Unique'),
        '#return_value' => 1,
        '#description' => t('Check that all entered values for this field are unique. The same value is not allowed to be used twice.'),
        '#weight' => 1,
        '#default_value' => $component['extra']['unique'],
        '#parents' => array('extra', 'unique'),
    );
    $form['validation']['restrictions'] = array(
        '#type' => 'textarea',
        '#title' => t('Restrictions'),
        '#description' => t('Restrict to only these zipcodes. Separated by line. These should match the format below. Leave blank to leave zip codes unrestricted.'),
        '#weight' => 2,
        '#default_value' => $component['extra']['restrictions'],
        '#parents' => array('extra', 'restrictions'),
    );
    $form['validation']['restriction_error_message'] = array(
        '#type' => 'textfield',
        '#title' => t('Restrictions error message'),
        '#description' => t('Error message displayed when a restricted zip is chosen'),
        '#weight' => 3,
        '#default_value' => $component['extra']['restriction_error_message'],
        '#parents' => array('extra', 'restriction_error_message'),
    );
    return $form;
}

/**
 * Implements _webform_render_component().
 */
function _webform_render_zipcode($component, $value = NULL, $filter = TRUE, $submission = NULL) {
    $node = isset($component['nid']) ? node_load($component['nid']) : NULL;
    
    $element = array(
        '#type' => 'textfield',
        '#title' => $filter ? webform_filter_xss($component['name']) : $component['name'],
        '#title_display' => $component['extra']['title_display'] ? $component['extra']['title_display'] : 'before',
        '#default_value' => $filter ? webform_replace_tokens($component['value'], $node) : $component['value'],
        '#required' => $component['required'],
        '#weight' => $component['weight'],
        '#field_prefix' => empty($component['extra']['field_prefix']) ? NULL : ($filter ? webform_filter_xss($component['extra']['field_prefix']) : $component['extra']['field_prefix']),
        '#field_suffix' => empty($component['extra']['field_suffix']) ? NULL : ($filter ? webform_filter_xss($component['extra']['field_suffix']) : $component['extra']['field_suffix']),
        '#description' => $filter ? webform_filter_descriptions($component['extra']['description'], $node) : $component['extra']['description'],
        '#attributes' => $component['extra']['attributes'],
        '#theme_wrappers' => array('webform_element'),
        '#translatable' => array('title', 'description', 'field_prefix', 'field_suffix'),
    );
    
    if ($component['required']) {
        $element['#attributes']['required'] = 'required';
    }
    
    if ($component['extra']['placeholder']) {
        $element['#attributes']['placeholder'] = $component['extra']['placeholder'];
    }
    
    if ($component['extra']['disabled']) {
        if ($filter) {
            $element['#attributes']['readonly'] = 'readonly';
        }
        else {
            $element['#disabled'] = TRUE;
        }
    }
    
    $width = strlen($component['extra']['format']);
    $element['#size'] = $width;
    $element['#maxlength'] = $width;
    
    // Enforce uniqueness.
    if ($component['extra']['unique']) {
        $element['#element_validate'][] = 'webform_validate_unique';
    }
    
    if (isset($value[0])) {
        $element['#default_value'] = $value[0];
    }
    
    $element['#element_validate'][] = 'webform_zipcode_restriction_validate_zipcode';
    
    $rests = $component['extra']['restrictions'];
    if(!empty($rests)){
        $element['#autocomplete_path'] = "webform_zipcode_restriction_autocomplete/{$component['nid']}/{$component['cid']}";
    }
    
    return $element;
}

/**
 * Implements _webform_display_component().
 */
function _webform_display_zipcode($component, $value, $format = 'html', $submission = array()) {
    return array(
        '#title' => $component['name'],
        '#title_display' => $component['extra']['title_display'] ? $component['extra']['title_display'] : 'before',
        '#weight' => $component['weight'],
        '#theme' => 'webform_display_textfield',
        '#theme_wrappers' => $format == 'html' ? array('webform_element') : array('webform_element_text'),
        '#field_prefix' => $component['extra']['field_prefix'],
        '#field_suffix' => $component['extra']['field_suffix'],
        '#format' => $format,
        '#value' => isset($value[0]) ? $value[0] : '',
        '#translatable' => array('title', 'field_prefix', 'field_suffix'),
    );
}

/**
 * Format the output of data for this component.
 */
function theme_webform_display_zipcode($variables) {
    $element = $variables['element'];
    $prefix = $element['#format'] == 'html' ? '' : $element['#field_prefix'];
    $suffix = $element['#format'] == 'html' ? '' : $element['#field_suffix'];
    $value = $element['#format'] == 'html' ? check_plain($element['#value']) : $element['#value'];
    return $value !== '' ? ($prefix . $value . $suffix) : ' ';
}


/**
 * Implements _webform_table_component().
 */
function _webform_table_zipcode($component, $value) {
    return check_plain(empty($value[0]) ? '' : $value[0]);
}

/**
 * Implements _webform_action_set_component().
 */
function _webform_action_set_zipcode($component, &$element, &$form_state, $value) {
    $element['#value'] = $value;
    form_set_value($element, $value, $form_state);
}

/**
 * Implements _webform_csv_headers_component().
 */
function _webform_csv_headers_zipcode($component, $export_options) {
    $header = array();
    $header[0] = '';
    $header[1] = '';
    $header[2] = $export_options['header_keys'] ? $component['form_key'] : $component['name'];
    return $header;
}

/**
 * Implements _webform_csv_data_component().
 */
function _webform_csv_data_zipcode($component, $export_options, $value) {
    return !isset($value[0]) ? '' : $value[0];
}
