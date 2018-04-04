<?php

class SprowtException extends \Exception {
    
    /**
     * Constructs a SprowtException.
     *
     * @param string $class
     *   The class which does not correspond to an entity type.
     */
    public function __construct($message) {
        parent::__construct($message);
    }
    
}

require_once('sprowtbuilder.php');

/***
 * Include form functions
 */

foreach(glob(drupal_get_path('profile', 'sprowt') . "/forms/*.inc") as $include) {
    include_once($include);
}


/**
 * Alter tasks order and such
 *
 * implements hook_install_tasks_alter()
 */

function sprowt_install_tasks_alter(&$tasks, &$install_state) {

    _sprowt_set_maintenance_theme("adminimal");

    $tasks['install_select_locale']['function'] = 'sprowt_locale_selection';

    $tasks_performed = $install_state['tasks_performed'];
    if(!isset($install_state['storage'])) {
        $install_state['storage'] = array();
    }
    $install_state['storage']['is_starter'] = variable_get('sprowt_is_starter');


    $task_map = array(
        'install_select_profile',
        'install_select_locale',
        'install_load_profile',
        'install_verify_requirements',
        'install_settings_form', //set up database
        'install_system_module',
        'install_bootstrap_full',
        'sprowt_setup_tables', //sprowt
        'sprowt_is_starter', //sprowt
        'sprowt_starter_choose_page', //sprowt
        'sprowt_company_info', //sprowt
        'sprowt_market_setup', //sprowt
        'sprowt_branding', //sprowt
        'sprowt_users', //sprowt
        'sprowt_locations', //sprowt
        'sprowt_social', //sprowt
        'sprowt_review', //sprowt
        'sprowt_integrations', //sprowt
        'sprowt_module_preinstall', //sprowt
        'install_profile_modules',
        'install_import_locales',
        'sprowt_module_postinstall', //sprowt
        'install_configure_form',
        'sprowt_configure',
    );

    $new_tasks = array();

    foreach($task_map as $task){
        $new_tasks[$task] = $tasks[$task];
        unset($tasks[$task]);
        
        if($task == 'sprowt_starter_choose_page' && empty($install_state['storage']['is_starter'])) {
            $new_tasks[$task]['run'] = INSTALL_TASK_SKIP;
        }
    }

    $new_tasks = $new_tasks + $tasks;

    $tasks = $new_tasks;

}


/**
 * stolen from Kickstart
 *
 * Force-set a theme at any point during the execution of the request.
 *
 * Drupal doesn't give us the option to set the theme during the installation
 * process and forces enable the maintenance theme too early in the request
 * for us to modify it in a clean way.
 */
function _sprowt_set_maintenance_theme($target_theme) {
    if ($GLOBALS['theme'] != $target_theme) {
        unset($GLOBALS['theme']);

        drupal_static_reset();
        $GLOBALS['conf']['maintenance_theme'] = $target_theme;
        $adminimal_settings = variable_get('theme_adminimal_settings', array());
        $adminimal_settings['logo_path'] = 'profiles/sprowt/images/sprowt-logo.png';
        $adminimal_settings['default_logo'] = false;
        //variable_set('theme_adminimal_settings', $adminimal_settings);
        $GLOBALS['conf']['theme_adminimal_settings'] = $adminimal_settings;
        _drupal_maintenance_theme();
        drupal_add_css(drupal_get_path('profile', 'sprowt') . '/css/maintenence.css');
    }
}

/**
 * Default values for confiure page
 * Implements hook_install_configure_form_alter().
 */

