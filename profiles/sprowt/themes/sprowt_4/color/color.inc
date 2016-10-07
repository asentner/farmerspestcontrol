<?php

$info = array();

$info['fields'] = array(
   'primary' => t('Primary Base'),
   'primary_1' => t('Primary Dark'),
   'secondary' => t('Secondary Base'),
   'secondary_1' => t('Secondary Light'),
   'secondary_2' => t('Secondary Dark'),
   'slide_overlay' => t('Slide Overlay'),
);

$info['schemes'] = array(
   'default' => array(
     'title' => t('Default'),
     'colors' => array(
         'primary' => '#3da244',
         'primary_1' => '#245927',
         'secondary' => '#f3ba0d',
         'secondary_1' => '#f5c533',
         'secondary_2' => '#c3950a',
         'slide_overlay' => '#151616',
     ),
   ),
);

// $info['css'] = array( 'css/sprowt-4.styles.css', );
$info['css'] = array( 'css/sprowt-4.colors.css', );

$info['copy'] = array();

$info['gradients'] = array();

$info['fill'] = array();

$info['slices'] = array();

$info['blend_target'] = '#ffffff';

$info['preview_css'] = 'color/preview.css';
$info['preview_js'] = 'color/preview.js';
$info['preview_html'] = 'color/preview.html';

$info['base_image'] = 'color/base.png';
