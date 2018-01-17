<?php

/**
 * @file
 * Contains a pre-process hook for 'field'.
 */

/**
 * Implements hook_preprocess_block().
 */
function sprowt_theme_preprocess_field(&$variables) {
    $element = &$variables['element'];
    $parent = &$element['#object'];

    $variables['theme_hook_suggestions'][] = 'field__' . $element['#field_name'] . '__' . $element['#entity_type'];
    $variables['theme_hook_suggestions'][] = 'field__' . $element['#field_name'] . '__' . $element['#entity_type'] . '__' . $element['#bundle'];
}
