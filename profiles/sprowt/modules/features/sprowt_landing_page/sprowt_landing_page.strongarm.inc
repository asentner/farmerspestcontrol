<?php
/**
 * @file
 * sprowt_landing_page.strongarm.inc
 */

/**
 * Implements hook_strongarm().
 */
function sprowt_landing_page_strongarm() {
  $export = array();

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'diff_enable_revisions_page_node_landing_page';
  $strongarm->value = 1;
  $export['diff_enable_revisions_page_node_landing_page'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'diff_show_preview_changes_node_landing_page';
  $strongarm->value = 1;
  $export['diff_show_preview_changes_node_landing_page'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'diff_view_mode_preview_node_landing_page';
  $strongarm->value = 'full';
  $export['diff_view_mode_preview_node_landing_page'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'field_bundle_settings_node__landing_page';
  $strongarm->value = array(
    'view_modes' => array(
      'alt_teaser' => array(
        'custom_settings' => TRUE,
      ),
      'teaser' => array(
        'custom_settings' => TRUE,
      ),
      'full' => array(
        'custom_settings' => FALSE,
      ),
      'rss' => array(
        'custom_settings' => FALSE,
      ),
      'search_index' => array(
        'custom_settings' => FALSE,
      ),
      'search_result' => array(
        'custom_settings' => FALSE,
      ),
      'diff_standard' => array(
        'custom_settings' => FALSE,
      ),
      'token' => array(
        'custom_settings' => FALSE,
      ),
      'secondary_teaser' => array(
        'custom_settings' => TRUE,
      ),
      'tertiary_teaser' => array(
        'custom_settings' => FALSE,
      ),
      'quaternary_teaser' => array(
        'custom_settings' => FALSE,
      ),
      'landing_page' => array(
        'custom_settings' => FALSE,
      ),
      'landing_page_compact' => array(
        'custom_settings' => FALSE,
      ),
    ),
    'extra_fields' => array(
      'form' => array(
        'metatags' => array(
          'weight' => '8',
        ),
        'title' => array(
          'weight' => '0',
        ),
        'path' => array(
          'weight' => '6',
        ),
        'rabbit_hole' => array(
          'weight' => '5',
        ),
        'xmlsitemap' => array(
          'weight' => '7',
        ),
      ),
      'display' => array(),
    ),
  );
  $export['field_bundle_settings_node__landing_page'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'menu_options_landing_page';
  $strongarm->value = array(
    0 => 'main-menu',
  );
  $export['menu_options_landing_page'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'menu_parent_landing_page';
  $strongarm->value = 'main-menu:0';
  $export['menu_parent_landing_page'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_options_landing_page';
  $strongarm->value = array(
    0 => 'status',
    1 => 'promote',
    2 => 'revision',
  );
  $export['node_options_landing_page'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_preview_landing_page';
  $strongarm->value = '1';
  $export['node_preview_landing_page'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_submitted_landing_page';
  $strongarm->value = 0;
  $export['node_submitted_landing_page'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'pathauto_node_landing_page_pattern';
  $strongarm->value = '';
  $export['pathauto_node_landing_page_pattern'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'themekey_attributes';
  $strongarm->value = array(
    'drupal:base_path' => array(
      'description' => 'Drupal: Base path - If Drupal is installed in a subdirectory, the base path will be \'/[subdirectory]/\', otherwise just \'/\'.',
      'page cache' => 1,
    ),
    'drupal:get_q' => array(
      'description' => 'Drupal: $_GET[\'q\'] - Current value of Drupal\'s query parameter "q"',
      'validator' => '',
      'page cache' => 1,
    ),
    'drupal:is_front_page' => array(
      'description' => 'Drupal: Is front page - \'true\' if current page is front page, otherwise just \'false\'.',
      'validator' => 'themekey_validator_string_boolean',
      'page cache' => 1,
    ),
    'drupal:path' => array(
      'description' => 'Drupal: Drupal path like "node/add/story" or path alias with support for wildcards.<br />
Query parameters are stripped off before the path gets examined. P.e. "node/add/story?destination=node" becomes "node/add/story" first. If you want to access query parameters, have a look at the <strong>system:query_param</strong> property.<br />
Wildcard characters are "#" for numeric parts and "%" for all characters. To match conditions against a certain part, use an identifier with the wildcard. For example "comment/reply/#xyz" matches all paths with "comment/reply" and a numeric third argument. You can then specify conditions for every wildcard argument using the property "drupal:path:wildcard" and the identifier you choose ("xyz" in this example).<br />
These are the possible wildcard replacements for foo/bar/42/test.html:<pre>
foo/bar/42/test.html
foo/bar/42/%
foo/bar/42
foo/bar/%/test.html
foo/bar/%/%
foo/bar/%
foo/bar/#/test.html
foo/bar/#/%
foo/bar/#
foo/bar
foo/%/42/test.html
foo/%/42/%
foo/%/42
foo/%/%/test.html
foo/%/%/%
foo/%/%
foo/%/#/test.html
foo/%/#/%
foo/%/#
foo/%
foo
%/bar/42/test.html
%/bar/42/%
%/bar/42
%/bar/%/test.html
%/bar/%/%
%/bar/%
%/bar/#/test.html
%/bar/#/%
%/bar/#
%/bar
%/%/42/test.html
%/%/42/%
%/%/42
%/%/%/test.html
%/%/%/%
%/%/%
%/%/#/test.html
%/%/#/%
%/%/#
%/%
%
</pre>',
      'validator' => 'themekey_validator_drupal_path',
      'page cache' => 1,
    ),
    'drupal:path:wildcard' => array(
      'description' => 'Wildcard of "drupal:path". See explanation of "drupal:path" for details.',
      'validator' => 'themekey_validator_wildcard',
      'page cache' => 1,
    ),
    'drupal:path_is_admin' => array(
      'description' => 'Drupal: Path is admin - \'true\' if current page\'s path belongs to the admin section, otherwise just \'false\'.',
      'validator' => 'themekey_validator_string_boolean',
      'page cache' => 1,
    ),
    'node:body_format' => array(
      'description' => 'Node: Field Value - The (simple scalar) value of the column <em class="placeholder">format</em> of the field <em class="placeholder">body</em>. The value will be converted in its string representation.',
      'page cache' => 1,
    ),
    'node:body_summary' => array(
      'description' => 'Node: Field Value - The (simple scalar) value of the column <em class="placeholder">summary</em> of the field <em class="placeholder">body</em>. The value will be converted in its string representation.',
      'page cache' => 1,
    ),
    'node:body_value' => array(
      'description' => 'Node: Field Value - The (simple scalar) value of the column <em class="placeholder">value</em> of the field <em class="placeholder">body</em>. The value will be converted in its string representation.',
      'page cache' => 1,
    ),
    'node:changed' => array(
      'description' => 'Node: Changed date - The date when the node was last edited/updated, formatted as unix timestamp like "1248873565".',
      'validator' => 'themekey_validator_ctype_digit',
      'page cache' => 1,
    ),
    'node:changed_date' => array(
      'description' => 'Node: Changed date - The date without the time when the node was last edited/updated, formatted like "2009-12-24"',
      'validator' => 'themekey_validator_date',
      'page cache' => 1,
    ),
    'node:changed_date_time' => array(
      'description' => 'Node: Changed date - The date including the time when the node was last edited/updated, formatted like "2009-12-24 18:13:24"',
      'validator' => 'themekey_validator_date_time',
      'page cache' => 1,
    ),
    'node:created' => array(
      'description' => 'Node: Created date - The date when the node was created, formatted as unix timestamp like "1248873565".',
      'validator' => 'themekey_validator_ctype_digit',
      'page cache' => 1,
    ),
    'node:created_date' => array(
      'description' => 'Node: Created date - The date without the time when the node was created, formatted like "2009-12-24"',
      'validator' => 'themekey_validator_date',
      'page cache' => 1,
    ),
    'node:created_date_time' => array(
      'description' => 'Node: Created date - The date including the time when the node was created, formatted like "2009-12-24 18:13:24"',
      'validator' => 'themekey_validator_date_time',
      'page cache' => 1,
    ),
    'node:field_address_label_format' => array(
      'description' => 'Node: Field Value - The (simple scalar) value of the column <em class="placeholder">format</em> of the field <em class="placeholder">field_address_label</em>. The value will be converted in its string representation.',
      'page cache' => 1,
    ),
    'node:field_address_label_value' => array(
      'description' => 'Node: Field Value - The (simple scalar) value of the column <em class="placeholder">value</em> of the field <em class="placeholder">field_address_label</em>. The value will be converted in its string representation.',
      'page cache' => 1,
    ),
    'node:field_attachments_description' => array(
      'description' => 'Node: Field Value - The (simple scalar) value of the column <em class="placeholder">description</em> of the field <em class="placeholder">field_attachments</em>. The value will be converted in its string representation.',
      'page cache' => 1,
    ),
    'node:field_attachments_display' => array(
      'description' => 'Node: Field Value - The (simple scalar) value of the column <em class="placeholder">display</em> of the field <em class="placeholder">field_attachments</em>. The value will be converted in its string representation.',
      'page cache' => 1,
    ),
    'node:field_attachments_fid' => array(
      'description' => 'Node: Field Value - The (simple scalar) value of the column <em class="placeholder">fid</em> of the field <em class="placeholder">field_attachments</em>. The value will be converted in its string representation.',
      'page cache' => 1,
    ),
    'node:field_block_link_attributes' => array(
      'description' => 'Node: Field Value - The (simple scalar) value of the column <em class="placeholder">attributes</em> of the field <em class="placeholder">field_block_link</em>. The value will be converted in its string representation.',
      'page cache' => 1,
    ),
    'node:field_block_link_title' => array(
      'description' => 'Node: Field Value - The (simple scalar) value of the column <em class="placeholder">title</em> of the field <em class="placeholder">field_block_link</em>. The value will be converted in its string representation.',
      'page cache' => 1,
    ),
    'node:field_block_link_url' => array(
      'description' => 'Node: Field Value - The (simple scalar) value of the column <em class="placeholder">url</em> of the field <em class="placeholder">field_block_link</em>. The value will be converted in its string representation.',
      'page cache' => 1,
    ),
    'node:field_button_attributes' => array(
      'description' => 'Node: Field Value - The (simple scalar) value of the column <em class="placeholder">attributes</em> of the field <em class="placeholder">field_button</em>. The value will be converted in its string representation.',
      'page cache' => 1,
    ),
    'node:field_button_title' => array(
      'description' => 'Node: Field Value - The (simple scalar) value of the column <em class="placeholder">title</em> of the field <em class="placeholder">field_button</em>. The value will be converted in its string representation.',
      'page cache' => 1,
    ),
    'node:field_button_url' => array(
      'description' => 'Node: Field Value - The (simple scalar) value of the column <em class="placeholder">url</em> of the field <em class="placeholder">field_button</em>. The value will be converted in its string representation.',
      'page cache' => 1,
    ),
    'node:field_call_out_format' => array(
      'description' => 'Node: Field Value - The (simple scalar) value of the column <em class="placeholder">format</em> of the field <em class="placeholder">field_call_out</em>. The value will be converted in its string representation.',
      'page cache' => 1,
    ),
    'node:field_call_out_value' => array(
      'description' => 'Node: Field Value - The (simple scalar) value of the column <em class="placeholder">value</em> of the field <em class="placeholder">field_call_out</em>. The value will be converted in its string representation.',
      'page cache' => 1,
    ),
    'node:field_color_rgb' => array(
      'description' => 'Node: Field Value - The (simple scalar) value of the column <em class="placeholder">rgb</em> of the field <em class="placeholder">field_color</em>. The value will be converted in its string representation.',
      'page cache' => 1,
    ),
    'node:field_colors_revision_id' => array(
      'description' => 'Node: Field Value - The (simple scalar) value of the column <em class="placeholder">revision_id</em> of the field <em class="placeholder">field_colors</em>. The value will be converted in its string representation.',
      'page cache' => 1,
    ),
    'node:field_colors_value' => array(
      'description' => 'Node: Field Value - The (simple scalar) value of the column <em class="placeholder">value</em> of the field <em class="placeholder">field_colors</em>. The value will be converted in its string representation.',
      'page cache' => 1,
    ),
    'node:field_content_edited_value' => array(
      'description' => 'Node: Field Value - The (simple scalar) value of the column <em class="placeholder">value</em> of the field <em class="placeholder">field_content_edited</em>. The value will be converted in its string representation.',
      'page cache' => 1,
    ),
    'node:field_content_revision_id' => array(
      'description' => 'Node: Field Value - The (simple scalar) value of the column <em class="placeholder">revision_id</em> of the field <em class="placeholder">field_content</em>. The value will be converted in its string representation.',
      'page cache' => 1,
    ),
    'node:field_content_value' => array(
      'description' => 'Node: Field Value - The (simple scalar) value of the column <em class="placeholder">value</em> of the field <em class="placeholder">field_content</em>. The value will be converted in its string representation.',
      'page cache' => 1,
    ),
    'node:field_display_title_format' => array(
      'description' => 'Node: Field Value - The (simple scalar) value of the column <em class="placeholder">format</em> of the field <em class="placeholder">field_display_title</em>. The value will be converted in its string representation.',
      'page cache' => 1,
    ),
    'node:field_display_title_value' => array(
      'description' => 'Node: Field Value - The (simple scalar) value of the column <em class="placeholder">value</em> of the field <em class="placeholder">field_display_title</em>. The value will be converted in its string representation.',
      'page cache' => 1,
    ),
    'node:field_email_format' => array(
      'description' => 'Node: Field Value - The (simple scalar) value of the column <em class="placeholder">format</em> of the field <em class="placeholder">field_email</em>. The value will be converted in its string representation.',
      'page cache' => 1,
    ),
    'node:field_email_value' => array(
      'description' => 'Node: Field Value - The (simple scalar) value of the column <em class="placeholder">value</em> of the field <em class="placeholder">field_email</em>. The value will be converted in its string representation.',
      'page cache' => 1,
    ),
    'node:field_expiration_date_value' => array(
      'description' => 'Node: Field Value - The (simple scalar) value of the column <em class="placeholder">value</em> of the field <em class="placeholder">field_expiration_date</em>. The value will be converted in its string representation.',
      'page cache' => 1,
    ),
    'node:field_features_tid' => array(
      'description' => 'Node: Field Value - The (simple scalar) value of the column <em class="placeholder">tid</em> of the field <em class="placeholder">field_features</em>. The value will be converted in its string representation.',
      'page cache' => 1,
    ),
    'node:field_footer_paragraph_revision_id' => array(
      'description' => 'Node: Field Value - The (simple scalar) value of the column <em class="placeholder">revision_id</em> of the field <em class="placeholder">field_footer_paragraph</em>. The value will be converted in its string representation.',
      'page cache' => 1,
    ),
    'node:field_footer_paragraph_value' => array(
      'description' => 'Node: Field Value - The (simple scalar) value of the column <em class="placeholder">value</em> of the field <em class="placeholder">field_footer_paragraph</em>. The value will be converted in its string representation.',
      'page cache' => 1,
    ),
    'node:field_google_url_format' => array(
      'description' => 'Node: Field Value - The (simple scalar) value of the column <em class="placeholder">format</em> of the field <em class="placeholder">field_google_url</em>. The value will be converted in its string representation.',
      'page cache' => 1,
    ),
    'node:field_google_url_value' => array(
      'description' => 'Node: Field Value - The (simple scalar) value of the column <em class="placeholder">value</em> of the field <em class="placeholder">field_google_url</em>. The value will be converted in its string representation.',
      'page cache' => 1,
    ),
    'node:field_header_paragraph_revision_id' => array(
      'description' => 'Node: Field Value - The (simple scalar) value of the column <em class="placeholder">revision_id</em> of the field <em class="placeholder">field_header_paragraph</em>. The value will be converted in its string representation.',
      'page cache' => 1,
    ),
    'node:field_header_paragraph_value' => array(
      'description' => 'Node: Field Value - The (simple scalar) value of the column <em class="placeholder">value</em> of the field <em class="placeholder">field_header_paragraph</em>. The value will be converted in its string representation.',
      'page cache' => 1,
    ),
    'node:field_hero_image_alt' => array(
      'description' => 'Node: Field Value - The (simple scalar) value of the column <em class="placeholder">alt</em> of the field <em class="placeholder">field_hero_image</em>. The value will be converted in its string representation.',
      'page cache' => 1,
    ),
    'node:field_hero_image_fid' => array(
      'description' => 'Node: Field Value - The (simple scalar) value of the column <em class="placeholder">fid</em> of the field <em class="placeholder">field_hero_image</em>. The value will be converted in its string representation.',
      'page cache' => 1,
    ),
    'node:field_hero_image_height' => array(
      'description' => 'Node: Field Value - The (simple scalar) value of the column <em class="placeholder">height</em> of the field <em class="placeholder">field_hero_image</em>. The value will be converted in its string representation.',
      'page cache' => 1,
    ),
    'node:field_hero_image_title' => array(
      'description' => 'Node: Field Value - The (simple scalar) value of the column <em class="placeholder">title</em> of the field <em class="placeholder">field_hero_image</em>. The value will be converted in its string representation.',
      'page cache' => 1,
    ),
    'node:field_hero_image_width' => array(
      'description' => 'Node: Field Value - The (simple scalar) value of the column <em class="placeholder">width</em> of the field <em class="placeholder">field_hero_image</em>. The value will be converted in its string representation.',
      'page cache' => 1,
    ),
    'node:field_highlight_icon_alt' => array(
      'description' => 'Node: Field Value - The (simple scalar) value of the column <em class="placeholder">alt</em> of the field <em class="placeholder">field_highlight_icon</em>. The value will be converted in its string representation.',
      'page cache' => 1,
    ),
    'node:field_highlight_icon_fid' => array(
      'description' => 'Node: Field Value - The (simple scalar) value of the column <em class="placeholder">fid</em> of the field <em class="placeholder">field_highlight_icon</em>. The value will be converted in its string representation.',
      'page cache' => 1,
    ),
    'node:field_highlight_icon_height' => array(
      'description' => 'Node: Field Value - The (simple scalar) value of the column <em class="placeholder">height</em> of the field <em class="placeholder">field_highlight_icon</em>. The value will be converted in its string representation.',
      'page cache' => 1,
    ),
    'node:field_highlight_icon_title' => array(
      'description' => 'Node: Field Value - The (simple scalar) value of the column <em class="placeholder">title</em> of the field <em class="placeholder">field_highlight_icon</em>. The value will be converted in its string representation.',
      'page cache' => 1,
    ),
    'node:field_highlight_icon_width' => array(
      'description' => 'Node: Field Value - The (simple scalar) value of the column <em class="placeholder">width</em> of the field <em class="placeholder">field_highlight_icon</em>. The value will be converted in its string representation.',
      'page cache' => 1,
    ),
    'node:field_highlight_value' => array(
      'description' => 'Node: Field Value - The (simple scalar) value of the column <em class="placeholder">value</em> of the field <em class="placeholder">field_highlight</em>. The value will be converted in its string representation.',
      'page cache' => 1,
    ),
    'node:field_hours_format' => array(
      'description' => 'Node: Field Value - The (simple scalar) value of the column <em class="placeholder">format</em> of the field <em class="placeholder">field_hours</em>. The value will be converted in its string representation.',
      'page cache' => 1,
    ),
    'node:field_hours_label_format' => array(
      'description' => 'Node: Field Value - The (simple scalar) value of the column <em class="placeholder">format</em> of the field <em class="placeholder">field_hours_label</em>. The value will be converted in its string representation.',
      'page cache' => 1,
    ),
    'node:field_hours_label_value' => array(
      'description' => 'Node: Field Value - The (simple scalar) value of the column <em class="placeholder">value</em> of the field <em class="placeholder">field_hours_label</em>. The value will be converted in its string representation.',
      'page cache' => 1,
    ),
    'node:field_hours_value' => array(
      'description' => 'Node: Field Value - The (simple scalar) value of the column <em class="placeholder">value</em> of the field <em class="placeholder">field_hours</em>. The value will be converted in its string representation.',
      'page cache' => 1,
    ),
    'node:field_icon_alt' => array(
      'description' => 'Node: Field Value - The (simple scalar) value of the column <em class="placeholder">alt</em> of the field <em class="placeholder">field_icon</em>. The value will be converted in its string representation.',
      'page cache' => 1,
    ),
    'node:field_icon_fid' => array(
      'description' => 'Node: Field Value - The (simple scalar) value of the column <em class="placeholder">fid</em> of the field <em class="placeholder">field_icon</em>. The value will be converted in its string representation.',
      'page cache' => 1,
    ),
    'node:field_icon_height' => array(
      'description' => 'Node: Field Value - The (simple scalar) value of the column <em class="placeholder">height</em> of the field <em class="placeholder">field_icon</em>. The value will be converted in its string representation.',
      'page cache' => 1,
    ),
    'node:field_icon_title' => array(
      'description' => 'Node: Field Value - The (simple scalar) value of the column <em class="placeholder">title</em> of the field <em class="placeholder">field_icon</em>. The value will be converted in its string representation.',
      'page cache' => 1,
    ),
    'node:field_icon_width' => array(
      'description' => 'Node: Field Value - The (simple scalar) value of the column <em class="placeholder">width</em> of the field <em class="placeholder">field_icon</em>. The value will be converted in its string representation.',
      'page cache' => 1,
    ),
    'node:field_image_alt' => array(
      'description' => 'Node: Field Value - The (simple scalar) value of the column <em class="placeholder">alt</em> of the field <em class="placeholder">field_image</em>. The value will be converted in its string representation.',
      'page cache' => 1,
    ),
    'node:field_image_fid' => array(
      'description' => 'Node: Field Value - The (simple scalar) value of the column <em class="placeholder">fid</em> of the field <em class="placeholder">field_image</em>. The value will be converted in its string representation.',
      'page cache' => 1,
    ),
    'node:field_image_height' => array(
      'description' => 'Node: Field Value - The (simple scalar) value of the column <em class="placeholder">height</em> of the field <em class="placeholder">field_image</em>. The value will be converted in its string representation.',
      'page cache' => 1,
    ),
    'node:field_image_insert_alt' => array(
      'description' => 'Node: Field Value - The (simple scalar) value of the column <em class="placeholder">alt</em> of the field <em class="placeholder">field_image_insert</em>. The value will be converted in its string representation.',
      'page cache' => 1,
    ),
    'node:field_image_insert_fid' => array(
      'description' => 'Node: Field Value - The (simple scalar) value of the column <em class="placeholder">fid</em> of the field <em class="placeholder">field_image_insert</em>. The value will be converted in its string representation.',
      'page cache' => 1,
    ),
    'node:field_image_insert_height' => array(
      'description' => 'Node: Field Value - The (simple scalar) value of the column <em class="placeholder">height</em> of the field <em class="placeholder">field_image_insert</em>. The value will be converted in its string representation.',
      'page cache' => 1,
    ),
    'node:field_image_insert_title' => array(
      'description' => 'Node: Field Value - The (simple scalar) value of the column <em class="placeholder">title</em> of the field <em class="placeholder">field_image_insert</em>. The value will be converted in its string representation.',
      'page cache' => 1,
    ),
    'node:field_image_insert_width' => array(
      'description' => 'Node: Field Value - The (simple scalar) value of the column <em class="placeholder">width</em> of the field <em class="placeholder">field_image_insert</em>. The value will be converted in its string representation.',
      'page cache' => 1,
    ),
    'node:field_image_title' => array(
      'description' => 'Node: Field Value - The (simple scalar) value of the column <em class="placeholder">title</em> of the field <em class="placeholder">field_image</em>. The value will be converted in its string representation.',
      'page cache' => 1,
    ),
    'node:field_image_width' => array(
      'description' => 'Node: Field Value - The (simple scalar) value of the column <em class="placeholder">width</em> of the field <em class="placeholder">field_image</em>. The value will be converted in its string representation.',
      'page cache' => 1,
    ),
    'node:field_initial_fee_format' => array(
      'description' => 'Node: Field Value - The (simple scalar) value of the column <em class="placeholder">format</em> of the field <em class="placeholder">field_initial_fee</em>. The value will be converted in its string representation.',
      'page cache' => 1,
    ),
    'node:field_initial_fee_value' => array(
      'description' => 'Node: Field Value - The (simple scalar) value of the column <em class="placeholder">value</em> of the field <em class="placeholder">field_initial_fee</em>. The value will be converted in its string representation.',
      'page cache' => 1,
    ),
    'node:field_intro_format' => array(
      'description' => 'Node: Field Value - The (simple scalar) value of the column <em class="placeholder">format</em> of the field <em class="placeholder">field_intro</em>. The value will be converted in its string representation.',
      'page cache' => 1,
    ),
    'node:field_intro_value' => array(
      'description' => 'Node: Field Value - The (simple scalar) value of the column <em class="placeholder">value</em> of the field <em class="placeholder">field_intro</em>. The value will be converted in its string representation.',
      'page cache' => 1,
    ),
    'node:field_landing_page_content_revision_id' => array(
      'description' => 'Node: Field Value - The (simple scalar) value of the column <em class="placeholder">revision_id</em> of the field <em class="placeholder">field_landing_page_content</em>. The value will be converted in its string representation.',
      'page cache' => 1,
    ),
    'node:field_landing_page_content_value' => array(
      'description' => 'Node: Field Value - The (simple scalar) value of the column <em class="placeholder">value</em> of the field <em class="placeholder">field_landing_page_content</em>. The value will be converted in its string representation.',
      'page cache' => 1,
    ),
    'node:field_link_attributes' => array(
      'description' => 'Node: Field Value - The (simple scalar) value of the column <em class="placeholder">attributes</em> of the field <em class="placeholder">field_link</em>. The value will be converted in its string representation.',
      'page cache' => 1,
    ),
    'node:field_link_title' => array(
      'description' => 'Node: Field Value - The (simple scalar) value of the column <em class="placeholder">title</em> of the field <em class="placeholder">field_link</em>. The value will be converted in its string representation.',
      'page cache' => 1,
    ),
    'node:field_link_url' => array(
      'description' => 'Node: Field Value - The (simple scalar) value of the column <em class="placeholder">url</em> of the field <em class="placeholder">field_link</em>. The value will be converted in its string representation.',
      'page cache' => 1,
    ),
    'node:field_local_content_format' => array(
      'description' => 'Node: Field Value - The (simple scalar) value of the column <em class="placeholder">format</em> of the field <em class="placeholder">field_local_content</em>. The value will be converted in its string representation.',
      'page cache' => 1,
    ),
    'node:field_local_content_value' => array(
      'description' => 'Node: Field Value - The (simple scalar) value of the column <em class="placeholder">value</em> of the field <em class="placeholder">field_local_content</em>. The value will be converted in its string representation.',
      'page cache' => 1,
    ),
    'node:field_locality_format' => array(
      'description' => 'Node: Field Value - The (simple scalar) value of the column <em class="placeholder">format</em> of the field <em class="placeholder">field_locality</em>. The value will be converted in its string representation.',
      'page cache' => 1,
    ),
    'node:field_locality_value' => array(
      'description' => 'Node: Field Value - The (simple scalar) value of the column <em class="placeholder">value</em> of the field <em class="placeholder">field_locality</em>. The value will be converted in its string representation.',
      'page cache' => 1,
    ),
    'node:field_map_code_format' => array(
      'description' => 'Node: Field Value - The (simple scalar) value of the column <em class="placeholder">format</em> of the field <em class="placeholder">field_map_code</em>. The value will be converted in its string representation.',
      'page cache' => 1,
    ),
    'node:field_map_code_value' => array(
      'description' => 'Node: Field Value - The (simple scalar) value of the column <em class="placeholder">value</em> of the field <em class="placeholder">field_map_code</em>. The value will be converted in its string representation.',
      'page cache' => 1,
    ),
    'node:field_market_tid' => array(
      'description' => 'Node: Field Value - The (simple scalar) value of the column <em class="placeholder">tid</em> of the field <em class="placeholder">field_market</em>. The value will be converted in its string representation.',
      'page cache' => 1,
    ),
    'node:field_offer_headline_format' => array(
      'description' => 'Node: Field Value - The (simple scalar) value of the column <em class="placeholder">format</em> of the field <em class="placeholder">field_offer_headline</em>. The value will be converted in its string representation.',
      'page cache' => 1,
    ),
    'node:field_offer_headline_value' => array(
      'description' => 'Node: Field Value - The (simple scalar) value of the column <em class="placeholder">value</em> of the field <em class="placeholder">field_offer_headline</em>. The value will be converted in its string representation.',
      'page cache' => 1,
    ),
    'node:field_offer_price_value' => array(
      'description' => 'Node: Field Value - The (simple scalar) value of the column <em class="placeholder">value</em> of the field <em class="placeholder">field_offer_price</em>. The value will be converted in its string representation.',
      'page cache' => 1,
    ),
    'node:field_offer_subheadline_format' => array(
      'description' => 'Node: Field Value - The (simple scalar) value of the column <em class="placeholder">format</em> of the field <em class="placeholder">field_offer_subheadline</em>. The value will be converted in its string representation.',
      'page cache' => 1,
    ),
    'node:field_offer_subheadline_value' => array(
      'description' => 'Node: Field Value - The (simple scalar) value of the column <em class="placeholder">value</em> of the field <em class="placeholder">field_offer_subheadline</em>. The value will be converted in its string representation.',
      'page cache' => 1,
    ),
    'node:field_original_price_value' => array(
      'description' => 'Node: Field Value - The (simple scalar) value of the column <em class="placeholder">value</em> of the field <em class="placeholder">field_original_price</em>. The value will be converted in its string representation.',
      'page cache' => 1,
    ),
    'node:field_package_colors_rgb' => array(
      'description' => 'Node: Field Value - The (simple scalar) value of the column <em class="placeholder">rgb</em> of the field <em class="placeholder">field_package_colors</em>. The value will be converted in its string representation.',
      'page cache' => 1,
    ),
    'node:field_package_features_tid' => array(
      'description' => 'Node: Field Value - The (simple scalar) value of the column <em class="placeholder">tid</em> of the field <em class="placeholder">field_package_features</em>. The value will be converted in its string representation.',
      'page cache' => 1,
    ),
    'node:field_package_intro_format' => array(
      'description' => 'Node: Field Value - The (simple scalar) value of the column <em class="placeholder">format</em> of the field <em class="placeholder">field_package_intro</em>. The value will be converted in its string representation.',
      'page cache' => 1,
    ),
    'node:field_package_intro_value' => array(
      'description' => 'Node: Field Value - The (simple scalar) value of the column <em class="placeholder">value</em> of the field <em class="placeholder">field_package_intro</em>. The value will be converted in its string representation.',
      'page cache' => 1,
    ),
    'node:field_package_target_id' => array(
      'description' => 'Node: Field Value - The (simple scalar) value of the column <em class="placeholder">target_id</em> of the field <em class="placeholder">field_package</em>. The value will be converted in its string representation.',
      'page cache' => 1,
    ),
    'node:field_packages_intro_format' => array(
      'description' => 'Node: Field Value - The (simple scalar) value of the column <em class="placeholder">format</em> of the field <em class="placeholder">field_packages_intro</em>. The value will be converted in its string representation.',
      'page cache' => 1,
    ),
    'node:field_packages_intro_value' => array(
      'description' => 'Node: Field Value - The (simple scalar) value of the column <em class="placeholder">value</em> of the field <em class="placeholder">field_packages_intro</em>. The value will be converted in its string representation.',
      'page cache' => 1,
    ),
    'node:field_packages_revision_id' => array(
      'description' => 'Node: Field Value - The (simple scalar) value of the column <em class="placeholder">revision_id</em> of the field <em class="placeholder">field_packages</em>. The value will be converted in its string representation.',
      'page cache' => 1,
    ),
    'node:field_packages_title_format' => array(
      'description' => 'Node: Field Value - The (simple scalar) value of the column <em class="placeholder">format</em> of the field <em class="placeholder">field_packages_title</em>. The value will be converted in its string representation.',
      'page cache' => 1,
    ),
    'node:field_packages_title_value' => array(
      'description' => 'Node: Field Value - The (simple scalar) value of the column <em class="placeholder">value</em> of the field <em class="placeholder">field_packages_title</em>. The value will be converted in its string representation.',
      'page cache' => 1,
    ),
    'node:field_packages_value' => array(
      'description' => 'Node: Field Value - The (simple scalar) value of the column <em class="placeholder">value</em> of the field <em class="placeholder">field_packages</em>. The value will be converted in its string representation.',
      'page cache' => 1,
    ),
    'node:field_phone_label_format' => array(
      'description' => 'Node: Field Value - The (simple scalar) value of the column <em class="placeholder">format</em> of the field <em class="placeholder">field_phone_label</em>. The value will be converted in its string representation.',
      'page cache' => 1,
    ),
    'node:field_phone_label_value' => array(
      'description' => 'Node: Field Value - The (simple scalar) value of the column <em class="placeholder">value</em> of the field <em class="placeholder">field_phone_label</em>. The value will be converted in its string representation.',
      'page cache' => 1,
    ),
    'node:field_phone_number_value' => array(
      'description' => 'Node: Field Value - The (simple scalar) value of the column <em class="placeholder">value</em> of the field <em class="placeholder">field_phone_number</em>. The value will be converted in its string representation.',
      'page cache' => 1,
    ),
    'node:field_position_format' => array(
      'description' => 'Node: Field Value - The (simple scalar) value of the column <em class="placeholder">format</em> of the field <em class="placeholder">field_position</em>. The value will be converted in its string representation.',
      'page cache' => 1,
    ),
    'node:field_position_value' => array(
      'description' => 'Node: Field Value - The (simple scalar) value of the column <em class="placeholder">value</em> of the field <em class="placeholder">field_position</em>. The value will be converted in its string representation.',
      'page cache' => 1,
    ),
    'node:field_post_date_value' => array(
      'description' => 'Node: Field Value - The (simple scalar) value of the column <em class="placeholder">value</em> of the field <em class="placeholder">field_post_date</em>. The value will be converted in its string representation.',
      'page cache' => 1,
    ),
    'node:field_postal_code_format' => array(
      'description' => 'Node: Field Value - The (simple scalar) value of the column <em class="placeholder">format</em> of the field <em class="placeholder">field_postal_code</em>. The value will be converted in its string representation.',
      'page cache' => 1,
    ),
    'node:field_postal_code_value' => array(
      'description' => 'Node: Field Value - The (simple scalar) value of the column <em class="placeholder">value</em> of the field <em class="placeholder">field_postal_code</em>. The value will be converted in its string representation.',
      'page cache' => 1,
    ),
    'node:field_region_tid' => array(
      'description' => 'Node: Field Value - The (simple scalar) value of the column <em class="placeholder">tid</em> of the field <em class="placeholder">field_region</em>. The value will be converted in its string representation.',
      'page cache' => 1,
    ),
    'node:field_seo_title_format' => array(
      'description' => 'Node: Field Value - The (simple scalar) value of the column <em class="placeholder">format</em> of the field <em class="placeholder">field_seo_title</em>. The value will be converted in its string representation.',
      'page cache' => 1,
    ),
    'node:field_seo_title_value' => array(
      'description' => 'Node: Field Value - The (simple scalar) value of the column <em class="placeholder">value</em> of the field <em class="placeholder">field_seo_title</em>. The value will be converted in its string representation.',
      'page cache' => 1,
    ),
    'node:field_service_tid' => array(
      'description' => 'Node: Field Value - The (simple scalar) value of the column <em class="placeholder">tid</em> of the field <em class="placeholder">field_service</em>. The value will be converted in its string representation.',
      'page cache' => 1,
    ),
    'node:field_services_tid' => array(
      'description' => 'Node: Field Value - The (simple scalar) value of the column <em class="placeholder">tid</em> of the field <em class="placeholder">field_services</em>. The value will be converted in its string representation.',
      'page cache' => 1,
    ),
    'node:field_social_reviews_attributes' => array(
      'description' => 'Node: Field Value - The (simple scalar) value of the column <em class="placeholder">attributes</em> of the field <em class="placeholder">field_social_reviews</em>. The value will be converted in its string representation.',
      'page cache' => 1,
    ),
    'node:field_social_reviews_title' => array(
      'description' => 'Node: Field Value - The (simple scalar) value of the column <em class="placeholder">title</em> of the field <em class="placeholder">field_social_reviews</em>. The value will be converted in its string representation.',
      'page cache' => 1,
    ),
    'node:field_social_reviews_url' => array(
      'description' => 'Node: Field Value - The (simple scalar) value of the column <em class="placeholder">url</em> of the field <em class="placeholder">field_social_reviews</em>. The value will be converted in its string representation.',
      'page cache' => 1,
    ),
    'node:field_starting_price_value' => array(
      'description' => 'Node: Field Value - The (simple scalar) value of the column <em class="placeholder">value</em> of the field <em class="placeholder">field_starting_price</em>. The value will be converted in its string representation.',
      'page cache' => 1,
    ),
    'node:field_state_format' => array(
      'description' => 'Node: Field Value - The (simple scalar) value of the column <em class="placeholder">format</em> of the field <em class="placeholder">field_state</em>. The value will be converted in its string representation.',
      'page cache' => 1,
    ),
    'node:field_state_value' => array(
      'description' => 'Node: Field Value - The (simple scalar) value of the column <em class="placeholder">value</em> of the field <em class="placeholder">field_state</em>. The value will be converted in its string representation.',
      'page cache' => 1,
    ),
    'node:field_street_address_format' => array(
      'description' => 'Node: Field Value - The (simple scalar) value of the column <em class="placeholder">format</em> of the field <em class="placeholder">field_street_address</em>. The value will be converted in its string representation.',
      'page cache' => 1,
    ),
    'node:field_street_address_value' => array(
      'description' => 'Node: Field Value - The (simple scalar) value of the column <em class="placeholder">value</em> of the field <em class="placeholder">field_street_address</em>. The value will be converted in its string representation.',
      'page cache' => 1,
    ),
    'node:field_subtitle_format' => array(
      'description' => 'Node: Field Value - The (simple scalar) value of the column <em class="placeholder">format</em> of the field <em class="placeholder">field_subtitle</em>. The value will be converted in its string representation.',
      'page cache' => 1,
    ),
    'node:field_subtitle_value' => array(
      'description' => 'Node: Field Value - The (simple scalar) value of the column <em class="placeholder">value</em> of the field <em class="placeholder">field_subtitle</em>. The value will be converted in its string representation.',
      'page cache' => 1,
    ),
    'node:field_table_link_attributes' => array(
      'description' => 'Node: Field Value - The (simple scalar) value of the column <em class="placeholder">attributes</em> of the field <em class="placeholder">field_table_link</em>. The value will be converted in its string representation.',
      'page cache' => 1,
    ),
    'node:field_table_link_title' => array(
      'description' => 'Node: Field Value - The (simple scalar) value of the column <em class="placeholder">title</em> of the field <em class="placeholder">field_table_link</em>. The value will be converted in its string representation.',
      'page cache' => 1,
    ),
    'node:field_table_link_url' => array(
      'description' => 'Node: Field Value - The (simple scalar) value of the column <em class="placeholder">url</em> of the field <em class="placeholder">field_table_link</em>. The value will be converted in its string representation.',
      'page cache' => 1,
    ),
    'node:field_tags_tid' => array(
      'description' => 'Node: Field Value - The (simple scalar) value of the column <em class="placeholder">tid</em> of the field <em class="placeholder">field_tags</em>. The value will be converted in its string representation.',
      'page cache' => 1,
    ),
    'node:language' => array(
      'description' => 'Node: Language - The code of the selected language of a node (formatted like "en" or "de") or "neutral". See <a href="/admin/config/language">admin/config/language</a> for the codes of your enabled languages',
      'validator' => 'themekey_validator_language',
      'page cache' => 1,
    ),
    'node:nid' => array(
      'description' => 'Node: ID - The id of a node (nid), can be found in the URL of the node, "node/23" or "node/23/edit" (23 = nid)',
      'validator' => 'themekey_validator_ctype_digit',
      'page cache' => 1,
    ),
    'node:promote' => array(
      'description' => 'Node: Promoted - If the node is promoted to the front page. Possible values are "0" for true and "1" for false.',
      'validator' => 'themekey_validator_numeric_boolean',
      'page cache' => 1,
    ),
    'node:sticky' => array(
      'description' => 'Node: Sticky - If the node is set "Sticky at top of lists". Possible values are "0" for true and "1" for false.',
      'validator' => 'themekey_validator_numeric_boolean',
      'page cache' => 1,
    ),
    'node:title' => array(
      'description' => 'Node: Title - The title of the node.',
      'page cache' => 1,
    ),
    'node:type' => array(
      'description' => 'Node: Type - The machine-readable content type of the node. See <a href="/admin/structure/types">admin/structure/types</a> for your content types (use column "Type"). Drupal default types are "page" and "story".',
      'validator' => 'themekey_validator_node_type',
      'page cache' => 1,
    ),
    'node:uid' => array(
      'description' => 'Node: User ID - The node author\'s user id (uid). The user id can be found in the URL of the user\'s profile page, "user/23" or "user/23/edit" (23 = uid). See <a href="/admin/user/user/list">admin/user/user/list</a> for your users.',
      'validator' => 'themekey_validator_ctype_digit',
      'page cache' => 1,
    ),
    'node:vid' => array(
      'description' => 'Node: The version id of a node (vid), mostly for internal use within ThemeKey. In most cases it\'s better to use node:nid within your rule chains.',
      'validator' => 'themekey_validator_ctype_digit',
      'page cache' => 1,
    ),
    'path:node_alias' => array(
      'description' => 'Path: Node alias - The path alias assigned to a node.',
      'validator' => '',
      'page cache' => 1,
    ),
    'system:cookie' => array(
      'description' => 'System: Cookie - Every single cookie and its value if present will be formatted like \'COOKIE_NAME=COOKIE_VALUE\'',
      'page cache' => 0,
    ),
    'system:date' => array(
      'description' => 'System: Date - Current time formatted as Y-m-d (example: 2009-12-24)',
      'validator' => 'themekey_validator_date',
      'page cache' => 2,
    ),
    'system:date_time' => array(
      'description' => 'System: Date Time - Current time formatted as Y-m-d H:i:s (example: 2009-12-24 18:30:10)',
      'validator' => 'themekey_validator_date_time',
      'page cache' => 2,
    ),
    'system:day_of_month' => array(
      'description' => 'System: Day of Month - Current day of the month formatted as 1 - 31',
      'validator' => 'themekey_validator_day_of_month',
      'page cache' => 2,
    ),
    'system:day_of_week' => array(
      'description' => 'System: Day of Week - Current day of the week formatted as three letters \'Mon\' through \'Sun\'',
      'validator' => 'themekey_validator_day_of_week',
      'page cache' => 2,
    ),
    'system:dummy' => array(
      'description' => 'System: Dummy - Dummy property. Value is always \'dummy\'',
      'page cache' => 1,
    ),
    'system:host' => array(
      'description' => 'System: HTTP_HOST - The hostname/domain of the site without http:// or https://, like "www.drupal.org" or "www.biologis.com"',
      'validator' => 'themekey_validator_http_host',
      'page cache' => 1,
    ),
    'system:http_header' => array(
      'description' => 'System: HTTP Header - Every single HTTP header and its value if present will be formatted like \'HEADER_NAME=HEADER_VALUE\'',
      'page cache' => 0,
    ),
    'system:https' => array(
      'description' => 'System: \'HTTPS\' - Set to \'true\' value if the script was queried through the HTTPS protocol, otherwise \'false\'.',
      'validator' => 'themekey_validator_string_boolean',
      'page cache' => 1,
    ),
    'system:month' => array(
      'description' => 'System: Month - Current month formatted as \'Jan\' through \'Dec\'',
      'validator' => 'themekey_validator_month',
      'page cache' => 2,
    ),
    'system:post' => array(
      'description' => 'System: POST - Every single POST value formatted like \'POST_VARIABLE_NAME=POST_VARIABLE_VALUE\'. Example: form_id=node_form. If the POST value is not a scalar but a complex type like array or object, the resulting string is formatted as \'POST_VARIABLE_NAME\' without a value.',
      'page cache' => 0,
    ),
    'system:query_param' => array(
      'description' => 'System: Query Parameter - Every single query parameter other than \'q\' and its value, if present. Note that values are url decoded. Example: \'?q=node&foo=bar&dummy&filter=tid%3A27\' will cause three entries \'foo=bar\', \'dummy\' and \'filter=tid:27\'. For \'q\', see property drupal:get_q.',
      'page cache' => 1,
    ),
    'system:query_string' => array(
      'description' => 'System: Query String - Complete query string except parameter \'q\'. Example: \'?q=node&foo=bar&dummy&filter=tid%3A27\' will result in \'foo=bar&dummy&filter=tid%3A27\'. For \'q\' see property drupal:get_q.',
      'page cache' => 1,
    ),
    'system:random' => array(
      'description' => 'System: Random - A random value that could be \'0\' or 1\'.',
      'validator' => 'themekey_validator_numeric_boolean',
      'page cache' => 0,
    ),
    'system:referer' => array(
      'description' => 'System: \'HTTP_REFERER\' - The address of the page (if any) which referred the user agent to the current page. This is set by the user agent. Not all user agents will set this, and some provide the ability to modify HTTP_REFERER as a feature. In short, it cannot really be trusted.',
      'page cache' => 0,
    ),
    'system:remote_ip' => array(
      'description' => 'System: \'REMOTE_ADDR\' - The IP address from which the user is viewing the current page.',
      'validator' => 'themekey_validator_ip_address',
      'page cache' => 0,
    ),
    'system:server_ip' => array(
      'description' => 'System: \'SERVER_ADDR\' - The IP address of the server under which the current script is executing.',
      'validator' => 'themekey_validator_ip_address',
      'page cache' => 0,
    ),
    'system:server_name' => array(
      'description' => 'System:  \'SERVER_NAME\' - The name of the server host under which the current script is executing. If the script is running on a virtual host, this will be the value defined for that virtual host.',
      'page cache' => 0,
    ),
    'system:server_port' => array(
      'description' => 'System: \'SERVER_PORT\' - The port on the server machine being used by the web server for communication. For default setups, this will be \'80\'; using SSL, for instance, will change this to whatever your defined secure HTTP port is.',
      'validator' => 'themekey_validator_ctype_digit',
      'page cache' => 0,
    ),
    'system:session' => array(
      'description' => 'System: Session - Every single session parameter and its value, if a value is present and a simple type (string, integer, boolean). Booleans are represented as integers; \'1\' as TRUE and \'0\' as FALSE.',
      'page cache' => 1,
    ),
    'system:time' => array(
      'description' => 'System: Time - Current time formatted as H:i:s (example: 18:30:10)',
      'validator' => 'themekey_validator_time',
      'page cache' => 2,
    ),
    'system:user_agent' => array(
      'description' => 'System: \'HTTP_USER_AGENT\' - Contents of the User-Agent: header from the current request, if there is one. This is a string denoting the user agent which is accessing the page. A typical example is: Mozilla/4.5 [en] (X11; U; Linux 2.2.9 i586).',
      'page cache' => 0,
    ),
    'system:user_browser' => array(
      'description' => 'System: Browser - Information about user\'s browser. Possible values: \'Blazer [VERSION]\', \'Internet Explorer [VERSION]\', \'Internet Explorer Mobile [VERSION]\', \'Mozilla Firefox [VERSION]\', \'Netscape [VERSION]\', \'Google Chrome [VERSION]\', \'Safari [VERSION]\', \'Galeon [VERSION]\', \'Konqueror [VERSION]\', \'Gecko based\', \'Opera [VERSION]\', \'Lynx [VERSION]\', \'Fennec [VERSION]\', \'Maemo [VERSION]\', \'unknown\'',
      'page cache' => 0,
      'deprecated' => TRUE,
      'deprecated message' => 'Property system:user_browser is deprecated. Consider to use one of the new properties ThemeKey provides in combination with <a href="https://drupal.org/project/browscap">Browscap</a>, <a href="https://drupal.org/project/mobile_detect_api">Mobile Detect API</a>, or <a href="https://drupal.org/project/mobile_detect_api">Mobile Detect</a>.',
    ),
    'system:user_browser_simplified' => array(
      'description' => 'System: Browser - Simplified information about user\'s browser. Possible values: \'Blazer\', \'Internet Explorer\', \'Internet Explorer Mobile\', \'Mozilla Firefox\', \'Netscape\', \'Google Chrome\', \'Safari\', \'Galeon\', \'Konqueror\', \'Gecko based\', \'Opera\', \'Lynx\', \'Fennec\', \'Maemo\', \'unknown\'',
      'page cache' => 0,
      'deprecated' => TRUE,
      'deprecated message' => 'Property system:user_browser_simplified is deprecated. Consider to use one of the new properties ThemeKey provides in combination with <a href="https://drupal.org/project/browscap">Browscap</a>, <a href="https://drupal.org/project/mobile_detect_api">Mobile Detect API</a>, or <a href="https://drupal.org/project/mobile_detect_api">Mobile Detect</a>.',
    ),
    'system:user_os' => array(
      'description' => 'System: Operating System - Information about user\'s browser. Possible values: \'Windows XP\', \'Windows Vista\', \'Windows 98\', \'Windows 2000\', \'Windows 2003 server\', \'Windows NT\',  \'Windows ME\', \'Windows CE\', \'Windows ME\', \'Windows Phone\', \'iPhone\', \'iPad\', \'Mac OS X\', \'Macintosh\', \'Linux\', \'Free BSD\', \'Symbian\', \'webOS\', \'Android\', \'Blackberry\', \'unknown\'',
      'page cache' => 0,
      'deprecated' => TRUE,
      'deprecated message' => 'Property system:user_os is deprecated. Consider to use one of the new properties ThemeKey provides in combination with <a href="https://drupal.org/project/browscap">Browscap</a>, <a href="https://drupal.org/project/mobile_detect_api">Mobile Detect API</a>, or <a href="https://drupal.org/project/mobile_detect_api">Mobile Detect</a>.',
    ),
    'system:user_os_simplified' => array(
      'description' => 'System: Operating System - Simplified information about user\'s browser. Possible values: \'Windows\', \'Windows Phone\', \'iPhone\', \'iPad\', \'Mac OS X\', \'Macintosh\', \'Linux\', \'Free BSD\', \'Symbian\', \'webOS\', \'Android\', \'Blackberry\', \'unknown\'',
      'page cache' => 0,
      'deprecated' => TRUE,
      'deprecated message' => 'Property system:user_os_simplified is deprecated. Consider to use one of the new properties ThemeKey provides in combination with <a href="https://drupal.org/project/browscap">Browscap</a>, <a href="https://drupal.org/project/mobile_detect_api">Mobile Detect API</a>, or <a href="https://drupal.org/project/mobile_detect_api">Mobile Detect</a>.',
    ),
    'taxonomy:name' => array(
      'description' => 'Taxonomy: Name - The term name (name) of a taxonomy term without support for translations.',
      'validator' => '',
      'page cache' => 1,
    ),
    'taxonomy:tid' => array(
      'description' => 'Taxonomy: Term - The term id (tid) of a taxonomy term.',
      'validator' => 'themekey_validator_ctype_digit',
      'page cache' => 1,
    ),
    'taxonomy:tid_and_childs' => array(
      'description' => 'Taxonomy: Term and its childs - The term id (tid) of a taxonomy term. If set, all child terms of this term will be used too.',
      'validator' => 'themekey_validator_ctype_digit',
      'page cache' => 0,
    ),
    'taxonomy:vid' => array(
      'description' => 'Taxonomy: Vocabulary - The vocabulary id (vid) of a taxonomy vocabulary. See <a href="/admin/structure/taxonomy">admin/structure/taxonomy</a> for your vocabularies.',
      'validator' => 'themekey_validator_ctype_digit',
      'page cache' => 1,
    ),
    'user:hostname' => array(
      'description' => 'User: Hostname - The user hostname property which is the IP address of client machine, adjusted for reverse proxy. Text from Drupal bootstrap.inc:
      If Drupal is behind a reverse proxy, we use the X-Forwarded-For header instead of $_SERVER[\'REMOTE_ADDR\'], which would be the IP address of the proxy server, and not the client\'s.',
      'validator' => 'themekey_validator_http_host',
      'page cache' => 0,
    ),
    'user:language' => array(
      'description' => 'User: Language - The language the user has set in the settings of his profile page.
      Format is the language code (for example "en" for English or "de" for German) that can be found on <a href="/admin/config/regional/language/overview">admin/config/regional/language/overview</a>.',
      'validator' => 'themekey_validator_language',
      'page cache' => 1,
    ),
    'user:name' => array(
      'description' => 'User: Name - The username of the user. See <a href="/admin/people/people">admin/people/people</a> for your users.',
      'page cache' => 1,
    ),
    'user:role' => array(
      'description' => 'User: Role - Defined user roles (examples: \'anonymous user\', \'authenticated user\')',
      'validator' => 'themekey_validator_role',
      'page cache' => 1,
    ),
    'user:uid' => array(
      'description' => 'User: ID - The id of the user (uid). The user id can be found in the URL of the users profile page, "user/23" or "user/23/edit" (23 = uid). See <a href="/admin/people/people">admin/people/people</a> for your users.',
      'validator' => 'themekey_validator_ctype_digit',
      'page cache' => 1,
    ),
    'views:human_name' => array(
      'description' => 'Views: Human Name - The (human readable) name of a view',
      'page cache' => 1,
    ),
    'views:machine_name' => array(
      'description' => 'Views: Machine Name - The machine name of a view',
      'page cache' => 1,
    ),
    'views:vid' => array(
      'description' => 'Views: VID - The vid of a view (vid)',
      'validator' => 'themekey_validator_ctype_digit',
      'page cache' => 1,
    ),
  );
  $export['themekey_attributes'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'themekey_maps';
  $strongarm->value = array(
    0 => array(
      'src' => 'node:nid',
      'dst' => 'path:node_alias',
      'callback' => 'themekey_path_nid2alias',
    ),
    1 => array(
      'src' => 'system:dummy',
      'dst' => 'system:query_param',
      'callback' => 'themekey_dummy2query_param',
    ),
    2 => array(
      'src' => 'system:dummy',
      'dst' => 'system:cookie',
      'callback' => 'themekey_dummy2cookie',
    ),
    3 => array(
      'src' => 'system:dummy',
      'dst' => 'system:http_header',
      'callback' => 'themekey_dummy2http_header',
    ),
    4 => array(
      'src' => 'system:dummy',
      'dst' => 'system:post',
      'callback' => 'themekey_dummy2post',
    ),
    5 => array(
      'src' => 'system:dummy',
      'dst' => 'system:query_string',
      'callback' => 'themekey_dummy2query_string',
    ),
    6 => array(
      'src' => 'system:dummy',
      'dst' => 'system:date_time',
      'callback' => 'themekey_dummy2date_time',
    ),
    7 => array(
      'src' => 'system:dummy',
      'dst' => 'system:date',
      'callback' => 'themekey_dummy2date',
    ),
    8 => array(
      'src' => 'system:dummy',
      'dst' => 'system:month',
      'callback' => 'themekey_dummy2month',
    ),
    9 => array(
      'src' => 'system:dummy',
      'dst' => 'system:time',
      'callback' => 'themekey_dummy2time',
    ),
    10 => array(
      'src' => 'system:dummy',
      'dst' => 'system:day_of_week',
      'callback' => 'themekey_dummy2day_of_week',
    ),
    11 => array(
      'src' => 'system:dummy',
      'dst' => 'system:day_of_month',
      'callback' => 'themekey_dummy2day_of_month',
    ),
    12 => array(
      'src' => 'system:dummy',
      'dst' => 'system:user_browser',
      'callback' => 'themekey_dummy2user_browser',
    ),
    13 => array(
      'src' => 'system:dummy',
      'dst' => 'system:user_os',
      'callback' => 'themekey_dummy2user_os',
    ),
    14 => array(
      'src' => 'system:user_browser',
      'dst' => 'system:user_browser_simplified',
      'callback' => 'themekey_user_browser2user_browser_simplified',
    ),
    15 => array(
      'src' => 'system:user_os',
      'dst' => 'system:user_os_simplified',
      'callback' => 'themekey_user_os2user_os_simplified',
    ),
    16 => array(
      'src' => 'system:dummy',
      'dst' => 'system:session',
      'callback' => 'themekey_dummy2session',
    ),
    17 => array(
      'src' => 'taxonomy:tid',
      'dst' => 'taxonomy:vid',
      'callback' => 'themekey_taxonomy_tid2vid',
    ),
    18 => array(
      'src' => 'taxonomy:tid',
      'dst' => 'taxonomy:tid_and_childs',
      'callback' => 'themekey_taxonomy_tid2tid_and_parents',
    ),
    19 => array(
      'src' => 'node:nid',
      'dst' => 'taxonomy:tid',
      'callback' => 'themekey_taxonomy_nid2tid',
    ),
    20 => array(
      'src' => 'taxonomy:tid',
      'dst' => 'taxonomy:name',
      'callback' => 'themekey_taxonomy_tid2name',
    ),
    21 => array(
      'src' => 'drupal:get_q',
      'dst' => 'views:vid',
      'callback' => 'themekey_views_getq2vid',
    ),
    22 => array(
      'src' => 'drupal:get_q',
      'dst' => 'views:machine_name',
      'callback' => 'themekey_views_getq2machine_name',
    ),
    23 => array(
      'src' => 'drupal:get_q',
      'dst' => 'views:human_name',
      'callback' => 'themekey_views_getq2human_name',
    ),
    24 => array(
      'src' => 'profile:uid',
      'dst' => 'themekey_ui:author_triggers_theme',
      'callback' => 'themekey_user_profile2theme',
    ),
    25 => array(
      'src' => 'node:nid',
      'dst' => 'node:changed',
      'callback' => 'themekey_node_nid2changed',
    ),
    26 => array(
      'src' => 'node:nid',
      'dst' => 'node:created',
      'callback' => 'themekey_node_nid2created',
    ),
    27 => array(
      'src' => 'node:changed',
      'dst' => 'node:changed_date_time',
      'callback' => 'themekey_node_timestamp2datetime',
    ),
    28 => array(
      'src' => 'node:created',
      'dst' => 'node:created_date_time',
      'callback' => 'themekey_node_timestamp2datetime',
    ),
    29 => array(
      'src' => 'node:changed',
      'dst' => 'node:changed_date',
      'callback' => 'themekey_node_timestamp2date',
    ),
    30 => array(
      'src' => 'node:created',
      'dst' => 'node:created_date',
      'callback' => 'themekey_node_timestamp2date',
    ),
    31 => array(
      'src' => 'node:nid',
      'dst' => 'node:language',
      'callback' => 'themekey_node_nid2language',
    ),
    32 => array(
      'src' => 'node:nid',
      'dst' => 'node:vid',
      'callback' => 'themekey_node_nid2vid',
    ),
    33 => array(
      'src' => 'node:nid',
      'dst' => 'node:promote',
      'callback' => 'themekey_node_nid2promote',
    ),
    34 => array(
      'src' => 'node:nid',
      'dst' => 'node:sticky',
      'callback' => 'themekey_node_nid2sticky',
    ),
    35 => array(
      'src' => 'node:nid',
      'dst' => 'node:type',
      'callback' => 'themekey_node_nid2type',
    ),
    36 => array(
      'src' => 'node:nid',
      'dst' => 'node:uid',
      'callback' => 'themekey_node_nid2uid',
    ),
    37 => array(
      'src' => 'node:nid',
      'dst' => 'node:title',
      'callback' => 'themekey_node_nid2title',
    ),
    38 => array(
      'src' => 'drupal:get_q',
      'dst' => 'node:type',
      'callback' => 'themekey_node_get_q2type',
    ),
    39 => array(
      'src' => 'node:nid',
      'dst' => 'node:body_value',
      'callback' => 'themekey_node_nid2field_value',
      'args' => array(
        'field_name' => 'body',
        'type' => 'text_with_summary',
        'column' => 'value',
        'translatable' => '0',
      ),
    ),
    40 => array(
      'src' => 'node:nid',
      'dst' => 'node:body_summary',
      'callback' => 'themekey_node_nid2field_value',
      'args' => array(
        'field_name' => 'body',
        'type' => 'text_with_summary',
        'column' => 'summary',
        'translatable' => '0',
      ),
    ),
    41 => array(
      'src' => 'node:nid',
      'dst' => 'node:body_format',
      'callback' => 'themekey_node_nid2field_value',
      'args' => array(
        'field_name' => 'body',
        'type' => 'text_with_summary',
        'column' => 'format',
        'translatable' => '0',
      ),
    ),
    42 => array(
      'src' => 'node:nid',
      'dst' => 'node:field_tags_tid',
      'callback' => 'themekey_node_nid2field_value',
      'args' => array(
        'field_name' => 'field_tags',
        'type' => 'taxonomy_term_reference',
        'column' => 'tid',
        'translatable' => '0',
      ),
    ),
    43 => array(
      'src' => 'node:nid',
      'dst' => 'node:field_image_fid',
      'callback' => 'themekey_node_nid2field_value',
      'args' => array(
        'field_name' => 'field_image',
        'type' => 'image',
        'column' => 'fid',
        'translatable' => '0',
      ),
    ),
    44 => array(
      'src' => 'node:nid',
      'dst' => 'node:field_image_alt',
      'callback' => 'themekey_node_nid2field_value',
      'args' => array(
        'field_name' => 'field_image',
        'type' => 'image',
        'column' => 'alt',
        'translatable' => '0',
      ),
    ),
    45 => array(
      'src' => 'node:nid',
      'dst' => 'node:field_image_title',
      'callback' => 'themekey_node_nid2field_value',
      'args' => array(
        'field_name' => 'field_image',
        'type' => 'image',
        'column' => 'title',
        'translatable' => '0',
      ),
    ),
    46 => array(
      'src' => 'node:nid',
      'dst' => 'node:field_image_width',
      'callback' => 'themekey_node_nid2field_value',
      'args' => array(
        'field_name' => 'field_image',
        'type' => 'image',
        'column' => 'width',
        'translatable' => '0',
      ),
    ),
    47 => array(
      'src' => 'node:nid',
      'dst' => 'node:field_image_height',
      'callback' => 'themekey_node_nid2field_value',
      'args' => array(
        'field_name' => 'field_image',
        'type' => 'image',
        'column' => 'height',
        'translatable' => '0',
      ),
    ),
    48 => array(
      'src' => 'node:nid',
      'dst' => 'node:field_call_out_value',
      'callback' => 'themekey_node_nid2field_value',
      'args' => array(
        'field_name' => 'field_call_out',
        'type' => 'text_long',
        'column' => 'value',
        'translatable' => '0',
      ),
    ),
    49 => array(
      'src' => 'node:nid',
      'dst' => 'node:field_call_out_format',
      'callback' => 'themekey_node_nid2field_value',
      'args' => array(
        'field_name' => 'field_call_out',
        'type' => 'text_long',
        'column' => 'format',
        'translatable' => '0',
      ),
    ),
    50 => array(
      'src' => 'node:nid',
      'dst' => 'node:field_image_insert_fid',
      'callback' => 'themekey_node_nid2field_value',
      'args' => array(
        'field_name' => 'field_image_insert',
        'type' => 'image',
        'column' => 'fid',
        'translatable' => '0',
      ),
    ),
    51 => array(
      'src' => 'node:nid',
      'dst' => 'node:field_image_insert_alt',
      'callback' => 'themekey_node_nid2field_value',
      'args' => array(
        'field_name' => 'field_image_insert',
        'type' => 'image',
        'column' => 'alt',
        'translatable' => '0',
      ),
    ),
    52 => array(
      'src' => 'node:nid',
      'dst' => 'node:field_image_insert_title',
      'callback' => 'themekey_node_nid2field_value',
      'args' => array(
        'field_name' => 'field_image_insert',
        'type' => 'image',
        'column' => 'title',
        'translatable' => '0',
      ),
    ),
    53 => array(
      'src' => 'node:nid',
      'dst' => 'node:field_image_insert_width',
      'callback' => 'themekey_node_nid2field_value',
      'args' => array(
        'field_name' => 'field_image_insert',
        'type' => 'image',
        'column' => 'width',
        'translatable' => '0',
      ),
    ),
    54 => array(
      'src' => 'node:nid',
      'dst' => 'node:field_image_insert_height',
      'callback' => 'themekey_node_nid2field_value',
      'args' => array(
        'field_name' => 'field_image_insert',
        'type' => 'image',
        'column' => 'height',
        'translatable' => '0',
      ),
    ),
    55 => array(
      'src' => 'node:nid',
      'dst' => 'node:field_intro_value',
      'callback' => 'themekey_node_nid2field_value',
      'args' => array(
        'field_name' => 'field_intro',
        'type' => 'text_long',
        'column' => 'value',
        'translatable' => '0',
      ),
    ),
    56 => array(
      'src' => 'node:nid',
      'dst' => 'node:field_intro_format',
      'callback' => 'themekey_node_nid2field_value',
      'args' => array(
        'field_name' => 'field_intro',
        'type' => 'text_long',
        'column' => 'format',
        'translatable' => '0',
      ),
    ),
    57 => array(
      'src' => 'node:nid',
      'dst' => 'node:field_link_url',
      'callback' => 'themekey_node_nid2field_value',
      'args' => array(
        'field_name' => 'field_link',
        'type' => 'link_field',
        'column' => 'url',
        'translatable' => '0',
      ),
    ),
    58 => array(
      'src' => 'node:nid',
      'dst' => 'node:field_link_title',
      'callback' => 'themekey_node_nid2field_value',
      'args' => array(
        'field_name' => 'field_link',
        'type' => 'link_field',
        'column' => 'title',
        'translatable' => '0',
      ),
    ),
    59 => array(
      'src' => 'node:nid',
      'dst' => 'node:field_link_attributes',
      'callback' => 'themekey_node_nid2field_value',
      'args' => array(
        'field_name' => 'field_link',
        'type' => 'link_field',
        'column' => 'attributes',
        'translatable' => '0',
      ),
    ),
    60 => array(
      'src' => 'node:nid',
      'dst' => 'node:field_content_value',
      'callback' => 'themekey_node_nid2field_value',
      'args' => array(
        'field_name' => 'field_content',
        'type' => 'paragraphs',
        'column' => 'value',
        'translatable' => '0',
      ),
    ),
    61 => array(
      'src' => 'node:nid',
      'dst' => 'node:field_content_revision_id',
      'callback' => 'themekey_node_nid2field_value',
      'args' => array(
        'field_name' => 'field_content',
        'type' => 'paragraphs',
        'column' => 'revision_id',
        'translatable' => '0',
      ),
    ),
    62 => array(
      'src' => 'node:nid',
      'dst' => 'node:field_display_title_value',
      'callback' => 'themekey_node_nid2field_value',
      'args' => array(
        'field_name' => 'field_display_title',
        'type' => 'text',
        'column' => 'value',
        'translatable' => '0',
      ),
    ),
    63 => array(
      'src' => 'node:nid',
      'dst' => 'node:field_display_title_format',
      'callback' => 'themekey_node_nid2field_value',
      'args' => array(
        'field_name' => 'field_display_title',
        'type' => 'text',
        'column' => 'format',
        'translatable' => '0',
      ),
    ),
    64 => array(
      'src' => 'node:nid',
      'dst' => 'node:field_icon_fid',
      'callback' => 'themekey_node_nid2field_value',
      'args' => array(
        'field_name' => 'field_icon',
        'type' => 'image',
        'column' => 'fid',
        'translatable' => '0',
      ),
    ),
    65 => array(
      'src' => 'node:nid',
      'dst' => 'node:field_icon_alt',
      'callback' => 'themekey_node_nid2field_value',
      'args' => array(
        'field_name' => 'field_icon',
        'type' => 'image',
        'column' => 'alt',
        'translatable' => '0',
      ),
    ),
    66 => array(
      'src' => 'node:nid',
      'dst' => 'node:field_icon_title',
      'callback' => 'themekey_node_nid2field_value',
      'args' => array(
        'field_name' => 'field_icon',
        'type' => 'image',
        'column' => 'title',
        'translatable' => '0',
      ),
    ),
    67 => array(
      'src' => 'node:nid',
      'dst' => 'node:field_icon_width',
      'callback' => 'themekey_node_nid2field_value',
      'args' => array(
        'field_name' => 'field_icon',
        'type' => 'image',
        'column' => 'width',
        'translatable' => '0',
      ),
    ),
    68 => array(
      'src' => 'node:nid',
      'dst' => 'node:field_icon_height',
      'callback' => 'themekey_node_nid2field_value',
      'args' => array(
        'field_name' => 'field_icon',
        'type' => 'image',
        'column' => 'height',
        'translatable' => '0',
      ),
    ),
    69 => array(
      'src' => 'node:nid',
      'dst' => 'node:field_market_tid',
      'callback' => 'themekey_node_nid2field_value',
      'args' => array(
        'field_name' => 'field_market',
        'type' => 'taxonomy_term_reference',
        'column' => 'tid',
        'translatable' => '0',
      ),
    ),
    70 => array(
      'src' => 'node:nid',
      'dst' => 'node:field_service_tid',
      'callback' => 'themekey_node_nid2field_value',
      'args' => array(
        'field_name' => 'field_service',
        'type' => 'taxonomy_term_reference',
        'column' => 'tid',
        'translatable' => '0',
      ),
    ),
    71 => array(
      'src' => 'node:nid',
      'dst' => 'node:field_attachments_fid',
      'callback' => 'themekey_node_nid2field_value',
      'args' => array(
        'field_name' => 'field_attachments',
        'type' => 'file',
        'column' => 'fid',
        'translatable' => '0',
      ),
    ),
    72 => array(
      'src' => 'node:nid',
      'dst' => 'node:field_attachments_display',
      'callback' => 'themekey_node_nid2field_value',
      'args' => array(
        'field_name' => 'field_attachments',
        'type' => 'file',
        'column' => 'display',
        'translatable' => '0',
      ),
    ),
    73 => array(
      'src' => 'node:nid',
      'dst' => 'node:field_attachments_description',
      'callback' => 'themekey_node_nid2field_value',
      'args' => array(
        'field_name' => 'field_attachments',
        'type' => 'file',
        'column' => 'description',
        'translatable' => '0',
      ),
    ),
    74 => array(
      'src' => 'node:nid',
      'dst' => 'node:field_post_date_value',
      'callback' => 'themekey_node_nid2field_value',
      'args' => array(
        'field_name' => 'field_post_date',
        'type' => 'datetime',
        'column' => 'value',
        'translatable' => '0',
      ),
    ),
    75 => array(
      'src' => 'node:nid',
      'dst' => 'node:field_subtitle_value',
      'callback' => 'themekey_node_nid2field_value',
      'args' => array(
        'field_name' => 'field_subtitle',
        'type' => 'text',
        'column' => 'value',
        'translatable' => '0',
      ),
    ),
    76 => array(
      'src' => 'node:nid',
      'dst' => 'node:field_subtitle_format',
      'callback' => 'themekey_node_nid2field_value',
      'args' => array(
        'field_name' => 'field_subtitle',
        'type' => 'text',
        'column' => 'format',
        'translatable' => '0',
      ),
    ),
    77 => array(
      'src' => 'node:nid',
      'dst' => 'node:field_hero_image_fid',
      'callback' => 'themekey_node_nid2field_value',
      'args' => array(
        'field_name' => 'field_hero_image',
        'type' => 'image',
        'column' => 'fid',
        'translatable' => '0',
      ),
    ),
    78 => array(
      'src' => 'node:nid',
      'dst' => 'node:field_hero_image_alt',
      'callback' => 'themekey_node_nid2field_value',
      'args' => array(
        'field_name' => 'field_hero_image',
        'type' => 'image',
        'column' => 'alt',
        'translatable' => '0',
      ),
    ),
    79 => array(
      'src' => 'node:nid',
      'dst' => 'node:field_hero_image_title',
      'callback' => 'themekey_node_nid2field_value',
      'args' => array(
        'field_name' => 'field_hero_image',
        'type' => 'image',
        'column' => 'title',
        'translatable' => '0',
      ),
    ),
    80 => array(
      'src' => 'node:nid',
      'dst' => 'node:field_hero_image_width',
      'callback' => 'themekey_node_nid2field_value',
      'args' => array(
        'field_name' => 'field_hero_image',
        'type' => 'image',
        'column' => 'width',
        'translatable' => '0',
      ),
    ),
    81 => array(
      'src' => 'node:nid',
      'dst' => 'node:field_hero_image_height',
      'callback' => 'themekey_node_nid2field_value',
      'args' => array(
        'field_name' => 'field_hero_image',
        'type' => 'image',
        'column' => 'height',
        'translatable' => '0',
      ),
    ),
    82 => array(
      'src' => 'node:nid',
      'dst' => 'node:field_local_content_value',
      'callback' => 'themekey_node_nid2field_value',
      'args' => array(
        'field_name' => 'field_local_content',
        'type' => 'text_long',
        'column' => 'value',
        'translatable' => '0',
      ),
    ),
    83 => array(
      'src' => 'node:nid',
      'dst' => 'node:field_local_content_format',
      'callback' => 'themekey_node_nid2field_value',
      'args' => array(
        'field_name' => 'field_local_content',
        'type' => 'text_long',
        'column' => 'format',
        'translatable' => '0',
      ),
    ),
    84 => array(
      'src' => 'node:nid',
      'dst' => 'node:field_packages_intro_value',
      'callback' => 'themekey_node_nid2field_value',
      'args' => array(
        'field_name' => 'field_packages_intro',
        'type' => 'text_long',
        'column' => 'value',
        'translatable' => '0',
      ),
    ),
    85 => array(
      'src' => 'node:nid',
      'dst' => 'node:field_packages_intro_format',
      'callback' => 'themekey_node_nid2field_value',
      'args' => array(
        'field_name' => 'field_packages_intro',
        'type' => 'text_long',
        'column' => 'format',
        'translatable' => '0',
      ),
    ),
    86 => array(
      'src' => 'node:nid',
      'dst' => 'node:field_packages_title_value',
      'callback' => 'themekey_node_nid2field_value',
      'args' => array(
        'field_name' => 'field_packages_title',
        'type' => 'text',
        'column' => 'value',
        'translatable' => '0',
      ),
    ),
    87 => array(
      'src' => 'node:nid',
      'dst' => 'node:field_packages_title_format',
      'callback' => 'themekey_node_nid2field_value',
      'args' => array(
        'field_name' => 'field_packages_title',
        'type' => 'text',
        'column' => 'format',
        'translatable' => '0',
      ),
    ),
    88 => array(
      'src' => 'node:nid',
      'dst' => 'node:field_seo_title_value',
      'callback' => 'themekey_node_nid2field_value',
      'args' => array(
        'field_name' => 'field_seo_title',
        'type' => 'text',
        'column' => 'value',
        'translatable' => '0',
      ),
    ),
    89 => array(
      'src' => 'node:nid',
      'dst' => 'node:field_seo_title_format',
      'callback' => 'themekey_node_nid2field_value',
      'args' => array(
        'field_name' => 'field_seo_title',
        'type' => 'text',
        'column' => 'format',
        'translatable' => '0',
      ),
    ),
    90 => array(
      'src' => 'node:nid',
      'dst' => 'node:field_address_label_value',
      'callback' => 'themekey_node_nid2field_value',
      'args' => array(
        'field_name' => 'field_address_label',
        'type' => 'text',
        'column' => 'value',
        'translatable' => '0',
      ),
    ),
    91 => array(
      'src' => 'node:nid',
      'dst' => 'node:field_address_label_format',
      'callback' => 'themekey_node_nid2field_value',
      'args' => array(
        'field_name' => 'field_address_label',
        'type' => 'text',
        'column' => 'format',
        'translatable' => '0',
      ),
    ),
    92 => array(
      'src' => 'node:nid',
      'dst' => 'node:field_button_url',
      'callback' => 'themekey_node_nid2field_value',
      'args' => array(
        'field_name' => 'field_button',
        'type' => 'link_field',
        'column' => 'url',
        'translatable' => '0',
      ),
    ),
    93 => array(
      'src' => 'node:nid',
      'dst' => 'node:field_button_title',
      'callback' => 'themekey_node_nid2field_value',
      'args' => array(
        'field_name' => 'field_button',
        'type' => 'link_field',
        'column' => 'title',
        'translatable' => '0',
      ),
    ),
    94 => array(
      'src' => 'node:nid',
      'dst' => 'node:field_button_attributes',
      'callback' => 'themekey_node_nid2field_value',
      'args' => array(
        'field_name' => 'field_button',
        'type' => 'link_field',
        'column' => 'attributes',
        'translatable' => '0',
      ),
    ),
    95 => array(
      'src' => 'node:nid',
      'dst' => 'node:field_email_value',
      'callback' => 'themekey_node_nid2field_value',
      'args' => array(
        'field_name' => 'field_email',
        'type' => 'text',
        'column' => 'value',
        'translatable' => '0',
      ),
    ),
    96 => array(
      'src' => 'node:nid',
      'dst' => 'node:field_email_format',
      'callback' => 'themekey_node_nid2field_value',
      'args' => array(
        'field_name' => 'field_email',
        'type' => 'text',
        'column' => 'format',
        'translatable' => '0',
      ),
    ),
    97 => array(
      'src' => 'node:nid',
      'dst' => 'node:field_google_url_value',
      'callback' => 'themekey_node_nid2field_value',
      'args' => array(
        'field_name' => 'field_google_url',
        'type' => 'text',
        'column' => 'value',
        'translatable' => '0',
      ),
    ),
    98 => array(
      'src' => 'node:nid',
      'dst' => 'node:field_google_url_format',
      'callback' => 'themekey_node_nid2field_value',
      'args' => array(
        'field_name' => 'field_google_url',
        'type' => 'text',
        'column' => 'format',
        'translatable' => '0',
      ),
    ),
    99 => array(
      'src' => 'node:nid',
      'dst' => 'node:field_hours_value',
      'callback' => 'themekey_node_nid2field_value',
      'args' => array(
        'field_name' => 'field_hours',
        'type' => 'text_long',
        'column' => 'value',
        'translatable' => '0',
      ),
    ),
    100 => array(
      'src' => 'node:nid',
      'dst' => 'node:field_hours_format',
      'callback' => 'themekey_node_nid2field_value',
      'args' => array(
        'field_name' => 'field_hours',
        'type' => 'text_long',
        'column' => 'format',
        'translatable' => '0',
      ),
    ),
    101 => array(
      'src' => 'node:nid',
      'dst' => 'node:field_hours_label_value',
      'callback' => 'themekey_node_nid2field_value',
      'args' => array(
        'field_name' => 'field_hours_label',
        'type' => 'text',
        'column' => 'value',
        'translatable' => '0',
      ),
    ),
    102 => array(
      'src' => 'node:nid',
      'dst' => 'node:field_hours_label_format',
      'callback' => 'themekey_node_nid2field_value',
      'args' => array(
        'field_name' => 'field_hours_label',
        'type' => 'text',
        'column' => 'format',
        'translatable' => '0',
      ),
    ),
    103 => array(
      'src' => 'node:nid',
      'dst' => 'node:field_locality_value',
      'callback' => 'themekey_node_nid2field_value',
      'args' => array(
        'field_name' => 'field_locality',
        'type' => 'text',
        'column' => 'value',
        'translatable' => '0',
      ),
    ),
    104 => array(
      'src' => 'node:nid',
      'dst' => 'node:field_locality_format',
      'callback' => 'themekey_node_nid2field_value',
      'args' => array(
        'field_name' => 'field_locality',
        'type' => 'text',
        'column' => 'format',
        'translatable' => '0',
      ),
    ),
    105 => array(
      'src' => 'node:nid',
      'dst' => 'node:field_map_code_value',
      'callback' => 'themekey_node_nid2field_value',
      'args' => array(
        'field_name' => 'field_map_code',
        'type' => 'text_long',
        'column' => 'value',
        'translatable' => '0',
      ),
    ),
    106 => array(
      'src' => 'node:nid',
      'dst' => 'node:field_map_code_format',
      'callback' => 'themekey_node_nid2field_value',
      'args' => array(
        'field_name' => 'field_map_code',
        'type' => 'text_long',
        'column' => 'format',
        'translatable' => '0',
      ),
    ),
    107 => array(
      'src' => 'node:nid',
      'dst' => 'node:field_phone_label_value',
      'callback' => 'themekey_node_nid2field_value',
      'args' => array(
        'field_name' => 'field_phone_label',
        'type' => 'text',
        'column' => 'value',
        'translatable' => '0',
      ),
    ),
    108 => array(
      'src' => 'node:nid',
      'dst' => 'node:field_phone_label_format',
      'callback' => 'themekey_node_nid2field_value',
      'args' => array(
        'field_name' => 'field_phone_label',
        'type' => 'text',
        'column' => 'format',
        'translatable' => '0',
      ),
    ),
    109 => array(
      'src' => 'node:nid',
      'dst' => 'node:field_phone_number_value',
      'callback' => 'themekey_node_nid2field_value',
      'args' => array(
        'field_name' => 'field_phone_number',
        'type' => 'telephone',
        'column' => 'value',
        'translatable' => '0',
      ),
    ),
    110 => array(
      'src' => 'node:nid',
      'dst' => 'node:field_postal_code_value',
      'callback' => 'themekey_node_nid2field_value',
      'args' => array(
        'field_name' => 'field_postal_code',
        'type' => 'text',
        'column' => 'value',
        'translatable' => '0',
      ),
    ),
    111 => array(
      'src' => 'node:nid',
      'dst' => 'node:field_postal_code_format',
      'callback' => 'themekey_node_nid2field_value',
      'args' => array(
        'field_name' => 'field_postal_code',
        'type' => 'text',
        'column' => 'format',
        'translatable' => '0',
      ),
    ),
    112 => array(
      'src' => 'node:nid',
      'dst' => 'node:field_social_reviews_url',
      'callback' => 'themekey_node_nid2field_value',
      'args' => array(
        'field_name' => 'field_social_reviews',
        'type' => 'link_field',
        'column' => 'url',
        'translatable' => '0',
      ),
    ),
    113 => array(
      'src' => 'node:nid',
      'dst' => 'node:field_social_reviews_title',
      'callback' => 'themekey_node_nid2field_value',
      'args' => array(
        'field_name' => 'field_social_reviews',
        'type' => 'link_field',
        'column' => 'title',
        'translatable' => '0',
      ),
    ),
    114 => array(
      'src' => 'node:nid',
      'dst' => 'node:field_social_reviews_attributes',
      'callback' => 'themekey_node_nid2field_value',
      'args' => array(
        'field_name' => 'field_social_reviews',
        'type' => 'link_field',
        'column' => 'attributes',
        'translatable' => '0',
      ),
    ),
    115 => array(
      'src' => 'node:nid',
      'dst' => 'node:field_state_value',
      'callback' => 'themekey_node_nid2field_value',
      'args' => array(
        'field_name' => 'field_state',
        'type' => 'text',
        'column' => 'value',
        'translatable' => '0',
      ),
    ),
    116 => array(
      'src' => 'node:nid',
      'dst' => 'node:field_state_format',
      'callback' => 'themekey_node_nid2field_value',
      'args' => array(
        'field_name' => 'field_state',
        'type' => 'text',
        'column' => 'format',
        'translatable' => '0',
      ),
    ),
    117 => array(
      'src' => 'node:nid',
      'dst' => 'node:field_street_address_value',
      'callback' => 'themekey_node_nid2field_value',
      'args' => array(
        'field_name' => 'field_street_address',
        'type' => 'text',
        'column' => 'value',
        'translatable' => '0',
      ),
    ),
    118 => array(
      'src' => 'node:nid',
      'dst' => 'node:field_street_address_format',
      'callback' => 'themekey_node_nid2field_value',
      'args' => array(
        'field_name' => 'field_street_address',
        'type' => 'text',
        'column' => 'format',
        'translatable' => '0',
      ),
    ),
    119 => array(
      'src' => 'node:nid',
      'dst' => 'node:field_highlight_value',
      'callback' => 'themekey_node_nid2field_value',
      'args' => array(
        'field_name' => 'field_highlight',
        'type' => 'list_text',
        'column' => 'value',
        'translatable' => '0',
      ),
    ),
    120 => array(
      'src' => 'node:nid',
      'dst' => 'node:field_highlight_icon_fid',
      'callback' => 'themekey_node_nid2field_value',
      'args' => array(
        'field_name' => 'field_highlight_icon',
        'type' => 'image',
        'column' => 'fid',
        'translatable' => '0',
      ),
    ),
    121 => array(
      'src' => 'node:nid',
      'dst' => 'node:field_highlight_icon_alt',
      'callback' => 'themekey_node_nid2field_value',
      'args' => array(
        'field_name' => 'field_highlight_icon',
        'type' => 'image',
        'column' => 'alt',
        'translatable' => '0',
      ),
    ),
    122 => array(
      'src' => 'node:nid',
      'dst' => 'node:field_highlight_icon_title',
      'callback' => 'themekey_node_nid2field_value',
      'args' => array(
        'field_name' => 'field_highlight_icon',
        'type' => 'image',
        'column' => 'title',
        'translatable' => '0',
      ),
    ),
    123 => array(
      'src' => 'node:nid',
      'dst' => 'node:field_highlight_icon_width',
      'callback' => 'themekey_node_nid2field_value',
      'args' => array(
        'field_name' => 'field_highlight_icon',
        'type' => 'image',
        'column' => 'width',
        'translatable' => '0',
      ),
    ),
    124 => array(
      'src' => 'node:nid',
      'dst' => 'node:field_highlight_icon_height',
      'callback' => 'themekey_node_nid2field_value',
      'args' => array(
        'field_name' => 'field_highlight_icon',
        'type' => 'image',
        'column' => 'height',
        'translatable' => '0',
      ),
    ),
    125 => array(
      'src' => 'node:nid',
      'dst' => 'node:field_services_tid',
      'callback' => 'themekey_node_nid2field_value',
      'args' => array(
        'field_name' => 'field_services',
        'type' => 'taxonomy_term_reference',
        'column' => 'tid',
        'translatable' => '0',
      ),
    ),
    126 => array(
      'src' => 'node:nid',
      'dst' => 'node:field_position_value',
      'callback' => 'themekey_node_nid2field_value',
      'args' => array(
        'field_name' => 'field_position',
        'type' => 'text',
        'column' => 'value',
        'translatable' => '0',
      ),
    ),
    127 => array(
      'src' => 'node:nid',
      'dst' => 'node:field_position_format',
      'callback' => 'themekey_node_nid2field_value',
      'args' => array(
        'field_name' => 'field_position',
        'type' => 'text',
        'column' => 'format',
        'translatable' => '0',
      ),
    ),
    128 => array(
      'src' => 'node:nid',
      'dst' => 'node:field_region_tid',
      'callback' => 'themekey_node_nid2field_value',
      'args' => array(
        'field_name' => 'field_region',
        'type' => 'taxonomy_term_reference',
        'column' => 'tid',
        'translatable' => '0',
      ),
    ),
    129 => array(
      'src' => 'node:nid',
      'dst' => 'node:field_package_intro_value',
      'callback' => 'themekey_node_nid2field_value',
      'args' => array(
        'field_name' => 'field_package_intro',
        'type' => 'text_long',
        'column' => 'value',
        'translatable' => '0',
      ),
    ),
    130 => array(
      'src' => 'node:nid',
      'dst' => 'node:field_package_intro_format',
      'callback' => 'themekey_node_nid2field_value',
      'args' => array(
        'field_name' => 'field_package_intro',
        'type' => 'text_long',
        'column' => 'format',
        'translatable' => '0',
      ),
    ),
    131 => array(
      'src' => 'node:nid',
      'dst' => 'node:field_color_rgb',
      'callback' => 'themekey_node_nid2field_value',
      'args' => array(
        'field_name' => 'field_color',
        'type' => 'color_field_rgb',
        'column' => 'rgb',
        'translatable' => '0',
      ),
    ),
    132 => array(
      'src' => 'node:nid',
      'dst' => 'node:field_expiration_date_value',
      'callback' => 'themekey_node_nid2field_value',
      'args' => array(
        'field_name' => 'field_expiration_date',
        'type' => 'datetime',
        'column' => 'value',
        'translatable' => '0',
      ),
    ),
    133 => array(
      'src' => 'node:nid',
      'dst' => 'node:field_offer_headline_value',
      'callback' => 'themekey_node_nid2field_value',
      'args' => array(
        'field_name' => 'field_offer_headline',
        'type' => 'text',
        'column' => 'value',
        'translatable' => '0',
      ),
    ),
    134 => array(
      'src' => 'node:nid',
      'dst' => 'node:field_offer_headline_format',
      'callback' => 'themekey_node_nid2field_value',
      'args' => array(
        'field_name' => 'field_offer_headline',
        'type' => 'text',
        'column' => 'format',
        'translatable' => '0',
      ),
    ),
    135 => array(
      'src' => 'node:nid',
      'dst' => 'node:field_offer_price_value',
      'callback' => 'themekey_node_nid2field_value',
      'args' => array(
        'field_name' => 'field_offer_price',
        'type' => 'number_integer',
        'column' => 'value',
        'translatable' => '0',
      ),
    ),
    136 => array(
      'src' => 'node:nid',
      'dst' => 'node:field_offer_subheadline_value',
      'callback' => 'themekey_node_nid2field_value',
      'args' => array(
        'field_name' => 'field_offer_subheadline',
        'type' => 'text',
        'column' => 'value',
        'translatable' => '0',
      ),
    ),
    137 => array(
      'src' => 'node:nid',
      'dst' => 'node:field_offer_subheadline_format',
      'callback' => 'themekey_node_nid2field_value',
      'args' => array(
        'field_name' => 'field_offer_subheadline',
        'type' => 'text',
        'column' => 'format',
        'translatable' => '0',
      ),
    ),
    138 => array(
      'src' => 'node:nid',
      'dst' => 'node:field_original_price_value',
      'callback' => 'themekey_node_nid2field_value',
      'args' => array(
        'field_name' => 'field_original_price',
        'type' => 'number_integer',
        'column' => 'value',
        'translatable' => '0',
      ),
    ),
    139 => array(
      'src' => 'node:nid',
      'dst' => 'node:field_package_target_id',
      'callback' => 'themekey_node_nid2field_value',
      'args' => array(
        'field_name' => 'field_package',
        'type' => 'entityreference',
        'column' => 'target_id',
        'translatable' => '0',
      ),
    ),
    140 => array(
      'src' => 'node:nid',
      'dst' => 'node:field_landing_page_content_value',
      'callback' => 'themekey_node_nid2field_value',
      'args' => array(
        'field_name' => 'field_landing_page_content',
        'type' => 'paragraphs',
        'column' => 'value',
        'translatable' => '0',
      ),
    ),
    141 => array(
      'src' => 'node:nid',
      'dst' => 'node:field_landing_page_content_revision_id',
      'callback' => 'themekey_node_nid2field_value',
      'args' => array(
        'field_name' => 'field_landing_page_content',
        'type' => 'paragraphs',
        'column' => 'revision_id',
        'translatable' => '0',
      ),
    ),
    142 => array(
      'src' => 'node:nid',
      'dst' => 'node:field_header_paragraph_value',
      'callback' => 'themekey_node_nid2field_value',
      'args' => array(
        'field_name' => 'field_header_paragraph',
        'type' => 'paragraphs',
        'column' => 'value',
        'translatable' => '0',
      ),
    ),
    143 => array(
      'src' => 'node:nid',
      'dst' => 'node:field_header_paragraph_revision_id',
      'callback' => 'themekey_node_nid2field_value',
      'args' => array(
        'field_name' => 'field_header_paragraph',
        'type' => 'paragraphs',
        'column' => 'revision_id',
        'translatable' => '0',
      ),
    ),
    144 => array(
      'src' => 'node:nid',
      'dst' => 'node:field_footer_paragraph_value',
      'callback' => 'themekey_node_nid2field_value',
      'args' => array(
        'field_name' => 'field_footer_paragraph',
        'type' => 'paragraphs',
        'column' => 'value',
        'translatable' => '0',
      ),
    ),
    145 => array(
      'src' => 'node:nid',
      'dst' => 'node:field_footer_paragraph_revision_id',
      'callback' => 'themekey_node_nid2field_value',
      'args' => array(
        'field_name' => 'field_footer_paragraph',
        'type' => 'paragraphs',
        'column' => 'revision_id',
        'translatable' => '0',
      ),
    ),
    146 => array(
      'src' => 'node:nid',
      'dst' => 'node:field_colors_value',
      'callback' => 'themekey_node_nid2field_value',
      'args' => array(
        'field_name' => 'field_colors',
        'type' => 'paragraphs',
        'column' => 'value',
        'translatable' => '0',
      ),
    ),
    147 => array(
      'src' => 'node:nid',
      'dst' => 'node:field_colors_revision_id',
      'callback' => 'themekey_node_nid2field_value',
      'args' => array(
        'field_name' => 'field_colors',
        'type' => 'paragraphs',
        'column' => 'revision_id',
        'translatable' => '0',
      ),
    ),
    148 => array(
      'src' => 'node:nid',
      'dst' => 'node:field_packages_value',
      'callback' => 'themekey_node_nid2field_value',
      'args' => array(
        'field_name' => 'field_packages',
        'type' => 'field_collection',
        'column' => 'value',
        'translatable' => '0',
      ),
    ),
    149 => array(
      'src' => 'node:nid',
      'dst' => 'node:field_packages_revision_id',
      'callback' => 'themekey_node_nid2field_value',
      'args' => array(
        'field_name' => 'field_packages',
        'type' => 'field_collection',
        'column' => 'revision_id',
        'translatable' => '0',
      ),
    ),
    150 => array(
      'src' => 'node:nid',
      'dst' => 'node:field_features_tid',
      'callback' => 'themekey_node_nid2field_value',
      'args' => array(
        'field_name' => 'field_features',
        'type' => 'taxonomy_term_reference',
        'column' => 'tid',
        'translatable' => '0',
      ),
    ),
    151 => array(
      'src' => 'node:nid',
      'dst' => 'node:field_block_link_url',
      'callback' => 'themekey_node_nid2field_value',
      'args' => array(
        'field_name' => 'field_block_link',
        'type' => 'link_field',
        'column' => 'url',
        'translatable' => '0',
      ),
    ),
    152 => array(
      'src' => 'node:nid',
      'dst' => 'node:field_block_link_title',
      'callback' => 'themekey_node_nid2field_value',
      'args' => array(
        'field_name' => 'field_block_link',
        'type' => 'link_field',
        'column' => 'title',
        'translatable' => '0',
      ),
    ),
    153 => array(
      'src' => 'node:nid',
      'dst' => 'node:field_block_link_attributes',
      'callback' => 'themekey_node_nid2field_value',
      'args' => array(
        'field_name' => 'field_block_link',
        'type' => 'link_field',
        'column' => 'attributes',
        'translatable' => '0',
      ),
    ),
    154 => array(
      'src' => 'node:nid',
      'dst' => 'node:field_initial_fee_value',
      'callback' => 'themekey_node_nid2field_value',
      'args' => array(
        'field_name' => 'field_initial_fee',
        'type' => 'text',
        'column' => 'value',
        'translatable' => '0',
      ),
    ),
    155 => array(
      'src' => 'node:nid',
      'dst' => 'node:field_initial_fee_format',
      'callback' => 'themekey_node_nid2field_value',
      'args' => array(
        'field_name' => 'field_initial_fee',
        'type' => 'text',
        'column' => 'format',
        'translatable' => '0',
      ),
    ),
    156 => array(
      'src' => 'node:nid',
      'dst' => 'node:field_package_colors_rgb',
      'callback' => 'themekey_node_nid2field_value',
      'args' => array(
        'field_name' => 'field_package_colors',
        'type' => 'color_field_rgb',
        'column' => 'rgb',
        'translatable' => '0',
      ),
    ),
    157 => array(
      'src' => 'node:nid',
      'dst' => 'node:field_package_features_tid',
      'callback' => 'themekey_node_nid2field_value',
      'args' => array(
        'field_name' => 'field_package_features',
        'type' => 'taxonomy_term_reference',
        'column' => 'tid',
        'translatable' => '0',
      ),
    ),
    158 => array(
      'src' => 'node:nid',
      'dst' => 'node:field_starting_price_value',
      'callback' => 'themekey_node_nid2field_value',
      'args' => array(
        'field_name' => 'field_starting_price',
        'type' => 'number_integer',
        'column' => 'value',
        'translatable' => '0',
      ),
    ),
    159 => array(
      'src' => 'node:nid',
      'dst' => 'node:field_table_link_url',
      'callback' => 'themekey_node_nid2field_value',
      'args' => array(
        'field_name' => 'field_table_link',
        'type' => 'link_field',
        'column' => 'url',
        'translatable' => '0',
      ),
    ),
    160 => array(
      'src' => 'node:nid',
      'dst' => 'node:field_table_link_title',
      'callback' => 'themekey_node_nid2field_value',
      'args' => array(
        'field_name' => 'field_table_link',
        'type' => 'link_field',
        'column' => 'title',
        'translatable' => '0',
      ),
    ),
    161 => array(
      'src' => 'node:nid',
      'dst' => 'node:field_table_link_attributes',
      'callback' => 'themekey_node_nid2field_value',
      'args' => array(
        'field_name' => 'field_table_link',
        'type' => 'link_field',
        'column' => 'attributes',
        'translatable' => '0',
      ),
    ),
    162 => array(
      'src' => 'node:nid',
      'dst' => 'node:field_content_edited_value',
      'callback' => 'themekey_node_nid2field_value',
      'args' => array(
        'field_name' => 'field_content_edited',
        'type' => 'list_boolean',
        'column' => 'value',
        'translatable' => '0',
      ),
    ),
  );
  $export['themekey_maps'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'themekey_modules';
  $strongarm->value = array(
    0 => 'path',
    1 => 'system',
    2 => 'taxonomy',
    3 => 'views',
    4 => 'admin_menu',
    5 => 'user',
    6 => 'node',
  );
  $export['themekey_modules'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'themekey_paths';
  $strongarm->value = array(
    0 => array(
      'path' => 'node/#/revisions/#/view',
      'callbacks' => array(),
      'wildcards' => array(
        1 => 'node:nid',
        3 => 'node:vid',
      ),
      'weight' => 10,
      'fit' => 21,
    ),
    1 => array(
      'path' => 'taxonomy/term/#',
      'callbacks' => array(),
      'wildcards' => array(
        2 => 'taxonomy:tid',
      ),
      'weight' => 1,
      'fit' => 6,
    ),
    2 => array(
      'path' => 'user/#/edit',
      'callbacks' => array(),
      'wildcards' => array(
        1 => 'profile:uid',
      ),
      'weight' => 2,
      'fit' => 5,
    ),
    3 => array(
      'path' => 'user/#',
      'callbacks' => array(),
      'wildcards' => array(
        1 => 'profile:uid',
      ),
      'weight' => 1,
      'fit' => 2,
    ),
    4 => array(
      'path' => 'node/#',
      'callbacks' => array(),
      'wildcards' => array(
        1 => 'node:nid',
      ),
      'weight' => 1,
      'fit' => 2,
    ),
  );
  $export['themekey_paths'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'themekey_properties';
  $strongarm->value = array(
    'drupal:base_path' => 'drupal:base_path',
    'drupal:get_q' => 'drupal:get_q',
    'drupal:is_front_page' => 'drupal:is_front_page',
    'drupal:path' => 'drupal:path',
    'drupal:path:wildcard' => 'drupal:path:wildcard',
    'drupal:path_is_admin' => 'drupal:path_is_admin',
    'node:body_format' => 'node:body_format',
    'node:body_summary' => 'node:body_summary',
    'node:body_value' => 'node:body_value',
    'node:changed' => 'node:changed',
    'node:changed_date' => 'node:changed_date',
    'node:changed_date_time' => 'node:changed_date_time',
    'node:created' => 'node:created',
    'node:created_date' => 'node:created_date',
    'node:created_date_time' => 'node:created_date_time',
    'node:field_address_label_format' => 'node:field_address_label_format',
    'node:field_address_label_value' => 'node:field_address_label_value',
    'node:field_attachments_description' => 'node:field_attachments_description',
    'node:field_attachments_display' => 'node:field_attachments_display',
    'node:field_attachments_fid' => 'node:field_attachments_fid',
    'node:field_block_link_attributes' => 'node:field_block_link_attributes',
    'node:field_block_link_title' => 'node:field_block_link_title',
    'node:field_block_link_url' => 'node:field_block_link_url',
    'node:field_button_attributes' => 'node:field_button_attributes',
    'node:field_button_title' => 'node:field_button_title',
    'node:field_button_url' => 'node:field_button_url',
    'node:field_call_out_format' => 'node:field_call_out_format',
    'node:field_call_out_value' => 'node:field_call_out_value',
    'node:field_color_rgb' => 'node:field_color_rgb',
    'node:field_colors_revision_id' => 'node:field_colors_revision_id',
    'node:field_colors_value' => 'node:field_colors_value',
    'node:field_content_edited_value' => 'node:field_content_edited_value',
    'node:field_content_revision_id' => 'node:field_content_revision_id',
    'node:field_content_value' => 'node:field_content_value',
    'node:field_display_title_format' => 'node:field_display_title_format',
    'node:field_display_title_value' => 'node:field_display_title_value',
    'node:field_email_format' => 'node:field_email_format',
    'node:field_email_value' => 'node:field_email_value',
    'node:field_expiration_date_value' => 'node:field_expiration_date_value',
    'node:field_features_tid' => 'node:field_features_tid',
    'node:field_footer_paragraph_revision_id' => 'node:field_footer_paragraph_revision_id',
    'node:field_footer_paragraph_value' => 'node:field_footer_paragraph_value',
    'node:field_google_url_format' => 'node:field_google_url_format',
    'node:field_google_url_value' => 'node:field_google_url_value',
    'node:field_header_paragraph_revision_id' => 'node:field_header_paragraph_revision_id',
    'node:field_header_paragraph_value' => 'node:field_header_paragraph_value',
    'node:field_hero_image_alt' => 'node:field_hero_image_alt',
    'node:field_hero_image_fid' => 'node:field_hero_image_fid',
    'node:field_hero_image_height' => 'node:field_hero_image_height',
    'node:field_hero_image_title' => 'node:field_hero_image_title',
    'node:field_hero_image_width' => 'node:field_hero_image_width',
    'node:field_highlight_icon_alt' => 'node:field_highlight_icon_alt',
    'node:field_highlight_icon_fid' => 'node:field_highlight_icon_fid',
    'node:field_highlight_icon_height' => 'node:field_highlight_icon_height',
    'node:field_highlight_icon_title' => 'node:field_highlight_icon_title',
    'node:field_highlight_icon_width' => 'node:field_highlight_icon_width',
    'node:field_highlight_value' => 'node:field_highlight_value',
    'node:field_hours_format' => 'node:field_hours_format',
    'node:field_hours_label_format' => 'node:field_hours_label_format',
    'node:field_hours_label_value' => 'node:field_hours_label_value',
    'node:field_hours_value' => 'node:field_hours_value',
    'node:field_icon_alt' => 'node:field_icon_alt',
    'node:field_icon_fid' => 'node:field_icon_fid',
    'node:field_icon_height' => 'node:field_icon_height',
    'node:field_icon_title' => 'node:field_icon_title',
    'node:field_icon_width' => 'node:field_icon_width',
    'node:field_image_alt' => 'node:field_image_alt',
    'node:field_image_fid' => 'node:field_image_fid',
    'node:field_image_height' => 'node:field_image_height',
    'node:field_image_insert_alt' => 'node:field_image_insert_alt',
    'node:field_image_insert_fid' => 'node:field_image_insert_fid',
    'node:field_image_insert_height' => 'node:field_image_insert_height',
    'node:field_image_insert_title' => 'node:field_image_insert_title',
    'node:field_image_insert_width' => 'node:field_image_insert_width',
    'node:field_image_title' => 'node:field_image_title',
    'node:field_image_width' => 'node:field_image_width',
    'node:field_initial_fee_format' => 'node:field_initial_fee_format',
    'node:field_initial_fee_value' => 'node:field_initial_fee_value',
    'node:field_intro_format' => 'node:field_intro_format',
    'node:field_intro_value' => 'node:field_intro_value',
    'node:field_landing_page_content_revision_id' => 'node:field_landing_page_content_revision_id',
    'node:field_landing_page_content_value' => 'node:field_landing_page_content_value',
    'node:field_link_attributes' => 'node:field_link_attributes',
    'node:field_link_title' => 'node:field_link_title',
    'node:field_link_url' => 'node:field_link_url',
    'node:field_local_content_format' => 'node:field_local_content_format',
    'node:field_local_content_value' => 'node:field_local_content_value',
    'node:field_locality_format' => 'node:field_locality_format',
    'node:field_locality_value' => 'node:field_locality_value',
    'node:field_map_code_format' => 'node:field_map_code_format',
    'node:field_map_code_value' => 'node:field_map_code_value',
    'node:field_market_tid' => 'node:field_market_tid',
    'node:field_offer_headline_format' => 'node:field_offer_headline_format',
    'node:field_offer_headline_value' => 'node:field_offer_headline_value',
    'node:field_offer_price_value' => 'node:field_offer_price_value',
    'node:field_offer_subheadline_format' => 'node:field_offer_subheadline_format',
    'node:field_offer_subheadline_value' => 'node:field_offer_subheadline_value',
    'node:field_original_price_value' => 'node:field_original_price_value',
    'node:field_package_colors_rgb' => 'node:field_package_colors_rgb',
    'node:field_package_features_tid' => 'node:field_package_features_tid',
    'node:field_package_intro_format' => 'node:field_package_intro_format',
    'node:field_package_intro_value' => 'node:field_package_intro_value',
    'node:field_package_target_id' => 'node:field_package_target_id',
    'node:field_packages_intro_format' => 'node:field_packages_intro_format',
    'node:field_packages_intro_value' => 'node:field_packages_intro_value',
    'node:field_packages_revision_id' => 'node:field_packages_revision_id',
    'node:field_packages_title_format' => 'node:field_packages_title_format',
    'node:field_packages_title_value' => 'node:field_packages_title_value',
    'node:field_packages_value' => 'node:field_packages_value',
    'node:field_phone_label_format' => 'node:field_phone_label_format',
    'node:field_phone_label_value' => 'node:field_phone_label_value',
    'node:field_phone_number_value' => 'node:field_phone_number_value',
    'node:field_position_format' => 'node:field_position_format',
    'node:field_position_value' => 'node:field_position_value',
    'node:field_post_date_value' => 'node:field_post_date_value',
    'node:field_postal_code_format' => 'node:field_postal_code_format',
    'node:field_postal_code_value' => 'node:field_postal_code_value',
    'node:field_region_tid' => 'node:field_region_tid',
    'node:field_seo_title_format' => 'node:field_seo_title_format',
    'node:field_seo_title_value' => 'node:field_seo_title_value',
    'node:field_service_tid' => 'node:field_service_tid',
    'node:field_services_tid' => 'node:field_services_tid',
    'node:field_social_reviews_attributes' => 'node:field_social_reviews_attributes',
    'node:field_social_reviews_title' => 'node:field_social_reviews_title',
    'node:field_social_reviews_url' => 'node:field_social_reviews_url',
    'node:field_starting_price_value' => 'node:field_starting_price_value',
    'node:field_state_format' => 'node:field_state_format',
    'node:field_state_value' => 'node:field_state_value',
    'node:field_street_address_format' => 'node:field_street_address_format',
    'node:field_street_address_value' => 'node:field_street_address_value',
    'node:field_subtitle_format' => 'node:field_subtitle_format',
    'node:field_subtitle_value' => 'node:field_subtitle_value',
    'node:field_table_link_attributes' => 'node:field_table_link_attributes',
    'node:field_table_link_title' => 'node:field_table_link_title',
    'node:field_table_link_url' => 'node:field_table_link_url',
    'node:field_tags_tid' => 'node:field_tags_tid',
    'node:language' => 'node:language',
    'node:nid' => 'node:nid',
    'node:promote' => 'node:promote',
    'node:sticky' => 'node:sticky',
    'node:title' => 'node:title',
    'node:type' => 'node:type',
    'node:uid' => 'node:uid',
    'node:vid' => 'node:vid',
    'path:node_alias' => 'path:node_alias',
    'system:cookie' => 'system:cookie',
    'system:date' => 'system:date',
    'system:date_time' => 'system:date_time',
    'system:day_of_month' => 'system:day_of_month',
    'system:day_of_week' => 'system:day_of_week',
    'system:dummy' => 'system:dummy',
    'system:host' => 'system:host',
    'system:http_header' => 'system:http_header',
    'system:https' => 'system:https',
    'system:month' => 'system:month',
    'system:post' => 'system:post',
    'system:query_param' => 'system:query_param',
    'system:query_string' => 'system:query_string',
    'system:random' => 'system:random',
    'system:referer' => 'system:referer',
    'system:remote_ip' => 'system:remote_ip',
    'system:server_ip' => 'system:server_ip',
    'system:server_name' => 'system:server_name',
    'system:server_port' => 'system:server_port',
    'system:session' => 'system:session',
    'system:time' => 'system:time',
    'system:user_agent' => 'system:user_agent',
    'system:user_browser' => 'system:user_browser',
    'system:user_browser_simplified' => 'system:user_browser_simplified',
    'system:user_os' => 'system:user_os',
    'system:user_os_simplified' => 'system:user_os_simplified',
    'taxonomy:name' => 'taxonomy:name',
    'taxonomy:tid' => 'taxonomy:tid',
    'taxonomy:tid_and_childs' => 'taxonomy:tid_and_childs',
    'taxonomy:vid' => 'taxonomy:vid',
    'user:hostname' => 'user:hostname',
    'user:language' => 'user:language',
    'user:name' => 'user:name',
    'user:role' => 'user:role',
    'user:uid' => 'user:uid',
    'views:human_name' => 'views:human_name',
    'views:machine_name' => 'views:machine_name',
    'views:vid' => 'views:vid',
  );
  $export['themekey_properties'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'xmlsitemap_settings_node_landing_page';
  $strongarm->value = array(
    'status' => '1',
    'priority' => '0.5',
  );
  $export['xmlsitemap_settings_node_landing_page'] = $strongarm;

  return $export;
}
