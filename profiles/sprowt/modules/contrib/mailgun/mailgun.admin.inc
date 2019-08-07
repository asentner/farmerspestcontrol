<?php

/**
 * @file
 * Administration page callbacks for Mailgun.
 */

/**
 * Menu callback: displays the Mailgun module settings page.
 *
 * @param array $form
 *   Form render array.
 * @param array $form_state
 *   Array containing form state values.
 *
 * @return array
 *   An array containing form items to place on the module settings page.
 */
function mailgun_admin_settings(array $form, array &$form_state) {
  // Check if the Mailgun PHP library is installed.
  if (!mailgun_check_library()) {
    drupal_set_message(t('The Mailgun PHP library is not installed. Please see Installation section in the !link.', array(
      '!link' => l(t('documentation'), MAILGUN_DOCUMENTATION_LINK),
    )), 'error');
  }

  $key = variable_get('mailgun_api_key', '');

  $form['mailgun_api_key'] = array(
    '#title' => t('Mailgun API key'),
    '#type' => 'textfield',
    '#description' => t('Get your Secret API key from the !link.', array(
      '!link' => l(t('Mailgun dashboard'), MAILGUN_DASHBOARD_LINK),
    )),
    '#default_value' => $key,
    '#required' => TRUE,
  );

  $client = FALSE;
  if (!empty($key)) {
    try {
      $client = mailgun_get_client($key);
    }
    catch (Exception $e) {
      watchdog('mailgun', 'An exception occurred. @code: @message', array(
        '@code' => $e->getCode(),
        '@message' => $e->getMessage(),
      ), WATCHDOG_WARNING, MAILGUN_ADMIN_PAGE);
      drupal_set_message(t('Mailgun: %message', array('%message' => $e->getMessage())), 'error');
    }
  }

  // Display settings only when a valid API key is present and client is active.
  if ($client) {
    $domain_options = array(
      '_sender' => t('Get domain from sender address'),
    );
    $result = $client->domains()->index();
    if (!empty($result)) {
      if($result->getTotalCount() > 100) {
        $result = $client->domains()->index($result->getTotalCount());
      }
      $options = [];
      foreach ($result->getDomains() as $domain) {
        $options[$domain->getName()] = $domain->getName();
      }
      ksort($options);
      $domain_options = array_merge($domain_options, $options);
    }

    $form['mailgun_domain'] = array(
      '#title' => t('Domain'),
      '#type' => 'select',
      '#options' => $domain_options,
      '#description' => t('Mails will be sent using this domain.'),
      '#default_value' => variable_get('mailgun_domain', '_sender'),
    );

    $form['mailgun_test'] = array(
      '#title' => t('Test mode'),
      '#type' => 'checkbox',
      '#default_value' => variable_get('mailgun_test', FALSE),
      '#description' => t('Mailgun will accept the message but will not send it. This is useful for testing purposes.'),
    );

    $form['mailgun_log'] = array(
      '#title' => t('Log mails'),
      '#type' => 'checkbox',
      '#description' => t('Log all mails sent through Mailgun. Messages fail to send will be logged regardless of this setting.'),
      '#default_value' => variable_get('mailgun_log', FALSE),
    );

    $form['extra'] = array(
      '#type' => 'fieldset',
      '#title' => t('Additional settings'),
      '#description' => t('These default settings apply to messages sent using Mailgun and may be overriden on a per-message basis.'),
      '#collapsible' => TRUE,
      '#collapsed' => TRUE,
    );

    // We have the same options for all settings.
    $options = array(
      'default' => t('Use default setting'),
      'enabled' => t('Enabled'),
      'disabled' => t('Disabled'),
    );

    $form['extra']['tracking'] = array(
      '#type' => 'fieldset',
      '#title' => t('Tracking'),
    );

    $form['extra']['tracking']['mailgun_tracking'] = array(
      '#title' => t('Enable tracking'),
      '#type' => 'select',
      '#options' => $options,
      '#description' => t('Whether to enable event tracking by default or not. See !link for details.', array(
        '!link' => l(t('Tracking Messages'), 'https://documentation.mailgun.com/user_manual.html#tracking-messages'),
      )),
      '#default_value' => variable_get('mailgun_tracking', 'default'),
    );

    $form['extra']['tracking']['mailgun_tracking_clicks'] = array(
      '#title' => t('Enable click tracking'),
      '#type' => 'select',
      '#options' => $options,
      '#description' => t('Whether to enable click tracking by default or not.'),
      '#default_value' => variable_get('mailgun_tracking_clicks', 'default'),
    );

    $form['extra']['tracking']['mailgun_tracking_opens'] = array(
      '#title' => t('Enable open tracking'),
      '#type' => 'select',
      '#options' => $options,
      '#description' => t('Whether to enable open tracking by default or not.'),
      '#default_value' => variable_get('mailgun_tracking_opens', 'default'),
    );

    $formats = array('_none' => t('- None -'));
    foreach (filter_formats() as $format) {
      if ($format->format === 'php_code') {
        continue;
      }
      $formats[$format->format] = $format->name;
    }
    $form['extra']['mailgun_format'] = array(
      '#title' => t('Text format'),
      '#type' => 'select',
      '#description' => t('Specify an additional text format to filter the message through before sending the email.'),
      '#options' => $formats,
      '#default_value' => variable_get('mailgun_format', '_none'),
    );

    $form['extra']['mailgun_queue'] = array(
      '#title' => t('Queue mails'),
      '#type' => 'checkbox',
      '#description' => t('Mails will be queued and sent during cron runs. Useful for sending a large number of emails.'),
      '#default_value' => variable_get('mailgun_queue', FALSE),
    );

    $form['extra']['mailgun_tagging_mailkey'] = array(
      '#type' => 'checkbox',
      '#title' => t('Enable tags by mail key'),
      '#description' => t('See !url for details.', array(
        '!url' => l(t('Tagging'), 'https://documentation.mailgun.com/user_manual.html#tagging', array(
          'attributes' => array(
            'onclick' => "target='_blank'",
          ),
        )),
      )),
      '#default_value' => variable_get('mailgun_tagging_mailkey', TRUE),
    );
  }

  $form = system_settings_form($form);
  $form['#validate'][] = 'mailgun_admin_settings_validate';

  return $form;
}