function sprowt_form_install_configure_form_alter(&$form, &$form_state) {
    global $install_state;
    drupal_add_css('.messages {display: none;}',array('type' => 'inline'));

    $form['#attached']['js'][] = "https://code.jquery.com/jquery-1.11.2.min.js"; //I don't wanna use drupal's old as dirt jQuery
    $form['#attached']['js'][] = drupal_get_path('profile', 'sprowt') . "/js/configure.js";

    $sb_info = _sprowt_get_data();

    $form['admin_account']['#access'] = false;
    $form['admin_account']['account']['name']['#required'] = false;
    $form['admin_account']['account']['mail']['#required'] = false;
    $form['admin_account']['account']['pass']['#required'] = false;

    $form['admin_account']['account']['name']['#value'] = 'coalmarch';
    $form['admin_account']['account']['mail']['#value'] = 'devel@coalmarch.com';
    $form['server_settings']['site_default_country']['#default_value'] = 'US';

    $form['site_information']['site_mail']['#value'] = 'devel@coalmarch.com';

    if(!empty($sb_info['company_info']['company_name'])){
        $form['site_information']['site_name']['#default_value'] = $sb_info['company_info']['company_name'];
    }

    if($_SERVER['REMOTE_ADDR'] == '127.0.0.1') {
        $form['update_notifications']['update_status_module']['#default_value'] = array(1, 0);
    }
}

/**
 * Default values for database confiure page
 * Implements hook_install_settings_form_alter().
 */
function system_form_install_settings_form_alter(&$form, &$form_state) {
    $form['settings']['mysql']['username']['#default_value'] = 'root';
    $form['settings']['mysql']['password']['#attributes']['value'] = 'root';

    //Only for testing purposes
    //$form['settings']['mysql']['database']['#attributes']['value'] = 'sprowt';
}


function sprowt_locale_selection(&$install_state){
    $install_state['parameters']['locale'] = 'en';
    return;
}

function sprowt_setup_tables($install_state){

    if(db_table_exists('sprowt_setup')){
        db_drop_table('sprowt_setup');
    }

    $sprowt_setup_schema = array(
        'description' => 'The initial setup for this sprowt site',
        'fields' => array(
            'setup_id' => array('type' => 'serial', 'unsigned' => true, 'not null' => true),
            'form_name' => array('type'=> 'varchar', 'length' => 255, 'not null' => true, 'default' => ''),
            'form_field' => array('type'=> 'varchar', 'length' => 255, 'not null' => true, 'default' => ''),
            'field_value' => array('type'=> 'text'),
        ),
        'indexes' => array(
            'form' => array('form_name')
        ),
        'primary key' => array('setup_id')
    );

    db_create_table('sprowt_setup', $sprowt_setup_schema);


    if(db_table_exists('sprowt_process')){
        db_drop_table('sprowt_process');
    }

    $sprowt_setup_schema = array(
        'description' => 'The process db for Sprowt',
        'fields' => array(
            'process_id' => array('type'=> 'varchar', 'length' => 255, 'not null' => true, 'default' => ''),
            'message' => array('type'=> 'varchar', 'length' => 255, 'not null' => true, 'default' => ''),
            'status' => array('type'=> 'varchar', 'length' => 255, 'not null' => true, 'default' => ''),
        ),
        'primary key' => array('process_id')
    );

    db_create_table('sprowt_process', $sprowt_setup_schema);

}



/**
 * Function for getting the user names of the default users
 */
function _sprowt_get_default_usernames(){
    $glob = getcwd() . "default_users/*.json";
    $json_files = glob(getcwd() . "/profiles/sprowt/default_users/*.json");

    $names = array();
    foreach($json_files as $file){
        $json = file_get_contents($file);
        $user = json_decode($json, true);
        $names[$user['username']] = array($user['first_name'],$user['last_name']);
    }

    return $names;
}

/**
 * Submit function for forms to save to the sprowt_setup table
 */
function _sprowt_save_to_table($form_name, $fields) {

    $insert = db_insert('sprowt_setup')
        ->fields(
            array(
                'form_name',
                'form_field',
                'field_value',
            ));

    foreach($fields as $form_field=>$field_value) {
        $insert->values(array(
            'form_name' => $form_name,
            'form_field' => $form_field,
            'field_value' => $field_value
        ));
    }

    $insert->execute();
}

/**
 * Set up base config for pantheon
 */
