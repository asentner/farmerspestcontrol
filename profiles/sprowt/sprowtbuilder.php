<?php

if(!defined('DRUPAL_ROOT')){
    define('DRUPAL_ROOT', str_replace("/profiles/sprowt", "", getcwd()));
    require_once DRUPAL_ROOT . '/includes/bootstrap.inc';
    drupal_bootstrap(DRUPAL_BOOTSTRAP_FULL);
}


require_once DRUPAL_ROOT . '/profiles/sprowt/includes/menubuilder.php';
require_once DRUPAL_ROOT . '/profiles/sprowt/includes/userbuilder.php';

Class SprowtBuilder {

    public $data = array();
    public $default_images = array();

    private $node_json;
    private $uuidMap = [];


    function __construct() {
        if(!defined('MAINTENANCE_MODE')){
            define('MAINTENANCE_MODE', "install");
        }
        chdir(DRUPAL_ROOT);

        //hardcoded paths for sprowt sites
        $paths = array(
            '934b332a-a247-41eb-ae2e-09dfe144aed3' => 'contact',
            '616bbe72-80a0-43ec-b5a3-838d2b60f1e5' => 'free-quote',
            'b8f3a9e5-f431-4428-b5b2-9ce69f6b437c' => 'refer-friend',
            'c1c20802-54d4-49c2-ad31-61784e121b9f' => 'our-pest-control-services',
        );

        $this->paths = $paths;
    }

    function decodeVal($string) {
        $decoded = json_decode($string, true);
        if(json_last_error() == JSON_ERROR_NONE) {
            return $decoded;
        }
        return $string;
    }



    /**
     * Gets all the data from the sprowt_setup table
     *
     */
    function getData(){
        if(!function_exists('db_table_exists') || !db_table_exists('sprowt_setup')) {
            return false;
        }
        $query = db_query(
            "SELECT * FROM sprowt_setup"
        );

        if(empty($query)){
            throw new Exception('Sprowt Setup Table empty!!!');
            die;
        }

        $result = $query->fetchAll( PDO::FETCH_ASSOC);
        foreach($result as $row){
            if(empty($this->data[$row['form_name']])){
                $this->data[$row['form_name']] = array();
            }


            $this->data[$row['form_name']][$row['form_field']] = $this->decodeVal($row['field_value']);
        }

        return $this->data;
    }

    function saveData($data) {
        db_truncate('sprowt_setup')->execute();
        $insert = db_insert('sprowt_setup')
            ->fields(
                array(
                    'form_name',
                    'form_field',
                    'field_value',
                ));

        foreach($data as $form_name => $fields) {
            foreach($fields as $field_name => $field_value) {

                if(is_object($field_value) || is_array($field_value)) {
                    $field_value = json_encode($field_value);
                }

                $insert->values(array(
                    'form_name' => $form_name,
                    'form_field' => $field_name,
                    'field_value' => $field_value
                ));
            }
        }

        return $insert->execute();
    }

    function is_starter() {
        if(empty($this->data)){
            $this->getData();
        }

        return isset($this->data['starter']['is_starter']) ? $this->data['starter']['is_starter'] : null;
    }

    static function isStarter() {

    }

    /**
     *Adds integrations to site
     */
    function addIntegrations(){
        if(empty($this->data)){
            $this->getData();
        }

        if(!empty($this->data['integrations']['google_analytics'])){
            module_enable(array('googleanalytics'));
            variable_set('googleanalytics_account', $this->data['integrations']['google_analytics']);
        }

        if(!empty($this->data['integrations']['gtm'])){
            module_enable(array('google_tag'));
            variable_set('google_tag_container_id', $this->data['integrations']['gtm']);
        }

        if(!empty($this->data['integrations']['optimizely_id'])){
            variable_set('optimizely_id', $this->data['integrations']['optimizely_id']);
        }

        if(!empty($this->data['integrations']['ac_newsletter_api_url'])){
            variable_set('ac_newsletter_api_url',$this->data['integrations']['ac_newsletter_api_url']);
        }

        if(!empty($this->data['integrations']['ac_newsletter_api_key'])){
            variable_set('ac_newsletter_api_key', $this->data['integrations']['ac_newsletter_api_key']);
        }
    }

    /**
     *Adds company info to site
     */
    function addSocial(){
        require_once drupal_get_path('module', 'sprowt_settings') . '/sprowt_settings.module';
        if(empty($this->data)){
            $this->getData();
        }

        if(!empty($this->data['social_media']['facebook'])){
            variable_set('sprowt_settings_facebook_url', $this->data['social_media']['facebook']);
        }

        if(!empty($this->data['social_media']['twitter'])){
            variable_set('sprowt_settings_twitter_handle', $this->data['social_media']['twitter']);
        }

        if(!empty($this->data['social_media']['linkedin'])){
            variable_set('sprowt_settings_linkedin_url', $this->data['social_media']['linkedin']);
        }

        if(!empty($this->data['social_media']['yelp'])){
            variable_set('sprowt_settings_yelp_url', $this->data['social_media']['yelp']);
        }

        if(!empty($this->data['social_media']['bbb'])){
            variable_set('sprowt_settings_bbb_url', $this->data['social_media']['bbb']);
        }

        if(!empty($this->data['social_media']['gplus'])){
            variable_set('sprowt_settings_gplus_url', $this->data['social_media']['gplus']);
        }

        if(!empty($this->data['social_media']['accounts'])) {
            _sprowt_settings_set_social_media_accounts($this->data['social_media']['accounts']);
        }
    }

    /**
     * Adds social media urls to site
     */
    function addCompanyInfo(){
        if(empty($this->data)){
            $this->getData();
        }

        variable_set('sprowt_settings_company_name', $this->data['company_info']['company_name']);
        variable_set('sprowt_settings_phone_number', $this->cleanPhone($this->data['company_info']['company_phone']));
        if(!empty($this->data['company_info']['contact_phone'])){
            variable_set('sprowt_settings_contact_phone', $this->cleanPhone($this->data['company_info']['contact_phone']));
        }

        if(!empty($this->data['company_info']['contact_name'])){
            variable_set('sprowt_settings_contact_name', $this->data['company_info']['contact_name']);
        }

        if(!empty($this->data['company_info']['contact_email'])){
            variable_set('sprowt_settings_contact_email', $this->data['company_info']['contact_email']);
        }

        if(!empty($this->data['company_info']['company_type'])){
            variable_set('sprowt_settings_company_type', $this->data['company_info']['company_type']);
        }

        if(!empty($this->data['company_info']['customer_login'])) {
            variable_set('sprowt_customer_login', $this->data['company_info']['customer_login']);
        }

        variable_set('sprowt_settings_webform_to_email', $this->data['company_info']['webform_to_email']);

        if(function_exists('_sprowt_login_create_sprowt_company_alias')) {
            _sprowt_login_create_sprowt_company_alias();
        }
    }

    function cleanPhone($phone) {
        $phone = preg_replace('/[^\d]/',"", $phone);
        return $phone;
    }


    function addReview() {
        if(empty($this->data)){
            $this->getData();
        }
        if(!empty($this->data['review'])) {
            $review = $this->data['review'];
            foreach ($review as $param => $value) {
                if (!empty($value)) {
                    variable_set($param, $value);
                }
            }
        }
    }

    /**
     * Pulls in nodes form sprowt and adds them, hopefully
     *
     */
    function addNodes(){
        variable_set('sprowt_settings_paths', $this->paths);

        $sprowt_path = drupal_get_path('profile', 'sprowt');
        $theme_path = drupal_get_path('theme', $this->data['branding']['theme']);

        //deprecated in favor of fetching from a URL

//        $json_filename = "sprowt_export.json";
//        if(file_exists($theme_path . "/$json_filename")) {
//            $json_file = $theme_path . "/$json_filename";
//        }
//        else {
//            $json_file = $sprowt_path . "/$json_filename";
//        }
//
//
//        //run this command to generate a json file of all pages: drush ne-export --format=json --file=profiles/sprowt/sprowt_export.json --type=affiliation,benefit,blog,cta,page,profile,slide,special_offer,webform
//        $node_json = file_get_contents($json_file);
//        $this->node_json = $node_json;

        $sync = new SprowtNodeSync();
        $node_json = $sync->fetch([], true);
        $this->node_json = $node_json;

        $nodes = json_decode($node_json,true);
        $uuids = array();

        $this->addDefaultImages();
        $default_images = $this->default_images;
        $image_dest = 'public://default_node_images';

        $fields = [
            'field_image'
        ];

        foreach($fields as $field) {
            foreach($nodes as $key => $node){
                $uuids[$node['nid']] = $node['uuid'];
                if(!empty($node[$field]['und'][0]['fid'])){
                    switch($node['type']) {
                        case 'slide':
                            $file = $default_images['slideshow-placeholder.png'];
                            break;
                        case 'benefit':
                        case 'affiliation':
                        case 'special_offer':
                            $file = $default_images['icon-placeholder.png'];
                            break;
                        case 'profile':
                            $file = $default_images['profile-placeholder.png'];
                            break;
                        default:
                            $file = $default_images['service-placeholder.png'];
                            break;
                    }

                    $field_info = field_info_instance('node', $field, $node['type']);
                    if(!empty($field_info)) {
                        $file = file_copy($file, $image_dest);
                        foreach($field_info['display'] as $display){
                            if(!empty($display['settings']['image_style'])){
                                $image_style = $display['settings']['image_style'];
                                if(!empty($image_style)){
                                    image_style_create_derivative(image_style_load($image_style), $file->uri, image_style_path($image_style, $file->uri));
                                }
                            }
                        }
                        if(!empty($file)) {
                            $node[$field]['und'][0]= array('fid' => $file->fid, 'focal_point' => $node['field_image']['und'][0]['focal_point']);
                        }
                        $nodes[$key] = $node;
                    }
                }
            }
        }

        require_once DRUPAL_ROOT . '/profiles/sprowt/modules/contrib/node_export/formats/json.inc';

        //$result = $this->node_export_import($node_json);

        $this->buildUuidMap($nodes);

        $result = $this->node_import($nodes);

        $nid_array = entity_get_id_by_uuid('node', $uuids);

        $fourofour = $nid_array['e6e64b98-71d8-4eb3-9c9c-dc1c573c13cb'];
        $fourothree = $nid_array['9512a22e-11e7-47f5-a63d-e8861401302a'];
        $home = $nid_array['3c0659bb-655d-415d-bb4e-822b9a4e4218'];

        variable_set('site_frontpage', "node/$home");
        variable_set('site_403', "node/$fourothree");
        variable_set('site_404', "node/$fourofour");
        variable_set('weight_frontpage', 0);

        $menu = db_query("SELECT * FROM menu_links WHERE menu_name = :main", array(':main' => 'main-menu'))->fetchAll(PDO::FETCH_ASSOC);
        foreach($menu as $link){
            _menu_delete_item($link);
        }

        $this->update_display();

        $this->import_menus();

        //webform settings
        variable_set('webform_default_from_address', $this->data['company_info']['webform_from_email']);
        variable_set('webform_default_from_name', $this->data['company_info']['webform_from_name']);
        variable_set('webform_email_replyto', false);

        $privacy = entity_uuid_load('node', ['6da1b988-5564-47a2-8404-72ec6aaa46ed']);
        if(empty($privacy)) {
            $this->importPrivacyPolicy();
        }
    }

    function addDefaultImages() {
        $image_dest = 'public://default_node_images';
        file_prepare_directory($image_dest, FILE_CREATE_DIRECTORY);
        $default_image_paths = glob(drupal_get_path('profile', 'sprowt') . '/images/node_default/*');
        $default_images = array();
        foreach($default_image_paths as $image_path) {
            $handle = fopen($image_path, 'r');
            $filename = basename($image_path);
            $dest = 'public://default_node_images/' . $filename;
            $file = file_save_data($handle, $dest, FILE_EXISTS_REPLACE);
            $default_images[$filename] = $file;
        }

        $styles = image_styles();
        foreach($styles as $style_name => $style) {
            foreach($default_images as $filename => $file) {
                image_style_create_derivative($style, $file->uri, image_style_path($style_name, $file->uri));
            }
        }

        $this->default_images = $default_images;
    }

    function addNodeDefaultImages() {
        $default_images = array();
        foreach($this->default_images as $file) {
            $default_images[$file->filename] = $file;
            switch($file->filename) {
                case 'service-placeholder.png':
                    $instance = field_info_instance('node', 'field_image', 'service');
                    $instance['settings']['default_image'] = $file->fid;
                    field_update_instance($instance);
                    break;
                case 'icon-placeholder.png':
                    $instance = field_info_instance('node', 'field_image', 'benefit');
                    $instance['settings']['default_image'] = $file->fid;
                    field_update_instance($instance);
                    $instance = field_info_instance('node', 'field_icon', 'benefit');
                    $instance['settings']['default_image'] = $file->fid;
                    field_update_instance($instance);
                    $instance = field_info_instance('node', 'field_icon', 'service');
                    $instance['settings']['default_image'] = $file->fid;
                    field_update_instance($instance);
            }
        }

        $styles = image_styles();
        foreach($styles as $style_name => $style) {
            foreach($default_images as $filename => $file) {
                image_style_create_derivative($style, $file->uri, image_style_path($style_name, $file->uri));
            }
        }
    }

    function import_menus() {
        $sprowt_path = drupal_get_path('profile', 'sprowt');
        $theme_path = drupal_get_path('theme', $this->data['branding']['theme']);

        $files = array(
            'main-menu' => "main-menu_link_export.json",
            'menu-mobile-menu' => "menu-mobile-menu_link_export.json",
            'menu-mobile-callout' => "menu-mobile-callout_link_export.json",
            'menu-utility-menu' => "menu-utility-menu_link_export.json",
            'menu-mobile-footer' => "menu-mobile-footer_link_export.json",
            'menu-mobile-utility' => "menu-mobile-utility_link_export.json",
            'menu-ctm-utility-menu' => "menu-ctm-utility-menu_link_export.json"
        );

        $MB = new MenuBuilder();

        foreach($files as $menu => $filename) {
            if(file_exists("$theme_path/$filename")) {
                $MB->importFromFile("$theme_path/$filename");
            }
            else if(file_exists("$sprowt_path/$filename")) {
                $MB->importFromFile("$sprowt_path/$filename");
            }
        }
    }

    function update_display(){
        $objs = node_type_get_types();
        foreach($objs as $obj) {
            variable_set('node_submitted_' . $obj->type, '0');
        }
    }

    function importPrivacyPolicy(){
        $fName = 'profiles/sprowt/privacypolicy.txt';

        $handle = fopen($fName,'r');
        $data = fread($handle,filesize($fName));

        node_export_import($data);
    }

    function modifyDefaultNode($node) {
        //$n = entity_metadata_wrapper('node', $node);
        $front_page_benfit_uuids = array(
            '1172b3dc-5937-4280-b5b5-74772dda3b49',
            'fef4a25f-9485-44dd-b264-ba89a48b29b8',
            '54c876bd-629b-4abc-81bf-f4fb9c8bd239'
        );

        if(in_array($node->uuid, $front_page_benfit_uuids)) {
            $node->promote = 1;
            switch($node->uuid) {
                case '1172b3dc-5937-4280-b5b5-74772dda3b49':
                    $node->weight_weight = 1;
                    break;
                case 'fef4a25f-9485-44dd-b264-ba89a48b29b8':
                    $node->weight_weight = 2;
                    break;
                case '54c876bd-629b-4abc-81bf-f4fb9c8bd239':
                    $node->weight_weight = 3;
                    break;
            }
        }

        $ltp_benefit_uuids = array(
            'd7851455-0d59-4127-b0bd-28c8247f34cd',
            '9ef2c5d3-9b00-4ec3-9523-0a66c443fa23',
            '6732c347-4157-4171-879f-0ed849c4ef9e'
        );

        if(in_array($node->uuid, $ltp_benefit_uuids)) {
            $node->promote = 0;
            switch($node->uuid) {
                case 'd7851455-0d59-4127-b0bd-28c8247f34cd':
                    $node->weight_weight = 1;
                    break;
                case '9ef2c5d3-9b00-4ec3-9523-0a66c443fa23':
                    $node->weight_weight = 2;
                    break;
                case '6732c347-4157-4171-879f-0ed849c4ef9e':
                    $node->weight_weight = 3;
                    break;
            }
        }

        return $node;
    }

    function modify_nodes($nodes = []) {

        $noIndexUnpublish = [
            '9689e757-b8b7-424c-92e2-cbe6973e2b8c',
            '9d9e355f-2748-4146-906b-5d352ded78b7',
            '98a36e38-d9b0-4d82-b8cb-8a2ac0c7c8f4',
            'aaed225c-73ed-4920-aa47-b14e096491fd',
            'dde62ef5-78c2-4ab9-9800-30f4704f3664',
            '3bfa987c-ead4-4b83-9b02-dd0922d9db22',
            '4dbc6ac9-3409-4bd6-808a-a7cdc51af733',
            '4907444d-86fa-46cf-812e-767397d37563',
            'e645ab25-f709-4bf2-86ec-4f63ab8c5d09',
            'dc37f1bb-706c-410c-8b15-bb34555ff74c'
        ];

        foreach($nodes as $nodeArray) {
            $type = $nodeArray['type'];
            $uuid = $nodeArray['uuid'];


            if($type == 'issue' || $type == 'concern' || in_array($uuid, $noIndexUnpublish)) {
                $node = entity_uuid_load('node', [$uuid]);
                $node = array_pop($node);
                $node->status = 0;
                $node->metatags[LANGUAGE_NONE]['robots']['value']['noindex'] = 'noindex';
                entity_uuid_save('node', $node);
            }

            if($type == 'webform') {
                $node = entity_uuid_load('node', [$uuid]);
                $node = array_pop($node);

                $node->webform['progress_bar'] = 0;
                entity_uuid_save('node', $node);
            }

        }
    }

    function buildUuidMap($nodes) {
        $map = [];
        foreach($nodes as $nodeArray) {
            $map[$nodeArray['nid']] = $nodeArray['uuid'];
        }

        $this->uuidMap = $map;
    }

    function node_import($nodes = array(), $later = false) {
        require_once('includes/nodebuilder.php');

        $paths = $this->paths;


        $saveForLater = [];
        $modify = [];

        $sync = new SprowtNodeSync();

        foreach($nodes as $node){
            $type = $node['type'];

            if($type == 'issue' && !$later) {
                $saveForLater[] = $node;
                continue;
            }
            else {
                $modify[] = $node;
                $nodeString = $node;
                unset($nodeString['menu']);

                $output = $sync->import(json_encode([$nodeString]), 'revision');
            }

            $nid_array = entity_get_id_by_uuid('node', array($node['uuid']));

            if(!empty($nid_array[$node['uuid']])){
                $n = node_load($nid_array[$node['uuid']]);
                $loaded = true;
            }
            else {
                $n = new stdClass();
                $n->type = $type;
                $n->uuid = $node['uuid'];
                $n->language = LANGUAGE_NONE;
                $loaded = false;

                $instances = field_info_instances('node', $type);

                foreach($instances as $instance => $i_info) {
                    if(!empty($node[$instance])) {
                        $n->$instance = $node[$instance];
                    }
                }

                node_export_file_field_import($n, clone $n);
            }

            $n->status = $node['status'];
            $n->title = $node['title'];
            $n->promote = $node['promote'];
            //$n->menu = $node['menu'];
            $n = $this->modifyDefaultNode($n);

            if($n->type == 'webform') {

                foreach($node['webform']['emails'] as $k => $email) {
                    $email['email'] = '[sprowt:sprowt_webform_to_email]';
                    $email['from_name'] = 'default';
                    $email['from_address'] = 'default';
                    $node['webform']['emails'][$k] = $email;
                }

                $node['webform']['progress_bar'] = 0;


                $n->webform = $node['webform'];
            }

            if(in_array($node['uuid'], array_keys($paths))) {
                $n->path = array(
                    'alias' => $paths[$node['uuid']],
                    'pathauto' => false
                );
            }

            if(!$loaded){
                node_object_prepare($n);
                $n = node_submit($n);
            }

            $this->addReferencestoEntity($n, 'node', $type);

            node_save($n);
        }

        $this->modify_nodes($modify);

        if(!empty($saveForLater) && !$later) {
            $this->node_import($saveForLater, true);
        }
    }

    function addReferencestoEntity(&$entity, $entity_type, $bundle) {
        $instances = field_info_instances($entity_type, $bundle);
        foreach($instances as $bundle_field_name => $instance) {
            $info = field_info_field($bundle_field_name);

            switch($info['type']) {
                case 'entityreference':
                    if(!empty($entity->{$bundle_field_name})) {
                        foreach($entity->{$bundle_field_name} as $lang => &$items) {
                            foreach($items as $item_delta => &$item) {
                                if(!empty($item['uuid'])) {
                                    $uuid = $item['uuid'];
                                }
                                else if(!empty($item['target_id']) && !empty($this->uuidMap[$item['target_id']])) {
                                    $uuid = $this->uuidMap[$item['target_id']];
                                }

                                if(!empty($uuid)) {
                                    $target_id = entity_get_id_by_uuid($info['settings']['target_type'], array($uuid));
                                }
                                else {
                                    $target_id = null;
                                }

                                if(!empty($target_id)) {
                                    foreach($target_id as $id) {
                                        if(!empty($id)) {
                                            $target_id = $id;
                                            break;
                                        }
                                    }
                                    if(!empty($target_id)) {
                                        $item = array(
                                            'target_id' => $target_id
                                        );
                                    }
                                    else {
                                        unset($items[$item_delta]);
                                    }
                                }
                                else {
                                    unset($items[$item_delta]);
                                }
                            }
                        }
                        if(empty($items)) {
                            unset($entity->{$bundle_field_name}[$lang]);
                        }
                    }
                    break;
            }
        }
    }

    /**
     * Adds users from the sprowt_setup table
     *
     */
    function addUsers(){
        require_once DRUPAL_ROOT . '/includes/password.inc';
        global $base_url;
        if(empty($this->data)){
            $this->getData();
        }

        $query = db_query(
            "SELECT * FROM role"
        );

        $roles = array();

        foreach($query->fetchAll( PDO::FETCH_ASSOC) as $row){
            $roles[$row['name']] = $row['rid'];
        }

        $query = db_query(
            "SELECT * FROM users"
        );

        $current_users = array();

        foreach($query->fetchAll( PDO::FETCH_ASSOC) as $row){
            $current_users[$row['name']] = $row['uid'];
        }

        $picture_style = variable_get('user_picture_style', 0);
        $directory = file_default_scheme() . '://' . variable_get('user_picture_path', 'pictures');
        file_prepare_directory($directory, FILE_CREATE_DIRECTORY);


        $default_users = $this->getDefaultUsers();
        if(!in_array('coalmarch', array_keys($this->data['users']))
            && !empty($default_users['coalmarch'])
        ) {
            //there should always be a coalmarch user (user 1)
            $this->data['users']['coalmarch'] = $default_users['coalmarch'];
        }

        foreach($this->data['users'] as $username => $userinfo){
            if($username == 'coalmarch' && !empty($default_users[$username])) {
                //always use what's in the codebase for user 1
                $userinfo = $default_users[$username];
            }

            UserBuilder::addUser($userinfo);
        }
    }

    function getDefaultUsers() {
        $fields = array();

        $default_users = [
            'coalmarch' => ['Coal', 'March']
        ];

        foreach($default_users as $username => $name_array){
            if($username == 'coalmarch'){
                $filepath = getcwd() . "/profiles/sprowt/default_users/_$username.json";
            }
            else {
                $filepath = getcwd() . "/profiles/sprowt/default_users/$username.json";
            }
            $fields[$username] = json_decode(file_get_contents($filepath), true);
        }
        return $fields;
    }

    function updateUsers() {
        if(empty($this->data)){
            $this->getData();
        }

        require_once DRUPAL_ROOT . '/includes/password.inc';
        $fields = array();

        $default_users = [
            'coalmarch' => ['Coal', 'March']
        ];

        foreach($default_users as $username => $name_array){
            if($username == 'coalmarch'){
                $filepath = getcwd() . "/profiles/sprowt/default_users/_$username.json";
            }
            else {
                $filepath = getcwd() . "/profiles/sprowt/default_users/$username.json";
            }
            $fields[$username] = json_decode(file_get_contents($filepath), true);
        }
        $this->data['users'] = $fields;
        $this->addUsers();
    }

    /**
     * Sets up branding
     */

    function addBranding(){
        if(empty($this->data)){
            $this->getData();
        }

        require_once('includes/themebuilder.php');

        $ThemeBuilder = new ThemeBuilder();

        $branding = $this->data['branding'];

        $ThemeBuilder->enable($branding['theme']);

        //make double sure blocks import correctly
        db_delete('block')->condition('theme', $branding['theme'])->execute();
        $ThemeBuilder->import_blocks($branding['theme'], $branding['theme']);


        theme_enable(array('adminimal'));
    }

    /**
     * Adding market, region, service taxonomy
     */
    function addMarketsServices(){
        if(empty($this->data)){
            $this->getData();
        }

        require_once('includes/taxonomybuilder.php');

        $services = new TaxonomyBuilder('services');
        $markets = new TaxonomyBuilder('markets');
        $regions = new TaxonomyBuilder('regions');

        foreach($this->data['market_setup']['services'] as $key=>$service){
            $service = $services->add_term($service);
            if($key == 0){
                $t_service = $service;
            }
        }

        foreach($this->data['market_setup']['regions'] as $region => $region_markets){
            $market_terms = array();
            foreach($region_markets as $key=>$market){
                $market = $market_terms[] = $markets->add_term($market);
                if($key == 0){
                    $t_market = $market;
                }
            }

            $region_term = array(
                'name' => $region,
                'field_markets' => array(
                    LANGUAGE_NONE => array()
                ),
            );

            foreach($market_terms as $market_term){
                $region_term['field_markets'][LANGUAGE_NONE][] = array('tid' => $market_term->tid);
            }

            $region_term = $regions->add_term($region_term);
        }

        $this->publishMarketsandServices();

        //add one testimonial

        require_once('includes/nodebuilder.php');
        $node = new NodeBuilder('testimonial');

        $node-> title = "Testimonial Person";
        $body = "Lorem ipsum dolor sit amet, consectetur adipiscing elit. Vestibulum nec nisi libero. Nunc efficitur hendrerit gravida.";

        if(!empty($t_service->tid)){
            $node->field_service->set($t_service->tid);
        }

        if(!empty($t_market->tid)){
            $node->field_market = array($t_market->tid);
        }

        if(!empty($t_service->name) && !empty($t_market->name)){
            $body = "{$t_service->name} in {$t_market->name} is Great!\n$body";
        }

        $node->body->value->set($body);
        $node->save();
    }

    /**
     * Publishes service, regions, and markets
     *
     * @return void
     */
    function publishMarketsandServices(){
        $mnses = db_query("SELECT nid,type FROM node WHERE type IN (:service, :region, :market) ORDER BY type", array(
            ':service' => 'service',
            ':region' => 'region',
            ':market' => 'market',
        ))->fetchAll(PDO::FETCH_ASSOC);

        $regions = array();
        $services = array();
        $markets = array();

        foreach($mnses as $mns){
            $node = node_load($mns['nid']);
            $node->status = 1;

            switch($mns['type']){
                case 'service':
                    $services[] = $node;
                    break;
                case 'region':
                    $regions[] = $node;
                    break;
                case 'market':
                    $markets[] = $node;
                    break;
            }
        }

        foreach ($regions as $region){
            node_save($region);
            if(count($regions) > 1 && empty($region_added)){
                $entities = array_values(entity_uuid_load('node', array('2b054fc1-1268-405d-9d93-9829b7c4a20c')));
                $service_areas = _sprowt_taxonomy_engine_add_menu_info($entities[0]);
                $region->menu = array(
                    'link_title' => $region->title,
                    'menu_name' => 'main-menu',
                    'plid' => $service_areas->menu['mlid'],
                    'enabled' => 1,
                    'description' => $region->title,
                );
                menu_node_save($region);
                $region_added = true;
            }
        }

        foreach ($markets as $market){
            node_save($market);
        }

        foreach ($services as $service){
            node_save($service);
        }
    }

    /**
     * Adding locations
     */
    function addLocations(){
        if(empty($this->data)){
            $this->getData();
        }

        require_once('includes/nodebuilder.php');

        foreach($this->data['locations'] as $location){
            $nb = new NodeBuilder('location');

            $nb->title = $location['name'];
            $nb->field_phone_number = $location['phone'];
            $nb->field_street_address = $location['address'];
            $nb->field_locality = $location['city'];
            $nb->field_state = $location['state'];
            $nb->field_postal_code = $location['zip'];

            if(!empty($location['email'])){
                $nb->field_email = $location['email'];
            }

            if(!empty($location['gplus'])){
                $nb->field_google_url = $location['glpus'];
            }

            $nb->save();
        }

    }

    /**
     * Revert all features
     */

    function revertFeatures() {
        variable_set('sprowt_initial_revert', true);
        $features = _sprowt_get_features();

        foreach($features as $feature) {
            features_revert_module($feature);
        }

        $this->afterRevert();
    }

    function afterRevert(){
        if(empty($this->data)){
            $this->getData();
        }
        $branding = $this->data['branding'];
        $node_json = $this->node_json;
        $orig_nodes = json_decode($node_json,true);
        $uuid_array = array();
        foreach($orig_nodes as $node) {
            $uuid_array[$node['nid']] = $node['uuid'];
        }
        $nid_array = entity_get_id_by_uuid('node', $uuid_array);

        //special offers update
        $redeem_nid = $nid_array['7ac2f749-f7d3-4db7-8b05-258588aba660'];
        $link = array(
            'url' => "node/$redeem_nid"
        );

        $instance = field_info_instance('node', 'field_button', 'special_offer');
        $instance['default_value'] = array($link);
        field_update_instance($instance);

        $nids = db_query("SELECT nid FROM node WHERE type='special_offer'")->fetchCol();
        foreach(node_load_multiple($nids) as $node) {
            $NB = new NodeBuilder($node);
            $NB->field_button = $link;
            $NB->save();
        }

        //handle webforms
        $nids = db_query("SELECT nid FROM node WHERE type='webform'")->fetchCol();
        foreach(node_load_multiple($nids) as $node) {
            if(in_array($node->uuid, array_keys($this->paths))) {
                $node->path = array(
                    'alias' => $this->paths[$node->uuid],
                    'pathauto' => false
                );
            }
            else {
                $node->path = array(
                    'pathauto' => true
                );
            }

            node_save($node);
        }

        //update contexts
        $themeBuilder = new ThemeBuilder();
        $blockFile = $themeBuilder->getBlockFile($branding['theme'], $branding['theme']);
        if(!empty($blockFile)) {
            $blockBuilder = new BlockBuilder();
            $blockBuilder->setFromFile($blockFile);
            $blockBuilder->handleContexts();
        }

        //update default images
        $this->addNodeDefaultImages();

        //reimport solutions
        _sprowt_solution_finder_sample_nodes();
        variable_del('sprowt_initial_revert');
    }

    function setUpSprowtStarter() {
        if(empty($this->data)){
            $this->getData();
        }
        $branding = $this->data['branding'];
        $starter = $this->data['starter'];
        module_enable(array('sprowt_landing_page'));
        _sprowt_landing_page_create_landing_pages();

        $excludedNids = entity_get_id_by_uuid('node', array('e6e64b98-71d8-4eb3-9c9c-dc1c573c13cb','9512a22e-11e7-47f5-a63d-e8861401302a'));
        $excludedNids = array_values($excludedNids);

        $landing_page_nids = db_query("
            SELECT nid
            FROM node
            WHERE type = 'landing_page'
        ")->fetchCol();
        $nodes = node_load_multiple($landing_page_nids);

        foreach($nodes as $node) {
            $nids = _sprowt_landing_page_find_all_nids_used($node);
            $excludedNids = array_merge($excludedNids, $nids);
        }

        $nids_to_be_disabled = db_query("
            SELECT nid
            FROM node
            WHERE status = 1
            AND nid NOT IN (:nids)
        ", array(
            ':nids' => $excludedNids
        ))->fetchCol();

        db_update('node')->fields(array('status' => 0))->condition('nid', $excludedNids, 'NOT IN')->execute();
        variable_set('sprowt_starter_nids_disabled', $nids_to_be_disabled);

        $homeUUID = $starter['landing_page_uuid'];

        $homeNid = entity_get_id_by_uuid('node', array($homeUUID));
        if(empty($homeNid)) {
            $home = array_shift($nodes);
            $homeNid = $home->nid;
        }
        else {
            $homeNid = array_pop($homeNid);
        }

        variable_set('site_frontpage', "node/$homeNid");

        sprowt_custom_colors_set_colors(
            !empty($branding['primary-color']) ? $branding['primary-color'] : null,
            !empty($branding['secondary-color']) ? $branding['secondary-color'] : null,
            !empty($branding['tertiary-color']) ? $branding['tertiary-color'] : null
        );
    }

    function resetLocalTargetPaths() {
        $nids = db_query("SELECT nid from node WHERE type = 'localtarget'")->fetchCol();
        $nodes = node_load_multiple($nids);

        $sources = array();
        foreach($nodes as $node) {
            $sources[] = "node/{$node->nid}";
        }

        db_delete('url_alias')->condition('source', $sources, 'IN')->execute();


        foreach($nodes as $node) {
            $node->path['pathauto'] = 1;
            node_save($node);
        }

    }
}
