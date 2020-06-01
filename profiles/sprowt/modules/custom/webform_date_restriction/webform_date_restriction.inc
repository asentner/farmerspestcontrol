<?php

/**
 * @file
 * Contains functions specific to module.
 */

/**
 * Form modifications for date component.
 *
 * See webform_date_restriction_form_webform_component_edit_form_alter().
 */
function _webform_date_restriction_date_form(&$form, &$form_state) {

  $nid = $form['nid']['#value'];
  $cid = $form['cid']['#value'];

  $rests = _webform_date_restriction_get_date_restrictions($nid, $cid);

  $restriction = array();

  $daynums = range(0, 6);
  $daysoweek = array();
  $dateTime = new DateTime('Sunday');
  $day = new DateInterval('P1D');
  foreach ($daynums as $d) {
    $daysoweek[$d] = t($dateTime->format('D'));
    $dateTime->add($day);
  }

  $restriction['daysoweek'] = array(
    '#type' => 'checkboxes',
    '#title' => t('Restrict By Days of the Week'),
    '#description' => t('Chosen days will not be available to the form.'),
    '#options' => $daysoweek,
    '#attributes' => array(
      'class' => array('horizontal-checks'),
    ),
    '#default_value' => $rests['daysoweek'],
  );

  $monthnums = range(1, 12);
  $months = array();
  $dateTime = new DateTime('01/01/1970');
  $month = new DateInterval('P1M');
  foreach ($monthnums as $m) {
    $months[$m] = t($dateTime->format('M'));
    $dateTime->add($month);
  }

  $restriction['months'] = array(
    '#type' => 'checkboxes',
    '#title' => t('Restrict By Month'),
    '#description' => t('Chosen months will not be available to the form.'),
    '#options' => $months,
    '#attributes' => array(
      'class' => array('horizontal-checks'),
    ),
    '#default_value' => $rests['months'],
  );

  if (!isset($form_state['years'])) {
    $form_state['years'] = empty($rests['years']) ? array() : $rests['years'];
  }

  if (!isset($form_state['days'])) {
    $form_state['days'] = empty($rests['days']) ? array() : $rests['days'];
  }

  if (!isset($form_state['daysoyear'])) {
    $form_state['daysoyear'] = empty($rests['daysoyear']) ? array() : $rests['daysoyear'];
  }

  if (!isset($form_state['phpval'])) {
    $form_state['phpval'] = empty($rests['phpval']) ? array() : $rests['phpval'];
  }

  $years = array();
  foreach ($form_state['years'] as $i => $year) {
    $remove = array(
      'remove' => array(
        '#type' => 'hidden',
        '#default_value' => '',
        '#attributes' => array(
          'data-index' => $i,
          'id' => 'remove-' . $i,
          'class' => array(
            'removeYearVal',
          ),
        ),
      ),
      'removeButton' => array(
        '#type' => 'markup',
        '#markup' => '<input data-index="' . $i . '" class="removeYear form-submit" value="' . t('Remove') . '" type="button">',
      ),
      'removeButtonAjax' => array(
        '#prefix' => '<div style="display:none;">',
        '#suffix' => '</div>',
        '#type' => 'submit',
        '#name' => 'removeYear_' . $i,
        '#value' => t('Remove'),
        '#attributes' => array(
          'data-index' => $i,
          'class' => array(
            'removeButtonAjax',
          ),
        ),
        '#submit' => array('_webform_date_restriction_remove_year'),
        '#validate' => array('_webform_date_restriction_cleanup_values'),
        '#ajax' => array(
          'callback' => '_webform_date_restriction_add_year_callback',
          'wrapper' => 'years-wrap',
        ),
      ),
    );
    $years['years_' . $i] = array(
      '#type' => 'container',
      '#attributes' => array(
        'class' => array('year-container'),
      ),
      'year' => array(
        '#type' => 'textfield',
        '#size' => 4,
        '#maxlength' => 4,
        '#default_value' => $year,
      ),
    );
    $years['years_' . $i] = array_merge($years['years_' . $i], $remove);
  }

  $days = array();
  foreach ($form_state['days'] as $i => $day) {
    $remove = array(
      'remove' => array(
        '#type' => 'hidden',
        '#default_value' => '',
        '#attributes' => array(
          'data-index' => $i,
          'id' => 'remove-' . $i,
          'class' => array(
            'removeDayVal',
          ),
        ),
      ),
      'removeButton' => array(
        '#type' => 'markup',
        '#markup' => '<input data-index="' . $i . '" class="removeDay form-submit" value="' . t('Remove') . '" type="button">',
      ),
      'removeButtonAjax' => array(
        '#prefix' => '<div style="display:none;">',
        '#suffix' => '</div>',
        '#type' => 'submit',
        '#value' => t('Remove'),
        '#name' => 'removeDay_' . $i,
        '#attributes' => array(
          'data-index' => $i,
          'class' => array(
            'removeButtonAjax',
          ),
        ),
        '#submit' => array('_webform_date_restriction_remove_day'),
        '#validate' => array('_webform_date_restriction_cleanup_values'),
        '#ajax' => array(
          'callback' => '_webform_date_restriction_add_day_callback',
          'wrapper' => 'day-wrap',
        ),
      ),
    );

    if (module_exists('date_popup')) {
      $dayfield = array(
        '#type' => 'date_popup',
        '#date_format' => 'm/d/Y',
        '#date_year_range' => '0:+15',
        '#default_value' => $day,
        '#prefix' => '<div class="dayfield">',
        '#suffix' => '</div>',
      );
    }
    else {
      $dayfield = array(
        '#type' => 'date',
        '#prefix' => '<div class="dayfield">',
        '#suffix' => '</div>',
      );
      if (!empty($day)) {
        if (!is_array($day)) {
          $dateTime = new DateTime($day);
          $day = array(
            'year' => $dateTime->format('Y'),
            'month' => $dateTime->format('n'),
            'day' => $dateTime->format('j'),
          );
        }
        $dayfield['#default_value'] = $day;
      }
    }

    $days['days_' . $i] = array(
      '#type' => 'container',
      '#attributes' => array(
        'class' => array('day-container'),
      ),
      'day' => $dayfield,
    );
    $days['days_' . $i] = array_merge($days['days_' . $i], $remove);
  }

  $daysoyear = array();
  foreach ($form_state['daysoyear'] as $i => $dayoyear) {
    $remove = array(
      'remove' => array(
        '#type' => 'hidden',
        '#default_value' => '',
        '#attributes' => array(
          'data-index' => $i,
          'id' => 'remove-' . $i,
          'class' => array(
            'removeDayoyearVal',
          ),
        ),
      ),
      'removeButton' => array(
        '#type' => 'markup',
        '#markup' => '<input data-index="' . $i . '" class="removeDayoyear form-submit" value="' . t('Remove') . '" type="button">',
      ),
      'removeButtonAjax' => array(
        '#prefix' => '<div style="display:none;">',
        '#suffix' => '</div>',
        '#type' => 'submit',
        '#value' => t('Remove'),
        '#name' => 'removeDayoyear_' . $i,
        '#attributes' => array(
          'data-index' => $i,
          'class' => array(
            'removeButtonAjax',
          ),
        ),
        '#submit' => array('_webform_date_restriction_remove_dayoyear'),
        '#validate' => array('_webform_date_restriction_cleanup_values'),
        '#ajax' => array(
          'callback' => '_webform_date_restriction_add_dayoyear_callback',
          'wrapper' => 'dayoyear-wrap',
        ),
      ),
    );

    $dayfield = array(
      '#type' => 'date_select',
      '#date_format' => 'm-d',
      '#date_year_range' => '0:+15',
      '#prefix' => '<div class="dayfield">',
      '#suffix' => '</div>',
    );

    if (!empty($dayoyear)) {
      $dayfield['#default_value'] = '1970-' . $dayoyear;
    }

    $daysoyear['daysoyear_' . $i] = array(
      '#type' => 'container',
      '#attributes' => array(
        'class' => array('day-container'),
      ),
      'dayoyear' => $dayfield,
    );
    $daysoyear['daysoyear_' . $i] = array_merge($daysoyear['daysoyear_' . $i], $remove);
  }

  $phpfields = array();

  foreach ($form_state['phpval'] as $i => $phpval) {
    $remove = array(
      'remove' => array(
        '#type' => 'hidden',
        '#default_value' => '',
        '#attributes' => array(
          'data-index' => $i,
          'id' => 'remove-' . $i,
          'class' => array(
            'removePhpVal',
          ),
        ),
      ),
      'removeButton' => array(
        '#type' => 'markup',
        '#markup' => '<input data-index="' . $i . '" class="removePhp form-submit" value="' . t('Remove') . '" type="button">',
      ),
      'removeButtonAjax' => array(
        '#prefix' => '<div style="display:none;">',
        '#suffix' => '</div>',
        '#type' => 'submit',
        '#value' => t('Remove'),
        '#name' => 'removePhpVal_' . $i,
        '#attributes' => array(
          'data-index' => $i,
          'class' => array(
            'removeButtonAjax',
          ),
        ),
        '#submit' => array('_webform_date_restriction_remove_phpval'),
        '#validate' => array('_webform_date_restriction_cleanup_values'),
        '#ajax' => array(
          'callback' => '_webform_date_restriction_add_phpval_callback',
          'wrapper' => 'phpval-wrap',
        ),
      ),
    );

    $phpfield = array(
      '#type' => 'textfield',
    );

    if (!empty($phpval)) {
      $phpfield['#default_value'] = $phpval;
    }

    $phpfields['phpval_' . $i] = array(
      '#type' => 'container',
      '#attributes' => array(
        'class' => array('year-container'),
      ),
      'phpval' => $phpfield,
    );
    $phpfields['phpval_' . $i] = array_merge($phpfields['phpval_' . $i], $remove);
  }

  $restriction['years_container'] = array(
    '#type' => 'item',
    '#title' => t('Restrict By Year'),
    '#description' => t('Added years will not be available to the form.'),
    'years_wrap' => array(
      '#type' => 'container',
      'years' => $years,
      '#attributes' => array(
        'id' => 'years-wrap',
      ),
    ),
    'add_year' => array(
      '#type' => 'submit',
      '#value' => t('Add'),
      '#submit' => array('_webform_date_restriction_add_year'),
      '#name' => 'addYear',
      '#validate' => array('_webform_date_restriction_cleanup_values'),
      '#ajax' => array(
        'callback' => '_webform_date_restriction_add_year_callback',
        'wrapper' => 'years-wrap',
      ),
    ),
  );

  $restriction['daysoyear_container'] = array(
    '#type' => 'item',
    '#title' => t('Restrict By Day of the Year'),
    '#description' => t('Added days of the year will not be available to the form when a year is filled out (or hidden).'),
    'daysoyear_wrap' => array(
      '#type' => 'container',
      'daysoyear' => $daysoyear,
      '#attributes' => array(
        'id' => 'dayoyear-wrap',
      ),
    ),
    'add_dayoyear' => array(
      '#type' => 'submit',
      '#value' => t('Add'),
      '#submit' => array('_webform_date_restriction_add_dayoyear'),
      '#name' => 'addDayoyear',
      '#validate' => array('_webform_date_restriction_cleanup_values'),
      '#ajax' => array(
        'callback' => '_webform_date_restriction_add_dayoyear_callback',
        'wrapper' => 'dayoyear-wrap',
      ),
    ),
  );

  $restriction['days_container'] = array(
    '#type' => 'item',
    '#title' => t('Restrict By Date'),
    '#description' => t('Added dates will not be available to the form.'),
    'days_wrap' => array(
      '#type' => 'container',
      'days' => $days,
      '#attributes' => array(
        'id' => 'day-wrap',
      ),
    ),
    'add_day' => array(
      '#type' => 'submit',
      '#value' => t('Add'),
      '#submit' => array('_webform_date_restriction_add_day'),
      '#name' => 'addDay',
      '#validate' => array('_webform_date_restriction_cleanup_values'),
      '#ajax' => array(
        'callback' => '_webform_date_restriction_add_day_callback',
        'wrapper' => 'day-wrap',
      ),
    ),
  );

  $restriction['phpval_container'] = array(
    '#type' => 'item',
    '#title' => t('Restrict By Relative Value'),
    '#description' => t('Values here use PHP <a href="http://php.net/manual/en/datetime.formats.php">date and time formats</a>. Added dates will not be available to the form.'),
    'phpval_wrap' => array(
      '#type' => 'container',
      'phpvals' => $phpfields,
      '#attributes' => array(
        'id' => 'phpval-wrap',
      ),
    ),
    'add_phpval' => array(
      '#type' => 'submit',
      '#value' => t('Add'),
      '#submit' => array('_webform_date_restriction_add_phpval'),
      '#name' => 'addPhpVal',
      '#validate' => array('_webform_date_restriction_cleanup_values'),
      '#ajax' => array(
        'callback' => '_webform_date_restriction_add_phpval_callback',
        'wrapper' => 'phpval-wrap',
      ),
    ),
  );

  $form['restriction'] = array(
    '#type' => 'fieldset',
    '#title' => t('Restrictions'),
    '#description' => t('This will limit the dates available to be chosen'),
    '#collapsible' => TRUE,
    '#collapsed' => TRUE,
    '#weight' => 4,
    'values' => $restriction,
  );

  $form['#validate'][] = '_webform_date_restriction_cleanup_values';
  $form['#validate'][] = '_webform_date_restriction_check_year';
  $form['#validate'][] = '_webform_date_restriction_check_php';
  $form['#submit'][] = '_webform_date_restriction_submit_date';

  $form['#attached']['js'][] = drupal_get_path('module', 'webform_date_restriction') . '/js/date.js';
  $form['#attached']['css'][] = drupal_get_path('module', 'webform_date_restriction') . '/css/date.css';
}

