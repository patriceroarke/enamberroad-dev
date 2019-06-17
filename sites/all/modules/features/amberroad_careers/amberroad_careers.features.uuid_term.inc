<?php
/**
 * @file
 * amberroad_careers.features.uuid_term.inc
 */

/**
 * Implements hook_uuid_features_default_terms().
 */
function amberroad_careers_uuid_features_default_terms() {
  $terms = array();

  $terms[] = array(
    'name' => 'Asia Pacific',
    'description' => NULL,
    'format' => NULL,
    'weight' => 0,
    'uuid' => '7a6d0315-e358-48ad-a6fd-5b80b2bbec13',
    'vocabulary_machine_name' => 'career_location',
  );
  $terms[] = array(
    'name' => 'Europe',
    'description' => NULL,
    'format' => NULL,
    'weight' => 0,
    'uuid' => '7b2b4f5f-a5f9-4da7-ab96-add7e32e1c78',
    'vocabulary_machine_name' => 'career_location',
  );
  $terms[] = array(
    'name' => 'United States',
    'description' => NULL,
    'format' => NULL,
    'weight' => 0,
    'uuid' => '9ee330e3-0233-403d-a545-1cf5e7562a2a',
    'vocabulary_machine_name' => 'career_location',
  );
  $terms[] = array(
    'name' => 'India',
    'description' => NULL,
    'format' => NULL,
    'weight' => 0,
    'uuid' => 'fab040b5-bca8-48c7-a913-13a8d4df86b6',
    'vocabulary_machine_name' => 'career_location',
  );
  return $terms;
}
