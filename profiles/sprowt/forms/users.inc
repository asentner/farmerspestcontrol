<?php
/**
 * User Info Form
 */

function sprowt_users($form, &$form_state, &$install_state){
    drupal_set_title(st('Configure Users'));

    //Adding scripts
    $form['#attached']['js'][] = "https://code.jquery.com/jquery-1.11.2.min.js"; //I don't wanna use drupal's old as dirt jQuery
    //drupal_add_js("https://code.jquery.com/ui/1.11.3/jquery-ui.min.js"); Don't need this as we aren't going to o drag and drop
    $form['#attached']['js'][] = drupal_get_path('profile', 'sprowt') . "/js/jsrender.min.js";

    $form['#attached']['js'][] = drupal_get_path('profile', 'sprowt') . "/js/users.js";//custom jQuery

    //Adding styles
    $form['#attached']['css'][] = drupal_get_path('profile', 'sprowt') . "/css/sprowt.css";

    $users = _sprowt_get_default_usernames();
    
    $coalmarch_users = _sprowt_get_users_from_forgely();
    
    $userInfo = [];
    foreach($coalmarch_users as $coalmarch_user) {
        $coalmarch_user['roles'] = ['administrator'];
        $userInfo[$coalmarch_user['username']] = $coalmarch_user;
    }
    
    $form['user_info'] = array(
        '#type' => 'hidden',
        '#attributes' => array(
            'id' => 'user-info'
        ),
        '#value' => json_encode($userInfo)
    );

    ob_start();
    include drupal_get_path('profile', 'sprowt') . '/includes/users.tpl.php';
    $users_form = ob_get_clean();


    $form['default_users'] = array(
        '#type' => 'fieldset',
        '#title' =>'Default Users',
        '#collapsible' => true,
        '#collapsed' => true,
        'users' => array(),
    );

    foreach($users as $username => $name_array){
        $form['default_users']['users'][$username] = array(
            '#type' => 'checkbox',
            '#title' => implode(" ",$name_array),
            '#attributes' => array(
                'checked' => 'checked'
            ),
        );
        if($username == 'coalmarch'){
            $form['default_users']['users'][$username]['#checked'] = true;
            $form['default_users']['users'][$username]['#disabled'] = true;
        }
    }

    $form['add_users'] = array(
        '#prefix' => $users_form,
    );

    $form['hidden_values'] = array(
        'additional_users' => array(
            '#type' => 'hidden',
            '#default_value' => _sprowt_form_default('additional_users', '[]'),
            '#attributes' => array(
                'id' => 'users_hidden',
            ),
        ),
    );


    $form['hidden_errors'] = array(
        '#type' => 'hidden',
        '#attributes' => array(
            'id' => 'hidden_errors'
        ),
    );

    if(!empty($form_state['hidden_errors'])){
        $form['hidden_errors']['#value'] = $form_state['hidden_errors'];
    }
    else {
        $form['hidden_errors']['#value'] = '';
    }

    $form['actions']['submit'] = array(
        '#type' => 'submit',
        '#value' => t('Save'),
    );

    return $form;
}


function sprowt_users_validate($form, &$form_state){
    $users = json_decode($form['hidden_values']['additional_users']['#value'], true);

    $hidden_errors = array();

    foreach($users as $user) {
        $userId = $user['id'];
        if(empty($user['username'])){
            $hidden_errors[] = "#$userId-username";
            if(empty($username_message)){
                $username_message = true;
                drupal_set_message('Username is required', 'error');
            }
        }

        if(empty($user['password'])){
            $hidden_errors[] = "#$userId-password";
            if(empty($password_message)){
                $password_message = true;
                drupal_set_message('Password is required', 'error');
            }
        }

        if(empty($user['roles'])){
            $hidden_errors[] = "#$userId .role-checks label";
            if(empty($roles_message)){
                $roles_message = true;
                drupal_set_message('At least one role is required', 'error');
            }
        }
    }


    if(!empty($hidden_errors)){
        $form_state['hidden_errors'] = json_encode($hidden_errors);
        $form_state['rebuild'] = true;
    }
}


function sprowt_users_submit($form, &$form_state){
    require_once DRUPAL_ROOT . '/includes/password.inc';
    $fields = array();
    $users = json_decode($form['hidden_values']['additional_users']['#value'], true);

    foreach($users as $user){
        unset($user['id']);
        $user['encrypted'] = true;
        $user['password'] = user_hash_password($user['password']);
        $fields[$user['username']] = json_encode($user);
    }

    _sprowt_save_to_table('users', $fields);

}