<?php

/**
 * @file
 * File for all the specific heatmap methods
 */
 
/*
 * For temporary saving to memcache
 */
function heatmap_temp_memcache($data) {
  $memcachebin = variable_get('cache_default_class', 'MemCacheBin');
  
  if($data['id']) {
    $cid = $data['id'];
  } else {
    // Randomize an unique CID
    $cid = 'heatmap_' . md5(microtime());
    // Save the key to a key array
    heatmap_temp_save_index($cid);
  }

  // Save the data to memcache
  $cache = cache_set($cid, json_encode($data), $memcachebin);
  return $cid;
}

/*
 * For saving a key to a memcache index (I know of the ugly namespace solution, but lets keep it simple and clean)
 */
function heatmap_temp_save_index($cid) {
  $memcachebin = variable_get('cache_default_class', 'MemCacheBin');
  $cache = cache_get('heatmap_bin', $memcachebin);

  $array = array();
  if($cache) {
    $array = json_decode($cache->data);
  }

  $array[] = $cid;
  cache_set('heatmap_bin', json_encode($array), $memcachebin);
}

/*
 * For flushing to the normal database
 */
function heatmap_cache_to_persistant() {
  $memcachebin = variable_get('cache_default_class', 'MemCacheBin');
  $cache = cache_get('heatmap_bin', $memcachebin);
  $savedata = array();
  
  if($cache) {
    $databucket = json_decode($cache->data);

    foreach($databucket as $cid) {
      $rawdata = cache_get($cid, $memcachebin);
      if($rawdata) {
        $data = json_decode($rawdata->data);
        // Make unique key to aggregate data
        $key = md5($data->navigator . '_' . $data->browser_width . '_' . $data->browser_language . '_' . $data->url . '_' . $data->country);
        $savedata[$key]['browser_width'] = $data->browser_width;
        $savedata[$key]['browser_language'] = $data->browser_language;
        $savedata[$key]['url'] = $data->url;
        $savedata[$key]['navigator'] = $data->navigator;
        $savedata[$key]['country'] = $data->country;
        
        $mouse_moves = json_decode($data->mousedata);
        $clicks = json_decode($data->clickdata);
        $lowest = json_decode($data->positiondata);

        $savedata[$key]['mousedata'] = array();
        foreach($mouse_moves as $move) {
          $savedata[$key]['mousedata'][$move->x . '_' . $move->y] = isset($savedata[$key]['mouse_moves'][$move->x . '_' . $move->y]) ? $savedata[$key]['mouse_moves'][$move->x . '_' . $move->y] + $move->value : $move->value;
        }
        
        $savedata[$key]['clickdata'] = array();
        foreach($clicks as $click) {
          $savedata[$key]['clickdata'][$click->x . '_' . $click->y] = isset($savedata[$key]['clicks'][$click->x . '_' . $click->y]) ? $savedata[$key]['clicks'][$click->x . '_' . $click->y] + $click->value : $click->value;
        }

        $savedata[$key]['lowest_position'] = array();
        foreach($lowest as $low => $value) {
          $savedata[$key]['lowest_position'][$low] = isset($savedata[$key]['lowest_position'][$low]) ? $savedata[$key]['lowest_position'][$low] + 1 : 1;
        }        
      }
      cache_clear_all($cid, $memcachebin);
    }
    cache_set('heatmap_bin', json_encode(array()), $memcachebin);
  }
  
  $returnarray = array();
  // Normalized each aggregated data
  foreach($savedata as $values) {
    $mousemoves = array();
    foreach($values['mousedata'] as $pixel => $amount) {
      $cord = explode('_', $pixel);
      $mousemoves[] = array('x' => $cord[0], 'y' => $cord[1], 'time' => $amount);
    }
    $values['mousedata'] = json_encode($mousemoves);
    
    $clicks = array();
    foreach($values['clickdata'] as $pixel => $amount) {
      $cord = explode('_', $pixel);
      $clicks[] = array('x' => $cord[0], 'y' => $cord[1], 'clicks' => $amount);
    }
    $values['clickdata'] = json_encode($clicks);
    $values['positiondata'] = json_encode($values['lowest_position']);
    unset($values['lowest_position']);
    $returnarray[] = $values;
  }
  
  module_invoke(variable_get('heatmap_storage_type', 'heatmap'), 'heatmap_batch', $returnarray);
}

/*
 * Determine browser (getbrowser()/browscap.ini eats too much memory)
 */
function heatmap_determine_browser() {
  if(strpos($_SERVER['HTTP_USER_AGENT'], 'MSIE') !== FALSE) {
    return 1;
  } elseif(strpos($_SERVER['HTTP_USER_AGENT'], 'Trident') !== FALSE) {
    return 1;
  } elseif(strpos($_SERVER['HTTP_USER_AGENT'], 'Firefox') !== FALSE) {
    return 2;
  } elseif(strpos($_SERVER['HTTP_USER_AGENT'], 'Chrome') !== FALSE) {
    return 3;
  } elseif(strpos($_SERVER['HTTP_USER_AGENT'], 'Opera Mini') !== FALSE) {
    return 4;
  } elseif(strpos($_SERVER['HTTP_USER_AGENT'], 'Opera') !== FALSE) {
    return 5;
  } elseif(strpos($_SERVER['HTTP_USER_AGENT'], 'Safari') !== FALSE) {
    return 6;
  } elseif(strpos($_SERVER['HTTP_USER_AGENT'], 'konqueror') !== FALSE) {
    return 7;
  } elseif(strpos($_SERVER['HTTP_USER_AGENT'], 'netscape') !== FALSE) {
    return 8;
  }
  return 0;
}

/*
 * Return Browser Array
 */
function heatmap_browser_array() {
  return array(
    '' => t('All Browsers'),
    '1' => t('Internet Explorer'),
    '2' => t('Mozilla Firefox'),
    '3' => t('Google Chrome'),
    '4' => t('Opera Mini'),
    '5' => t('Opera'),
    '6' => t('Safari'),
    '7' => t('Konqueror'),
    '8' => t('Netscape'),
    '0' => t('Other')
  );
}

/*
 * For combining mouse data and click data
 */
function heatmap_combine_data($data1, $data2) {
  $newdata = array();
  foreach($data1 as $values) {
    $value = isset($values->value) ? $values->value : 1;
    if(isset($values->x) && isset($values->y)) {
      $newdata[$values->x . '_' . $values->y] = $value;
    }
  }
  
  foreach($data2 as $values) {
    $value = isset($values->value) ? $values->value : 1;
    if(isset($values->x) && isset($values->y)) {
      $newdata[$values->x . '_' . $values->y] = isset($newdata[$values->x . '_' . $values->y]) ? $newdata[$values->x . '_' . $values->y] + $value : $value;
    }
  }
  
  $returndata = array();
  foreach($newdata as $key => $value) {
    $cord = explode('_', $key);
    $returndata[] = array('x' => $cord[0], 'y' => $cord[1], 'value' => $value);
  }
  
  return $returndata;
}

/*
 * For combining position data
 */
function heatmap_combine_positiondata($data1, $data2) {
  $returndata = array();
  foreach($data1 as $key => $value) {
    $returndata[$key] = isset($returndata[$key]) ? $returndata[$key] + $value : $value;
  }
  
  foreach($data2 as $key => $value) {
    $returndata[$key] = isset($returndata[$key]) ? $returndata[$key] + $value : $value;
  }
  
  return $returndata;
}