/**
 * Date Component validate function to clean up values for the form state.
 */
function _webform_date_restriction_cleanup_values($form, &$form_state) {
  $restriction = $form_state['values']['restriction']['values'];
  $vals = array(
    'daysoweek' => array(),
    'months' => array(),
    'years' => array(),
    'days' => array(),
    'daysoyear' => array(),
    'phpval' => array(),
  );

  foreach ($restriction['daysoweek'] as $k => $v) {
    if ($v !== 0) {
      $vals['daysoweek'][] = $k;
    }
  }

  foreach ($restriction['months'] as $k => $v) {
    if ($v !== 0) {
      $vals['months'][] = $k;
    }
  }

  $years = empty($restriction['years_container']['years_wrap']['years']) ? array() : $restriction['years_container']['years_wrap']['years'];

  foreach ($years as $year) {
    if (empty($year['remove'])) {
      $vals['years'][] = $year['year'];
    }
  }

  $days = empty($restriction['days_container']['days_wrap']['days']) ? array() : $restriction['days_container']['days_wrap']['days'];

  foreach ($days as $day) {
    if (empty($day['remove'])) {
      $vals['days'][] = $day['day'];
    }
  }

  $daysoyear = empty($restriction['daysoyear_container']['daysoyear_wrap']['daysoyear']) ? array() : $restriction['daysoyear_container']['daysoyear_wrap']['daysoyear'];

  foreach ($daysoyear as $dayoyear) {
    if (empty($dayoyear['remove'])) {
      $vals['daysoyear'][] = $dayoyear['dayoyear'];
    }
  }

  $phpval = empty($restriction['phpval_container']['phpval_wrap']['phpvals']) ? array() : $restriction['phpval_container']['phpval_wrap']['phpvals'];
  foreach ($phpval as $php) {
    if (empty($php['remove'])) {
      $vals['phpval'][] = $php['phpval'];
    }
  }

  $form_state['values']['restriction'] = $vals;
}

