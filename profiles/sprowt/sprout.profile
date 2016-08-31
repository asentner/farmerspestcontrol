<?php

require_once('sproutbuilder.php');

/***
 * Include form functions
 */

foreach(glob(drupal_get_path('profile', 'sprout') . "/forms/*.inc") as $include) {
    include_once($include);
}


/**
 * Alter tasks order and such
 *
 * implements hook_install_tasks_alter()
 */

function sprout_install_tasks_alter(&$tasks, $install_state) {

    _sprout_set_maintenance_theme("adminimal");

    $tasks['install_select_locale']['function'] = 'sprout_locale_selection';


    $task_map = array(
        'install_select_profile',
        'install_select_locale',
        'install_load_profile',
        'install_verify_requirements',
        'install_settings_form', //set up database
        'install_system_module',
        'install_bootstrap_full',
        'sprout_setup_tables', //sprout
        'sprout_company_info', //sprout
        'sprout_market_setup', //sprout
        'sprout_branding', //sprout
        'sprout_users', //sprout
        'sprout_locations', //sprout
        'sprout_social', //sprout
        'sprout_review', //sprout
        'sprout_integrations', //sprout
        'install_profile_modules',
        'install_import_locales',
        'sprout_install_features', //sprout
        'install_configure_form',
        'sprout_configure',
    );

    $new_tasks = array();

    foreach($task_map as $task){
        $new_tasks[$task] = $tasks[$task];
        unset($tasks[$task]);
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
function _sprout_set_maintenance_theme($target_theme) {
    if ($GLOBALS['theme'] != $target_theme) {
        unset($GLOBALS['theme']);

        drupal_static_reset();
        $GLOBALS['conf']['maintenance_theme'] = $target_theme;
        $adminimal_settings = variable_get('theme_adminimal_settings', array());
        $adminimal_settings['logo_path'] = 'profiles/sprout/images/sprowt-logo.png';
        $adminimal_settings['default_logo'] = false;
        //variable_set('theme_adminimal_settings', $adminimal_settings);
        $GLOBALS['conf']['theme_adminimal_settings'] = $adminimal_settings;
        _drupal_maintenance_theme();
        drupal_add_css(drupal_get_path('profile', 'sprout') . '/css/maintenence.css');
    }
}

/**
 * Default values for confiure page
 * Implements hook_install_configure_form_alter().
 */

function sprout_form_install_configure_form_alter(&$form, &$form_state) {
    global $install_state;
    drupal_add_css('.messages {display: none;}',array('type' => 'inline'));

    $form['#attached']['js'][] = "https://code.jquery.com/jquery-1.11.2.min.js"; //I don't wanna use drupal's old as dirt jQuery
    $form['#attached']['js'][] = drupal_get_path('profile', 'sprout') . "/js/configure.js";

    $sb_info = _sprout_get_data();

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
    //$form['settings']['mysql']['database']['#attributes']['value'] = 'sprout';
}


function sprout_locale_selection(&$install_state){
    $install_state['parameters']['locale'] = 'en';
    return;
}

function sprout_setup_tables($install_state){

    if(db_table_exists('sprout_setup')){
        db_drop_table('sprout_setup');
    }

    $sprout_setup_schema = array(
        'description' => 'The initial setup for this leadbuilder site',
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

    db_create_table('sprout_setup', $sprout_setup_schema);


    if(db_table_exists('sprout_process')){
        db_drop_table('sprout_process');
    }

    $sprout_setup_schema = array(
        'description' => 'The process db for Sprout',
        'fields' => array(
            'process_id' => array('type'=> 'varchar', 'length' => 255, 'not null' => true, 'default' => ''),
            'message' => array('type'=> 'varchar', 'length' => 255, 'not null' => true, 'default' => ''),
            'status' => array('type'=> 'varchar', 'length' => 255, 'not null' => true, 'default' => ''),
        ),
        'primary key' => array('process_id')
    );

    db_create_table('sprout_process', $sprout_setup_schema);

}



/**
 * Function for getting the user names of the default users
 */
function _sprout_get_default_usernames(){
    $glob = getcwd() . "default_users/*.json";
    $json_files = glob(getcwd() . "/profiles/sprout/default_users/*.json");

    $names = array();
    foreach($json_files as $file){
        $json = file_get_contents($file);
        $user = json_decode($json, true);
        $names[$user['username']] = array($user['first_name'],$user['last_name']);
    }

    return $names;
}

/**
 * Submit function for forms to save to the sprout_setup table
 */
function _sprout_save_to_table($form_name, $fields) {

    $insert = db_insert('sprout_setup')
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
function sprout_configure() {
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
 * Function for installing features and other modules
 */

function sprout_install_features(){

    /*
  //Grabbing the theme
  $array = array(
    ':form' => 'branding',
    ':field' => 'theme'
  );
  $theme = str_replace("-","_", db_query("SELECT field_value FROM sprout_setup WHERE form_name = :form AND form_field = :field", $array)->fetchField());
  */

    //base features
    $base_features = array(
        'leadbuilder_taxonomy',
        'leadbuilder_fields_and_text_formats',
        'leadbuilder_content_types',
        'leadbuilder_views_feature',
        'leadbuilder_user_settings',
        'leadbuilder_menu_settings'
    );

    foreach($base_features as $feature){
        module_enable(array($feature));
    }

    //disabling comment module

    module_disable(array('comment'));

}


function sprout_setup(&$install_state){

    $sb = new SproutBuilder();
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

function _sprout_get_data(){
    $sb = new SproutBuilder();
    return $sb->getData();
}

function _sprout_form_default($field_name, $default = '') {
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
                            'image' => '/profiles/sprout/images/coalmarch/wmcmillian.jpg',
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
                case 'leadbuilder_settings_yelp_url':
                    return 'http://yelp.com';
                    break;
                case 'leadbuilder_settings_bbb_url':
                    return 'http://bbb.com';
                    break;
                case 'leadbuilder_settings_angie_url':
                    return 'http://angieslist.com';
                    break;
                case 'leadbuilder_settings_yp_url':
                    return 'http://yp.com';
                    break;
                case 'gtm':
                    return 'GTM-123456';
                    break;
                case 'optimizely_id':
                    return 'optimizely123';
                    break;
                case 'theme':
                    return 'template_qaclawn';
                    break;
                case 'new_theme_name':
                    return 'Sprout Theme 1';
                    break;
                case 'new_theme':
                    require_once DRUPAL_ROOT . '/' . drupal_get_path('profile', 'sprout') . '/includes/themebuilder.php';
                    $TB = new ThemeBuilder();
                    return $TB->machine_nameify('Sprout Theme 1');
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