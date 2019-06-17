<?php
/**
 * @file
 * amberroad_bean.features.uuid_bean.inc
 */

/**
 * Implements hook_uuid_features_default_beans().
 */
function amberroad_bean_uuid_features_default_beans() {
  $beans = array();

  $beans[] = array(
    'label' => 'Homepage Featured Block',
    'description' => NULL,
    'title' => 'Featured',
    'type' => 'homepage_featured_block',
    'data' => array(
      'view_mode' => 'default',
    ),
    'delta' => 'homepage-featured-block',
    'view_mode' => 'default',
    'created' => 1435834539,
    'log' => '',
    'uid' => 1,
    'default_revision' => 1,
    'revisions' => array(),
    'vuuid' => 'c42e21da-0393-4b32-a0f4-057874166c87',
    'uuid' => 'a5f7e757-ecf4-49b7-a4c2-48ce8c44db63',
    'field_block_image' => array(
      'und' => array(
        0 => array(
          'fid' => NULL,
          'uid' => 1,
          'filename' => 'featured_SC_Insights.jpg',
          'uri' => 'public://featured_SC_Insights.jpg',
          'filemime' => 'image/jpeg',
          'filesize' => 19715,
          'status' => 1,
          'timestamp' => NULL,
          'uuid' => 'e76341a7-0b59-471d-94ea-914172cd6bc6',
          'rdf_mapping' => array(),
          'alt' => '',
          'title' => '',
          'width' => 333,
          'height' => 230,
          'uuid_features_file_path' => 'profiles/amberroad/uuid_features_assets/featured_SC_Insights.jpg',
        ),
      ),
    ),
    'field_link' => array(
      'und' => array(
        0 => array(
          'url' => 'http://info.amberroad.com/rl_SC-Insights-Imports-and-Exports-Made-Easier-with-GTM.html',
          'title' => NULL,
          'attributes' => array(),
        ),
      ),
    ),
  );
  return $beans;
}
