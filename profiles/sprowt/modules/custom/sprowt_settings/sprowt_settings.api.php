<?php

/**
 * Implements hook_sprowt_shortcode_replace_alter().
 *
 * Alter the default replace pattern for Sprowt phone numbers
 *
 * @param $replace Default phone number pattern split into three chunks
 *      ($1 = first 3 numbers, $2 = second 3 numbers, $3 = last 4 numbers)
 */
function hook_sprowt_phone_pattern_alter(&$replace) {
    $replace = "$1.$2.$3";
}

/**
 * Implements hook_sprowt_shortcode_replace_alter().
 *
 * Alter the shortcode replacement array. The keys are the short code and the values are what they're replaced with.
 *
 * @param $shortcodes
 */
function hook_sprowt_shortcode_replace_alter(&$shortcodes) {
    $shortcodes['[shortcode-name]'] = 'shortcode value';
}

/**
 * Implements hook_sprowt_shortcode_replace().
 *
 * Hook that allows a module to completely customize the shortcode replacement.
 * The code should be in the $string variable.
 * You should return the string after the shortcode's been replaced.
 *
 * @param $string
 * @return mixed
 */
function hook_sprowt_shortcode_replace($string) {
    //replacement code to manipulate $string;
    return $string;
}