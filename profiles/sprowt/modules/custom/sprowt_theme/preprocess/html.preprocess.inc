<?php

function sprowt_theme_preprocess_html(&$variables) {
	if (isset($variables['page'])) {
    if (isset($variables['page']['sidebar_first']) && isset($variables['page']['sidebar_second'])) {
      $variables['classes_array'][] = 'has-two-sidebars';
    } else if (isset($variables['page']['sidebar_first'])) {
      $variables['classes_array'][] = 'has-sidebar-first';
    } else if (isset($variables['page']['sidebar_second'])) {
      $variables['classes_array'][] = 'has-sidebar-second';
    }
  }

	$variables['base_path'] = base_path() . path_to_theme();
  
  if($node = menu_get_object()) {
    sprowt_require_class('nodebuilder');
    $Node = new NodeBuilder($node);
    if(!empty($node->field_ebooking) && $Node->field_ebooking->value() == 'yes') {
      $variables['classes_array'][] = 'node-ebooking';
    }
  }
  
  $page = $variables['page'];
  foreach($page as $region) {
    if(is_array($region)) {
      foreach($region as $id => $block) {
        if(strpos($id, 'webform') !== false) {
          $nid = str_replace('webform_client-block-', '', $id);
          if($node = node_load($nid)) {
            sprowt_require_class('nodebuilder');
            $Node = new NodeBuilder($node);
            if(!empty($node->field_ebooking) && $Node->field_ebooking->value() == 'yes') {
              if(!in_array('has-ebooking', $variables['classes_array'])) {
                $variables['classes_array'][] = 'has-ebooking';
              }
            }
          }
        }
      }
    }
  }
  
}