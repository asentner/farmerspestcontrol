<?php

/**
 * Implements hook_preprocess_node().
 */
function sprowt_starter_preprocess_node(&$variables) {
  // remove role attribute
  unset($variables['attributes_array']['role']);
}