function sprowt_configure() {
    // Set default Pantheon variables
    variable_set('cache', 1);
    variable_set('block_cache', 1);
    variable_set('cache_lifetime', '0');
    variable_set('page_cache_maximum_age', '900');
    variable_set('page_compression', 0);
    variable_set('preprocess_css', 1);
    variable_set('preprocess_js', 1);
    $search_active_modules = array(
        'apachesolr_search' => 'apachesolr_search',
        'user' => 'user',
        'node' => 0
    );
    variable_set('search_active_modules', $search_active_modules);
    variable_set('search_default_module', 'apachesolr_search');
    drupal_set_message(t('Pantheon defaults configured.'));
}


/**
 * Get features to enable
 */

function _sprowt_get_features(){
    $data = _sprowt_get_data();
    $theme = $data['branding']['theme'];
    
    $sprowt_info = drupal_get_path('profile', 'sprowt') . '/features.info';
    $theme_info = drupal_get_path('theme', $theme) . '/features.info';
    
    $features = array();
    if(file_exists($sprowt_info)) {
        $info = drupal_parse_info_file($sprowt_info);
        $features = (!empty($info['features'])) ? $info['features'] : array();
    }
    
    if(file_exists($theme_info)) {
        $info = drupal_parse_info_file($theme_info);
        $theme_features = (!empty($info['features'])) ? $info['features'] : array();
        $features = array_merge($features, $theme_features);
        $overrides = (!empty($info['overrides'])) ? $info['overrides'] : array();
        foreach($overrides as $orig => $new) {
            $key = array_search($orig, $features);
            $features[$key] = $new;
        }
    }
    
    return $features;
}

/**
 * Some pre-install stuff
 */
function sprowt_module_preinstall() {
    //set this to false so that the batch module install doesn't break
    //we'll rebuild the features at the end when we revert them all
    variable_set('features_rebuild_on_module_install', false);

    //merge features and modules that are being installed
    $features = _sprowt_get_features();
    $modules = variable_get('install_profile_modules', array());

    $modules = array_merge($modules, $features);

    variable_set('install_profile_modules', $modules);
}

/**
 * Function for installing features and other modules
 */

function sprowt_module_postinstall(){

    variable_set('features_rebuild_on_module_install', true);

    //disabling comment module

    module_disable(array('comment'));

    //hopefully this fixes the weird issues we get on a fresh Pantheon rollout
    system_list_reset();
    drupal_flush_all_caches();
}


function sprowt_setup(&$install_state){

    $sb = new SprowtBuilder();
    $data = $sb->getData();
    $id = md5(serialize($data));

    if(!empty($install_state['forms']['drush_setup'])){
        $sb->addUsers();
        $sb->addBranding();
        $sb->addNodes();
        $sb->addCompanyInfo();
        $sb->addMarketsServices();
        $sb->addLocations();
        $sb->addSocial();
        $sb->addIntegrations();
        return true;
    }
    else {
        return false;
    }
}

function _sprowt_get_data(){
    $sb = new SprowtBuilder();
    return $sb->getData();
}