/**
 * Validate function to check for a valid year.
 */
function _webform_date_restriction_check_year(&$form, &$form_state) {
  $rests = $form_state['values']['restriction'];
  if (!empty($rests['years'])) {
    foreach ($rests['years'] as $key => $year) {
      if (!preg_match('/[\d]{4}/', $year)) {
        $element = _webform_date_restriction_get_element($form, 'years_' . $key);
        form_error($element['year'], t('Year is invalid.'));
      }
    }
  }
}

/**
 * Validate function to check for a valid year.
 */
function _webform_date_restriction_check_php(&$form, &$form_state) {
  $rests = $form_state['values']['restriction'];
  if (!empty($rests['phpval'])) {
    foreach ($rests['phpval'] as $key => $php) {
      try {
        $DT = new DateTime($php);
      }
      catch(Exception $e) {
        $element = _webform_date_restriction_get_element($form, 'phpval_' . $key);
        form_error($element['phpval'], t('Relative date is not valid'));
      }
    }
  }
}

/**
 * Date Component submit function to add values to DB.
 */
function _webform_date_restriction_submit_date($form, &$form_state) {
  $values = $form_state['values']['restriction'];
  $nid = $form_state['values']['nid'];
  $cid = $form_state['values']['cid'];
  $transaction = db_transaction();
  try {
    db_delete('webform_date_restriction_date')
      ->condition('nid', $nid)
      ->condition('cid', $cid)
      ->execute();
  }
  catch (Exception $e) {
    $transaction->rollback();
    watchdog_exception('webform_date_restriction', $e);
    return FALSE;
  }

  $trans = array();
  $base_fields = array(
    'nid' => $nid,
    'cid' => $cid,
  );
  foreach ($values as $type => $val) {
    switch ($type) {
      case 'daysoweek':
      case 'months':
      case 'years':
      case 'daysoyear':
      case 'phpval':
        foreach ($val as $v) {
          if ($v !== '' && $v !== NULL) {
            $insert = db_insert('webform_date_restriction_date')
              ->fields(array_merge($base_fields, array(
                'type' => $type,
                'value' => $v,
              )));
            $trans[] = $insert;
          }
        }
        break;

      case 'days':
        foreach ($val as $v) {
          if ($v !== '' && $v !== NULL) {
            if (is_array($v)) {
              $dateTime = new DateTime();
              $dateTime->setTime(12, 0, 0);
              $dateTime->setDate($v['year'], $v['month'], $v['day']);
              $v = $dateTime->format('Y-m-d');
            }
            $insert = db_insert('webform_date_restriction_date')
              ->fields(array_merge($base_fields, array(
                'type' => $type,
                'value' => $v,
              )));
            $trans[] = $insert;
          }
        }
        break;
    }
  }

  if (!empty($trans)) {
    foreach ($trans as $t) {
      try {
        $t->execute();
      }
      catch (Exception $e) {
        $transaction->rollback();
        watchdog_exception('webform_date_restriction', $e);
        return FALSE;
      }
    }
  }

}

