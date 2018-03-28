<?php

/**
 * @file
 * Contains a pre-process hook for 'field'.
 */

/**
 * Implements hook_preprocess_block().
 */
function landing_page_preprocess_field(&$variables) {
    $element = $variables['element'];
    $parent = $variables['element']['#object'];
    if($variables['element']['#field_name'] == 'field_embedded_benefits') {
        if(!empty($parent->field_benefit_style)) {
            $style = field_get_items($parent->entity_type, $parent, 'field_benefit_style');
            $style = $style[0]['value'];
            foreach ($variables['items'] as &$item) {
                foreach ($item['node'] as &$node) {
                    if (!empty($node) && is_array($node)) {
                        switch($style) {
                            case 'compact':
                                unset($node['body']);
                                break;
                        }
                    }
                }
            }
        }
    }
    
    if($variables['element']['#field_name'] == 'field_map_code') {
        foreach($variables['items'] as &$item){
            $code = $item['#markup'];
            if (preg_match('/src="([^\s"]+)/', $code, $s)) {
                $link = $s[1];
            }
            else {
                $link = $code;
            }
            
            $iframe = _sprowt_settings_map_embed_link_to_iframe($link);
            $item['#markup'] = $iframe;
        }
    }

    if($variables['element']['#field_name'] == 'field_starting_price') {
        $bundle = rabbit_hole_entity_get_bundle($parent->entity_type, $parent);
        $instance = field_info_instance($parent->entity_type, 'field_starting_price', $bundle);
        $prefix = $instance['settings']['prefix'];
        $suffix = $instance['settings']['suffix'];
            $prefix = explode(' ', $prefix);
            $pl = array_pop($prefix);
            if($pl != '$') {
                $prefix[] = $pl;
            }
            $prefix = implode(' ', $prefix);

        foreach($variables['items'] as &$item) {
            $item['#markup'] = str_replace($prefix, '<span class="prefix">' . $prefix . '</span>', $item['#markup']);
            $item['#markup'] = str_replace($suffix, '<span class="suffix">' . $suffix . '</span>', $item['#markup']);
            $item['#markup'] = str_replace('$', '<span class="dollar">$</span>', $item['#markup']);
        }
    }
}
