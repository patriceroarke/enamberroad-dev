<?php

/**
 * @file
 * Page for saving tracking data.
 */

/**
 * Page that the javascript posts the data to.
 */
function heatmap_track() {
  module_load_include('inc', 'heatmap', 'heatmap.api');
  
  $params = drupal_get_query_parameters($_REQUEST);
  $var = array(
    'navigator' => heatmap_determine_browser(),
    'browser_width' => isset($params['width']) ? (int) $params['width'] : 0,
    'browser_language' => isset($params['browser_language']) ? $params['browser_language'] : '',
    'mousedata' => isset($params['mouse_moves']) ? $params['mouse_moves'] : '',
    'clickdata' => isset($params['clicks']) ? $params['clicks'] : '',
    'url' => isset($params['href']) ? trim($params['href'], '/') : '',
    'positiondata' => isset($params['lowest_position']) ? json_encode(array($params['lowest_position'] => 1)) : json_encode(array()) ,
    'id' => isset($params['id']) ? $params['id'] : '',
    'country' => module_exists('geoip') ? geoip_country_code() : '',
  );
  
  $id = false;
  
  // If memcache enabled, save temporary
  if(variable_get('heatmap_memcache_enabled', '0')) {
      $id = heatmap_temp_memcache($var);
      // Write mecache to persistant every 5 minutes
      if(variable_get('heatmap_lastrun', 0) < time()) {
        heatmap_cache_to_persistant();
        variable_set('heatmap_lastrun', time() + variable_get('heatmap_memcache_batch_time', '300'));
      }    
  } else {
    // Otherwise invoke the current storage engine
    $id = module_invoke(variable_get('heatmap_storage_type', 'heatmap'), 'heatmap_single', $var);
  }
  
  if ($id) {
    drupal_json_output(array('status' => 'ok', 'id' => $id));
  } else {
    drupal_json_output(array('status' => 'error'));
  } 
}