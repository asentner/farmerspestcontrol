<?php

/**
 * @file
 * Template overrides as well as (pre-)process and alter hooks for the
 * Sprowt 1 theme.
 */


function sprowt_6_form_alter(&$form, &$form_state, $form_id) {
    if (strpos($form_id, 'webform_client_form_') !== false) {
        $node = !empty($form['#node']) ? $form['#node'] : false;
        if(!empty($node)) {
            if (!empty($node->uuid)) {
                if($node->uuid == 'e12bc7a9-07dc-44d5-bf91-1c5f85c1f8ad') {
                    $form['submit']['#weight'] = 1100;
                }
            }
        }
    }
}
