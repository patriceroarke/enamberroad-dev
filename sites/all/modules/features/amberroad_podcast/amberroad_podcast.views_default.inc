<?php
/**
 * @file
 * amberroad_podcast.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function amberroad_podcast_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'podcasts';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Podcasts';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Podcasts';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Header: Global: Text area */
  $handler->display->display_options['header']['area']['id'] = 'area';
  $handler->display->display_options['header']['area']['table'] = 'views';
  $handler->display->display_options['header']['area']['field'] = 'area';
  $handler->display->display_options['header']['area']['content'] = 'Listen to our podcasts on a variety of trade related subjects and learn more from our subject matter experts about key changes in the industry.';
  $handler->display->display_options['header']['area']['format'] = 'plain_text';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  /* Field: Field: Presented By */
  $handler->display->display_options['fields']['field_podcast_presented_by']['id'] = 'field_podcast_presented_by';
  $handler->display->display_options['fields']['field_podcast_presented_by']['table'] = 'field_data_field_podcast_presented_by';
  $handler->display->display_options['fields']['field_podcast_presented_by']['field'] = 'field_podcast_presented_by';
  $handler->display->display_options['fields']['field_podcast_presented_by']['element_type'] = 'span';
  /* Field: Field: Short Summary */
  $handler->display->display_options['fields']['field_podcast_short_summary']['id'] = 'field_podcast_short_summary';
  $handler->display->display_options['fields']['field_podcast_short_summary']['table'] = 'field_data_field_podcast_short_summary';
  $handler->display->display_options['fields']['field_podcast_short_summary']['field'] = 'field_podcast_short_summary';
  $handler->display->display_options['fields']['field_podcast_short_summary']['label'] = '';
  $handler->display->display_options['fields']['field_podcast_short_summary']['element_label_colon'] = FALSE;
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
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'podcast' => 'podcast',
  );

  /* Display: Podcasts pane */
  $handler = $view->new_display('panel_pane', 'Podcasts pane', 'panel_pane_1');
  $handler->display->display_options['defaults']['css_class'] = FALSE;
  $handler->display->display_options['css_class'] = 'view-teaser-listing';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['row_options']['inline'] = array(
    'title' => 'title',
    'field_podcast_presented_by' => 'field_podcast_presented_by',
    'field_podcast_short_summary' => 'field_podcast_short_summary',
  );
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  /* Field: Field: Presented By */
  $handler->display->display_options['fields']['field_podcast_presented_by']['id'] = 'field_podcast_presented_by';
  $handler->display->display_options['fields']['field_podcast_presented_by']['table'] = 'field_data_field_podcast_presented_by';
  $handler->display->display_options['fields']['field_podcast_presented_by']['field'] = 'field_podcast_presented_by';
  $handler->display->display_options['fields']['field_podcast_presented_by']['element_type'] = 'span';
  /* Field: Field: Short Summary */
  $handler->display->display_options['fields']['field_podcast_short_summary']['id'] = 'field_podcast_short_summary';
  $handler->display->display_options['fields']['field_podcast_short_summary']['table'] = 'field_data_field_podcast_short_summary';
  $handler->display->display_options['fields']['field_podcast_short_summary']['field'] = 'field_podcast_short_summary';
  $handler->display->display_options['fields']['field_podcast_short_summary']['label'] = '';
  $handler->display->display_options['fields']['field_podcast_short_summary']['element_label_colon'] = FALSE;
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
    'podcast' => 'podcast',
  );
  /* Filter criterion: Field: Podcast MP3 (field_podcast_mp3:description) */
  $handler->display->display_options['filters']['field_podcast_mp3_description']['id'] = 'field_podcast_mp3_description';
  $handler->display->display_options['filters']['field_podcast_mp3_description']['table'] = 'field_data_field_podcast_mp3';
  $handler->display->display_options['filters']['field_podcast_mp3_description']['field'] = 'field_podcast_mp3_description';
  /* Filter criterion: Field: Podcast MP3 (field_podcast_mp3:display) */
  $handler->display->display_options['filters']['field_podcast_mp3_display']['id'] = 'field_podcast_mp3_display';
  $handler->display->display_options['filters']['field_podcast_mp3_display']['table'] = 'field_data_field_podcast_mp3';
  $handler->display->display_options['filters']['field_podcast_mp3_display']['field'] = 'field_podcast_mp3_display';
  /* Filter criterion: Field: Podcast MP3 (field_podcast_mp3:fid) */
  $handler->display->display_options['filters']['field_podcast_mp3_fid']['id'] = 'field_podcast_mp3_fid';
  $handler->display->display_options['filters']['field_podcast_mp3_fid']['table'] = 'field_data_field_podcast_mp3';
  $handler->display->display_options['filters']['field_podcast_mp3_fid']['field'] = 'field_podcast_mp3_fid';
  /* Filter criterion: Field: Presented By (field_podcast_presented_by) */
  $handler->display->display_options['filters']['field_podcast_presented_by_value']['id'] = 'field_podcast_presented_by_value';
  $handler->display->display_options['filters']['field_podcast_presented_by_value']['table'] = 'field_data_field_podcast_presented_by';
  $handler->display->display_options['filters']['field_podcast_presented_by_value']['field'] = 'field_podcast_presented_by_value';
  $handler->display->display_options['allow']['use_pager'] = 0;
  $handler->display->display_options['allow']['items_per_page'] = 0;
  $handler->display->display_options['allow']['offset'] = 0;
  $handler->display->display_options['allow']['link_to_view'] = 0;
  $handler->display->display_options['allow']['more_link'] = 0;
  $handler->display->display_options['allow']['path_override'] = 0;
  $handler->display->display_options['allow']['title_override'] = 'title_override';
  $handler->display->display_options['allow']['exposed_form'] = 0;
  $handler->display->display_options['allow']['fields_override'] = 0;
  $handler->display->display_options['inherit_panels_path'] = '1';
  $export['podcasts'] = $view;

  return $export;
}
