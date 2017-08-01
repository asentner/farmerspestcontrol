<?php

require_once drupal_get_path('module', 'system') . '/system.admin.inc';

function _review_boost_admin_menu_block_page() {
    $item = menu_get_item();
    if ($content = system_admin_menu_block($item)) {
        $output = theme('admin_block_content', array('content' => $content));
    }
    else {
        $output = t('You do not have any administrative items.');
    }
    return $output;
}

function _review_boost_admin_import_csv() {
    return theme('review_boost_admin_import_csv', array(
        'form' => drupal_get_form('_review_boost_admin_import_csv_form'),
    ));
}

function _review_boost_admin_import_csv_form($form, $form_state) {
    variable_del('_review_boost_temp_data');
    $form['csv_file'] = array(
        '#type' => 'file',
        '#title' => 'CSV File',
        '#description' => 'Select a CSV (comma-separated values) document to upload. If you\'d like an example csv click <a href="/admin/survey/sample" target="_blank">here</a>.',
    );
    
    $form['actions'] = array(
        '#type' => 'actions',
        'submit' => array(
            '#type' => 'submit',
            '#value' => 'Upload service calls',
            '#submit' => array('_review_boost_admin_import_csv_form_submit_redirect')
        )
    );

    return $form;
}

function _review_boost_admin_import_csv_form_validate($form, &$form_state) {
    $file = file_save_upload('csv_file', array(
        'file_validate_extensions' => array('csv'),
    ));

    if (isset($file->filename)) {
        $form_state['storage']['csv_file'] = $file;
    }
    else {
        form_set_error('There was a problem uploading the file, please try again!');
        return;
    }

    if (($fp = fopen($form_state['storage']['csv_file']->destination, 'r')) !== false) {

        $i = 0;
        $expected_columns = array(
            'customer_id',
            'customer_first_name',
            'customer_last_name',
            'customer_email',
            'technician',
            'sales',
            'branch',
            'service',
            'service_date',
        );
        $columns = array();
        $skipped_columns = array();
        $data = array();

        while(($line = fgetcsv($fp)) !== false) {
            foreach($line as $key => $column) {
                if ($i != 0) {
                    if (empty($columns[$key])) {
                        continue;
                    }

                    if ($columns[$key] == 'service_date') {
                        try {
                            $date = new DateTime($column, new DateTimeZone(drupal_get_user_timezone()));
                        } catch (Exception $e) {
                            form_set_error('csv_file', sprintf('Your CSV contains a bad date on line %d!', $i));
                            break 2;
                        }

                        $date->setTime(12, 0, 0);
                        $data[$i][$columns[$key]] = $date;
                    }
                    else {
                        $data[$i][$columns[$key]] = $column;
                    }
                }
                else {
                    if (in_array($column, $expected_columns)) {
                        unset($expected_columns[array_search($column, $expected_columns)]);
                        $columns[$key] = $column;
                    }
                    else {
                        $skipped_columns[] = $column;
                    }
                }
            }

            if (count($data)) {
                $data[$i]['token'] = _review_boost_generate_token();
            }

            $i++;
        }
        fclose($fp);

        // Validate the columns
        if (count($expected_columns)) {
            form_set_error('csv_file', sprintf('You are missing the following columns: %s', implode(', ', $expected_columns)));
        }

        if (count($skipped_columns)) {
            drupal_set_message(sprintf('Skipped the following column(s): %s', implode(', ', $skipped_columns)), 'warning');
        }

        $form_state['storage']['data'] = $data;
    }
}

function _review_boost_admin_import_csv_form_submit_redirect($form, &$form_state) {
    if (count($form_state['storage']['data'])) {
        variable_set('_review_boost_temp_data', $form_state['storage']['data']);
    }
    else {
        variable_del('_review_boost_temp_data');
    }
    
    $form_state['redirect'] = array('admin/survey/import-csv/confirm');
}

function _review_boost_admin_import_csv_confirm() {
    $data = variable_get('_review_boost_temp_data');
    $test_data = array_slice($data, 0, 15);
    
    
    return theme('review_boost_admin_import_csv_confirm', array(
        'data' => $data,
        'test_data' => $test_data,
        'form' => drupal_get_form('_review_boost_admin_import_csv_form_confirm_form'),
    ));
}

