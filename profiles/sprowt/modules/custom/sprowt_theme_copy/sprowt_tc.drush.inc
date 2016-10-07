<?php

function sprowt_tc_drush_command() {
    $items = array();
    
    $access = (!defined('PANTHEON_ENVIRONMENT'));
    if(!$access) {
        $access = (PANTHEON_ENVIRONMENT == 'kalabox');
    }
    if($access) {
        $items['theme-copy'] = array(
            'description' => 'Copy a sprowt theme to the sites/all/themes directory',
            'arguments'   => array(
                'old'      => 'Machine Name for Sprowt theme being copied',
                'new-name' => 'Name of new theme'
            ),
            'options'     => array(
                'old' => 'Machine Name for Sprowt theme being copied',
                'new' => 'Human readable name of new theme',
                'machine-name' => 'Machine Name of the new theme',
                'primary'   => 'Hex of primary color',
                'secondary' => 'Hex of secondary color',
                'tertiary'  => 'Hex of tertiary color'
            ),
            'examples'    => array(
                'drush theme-copy sprowt_starter "New Theme"',
                'drush stc sprowt_starter "New Theme" --primary="#000000" --secondary="#123456" --tertiary="#999999"',
                'drush stc sprowt_starter "New Theme" --machine-name=new --primary="#000000" --secondary="#123456" --tertiary="#999999"'
            ),
            'aliases'     => array('stc'),
        );
    }

    return $items;
}

function drush_sprowt_tc_theme_copy($old = '', $new_name = '') {
    $machine_name = drush_get_option('machine-name');
    $primary = drush_get_option('primary');
    $secondary = drush_get_option('secondary');
    $tertiary = drush_get_option('tertiary');
    
    if(empty($old)) {
        $theme_list = list_themes(TRUE);
        $options = array();
        foreach($theme_list as $theme_name => $theme) {
            $options[$theme_name] = $theme->info['name'];
        }
        $choice = drush_choice($options, dt('Which theme would you like to copy?'));
    
        if($choice) {
            $old = $choice;
        }
        else {
            return drush_set_error('Theme Copy Error', 'Theme copy requires a theme to be chosen!');
        }
    }
    
    if(empty($new_name)) {
        $new_name = drush_prompt('What human readable name would you like the new theme to use?', null, true);
    }

    if(!empty($machine_name)) {
        $machine_name = sprowt_theme_copy_machine_name($machine_name);
    }
    else {
        $machine_name = sprowt_theme_copy_machine_name($new_name);
        $machine_name = drush_prompt('What machine name would you like the new theme to use?', $machine_name);
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