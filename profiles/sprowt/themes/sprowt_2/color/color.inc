<?php

$info = array();

$info['fields'] = array(
   'primary' => t('Primary Base'),
   'primary_1' => t('Primary Dark'),
   'secondary' => t('Secondary Base'),
   'secondary_1' => t('Secondary Light'),
   'slide_overlay' => t('Slide Overlay'),
   'ltp_map' => t('LTP Location Background'),
);

$info['schemes'] = array(
   'default' => array(
     'title' => t('Default'),
     'colors' => array(
         'primary' => '#47b649',
         'primary_1' => '#3a933b',
         'secondary' => '#e9b404',
         'secondary_1' => '#fdd244',
         'slide_overlay' => '#151616',
         'ltp_map' => '#f4f4f5',
     ),
   ),
);

$info['css'] = array( 'css/sprowt-2.colors.css', );

$info['copy'] = array();

$info['gradients'] = array();

$info['fill'] = array();

$info['slices'] = array();

$info['blend_target'] = '#ffffff';

$info['preview_css'] = 'color/preview.css';
$info['preview_js'] = 'color/preview.js';
$info['preview_html'] = 'color/preview.html';

$info['base_image'] = 'color/base.png';
