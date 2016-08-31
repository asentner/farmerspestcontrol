<?php

function leadbuilder_dashboard_admin() {

  drupal_set_title(variable_get('site_name') . ' Dashboard');
  drupal_add_css(drupal_get_path('module', 'leadbuilder_dashboard') . '/leadbuilder_dashboard.css');
  $html = '';

  $html .= _leadbuilder_dashboard_generate_package_block();
  $html .= _leadbuilder_dashboard_generate_service_block();
  $html .= _leadbuilder_dashboard_generate_markets_block();
  $html .= _leadbuilder_dashboard_generate_regions_block();
  $html .= _leadbuilder_dashboard_generate_localtargets_block();



  return $html;
}
/**
 * Function to display the Service table.
 */
function _leadbuilder_dashboard_generate_service_block() {
  $result = db_query('SELECT * FROM {node} WHERE type=:type ORDER BY title', array(':type'=>'service'));

  $headers = array(
    'Title',
    'Status',
    'Operations',
  );

  $data = array();
  foreach($result as $row) {
    $view = l('View', 'node/'.$row->nid);
    $edit = l('Edit', 'node/'.$row->nid.'/edit');
    $status = ($row->status == 1) ? 'published' : 'not published';

    $data[] = array(
      $row->title,
      $status,
      "$view | $edit",
    );
  }

  $html = '<div class="leadbuilder_dashboard_table">';
  $html .= '<h2 class="block-title">' . t('Services') . '</h2>';
  $html .= '<ul class="action-links"><li><a href="/admin/structure/taxonomy/services/add">Add</a></li></ul>';
  $html .= _leadbuilder_dashboard_generate_table_block($headers, $data);
  $html .= '</div>';

  return $html;
}

/**
 * Function to display the Packages table.
 */
function _leadbuilder_dashboard_generate_package_block() {
  $result = db_query('SELECT nid, title, status, GROUP_CONCAT(name SEPARATOR \', \') as names FROM {node} 
    LEFT JOIN {field_data_field_services} sc ON sc.entity_id=nid
    LEFT JOIN {taxonomy_term_data} ta ON field_services_tid=ta.tid
    WHERE type=:type GROUP BY node.nid', array(':type'=>'package'));

  $headers = array(
    'Title',
    'Services',
    'Status',
    'Operations',
  );

  $data = array();
  foreach($result as $row) {
    $view = l('View', 'node/'.$row->nid);
    $edit = l('Edit', 'node/'.$row->nid.'/edit');
    $status = ($row->status == 1) ? 'published' : 'not published';

    $data[] = array(
      $row->title,
      $row->names,
      $status,
      "$view | $edit",
    );
  }

  $html = '<div class="leadbuilder_dashboard_table">';
  $html .= '<h2 class="block-title">' . t('Packages') . '</h2>';
  $html .= '<ul class="action-links"><li><a href="/node/add/package">Add</a></li></ul>';
  $html .= _leadbuilder_dashboard_generate_table_block($headers, $data);
  $html .= '</div>';

  return $html;
}

/**
 * Function to display the Markets table.
 */
function _leadbuilder_dashboard_generate_markets_block() {
  $result = db_query('SELECT td.tid, td.name, GROUP_CONCAT(r.name SEPARATOR \', \') AS region
    FROM {taxonomy_term_data} td
    LEFT JOIN field_data_field_markets m ON m.field_markets_tid=td.tid
    LEFT JOIN {taxonomy_term_data} r ON r.tid=m.entity_id
    LEFT JOIN {taxonomy_vocabulary} v ON v.vid=td.vid
    WHERE v.machine_name=:vocab GROUP BY td.tid ORDER BY td.name', array(':vocab'=>'markets'));

  $headers = array(
    'Title',
    'Regions',
    'Operations',
  );

  $data = array();
  foreach($result as $row) {
    $view = l('View', 'taxonomy/term/'.$row->tid);
    $edit = l('Edit', 'taxonomy/term/'.$row->tid.'/edit');

    $data[] = array(
      $row->name,
      $row->region,
      "$view | $edit",
    );
  }

  $html = '<div class="leadbuilder_dashboard_table">';
  $html .= '<h2 class="block-title">' . t('Markets') . '</h2>';
  $html .= '<ul class="action-links"><li><a href="/admin/structure/taxonomy/markets/add">Add</a></li></ul>';
  $html .= _leadbuilder_dashboard_generate_table_block($headers, $data);
  $html .= '</div>';

  return $html;
}

/**
 * Function to display the Regions table.
 */
function _leadbuilder_dashboard_generate_regions_block() {
  $result = db_query('SELECT td.tid, td.name
    FROM {taxonomy_term_data} td
    LEFT JOIN {taxonomy_vocabulary} v ON v.vid=td.vid
    WHERE v.machine_name=:vocab ORDER BY td.name', array(':vocab'=>'regions'));

  $headers = array(
    'Title',
    'Operations',
  );

  $data = array();
  foreach($result as $row) {
    $view = l('View', 'taxonomy/term/'.$row->tid);
    $edit = l('Edit', 'taxonomy/term/'.$row->tid.'/edit');

    $data[] = array(
      $row->name,
      "$view | $edit",
    );
  }

  $html = '<div class="leadbuilder_dashboard_table">';
  $html .= '<h2 class="block-title">' . t('Regions') . '</h2>';
  $html .= '<ul class="action-links"><li><a href="/admin/structure/taxonomy/regions/add">Add</a></li></ul>';
  $html .= _leadbuilder_dashboard_generate_table_block($headers, $data);
  $html .= '</div>';

  return $html;
}

/**
 * Function to display the LocalTarget table.
 */
function _leadbuilder_dashboard_generate_localtargets_block() {
  $result = db_query('SELECT nid, status, title, tm.name AS market, ta.name AS scat 
    FROM {node}
    LEFT JOIN {field_data_field_market} m ON nid=m.entity_id
    LEFT JOIN {field_data_field_service} sc ON sc.entity_id=nid
    LEFT JOIN {taxonomy_term_data} tm ON field_market_tid=tm.tid
    LEFT JOIN {taxonomy_term_data} ta ON field_service_tid=ta.tid
    WHERE type=:type ORDER BY title', array(':type'=>'localtarget'));

  $headers = array(
    'Title',
    'Service',
    'Market',
    'Status',
    'Operations',
  );

  $data = array();
  foreach($result as $row) {
    $view = l('View', 'node/'.$row->nid);
    $edit = l('Edit', 'node/'.$row->nid.'/edit');
    $status = ($row->status == 1) ? 'published' : 'not published';

    $data[] = array(
      $row->title,
      $row->scat,
      $row->market,
      $status,
      "$view | $edit",
    );
  }

  $html = '<div class="leadbuilder_dashboard_table">';
  $html .= '<h2 class="block-title">' . t('LocalTarget') . '</h2>';
  $html .= _leadbuilder_dashboard_generate_table_block($headers, $data);
  $html .= '</div>';

  return $html;
}


/**
 * Helper function to render a dashboard table.
 */
function _leadbuilder_dashboard_generate_table_block($headers, $data) {
  $variables = array(
    'header' => $headers,
    'rows' => $data,
    'attributes' => array(),
    'caption' => '',
    'colgroups' => array(),
    'sticky' => FALSE,
    'empty' => '',
  );

  return theme_table($variables);
}
















































