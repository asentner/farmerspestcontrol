<?php

require_once drupal_get_path('profile', 'sprowt') . '/includes/blockbuilder.php';

Class ThemeBuilder {
    
    function get_theme_location($theme){
        $info_loc = db_query("SELECT filename FROM system WHERE type = 'theme' and name = :name", array(':name' => $theme));
        
        if(empty($info_loc)){
            return false;
        }
        else {
            $info_loc = $info_loc->fetchCol();
        }
        
        $location = DRUPAL_ROOT . "/" . str_replace("/$theme.info", "", $info_loc[0]);
        
        return $location;
    }

    function get_base_theme($theme) {
        $info_loc = db_query("SELECT filename FROM system WHERE type = 'theme' and name = :name", array(':name' => $theme));

        if(empty($info_loc)){
            return false;
        }
        else {
            $info_loc = $info_loc->fetchField();
        }

        $info_loc = DRUPAL_ROOT . '/' . $info_loc;

        $info = drupal_parse_info_file($info_loc);

        if(empty($info['base theme'])) {
            return false;
        }

        return $info['base theme'];
    }
    
    function color_rename($theme, $primary = '', $secondary = '', $tertiary = ''){
        if(!$location = $this->get_theme_location($theme)){
            return false;
        }
        
        $color_file = $location . "/sass/variables/_colors.scss";
        
        if(!file_exists($color_file)){
            $handle = fopen($color_file, 'a');
            fclose($handle);
        }
        
        $color_str = file_get_contents($color_file);
        
        $colors = array(
            'primary' => $primary,
            'secondary' => $secondary,
            'tertiary' => $tertiary
        );
        
        $color_swap = false;
        
        foreach($colors as $var=>$val){
            if(!empty($val)) {
                $color_swap = true;
            }
            if( strpos($color_str, "\$color-brand-$var") !== false) {
                preg_match('/\$color-brand-'.$var.':(.*);/', $color_str, $matches);
                
                $color_str = preg_replace('/\$color-brand-'.$var.':.*/',"\$color-brand-$var: $val; // OLD: {$matches[1]}", $color_str);
            }
        }
        
        if($color_swap){
            $color_comments = "\n";
            $color_comments .= "// primary: {$colors['primary']}\n";
            $color_comments .= "// secondary: {$colors['secondary']}\n";
            $color_comments .= "// tertiary: {$colors['tertiary']}\n\n";

            file_put_contents($color_file, $color_comments . $color_str);
        }
        
    }
    
    function copy_theme($old, $new, $machine_name = null){

        $new_orig = $new;

        if(!empty($machine_name)) {
            $new = preg_replace('/[^0-9a-zA-Z\_]/','',preg_replace('/\s/','_',str_replace('-','_',strtolower($machine_name))));;
        }
        else {
            $new = preg_replace('/[^0-9a-zA-Z\_]/','',preg_replace('/\s/','_',str_replace('-','_',strtolower($new))));
        }

        if(!$location = $this->get_theme_location($old)){
            return false;
        }
        
        $src = $location;
        $dest = DRUPAL_ROOT . "/sites/all/themes/$new";
        
        if(is_dir($dest)){
            return 'exists';
        }
        
        $this->directory_recurse_copy($src, $dest);
        $this->theme_rename($old, $new, $dest);
        $this->info_change($new, $old, $new_orig);
        system_rebuild_theme_data();

        $theme_settings = variable_get('theme_'. $new . '_settings', array());
        $theme_settings['omega_toggle_extension_development'] = 0;
        variable_set('theme_'. $new . '_settings', $theme_settings);
    }
    
    function directory_recurse_copy($src,$dst) { 
        $dir = opendir($src); 
        @mkdir($dst); 
        while(false !== ( $file = readdir($dir)) ) { 
            if (( $file != '.' ) && ( $file != '..' )) { 
                if ( is_dir($src . '/' . $file) ) { 
                    $this->directory_recurse_copy($src . '/' . $file,$dst . '/' . $file); 
                } 
                else { 
                    copy($src . '/' . $file,$dst . '/' . $file); 
                } 
            } 
        } 
        closedir($dir); 
    }
    
    function theme_rename($old, $new, $directory) {
        $dir = opendir($directory);
        while(false !== ( $file = readdir($dir)) ) {
            if (( $file != '.' ) && ( $file != '..' )) {
                $filepath = $directory . '/' . $file;
                $dash_old = str_replace('_','-',$old);

                if($old == $dash_old) {
                    $dash_old = $old .'-';
                }

                $dash_new = str_replace('_','-',$new);
                if (is_dir($filepath)) {
                    if(strpos($file, $old) !== false){
                        $new_filepath = $directory . "/" . str_replace($old, $new, $file);
                        rename($filepath, $new_filepath);
                        $filepath = $new_filepath;
                    }

                    if(strpos($file, $dash_old) !== false){
                        $new_filepath = $directory . "/" . str_replace($dash_old, $dash_new, $file);
                        rename($filepath, $new_filepath);
                        $filepath = $new_filepath;
                    }

                    $this->theme_rename($old, $new, $filepath);
                }
                else {
                    if(strpos($file, $old) !== false){
                        $new_filepath = $directory . "/" . str_replace($old, $new, $file);
                        rename($filepath, $new_filepath);
                        $filepath = $new_filepath;
                    }

                    if(strpos($file, $dash_old) !== false){
                        $new_filepath = $directory . "/" . str_replace($dash_old, $dash_new, $file);
                        rename($filepath, $new_filepath);
                        $filepath = $new_filepath;
                    }
                    $str = file_get_contents($filepath);
                    if(strpos($str, $old) !== false){
                        file_put_contents($filepath, str_replace($old, $new, $str));
                    }

                    if(strpos($str, $dash_old) !== false){
                        file_put_contents($filepath, str_replace($dash_old,$dash_new, $str));
                    }
                }
            }
        }

        return $new;
    }

    function info_change($new, $old, $new_upper = '') {

        $directory = DRUPAL_ROOT . "/sites/all/themes/$new";

        if(empty($new_upper)) {
            $new_upper = $new;
        }

        if(file_exists($directory . "/$new.info")){
            $info_str = file_get_contents($directory . "/$new.info");

            preg_match('/name[\s]+?\=(.*)/', $info_str, $matches);
            $old_name = $matches[1];
            $info_str = preg_replace('/name[\s]+?\=.*/', "name = $new_upper", $info_str);

            preg_match('/description[\s]+?\=(.*)/', $info_str, $matches);
            $info_str = preg_replace('/description[\s]+?\=.*/', "description = Theme copied from \"$old_name\".\ncopied_from = $old", $info_str);

            file_put_contents($directory . "/$new.info", $info_str);
        }

        return $new;
    }

    function theme_delete($name) {
        if(empty($name)) {
            return false;
        }

        $path = DRUPAL_ROOT . '/sites/all/themes/' . $name;

        return $this->delete_directory($path);

    }

    function delete_directory($src) {
        if(!is_dir($src) || basename($src) == '.git') {
            return false;
        }

        $dir = opendir($src);
        while(false !== ( $file = readdir($dir)) ) {
            $path = "$src/$file";
            if (( $file != '.' ) && ( $file != '..' ) && ( $file != '.git' )) {
                if ( is_dir($path) ) {
                    $this->delete_directory($path);
                }
                else {
                    unlink($path);
                }
            }
        }
        closedir($dir);

        return rmdir($src);
    }

    function import_blocks($old, $new, $filename = null){
        $custom_filename = true;
        if(empty($filename)) {
            $custom_filename = false;
            $filename = $old . '_block_export.json';
        }

        $file_location = $this->get_theme_location($old) . '/' . $filename;

        if(!file_exists($file_location)) {
            $base_theme = $this->get_base_theme($old);
            if(empty($base_theme)) {
                return false;
            }
            else {
                if($custom_filename) {
                    $this->import_blocks($base_theme, $new, $filename);
                }
                else {
                    $this->import_blocks($base_theme, $new);
                }
                return false;
            }
        }

        $BB = new BlockBuilder();

        $BB->importFromFile($file_location, $new);
    }
    
    function enable($theme_name){
      
        system_rebuild_theme_data();
        
        theme_enable(array($theme_name));
        
        $default = variable_get('theme_default');
        variable_set('theme_default', $theme_name);
        
        theme_disable(array($default));
    }

    function sprowt_themes(){
        $json = file_get_contents(drupal_get_path('profile', 'sprowt') . '/sprowt_themes.json');

        $sprowt_themes = json_decode($json, true);

        $theme_list = list_themes(TRUE);
        $new_theme_list = array();

        foreach($theme_list as $theme_name => $object) {
            if(in_array($theme_name, $sprowt_themes)) {
                $new_theme_list[$theme_name] = $object;
            }
        }

        return $new_theme_list;
    }

    function machine_nameify($name) {
        return preg_replace('/[^0-9a-zA-Z\_]/','',preg_replace('/\s/','_',str_replace('-','_',strtolower($name))));
    }


    function theme_field($logo, $theme) {
        if(!empty($theme)){
            ob_start();
            include drupal_get_path('profile', 'sprowt') . '/includes/theme_field.tpl.php';
            return ob_get_clean();
        }
    }

    function theme_picker_form($submit = array(), $validate = array(), $machine_name_exists = 'sprowt_theme_machine_name_exists') {
        $sprowt_theme_list = $this->sprowt_themes();
        $theme_list = list_themes(TRUE);
        $path = drupal_get_path('profile', 'sprowt');
    
    
        $form['#attached']['js'][] = "https://code.jquery.com/jquery-1.11.2.min.js"; //I don't wanna use drupal's old as dirt jQuery
        $form['#attached']['js'][] = $path . "/js/machine-name.js";
    
        $form['#attached']['css'][] = $path . "/css/spectrum.css";
        $form['#attached']['js'][] = $path . "/js/spectrum.js";
    
        $form['#attached']['css'][] = $path . "/css/theme_copy.css";
        $form['#attached']['js'][] = $path . "/js/branding.js";
    
        $excluded = array(
            'omega',
            'ohm',
            'seven_sprowt'
        );
    
        $themes = array();
        foreach($sprowt_theme_list as $theme_name => $object) {
            $location = str_replace("/$theme_name.info", "", $object->filename);
            if(!in_array($theme_name, $excluded)
                && strpos($location, 'sprowt/themes') !== false
            )
            {
                $logo = glob("$location/screenshot.*");
                if(!empty($logo)){
                    $logo = "/$logo[0]";
                }
                elseif(!empty($object->base_theme)){
                    $base_location = str_replace("/{$object->base_theme}.info", "", $theme_list[$object->base_theme]->filename);
                    $logo = glob("$base_location/screenshot.*");
                    if(!empty($logo)){
                        $logo = "/$logo[0]";
                    }
                    else {
                        $logo = "/" . drupal_get_path('theme', 'seven') . "/logo.png";
                    }
                }
                else {
                    $logo = "/" . drupal_get_path('theme', 'seven') . "/logo.png";
                }
            
                $theme = $object->info;
                if(!empty($theme)){
                    $theme_field = $this->theme_field($logo, $theme);
                    $themes[$theme['name']] = array(
                        'index' => $theme_name,
                        'markup' =>$theme_field,
                    );
                }
            }
        }
    
        ksort($themes, SORT_NATURAL);
    
        $theme_options = array();
    
        foreach($themes as $opt) {
            $theme_options[$opt['index']] = $opt['markup'];
        }
    
        $form['theme'] = array(
            '#title' => t("Choose a theme to base the site's theme off of."),
        );
    
        $form['theme']['theme_chooser'] = array(
            '#title' => t("Choose a theme to base the site's theme off of."),
            '#type' => 'radios',
            '#options' => $theme_options,
            '#required' => true,
        );
    
        $form['new_theme_name'] = array(
            '#type' => 'textfield',
            '#title' => 'New Theme Name',
            '#required' => true,
        );
    
        $form['new_theme'] = array(
            '#type' => 'machine_name',
            '#title' => 'New Theme Machine Name',
            '#required' => true,
            '#machine_name' => array(
                'exists' => $machine_name_exists,
                'source' => array('new_theme_name')
            ),
            '#process' => array('form_process_machine_name')
        );
    
        $form['colors'] = array(
            '#type' => 'fieldset',
            '#title' => t('Choose your theme\'s colors (optional)'),
            '#description' => 'This will only apply after the dev team modifies the theme'
        );
    
        $form['colors']['primary'] = array(
            '#type' => 'textfield',
            '#title' => 'Primary Color',
            '#attributes' => array(
                'id' => 'primary-color',
                'class' => array('color'),
                'data-spectrum' => 'spectrum-primary',
            ),
            '#prefix' => '<div class="color-picker">',
            '#suffix' => '<input type="text" id="spectrum-primary" class="spectrum" data-color_id="primary-color"></div>',
        );
    
        $form['colors']['secondary'] = array(
            '#type' => 'textfield',
            '#title' => 'Secondary Color',
            '#attributes' => array(
                'id' => 'secondary-color',
                'class' => array('color'),
                'data-spectrum' => 'spectrum-secondary',
            ),
            '#prefix' => '<div class="color-picker">',
            '#suffix' => '<input type="text" id="spectrum-secondary" class="spectrum" data-color_id="secondary-color"></div>',
        );
    
        $form['colors']['tertiary'] = array(
            '#type' => 'textfield',
            '#title' => 'Tertiary Color',
            '#attributes' => array(
                'id' => 'tertiary-color',
                'class' => array('color'),
                'data-spectrum' => 'spectrum-tertiary',
            ),
            '#prefix' => '<div class="color-picker">',
            '#suffix' => '<input type="text" id="spectrum-tertiary" class="spectrum" data-color_id="tertiary-color"></div>',
        );
    
        $form['actions']['submit'] = array(
            '#type' => 'submit',
            '#value' => t('Save and Continue'),
        );

        if(!empty($submit)) {
            $form['#submit'] = $submit;
        }

        if(!empty($validate)) {
            $form['#validate'] = $validate;
        }

        return $form;
    }

    function theme_machine_name_exists($name) {
        $theme_list = list_themes(TRUE);

        return in_array($name, array_keys($theme_list));
    }
}