<?php
/**
 * @file
 * amberroad_panels.panelizer.inc
 */

/**
 * Implements hook_panelizer_defaults().
 */
function amberroad_panels_panelizer_defaults() {
  $export = array();

  $panelizer = new stdClass();
  $panelizer->disabled = FALSE; /* Edit this to true to make a default panelizer disabled initially */
  $panelizer->api_version = 1;
  $panelizer->name = 'node:solution_area:default';
  $panelizer->title = 'Default';
  $panelizer->panelizer_type = 'node';
  $panelizer->panelizer_key = 'solution_area';
  $panelizer->no_blocks = FALSE;
  $panelizer->css_id = '';
  $panelizer->css = '';
  $panelizer->pipeline = 'standard';
  $panelizer->contexts = array();
  $panelizer->relationships = array();
  $panelizer->access = array();
  $panelizer->view_mode = 'page_manager';
  $panelizer->css_class = '';
  $panelizer->title_element = 'H2';
  $panelizer->link_to_entity = TRUE;
  $panelizer->extra = array();
  $display = new panels_display();
  $display->layout = 'ar_internal_1';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'content_banner' => NULL,
      'content_top' => NULL,
      'content_main' => NULL,
      'content_sidebar' => NULL,
      'row1-content' => NULL,
      'row1-sidebar' => NULL,
      'row2-left' => NULL,
      'row2-right' => NULL,
      'row3-main' => NULL,
      'row3-right1' => NULL,
      'row3-right2' => NULL,
      'row4-left' => NULL,
      'row4-content' => NULL,
      'header' => NULL,
      'row2' => NULL,
      'row2-2col1' => NULL,
      'row2-2col2' => NULL,
      'row3-short-main' => NULL,
      'row3-short-right1' => NULL,
      'row3-short-right2' => NULL,
      'row3-long-main' => NULL,
      'row3-long-right1' => NULL,
      'row3-long-right2' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = '%node:title';
  $display->uuid = '3249ae47-b763-4d1f-87e4-9f0d3d3e33ac';
  $display->content = array();
  $display->panels = array();
  $pane = new stdClass();
  $pane->pid = 'new-298af60c-483f-4fd9-979e-94eed51fc95c';
  $pane->panel = 'header';
  $pane->type = 'entity_field';
  $pane->subtype = 'node:field_header_image';
  $pane->shown = TRUE;
  $pane->access = array();
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
    'context' => array(),
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
  $pane->uuid = '298af60c-483f-4fd9-979e-94eed51fc95c';
  $display->content['new-298af60c-483f-4fd9-979e-94eed51fc95c'] = $pane;
  $display->panels['header'][0] = 'new-298af60c-483f-4fd9-979e-94eed51fc95c';
  $pane = new stdClass();
  $pane->pid = 'new-8b32b4c9-c0e0-4795-ab4f-1194969a45e2';
  $pane->panel = 'row1-content';
  $pane->type = 'node_title';
  $pane->subtype = 'node_title';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'link' => 0,
    'markup' => 'h1',
    'id' => '',
    'class' => '',
    'context' => 'panelizer',
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
  $pane->uuid = '8b32b4c9-c0e0-4795-ab4f-1194969a45e2';
  $display->content['new-8b32b4c9-c0e0-4795-ab4f-1194969a45e2'] = $pane;
  $display->panels['row1-content'][0] = 'new-8b32b4c9-c0e0-4795-ab4f-1194969a45e2';
  $pane = new stdClass();
  $pane->pid = 'new-2b015fea-aeae-4097-a2ac-669a00f89ce9';
  $pane->panel = 'row1-content';
  $pane->type = 'page_breadcrumb';
  $pane->subtype = 'page_breadcrumb';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'panels_breadcrumbs_admin_title' => '',
    'panels_breadcrumbs_state' => 0,
    'panels_breadcrumbs_titles' => '',
    'panels_breadcrumbs_paths' => '',
    'panels_breadcrumbs_home' => 0,
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
  $pane->uuid = '2b015fea-aeae-4097-a2ac-669a00f89ce9';
  $display->content['new-2b015fea-aeae-4097-a2ac-669a00f89ce9'] = $pane;
  $display->panels['row1-content'][1] = 'new-2b015fea-aeae-4097-a2ac-669a00f89ce9';
  $pane = new stdClass();
  $pane->pid = 'new-86af998f-5cca-437d-aae4-bdb7183b726b';
  $pane->panel = 'row1-content';
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
  $pane->position = 2;
  $pane->locks = array();
  $pane->uuid = '86af998f-5cca-437d-aae4-bdb7183b726b';
  $display->content['new-86af998f-5cca-437d-aae4-bdb7183b726b'] = $pane;
  $display->panels['row1-content'][2] = 'new-86af998f-5cca-437d-aae4-bdb7183b726b';
  $pane = new stdClass();
  $pane->pid = 'new-0f0c5aa5-73b1-49f5-a307-a46627596733';
  $pane->panel = 'row1-content';
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
    'context' => 'panelizer',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 3;
  $pane->locks = array();
  $pane->uuid = '0f0c5aa5-73b1-49f5-a307-a46627596733';
  $display->content['new-0f0c5aa5-73b1-49f5-a307-a46627596733'] = $pane;
  $display->panels['row1-content'][3] = 'new-0f0c5aa5-73b1-49f5-a307-a46627596733';
  $pane = new stdClass();
  $pane->pid = 'new-d46bb50e-c98f-4717-95f4-0045e450fd72';
  $pane->panel = 'row1-sidebar';
  $pane->type = 'fieldable_panels_pane';
  $pane->subtype = 'uuid:39573e77-9907-44da-abd2-670f24f3eb22';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'view_mode' => 'image_block',
    'fieldable_panels_pane' => (object) array(
      'timestamp' => 1457705044,
      'uid' => '28',
      'title' => '',
      'log' => '',
      'vuuid' => '5391ebb2-ae75-449a-9667-47c20747f7f4',
      'fpid' => '41',
      'bundle' => 'box',
      'link' => 0,
      'path' => '',
      'reusable' => 1,
      'admin_title' => 'Solution brochure',
      'admin_description' => '',
      'category' => 'Reusable Content',
      'view_access' => NULL,
      'edit_access' => NULL,
      'created' => '1457703866',
      'changed' => 1457705044,
      'uuid' => '39573e77-9907-44da-abd2-670f24f3eb22',
      'language' => '',
      'current_vid' => '122',
      'field_text' => array(
        'und' => array(),
      ),
      'field_basic_image_image' => array(
        'und' => array(
          0 => array(
            'fid' => '1488',
            'display' => '1',
            'description' => '',
            'attach_button' => 'Attach',
            'upload' => '',
            'remove_button' => 'Remove',
            'width' => 230,
            'height' => 250,
          ),
        ),
      ),
      'field_button' => array(
        'und' => array(
          0 => array(
            'title' => 'Solution brochure',
            'url' => 'http://www.amberroad.com',
            'attributes' => 'a:1:{s:6:"target";i:0;}',
          ),
        ),
      ),
      'field_video_file' => array(
        'und' => array(),
      ),
      'field_panel_pane_type' => array(
        'und' => array(),
      ),
      'rdf_mapping' => array(),
      'revision' => 1,
      'is_new' => FALSE,
      'original' => (object) array(
        'vid' => '122',
        'timestamp' => '1457704140',
        'uid' => '28',
        'title' => '',
        'log' => '',
        'vuuid' => '9d5ba9f2-ffa0-4615-9dbd-ccd0b8e03acd',
        'fpid' => '41',
        'bundle' => 'box',
        'link' => '0',
        'path' => '',
        'reusable' => '1',
        'admin_title' => 'Solution brochure',
        'admin_description' => '',
        'category' => 'Reusable Content',
        'view_access' => NULL,
        'edit_access' => NULL,
        'created' => '1457703866',
        'changed' => '1457704140',
        'uuid' => '39573e77-9907-44da-abd2-670f24f3eb22',
        'language' => '',
        'current_vid' => '122',
        'field_text' => array(),
        'field_basic_image_image' => array(
          'und' => array(
            0 => array(
              'fid' => '1488',
              'uid' => '28',
              'filename' => 'sidebar_brochure_transportation_management_6.jpg',
              'uri' => 'public://sidebar_brochure_transportation_management_6.jpg',
              'filemime' => 'image/jpeg',
              'filesize' => '40629',
              'status' => '1',
              'timestamp' => '1457703805',
              'type' => 'image',
              'uuid' => '73f03aec-4e29-4189-8d65-75bed1910b70',
              'field_file_image_alt_text' => array(),
              'field_file_image_title_text' => array(),
              'metatags' => array(),
              'rdf_mapping' => array(),
              'metadata' => array(
                'height' => 250,
                'width' => 230,
              ),
              'alt' => NULL,
              'title' => NULL,
              'height' => '250',
              'width' => '230',
            ),
          ),
        ),
        'field_button' => array(
          'und' => array(
            0 => array(
              'url' => 'http://www.amberroad.com',
              'title' => 'aaaaa',
              'attributes' => array(
                'target' => 0,
              ),
            ),
          ),
        ),
        'field_video_file' => array(),
        'field_panel_pane_type' => array(),
        'rdf_mapping' => array(),
      ),
      'old_vid' => '122',
      'vid' => '124',
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
  $pane->uuid = 'd46bb50e-c98f-4717-95f4-0045e450fd72';
  $display->content['new-d46bb50e-c98f-4717-95f4-0045e450fd72'] = $pane;
  $display->panels['row1-sidebar'][0] = 'new-d46bb50e-c98f-4717-95f4-0045e450fd72';
  $pane = new stdClass();
  $pane->pid = 'new-3c2867cf-12b3-442a-a159-24d888f9ddaf';
  $pane->panel = 'row1-sidebar';
  $pane->type = 'fieldable_panels_pane';
  $pane->subtype = 'uuid:afbc9ec4-6c3e-430f-875a-4537e256c444';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'view_mode' => 'image_block',
    'fieldable_panels_pane' => (object) array(
      'timestamp' => 1457705079,
      'uid' => '28',
      'title' => '',
      'log' => '',
      'vuuid' => '9ce73140-db70-46ae-bf07-ceac4f71dda8',
      'fpid' => '42',
      'bundle' => 'box',
      'link' => 0,
      'path' => '',
      'reusable' => 1,
      'admin_title' => 'Webinar image',
      'admin_description' => '',
      'category' => 'Reusable Content',
      'view_access' => NULL,
      'edit_access' => NULL,
      'created' => '1457704891',
      'changed' => 1457705079,
      'uuid' => 'afbc9ec4-6c3e-430f-875a-4537e256c444',
      'language' => 'und',
      'current_vid' => '123',
      'field_text' => array(
        'und' => array(),
      ),
      'field_basic_image_image' => array(
        'und' => array(
          0 => array(
            'fid' => '1489',
            'display' => '1',
            'description' => '',
            'attach_button' => 'Attach',
            'upload' => '',
            'remove_button' => 'Remove',
            'width' => 230,
            'height' => 250,
          ),
        ),
      ),
      'field_button' => array(
        'und' => array(
          0 => array(
            'title' => 'Webinar image',
            'url' => 'http://www.amberroad.com',
            'attributes' => 'a:1:{s:6:"target";i:0;}',
          ),
        ),
      ),
      'field_video_file' => array(
        'und' => array(),
      ),
      'field_panel_pane_type' => array(
        'und' => array(),
      ),
      'rdf_mapping' => array(),
      'revision' => 1,
      'is_new' => FALSE,
      'original' => (object) array(
        'vid' => '123',
        'timestamp' => '1457704891',
        'uid' => '28',
        'title' => '',
        'log' => '',
        'vuuid' => 'a3ed4c94-506a-4c86-bbfe-7ca424d8534b',
        'fpid' => '42',
        'bundle' => 'box',
        'link' => '0',
        'path' => '',
        'reusable' => '1',
        'admin_title' => 'Webinar image',
        'admin_description' => '',
        'category' => 'Reusable Content',
        'view_access' => NULL,
        'edit_access' => NULL,
        'created' => '1457704891',
        'changed' => '1457704891',
        'uuid' => 'afbc9ec4-6c3e-430f-875a-4537e256c444',
        'language' => 'und',
        'current_vid' => '123',
        'field_text' => array(),
        'field_basic_image_image' => array(
          'und' => array(
            0 => array(
              'fid' => '1489',
              'uid' => '28',
              'filename' => 'sidebar-webinar-managing-fta_1.jpg',
              'uri' => 'public://sidebar-webinar-managing-fta_1.jpg',
              'filemime' => 'image/jpeg',
              'filesize' => '28046',
              'status' => '1',
              'timestamp' => '1457704859',
              'type' => 'image',
              'uuid' => 'c712c50d-4354-4ac2-a240-ba38235cef8c',
              'field_file_image_alt_text' => array(),
              'field_file_image_title_text' => array(),
              'metatags' => array(),
              'rdf_mapping' => array(),
              'metadata' => array(
                'height' => 250,
                'width' => 230,
              ),
              'alt' => NULL,
              'title' => NULL,
              'height' => '250',
              'width' => '230',
            ),
          ),
        ),
        'field_button' => array(
          'und' => array(
            0 => array(
              'url' => 'http://www.amberroad.com',
              'title' => '',
              'attributes' => array(
                'target' => 0,
              ),
            ),
          ),
        ),
        'field_video_file' => array(),
        'field_panel_pane_type' => array(),
        'rdf_mapping' => array(),
      ),
      'old_vid' => '123',
      'vid' => '125',
    ),
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 1;
  $pane->locks = array();
  $pane->uuid = '3c2867cf-12b3-442a-a159-24d888f9ddaf';
  $display->content['new-3c2867cf-12b3-442a-a159-24d888f9ddaf'] = $pane;
  $display->panels['row1-sidebar'][1] = 'new-3c2867cf-12b3-442a-a159-24d888f9ddaf';
  $pane = new stdClass();
  $pane->pid = 'new-81a08b50-6cd3-4f58-8740-727de063e892';
  $pane->panel = 'row2';
  $pane->type = 'fieldable_panels_pane';
  $pane->subtype = 'uuid:2c98a478-a55b-414a-a421-6c7af9fe274f';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'view_mode' => 'video_horizontal',
    'fieldable_panels_pane' => (object) array(
      'timestamp' => 1457712359,
      'uid' => '1',
      'title' => 'What Makes Amber Road the Best in Class?',
      'log' => '',
      'vuuid' => '35da3338-82e7-4adf-90f3-b6bf8c8975a3',
      'fpid' => '44',
      'bundle' => 'box',
      'link' => 0,
      'path' => '',
      'reusable' => 1,
      'admin_title' => '',
      'admin_description' => '',
      'category' => 'Reusable Content',
      'view_access' => NULL,
      'edit_access' => NULL,
      'created' => '1457711077',
      'changed' => 1457712359,
      'uuid' => '2c98a478-a55b-414a-a421-6c7af9fe274f',
      'language' => 'und',
      'current_vid' => '135',
      'field_text' => array(
        'und' => array(
          0 => array(
            'summary' => '',
            'value' => '<p>Key differentiators include:</p>

<ul>
	<li>Functional depth and breadth of GTM software</li>
	<li>Trade compliance plus supply chain visibility</li>
	<li>One-stop shop for software and content Flexible enterprise technology framework</li>
</ul>
',
            'format' => 'full_html',
          ),
        ),
      ),
      'field_basic_image_image' => array(
        'und' => array(),
      ),
      'field_button' => array(
        'und' => array(),
      ),
      'field_video_file' => array(
        'und' => array(),
      ),
      'field_panel_pane_type' => array(
        'und' => array(),
      ),
      'field_video' => array(
        'und' => array(
          0 => array(
            'value' => '5-tmdJkBECnMMaRWJAHx9Q',
          ),
        ),
      ),
      'rdf_mapping' => array(),
      'revision' => 1,
      'is_new' => FALSE,
      'original' => (object) array(
        'vid' => '135',
        'timestamp' => '1457712107',
        'uid' => '1',
        'title' => 'What Makes Amber Road the Best in Class?',
        'log' => '',
        'vuuid' => 'ee83a8fe-bd03-4531-bf29-9dc825a57e9c',
        'fpid' => '44',
        'bundle' => 'box',
        'link' => '0',
        'path' => '',
        'reusable' => '0',
        'admin_title' => '',
        'admin_description' => '',
        'category' => 'Reusable Content',
        'view_access' => NULL,
        'edit_access' => NULL,
        'created' => '1457711077',
        'changed' => '1457712107',
        'uuid' => '2c98a478-a55b-414a-a421-6c7af9fe274f',
        'language' => 'und',
        'current_vid' => '135',
        'field_text' => array(
          'und' => array(
            0 => array(
              'value' => '<p>Key differentiators include:</p>

<ul>
	<li>Functional depth and breadth of GTM software</li>
	<li>Trade compliance plus supply chain visibility</li>
	<li>One-stop shop for software and content Flexible enterprise technology framework</li>
</ul>
',
              'summary' => '',
              'format' => 'full_html',
              'safe_value' => '<p>Key differentiators include:</p>
<ul><li>Functional depth and breadth of GTM software</li>
<li>Trade compliance plus supply chain visibility</li>
<li>One-stop shop for software and content Flexible enterprise technology framework</li>
</ul>',
              'safe_summary' => '',
            ),
          ),
        ),
        'field_basic_image_image' => array(),
        'field_button' => array(),
        'field_video_file' => array(),
        'field_panel_pane_type' => array(),
        'field_video' => array(),
        'rdf_mapping' => array(),
      ),
      'old_vid' => '135',
      'vid' => '136',
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
  $pane->uuid = '81a08b50-6cd3-4f58-8740-727de063e892';
  $display->content['new-81a08b50-6cd3-4f58-8740-727de063e892'] = $pane;
  $display->panels['row2'][0] = 'new-81a08b50-6cd3-4f58-8740-727de063e892';
  $pane = new stdClass();
  $pane->pid = 'new-2b98c162-5f36-4c9f-be55-5d02e2e1bb68';
  $pane->panel = 'row3-main';
  $pane->type = 'entity_field';
  $pane->subtype = 'node:field_related_content_descriptio';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'label' => 'above',
    'formatter' => 'text_default',
    'delta_limit' => 0,
    'delta_offset' => '0',
    'delta_reversed' => FALSE,
    'formatter_settings' => array(),
    'context' => 'panelizer',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 0;
  $pane->locks = array();
  $pane->uuid = '2b98c162-5f36-4c9f-be55-5d02e2e1bb68';
  $display->content['new-2b98c162-5f36-4c9f-be55-5d02e2e1bb68'] = $pane;
  $display->panels['row3-main'][0] = 'new-2b98c162-5f36-4c9f-be55-5d02e2e1bb68';
  $pane = new stdClass();
  $pane->pid = 'new-eb20e431-33e2-43c8-b7e5-180ff8af0dde';
  $pane->panel = 'row3-main';
  $pane->type = 'entity_field';
  $pane->subtype = 'node:field_related_solution_area_cont';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'label' => 'above',
    'formatter' => 'entityreference_label',
    'delta_limit' => 0,
    'delta_offset' => '0',
    'delta_reversed' => FALSE,
    'formatter_settings' => array(
      'link' => FALSE,
    ),
    'context' => 'panelizer',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 1;
  $pane->locks = array();
  $pane->uuid = 'eb20e431-33e2-43c8-b7e5-180ff8af0dde';
  $display->content['new-eb20e431-33e2-43c8-b7e5-180ff8af0dde'] = $pane;
  $display->panels['row3-main'][1] = 'new-eb20e431-33e2-43c8-b7e5-180ff8af0dde';
  $pane = new stdClass();
  $pane->pid = 'new-bd29f975-e736-4ac0-a00d-1c97f4d2bfde';
  $pane->panel = 'row3-right1';
  $pane->type = 'views_panes';
  $pane->subtype = 'client_images-panel_pane_1';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'items_per_page' => '1',
    'arguments' => array(
      'nid' => '569',
    ),
    'view_settings' => 'fields',
    'header_type' => 'titles',
    'view_mode' => 'teaser',
    'exposed' => array(
      'title' => 'Agilent',
    ),
    'offset' => '4',
    'fields_override' => array(
      'title' => 0,
      'field_fc_client_image' => 1,
    ),
    'override_title' => '',
    'override_title_text' => '',
    'override_title_heading' => 'h2',
    'widget_title' => 'Client Images',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 0;
  $pane->locks = array();
  $pane->uuid = 'bd29f975-e736-4ac0-a00d-1c97f4d2bfde';
  $display->content['new-bd29f975-e736-4ac0-a00d-1c97f4d2bfde'] = $pane;
  $display->panels['row3-right1'][0] = 'new-bd29f975-e736-4ac0-a00d-1c97f4d2bfde';
  $pane = new stdClass();
  $pane->pid = 'new-6ec82532-1c65-4664-bb40-c7b6b005fc9c';
  $pane->panel = 'row3-right2';
  $pane->type = 'fieldable_panels_pane';
  $pane->subtype = 'uuid:63de82a7-2bfd-4585-aee3-0d4ee79c3423';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'view_mode' => 'image_block',
    'fieldable_panels_pane' => (object) array(
      'bundle' => 'box',
      'language' => '',
      'is_new' => TRUE,
      'title' => '',
      'link' => 0,
      'path' => '',
      'reusable' => 1,
      'admin_title' => 'Find out more',
      'admin_description' => '',
      'category' => 'Reusable Content',
      'vid' => '126',
      'current_vid' => '',
      'revision' => 1,
      'fpid' => '43',
      'field_text' => array(
        'und' => array(),
      ),
      'field_basic_image_image' => array(
        'und' => array(
          0 => array(
            'fid' => '1490',
            'display' => '1',
            'description' => '',
            'attach_button' => 'Attach',
            'upload' => '',
            'remove_button' => 'Remove',
            'width' => 230,
            'height' => 241,
          ),
        ),
      ),
      'field_button' => array(
        'und' => array(
          0 => array(
            'title' => 'Find out more',
            'url' => 'http://amberroad.com',
            'attributes' => 'a:1:{s:6:"target";i:0;}',
          ),
        ),
      ),
      'field_video_file' => array(
        'und' => array(),
      ),
      'field_panel_pane_type' => array(
        'und' => array(),
      ),
      'log' => '',
      'created' => 1457705360,
      'timestamp' => 1457705360,
      'changed' => 1457705360,
      'uuid' => '63de82a7-2bfd-4585-aee3-0d4ee79c3423',
      'vuuid' => 'f62a83c2-34e4-4cd5-a01e-bde423595efb',
      'uid' => '28',
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
  $pane->uuid = '6ec82532-1c65-4664-bb40-c7b6b005fc9c';
  $display->content['new-6ec82532-1c65-4664-bb40-c7b6b005fc9c'] = $pane;
  $display->panels['row3-right2'][0] = 'new-6ec82532-1c65-4664-bb40-c7b6b005fc9c';
  $pane = new stdClass();
  $pane->pid = 'new-7f4c61d3-490f-48d0-ab2f-12f2e397f46e';
  $pane->panel = 'row4-content';
  $pane->type = 'entity_field';
  $pane->subtype = 'node:field_related_blog_post';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'label' => 'above',
    'formatter' => 'text_default',
    'delta_limit' => 0,
    'delta_offset' => '0',
    'delta_reversed' => FALSE,
    'formatter_settings' => array(),
    'context' => 'panelizer',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 0;
  $pane->locks = array();
  $pane->uuid = '7f4c61d3-490f-48d0-ab2f-12f2e397f46e';
  $display->content['new-7f4c61d3-490f-48d0-ab2f-12f2e397f46e'] = $pane;
  $display->panels['row4-content'][0] = 'new-7f4c61d3-490f-48d0-ab2f-12f2e397f46e';
  $pane = new stdClass();
  $pane->pid = 'new-d33ae7a1-05b3-42d7-b8c3-52fab2ba34c6';
  $pane->panel = 'row4-left';
  $pane->type = 'fieldable_panels_pane';
  $pane->subtype = 'uuid:972e65c9-2765-4f36-a6df-93117a10251b';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'view_mode' => 'full',
    'fieldable_panels_pane' => (object) array(
      'bundle' => 'box',
      'language' => 'und',
      'is_new' => TRUE,
      'title' => 'Background Image',
      'link' => 0,
      'path' => '',
      'reusable' => 1,
      'admin_title' => '',
      'admin_description' => '',
      'category' => 'Reusable Content',
      'vid' => '453',
      'current_vid' => '',
      'revision' => 1,
      'fpid' => '135',
      'field_basic_image_image' => array(
        'und' => array(),
      ),
      'field_button' => array(
        'und' => array(),
      ),
      'field_panel_pane_type' => array(
        'und' => array(),
      ),
      'field_text' => array(
        'und' => array(
          0 => array(
            'summary' => '',
            'value' => '<style type="text/css">body.page-node .ar-internal-1 .container.main-container .row4 .col-md-3 {
background-image: url(\'/sites/all/themes/ar_theme/assets/images/port.png\');
}
</style>
',
            'format' => 'full_html',
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
      'created' => 1461065240,
      'timestamp' => 1461065240,
      'changed' => 1461065240,
      'uuid' => '972e65c9-2765-4f36-a6df-93117a10251b',
      'vuuid' => '77318d9c-d8ed-4027-933a-a1f0ec148229',
      'uid' => '28',
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
  $pane->uuid = 'd33ae7a1-05b3-42d7-b8c3-52fab2ba34c6';
  $display->content['new-d33ae7a1-05b3-42d7-b8c3-52fab2ba34c6'] = $pane;
  $display->panels['row4-left'][0] = 'new-d33ae7a1-05b3-42d7-b8c3-52fab2ba34c6';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = 'new-0f0c5aa5-73b1-49f5-a307-a46627596733';
  $panelizer->display = $display;
  $export['node:solution_area:default'] = $panelizer;

  return $export;
}