function _sprowt_form_default($field_name, $default = '') {
    if(!empty($_GET['example_values'])) {
        if($_GET['example_values'] == 1) {
            switch ($field_name) {
                case 'company_name':
                    return 'Company Name';
                    break;
                case 'company_phone':
                    return '9195555555';
                    break;
                case 'contact_name':
                    return 'Contact Name';
                    break;
                case 'contact_email':
                    return 'contact@email.com';
                    break;
                case 'contact_phone':
                    return '9194444444';
                    break;
                case 'services':
                    $services = array (
                        array (
                            'service-1' => 'Lawn Care',
                        ),
                        array (
                            'service-2' => 'Seeding',
                        ),
                        array (
                            'service-3' => 'Aerating',
                        ),
                        array (
                            'service-4' => 'Pest Control',
                        ),
                        array (
                            'service-5' => 'Termite Control',
                        ),
                    );
                    return json_encode($services);
                    break;
                case 'region_markets':
                    $markets = array (
                        'region-1' =>
                            array (
                                'regionName' => 'Triangle',
                                'markets' =>
                                    array (
                                        array (
                                            'region-2-market-1' => 'Raleigh',
                                        ),
                                        array (
                                            'region-2-market-2' => 'Durham',
                                        ),
                                        array (
                                            'region-2-market-3' => 'Chapel Hill',
                                        ),
                                    ),
                            ),
                    );
                    return json_encode($markets);
                    break;
                case 'additional_users':
                    $users = array (
                        array (
                            'username' => 'wmcmillian',
                            'password' => '',
                            'email' => 'wmcmillian@coalmarch.com',
                            'first_name' => 'Will',
                            'last_name' => 'McMillian',
                            'position' => 'PHP Developer',
                            'roles' =>
                                array (
                                    'administrator',
                                ),
                            'image' => '/profiles/sprowt/images/coalmarch/wmcmillian.jpg',
                            'id' => 'wmcmillian',
                        ),
                    );
                    return json_encode($users);
                    break;
                case 'locations':
                    $locations = array (
                        array (
                            'id' => 'location-1',
                            'name' => 'Location Name',
                            'address' => '101 Test Ave',
                            'city' => 'Localplace',
                            'state' => 'NC',
                            'zip' => '27601',
                            'phone' => '9195555555',
                            'email' => 'location@email.com',
                            'gplus' => 'http://locationgplus.com',
                        ),
                    );
                    return json_encode($locations);
                    break;
                case 'facebook':
                    return 'http://facebook.com';
                    break;
                case 'twitter':
                    return 'twitterhandle';
                    break;
                case 'linkedin':
                    return 'http://linkedin.com';
                    break;
                case 'gplus':
                    return 'http://gplusurl.com';
                    break;
                case 'sprowt_settings_yelp_url':
                    return 'http://yelp.com';
                    break;
                case 'sprowt_settings_bbb_url':
                    return 'http://bbb.com';
                    break;
                case 'sprowt_settings_angie_url':
                    return 'http://angieslist.com';
                    break;
                case 'sprowt_settings_yp_url':
                    return 'http://yp.com';
                    break;
                case 'gtm':
                    return 'GTM-123456';
                    break;
                case 'optimizely_id':
                    return 'optimizely123';
                    break;
                case 'theme':
                    return 'sprowt_1';
                    break;
                case 'new_theme_name':
                    return 'Sprowt Theme 1';
                    break;
                case 'new_theme':
                    require_once DRUPAL_ROOT . '/' . drupal_get_path('profile', 'sprowt') . '/includes/themebuilder.php';
                    $TB = new ThemeBuilder();
                    return $TB->machine_nameify('Sprowt Theme 1');
                case 'primary_color':
                    return '#2ca8fc';
                    break;
                case 'secondary_color':
                    return '#ff9913';
                    break;
                case 'tertiary_color':
                    return '#eeeeee';
                    break;
                case 'webform_to_email':
                    return 'company@email.com';
                    break;
                case 'webform_from_email':
                    return 'company@email.com';
                    break;
                case 'webform_from_name':
                    return 'Company From Name';
                    break;
                default:
                    return $default;
                    break;
            }
        }
    }

    return $default;
}

function sprowt_require_class($include) {
    require_once drupal_get_path('profile', 'sprowt') . '/includes/' . "$include.php";
}

function sprowt_is_sprowt_theme($theme) {
    sprowt_require_class('themebuilder');
    $TB = new ThemeBuilder();
    $sprowt_themes = $TB->sprowt_themes();
    
    return in_array($theme, array_keys($sprowt_themes));
}

function sprowt_add_cm_user($username) {
    require_once drupal_get_path('profile', 'sprowt') . '/includes/userbuilder.php';
    
    $UB = new UserBuilder();
    
    if($account = $UB->addCoalmarchUser($username)) {
        _user_mail_notify('register_admin_created', $account);
    }
    else {
        throw new SprowtException('Coalmarch user, '.$username.',  could not be created');
    }
}