<?php

/**
 * This file is normally used to set up multisite. But we can use it to add code
 * that would normally go into settings.php without having to create a
 * settings.php file
 */

/**
 * Environment Indicator
 */
$conf['environment_indicator_overwrite'] = TRUE;
$conf['environment_indicator_overwritten_position'] = 'top';
$conf['environment_indicator_overwritten_fixed'] = FALSE;
if (!defined('PANTHEON_ENVIRONMENT')) {
    $conf['environment_indicator_overwritten_name'] = 'Local';
    $conf['environment_indicator_overwritten_color'] = '#808080';
    $conf['environment_indicator_overwritten_text_color'] = '#ffffff';
}
// Pantheon Env Specific Config
if (isset($_SERVER['PANTHEON_ENVIRONMENT'])) {
    switch ($_SERVER['PANTHEON_ENVIRONMENT']) {
        case 'dev':
            $conf['environment_indicator_overwritten_name'] = 'Dev';
            $conf['environment_indicator_overwritten_color'] = '#d25e0f';
            $conf['environment_indicator_overwritten_text_color'] = '#ffffff';
            break;
        case 'test':
            $conf['environment_indicator_overwritten_name'] = 'Test';
            $conf['environment_indicator_overwritten_color'] = '#c50707';
            $conf['environment_indicator_overwritten_text_color'] = '#ffffff';
            break;
        case 'live':
            $conf['environment_indicator_overwritten_name'] = 'Live!';
            $conf['environment_indicator_overwritten_color'] = '#4C742C';
            $conf['environment_indicator_overwritten_text_color'] = '#ffffff';
            break;
    }
}