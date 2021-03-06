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

    drupal_add_js(drupal_get_path('profile', 'sprowt') . '/js/empty.js');

    //maybe this is getting unset somewhere?
    $install_state['parameters']['profile'] = 'sprowt';

    if(empty($GLOBALS['conf']['maintenance_theme']) || $GLOBALS['conf']['maintenance_theme'] != 'adminimal') {
        _sprowt_set_maintenance_theme("adminimal");
    }

    $tasks['install_select_locale']['function'] = 'sprowt_locale_selection';

    if(!isset($install_state['storage'])) {
        $install_state['storage'] = array();
    }
    if(!empty($install_state['tasks_performed']) && in_array('install_bootstrap_full', $install_state['tasks_performed'])) {
        $Sprowtbuilder = new SprowtBuilder();
        $install_state['storage']['is_starter'] = $Sprowtbuilder->is_starter();
    }
    $install_state['storage']['from_file'] = variable_get('sprowt_install_from_file', false);


    $task_map = array(
        'install_select_profile',
        'install_select_locale',
        'install_load_profile',
        'install_verify_requirements',
        'install_settings_form', //set up database
        'install_system_module',
        'install_bootstrap_full',
        'sprowt_setup_tables', //sprowt
        'sprowt_install_from_file', //sprowt
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
        'sprowt_save_file', //sprowt
        'sprowt_module_preinstall', //sprowt
        'install_profile_modules',
        'install_import_locales',
        'sprowt_module_postinstall', //sprowt
        'sprowt_check_install',
        'install_configure_form',
        'sprowt_configure',
        'sprowt_setup_form',
        'sprowt_reset_localtarget_aliases'
    );


    if(!empty($install_state['forms']['file'])){
        $task_map = array(
            'install_select_profile',
            'install_select_locale',
            'install_load_profile',
            'install_verify_requirements',
            'sprowt_drush_presetup',
            'install_settings_form', //set up database
            'install_system_module',
            'install_bootstrap_full',
            'sprowt_setup_tables', //sprowt
            'sprowt_drush_setup', //sprowt
            'sprowt_module_preinstall', //sprowt
            'install_profile_modules',
            'install_import_locales',
            'sprowt_module_postinstall', //sprowt
            'install_configure_form',
            'sprowt_setup',
            'sprowt_configure',
            'sprowt_setup_form',
            'sprowt_reset_localtarget_aliases'
        );
    }

    $new_tasks = array();

    $setup_tasks = array(
        'sprowt_is_starter',
        'sprowt_starter_choose_page',
        'sprowt_company_info',
        'sprowt_market_setup',
        'sprowt_branding',
        'sprowt_users',
        'sprowt_locations',
        'sprowt_social',
        'sprowt_review',
        'sprowt_integrations'
    );

    foreach($task_map as $task){
        $new_tasks[$task] = $tasks[$task];
        unset($tasks[$task]);

        if($task == 'sprowt_starter_choose_page' && empty($install_state['storage']['is_starter'])) {
            $new_tasks[$task]['run'] = INSTALL_TASK_SKIP;
        }

        if(in_array($task, $setup_tasks) && !empty($install_state['storage']['from_file'])) {
            $new_tasks[$task]['run'] = INSTALL_TASK_SKIP;
        }

        if(module_exists('sprowt') && $task == 'sprowt_check_install') {
            $new_tasks[$task]['run'] = INSTALL_TASK_SKIP;
        }
    }

    $new_tasks = $new_tasks + $tasks;

    $tasks = $new_tasks;

    //$tasks['install_finished']['function'] = '_sprowt_install_finished';

}

function sprowt_reset_localtarget_aliases() {
    $nids = db_query("SELECT nid from node WHERE type = 'localtarget'")->fetchCol();

    $sources = array();
    $operations = array();
    foreach($nids as $nid) {
        $sources[] = "node/$nid";
        $operations[] = array(
            '_sprowt_update_localtarget_alias', array(
                $nid
            )
        );
    }

    if(!empty($sources)) {
        db_delete('url_alias')->condition('source', $sources, 'IN')->execute();
    }

    $batch = array(
        'operations' => $operations,
        'title' => 'Updating LocalTarget URL Aliases',
        'error_message' => 'The installation has encountered an error.',
        'finished' => 'drupal_flush_all_caches'
    );

    return $batch;

}

