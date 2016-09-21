<?php

function sprowt_drush_command() {
    $items = array();

    $access = (!defined('PANTHEON_ENVIRONMENT'));
    if($access) {
        $items['block-export'] = array(
            'description' => 'Export blocks and theme block settings to a file in the json format.',
            'arguments' => array(
                'bids'
            ),
            'options'     => array(
                'theme' => 'Machine Name of the theme to get the settings from',
                'location' => 'directory to place the export file',
                'file-name' => 'name of the export file'
            ),
            'examples'    => array(
                'drush block-export --theme=interstate',
                'drush sbe --theme=interstate --location="profiles/sprowt/themes/interstate" --file-name="interstate-block-export.json"',
                'drush sbe'
            ),
            'aliases'     => array('sbe'),
        );

        $items['menu-export'] = array(
            'description' => 'Export menu links to a file in the json format.',
            'arguments' => array('menu'),
            'options' => array(
                'location' => 'directory to place the export file',
                'file-name' => 'name of the export file'
            ),
            'examples' => array(
                'drush menu-export menu-mobile-menu',
                'drush sme menu-mobile-menu'
            ),
            'aliases' => array('sme')
        );
    }

    $items['cm-add'] = array(
        'description' => 'Add a coalmarch user',
        'options' => array(
            'name' => 'coalmarch username'
        ),
        'examples' => array(
            'drush cm-add --name=wmcmillian',
            'drush cm-add',
            'drush cma'
        ),
        'aliases' => array('cma')
    );

    return $items;
}

function drush_sprowt_block_export($bids = array()) {
    $bids = drush_get_arguments();
    if(!is_array($bids)) {
        if(!empty($bids)) {
            $bids = array($bids);
        }
    }
    $theme = drush_get_option('theme');
    $location = drush_get_option('location');
    $file_name = drush_get_option('file-name');

    if(empty($theme)) {
        $theme_list = list_themes(TRUE);
        $options = array();
        $locations = array();
        foreach($theme_list as $theme_name => $object) {
            $options[$theme_name] = $theme_name;
            $theme_location = str_replace("/$theme_name.info", "", $object->filename);
            $locations[$theme_name] = $theme_location;
        }
        $choice = drush_choice($options, dt('Which theme would you like to export block settings from?'));

        if($choice) {
            $theme = $choice;
        }
        else {
            drush_set_error('Block Export Error', 'Block Export requires a theme to be chosen!');
        }
    }

    if(empty($location)) {
        if(empty($locations)) {
            $theme_list = list_themes(TRUE);
            $locations = array();
            foreach($theme_list as $theme_name => $object) {
                $theme_location = str_replace("/$theme_name.info", "", $object->filename);
                $locations[$theme_name] = $theme_location;
            }
        }
        $default_location = $locations[$theme];
        $prompt = 'Where would you like this file placed?';
        $location = drush_prompt($prompt, $default_location);
    }

    if(empty($file_name)) {
        $default = $theme . '_block_export.json';
        $prompt = 'What would you like the file name to be?';
        $file_name = drush_prompt($prompt, $default);
    }

    if (strpos($location, '/') !== 0) {
        $location = DRUPAL_ROOT . '/' . $location;
    }

    _drush_sprowt_block_export_validate_options($theme, $location, $file_name);

    require_once drupal_get_path('profile', 'sprowt') . '/includes/blockbuilder.php';

    $BB = new BlockBuilder();

    $file_location = $location . '/' . $file_name;

    $BB->exportToFile($theme, $file_location);
}

function _drush_sprowt_block_export_validate_options($theme, $location, $file_name) {
    if(!empty($theme)) {
        $theme_list = list_themes(TRUE);

        if (!isset($theme_list[$theme])) {
            drush_set_error('Block Export Error', 'You must select a valid theme');
        }
    }

    if(!empty($location)) {
        if (strpos($location, '/') !== 0) {
            $location = DRUPAL_ROOT . '/' . $location;
        }

        if (!is_dir($location) || !is_writable($location)) {
            drush_set_error('Block Export Error', "Location must exist and be writable [$location]");
        }
    }

    if(!empty($file_name)) {
        $file_location = $location . '/' . $file_name;
        if(file_exists($file_location)) {
            $prompt = 'File exists! Would you like to overwrite the file at "'.$file_location.'"?';
            if(!drush_confirm($prompt)) {
                drush_user_abort();
            }

            if(!is_writable($file_location)) {
                drush_set_error('Block Export Error', "File must be writable [$file_location]");
            }
        }
    }
}

function drush_sprowt_menu_export($menu) {
    if(!menu_load($menu)) {
        drush_set_error('Invalid Menu');
    }

    $location = drush_get_option('location');
    $file_name = drush_get_option('file-name');

    if(empty($location)) {
        $default_location = '.';
        $prompt = 'Where would you like this file placed?';
        $location = drush_prompt($prompt, $default_location);
    }

    if(empty($file_name)) {
        $default = $menu . '_link_export.json';
        $prompt = 'What would you like the file name to be?';
        $file_name = drush_prompt($prompt, $default);
    }

    $file_path = rtrim($location, '/' . "\t\n\r \v") . '/' . ltrim($file_name, '/' . "\t\n\r \v");

    require_once drupal_get_path('profile', 'sprowt') . '/includes/menubuilder.php';

    $MB = new MenuBuilder();
    $MB->exportToFile($menu, $file_path);
}

function drush_sprowt_cm_add(){
    require_once drupal_get_path('profile', 'sprowt') . '/includes/userbuilder.php';

    $UB = new UserBuilder();
    $username = drush_get_option('name');

    if(empty($username)) {
        $files = glob(drupal_get_path('profile', 'sprowt') . '/coalmarch_users/*.json');
        $options = array();
        foreach($files as $file) {
            $filename = basename($file);
            $user = str_replace('.json', '', $filename);
            $options[$user] = $user;
        }

        $username = drush_choice($options, dt('Which user would you like to add?'));
    }

    if($UB->addCoalmarchUser($username)) {
        echo "$username Added!\n";
    }
    else {
        drush_log("There was an error. $username not added.", 'error');
    }

}