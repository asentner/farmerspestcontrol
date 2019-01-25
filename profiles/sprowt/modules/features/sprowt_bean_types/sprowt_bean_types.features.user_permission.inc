<?php

/**
 * @file
 * sprowt_bean_types.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function sprowt_bean_types_user_default_permissions() {
  $permissions = array();

  // Exported permission: 'access bean overview'.
  $permissions['access bean overview'] = array(
    'name' => 'access bean overview',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'bean',
  );

  // Exported permission: 'administer bean settings'.
  $permissions['administer bean settings'] = array(
    'name' => 'administer bean settings',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'bean',
  );

  // Exported permission: 'administer bean types'.
  $permissions['administer bean types'] = array(
    'name' => 'administer bean types',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'bean',
  );

  // Exported permission: 'administer beans'.
  $permissions['administer beans'] = array(
    'name' => 'administer beans',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'bean',
  );

  // Exported permission: 'create any aggregated_reviews_bean bean'.
  $permissions['create any aggregated_reviews_bean bean'] = array(
    'name' => 'create any aggregated_reviews_bean bean',
    'roles' => array(),
    'module' => 'bean',
  );

  // Exported permission: 'create any benefits_bean bean'.
  $permissions['create any benefits_bean bean'] = array(
    'name' => 'create any benefits_bean bean',
    'roles' => array(),
    'module' => 'bean',
  );

  // Exported permission: 'create any call_out_bean bean'.
  $permissions['create any call_out_bean bean'] = array(
    'name' => 'create any call_out_bean bean',
    'roles' => array(),
    'module' => 'bean',
  );

  // Exported permission: 'create any faq_bean bean'.
  $permissions['create any faq_bean bean'] = array(
    'name' => 'create any faq_bean bean',
    'roles' => array(),
    'module' => 'bean',
  );

  // Exported permission: 'create any generic_bean bean'.
  $permissions['create any generic_bean bean'] = array(
    'name' => 'create any generic_bean bean',
    'roles' => array(),
    'module' => 'bean',
  );

  // Exported permission: 'create any h1_bean bean'.
  $permissions['create any h1_bean bean'] = array(
    'name' => 'create any h1_bean bean',
    'roles' => array(),
    'module' => 'bean',
  );

  // Exported permission: 'create any hero bean'.
  $permissions['create any hero bean'] = array(
    'name' => 'create any hero bean',
    'roles' => array(),
    'module' => 'bean',
  );

  // Exported permission: 'create any image_only_bean bean'.
  $permissions['create any image_only_bean bean'] = array(
    'name' => 'create any image_only_bean bean',
    'roles' => array(),
    'module' => 'bean',
  );

  // Exported permission: 'create any image_text_bean bean'.
  $permissions['create any image_text_bean bean'] = array(
    'name' => 'create any image_text_bean bean',
    'roles' => array(),
    'module' => 'bean',
  );

  // Exported permission: 'create any multi_image_bean bean'.
  $permissions['create any multi_image_bean bean'] = array(
    'name' => 'create any multi_image_bean bean',
    'roles' => array(),
    'module' => 'bean',
  );

  // Exported permission: 'create any sesonal bean'.
  $permissions['create any sesonal bean'] = array(
    'name' => 'create any sesonal bean',
    'roles' => array(),
    'module' => 'bean',
  );

  // Exported permission: 'create any video_bean bean'.
  $permissions['create any video_bean bean'] = array(
    'name' => 'create any video_bean bean',
    'roles' => array(),
    'module' => 'bean',
  );

  // Exported permission: 'delete any aggregated_reviews_bean bean'.
  $permissions['delete any aggregated_reviews_bean bean'] = array(
    'name' => 'delete any aggregated_reviews_bean bean',
    'roles' => array(),
    'module' => 'bean',
  );

  // Exported permission: 'delete any benefits_bean bean'.
  $permissions['delete any benefits_bean bean'] = array(
    'name' => 'delete any benefits_bean bean',
    'roles' => array(),
    'module' => 'bean',
  );

  // Exported permission: 'delete any call_out_bean bean'.
  $permissions['delete any call_out_bean bean'] = array(
    'name' => 'delete any call_out_bean bean',
    'roles' => array(),
    'module' => 'bean',
  );

  // Exported permission: 'delete any faq_bean bean'.
  $permissions['delete any faq_bean bean'] = array(
    'name' => 'delete any faq_bean bean',
    'roles' => array(),
    'module' => 'bean',
  );

  // Exported permission: 'delete any generic_bean bean'.
  $permissions['delete any generic_bean bean'] = array(
    'name' => 'delete any generic_bean bean',
    'roles' => array(),
    'module' => 'bean',
  );

  // Exported permission: 'delete any h1_bean bean'.
  $permissions['delete any h1_bean bean'] = array(
    'name' => 'delete any h1_bean bean',
    'roles' => array(),
    'module' => 'bean',
  );

  // Exported permission: 'delete any hero bean'.
  $permissions['delete any hero bean'] = array(
    'name' => 'delete any hero bean',
    'roles' => array(),
    'module' => 'bean',
  );

  // Exported permission: 'delete any image_only_bean bean'.
  $permissions['delete any image_only_bean bean'] = array(
    'name' => 'delete any image_only_bean bean',
    'roles' => array(),
    'module' => 'bean',
  );

  // Exported permission: 'delete any image_text_bean bean'.
  $permissions['delete any image_text_bean bean'] = array(
    'name' => 'delete any image_text_bean bean',
    'roles' => array(),
    'module' => 'bean',
  );

  // Exported permission: 'delete any multi_image_bean bean'.
  $permissions['delete any multi_image_bean bean'] = array(
    'name' => 'delete any multi_image_bean bean',
    'roles' => array(),
    'module' => 'bean',
  );

  // Exported permission: 'delete any sesonal bean'.
  $permissions['delete any sesonal bean'] = array(
    'name' => 'delete any sesonal bean',
    'roles' => array(),
    'module' => 'bean',
  );

  // Exported permission: 'delete any video_bean bean'.
  $permissions['delete any video_bean bean'] = array(
    'name' => 'delete any video_bean bean',
    'roles' => array(),
    'module' => 'bean',
  );

  // Exported permission: 'edit any aggregated_reviews_bean bean'.
  $permissions['edit any aggregated_reviews_bean bean'] = array(
    'name' => 'edit any aggregated_reviews_bean bean',
    'roles' => array(),
    'module' => 'bean',
  );

  // Exported permission: 'edit any benefits_bean bean'.
  $permissions['edit any benefits_bean bean'] = array(
    'name' => 'edit any benefits_bean bean',
    'roles' => array(),
    'module' => 'bean',
  );

  // Exported permission: 'edit any call_out_bean bean'.
  $permissions['edit any call_out_bean bean'] = array(
    'name' => 'edit any call_out_bean bean',
    'roles' => array(),
    'module' => 'bean',
  );

  // Exported permission: 'edit any faq_bean bean'.
  $permissions['edit any faq_bean bean'] = array(
    'name' => 'edit any faq_bean bean',
    'roles' => array(),
    'module' => 'bean',
  );

  // Exported permission: 'edit any generic_bean bean'.
  $permissions['edit any generic_bean bean'] = array(
    'name' => 'edit any generic_bean bean',
    'roles' => array(),
    'module' => 'bean',
  );

  // Exported permission: 'edit any h1_bean bean'.
  $permissions['edit any h1_bean bean'] = array(
    'name' => 'edit any h1_bean bean',
    'roles' => array(),
    'module' => 'bean',
  );

  // Exported permission: 'edit any hero bean'.
  $permissions['edit any hero bean'] = array(
    'name' => 'edit any hero bean',
    'roles' => array(),
    'module' => 'bean',
  );

  // Exported permission: 'edit any image_only_bean bean'.
  $permissions['edit any image_only_bean bean'] = array(
    'name' => 'edit any image_only_bean bean',
    'roles' => array(),
    'module' => 'bean',
  );

  // Exported permission: 'edit any image_text_bean bean'.
  $permissions['edit any image_text_bean bean'] = array(
    'name' => 'edit any image_text_bean bean',
    'roles' => array(),
    'module' => 'bean',
  );

  // Exported permission: 'edit any multi_image_bean bean'.
  $permissions['edit any multi_image_bean bean'] = array(
    'name' => 'edit any multi_image_bean bean',
    'roles' => array(),
    'module' => 'bean',
  );

  // Exported permission: 'edit any sesonal bean'.
  $permissions['edit any sesonal bean'] = array(
    'name' => 'edit any sesonal bean',
    'roles' => array(),
    'module' => 'bean',
  );

  // Exported permission: 'edit any video_bean bean'.
  $permissions['edit any video_bean bean'] = array(
    'name' => 'edit any video_bean bean',
    'roles' => array(),
    'module' => 'bean',
  );

  // Exported permission: 'edit bean view mode'.
  $permissions['edit bean view mode'] = array(
    'name' => 'edit bean view mode',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'bean',
  );

  // Exported permission: 'view any aggregated_reviews_bean bean'.
  $permissions['view any aggregated_reviews_bean bean'] = array(
    'name' => 'view any aggregated_reviews_bean bean',
    'roles' => array(
      'anonymous user' => 'anonymous user',
    ),
    'module' => 'bean',
  );

  // Exported permission: 'view any benefits_bean bean'.
  $permissions['view any benefits_bean bean'] = array(
    'name' => 'view any benefits_bean bean',
    'roles' => array(
      'anonymous user' => 'anonymous user',
    ),
    'module' => 'bean',
  );

  // Exported permission: 'view any call_out_bean bean'.
  $permissions['view any call_out_bean bean'] = array(
    'name' => 'view any call_out_bean bean',
    'roles' => array(
      'anonymous user' => 'anonymous user',
    ),
    'module' => 'bean',
  );

  // Exported permission: 'view any faq_bean bean'.
  $permissions['view any faq_bean bean'] = array(
    'name' => 'view any faq_bean bean',
    'roles' => array(
      'anonymous user' => 'anonymous user',
    ),
    'module' => 'bean',
  );

  // Exported permission: 'view any generic_bean bean'.
  $permissions['view any generic_bean bean'] = array(
    'name' => 'view any generic_bean bean',
    'roles' => array(
      'anonymous user' => 'anonymous user',
    ),
    'module' => 'bean',
  );

  // Exported permission: 'view any h1_bean bean'.
  $permissions['view any h1_bean bean'] = array(
    'name' => 'view any h1_bean bean',
    'roles' => array(
      'anonymous user' => 'anonymous user',
    ),
    'module' => 'bean',
  );

  // Exported permission: 'view any hero bean'.
  $permissions['view any hero bean'] = array(
    'name' => 'view any hero bean',
    'roles' => array(
      'anonymous user' => 'anonymous user',
    ),
    'module' => 'bean',
  );

  // Exported permission: 'view any image_only_bean bean'.
  $permissions['view any image_only_bean bean'] = array(
    'name' => 'view any image_only_bean bean',
    'roles' => array(
      'anonymous user' => 'anonymous user',
    ),
    'module' => 'bean',
  );

  // Exported permission: 'view any image_text_bean bean'.
  $permissions['view any image_text_bean bean'] = array(
    'name' => 'view any image_text_bean bean',
    'roles' => array(
      'anonymous user' => 'anonymous user',
    ),
    'module' => 'bean',
  );

  // Exported permission: 'view any multi_image_bean bean'.
  $permissions['view any multi_image_bean bean'] = array(
    'name' => 'view any multi_image_bean bean',
    'roles' => array(
      'anonymous user' => 'anonymous user',
    ),
    'module' => 'bean',
  );

  // Exported permission: 'view any sesonal bean'.
  $permissions['view any sesonal bean'] = array(
    'name' => 'view any sesonal bean',
    'roles' => array(
      'anonymous user' => 'anonymous user',
    ),
    'module' => 'bean',
  );

  // Exported permission: 'view any video_bean bean'.
  $permissions['view any video_bean bean'] = array(
    'name' => 'view any video_bean bean',
    'roles' => array(
      'anonymous user' => 'anonymous user',
    ),
    'module' => 'bean',
  );

  // Exported permission: 'view bean page'.
  $permissions['view bean page'] = array(
    'name' => 'view bean page',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'bean',
  );

  // Exported permission: 'view bean revisions'.
  $permissions['view bean revisions'] = array(
    'name' => 'view bean revisions',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'bean',
  );

  return $permissions;
}
