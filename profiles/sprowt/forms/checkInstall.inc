<?php

function sprowt_check_install($form, &$form_state, &$install_state) {
    $file_url = '/profiles/sprowt/build_file.php';

    $markup = "<h1 class=\"error\">An error occurred while installing Sprowt!</h1><p>Please wipe the environment and refresh this page to try again.</p>";
    $form['uhoh'] = array(
        '#type' => 'markup',
        '#markup' => $markup
    );

    $form['save_file'] = array(
        '#type' => 'markup',
        '#markup' => '<p><strong>Be sure to download the file below to re-use your configurations!</strong>:</p><p><a href="'.$file_url.'" target="_blank">Get File</a></p>'
    );

    if(!empty($_ENV['PANTHEON_SITE'])) {
        $link = "https://dashboard.pantheon.io/sites/{$_ENV['PANTHEON_SITE']}#{$_ENV['PANTHEON_ENVIRONMENT']}/content/wipe";
        $wipeMarkup = "<p>To wipe the environment proceed to <a href=\"$link\" target='\"_blank\"'>here</a> and click \"Wipe the {$_ENV['PANTHEON_ENVIRONMENT']} Environment\" and follow the instructions. Then refresh this page.</p>";
        $form['wipe'] = array(
            '#type' => 'markup',
            '#markup' => $wipeMarkup
        );
    }

    $form['actions'] = array();
    $form['actions']['submit'] = array(
        '#type' => 'submit',
        '#value' => t('Continue Anyway'),
    );

    return $form;
}