/**
 * Ajax submit function.
 */
function _webform_date_restriction_remove_year($form, &$form_state) {
  $years = $form_state['values']['restriction']['years'];
  $form_state['years'] = $years;
  $form_state['rebuild'] = TRUE;
}

/**
 * Ajax submit function.
 */
function _webform_date_restriction_add_year($form, &$form_state) {
  $years = $form_state['values']['restriction']['years'];
  $form_state['years'] = array_merge($years, array(""));
  $form_state['rebuild'] = TRUE;
}

/**
 * Ajax callback.
 */
function _webform_date_restriction_add_year_callback(&$form, &$form_state) {
  $cont = &$form['restriction']['values']['years_container']['years_wrap'];
  return $cont;
}

/**
 * Ajax submit function.
 */
function _webform_date_restriction_remove_day($form, &$form_state) {
  $days = $form_state['values']['restriction']['days'];
  $form_state['days'] = $days;
  $form_state['rebuild'] = TRUE;
}

/**
 * Ajax submit function.
 */
function _webform_date_restriction_add_day($form, &$form_state) {
  $days = $form_state['values']['restriction']['days'];
  $form_state['days'] = array_merge($days, array(""));
  $form_state['rebuild'] = TRUE;
}

/**
 * Ajax callback.
 */
function _webform_date_restriction_add_day_callback(&$form, &$form_state) {
  $cont = &$form['restriction']['values']['days_container']['days_wrap'];
  return $cont;
}

