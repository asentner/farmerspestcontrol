<?php

function sprowt_is_starter($form, &$form_state, &$install_state) {
    drupal_set_title(st('Is This a Sprowt Starter Roll Out?'));
    $path = drupal_get_path('profile', 'sprowt');

    $form['#attached']['css'][] = $path . "/css/sprowt.css";

    $form['actions'] = array();

    $form['actions']['yes'] = array(
        '#type' => 'submit',
        '#submit' => array('_sprowt_is_starter_yes'),
        '#value' => t('Yes'),
    );

    $form['actions']['no'] = array(
        '#type' => 'submit',
        '#submit' => array('_sprowt_is_starter_no'),
        '#value' => t('No'),
    );

    return $form;
}

function _sprowt_is_starter_yes(&$form, &$form_state) {
    variable_set('sprowt_is_starter', true);
}

function _sprowt_is_starter_no(&$form, &$form_state) {
    variable_set('sprowt_is_starter', false);
}

function sprowt_starter_choose_page($form, &$form_state, &$install_state) {
    drupal_set_title(st('Choose a Landing Page'));

    $path = drupal_get_path('profile', 'sprowt');
    $base = "/$path";

    $form['#attached']['js'][] = "https://code.jquery.com/jquery-1.11.2.min.js"; //I don't wanna use drupal's old as dirt jQuery
    $form['#attached']['js'][] = $path . "/js/starter_theme.js";

    $form['#attached']['css'][] = $path . "/css/sprowt.css";
    $form['#attached']['css'][] = $path . "/css/magnific.css";

    $array = array(
        '3f3e2ea8-95d3-49f0-9be6-0343b66c1b37',
        '6917401c-b0e9-4f50-8fe8-9c4fb59262f4',
        'ec7a8b5c-3a7d-4799-8b6d-db1ba0d88b16',
        'db83172b-ffb4-4ae3-a83c-26bbc5276975'
    );

    $options = array();
    foreach($array as $uuid) {
        switch($uuid) {
            case '3f3e2ea8-95d3-49f0-9be6-0343b66c1b37':
                $theme = 1;
                break;
            case '6917401c-b0e9-4f50-8fe8-9c4fb59262f4':
                $theme = 2;
                break;
            case 'ec7a8b5c-3a7d-4799-8b6d-db1ba0d88b16':
                $theme = 3;
                break;
            case 'db83172b-ffb4-4ae3-a83c-26bbc5276975':
                $theme = 4;
                break;
        }

        if(!empty($theme)) {
            $fileNameBase = "landing-page-theme-$theme";
            $img = "$base/images/$fileNameBase.png";
            $thumb = "$base/images/$fileNameBase-thumb.png";
            $html = "<div><h2>Landing Page Theme $theme</h2><div><a href=\"$img\" class=\"image-popup\"><img src=\"$thumb\"></a></div></div>";
            $options[$uuid] = $html;
        }
    }


    $form['choose_page'] = array(
        '#type' => 'radios',
        '#title' => 'Choose a landing page to use',
        '#required' => true,
        '#options' => $options
    );

    $form['actions'] = array();

    $form['actions']['submit'] = array(
        '#type' => 'submit',
        '#value' => t('Save'),
    );

    return $form;
}

function sprowt_starter_choose_page_submit(&$form, &$form_state) {
    $values = $form_state['values'];
    variable_set('sprowt_starter_landing_page_uuid', $values['choose_page']);
}