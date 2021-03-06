<?php
/**
 * @file
 * sprowt_fields_and_text_formats.features.taxonomy.inc
 */

/**
 * Implements hook_taxonomy_default_vocabularies().
 */
function sprowt_fields_and_text_formats_taxonomy_default_vocabularies() {
  return array(
    'concerns' => array(
      'name' => 'Concerns',
      'machine_name' => 'concerns',
      'description' => '',
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
