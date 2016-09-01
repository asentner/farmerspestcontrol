<?php

if(!defined('DRUPAL_ROOT')){
    define('DRUPAL_ROOT', str_replace("/profiles/sprowt", "", getcwd()));
    require_once DRUPAL_ROOT . '/includes/bootstrap.inc';
    drupal_bootstrap(DRUPAL_BOOTSTRAP_FULL);
}


require_once DRUPAL_ROOT . '/profiles/sprowt/includes/menubuilder.php';

Class SproutBuilder {
    
    public $data = array();
    
    
    function __construct() {
        if(!defined('MAINTENANCE_MODE')){
            define('MAINTENANCE_MODE', "install");
        }
        chdir(DRUPAL_ROOT);
    }
    
    /**
     * Gets all the data from the sprowt_setup table
     *
     */
    function getData(){
        $query = db_query(
            "SELECT * FROM sprowt_setup"
        );
        
        if(empty($query)){
            throw new Exception('Sprout Setup Table empty!!!');
            die;
        }
        
        $result = $query->fetchAll( PDO::FETCH_ASSOC);
        foreach($result as $row){
            if(empty($this->data[$row['form_name']])){
                $this->data[$row['form_name']] = array();
            }
            
            if($row['form_name'] == 'market_setup'
                || $row['form_name'] == 'users'
                || $row['form_name'] == 'locations')
            {
                $row['field_value'] = json_decode($row['field_value'], true);
            }
            
            
            $this->data[$row['form_name']][$row['form_field']] = $row['field_value'];
        }
        
        return $this->data;
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
        
        $node_json = file_get_contents(DRUPAL_ROOT . "/profiles/sprowt/sprowt_export.json");
        
        
        $nodes = json_decode($node_json,true);
        $uuids = array();

        $default_image_paths = glob(drupal_get_path('profile', 'sprowt') . '/images/node_default/*');
        $default_images = array();
        foreach($default_image_paths as $image_path) {
            $handle = fopen($image_path, 'r');
            $filename = basename($image_path);
            $dest = 'public://' . $filename;
            $file = file_save_data($handle, $dest, FILE_EXISTS_REPLACE);
            $default_images[$filename] = $file;
            switch($filename) {
                case 'service-placeholder.png':
                    $instance = field_info_instance('node', 'field_image', 'service');
                    $instance['settings']['default_image'] = $file->fid;
                    field_update_instance($instance);
                    break;
                case 'icon-placeholder.png':
                    $instance = field_info_instance('node', 'field_image', 'benefit');
                    $instance['settings']['default_image'] = $file->fid;
                    field_update_instance($instance);
                    $instance = field_info_instance('node', 'field_icon', 'service');
                    $instance['settings']['default_image'] = $file->fid;
                    field_update_instance($instance);
            }
        }

        $image_dest = 'public://default_node_images';
        file_prepare_directory($image_dest, FILE_CREATE_DIRECTORY);
        
        foreach($nodes as $key => $node){
            $uuids[$node['nid']] = $node['uuid'];
            if(!empty($node['field_image']['und'][0]['fid'])){
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

                $file = file_copy($file, $image_dest);

                $field_info = field_info_instance('node', 'field_image', $node['type']);

                foreach($field_info['display'] as $display){
                    if(!empty($display['settings']['image_style'])){
                        $image_style = $display['settings']['image_style'];
                        if(!empty($image_style)){
                            image_style_create_derivative(image_style_load($image_style), $file->uri, image_style_path($image_style, $file->uri));
                        }
                    }
                }
                if(!empty($file)) {
                    $node['field_image']['und'][0]= array('fid' => $file->fid, 'focal_point' => $node['field_image']['und'][0]['focal_point']);
                }
                $nodes[$key] = $node;
            }
        }
        
        require_once DRUPAL_ROOT . '/profiles/sprowt/modules/contrib/node_export/formats/json.inc';
        
        //$result = $this->node_export_import($node_json);
        
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
            if(preg_match('/node\/([\d]+)/',$link['link_path'], $matches)){
                if(!empty($uuids[$matches[1]]) && !empty($nid_array[$uuids[$matches[1]]])){
                    db_update('menu_links')
                    ->fields(array(
                        'link_path' => "node/" . $nid_array[$uuids[$matches[1]]],
                    ))
                    ->condition('mlid',$link['mlid'],'=')
                    ->execute();
                }
                else {
                    _menu_delete_item($link);
                }
            }
        }
        
        $this->update_display();
        
        $this->update_main_menu($nid_array);

        $this->import_menus();

    }

    function import_menus() {
        $path = drupal_get_path('profile', 'sprowt');

        $files = array(
            'menu-mobile-menu' => "$path/menu-mobile-menu_link_export.json",
            'menu-mobile-callout' => "$path/menu-mobile-callout_link_export.json",
        );

        $MB = new MenuBuilder();

        foreach($files as $menu => $filepath) {
            $MB->importFromFile($filepath);
        }
    }
    
    function update_display(){
        $objs = node_type_get_types();
        foreach($objs as $obj) {
            variable_set('node_submitted_' . $obj->type, '0');
        }
    }
    
    function update_menu($menu_items, $menu){
        foreach($menu_items as $item) {
            $children = array();
            if(isset($item['children'])) {
                $children = $item['children'];
                unset($item['children']);
            }
            
            $item['menu_name'] = $menu;
            
            $mlid = menu_link_save($item);
            
            if(!empty($children)) {
                foreach($children as $i =>$child) {
                    $children[$i]['plid'] = $mlid;
                }
                $this->update_menu($children, $menu);
            }
            
        }
    }
    
    function update_main_menu($nids_array = array()){
        menu_delete_links('main-menu');

        $file = drupal_get_path('profile', 'sprowt') . '/main-menu_link_export.json';

        require_once drupal_get_path('profile', 'sprowt') . '/includes/menubuilder.php';

        $MB = new MenuBuilder();
        $MB->importFromFile($file);
    }
    
    function node_import($nodes = array()) {
        require_once('includes/nodebuilder.php');
        
        foreach($nodes as $node){
            $type = $node['type'];
            
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
            }
            
            $n->status = $node['status'];
            $n->title = $node['title'];
            $n->promote = $node['promote'];
            //$n->menu = $node['menu'];
            
            $instances = field_info_instances('node', $type);
            
            foreach($instances as $instance => $i_info) {
                if(!empty($node[$instance])) {
                    $n->$instance = $node[$instance];
                }
            }

            if($n->type == 'webform') {

                foreach($node['webform']['emails'] as $k => $email) {
                    $email['email'] = $this->data['company_info']['webform_to_email'];
                    $email['from_name'] = $this->data['company_info']['webform_from_name'];
                    $email['from_address'] = $this->data['company_info']['webform_from_email'];
                    $node['webform']['emails'][$k] = $email;
                }

                $n->webform = $node['webform'];
            }
            
            if(!$loaded){
                node_object_prepare($n);
                $n = node_submit($n);
            }
            
            node_save($n);
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
        
        foreach($this->data['users'] as $username => $userinfo){
            $user = (object) array(
                'name' => $username, 
                'mail' => $userinfo['email'], 
                'status' => 1, 
                'init' => $userinfo['email'],
            );
            
            $user->roles = array();
            
            foreach($userinfo['roles'] as $role){
                if(!empty($roles[$role])){
                    $user->roles[$roles[$role]] = $role;
                }
            }
            
            if(!empty($userinfo['first_name'])){
                $user->field_first_name[LANGUAGE_NONE][0]['value'] = $userinfo['first_name'];
            }
            
            if(!empty($userinfo['last_name'])){
                $user->field_last_name[LANGUAGE_NONE][0]['value'] = $userinfo['last_name'];
            }
            
            if(!empty($userinfo['position'])){
                $user->field_position[LANGUAGE_NONE][0]['value'] = $userinfo['position'];
            }
            
            if(!empty($userinfo['google_plus_id'])){
                $user->field_google_plus_id[LANGUAGE_NONE][0]['value'] = $userinfo['google_plus_id'];
            }
            
            if(!empty($userinfo['Description'])){
                $user->field_description[LANGUAGE_NONE][0]['value'] = $userinfo['Description'];
            }
            
            
            if(!empty($userinfo['encrypted'])){
                $user->pass = $userinfo['password'];
            }
            else {
                $user->pass = user_hash_password($userinfo['password']);
            }
            
            if($username == 'coalmarch'){
                $user->uid = 1;
            }
            else if(!empty($current_users[$username])){
                $user->uid = $current_users[$username];
            }
            
            user_save($user);
            
            if(!empty($userinfo['image'])
               && $userinfo['image'] != "/profiles/sprowt/images/default.jpg")
            {
                $dest = file_unmanaged_copy(DRUPAL_ROOT . $userinfo['image'], $directory, FILE_EXISTS_REPLACE);
                $file = new stdClass();
                $file->uri = $dest;
                $file->filename = drupal_basename($dest);
                $file->filemime = file_get_mimetype($dest);
                $file->status = FILE_STATUS_PERMANENT;
                
                $existing_files = file_load_multiple(array(), array('uri' => $dest));
                if (count($existing_files)) {
                  $existing = reset($existing_files);
                  $file->fid = $existing->fid;
                  $file->filename = $existing->filename;
                }
                
                $file = file_save($file);
                
                if($file !== false){
                    if($picture_style){
                        image_style_create_derivative(image_style_load($picture_style), $file->uri, image_style_path($picture_style, $file->uri));
                    }
                    $user->picture = $file;
                }
                user_save($user);
            }
        }
    }


    function updateUsers() {
        if(empty($this->data)){
            $this->getData();
        }

        require_once DRUPAL_ROOT . '/includes/password.inc';
        $fields = array();

        $default_users = _sprowt_get_default_usernames();

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
            $node->field_market->set($t_market->tid);
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
}