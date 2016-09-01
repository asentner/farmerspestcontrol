<?php

function sprowt_tc_drush_command() {
    $items = array();

    $access = ($_SERVER['REMOTE_ADDR'] == '127.0.0.1');
    if($access) {
        $items['theme-copy'] = array(
            'description' => 'Copy a sprout theme to the sites/all/themes directory',
            'arguments'   => array(
                'old'      => 'Machine Name for Sprout theme being copied',
                'new-name' => 'Name of new theme'
            ),
            'options'     => array(
                'machine-name' => 'Machine Name of the new theme',
                'primary'   => 'Hex of primary color',
                'secondary' => 'Hex of secondary color',
                'tertiary'  => 'Hex of tertiary color'
            ),
            'examples'    => array(
                'drush theme-copy sprout_starter "New Theme"',
                'drush stc sprout_starter "New Theme" --primary="#000000" --secondary="#123456" --tertiary="#999999"',
                'drush stc sprout_starter "New Theme" --machine-name=new --primary="#000000" --secondary="#123456" --tertiary="#999999"'
            ),
            'aliases'     => array('stc'),
        );
    }

    return $items;
}

function drush_sprowt_tc_theme_copy($old, $new_name) {
    $machine_name = drush_get_option('machine-name');
    $primary = drush_get_option('primary');
    $secondary = drush_get_option('secondary');
    $tertiary = drush_get_option('tertiary');

    if(!empty($machine_name)) {
        $machine_name = sprowt_theme_copy_machine_name($machine_name);
    }
    else {
        $machine_name = sprowt_theme_copy_machine_name($new_name);
    }

    $path = DRUPAL_ROOT . "/sites/all/themes/$machine_name";

    $confirm = false;

    if(is_dir($path)) {
        $confirm = drush_confirm('Theme Exists! Do you wish to overwrite it?');
    }

    $_GET['overwrite'] = $confirm;

    if(_sprowt_theme_copy_copy_theme($old, $new_name, $machine_name, $primary, $secondary, $tertiary)) {
        print "\nTheme copied to $path\n\n";
    }

}

function drush_sprowt_tc_theme_copy_validate() {

    $args = drush_get_arguments();

    if(count($args) > 3 || count($args) < 3) {
        drush_set_error('Theme Copy Error', 'Invalid number of arguments supplied');
    }

    $options = array(
        'primary' => drush_get_option('primary'),
        'secondary' => drush_get_option('secondary'),
        'tertiary' => drush_get_option('tertiary'),
    );

    foreach($options as $opt => $v) {
        if(!empty($v)) {
            $valid = preg_match('/^\#[\dA-Fa-f]{3}$|^\#[\dA-Fa-f]{6}$/', $v);
            if(empty($valid)) {
                drush_set_error('Theme Copy Error', "Hex for $opt is invalid");
            }
        }
    }
}