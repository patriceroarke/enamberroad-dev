<?php
/**
 * @file
 * amberroad_solution_area.features.field_base.inc
 */

/**
 * Implements hook_field_default_field_bases().
 */
function amberroad_solution_area_field_default_field_bases() {
  $field_bases = array();

  // Exported field_base: 'field_ad_new_window'.
  $field_bases['field_ad_new_window'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_ad_new_window',
    'indexes' => array(
      'value' => array(
        0 => 'value',
      ),
    ),
    'locked' => 0,
    'module' => 'list',
    'settings' => array(
      'allowed_values' => array(
        0 => '',
        1 => 'Open in new window',
      ),
      'allowed_values_function' => '',
    ),
    'translatable' => 0,
    'type' => 'list_boolean',
  );

  return $field_bases;
}
