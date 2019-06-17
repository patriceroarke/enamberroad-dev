<?php
/**
 * @file
 * amberroad_press_release.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function amberroad_press_release_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "flexslider" && $api == "flexslider_default_preset") {
    return array("version" => "1");
  }
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_views_api().
 */
function amberroad_press_release_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}

/**
 * Implements hook_node_info().
 */
function amberroad_press_release_node_info() {
  $items = array(
    'press_release' => array(
      'name' => t('Press Releases'),
      'base' => 'node_content',
      'description' => t('Create Press Release contents.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}
