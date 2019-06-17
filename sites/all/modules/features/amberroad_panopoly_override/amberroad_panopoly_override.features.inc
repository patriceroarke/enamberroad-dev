<?php
/**
 * @file
 * amberroad_panopoly_override.features.inc
 */

/**
 * Implements hook_field_default_field_instances_alter().
 */
function amberroad_panopoly_override_field_default_field_instances_alter(&$data) {
  if (isset($data['node-panopoly_page-body'])) {
    $data['node-panopoly_page-body']['display']['related_contents'] = array(
      'label' => 'above',
      'settings' => array(),
      'type' => 'hidden',
      'weight' => 0,
    ); /* WAS: '' */
  }
  if (isset($data['node-panopoly_page-field_featured_categories'])) {
    $data['node-panopoly_page-field_featured_categories']['display']['related_contents'] = array(
      'label' => 'above',
      'settings' => array(),
      'type' => 'hidden',
      'weight' => 0,
    ); /* WAS: '' */
  }
  if (isset($data['node-panopoly_page-field_featured_image'])) {
    $data['node-panopoly_page-field_featured_image']['display']['related_contents'] = array(
      'label' => 'above',
      'settings' => array(),
      'type' => 'hidden',
      'weight' => 0,
    ); /* WAS: '' */
  }
  if (isset($data['node-panopoly_page-field_featured_status'])) {
    $data['node-panopoly_page-field_featured_status']['display']['related_contents'] = array(
      'label' => 'above',
      'settings' => array(),
      'type' => 'hidden',
      'weight' => 0,
    ); /* WAS: '' */
  }
}

/**
 * Implements hook_taxonomy_default_vocabularies_alter().
 */
function amberroad_panopoly_override_taxonomy_default_vocabularies_alter(&$data) {
  if (isset($data['panopoly_categories'])) {
    $data['panopoly_categories']['rdf_mapping'] = array(
      'description' => array(
        'predicates' => array(
          0 => 'rdfs:comment',
        ),
      ),
      'name' => array(
        'predicates' => array(
          0 => 'dc:title',
        ),
      ),
      'rdftype' => array(
        0 => 'skos:ConceptScheme',
      ),
    ); /* WAS: '' */
  }
}

/**
 * Implements hook_strongarm_alter().
 */
function amberroad_panopoly_override_strongarm_alter(&$data) {
  if (isset($data['ctools_content_all_views'])) {
    $data['ctools_content_all_views']->value = 1; /* WAS: 0 */
  }
  if (isset($data['page_manager_node_edit_disabled'])) {
    $data['page_manager_node_edit_disabled']->value = TRUE; /* WAS: FALSE */
  }
}
