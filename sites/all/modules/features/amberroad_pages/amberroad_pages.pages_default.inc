<?php
/**
 * @file
 * amberroad_pages.pages_default.inc
 */

/**
 * Implements hook_default_page_manager_handlers().
 */
function amberroad_pages_default_page_manager_handlers() {
  $export = array();

  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'node_view__basic_page';
  $handler->task = 'node_view';
  $handler->subtask = '';
  $handler->handler = 'panel_context';
  $handler->weight = -98;
  $handler->conf = array(
    'title' => 'Basic Page',
    'no_blocks' => 0,
    'pipeline' => 'ipe',
    'body_classes_to_remove' => '',
    'body_classes_to_add' => '',
    'css_id' => '',
    'css' => '',
    'contexts' => array(),
    'relationships' => array(),
    'name' => 'basic_page',
    'access' => array(
      'logic' => 'and',
      'plugins' => array(
        0 => array(
          'name' => 'entity_bundle:node',
          'settings' => array(
            'type' => array(
              'page' => 'page',
            ),
          ),
          'context' => 'argument_entity_id:node_1',
          'not' => FALSE,
        ),
      ),
    ),
  );
  $display = new panels_display();
  $display->layout = 'amberroad_custom_onerowtwocols_theme';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'content_banner' => NULL,
      'content_main' => NULL,
      'content_sidebar' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = '%node:title';
  $display->uuid = 'f3dea044-8263-4eee-b2dc-19ca9dfef746';
  $display->content = array();
  $display->panels = array();
  $pane = new stdClass();
  $pane->pid = 'new-990a82f3-d571-48ba-9969-9ac90e3cf739';
  $pane->panel = 'content_banner';
  $pane->type = 'entity_field';
  $pane->subtype = 'node:field_header_image';
  $pane->shown = TRUE;
  $pane->access = array(
    'plugins' => array(
      0 => array(
        'name' => 'entity_field_value:node:page:field_banner_option',
        'settings' => array(
          'field_banner_option' => array(
            'und' => array(
              0 => array(
                'value' => 'static',
              ),
            ),
          ),
          'field_banner_option_value' => array(
            0 => 'static',
          ),
        ),
        'context' => 'argument_entity_id:node_1',
        'not' => FALSE,
      ),
    ),
  );
  $pane->configuration = array(
    'label' => 'hidden',
    'formatter' => 'image_link_formatter',
    'delta_limit' => 0,
    'delta_offset' => '0',
    'delta_reversed' => FALSE,
    'formatter_settings' => array(
      'image_style' => '',
      'image_link' => 'field_header_link',
    ),
    'context' => 'argument_entity_id:node_1',
    'override_title' => 0,
    'override_title_text' => '',
    'override_title_heading' => 'h2',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 0;
  $pane->locks = array();
  $pane->uuid = '990a82f3-d571-48ba-9969-9ac90e3cf739';
  $display->content['new-990a82f3-d571-48ba-9969-9ac90e3cf739'] = $pane;
  $display->panels['content_banner'][0] = 'new-990a82f3-d571-48ba-9969-9ac90e3cf739';
  $pane = new stdClass();
  $pane->pid = 'new-3a2574f3-f695-4d72-85cb-3362620ec960';
  $pane->panel = 'content_banner';
  $pane->type = 'entity_field';
  $pane->subtype = 'node:field_banner_image';
  $pane->shown = TRUE;
  $pane->access = array(
    'plugins' => array(
      0 => array(
        'name' => 'entity_field_value:node:page:field_banner_option',
        'settings' => array(
          'field_banner_option' => array(
            'und' => array(
              0 => array(
                'value' => 'caption',
              ),
            ),
          ),
          'field_banner_option_value' => array(
            0 => 'caption',
          ),
        ),
        'context' => 'argument_entity_id:node_1',
        'not' => FALSE,
      ),
    ),
  );
  $pane->configuration = array(
    'label' => 'hidden',
    'formatter' => 'image',
    'delta_limit' => 0,
    'delta_offset' => '0',
    'delta_reversed' => FALSE,
    'formatter_settings' => array(
      'image_style' => '',
      'image_link' => '',
    ),
    'context' => 'argument_entity_id:node_1',
    'override_title' => 1,
    'override_title_text' => '',
    'override_title_heading' => 'h2',
  );
  $pane->cache = array();
  $pane->style = array(
    'style' => 'wrapper_element',
    'settings' => array(),
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 1;
  $pane->locks = array();
  $pane->uuid = '3a2574f3-f695-4d72-85cb-3362620ec960';
  $display->content['new-3a2574f3-f695-4d72-85cb-3362620ec960'] = $pane;
  $display->panels['content_banner'][1] = 'new-3a2574f3-f695-4d72-85cb-3362620ec960';
  $pane = new stdClass();
  $pane->pid = 'new-24dac1a0-3822-4e95-8136-a2edbf94efae';
  $pane->panel = 'content_banner';
  $pane->type = 'entity_field';
  $pane->subtype = 'node:field_caption_title';
  $pane->shown = TRUE;
  $pane->access = array(
    'plugins' => array(
      0 => array(
        'name' => 'entity_field_value:node:page:field_banner_option',
        'settings' => array(
          'field_banner_option' => array(
            'und' => array(
              0 => array(
                'value' => 'caption',
              ),
            ),
          ),
          'field_banner_option_value' => array(
            0 => 'caption',
          ),
        ),
        'context' => 'argument_entity_id:node_1',
        'not' => FALSE,
      ),
    ),
  );
  $pane->configuration = array(
    'label' => 'hidden',
    'formatter' => 'text_default',
    'delta_limit' => 0,
    'delta_offset' => '0',
    'delta_reversed' => FALSE,
    'formatter_settings' => array(),
    'context' => 'argument_entity_id:node_1',
    'override_title' => 1,
    'override_title_text' => '',
    'override_title_heading' => 'h2',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => array(
      'title' => array(
        'prefix' => '',
        'suffix' => '',
      ),
      'content' => array(
        'prefix' => '<div class="dynamic-banner-wrapper">',
        'suffix' => '',
      ),
      'theme' => 0,
    ),
    'style' => 'wrapper_raw',
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 2;
  $pane->locks = array();
  $pane->uuid = '24dac1a0-3822-4e95-8136-a2edbf94efae';
  $display->content['new-24dac1a0-3822-4e95-8136-a2edbf94efae'] = $pane;
  $display->panels['content_banner'][2] = 'new-24dac1a0-3822-4e95-8136-a2edbf94efae';
  $pane = new stdClass();
  $pane->pid = 'new-94ff8796-cf55-450a-bb4d-15448924f473';
  $pane->panel = 'content_banner';
  $pane->type = 'entity_field';
  $pane->subtype = 'node:field_caption_descrption';
  $pane->shown = TRUE;
  $pane->access = array(
    'plugins' => array(
      0 => array(
        'name' => 'entity_field_value:node:page:field_banner_option',
        'settings' => array(
          'field_banner_option' => array(
            'und' => array(
              0 => array(
                'value' => 'caption',
              ),
            ),
          ),
          'field_banner_option_value' => array(
            0 => 'caption',
          ),
        ),
        'context' => 'argument_entity_id:node_1',
        'not' => FALSE,
      ),
    ),
  );
  $pane->configuration = array(
    'label' => 'hidden',
    'formatter' => 'text_default',
    'delta_limit' => 0,
    'delta_offset' => '0',
    'delta_reversed' => FALSE,
    'formatter_settings' => array(),
    'context' => 'argument_entity_id:node_1',
    'override_title' => 1,
    'override_title_text' => '',
    'override_title_heading' => 'h2',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => array(
      'title' => array(
        'prefix' => '',
        'suffix' => '',
      ),
      'content' => array(
        'prefix' => '',
        'suffix' => '</div>',
      ),
      'theme' => 0,
    ),
    'style' => 'wrapper_raw',
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 3;
  $pane->locks = array();
  $pane->uuid = '94ff8796-cf55-450a-bb4d-15448924f473';
  $display->content['new-94ff8796-cf55-450a-bb4d-15448924f473'] = $pane;
  $display->panels['content_banner'][3] = 'new-94ff8796-cf55-450a-bb4d-15448924f473';
  $pane = new stdClass();
  $pane->pid = 'new-ffed7fed-1403-465e-b278-c98d9d4ed471';
  $pane->panel = 'content_banner';
  $pane->type = 'entity_field';
  $pane->subtype = 'node:field_banner_menu_details';
  $pane->shown = TRUE;
  $pane->access = array(
    'plugins' => array(
      0 => array(
        'name' => 'entity_field_value:node:page:field_banner_option',
        'settings' => array(
          'field_banner_option' => array(
            'und' => array(
              0 => array(
                'value' => 'menu',
              ),
            ),
          ),
          'field_banner_option_value' => array(
            0 => 'menu',
          ),
        ),
        'context' => 'argument_entity_id:node_1',
        'not' => FALSE,
      ),
    ),
  );
  $pane->configuration = array(
    'label' => 'hidden',
    'formatter' => 'text_default',
    'delta_limit' => 0,
    'delta_offset' => '0',
    'delta_reversed' => FALSE,
    'formatter_settings' => array(),
    'context' => 'argument_entity_id:node_1',
    'override_title' => 1,
    'override_title_text' => '',
    'override_title_heading' => 'h1',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 4;
  $pane->locks = array();
  $pane->uuid = 'ffed7fed-1403-465e-b278-c98d9d4ed471';
  $display->content['new-ffed7fed-1403-465e-b278-c98d9d4ed471'] = $pane;
  $display->panels['content_banner'][4] = 'new-ffed7fed-1403-465e-b278-c98d9d4ed471';
  $pane = new stdClass();
  $pane->pid = 'new-96825f66-383e-42b1-bf4e-dc949106699a';
  $pane->panel = 'content_banner';
  $pane->type = 'page_tabs';
  $pane->subtype = 'page_tabs';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'type' => 'both',
    'id' => 'tabs',
    'override_title' => 0,
    'override_title_text' => '',
    'override_title_heading' => 'h2',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 5;
  $pane->locks = array();
  $pane->uuid = '96825f66-383e-42b1-bf4e-dc949106699a';
  $display->content['new-96825f66-383e-42b1-bf4e-dc949106699a'] = $pane;
  $display->panels['content_banner'][5] = 'new-96825f66-383e-42b1-bf4e-dc949106699a';
  $pane = new stdClass();
  $pane->pid = 'new-b5fde5d8-1f50-4fed-b791-cc0200c4d80b';
  $pane->panel = 'content_main';
  $pane->type = 'page_title';
  $pane->subtype = 'page_title';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'markup' => 'h1',
    'class' => '',
    'id' => '',
    'override_title' => 0,
    'override_title_text' => '',
    'override_title_heading' => 'h2',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 0;
  $pane->locks = array();
  $pane->uuid = 'b5fde5d8-1f50-4fed-b791-cc0200c4d80b';
  $display->content['new-b5fde5d8-1f50-4fed-b791-cc0200c4d80b'] = $pane;
  $display->panels['content_main'][0] = 'new-b5fde5d8-1f50-4fed-b791-cc0200c4d80b';
  $pane = new stdClass();
  $pane->pid = 'new-640f4e57-0446-4154-8942-3e56c5b64877';
  $pane->panel = 'content_main';
  $pane->type = 'page_breadcrumb';
  $pane->subtype = 'page_breadcrumb';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array();
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 1;
  $pane->locks = array();
  $pane->uuid = '640f4e57-0446-4154-8942-3e56c5b64877';
  $display->content['new-640f4e57-0446-4154-8942-3e56c5b64877'] = $pane;
  $display->panels['content_main'][1] = 'new-640f4e57-0446-4154-8942-3e56c5b64877';
  $pane = new stdClass();
  $pane->pid = 'new-1f1ba5f6-b80e-4990-b565-b9fd0d9ab3c0';
  $pane->panel = 'content_main';
  $pane->type = 'entity_field';
  $pane->subtype = 'node:body';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'label' => 'hidden',
    'formatter' => 'text_default',
    'delta_limit' => 0,
    'delta_offset' => '0',
    'delta_reversed' => FALSE,
    'formatter_settings' => array(),
    'context' => 'argument_entity_id:node_1',
    'override_title' => 0,
    'override_title_text' => '',
    'override_title_heading' => 'h2',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 2;
  $pane->locks = array();
  $pane->uuid = '1f1ba5f6-b80e-4990-b565-b9fd0d9ab3c0';
  $display->content['new-1f1ba5f6-b80e-4990-b565-b9fd0d9ab3c0'] = $pane;
  $display->panels['content_main'][2] = 'new-1f1ba5f6-b80e-4990-b565-b9fd0d9ab3c0';
  $pane = new stdClass();
  $pane->pid = 'new-72e12757-ff0c-4861-9b0a-d1618e185743';
  $pane->panel = 'content_main';
  $pane->type = 'entity_field';
  $pane->subtype = 'node:field_related_blog_post';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'label' => 'hidden',
    'formatter' => 'text_default',
    'delta_limit' => 0,
    'delta_offset' => '0',
    'delta_reversed' => FALSE,
    'formatter_settings' => array(),
    'context' => 'argument_entity_id:node_1',
    'override_title' => 1,
    'override_title_text' => '',
    'override_title_heading' => 'h2',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => array(
      'title' => array(
        'prefix' => '',
        'suffix' => '',
      ),
      'content' => array(
        'prefix' => '<div class="related_blogs_wrapper">',
        'suffix' => '</div>',
      ),
      'theme' => 0,
    ),
    'style' => 'wrapper_raw',
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 3;
  $pane->locks = array();
  $pane->uuid = '72e12757-ff0c-4861-9b0a-d1618e185743';
  $display->content['new-72e12757-ff0c-4861-9b0a-d1618e185743'] = $pane;
  $display->panels['content_main'][3] = 'new-72e12757-ff0c-4861-9b0a-d1618e185743';
  $pane = new stdClass();
  $pane->pid = 'new-11f52062-6902-4c52-aa8e-569632e54df7';
  $pane->panel = 'content_sidebar';
  $pane->type = 'entity_field';
  $pane->subtype = 'node:field_rhs_ad_blocks';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'label' => 'hidden',
    'formatter' => 'field_collection_view',
    'delta_limit' => '0',
    'delta_offset' => '0',
    'delta_reversed' => 0,
    'formatter_settings' => array(
      'edit' => '',
      'delete' => '',
      'add' => '',
      'description' => 0,
      'view_mode' => 'full',
    ),
    'context' => 'argument_entity_id:node_1',
    'override_title' => 0,
    'override_title_text' => '',
    'override_title_heading' => 'h2',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array(
    'css_id' => '',
    'css_class' => 'rhs_ad_blocks',
  );
  $pane->extras = array();
  $pane->position = 0;
  $pane->locks = array();
  $pane->uuid = '11f52062-6902-4c52-aa8e-569632e54df7';
  $display->content['new-11f52062-6902-4c52-aa8e-569632e54df7'] = $pane;
  $display->panels['content_sidebar'][0] = 'new-11f52062-6902-4c52-aa8e-569632e54df7';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $export['node_view__basic_page'] = $handler;

  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'node_view__panel_context_8e4c73e1-20a6-4a19-a95a-5a083a17dc7b';
  $handler->task = 'node_view';
  $handler->subtask = '';
  $handler->handler = 'panel_context';
  $handler->weight = -97;
  $handler->conf = array(
    'title' => 'Podcast',
    'no_blocks' => 0,
    'pipeline' => 'ipe',
    'body_classes_to_remove' => '',
    'body_classes_to_add' => '',
    'css_id' => '',
    'css' => '',
    'contexts' => array(),
    'relationships' => array(),
    'name' => '',
    'access' => array(
      'plugins' => array(
        0 => array(
          'name' => 'entity_bundle:node',
          'settings' => array(
            'type' => array(
              'podcast' => 'podcast',
            ),
          ),
          'context' => 'argument_entity_id:node_1',
          'not' => FALSE,
        ),
      ),
      'logic' => 'and',
    ),
  );
  $display = new panels_display();
  $display->layout = 'amberroad_custom_onecol_theme';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'content_banner' => NULL,
      'content_main' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = '';
  $display->uuid = '2f92a18d-4ba9-4ef8-8ddb-9e6c037efc61';
  $display->content = array();
  $display->panels = array();
  $pane = new stdClass();
  $pane->pid = 'new-f55601a5-d962-42b1-a1c8-174fe9507f02';
  $pane->panel = 'content_banner';
  $pane->type = 'fieldable_panels_pane';
  $pane->subtype = 'uuid:85641390-1fc6-4cf1-80b8-cf0014e4be7d';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'view_mode' => 'header',
    'fieldable_panels_pane' => (object) array(
      'bundle' => 'box',
      'language' => '',
      'is_new' => TRUE,
      'title' => 'Podcast - Global Trade Hot Topics',
      'link' => 0,
      'path' => '',
      'reusable' => 1,
      'admin_title' => 'Header-Podcast',
      'admin_description' => '',
      'category' => 'Reusable Content',
      'vid' => '2760',
      'current_vid' => '',
      'revision' => 1,
      'fpid' => '681',
      'field_basic_image_image' => array(
        'und' => array(
          0 => array(
            'fid' => '3044',
            'display' => '1',
            'description' => '',
            'attach_button' => 'Attach',
            'upload' => '',
            'remove_button' => 'Remove',
            'width' => 2500,
            'height' => 150,
          ),
        ),
      ),
      'field_button' => array(
        'und' => array(),
      ),
      'field_text' => array(
        'und' => array(),
      ),
      'field_video' => array(
        'und' => array(),
      ),
      'field_video_width' => array(
        'und' => array(),
      ),
      'log' => '',
      'created' => 1471769627,
      'timestamp' => 1471769627,
      'changed' => 1471769627,
      'uuid' => '85641390-1fc6-4cf1-80b8-cf0014e4be7d',
      'vuuid' => 'e6a95c31-b50f-47df-bd1a-add1bb9a1b88',
      'uid' => '18',
    ),
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 0;
  $pane->locks = array();
  $pane->uuid = 'f55601a5-d962-42b1-a1c8-174fe9507f02';
  $display->content['new-f55601a5-d962-42b1-a1c8-174fe9507f02'] = $pane;
  $display->panels['content_banner'][0] = 'new-f55601a5-d962-42b1-a1c8-174fe9507f02';
  $pane = new stdClass();
  $pane->pid = 'new-a6a47d68-5c7f-4be4-9572-da392d373626';
  $pane->panel = 'content_banner';
  $pane->type = 'page_tabs';
  $pane->subtype = 'page_tabs';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'type' => 'both',
    'id' => 'tabs',
    'override_title' => 0,
    'override_title_text' => '',
    'override_title_heading' => 'h2',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 1;
  $pane->locks = array();
  $pane->uuid = 'a6a47d68-5c7f-4be4-9572-da392d373626';
  $display->content['new-a6a47d68-5c7f-4be4-9572-da392d373626'] = $pane;
  $display->panels['content_banner'][1] = 'new-a6a47d68-5c7f-4be4-9572-da392d373626';
  $pane = new stdClass();
  $pane->pid = 'new-a2eaab01-fbd2-4d26-8dc3-79d70402aafe';
  $pane->panel = 'content_main';
  $pane->type = 'node_title';
  $pane->subtype = 'node_title';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'link' => 0,
    'markup' => 'h1',
    'id' => '',
    'class' => '',
    'context' => 'argument_entity_id:node_1',
    'override_title' => 1,
    'override_title_text' => '',
    'override_title_heading' => 'h2',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => array(
      'title' => array(
        'prefix' => '',
        'suffix' => '',
      ),
      'content' => array(
        'prefix' => '<div class="podcast_node_detail">',
        'suffix' => '',
      ),
      'theme' => 0,
    ),
    'style' => 'wrapper_raw',
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 0;
  $pane->locks = array();
  $pane->uuid = 'a2eaab01-fbd2-4d26-8dc3-79d70402aafe';
  $display->content['new-a2eaab01-fbd2-4d26-8dc3-79d70402aafe'] = $pane;
  $display->panels['content_main'][0] = 'new-a2eaab01-fbd2-4d26-8dc3-79d70402aafe';
  $pane = new stdClass();
  $pane->pid = 'new-0b0d6758-d439-4959-aa65-49698c997d82';
  $pane->panel = 'content_main';
  $pane->type = 'page_breadcrumb';
  $pane->subtype = 'page_breadcrumb';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array();
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 1;
  $pane->locks = array();
  $pane->uuid = '0b0d6758-d439-4959-aa65-49698c997d82';
  $display->content['new-0b0d6758-d439-4959-aa65-49698c997d82'] = $pane;
  $display->panels['content_main'][1] = 'new-0b0d6758-d439-4959-aa65-49698c997d82';
  $pane = new stdClass();
  $pane->pid = 'new-ea1f0bca-9c9a-4e65-b416-00d56dfce4b7';
  $pane->panel = 'content_main';
  $pane->type = 'entity_field';
  $pane->subtype = 'node:field_podcast_author_image';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'label' => 'hidden',
    'formatter' => 'image',
    'delta_limit' => '0',
    'delta_offset' => '0',
    'delta_reversed' => 0,
    'formatter_settings' => array(
      'image_style' => 'author_image',
      'image_link' => '',
    ),
    'context' => 'argument_entity_id:node_1',
    'override_title' => 0,
    'override_title_text' => '',
    'override_title_heading' => 'h2',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 2;
  $pane->locks = array();
  $pane->uuid = 'ea1f0bca-9c9a-4e65-b416-00d56dfce4b7';
  $display->content['new-ea1f0bca-9c9a-4e65-b416-00d56dfce4b7'] = $pane;
  $display->panels['content_main'][2] = 'new-ea1f0bca-9c9a-4e65-b416-00d56dfce4b7';
  $pane = new stdClass();
  $pane->pid = 'new-4e3904ba-72ef-487e-b1ac-3aefa6663977';
  $pane->panel = 'content_main';
  $pane->type = 'entity_field';
  $pane->subtype = 'node:field_podcast_presented_by';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'label' => 'inline',
    'formatter' => 'text_default',
    'delta_limit' => 0,
    'delta_offset' => '0',
    'delta_reversed' => FALSE,
    'formatter_settings' => array(),
    'context' => 'argument_entity_id:node_1',
    'override_title' => 0,
    'override_title_text' => '',
    'override_title_heading' => 'h2',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 3;
  $pane->locks = array();
  $pane->uuid = '4e3904ba-72ef-487e-b1ac-3aefa6663977';
  $display->content['new-4e3904ba-72ef-487e-b1ac-3aefa6663977'] = $pane;
  $display->panels['content_main'][3] = 'new-4e3904ba-72ef-487e-b1ac-3aefa6663977';
  $pane = new stdClass();
  $pane->pid = 'new-26e1ad2c-68b9-4303-9c2e-5165fa680017';
  $pane->panel = 'content_main';
  $pane->type = 'entity_field';
  $pane->subtype = 'node:body';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'label' => 'hidden',
    'formatter' => 'text_default',
    'delta_limit' => 0,
    'delta_offset' => '0',
    'delta_reversed' => FALSE,
    'formatter_settings' => array(),
    'context' => 'argument_entity_id:node_1',
    'override_title' => 0,
    'override_title_text' => '',
    'override_title_heading' => 'h2',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 4;
  $pane->locks = array();
  $pane->uuid = '26e1ad2c-68b9-4303-9c2e-5165fa680017';
  $display->content['new-26e1ad2c-68b9-4303-9c2e-5165fa680017'] = $pane;
  $display->panels['content_main'][4] = 'new-26e1ad2c-68b9-4303-9c2e-5165fa680017';
  $pane = new stdClass();
  $pane->pid = 'new-3ef1f84a-d6a1-4dca-a94d-615b11f692ed';
  $pane->panel = 'content_main';
  $pane->type = 'entity_field';
  $pane->subtype = 'node:field_podcast_mp3';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'label' => 'hidden',
    'formatter' => 'file_default',
    'delta_limit' => 0,
    'delta_offset' => '0',
    'delta_reversed' => FALSE,
    'formatter_settings' => array(),
    'context' => 'argument_entity_id:node_1',
    'override_title' => 0,
    'override_title_text' => '',
    'override_title_heading' => 'h2',
  );
  $pane->cache = array();
  $pane->style = array(
    'style' => 'wrapper_raw',
    'settings' => array(
      'title' => array(
        'prefix' => '',
        'suffix' => '',
      ),
      'content' => array(
        'prefix' => '',
        'suffix' => '</div>',
      ),
      'theme' => 0,
    ),
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 5;
  $pane->locks = array();
  $pane->uuid = '3ef1f84a-d6a1-4dca-a94d-615b11f692ed';
  $display->content['new-3ef1f84a-d6a1-4dca-a94d-615b11f692ed'] = $pane;
  $display->panels['content_main'][5] = 'new-3ef1f84a-d6a1-4dca-a94d-615b11f692ed';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $export['node_view__panel_context_8e4c73e1-20a6-4a19-a95a-5a083a17dc7b'] = $handler;

  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'node_view__press_release';
  $handler->task = 'node_view';
  $handler->subtask = '';
  $handler->handler = 'panel_context';
  $handler->weight = -94;
  $handler->conf = array(
    'title' => 'Press Release',
    'no_blocks' => 0,
    'pipeline' => 'ipe',
    'body_classes_to_remove' => '',
    'body_classes_to_add' => '',
    'css_id' => '',
    'css' => '',
    'contexts' => array(),
    'relationships' => array(),
    'name' => 'press_release',
    'access' => array(
      'plugins' => array(
        0 => array(
          'name' => 'entity_bundle:node',
          'settings' => array(
            'type' => array(
              'press_release' => 'press_release',
            ),
          ),
          'context' => 'argument_entity_id:node_1',
          'not' => FALSE,
        ),
      ),
      'logic' => 'and',
    ),
  );
  $display = new panels_display();
  $display->layout = 'amberroad_custom_onecol_theme';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'content_banner' => NULL,
      'content_main' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = 'Press Releases';
  $display->uuid = '6eaf1b5c-e61b-452a-9a8f-9d0826d8415b';
  $display->content = array();
  $display->panels = array();
  $pane = new stdClass();
  $pane->pid = 'new-c7391832-7941-4e8a-8f2a-88aba9876bcc';
  $pane->panel = 'content_banner';
  $pane->type = 'block';
  $pane->subtype = 'block-9';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'override_title' => 1,
    'override_title_text' => '',
    'override_title_heading' => 'h2',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 0;
  $pane->locks = array();
  $pane->uuid = 'c7391832-7941-4e8a-8f2a-88aba9876bcc';
  $display->content['new-c7391832-7941-4e8a-8f2a-88aba9876bcc'] = $pane;
  $display->panels['content_banner'][0] = 'new-c7391832-7941-4e8a-8f2a-88aba9876bcc';
  $pane = new stdClass();
  $pane->pid = 'new-ec372454-5274-4c02-8a29-fa69e379eab6';
  $pane->panel = 'content_banner';
  $pane->type = 'page_tabs';
  $pane->subtype = 'page_tabs';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'type' => 'both',
    'id' => 'tabs',
    'override_title' => 0,
    'override_title_text' => '',
    'override_title_heading' => 'h2',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 1;
  $pane->locks = array();
  $pane->uuid = 'ec372454-5274-4c02-8a29-fa69e379eab6';
  $display->content['new-ec372454-5274-4c02-8a29-fa69e379eab6'] = $pane;
  $display->panels['content_banner'][1] = 'new-ec372454-5274-4c02-8a29-fa69e379eab6';
  $pane = new stdClass();
  $pane->pid = 'new-52cb26b1-1e85-443b-baf5-31b68b8adbff';
  $pane->panel = 'content_main';
  $pane->type = 'page_title';
  $pane->subtype = 'page_title';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'markup' => 'h1',
    'class' => '',
    'id' => '',
    'override_title' => 0,
    'override_title_text' => '',
    'override_title_heading' => 'h2',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 0;
  $pane->locks = array();
  $pane->uuid = '52cb26b1-1e85-443b-baf5-31b68b8adbff';
  $display->content['new-52cb26b1-1e85-443b-baf5-31b68b8adbff'] = $pane;
  $display->panels['content_main'][0] = 'new-52cb26b1-1e85-443b-baf5-31b68b8adbff';
  $pane = new stdClass();
  $pane->pid = 'new-2c8913ee-4472-4950-b153-6cb12f1b57e5';
  $pane->panel = 'content_main';
  $pane->type = 'page_breadcrumb';
  $pane->subtype = 'page_breadcrumb';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array();
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 1;
  $pane->locks = array();
  $pane->uuid = '2c8913ee-4472-4950-b153-6cb12f1b57e5';
  $display->content['new-2c8913ee-4472-4950-b153-6cb12f1b57e5'] = $pane;
  $display->panels['content_main'][1] = 'new-2c8913ee-4472-4950-b153-6cb12f1b57e5';
  $pane = new stdClass();
  $pane->pid = 'new-c4981de0-34da-47b8-9f35-165d76532599';
  $pane->panel = 'content_main';
  $pane->type = 'entity_field';
  $pane->subtype = 'node:field_press_release_date';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'label' => 'hidden',
    'formatter' => 'date_default',
    'delta_limit' => 0,
    'delta_offset' => '0',
    'delta_reversed' => FALSE,
    'formatter_settings' => array(
      'format_type' => 'press_release',
      'multiple_number' => '',
      'multiple_from' => '',
      'multiple_to' => '',
      'fromto' => 'both',
    ),
    'context' => 'argument_entity_id:node_1',
    'override_title' => 0,
    'override_title_text' => '',
    'override_title_heading' => 'h2',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 2;
  $pane->locks = array();
  $pane->uuid = 'c4981de0-34da-47b8-9f35-165d76532599';
  $display->content['new-c4981de0-34da-47b8-9f35-165d76532599'] = $pane;
  $display->panels['content_main'][2] = 'new-c4981de0-34da-47b8-9f35-165d76532599';
  $pane = new stdClass();
  $pane->pid = 'new-20eba07a-4d6d-406f-ac91-8e2093faec25';
  $pane->panel = 'content_main';
  $pane->type = 'block';
  $pane->subtype = 'amberroad_blocks-press_release_back_link';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'override_title' => 1,
    'override_title_text' => '',
    'override_title_heading' => 'h2',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 3;
  $pane->locks = array();
  $pane->uuid = '20eba07a-4d6d-406f-ac91-8e2093faec25';
  $display->content['new-20eba07a-4d6d-406f-ac91-8e2093faec25'] = $pane;
  $display->panels['content_main'][3] = 'new-20eba07a-4d6d-406f-ac91-8e2093faec25';
  $pane = new stdClass();
  $pane->pid = 'new-19207147-23a0-4e8f-b53a-e9fa71157837';
  $pane->panel = 'content_main';
  $pane->type = 'entity_field';
  $pane->subtype = 'node:body';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'label' => 'hidden',
    'formatter' => 'text_default',
    'delta_limit' => 0,
    'delta_offset' => '0',
    'delta_reversed' => FALSE,
    'formatter_settings' => array(),
    'context' => 'argument_entity_id:node_1',
    'override_title' => 0,
    'override_title_text' => '',
    'override_title_heading' => 'h2',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 4;
  $pane->locks = array();
  $pane->uuid = '19207147-23a0-4e8f-b53a-e9fa71157837';
  $display->content['new-19207147-23a0-4e8f-b53a-e9fa71157837'] = $pane;
  $display->panels['content_main'][4] = 'new-19207147-23a0-4e8f-b53a-e9fa71157837';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = 'new-52cb26b1-1e85-443b-baf5-31b68b8adbff';
  $handler->conf['display'] = $display;
  $export['node_view__press_release'] = $handler;

  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'node_view__solution_area';
  $handler->task = 'node_view';
  $handler->subtask = '';
  $handler->handler = 'panel_context';
  $handler->weight = -96;
  $handler->conf = array(
    'title' => 'Solution Area',
    'no_blocks' => 0,
    'pipeline' => 'standard',
    'body_classes_to_remove' => '',
    'body_classes_to_add' => '',
    'css_id' => '',
    'css' => '',
    'contexts' => array(),
    'relationships' => array(),
    'name' => 'solution_area',
    'access' => array(
      'plugins' => array(
        0 => array(
          'name' => 'entity_bundle:node',
          'settings' => array(
            'type' => array(
              'solution_area' => 'solution_area',
            ),
          ),
          'context' => 'argument_entity_id:node_1',
          'not' => FALSE,
        ),
      ),
      'logic' => 'and',
    ),
  );
  $display = new panels_display();
  $display->layout = 'amberroad_custom_onerowtwocols_theme';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'content_banner' => NULL,
      'content_main' => NULL,
      'content_sidebar' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = '%node:title';
  $display->uuid = '55fde7e5-70fe-45de-8ea3-4d79602e56d9';
  $display->content = array();
  $display->panels = array();
  $pane = new stdClass();
  $pane->pid = 'new-626a9d46-78bc-4777-be59-162a75ae7acd';
  $pane->panel = 'content_banner';
  $pane->type = 'entity_field';
  $pane->subtype = 'node:field_header_image';
  $pane->shown = TRUE;
  $pane->access = array(
    'plugins' => array(
      0 => array(
        'name' => 'entity_field_value:node:solution_area:field_banner_option',
        'settings' => array(
          'field_banner_option' => array(
            'und' => array(
              0 => array(
                'value' => 'static',
              ),
            ),
          ),
          'field_banner_option_value' => array(
            0 => 'static',
          ),
        ),
        'context' => 'argument_entity_id:node_1',
        'not' => FALSE,
      ),
    ),
  );
  $pane->configuration = array(
    'label' => 'hidden',
    'formatter' => 'image',
    'delta_limit' => 0,
    'delta_offset' => '0',
    'delta_reversed' => FALSE,
    'formatter_settings' => array(
      'image_style' => '',
      'image_link' => 'content',
    ),
    'context' => 'argument_entity_id:node_1',
    'override_title' => 1,
    'override_title_text' => '',
    'override_title_heading' => 'h2',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 0;
  $pane->locks = array();
  $pane->uuid = '626a9d46-78bc-4777-be59-162a75ae7acd';
  $display->content['new-626a9d46-78bc-4777-be59-162a75ae7acd'] = $pane;
  $display->panels['content_banner'][0] = 'new-626a9d46-78bc-4777-be59-162a75ae7acd';
  $pane = new stdClass();
  $pane->pid = 'new-9920d73d-845f-49c3-b113-7790258f2e06';
  $pane->panel = 'content_banner';
  $pane->type = 'entity_field';
  $pane->subtype = 'node:field_banner_image';
  $pane->shown = TRUE;
  $pane->access = array(
    'plugins' => array(
      0 => array(
        'name' => 'entity_field_value:node:solution_area:field_banner_option',
        'settings' => array(
          'field_banner_option' => array(
            'und' => array(
              0 => array(
                'value' => 'caption',
              ),
            ),
          ),
          'field_banner_option_value' => array(
            0 => 'caption',
          ),
        ),
        'context' => 'argument_entity_id:node_1',
        'not' => FALSE,
      ),
    ),
  );
  $pane->configuration = array(
    'label' => 'hidden',
    'formatter' => 'image',
    'delta_limit' => 0,
    'delta_offset' => '0',
    'delta_reversed' => FALSE,
    'formatter_settings' => array(
      'image_style' => '',
      'image_link' => '',
    ),
    'context' => 'argument_entity_id:node_1',
    'override_title' => 1,
    'override_title_text' => '',
    'override_title_heading' => 'h2',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 1;
  $pane->locks = array();
  $pane->uuid = '9920d73d-845f-49c3-b113-7790258f2e06';
  $display->content['new-9920d73d-845f-49c3-b113-7790258f2e06'] = $pane;
  $display->panels['content_banner'][1] = 'new-9920d73d-845f-49c3-b113-7790258f2e06';
  $pane = new stdClass();
  $pane->pid = 'new-57070dd7-e85c-4087-a9c4-3497c4a2dcc0';
  $pane->panel = 'content_banner';
  $pane->type = 'entity_field';
  $pane->subtype = 'node:field_caption_title';
  $pane->shown = TRUE;
  $pane->access = array(
    'plugins' => array(
      0 => array(
        'name' => 'entity_field_value:node:solution_area:field_banner_option',
        'settings' => array(
          'field_banner_option' => array(
            'und' => array(
              0 => array(
                'value' => 'caption',
              ),
            ),
          ),
          'field_banner_option_value' => array(
            0 => 'caption',
          ),
        ),
        'context' => 'argument_entity_id:node_1',
        'not' => FALSE,
      ),
    ),
  );
  $pane->configuration = array(
    'label' => 'hidden',
    'formatter' => 'text_default',
    'delta_limit' => 0,
    'delta_offset' => '0',
    'delta_reversed' => FALSE,
    'formatter_settings' => array(),
    'context' => 'argument_entity_id:node_1',
    'override_title' => 1,
    'override_title_text' => '',
    'override_title_heading' => 'h2',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => array(
      'title' => array(
        'prefix' => '',
        'suffix' => '',
      ),
      'content' => array(
        'prefix' => '<div class="dynamic-banner-wrapper">',
        'suffix' => '',
      ),
      'theme' => 0,
    ),
    'style' => 'wrapper_raw',
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 2;
  $pane->locks = array();
  $pane->uuid = '57070dd7-e85c-4087-a9c4-3497c4a2dcc0';
  $display->content['new-57070dd7-e85c-4087-a9c4-3497c4a2dcc0'] = $pane;
  $display->panels['content_banner'][2] = 'new-57070dd7-e85c-4087-a9c4-3497c4a2dcc0';
  $pane = new stdClass();
  $pane->pid = 'new-6f10e19c-a74a-4ea5-a714-9a6037540261';
  $pane->panel = 'content_banner';
  $pane->type = 'entity_field';
  $pane->subtype = 'node:field_caption_descrption';
  $pane->shown = TRUE;
  $pane->access = array(
    'plugins' => array(
      0 => array(
        'name' => 'entity_field_value:node:solution_area:field_banner_option',
        'settings' => array(
          'field_banner_option' => array(
            'und' => array(
              0 => array(
                'value' => 'caption',
              ),
            ),
          ),
          'field_banner_option_value' => array(
            0 => 'caption',
          ),
        ),
        'context' => 'argument_entity_id:node_1',
        'not' => FALSE,
      ),
    ),
  );
  $pane->configuration = array(
    'label' => 'hidden',
    'formatter' => 'text_default',
    'delta_limit' => 0,
    'delta_offset' => '0',
    'delta_reversed' => FALSE,
    'formatter_settings' => array(),
    'context' => 'argument_entity_id:node_1',
    'override_title' => 1,
    'override_title_text' => '',
    'override_title_heading' => 'h2',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => array(
      'title' => array(
        'prefix' => '',
        'suffix' => '',
      ),
      'content' => array(
        'prefix' => '',
        'suffix' => '</div>',
      ),
      'theme' => 0,
    ),
    'style' => 'wrapper_raw',
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 3;
  $pane->locks = array();
  $pane->uuid = '6f10e19c-a74a-4ea5-a714-9a6037540261';
  $display->content['new-6f10e19c-a74a-4ea5-a714-9a6037540261'] = $pane;
  $display->panels['content_banner'][3] = 'new-6f10e19c-a74a-4ea5-a714-9a6037540261';
  $pane = new stdClass();
  $pane->pid = 'new-a9f441d5-239d-4d2c-ba38-3a628e11f342';
  $pane->panel = 'content_banner';
  $pane->type = 'entity_field';
  $pane->subtype = 'node:field_banner_menu_details';
  $pane->shown = TRUE;
  $pane->access = array(
    'plugins' => array(
      0 => array(
        'name' => 'entity_field_value:node:solution_area:field_banner_option',
        'settings' => array(
          'field_banner_option' => array(
            'und' => array(
              0 => array(
                'value' => 'menu',
              ),
            ),
          ),
          'field_banner_option_value' => array(
            0 => 'menu',
          ),
        ),
        'context' => 'argument_entity_id:node_1',
        'not' => FALSE,
      ),
    ),
  );
  $pane->configuration = array(
    'label' => 'hidden',
    'formatter' => 'text_default',
    'delta_limit' => 0,
    'delta_offset' => '0',
    'delta_reversed' => FALSE,
    'formatter_settings' => array(),
    'context' => 'argument_entity_id:node_1',
    'override_title' => 1,
    'override_title_text' => '',
    'override_title_heading' => 'h2',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 4;
  $pane->locks = array();
  $pane->uuid = 'a9f441d5-239d-4d2c-ba38-3a628e11f342';
  $display->content['new-a9f441d5-239d-4d2c-ba38-3a628e11f342'] = $pane;
  $display->panels['content_banner'][4] = 'new-a9f441d5-239d-4d2c-ba38-3a628e11f342';
  $pane = new stdClass();
  $pane->pid = 'new-266c36d3-35f9-4c9a-9fe3-ffbb53cb3e3a';
  $pane->panel = 'content_banner';
  $pane->type = 'page_tabs';
  $pane->subtype = 'page_tabs';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'type' => 'both',
    'id' => 'tabs',
    'override_title' => 0,
    'override_title_text' => '',
    'override_title_heading' => 'h2',
  );
  $pane->cache = array();
  $pane->style = array();
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 5;
  $pane->locks = array();
  $pane->uuid = '266c36d3-35f9-4c9a-9fe3-ffbb53cb3e3a';
  $display->content['new-266c36d3-35f9-4c9a-9fe3-ffbb53cb3e3a'] = $pane;
  $display->panels['content_banner'][5] = 'new-266c36d3-35f9-4c9a-9fe3-ffbb53cb3e3a';
  $pane = new stdClass();
  $pane->pid = 'new-38882da0-8628-48e9-b658-fd41c9de80e8';
  $pane->panel = 'content_main';
  $pane->type = 'page_title';
  $pane->subtype = 'page_title';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'markup' => 'h1',
    'class' => '',
    'id' => '',
    'override_title' => 0,
    'override_title_text' => '',
    'override_title_heading' => 'h2',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 0;
  $pane->locks = array();
  $pane->uuid = '38882da0-8628-48e9-b658-fd41c9de80e8';
  $display->content['new-38882da0-8628-48e9-b658-fd41c9de80e8'] = $pane;
  $display->panels['content_main'][0] = 'new-38882da0-8628-48e9-b658-fd41c9de80e8';
  $pane = new stdClass();
  $pane->pid = 'new-646a541a-64ab-401e-adeb-c2f0018264cb';
  $pane->panel = 'content_main';
  $pane->type = 'page_breadcrumb';
  $pane->subtype = 'page_breadcrumb';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array();
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 1;
  $pane->locks = array();
  $pane->uuid = '646a541a-64ab-401e-adeb-c2f0018264cb';
  $display->content['new-646a541a-64ab-401e-adeb-c2f0018264cb'] = $pane;
  $display->panels['content_main'][1] = 'new-646a541a-64ab-401e-adeb-c2f0018264cb';
  $pane = new stdClass();
  $pane->pid = 'new-6179edbb-3af1-4c77-b07b-76c53cdf0c6d';
  $pane->panel = 'content_main';
  $pane->type = 'entity_field';
  $pane->subtype = 'node:body';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'label' => 'hidden',
    'formatter' => 'text_default',
    'delta_limit' => 0,
    'delta_offset' => '0',
    'delta_reversed' => FALSE,
    'formatter_settings' => array(),
    'context' => 'argument_entity_id:node_1',
    'override_title' => 0,
    'override_title_text' => '',
    'override_title_heading' => 'h2',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 2;
  $pane->locks = array();
  $pane->uuid = '6179edbb-3af1-4c77-b07b-76c53cdf0c6d';
  $display->content['new-6179edbb-3af1-4c77-b07b-76c53cdf0c6d'] = $pane;
  $display->panels['content_main'][2] = 'new-6179edbb-3af1-4c77-b07b-76c53cdf0c6d';
  $pane = new stdClass();
  $pane->pid = 'new-958b962e-e3d6-4c1f-afe8-0e7d9ad24f77';
  $pane->panel = 'content_main';
  $pane->type = 'entity_field';
  $pane->subtype = 'node:field_related_content_descriptio';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'label' => 'hidden',
    'formatter' => 'text_default',
    'delta_limit' => 0,
    'delta_offset' => '0',
    'delta_reversed' => FALSE,
    'formatter_settings' => array(),
    'context' => 'argument_entity_id:node_1',
    'override_title' => 0,
    'override_title_text' => '',
    'override_title_heading' => 'h2',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 3;
  $pane->locks = array();
  $pane->uuid = '958b962e-e3d6-4c1f-afe8-0e7d9ad24f77';
  $display->content['new-958b962e-e3d6-4c1f-afe8-0e7d9ad24f77'] = $pane;
  $display->panels['content_main'][3] = 'new-958b962e-e3d6-4c1f-afe8-0e7d9ad24f77';
  $pane = new stdClass();
  $pane->pid = 'new-15790f68-337a-4155-a2c4-7f987618dfa5';
  $pane->panel = 'content_main';
  $pane->type = 'entity_field';
  $pane->subtype = 'node:field_related_solution_area_cont';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'label' => 'above',
    'formatter' => 'entityreference_entity_view',
    'delta_limit' => '0',
    'delta_offset' => '0',
    'delta_reversed' => 0,
    'formatter_settings' => array(
      'view_mode' => 'related_contents',
      'links' => 0,
    ),
    'context' => 'argument_entity_id:node_1',
    'override_title' => 0,
    'override_title_text' => '',
    'override_title_heading' => 'h2',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 4;
  $pane->locks = array();
  $pane->uuid = '15790f68-337a-4155-a2c4-7f987618dfa5';
  $display->content['new-15790f68-337a-4155-a2c4-7f987618dfa5'] = $pane;
  $display->panels['content_main'][4] = 'new-15790f68-337a-4155-a2c4-7f987618dfa5';
  $pane = new stdClass();
  $pane->pid = 'new-5f83b99d-a4de-4f78-b461-69533ff91b52';
  $pane->panel = 'content_main';
  $pane->type = 'entity_field';
  $pane->subtype = 'node:field_related_blog_post';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'label' => 'hidden',
    'formatter' => 'text_default',
    'delta_limit' => 0,
    'delta_offset' => '0',
    'delta_reversed' => FALSE,
    'formatter_settings' => array(),
    'context' => 'argument_entity_id:node_1',
    'override_title' => 1,
    'override_title_text' => '',
    'override_title_heading' => 'h2',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => array(
      'title' => array(
        'prefix' => '',
        'suffix' => '',
      ),
      'content' => array(
        'prefix' => '<div class="related_blogs_wrapper">',
        'suffix' => '</div>',
      ),
      'theme' => 0,
    ),
    'style' => 'wrapper_raw',
  );
  $pane->css = array(
    'css_id' => '',
    'css_class' => 'related_blog',
  );
  $pane->extras = array();
  $pane->position = 5;
  $pane->locks = array();
  $pane->uuid = '5f83b99d-a4de-4f78-b461-69533ff91b52';
  $display->content['new-5f83b99d-a4de-4f78-b461-69533ff91b52'] = $pane;
  $display->panels['content_main'][5] = 'new-5f83b99d-a4de-4f78-b461-69533ff91b52';
  $pane = new stdClass();
  $pane->pid = 'new-a314c014-5653-4d92-898a-c001bebafec8';
  $pane->panel = 'content_sidebar';
  $pane->type = 'entity_field';
  $pane->subtype = 'node:field_rhs_ad_blocks';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'label' => 'hidden',
    'formatter' => 'field_collection_view',
    'delta_limit' => '0',
    'delta_offset' => '0',
    'delta_reversed' => 0,
    'formatter_settings' => array(
      'edit' => '',
      'delete' => '',
      'add' => '',
      'description' => 0,
      'view_mode' => 'full',
    ),
    'context' => 'argument_entity_id:node_1',
    'override_title' => 0,
    'override_title_text' => '',
    'override_title_heading' => 'h2',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array(
    'css_id' => '',
    'css_class' => 'rhs_ad_blocks',
  );
  $pane->extras = array();
  $pane->position = 0;
  $pane->locks = array();
  $pane->uuid = 'a314c014-5653-4d92-898a-c001bebafec8';
  $display->content['new-a314c014-5653-4d92-898a-c001bebafec8'] = $pane;
  $display->panels['content_sidebar'][0] = 'new-a314c014-5653-4d92-898a-c001bebafec8';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = 'new-626a9d46-78bc-4777-be59-162a75ae7acd';
  $handler->conf['display'] = $display;
  $export['node_view__solution_area'] = $handler;

  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'node_view__testimonial';
  $handler->task = 'node_view';
  $handler->subtask = '';
  $handler->handler = 'panel_context';
  $handler->weight = -95;
  $handler->conf = array(
    'title' => 'Testimonial',
    'no_blocks' => 0,
    'pipeline' => 'ipe',
    'body_classes_to_remove' => '',
    'body_classes_to_add' => '',
    'css_id' => '',
    'css' => '',
    'contexts' => array(),
    'relationships' => array(),
    'name' => 'testimonial',
    'access' => array(
      'plugins' => array(
        0 => array(
          'name' => 'entity_bundle:node',
          'settings' => array(
            'type' => array(
              'testimonial' => 'testimonial',
            ),
          ),
          'context' => 'argument_entity_id:node_1',
          'not' => FALSE,
        ),
      ),
      'logic' => 'and',
    ),
  );
  $display = new panels_display();
  $display->layout = 'amberroad_custom_onecol_theme';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'content_banner' => NULL,
      'content_main' => NULL,
    ),
    'content_banner' => array(
      'style' => '0',
    ),
  );
  $display->cache = array();
  $display->title = 'Testimonials';
  $display->uuid = 'b44fd84c-974d-41da-b505-939322b71cf1';
  $display->content = array();
  $display->panels = array();
  $pane = new stdClass();
  $pane->pid = 'new-1c758a02-9ac0-4f5f-8108-83470d15ce30';
  $pane->panel = 'content_banner';
  $pane->type = 'block';
  $pane->subtype = 'block-6';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'override_title' => 0,
    'override_title_text' => 'Customer Header',
    'override_title_heading' => 'h2',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 0;
  $pane->locks = array();
  $pane->uuid = '1c758a02-9ac0-4f5f-8108-83470d15ce30';
  $display->content['new-1c758a02-9ac0-4f5f-8108-83470d15ce30'] = $pane;
  $display->panels['content_banner'][0] = 'new-1c758a02-9ac0-4f5f-8108-83470d15ce30';
  $pane = new stdClass();
  $pane->pid = 'new-f25b92a6-5e98-43cf-aa95-aefe3c87ae95';
  $pane->panel = 'content_banner';
  $pane->type = 'page_tabs';
  $pane->subtype = 'page_tabs';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'type' => 'both',
    'id' => 'tabs',
    'override_title' => 0,
    'override_title_text' => '',
    'override_title_heading' => 'h2',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 1;
  $pane->locks = array();
  $pane->uuid = 'f25b92a6-5e98-43cf-aa95-aefe3c87ae95';
  $display->content['new-f25b92a6-5e98-43cf-aa95-aefe3c87ae95'] = $pane;
  $display->panels['content_banner'][1] = 'new-f25b92a6-5e98-43cf-aa95-aefe3c87ae95';
  $pane = new stdClass();
  $pane->pid = 'new-d9cf4f36-f937-40e8-a6da-28358ffc3aae';
  $pane->panel = 'content_main';
  $pane->type = 'page_title';
  $pane->subtype = 'page_title';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'markup' => 'h1',
    'class' => '',
    'id' => '',
    'override_title' => 0,
    'override_title_text' => '',
    'override_title_heading' => 'h2',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 0;
  $pane->locks = array();
  $pane->uuid = 'd9cf4f36-f937-40e8-a6da-28358ffc3aae';
  $display->content['new-d9cf4f36-f937-40e8-a6da-28358ffc3aae'] = $pane;
  $display->panels['content_main'][0] = 'new-d9cf4f36-f937-40e8-a6da-28358ffc3aae';
  $pane = new stdClass();
  $pane->pid = 'new-c3dfc258-85a3-4965-b4e5-ffcda6ff4b7b';
  $pane->panel = 'content_main';
  $pane->type = 'page_breadcrumb';
  $pane->subtype = 'page_breadcrumb';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array();
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 1;
  $pane->locks = array();
  $pane->uuid = 'c3dfc258-85a3-4965-b4e5-ffcda6ff4b7b';
  $display->content['new-c3dfc258-85a3-4965-b4e5-ffcda6ff4b7b'] = $pane;
  $display->panels['content_main'][1] = 'new-c3dfc258-85a3-4965-b4e5-ffcda6ff4b7b';
  $pane = new stdClass();
  $pane->pid = 'new-8b887b52-1af7-4616-9f99-c9853fc2e7d7';
  $pane->panel = 'content_main';
  $pane->type = 'views';
  $pane->subtype = 'testimonial';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'override_pager_settings' => 0,
    'use_pager' => 0,
    'nodes_per_page' => '0',
    'pager_id' => '0',
    'offset' => '0',
    'more_link' => 0,
    'feed_icons' => 0,
    'panel_args' => 0,
    'link_to_view' => 0,
    'args' => '',
    'url' => '',
    'display' => 'block_1',
    'override_title' => 1,
    'override_title_text' => '',
    'override_title_heading' => 'h2',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array(
    'css_id' => '',
    'css_class' => 'pane-testimonials-list-block',
  );
  $pane->extras = array();
  $pane->position = 2;
  $pane->locks = array();
  $pane->uuid = '8b887b52-1af7-4616-9f99-c9853fc2e7d7';
  $display->content['new-8b887b52-1af7-4616-9f99-c9853fc2e7d7'] = $pane;
  $display->panels['content_main'][2] = 'new-8b887b52-1af7-4616-9f99-c9853fc2e7d7';
  $pane = new stdClass();
  $pane->pid = 'new-3ee2b188-bb90-430b-961c-681115650838';
  $pane->panel = 'content_main';
  $pane->type = 'entity_view';
  $pane->subtype = 'node';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'view_mode' => 'full',
    'context' => 'argument_entity_id:node_1',
    'override_title' => 1,
    'override_title_text' => '',
    'override_title_heading' => 'h2',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array(
    'css_id' => '',
    'css_class' => 'pane-testimonial-detail-block',
  );
  $pane->extras = array();
  $pane->position = 3;
  $pane->locks = array();
  $pane->uuid = '3ee2b188-bb90-430b-961c-681115650838';
  $display->content['new-3ee2b188-bb90-430b-961c-681115650838'] = $pane;
  $display->panels['content_main'][3] = 'new-3ee2b188-bb90-430b-961c-681115650838';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = 'new-d9cf4f36-f937-40e8-a6da-28358ffc3aae';
  $handler->conf['display'] = $display;
  $export['node_view__testimonial'] = $handler;

  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'term_view__careers';
  $handler->task = 'term_view';
  $handler->subtask = '';
  $handler->handler = 'panel_context';
  $handler->weight = 4;
  $handler->conf = array(
    'title' => 'Careers',
    'no_blocks' => 0,
    'pipeline' => 'ipe',
    'body_classes_to_remove' => '',
    'body_classes_to_add' => 'page-taxonomy-term-careers',
    'css_id' => '',
    'css' => '',
    'contexts' => array(),
    'relationships' => array(),
    'name' => 'careers',
    'access' => array(
      'plugins' => array(
        0 => array(
          'name' => 'term_vocabulary',
          'settings' => array(
            'machine_name' => array(
              'career_location' => 'career_location',
            ),
          ),
          'context' => 'argument_term_1',
          'not' => FALSE,
        ),
      ),
      'logic' => 'and',
    ),
  );
  $display = new panels_display();
  $display->layout = 'amberroad_custom_onecol_theme';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'content_banner' => NULL,
      'content_main' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = '';
  $display->uuid = 'ae00bd84-f0f8-48ae-8d8c-19a38ae2904d';
  $display->content = array();
  $display->panels = array();
  $pane = new stdClass();
  $pane->pid = 'new-a0477487-8be9-4581-88c1-fa5595653ef3';
  $pane->panel = 'content_banner';
  $pane->type = 'fieldable_panels_pane';
  $pane->subtype = 'uuid:42151f22-91f2-4bf9-bcf4-f6ccefc19262';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'view_mode' => 'header',
    'fieldable_panels_pane' => (object) array(
      'bundle' => 'box',
      'language' => 'und',
      'is_new' => TRUE,
      'title' => 'Join Amber Road',
      'link' => 0,
      'path' => '',
      'reusable' => 0,
      'admin_title' => '',
      'admin_description' => '',
      'category' => 'Reusable Content',
      'vid' => '2612',
      'current_vid' => '',
      'revision' => 1,
      'fpid' => '614',
      'field_basic_image_image' => array(
        'und' => array(
          0 => array(
            'fid' => '2941',
            'display' => '1',
            'description' => '',
            'attach_button' => 'Attach',
            'upload' => '',
            'remove_button' => 'Remove',
            'width' => 2500,
            'height' => 150,
          ),
        ),
      ),
      'field_button' => array(
        'und' => array(),
      ),
      'field_text' => array(
        'und' => array(),
      ),
      'field_video' => array(
        'und' => array(),
      ),
      'field_video_width' => array(
        'und' => array(),
      ),
      'log' => '',
      'created' => 1467292618,
      'timestamp' => 1467292618,
      'changed' => 1467292618,
      'uuid' => '42151f22-91f2-4bf9-bcf4-f6ccefc19262',
      'vuuid' => 'fca3997e-9118-4b18-a09c-d8c837a152c3',
      'uid' => '43',
    ),
  );
  $pane->cache = array();
  $pane->style = array();
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 0;
  $pane->locks = array();
  $pane->uuid = 'a0477487-8be9-4581-88c1-fa5595653ef3';
  $display->content['new-a0477487-8be9-4581-88c1-fa5595653ef3'] = $pane;
  $display->panels['content_banner'][0] = 'new-a0477487-8be9-4581-88c1-fa5595653ef3';
  $pane = new stdClass();
  $pane->pid = 'new-13d14a95-fae5-4681-ae00-1debeefff255';
  $pane->panel = 'content_main';
  $pane->type = 'page_title';
  $pane->subtype = 'page_title';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'markup' => 'h1',
    'class' => '',
    'id' => '',
    'override_title' => 0,
    'override_title_text' => '',
    'override_title_heading' => 'h2',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 0;
  $pane->locks = array();
  $pane->uuid = '13d14a95-fae5-4681-ae00-1debeefff255';
  $display->content['new-13d14a95-fae5-4681-ae00-1debeefff255'] = $pane;
  $display->panels['content_main'][0] = 'new-13d14a95-fae5-4681-ae00-1debeefff255';
  $pane = new stdClass();
  $pane->pid = 'new-1fa33c53-7c75-42d4-8445-f6f4259dc855';
  $pane->panel = 'content_main';
  $pane->type = 'page_breadcrumb';
  $pane->subtype = 'page_breadcrumb';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array();
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 1;
  $pane->locks = array();
  $pane->uuid = '1fa33c53-7c75-42d4-8445-f6f4259dc855';
  $display->content['new-1fa33c53-7c75-42d4-8445-f6f4259dc855'] = $pane;
  $display->panels['content_main'][1] = 'new-1fa33c53-7c75-42d4-8445-f6f4259dc855';
  $pane = new stdClass();
  $pane->pid = 'new-30c3b5ce-02df-4f58-b66d-6cefe2f39e66';
  $pane->panel = 'content_main';
  $pane->type = 'block';
  $pane->subtype = 'amberroad_blocks-how_to_apply_career';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'override_title' => 0,
    'override_title_text' => '',
    'override_title_heading' => 'h2',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 2;
  $pane->locks = array();
  $pane->uuid = '30c3b5ce-02df-4f58-b66d-6cefe2f39e66';
  $display->content['new-30c3b5ce-02df-4f58-b66d-6cefe2f39e66'] = $pane;
  $display->panels['content_main'][2] = 'new-30c3b5ce-02df-4f58-b66d-6cefe2f39e66';
  $pane = new stdClass();
  $pane->pid = 'new-11c67ce5-24ae-4cdf-9e74-cdf0cf09747c';
  $pane->panel = 'content_main';
  $pane->type = 'custom';
  $pane->subtype = 'custom';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'admin_title' => 'Current Opportunities',
    'title' => '',
    'body' => '<p><a name="top"></a><strong>Current Opportunities</strong></p>
',
    'format' => 'full_html',
    'substitute' => 1,
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 3;
  $pane->locks = array();
  $pane->uuid = '11c67ce5-24ae-4cdf-9e74-cdf0cf09747c';
  $display->content['new-11c67ce5-24ae-4cdf-9e74-cdf0cf09747c'] = $pane;
  $display->panels['content_main'][3] = 'new-11c67ce5-24ae-4cdf-9e74-cdf0cf09747c';
  $pane = new stdClass();
  $pane->pid = 'new-f11f1ec3-4627-44a7-bb45-f40493a55ca4';
  $pane->panel = 'content_main';
  $pane->type = 'views_panes';
  $pane->subtype = 'careers-panel_pane_1';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array();
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array(
    'css_id' => '',
    'css_class' => 'pane-view-all-careers',
  );
  $pane->extras = array();
  $pane->position = 4;
  $pane->locks = array();
  $pane->uuid = 'f11f1ec3-4627-44a7-bb45-f40493a55ca4';
  $display->content['new-f11f1ec3-4627-44a7-bb45-f40493a55ca4'] = $pane;
  $display->panels['content_main'][4] = 'new-f11f1ec3-4627-44a7-bb45-f40493a55ca4';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $export['term_view__careers'] = $handler;

  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'term_view__resources';
  $handler->task = 'term_view';
  $handler->subtask = '';
  $handler->handler = 'panel_context';
  $handler->weight = 3;
  $handler->conf = array(
    'title' => 'Resources',
    'no_blocks' => 0,
    'pipeline' => 'ipe',
    'body_classes_to_remove' => '',
    'body_classes_to_add' => '',
    'css_id' => '',
    'css' => '',
    'contexts' => array(),
    'relationships' => array(),
    'name' => 'resources',
    'access' => array(
      'plugins' => array(
        0 => array(
          'name' => 'term_vocabulary',
          'settings' => array(
            'machine_name' => array(
              'resource_type' => 'resource_type',
            ),
          ),
          'context' => 'argument_term_1',
          'not' => FALSE,
        ),
      ),
      'logic' => 'and',
    ),
  );
  $display = new panels_display();
  $display->layout = 'amberroad_custom_onecol_theme';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'content_banner' => NULL,
      'content_main' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = '';
  $display->uuid = '433182eb-10e4-452a-9e87-110f65e81646';
  $display->content = array();
  $display->panels = array();
  $pane = new stdClass();
  $pane->pid = 'new-91e14767-6475-47ea-a301-c15168ed64c9';
  $pane->panel = 'content_banner';
  $pane->type = 'block';
  $pane->subtype = 'amberroad_blocks-resource_banner';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'override_title' => 0,
    'override_title_text' => '',
    'override_title_heading' => 'h2',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 0;
  $pane->locks = array();
  $pane->uuid = '91e14767-6475-47ea-a301-c15168ed64c9';
  $display->content['new-91e14767-6475-47ea-a301-c15168ed64c9'] = $pane;
  $display->panels['content_banner'][0] = 'new-91e14767-6475-47ea-a301-c15168ed64c9';
  $pane = new stdClass();
  $pane->pid = 'new-4a782683-8d02-42e8-98b9-a32c8e86fc32';
  $pane->panel = 'content_main';
  $pane->type = 'page_title';
  $pane->subtype = 'page_title';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'markup' => 'h1',
    'class' => '',
    'id' => '',
    'override_title' => 0,
    'override_title_text' => '',
    'override_title_heading' => 'h2',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 0;
  $pane->locks = array();
  $pane->uuid = '4a782683-8d02-42e8-98b9-a32c8e86fc32';
  $display->content['new-4a782683-8d02-42e8-98b9-a32c8e86fc32'] = $pane;
  $display->panels['content_main'][0] = 'new-4a782683-8d02-42e8-98b9-a32c8e86fc32';
  $pane = new stdClass();
  $pane->pid = 'new-b2950e6b-0170-4703-b4f5-8fe3f2f89f41';
  $pane->panel = 'content_main';
  $pane->type = 'page_breadcrumb';
  $pane->subtype = 'page_breadcrumb';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array();
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 1;
  $pane->locks = array();
  $pane->uuid = 'b2950e6b-0170-4703-b4f5-8fe3f2f89f41';
  $display->content['new-b2950e6b-0170-4703-b4f5-8fe3f2f89f41'] = $pane;
  $display->panels['content_main'][1] = 'new-b2950e6b-0170-4703-b4f5-8fe3f2f89f41';
  $pane = new stdClass();
  $pane->pid = 'new-c1cb6d5c-53b0-44ac-a160-26f136f4ec71';
  $pane->panel = 'content_main';
  $pane->type = 'custom';
  $pane->subtype = 'custom';
  $pane->shown = TRUE;
  $pane->access = array(
    'plugins' => array(
      0 => array(
        'name' => 'path_visibility',
        'settings' => array(
          'visibility_setting' => '1',
          'paths' => 'html/rl_case_studies.shtml',
        ),
        'context' => 'empty',
        'not' => FALSE,
      ),
    ),
  );
  $pane->configuration = array(
    'admin_title' => 'Case Studies Header',
    'title' => '',
    'body' => 'Demonstrating leadership across a range of industries, and with a proven track record for software excellence and innovation, Amber Road powers the global operations for some of the most successful companies in the world. Download one of our case studies to learn how.',
    'format' => 'plain_text',
    'substitute' => 1,
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 2;
  $pane->locks = array();
  $pane->uuid = 'c1cb6d5c-53b0-44ac-a160-26f136f4ec71';
  $display->content['new-c1cb6d5c-53b0-44ac-a160-26f136f4ec71'] = $pane;
  $display->panels['content_main'][2] = 'new-c1cb6d5c-53b0-44ac-a160-26f136f4ec71';
  $pane = new stdClass();
  $pane->pid = 'new-d78d4b48-f8c5-4b1c-beb8-776bb0aa4a67';
  $pane->panel = 'content_main';
  $pane->type = 'custom';
  $pane->subtype = 'custom';
  $pane->shown = TRUE;
  $pane->access = array(
    'plugins' => array(
      0 => array(
        'name' => 'path_visibility',
        'settings' => array(
          'visibility_setting' => '1',
          'paths' => 'html/rl_product_tours.shtml',
        ),
        'context' => 'empty',
        'not' => FALSE,
      ),
    ),
  );
  $pane->configuration = array(
    'admin_title' => 'Product Tour Custom Header',
    'title' => '',
    'body' => '<p><span style="color:rgb(0, 0, 0); font-family:arial; font-size:14.6666669845581px">Take a tour and find out how Amber Road\'s On-Demand software drives effective global trade management.</span></p>
',
    'format' => 'full_html',
    'substitute' => 1,
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 3;
  $pane->locks = array();
  $pane->uuid = 'd78d4b48-f8c5-4b1c-beb8-776bb0aa4a67';
  $display->content['new-d78d4b48-f8c5-4b1c-beb8-776bb0aa4a67'] = $pane;
  $display->panels['content_main'][3] = 'new-d78d4b48-f8c5-4b1c-beb8-776bb0aa4a67';
  $pane = new stdClass();
  $pane->pid = 'new-8ac7d72b-d0a4-48b4-b938-7f4a6a5abebd';
  $pane->panel = 'content_main';
  $pane->type = 'views_panes';
  $pane->subtype = 'resources-panel_pane_1';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'override_title' => 1,
    'override_title_text' => '',
    'override_title_heading' => 'h2',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array(
    'css_id' => '',
    'css_class' => 'pane-view-teaser-listing',
  );
  $pane->extras = array();
  $pane->position = 4;
  $pane->locks = array();
  $pane->uuid = '8ac7d72b-d0a4-48b4-b938-7f4a6a5abebd';
  $display->content['new-8ac7d72b-d0a4-48b4-b938-7f4a6a5abebd'] = $pane;
  $display->panels['content_main'][4] = 'new-8ac7d72b-d0a4-48b4-b938-7f4a6a5abebd';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = 'new-91e14767-6475-47ea-a301-c15168ed64c9';
  $handler->conf['display'] = $display;
  $export['term_view__resources'] = $handler;

  return $export;
}

/**
 * Implements hook_default_page_manager_pages().
 */
function amberroad_pages_default_page_manager_pages() {
  $page = new stdClass();
  $page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'archived_webinars';
  $page->task = 'page';
  $page->admin_title = 'Archived Webinars';
  $page->admin_description = '';
  $page->path = 'html/rl_webinars.shtml';
  $page->access = array(
    'type' => 'none',
    'settings' => NULL,
  );
  $page->menu = array();
  $page->arguments = array();
  $page->conf = array(
    'admin_paths' => FALSE,
  );
  $page->default_handlers = array();
  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'page_archived_webinars__panel_context_6eeb99de-fd64-4ca9-9046-f4aa64fd31e7';
  $handler->task = 'page';
  $handler->subtask = 'archived_webinars';
  $handler->handler = 'panel_context';
  $handler->weight = 0;
  $handler->conf = array(
    'title' => 'Archived Webinars',
    'no_blocks' => 0,
    'pipeline' => 'ipe',
    'body_classes_to_remove' => '',
    'body_classes_to_add' => '',
    'css_id' => '',
    'css' => '',
    'contexts' => array(),
    'relationships' => array(),
  );
  $display = new panels_display();
  $display->layout = 'amberroad_custom_onecol_theme';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'content_banner' => NULL,
      'content_main' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = '';
  $display->uuid = '0393b2f0-e88e-48f2-a84a-e4748be39ad4';
  $display->content = array();
  $display->panels = array();
  $pane = new stdClass();
  $pane->pid = 'new-beedb69d-d66b-4794-b48d-4a752ad13157';
  $pane->panel = 'content_banner';
  $pane->type = 'block';
  $pane->subtype = 'amberroad_blocks-resource_banner';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'override_title' => 0,
    'override_title_text' => '',
    'override_title_heading' => 'h2',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 0;
  $pane->locks = array();
  $pane->uuid = 'beedb69d-d66b-4794-b48d-4a752ad13157';
  $display->content['new-beedb69d-d66b-4794-b48d-4a752ad13157'] = $pane;
  $display->panels['content_banner'][0] = 'new-beedb69d-d66b-4794-b48d-4a752ad13157';
  $pane = new stdClass();
  $pane->pid = 'new-b71ade6d-0584-46b6-bceb-2c251bd7fd65';
  $pane->panel = 'content_main';
  $pane->type = 'page_title';
  $pane->subtype = 'page_title';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'markup' => 'h1',
    'class' => '',
    'id' => '',
    'override_title' => 0,
    'override_title_text' => '',
    'override_title_heading' => 'h2',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 0;
  $pane->locks = array();
  $pane->uuid = 'b71ade6d-0584-46b6-bceb-2c251bd7fd65';
  $display->content['new-b71ade6d-0584-46b6-bceb-2c251bd7fd65'] = $pane;
  $display->panels['content_main'][0] = 'new-b71ade6d-0584-46b6-bceb-2c251bd7fd65';
  $pane = new stdClass();
  $pane->pid = 'new-b6890328-109e-449e-b8e6-453ebebf6810';
  $pane->panel = 'content_main';
  $pane->type = 'page_breadcrumb';
  $pane->subtype = 'page_breadcrumb';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array();
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 1;
  $pane->locks = array();
  $pane->uuid = 'b6890328-109e-449e-b8e6-453ebebf6810';
  $display->content['new-b6890328-109e-449e-b8e6-453ebebf6810'] = $pane;
  $display->panels['content_main'][1] = 'new-b6890328-109e-449e-b8e6-453ebebf6810';
  $pane = new stdClass();
  $pane->pid = 'new-32cf93ae-1e23-4ead-b6ea-a5288b6141df';
  $pane->panel = 'content_main';
  $pane->type = 'views_panes';
  $pane->subtype = 'events-panel_pane_1';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'override_title' => 1,
    'override_title_text' => '',
    'override_title_heading' => 'h2',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array(
    'css_id' => '',
    'css_class' => 'pane-view-teaser-listing',
  );
  $pane->extras = array();
  $pane->position = 2;
  $pane->locks = array();
  $pane->uuid = '32cf93ae-1e23-4ead-b6ea-a5288b6141df';
  $display->content['new-32cf93ae-1e23-4ead-b6ea-a5288b6141df'] = $pane;
  $display->panels['content_main'][2] = 'new-32cf93ae-1e23-4ead-b6ea-a5288b6141df';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['archived_webinars'] = $page;

  $page = new stdClass();
  $page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'awards';
  $page->task = 'page';
  $page->admin_title = 'Awards';
  $page->admin_description = 'Press Release landing page.';
  $page->path = 'html/awards.shtml';
  $page->access = array(
    'type' => 'none',
    'settings' => NULL,
  );
  $page->menu = array();
  $page->arguments = array();
  $page->conf = array(
    'admin_paths' => FALSE,
  );
  $page->default_handlers = array();
  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'page_awards__panel_context_ef2808d1-9eb9-4366-b4a9-f97e244ff123';
  $handler->task = 'page';
  $handler->subtask = 'awards';
  $handler->handler = 'panel_context';
  $handler->weight = 0;
  $handler->conf = array(
    'title' => 'Panel',
    'no_blocks' => 0,
    'pipeline' => 'ipe',
    'body_classes_to_remove' => '',
    'body_classes_to_add' => '',
    'css_id' => '',
    'css' => '',
    'contexts' => array(),
    'relationships' => array(),
    'metatag_panels' => array(
      'enabled' => 1,
      'metatags' => array(
        'title' => array(
          'value' => 'Global Trade Management Software | Company - Amber Road',
        ),
        'description' => array(
          'value' => 'Over the several years Amber Road was recognized for it excellence is global trade management, import export compliance management, supply chain visibility management and global transportation management, by a number of industry awards including: 100 Great Supply Chain Partners, Supply & Demand Chain Executives 100, Top 100 Logistics IT Providers, Pros to Know, Consumer Goods Technology Reader\'s Choice and 100 Great Supply Chain Partners.',
        ),
      ),
    ),
  );
  $display = new panels_display();
  $display->layout = 'amberroad_custom_onecol_theme';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'content_banner' => NULL,
      'content_main' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = 'Awards';
  $display->uuid = '4d749deb-6c7b-4b03-ac4f-d09a62a18b6a';
  $display->content = array();
  $display->panels = array();
  $pane = new stdClass();
  $pane->pid = 'new-9329f644-0f46-45b6-8090-c122d4970bd2';
  $pane->panel = 'content_banner';
  $pane->type = 'fieldable_panels_pane';
  $pane->subtype = 'uuid:6eb276fb-2d6b-477b-962b-afffd2e6b350';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'view_mode' => 'header',
    'fieldable_panels_pane' => (object) array(
      'bundle' => 'box',
      'language' => '',
      'is_new' => TRUE,
      'title' => 'Multiple Award Winner',
      'link' => 0,
      'path' => '',
      'reusable' => 0,
      'admin_title' => '',
      'admin_description' => '',
      'category' => 'Reusable Content',
      'vid' => '2623',
      'current_vid' => '',
      'revision' => 1,
      'fpid' => '624',
      'field_basic_image_image' => array(
        'und' => array(
          0 => array(
            'fid' => '2951',
            'display' => '1',
            'description' => '',
            'attach_button' => 'Attach',
            'upload' => '',
            'remove_button' => 'Remove',
            'width' => 2500,
            'height' => 150,
          ),
        ),
      ),
      'field_button' => array(
        'und' => array(),
      ),
      'field_text' => array(
        'und' => array(),
      ),
      'field_video' => array(
        'und' => array(),
      ),
      'field_video_width' => array(
        'und' => array(),
      ),
      'log' => '',
      'created' => 1467294082,
      'timestamp' => 1467294082,
      'changed' => 1467294082,
      'uuid' => '6eb276fb-2d6b-477b-962b-afffd2e6b350',
      'vuuid' => '543ae8cd-c7ab-431f-a372-7947247c23ee',
      'uid' => '43',
    ),
  );
  $pane->cache = array();
  $pane->style = array();
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 0;
  $pane->locks = array();
  $pane->uuid = '9329f644-0f46-45b6-8090-c122d4970bd2';
  $display->content['new-9329f644-0f46-45b6-8090-c122d4970bd2'] = $pane;
  $display->panels['content_banner'][0] = 'new-9329f644-0f46-45b6-8090-c122d4970bd2';
  $pane = new stdClass();
  $pane->pid = 'new-39a1a312-1508-44ab-ac2a-4ec218fd3776';
  $pane->panel = 'content_main';
  $pane->type = 'page_title';
  $pane->subtype = 'page_title';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'markup' => 'h1',
    'class' => '',
    'id' => '',
    'override_title' => 0,
    'override_title_text' => '',
    'override_title_heading' => 'h2',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 0;
  $pane->locks = array();
  $pane->uuid = '39a1a312-1508-44ab-ac2a-4ec218fd3776';
  $display->content['new-39a1a312-1508-44ab-ac2a-4ec218fd3776'] = $pane;
  $display->panels['content_main'][0] = 'new-39a1a312-1508-44ab-ac2a-4ec218fd3776';
  $pane = new stdClass();
  $pane->pid = 'new-6b125d7c-2a51-4cea-b244-03ed894e4b02';
  $pane->panel = 'content_main';
  $pane->type = 'page_breadcrumb';
  $pane->subtype = 'page_breadcrumb';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array();
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 1;
  $pane->locks = array();
  $pane->uuid = '6b125d7c-2a51-4cea-b244-03ed894e4b02';
  $display->content['new-6b125d7c-2a51-4cea-b244-03ed894e4b02'] = $pane;
  $display->panels['content_main'][1] = 'new-6b125d7c-2a51-4cea-b244-03ed894e4b02';
  $pane = new stdClass();
  $pane->pid = 'new-660e44c0-08dd-4d93-b8cb-e524d30e396a';
  $pane->panel = 'content_main';
  $pane->type = 'views_panes';
  $pane->subtype = 'awards-panel_pane_1';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array();
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 2;
  $pane->locks = array();
  $pane->uuid = '660e44c0-08dd-4d93-b8cb-e524d30e396a';
  $display->content['new-660e44c0-08dd-4d93-b8cb-e524d30e396a'] = $pane;
  $display->panels['content_main'][2] = 'new-660e44c0-08dd-4d93-b8cb-e524d30e396a';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = 'new-39a1a312-1508-44ab-ac2a-4ec218fd3776';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['awards'] = $page;

  $page = new stdClass();
  $page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'home_page';
  $page->task = 'page';
  $page->admin_title = 'Home Page';
  $page->admin_description = '';
  $page->path = 'home';
  $page->access = array(
    'type' => 'none',
    'settings' => NULL,
  );
  $page->menu = array();
  $page->arguments = array();
  $page->conf = array(
    'admin_paths' => FALSE,
  );
  $page->default_handlers = array();
  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'page_home_page__panel_context_4ad7fbc7-8d7a-4ed5-b623-317da86f4b99';
  $handler->task = 'page';
  $handler->subtask = 'home_page';
  $handler->handler = 'panel_context';
  $handler->weight = 0;
  $handler->conf = array(
    'title' => 'Panel',
    'no_blocks' => 0,
    'pipeline' => 'standard',
    'body_classes_to_remove' => '',
    'body_classes_to_add' => '',
    'css_id' => '',
    'css' => '',
    'contexts' => array(),
    'relationships' => array(),
  );
  $display = new panels_display();
  $display->layout = 'amberroad_custom_onecol_theme';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'content_banner' => NULL,
      'content_main' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = '';
  $display->uuid = '05402df7-79b2-43f7-96b0-f14ee28055d2';
  $display->content = array();
  $display->panels = array();
  $pane = new stdClass();
  $pane->pid = 'new-4e675dd1-8833-4df8-8218-1bef2d96a6e0';
  $pane->panel = 'content_banner';
  $pane->type = 'block';
  $pane->subtype = 'views-slideshow-block';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'override_title' => 0,
    'override_title_text' => '',
    'override_title_heading' => 'h2',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 0;
  $pane->locks = array();
  $pane->uuid = '4e675dd1-8833-4df8-8218-1bef2d96a6e0';
  $display->content['new-4e675dd1-8833-4df8-8218-1bef2d96a6e0'] = $pane;
  $display->panels['content_banner'][0] = 'new-4e675dd1-8833-4df8-8218-1bef2d96a6e0';
  $pane = new stdClass();
  $pane->pid = 'new-bfe4d5a9-a5c3-4d94-ba32-81e908451646';
  $pane->panel = 'content_main';
  $pane->type = 'block';
  $pane->subtype = 'amberroad_blocks-homepage_promo_text';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'override_title' => 0,
    'override_title_text' => '',
    'override_title_heading' => 'h2',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 0;
  $pane->locks = array();
  $pane->uuid = 'bfe4d5a9-a5c3-4d94-ba32-81e908451646';
  $display->content['new-bfe4d5a9-a5c3-4d94-ba32-81e908451646'] = $pane;
  $display->panels['content_main'][0] = 'new-bfe4d5a9-a5c3-4d94-ba32-81e908451646';
  $pane = new stdClass();
  $pane->pid = 'new-1e504b6f-f906-4ce1-a52f-9967ab62491e';
  $pane->panel = 'content_main';
  $pane->type = 'views';
  $pane->subtype = 'client_banner';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'override_pager_settings' => 0,
    'use_pager' => 0,
    'nodes_per_page' => '0',
    'pager_id' => '0',
    'offset' => '0',
    'more_link' => 0,
    'feed_icons' => 0,
    'panel_args' => 0,
    'link_to_view' => 0,
    'args' => '',
    'url' => '',
    'display' => 'block',
    'override_title' => 1,
    'override_title_text' => '',
    'override_title_heading' => 'h2',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 1;
  $pane->locks = array();
  $pane->uuid = '1e504b6f-f906-4ce1-a52f-9967ab62491e';
  $display->content['new-1e504b6f-f906-4ce1-a52f-9967ab62491e'] = $pane;
  $display->panels['content_main'][1] = 'new-1e504b6f-f906-4ce1-a52f-9967ab62491e';
  $pane = new stdClass();
  $pane->pid = 'new-8dea08b3-7d38-4b64-8401-57c9eb8541fb';
  $pane->panel = 'content_main';
  $pane->type = 'views';
  $pane->subtype = 'homepage_featured_block';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'override_pager_settings' => 0,
    'use_pager' => 0,
    'nodes_per_page' => '1',
    'pager_id' => '0',
    'offset' => '0',
    'more_link' => 0,
    'feed_icons' => 0,
    'panel_args' => 0,
    'link_to_view' => 0,
    'args' => '',
    'url' => '',
    'display' => 'block',
    'override_title' => 1,
    'override_title_text' => 'Featured',
    'override_title_heading' => 'h2',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 2;
  $pane->locks = array();
  $pane->uuid = '8dea08b3-7d38-4b64-8401-57c9eb8541fb';
  $display->content['new-8dea08b3-7d38-4b64-8401-57c9eb8541fb'] = $pane;
  $display->panels['content_main'][2] = 'new-8dea08b3-7d38-4b64-8401-57c9eb8541fb';
  $pane = new stdClass();
  $pane->pid = 'new-415c0184-e7ab-4260-ab26-e3a64c334d91';
  $pane->panel = 'content_main';
  $pane->type = 'views';
  $pane->subtype = 'homepage_blocks';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'override_pager_settings' => 0,
    'use_pager' => 0,
    'nodes_per_page' => '1',
    'pager_id' => '0',
    'offset' => '0',
    'more_link' => 0,
    'feed_icons' => 0,
    'panel_args' => 0,
    'link_to_view' => 0,
    'args' => '',
    'url' => '',
    'display' => 'webinar_block',
    'override_title' => 1,
    'override_title_text' => 'New Webinar',
    'override_title_heading' => 'h2',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array(
    'css_id' => '',
    'css_class' => 'pane-homepage-webinar',
  );
  $pane->extras = array();
  $pane->position = 3;
  $pane->locks = array();
  $pane->uuid = '415c0184-e7ab-4260-ab26-e3a64c334d91';
  $display->content['new-415c0184-e7ab-4260-ab26-e3a64c334d91'] = $pane;
  $display->panels['content_main'][3] = 'new-415c0184-e7ab-4260-ab26-e3a64c334d91';
  $pane = new stdClass();
  $pane->pid = 'new-2ad56737-9984-46b3-9d26-38d91eb2b3ff';
  $pane->panel = 'content_main';
  $pane->type = 'views';
  $pane->subtype = 'homepage_blocks';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'override_pager_settings' => 0,
    'use_pager' => 0,
    'nodes_per_page' => '1',
    'pager_id' => '0',
    'offset' => '',
    'more_link' => 1,
    'feed_icons' => 0,
    'panel_args' => 0,
    'link_to_view' => 0,
    'args' => '',
    'url' => '',
    'display' => 'event_block',
    'override_title' => 1,
    'override_title_text' => 'Upcoming Events',
    'override_title_heading' => 'h2',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array(
    'css_id' => '',
    'css_class' => 'pane-homepage-event',
  );
  $pane->extras = array();
  $pane->position = 4;
  $pane->locks = array();
  $pane->uuid = '2ad56737-9984-46b3-9d26-38d91eb2b3ff';
  $display->content['new-2ad56737-9984-46b3-9d26-38d91eb2b3ff'] = $pane;
  $display->panels['content_main'][4] = 'new-2ad56737-9984-46b3-9d26-38d91eb2b3ff';
  $pane = new stdClass();
  $pane->pid = 'new-cbadf15a-1c0b-4ba3-975c-8d75701bdc8e';
  $pane->panel = 'content_main';
  $pane->type = 'views_panes';
  $pane->subtype = 'press_release-panel_pane_3';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array();
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array(
    'css_id' => '',
    'css_class' => 'pane-news-ticker-desktop-view',
  );
  $pane->extras = array();
  $pane->position = 5;
  $pane->locks = array();
  $pane->uuid = 'cbadf15a-1c0b-4ba3-975c-8d75701bdc8e';
  $display->content['new-cbadf15a-1c0b-4ba3-975c-8d75701bdc8e'] = $pane;
  $display->panels['content_main'][5] = 'new-cbadf15a-1c0b-4ba3-975c-8d75701bdc8e';
  $pane = new stdClass();
  $pane->pid = 'new-7325b91c-0fd9-4543-ac9c-2536ec8aebde';
  $pane->panel = 'content_main';
  $pane->type = 'views_panes';
  $pane->subtype = 'press_release-panel_pane_4';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array();
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array(
    'css_id' => '',
    'css_class' => 'pane-news-ticker-mobile-view',
  );
  $pane->extras = array();
  $pane->position = 6;
  $pane->locks = array();
  $pane->uuid = '7325b91c-0fd9-4543-ac9c-2536ec8aebde';
  $display->content['new-7325b91c-0fd9-4543-ac9c-2536ec8aebde'] = $pane;
  $display->panels['content_main'][6] = 'new-7325b91c-0fd9-4543-ac9c-2536ec8aebde';
  $display->hide_title = PANELS_TITLE_NONE;
  $display->title_pane = 'new-4e675dd1-8833-4df8-8218-1bef2d96a6e0';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['home_page'] = $page;

  $page = new stdClass();
  $page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'industry_events';
  $page->task = 'page';
  $page->admin_title = 'Industry Events';
  $page->admin_description = '';
  $page->path = 'html/industry_events.shtml';
  $page->access = array(
    'type' => 'none',
    'settings' => NULL,
  );
  $page->menu = array();
  $page->arguments = array();
  $page->conf = array(
    'admin_paths' => FALSE,
  );
  $page->default_handlers = array();
  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'page_industry_events__panel_context_d1952e55-4005-4b75-9387-bc8097c5b950';
  $handler->task = 'page';
  $handler->subtask = 'industry_events';
  $handler->handler = 'panel_context';
  $handler->weight = 0;
  $handler->conf = array(
    'title' => 'Industry Events',
    'no_blocks' => 0,
    'pipeline' => 'standard',
    'body_classes_to_remove' => '',
    'body_classes_to_add' => '',
    'css_id' => '',
    'css' => '',
    'contexts' => array(),
    'relationships' => array(),
    'metatag_panels' => array(
      'enabled' => 1,
      'metatags' => array(
        'title' => array(
          'value' => 'Global Trade Management Software | Company - Amber Road',
        ),
        'description' => array(
          'value' => 'Amber Road\'s Trade Compliance solution automates and streamlines your import, export and trade agreement operations. Establishing an end-to-end global transaction, three integrated modules ensure global regulatory compliance, prevent border delays, fines and penalties, and enable legal, cost-effective international trade.',
        ),
      ),
    ),
  );
  $display = new panels_display();
  $display->layout = 'amberroad_custom_onecol_theme';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'content_banner' => NULL,
      'content_main' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = '';
  $display->uuid = '0393b2f0-e88e-48f2-a84a-e4748be39ad4';
  $display->content = array();
  $display->panels = array();
  $pane = new stdClass();
  $pane->pid = 'new-dfcb02eb-c725-46d5-a779-5cd2883602fe';
  $pane->panel = 'content_banner';
  $pane->type = 'fieldable_panels_pane';
  $pane->subtype = 'uuid:72440642-fd4c-4591-a749-6379c22dbcd3';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'view_mode' => 'header',
    'fieldable_panels_pane' => (object) array(
      'bundle' => 'box',
      'language' => '',
      'is_new' => TRUE,
      'title' => 'Advancing the Industry',
      'link' => 0,
      'path' => '',
      'reusable' => 0,
      'admin_title' => '',
      'admin_description' => '',
      'category' => 'Reusable Content',
      'vid' => '2613',
      'current_vid' => '',
      'revision' => 1,
      'fpid' => '615',
      'field_basic_image_image' => array(
        'und' => array(
          0 => array(
            'fid' => '2942',
            'display' => '1',
            'description' => '',
            'attach_button' => 'Attach',
            'upload' => '',
            'remove_button' => 'Remove',
            'width' => 2500,
            'height' => 150,
          ),
        ),
      ),
      'field_button' => array(
        'und' => array(),
      ),
      'field_text' => array(
        'und' => array(),
      ),
      'field_video' => array(
        'und' => array(),
      ),
      'field_video_width' => array(
        'und' => array(),
      ),
      'log' => '',
      'created' => 1467293101,
      'timestamp' => 1467293101,
      'changed' => 1467293101,
      'uuid' => '72440642-fd4c-4591-a749-6379c22dbcd3',
      'vuuid' => '73d02cab-3fa5-49f9-a39d-644955484409',
      'uid' => '43',
    ),
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 0;
  $pane->locks = array();
  $pane->uuid = 'dfcb02eb-c725-46d5-a779-5cd2883602fe';
  $display->content['new-dfcb02eb-c725-46d5-a779-5cd2883602fe'] = $pane;
  $display->panels['content_banner'][0] = 'new-dfcb02eb-c725-46d5-a779-5cd2883602fe';
  $pane = new stdClass();
  $pane->pid = 'new-1aef1f3e-aba2-490c-90a3-2f4c1cc3672a';
  $pane->panel = 'content_main';
  $pane->type = 'page_title';
  $pane->subtype = 'page_title';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'markup' => 'h1',
    'class' => '',
    'id' => '',
    'override_title' => 0,
    'override_title_text' => '',
    'override_title_heading' => 'h2',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 0;
  $pane->locks = array();
  $pane->uuid = '1aef1f3e-aba2-490c-90a3-2f4c1cc3672a';
  $display->content['new-1aef1f3e-aba2-490c-90a3-2f4c1cc3672a'] = $pane;
  $display->panels['content_main'][0] = 'new-1aef1f3e-aba2-490c-90a3-2f4c1cc3672a';
  $pane = new stdClass();
  $pane->pid = 'new-b6890328-109e-449e-b8e6-453ebebf6810';
  $pane->panel = 'content_main';
  $pane->type = 'page_breadcrumb';
  $pane->subtype = 'page_breadcrumb';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array();
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 1;
  $pane->locks = array();
  $pane->uuid = 'b6890328-109e-449e-b8e6-453ebebf6810';
  $display->content['new-b6890328-109e-449e-b8e6-453ebebf6810'] = $pane;
  $display->panels['content_main'][1] = 'new-b6890328-109e-449e-b8e6-453ebebf6810';
  $pane = new stdClass();
  $pane->pid = 'new-6d8d4073-034a-4aac-83ad-09b528fe2a0e';
  $pane->panel = 'content_main';
  $pane->type = 'views_panes';
  $pane->subtype = 'events-panel_industry_conference';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'override_title' => 1,
    'override_title_text' => '',
    'override_title_heading' => 'h2',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 2;
  $pane->locks = array();
  $pane->uuid = '6d8d4073-034a-4aac-83ad-09b528fe2a0e';
  $display->content['new-6d8d4073-034a-4aac-83ad-09b528fe2a0e'] = $pane;
  $display->panels['content_main'][2] = 'new-6d8d4073-034a-4aac-83ad-09b528fe2a0e';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['industry_events'] = $page;

  $page = new stdClass();
  $page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'podcasts';
  $page->task = 'page';
  $page->admin_title = 'Podcasts';
  $page->admin_description = '';
  $page->path = 'html/rl_podcasts.shtml';
  $page->access = array(
    'type' => 'none',
    'settings' => NULL,
  );
  $page->menu = array();
  $page->arguments = array();
  $page->conf = array(
    'admin_paths' => FALSE,
  );
  $page->default_handlers = array();
  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'page_podcasts__panel_context_015c210d-0583-4119-99c1-7e0c275698dc';
  $handler->task = 'page';
  $handler->subtask = 'podcasts';
  $handler->handler = 'panel_context';
  $handler->weight = 0;
  $handler->conf = array(
    'title' => 'Panel',
    'no_blocks' => 0,
    'pipeline' => 'standard',
    'body_classes_to_remove' => '',
    'body_classes_to_add' => '',
    'css_id' => '',
    'css' => '',
    'contexts' => array(),
    'relationships' => array(),
  );
  $display = new panels_display();
  $display->layout = 'amberroad_custom_onecol_theme';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'content_banner' => NULL,
      'content_main' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = '';
  $display->uuid = '33840e16-5a2e-4ec1-90f1-7f1f12fdfcf8';
  $display->content = array();
  $display->panels = array();
  $pane = new stdClass();
  $pane->pid = 'new-f54596cc-9dd8-42f4-82e6-a53126c111d6';
  $pane->panel = 'content_banner';
  $pane->type = 'block';
  $pane->subtype = 'amberroad_blocks-resource_banner';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'override_title' => 0,
    'override_title_text' => '',
    'override_title_heading' => 'h2',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 0;
  $pane->locks = array();
  $pane->uuid = 'f54596cc-9dd8-42f4-82e6-a53126c111d6';
  $display->content['new-f54596cc-9dd8-42f4-82e6-a53126c111d6'] = $pane;
  $display->panels['content_banner'][0] = 'new-f54596cc-9dd8-42f4-82e6-a53126c111d6';
  $pane = new stdClass();
  $pane->pid = 'new-43858f8e-2e0e-4fc2-9690-3b3e0c145f35';
  $pane->panel = 'content_main';
  $pane->type = 'page_title';
  $pane->subtype = 'page_title';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'markup' => 'h1',
    'class' => '',
    'id' => '',
    'override_title' => 0,
    'override_title_text' => '',
    'override_title_heading' => 'h2',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 0;
  $pane->locks = array();
  $pane->uuid = '43858f8e-2e0e-4fc2-9690-3b3e0c145f35';
  $display->content['new-43858f8e-2e0e-4fc2-9690-3b3e0c145f35'] = $pane;
  $display->panels['content_main'][0] = 'new-43858f8e-2e0e-4fc2-9690-3b3e0c145f35';
  $pane = new stdClass();
  $pane->pid = 'new-e915d582-3a10-49c0-a2f3-c73d9e29a941';
  $pane->panel = 'content_main';
  $pane->type = 'page_breadcrumb';
  $pane->subtype = 'page_breadcrumb';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array();
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 1;
  $pane->locks = array();
  $pane->uuid = 'e915d582-3a10-49c0-a2f3-c73d9e29a941';
  $display->content['new-e915d582-3a10-49c0-a2f3-c73d9e29a941'] = $pane;
  $display->panels['content_main'][1] = 'new-e915d582-3a10-49c0-a2f3-c73d9e29a941';
  $pane = new stdClass();
  $pane->pid = 'new-0f3bab1c-ceeb-460e-bbdb-153c1701e405';
  $pane->panel = 'content_main';
  $pane->type = 'views_panes';
  $pane->subtype = 'podcasts-panel_pane_1';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'override_title' => 1,
    'override_title_text' => '',
    'override_title_heading' => 'h2',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 2;
  $pane->locks = array();
  $pane->uuid = '0f3bab1c-ceeb-460e-bbdb-153c1701e405';
  $display->content['new-0f3bab1c-ceeb-460e-bbdb-153c1701e405'] = $pane;
  $display->panels['content_main'][2] = 'new-0f3bab1c-ceeb-460e-bbdb-153c1701e405';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = 'new-0f3bab1c-ceeb-460e-bbdb-153c1701e405';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['podcasts'] = $page;

  $page = new stdClass();
  $page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'press_coverage';
  $page->task = 'page';
  $page->admin_title = 'Press Coverage';
  $page->admin_description = 'Press Release landing page.';
  $page->path = 'html/press_coverage.shtml';
  $page->access = array(
    'type' => 'none',
    'settings' => NULL,
  );
  $page->menu = array();
  $page->arguments = array();
  $page->conf = array(
    'admin_paths' => FALSE,
  );
  $page->default_handlers = array();
  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'page_press_coverage__panel_context_6cc360b8-8b9b-45c3-8414-cd0fde34354c';
  $handler->task = 'page';
  $handler->subtask = 'press_coverage';
  $handler->handler = 'panel_context';
  $handler->weight = 0;
  $handler->conf = array(
    'title' => 'Panel',
    'no_blocks' => 0,
    'pipeline' => 'ipe',
    'body_classes_to_remove' => '',
    'body_classes_to_add' => '',
    'css_id' => '',
    'css' => '',
    'contexts' => array(),
    'relationships' => array(),
    'metatag_panels' => array(
      'enabled' => 1,
      'metatags' => array(
        'title' => array(
          'value' => 'Global Trade Management Software | Company - Amber Road',
        ),
        'description' => array(
          'value' => 'Read Amber Road\'s latest news feature from leading publication including: American Shipper, Supply Chain Digest, Journal of Commerce, DC Velocity, Inbound Logistics, Manufacturing Business Today, Supply & Demand Chain Executive, Compliance & Ethics Professional, Information Week, covering issues on export management, import management, restricted party screening, free trade agreement management, global trade management, import compliance, export compliance, import management, supply chain visibility and transportation management.',
        ),
      ),
    ),
  );
  $display = new panels_display();
  $display->layout = 'amberroad_custom_onerowtwocols_theme';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'content_banner' => NULL,
      'content_main' => NULL,
      'content_sidebar' => NULL,
      'content_top' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = 'Press Coverage';
  $display->uuid = '4d749deb-6c7b-4b03-ac4f-d09a62a18b6a';
  $display->content = array();
  $display->panels = array();
  $pane = new stdClass();
  $pane->pid = 'new-b0b6530f-7136-4a7f-b1ee-4253d0bd785f';
  $pane->panel = 'content_banner';
  $pane->type = 'fieldable_panels_pane';
  $pane->subtype = 'uuid:31ae8f68-bf31-4ead-b251-39002b850321';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'view_mode' => 'header',
    'fieldable_panels_pane' => (object) array(
      'bundle' => 'box',
      'language' => '',
      'is_new' => TRUE,
      'title' => 'Making the Headlines',
      'link' => 0,
      'path' => '',
      'reusable' => 0,
      'admin_title' => '',
      'admin_description' => '',
      'category' => 'Reusable Content',
      'vid' => '2624',
      'current_vid' => '',
      'revision' => 1,
      'fpid' => '625',
      'field_basic_image_image' => array(
        'und' => array(
          0 => array(
            'fid' => '2952',
            'display' => '1',
            'description' => '',
            'attach_button' => 'Attach',
            'upload' => '',
            'remove_button' => 'Remove',
            'width' => 2500,
            'height' => 150,
          ),
        ),
      ),
      'field_button' => array(
        'und' => array(),
      ),
      'field_text' => array(
        'und' => array(),
      ),
      'field_video' => array(
        'und' => array(),
      ),
      'field_video_width' => array(
        'und' => array(),
      ),
      'log' => '',
      'created' => 1467294144,
      'timestamp' => 1467294144,
      'changed' => 1467294144,
      'uuid' => '31ae8f68-bf31-4ead-b251-39002b850321',
      'vuuid' => '5cb3b7e1-1431-4ae2-9f24-03d158ee0684',
      'uid' => '43',
    ),
  );
  $pane->cache = array();
  $pane->style = array();
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 0;
  $pane->locks = array();
  $pane->uuid = 'b0b6530f-7136-4a7f-b1ee-4253d0bd785f';
  $display->content['new-b0b6530f-7136-4a7f-b1ee-4253d0bd785f'] = $pane;
  $display->panels['content_banner'][0] = 'new-b0b6530f-7136-4a7f-b1ee-4253d0bd785f';
  $pane = new stdClass();
  $pane->pid = 'new-39a1a312-1508-44ab-ac2a-4ec218fd3776';
  $pane->panel = 'content_main';
  $pane->type = 'page_title';
  $pane->subtype = 'page_title';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'markup' => 'h1',
    'class' => '',
    'id' => '',
    'override_title' => 0,
    'override_title_text' => '',
    'override_title_heading' => 'h2',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 0;
  $pane->locks = array();
  $pane->uuid = '39a1a312-1508-44ab-ac2a-4ec218fd3776';
  $display->content['new-39a1a312-1508-44ab-ac2a-4ec218fd3776'] = $pane;
  $display->panels['content_main'][0] = 'new-39a1a312-1508-44ab-ac2a-4ec218fd3776';
  $pane = new stdClass();
  $pane->pid = 'new-6b125d7c-2a51-4cea-b244-03ed894e4b02';
  $pane->panel = 'content_main';
  $pane->type = 'page_breadcrumb';
  $pane->subtype = 'page_breadcrumb';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array();
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 1;
  $pane->locks = array();
  $pane->uuid = '6b125d7c-2a51-4cea-b244-03ed894e4b02';
  $display->content['new-6b125d7c-2a51-4cea-b244-03ed894e4b02'] = $pane;
  $display->panels['content_main'][1] = 'new-6b125d7c-2a51-4cea-b244-03ed894e4b02';
  $pane = new stdClass();
  $pane->pid = 'new-cdc8b3e0-edac-442e-be72-520d8f4ceb49';
  $pane->panel = 'content_main';
  $pane->type = 'views_panes';
  $pane->subtype = 'press_coverage-panel_pane_1';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array();
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array(
    'css_id' => '',
    'css_class' => 'pane-press-coverage-list',
  );
  $pane->extras = array();
  $pane->position = 2;
  $pane->locks = array();
  $pane->uuid = 'cdc8b3e0-edac-442e-be72-520d8f4ceb49';
  $display->content['new-cdc8b3e0-edac-442e-be72-520d8f4ceb49'] = $pane;
  $display->panels['content_main'][2] = 'new-cdc8b3e0-edac-442e-be72-520d8f4ceb49';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = 'new-39a1a312-1508-44ab-ac2a-4ec218fd3776';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['press_coverage'] = $page;

  $page = new stdClass();
  $page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'press_release';
  $page->task = 'page';
  $page->admin_title = 'Press Releases';
  $page->admin_description = 'Press Releases landing page.';
  $page->path = 'html/press_releases.shtml';
  $page->access = array(
    'type' => 'none',
    'settings' => NULL,
  );
  $page->menu = array();
  $page->arguments = array();
  $page->conf = array(
    'admin_paths' => FALSE,
  );
  $page->default_handlers = array();
  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'page_press_release__panel_context_850a21e9-5727-4f26-aef1-b7607ad2b3cc';
  $handler->task = 'page';
  $handler->subtask = 'press_release';
  $handler->handler = 'panel_context';
  $handler->weight = 0;
  $handler->conf = array(
    'title' => 'Panel',
    'no_blocks' => 0,
    'pipeline' => 'ipe',
    'body_classes_to_remove' => '',
    'body_classes_to_add' => '',
    'css_id' => '',
    'css' => '',
    'contexts' => array(),
    'relationships' => array(),
    'metatag_panels' => array(
      'enabled' => 1,
      'metatags' => array(
        'title' => array(
          'value' => 'Global Trade Management Software | Company - Amber Road',
        ),
        'description' => array(
          'value' => 'Access Amber Road\'s latest press releases to find out what\'s new with our export compliance software, import compliance software, import management, export management, supply chain visibility software, free trade agreement software, global trade compliance software, foreign trade zone software, import software, export software, Transportation management software.',
        ),
      ),
    ),
  );
  $display = new panels_display();
  $display->layout = 'amberroad_custom_onecol_theme';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'content_banner' => NULL,
      'content_main' => NULL,
      'content_sidebar' => NULL,
      'content_top' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = 'Press Releases';
  $display->uuid = '4d749deb-6c7b-4b03-ac4f-d09a62a18b6a';
  $display->content = array();
  $display->panels = array();
  $pane = new stdClass();
  $pane->pid = 'new-da90688b-c9df-4cbd-a0b6-125c1c4a7241';
  $pane->panel = 'content_banner';
  $pane->type = 'fieldable_panels_pane';
  $pane->subtype = 'uuid:e6e6ad17-1e04-44cd-980b-923b908d4319';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'view_mode' => 'header',
    'fieldable_panels_pane' => (object) array(
      'bundle' => 'box',
      'language' => 'und',
      'is_new' => TRUE,
      'title' => 'Making the Headlines',
      'link' => 0,
      'path' => '',
      'reusable' => 0,
      'admin_title' => '',
      'admin_description' => '',
      'category' => 'Reusable Content',
      'vid' => '2625',
      'current_vid' => '',
      'revision' => 1,
      'fpid' => '626',
      'field_basic_image_image' => array(
        'und' => array(
          0 => array(
            'fid' => '2953',
            'display' => '1',
            'description' => '',
            'attach_button' => 'Attach',
            'upload' => '',
            'remove_button' => 'Remove',
            'width' => 2500,
            'height' => 150,
          ),
        ),
      ),
      'field_button' => array(
        'und' => array(),
      ),
      'field_text' => array(
        'und' => array(),
      ),
      'field_video' => array(
        'und' => array(),
      ),
      'field_video_width' => array(
        'und' => array(),
      ),
      'log' => '',
      'created' => 1467294196,
      'timestamp' => 1467294196,
      'changed' => 1467294196,
      'uuid' => 'e6e6ad17-1e04-44cd-980b-923b908d4319',
      'vuuid' => '253a23bb-dbbc-4c2e-9e42-8f633c520f48',
      'uid' => '43',
    ),
  );
  $pane->cache = array();
  $pane->style = array();
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 0;
  $pane->locks = array();
  $pane->uuid = 'da90688b-c9df-4cbd-a0b6-125c1c4a7241';
  $display->content['new-da90688b-c9df-4cbd-a0b6-125c1c4a7241'] = $pane;
  $display->panels['content_banner'][0] = 'new-da90688b-c9df-4cbd-a0b6-125c1c4a7241';
  $pane = new stdClass();
  $pane->pid = 'new-39a1a312-1508-44ab-ac2a-4ec218fd3776';
  $pane->panel = 'content_main';
  $pane->type = 'page_title';
  $pane->subtype = 'page_title';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'markup' => 'h1',
    'class' => '',
    'id' => '',
    'override_title' => 0,
    'override_title_text' => '',
    'override_title_heading' => 'h2',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 0;
  $pane->locks = array();
  $pane->uuid = '39a1a312-1508-44ab-ac2a-4ec218fd3776';
  $display->content['new-39a1a312-1508-44ab-ac2a-4ec218fd3776'] = $pane;
  $display->panels['content_main'][0] = 'new-39a1a312-1508-44ab-ac2a-4ec218fd3776';
  $pane = new stdClass();
  $pane->pid = 'new-6b125d7c-2a51-4cea-b244-03ed894e4b02';
  $pane->panel = 'content_main';
  $pane->type = 'page_breadcrumb';
  $pane->subtype = 'page_breadcrumb';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array();
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 1;
  $pane->locks = array();
  $pane->uuid = '6b125d7c-2a51-4cea-b244-03ed894e4b02';
  $display->content['new-6b125d7c-2a51-4cea-b244-03ed894e4b02'] = $pane;
  $display->panels['content_main'][1] = 'new-6b125d7c-2a51-4cea-b244-03ed894e4b02';
  $pane = new stdClass();
  $pane->pid = 'new-e721d480-3613-4b16-9214-8fc043b1c0c9';
  $pane->panel = 'content_main';
  $pane->type = 'views_panes';
  $pane->subtype = 'press_release-panel_pane_2';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'override_title' => 1,
    'override_title_text' => '',
    'override_title_heading' => 'h1',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 2;
  $pane->locks = array();
  $pane->uuid = 'e721d480-3613-4b16-9214-8fc043b1c0c9';
  $display->content['new-e721d480-3613-4b16-9214-8fc043b1c0c9'] = $pane;
  $display->panels['content_main'][2] = 'new-e721d480-3613-4b16-9214-8fc043b1c0c9';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = 'new-39a1a312-1508-44ab-ac2a-4ec218fd3776';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['press_release'] = $page;

  $page = new stdClass();
  $page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'press_room';
  $page->task = 'page';
  $page->admin_title = 'Press Room';
  $page->admin_description = 'Press Release landing page.';
  $page->path = 'html/press.shtml';
  $page->access = array(
    'type' => 'none',
    'settings' => NULL,
  );
  $page->menu = array();
  $page->arguments = array();
  $page->conf = array(
    'admin_paths' => FALSE,
  );
  $page->default_handlers = array();
  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'page_press_room__panel_context_e1d80401-5cfd-44ef-964e-dd3b378583df';
  $handler->task = 'page';
  $handler->subtask = 'press_room';
  $handler->handler = 'panel_context';
  $handler->weight = 0;
  $handler->conf = array(
    'title' => 'Panel',
    'no_blocks' => 0,
    'pipeline' => 'ipe',
    'body_classes_to_remove' => '',
    'body_classes_to_add' => '',
    'css_id' => '',
    'css' => '',
    'contexts' => array(),
    'relationships' => array(),
    'metatag_panels' => array(
      'enabled' => 1,
      'metatags' => array(
        'title' => array(
          'value' => 'Global Trade Management Software | Company - Amber Road',
        ),
        'description' => array(
          'value' => 'Access Amber Road\'s latest press releases and press coverage to find out what\'s new with our export compliance software, import compliance software, import management, export management, supply chain visibility software, free trade agreement software, global trade compliance software, foreign trade zone software, import software, export software, Transportation management software; find out the key industry recognition that Amber Road attains.',
        ),
      ),
    ),
  );
  $display = new panels_display();
  $display->layout = 'amberroad_custom_onecol_theme';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'content_banner' => NULL,
      'content_main' => NULL,
      'content_sidebar' => NULL,
      'content_top' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = 'Press Room';
  $display->uuid = '4d749deb-6c7b-4b03-ac4f-d09a62a18b6a';
  $display->content = array();
  $display->panels = array();
  $pane = new stdClass();
  $pane->pid = 'new-512edafb-3769-4292-b0a8-07549ff767a5';
  $pane->panel = 'content_banner';
  $pane->type = 'fieldable_panels_pane';
  $pane->subtype = 'uuid:f564305b-9ed9-4a03-922e-094e99806ba7';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'view_mode' => 'header',
    'fieldable_panels_pane' => (object) array(
      'bundle' => 'box',
      'language' => 'und',
      'is_new' => TRUE,
      'title' => 'Making the Headlines',
      'link' => 0,
      'path' => '',
      'reusable' => 0,
      'admin_title' => '',
      'admin_description' => '',
      'category' => 'Reusable Content',
      'vid' => '2622',
      'current_vid' => '',
      'revision' => 1,
      'fpid' => '623',
      'field_basic_image_image' => array(
        'und' => array(
          0 => array(
            'fid' => '2950',
            'display' => '1',
            'description' => '',
            'attach_button' => 'Attach',
            'upload' => '',
            'remove_button' => 'Remove',
            'width' => 2500,
            'height' => 150,
          ),
        ),
      ),
      'field_button' => array(
        'und' => array(),
      ),
      'field_text' => array(
        'und' => array(),
      ),
      'field_video' => array(
        'und' => array(),
      ),
      'field_video_width' => array(
        'und' => array(),
      ),
      'log' => '',
      'created' => 1467294026,
      'timestamp' => 1467294026,
      'changed' => 1467294026,
      'uuid' => 'f564305b-9ed9-4a03-922e-094e99806ba7',
      'vuuid' => 'adda27f8-6d7b-4642-a40d-0b9760257385',
      'uid' => '43',
    ),
  );
  $pane->cache = array();
  $pane->style = array();
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 0;
  $pane->locks = array();
  $pane->uuid = '512edafb-3769-4292-b0a8-07549ff767a5';
  $display->content['new-512edafb-3769-4292-b0a8-07549ff767a5'] = $pane;
  $display->panels['content_banner'][0] = 'new-512edafb-3769-4292-b0a8-07549ff767a5';
  $pane = new stdClass();
  $pane->pid = 'new-39a1a312-1508-44ab-ac2a-4ec218fd3776';
  $pane->panel = 'content_main';
  $pane->type = 'page_title';
  $pane->subtype = 'page_title';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'markup' => 'h1',
    'class' => '',
    'id' => '',
    'override_title' => 0,
    'override_title_text' => '',
    'override_title_heading' => 'h2',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 0;
  $pane->locks = array();
  $pane->uuid = '39a1a312-1508-44ab-ac2a-4ec218fd3776';
  $display->content['new-39a1a312-1508-44ab-ac2a-4ec218fd3776'] = $pane;
  $display->panels['content_main'][0] = 'new-39a1a312-1508-44ab-ac2a-4ec218fd3776';
  $pane = new stdClass();
  $pane->pid = 'new-6b125d7c-2a51-4cea-b244-03ed894e4b02';
  $pane->panel = 'content_main';
  $pane->type = 'page_breadcrumb';
  $pane->subtype = 'page_breadcrumb';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array();
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 1;
  $pane->locks = array();
  $pane->uuid = '6b125d7c-2a51-4cea-b244-03ed894e4b02';
  $display->content['new-6b125d7c-2a51-4cea-b244-03ed894e4b02'] = $pane;
  $display->panels['content_main'][1] = 'new-6b125d7c-2a51-4cea-b244-03ed894e4b02';
  $pane = new stdClass();
  $pane->pid = 'new-f323b2cd-91cd-46b5-a8b4-db09db8325ee';
  $pane->panel = 'content_main';
  $pane->type = 'fieldable_panels_pane';
  $pane->subtype = 'uuid:babb1a19-9577-44f3-93dd-885a9fd72689';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'view_mode' => 'full',
    'fieldable_panels_pane' => (object) array(
      'bundle' => 'box',
      'language' => '',
      'is_new' => TRUE,
      'title' => '',
      'link' => 0,
      'path' => '',
      'reusable' => 0,
      'admin_title' => '',
      'admin_description' => '',
      'category' => 'Reusable Content',
      'vid' => '2790',
      'current_vid' => '',
      'revision' => 1,
      'fpid' => '684',
      'field_basic_image_image' => array(
        'und' => array(),
      ),
      'field_button' => array(
        'und' => array(),
      ),
      'field_text' => array(
        'und' => array(
          0 => array(
            'summary' => '',
            'value' => '<p>Please send all media inquiries to&nbsp;<a href="https://owa.apptixemail.net/owa/redir.aspx?C=69RUbJ0jfUqMFBm0FOwwyF3G2CFV4dMIbWP8sWLHgoUhnIb3mOCquswFpFSDHRdOYsXyIp2mTq4.&amp;URL=mailto%3aPress%40AmberRoad.com" style="font-family: Calibri, sans-serif; font-size: 14.6667px; line-height: normal; text-indent: 48px;">Press@AmberRoad.com</a>.</p>
',
            'format' => 'filtered_html',
          ),
        ),
      ),
      'field_video' => array(
        'und' => array(),
      ),
      'field_video_width' => array(
        'und' => array(),
      ),
      'log' => '',
      'created' => 1473792140,
      'timestamp' => 1473792140,
      'changed' => 1473792140,
      'uuid' => 'babb1a19-9577-44f3-93dd-885a9fd72689',
      'vuuid' => '0d3d9aed-3b45-4d78-a101-f4dfdd736d56',
      'uid' => '43',
    ),
  );
  $pane->cache = array();
  $pane->style = array();
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 2;
  $pane->locks = array();
  $pane->uuid = 'f323b2cd-91cd-46b5-a8b4-db09db8325ee';
  $display->content['new-f323b2cd-91cd-46b5-a8b4-db09db8325ee'] = $pane;
  $display->panels['content_main'][2] = 'new-f323b2cd-91cd-46b5-a8b4-db09db8325ee';
  $pane = new stdClass();
  $pane->pid = 'new-04a8b73c-08f6-4655-a2b0-59938c9e5529';
  $pane->panel = 'content_main';
  $pane->type = 'views_panes';
  $pane->subtype = 'press_release-panel_pane_1';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'more_link' => 1,
    'view_settings' => 'fields',
    'header_type' => 'none',
    'view_mode' => 'teaser',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 3;
  $pane->locks = array();
  $pane->uuid = '04a8b73c-08f6-4655-a2b0-59938c9e5529';
  $display->content['new-04a8b73c-08f6-4655-a2b0-59938c9e5529'] = $pane;
  $display->panels['content_main'][3] = 'new-04a8b73c-08f6-4655-a2b0-59938c9e5529';
  $pane = new stdClass();
  $pane->pid = 'new-31940742-2421-47d4-9f0d-1267bccab89f';
  $pane->panel = 'content_main';
  $pane->type = 'views_panes';
  $pane->subtype = 'press_coverage-panel_pane_2';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array();
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 4;
  $pane->locks = array();
  $pane->uuid = '31940742-2421-47d4-9f0d-1267bccab89f';
  $display->content['new-31940742-2421-47d4-9f0d-1267bccab89f'] = $pane;
  $display->panels['content_main'][4] = 'new-31940742-2421-47d4-9f0d-1267bccab89f';
  $pane = new stdClass();
  $pane->pid = 'new-84fde5bb-c55c-4a77-92cd-280af7d10630';
  $pane->panel = 'content_main';
  $pane->type = 'views_panes';
  $pane->subtype = 'awards-panel_pane_2';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array();
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array(
    'css_id' => '',
    'css_class' => 'pane-awards-list',
  );
  $pane->extras = array();
  $pane->position = 5;
  $pane->locks = array();
  $pane->uuid = '84fde5bb-c55c-4a77-92cd-280af7d10630';
  $display->content['new-84fde5bb-c55c-4a77-92cd-280af7d10630'] = $pane;
  $display->panels['content_main'][5] = 'new-84fde5bb-c55c-4a77-92cd-280af7d10630';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = 'new-39a1a312-1508-44ab-ac2a-4ec218fd3776';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['press_room'] = $page;

  $page = new stdClass();
  $page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'resources';
  $page->task = 'page';
  $page->admin_title = 'Resource Library Search';
  $page->admin_description = '';
  $page->path = 'html/search/resources';
  $page->access = array(
    'type' => 'none',
    'settings' => NULL,
  );
  $page->menu = array(
    'type' => 'normal',
    'title' => 'Resource Library',
    'name' => 'amberroad-main-menu',
    'weight' => '0',
    'parent' => array(
      'type' => 'none',
      'title' => '',
      'name' => 'navigation',
      'weight' => '0',
    ),
  );
  $page->arguments = array();
  $page->conf = array(
    'admin_paths' => FALSE,
  );
  $page->default_handlers = array();
  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'page_resources__panel_context_0e9f027f-98fc-4e54-abfa-8d3ac57b4333';
  $handler->task = 'page';
  $handler->subtask = 'resources';
  $handler->handler = 'panel_context';
  $handler->weight = 0;
  $handler->conf = array(
    'title' => 'Resource Library Search',
    'no_blocks' => 0,
    'pipeline' => 'ipe',
    'body_classes_to_remove' => '',
    'body_classes_to_add' => '',
    'css_id' => '',
    'css' => '',
    'contexts' => array(),
    'relationships' => array(),
    'metatag_panels' => array(
      'enabled' => 1,
      'metatags' => array(
        'title' => array(
          'value' => 'Global Trade Management Software | Resources - Amber Road',
        ),
        'description' => array(
          'value' => 'Amber Road\'s Trade Compliance solution automates and streamlines your import, export and trade agreement operations. Establishing an end-to-end global transaction, three integrated modules ensure global regulatory compliance, prevent border delays, fines and penalties, and enable legal, cost-effective international trade.',
        ),
      ),
    ),
  );
  $display = new panels_display();
  $display->layout = 'amberroad_custom_onerowtwocols_theme';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'content_banner' => NULL,
      'content_main' => NULL,
      'content_sidebar' => NULL,
      'content_top' => NULL,
    ),
    'content_main' => array(
      'style' => '-1',
    ),
  );
  $display->cache = array();
  $display->title = 'Resource Library';
  $display->uuid = '0393b2f0-e88e-48f2-a84a-e4748be39ad4';
  $display->content = array();
  $display->panels = array();
  $pane = new stdClass();
  $pane->pid = 'new-5e8fe9f3-2025-47fa-b556-43a321074104';
  $pane->panel = 'content_banner';
  $pane->type = 'fieldable_panels_pane';
  $pane->subtype = 'uuid:7c560836-37e9-4308-896d-fcf89a67c41b';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'view_mode' => 'header',
    'fieldable_panels_pane' => (object) array(
      'bundle' => 'box',
      'language' => '',
      'is_new' => TRUE,
      'title' => 'Knowledge is Power',
      'link' => 0,
      'path' => '',
      'reusable' => 1,
      'admin_title' => 'Header - Resources',
      'admin_description' => '',
      'category' => 'Reusable Content',
      'vid' => '2662',
      'current_vid' => '',
      'revision' => 1,
      'fpid' => '657',
      'field_basic_image_image' => array(
        'und' => array(
          0 => array(
            'fid' => '2994',
            'display' => '1',
            'description' => '',
            'attach_button' => 'Attach',
            'upload' => '',
            'remove_button' => 'Remove',
            'width' => 2500,
            'height' => 150,
          ),
        ),
      ),
      'field_button' => array(
        'und' => array(),
      ),
      'field_text' => array(
        'und' => array(),
      ),
      'field_video' => array(
        'und' => array(),
      ),
      'field_video_width' => array(
        'und' => array(),
      ),
      'log' => '',
      'created' => 1467299284,
      'timestamp' => 1467299284,
      'changed' => 1467299284,
      'uuid' => '7c560836-37e9-4308-896d-fcf89a67c41b',
      'vuuid' => 'ba2f8354-28d7-4408-9361-790a34a84a0a',
      'uid' => '43',
    ),
  );
  $pane->cache = array();
  $pane->style = array();
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 0;
  $pane->locks = array();
  $pane->uuid = '5e8fe9f3-2025-47fa-b556-43a321074104';
  $display->content['new-5e8fe9f3-2025-47fa-b556-43a321074104'] = $pane;
  $display->panels['content_banner'][0] = 'new-5e8fe9f3-2025-47fa-b556-43a321074104';
  $pane = new stdClass();
  $pane->pid = 'new-b71ade6d-0584-46b6-bceb-2c251bd7fd65';
  $pane->panel = 'content_main';
  $pane->type = 'page_title';
  $pane->subtype = 'page_title';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'markup' => 'h1',
    'class' => '',
    'id' => '',
    'override_title' => 0,
    'override_title_text' => '',
    'override_title_heading' => 'h2',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 0;
  $pane->locks = array();
  $pane->uuid = 'b71ade6d-0584-46b6-bceb-2c251bd7fd65';
  $display->content['new-b71ade6d-0584-46b6-bceb-2c251bd7fd65'] = $pane;
  $display->panels['content_main'][0] = 'new-b71ade6d-0584-46b6-bceb-2c251bd7fd65';
  $pane = new stdClass();
  $pane->pid = 'new-a653205b-d4ae-4aaf-9104-d7a841b17044';
  $pane->panel = 'content_main';
  $pane->type = 'page_breadcrumb';
  $pane->subtype = 'page_breadcrumb';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'panels_breadcrumbs_admin_title' => '',
    'panels_breadcrumbs_state' => 1,
    'panels_breadcrumbs_titles' => 'Resources',
    'panels_breadcrumbs_paths' => '/html/search/resources',
    'panels_breadcrumbs_home' => 1,
    'override_title' => 0,
    'override_title_text' => '',
    'override_title_heading' => 'h2',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 1;
  $pane->locks = array();
  $pane->uuid = 'a653205b-d4ae-4aaf-9104-d7a841b17044';
  $display->content['new-a653205b-d4ae-4aaf-9104-d7a841b17044'] = $pane;
  $display->panels['content_main'][1] = 'new-a653205b-d4ae-4aaf-9104-d7a841b17044';
  $pane = new stdClass();
  $pane->pid = 'new-6eab094b-21a2-4af6-8795-4216d37cb1d9';
  $pane->panel = 'content_main';
  $pane->type = 'custom';
  $pane->subtype = 'custom';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'admin_title' => '',
    'title' => '',
    'body' => '<p><span style="font-size:16px;">Our resource library houses hundreds of thought leadership pieces to help you stay on top of global supply chain trends, industry hot topics, and best practices. Use the filters below to easily find content you’re interested in.</span></p>

