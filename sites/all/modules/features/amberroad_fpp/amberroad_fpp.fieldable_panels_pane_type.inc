<?php
/**
 * @file
 * amberroad_fpp.fieldable_panels_pane_type.inc
 */

/**
 * Implements hook_default_fieldable_panels_pane_type().
 */
function amberroad_fpp_default_fieldable_panels_pane_type() {
  $export = array();

  $fieldable_panels_pane_type = new stdClass();
  $fieldable_panels_pane_type->disabled = FALSE; /* Edit this to true to make a default fieldable_panels_pane_type disabled initially */
  $fieldable_panels_pane_type->api_version = 1;
  $fieldable_panels_pane_type->name = 'fieldable_panels_pane';
  $fieldable_panels_pane_type->title = 'Panels Pane';
  $fieldable_panels_pane_type->description = '';
  $export['fieldable_panels_pane'] = $fieldable_panels_pane_type;

  $fieldable_panels_pane_type = new stdClass();
  $fieldable_panels_pane_type->disabled = FALSE; /* Edit this to true to make a default fieldable_panels_pane_type disabled initially */
  $fieldable_panels_pane_type->api_version = 1;
  $fieldable_panels_pane_type->name = 'video_and_text';
  $fieldable_panels_pane_type->title = 'Video and Text';
  $fieldable_panels_pane_type->description = '';
  $export['video_and_text'] = $fieldable_panels_pane_type;

  return $export;
}
