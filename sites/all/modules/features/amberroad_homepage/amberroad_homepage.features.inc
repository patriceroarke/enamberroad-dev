<?php
/**
 * @file
 * amberroad_homepage.features.inc
 */

/**
 * Implements hook_entityqueue_api().
 */
function amberroad_homepage_entityqueue_api($module = NULL, $api = NULL) {
  if ($module == "entityqueue" && $api == "entityqueue_default") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_views_api().
 */
function amberroad_homepage_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}

/**
 * Implements hook_image_default_styles().
 */
function amberroad_homepage_image_default_styles() {
  $styles = array();

  // Exported image style: homepage_block.
  $styles['homepage_block'] = array(
    'label' => 'Homepage block (318x230)',
    'effects' => array(
      1 => array(
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 318,
          'height' => 230,
        ),
        'weight' => 1,
      ),
    ),
  );

  return $styles;
}