function _review_boost_admin_import_csv_form_confirm_form($form, &$form_state) {
    $data = variable_get('_review_boost_temp_data');
    $form_state['storage']['data'] = $data;
    $form['actions'] = array(
        '#type' => 'actions',
        'submit' => array(
            '#type' => 'submit',
            '#value' => 'Import',
            '#submit' => array('_review_boost_admin_import_csv_form_submit')
        ),
        'cancel' => array(
            '#type' => 'submit',
            '#value' => 'Cancel',
            '#submit' => array('_review_boost_admin_import_csv_form_cancel')
        ),
    );
    return $form;
}

function _review_boost_admin_import_csv_form_cancel($form, &$form_state) {
    variable_del('_review_boost_temp_data');
    drupal_set_message('CSV Import Cancelled');
    $form_state['redirect'] = array('admin/survey/import-csv');
}

function _review_boost_admin_import_csv_form_submit($form, &$form_state) {
    $queued = 0;
    if (count($form_state['storage']['data'])) {
      $queue = DrupalQueue::get('review_boost_email_worker');
        foreach($form_state['storage']['data'] as $data) {
            $row = array(
                'token' => $data['token'],
                'customer_id' => $data['customer_id'],
                'first_name' => $data['customer_first_name'],
                'last_name' => $data['customer_last_name'],
                'email' => $data['customer_email'],
                'tech' => $data['technician'],
                'sales' => $data['sales'],
                'branch' => $data['branch'],
                'service' => $data['service'],
                'service_date' => $data['service_date'] instanceof DateTime ? $data['service_date']->getTimestamp() : time(),
                'creation_date' => time(),
                'email_sent' => 0,
            );
            if(_review_boost_admin_import_csv_validate_data($row)) {
                $hash = _review_boost_hash_data_row($row);
                $row['hash'] = $hash;
                db_insert('review_boost_token')
                    ->fields($row)
                    ->execute();
    
                _review_boost_get_hashes($hash);
                $queue->createItem(array('data' => $data));
                $queued++;
            }
        }
    }
    variable_del('_review_boost_temp_data');
    drupal_set_message(t('CSV Import Completed! %d emails queued!', array(
        '%d' => $queued
    )));
    $form_state['redirect'] = array('admin/survey/import-csv');
}

function _review_boost_admin_import_csv_validate_data($data) {
    if(empty($data['email'])) {
        drupal_set_message('Email empty for customer with customer_id of ' . $data['customer_id'], 'error');
        return false;
    }
    
    
    $hashes = _review_boost_get_hashes();
    $hash = _review_boost_hash_data_row($data);

    if(in_array($hash, $hashes)) {
        drupal_set_message('Review boost email already sent to/queued for customer with customer_id of ' . $data['customer_id'] . '!', 'error');
        return false;
    }

    return true;
}

function _review_boost_hash_data_row($data) {
    $row = array(
        'email' => _review_boost_clean_for_hash($data['email']),
        'tech' => _review_boost_clean_for_hash($data['tech']),
        'sales' => _review_boost_clean_for_hash($data['sales']),
        'branch' => _review_boost_clean_for_hash($data['branch']),
        'service' => _review_boost_clean_for_hash($data['service']),
        'service_date' => _review_boost_clean_for_hash($data['service_date'])
    );
    
    $json = json_encode($row);
    return md5($json);
}

function _review_boost_clean_for_hash($item) {
    $return = strtolower(trim($item));
    if(empty($return)) {
        $return = 'NULL';
    }
    return $return;
}

