<?php
/**
 * @file
 * amberroad_solution_area.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function amberroad_solution_area_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "field_group" && $api == "field_group") {
    return array("version" => "1");
  }
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_views_api().
 */
function amberroad_solution_area_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}

/**
 * Implements hook_node_info().
 */
function amberroad_solution_area_node_info() {
  $items = array(
    'solution_area' => array(
      'name' => t('Solution Area'),
      'base' => 'node_content',
      'description' => t('Add content related to solution area.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}
