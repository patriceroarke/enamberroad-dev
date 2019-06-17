<?php
/**
 * @file
 * amberroad_panopoly_override.features.features_overrides.inc
 */

/**
 * Implements hook_features_override_default_overrides().
 */
function amberroad_panopoly_override_features_override_default_overrides() {
  // This code is only used for UI in features. Exported alters hooks do the magic.
  $overrides = array();

  // Exported overrides for: field_instance
  $overrides["field_instance.node-panopoly_page-body.display|related_contents"] = array(
    'label' => 'above',
    'settings' => array(),
    'type' => 'hidden',
    'weight' => 0,
  );
  $overrides["field_instance.node-panopoly_page-field_featured_categories.display|related_contents"] = array(
    'label' => 'above',
    'settings' => array(),
    'type' => 'hidden',
    'weight' => 0,
  );
  $overrides["field_instance.node-panopoly_page-field_featured_image.display|related_contents"] = array(
    'label' => 'above',
    'settings' => array(),
    'type' => 'hidden',
    'weight' => 0,
  );
  $overrides["field_instance.node-panopoly_page-field_featured_status.display|related_contents"] = array(
    'label' => 'above',
    'settings' => array(),
    'type' => 'hidden',
    'weight' => 0,
  );

  // Exported overrides for: taxonomy
  $overrides["taxonomy.panopoly_categories.rdf_mapping"] = array(
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
  );

  // Exported overrides for: variable
  $overrides["variable.ctools_content_all_views.value"] = 1;
  $overrides["variable.page_manager_node_edit_disabled.value"] = TRUE;

 return $overrides;
}
