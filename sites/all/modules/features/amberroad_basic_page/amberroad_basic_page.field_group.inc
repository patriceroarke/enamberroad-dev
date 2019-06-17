<?php
/**
 * @file
 * amberroad_basic_page.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function amberroad_basic_page_field_group_info() {
  $field_groups = array();

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_banner_caption|node|page|form';
  $field_group->group_name = 'group_banner_caption';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'page';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Banner Caption',
    'weight' => '7',
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
  $field_groups['group_banner_caption|node|page|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_header|node|page|form';
  $field_group->group_name = 'group_header';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'page';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Header',
    'weight' => '6',
    'children' => array(
      0 => 'field_header_image',
      1 => 'field_header_link',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-header field-group-fieldset',
        'required_fields' => 1,
      ),
    ),
  );
  $field_groups['group_header|node|page|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_translate|node|page|form';
  $field_group->group_name = 'group_translate';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'page';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Translations',
    'weight' => '2',
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
  $field_groups['group_translate|node|page|form'] = $field_group;

  // Translatables
  // Included for use with string extractors like potx.
  t('Banner Caption');
  t('Header');
  t('Translations');

  return $field_groups;
}