/**
 * Ajax submit function.
 */
function _webform_date_restriction_remove_dayoyear($form, &$form_state) {
  $days = $form_state['values']['restriction']['daysoyear'];
  $form_state['daysoyear'] = $days;
  $form_state['rebuild'] = TRUE;
}

/**
 * Ajax submit function.
 */
function _webform_date_restriction_add_dayoyear($form, &$form_state) {
  $days = $form_state['values']['restriction']['daysoyear'];
  $form_state['daysoyear'] = array_merge($days, array(""));
  $form_state['rebuild'] = TRUE;
}

/**
 * Ajax callback.
 */
function _webform_date_restriction_add_dayoyear_callback(&$form, &$form_state) {
  $cont = &$form['restriction']['values']['daysoyear_container']['daysoyear_wrap'];
  return $cont;
}

/**
 * Ajax submit function.
 */
function _webform_date_restriction_remove_phpval($form, &$form_state) {
  $phpval = $form_state['values']['restriction']['phpval'];
  $form_state['phpval'] = $phpval;
  $form_state['rebuild'] = TRUE;
}

/**
 * Ajax submit function.
 */
function _webform_date_restriction_add_phpval($form, &$form_state) {
  $phpval = $form_state['values']['restriction']['phpval'];
  $form_state['phpval'] = array_merge($phpval, array(""));
  $form_state['rebuild'] = TRUE;
}

