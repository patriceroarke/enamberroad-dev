<?php
/**
 * @file
 * amberroad_careers.features.taxonomy.inc
 */

/**
 * Implements hook_taxonomy_default_vocabularies().
 */
function amberroad_careers_taxonomy_default_vocabularies() {
  return array(
    'career_location' => array(
      'name' => 'Career Location',
      'machine_name' => 'career_location',
      'description' => 'Contains locations for career content.',
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
