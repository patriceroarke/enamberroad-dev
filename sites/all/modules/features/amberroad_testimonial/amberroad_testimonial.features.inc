<?php
/**
 * @file
 * amberroad_testimonial.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function amberroad_testimonial_ctools_plugin_api($module = NULL, $api = NULL) {
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
function amberroad_testimonial_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}

/**
 * Implements hook_node_info().
 */
function amberroad_testimonial_node_info() {
  $items = array(
    'testimonial' => array(
      'name' => t('Testimonial'),
      'base' => 'node_content',
      'description' => t('Add client testimonial.'),
      'has_title' => '1',
      'title_label' => t('Client Name'),
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}
