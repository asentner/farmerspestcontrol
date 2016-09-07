<?php

/**
 * Implements hook_preprocess_block().
 */
function sprowt_1_preprocess_block(&$variables) {
  // remove role attribute
  unset($variables['attributes_array']['role']);
}
