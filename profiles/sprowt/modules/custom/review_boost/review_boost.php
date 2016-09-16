<?php

class ReviewBoost {
    private $tokens = array();
    private $token_desciptions = array();
    private $address = array();
    private $formToken = '';
    private $data = array();
    private $company_name = null;
    private $company_phone = null;
    private $company_email = null;
    private $allow_html = null;

    function __construct($formToken = '') {
        $this->formToken = $formToken;
        $this->setDefaultTokens();
    }

    function setAddress($addtl_address = array()) {
        if(function_exists('_sprowt_settings_get_address')) {
            $address = _sprowt_settings_get_address();
            $address['street2'] = '';
        }
        else if(function_exists('_leadbuilder_settings_get_address')) {
            $address = _leadbuilder_settings_get_address();
            $address['street2'] = '';
        }
        else {
            $address = array(
                'street' => variable_get('coal_admin_address_street', ''),
                'street2' => variable_get('coal_admin_address_additional', ''),
                'locality' => variable_get('coal_admin_address_locality', ''),
                'province' => variable_get('coal_admin_address_province', ''),
                'postal_code' => variable_get('coal_admin_address_postal_code', ''),
            );
        }

        $this->address = array_merge($address, $addtl_address);
    }


    function setData($dateFormat = 'Y/m/d'){
        if(!empty($this->formToken)) {
            $formToken = $this->formToken;
            $data = db_query("
                SELECT *
                FROM review_boost_token
                WHERE token = :token
            ", array(
                ':token' => $formToken
            ))->fetchAssoc();

            if (empty($data)) {
                watchdog('review_boost', 'No data found for token: $token! No email sent!', array(
                    '%token' => $formToken
                ), 'error');
                return false;
            }

            $tz = new DateTimeZone(date_default_timezone(true));
            $service_date = new DateTime(date('c', $data['service_date']), $tz);
            $data['service_date_formatted'] = $service_date->format($dateFormat);
        }
        else {
            $data = array(
                'customer_id' => '',
                'first_name' => '',
                'last_name' => '',
                'email' => '',
                'tech' => '',
                'sales' => '',
                'branch' => '',
                'service' => '',
                'service_datae' => '',
                'service_date_formatted' => ''
            );
        }

