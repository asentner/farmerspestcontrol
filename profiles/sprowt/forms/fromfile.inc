<?php

function sprowt_install_from_file($form, &$form_state, &$install_state) {
    drupal_set_title(st('Would You Like to Install From a File?'));

    $form['#attached']['js'][] = drupal_get_path('profile', 'sprowt') . '/js/fromfile.js';
    
    $form['file'] = array(
        '#type' => 'file',
        '#title' => t('Choose a file'),
    );

    $form['actions'] = array();

    $form['actions']['submit'] = array(
        '#type' => 'submit',
        '#value' => t('Install From File'),
        '#validate' => array('_sprowt_install_from_file_validate'),
        '#submit' => array('_sprowt_install_from_file_submit')
    );

    $form['actions']['continue'] = array(
        '#type' => 'submit',
        '#value' => t('Continue With Manual Install'),
    );

    return $form;
}

function _sprowt_install_from_file_validate(&$form, &$form_state) {
    $values = $form_state['values'];
    if(!empty($_FILES['files']['tmp_name']['file'])) {
        $type = $_FILES['files']['type']['file'];
        $tmpFile = $_FILES['files']['tmp_name']['file'];
    }
    else {
        form_error($form['file'], 'File is required');
    }

    if($type !== 'application/json') {
        form_error($form['file'], 'File is not a JSON file.');
    }

    $json = file_get_contents($tmpFile);
    $data = json_decode($json, true);
    if(!isset($data['company_info'])) {
        form_error($form['file'], 'Invalid File');
    }

    $form_state['storage']['data'] = $data;

}

function _sprowt_install_from_file_submit(&$form, &$form_state) {
    $data = $form_state['storage']['data'];
    $sb = new SprowtBuilder();
    $sb->saveData($data);
    global $install_state;
    variable_set('sprowt_install_from_file', true);
}