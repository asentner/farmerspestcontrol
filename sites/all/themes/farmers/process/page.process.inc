<?php

/**
 * Implements hook_process_page().
 */
function farmers_process_page(&$variables) {
  // You can use process hooks to modify the variables before they are passed to
  // the theme function or template file.
  if (module_exists('color')) {
    _color_page_alter($variables);
  }
}
