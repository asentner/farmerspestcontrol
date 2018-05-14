<?php
/**
 * @file
 * sprowt_package_comparison.features.taxonomy.inc
 */

/**
 * Implements hook_taxonomy_default_vocabularies().
 */
function sprowt_package_comparison_taxonomy_default_vocabularies() {
  return array(
    'features' => array(
      'name' => 'Package Features',
      'machine_name' => 'features',
      'description' => 'Package Features',
      'hierarchy' => 0,
      'module' => 'taxonomy',
      'weight' => 0,
      'rdf_mapping' => array(
        'rdftype' => array(
          0 => 'skos:ConceptScheme',
        ),
        'name' => array(
          'predicates' => array(
            0 => 'dc:title',
          ),
        ),
        'description' => array(
          'predicates' => array(
            0 => 'rdfs:comment',
          ),
        ),
      ),
    ),
  );
}
