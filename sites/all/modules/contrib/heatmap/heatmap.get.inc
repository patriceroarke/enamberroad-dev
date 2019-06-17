<?php

/**
 * @file
 * Page for outputting the heatmap data.
 */

/**
 * JSON output of heatmap
 */
function heatmap_get() {
  $params = drupal_get_query_parameters();
  // Invoke the storage engine
  $result = module_invoke(variable_get('heatmap_storage_type', 'heatmap'), 'heatmap_get', $params);

  // Auto-aggregate data that is not aggregated and make sure that x is correct for all
  $minscroll = 10000;
  $maxscroll = 0;
  $outputdata = array();
  $mousedata = array();
  foreach($result as $row) {
    if ($params['type'] == 3) {
      $tempdata = json_decode($row->positiondata);
      foreach($tempdata as $key => $value) {
        if($key > $maxscroll) $maxscroll = $key;
        if($key < $minscroll) $minscroll = $key;
        $outputdata[$key] = isset($outputdata[$key]) ? $outputdata[$key] + 1 : 1;
      }
    } elseif ($params['type'] == 2) {
      $tempdata = json_decode($row->clickdata);
      foreach($tempdata as $temp) {
        if ($params['width'] == 'all') {
          switch($params['windowtype']) {
            case 1:
              $x = $temp->x;
              break;
            case 2:
              $diff = 0;
              if($params['windowwidth'] > $params['divwidth']) {
                $diff = round(($params['windowwidth']-$row->browser_width)/2);
              }
              $x = $temp->x + $diff;
              break;
          }
        } else {
          $x = $temp->x;
        }
        $outputdata[$x . '_' . $temp->y] = isset($outputdata[$x . '_' . $temp->y]) ? $outputdata[$x . '_' . $temp->y] + $temp->value : $temp->value;
      }
    } else {
      $tempdata = json_decode($row->mousedata);
      foreach($tempdata as $temp) {
        if ($params['width'] == 'all') {
          switch($params['windowtype']) {
            case 1:
              $x = $temp->x;
              break;
            case 2:
              $diff = 0;
              if($params['windowwidth'] > $params['divwidth']) {
                $diff = round(($params['windowwidth']-$row->browser_width)/2);
              }
              $x = $temp->x + $diff;
              break;
          }
        } else {
          $x = $temp->x;
        }      
        $outputdata[$x . '_' . $temp->y] = isset($outputdata[$x . '_' . $temp->y]) ? $outputdata[$x . '_' . $temp->y] + $temp->value : $temp->value;
      }
    }
  }
  
  
  $total = 0;
  ksort($outputdata);
  $output['data'] = array();
  if ($params['type'] == 3) {
    foreach($outputdata as $key => $clicks ) {
      $total = $total + $clicks;
      $output['data'][] = array('y' => $key, 'value' => $clicks);
    }    
    $output['minscroll'] = $minscroll;
    $output['maxscroll'] = $maxscroll;
    $output['total'] = $total; 
  } else {
    $maxvalue = 0;
    foreach($outputdata as $key => $clicks ) {
      if($clicks > $maxvalue) $maxvalue = $clicks;
      $cord = explode('_', $key);
      $output['data'][] = array('x' => $cord[0], 'y' => $cord[1], 'value' => $clicks);
    }    
    $output['max'] = $maxvalue;
  }  

  drupal_json_output($output);
}