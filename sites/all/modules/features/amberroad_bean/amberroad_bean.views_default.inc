<?php
/**
 * @file
 * amberroad_bean.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function amberroad_bean_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'homepage_featured_block';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'bean';
  $view->human_name = 'Homepage Featured Block';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Homepage Featured Block';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'none';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '1';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Field: Block: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'bean';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  /* Field: Block: Link */
  $handler->display->display_options['fields']['field_link']['id'] = 'field_link';
  $handler->display->display_options['fields']['field_link']['table'] = 'field_data_field_link';
  $handler->display->display_options['fields']['field_link']['field'] = 'field_link';
  $handler->display->display_options['fields']['field_link']['label'] = '';
  $handler->display->display_options['fields']['field_link']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_link']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_link']['click_sort_column'] = 'url';
  $handler->display->display_options['fields']['field_link']['type'] = 'link_absolute';
  /* Field: Block: Block Image */
  $handler->display->display_options['fields']['field_block_image']['id'] = 'field_block_image';
  $handler->display->display_options['fields']['field_block_image']['table'] = 'field_data_field_block_image';
  $handler->display->display_options['fields']['field_block_image']['field'] = 'field_block_image';
  $handler->display->display_options['fields']['field_block_image']['label'] = '';
  $handler->display->display_options['fields']['field_block_image']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['field_block_image']['alter']['path'] = '[field_link]';
  $handler->display->display_options['fields']['field_block_image']['alter']['target'] = '_blank';
  $handler->display->display_options['fields']['field_block_image']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_block_image']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_block_image']['settings'] = array(
    'image_style' => '',
    'image_link' => '',
  );
  /* Filter criterion: Block: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'bean';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'homepage_featured_block' => 'homepage_featured_block',
  );

  /* Display: Block */
  $handler = $view->new_display('block', 'Block', 'block');
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Block: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'bean';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  /* Field: Block: Link */
  $handler->display->display_options['fields']['field_link']['id'] = 'field_link';
  $handler->display->display_options['fields']['field_link']['table'] = 'field_data_field_link';
  $handler->display->display_options['fields']['field_link']['field'] = 'field_link';
  $handler->display->display_options['fields']['field_link']['label'] = '';
  $handler->display->display_options['fields']['field_link']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_link']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_link']['click_sort_column'] = 'url';
  $handler->display->display_options['fields']['field_link']['type'] = 'link_absolute';
  /* Field: Block: Block Image */
  $handler->display->display_options['fields']['field_block_image']['id'] = 'field_block_image';
  $handler->display->display_options['fields']['field_block_image']['table'] = 'field_data_field_block_image';
  $handler->display->display_options['fields']['field_block_image']['field'] = 'field_block_image';
  $handler->display->display_options['fields']['field_block_image']['label'] = '';
  $handler->display->display_options['fields']['field_block_image']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['field_block_image']['alter']['path'] = '[field_link]';
  $handler->display->display_options['fields']['field_block_image']['alter']['target'] = '_blank';
  $handler->display->display_options['fields']['field_block_image']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_block_image']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_block_image']['settings'] = array(
    'image_style' => 'homepage_block',
    'image_link' => '',
  );
  $export['homepage_featured_block'] = $view;

  return $export;
}
