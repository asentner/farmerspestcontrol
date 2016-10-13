<?php
/**
 * @file
 * sprowt_image_styles_features.features.inc
 */

/**
 * Implements hook_image_default_styles().
 */
function sprowt_image_styles_features_image_default_styles() {
  $styles = array();

  // Exported image style: affiliation_image.
  $styles['affiliation_image'] = array(
    'label' => 'Affiliation',
    'effects' => array(
      4 => array(
        'name' => 'image_scale',
        'data' => array(
          'width' => 200,
          'height' => 200,
          'upscale' => 1,
        ),
        'weight' => 1,
      ),
    ),
  );

  // Exported image style: benefits.
  $styles['benefits'] = array(
    'label' => 'Benefits (235 x 150)',
    'effects' => array(
      7 => array(
        'name' => 'focal_point_scale_and_crop',
        'data' => array(
          'width' => 300,
          'height' => 150,
          'focal_point_advanced' => array(
            'shift_x' => '',
            'shift_y' => '',
          ),
        ),
        'weight' => 1,
      ),
    ),
  );

  // Exported image style: benefits__front_page_.
  $styles['benefits__front_page_'] = array(
    'label' => 'Benefits (Front Page)',
    'effects' => array(
      5 => array(
        'name' => 'focal_point_scale_and_crop',
        'data' => array(
          'width' => 185,
          'height' => 185,
          'focal_point_advanced' => array(
            'shift_x' => '',
            'shift_y' => '',
          ),
        ),
        'weight' => 1,
      ),
    ),
  );

  // Exported image style: focal_point_scale_and_crop_100x100.
  $styles['focal_point_scale_and_crop_100x100'] = array(
    'label' => 'Focal Point Scale and Crop 100x100',
    'effects' => array(
      1 => array(
        'name' => 'focal_point_scale_and_crop',
        'data' => array(
          'width' => 100,
          'height' => 100,
          'focal_point_advanced' => array(
            'shift_x' => '',
            'shift_y' => '',
          ),
        ),
        'weight' => 1,
      ),
    ),
  );

  // Exported image style: focal_point_scale_and_crop_185x150.
  $styles['focal_point_scale_and_crop_185x150'] = array(
    'label' => 'Focal Point Scale and Crop 185x150',
    'effects' => array(
      1 => array(
        'name' => 'focal_point_scale_and_crop',
        'data' => array(
          'width' => 185,
          'height' => 150,
          'focal_point_advanced' => array(
            'shift_x' => '',
            'shift_y' => '',
          ),
        ),
        'weight' => 1,
      ),
    ),
  );

  // Exported image style: focal_point_scale_and_crop_250x250.
  $styles['focal_point_scale_and_crop_250x250'] = array(
    'label' => 'Focal Point Scale And Crop 250x250',
    'effects' => array(
      5 => array(
        'name' => 'focal_point_scale_and_crop',
        'data' => array(
          'width' => 250,
          'height' => 250,
          'focal_point_advanced' => array(
            'shift_x' => '',
            'shift_y' => '',
          ),
        ),
        'weight' => 1,
      ),
    ),
  );

  // Exported image style: focal_point_scale_and_crop_470x400.
  $styles['focal_point_scale_and_crop_470x400'] = array(
    'label' => 'Focal Point Scale And Crop 470x400',
    'effects' => array(
      2 => array(
        'name' => 'focal_point_scale_and_crop',
        'data' => array(
          'width' => 470,
          'height' => 400,
          'focal_point_advanced' => array(
            'shift_x' => '',
            'shift_y' => '',
          ),
        ),
        'weight' => 1,
      ),
    ),
  );

  // Exported image style: focal_point_scale_and_crop_80x80.
  $styles['focal_point_scale_and_crop_80x80'] = array(
    'label' => 'Focal Point Scale And Crop 80x80',
    'effects' => array(
      3 => array(
        'name' => 'focal_point_scale_and_crop',
        'data' => array(
          'width' => 80,
          'height' => 80,
          'focal_point_advanced' => array(
            'shift_x' => '',
            'shift_y' => '',
          ),
        ),
        'weight' => 1,
      ),
    ),
  );

  // Exported image style: fresh_light_service.
  $styles['fresh_light_service'] = array(
    'label' => 'Fresh Light Service',
    'effects' => array(
      10 => array(
        'name' => 'focal_point_scale_and_crop',
        'data' => array(
          'width' => 235,
          'height' => 170,
          'focal_point_advanced' => array(
            'shift_x' => '',
            'shift_y' => '',
          ),
        ),
        'weight' => 1,
      ),
    ),
  );

  // Exported image style: markets.
  $styles['markets'] = array(
    'label' => 'Markets',
    'effects' => array(
      8 => array(
        'name' => 'focal_point_scale_and_crop',
        'data' => array(
          'width' => 230,
          'height' => 150,
          'focal_point_advanced' => array(
            'shift_x' => '',
            'shift_y' => '',
          ),
        ),
        'weight' => 1,
      ),
    ),
  );

  // Exported image style: package_icon.
  $styles['package_icon'] = array(
    'label' => 'Package Icon',
    'effects' => array(
      1 => array(
        'name' => 'image_scale',
        'data' => array(
          'width' => 55,
          'height' => '',
          'upscale' => 0,
        ),
        'weight' => 1,
      ),
    ),
  );

  // Exported image style: primary__800x400_.
  $styles['primary__800x400_'] = array(
    'label' => 'primary (800x400)',
    'effects' => array(
      6 => array(
        'name' => 'focal_point_scale_and_crop',
        'data' => array(
          'width' => 800,
          'height' => 400,
          'focal_point_advanced' => array(
            'shift_x' => '',
            'shift_y' => '',
          ),
        ),
        'weight' => 1,
      ),
    ),
  );

  // Exported image style: profile.
  $styles['profile'] = array(
    'label' => 'Profile',
    'effects' => array(
      6 => array(
        'name' => 'focal_point_scale_and_crop',
        'data' => array(
          'width' => 180,
          'height' => 180,
          'focal_point_advanced' => array(
            'shift_x' => '',
            'shift_y' => '',
          ),
        ),
        'weight' => 1,
      ),
    ),
  );

  // Exported image style: scale_235.
  $styles['scale_235'] = array(
    'label' => 'Scale 235',
    'effects' => array(
      2 => array(
        'name' => 'image_scale',
        'data' => array(
          'width' => 235,
          'height' => '',
          'upscale' => 0,
        ),
        'weight' => 1,
      ),
    ),
  );

  // Exported image style: scale_60x60.
  $styles['scale_60x60'] = array(
    'label' => 'Scale 60x60',
    'effects' => array(
      4 => array(
        'name' => 'image_scale',
        'data' => array(
          'width' => 60,
          'height' => 60,
          'upscale' => 0,
        ),
        'weight' => 1,
      ),
    ),
  );

  // Exported image style: service.
  $styles['service'] = array(
    'label' => 'Service',
    'effects' => array(
      2 => array(
        'name' => 'focal_point_scale_and_crop',
        'data' => array(
          'width' => 185,
          'height' => 185,
          'focal_point_advanced' => array(
            'shift_x' => '',
            'shift_y' => '',
          ),
        ),
        'weight' => 1,
      ),
    ),
  );

  // Exported image style: service_primary.
  $styles['service_primary'] = array(
    'label' => 'Service Primary',
    'effects' => array(
      4 => array(
        'name' => 'focal_point_scale_and_crop',
        'data' => array(
          'width' => 800,
          'height' => 400,
          'focal_point_advanced' => array(
            'shift_x' => '',
            'shift_y' => '',
          ),
        ),
        'weight' => 1,
      ),
    ),
  );

  // Exported image style: slideshow_homepage.
  $styles['slideshow_homepage'] = array(
    'label' => 'Slideshow (Homepage)',
    'effects' => array(),
  );

  // Exported image style: special_offers_slideshow.
  $styles['special_offers_slideshow'] = array(
    'label' => 'Special Offers Slideshow',
    'effects' => array(
      9 => array(
        'name' => 'focal_point_scale_and_crop',
        'data' => array(
          'width' => 320,
          'height' => 305,
          'focal_point_advanced' => array(
            'shift_x' => '',
            'shift_y' => '',
          ),
        ),
        'weight' => 1,
      ),
    ),
  );

  return $styles;
}
