<?php

class UserBuilder {

    function addUser(array $userinfo){
        $username = $userinfo['username'];
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

        $user = (object) array(
            'name' => $userinfo['username'],
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

        $instances = field_info_instances('user', 'user');

        if(!empty($userinfo['first_name'])){
            if (!empty($instances['field_first_name'])) {
                $user->field_first_name[LANGUAGE_NONE][0]['value'] = $userinfo['first_name'];
            }
        }

        if(!empty($userinfo['last_name'])){
            if (!empty($instances['field_last_name'])) {
                $user->field_last_name[LANGUAGE_NONE][0]['value'] = $userinfo['last_name'];
            }
        }

        if(!empty($userinfo['position'])){
            if (!empty($instances['field_position'])) {
                $user->field_position[LANGUAGE_NONE][0]['value'] = $userinfo['position'];
            }
        }

        if(!empty($userinfo['google_plus_id'])){
            if (!empty($instances['field_google_plus_id'])) {
                $user->field_google_plus_id[LANGUAGE_NONE][0]['value'] = $userinfo['google_plus_id'];
            }
        }

        if(!empty($userinfo['Description'])){
            if (!empty($instances['field_description'])) {
                $user->field_description[LANGUAGE_NONE][0]['value'] = $userinfo['Description'];
            }
        }


        if(!empty($userinfo['encrypted'])){
            $user->pass = $userinfo['password'];
        }
        else {
            $user->pass = user_hash_password($userinfo['password']);
        }

        if($userinfo['username'] == 'coalmarch'){
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

        return $user;
    }

    function addCoalmarchUser($username) {
        $filepath = getcwd() . "/profiles/sprowt/coalmarch_users/$username.json";
        if(!file_exists($filepath)) {
            return false;
        }
        else {
            $json = file_get_contents($filepath);
            return $this->addUser(json_decode($json, true));
        }
    }

}