<?php
/**
 * @file
 * amberroad_events.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function amberroad_events_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_views_api().
 */
function amberroad_events_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}

/**
 * Implements hook_image_default_styles().
 */
function amberroad_events_image_default_styles() {
  $styles = array();

  // Exported image style: seminar_image.
  $styles['seminar_image'] = array(
    'label' => 'Seminar Image(200x200)',
    'effects' => array(
      1 => array(
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 200,
          'height' => 200,
        ),
        'weight' => 1,
      ),
    ),
  );

  return $styles;
}

/**
 * Implements hook_node_info().
 */
function amberroad_events_node_info() {
  $items = array(
    'industry_conference' => array(
      'name' => t('Industry Conference'),
      'base' => 'node_content',
      'description' => t('Add content related to Industry Conference.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
    'seminar' => array(
      'name' => t('Seminar'),
      'base' => 'node_content',
      'description' => t('Add content related to Seminar.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
    'webinar' => array(
      'name' => t('Webinar'),
      'base' => 'node_content',
      'description' => t('Add content related to Webinar.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}
