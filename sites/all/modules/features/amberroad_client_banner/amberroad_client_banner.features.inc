<?php
/**
 * @file
 * amberroad_client_banner.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function amberroad_client_banner_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_views_api().
 */
function amberroad_client_banner_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}

/**
 * Implements hook_node_info().
 */
function amberroad_client_banner_node_info() {
  $items = array(
    'client_image' => array(
      'name' => t('Client Image'),
      'base' => 'node_content',
      'description' => t('Add client image shown in homepage.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}