        $this->data = $data;
    }

    function setDefaultTokens($formToken = ''){
        if(!empty($formToken)) {
            $this->formToken = $formToken;
        }
        global $base_url;
        $survey_link = $base_url . '/customer-survey/' . $this->formToken;

        if(empty($this->address)) {
            $this->setAddress();
        }

        if(empty($this->data)) {
            $this->setData();
        }

        $data = $this->data;

        $default_tokens = array(
            '%customer_id' => array(
                'value' => $data['customer_id'],
                'description' => 'Customer ID from the imported CSV'
            ),
            '%customer_first_name' => array(
                'value' => $data['first_name'],
                'description' => 'Customer first name from the imported CSV'
            ),
            '%customer_last_name' => array(
                'value' => $data['last_name'],
                'description' => 'Customer last name from the imported CSV'
            ),
            '%customer_email' => array(
                'value' => $data['email'],
                'description' => 'Customer email from the imported CSV'
            ),
            '%technician' => array(
                'value' => $data['tech'],
                'description' => 'Technician ID/name from the imported CSV'
            ),
            '%sales' => array(
                'value' => $data['sales'],
                'description' => 'Sales ID/name from the imported CSV'
            ),
            '%branch' => array(
                'value' => $data['branch'],
                'description' => 'Branch ID/name from the imported CSV'
            ),
            '%service_date' => array(
                'value' => $data['service_date_formatted'],
                'description' => 'Service Date from the imported CSV'
            ),
            '%service' => array(
                'value' => $data['service'],
                'description' => 'Service from the imported CSV'
            ),
            '%survey_link' => array(
                'value' => $survey_link,
                'description' => 'Link to the survey',
            ),
            '%admin_email' => array(
                'value' => $this->getEmail(),
                'description' => 'Review Boost Admin Email ('.$this->getEmail().')'
            ),
            '%company_phone' => array(
                'value' => $this->getPhone(),
                'description' => 'Company phone number (' . $this->getPhone().')'
            ),
            '%company_name' => array(
                'value' => $this->getCompanyName(),
                'description' => 'Company name (' . $this->getCompanyName().')'
            ),
            '%street' => array(
                'value' => $this->address['street'],
                'description' => 'Site location address: Street' . " ({$this->address['street']})"
            ),
            '%street2' => array(
                'value' => $this->address['street2'],
                'description' => 'Site location address: Additional' . " ({$this->address['street2']})"
            ),
            '%locality' => array(
                'value' => $this->address['locality'],
                'description' => 'Site location address: City' . " ({$this->address['locality']})"
            ),
            '%province' => array(
                'value' => $this->address['province'],
                'description' => 'Site location address: State/Province' . " ({$this->address['province']})"
            ),
            '%postal_code' => array(
                'value' => $this->address['postal_code'],
                'description' => 'Site location address: Postal Code' . " ({$this->address['postal_code']})"
            ),
            '%review_links' => array(
                'value' => $this->getReviewLinksHtml(),
                'description' => 'Review links selected <a href="/admin/survey/review-settings">here</a>.'
            ),
        );

        $this->tokens = array();
        $this->token_desciptions = array();
        foreach ($default_tokens as $t => $v) {
            $this->tokens[$t] = $v['value'];
            $this->token_desciptions[$t] = $v['description'];
        }
    }

    function getEmail() {
        if($this->company_email === null) {
            $this->company_email = variable_get('review_boost_settings_email',
                variable_get('webform_default_from_address',
                    variable_set('site_mail', '')
                )
            );
        }

        return $this->company_email;
    }

    function getPhone() {
        if($this->company_phone === null) {
            $phone = '';

            $functions = array(
                'sprowt_settings_get_phone_number',
                'leadbuilder_settings_get_phone_number',
                'coal_admin_get_phone_number'
            );

            foreach ($functions as $f) {
                if (function_exists($f)) {
                    $phone = $f();
                }
            }

            $this->company_phone = $phone;
        }

        return $this->company_phone;
    }

    function getCompanyName() {
        if($this->company_name === null) {
            $this->company_name = variable_get('sprowt_settings_company_name',
                variable_get('leadbuilder_settings_company_name',
                    variable_get('coal_admin_company_name',
                        variable_get('site_name')
                    )
                )
            );
        }

        return $this->company_name;
    }

    function addTokenValues($array) {
        $this->tokens = array_merge($this->tokens, $array);
    }

    function addTokenDescriptions($array) {
        $this->token_desciptions = array_merge($this->token_desciptions, $array);
    }

    function translateValues($str, $addtl = array()) {
        $this->addTokenValues($addtl);

        foreach($this->tokens as $t => $value) {
            $str = str_replace($t, $value , $str);
        }

        return $str;
    }

    function getTokenHelp($addtl = array()) {
        $this->addTokenDescriptions($addtl);

        $token_list = '<ul>';

        foreach($this->token_desciptions as $t => $desc) {
            $token_list .= "<li>$t - $desc</li>";
        }

        $token_list .= '</ul>';

        return $token_list;
    }

    function allowHtml() {
        if($this->allow_html === null) {
            if(module_exists('smtp')) {
                $allow_html = variable_get('smtp_allowhtml', false);
            }
            else {
                $allow_html = false;
            }
            $this->allow_html = $allow_html;
        }

        return $this->allow_html;
    }

    function defaultCustomerEmailBody() {
        $body = theme('review_boost_email_request');

        if(!$this->allowHtml()) {
            $body = preg_replace('/<.?\/?br.?>/',"\r\n\t" , $body);
            $body = drupal_html_to_text($body);
        }

        return $body;
    }

    function defaultAdminEmailBody() {

        $tokens = array(
            '%customer_id',
            '%customer_first_name',
            '%customer_last_name',
            '%customer_email',
            '%technician',
            '%sales',
            '%branch',
            '%service',
            '%service_date',
            '%survey_link',
        );

        $admin_email_body = "<p>A new survey has come in with the following results:</p>";
        $admin_email_body .= '<ul><li><b>rating</b>: %rating</li><li><b>comments</b>: %comments</li></ul>';
        $admin_email_body .= '<p>And the following customer info:</p><ul>';

        foreach($tokens as $t) {
            $admin_email_body .= '<li><b>' . str_replace('%', '' , $t) . '</b>: ' . $t . '</li>';
        }
        $admin_email_body .= '</ul>';

        if(!$this->allowHtml()) {
            $admin_email_body = drupal_html_to_text($admin_email_body);
        }

        return $admin_email_body;
    }

    function companySignoff() {
        $signoff_array = $this->address;
        $signoff_array['phone_number'] = $this->getPhone();
        $signoff_array['company_name'] = $this->getCompanyName();
        $signoff = theme('review_boost_email_signoff', $signoff_array);

        return $signoff;
    }

    function customerEmailBody($addtl = array(), $translate = true) {
        $customer_email_body = variable_get('review_boost_customer_body');
        if(!empty($customer_email_body)) {
            if(is_array($customer_email_body)) {
                $customer_email_body = $customer_email_body['value'];
            }

            if(!$this->allowHtml()) {
                $customer_email_body = drupal_html_to_text($customer_email_body);
            }
        }
        else {
            $customer_email_body = $this->defaultCustomerEmailBody();
        }
        if($translate) {
            $customer_email_body = $this->translateValues($customer_email_body, $addtl);
        }

        return $customer_email_body;
    }

    function customerEmailFormat() {
        $customer_email_body = variable_get('review_boost_customer_body');

        $email_format = 'full_html';
        if(!empty($customer_email_body)) {
            if (is_array($customer_email_body)) {
                $email_format = $customer_email_body['format'];
            }
        }

        return $email_format;
    }

    function adminEmailBody($addtl = array(), $translate = true) {
        $admin_email_body = variable_get('review_boost_admin_body');

        if(!empty($admin_email_body)) {
            if(is_array($admin_email_body)) {
                $admin_email_body = $admin_email_body['value'];
            }
        }
        else {
            $admin_email_body = $this->defaultAdminEmailBody();
        }

        if(!$this->allowHtml()) {
            $admin_email_body = drupal_html_to_text($admin_email_body);
        }

        if($translate) {
            $admin_email_body = $this->translateValues($admin_email_body, $addtl);
        }

        return $admin_email_body;
    }

    function adminEmailFormat() {
        $admin_email_body = variable_get('review_boost_admin_body');

        $email_format = 'full_html';
        if(!empty($admin_email_body)) {
            if(is_array($admin_email_body)) {
                $email_format = $admin_email_body['format'];
            }
        }

        return $email_format;
    }

    function getStarField($field_name, $title, $description = '') {
        $form = array();

        $form[$field_name] = array(
            '#type' => 'hidden',
            '#attributes' => array(
                'id' => array(
                    'backing-' . $field_name,
                ),
            ),
        );

        $form['rateit_' . $field_name] = array(
            '#title' => t($title),
            '#type' => 'markup',
            '#markup' => '<div id="rateit" class="rateit bigstars" data-rateit-backingfld="#backing-'.$field_name.'" data-rateit-starwidth="32" data-rateit-starheight="32" data-rateit-step="1"></div>',
        );

        return $form;
    }

    function defaultReviewUrl($machinename){
        return variable_get('sprowt_settings_'.$machinename.'_url',
                    variable_get('leadbuilder_settings_'.$machinename.'_url',
                        variable_get('coal_admin_'.$machinename.'_url', '')
                    )
        );
    }

    function defaultReviewLinks() {
        $default = array(
            'facebook' => 'Facebook',
            'gplus' => 'Google+',
            'yelp' => 'Yelp',
            'bbb' => 'Better Business Bureau',
            'angie' => 'Angie\'s List',
            'yp' => 'Yellow Pages'
        );

        $return = array();
        foreach($default as $m => $t) {
            $item = array(
                'id' => $m,
                'class' => $m,
                'link' => $this->defaultReviewUrl($m),
                'title' => $t,
                'enabled' => false,
                'default' => true
            );

            $return[$m] = $item;
        }

        return $return;
    }

    function getReviewLinks($json = false) {
        $val = variable_get('review_boost_review_links', null);
        if(empty($val)) {
            $val = $this->defaultReviewLinks();

            $val['facebook']['enabled'] = true;
            $val['gplus']['enabled'] = true;
        }

        if($json) {
            return json_encode($val);
        }

        return $val;
    }

    function getReviewLinksHtml(){
        $links = $this->getReviewLinks();

        $html = '<div class="review-boost-review-links-wrap">';
        $html .= '<ul class="review-boost-review-links">';
        foreach($links as $link) {
            if($link['enabled'] || variable_get('review_boost_show_all_links', false)) {
                $html .= "<li class=\"{$link['class']}\">";
                $html .= "<a href=\"{$link['link']}\" target=\"_blank\"><span>{$link['title']}</span></a>";
                $html .= "</li>";
            }
        }
        $html .= '</ul>';
        $html .= '</div>';

        return $html;
    }
}