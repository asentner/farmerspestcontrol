<?php

/**
 * Implements hook_migrate_api().
 */
function migrate_sprout_migrate_api() {
    $api = array(
        'api' => 2,
        'groups' => array(
            'sprout' => array(
                'title' => t('Sprout to Sprowt migration'),
            ),
            'migrations' => array(),
        ),
    );
    
    $api['migrations']['SproutPrep'] = array(
        'class_name' => 'SproutPrep',
        'group_name' => 'sprout',
    );
    
    /**
     * Each migration being registered takes an array of arguments, some required
     * and some optional. Start with the common arguments required by all - the
     * source_connection (connection key, set up in settings.php, pointing to
     * the Drupal 6 database), source_version (major version of Drupal), and
     * group_name (a.k.a. import job).
     */
    $common_arguments = array(
        'source_connection' => 'legacy',
        'source_version' => 7,
        'group_name' => 'sprout',
    );
    
    $sourcedb = variable_get('migrate_sprout_sourcedb', array());
    if(!empty($sourcedb)) {
        $common_arguments['source_database'] = array_merge(array(
            'driver' => 'mysql',
            'username' => 'pantheon',
            'database' => 'pantheon',
            'prefix' => ''
        ),$sourcedb);
    }
    
    $file_arguments = array(
        'class_name' => 'DrupalFile7Migration',
        'description' => t('Import files'),
        'default_uid' => 1,
        'source_dir' => variable_get('migrate_sprout_source_base_url'),
        'destination_dir' => 'public://sprout_files',
    );
    
    $api['migrations']['File'] = $common_arguments + $file_arguments;
    
    $vocabulary_arguments = array(
        'RegionTerms' => array(
            'description' => t('Migration of Regions'),
            'source_vocabulary' => 'regions',
            'destination_vocabulary' => 'regions',
        ),
        'MarketTerms' => array(
            'description' => t('Migration of Markets'),
            'source_vocabulary' => 'markets',
            'destination_vocabulary' => 'markets',
        ),
        'ServiceTerms' => array(
            'description' => t('Migration of Services'),
            'source_vocabulary' => 'services',
            'destination_vocabulary' => 'services',
        ),
    );
    
    $common_vocabulary_arguments = $common_arguments + array(
            'class_name' => 'DrupalTerm7Migration',
        );
    foreach ($vocabulary_arguments as $migration_name => $arguments) {
        $arguments += $common_vocabulary_arguments;
        $api['migrations'][$migration_name] = $arguments;
    }
    
    
    $node_arguments = array(
        'Affiliation' => array(
            'class_name' => 'AffiliationMigration',
            'description' => t('Migration of Affiliations'),
            'source_type' => 'affiliation',
            'destination_type' => 'affiliation',
            'dependencies' => array('File'),
        ),
        'Benefit' => array(
            'class_name' => 'BenefitMigration',
            'description' => t('Migration of Benefits'),
            'source_type' => 'benefit',
            'destination_type' => 'benefit',
            'dependencies' => array('File', 'MarketTerms', 'ServiceTerms'),
        ),
        'Blog' => array(
            'class_name' => 'BlogMigration',
            'description' => t('Migration of Blogs'),
            'source_type' => 'blog',
            'destination_type' => 'blog',
            'dependencies' => array('File', 'MarketTerms', 'ServiceTerms'),
        ),
        'CTA' => array(
            'class_name' => 'CTAMigration',
            'description' => t('Migration of CTAs'),
            'source_type' => 'cta',
            'destination_type' => 'cta',
        ),
        'LocalTarget' => array(
            'class_name' => 'LocalTargetMigration',
            'description' => t('Migration of LocalTargets'),
            'source_type' => 'localtarget',
            'destination_type' => 'localtarget',
            'dependencies' => array('File', 'MarketTerms', 'ServiceTerms'),
        ),
        'Location' => array(
            'class_name' => 'LocationMigration',
            'description' => t('Migration of Locations'),
            'source_type' => 'location',
            'destination_type' => 'location',
            'dependencies' => array('MarketTerms'),
        ),
        'Market' => array(
            'class_name' => 'MarketMigration',
            'description' => t('Migration of Markets'),
            'source_type' => 'market',
            'destination_type' => 'market',
            'dependencies' => array('File', 'MarketTerms'),
        ),
        'Package' => array(
            'class_name' => 'PackageMigration',
            'description' => t('Migration of Packages'),
            'source_type' => 'package',
            'destination_type' => 'package',
            'dependencies' => array('File', 'ServiceTerms'),
        ),
        'Profile' => array(
            'class_name' => 'ProfileMigration',
            'description' => t('Migration of Profiles'),
            'source_type' => 'profile',
            'destination_type' => 'profile',
            'dependencies' => array('File'),
        ),
        'Region' => array(
            'class_name' => 'RegionMigration',
            'description' => t('Migration of Regions'),
            'source_type' => 'region',
            'destination_type' => 'region',
            'dependencies' => array('File', 'RegionTerms'),
        ),
        'Service' => array(
            'class_name' => 'ServiceMigration',
            'description' => t('Migration of Services'),
            'source_type' => 'service',
            'destination_type' => 'service',
            'dependencies' => array('File', 'ServiceTerms'),
        ),
        'SlideshowSlide' => array(
            'class_name' => 'SlideMigration',
            'description' => t('Migration of Slideshow Slides'),
            'source_type' => 'slide',
            'destination_type' => 'slide',
            'dependencies' => array('File', 'MarketTerms', 'ServiceTerms'),
        ),
        'SpecialOffer' => array(
            'class_name' => 'SpecialOfferMigration',
            'description' => t('Migration of Special Offers'),
            'source_type' => 'special_offer',
            'destination_type' => 'special_offer',
            'dependencies' => array('File', 'ServiceTerms'),
        ),
        'Testimonial' => array(
            'class_name' => 'TestimonialMigration',
            'description' => t('Migration of Testimonials'),
            'source_type' => 'testimonial',
            'destination_type' => 'testimonial',
            'dependencies' => array('File', 'MarketTerms', 'ServiceTerms'),
        ),
        'Webform' => array(
            'class_name' => 'WebformMigration',
            'description' => t('Migration of Webforms'),
            'source_type' => 'webform',
            'destination_type' => 'webform',
            'dependencies' => array(),
        ),
    );
    
    
    foreach ($node_arguments as $migration_name => $arguments) {
        $arguments = array_merge_recursive($arguments, $common_arguments);
        $api['migrations'][$migration_name] = $arguments;
    }
    
    $api['migrations']['SproutFinish'] = array(
        'class_name' => 'SproutFinish',
        'group_name' => 'sprout',
    );
    
    return $api;
}