/**
 * Form validation handler for mailgun_admin_settings().
 *
 * Perform additional validation to ensure the API key entered is valid.
 */
function mailgun_admin_settings_validate($form, &$form_state) {
  if ($form['mailgun_api_key']['#default_value'] != $form_state['values']['mailgun_api_key']) {
    // The API key has changed. Perform validation.
    $form_state['values']['mailgun_api_key'] = trim($form_state['values']['mailgun_api_key']);
    $client = mailgun_get_client($form_state['values']['mailgun_api_key']);

    if ($client === FALSE) {
      drupal_set_message(t('Could not connect to Mailgun API. Please check your settings'), 'warning');
      return;
    }

    try {
      $client->domains()->index();
      drupal_set_message(t('Your API key has been successfully validated.'));
    }
    catch (Exception $e) {
      form_set_error('mailgun_api_key', t('An exception occurred. @code: @message', array(
        '@code' => $e->getCode(),
        '@message' => $e->getMessage(),
      )));
    }
  }
}

/**
 * Form builder. Display a form for sending a test e-mail.
 */
function mailgun_test_form($form, &$form_state) {
  drupal_set_title(t('Send test mail'));

  $form['to'] = array(
    '#type' => 'textfield',
    '#title' => t('To'),
    '#default_value' => variable_get('site_mail', ''),
    '#description' => t('Type in an address to have the test email sent there.'),
    '#required' => TRUE,
  );

  $message = "Howdy!\n\nIf this e-mail is displayed correctly and delivered sound and safe, congrats! You have successfully configured Mailgun. ";
  $message .= t('Visit the !project to contribute or read !documentation to learn more.', array(
    '!project' => l(t('project page'), 'https://www.drupal.org/project/mailgun'),
    '!documentation' => l(t('documentation'), MAILGUN_DOCUMENTATION_LINK),
  ));
  $form['message'] = array(
    '#type' => 'textarea',
    '#title' => t('Message'),
    '#default_value' => $message,
    '#required' => TRUE,
  );

  $form['attachment'] = array(
    '#title' => t('Include attachment'),
    '#type' => 'checkbox',
    '#description' => t('If checked, the Drupal icon will be included as an attachment with the test e-mail.'),
    '#default_value' => TRUE,
  );

  $form['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Send'),
  );
  $form['cancel'] = array(
    '#type' => 'link',
    '#href' => MAILGUN_ADMIN_PAGE,
    '#title' => t('Cancel'),
  );

  return $form;
}

/**
 * Form submission handler for mailgun_test_form().
 *
 * Send the test e-mail.
 */
function mailgun_test_form_submit($form, &$form_state) {
  $to = $form_state['values']['to'];
  $body = explode('\n', $form_state['values']['message']);

  $params = array(
    'message' => $body,
    'attachment' => $form_state['values']['attachment'],
  );
  $site_name = variable_get('site_name', '');
  $default_from = variable_get('site_mail', ini_get('sendmail_from'));
  $from = (!empty($site_name)) ? $site_name . ' <' . $default_from . '>' : $default_from;
  $result = drupal_mail('mailgun', 'test', $to, $GLOBALS['language'], $params, $from);

  drupal_set_message(t('Test email sent from %from to %to. If you have the "Log mails" setting enabled, check the <a href="@url">database log</a> for details.',
    array(
      '%from' => $result['from'],
      '%to' => $result['to'],
      '@url' => url('admin/reports/dblog'),
    )), 'status');
}