<?php
/**
 * @file
 * amberroad_panels.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function amberroad_panels_field_group_info() {
  $field_groups = array();

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_video|fieldable_panels_pane|box|form';
  $field_group->group_name = 'group_video';
  $field_group->entity_type = 'fieldable_panels_pane';
  $field_group->bundle = 'box';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Video',
    'weight' => '8',
    'children' => array(
      0 => 'field_video',
      1 => 'field_video_height',
      2 => 'field_video_width',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-video field-group-fieldset',
        'required_fields' => 1,
        'id' => '',
      ),
    ),
  );
  $field_groups['group_video|fieldable_panels_pane|box|form'] = $field_group;

  // Translatables
  // Included for use with string extractors like potx.
  t('Video');

  return $field_groups;
}
