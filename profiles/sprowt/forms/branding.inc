<?php 
/**
 * Branding form
 */
function sprout_branding($form, &$form_state, &$install_state){
  require_once drupal_get_path('profile', 'sprout') . '/includes/themebuilder.php';

  $TB = new ThemeBuilder();
  
  drupal_set_title(st('Configure Branding'));

  $form = $TB->theme_picker_form(array('sprout_branding_submit'));
  $form['#prefix'] = '<div class="description">';
  $form['#prefix'] .= '<p>This will set which theme is enabled when the site is created. The settings will also prepopulate the theme copy script located at Appearance->Leadbuilder Theme Copy.</p>';
  $form['#prefix'] .= '</div>';

  $form['new_theme']['#required'] = false;
  $form['new_theme_name']['#required'] = false;

  $form['theme']['theme_chooser']['#default_value'] = _sprout_form_default('theme', null);
  $form['new_theme_name']['#default_value'] = _sprout_form_default('new_theme_name');
  $form['new_theme']['#default_value'] = _sprout_form_default('new_theme');
  $form['colors']['primary']['#default_value'] = _sprout_form_default('primary_color');
  $form['colors']['secondary']['#default_value'] = _sprout_form_default('secondary_color');
  $form['colors']['tertiary']['#default_value'] = _sprout_form_default('tertiary_color');
  
  return $form;
}

function sprout_branding_submit($form, $form_state){
  $values = $form_state['values'];

  $fields = array(
      'theme' => $values['theme_chooser'],
      'new_theme_name' => $values['new_theme_name'],
      'new_theme' => $values['new_theme'],
      'primary-color' => $values['primary'],
      'secondary-color' => $values['secondary'],
      'tertiary-color' => $values['tertiary'],
      'new_path' => "sites/all/themes/{$values['new_theme']}"
  );
  
  _sprout_save_to_table('branding', $fields);
}

function sprout_theme_machine_name_exists($name) {
  require_once drupal_get_path('profile', 'sprout') . '/includes/themebuilder.php';
  $TB = new ThemeBuilder();

  return $TB->theme_machine_name_exists($name);
}