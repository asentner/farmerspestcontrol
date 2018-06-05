<?php

/**
 * Implements hook_process_html().
 */
function sprowt_6_process_html(&$variables) {
  // You can use process hooks to modify the variables before they are passed to
  // the theme function or template file.
  if (module_exists('color')) {
    _color_html_alter($variables);
  }
}