function _sprowt_update_localtarget_alias($nid, &$context) {
    $node = node_load($nid);
    $node->path['pathauto'] = 1;
    node_save($node);

    $context['results'][] = $nid;
    $context['message'] = st('Updated %count localtargets.', array(
        '%count' => count($context['results']),
    ));
}


function _sprowt_install_finished(&$install_state) {
    $sb = new SprowtBuilder();
    $sb->resetLocalTargetPaths();
    return install_finished($install_state);
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

        //drupal_static_reset();
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

function _sprowt_curl($uri, $payload = array()) {
    $ch = curl_init();
    $accessKey = '93f258dace70208b4b5d38de7266570dc48a7572';
    $secretKey = 'a0ZkBetAFbDwW89HXF260jF2Iut6iMpph95v';

    $base = 'https://forge.ly';
    if(strpos($_SERVER['HTTP_HOST'], '.test') !== false && !empty($_GET['debug'])) {
        $base = 'http://dev.forge.ly:8080';
    }

    $base .= '/api/v1';

    if(strpos($uri, '/') !== 0) {
        $uri = "/$uri";
    }

    curl_setopt($ch, CURLOPT_URL, $base . $uri);
    curl_setopt($ch, CURLOPT_RETURNTRANSFER, true);
    curl_setopt($ch, CURLOPT_FOLLOWLOCATION, true);
    curl_setopt($ch, CURLOPT_MAXREDIRS, 5);
    curl_setopt($ch, CURLOPT_CONNECTTIMEOUT, 30);
    curl_setopt($ch, CURLOPT_TIMEOUT, 30);
    curl_setopt($ch, CURLOPT_USERPWD, $accessKey . ':' . $secretKey);

    curl_setopt($ch, CURLOPT_COOKIE, 'XDEBUG_SESSION=forgelyapitest');

    if (count($payload)) {
        curl_setopt($ch, CURLOPT_POSTFIELDS, http_build_query($payload, '', '&'));
    }

    $output = curl_exec($ch);

    $httpInfo = curl_getinfo($ch);
    $httpcode = curl_getinfo($ch, CURLINFO_HTTP_CODE);

    curl_close($ch);

    return array(
        'info' => $httpInfo,
        'code' => $httpcode,
        'result' => $output
    );
}

function _sprowt_get_users_from_forgely() {
    $res =  _sprowt_curl('/users/sprowt');
    $response = json_decode($res['result'], true);

    if($res['code'] != 200) {
        if(empty($response)) {
            $response = $res['result'];
        }
        watchdog('error', 'Sprowt Curl Error: <pre>%response</pre>', [
            '%response' => json_encode($response, JSON_PRETTY_PRINT)
        ]);
        return [];
    }

    return $response['data'];
}

function _sprowt_get_coalmarch_user($username){
    $users = _sprowt_get_users_from_forgely();
    foreach($users as $user) {
        if($user['username'] == $username) {
            return $user;
        }
    }

    return false;
}

/**
 * Function for getting the user names of the default users
 */
function _sprowt_get_default_usernames(){
    $users = _sprowt_get_users_from_forgely();
    $names = [];
    foreach($users as $user) {
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
    require_once drupal_get_path('profile', 'pantheon') . '/pantheon.profile';
    return pantheon_configure();
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
        $excludes = (!empty($info['excludes'])) ? $info['excludes'] : array();
        foreach($overrides as $orig => $new) {
            $key = array_search($orig, $features);
            $features[$key] = $new;
        }

        foreach($excludes as $module) {
            $key = array_search($module, $features);
            unset($features[$key]);
        }
    }

    return $features;
}

/**
 * Some pre-install stuff
 */
function sprowt_module_preinstall(&$install_state) {
    //set this so features don't break everything
    db_query("ALTER TABLE `system` CHANGE `info` `info` LONGBLOB NULL DEFAULT NULL")->execute();


    //set this to false so that the batch module install doesn't break
    //we'll rebuild the features at the end when we revert them all
    variable_set('features_rebuild_on_module_install', false);

    //merge features and modules that are being installed
    $features = _sprowt_get_features();
    $modules = variable_get('install_profile_modules', array());

    $modules = array_merge($modules, $features);

    variable_set('install_profile_modules', $modules);
    variable_set('install_profile', 'sprowt');
    $install_state['parameters']['profile'] = 'sprowt';
}

/**
 * Function for installing features and other modules
 */

function sprowt_module_postinstall(){

    variable_set('features_rebuild_on_module_install', true);

    //hopefully this fixes the weird issues we get on a fresh Pantheon rollout
//    variable_set('install_profile', 'sprowt');
//    system_list_reset();
//    drupal_flush_all_caches();
}

function sprowt_drush_presetup(&$install_state) {
    if(!empty($install_state['forms']['file'])){
        $file = $install_state['forms']['file'];
        $json = file_get_contents($file);
        $data = json_decode($json, true);

        if(json_last_error() !== JSON_ERROR_NONE) {
            throw new SprowtException("[$file] File is not a JSON file.");
        }

        if(!isset($data['company_info'])) {
            throw new SprowtException("Invalid File.");
        }

        $company_name = $data['company_info']['company_name'];
        if(empty($company_name)) {
            throw new SprowtException("Company Name Required.");
        }

        $database = preg_replace('/[a-z0-9_]/', '_', strtolower($company_name));
        $database = trim($database, '_');
        $install_state['forms']['install_settings_form']['mysql']['database'] = $database;

        $install_state['forms']['install_configure_form']['site_name'] = $data['company_info']['company_name'];
        $install_state['forms']['install_configure_form']['site_mail'] = $data['company_info']['webform_from_email'];

        $install_state['forms']['install_configure_form']['account']['name'] = 'coalmarch';
        $install_state['forms']['install_configure_form']['account']['mail'] = 'devel@coalmarch.com';
        $install_state['forms']['install_configure_form']['account']['pass']['pass1'] = 'c04lm4rch';
        $install_state['forms']['install_configure_form']['account']['pass']['pass2'] = 'c04lm4rch';
        $install_state['forms']['install_configure_form']['update_status_module'] = array();
    }
    else {
        throw new SprowtException("A file is required.");
    }
}

function sprowt_drush_setup(&$install_state) {
    if(!empty($install_state['forms']['file'])){
        $file = $install_state['forms']['file'];
        $json = file_get_contents($file);
        $data = json_decode($json, true);

        if(json_last_error() !== JSON_ERROR_NONE) {
            throw new SprowtException("[$file] File is not a JSON file.");
        }

        if(!isset($data['company_info'])) {
            throw new SprowtException("Invalid File.");
        }
        $sb = new SprowtBuilder();
        $sb->saveData($data);
    }
    else {
        throw new SprowtException("A file is required.");
    }
}

function sprowt_setup(&$install_state){

    $sb = new SprowtBuilder();
    $data = $sb->getData();
    $id = md5(serialize($data));

    if(!empty($install_state['forms']['file'])){
        $actions = array(
            'getData' => "Getting Sprowt Data...",
            'addUsers' => "Adding Users...",
            'addNodes' => "Adding Default Nodes...",
            'addCompanyInfo' => "Adding Company Info...",
            'addReview' => "Adding Review Sites...",
            'addMarketsServices' => "Adding Markets and Services...",
            'addLocations' => "Adding Locations...",
            'addBranding' => "Adding Branding...",
            'addSocial' => "Adding Social Media...",
            'addIntegrations' => "Adding Integrations...",
            'revertFeatures' => "Revert Features...",
            'addNodeDefaultImages' => "Updating Default Images..."
        );

        if(!empty($data['starter']['is_starter'])) {
            $actions['setUpSprowtStarter'] = 'Setting Up Sprowt Starter Specific Settings...';
        }

        foreach($actions as $method => $message) {
            $sb->$method();
        }
        return true;
    }
    else {
        return false;
    }

    variable_set('site_name', $data['company_info']['company_name']);
    variable_set('site_mail', 'devel@coalmarch.com');
}

function _sprowt_get_data(){
    $sb = new SprowtBuilder();
    return $sb->getData();
}

function _sprowt_form_default($field_name, $default = '') {
    if(!empty($_GET['example_values'])) {
        if($_GET['example_values'] == 1) {
            switch ($field_name) {
                case 'customer_login':
                    return 'http://google.com?q=customer_login';
                    break;
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
                    $me = _sprowt_get_coalmarch_user('wmcmillian');
                    $me['roles'] = [
                        'administrator'
                    ];
                    $users = array (
                        $me
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
                case 'social_media_accounts':
                    return [
                        [
                            'type' => 'facebook',
                            'machineName' => 'facebook',
                            'iconClass' => 'facebook',
                            'link' =>  'http://facebook.com',
                            'description' => ''
                        ],
                        [
                            'type' => 'twitter',
                            'machineName' => 'twitter',
                            'iconClass' => 'twitter',
                            'link' =>  'twitterhandle',
                            'description' => ''
                        ],
                        [
                            'type' => 'instagram',
                            'machineName' => 'instagram',
                            'iconClass' => 'instagram',
                            'link' =>  'instahandle',
                            'description' => ''
                        ],
                        [
                            'type' => 'gplus',
                            'machineName' => 'gplus',
                            'iconClass' => 'google-plus',
                            'link' =>  'http://gplusurl.com',
                            'description' => ''
                        ],
                        [
                            'type' => 'linkedin',
                            'machineName' => 'linkedin',
                            'iconClass' => 'linkedin',
                            'link' =>  'http://linkedin.com',
                            'description' => ''
                        ],
                        [
                            'type' => 'pinterest',
                            'machineName' => 'pinterest',
                            'iconClass' => 'pinterest-p',
                            'link' =>  'http://pinterest.com/examplecompany',
                            'description' => ''
                        ]
                    ];
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

function sprowt_add_cm_user($username, $password = '') {
    require_once drupal_get_path('profile', 'sprowt') . '/includes/userbuilder.php';

    $UB = new UserBuilder();

    if($account = $UB->addCoalmarchUser($username, $password)) {
        if(empty($password)) {
            _user_mail_notify('register_admin_created', $account);
        }
    }
    else {
        throw new SprowtException('Coalmarch user, '.$username.',  could not be created');
    }
}


/**
 * Rebuilds a field base in a feature
 */
function sprowt_field_base_features_rebuild_per_field($module, $field_name) {
    module_load_include('inc', 'features', 'features.export');
    if ($fields = features_get_default('field_base', $module)) {
        field_info_cache_clear();

        // Load all the existing field bases up-front so that we don't
        // have to rebuild the cache all the time.
        $existing_fields = field_info_fields();

        foreach ($fields as $field) {
            if ($field['field_name'] == $field_name) {
                // Create or update field.
                if (isset($existing_fields[$field['field_name']])) {
                    $existing_field = $existing_fields[$field['field_name']];
                    $array_diff_result = features_array_diff_assoc_recursive($field + $existing_field, $existing_field);
                    if (!empty($array_diff_result)) {
                        try {
                            field_update_field($field);
                        } catch (FieldException $e) {
                            watchdog('features', 'Attempt to update field %label failed: %message', array('%label' => $field['field_name'], '%message' => $e->getMessage()), WATCHDOG_ERROR);
                        }
                    }
                }
                else {
                    try {
                        field_create_field($field);
                    } catch (FieldException $e) {
                        watchdog('features', 'Attempt to create field %label failed: %message', array('%label' => $field['field_name'], '%message' => $e->getMessage()), WATCHDOG_ERROR);
                    }
                    $existing_fields[$field['field_name']] = $field;
                }
                variable_set('menu_rebuild_needed', TRUE);
                break;
            }
        }
    }
}

function _sprowt_features_field_base_map() {
    $features_dir = drupal_get_path('profile', 'sprowt') . '/modules/features';
    $map = [];
    module_load_include('inc', 'features', 'features.export');
    foreach(scandir($features_dir) as $feature) {
        if ($fields = features_get_default('field_base', $feature)) {
            foreach($fields as $field) {
                $map[$field['field_name']] = $feature;
            }
        }
    }

    return $map;
}

function _sprowt_revert_solutions_finder() {
    $feature = 'sprowt_solution_finder';
    module_load_include('inc', 'features', 'features.export');
    $fieldMap = _sprowt_features_field_base_map();
    if ($instances = features_get_default('field_instance', $feature)) {
        foreach($instances as $instance) {
            $module = $fieldMap[$instance['field_name']];
            sprowt_field_base_features_rebuild_per_field($module, $instance['field_name']);
        }
    }

    features_revert_module($feature);
}
