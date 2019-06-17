<?php
/**
 * @file
 * amberroad_events.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function amberroad_events_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'events';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Events';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Industry Conferences';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['row_options']['inline'] = array(
    'field_presenter' => 'field_presenter',
    'field_podcast_presented_by' => 'field_podcast_presented_by',
  );
  $handler->display->display_options['row_options']['separator'] = '(&nbsp;)';
  /* Field: Content: Webinar Logo */
  $handler->display->display_options['fields']['field_event_logo']['id'] = 'field_event_logo';
  $handler->display->display_options['fields']['field_event_logo']['table'] = 'field_data_field_event_logo';
  $handler->display->display_options['fields']['field_event_logo']['field'] = 'field_event_logo';
  $handler->display->display_options['fields']['field_event_logo']['label'] = '';
  $handler->display->display_options['fields']['field_event_logo']['alter']['path'] = '[field_event_link] ';
  $handler->display->display_options['fields']['field_event_logo']['alter']['absolute'] = TRUE;
  $handler->display->display_options['fields']['field_event_logo']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_event_logo']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_event_logo']['type'] = 'image_link_formatter';
  $handler->display->display_options['fields']['field_event_logo']['settings'] = array(
    'image_style' => '',
    'image_link' => 'content',
  );
  /* Field: Content: Body */
  $handler->display->display_options['fields']['body']['id'] = 'body';
  $handler->display->display_options['fields']['body']['table'] = 'field_data_body';
  $handler->display->display_options['fields']['body']['field'] = 'body';
  $handler->display->display_options['fields']['body']['label'] = '';
  $handler->display->display_options['fields']['body']['element_label_colon'] = FALSE;
  /* Field: Content: External Link */
  $handler->display->display_options['fields']['field_event_link']['id'] = 'field_event_link';
  $handler->display->display_options['fields']['field_event_link']['table'] = 'field_data_field_event_link';
  $handler->display->display_options['fields']['field_event_link']['field'] = 'field_event_link';
  $handler->display->display_options['fields']['field_event_link']['label'] = '';
  $handler->display->display_options['fields']['field_event_link']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_event_link']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_event_link']['click_sort_column'] = 'url';
  $handler->display->display_options['fields']['field_event_link']['type'] = 'link_url';
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
  $handler->display->display_options['fields']['title']['link_to_node'] = FALSE;
  /* Field: Content: Date */
  $handler->display->display_options['fields']['field_event_date']['id'] = 'field_event_date';
  $handler->display->display_options['fields']['field_event_date']['table'] = 'field_data_field_event_date';
  $handler->display->display_options['fields']['field_event_date']['field'] = 'field_event_date';
  $handler->display->display_options['fields']['field_event_date']['type'] = 'addtocal_view';
  $handler->display->display_options['fields']['field_event_date']['settings'] = array(
    'location_field' => '-1',
    'description_field' => '-1',
    'past_events' => 1,
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
  $handler->display->display_options['fields']['field_event_city_and_state']['element_label_colon'] = FALSE;
  /* Contextual filter: Content: Nid */
  $handler->display->display_options['arguments']['nid']['id'] = 'nid';
  $handler->display->display_options['arguments']['nid']['table'] = 'node';
  $handler->display->display_options['arguments']['nid']['field'] = 'nid';
  $handler->display->display_options['arguments']['nid']['default_action'] = 'default';
  $handler->display->display_options['arguments']['nid']['default_argument_type'] = 'node';
  $handler->display->display_options['arguments']['nid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['nid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['nid']['summary_options']['items_per_page'] = '25';
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;

  /* Display: Industry Conferences */
  $handler = $view->new_display('panel_pane', 'Industry Conferences', 'panel_industry_conference');
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Webinar Logo */
  $handler->display->display_options['fields']['field_event_logo']['id'] = 'field_event_logo';
  $handler->display->display_options['fields']['field_event_logo']['table'] = 'field_data_field_event_logo';
  $handler->display->display_options['fields']['field_event_logo']['field'] = 'field_event_logo';
  $handler->display->display_options['fields']['field_event_logo']['label'] = '';
  $handler->display->display_options['fields']['field_event_logo']['alter']['path'] = '[field_event_link] ';
  $handler->display->display_options['fields']['field_event_logo']['alter']['absolute'] = TRUE;
  $handler->display->display_options['fields']['field_event_logo']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_event_logo']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_event_logo']['settings'] = array(
    'image_style' => '',
    'image_link' => 'content',
  );
  /* Field: Content: External Link */
  $handler->display->display_options['fields']['field_event_link']['id'] = 'field_event_link';
  $handler->display->display_options['fields']['field_event_link']['table'] = 'field_data_field_event_link';
  $handler->display->display_options['fields']['field_event_link']['field'] = 'field_event_link';
  $handler->display->display_options['fields']['field_event_link']['label'] = '';
  $handler->display->display_options['fields']['field_event_link']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_event_link']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_event_link']['click_sort_column'] = 'url';
  $handler->display->display_options['fields']['field_event_link']['type'] = 'link_url';
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
  $handler->display->display_options['fields']['title']['link_to_node'] = FALSE;
  /* Field: Content: Date */
  $handler->display->display_options['fields']['field_event_date']['id'] = 'field_event_date';
  $handler->display->display_options['fields']['field_event_date']['table'] = 'field_data_field_event_date';
  $handler->display->display_options['fields']['field_event_date']['field'] = 'field_event_date';
  $handler->display->display_options['fields']['field_event_date']['label'] = '';
  $handler->display->display_options['fields']['field_event_date']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_event_date']['settings'] = array(
    'format_type' => 'event_date',
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
  $handler->display->display_options['fields']['field_event_city_and_state']['element_label_colon'] = FALSE;
  /* Field: Content: Body */
  $handler->display->display_options['fields']['body']['id'] = 'body';
  $handler->display->display_options['fields']['body']['table'] = 'field_data_body';
  $handler->display->display_options['fields']['body']['field'] = 'body';
  $handler->display->display_options['fields']['body']['label'] = '';
  $handler->display->display_options['fields']['body']['element_label_colon'] = FALSE;
  /* Field: Content: Nid */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['label'] = '';
  $handler->display->display_options['fields']['nid']['exclude'] = TRUE;
  $handler->display->display_options['fields']['nid']['element_label_colon'] = FALSE;
  /* Field: Calender */
  $handler->display->display_options['fields']['nothing']['id'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['table'] = 'views';
  $handler->display->display_options['fields']['nothing']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['ui_name'] = 'Calender';
  $handler->display->display_options['fields']['nothing']['label'] = '';
  $handler->display->display_options['fields']['nothing']['alter']['text'] = 'Add to your Outlook calendar';
  $handler->display->display_options['fields']['nothing']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['nothing']['alter']['path'] = 'calendar/[nid]/industry-conference.ics';
  $handler->display->display_options['fields']['nothing']['element_label_colon'] = FALSE;
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  /* Sort criterion: Content: Date -  start date (field_event_date) */
  $handler->display->display_options['sorts']['field_event_date_value']['id'] = 'field_event_date_value';
  $handler->display->display_options['sorts']['field_event_date_value']['table'] = 'field_data_field_event_date';
  $handler->display->display_options['sorts']['field_event_date_value']['field'] = 'field_event_date_value';
  $handler->display->display_options['defaults']['arguments'] = FALSE;
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
  );
  /* Filter criterion: Content: Date -  start date (field_event_date) */
  $handler->display->display_options['filters']['field_event_date_value']['id'] = 'field_event_date_value';
  $handler->display->display_options['filters']['field_event_date_value']['table'] = 'field_data_field_event_date';
  $handler->display->display_options['filters']['field_event_date_value']['field'] = 'field_event_date_value';
  $handler->display->display_options['filters']['field_event_date_value']['operator'] = '>=';
  $handler->display->display_options['filters']['field_event_date_value']['granularity'] = 'minute';
  $handler->display->display_options['filters']['field_event_date_value']['default_date'] = 'now -5 day';
  $handler->display->display_options['allow']['use_pager'] = 0;
  $handler->display->display_options['allow']['items_per_page'] = 0;
  $handler->display->display_options['allow']['offset'] = 0;
  $handler->display->display_options['allow']['link_to_view'] = 0;
  $handler->display->display_options['allow']['more_link'] = 0;
  $handler->display->display_options['allow']['path_override'] = 0;
  $handler->display->display_options['allow']['title_override'] = 'title_override';
  $handler->display->display_options['allow']['exposed_form'] = 0;
  $handler->display->display_options['allow']['fields_override'] = 0;

  /* Display: Seminars */
  $handler = $view->new_display('panel_pane', 'Seminars', 'panel_seminar');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Seminars';
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Webinar Logo */
  $handler->display->display_options['fields']['field_event_logo']['id'] = 'field_event_logo';
  $handler->display->display_options['fields']['field_event_logo']['table'] = 'field_data_field_event_logo';
  $handler->display->display_options['fields']['field_event_logo']['field'] = 'field_event_logo';
  $handler->display->display_options['fields']['field_event_logo']['label'] = '';
  $handler->display->display_options['fields']['field_event_logo']['alter']['path'] = '[field_event_link] ';
  $handler->display->display_options['fields']['field_event_logo']['alter']['absolute'] = TRUE;
  $handler->display->display_options['fields']['field_event_logo']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_event_logo']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_event_logo']['settings'] = array(
    'image_style' => 'seminar_image',
    'image_link' => 'content',
  );
  /* Field: Content: External Link */
  $handler->display->display_options['fields']['field_event_link']['id'] = 'field_event_link';
  $handler->display->display_options['fields']['field_event_link']['table'] = 'field_data_field_event_link';
  $handler->display->display_options['fields']['field_event_link']['field'] = 'field_event_link';
  $handler->display->display_options['fields']['field_event_link']['label'] = '';
  $handler->display->display_options['fields']['field_event_link']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_event_link']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_event_link']['click_sort_column'] = 'url';
  $handler->display->display_options['fields']['field_event_link']['type'] = 'link_url';
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
  $handler->display->display_options['fields']['title']['link_to_node'] = FALSE;
  /* Field: Content: City and State */
  $handler->display->display_options['fields']['field_event_city_and_state']['id'] = 'field_event_city_and_state';
  $handler->display->display_options['fields']['field_event_city_and_state']['table'] = 'field_data_field_event_city_and_state';
  $handler->display->display_options['fields']['field_event_city_and_state']['field'] = 'field_event_city_and_state';
  $handler->display->display_options['fields']['field_event_city_and_state']['label'] = '';
  $handler->display->display_options['fields']['field_event_city_and_state']['element_label_colon'] = FALSE;
  /* Field: Content: Date */
  $handler->display->display_options['fields']['field_event_date']['id'] = 'field_event_date';
  $handler->display->display_options['fields']['field_event_date']['table'] = 'field_data_field_event_date';
  $handler->display->display_options['fields']['field_event_date']['field'] = 'field_event_date';
  $handler->display->display_options['fields']['field_event_date']['label'] = '';
  $handler->display->display_options['fields']['field_event_date']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_event_date']['settings'] = array(
    'format_type' => 'event_date',
    'fromto' => 'both',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
  );
  /* Field: Content: Body */
  $handler->display->display_options['fields']['body']['id'] = 'body';
  $handler->display->display_options['fields']['body']['table'] = 'field_data_body';
  $handler->display->display_options['fields']['body']['field'] = 'body';
  $handler->display->display_options['fields']['body']['label'] = '';
  $handler->display->display_options['fields']['body']['element_label_colon'] = FALSE;
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  /* Sort criterion: Content: Date -  start date (field_event_date) */
  $handler->display->display_options['sorts']['field_event_date_value']['id'] = 'field_event_date_value';
  $handler->display->display_options['sorts']['field_event_date_value']['table'] = 'field_data_field_event_date';
  $handler->display->display_options['sorts']['field_event_date_value']['field'] = 'field_event_date_value';
  $handler->display->display_options['defaults']['arguments'] = FALSE;
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
    'seminar' => 'seminar',
  );
  $handler->display->display_options['allow']['use_pager'] = 0;
  $handler->display->display_options['allow']['items_per_page'] = 0;
  $handler->display->display_options['allow']['offset'] = 0;
  $handler->display->display_options['allow']['link_to_view'] = 0;
  $handler->display->display_options['allow']['more_link'] = 0;
  $handler->display->display_options['allow']['path_override'] = 0;
  $handler->display->display_options['allow']['title_override'] = 'title_override';
  $handler->display->display_options['allow']['exposed_form'] = 0;
  $handler->display->display_options['allow']['fields_override'] = 0;

  /* Display: Upcoming Webinars */
  $handler = $view->new_display('panel_pane', 'Upcoming Webinars', 'panel_webinar');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Upcoming Webinars';
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Webinar Logo */
  $handler->display->display_options['fields']['field_event_logo']['id'] = 'field_event_logo';
  $handler->display->display_options['fields']['field_event_logo']['table'] = 'field_data_field_event_logo';
  $handler->display->display_options['fields']['field_event_logo']['field'] = 'field_event_logo';
  $handler->display->display_options['fields']['field_event_logo']['label'] = '';
  $handler->display->display_options['fields']['field_event_logo']['alter']['path'] = '[field_event_link] ';
  $handler->display->display_options['fields']['field_event_logo']['alter']['absolute'] = TRUE;
  $handler->display->display_options['fields']['field_event_logo']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_event_logo']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_event_logo']['settings'] = array(
    'image_style' => 'seminar_image',
    'image_link' => 'content',
  );
  /* Field: Content: External Link */
  $handler->display->display_options['fields']['field_event_link']['id'] = 'field_event_link';
  $handler->display->display_options['fields']['field_event_link']['table'] = 'field_data_field_event_link';
  $handler->display->display_options['fields']['field_event_link']['field'] = 'field_event_link';
  $handler->display->display_options['fields']['field_event_link']['label'] = '';
  $handler->display->display_options['fields']['field_event_link']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_event_link']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_event_link']['click_sort_column'] = 'url';
  $handler->display->display_options['fields']['field_event_link']['type'] = 'link_url';
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
  $handler->display->display_options['fields']['title']['link_to_node'] = FALSE;
  /* Field: Content: Hosted By */
  $handler->display->display_options['fields']['field_event_hosted_by']['id'] = 'field_event_hosted_by';
  $handler->display->display_options['fields']['field_event_hosted_by']['table'] = 'field_data_field_event_hosted_by';
  $handler->display->display_options['fields']['field_event_hosted_by']['field'] = 'field_event_hosted_by';
  $handler->display->display_options['fields']['field_event_hosted_by']['element_type'] = 'span';
  $handler->display->display_options['fields']['field_event_hosted_by']['element_label_colon'] = FALSE;
  /* Field: Content: Date and Time */
  $handler->display->display_options['fields']['field_event_date_and_time']['id'] = 'field_event_date_and_time';
  $handler->display->display_options['fields']['field_event_date_and_time']['table'] = 'field_data_field_event_date_and_time';
  $handler->display->display_options['fields']['field_event_date_and_time']['field'] = 'field_event_date_and_time';
  $handler->display->display_options['fields']['field_event_date_and_time']['label'] = 'Broadcasting Live on';
  $handler->display->display_options['fields']['field_event_date_and_time']['element_type'] = 'span';
  $handler->display->display_options['fields']['field_event_date_and_time']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_event_date_and_time']['settings'] = array(
    'format_type' => 'long',
    'fromto' => 'both',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
  );
  /* Field: Content: Body */
  $handler->display->display_options['fields']['body']['id'] = 'body';
  $handler->display->display_options['fields']['body']['table'] = 'field_data_body';
  $handler->display->display_options['fields']['body']['field'] = 'body';
  $handler->display->display_options['fields']['body']['label'] = '';
  $handler->display->display_options['fields']['body']['element_label_colon'] = FALSE;
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  /* Sort criterion: Content: Date and Time -  start date (field_event_date_and_time) */
  $handler->display->display_options['sorts']['field_event_date_and_time_value']['id'] = 'field_event_date_and_time_value';
  $handler->display->display_options['sorts']['field_event_date_and_time_value']['table'] = 'field_data_field_event_date_and_time';
  $handler->display->display_options['sorts']['field_event_date_and_time_value']['field'] = 'field_event_date_and_time_value';
  $handler->display->display_options['defaults']['arguments'] = FALSE;
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
  /* Filter criterion: Content: Date and Time -  start date (field_event_date_and_time) */
  $handler->display->display_options['filters']['field_event_date_and_time_value']['id'] = 'field_event_date_and_time_value';
  $handler->display->display_options['filters']['field_event_date_and_time_value']['table'] = 'field_data_field_event_date_and_time';
  $handler->display->display_options['filters']['field_event_date_and_time_value']['field'] = 'field_event_date_and_time_value';
  $handler->display->display_options['filters']['field_event_date_and_time_value']['operator'] = '>=';
  $handler->display->display_options['filters']['field_event_date_and_time_value']['default_date'] = 'now';
  $handler->display->display_options['allow']['use_pager'] = 0;
  $handler->display->display_options['allow']['items_per_page'] = 0;
  $handler->display->display_options['allow']['offset'] = 0;
  $handler->display->display_options['allow']['link_to_view'] = 0;
  $handler->display->display_options['allow']['more_link'] = 0;
  $handler->display->display_options['allow']['path_override'] = 0;
  $handler->display->display_options['allow']['title_override'] = 'title_override';
  $handler->display->display_options['allow']['exposed_form'] = 0;
  $handler->display->display_options['allow']['fields_override'] = 0;

  /* Display: ical Feeds */
  $handler = $view->new_display('feed', 'ical Feeds', 'feed_1');
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'date_ical';
  $handler->display->display_options['style_options']['cal_name'] = '';
  $handler->display->display_options['style_options']['disable_webcal'] = TRUE;
  $handler->display->display_options['row_plugin'] = 'date_ical';
  $handler->display->display_options['row_options']['date_field'] = 'field_data_field_event_date.field_event_date_value';
  $handler->display->display_options['row_options']['summary_field'] = 'field_data_body.body';
  $handler->display->display_options['row_options']['location_field'] = 'field_data_field_event_city_and_state.field_event_city_and_state';
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: Content: Nid */
  $handler->display->display_options['arguments']['nid']['id'] = 'nid';
  $handler->display->display_options['arguments']['nid']['table'] = 'node';
  $handler->display->display_options['arguments']['nid']['field'] = 'nid';
  $handler->display->display_options['arguments']['nid']['default_action'] = 'default';
  $handler->display->display_options['arguments']['nid']['default_argument_type'] = 'node';
  $handler->display->display_options['arguments']['nid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['nid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['nid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  $handler->display->display_options['path'] = 'calendar/%/industry-conference.ics';
  $handler->display->display_options['displays'] = array(
    'default' => 0,
    'panel_industry_conference' => 0,
    'panel_seminar' => 0,
    'panel_webinar' => 0,
  );

  /* Display: Archived Webinars */
  $handler = $view->new_display('panel_pane', 'Archived Webinars', 'panel_pane_1');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Archived Webinars';
  $handler->display->display_options['defaults']['css_class'] = FALSE;
  $handler->display->display_options['css_class'] = 'view-teaser-listing';
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['defaults']['header'] = FALSE;
  /* Header: Global: Text area */
  $handler->display->display_options['header']['area']['id'] = 'area';
  $handler->display->display_options['header']['area']['table'] = 'views';
  $handler->display->display_options['header']['area']['field'] = 'area';
  $handler->display->display_options['header']['area']['content'] = 'View an archived webinar to hear what industry experts have to say about automating global trade management.';
  $handler->display->display_options['header']['area']['format'] = 'full_html';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: External Link */
  $handler->display->display_options['fields']['field_event_link']['id'] = 'field_event_link';
  $handler->display->display_options['fields']['field_event_link']['table'] = 'field_data_field_event_link';
  $handler->display->display_options['fields']['field_event_link']['field'] = 'field_event_link';
  $handler->display->display_options['fields']['field_event_link']['label'] = '';
  $handler->display->display_options['fields']['field_event_link']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_event_link']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_event_link']['click_sort_column'] = 'url';
  $handler->display->display_options['fields']['field_event_link']['type'] = 'link_url';
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
  $handler->display->display_options['fields']['title']['link_to_node'] = FALSE;
  /* Field: Content: Hosted By */
  $handler->display->display_options['fields']['field_event_hosted_by']['id'] = 'field_event_hosted_by';
  $handler->display->display_options['fields']['field_event_hosted_by']['table'] = 'field_data_field_event_hosted_by';
  $handler->display->display_options['fields']['field_event_hosted_by']['field'] = 'field_event_hosted_by';
  $handler->display->display_options['fields']['field_event_hosted_by']['element_type'] = 'span';
  $handler->display->display_options['fields']['field_event_hosted_by']['element_label_colon'] = FALSE;
  /* Field: Content: Date and Time */
  $handler->display->display_options['fields']['field_event_date_and_time']['id'] = 'field_event_date_and_time';
  $handler->display->display_options['fields']['field_event_date_and_time']['table'] = 'field_data_field_event_date_and_time';
  $handler->display->display_options['fields']['field_event_date_and_time']['field'] = 'field_event_date_and_time';
  $handler->display->display_options['fields']['field_event_date_and_time']['label'] = 'Broadcasting Live on';
  $handler->display->display_options['fields']['field_event_date_and_time']['element_type'] = 'span';
  $handler->display->display_options['fields']['field_event_date_and_time']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_event_date_and_time']['settings'] = array(
    'format_type' => 'press_release',
    'fromto' => 'both',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
  );
  /* Field: Content: Body */
  $handler->display->display_options['fields']['body']['id'] = 'body';
  $handler->display->display_options['fields']['body']['table'] = 'field_data_body';
  $handler->display->display_options['fields']['body']['field'] = 'body';
  $handler->display->display_options['fields']['body']['label'] = '';
  $handler->display->display_options['fields']['body']['element_label_colon'] = FALSE;
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  /* Sort criterion: Content: Date and Time -  start date (field_event_date_and_time) */
  $handler->display->display_options['sorts']['field_event_date_and_time_value']['id'] = 'field_event_date_and_time_value';
  $handler->display->display_options['sorts']['field_event_date_and_time_value']['table'] = 'field_data_field_event_date_and_time';
  $handler->display->display_options['sorts']['field_event_date_and_time_value']['field'] = 'field_event_date_and_time_value';
  $handler->display->display_options['sorts']['field_event_date_and_time_value']['order'] = 'DESC';
  $handler->display->display_options['defaults']['arguments'] = FALSE;
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
  /* Filter criterion: Content: Date and Time -  start date (field_event_date_and_time) */
  $handler->display->display_options['filters']['field_event_date_and_time_value']['id'] = 'field_event_date_and_time_value';
  $handler->display->display_options['filters']['field_event_date_and_time_value']['table'] = 'field_data_field_event_date_and_time';
  $handler->display->display_options['filters']['field_event_date_and_time_value']['field'] = 'field_event_date_and_time_value';
  $handler->display->display_options['filters']['field_event_date_and_time_value']['operator'] = '<';
  $handler->display->display_options['filters']['field_event_date_and_time_value']['default_date'] = 'now';
  /* Filter criterion: Content: Add Webinar to archive list (field_add_webinar_to_archive_lis) */
  $handler->display->display_options['filters']['field_add_webinar_to_archive_lis_value']['id'] = 'field_add_webinar_to_archive_lis_value';
  $handler->display->display_options['filters']['field_add_webinar_to_archive_lis_value']['table'] = 'field_data_field_add_webinar_to_archive_lis';
  $handler->display->display_options['filters']['field_add_webinar_to_archive_lis_value']['field'] = 'field_add_webinar_to_archive_lis_value';
  $handler->display->display_options['filters']['field_add_webinar_to_archive_lis_value']['value'] = array(
    1 => '1',
  );
  $handler->display->display_options['allow']['use_pager'] = 0;
  $handler->display->display_options['allow']['items_per_page'] = 0;
  $handler->display->display_options['allow']['offset'] = 0;
  $handler->display->display_options['allow']['link_to_view'] = 0;
  $handler->display->display_options['allow']['more_link'] = 0;
  $handler->display->display_options['allow']['path_override'] = 0;
  $handler->display->display_options['allow']['title_override'] = 'title_override';
  $handler->display->display_options['allow']['exposed_form'] = 0;
  $handler->display->display_options['allow']['fields_override'] = 0;

  /* Display: Speaking Engagements */
  $handler = $view->new_display('panel_pane', 'Speaking Engagements', 'panel_pane_2');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['style_options']['row_class'] = 'resp-container';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['row_options']['inline'] = array(
    'field_presenter' => 'field_presenter',
  );
  $handler->display->display_options['row_options']['separator'] = '(&nbsp;)';
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Webinar Logo */
  $handler->display->display_options['fields']['field_event_logo']['id'] = 'field_event_logo';
  $handler->display->display_options['fields']['field_event_logo']['table'] = 'field_data_field_event_logo';
  $handler->display->display_options['fields']['field_event_logo']['field'] = 'field_event_logo';
  $handler->display->display_options['fields']['field_event_logo']['label'] = '';
  $handler->display->display_options['fields']['field_event_logo']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_event_logo']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_event_logo']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_event_logo']['settings'] = array(
    'image_style' => '',
    'image_link' => '',
  );
  /* Field: Content: Url */
  $handler->display->display_options['fields']['field_url']['id'] = 'field_url';
  $handler->display->display_options['fields']['field_url']['table'] = 'field_data_field_url';
  $handler->display->display_options['fields']['field_url']['field'] = 'field_url';
  $handler->display->display_options['fields']['field_url']['label'] = '';
  $handler->display->display_options['fields']['field_url']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_url']['element_label_colon'] = FALSE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['exclude'] = TRUE;
  $handler->display->display_options['fields']['title']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['title']['alter']['path'] = '[field_url]';
  $handler->display->display_options['fields']['title']['alter']['external'] = TRUE;
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['link_to_node'] = FALSE;
  /* Field: Content: City and State */
  $handler->display->display_options['fields']['field_event_city_and_state']['id'] = 'field_event_city_and_state';
  $handler->display->display_options['fields']['field_event_city_and_state']['table'] = 'field_data_field_event_city_and_state';
  $handler->display->display_options['fields']['field_event_city_and_state']['field'] = 'field_event_city_and_state';
  $handler->display->display_options['fields']['field_event_city_and_state']['label'] = '';
  $handler->display->display_options['fields']['field_event_city_and_state']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_event_city_and_state']['alter']['strip_tags'] = TRUE;
  $handler->display->display_options['fields']['field_event_city_and_state']['element_label_colon'] = FALSE;
  /* Field: Content: Date */
  $handler->display->display_options['fields']['field_event_date']['id'] = 'field_event_date';
  $handler->display->display_options['fields']['field_event_date']['table'] = 'field_data_field_event_date';
  $handler->display->display_options['fields']['field_event_date']['field'] = 'field_event_date';
  $handler->display->display_options['fields']['field_event_date']['label'] = '';
  $handler->display->display_options['fields']['field_event_date']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_event_date']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_event_date']['settings'] = array(
    'format_type' => 'long',
    'fromto' => 'value',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
    'show_remaining_days' => 0,
  );
  /* Field: Content: Author Image */
  $handler->display->display_options['fields']['field_podcast_author_image']['id'] = 'field_podcast_author_image';
  $handler->display->display_options['fields']['field_podcast_author_image']['table'] = 'field_data_field_podcast_author_image';
  $handler->display->display_options['fields']['field_podcast_author_image']['field'] = 'field_podcast_author_image';
  $handler->display->display_options['fields']['field_podcast_author_image']['label'] = '';
  $handler->display->display_options['fields']['field_podcast_author_image']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_podcast_author_image']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_podcast_author_image']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_podcast_author_image']['settings'] = array(
    'image_style' => '',
    'image_link' => '',
  );
  $handler->display->display_options['fields']['field_podcast_author_image']['delta_limit'] = '1';
  $handler->display->display_options['fields']['field_podcast_author_image']['delta_offset'] = '0';
  /* Field: Content: Author Image */
  $handler->display->display_options['fields']['field_podcast_author_image_1']['id'] = 'field_podcast_author_image_1';
  $handler->display->display_options['fields']['field_podcast_author_image_1']['table'] = 'field_data_field_podcast_author_image';
  $handler->display->display_options['fields']['field_podcast_author_image_1']['field'] = 'field_podcast_author_image';
  $handler->display->display_options['fields']['field_podcast_author_image_1']['label'] = '';
  $handler->display->display_options['fields']['field_podcast_author_image_1']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_podcast_author_image_1']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_podcast_author_image_1']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_podcast_author_image_1']['settings'] = array(
    'image_style' => '',
    'image_link' => '',
  );
  $handler->display->display_options['fields']['field_podcast_author_image_1']['delta_limit'] = '1';
  $handler->display->display_options['fields']['field_podcast_author_image_1']['delta_offset'] = '1';
  /* Field: Content: Speaker Name and Title */
  $handler->display->display_options['fields']['field_speaker_name_and_title']['id'] = 'field_speaker_name_and_title';
  $handler->display->display_options['fields']['field_speaker_name_and_title']['table'] = 'field_data_field_speaker_name_and_title';
  $handler->display->display_options['fields']['field_speaker_name_and_title']['field'] = 'field_speaker_name_and_title';
  $handler->display->display_options['fields']['field_speaker_name_and_title']['label'] = '';
  $handler->display->display_options['fields']['field_speaker_name_and_title']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_speaker_name_and_title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_speaker_name_and_title']['delta_limit'] = '1';
  $handler->display->display_options['fields']['field_speaker_name_and_title']['delta_offset'] = '0';
  /* Field: Content: Speaker Name and Title */
  $handler->display->display_options['fields']['field_speaker_name_and_title_1']['id'] = 'field_speaker_name_and_title_1';
  $handler->display->display_options['fields']['field_speaker_name_and_title_1']['table'] = 'field_data_field_speaker_name_and_title';
  $handler->display->display_options['fields']['field_speaker_name_and_title_1']['field'] = 'field_speaker_name_and_title';
  $handler->display->display_options['fields']['field_speaker_name_and_title_1']['label'] = '';
  $handler->display->display_options['fields']['field_speaker_name_and_title_1']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_speaker_name_and_title_1']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_speaker_name_and_title_1']['delta_limit'] = '1';
  $handler->display->display_options['fields']['field_speaker_name_and_title_1']['delta_offset'] = '1';
  /* Field: Field: Short Summary */
  $handler->display->display_options['fields']['field_podcast_short_summary']['id'] = 'field_podcast_short_summary';
  $handler->display->display_options['fields']['field_podcast_short_summary']['table'] = 'field_data_field_podcast_short_summary';
  $handler->display->display_options['fields']['field_podcast_short_summary']['field'] = 'field_podcast_short_summary';
  $handler->display->display_options['fields']['field_podcast_short_summary']['label'] = '';
  $handler->display->display_options['fields']['field_podcast_short_summary']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_podcast_short_summary']['element_label_colon'] = FALSE;
  /* Field: Content: Date */
  $handler->display->display_options['fields']['field_event_date_1']['id'] = 'field_event_date_1';
  $handler->display->display_options['fields']['field_event_date_1']['table'] = 'field_data_field_event_date';
  $handler->display->display_options['fields']['field_event_date_1']['field'] = 'field_event_date';
  $handler->display->display_options['fields']['field_event_date_1']['label'] = '';
  $handler->display->display_options['fields']['field_event_date_1']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_event_date_1']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_event_date_1']['settings'] = array(
    'format_type' => 'panopoly_day',
    'fromto' => 'both',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
    'show_remaining_days' => 0,
  );
  /* Field: Content: Nid */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['label'] = '';
  $handler->display->display_options['fields']['nid']['exclude'] = TRUE;
  $handler->display->display_options['fields']['nid']['element_type'] = 'div';
  $handler->display->display_options['fields']['nid']['element_class'] = 'padding-bottom:25px';
  $handler->display->display_options['fields']['nid']['element_label_colon'] = FALSE;
  /* Field: Global: Custom text */
  $handler->display->display_options['fields']['nothing']['id'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['table'] = 'views';
  $handler->display->display_options['fields']['nothing']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['label'] = '';
  $handler->display->display_options['fields']['nothing']['alter']['text'] = '<div class="row">
  <div class="col-xs-12 col-sm-3">[field_event_logo]<br /><br /><br />[title]<br />[field_event_city_and_state]<br />[field_event_date_1]</div>
  <div class="col-xs-12 col-sm-9">
    <div class="row">
      <div class="col-xs-12 col-sm-3 col-md-2">[field_podcast_author_image]</div>
      <div class="col-xs-12 col-sm-3 col-md-4"> [field_speaker_name_and_title]</div>
      <div class="col-xs-12 col-sm-3 col-md-2">[field_podcast_author_image_1]</div>
      <div class="col-xs-12 col-sm-3 col-md-4"> [field_speaker_name_and_title_1]</div>
    </div><br />
    [field_podcast_short_summary]
  </div>
<hr />
</div>
<br /><br />';
  $handler->display->display_options['fields']['nothing']['element_label_colon'] = FALSE;
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  /* Sort criterion: Content: Date -  start date (field_event_date) */
  $handler->display->display_options['sorts']['field_event_date_value']['id'] = 'field_event_date_value';
  $handler->display->display_options['sorts']['field_event_date_value']['table'] = 'field_data_field_event_date';
  $handler->display->display_options['sorts']['field_event_date_value']['field'] = 'field_event_date_value';
  $handler->display->display_options['defaults']['arguments'] = FALSE;
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
    'speaking' => 'speaking',
  );
  $handler->display->display_options['filters']['type']['group'] = 1;
  /* Filter criterion: Content: Date -  start date (field_event_date) */
  $handler->display->display_options['filters']['field_event_date_value']['id'] = 'field_event_date_value';
  $handler->display->display_options['filters']['field_event_date_value']['table'] = 'field_data_field_event_date';
  $handler->display->display_options['filters']['field_event_date_value']['field'] = 'field_event_date_value';
  $handler->display->display_options['filters']['field_event_date_value']['operator'] = '>=';
  $handler->display->display_options['filters']['field_event_date_value']['group'] = 1;
  $handler->display->display_options['filters']['field_event_date_value']['granularity'] = 'minute';
  $handler->display->display_options['filters']['field_event_date_value']['default_date'] = 'now -5 day';
  $handler->display->display_options['allow']['use_pager'] = 0;
  $handler->display->display_options['allow']['items_per_page'] = 0;
  $handler->display->display_options['allow']['offset'] = 0;
  $handler->display->display_options['allow']['link_to_view'] = 0;
  $handler->display->display_options['allow']['more_link'] = 0;
  $handler->display->display_options['allow']['path_override'] = 0;
  $handler->display->display_options['allow']['title_override'] = 'title_override';
  $handler->display->display_options['allow']['exposed_form'] = 0;
  $handler->display->display_options['allow']['fields_override'] = 0;

  /* Display: Speaking */
  $handler = $view->new_display('panel_pane', 'Speaking', 'panel_pane_3');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Speaking Engagements';
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Webinar Logo */
  $handler->display->display_options['fields']['field_event_logo']['id'] = 'field_event_logo';
  $handler->display->display_options['fields']['field_event_logo']['table'] = 'field_data_field_event_logo';
  $handler->display->display_options['fields']['field_event_logo']['field'] = 'field_event_logo';
  $handler->display->display_options['fields']['field_event_logo']['label'] = '';
  $handler->display->display_options['fields']['field_event_logo']['alter']['path'] = '[field_event_link] ';
  $handler->display->display_options['fields']['field_event_logo']['alter']['absolute'] = TRUE;
  $handler->display->display_options['fields']['field_event_logo']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_event_logo']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_event_logo']['settings'] = array(
    'image_style' => '',
    'image_link' => 'content',
  );
  /* Field: Content: External Link */
  $handler->display->display_options['fields']['field_event_link']['id'] = 'field_event_link';
  $handler->display->display_options['fields']['field_event_link']['table'] = 'field_data_field_event_link';
  $handler->display->display_options['fields']['field_event_link']['field'] = 'field_event_link';
  $handler->display->display_options['fields']['field_event_link']['label'] = '';
  $handler->display->display_options['fields']['field_event_link']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_event_link']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_event_link']['click_sort_column'] = 'url';
  $handler->display->display_options['fields']['field_event_link']['type'] = 'link_url';
  /* Field: Content: Author Image */
  $handler->display->display_options['fields']['field_podcast_author_image']['id'] = 'field_podcast_author_image';
  $handler->display->display_options['fields']['field_podcast_author_image']['table'] = 'field_data_field_podcast_author_image';
  $handler->display->display_options['fields']['field_podcast_author_image']['field'] = 'field_podcast_author_image';
  $handler->display->display_options['fields']['field_podcast_author_image']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_podcast_author_image']['settings'] = array(
    'image_style' => '',
    'image_link' => '',
  );
  $handler->display->display_options['fields']['field_podcast_author_image']['delta_offset'] = '0';
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
  $handler->display->display_options['fields']['title']['link_to_node'] = FALSE;
  /* Field: Content: Date */
  $handler->display->display_options['fields']['field_event_date']['id'] = 'field_event_date';
  $handler->display->display_options['fields']['field_event_date']['table'] = 'field_data_field_event_date';
  $handler->display->display_options['fields']['field_event_date']['field'] = 'field_event_date';
  $handler->display->display_options['fields']['field_event_date']['label'] = '';
  $handler->display->display_options['fields']['field_event_date']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_event_date']['settings'] = array(
    'format_type' => 'event_date',
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
  $handler->display->display_options['fields']['field_event_city_and_state']['element_label_colon'] = FALSE;
  /* Field: Content: Body */
  $handler->display->display_options['fields']['body']['id'] = 'body';
  $handler->display->display_options['fields']['body']['table'] = 'field_data_body';
  $handler->display->display_options['fields']['body']['field'] = 'body';
  $handler->display->display_options['fields']['body']['label'] = '';
  $handler->display->display_options['fields']['body']['element_label_colon'] = FALSE;
  /* Field: Content: Nid */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['label'] = '';
  $handler->display->display_options['fields']['nid']['exclude'] = TRUE;
  $handler->display->display_options['fields']['nid']['element_label_colon'] = FALSE;
  /* Field: Calender */
  $handler->display->display_options['fields']['nothing']['id'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['table'] = 'views';
  $handler->display->display_options['fields']['nothing']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['ui_name'] = 'Calender';
  $handler->display->display_options['fields']['nothing']['label'] = '';
  $handler->display->display_options['fields']['nothing']['alter']['text'] = 'Add to your Outlook calendar';
  $handler->display->display_options['fields']['nothing']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['nothing']['alter']['path'] = 'calendar/[nid]/industry-conference.ics';
  $handler->display->display_options['fields']['nothing']['element_label_colon'] = FALSE;
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  /* Sort criterion: Content: Date -  start date (field_event_date) */
  $handler->display->display_options['sorts']['field_event_date_value']['id'] = 'field_event_date_value';
  $handler->display->display_options['sorts']['field_event_date_value']['table'] = 'field_data_field_event_date';
  $handler->display->display_options['sorts']['field_event_date_value']['field'] = 'field_event_date_value';
  $handler->display->display_options['defaults']['arguments'] = FALSE;
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
    'speaking' => 'speaking',
  );
  /* Filter criterion: Content: Date -  start date (field_event_date) */
  $handler->display->display_options['filters']['field_event_date_value']['id'] = 'field_event_date_value';
  $handler->display->display_options['filters']['field_event_date_value']['table'] = 'field_data_field_event_date';
  $handler->display->display_options['filters']['field_event_date_value']['field'] = 'field_event_date_value';
  $handler->display->display_options['filters']['field_event_date_value']['operator'] = '>=';
  $handler->display->display_options['filters']['field_event_date_value']['granularity'] = 'minute';
  $handler->display->display_options['filters']['field_event_date_value']['default_date'] = 'now -5 day';
  $handler->display->display_options['allow']['use_pager'] = 0;
  $handler->display->display_options['allow']['items_per_page'] = 0;
  $handler->display->display_options['allow']['offset'] = 0;
  $handler->display->display_options['allow']['link_to_view'] = 0;
  $handler->display->display_options['allow']['more_link'] = 0;
  $handler->display->display_options['allow']['path_override'] = 0;
  $handler->display->display_options['allow']['title_override'] = 'title_override';
  $handler->display->display_options['allow']['exposed_form'] = 0;
  $handler->display->display_options['allow']['fields_override'] = 0;
  $export['events'] = $view;

  return $export;
}
