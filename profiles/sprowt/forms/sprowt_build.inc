<?php

function sprowt_save_file($form, &$form_state, &$install_state){
    drupal_set_title('Would you like to save these settings to a file?');

    $file_url = '/profiles/sprowt/build_file.php';

    $form['save_file'] = array(
        '#type' => 'markup',
        '#markup' => '<p>Download the file below to re-use in future Sprowt rollouts:</p><p><a href="'.$file_url.'" target="_blank">Get File</a></p>'
    );

    $form['actions'] = array();
    $form['actions']['submit'] = array(
        '#type' => 'submit',
        '#value' => t('Continue'),
    );

    return $form;
}