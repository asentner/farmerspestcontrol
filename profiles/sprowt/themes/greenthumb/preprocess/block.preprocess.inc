<?php

/**
 * Implements hook_preprocess_block().
 */
function greenthumb_preprocess_block(&$variables) {
  // remove role attribute
  unset($variables['attributes_array']['role']);
}