function _review_boost_get_hashes($add = '', $reset = false) {
    $hashes = &drupal_static(__FUNCTION__);
    if($reset) {
        $hashes = &drupal_static(__FUNCTION__, null, true);
    }
    
    if(!isset($hashes)) {
        $hashes = db_query("
            SELECT hash
            FROM review_boost_token
        ")->fetchCol();
    }
    
    if(!empty($add)) {
        $hashes[] = $add;
    }
    
    return $hashes;
}

/**
 * Grabbed this from here: https://gist.github.com/johanmeiring/2894568
 */
if(!function_exists('str_putcsv'))
{
    function str_putcsv($input, $delimiter = ',', $enclosure = '"') {
        $fp = fopen('php://temp', 'r+b');
        fputcsv($fp, $input, $delimiter, $enclosure);
        rewind($fp);
        $data = rtrim(stream_get_contents($fp), "\n");
        fclose($fp);
        return $data;
    }
}

function _review_boost_admin_sample_csv(){
    drupal_page_is_cacheable(false);
    $lines = array();

    $lines[] = array(
        'customer_id',
        'customer_first_name',
        'customer_last_name',
        'customer_email',
        'technician',
        'sales',
        'branch',
        'service',
        'service_date',
    );

    $lines[] = array(
        'CUSTOMER_ID',
        'First',
        'Last',
        'email@example.com',
        'TECHNICIAN NAME/ID',
        'SALES PERSON NAME/ID',
        'BRANCH NAME/ID',
        'SERVICE NAME/ID',
        date('m/d/Y'),
    );

    header('Content-type: text/csv');
    header('Content-disposition: attachment;filename=sample.csv');

    $csv = array();
    foreach($lines as $fields){
        $csv[] = str_putcsv($fields);
    }

    echo implode("\n", $csv);
}

function _review_boost_admin(){
    return theme('review_boost_admin', array(
        'form' => drupal_get_form('_review_boost_admin_form'),
    ));
}

function _review_boost_admin_form($form, &$form_state){
    drupal_add_css(drupal_get_path('module', 'review_boost') . '/css/admin.css');
    $RB = new ReviewBoost();

    $customer_email = array();

    $customer_email['review_boost_customer_from_email'] = array(
        '#type' => 'textfield',
        '#title' => t('From Email'),
        '#description' => 'The email address this customer email will be marked as coming from',
        '#default_value' => variable_get('review_boost_customer_from_email', $RB->getEmail())
    );

    $customer_email['review_boost_customer_subject'] = array(
        '#type' => 'textfield',
        '#title' => t('Email Subject'),
        '#description' => 'The subject of the email sent to the customer. It can also use the same tokens as the body.',
        '#default_value' => variable_get('review_boost_customer_subject', 'How did we do?')
    );

    $customer_email['review_boost_reset_customer_body'] = array(
        '#type' => 'checkbox',
        '#title' => 'Reset Body?',
        '#description' => 'This will reset the body to the default value. Use this if you want to change from the text version to the HTML version or if you want to delete the current customized body. <strong>This will delete the current body value!</strong>'
    );

    $customer_email['review_boost_customer_body'] = array(
        '#type' => $RB->allowHtml() ? 'text_format' : 'textarea',
        '#title' => t('Email Body'),
        '#description' => 'The body of the email sent to the customer.',
        '#default_value' => $RB->customerEmailBody(array(), false),
    );

    if($RB->allowHtml()) {
        $customer_email['review_boost_customer_body']['#format'] = $RB->customerEmailFormat();
    }

    $customer_email['tokens'] = array(
        '#type' => 'fieldset',
        '#title' => 'Available Tokens',
        '#description' => 'Can be used in Subject and Body',
        '#collapsible' => true,
        '#collapsed' => true,
        'token_markup' => array(
            '#type' => 'markup',
            '#markup' => _review_boost_generate_token_help()
        )
    );

    $admin_email = array();

    $admin_email['review_boost_admin_email'] = array(
        '#type' => 'textfield',
        '#title' => t('Admin Email(s)'),
        '#description' => 'A comma separated list of emails to send a notification to once a survey is filled out',
        '#default_value' => variable_get('review_boost_admin_email', $RB->getEmail())
    );

    $admin_email['review_boost_admin_subject'] = array(
        '#type' => 'textfield',
        '#title' => t('Admin Email Subject'),
        '#description' => 'The subject of the notification email. This can also use the same tokens as below',
        '#default_value' => variable_get('review_boost_admin_subject', 'A new ReviewBoost survey has been filled out')
    );

    $desc = 'The body of the email sent to the above email(s).';

    $admin_email['review_boost_reset_admin_body'] = array(
        '#type' => 'checkbox',
        '#title' => 'Reset Body?',
        '#description' => 'This will reset the body to the default value. Use this if you want to change from the text version to the HTML version or if you want to delete the current customized body. <strong>This will delete the current body value!</strong>'
    );

    $admin_email['review_boost_admin_body'] = array(
        '#type' => $RB->allowHtml() ? 'text_format' : 'textarea',
        '#title' => t('Email Body'),
        '#description' => $desc,
        '#default_value' => $RB->adminEmailBody(array(), false)
    );
    if($RB->allowHtml()) {
        $admin_email['review_boost_admin_body']['#format'] = $RB->adminEmailFormat();
    }

    $extra_tokens = array(
        '%rating' => 'Rating value provided by the survey',
        '%comments' => 'Comments provided in survey',
    );

    $admin_tokens = array_merge($extra_tokens, array(
        '%survey_link' => 'Results of the survey',
        '%from_email' => 'Email address the email will be sent from'
    ));

    $admin_email['tokens'] = array(
        '#type' => 'fieldset',
        '#title' => 'Available Tokens',
        '#description' => 'Can be used in Subject and Body',
        '#collapsible' => true,
        '#collapsed' => true,
        'token_markup' => array(
            '#type' => 'markup',
            '#markup' => _review_boost_generate_token_help($admin_tokens)
        )
    );

    $ty_high = array();

    $ty_high['review_boost_thank_you_high_title'] = array(
        '#type' => 'textfield',
        '#title' => t('Title'),
        '#default_value' => variable_get('review_boost_thank_you_high_title', 'We’re so glad you enjoyed your service!')
    );

    $content_val = variable_get('review_boost_thank_you_high_content');

    if(empty($content_val)) {
        $content_val = array(
            'format' => 'full_html',
            'value' => _review_boost_questionnaire_complete_default(true)
        );
    }

    $ty_high['review_boost_thank_you_high_content'] = array(
        '#type' => 'text_format',
        '#title' => t('Content'),
        '#format' => $content_val['format'],
        '#default_value' => $content_val['value']
    );

    $ty_high['tokens'] = array(
        '#type' => 'fieldset',
        '#title' => 'Available Tokens',
        '#description' => 'Can be used in Title and Content',
        '#collapsible' => true,
        '#collapsed' => true,
        'token_markup' => array(
            '#type' => 'markup',
            '#markup' => _review_boost_generate_token_help($extra_tokens)
        )
    );

    $ty_low = array();

    $ty_low['review_boost_thank_you_low_title'] = array(
        '#type' => 'textfield',
        '#title' => t('Title'),
        '#default_value' => variable_get('review_boost_thank_you_low_title', 'Thank you for your response!')
    );

    $content_val = variable_get('review_boost_thank_you_low_content');

    if(empty($content_val)) {
        $content_val = array(
            'format' => 'full_html',
            'value' => _review_boost_questionnaire_complete_default(false)
        );
    }

    $ty_low['review_boost_thank_you_low_content'] = array(
        '#type' => 'text_format',
        '#title' => t('Content'),
        '#format' => $content_val['format'],
        '#default_value' => $content_val['value']
    );

    $ty_low['tokens'] = array(
        '#type' => 'fieldset',
        '#title' => 'Available Tokens',
        '#description' => 'Can be used in Title and Content',
        '#collapsible' => true,
        '#collapsed' => true,
        'token_markup' => array(
            '#type' => 'markup',
            '#markup' => _review_boost_generate_token_help($extra_tokens)
        )
    );

    $form['review_boost_settings_email'] = array(
        '#type' => 'textfield',
        '#description' => 'This is the email used in the token, "%admin_email" and also the email the "Email to Admin(s)" is marked as coming from.',
        '#title' => 'Review Boost Admin Email',
        '#default_value' => $RB->getEmail()
    );

    $thresh_opts = array(
        1 => 1,
        2 => 2,
        3 => 3,
        4 => 4,
        5 => 5
    );
    $form['review_boost_threshold'] = array(
        '#type' => 'radios',
        '#title' => 'Threshold',
        '#description' => 'This number or greater will result in the "high rating" thank you page.',
        '#options' => $thresh_opts,
        '#default_value' => $RB->getThreshold()
    );

    $form['customer_email'] = array(
        '#type' => 'fieldset',
        '#title' => 'Email to Customer',
        $customer_email
    );

    $form['admin_email'] = array(
        '#type' => 'fieldset',
        '#title' => 'Email to Admin(s)',
        $admin_email
    );

    $form['ty_high'] = array(
        '#type' => 'fieldset',
        '#title' => 'Thank You Page (high rating)',
        $ty_high
    );

    $form['ty_low'] = array(
        '#type' => 'fieldset',
        '#title' => 'Thank You Page (low rating)',
        $ty_low
    );

    $form['#validate'][] = '_review_boost_admin_form_validate';
    $form['#submit'][] = '_review_boost_admin_form_submit';

    return system_settings_form($form);
}

function _review_boost_generate_token_help($addtl = array()){
    $RB = new ReviewBoost();
    $RB->addTokenDescriptions($addtl);
    return $RB->getTokenHelp();
}

function _review_boost_admin_form_validate(&$form, &$form_state){
    $form_state['values']['review_boost_customer_from_email'] = trim($form_state['values']['review_boost_customer_from_email']);

    $values = $form_state['values'];

    if(!valid_email_address($values['review_boost_customer_from_email'])) {
        form_set_error('review_boost_customer_from_email', 'Please provide a valid email address');
    }

    $emails = explode(',', $values['review_boost_admin_email']);

    if(!array($emails)) {
        $emails = array($emails);
    }
    $new_emails = array();
    foreach($emails as $email) {
        $email = trim($email);
        if(!valid_email_address($email)){
            form_set_error('review_boost_admin_email', 'Please provide a valid email address');
        }
        $new_emails[] = $email;
    }

    $form_state['values']['review_boost_admin_email'] = implode(', ', $new_emails);
}

function _review_boost_admin_form_submit(&$from, &$form_state) {
    $values = &$form_state['values'];

    if($values['review_boost_reset_customer_body']) {
        variable_del('review_boost_customer_body');
        unset($values['review_boost_customer_body']);
    }

    if($values['review_boost_reset_admin_body']) {
        variable_del('review_boost_admin_body');
        unset($values['review_boost_admin_body']);
    }
}

function _review_boost_admin_survey_results(){
    drupal_add_library('system', 'ui.datepicker');
    drupal_add_js('var jqO = jQuery;', array(
        'type' => 'inline',
        'scope' => 'footer'
    ));
    drupal_add_js('https://code.jquery.com/jquery-1.11.2.min.js', array(
        'type' => 'external',
        'scope' => 'footer'
    ));
    drupal_add_js('var jq11 = jQuery;jQuery = jqO;', array(
        'type' => 'inline',
        'scope' => 'footer'
    ));
    drupal_add_js(drupal_get_path('module', 'review_boost') . '/js/results.js', array(
        'type' => 'file',
        'scope' => 'footer'
    ));
    drupal_add_css(drupal_get_path('module', 'review_boost') . '/css/results.css');



    $header = array(
        array(
          'data' => 'Survey Date',
          'field' => 'r.creation_date',
          'sort' => 'ASC'
        ),
        array(
            'data' => 'Survey Rating',
            'field' => 'r.service_rating',
            'sort' => 'ASC'
        ),
        array(
            'data' => 'Customer Last Name',
            'field' => 't.last_name',
            'sort' => 'ASC'
        ),
        array(
            'data' => 'Customer First Name',
            'field' => 't.first_name',
            'sort' => 'ASC'
        )
    );



    $per_page = empty($_GET['per_page']) ? 10 : $_GET['per_page'];
    $count = db_select('review_boost_token', 't');

    $count->Join('review_boost_result', 'r', 't.tid = r.tid');
    $count->fields(null, array('*'));
    $select = db_select('review_boost_token', 't')
        ->extend('PagerDefault')
        ->extend('TableSort');

    $select->leftJoin('review_boost_result', 'r', 't.tid = r.tid');
    $select->fields('r', array('service_rating', 'creation_date'));
    $select->fields('t', array('token', 'first_name', 'last_name'));
    $select->isNotNull('r.tid');
    $select->orderByHeader($header);
    $select->limit($per_page);


    if(!empty($_GET['filters'])) {
        $select = _review_boost_apply_filters($select);
        $count = _review_boost_apply_filters($count);
    }

    $sql = (string) $select;

    $count = $count->countQuery()->execute()->fetchField();
    $results = $select->execute()->fetchAll(PDO::FETCH_ASSOC);

    $rows = array();
    $tz = new DateTimeZone(date_default_timezone(true));
    foreach($results as $r) {
        $survey_date = new DateTime('now', $tz);
        $survey_date->setTimestamp($r['creation_date']);
        $rows[] = array(
            "<a href=\"/admin/survey/{$r['token']}/result\">{$survey_date->format('m/d/Y')}</a>",
            $r['service_rating'],
            $r['last_name'],
            $r['first_name']
        );
    }

    $pager = '';
    if(count($results) && $count > $per_page) {
        $current_page = pager_default_initialize($count, $per_page);
        $pager = theme('pager');
    }

    $table = theme('table',array(
        'header' => $header,
        'rows' => $rows
    ));

    return theme('review_boost_survey_results', array(
        'pager' => $pager,
        'table' => $table,
        'totals' => _review_boost_get_totals()
    ));
}

function _review_boost_get_totals(){

    $sent = db_query("
        SELECT count(*)
        FROM review_boost_token t
        WHERE t.email_sent = 1
    ")->fetchField();

    $completed = db_query("
        SELECT count(*)
        FROM review_boost_result r 
        LEFT JOIN review_boost_token t on t.tid = r.tid
    ")->fetchField();

    $filtered = _review_boost_db_query("
        SELECT count(*)
        FROM review_boost_result r 
        LEFT JOIN review_boost_token t on t.tid = r.tid
    ")->fetchField();

    $scores = _review_boost_db_query("
        SELECT r.service_rating
        FROM review_boost_result r
        LEFT JOIN review_boost_token t on t.tid = r.tid
    ")->fetchCol();

    $total_score = 0;
    foreach($scores as $score) {
        $total_score += $score;
    }

    if(count($scores) == 0) {
        $average = 0;
    }
    else {
        $average = round($total_score / count($scores), 3);
    }

    return array(
        'sent' => $sent,
        'completed' => $completed,
        'average_score' => $average,
        'filtered' => $filtered
    );

}

function _review_boost_db_query($sql, $args = array(), $filters = null) {
    if(empty($filters)) {
        if(!empty($_GET['filters'])) {
            $filters = json_decode($_GET['filters'], true);
        }
    }

    if(!empty($filters)) {
        $filters = _review_boost_apply_filters($sql, $filters);
        $sql_after = '';
        if(!preg_match('/\swhere\s/i', $sql)) {
            $after_where = array('group by', 'having', 'order by', 'limit');
            foreach($after_where as $after) {
                if(preg_match('/\s'.$after.'\s/i', $sql)) {
                    $sql_array = preg_split('/\s'.$after.'\s/i', $sql);
                    $sql = array_shift($sql_array);
                    $sql_after = "\n$after\n" . implode(' ', $sql_array);
                    break;
                }
            }
            $sql .= "\nWHERE 1=1";

        }

        $sql = $sql . "\n" . implode("\n", $filters['sql']) . $sql_after;
        $args = array_merge($args, $filters['args']);
    }

    return db_query($sql, $args);
}

function _review_boost_apply_filters($query, $filters = null) {
    if(empty($filters)) {
        $filters = json_decode($_GET['filters'], true);
    }
    if(is_object($query)) {
        $sql = $query;
    }
    else {
        $sql = array(
            'sql' => array(),
            'args' => array()
        );
    }

    foreach($filters as $filter){
        switch($filter['key']) {
            case 'survey_completed':
                $field = 'r.creation_date';
                break;
            case 'survey_sent':
                $field = 't.creation_date';
                break;
            case 'technician':
                $field = 't.tech';
                break;
            case 'survey_score':
                $field = 'r.service_rating';
                break;
            default:
                $field = "t.{$filter['key']}";
        }

        switch($filter['type']) {
            case 'text':
                $value = '%' . db_like($filter['value']) . '%';
                $op = 'LIKE';
                break;
            case 'date':
                if(!is_array($filter['value']) && $filter['value'] == 'all') {
                    $filter['value'] = array(
                        'from' => '1/1/1970',
                        'to' => '1/1/3000'
                    );
                }

                $from = new DateTime($filter['value']['from']);
                $from->setTime(0,0,0);
                $to = new DateTime($filter['value']['to']);
                $to->setTime(23,59,59);

                $value = array($from->getTimestamp(), $to->getTimestamp());
                $op = 'BETWEEN';
                break;
            case 'score':
                $op_map = array(
                    'eq' => '=',
                    'gt' => '>',
                    'lt' => '<',
                    'gte' => '>=',
                    'lte' => '<='
                );
                $value = $filter['value']['value'];
                $op = $op_map[$filter['value']['op']];
        }

        if(is_array($sql)) {
            $id = ':' . trim(str_replace('-', '', $filter['id']));
            if($op == 'BETWEEN') {
                foreach($value as $k => $v) {
                    $idb = $id . '_' . $k;
                    if($k == 0) {
                        $op = '>=';
                    }
                    else {
                        $op = '<=';
                    }
                    $sql['sql'][] = "AND $field $op $idb";
                    $sql['args'][$idb] = $value[$k];
                }
            }
            else {
                $sql['sql'][] = "AND $field $op $id";
                $sql['args'][$id] = $value;
            }
        }
        else {
            $sql->condition($field, $value, $op);
        }
    }

    return $sql;
}

function _review_boost_admin_survey_result($token) {

    $sql = "SELECT r.creation_date as 'Survey Date',
        r.service_rating as 'Rating',
        r.service_comments as 'Comments',
        t.customer_id as 'Customer Id',
        t.first_name as 'Customer First Name',
        t.last_name as 'Customer Last Name',
        t.email as 'Customer Email',
        t.tech as 'Technician',
        t.sales as 'Sales',
        t.branch as 'Branch',
        t.service as 'Service',
        t.service_date as 'Service Date'
        FROM review_boost_token t
        LEFT JOIN review_boost_result r on t.tid = r.tid
        WHERE t.token = :token
        AND r.tid IS NOT NULL";

    $args = array(
        ':token' => $token,
    );

    $result = db_query($sql, $args)->fetchAssoc();

    $tz = new DateTimeZone(date_default_timezone(true));

    $survey_date = new DateTime('now', $tz);
    $service_date = new DateTime('now', $tz);

    $survey_date->setTimestamp($result['Survey Date']);
    $service_date->setTimestamp($result['Service Date']);

    $date_format = 'm/d/Y g:ia';

    $result['Survey Date'] = $survey_date->format($date_format);
    $result['Service Date'] = $service_date->format('m/d/Y');

    return theme('review_boost_survey_result', array(
        'fields' => $result,
        'token' => $token
    ));
}

function _review_boost_result_delete($form, &$form_state, $token) {
    $form_state['storage']['token'] = $token;
    $form['#submit'] = array('_review_boost_result_delete_submit');
    return confirm_form($form,
        'Are you sure you want to delete this result?',
        'admin/survey/results',
        t('This action cannot be undone.'),
        t('Delete'),
        t('Cancel')
    );
}

function _review_boost_result_delete_submit($form, &$form_state) {
    $token = $form_state['storage']['token'];
    $tid = db_query("
        SELECT tid
        FROM review_boost_token
        WHERE token = :token
    ", array(
        ':token' => $token
    ))->fetchField();

    db_delete('review_boost_token')->condition('tid', $tid)->execute();
    db_delete('review_boost_result')->condition('tid', $tid)->execute();
    drupal_set_message('Survey result deleted!');
    $form_state['redirect'] = array('admin/survey/results');
}

function _review_boost_admin_results_csv(){
    drupal_page_is_cacheable(false);
    $sql = "
        SELECT r.creation_date as 'Survey Date',
        r.service_rating as 'Rating',
        r.service_comments as 'Comments',
        t.customer_id as 'Customer Id',
        t.first_name as 'Customer First Name',
        t.last_name as 'Customer Last Name',
        t.email as 'Customer Email',
        t.tech as 'Technician',
        t.sales as 'Sales',
        t.branch as 'Branch',
        t.service as 'Service',
        t.service_date as 'Service Date'
        FROM review_boost_token t
        LEFT JOIN review_boost_result r on t.tid = r.tid
        WHERE r.tid IS NOT NULL
        ";

    $args = array();

    $results = _review_boost_db_query($sql, $args)->fetchAll(PDO::FETCH_ASSOC);;

    $csv = array();
    $csv[] = str_putcsv(array_keys($results[0]));

    $tz = new DateTimeZone(date_default_timezone(true));

    foreach($results as $k => $row) {
        $survey_date = new DateTime('now', $tz);
        $service_date = new DateTime('now', $tz);
        $survey_date->setTimestamp($row['Survey Date']);
        $service_date->setTimestamp($row['Service Date']);
        $date_format = 'm/d/Y g:ia';

        $row['Survey Date'] = $survey_date->format($date_format);
        $row['Service Date'] = $service_date->format('m/d/Y');
        $csv[] = str_putcsv(array_values($row));
    }

    $now = new DateTime();
    $filename = 'results_' . $now->format('Y-m-D_His') . '.csv';

    header('Content-type: text/csv');
    header('Content-disposition: attachment;filename='. $filename);

    echo implode("\n", $csv);
}

function _review_boost_admin_review() {
    global $conf;
    $conf['preprocess_js'] = false; //disable js aggregation for this page
    drupal_page_is_cacheable(false); //disable caching for this page
    drupal_add_js('//code.jquery.com/jquery-1.12.4.min.js');
    drupal_add_js('//cdnjs.cloudflare.com/ajax/libs/jsrender/0.9.80/jsrender.min.js');
    drupal_add_js(drupal_get_path('module', 'review_boost') . '/js/review_links.js');
    return theme('review_boost_review_settings', array(
        'form' => drupal_get_form('_review_boost_admin_review_form'),
    ));
}

function _review_boost_admin_review_form($form, &$form_state) {
    $form = array();

    $RB = new ReviewBoost();


    $form['review_links'] = array(
        '#type' => 'hidden',
        '#default_value' => $RB->getReviewLinks(true),
        '#attributes' => array(
            'id' => 'review-links'
        ),
    );

    $form['actions'] = array(
        'submit' => array(
            '#type' => 'submit',
            '#value' => 'Save',
        ),
        'addRow' => array(
            '#type' => 'button',
            '#value' => 'Add Custom Site',
            '#attributes' => array(
                'id' => 'addRow'
            )
        ),
    );

    $form['#validate'][] = '_review_boost_admin_review_form_validate';
    $form['#submit'][] = '_review_boost_admin_review_form_submit';

    return $form;
}

function _review_boost_admin_review_form_validate(&$form, &$form_state) {
    $values = &$form_state['values'];

    $links = json_decode($values['review_links'], true);

    $enabled = array();

    foreach ($links as $link) {
        if($link['enabled']) {
            $enabled[] = $link['id'];
        }
    }

    if(count($enabled) > 3) {
        form_set_error('review_links', 'No more than three links can be enabled');
        drupal_add_js(array('hidden_errors' => json_encode($enabled)), 'setting');
        $form_state['rebuild'] = true;
    }
}

function _review_boost_admin_review_form_submit(&$form, &$form_state) {
    $values = $form_state['values'];
    $links = json_decode($values['review_links'], true);

    variable_set('review_boost_review_links', $links);
    cache_clear_all();
}