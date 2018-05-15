<?php

global $conf;
$conf['migrate_antipesto_sourcedb'] = array(
    'host' => 'dbserver.live.4f3a7499-c78b-4aac-a77c-85c3337f77a2.drush.in',
    'password' => '426b84882aec4ab8b001eb460e014d1e',
    'port' => 10553
);

$conf['migrate_antipesto_source_base_url'] = 'https://www.antipesto.com';

/**
 * Implements hook_migrate_api().
 */
function migrate_antipesto_migrate_api() {
    $api = array(
        'api' => 2,
        'groups' => array(
            'antipesto' => array(
                'title' => t('Sprout to Sprowt migration'),
            ),
            'migrations' => array(),
        ),
        'destination handlers' => array(
            'FocalPointDestinationHandler',
        ),
    );
    
    $api['migrations']['ApPrep'] = array(
        'class_name' => 'ApPrep',
        'group_name' => 'antipesto',
    );
    
    /**
     * Each migration being registered takes an array of arguments, some required
     * and some optional. Start with the common arguments required by all - the
     * source_connection (connection key, set up in settings.php, pointing to
     * the Drupal 6 database), source_version (major version of Drupal), and
     * group_name (a.k.a. import job).
     */
    $common_arguments = array(
        'source_connection' => 'antipesto',
        'source_version' => 7,
        'group_name' => 'antipesto',
        'soft_dependencies' => array('ApPrep')
    );

    $sourcedb = variable_get('migrate_antipesto_sourcedb', array());
    if(!empty($sourcedb)) {
        $common_arguments['source_database'] = array_merge(array(
            'driver' => 'mysql',
            'username' => 'pantheon',
            'database' => 'pantheon',
            'prefix' => ''
        ),$sourcedb);
    }
    
    $file_arguments = array(
        'class_name' => 'FocalPointFile',
        'description' => t('Import files'),
        'default_uid' => 1,
        'source_dir' => variable_get('migrate_antipesto_source_base_url') . '/sites/default/files',
        'destination_dir' => 'public://',
    );
    
    $api['migrations']['File'] = $common_arguments + $file_arguments;

    $api['migrations']['Role'] = $common_arguments + array(
            'description' => t('Migration of user toles'),
            'class_name' => 'ApRole',
            'role_mappings' => array(
                'administrator' => 'administrator',
                'content admin' => 'content admin'
            )
        );

    $api['migrations']['User'] = $common_arguments + array(
            'description' => t('Migration of users'),
            'class_name' => 'CoalmarchUser',
            'role_migration' => 'Role'
        );
    
    $vocabulary_arguments = array(
        'RegionTerms' => array(
            'description' => t('Migration of Regions'),
            'source_vocabulary' => 'region',
            'destination_vocabulary' => 'regions',
        ),
        'MarketTerms' => array(
            'description' => t('Migration of Markets'),
            'source_vocabulary' => 'market',
            'destination_vocabulary' => 'markets',
        ),
        'ServiceTerms' => array(
            'description' => t('Migration of Services'),
            'source_vocabulary' => 'service_category',
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
    

    $common_dependencies = array('User');

    $common_node_arguments = $common_arguments + array(
        'user_migration' => 'User'
    );

    $node_arguments = array(
        'Affiliation' => array(
            'class_name' => 'AffiliationMigration',
            'description' => t('Migration of Affiliations'),
            'source_type' => 'affiliation',
            'destination_type' => 'affiliation',
            'dependencies' => array('File'),
        ),
        'Blog' => array(
            'class_name' => 'BlogMigration',
            'description' => t('Migration of Blogs'),
            'source_type' => 'blog',
            'destination_type' => 'blog',
            'dependencies' => array('File', 'MarketTerms', 'ServiceTerms'),
        ),
        'Package' => array(
            'class_name' => 'PackageMigration',
            'description' => t('Migration of Packages'),
            'source_type' => 'service',
            'destination_type' => 'package',
            'dependencies' => array('File', 'ServiceTerms'),
        ),
        'Service' => array(
            'class_name' => 'ServiceMigration',
            'description' => t('Migration of Services'),
            'source_type' => 'service_category',
            'destination_type' => 'service',
            'dependencies' => array('File', 'ServiceTerms'),
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
        $arguments = array_merge_recursive($arguments, $common_node_arguments);
        $arguments['dependencies'] = array_merge($common_dependencies, $arguments['dependencies']);
        $api['migrations'][$migration_name] = $arguments;
    }
    
    $api['migrations']['ApFinish'] = array(
        'class_name' => 'ApFinish',
        'group_name' => 'antipesto',
        'soft_dependencies' => array_keys($api['migrations'])
    );
    
    return $api;
}