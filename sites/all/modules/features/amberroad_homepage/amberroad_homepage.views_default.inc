<?php
/**
 * @file
 * amberroad_homepage.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function amberroad_homepage_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'homepage_blocks';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Homepage Blocks';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Homepage Blocks';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '1';
  $handler->display->display_options['pager']['options']['offset'] = '';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  /* Sort criterion: Content: Post date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;

  /* Display: New Webinar */
  $handler = $view->new_display('block', 'New Webinar', 'webinar_block');
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  /* Relationship: Entityqueue: Content Queue */
  $handler->display->display_options['relationships']['entityqueue_relationship']['id'] = 'entityqueue_relationship';
  $handler->display->display_options['relationships']['entityqueue_relationship']['table'] = 'node';
  $handler->display->display_options['relationships']['entityqueue_relationship']['field'] = 'entityqueue_relationship';
  $handler->display->display_options['relationships']['entityqueue_relationship']['required'] = TRUE;
  $handler->display->display_options['relationships']['entityqueue_relationship']['limit'] = 1;
  $handler->display->display_options['relationships']['entityqueue_relationship']['queues'] = array(
    'upcoming_webinar' => 'upcoming_webinar',
    'slideshow' => 0,
    'upcoming_event' => 0,
  );
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: External Link */
  $handler->display->display_options['fields']['field_event_link']['id'] = 'field_event_link';
  $handler->display->display_options['fields']['field_event_link']['table'] = 'field_data_field_event_link';
  $handler->display->display_options['fields']['field_event_link']['field'] = 'field_event_link';
  $handler->display->display_options['fields']['field_event_link']['label'] = '';
  $handler->display->display_options['fields']['field_event_link']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_event_link']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_event_link']['hide_empty'] = TRUE;
  $handler->display->display_options['fields']['field_event_link']['hide_alter_empty'] = FALSE;
  $handler->display->display_options['fields']['field_event_link']['click_sort_column'] = 'url';
  $handler->display->display_options['fields']['field_event_link']['type'] = 'link_url';
  /* Field: Content: Webinar Logo */
  $handler->display->display_options['fields']['field_event_logo']['id'] = 'field_event_logo';
  $handler->display->display_options['fields']['field_event_logo']['table'] = 'field_data_field_event_logo';
  $handler->display->display_options['fields']['field_event_logo']['field'] = 'field_event_logo';
  $handler->display->display_options['fields']['field_event_logo']['label'] = '';
  $handler->display->display_options['fields']['field_event_logo']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_event_logo']['hide_empty'] = TRUE;
  $handler->display->display_options['fields']['field_event_logo']['hide_alter_empty'] = FALSE;
  $handler->display->display_options['fields']['field_event_logo']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_event_logo']['settings'] = array(
    'image_style' => '',
    'image_link' => 'content',
  );
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['title']['alter']['path'] = '[field_event_link]';
  $handler->display->display_options['fields']['title']['alter']['target'] = '_blank';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['hide_empty'] = TRUE;
  $handler->display->display_options['fields']['title']['hide_alter_empty'] = FALSE;
  $handler->display->display_options['fields']['title']['link_to_node'] = FALSE;
  /* Field: Content: Body */
  $handler->display->display_options['fields']['body']['id'] = 'body';
  $handler->display->display_options['fields']['body']['table'] = 'field_data_body';
  $handler->display->display_options['fields']['body']['field'] = 'body';
  $handler->display->display_options['fields']['body']['label'] = '';
  $handler->display->display_options['fields']['body']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['body']['hide_empty'] = TRUE;
  $handler->display->display_options['fields']['body']['hide_alter_empty'] = FALSE;
  $handler->display->display_options['fields']['body']['type'] = 'text_trimmed';
  $handler->display->display_options['fields']['body']['settings'] = array(
    'trim_length' => '300',
  );
  /* Field: Content: Date and Time */
  $handler->display->display_options['fields']['field_event_date_and_time']['id'] = 'field_event_date_and_time';
  $handler->display->display_options['fields']['field_event_date_and_time']['table'] = 'field_data_field_event_date_and_time';
  $handler->display->display_options['fields']['field_event_date_and_time']['field'] = 'field_event_date_and_time';
  $handler->display->display_options['fields']['field_event_date_and_time']['label'] = '';
  $handler->display->display_options['fields']['field_event_date_and_time']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_event_date_and_time']['hide_empty'] = TRUE;
  $handler->display->display_options['fields']['field_event_date_and_time']['hide_alter_empty'] = FALSE;
  $handler->display->display_options['fields']['field_event_date_and_time']['settings'] = array(
    'format_type' => 'long',
    'fromto' => 'both',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
  );
  /* Field: Content: Block Image */
  $handler->display->display_options['fields']['field_event_block_image']['id'] = 'field_event_block_image';
  $handler->display->display_options['fields']['field_event_block_image']['table'] = 'field_data_field_event_block_image';
  $handler->display->display_options['fields']['field_event_block_image']['field'] = 'field_event_block_image';
  $handler->display->display_options['fields']['field_event_block_image']['label'] = '';
  $handler->display->display_options['fields']['field_event_block_image']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_event_block_image']['hide_empty'] = TRUE;
  $handler->display->display_options['fields']['field_event_block_image']['hide_alter_empty'] = FALSE;
  $handler->display->display_options['fields']['field_event_block_image']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_event_block_image']['settings'] = array(
    'image_style' => '',
    'image_link' => 'content',
  );
  /* Field: Global: Custom text */
  $handler->display->display_options['fields']['nothing']['id'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['table'] = 'views';
  $handler->display->display_options['fields']['nothing']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['label'] = '';
  $handler->display->display_options['fields']['nothing']['alter']['text'] = 'REGISTER NOW';
  $handler->display->display_options['fields']['nothing']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['nothing']['alter']['path'] = '[field_event_link]';
  $handler->display->display_options['fields']['nothing']['alter']['external'] = TRUE;
  $handler->display->display_options['fields']['nothing']['alter']['path_case'] = 'upper';
  $handler->display->display_options['fields']['nothing']['alter']['target'] = '_blank';
  $handler->display->display_options['fields']['nothing']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['nothing']['hide_empty'] = TRUE;
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'webinar' => 'webinar',
  );

  /* Display: Upcoming Events */
  $handler = $view->new_display('block', 'Upcoming Events', 'event_block');
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  /* Relationship: Entityqueue: Content Queue */
  $handler->display->display_options['relationships']['entityqueue_relationship']['id'] = 'entityqueue_relationship';
  $handler->display->display_options['relationships']['entityqueue_relationship']['table'] = 'node';
  $handler->display->display_options['relationships']['entityqueue_relationship']['field'] = 'entityqueue_relationship';
  $handler->display->display_options['relationships']['entityqueue_relationship']['required'] = TRUE;
  $handler->display->display_options['relationships']['entityqueue_relationship']['limit'] = 0;
  $handler->display->display_options['relationships']['entityqueue_relationship']['queues'] = array(
    'new_webinar' => 0,
    'upcoming_event' => 0,
  );
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: External Link */
  $handler->display->display_options['fields']['field_event_link']['id'] = 'field_event_link';
  $handler->display->display_options['fields']['field_event_link']['table'] = 'field_data_field_event_link';
  $handler->display->display_options['fields']['field_event_link']['field'] = 'field_event_link';
  $handler->display->display_options['fields']['field_event_link']['label'] = '';
  $handler->display->display_options['fields']['field_event_link']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_event_link']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_event_link']['hide_empty'] = TRUE;
  $handler->display->display_options['fields']['field_event_link']['hide_alter_empty'] = FALSE;
  $handler->display->display_options['fields']['field_event_link']['click_sort_column'] = 'url';
  $handler->display->display_options['fields']['field_event_link']['type'] = 'link_url';
  /* Field: Content: Webinar Logo */
  $handler->display->display_options['fields']['field_event_logo']['id'] = 'field_event_logo';
  $handler->display->display_options['fields']['field_event_logo']['table'] = 'field_data_field_event_logo';
  $handler->display->display_options['fields']['field_event_logo']['field'] = 'field_event_logo';
  $handler->display->display_options['fields']['field_event_logo']['label'] = '';
  $handler->display->display_options['fields']['field_event_logo']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_event_logo']['hide_empty'] = TRUE;
  $handler->display->display_options['fields']['field_event_logo']['hide_alter_empty'] = FALSE;
  $handler->display->display_options['fields']['field_event_logo']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_event_logo']['settings'] = array(
    'image_style' => '',
    'image_link' => 'content',
  );
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['title']['alter']['path'] = '[field_event_link]';
  $handler->display->display_options['fields']['title']['alter']['target'] = '_blank';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['hide_empty'] = TRUE;
  $handler->display->display_options['fields']['title']['hide_alter_empty'] = FALSE;
  $handler->display->display_options['fields']['title']['link_to_node'] = FALSE;
  /* Field: Content: Body */
  $handler->display->display_options['fields']['body']['id'] = 'body';
  $handler->display->display_options['fields']['body']['table'] = 'field_data_body';
  $handler->display->display_options['fields']['body']['field'] = 'body';
  $handler->display->display_options['fields']['body']['label'] = '';
  $handler->display->display_options['fields']['body']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['body']['hide_empty'] = TRUE;
  $handler->display->display_options['fields']['body']['hide_alter_empty'] = FALSE;
  $handler->display->display_options['fields']['body']['type'] = 'text_trimmed';
  $handler->display->display_options['fields']['body']['settings'] = array(
    'trim_length' => '300',
  );
  /* Field: Content: Date */
  $handler->display->display_options['fields']['field_event_date']['id'] = 'field_event_date';
  $handler->display->display_options['fields']['field_event_date']['table'] = 'field_data_field_event_date';
  $handler->display->display_options['fields']['field_event_date']['field'] = 'field_event_date';
  $handler->display->display_options['fields']['field_event_date']['label'] = '';
  $handler->display->display_options['fields']['field_event_date']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_event_date']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_event_date']['hide_empty'] = TRUE;
  $handler->display->display_options['fields']['field_event_date']['hide_alter_empty'] = FALSE;
  $handler->display->display_options['fields']['field_event_date']['settings'] = array(
    'format_type' => 'long',
    'fromto' => 'both',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
  );
  /* Field: Content: City and State */
  $handler->display->display_options['fields']['field_event_city_and_state']['id'] = 'field_event_city_and_state';
  $handler->display->display_options['fields']['field_event_city_and_state']['table'] = 'field_data_field_event_city_and_state';
  $handler->display->display_options['fields']['field_event_city_and_state']['field'] = 'field_event_city_and_state';
  $handler->display->display_options['fields']['field_event_city_and_state']['label'] = '';
  $handler->display->display_options['fields']['field_event_city_and_state']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_event_city_and_state']['alter']['text'] = '[field_event_date]<div class="field-event-city-and-state">[field_event_city_and_state]</div>';
  $handler->display->display_options['fields']['field_event_city_and_state']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_event_city_and_state']['hide_empty'] = TRUE;
  $handler->display->display_options['fields']['field_event_city_and_state']['hide_alter_empty'] = FALSE;
  /* Field: Content: Block Image */
  $handler->display->display_options['fields']['field_event_block_image']['id'] = 'field_event_block_image';
  $handler->display->display_options['fields']['field_event_block_image']['table'] = 'field_data_field_event_block_image';
  $handler->display->display_options['fields']['field_event_block_image']['field'] = 'field_event_block_image';
  $handler->display->display_options['fields']['field_event_block_image']['label'] = '';
  $handler->display->display_options['fields']['field_event_block_image']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_event_block_image']['hide_empty'] = TRUE;
  $handler->display->display_options['fields']['field_event_block_image']['hide_alter_empty'] = FALSE;
  $handler->display->display_options['fields']['field_event_block_image']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_event_block_image']['settings'] = array(
    'image_style' => 'homepage_block',
    'image_link' => 'content',
  );
  /* Field: Global: Custom text */
  $handler->display->display_options['fields']['nothing']['id'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['table'] = 'views';
  $handler->display->display_options['fields']['nothing']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['label'] = '';
  $handler->display->display_options['fields']['nothing']['alter']['text'] = 'CALENDAR';
  $handler->display->display_options['fields']['nothing']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['nothing']['alter']['path'] = '[field_event_link]';
  $handler->display->display_options['fields']['nothing']['alter']['path_case'] = 'upper';
  $handler->display->display_options['fields']['nothing']['alter']['target'] = '_blank';
  $handler->display->display_options['fields']['nothing']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['nothing']['hide_empty'] = TRUE;
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'industry_conference' => 'industry_conference',
    'seminar' => 'seminar',
  );
  $export['homepage_blocks'] = $view;

  return $export;
}
