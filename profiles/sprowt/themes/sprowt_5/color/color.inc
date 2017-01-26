<?php

$info = array();

$info['fields'] = array(
   'primary' => t('Primary Base'),
   'primary_1' => t('Primary Dark'),
   'secondary' => t('Secondary Base'),
   'secondary_1' => t('Secondary Light'),
   'slide_overlay' => t('Slide Overlay'),
   'front_map' => t('Homepage Map Background'),
   'ltp_map' => t('LTP Location Background'),
);

$info['schemes'] = array(
   'default' => array(
     'title' => t('Default'),
     'colors' => array(
         'primary' => '#239343',
         'primary_1' => '#00591d',
         'secondary' => '#f5c505',
         'secondary_1' => '#ebe0b5',
         'slide_overlay' => '#151616',
         'front_map' => '#00591e',
         'ltp_map' => '#f4f4f5',
     ),
   ),
);

// $info['css'] = array( 'css/sprowt-5.styles.css', );
$info['css'] = array( 'css/sprowt-5.colors.css', );

$info['copy'] = array();

$info['gradients'] = array();

$info['fill'] = array();

$info['slices'] = array();

$info['blend_target'] = '#ffffff';

$info['preview_css'] = 'color/preview.css';
$info['preview_js'] = 'color/preview.js';
$info['preview_html'] = 'color/preview.html';

$info['base_image'] = 'color/base.png';