/**
 * Ajax callback.
 */
function _webform_date_restriction_add_phpval_callback(&$form, &$form_state) {
  $cont = &$form['restriction']['values']['phpval_container']['phpval_wrap'];
  return $cont;
}

/**
 * Available types.
 */
function _webform_date_restriction_restriction_types() {
  return array(
    'daysoweek',
    'months',
    'years',
    'daysoyear',
    'days',
    'phpval'
  );
}

/**
 * Retrieve date component values from DB.
 *
 * @param int $nid
 *   Webform Node ID.
 * @param int $cid
 *   Webform Component ID.
 *
 * @return array
 *   Assoc array of restrictions for the component.
 */
function _webform_date_restriction_get_date_restrictions($nid, $cid) {
  $raw = db_query("
        SELECT *
        FROM {webform_date_restriction_date}
        WHERE nid = :nid
        AND cid = :cid
    ", array(
      ':nid' => $nid,
      ':cid' => $cid,
    ))->fetchAll(PDO::FETCH_ASSOC);

  $types = _webform_date_restriction_restriction_types();
  $restrictions = array();
  foreach ($types as $type) {
    $restrictions[$type] = array();
  }

  foreach ($raw as $row) {
    $restrictions[$row['type']][] = $row['value'];
  }

  $context = [
      'nid' => $nid,
      'cid' => $cid
  ];

  drupal_alter('webform_date_restrictions', $restrictions, $context);

  return $restrictions;
}

/**
 * Validate function in case browser restriction fails.
 */
function _webform_date_restriction_date_validate($form, &$form_state) {
  $node = $form['#node'];
  $date_compenents = array();
  foreach ($node->webform['components'] as $cid => $comp) {
    if ($comp['type'] == 'date') {
      $date_compenents[$cid] = $comp;
    }
  }

  $values = _webform_client_form_submit_flatten($node, $form_state['values']['submitted']);
  $errors = array();
  foreach ($values as $cid => $val) {
    if (in_array($cid, array_keys($date_compenents))) {
      $key = $date_compenents[$cid]['form_key'];
      $rests = _webform_date_restriction_get_date_restrictions($node->nid, $cid);
      $valDate = new DateTime();
      $valDate->setTime(12, 0, 0);
      $valDate->setDate($val['year'], $val['month'], $val['day']);

      if (!empty($rests['years'])) {
        foreach ($rests['years'] as $year) {
          if ($val['year'] == $year && !in_array($key, $errors)) {
            $errors[] = $key;
          }
        }
      }

      if (!empty($rests['months'])) {
        foreach ($rests['months'] as $month) {
          if ($val['month'] == $month && !in_array($key, $errors)) {
            $errors[] = $key;
          }
        }
      }

      if (!empty($rests['daysoyear'])) {
        foreach ($rests['daysoyear'] as $doy) {
          if ($doy == $valDate->format('m-d') && !in_array($key, $errors)) {
            $errors[] = $key;
          }
        }
      }

      if (!empty($rests['daysoweek'])) {
        foreach ($rests['daysoweek'] as $dow) {
          if ($dow == $valDate->format('w') && !in_array($key, $errors)) {
            $errors[] = $key;
          }
        }
      }

      if (!empty($rests['days'])) {
        foreach ($rests['days'] as $day) {
          if ($day == $valDate->format('Y-m-d') && !in_array($key, $errors)) {
            $errors[] = $key;
          }
        }
      }

      if (!empty($rests['phpval'])) {
        foreach ($rests['phpval'] as $php) {
          try {
            $day = new DateTime($php);
            if ($day == $valDate && !in_array($key, $errors)) {
              $errors[] = $key;
            }
          }
          catch(Exception $e) {
            //nothing
          }
        }
      }
    }
  }

  if (!empty($errors)) {
    foreach ($errors as $key) {
      $element = _webform_date_restriction_get_element($form, $key);
      form_error($element, t("We're sorry, the date selected is not available. Please choose another."));
    }
  }
}
