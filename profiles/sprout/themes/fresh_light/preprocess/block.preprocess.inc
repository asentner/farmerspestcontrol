<?php

 function fresh_light_preprocess_block(&$variables) {
  $node = menu_get_object();
  $block = $variables['block'];
  
  if($node
     && ($node->type == 'localtarget'
      && ($block->delta == 'packages-related'
          || $block->delta == 'packages-localtarget'))){
      if(!empty($node->field_packages_title)){
          $variables['block']->subject = $node->field_packages_title[LANGUAGE_NONE][0]['value'];
      }
      
      if(!empty($node->field_packages_intro)){
          $field = field_view_field('node',$node,'field_packages_intro',array(
                                      'label' => 'hidden'
                                  ));
          $variables['content'] = render($field) .
                                  $variables['content'];
      }
  }
  if($node && $node->type == 'service'
     && $block->delta == 'packages-services'){
      if(!empty($node->field_package_title)){
          $variables['block']->subject = $node->field_packages_title[LANGUAGE_NONE][0]['value'];
      }
      
      if(!empty($node->field_package_intro)){
       $field = field_view_field('node',$node,'field_package_intro',array(
                                      'label' => 'hidden'
                                  ));
          $variables['content'] = render($field) .
                                  $variables['content'];
      }
  }
 }