<?php
/**
 * @file
 * amberroad_testimonial.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function amberroad_testimonial_field_group_info() {
  $field_groups = array();

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_translate|node|testimonial|form';
  $field_group->group_name = 'group_translate';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'testimonial';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Translations',
    'weight' => '7',
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
  $field_groups['group_translate|node|testimonial|form'] = $field_group;

  // Translatables
  // Included for use with string extractors like potx.
  t('Translations');

  return $field_groups;
}
