<?php

/**
 * Implements hook_preprocess_node().
 */
function sprowt_6_preprocess_node(&$variables) {
  $node = $variables['node'];

  // remove role attribute
  unset($variables['attributes_array']['role']);
  $variables['intro_title'] = FALSE;

  if (
    (!empty($variables['content']['field_display_title'][LANGUAGE_NONE][0])
      && !empty($variables['content']['field_intro'][LANGUAGE_NONE][0]))
    || (!empty($variables['content']['field_display_title'][0])
      && !empty($variables['content']['field_intro'][0]))
  )
  {
    $variables['intro_title'] = TRUE;
  }

  if($node->type == 'special_offer') {
      $nb = entity_metadata_wrapper('node', $node);
      $link = $nb->field_button->value();
      $variables['button_url'] = $link['url'];

      if(empty($variables['field_expiration_date'])) {
          $expiration_date = new DateTime('last day of this month');
          $expiration_date->setTime(12,0,0);
          $nb->field_expiration_date = $expiration_date->getTimestamp();
          $new_node = $nb->value();
          $field_view = field_view_field('node', $new_node, 'field_expiration_date', $variables['view_mode']);
          $variables['field_expiration_date'] = $new_node->field_expiration_date;
          $variables['content']['field_expiration_date'] = $field_view;
      }

  }

  if($node->type == 'package') {
      $info = field_info_instance('node', 'field_block_link', 'package');
      if(!empty($info)) {
          $nb = entity_metadata_wrapper('node', $node);
          $link = $nb->field_block_link->value();
          $variables['block_link_url'] = $link['url'];
      }
      else {
          $variables['block_link_url'] = $variables['node_url'];
      }
  }

    if($variables['view_mode'] == 'full' && empty($variables['page'])) {
        $variables['page'] = true; //this is false when logged in for some reason
    }

    if($node->type == 'localtarget') {
        $n = entity_metadata_wrapper('node', $node);
        if($variables['view_mode'] == 'hero') {
            $heroImage = $n->field_hero_image->value();
            $contentLocation = $n->field_content_location->value();
            $backgroundImageColor = $n->field_background_image_color->value();
            if(empty($backgroundImageColor)) {
                $backgroundImageColor = 'light';
            }
            $variables['classes_array'][] = 'background--' . $backgroundImageColor;
            if(!empty($contentLocation)) {
                $variables['classes_array'][] = 'content-' . $contentLocation;
            }
            else {
                $variables['classes_array'][] = 'content-center';
            }
            if(!empty($heroImage)) {
                global $base_url;
                if (!empty($variables["content"]["field_hero_image"][0]["#image_style"])) {
                    $heroImageUrl = image_style_url($variables["content"]["field_hero_image"][0]["#image_style"], $heroImage['uri']);
                }
                else {
                    $heroImageUrl = file_create_url($heroImage['uri']);
                }
                $heroImageUrl = str_replace($base_url, '', $heroImageUrl);
            }
            else {
                $heroImageUrl = '/' . drupal_get_path('profile', 'sprowt') . '/images/node_default/slideshow-placeholder.png';
            }

            if(!empty($variables['attributes_array']['style'])) {
                $style = explode(';', $variables['attributes_array']['style']);
            }
            else {
                $style = [];
            }
            $style[] = 'background-image: url(\''.$heroImageUrl.'\')';
            $variables['attributes_array']['style'] = implode(';', $style) . ';';
        }

    }

}
