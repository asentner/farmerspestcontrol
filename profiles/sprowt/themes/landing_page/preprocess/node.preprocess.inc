<?php

/**
 * @file
 * Contains a pre-process hook for 'node'.
 */

/**
 * Implements hook_preprocess_node().
 */
function landing_page_preprocess_node(&$variables) {
    $node = $variables['node'];
    if($node->type == 'benefit') {
        $something = 'something';
    }
}
