<?php

/**
 * @file
 * Contains a pre-process hook for 'field'.
 */

/**
 * Implements hook_preprocess_field().
 */
function sprowt_theme_preprocess_field(&$variables) {
    $element = &$variables['element'];
    $parent = &$element['#object'];

    $variables['theme_hook_suggestions'][] = 'field__' . $element['#field_name'] . '__' . $element['#entity_type'];
    $variables['theme_hook_suggestions'][] = 'field__' . $element['#field_name'] . '__' . $element['#entity_type'] . '__' . $element['#bundle'];

    $textfields = array(
        'text',
        'text_long',
        'list_text',
        'link_field',
        'text_with_summary'
    );
    if(in_array($element['#field_type'], $textfields)) {
        $something = 'something';
        switch($element['#field_type']) {
            case 'text':
                foreach($variables['items'] as &$item) {
                    str_replace('$', '<span class="dollar">$</span>', $item['#markup']);
                }
                break;
        }
    }

}