<p>&nbsp;</p>
',
    'format' => 'full_html',
    'substitute' => TRUE,
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 2;
  $pane->locks = array();
  $pane->uuid = '6eab094b-21a2-4af6-8795-4216d37cb1d9';
  $display->content['new-6eab094b-21a2-4af6-8795-4216d37cb1d9'] = $pane;
  $display->panels['content_main'][2] = 'new-6eab094b-21a2-4af6-8795-4216d37cb1d9';
  $pane = new stdClass();
  $pane->pid = 'new-2f16f23d-8f00-4f09-ab3e-49233a1858df';
  $pane->panel = 'content_main';
  $pane->type = 'views_panes';
  $pane->subtype = 'resource_library_search-panel_pane_1';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'path' => '',
    'view_settings' => 'fields',
    'header_type' => 'none',
    'view_mode' => 'teaser',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 3;
  $pane->locks = array();
  $pane->uuid = '2f16f23d-8f00-4f09-ab3e-49233a1858df';
  $display->content['new-2f16f23d-8f00-4f09-ab3e-49233a1858df'] = $pane;
  $display->panels['content_main'][3] = 'new-2f16f23d-8f00-4f09-ab3e-49233a1858df';
  $pane = new stdClass();
  $pane->pid = 'new-51193f34-6c8e-4cb3-8b9a-7485137d2159';
  $pane->panel = 'content_sidebar';
  $pane->type = 'block';
  $pane->subtype = 'views-9f7a0414340bac2c312448847d59be84';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'inherit_path' => 0,
    'override_title' => 1,
    'override_title_text' => 'Filter Resources By',
    'override_title_heading' => 'h2',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array(
    'css_id' => '',
    'css_class' => 'resource-library-search-filters',
  );
  $pane->extras = array();
  $pane->position = 0;
  $pane->locks = array();
  $pane->uuid = '51193f34-6c8e-4cb3-8b9a-7485137d2159';
  $display->content['new-51193f34-6c8e-4cb3-8b9a-7485137d2159'] = $pane;
  $display->panels['content_sidebar'][0] = 'new-51193f34-6c8e-4cb3-8b9a-7485137d2159';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['resources'] = $page;

  $page = new stdClass();
  $page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'seminars';
  $page->task = 'page';
  $page->admin_title = 'Seminars';
  $page->admin_description = '';
  $page->path = 'html/seminars.shtml';
  $page->access = array(
    'type' => 'none',
    'settings' => NULL,
  );
  $page->menu = array();
  $page->arguments = array();
  $page->conf = array(
    'admin_paths' => FALSE,
  );
  $page->default_handlers = array();
  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'page_seminars__panel_context_f06632d1-0764-47e7-bcb1-d7c599094825';
  $handler->task = 'page';
  $handler->subtask = 'seminars';
  $handler->handler = 'panel_context';
  $handler->weight = 0;
  $handler->conf = array(
    'title' => 'Seminars',
    'no_blocks' => 0,
    'pipeline' => 'standard',
    'body_classes_to_remove' => '',
    'body_classes_to_add' => '',
    'css_id' => '',
    'css' => '',
    'contexts' => array(),
    'relationships' => array(),
    'metatag_panels' => array(
      'enabled' => 1,
      'metatags' => array(
        'title' => array(
          'value' => 'Global Trade Management Software | Company - Amber Road<',
        ),
        'description' => array(
          'value' => 'Attend Amber Road\'s seminars to find out the latest issues in the industry and best practices for import export compliance, global trade compliance, supply chain visibility, and transportation management.',
        ),
      ),
    ),
  );
  $display = new panels_display();
  $display->layout = 'amberroad_custom_onecol_theme';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'content_banner' => NULL,
      'content_main' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = '';
  $display->uuid = '0393b2f0-e88e-48f2-a84a-e4748be39ad4';
  $display->content = array();
  $display->panels = array();
  $pane = new stdClass();
  $pane->pid = 'new-d506c6bb-f030-4d3b-81d3-afdec816454e';
  $pane->panel = 'content_banner';
  $pane->type = 'fieldable_panels_pane';
  $pane->subtype = 'uuid:67214f0e-d9c8-461f-97d9-557ec5673785';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'view_mode' => 'header',
    'fieldable_panels_pane' => (object) array(
      'bundle' => 'box',
      'language' => 'und',
      'is_new' => TRUE,
      'title' => 'Advancing the Industry',
      'link' => 0,
      'path' => '',
      'reusable' => 0,
      'admin_title' => '',
      'admin_description' => '',
      'category' => 'Reusable Content',
      'vid' => '2614',
      'current_vid' => '',
      'revision' => 1,
      'fpid' => '616',
      'field_basic_image_image' => array(
        'und' => array(
          0 => array(
            'fid' => '2943',
            'display' => '1',
            'description' => '',
            'attach_button' => 'Attach',
            'upload' => '',
            'remove_button' => 'Remove',
            'width' => 2500,
            'height' => 150,
          ),
        ),
      ),
      'field_button' => array(
        'und' => array(),
      ),
      'field_text' => array(
        'und' => array(),
      ),
      'field_video' => array(
        'und' => array(),
      ),
      'field_video_width' => array(
        'und' => array(),
      ),
      'log' => '',
      'created' => 1467293416,
      'timestamp' => 1467293416,
      'changed' => 1467293416,
      'uuid' => '67214f0e-d9c8-461f-97d9-557ec5673785',
      'vuuid' => '4579186e-fc94-42f0-b9a5-c8a9aa272173',
      'uid' => '43',
    ),
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 0;
  $pane->locks = array();
  $pane->uuid = 'd506c6bb-f030-4d3b-81d3-afdec816454e';
  $display->content['new-d506c6bb-f030-4d3b-81d3-afdec816454e'] = $pane;
  $display->panels['content_banner'][0] = 'new-d506c6bb-f030-4d3b-81d3-afdec816454e';
  $pane = new stdClass();
  $pane->pid = 'new-fed26fc7-f9e1-4443-9ba3-72adce7f5965';
  $pane->panel = 'content_main';
  $pane->type = 'page_title';
  $pane->subtype = 'page_title';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'markup' => 'h1',
    'class' => '',
    'id' => '',
    'override_title' => 0,
    'override_title_text' => '',
    'override_title_heading' => 'h2',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 0;
  $pane->locks = array();
  $pane->uuid = 'fed26fc7-f9e1-4443-9ba3-72adce7f5965';
  $display->content['new-fed26fc7-f9e1-4443-9ba3-72adce7f5965'] = $pane;
  $display->panels['content_main'][0] = 'new-fed26fc7-f9e1-4443-9ba3-72adce7f5965';
  $pane = new stdClass();
  $pane->pid = 'new-b6890328-109e-449e-b8e6-453ebebf6810';
  $pane->panel = 'content_main';
  $pane->type = 'page_breadcrumb';
  $pane->subtype = 'page_breadcrumb';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array();
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 1;
  $pane->locks = array();
  $pane->uuid = 'b6890328-109e-449e-b8e6-453ebebf6810';
  $display->content['new-b6890328-109e-449e-b8e6-453ebebf6810'] = $pane;
  $display->panels['content_main'][1] = 'new-b6890328-109e-449e-b8e6-453ebebf6810';
  $pane = new stdClass();
  $pane->pid = 'new-dd4400d3-e148-4c83-8fdc-8529d9be39d2';
  $pane->panel = 'content_main';
  $pane->type = 'views_panes';
  $pane->subtype = 'events-panel_seminar';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'override_title' => 1,
    'override_title_text' => '',
    'override_title_heading' => 'h2',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 2;
  $pane->locks = array();
  $pane->uuid = 'dd4400d3-e148-4c83-8fdc-8529d9be39d2';
  $display->content['new-dd4400d3-e148-4c83-8fdc-8529d9be39d2'] = $pane;
  $display->panels['content_main'][2] = 'new-dd4400d3-e148-4c83-8fdc-8529d9be39d2';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['seminars'] = $page;

  $page = new stdClass();
  $page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'testimonial';
  $page->task = 'page';
  $page->admin_title = 'Testimonial';
  $page->admin_description = 'Client testimonial page.';
  $page->path = 'html/testimonials.shtml';
  $page->access = array(
    'type' => 'none',
    'settings' => NULL,
  );
  $page->menu = array(
    'type' => 'none',
    'title' => '',
    'name' => 'amberroad-main-menu',
    'weight' => '0',
    'parent' => array(
      'type' => 'normal',
      'title' => '',
      'name' => 'amberroad-main-menu',
      'weight' => '0',
    ),
  );
  $page->arguments = array();
  $page->conf = array(
    'admin_paths' => FALSE,
  );
  $page->default_handlers = array();
  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'page_testimonial__panel_context_2bf2c7bc-ce19-4751-924a-ee5f4d71ce8f';
  $handler->task = 'page';
  $handler->subtask = 'testimonial';
  $handler->handler = 'panel_context';
  $handler->weight = 0;
  $handler->conf = array(
    'title' => 'Panel',
    'no_blocks' => 0,
    'pipeline' => 'ipe',
    'body_classes_to_remove' => '',
    'body_classes_to_add' => '',
    'css_id' => '',
    'css' => '',
    'contexts' => array(),
    'relationships' => array(),
    'metatag_panels' => array(
      'enabled' => 1,
      'metatags' => array(
        'title' => array(
          'value' => 'Global Trade Management Software | Solutions - Amber Road',
        ),
        'description' => array(
          'value' => 'Find out what Amber Road\'s customers and industry analysts are saying about our: export compliance software, import compliance software, supply chain visibility software, free trade agreement software, global trade compliance software, foreign trade zone software, import software, export software, and transportation management software.',
        ),
      ),
    ),
  );
  $display = new panels_display();
  $display->layout = 'amberroad_custom_onecol_theme';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'content_banner' => NULL,
      'content_main' => NULL,
      'header' => NULL,
      'sidebar' => NULL,
      'contentmain' => NULL,
    ),
    'content_banner' => array(
      'style' => '0',
    ),
  );
  $display->cache = array();
  $display->title = 'Testimonials';
  $display->uuid = 'b2245dea-1fb3-460b-9262-dc0d60d1c4ba';
  $display->content = array();
  $display->panels = array();
  $pane = new stdClass();
  $pane->pid = 'new-f8096d27-36c7-4d86-bdf4-3868b40919ce';
  $pane->panel = 'content_banner';
  $pane->type = 'fieldable_panels_pane';
  $pane->subtype = 'uuid:5818797b-fd4b-4b91-9b1a-98f9d4c06fb2';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'view_mode' => 'header',
    'fieldable_panels_pane' => (object) array(
      'bundle' => 'box',
      'language' => 'und',
      'is_new' => TRUE,
      'title' => 'Demonstrating Leadership Across a Range of Industries',
      'link' => 0,
      'path' => '',
      'reusable' => 0,
      'admin_title' => '',
      'admin_description' => '',
      'category' => 'Reusable Content',
      'vid' => '2607',
      'current_vid' => '',
      'revision' => 1,
      'fpid' => '610',
      'field_basic_image_image' => array(
        'und' => array(
          0 => array(
            'fid' => '2937',
            'display' => '1',
            'description' => '',
            'attach_button' => 'Attach',
            'upload' => '',
            'remove_button' => 'Remove',
            'width' => 2500,
            'height' => 150,
          ),
        ),
      ),
      'field_button' => array(
        'und' => array(),
      ),
      'field_text' => array(
        'und' => array(),
      ),
      'field_video' => array(
        'und' => array(),
      ),
      'field_video_width' => array(
        'und' => array(),
      ),
      'log' => '',
      'created' => 1467291878,
      'timestamp' => 1467291878,
      'changed' => 1467291878,
      'uuid' => '5818797b-fd4b-4b91-9b1a-98f9d4c06fb2',
      'vuuid' => '5f28995e-4bcf-458a-9d87-81d1c0cf342b',
      'uid' => '43',
    ),
  );
  $pane->cache = array();
  $pane->style = array();
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 0;
  $pane->locks = array();
  $pane->uuid = 'f8096d27-36c7-4d86-bdf4-3868b40919ce';
  $display->content['new-f8096d27-36c7-4d86-bdf4-3868b40919ce'] = $pane;
  $display->panels['content_banner'][0] = 'new-f8096d27-36c7-4d86-bdf4-3868b40919ce';
  $pane = new stdClass();
  $pane->pid = 'new-9543a6af-8f42-4c94-8315-be0807a69f93';
  $pane->panel = 'content_main';
  $pane->type = 'page_title';
  $pane->subtype = 'page_title';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'markup' => 'h1',
    'class' => '',
    'id' => '',
    'override_title' => 0,
    'override_title_text' => '',
    'override_title_heading' => 'h2',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 0;
  $pane->locks = array();
  $pane->uuid = '9543a6af-8f42-4c94-8315-be0807a69f93';
  $display->content['new-9543a6af-8f42-4c94-8315-be0807a69f93'] = $pane;
  $display->panels['content_main'][0] = 'new-9543a6af-8f42-4c94-8315-be0807a69f93';
  $pane = new stdClass();
  $pane->pid = 'new-19d766be-80a7-426d-9629-a156e8e368a2';
  $pane->panel = 'content_main';
  $pane->type = 'page_breadcrumb';
  $pane->subtype = 'page_breadcrumb';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array();
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 1;
  $pane->locks = array();
  $pane->uuid = '19d766be-80a7-426d-9629-a156e8e368a2';
  $display->content['new-19d766be-80a7-426d-9629-a156e8e368a2'] = $pane;
  $display->panels['content_main'][1] = 'new-19d766be-80a7-426d-9629-a156e8e368a2';
  $pane = new stdClass();
  $pane->pid = 'new-8b7d211d-7c80-4f4e-b684-f8b079d27ea6';
  $pane->panel = 'content_main';
  $pane->type = 'views';
  $pane->subtype = 'testimonial';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'override_pager_settings' => 0,
    'use_pager' => 0,
    'nodes_per_page' => '0',
    'pager_id' => '0',
    'offset' => '0',
    'more_link' => 0,
    'feed_icons' => 0,
    'panel_args' => 0,
    'link_to_view' => 0,
    'args' => '',
    'url' => '',
    'display' => 'block_1',
    'override_title' => 1,
    'override_title_text' => '',
    'override_title_heading' => 'h2',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array(
    'css_id' => '',
    'css_class' => 'pane-testimonials-list-block',
  );
  $pane->extras = array();
  $pane->position = 2;
  $pane->locks = array();
  $pane->uuid = '8b7d211d-7c80-4f4e-b684-f8b079d27ea6';
  $display->content['new-8b7d211d-7c80-4f4e-b684-f8b079d27ea6'] = $pane;
  $display->panels['content_main'][2] = 'new-8b7d211d-7c80-4f4e-b684-f8b079d27ea6';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = 'new-8b7d211d-7c80-4f4e-b684-f8b079d27ea6';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['testimonial'] = $page;

  $page = new stdClass();
  $page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'upcoming_webinars';
  $page->task = 'page';
  $page->admin_title = 'Upcoming Webinars';
  $page->admin_description = '';
  $page->path = 'html/webinars.shtml';
  $page->access = array(
    'type' => 'none',
    'settings' => NULL,
  );
  $page->menu = array();
  $page->arguments = array();
  $page->conf = array(
    'admin_paths' => FALSE,
  );
  $page->default_handlers = array();
  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'page_upcoming_webinars__panel_context_95099542-a887-42f6-a5a1-539477be9c53';
  $handler->task = 'page';
  $handler->subtask = 'upcoming_webinars';
  $handler->handler = 'panel_context';
  $handler->weight = 0;
  $handler->conf = array(
    'title' => 'Upcoming Webinars',
    'no_blocks' => 0,
    'pipeline' => 'ipe',
    'body_classes_to_remove' => '',
    'body_classes_to_add' => '',
    'css_id' => '',
    'css' => '',
    'contexts' => array(),
    'relationships' => array(),
    'metatag_panels' => array(
      'enabled' => 1,
      'metatags' => array(
        'title' => array(
          'value' => 'Global Trade Management Software | Company - Amber Road',
        ),
        'description' => array(
          'value' => 'Attend live webinars from Amber Road on topics related to global trade compliance, import and export compliance, supply chain visibility, logistics and transportation management.',
        ),
      ),
    ),
  );
  $display = new panels_display();
  $display->layout = 'amberroad_custom_onecol_theme';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'content_banner' => NULL,
      'content_main' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = '';
  $display->uuid = '0393b2f0-e88e-48f2-a84a-e4748be39ad4';
  $display->content = array();
  $display->panels = array();
  $pane = new stdClass();
  $pane->pid = 'new-de8eaa01-4baf-43d9-83a1-594dacf69902';
  $pane->panel = 'content_banner';
  $pane->type = 'fieldable_panels_pane';
  $pane->subtype = 'current:612';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'view_mode' => 'header',
    'fieldable_panels_pane' => (object) array(
      'timestamp' => 1467292372,
      'uid' => '43',
      'title' => 'Knowledge is Power',
      'log' => '',
      'vuuid' => 'f53a3799-ee19-4903-bc7e-fbc5340e701b',
      'fpid' => '612',
      'bundle' => 'box',
      'link' => 0,
      'path' => '',
      'reusable' => '0',
      'admin_title' => '',
      'admin_description' => '',
      'category' => 'Reusable Content',
      'view_access' => NULL,
      'edit_access' => NULL,
      'created' => '1467292290',
      'changed' => 1467292372,
      'uuid' => '6e5bd65a-4a63-443a-81c9-d6dc4741dcf2',
      'language' => '',
      'current_vid' => '2609',
      'field_basic_image_image' => array(
        'und' => array(
          0 => array(
            'fid' => '2939',
            'display' => '1',
            'description' => '',
            'attach_button' => 'Attach',
            'upload' => '',
            'remove_button' => 'Remove',
            'width' => 2500,
            'height' => 150,
          ),
        ),
      ),
      'field_button' => array(
        'und' => array(),
      ),
      'field_text' => array(
        'und' => array(),
      ),
      'field_video' => array(
        'und' => array(),
      ),
      'field_video_width' => array(
        'und' => array(),
      ),
      'rdf_mapping' => array(),
      'revision' => 1,
      'is_new' => FALSE,
      'original' => (object) array(
        'vid' => '2609',
        'timestamp' => '1467292290',
        'uid' => '43',
        'title' => 'Knowledge is Power',
        'log' => '',
        'vuuid' => 'c491d650-7b30-48d9-8323-0bb9c5076804',
        'fpid' => '612',
        'bundle' => 'box',
        'link' => '0',
        'path' => '',
        'reusable' => '0',
        'admin_title' => '',
        'admin_description' => '',
        'category' => 'Reusable Content',
        'view_access' => NULL,
        'edit_access' => NULL,
        'created' => '1467292290',
        'changed' => '1467292290',
        'uuid' => '6e5bd65a-4a63-443a-81c9-d6dc4741dcf2',
        'language' => '',
        'current_vid' => '2609',
        'field_basic_image_image' => array(
          'und' => array(
            0 => array(
              'fid' => '2939',
              'uid' => '43',
              'filename' => 'events.jpg',
              'uri' => 'public://events_6.jpg',
              'filemime' => 'image/jpeg',
              'filesize' => '31038',
              'status' => '1',
              'timestamp' => '1467292283',
              'type' => 'image',
              'uuid' => '6d1e75f9-dfdd-4ec9-a5d2-181452940354',
              'field_file_image_alt_text' => array(
                'und' => array(
                  0 => array(
                    'value' => 'Knowledge is Power',
                    'format' => NULL,
                    'safe_value' => 'Knowledge is Power',
                  ),
                ),
              ),
              'field_file_image_title_text' => array(),
              'metatags' => array(),
              'rdf_mapping' => array(),
              'metadata' => array(
                'height' => 150,
                'width' => 2500,
              ),
              'alt' => 'Knowledge is Power',
              'title' => NULL,
              'height' => '150',
              'width' => '2500',
            ),
          ),
        ),
        'field_button' => array(),
        'field_text' => array(),
        'field_video' => array(),
        'field_video_width' => array(),
        'rdf_mapping' => array(),
      ),
      'old_vid' => '2609',
      'vid' => '2610',
    ),
  );
  $pane->cache = array();
  $pane->style = array();
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 0;
  $pane->locks = array();
  $pane->uuid = 'de8eaa01-4baf-43d9-83a1-594dacf69902';
  $display->content['new-de8eaa01-4baf-43d9-83a1-594dacf69902'] = $pane;
  $display->panels['content_banner'][0] = 'new-de8eaa01-4baf-43d9-83a1-594dacf69902';
  $pane = new stdClass();
  $pane->pid = 'new-b71ade6d-0584-46b6-bceb-2c251bd7fd65';
  $pane->panel = 'content_main';
  $pane->type = 'page_title';
  $pane->subtype = 'page_title';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'markup' => 'h1',
    'class' => '',
    'id' => '',
    'override_title' => 0,
    'override_title_text' => '',
    'override_title_heading' => 'h2',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 0;
  $pane->locks = array();
  $pane->uuid = 'b71ade6d-0584-46b6-bceb-2c251bd7fd65';
  $display->content['new-b71ade6d-0584-46b6-bceb-2c251bd7fd65'] = $pane;
  $display->panels['content_main'][0] = 'new-b71ade6d-0584-46b6-bceb-2c251bd7fd65';
  $pane = new stdClass();
  $pane->pid = 'new-b6890328-109e-449e-b8e6-453ebebf6810';
  $pane->panel = 'content_main';
  $pane->type = 'page_breadcrumb';
  $pane->subtype = 'page_breadcrumb';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array();
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 1;
  $pane->locks = array();
  $pane->uuid = 'b6890328-109e-449e-b8e6-453ebebf6810';
  $display->content['new-b6890328-109e-449e-b8e6-453ebebf6810'] = $pane;
  $display->panels['content_main'][1] = 'new-b6890328-109e-449e-b8e6-453ebebf6810';
  $pane = new stdClass();
  $pane->pid = 'new-5e389ad5-e7f9-495e-a043-716ae24affae';
  $pane->panel = 'content_main';
  $pane->type = 'views_panes';
  $pane->subtype = 'events-panel_webinar';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'override_title' => 1,
    'override_title_text' => '',
    'override_title_heading' => 'h2',
    'view_settings' => 'fields',
    'header_type' => 'none',
    'view_mode' => 'teaser',
    'widget_title' => 'Upcoming Webinars',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 2;
  $pane->locks = array();
  $pane->uuid = '5e389ad5-e7f9-495e-a043-716ae24affae';
  $display->content['new-5e389ad5-e7f9-495e-a043-716ae24affae'] = $pane;
  $display->panels['content_main'][2] = 'new-5e389ad5-e7f9-495e-a043-716ae24affae';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['upcoming_webinars'] = $page;

  return $pages;

}
