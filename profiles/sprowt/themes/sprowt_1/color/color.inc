<?php

$info = array();

$info['fields'] = array(
   'primary' => t('Primary Base'),
   'primary_1' => t('Primary Dark'),
   'secondary' => t('Secondary Base'),
   'secondary_1' => t('Secondary Light'),
   'slide_overlay' => t('Slide Overlay'),
);

$info['schemes'] = array(
   'default' => array(
     'title' => t('Default'),
     'colors' => array(
         'primary' => '#80b840',
         'primary_1' => '#6fab34',
         'secondary' => '#216e82',
         'secondary_1' => '#21768c',
         'slide_overlay' => '#216e83',
     ),
   ),
);

// $info['css'] = array( 'css/sprowt-1.styles.css', );
$info['css'] = array( 'css/sprowt-1.colors.css', );

$info['copy'] = array();

$info['gradients'] = array();

$info['fill'] = array();

$info['slices'] = array();

$info['blend_target'] = '#ffffff';

$info['preview_css'] = 'color/preview.css';
$info['preview_js'] = 'color/preview.js';
$info['preview_html'] = 'color/preview.html';

$info['base_image'] = 'color/base.png';
