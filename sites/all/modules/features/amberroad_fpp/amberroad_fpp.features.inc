<?php
/**
 * @file
 * amberroad_fpp.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function amberroad_fpp_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "fieldable_panels_panes" && $api == "fieldable_panels_pane_type") {
    return array("version" => "1");
  }
}