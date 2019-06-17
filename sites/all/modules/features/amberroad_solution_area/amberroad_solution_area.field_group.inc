<?php
/**
 * @file
 * amberroad_solution_area.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function amberroad_solution_area_field_group_info() {
  $field_groups = array();

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_banner_caption|node|solution_area|form';
  $field_group->group_name = 'group_banner_caption';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'solution_area';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Banner Caption',
    'weight' => '8',
    'children' => array(
      0 => 'field_banner_image',
      1 => 'field_caption_title',
      2 => 'field_caption_descrption',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-banner-caption field-group-fieldset',
        'required_fields' => 1,
      ),
    ),
  );
  $field_groups['group_banner_caption|node|solution_area|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_related_content|node|solution_area|form';
  $field_group->group_name = 'group_related_content';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'solution_area';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Related Content',
    'weight' => '2',
    'children' => array(
      0 => 'field_related_content_descriptio',
      1 => 'field_related_solution_area_cont',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-related-content field-group-fieldset',
        'required_fields' => 1,
      ),
    ),
  );
  $field_groups['group_related_content|node|solution_area|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_translate|node|solution_area|form';
  $field_group->group_name = 'group_translate';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'solution_area';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Translations',
    'weight' => '4',
    'children' => array(
      0 => 'field_chinese_translation_link',
      1 => 'field_english_translation_link',
      2 => 'field_translation_link',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-translate field-group-fieldset',
        'required_fields' => 1,
      ),
    ),
  );
  $field_groups['group_translate|node|solution_area|form'] = $field_group;

  // Translatables
  // Included for use with string extractors like potx.
  t('Banner Caption');
  t('Related Content');
  t('Translations');

  return $field_groups;
}
