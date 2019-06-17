<?php
/**
 * @file
 * amberroad_resources.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function amberroad_resources_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'resource_library_search';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Resource Library Search';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['use_ajax'] = TRUE;
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['exposed_form']['options']['expose_sort_order'] = FALSE;
  $handler->display->display_options['exposed_form']['options']['autosubmit'] = TRUE;
  $handler->display->display_options['pager']['type'] = 'load_more';
  $handler->display->display_options['pager']['options']['items_per_page'] = '15';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['quantity'] = '9';
  $handler->display->display_options['pager']['options']['effects']['speed'] = 'slow';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Relationship: Content: Taxonomy terms on node */
  $handler->display->display_options['relationships']['term_node_tid']['id'] = 'term_node_tid';
  $handler->display->display_options['relationships']['term_node_tid']['table'] = 'node';
  $handler->display->display_options['relationships']['term_node_tid']['field'] = 'term_node_tid';
  $handler->display->display_options['relationships']['term_node_tid']['vocabularies'] = array(
    'resource_type' => 'resource_type',
    'audience' => 0,
    'buying_stage' => 0,
    'career_location' => 0,
    'industry' => 0,
    'persona' => 0,
    'solution_area' => 0,
  );
  /* Field: Content: Path */
  $handler->display->display_options['fields']['path']['id'] = 'path';
  $handler->display->display_options['fields']['path']['table'] = 'node';
  $handler->display->display_options['fields']['path']['field'] = 'path';
  $handler->display->display_options['fields']['path']['label'] = '';
  $handler->display->display_options['fields']['path']['exclude'] = TRUE;
  $handler->display->display_options['fields']['path']['element_label_colon'] = FALSE;
  /* Field: Taxonomy term: Resource Search Logo */
  $handler->display->display_options['fields']['field_resource_search_logo']['id'] = 'field_resource_search_logo';
  $handler->display->display_options['fields']['field_resource_search_logo']['table'] = 'field_data_field_resource_search_logo';
  $handler->display->display_options['fields']['field_resource_search_logo']['field'] = 'field_resource_search_logo';
  $handler->display->display_options['fields']['field_resource_search_logo']['relationship'] = 'term_node_tid';
  $handler->display->display_options['fields']['field_resource_search_logo']['label'] = '';
  $handler->display->display_options['fields']['field_resource_search_logo']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_resource_search_logo']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['field_resource_search_logo']['alter']['path'] = '[path]';
  $handler->display->display_options['fields']['field_resource_search_logo']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_resource_search_logo']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_resource_search_logo']['settings'] = array(
    'image_style' => '',
    'image_link' => '',
  );
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  /* Sort criterion: Content: Sticky */
  $handler->display->display_options['sorts']['sticky']['id'] = 'sticky';
  $handler->display->display_options['sorts']['sticky']['table'] = 'node';
  $handler->display->display_options['sorts']['sticky']['field'] = 'sticky';
  $handler->display->display_options['sorts']['sticky']['order'] = 'DESC';
  /* Sort criterion: Content: Title */
  $handler->display->display_options['sorts']['title']['id'] = 'title';
  $handler->display->display_options['sorts']['title']['table'] = 'node';
  $handler->display->display_options['sorts']['title']['field'] = 'title';
  /* Filter criterion: Content: Area of Interest (field_solution_area) */
  $handler->display->display_options['filters']['field_solution_area_tid']['id'] = 'field_solution_area_tid';
  $handler->display->display_options['filters']['field_solution_area_tid']['table'] = 'field_data_field_solution_area';
  $handler->display->display_options['filters']['field_solution_area_tid']['field'] = 'field_solution_area_tid';
  $handler->display->display_options['filters']['field_solution_area_tid']['group'] = 1;
  $handler->display->display_options['filters']['field_solution_area_tid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_solution_area_tid']['expose']['operator_id'] = 'field_solution_area_tid_op';
  $handler->display->display_options['filters']['field_solution_area_tid']['expose']['label'] = 'Solution Area (field_solution_area)';
  $handler->display->display_options['filters']['field_solution_area_tid']['expose']['operator'] = 'field_solution_area_tid_op';
  $handler->display->display_options['filters']['field_solution_area_tid']['expose']['identifier'] = 'field_solution_area_tid';
  $handler->display->display_options['filters']['field_solution_area_tid']['expose']['multiple'] = TRUE;
  $handler->display->display_options['filters']['field_solution_area_tid']['is_grouped'] = TRUE;
  $handler->display->display_options['filters']['field_solution_area_tid']['group_info']['label'] = 'Solution Area';
  $handler->display->display_options['filters']['field_solution_area_tid']['group_info']['identifier'] = 'field_solution_area_tid';
  $handler->display->display_options['filters']['field_solution_area_tid']['group_info']['multiple'] = TRUE;
  $handler->display->display_options['filters']['field_solution_area_tid']['group_info']['group_items'] = array(
    1 => array(
      'title' => 'All',
      'operator' => 'or',
      'value' => array(
        26 => '26',
        24 => '24',
        25 => '25',
        20 => '20',
        21 => '21',
        22 => '22',
        23 => '23',
      ),
    ),
    2 => array(
      'title' => 'Duty Management',
      'operator' => 'or',
      'value' => array(
        26 => '26',
      ),
    ),
    3 => array(
      'title' => 'Export Management',
      'operator' => 'or',
      'value' => array(
        24 => '24',
      ),
    ),
    4 => array(
      'title' => 'Import Management',
      'operator' => 'or',
      'value' => array(
        25 => '25',
      ),
    ),
  );
  $handler->display->display_options['filters']['field_solution_area_tid']['reduce_duplicates'] = TRUE;
  $handler->display->display_options['filters']['field_solution_area_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_solution_area_tid']['vocabulary'] = 'solution_area';
  /* Filter criterion: Content: Audience (field_audience) */
  $handler->display->display_options['filters']['field_audience_tid']['id'] = 'field_audience_tid';
  $handler->display->display_options['filters']['field_audience_tid']['table'] = 'field_data_field_audience';
  $handler->display->display_options['filters']['field_audience_tid']['field'] = 'field_audience_tid';
  $handler->display->display_options['filters']['field_audience_tid']['operator'] = 'and';
  $handler->display->display_options['filters']['field_audience_tid']['value'] = array(
    11 => '11',
    12 => '12',
  );
  $handler->display->display_options['filters']['field_audience_tid']['group'] = 1;
  $handler->display->display_options['filters']['field_audience_tid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_audience_tid']['expose']['operator_id'] = 'field_audience_tid_op';
  $handler->display->display_options['filters']['field_audience_tid']['expose']['label'] = 'Audience (field_audience)';
  $handler->display->display_options['filters']['field_audience_tid']['expose']['operator'] = 'field_audience_tid_op';
  $handler->display->display_options['filters']['field_audience_tid']['expose']['identifier'] = 'field_audience_tid';
  $handler->display->display_options['filters']['field_audience_tid']['expose']['multiple'] = TRUE;
  $handler->display->display_options['filters']['field_audience_tid']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    4 => 0,
    3 => 0,
  );
  $handler->display->display_options['filters']['field_audience_tid']['expose']['reduce'] = TRUE;
  $handler->display->display_options['filters']['field_audience_tid']['is_grouped'] = TRUE;
  $handler->display->display_options['filters']['field_audience_tid']['group_info']['label'] = 'Audience';
  $handler->display->display_options['filters']['field_audience_tid']['group_info']['identifier'] = 'field_audience_tid';
  $handler->display->display_options['filters']['field_audience_tid']['group_info']['multiple'] = TRUE;
  $handler->display->display_options['filters']['field_audience_tid']['group_info']['group_items'] = array(
    1 => array(
      'title' => 'All',
      'operator' => 'or',
      'value' => array(
        11 => '11',
        12 => '12',
      ),
    ),
    2 => array(
      'title' => 'Enterprise',
      'operator' => 'or',
      'value' => array(
        11 => '11',
      ),
    ),
    3 => array(
      'title' => 'Mid-Market',
      'operator' => 'and',
      'value' => array(
        12 => '12',
      ),
    ),
  );
  $handler->display->display_options['filters']['field_audience_tid']['reduce_duplicates'] = TRUE;
  $handler->display->display_options['filters']['field_audience_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_audience_tid']['vocabulary'] = 'audience';
  /* Filter criterion: Content: Resource Type (field_resource_type) */
  $handler->display->display_options['filters']['field_resource_type_tid']['id'] = 'field_resource_type_tid';
  $handler->display->display_options['filters']['field_resource_type_tid']['table'] = 'field_data_field_resource_type';
  $handler->display->display_options['filters']['field_resource_type_tid']['field'] = 'field_resource_type_tid';
  $handler->display->display_options['filters']['field_resource_type_tid']['group'] = 1;
  $handler->display->display_options['filters']['field_resource_type_tid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_resource_type_tid']['expose']['operator_id'] = 'field_resource_type_tid_op';
  $handler->display->display_options['filters']['field_resource_type_tid']['expose']['label'] = 'Resource Type (field_resource_type)';
  $handler->display->display_options['filters']['field_resource_type_tid']['expose']['operator'] = 'field_resource_type_tid_op';
  $handler->display->display_options['filters']['field_resource_type_tid']['expose']['identifier'] = 'field_resource_type_tid';
  $handler->display->display_options['filters']['field_resource_type_tid']['expose']['multiple'] = TRUE;
  $handler->display->display_options['filters']['field_resource_type_tid']['is_grouped'] = TRUE;
  $handler->display->display_options['filters']['field_resource_type_tid']['group_info']['label'] = 'Resource Type';
  $handler->display->display_options['filters']['field_resource_type_tid']['group_info']['identifier'] = 'field_resource_type_tid';
  $handler->display->display_options['filters']['field_resource_type_tid']['group_info']['multiple'] = TRUE;
  $handler->display->display_options['filters']['field_resource_type_tid']['group_info']['group_items'] = array(
    1 => array(
      'title' => 'All',
      'operator' => 'or',
      'value' => array(
        1 => '1',
        2 => '2',
        3 => '3',
        4 => '4',
        6 => '6',
        5 => '5',
      ),
    ),
    2 => array(
      'title' => 'Analyst & Industry Reports',
      'operator' => 'or',
      'value' => array(
        1 => '1',
      ),
    ),
    3 => array(
      'title' => 'Brochures',
      'operator' => 'or',
      'value' => array(
        2 => '2',
      ),
    ),
    4 => array(
      'title' => 'Case Studies',
      'operator' => 'or',
      'value' => array(
        3 => '3',
      ),
    ),
  );
  $handler->display->display_options['filters']['field_resource_type_tid']['reduce_duplicates'] = TRUE;
  $handler->display->display_options['filters']['field_resource_type_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_resource_type_tid']['vocabulary'] = 'resource_type';
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Industry (field_industry) */
  $handler->display->display_options['filters']['field_industry_tid']['id'] = 'field_industry_tid';
  $handler->display->display_options['filters']['field_industry_tid']['table'] = 'field_data_field_industry';
  $handler->display->display_options['filters']['field_industry_tid']['field'] = 'field_industry_tid';
  $handler->display->display_options['filters']['field_industry_tid']['group'] = 1;
  $handler->display->display_options['filters']['field_industry_tid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_industry_tid']['expose']['operator_id'] = 'field_industry_tid_op';
  $handler->display->display_options['filters']['field_industry_tid']['expose']['label'] = 'Industry (field_industry)';
  $handler->display->display_options['filters']['field_industry_tid']['expose']['operator'] = 'field_industry_tid_op';
  $handler->display->display_options['filters']['field_industry_tid']['expose']['identifier'] = 'field_industry_tid';
  $handler->display->display_options['filters']['field_industry_tid']['expose']['multiple'] = TRUE;
  $handler->display->display_options['filters']['field_industry_tid']['is_grouped'] = TRUE;
  $handler->display->display_options['filters']['field_industry_tid']['group_info']['label'] = 'Industry';
  $handler->display->display_options['filters']['field_industry_tid']['group_info']['identifier'] = 'field_industry_tid';
  $handler->display->display_options['filters']['field_industry_tid']['group_info']['multiple'] = TRUE;
  $handler->display->display_options['filters']['field_industry_tid']['group_info']['default_group'] = '1';
  $handler->display->display_options['filters']['field_industry_tid']['group_info']['group_items'] = array(
    1 => array(
      'title' => 'All',
      'operator' => 'or',
      'value' => array(
        27 => '27',
        28 => '28',
        29 => '29',
        30 => '30',
        31 => '31',
        32 => '32',
        33 => '33',
        34 => '34',
        35 => '35',
        36 => '36',
        37 => '37',
        38 => '38',
        39 => '39',
      ),
    ),
    2 => array(
      'title' => 'Aerospace and Defense',
      'operator' => 'or',
      'value' => array(
        27 => '27',
      ),
    ),
    3 => array(
      'title' => 'Apparel',
      'operator' => 'or',
      'value' => array(
        28 => '28',
      ),
    ),
    4 => array(
      'title' => 'Automotive',
      'operator' => 'or',
      'value' => array(
        29 => '29',
      ),
    ),
    5 => array(),
  );
  $handler->display->display_options['filters']['field_industry_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_industry_tid']['vocabulary'] = 'industry';
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'podcast' => 'podcast',
    'resource' => 'resource',
    'webinar' => 'webinar',
  );
  $handler->display->display_options['filters']['type']['group'] = 1;
  /* Filter criterion: Content: Persona (field_persona) */
  $handler->display->display_options['filters']['field_persona_tid']['id'] = 'field_persona_tid';
  $handler->display->display_options['filters']['field_persona_tid']['table'] = 'field_data_field_persona';
  $handler->display->display_options['filters']['field_persona_tid']['field'] = 'field_persona_tid';
  $handler->display->display_options['filters']['field_persona_tid']['group'] = 1;
  $handler->display->display_options['filters']['field_persona_tid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_persona_tid']['expose']['operator_id'] = 'field_persona_tid_op';
  $handler->display->display_options['filters']['field_persona_tid']['expose']['label'] = 'Persona (field_persona)';
  $handler->display->display_options['filters']['field_persona_tid']['expose']['operator'] = 'field_persona_tid_op';
  $handler->display->display_options['filters']['field_persona_tid']['expose']['identifier'] = 'field_persona_tid';
  $handler->display->display_options['filters']['field_persona_tid']['expose']['multiple'] = TRUE;
  $handler->display->display_options['filters']['field_persona_tid']['is_grouped'] = TRUE;
  $handler->display->display_options['filters']['field_persona_tid']['group_info']['label'] = 'Persona';
  $handler->display->display_options['filters']['field_persona_tid']['group_info']['identifier'] = 'field_persona_tid';
  $handler->display->display_options['filters']['field_persona_tid']['group_info']['multiple'] = TRUE;
  $handler->display->display_options['filters']['field_persona_tid']['group_info']['group_items'] = array(
    1 => array(
      'title' => 'All',
      'operator' => 'or',
      'value' => array(
        40 => '40',
        41 => '41',
        42 => '42',
        43 => '43',
        44 => '44',
        45 => '45',
      ),
    ),
    2 => array(
      'title' => 'Compliance',
      'operator' => 'or',
      'value' => array(
        40 => '40',
      ),
    ),
    3 => array(
      'title' => 'Finance',
      'operator' => 'or',
      'value' => array(
        41 => '41',
      ),
    ),
    4 => array(
      'title' => 'IT',
      'operator' => 'or',
      'value' => array(
        42 => '42',
      ),
    ),
  );
  $handler->display->display_options['filters']['field_persona_tid']['reduce_duplicates'] = TRUE;
  $handler->display->display_options['filters']['field_persona_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_persona_tid']['vocabulary'] = 'persona';
  /* Filter criterion: Content: Buying Stage (field_buying_stage) */
  $handler->display->display_options['filters']['field_buying_stage_tid']['id'] = 'field_buying_stage_tid';
  $handler->display->display_options['filters']['field_buying_stage_tid']['table'] = 'field_data_field_buying_stage';
  $handler->display->display_options['filters']['field_buying_stage_tid']['field'] = 'field_buying_stage_tid';
  $handler->display->display_options['filters']['field_buying_stage_tid']['group'] = 1;
  $handler->display->display_options['filters']['field_buying_stage_tid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_buying_stage_tid']['expose']['operator_id'] = 'field_buying_stage_tid_op';
  $handler->display->display_options['filters']['field_buying_stage_tid']['expose']['label'] = 'Buying Stage (field_buying_stage)';
  $handler->display->display_options['filters']['field_buying_stage_tid']['expose']['operator'] = 'field_buying_stage_tid_op';
  $handler->display->display_options['filters']['field_buying_stage_tid']['expose']['identifier'] = 'field_buying_stage_tid';
  $handler->display->display_options['filters']['field_buying_stage_tid']['expose']['multiple'] = TRUE;
  $handler->display->display_options['filters']['field_buying_stage_tid']['is_grouped'] = TRUE;
  $handler->display->display_options['filters']['field_buying_stage_tid']['group_info']['label'] = 'Buying Stage';
  $handler->display->display_options['filters']['field_buying_stage_tid']['group_info']['identifier'] = 'field_buying_stage_tid';
  $handler->display->display_options['filters']['field_buying_stage_tid']['group_info']['multiple'] = TRUE;
  $handler->display->display_options['filters']['field_buying_stage_tid']['group_info']['group_items'] = array(
    1 => array(
      'title' => 'All',
      'operator' => 'or',
      'value' => array(
        46 => '46',
        47 => '47',
        48 => '48',
      ),
    ),
    2 => array(
      'title' => 'BOFU',
      'operator' => 'or',
      'value' => array(
        46 => '46',
      ),
    ),
    3 => array(
      'title' => 'MOFU',
      'operator' => 'or',
      'value' => array(
        47 => '47',
      ),
    ),
    4 => array(
      'title' => 'TOFU',
      'operator' => 'or',
      'value' => array(
        48 => '48',
      ),
    ),
  );
  $handler->display->display_options['filters']['field_buying_stage_tid']['reduce_duplicates'] = TRUE;
  $handler->display->display_options['filters']['field_buying_stage_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_buying_stage_tid']['vocabulary'] = 'buying_stage';

  /* Display: Resource Library Search */
  $handler = $view->new_display('panel_pane', 'Resource Library Search', 'panel_pane_1');
  $handler->display->display_options['defaults']['use_ajax'] = FALSE;
  $handler->display->display_options['use_ajax'] = TRUE;
  $handler->display->display_options['defaults']['hide_attachment_summary'] = FALSE;
  $handler->display->display_options['hide_attachment_summary'] = TRUE;
  $handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
  $handler->display->display_options['hide_admin_links'] = TRUE;
  $handler->display->display_options['defaults']['exposed_form'] = FALSE;
  $handler->display->display_options['exposed_form']['type'] = 'better_exposed_filters';
  $handler->display->display_options['exposed_form']['options']['reset_button'] = TRUE;
  $handler->display->display_options['exposed_form']['options']['expose_sort_order'] = FALSE;
  $handler->display->display_options['exposed_form']['options']['autosubmit'] = TRUE;
  $handler->display->display_options['exposed_form']['options']['bef'] = array(
    'general' => array(
      'allow_secondary' => 0,
      'secondary_label' => 'Advanced options',
      'collapsible_label' => NULL,
      'combine_rewrite' => NULL,
      'reset_label' => NULL,
      'bef_filter_description' => NULL,
      'any_label' => NULL,
      'filter_rewrite_values' => NULL,
    ),
    'field_solution_area_tid' => array(
      'bef_format' => 'bef',
      'more_options' => array(
        'bef_select_all_none' => 0,
        'bef_collapsible' => 0,
        'is_secondary' => 0,
        'any_label' => 'All',
        'bef_filter_description' => '',
        'tokens' => array(
          'available' => array(
            0 => 'global_types',
            1 => 'vocabulary',
            'secondary_label' => NULL,
            'collapsible_label' => NULL,
            'combine_rewrite' => NULL,
            'reset_label' => NULL,
            'bef_filter_description' => NULL,
            'any_label' => NULL,
            'filter_rewrite_values' => NULL,
          ),
          'secondary_label' => NULL,
          'collapsible_label' => NULL,
          'combine_rewrite' => NULL,
          'reset_label' => NULL,
          'bef_filter_description' => NULL,
          'any_label' => NULL,
          'filter_rewrite_values' => NULL,
        ),
        'rewrite' => array(
          'filter_rewrite_values' => '',
          'secondary_label' => NULL,
          'collapsible_label' => NULL,
          'combine_rewrite' => NULL,
          'reset_label' => NULL,
          'bef_filter_description' => NULL,
          'any_label' => NULL,
        ),
        'secondary_label' => NULL,
        'collapsible_label' => NULL,
        'combine_rewrite' => NULL,
        'reset_label' => NULL,
        'filter_rewrite_values' => NULL,
      ),
      'secondary_label' => NULL,
      'collapsible_label' => NULL,
      'combine_rewrite' => NULL,
      'reset_label' => NULL,
      'bef_filter_description' => NULL,
      'any_label' => NULL,
      'filter_rewrite_values' => NULL,
    ),
    'field_audience_tid' => array(
      'bef_format' => 'bef',
      'more_options' => array(
        'bef_select_all_none' => 0,
        'bef_collapsible' => 0,
        'is_secondary' => 0,
        'any_label' => 'All',
        'bef_filter_description' => '',
        'tokens' => array(
          'available' => array(
            0 => 'global_types',
            1 => 'vocabulary',
            'secondary_label' => NULL,
            'collapsible_label' => NULL,
            'combine_rewrite' => NULL,
            'reset_label' => NULL,
            'bef_filter_description' => NULL,
            'any_label' => NULL,
            'filter_rewrite_values' => NULL,
          ),
          'secondary_label' => NULL,
          'collapsible_label' => NULL,
          'combine_rewrite' => NULL,
          'reset_label' => NULL,
          'bef_filter_description' => NULL,
          'any_label' => NULL,
          'filter_rewrite_values' => NULL,
        ),
        'rewrite' => array(
          'filter_rewrite_values' => '',
          'secondary_label' => NULL,
          'collapsible_label' => NULL,
          'combine_rewrite' => NULL,
          'reset_label' => NULL,
          'bef_filter_description' => NULL,
          'any_label' => NULL,
        ),
        'secondary_label' => NULL,
        'collapsible_label' => NULL,
        'combine_rewrite' => NULL,
        'reset_label' => NULL,
        'filter_rewrite_values' => NULL,
      ),
      'secondary_label' => NULL,
      'collapsible_label' => NULL,
      'combine_rewrite' => NULL,
      'reset_label' => NULL,
      'bef_filter_description' => NULL,
      'any_label' => NULL,
      'filter_rewrite_values' => NULL,
    ),
    'field_resource_type_tid' => array(
      'bef_format' => 'bef',
      'more_options' => array(
        'bef_select_all_none' => 0,
        'bef_collapsible' => 0,
        'is_secondary' => 0,
        'any_label' => 'All',
        'bef_filter_description' => '',
        'tokens' => array(
          'available' => array(
            0 => 'global_types',
            1 => 'vocabulary',
            'secondary_label' => NULL,
            'collapsible_label' => NULL,
            'combine_rewrite' => NULL,
            'reset_label' => NULL,
            'bef_filter_description' => NULL,
            'any_label' => NULL,
            'filter_rewrite_values' => NULL,
          ),
          'secondary_label' => NULL,
          'collapsible_label' => NULL,
          'combine_rewrite' => NULL,
          'reset_label' => NULL,
          'bef_filter_description' => NULL,
          'any_label' => NULL,
          'filter_rewrite_values' => NULL,
        ),
        'rewrite' => array(
          'filter_rewrite_values' => '',
          'secondary_label' => NULL,
          'collapsible_label' => NULL,
          'combine_rewrite' => NULL,
          'reset_label' => NULL,
          'bef_filter_description' => NULL,
          'any_label' => NULL,
        ),
        'secondary_label' => NULL,
        'collapsible_label' => NULL,
        'combine_rewrite' => NULL,
        'reset_label' => NULL,
        'filter_rewrite_values' => NULL,
      ),
      'secondary_label' => NULL,
      'collapsible_label' => NULL,
      'combine_rewrite' => NULL,
      'reset_label' => NULL,
      'bef_filter_description' => NULL,
      'any_label' => NULL,
      'filter_rewrite_values' => NULL,
    ),
    'field_industry_tid' => array(
      'bef_format' => 'bef',
      'more_options' => array(
        'bef_select_all_none' => 0,
        'bef_collapsible' => 0,
        'is_secondary' => 0,
        'any_label' => 'All',
        'bef_filter_description' => '',
        'tokens' => array(
          'available' => array(
            0 => 'global_types',
            1 => 'vocabulary',
            'secondary_label' => NULL,
            'collapsible_label' => NULL,
            'combine_rewrite' => NULL,
            'reset_label' => NULL,
            'bef_filter_description' => NULL,
            'any_label' => NULL,
            'filter_rewrite_values' => NULL,
          ),
          'secondary_label' => NULL,
          'collapsible_label' => NULL,
          'combine_rewrite' => NULL,
          'reset_label' => NULL,
          'bef_filter_description' => NULL,
          'any_label' => NULL,
          'filter_rewrite_values' => NULL,
        ),
        'rewrite' => array(
          'filter_rewrite_values' => '',
          'secondary_label' => NULL,
          'collapsible_label' => NULL,
          'combine_rewrite' => NULL,
          'reset_label' => NULL,
          'bef_filter_description' => NULL,
          'any_label' => NULL,
        ),
        'secondary_label' => NULL,
        'collapsible_label' => NULL,
        'combine_rewrite' => NULL,
        'reset_label' => NULL,
        'filter_rewrite_values' => NULL,
      ),
      'secondary_label' => NULL,
      'collapsible_label' => NULL,
      'combine_rewrite' => NULL,
      'reset_label' => NULL,
      'bef_filter_description' => NULL,
      'any_label' => NULL,
      'filter_rewrite_values' => NULL,
    ),
    'secondary_label' => NULL,
    'collapsible_label' => NULL,
    'combine_rewrite' => NULL,
    'reset_label' => NULL,
    'bef_filter_description' => NULL,
    'any_label' => NULL,
    'filter_rewrite_values' => NULL,
  );
  $handler->display->display_options['exposed_form']['options']['input_required'] = 0;
  $handler->display->display_options['exposed_form']['options']['text_input_required_format'] = 'full_html';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'node';
  $handler->display->display_options['row_options']['view_mode'] = 'resource_search';
  $handler->display->display_options['row_options']['links'] = FALSE;
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['exposed_block'] = TRUE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Path */
  $handler->display->display_options['fields']['path']['id'] = 'path';
  $handler->display->display_options['fields']['path']['table'] = 'node';
  $handler->display->display_options['fields']['path']['field'] = 'path';
  $handler->display->display_options['fields']['path']['label'] = '';
  $handler->display->display_options['fields']['path']['exclude'] = TRUE;
  $handler->display->display_options['fields']['path']['element_label_colon'] = FALSE;
  /* Field: Taxonomy term: Resource Search Logo */
  $handler->display->display_options['fields']['field_resource_search_logo']['id'] = 'field_resource_search_logo';
  $handler->display->display_options['fields']['field_resource_search_logo']['table'] = 'field_data_field_resource_search_logo';
  $handler->display->display_options['fields']['field_resource_search_logo']['field'] = 'field_resource_search_logo';
  $handler->display->display_options['fields']['field_resource_search_logo']['relationship'] = 'term_node_tid';
  $handler->display->display_options['fields']['field_resource_search_logo']['label'] = '';
  $handler->display->display_options['fields']['field_resource_search_logo']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_resource_search_logo']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['field_resource_search_logo']['alter']['path'] = '[path]';
  $handler->display->display_options['fields']['field_resource_search_logo']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_resource_search_logo']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_resource_search_logo']['settings'] = array(
    'image_style' => '',
    'image_link' => '',
  );
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  /* Field: Content: Edit link */
  $handler->display->display_options['fields']['edit_node']['id'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['table'] = 'views_entity_node';
  $handler->display->display_options['fields']['edit_node']['field'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['label'] = 'Edit content';
  $handler->display->display_options['fields']['edit_node']['exclude'] = TRUE;
  $handler->display->display_options['fields']['edit_node']['text'] = 'Edit content';
  /* Field: Global: Contextual Links */
  $handler->display->display_options['fields']['contextual_links']['id'] = 'contextual_links';
  $handler->display->display_options['fields']['contextual_links']['table'] = 'views';
  $handler->display->display_options['fields']['contextual_links']['field'] = 'contextual_links';
  $handler->display->display_options['fields']['contextual_links']['label'] = '';
  $handler->display->display_options['fields']['contextual_links']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['contextual_links']['fields'] = array(
    'edit_node' => 'edit_node',
    'path' => 0,
    'field_resource_search_logo' => 0,
    'title' => 0,
  );
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  /* Sort criterion: Content: Sticky */
  $handler->display->display_options['sorts']['sticky']['id'] = 'sticky';
  $handler->display->display_options['sorts']['sticky']['table'] = 'node';
  $handler->display->display_options['sorts']['sticky']['field'] = 'sticky';
  $handler->display->display_options['sorts']['sticky']['order'] = 'DESC';
  /* Sort criterion: Content: Resource Date (field_resource_date) */
  $handler->display->display_options['sorts']['field_resource_date_value']['id'] = 'field_resource_date_value';
  $handler->display->display_options['sorts']['field_resource_date_value']['table'] = 'field_data_field_resource_date';
  $handler->display->display_options['sorts']['field_resource_date_value']['field'] = 'field_resource_date_value';
  $handler->display->display_options['sorts']['field_resource_date_value']['order'] = 'DESC';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Area of Interest (field_solution_area) */
  $handler->display->display_options['filters']['field_solution_area_tid']['id'] = 'field_solution_area_tid';
  $handler->display->display_options['filters']['field_solution_area_tid']['table'] = 'field_data_field_solution_area';
  $handler->display->display_options['filters']['field_solution_area_tid']['field'] = 'field_solution_area_tid';
  $handler->display->display_options['filters']['field_solution_area_tid']['value'] = array(
    53 => '53',
    52 => '52',
    45 => '45',
    22 => '22',
    56 => '56',
    55 => '55',
    65 => '65',
    57 => '57',
    58 => '58',
    15 => '15',
    59 => '59',
    60 => '60',
    17 => '17',
    18 => '18',
    32 => '32',
    61 => '61',
    39 => '39',
  );
  $handler->display->display_options['filters']['field_solution_area_tid']['group'] = 1;
  $handler->display->display_options['filters']['field_solution_area_tid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_solution_area_tid']['expose']['operator_id'] = 'field_solution_area_tid_op';
  $handler->display->display_options['filters']['field_solution_area_tid']['expose']['label'] = 'Area of Interest';
  $handler->display->display_options['filters']['field_solution_area_tid']['expose']['operator'] = 'field_solution_area_tid_op';
  $handler->display->display_options['filters']['field_solution_area_tid']['expose']['identifier'] = 'field_solution_area_tid';
  $handler->display->display_options['filters']['field_solution_area_tid']['expose']['multiple'] = TRUE;
  $handler->display->display_options['filters']['field_solution_area_tid']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    4 => 0,
    3 => 0,
    5 => 0,
  );
  $handler->display->display_options['filters']['field_solution_area_tid']['expose']['reduce'] = TRUE;
  $handler->display->display_options['filters']['field_solution_area_tid']['group_info']['label'] = 'Solution Area';
  $handler->display->display_options['filters']['field_solution_area_tid']['group_info']['identifier'] = 'field_solution_area_tid';
  $handler->display->display_options['filters']['field_solution_area_tid']['group_info']['multiple'] = TRUE;
  $handler->display->display_options['filters']['field_solution_area_tid']['group_info']['group_items'] = array(
    1 => array(
      'title' => 'All',
      'operator' => 'or',
      'value' => array(
        26 => '26',
        24 => '24',
        25 => '25',
        20 => '20',
        21 => '21',
        22 => '22',
        23 => '23',
      ),
    ),
    2 => array(
      'title' => 'Duty Management',
      'operator' => 'or',
      'value' => array(
        26 => '26',
      ),
    ),
    3 => array(
      'title' => 'Export Management',
      'operator' => 'or',
      'value' => array(
        24 => '24',
      ),
    ),
    4 => array(
      'title' => 'Import Management',
      'operator' => 'or',
      'value' => array(
        25 => '25',
      ),
    ),
  );
  $handler->display->display_options['filters']['field_solution_area_tid']['reduce_duplicates'] = TRUE;
  $handler->display->display_options['filters']['field_solution_area_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_solution_area_tid']['vocabulary'] = 'solution_area';
  /* Filter criterion: Content: Audience (field_audience) */
  $handler->display->display_options['filters']['field_audience_tid']['id'] = 'field_audience_tid';
  $handler->display->display_options['filters']['field_audience_tid']['table'] = 'field_data_field_audience';
  $handler->display->display_options['filters']['field_audience_tid']['field'] = 'field_audience_tid';
  $handler->display->display_options['filters']['field_audience_tid']['value'] = array(
    11 => '11',
    46 => '46',
  );
  $handler->display->display_options['filters']['field_audience_tid']['group'] = 1;
  $handler->display->display_options['filters']['field_audience_tid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_audience_tid']['expose']['operator_id'] = 'field_audience_tid_op';
  $handler->display->display_options['filters']['field_audience_tid']['expose']['label'] = 'Audience';
  $handler->display->display_options['filters']['field_audience_tid']['expose']['operator'] = 'field_audience_tid_op';
  $handler->display->display_options['filters']['field_audience_tid']['expose']['identifier'] = 'field_audience_tid';
  $handler->display->display_options['filters']['field_audience_tid']['expose']['multiple'] = TRUE;
  $handler->display->display_options['filters']['field_audience_tid']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    4 => 0,
    3 => 0,
  );
  $handler->display->display_options['filters']['field_audience_tid']['expose']['reduce'] = TRUE;
  $handler->display->display_options['filters']['field_audience_tid']['group_info']['label'] = 'Audience';
  $handler->display->display_options['filters']['field_audience_tid']['group_info']['identifier'] = 'field_audience_tid';
  $handler->display->display_options['filters']['field_audience_tid']['group_info']['multiple'] = TRUE;
  $handler->display->display_options['filters']['field_audience_tid']['group_info']['group_items'] = array(
    1 => array(
      'title' => 'All',
      'operator' => 'or',
      'value' => array(
        11 => '11',
        12 => '12',
      ),
    ),
    2 => array(
      'title' => 'Enterprise',
      'operator' => 'or',
      'value' => array(
        11 => '11',
      ),
    ),
    3 => array(
      'title' => 'Mid-Market',
      'operator' => 'and',
      'value' => array(
        12 => '12',
      ),
    ),
  );
  $handler->display->display_options['filters']['field_audience_tid']['reduce_duplicates'] = TRUE;
  $handler->display->display_options['filters']['field_audience_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_audience_tid']['vocabulary'] = 'audience';
  /* Filter criterion: Content: Resource Type (field_resource_type) */
  $handler->display->display_options['filters']['field_resource_type_tid']['id'] = 'field_resource_type_tid';
  $handler->display->display_options['filters']['field_resource_type_tid']['table'] = 'field_data_field_resource_type';
  $handler->display->display_options['filters']['field_resource_type_tid']['field'] = 'field_resource_type_tid';
  $handler->display->display_options['filters']['field_resource_type_tid']['value'] = array(
    1 => '1',
    2 => '2',
    3 => '3',
    4 => '4',
    26 => '26',
    19 => '19',
    29 => '29',
    43 => '43',
    6 => '6',
    20 => '20',
    5 => '5',
  );
  $handler->display->display_options['filters']['field_resource_type_tid']['group'] = 1;
  $handler->display->display_options['filters']['field_resource_type_tid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_resource_type_tid']['expose']['operator_id'] = 'field_resource_type_tid_op';
  $handler->display->display_options['filters']['field_resource_type_tid']['expose']['label'] = 'Resource Type';
  $handler->display->display_options['filters']['field_resource_type_tid']['expose']['operator'] = 'field_resource_type_tid_op';
  $handler->display->display_options['filters']['field_resource_type_tid']['expose']['identifier'] = 'field_resource_type_tid';
  $handler->display->display_options['filters']['field_resource_type_tid']['expose']['multiple'] = TRUE;
  $handler->display->display_options['filters']['field_resource_type_tid']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    4 => 0,
    3 => 0,
  );
  $handler->display->display_options['filters']['field_resource_type_tid']['expose']['reduce'] = TRUE;
  $handler->display->display_options['filters']['field_resource_type_tid']['group_info']['label'] = 'Resource Type';
  $handler->display->display_options['filters']['field_resource_type_tid']['group_info']['identifier'] = 'field_resource_type_tid';
  $handler->display->display_options['filters']['field_resource_type_tid']['group_info']['multiple'] = TRUE;
  $handler->display->display_options['filters']['field_resource_type_tid']['group_info']['group_items'] = array(
    1 => array(
      'title' => 'All',
      'operator' => 'or',
      'value' => array(
        1 => '1',
        2 => '2',
        3 => '3',
        4 => '4',
        6 => '6',
        5 => '5',
      ),
    ),
    2 => array(
      'title' => 'Analyst & Industry Reports',
      'operator' => 'or',
      'value' => array(
        1 => '1',
      ),
    ),
    3 => array(
      'title' => 'Brochures',
      'operator' => 'or',
      'value' => array(
        2 => '2',
      ),
    ),
    4 => array(
      'title' => 'Case Studies',
      'operator' => 'or',
      'value' => array(
        3 => '3',
      ),
    ),
  );
  $handler->display->display_options['filters']['field_resource_type_tid']['reduce_duplicates'] = TRUE;
  $handler->display->display_options['filters']['field_resource_type_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_resource_type_tid']['vocabulary'] = 'resource_type';
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Industry (field_industry) */
  $handler->display->display_options['filters']['field_industry_tid']['id'] = 'field_industry_tid';
  $handler->display->display_options['filters']['field_industry_tid']['table'] = 'field_data_field_industry';
  $handler->display->display_options['filters']['field_industry_tid']['field'] = 'field_industry_tid';
  $handler->display->display_options['filters']['field_industry_tid']['value'] = array(
    42 => '42',
    14 => '14',
    27 => '27',
    21 => '21',
    35 => '35',
    23 => '23',
    33 => '33',
    24 => '24',
    30 => '30',
    41 => '41',
    47 => '47',
    34 => '34',
    44 => '44',
  );
  $handler->display->display_options['filters']['field_industry_tid']['group'] = 1;
  $handler->display->display_options['filters']['field_industry_tid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_industry_tid']['expose']['operator_id'] = 'field_industry_tid_op';
  $handler->display->display_options['filters']['field_industry_tid']['expose']['label'] = 'Industry';
  $handler->display->display_options['filters']['field_industry_tid']['expose']['operator'] = 'field_industry_tid_op';
  $handler->display->display_options['filters']['field_industry_tid']['expose']['identifier'] = 'field_industry_tid';
  $handler->display->display_options['filters']['field_industry_tid']['expose']['multiple'] = TRUE;
  $handler->display->display_options['filters']['field_industry_tid']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    4 => 0,
    3 => 0,
  );
  $handler->display->display_options['filters']['field_industry_tid']['expose']['reduce'] = TRUE;
  $handler->display->display_options['filters']['field_industry_tid']['group_info']['label'] = 'Industry';
  $handler->display->display_options['filters']['field_industry_tid']['group_info']['identifier'] = 'field_industry_tid';
  $handler->display->display_options['filters']['field_industry_tid']['group_info']['multiple'] = TRUE;
  $handler->display->display_options['filters']['field_industry_tid']['group_info']['default_group'] = '1';
  $handler->display->display_options['filters']['field_industry_tid']['group_info']['group_items'] = array(
    1 => array(
      'title' => 'All',
      'operator' => 'or',
      'value' => array(
        27 => '27',
        28 => '28',
        29 => '29',
        30 => '30',
        31 => '31',
        32 => '32',
        33 => '33',
        34 => '34',
        35 => '35',
        36 => '36',
        37 => '37',
        38 => '38',
        39 => '39',
      ),
    ),
    2 => array(
      'title' => 'Aerospace and Defense',
      'operator' => 'or',
      'value' => array(
        27 => '27',
      ),
    ),
    3 => array(
      'title' => 'Apparel',
      'operator' => 'or',
      'value' => array(
        28 => '28',
      ),
    ),
    4 => array(
      'title' => 'Automotive',
      'operator' => 'or',
      'value' => array(
        29 => '29',
      ),
    ),
    5 => array(
      'title' => 'Chemical',
      'operator' => 'or',
      'value' => array(
        30 => '30',
      ),
    ),
  );
  $handler->display->display_options['filters']['field_industry_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_industry_tid']['vocabulary'] = 'industry';
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'podcast' => 'podcast',
    'resource' => 'resource',
  );
  $handler->display->display_options['filters']['type']['group'] = 1;
  $handler->display->display_options['allow']['use_pager'] = 0;
  $handler->display->display_options['allow']['items_per_page'] = 0;
  $handler->display->display_options['allow']['offset'] = 0;
  $handler->display->display_options['allow']['link_to_view'] = 0;
  $handler->display->display_options['allow']['more_link'] = 0;
  $handler->display->display_options['allow']['path_override'] = 'path_override';
  $handler->display->display_options['allow']['title_override'] = 0;
  $handler->display->display_options['allow']['exposed_form'] = 0;
  $handler->display->display_options['allow']['fields_override'] = 0;
  $handler->display->display_options['inherit_panels_path'] = '1';

  /* Display: Block */
  $handler = $view->new_display('block', 'Block', 'block_1');
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'grid';
  $handler->display->display_options['style_options']['columns'] = '3';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'entity';
  $handler->display->display_options['row_options']['view_mode'] = 'teaser';
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Area of Interest (field_solution_area) */
  $handler->display->display_options['filters']['field_solution_area_tid']['id'] = 'field_solution_area_tid';
  $handler->display->display_options['filters']['field_solution_area_tid']['table'] = 'field_data_field_solution_area';
  $handler->display->display_options['filters']['field_solution_area_tid']['field'] = 'field_solution_area_tid';
  $handler->display->display_options['filters']['field_solution_area_tid']['group'] = 1;
  $handler->display->display_options['filters']['field_solution_area_tid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_solution_area_tid']['expose']['operator_id'] = 'field_solution_area_tid_op';
  $handler->display->display_options['filters']['field_solution_area_tid']['expose']['label'] = 'Solution Area (field_solution_area)';
  $handler->display->display_options['filters']['field_solution_area_tid']['expose']['operator'] = 'field_solution_area_tid_op';
  $handler->display->display_options['filters']['field_solution_area_tid']['expose']['identifier'] = 'field_solution_area_tid';
  $handler->display->display_options['filters']['field_solution_area_tid']['expose']['multiple'] = TRUE;
  $handler->display->display_options['filters']['field_solution_area_tid']['is_grouped'] = TRUE;
  $handler->display->display_options['filters']['field_solution_area_tid']['group_info']['label'] = 'Solution Area';
  $handler->display->display_options['filters']['field_solution_area_tid']['group_info']['identifier'] = 'field_solution_area_tid';
  $handler->display->display_options['filters']['field_solution_area_tid']['group_info']['multiple'] = TRUE;
  $handler->display->display_options['filters']['field_solution_area_tid']['group_info']['group_items'] = array(
    1 => array(
      'title' => 'All',
      'operator' => 'or',
      'value' => array(
        26 => '26',
        24 => '24',
        25 => '25',
        20 => '20',
        21 => '21',
        22 => '22',
        23 => '23',
      ),
    ),
    2 => array(
      'title' => 'Duty Management',
      'operator' => 'or',
      'value' => array(
        26 => '26',
      ),
    ),
    3 => array(
      'title' => 'Export Management',
      'operator' => 'or',
      'value' => array(
        24 => '24',
      ),
    ),
    4 => array(
      'title' => 'Import Management',
      'operator' => 'or',
      'value' => array(
        25 => '25',
      ),
    ),
  );
  $handler->display->display_options['filters']['field_solution_area_tid']['reduce_duplicates'] = TRUE;
  $handler->display->display_options['filters']['field_solution_area_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_solution_area_tid']['vocabulary'] = 'solution_area';
  /* Filter criterion: Content: Audience (field_audience) */
  $handler->display->display_options['filters']['field_audience_tid']['id'] = 'field_audience_tid';
  $handler->display->display_options['filters']['field_audience_tid']['table'] = 'field_data_field_audience';
  $handler->display->display_options['filters']['field_audience_tid']['field'] = 'field_audience_tid';
  $handler->display->display_options['filters']['field_audience_tid']['operator'] = 'and';
  $handler->display->display_options['filters']['field_audience_tid']['value'] = array(
    11 => '11',
    12 => '12',
  );
  $handler->display->display_options['filters']['field_audience_tid']['group'] = 1;
  $handler->display->display_options['filters']['field_audience_tid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_audience_tid']['expose']['operator_id'] = 'field_audience_tid_op';
  $handler->display->display_options['filters']['field_audience_tid']['expose']['label'] = 'Audience (field_audience)';
  $handler->display->display_options['filters']['field_audience_tid']['expose']['operator'] = 'field_audience_tid_op';
  $handler->display->display_options['filters']['field_audience_tid']['expose']['identifier'] = 'field_audience_tid';
  $handler->display->display_options['filters']['field_audience_tid']['expose']['multiple'] = TRUE;
  $handler->display->display_options['filters']['field_audience_tid']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    4 => 0,
    3 => 0,
  );
  $handler->display->display_options['filters']['field_audience_tid']['expose']['reduce'] = TRUE;
  $handler->display->display_options['filters']['field_audience_tid']['is_grouped'] = TRUE;
  $handler->display->display_options['filters']['field_audience_tid']['group_info']['label'] = 'Audience';
  $handler->display->display_options['filters']['field_audience_tid']['group_info']['identifier'] = 'field_audience_tid';
  $handler->display->display_options['filters']['field_audience_tid']['group_info']['multiple'] = TRUE;
  $handler->display->display_options['filters']['field_audience_tid']['group_info']['group_items'] = array(
    1 => array(
      'title' => 'All',
      'operator' => 'or',
      'value' => array(
        11 => '11',
        12 => '12',
      ),
    ),
    2 => array(
      'title' => 'Enterprise',
      'operator' => 'or',
      'value' => array(
        11 => '11',
      ),
    ),
    3 => array(
      'title' => 'Mid-Market',
      'operator' => 'and',
      'value' => array(
        12 => '12',
      ),
    ),
  );
  $handler->display->display_options['filters']['field_audience_tid']['reduce_duplicates'] = TRUE;
  $handler->display->display_options['filters']['field_audience_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_audience_tid']['vocabulary'] = 'audience';
  /* Filter criterion: Content: Resource Type (field_resource_type) */
  $handler->display->display_options['filters']['field_resource_type_tid']['id'] = 'field_resource_type_tid';
  $handler->display->display_options['filters']['field_resource_type_tid']['table'] = 'field_data_field_resource_type';
  $handler->display->display_options['filters']['field_resource_type_tid']['field'] = 'field_resource_type_tid';
  $handler->display->display_options['filters']['field_resource_type_tid']['group'] = 1;
  $handler->display->display_options['filters']['field_resource_type_tid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_resource_type_tid']['expose']['operator_id'] = 'field_resource_type_tid_op';
  $handler->display->display_options['filters']['field_resource_type_tid']['expose']['label'] = 'Resource Type (field_resource_type)';
  $handler->display->display_options['filters']['field_resource_type_tid']['expose']['operator'] = 'field_resource_type_tid_op';
  $handler->display->display_options['filters']['field_resource_type_tid']['expose']['identifier'] = 'field_resource_type_tid';
  $handler->display->display_options['filters']['field_resource_type_tid']['expose']['multiple'] = TRUE;
  $handler->display->display_options['filters']['field_resource_type_tid']['is_grouped'] = TRUE;
  $handler->display->display_options['filters']['field_resource_type_tid']['group_info']['label'] = 'Resource Type';
  $handler->display->display_options['filters']['field_resource_type_tid']['group_info']['identifier'] = 'field_resource_type_tid';
  $handler->display->display_options['filters']['field_resource_type_tid']['group_info']['multiple'] = TRUE;
  $handler->display->display_options['filters']['field_resource_type_tid']['group_info']['group_items'] = array(
    1 => array(
      'title' => 'All',
      'operator' => 'or',
      'value' => array(
        1 => '1',
        2 => '2',
        3 => '3',
        4 => '4',
        26 => '26',
        19 => '19',
        29 => '29',
        43 => '43',
        6 => '6',
        62 => '62',
        64 => '64',
        28 => '28',
        20 => '20',
      ),
    ),
    2 => array(
      'title' => 'Analyst & Industry Reports',
      'operator' => 'or',
      'value' => array(
        1 => '1',
      ),
    ),
    3 => array(
      'title' => 'Brochures',
      'operator' => 'or',
      'value' => array(
        2 => '2',
      ),
    ),
    4 => array(
      'title' => 'Case Studies',
      'operator' => 'or',
      'value' => array(
        3 => '3',
      ),
    ),
  );
  $handler->display->display_options['filters']['field_resource_type_tid']['reduce_duplicates'] = TRUE;
  $handler->display->display_options['filters']['field_resource_type_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_resource_type_tid']['vocabulary'] = 'resource_type';
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Industry (field_industry) */
  $handler->display->display_options['filters']['field_industry_tid']['id'] = 'field_industry_tid';
  $handler->display->display_options['filters']['field_industry_tid']['table'] = 'field_data_field_industry';
  $handler->display->display_options['filters']['field_industry_tid']['field'] = 'field_industry_tid';
  $handler->display->display_options['filters']['field_industry_tid']['group'] = 1;
  $handler->display->display_options['filters']['field_industry_tid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_industry_tid']['expose']['operator_id'] = 'field_industry_tid_op';
  $handler->display->display_options['filters']['field_industry_tid']['expose']['label'] = 'Industry (field_industry)';
  $handler->display->display_options['filters']['field_industry_tid']['expose']['operator'] = 'field_industry_tid_op';
  $handler->display->display_options['filters']['field_industry_tid']['expose']['identifier'] = 'field_industry_tid';
  $handler->display->display_options['filters']['field_industry_tid']['expose']['multiple'] = TRUE;
  $handler->display->display_options['filters']['field_industry_tid']['is_grouped'] = TRUE;
  $handler->display->display_options['filters']['field_industry_tid']['group_info']['label'] = 'Industry';
  $handler->display->display_options['filters']['field_industry_tid']['group_info']['identifier'] = 'field_industry_tid';
  $handler->display->display_options['filters']['field_industry_tid']['group_info']['multiple'] = TRUE;
  $handler->display->display_options['filters']['field_industry_tid']['group_info']['default_group'] = '1';
  $handler->display->display_options['filters']['field_industry_tid']['group_info']['group_items'] = array(
    1 => array(
      'title' => 'All',
      'operator' => 'or',
      'value' => array(
        27 => '27',
        28 => '28',
        29 => '29',
        30 => '30',
        31 => '31',
        32 => '32',
        33 => '33',
        34 => '34',
        35 => '35',
        36 => '36',
        37 => '37',
        38 => '38',
        39 => '39',
      ),
    ),
    2 => array(
      'title' => 'Aerospace and Defense',
      'operator' => 'or',
      'value' => array(
        27 => '27',
      ),
    ),
    3 => array(
      'title' => 'Apparel',
      'operator' => 'or',
      'value' => array(
        28 => '28',
      ),
    ),
    4 => array(
      'title' => 'Automotive',
      'operator' => 'or',
      'value' => array(
        29 => '29',
      ),
    ),
    5 => array(),
  );
  $handler->display->display_options['filters']['field_industry_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_industry_tid']['vocabulary'] = 'industry';
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'podcast' => 'podcast',
    'resource' => 'resource',
    'webinar' => 'webinar',
  );
  $handler->display->display_options['filters']['type']['group'] = 1;
  /* Filter criterion: Content: Persona (field_persona) */
  $handler->display->display_options['filters']['field_persona_tid']['id'] = 'field_persona_tid';
  $handler->display->display_options['filters']['field_persona_tid']['table'] = 'field_data_field_persona';
  $handler->display->display_options['filters']['field_persona_tid']['field'] = 'field_persona_tid';
  $handler->display->display_options['filters']['field_persona_tid']['group'] = 1;
  $handler->display->display_options['filters']['field_persona_tid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_persona_tid']['expose']['operator_id'] = 'field_persona_tid_op';
  $handler->display->display_options['filters']['field_persona_tid']['expose']['label'] = 'Persona (field_persona)';
  $handler->display->display_options['filters']['field_persona_tid']['expose']['operator'] = 'field_persona_tid_op';
  $handler->display->display_options['filters']['field_persona_tid']['expose']['identifier'] = 'field_persona_tid';
  $handler->display->display_options['filters']['field_persona_tid']['expose']['multiple'] = TRUE;
  $handler->display->display_options['filters']['field_persona_tid']['is_grouped'] = TRUE;
  $handler->display->display_options['filters']['field_persona_tid']['group_info']['label'] = 'Persona';
  $handler->display->display_options['filters']['field_persona_tid']['group_info']['identifier'] = 'field_persona_tid';
  $handler->display->display_options['filters']['field_persona_tid']['group_info']['multiple'] = TRUE;
  $handler->display->display_options['filters']['field_persona_tid']['group_info']['group_items'] = array(
    1 => array(
      'title' => 'All',
      'operator' => 'or',
      'value' => array(
        40 => '40',
        41 => '41',
        42 => '42',
        43 => '43',
        44 => '44',
        45 => '45',
      ),
    ),
    2 => array(
      'title' => 'Compliance',
      'operator' => 'or',
      'value' => array(
        40 => '40',
      ),
    ),
    3 => array(
      'title' => 'Finance',
      'operator' => 'or',
      'value' => array(
        41 => '41',
      ),
    ),
    4 => array(
      'title' => 'IT',
      'operator' => 'or',
      'value' => array(
        42 => '42',
      ),
    ),
  );
  $handler->display->display_options['filters']['field_persona_tid']['reduce_duplicates'] = TRUE;
  $handler->display->display_options['filters']['field_persona_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_persona_tid']['vocabulary'] = 'persona';
  /* Filter criterion: Content: Buying Stage (field_buying_stage) */
  $handler->display->display_options['filters']['field_buying_stage_tid']['id'] = 'field_buying_stage_tid';
  $handler->display->display_options['filters']['field_buying_stage_tid']['table'] = 'field_data_field_buying_stage';
  $handler->display->display_options['filters']['field_buying_stage_tid']['field'] = 'field_buying_stage_tid';
  $handler->display->display_options['filters']['field_buying_stage_tid']['group'] = 1;
  $handler->display->display_options['filters']['field_buying_stage_tid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_buying_stage_tid']['expose']['operator_id'] = 'field_buying_stage_tid_op';
  $handler->display->display_options['filters']['field_buying_stage_tid']['expose']['label'] = 'Buying Stage (field_buying_stage)';
  $handler->display->display_options['filters']['field_buying_stage_tid']['expose']['operator'] = 'field_buying_stage_tid_op';
  $handler->display->display_options['filters']['field_buying_stage_tid']['expose']['identifier'] = 'field_buying_stage_tid';
  $handler->display->display_options['filters']['field_buying_stage_tid']['expose']['multiple'] = TRUE;
  $handler->display->display_options['filters']['field_buying_stage_tid']['is_grouped'] = TRUE;
  $handler->display->display_options['filters']['field_buying_stage_tid']['group_info']['label'] = 'Buying Stage';
  $handler->display->display_options['filters']['field_buying_stage_tid']['group_info']['identifier'] = 'field_buying_stage_tid';
  $handler->display->display_options['filters']['field_buying_stage_tid']['group_info']['multiple'] = TRUE;
  $handler->display->display_options['filters']['field_buying_stage_tid']['group_info']['group_items'] = array(
    1 => array(
      'title' => 'All',
      'operator' => 'or',
      'value' => array(
        46 => '46',
        47 => '47',
        48 => '48',
      ),
    ),
    2 => array(
      'title' => 'BOFU',
      'operator' => 'or',
      'value' => array(
        46 => '46',
      ),
    ),
    3 => array(
      'title' => 'MOFU',
      'operator' => 'or',
      'value' => array(
        47 => '47',
      ),
    ),
    4 => array(
      'title' => 'TOFU',
      'operator' => 'or',
      'value' => array(
        48 => '48',
      ),
    ),
  );
  $handler->display->display_options['filters']['field_buying_stage_tid']['reduce_duplicates'] = TRUE;
  $handler->display->display_options['filters']['field_buying_stage_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_buying_stage_tid']['vocabulary'] = 'buying_stage';
  $export['resource_library_search'] = $view;

  $view = new view();
  $view->name = 'resources';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Resources';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Relationship: Content: Taxonomy terms on node */
  $handler->display->display_options['relationships']['term_node_tid']['id'] = 'term_node_tid';
  $handler->display->display_options['relationships']['term_node_tid']['table'] = 'node';
  $handler->display->display_options['relationships']['term_node_tid']['field'] = 'term_node_tid';
  $handler->display->display_options['relationships']['term_node_tid']['required'] = TRUE;
  $handler->display->display_options['relationships']['term_node_tid']['vocabularies'] = array(
    'resource_type' => 'resource_type',
  );
  /* Field: Content: PDF Download */
  $handler->display->display_options['fields']['field_resource_link']['id'] = 'field_resource_link';
  $handler->display->display_options['fields']['field_resource_link']['table'] = 'field_data_field_resource_link';
  $handler->display->display_options['fields']['field_resource_link']['field'] = 'field_resource_link';
  $handler->display->display_options['fields']['field_resource_link']['label'] = '';
  $handler->display->display_options['fields']['field_resource_link']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_resource_link']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_resource_link']['click_sort_column'] = 'url';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['title']['alter']['path'] = '[field_resource_link]';
  $handler->display->display_options['fields']['title']['alter']['absolute'] = TRUE;
  $handler->display->display_options['fields']['title']['alter']['target'] = '_blank';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['link_to_node'] = FALSE;
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
    'resource' => 'resource',
  );
  /* Filter criterion: Content: Resource Type (field_resource_type) */
  $handler->display->display_options['filters']['field_resource_type_tid']['id'] = 'field_resource_type_tid';
  $handler->display->display_options['filters']['field_resource_type_tid']['table'] = 'field_data_field_resource_type';
  $handler->display->display_options['filters']['field_resource_type_tid']['field'] = 'field_resource_type_tid';
  $handler->display->display_options['filters']['field_resource_type_tid']['value'] = array(
    4 => '4',
  );
  $handler->display->display_options['filters']['field_resource_type_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_resource_type_tid']['vocabulary'] = 'resource_type';

  /* Display: Resource Library */
  $handler = $view->new_display('panel_pane', 'Resource Library', 'panel_pane_1');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Resource Library';
  $handler->display->display_options['defaults']['css_class'] = FALSE;
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: PDF Download */
  $handler->display->display_options['fields']['field_resource_link']['id'] = 'field_resource_link';
  $handler->display->display_options['fields']['field_resource_link']['table'] = 'field_data_field_resource_link';
  $handler->display->display_options['fields']['field_resource_link']['field'] = 'field_resource_link';
  $handler->display->display_options['fields']['field_resource_link']['label'] = '';
  $handler->display->display_options['fields']['field_resource_link']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_resource_link']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_resource_link']['click_sort_column'] = 'url';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['title']['alter']['path'] = '[field_resource_link]';
  $handler->display->display_options['fields']['title']['alter']['absolute'] = TRUE;
  $handler->display->display_options['fields']['title']['alter']['target'] = '_blank';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['link_to_node'] = FALSE;
  /* Field: Content: Resource Type */
  $handler->display->display_options['fields']['field_resource_type']['id'] = 'field_resource_type';
  $handler->display->display_options['fields']['field_resource_type']['table'] = 'field_data_field_resource_type';
  $handler->display->display_options['fields']['field_resource_type']['field'] = 'field_resource_type';
  $handler->display->display_options['fields']['field_resource_type']['label'] = '';
  $handler->display->display_options['fields']['field_resource_type']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['field_resource_type']['alter']['path'] = '[field_resource_link] == Content: External Link';
  $handler->display->display_options['fields']['field_resource_type']['alter']['external'] = TRUE;
  $handler->display->display_options['fields']['field_resource_type']['alter']['target'] = '_blank';
  $handler->display->display_options['fields']['field_resource_type']['element_label_colon'] = FALSE;
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  /* Sort criterion: Content: Resource Date (field_resource_date) */
  $handler->display->display_options['sorts']['field_resource_date_value']['id'] = 'field_resource_date_value';
  $handler->display->display_options['sorts']['field_resource_date_value']['table'] = 'field_data_field_resource_date';
  $handler->display->display_options['sorts']['field_resource_date_value']['field'] = 'field_resource_date_value';
  $handler->display->display_options['sorts']['field_resource_date_value']['order'] = 'DESC';
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: Content: Has taxonomy term ID */
  $handler->display->display_options['arguments']['tid']['id'] = 'tid';
  $handler->display->display_options['arguments']['tid']['table'] = 'taxonomy_index';
  $handler->display->display_options['arguments']['tid']['field'] = 'tid';
  $handler->display->display_options['arguments']['tid']['default_action'] = 'default';
  $handler->display->display_options['arguments']['tid']['default_argument_type'] = 'taxonomy_tid';
  $handler->display->display_options['arguments']['tid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['tid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['tid']['summary_options']['items_per_page'] = '25';
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
    'resource' => 'resource',
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
  $export['resources'] = $view;

  return $export;
}
