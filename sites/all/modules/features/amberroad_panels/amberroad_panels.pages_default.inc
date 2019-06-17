<?php
/**
 * @file
 * amberroad_panels.pages_default.inc
 */

/**
 * Implements hook_default_page_manager_pages().
 */
function amberroad_panels_default_page_manager_pages() {
  $page = new stdClass();
  $page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'front';
  $page->task = 'page';
  $page->admin_title = 'Front';
  $page->admin_description = '';
  $page->path = 'front';
  $page->access = array();
  $page->menu = array(
    'type' => 'none',
    'title' => '',
    'weight' => '0',
    'name' => 'navigation',
    'parent' => array(
      'type' => 'none',
      'title' => '',
      'weight' => 0,
      'name' => 'navigation',
    ),
  );
  $page->arguments = array();
  $page->conf = array();
  $page->default_handlers = array();
  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'page_front__panel_context_9daaab9c-8b4c-4432-8e0e-9a390afd0ad2';
  $handler->task = 'page';
  $handler->subtask = 'front';
  $handler->handler = 'panel_context';
  $handler->weight = 0;
  $handler->conf = array(
    'title' => 'Landing page',
    'no_blocks' => FALSE,
    'pipeline' => 'ipe',
    'body_classes_to_remove' => '',
    'body_classes_to_add' => '',
    'css_id' => '',
    'css' => '',
    'contexts' => array(),
    'relationships' => array(),
    'name' => '',
  );
  $display = new panels_display();
  $display->layout = 'easydisplay_sutro_double';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'headerfull' => NULL,
      'header' => NULL,
      'column1' => NULL,
      'column2' => NULL,
      'middlefull' => NULL,
      'middle' => NULL,
      'secondcolumn1' => NULL,
      'secondcolumn2' => NULL,
      'footerfull' => NULL,
      'footer' => NULL,
      'section1_header' => NULL,
      'section1_3cols1.1' => NULL,
      'section1_3cols1.2' => NULL,
      'section1_3cols1.3' => NULL,
      'section1_3cols1' => NULL,
      'section1_3cols2' => NULL,
      'section1_3cols3' => NULL,
      'section1_2cols1' => NULL,
      'section1_2cols2' => NULL,
      'section1_footer' => NULL,
      'section2' => NULL,
      'section3_header' => NULL,
      'section3_2cols1' => NULL,
      'section3_2cols2' => NULL,
      'section3_3cols1' => NULL,
      'section3_3cols2' => NULL,
      'section3_3cols3' => NULL,
      'section3_footer' => NULL,
      'section4' => NULL,
      'section5_2cols1' => NULL,
      'section5_2cols2' => NULL,
      'section1_3cols2.1' => NULL,
      'section1_3cols2.2' => NULL,
      'section1_3cols2.3' => NULL,
      'section1_3cols1_1' => NULL,
      'section1_3cols1_2' => NULL,
      'section1_3cols1_3' => NULL,
      'section1_3cols2_1' => NULL,
      'section1_3cols2_2' => NULL,
      'section1_3cols2_3' => NULL,
      'header_top' => NULL,
      'section1_main' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = 'Front';
  $display->uuid = '053c1e37-3ab0-45d3-8123-d39535fcd315';
  $display->content = array();
  $display->panels = array();
  $pane = new stdClass();
  $pane->pid = 'new-ea883018-6711-47a6-81d8-67ab8a0cb81e';
  $pane->panel = 'header';
  $pane->type = 'block';
  $pane->subtype = 'revslider-1';
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
  $pane->uuid = 'ea883018-6711-47a6-81d8-67ab8a0cb81e';
  $display->content['new-ea883018-6711-47a6-81d8-67ab8a0cb81e'] = $pane;
  $display->panels['header'][0] = 'new-ea883018-6711-47a6-81d8-67ab8a0cb81e';
  $pane = new stdClass();
  $pane->pid = 'new-e0219017-775d-4f30-a3c1-28f3581652c9';
  $pane->panel = 'section1_3cols1_1';
  $pane->type = 'fieldable_panels_pane';
  $pane->subtype = 'current:3';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'view_mode' => 'logo_text_v',
    'fieldable_panels_pane' => (object) array(
      'timestamp' => 1460210643,
      'uid' => '18',
      'title' => 'Collaborate',
      'log' => '',
      'vuuid' => 'aeaa9398-4468-484a-b08d-7433fc4427bc',
      'fpid' => '3',
      'bundle' => 'box',
      'link' => 0,
      'path' => '',
      'reusable' => 1,
      'admin_title' => '',
      'admin_description' => '',
      'category' => 'Reusable Content',
      'view_access' => NULL,
      'edit_access' => NULL,
      'created' => '1457684425',
      'changed' => 1460210643,
      'uuid' => '0f191ede-2962-4063-903a-cea406c72972',
      'language' => '',
      'current_vid' => '245',
      'field_basic_image_image' => array(
        'und' => array(
          0 => array(
            'fid' => '1649',
            'display' => '1',
            'description' => '',
            'attach_button' => 'Attach',
            'upload' => '',
            'remove_button' => 'Remove',
            'width' => 263,
            'height' => 142,
          ),
        ),
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
            'value' => '<p class="rtecenter"><span style="font-size:18px;">Improve supplier performance and accelerate time-to-market with consistent and timely access to supplier information.</span></p>

<p class="rtecenter"><span style="font-size:18px;"><a href="http://solutions/vendor_management.shtml" target="_blank">Learn More »</a></span></p>
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
      'rdf_mapping' => array(),
      'revision' => 1,
      'is_new' => FALSE,
      'original' => (object) array(
        'vid' => '245',
        'timestamp' => '1460210612',
        'uid' => '18',
        'title' => 'Collaborate',
        'log' => '',
        'vuuid' => '28187b9c-3a2e-4554-bf8e-81171519ea33',
        'fpid' => '3',
        'bundle' => 'box',
        'link' => '0',
        'path' => '',
        'reusable' => '1',
        'admin_title' => '',
        'admin_description' => '',
        'category' => 'Reusable Content',
        'view_access' => NULL,
        'edit_access' => NULL,
        'created' => '1457684425',
        'changed' => '1460210612',
        'uuid' => '0f191ede-2962-4063-903a-cea406c72972',
        'language' => '',
        'current_vid' => '245',
        'field_basic_image_image' => array(
          'und' => array(
            0 => array(
              'fid' => '1649',
              'uid' => '28',
              'filename' => 'collaborate-icon.png',
              'uri' => 'public://collaborate-icon_0.png',
              'filemime' => 'image/png',
              'filesize' => '4694',
              'status' => '1',
              'timestamp' => '1458645165',
              'type' => 'image',
              'uuid' => '95683076-5315-4c4c-9c2b-d34561b277a1',
              'field_file_image_alt_text' => array(),
              'field_file_image_title_text' => array(),
              'metatags' => array(),
              'rdf_mapping' => array(),
              'metadata' => array(
                'height' => 142,
                'width' => 263,
              ),
              'alt' => NULL,
              'title' => NULL,
              'height' => '142',
              'width' => '263',
            ),
          ),
        ),
        'field_button' => array(),
        'field_panel_pane_type' => array(),
        'field_text' => array(
          'und' => array(
            0 => array(
              'value' => '<p class="rtecenter"><span style="font-size:18px;">Improve supplier performance and accelerate time-to-market with consistent and timely access to supplier information.</span></p>

<p class="rtecenter"><span style="font-size:18px;"><a href="http://solutions/vendor_management.shtml" target="_blank">Download Now »</a></span></p>
',
              'summary' => '',
              'format' => 'full_html',
              'safe_value' => '<p class="rtecenter"><span style="font-size:18px;">Improve supplier performance and accelerate time-to-market with consistent and timely access to supplier information.</span></p>
<p class="rtecenter"><span style="font-size:18px;"><a href="http://solutions/vendor_management.shtml" target="_blank">Download Now »</a></span></p>
',
              'safe_summary' => '',
            ),
          ),
        ),
        'field_video' => array(),
        'field_video_width' => array(),
        'rdf_mapping' => array(),
      ),
      'old_vid' => '245',
      'vid' => '246',
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
  $pane->uuid = 'e0219017-775d-4f30-a3c1-28f3581652c9';
  $display->content['new-e0219017-775d-4f30-a3c1-28f3581652c9'] = $pane;
  $display->panels['section1_3cols1_1'][0] = 'new-e0219017-775d-4f30-a3c1-28f3581652c9';
  $pane = new stdClass();
  $pane->pid = 'new-f107b27e-5739-41a4-8144-3bd00a1a1fa6';
  $pane->panel = 'section1_3cols1_2';
  $pane->type = 'fieldable_panels_pane';
  $pane->subtype = 'uuid:c438ed68-3176-43e5-bff7-efdc60bb1289';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'view_mode' => 'logo_text_v',
    'fieldable_panels_pane' => (object) array(
      'timestamp' => 1460210680,
      'uid' => '18',
      'title' => 'Connect',
      'log' => '',
      'vuuid' => '8c0f8386-5f55-4d07-aa96-fb9575635ace',
      'fpid' => '23',
      'bundle' => 'box',
      'link' => 0,
      'path' => '',
      'reusable' => 0,
      'admin_title' => '',
      'admin_description' => '',
      'category' => 'Reusable Content',
      'view_access' => NULL,
      'edit_access' => NULL,
      'created' => '1457690288',
      'changed' => 1460210680,
      'uuid' => 'c438ed68-3176-43e5-bff7-efdc60bb1289',
      'language' => 'und',
      'current_vid' => '30',
      'field_basic_image_image' => array(
        'und' => array(
          0 => array(
            'fid' => '1650',
            'display' => '1',
            'description' => '',
            'attach_button' => 'Attach',
            'upload' => '',
            'remove_button' => 'Remove',
            'width' => 263,
            'height' => 142,
          ),
        ),
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
            'value' => '<p class="rtecenter"><span style="font-size:18px;">Enable supply chain partners to  share information and receive  alerts on milestones critical to  the timely delivery of goods.</span></p>

<p class="rtecenter"><span style="font-size:18px;"><a href="/solutions/integrated-service-provider-network.shtml" target="_blank">Learn More »</a></span></p>
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
      'rdf_mapping' => array(),
      'revision' => 1,
      'is_new' => FALSE,
      'original' => (object) array(
        'vid' => '30',
        'timestamp' => '1458645198',
        'uid' => '28',
        'title' => 'Connect',
        'log' => '',
        'vuuid' => '2cb9f02c-e43a-4587-992f-95b6fa3fb330',
        'fpid' => '23',
        'bundle' => 'box',
        'link' => '0',
        'path' => '',
        'reusable' => '0',
        'admin_title' => '',
        'admin_description' => '',
        'category' => 'Reusable Content',
        'view_access' => NULL,
        'edit_access' => NULL,
        'created' => '1457690288',
        'changed' => '1458645198',
        'uuid' => 'c438ed68-3176-43e5-bff7-efdc60bb1289',
        'language' => 'und',
        'current_vid' => '30',
        'field_basic_image_image' => array(
          'und' => array(
            0 => array(
              'fid' => '1650',
              'uid' => '28',
              'filename' => 'connect-icon.png',
              'uri' => 'public://connect-icon_0.png',
              'filemime' => 'image/png',
              'filesize' => '5024',
              'status' => '1',
              'timestamp' => '1458645195',
              'type' => 'image',
              'uuid' => '759341bf-159c-48f6-a6f3-370b454b6d83',
              'field_file_image_alt_text' => array(),
              'field_file_image_title_text' => array(),
              'metatags' => array(),
              'rdf_mapping' => array(),
              'metadata' => array(
                'height' => 142,
                'width' => 263,
              ),
              'alt' => NULL,
              'title' => NULL,
              'height' => '142',
              'width' => '263',
            ),
          ),
        ),
        'field_button' => array(
          'und' => array(
            0 => array(
              'url' => '/solutions/integrated-service-provider-network.shtml',
              'title' => 'Learn More',
              'attributes' => array(
                'target' => 0,
              ),
            ),
          ),
        ),
        'field_panel_pane_type' => array(),
        'field_text' => array(
          'und' => array(
            0 => array(
              'value' => '<p>Enable supply chain partners to  share information and receive  alerts on milestones critical to  the timely delivery of goods.</p>
',
              'summary' => '',
              'format' => 'full_html',
              'safe_value' => '<p>Enable supply chain partners to  share information and receive  alerts on milestones critical to  the timely delivery of goods.</p>
',
              'safe_summary' => '',
            ),
          ),
        ),
        'field_video' => array(),
        'field_video_width' => array(),
        'rdf_mapping' => array(),
      ),
      'old_vid' => '30',
      'vid' => '247',
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
  $pane->uuid = 'f107b27e-5739-41a4-8144-3bd00a1a1fa6';
  $display->content['new-f107b27e-5739-41a4-8144-3bd00a1a1fa6'] = $pane;
  $display->panels['section1_3cols1_2'][0] = 'new-f107b27e-5739-41a4-8144-3bd00a1a1fa6';
  $pane = new stdClass();
  $pane->pid = 'new-2cafb135-b44d-41f8-a5fb-7ea090fff7cd';
  $pane->panel = 'section1_3cols1_3';
  $pane->type = 'fieldable_panels_pane';
  $pane->subtype = 'uuid:6670766f-2722-452d-b2b8-00a1ca4cd4b4';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'view_mode' => 'logo_text_v',
    'fieldable_panels_pane' => (object) array(
      'timestamp' => 1460210801,
      'uid' => '18',
      'title' => 'Comply',
      'log' => '',
      'vuuid' => '9e371848-d2fb-4217-8c5f-48e1b8d2084f',
      'fpid' => '13',
      'bundle' => 'box',
      'link' => 0,
      'path' => '',
      'reusable' => 0,
      'admin_title' => '',
      'admin_description' => '',
      'category' => 'Reusable Content',
      'view_access' => NULL,
      'edit_access' => NULL,
      'created' => '1457690564',
      'changed' => 1460210801,
      'uuid' => '6670766f-2722-452d-b2b8-00a1ca4cd4b4',
      'language' => 'und',
      'current_vid' => '248',
      'field_basic_image_image' => array(
        'und' => array(
          0 => array(
            'fid' => '1651',
            'display' => '1',
            'description' => '',
            'attach_button' => 'Attach',
            'upload' => '',
            'remove_button' => 'Remove',
            'width' => 261,
            'height' => 142,
          ),
        ),
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
            'value' => '<p class="rtecenter"><span style="font-size:16px;">Automate import/export processes  to enable goods to flow unimpeded  across international borders while  reducing duties.</span></p>

<p class="rtecenter"><span style="font-size:18px;"><a href="/solutions/importer-security-filing.shtml" target="_blank">Learn More »</a></span></p>
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
      'rdf_mapping' => array(),
      'revision' => 1,
      'is_new' => FALSE,
      'original' => (object) array(
        'vid' => '248',
        'timestamp' => '1460210746',
        'uid' => '18',
        'title' => 'Comply',
        'log' => '',
        'vuuid' => '5e420eb0-74c6-4fee-96b8-6df9ddcb369d',
        'fpid' => '13',
        'bundle' => 'box',
        'link' => '0',
        'path' => '',
        'reusable' => '0',
        'admin_title' => '',
        'admin_description' => '',
        'category' => 'Reusable Content',
        'view_access' => NULL,
        'edit_access' => NULL,
        'created' => '1457690564',
        'changed' => '1460210746',
        'uuid' => '6670766f-2722-452d-b2b8-00a1ca4cd4b4',
        'language' => 'und',
        'current_vid' => '248',
        'field_basic_image_image' => array(
          'und' => array(
            0 => array(
              'fid' => '1651',
              'uid' => '28',
              'filename' => 'comply-icon.png',
              'uri' => 'public://comply-icon_0.png',
              'filemime' => 'image/png',
              'filesize' => '2420',
              'status' => '1',
              'timestamp' => '1458645226',
              'type' => 'image',
              'uuid' => '0d6e1074-205e-44fb-9dee-d55091c0ac82',
              'field_file_image_alt_text' => array(),
              'field_file_image_title_text' => array(),
              'metatags' => array(),
              'rdf_mapping' => array(),
              'metadata' => array(
                'height' => 142,
                'width' => 261,
              ),
              'alt' => NULL,
              'title' => NULL,
              'height' => '142',
              'width' => '261',
            ),
          ),
        ),
        'field_button' => array(),
        'field_panel_pane_type' => array(),
        'field_text' => array(
          'und' => array(
            0 => array(
              'value' => '<p class="rtecenter"><span style="font-size:18px;">Automate import/export processes  to enable goods to flow unimpeded  across international borders while re ducing duties.</span></p>

<p class="rtecenter"><span style="font-size:18px;"><a href="/solutions/importer-security-filing.shtml" target="_blank">Learn More »</a></span></p>
',
              'summary' => '',
              'format' => 'full_html',
              'safe_value' => '<p class="rtecenter"><span style="font-size:18px;">Automate import/export processes  to enable goods to flow unimpeded  across international borders while re ducing duties.</span></p>
<p class="rtecenter"><span style="font-size:18px;"><a href="/solutions/importer-security-filing.shtml" target="_blank">Learn More »</a></span></p>
',
              'safe_summary' => '',
            ),
          ),
        ),
        'field_video' => array(),
        'field_video_width' => array(),
        'rdf_mapping' => array(),
      ),
      'old_vid' => '248',
      'vid' => '249',
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
  $pane->uuid = '2cafb135-b44d-41f8-a5fb-7ea090fff7cd';
  $display->content['new-2cafb135-b44d-41f8-a5fb-7ea090fff7cd'] = $pane;
  $display->panels['section1_3cols1_3'][0] = 'new-2cafb135-b44d-41f8-a5fb-7ea090fff7cd';
  $pane = new stdClass();
  $pane->pid = 'new-4c17126a-1adb-4e34-9de6-7fb0ac70748a';
  $pane->panel = 'section1_3cols2_1';
  $pane->type = 'fieldable_panels_pane';
  $pane->subtype = 'current:14';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'view_mode' => 'image_button',
    'fieldable_panels_pane' => (object) array(
      'timestamp' => 1477503786,
      'uid' => '18',
      'title' => 'Featured',
      'log' => '',
      'vuuid' => '9d6963cd-501e-457d-bb2d-f392b027ba39',
      'fpid' => '14',
      'bundle' => 'box',
      'link' => 0,
      'path' => '',
      'reusable' => '0',
      'admin_title' => '',
      'admin_description' => '',
      'category' => 'Reusable Content',
      'view_access' => NULL,
      'edit_access' => NULL,
      'created' => '1454203934',
      'changed' => 1477503786,
      'uuid' => '68eba7be-87d4-4fbe-9b74-c484dfa328a1',
      'language' => 'und',
      'current_vid' => '2928',
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
            'value' => '<p class="rtecenter"><span style="font-size:24px;"><span style="color: rgb(255, 140, 0);">eBook</span></span><br />
<span style="font-size:22px;"><span class="lpContentsItem richTextSpan">ACE: How to Meet the 2016 Single Window Mandate Now</span></span></p>

<p class="rtecenter"><span style="font-size:18px;"><span style="font-size:20px;"><img alt="Download our Analyst Report: The New GTM: Connecting Upstream Decisions to Improve Downstream Execution" height="85" src="/sites/default/files/ace-ebook.jpg" width="203" /></span></span></p>

<p class="rtecenter"><span style="font-size:18px;"><a href="http://info.amberroad.com/rl-eBook-AceSingleWindow_Landingpage.html" target="_blank">Download Now »</a></span></p>
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
      'rdf_mapping' => array(),
      'revision' => 1,
      'is_new' => FALSE,
      'original' => (object) array(
        'vid' => '2928',
        'timestamp' => '1477503757',
        'uid' => '18',
        'title' => 'Featured',
        'log' => '',
        'vuuid' => 'ac8fa390-b9f0-4034-8d27-7cc3bf492097',
        'fpid' => '14',
        'bundle' => 'box',
        'link' => '0',
        'path' => '',
        'reusable' => '0',
        'admin_title' => '',
        'admin_description' => '',
        'category' => 'Reusable Content',
        'view_access' => NULL,
        'edit_access' => NULL,
        'created' => '1454203934',
        'changed' => '1477503757',
        'uuid' => '68eba7be-87d4-4fbe-9b74-c484dfa328a1',
        'language' => 'und',
        'current_vid' => '2928',
        'field_basic_image_image' => array(),
        'field_button' => array(),
        'field_text' => array(
          'und' => array(
            0 => array(
              'value' => '<p class="rtecenter"><span style="font-size:24px;"><span style="color: rgb(255, 140, 0);">eBook</span></span><br />
<span style="font-size:22px;"><span class="lpContentsItem richTextSpan">ACE: How to Meet the 2016 Single Window Mandate Now</span></span></p>

<p class="rtecenter"><span style="font-size:18px;"><span style="font-size:20px;"><img alt="Download our Analyst Report: The New GTM: Connecting Upstream Decisions to Improve Downstream Execution" height="96" src="/sites/default/files/ace-ebook.jpg" width="230" /></span></span></p>

<p class="rtecenter"><span style="font-size:18px;"><a href="http://info.amberroad.com/rl-eBook-AceSingleWindow_Landingpage.html" target="_blank">Download Now »</a></span></p>
',
              'summary' => '',
              'format' => 'full_html',
              'safe_value' => '<p class="rtecenter"><span style="font-size:24px;"><span style="color: rgb(255, 140, 0);">eBook</span></span><br /><span style="font-size:22px;"><span class="lpContentsItem richTextSpan">ACE: How to Meet the 2016 Single Window Mandate Now</span></span></p>
<p class="rtecenter"><span style="font-size:18px;"><span style="font-size:20px;"><img alt="Download our Analyst Report: The New GTM: Connecting Upstream Decisions to Improve Downstream Execution" height="96" src="/sites/default/files/ace-ebook.jpg" width="230" /></span></span></p>
<p class="rtecenter"><span style="font-size:18px;"><a href="http://info.amberroad.com/rl-eBook-AceSingleWindow_Landingpage.html" target="_blank">Download Now »</a></span></p>
',
              'safe_summary' => '',
            ),
          ),
        ),
        'field_video' => array(),
        'field_video_width' => array(),
        'rdf_mapping' => array(),
      ),
      'old_vid' => '2928',
      'vid' => '2929',
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
  $pane->uuid = '4c17126a-1adb-4e34-9de6-7fb0ac70748a';
  $display->content['new-4c17126a-1adb-4e34-9de6-7fb0ac70748a'] = $pane;
  $display->panels['section1_3cols2_1'][0] = 'new-4c17126a-1adb-4e34-9de6-7fb0ac70748a';
  $pane = new stdClass();
  $pane->pid = 'new-bb4518b9-6303-4ef8-8a82-2476a313860f';
  $pane->panel = 'section1_3cols2_2';
  $pane->type = 'fieldable_panels_pane';
  $pane->subtype = 'current:24';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'view_mode' => 'image_button',
    'fieldable_panels_pane' => (object) array(
      'timestamp' => 1472659408,
      'uid' => '18',
      'title' => 'New Webinar',
      'log' => '',
      'vuuid' => 'b64349fb-f58a-4d62-b0aa-55efc4115eef',
      'fpid' => '24',
      'bundle' => 'box',
      'link' => 0,
      'path' => '',
      'reusable' => '0',
      'admin_title' => '',
      'admin_description' => '',
      'category' => 'Reusable Content',
      'view_access' => NULL,
      'edit_access' => NULL,
      'created' => '1454203995',
      'changed' => 1472659408,
      'uuid' => 'c9f26cd5-977f-4e90-aea4-f16287a00d37',
      'language' => 'und',
      'current_vid' => '2772',
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
            'value' => '<p class="rtecenter"><span style="font-size:24px;"><span name="title">Transloading at Abercrombie:</span></span><br />
<span style="font-size:16px;"><span name="title">The Business Drivers, Lessons Learned, and Realized Rewards</span></span><img alt="" src="/sites/default/files/scd-285.jpg" style="width: 285px; height: 75px;" /><br />
<span style="font-size: 14px;">September 08, 2016 | 1PM CDT</span></p>

<p class="rtecenter"><span style="font-size:18px;"><a href="https://event.on24.com/eventRegistration/EventLobbyServlet?target=reg20.jsp&amp;referrer=&amp;eventid=1120136&amp;sessionid=1&amp;key=D0051D861FAFD696D2668CBEC972EC7F&amp;regTag=&amp;sourcepage=register">Register Now »</a></span></p>
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
      'rdf_mapping' => array(),
      'revision' => 1,
      'is_new' => FALSE,
      'original' => (object) array(
        'vid' => '2772',
        'timestamp' => '1472659391',
        'uid' => '18',
        'title' => 'New Webinar',
        'log' => '',
        'vuuid' => '39bf2c24-b62b-4127-8275-07348198ffdb',
        'fpid' => '24',
        'bundle' => 'box',
        'link' => '0',
        'path' => '',
        'reusable' => '0',
        'admin_title' => '',
        'admin_description' => '',
        'category' => 'Reusable Content',
        'view_access' => NULL,
        'edit_access' => NULL,
        'created' => '1454203995',
        'changed' => '1472659391',
        'uuid' => 'c9f26cd5-977f-4e90-aea4-f16287a00d37',
        'language' => 'und',
        'current_vid' => '2772',
        'field_basic_image_image' => array(),
        'field_button' => array(),
        'field_text' => array(
          'und' => array(
            0 => array(
              'value' => '<p class="rtecenter"><span style="font-size:24px;"><span name="title">Transloading at Abercrombie:</span></span><br />
<span style="font-size:16px;"><span name="title">The Business Drivers, Lessons Learned, and Realized Rewards</span></span><img alt="" src="/sites/default/files/scd-285.jpg" style="width: 285px; height: 75px;" /><br />
<span style="font-size: 14px;">Thursday, September 08, 2016 | 1PM CDT</span></p>

<p class="rtecenter"><span style="font-size:18px;"><a href="https://event.on24.com/eventRegistration/EventLobbyServlet?target=reg20.jsp&amp;referrer=&amp;eventid=1120136&amp;sessionid=1&amp;key=D0051D861FAFD696D2668CBEC972EC7F&amp;regTag=&amp;sourcepage=register">Register Now »</a></span></p>
',
              'summary' => '',
              'format' => 'full_html',
              'safe_value' => '<p class="rtecenter"><span style="font-size:24px;"><span name="title">Transloading at Abercrombie:</span></span><br /><span style="font-size:16px;"><span name="title">The Business Drivers, Lessons Learned, and Realized Rewards</span></span><img alt="" src="/sites/default/files/scd-285.jpg" style="width: 285px; height: 75px;" /><br /><span style="font-size: 14px;">Thursday, September 08, 2016 | 1PM CDT</span></p>
<p class="rtecenter"><span style="font-size:18px;"><a href="https://event.on24.com/eventRegistration/EventLobbyServlet?target=reg20.jsp&amp;referrer=&amp;eventid=1120136&amp;sessionid=1&amp;key=D0051D861FAFD696D2668CBEC972EC7F&amp;regTag=&amp;sourcepage=register">Register Now »</a></span></p>
',
              'safe_summary' => '',
            ),
          ),
        ),
        'field_video' => array(),
        'field_video_width' => array(),
        'rdf_mapping' => array(),
      ),
      'old_vid' => '2772',
      'vid' => '2773',
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
  $pane->uuid = 'bb4518b9-6303-4ef8-8a82-2476a313860f';
  $display->content['new-bb4518b9-6303-4ef8-8a82-2476a313860f'] = $pane;
  $display->panels['section1_3cols2_2'][0] = 'new-bb4518b9-6303-4ef8-8a82-2476a313860f';
  $pane = new stdClass();
  $pane->pid = 'new-390f7076-784c-40b8-bae4-aeaf4a1e856f';
  $pane->panel = 'section1_3cols2_3';
  $pane->type = 'fieldable_panels_pane';
  $pane->subtype = 'current:15';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'view_mode' => 'image_button',
    'fieldable_panels_pane' => (object) array(
      'timestamp' => 1472659435,
      'uid' => '18',
      'title' => 'Upcoming Events',
      'log' => '',
      'vuuid' => 'f411c7cc-2b39-4562-a39a-62398dead828',
      'fpid' => '15',
      'bundle' => 'box',
      'link' => 0,
      'path' => '',
      'reusable' => '0',
      'admin_title' => '',
      'admin_description' => '',
      'category' => 'Reusable Content',
      'view_access' => NULL,
      'edit_access' => NULL,
      'created' => '1454204073',
      'changed' => 1472659435,
      'uuid' => '6a1a28a4-4a29-4f36-8ac8-1d0f2b87d000',
      'language' => 'und',
      'current_vid' => '2771',
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
            'value' => '<p class="rtecenter"><span style="font-size:24px;">CSCMP\'s 2016 Annual Conference</span></p>

<p class="rtecenter"><span style="font-size:22px;"><img alt="Learn more about the FDRA Footwear Forum" height="108" src="/sites/default/files/255x199-ac2016.png" width="135" /></span></p>

<p class="rtecenter"><span style="font-size:14px;">Kissimmee, FL | September 25-28, 2016</span></p>

<p class="rtecenter"><a href="https://cscmp.org/annual-conference" target="_blank"><span style="font-size:18px;">Learn More »</span></a></p>
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
      'rdf_mapping' => array(),
      'revision' => 1,
      'is_new' => FALSE,
      'original' => (object) array(
        'vid' => '2771',
        'timestamp' => '1472659373',
        'uid' => '18',
        'title' => 'Upcoming Events',
        'log' => '',
        'vuuid' => '87771c38-f3b6-4226-89cd-b8d19be6930f',
        'fpid' => '15',
        'bundle' => 'box',
        'link' => '0',
        'path' => '',
        'reusable' => '0',
        'admin_title' => '',
        'admin_description' => '',
        'category' => 'Reusable Content',
        'view_access' => NULL,
        'edit_access' => NULL,
        'created' => '1454204073',
        'changed' => '1472659373',
        'uuid' => '6a1a28a4-4a29-4f36-8ac8-1d0f2b87d000',
        'language' => 'und',
        'current_vid' => '2771',
        'field_basic_image_image' => array(),
        'field_button' => array(),
        'field_text' => array(
          'und' => array(
            0 => array(
              'value' => '<p class="rtecenter"><span style="font-size:24px;">CSCMP\'s 2016 Annual Conference</span></p>

<p class="rtecenter"><span style="font-size:22px;"><img alt="Learn more about the FDRA Footwear Forum" height="118" src="/sites/default/files/255x199-ac2016.png" width="148" /></span></p>

<p class="rtecenter"><span style="font-size:14px;">Kissimmee, FL | September 25-28, 2016</span></p>

<p class="rtecenter"><a href="https://cscmp.org/annual-conference" target="_blank"><span style="font-size:18px;">Learn More »</span></a></p>
',
              'summary' => '',
              'format' => 'full_html',
              'safe_value' => '<p class="rtecenter"><span style="font-size:24px;">CSCMP\'s 2016 Annual Conference</span></p>
<p class="rtecenter"><span style="font-size:22px;"><img alt="Learn more about the FDRA Footwear Forum" height="118" src="/sites/default/files/255x199-ac2016.png" width="148" /></span></p>
<p class="rtecenter"><span style="font-size:14px;">Kissimmee, FL | September 25-28, 2016</span></p>
<p class="rtecenter"><a href="https://cscmp.org/annual-conference" target="_blank"><span style="font-size:18px;">Learn More »</span></a></p>
',
              'safe_summary' => '',
            ),
          ),
        ),
        'field_video' => array(),
        'field_video_width' => array(),
        'rdf_mapping' => array(),
      ),
      'old_vid' => '2771',
      'vid' => '2774',
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
  $pane->uuid = '390f7076-784c-40b8-bae4-aeaf4a1e856f';
  $display->content['new-390f7076-784c-40b8-bae4-aeaf4a1e856f'] = $pane;
  $display->panels['section1_3cols2_3'][0] = 'new-390f7076-784c-40b8-bae4-aeaf4a1e856f';
  $pane = new stdClass();
  $pane->pid = 'new-c780d9c8-b68f-4b03-bd34-94a91adc4c02';
  $pane->panel = 'section1_header';
  $pane->type = 'fieldable_panels_pane';
  $pane->subtype = 'uuid:3ba893b9-07b7-45f2-b4f1-efa4945e764b';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'view_mode' => 'full',
    'fieldable_panels_pane' => (object) array(
      'bundle' => 'text',
      'language' => 'und',
      'is_new' => TRUE,
      'title' => 'THE WORLD LEADER IN CLOUD-BASED GLOBAL TRADE MANAGEMENT',
      'link' => 0,
      'path' => '',
      'reusable' => 0,
      'admin_title' => '',
      'admin_description' => '',
      'category' => 'Reusable Content',
      'vid' => '87',
      'current_vid' => '',
      'revision' => 1,
      'fpid' => '26',
      'field_basic_text_text' => array(
        'und' => array(),
      ),
      'log' => '',
      'created' => 1454511290,
      'timestamp' => 1454511290,
      'changed' => 1454511290,
      'uuid' => '3ba893b9-07b7-45f2-b4f1-efa4945e764b',
      'vuuid' => '25717e7d-d7a5-4fca-9fff-9f45aa2c5594',
      'uid' => '28',
    ),
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array(
    'css_id' => '',
    'css_class' => 'container',
  );
  $pane->extras = array();
  $pane->position = 0;
  $pane->locks = array();
  $pane->uuid = 'c780d9c8-b68f-4b03-bd34-94a91adc4c02';
  $display->content['new-c780d9c8-b68f-4b03-bd34-94a91adc4c02'] = $pane;
  $display->panels['section1_header'][0] = 'new-c780d9c8-b68f-4b03-bd34-94a91adc4c02';
  $pane = new stdClass();
  $pane->pid = 'new-a7787f5c-45c7-4d79-8a86-a6367c362e38';
  $pane->panel = 'section1_main';
  $pane->type = 'fieldable_panels_pane';
  $pane->subtype = 'current:508';
  $pane->shown = TRUE;
  $pane->access = array(
    'plugins' => array(),
  );
  $pane->configuration = array(
    'view_mode' => 'full',
    'fieldable_panels_pane' => (object) array(
      'timestamp' => 1462655690,
      'uid' => '18',
      'title' => '',
      'log' => '',
      'vuuid' => 'daa56726-5f25-4300-a7ad-8d185aaf00b7',
      'fpid' => '508',
      'bundle' => 'box',
      'link' => 0,
      'path' => '',
      'reusable' => 0,
      'admin_title' => '',
      'admin_description' => '',
      'category' => 'Reusable Content',
      'view_access' => NULL,
      'edit_access' => NULL,
      'created' => '1462444164',
      'changed' => 1462655690,
      'uuid' => '282fe766-1423-481e-813e-fa7363c90cb6',
      'language' => 'und',
      'current_vid' => '2064',
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
            'value' => '<div class="savings-compliance">
<div class="inner-container container-full">
<div class="row">
<div class="col-lg-offset-4 col-lg-8 col-md-offset-2 col-md-10 col-sm-12">&nbsp;</div>
</div>

<div class="col-lg-offset-4 col-lg-4 col-md-offset-2  col-md-5 col-sm-6 col-xs-12">
<ul>
</ul>
</div>
</div>
</div>
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
      'rdf_mapping' => array(),
      'revision' => 1,
      'is_new' => FALSE,
      'original' => (object) array(
        'vid' => '2064',
        'timestamp' => '1462655640',
        'uid' => '18',
        'title' => '',
        'log' => '',
        'vuuid' => '606187f7-1955-46c6-a416-4844a9a978ff',
        'fpid' => '508',
        'bundle' => 'box',
        'link' => '0',
        'path' => '',
        'reusable' => '0',
        'admin_title' => '',
        'admin_description' => '',
        'category' => 'Reusable Content',
        'view_access' => NULL,
        'edit_access' => NULL,
        'created' => '1462444164',
        'changed' => '1462655640',
        'uuid' => '282fe766-1423-481e-813e-fa7363c90cb6',
        'language' => 'und',
        'current_vid' => '2064',
        'field_basic_image_image' => array(),
        'field_button' => array(),
        'field_text' => array(
          'und' => array(
            0 => array(
              'value' => '<div class="savings-compliance">
<div class="inner-container container-full">
<div class="row">
<div class="col-lg-offset-4 col-lg-8 col-md-offset-2 col-md-10 col-sm-12">&nbsp;<img alt="" src="/sites/default/files/hero-roi_10.png" style="height: 100%; width: 100%;" /></div>
</div>

<div class="col-lg-offset-4 col-lg-4 col-md-offset-2  col-md-5 col-sm-6 col-xs-12">
<ul>
</ul>
</div>
</div>
</div>
',
              'summary' => '',
              'format' => 'full_html',
              'safe_value' => '<div class="savings-compliance">
<div class="inner-container container-full">
<div class="row">
<div class="col-lg-offset-4 col-lg-8 col-md-offset-2 col-md-10 col-sm-12"> <img alt="" src="/sites/default/files/hero-roi_10.png" style="height: 100%; width: 100%;" /></div>
</div>
<div class="col-lg-offset-4 col-lg-4 col-md-offset-2  col-md-5 col-sm-6 col-xs-12">
<ul></ul></div>
</div>
</div>
',
              'safe_summary' => '',
            ),
          ),
        ),
        'field_video' => array(),
        'field_video_width' => array(),
        'rdf_mapping' => array(),
      ),
      'old_vid' => '2064',
      'vid' => '2065',
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
  $pane->uuid = 'a7787f5c-45c7-4d79-8a86-a6367c362e38';
  $display->content['new-a7787f5c-45c7-4d79-8a86-a6367c362e38'] = $pane;
  $display->panels['section1_main'][0] = 'new-a7787f5c-45c7-4d79-8a86-a6367c362e38';
  $pane = new stdClass();
  $pane->pid = 'new-f15a0af7-a72c-4372-9f2d-24aef2856279';
  $pane->panel = 'section3_2cols1';
  $pane->type = 'fieldable_panels_pane';
  $pane->subtype = 'uuid:b686baaf-f02c-4d70-b3fc-7ed3ceaa099f';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'view_mode' => 'video_vertical',
    'fieldable_panels_pane' => (object) array(
      'timestamp' => 1454532808,
      'uid' => '28',
      'title' => 'Tyco Security: Customer Testimonial',
      'log' => '',
      'vuuid' => '9faca6ba-cf93-4b43-9525-ffca3cc15aa0',
      'fpid' => '14',
      'bundle' => 'box',
      'link' => 0,
      'path' => '',
      'reusable' => 1,
      'admin_title' => 'Tyco Security: Customer Testimonial',
      'admin_description' => '',
      'category' => 'Reusable Content',
      'view_access' => NULL,
      'edit_access' => NULL,
      'created' => '1454252636',
      'changed' => 1454532808,
      'uuid' => 'b686baaf-f02c-4d70-b3fc-7ed3ceaa099f',
      'language' => '',
      'current_vid' => '82',
      'field_text' => array(
        'und' => array(
          0 => array(
            'summary' => '',
            'value' => '<p>Kevin Willis, VP Inernation TradeCompliance, Tyco SEcurity discusses how Amber Road\'s global management solutions enable its supply chain to stay optimized.</p>
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
        'und' => array(
          0 => array(
            'fid' => '1470',
            'display' => '1',
            'description' => '',
            'attach_button' => 'Attach',
            'upload' => '',
            'remove_button' => 'Remove',
          ),
        ),
      ),
      'field_panel_pane_type' => array(
        'und' => array(),
      ),
      'rdf_mapping' => array(),
      'revision' => 1,
      'is_new' => FALSE,
      'original' => (object) array(
        'vid' => '82',
        'timestamp' => '1454414835',
        'uid' => '28',
        'title' => 'Tyco Security: Customer Testimonial',
        'log' => '',
        'vuuid' => 'b747d93a-3358-4ef4-ba49-8d20292a7424',
        'fpid' => '14',
        'bundle' => 'box',
        'link' => '0',
        'path' => '',
        'reusable' => '1',
        'admin_title' => '',
        'admin_description' => '',
        'category' => 'Reusable Content',
        'view_access' => NULL,
        'edit_access' => NULL,
        'created' => '1454252636',
        'changed' => '1454414835',
        'uuid' => 'b686baaf-f02c-4d70-b3fc-7ed3ceaa099f',
        'language' => '',
        'current_vid' => '82',
        'field_text' => array(
          'und' => array(
            0 => array(
              'value' => '<p>Kevin Willis, VP Inernation TradeCompliance, Tyco SEcurity discusses how Amber Road\'s global management solutions enable its supply chain to stay optimized.</p>
',
              'summary' => '',
              'format' => 'full_html',
              'safe_value' => '<p>Kevin Willis, VP Inernation TradeCompliance, Tyco SEcurity discusses how Amber Road\'s global management solutions enable its supply chain to stay optimized.</p>
',
              'safe_summary' => '',
            ),
          ),
        ),
        'field_basic_image_image' => array(),
        'field_button' => array(),
        'field_video_file' => array(
          'und' => array(
            0 => array(
              'fid' => '1461',
              'uid' => '28',
              'filename' => 'People Are Insane 2014 (Incredible Edition)',
              'uri' => 'youtube://v/U05REo2cd2M',
              'filemime' => 'video/youtube',
              'filesize' => '0',
              'status' => '1',
              'timestamp' => '1454252678',
              'type' => 'video',
              'uuid' => '9eb4f863-c712-4c44-89dc-aacffbc19d5b',
              'metatags' => array(),
              'rdf_mapping' => array(),
              'metadata' => array(),
              'alt' => '',
              'title' => '',
              'display' => '1',
              'description' => '',
            ),
          ),
        ),
        'field_panel_pane_type' => array(),
        'rdf_mapping' => array(),
      ),
      'old_vid' => '82',
      'vid' => '89',
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
  $pane->uuid = 'f15a0af7-a72c-4372-9f2d-24aef2856279';
  $display->content['new-f15a0af7-a72c-4372-9f2d-24aef2856279'] = $pane;
  $display->panels['section3_2cols1'][0] = 'new-f15a0af7-a72c-4372-9f2d-24aef2856279';
  $pane = new stdClass();
  $pane->pid = 'new-0d29f060-0ac3-410e-86af-8e45bc3aa078';
  $pane->panel = 'section3_2cols2';
  $pane->type = 'fieldable_panels_pane';
  $pane->subtype = 'current:683';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'view_mode' => 'video_vertical',
    'fieldable_panels_pane' => (object) array(
      'timestamp' => 1473415111,
      'uid' => 0,
      'title' => '',
      'log' => '',
      'vuuid' => '21ccaf99-6ad8-4460-95ef-97aac0216e53',
      'fpid' => '683',
      'bundle' => 'box',
      'link' => 0,
      'path' => '',
      'reusable' => '0',
      'admin_title' => '',
      'admin_description' => '',
      'category' => 'Reusable Content',
      'view_access' => NULL,
      'edit_access' => NULL,
      'created' => '1473355823',
      'changed' => 1473415111,
      'uuid' => '1210b6f6-991c-4dfc-863b-258b38dd7170',
      'language' => '',
      'current_vid' => '2783',
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
            'value' => '<p><span style="color:#FF8C00;"><span style="font-size: 20px;">Electrocomponents, PLC: Customer Testimonial</span></span></p>

<p><span style="font-size:16px;">The Global Head of Sourcing and Compliance at Electrocomponents discusses how Amber Road\'s global trade management solutions enable greater compliance capabilities. </span></p>
',
            'format' => 'full_html',
          ),
        ),
      ),
      'field_video' => array(
        'und' => array(
          0 => array(
            'value' => 'd_Szw-yDJDhZWBbJLCnV8Q',
          ),
        ),
      ),
      'field_video_width' => array(
        'und' => array(
          0 => array(
            'value' => '460',
          ),
        ),
      ),
      'rdf_mapping' => array(),
      'revision' => TRUE,
      'is_new' => FALSE,
      'original' => (object) array(
        'vid' => '2783',
        'timestamp' => '1473358054',
        'uid' => '18',
        'title' => '',
        'log' => '',
        'vuuid' => '853cebcc-35d8-4969-9cef-782e51468adb',
        'fpid' => '683',
        'bundle' => 'box',
        'link' => '0',
        'path' => '',
        'reusable' => '0',
        'admin_title' => '',
        'admin_description' => '',
        'category' => 'Reusable Content',
        'view_access' => NULL,
        'edit_access' => NULL,
        'created' => '1473355823',
        'changed' => '1473358054',
        'uuid' => '1210b6f6-991c-4dfc-863b-258b38dd7170',
        'language' => '',
        'current_vid' => '2783',
        'field_basic_image_image' => array(),
        'field_button' => array(),
        'field_text' => array(
          'und' => array(
            0 => array(
              'value' => '<p><span style="color:#FF8C00;"><span style="font-size: 20px;">Electrocomponents, PLC: Customer Testimonial</span></span></p>

<p><span style="font-size:16px;">The Global Head of Sourcing and Compliance at Electrocomponents discusses how Amber Road\'s global trade management solutions enable greater compliance capabilities. </span></p>
',
              'summary' => '',
              'format' => 'full_html',
              'safe_value' => '<p><span style="color:#FF8C00;"><span style="font-size: 20px;">Electrocomponents, PLC: Customer Testimonial</span></span></p>
<p><span style="font-size:16px;">The Global Head of Sourcing and Compliance at Electrocomponents discusses how Amber Road\'s global trade management solutions enable greater compliance capabilities. </span></p>
',
              'safe_summary' => '',
            ),
          ),
        ),
        'field_video' => array(
          'und' => array(
            0 => array(
              'value' => 'd_Szw-yDJDhZWBbJLCnV8Q',
              'format' => NULL,
              'safe_value' => 'd_Szw-yDJDhZWBbJLCnV8Q',
            ),
          ),
        ),
        'field_video_width' => array(),
        'rdf_mapping' => array(),
      ),
      'old_vid' => '2783',
      'vid' => '2784',
    ),
  );
  $pane->cache = array();
  $pane->style = array();
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 0;
  $pane->locks = array();
  $pane->uuid = '0d29f060-0ac3-410e-86af-8e45bc3aa078';
  $display->content['new-0d29f060-0ac3-410e-86af-8e45bc3aa078'] = $pane;
  $display->panels['section3_2cols2'][0] = 'new-0d29f060-0ac3-410e-86af-8e45bc3aa078';
  $pane = new stdClass();
  $pane->pid = 'new-dc17b7b7-e2b3-4b1c-8424-b2df2046f07a';
  $pane->panel = 'section3_3cols1';
  $pane->type = 'fieldable_panels_pane';
  $pane->subtype = 'uuid:14092e7c-c5f4-45b5-b7ec-f923be3718a5';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'view_mode' => 'image_text',
    'fieldable_panels_pane' => (object) array(
      'timestamp' => 1461776119,
      'uid' => '18',
      'title' => 'Agilent (logo + testimonial)',
      'log' => '',
      'vuuid' => '95ebe542-17c0-4c83-abd1-d3300849ea1b',
      'fpid' => '4',
      'bundle' => 'box',
      'link' => 0,
      'path' => '',
      'reusable' => 1,
      'admin_title' => '',
      'admin_description' => '',
      'category' => 'Reusable Content',
      'view_access' => NULL,
      'edit_access' => NULL,
      'created' => '1454276404',
      'changed' => 1461776119,
      'uuid' => '14092e7c-c5f4-45b5-b7ec-f923be3718a5',
      'language' => '',
      'current_vid' => '502',
      'field_basic_image_image' => array(
        'und' => array(
          0 => array(
            'fid' => '1656',
            'display' => '1',
            'description' => '',
            'attach_button' => 'Attach',
            'upload' => '',
            'remove_button' => 'Remove',
            'width' => 177,
            'height' => 57,
          ),
        ),
      ),
      'field_button' => array(
        'und' => array(),
      ),
      'field_text' => array(
        'und' => array(
          0 => array(
            'summary' => '',
            'value' => '<p><em><span style="font-size:16px;">“We needed a truly global integrated import/export trade compliance solution to support our high volume transactions. Now our worldwide solution interfaces with multiple ERP systems and 1,300 users in 42 countries.”</span></em></p>

<p class="rteright"><span style="font-size:16px;"><strong>Vice President Logistics<br />
Agilent Technologies</strong></span></p>
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
      'rdf_mapping' => array(),
      'revision' => 1,
      'is_new' => FALSE,
      'original' => (object) array(
        'vid' => '502',
        'timestamp' => '1461094710',
        'uid' => '18',
        'title' => 'Agilent (logo + testimonial)',
        'log' => '',
        'vuuid' => '2525edde-8999-48a6-97d6-8062ac62e227',
        'fpid' => '4',
        'bundle' => 'box',
        'link' => '0',
        'path' => '',
        'reusable' => '1',
        'admin_title' => '',
        'admin_description' => '',
        'category' => 'Reusable Content',
        'view_access' => NULL,
        'edit_access' => NULL,
        'created' => '1454276404',
        'changed' => '1461094710',
        'uuid' => '14092e7c-c5f4-45b5-b7ec-f923be3718a5',
        'language' => '',
        'current_vid' => '502',
        'field_basic_image_image' => array(
          'und' => array(
            0 => array(
              'fid' => '1656',
              'uid' => '28',
              'filename' => 'agilent_0.jpg',
              'uri' => 'public://agilent_0_0.jpg',
              'filemime' => 'image/jpeg',
              'filesize' => '9281',
              'status' => '1',
              'timestamp' => '1458645435',
              'type' => 'image',
              'uuid' => '050f8122-6ef3-4cb5-acec-44d958894aa3',
              'field_file_image_alt_text' => array(),
              'field_file_image_title_text' => array(),
              'metatags' => array(),
              'rdf_mapping' => array(),
              'metadata' => array(
                'height' => 57,
                'width' => 177,
              ),
              'alt' => NULL,
              'title' => NULL,
              'height' => '57',
              'width' => '177',
            ),
          ),
        ),
        'field_button' => array(),
        'field_text' => array(
          'und' => array(
            0 => array(
              'value' => '<p><span style="font-size:16px;"><em>"As the world\'s premier measurement company, Agilent Technologies needed a truly global integrated import / export trade compliance solution to support our high volume transactions. We have rolled the solution out worldwide and are processing millions of transactions per year and have interfaces with multiple ERP systems and 1,300 users in 42 countries." </em></span></p>

<p class="rteright"><span style="font-size:16px;"><strong>Vice President Logistics<br />
Agilent Technologies</strong></span></p>
',
              'summary' => '',
              'format' => 'full_html',
              'safe_value' => '<p><span style="font-size:16px;"><em>"As the world\'s premier measurement company, Agilent Technologies needed a truly global integrated import / export trade compliance solution to support our high volume transactions. We have rolled the solution out worldwide and are processing millions of transactions per year and have interfaces with multiple ERP systems and 1,300 users in 42 countries." </em></span></p>
<p class="rteright"><span style="font-size:16px;"><strong>Vice President Logistics<br />
Agilent Technologies</strong></span></p>
',
              'safe_summary' => '',
            ),
          ),
        ),
        'field_video' => array(),
        'field_video_width' => array(),
        'rdf_mapping' => array(),
      ),
      'old_vid' => '502',
      'vid' => '913',
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
  $pane->uuid = 'dc17b7b7-e2b3-4b1c-8424-b2df2046f07a';
  $display->content['new-dc17b7b7-e2b3-4b1c-8424-b2df2046f07a'] = $pane;
  $display->panels['section3_3cols1'][0] = 'new-dc17b7b7-e2b3-4b1c-8424-b2df2046f07a';
  $pane = new stdClass();
  $pane->pid = 'new-50c2b716-156c-41a1-9840-5a52b2e8cc21';
  $pane->panel = 'section3_3cols2';
  $pane->type = 'fieldable_panels_pane';
  $pane->subtype = 'uuid:b5b2168d-1675-41d2-9fdb-ad2681c14f8c';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'view_mode' => 'image_text',
    'fieldable_panels_pane' => (object) array(
      'timestamp' => 1461776160,
      'uid' => '18',
      'title' => 'Fairchild (logo + testimonial)',
      'log' => '',
      'vuuid' => '27acd4b7-14b6-4203-9c87-24679e97b430',
      'fpid' => '21',
      'bundle' => 'box',
      'link' => 0,
      'path' => '',
      'reusable' => 1,
      'admin_title' => '',
      'admin_description' => '',
      'category' => 'Reusable Content',
      'view_access' => NULL,
      'edit_access' => NULL,
      'created' => '1454276682',
      'changed' => 1461776160,
      'uuid' => 'b5b2168d-1675-41d2-9fdb-ad2681c14f8c',
      'language' => '',
      'current_vid' => '503',
      'field_basic_image_image' => array(
        'und' => array(
          0 => array(
            'fid' => '1658',
            'display' => '1',
            'description' => '',
            'attach_button' => 'Attach',
            'upload' => '',
            'remove_button' => 'Remove',
            'width' => 137,
            'height' => 57,
          ),
        ),
      ),
      'field_button' => array(
        'und' => array(),
      ),
      'field_text' => array(
        'und' => array(
          0 => array(
            'summary' => '',
            'value' => '<p><em><span style="font-size:16px;">“We’ve simplified our shipment process, automated documentation and trade party screening, and gained regulatory and financial control over our international shipments. Currently 90% of all of Fairchild’s shipments are pre-cleared.”</span></em></p>

<p class="rteright"><span style="font-size:16px;"><strong>Senior Manager, Global Logistics<br />
Fairchild Semiconductor</strong></span></p>
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
      'rdf_mapping' => array(),
      'revision' => 1,
      'is_new' => FALSE,
      'original' => (object) array(
        'vid' => '503',
        'timestamp' => '1461094731',
        'uid' => '18',
        'title' => 'Fairchild (logo + testimonial)',
        'log' => '',
        'vuuid' => '7d99165f-9dde-4121-b05a-6caab1c6496b',
        'fpid' => '21',
        'bundle' => 'box',
        'link' => '0',
        'path' => '',
        'reusable' => '1',
        'admin_title' => '',
        'admin_description' => '',
        'category' => 'Reusable Content',
        'view_access' => NULL,
        'edit_access' => NULL,
        'created' => '1454276682',
        'changed' => '1461094731',
        'uuid' => 'b5b2168d-1675-41d2-9fdb-ad2681c14f8c',
        'language' => '',
        'current_vid' => '503',
        'field_basic_image_image' => array(
          'und' => array(
            0 => array(
              'fid' => '1658',
              'uid' => '28',
              'filename' => 'fairchild_0.jpg',
              'uri' => 'public://fairchild_0_0.jpg',
              'filemime' => 'image/jpeg',
              'filesize' => '9803',
              'status' => '1',
              'timestamp' => '1458645487',
              'type' => 'image',
              'uuid' => 'd1ec5a9c-2371-4465-813d-6cc6b0061b34',
              'field_file_image_alt_text' => array(),
              'field_file_image_title_text' => array(),
              'metatags' => array(),
              'rdf_mapping' => array(),
              'metadata' => array(
                'height' => 57,
                'width' => 137,
              ),
              'alt' => NULL,
              'title' => NULL,
              'height' => '57',
              'width' => '137',
            ),
          ),
        ),
        'field_button' => array(),
        'field_text' => array(
          'und' => array(
            0 => array(
              'value' => '<p><span style="font-size:16px;"><em>“The collaboration with Amber Road has enabled Fairchild to achieve global logistics processes that are 100% standardized worldwide. More importantly, this process supports our initiative to provide exceptional customer service and maintain outstanding customer satisfaction worldwide.”</em></span></p>

<p class="rteright"><span style="font-size:16px;"><strong>Senior Manager, Global Logistics<br />
Fairchild Semiconductor</strong></span></p>
',
              'summary' => '',
              'format' => 'full_html',
              'safe_value' => '<p><span style="font-size:16px;"><em>“The collaboration with Amber Road has enabled Fairchild to achieve global logistics processes that are 100% standardized worldwide. More importantly, this process supports our initiative to provide exceptional customer service and maintain outstanding customer satisfaction worldwide.”</em></span></p>
<p class="rteright"><span style="font-size:16px;"><strong>Senior Manager, Global Logistics<br />
Fairchild Semiconductor</strong></span></p>
',
              'safe_summary' => '',
            ),
          ),
        ),
        'field_video' => array(),
        'field_video_width' => array(),
        'rdf_mapping' => array(),
      ),
      'old_vid' => '503',
      'vid' => '914',
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
  $pane->uuid = '50c2b716-156c-41a1-9840-5a52b2e8cc21';
  $display->content['new-50c2b716-156c-41a1-9840-5a52b2e8cc21'] = $pane;
  $display->panels['section3_3cols2'][0] = 'new-50c2b716-156c-41a1-9840-5a52b2e8cc21';
  $pane = new stdClass();
  $pane->pid = 'new-b3b1b2e8-834b-48b1-a0c6-f89a4d6386cb';
  $pane->panel = 'section3_3cols3';
  $pane->type = 'fieldable_panels_pane';
  $pane->subtype = 'uuid:142f0ac5-bef7-4e92-8b2f-8921d93e1cd9';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'view_mode' => 'image_text',
    'fieldable_panels_pane' => (object) array(
      'timestamp' => 1459986661,
      'uid' => '18',
      'title' => 'ABB (logo + testimonial)',
      'log' => '',
      'vuuid' => 'f4f62f67-8011-4d5a-b672-f2070acac6eb',
      'fpid' => '5',
      'bundle' => 'box',
      'link' => 0,
      'path' => '',
      'reusable' => 1,
      'admin_title' => 'Testimonial NCR',
      'admin_description' => '',
      'category' => 'Reusable Content',
      'view_access' => NULL,
      'edit_access' => NULL,
      'created' => '1454276550',
      'changed' => 1459986661,
      'uuid' => '142f0ac5-bef7-4e92-8b2f-8921d93e1cd9',
      'language' => 'und',
      'current_vid' => '90',
      'field_basic_image_image' => array(
        'und' => array(
          0 => array(
            'fid' => '1821',
            'display' => '1',
            'description' => '',
            'attach_button' => 'Attach',
            'upload' => '',
            'remove_button' => 'Remove',
            'width' => 240,
            'height' => 67,
          ),
        ),
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
            'value' => '<p><em>“Once you can see the shipments moving in transit, you can see when something’s going to be late and adjust to it. That’s helped to reduce the amount of expediting that we’ve had to do. NCR will see a seven-figure benefit from the implementation; it has added definite value for us.”</em></p>

<p class="rteright"><strong>Director, Global Logistics Sourcing, NCR</strong></p>
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
      'rdf_mapping' => array(),
      'revision' => 1,
      'is_new' => FALSE,
      'original' => (object) array(
        'vid' => '90',
        'timestamp' => '1459762442',
        'uid' => '18',
        'title' => 'ABB (logo + testimonial)',
        'log' => '',
        'vuuid' => '6df355f0-9004-4a83-97b5-87e794bab0c4',
        'fpid' => '5',
        'bundle' => 'box',
        'link' => '0',
        'path' => '',
        'reusable' => '1',
        'admin_title' => '',
        'admin_description' => '',
        'category' => 'Reusable Content',
        'view_access' => NULL,
        'edit_access' => NULL,
        'created' => '1454276550',
        'changed' => '1459762442',
        'uuid' => '142f0ac5-bef7-4e92-8b2f-8921d93e1cd9',
        'language' => 'und',
        'current_vid' => '90',
        'field_basic_image_image' => array(
          'und' => array(
            0 => array(
              'fid' => '1657',
              'uid' => '28',
              'filename' => 'abb.jpg',
              'uri' => 'public://abb_0.jpg',
              'filemime' => 'image/jpeg',
              'filesize' => '9017',
              'status' => '1',
              'timestamp' => '1458645465',
              'type' => 'image',
              'uuid' => 'cbfbf363-2db8-408b-afeb-46c0975bc1d5',
              'field_file_image_alt_text' => array(),
              'field_file_image_title_text' => array(),
              'metatags' => array(),
              'rdf_mapping' => array(),
              'metadata' => array(
                'height' => 57,
                'width' => 110,
              ),
              'alt' => NULL,
              'title' => NULL,
              'height' => '57',
              'width' => '110',
            ),
          ),
        ),
        'field_button' => array(),
        'field_panel_pane_type' => array(),
        'field_text' => array(
          'und' => array(
            0 => array(
              'value' => '<p><em>"Using Amber Road there is now a higher awareness and cosideration of preferential customs tariffs, which enriches our strategic decision making."</em></p>

<p class="rteright"><strong>In-House Legal Counsel, ABB</strong></p>
',
              'summary' => '',
              'format' => 'full_html',
              'safe_value' => '<p><em>"Using Amber Road there is now a higher awareness and cosideration of preferential customs tariffs, which enriches our strategic decision making."</em></p>
<p class="rteright"><strong>In-House Legal Counsel, ABB</strong></p>
',
              'safe_summary' => '',
            ),
          ),
        ),
        'field_video' => array(),
        'field_video_width' => array(),
        'rdf_mapping' => array(),
      ),
      'old_vid' => '90',
      'vid' => '165',
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
  $pane->uuid = 'b3b1b2e8-834b-48b1-a0c6-f89a4d6386cb';
  $display->content['new-b3b1b2e8-834b-48b1-a0c6-f89a4d6386cb'] = $pane;
  $display->panels['section3_3cols3'][0] = 'new-b3b1b2e8-834b-48b1-a0c6-f89a4d6386cb';
  $pane = new stdClass();
  $pane->pid = 'new-28ad2625-633b-4886-a5f2-5d01e633f1ff';
  $pane->panel = 'section3_header';
  $pane->type = 'fieldable_panels_pane';
  $pane->subtype = 'uuid:ccc59eaa-6426-4615-8385-2ace32a00fc1';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'view_mode' => 'full',
    'fieldable_panels_pane' => (object) array(
      'timestamp' => 1454338376,
      'uid' => '28',
      'title' => 'What our customers are say about Amber Road',
      'log' => '',
      'vuuid' => '41344240-f639-4b6e-85c0-f45291e36b93',
      'fpid' => '25',
      'bundle' => 'text',
      'link' => 0,
      'path' => '',
      'reusable' => 0,
      'admin_title' => '',
      'admin_description' => '',
      'category' => 'Reusable Content',
      'view_access' => NULL,
      'edit_access' => NULL,
      'created' => '1454338124',
      'changed' => 1454338376,
      'uuid' => 'ccc59eaa-6426-4615-8385-2ace32a00fc1',
      'language' => 'und',
      'current_vid' => '56',
      'field_basic_text_text' => array(
        'und' => array(),
      ),
      'rdf_mapping' => array(),
      'revision' => 1,
      'is_new' => FALSE,
      'original' => (object) array(
        'vid' => '56',
        'timestamp' => '1454338265',
        'uid' => '28',
        'title' => '',
        'log' => '',
        'vuuid' => '535bbfd8-6286-4400-842e-e9d3c50b3e3d',
        'fpid' => '25',
        'bundle' => 'text',
        'link' => '0',
        'path' => '',
        'reusable' => '0',
        'admin_title' => '',
        'admin_description' => '',
        'category' => 'Reusable Content',
        'view_access' => NULL,
        'edit_access' => NULL,
        'created' => '1454338124',
        'changed' => '1454338265',
        'uuid' => 'ccc59eaa-6426-4615-8385-2ace32a00fc1',
        'language' => 'und',
        'current_vid' => '56',
        'field_basic_text_text' => array(
          'und' => array(
            0 => array(
              'value' => '<div class="col-md-12">What our customers are say about Amber Road</div>
',
              'format' => 'full_html',
              'safe_value' => '<div class="col-md-12">What our customers are say about Amber Road</div>
',
            ),
          ),
        ),
        'rdf_mapping' => array(),
      ),
      'old_vid' => '56',
      'vid' => '57',
    ),
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array(
    'css_id' => '',
    'css_class' => 'container',
  );
  $pane->extras = array();
  $pane->position = 0;
  $pane->locks = array();
  $pane->uuid = '28ad2625-633b-4886-a5f2-5d01e633f1ff';
  $display->content['new-28ad2625-633b-4886-a5f2-5d01e633f1ff'] = $pane;
  $display->panels['section3_header'][0] = 'new-28ad2625-633b-4886-a5f2-5d01e633f1ff';
  $pane = new stdClass();
  $pane->pid = 'new-556a5778-1cd2-4317-98e4-a7b230395a4e';
  $pane->panel = 'section4';
  $pane->type = 'fieldable_panels_pane';
  $pane->subtype = 'uuid:86284f3c-a125-4e38-ae4a-81414ab82f7e';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'view_mode' => 'full',
    'fieldable_panels_pane' => (object) array(
      'timestamp' => 1461668361,
      'uid' => '18',
      'title' => '',
      'log' => '',
      'vuuid' => '99bc9b5d-2c57-4c78-aabb-de22966552ed',
      'fpid' => '18',
      'bundle' => 'text',
      'link' => 0,
      'path' => '',
      'reusable' => 0,
      'admin_title' => '',
      'admin_description' => '',
      'category' => 'Reusable Content',
      'view_access' => NULL,
      'edit_access' => NULL,
      'created' => '1454327124',
      'changed' => 1461668361,
      'uuid' => '86284f3c-a125-4e38-ae4a-81414ab82f7e',
      'language' => '',
      'current_vid' => '801',
      'field_basic_text_text' => array(
        'und' => array(
          0 => array(
            'value' => '<p style="text-align:center"><span style="font-size:30px;font-weight:100;color:gb(251, 137, 9);">The world\'s largest and fastest growing companies use Amber Road</span></p>

<p>&nbsp;</p>

<div class="container-fluid">
<div class="row">
<div class="col-lg-1 col-md-3 col-sm-6 col-xs-12"><img alt="Agilent Technologies" src="/sites/default/files/Client_logo/hp-logos_03_0.png" style="width: 150px; height: 103px;" /></div>

<div class="col-lg-1 col-md-3 col-sm-6 col-xs-12"><img alt="Amway" src="/sites/default/files/Client_logo/hp-logos_04_0.png" style="width: 150px; height: 103px;" /></div>

<div class="col-lg-1 col-md-3 col-sm-6 col-xs-12"><img alt="AXALTA" src="/sites/default/files/Client_logo/hp-logos_05_0.png" style="width: 150px; height: 103px;" /></div>

<div class="col-lg-1 col-md-3 col-sm-6 col-xs-12"><img alt="Baker Hughes" src="/sites/default/files/Client_logo/hp-logos_06_0.png" style="width: 150px; height: 103px;" /></div>

<div class="col-lg-1 col-md-3 col-sm-6 col-xs-12"><img alt="Bloomin Brands" src="/sites/default/files/hp-bloomin-brands.png" style="width: 150px; height: 103px;" /></div>

<div class="col-lg-1 col-md-3 col-sm-6 col-xs-12"><img alt="Bunzl" src="/sites/default/files/Client_logo/hp-bunzl_0.png" style="width: 150px; height: 103px;" /></div>

<div class="col-lg-1 col-md-3 col-sm-6 col-xs-12"><img alt="Caleres 5" src="/sites/default/files/Client_logo/hp-caleres.png" style="width: 150px; height: 103px;" /></div>

<div class="col-lg-1 col-md-3 col-sm-6 col-xs-12"><img alt="CISCO" src="/sites/default/files/Client_logo/hp-cisco.png" style="width: 150px; height: 103px;" /></div>

<div class="col-lg-1 col-md-3 col-sm-6 col-xs-12"><img alt="Construction Specialties" src="/sites/default/files/Client_logo/hp-constructionspecialists.png" style="width: 150px; height: 103px;" /></div>

<div class="col-lg-1 col-md-3 col-sm-6 col-xs-12"><img alt="Donaldson Filtration Solutions" src="/sites/default/files/Client_logo/hp-donaldson.png" style="width: 150px; height: 103px;" /></div>

<div class="col-lg-1 col-md-3 col-sm-6 col-xs-12"><img alt="Electrocomponents plc" src="/sites/default/files/Client_logo/hp-electrocomponents.png" style="width: 150px; height: 103px;" /></div>

<div class="col-lg-1 col-md-3 col-sm-6 col-xs-12"><img alt="Fairchild" src="/sites/default/files/Client_logo/hp-fairfield.png" style="width: 150px; height: 103px;" /></div>

<div class="col-lg-1 col-md-3 col-sm-6 col-xs-12"><img alt="FUJIFILM" src="/sites/default/files/Client_logo/hp-fujifilm.png" style="width: 150px; height: 103px;" /></div>

<div class="col-lg-1 col-md-3 col-sm-6 col-xs-12"><img alt="General Electric" src="/sites/default/files/Client_logo/hp-ge.png" style="width: 150px; height: 103px;" /></div>

<div class="col-lg-1 col-md-3 col-sm-6 col-xs-12"><img alt="General Mills" src="/sites/default/files/Client_logo/hp-generalmills.png" style="width: 150px; height: 103px;" /></div>

<div class="col-lg-1 col-md-3 col-sm-6 col-xs-12"><img alt="GlaskoSmithKline" src="/sites/default/files/Client_logo/hp-logos_18_0.png" style="width: 150px; height: 103px;" /></div>

<div class="col-lg-1 col-md-3 col-sm-6 col-xs-12"><img alt="Haworth" src="/sites/default/files/Client_logo/hp-logos_19_0.png" style="width: 150px; height: 103px;" /></div>

<div class="col-lg-1 col-md-3 col-sm-6 col-xs-12"><img alt="Honeywell" src="/sites/default/files/Client_logo/hp-logos_20_1.png" style="width: 150px; height: 103px;" /></div>

<div class="col-lg-1 col-md-3 col-sm-6 col-xs-12"><img alt="Ingersoll Rand" src="/sites/default/files/Client_logo/hp-logos_21_1.png" style="width: 150px; height: 103px;" /></div>

<div class="col-lg-1 col-md-3 col-sm-6 col-xs-12"><img alt="Intelsat" src="/sites/default/files/Client_logo/hp-logos_22_0.png" style="width: 150px; height: 103px;" /></div>

<div class="col-lg-1 col-md-3 col-sm-6 col-xs-12"><img alt="Kraft" src="/sites/default/files/Client_logo/hp-kraft.png" style="width: 150px; height: 103px;" /></div>

<div class="col-lg-1 col-md-3 col-sm-6 col-xs-12"><img alt="Leggett &amp; Platt" src="/sites/default/files/Client_logo/hp-leggettplatt.png" style="width: 150px; height: 103px;" /></div>

<div class="col-lg-1 col-md-3 col-sm-6 col-xs-12"><img alt="Levi\'s" src="/sites/default/files/Client_logo/hp-levis.png" style="width: 150px; height: 103px;" /></div>

<div class="col-lg-1 col-md-3 col-sm-6 col-xs-12"><img alt="Mercury" src="/sites/default/files/Client_logo/hp-logos_28_0.png" style="width: 150px; height: 103px;" /></div>

<div class="col-lg-1 col-md-3 col-sm-6 col-xs-12"><img alt="Monsanto" src="/sites/default/files/hp-monsanto.png" style="width: 150px; height: 103px;" /></div>

<div class="col-lg-1 col-md-3 col-sm-6 col-xs-12"><img alt="" src="/sites/default/files/Client_logo/hp-logos_29_0.png" style="width: 150px; height: 103px;" /></div>

<div class="col-lg-1 col-md-3 col-sm-6 col-xs-12"><img alt="" src="/sites/default/files/Client_logo/hp-logos_31_0.png" style="width: 150px; height: 103px;" /></div>

<div class="col-lg-1 col-md-3 col-sm-6 col-xs-12"><img alt="" src="/sites/default/files/Client_logo/hp-logos_33_0.png" style="width: 150px; height: 103px;" /></div>

<div class="col-lg-1 col-md-3 col-sm-6 col-xs-12"><img alt="" src="/sites/default/files/Client_logo/hp-logos_34_0.png" style="width: 150px; height: 103px;" /></div>

<div class="col-lg-1 col-md-3 col-sm-6 col-xs-12"><img alt="" src="/sites/default/files/Client_logo/hp-logos_35_0.png" style="width: 150px; height: 103px;" /></div>

<div class="col-lg-1 col-md-3 col-sm-6 col-xs-12"><img alt="" src="/sites/default/files/Client_logo/hp-logos_36_0.png" style="width: 150px; height: 103px;" /></div>

<div class="col-lg-1 col-md-3 col-sm-6 col-xs-12"><img alt="Tyco" src="/sites/default/files/hp-tyco.png" style="width: 150px; height: 103px;" /></div>

<div class="col-lg-1 col-md-3 col-sm-6 col-xs-12"><img alt="Unilever" src="/sites/default/files/hp-unilever.png" style="width: 150px; height: 103px;" /></div>

<div class="col-lg-1 col-md-3 col-sm-6 col-xs-12"><img alt="UPS" src="/sites/default/files/hp-ups.png" style="width: 150px; height: 103px;" /></div>

<div class="col-lg-1 col-md-3 col-sm-6 col-xs-12"><img alt="VF" src="/sites/default/files/hp-vf.png" style="width: 150px; height: 103px;" /></div>

<div class="col-lg-1 col-md-3 col-sm-6 col-xs-12"><img alt="" src="/sites/default/files/Client_logo/hp-logos_39_0.png" style="width: 150px; height: 103px;" /></div>
</div>
</div>
',
            'format' => 'full_html',
          ),
        ),
      ),
      'rdf_mapping' => array(),
      'revision' => 1,
      'is_new' => FALSE,
      'original' => (object) array(
        'vid' => '801',
        'timestamp' => '1461668265',
        'uid' => '18',
        'title' => '',
        'log' => '',
        'vuuid' => 'e7c6338a-b3c0-4067-b2f8-e4da7d6a7554',
        'fpid' => '18',
        'bundle' => 'text',
        'link' => '0',
        'path' => '',
        'reusable' => '0',
        'admin_title' => '',
        'admin_description' => '',
        'category' => 'Reusable Content',
        'view_access' => NULL,
        'edit_access' => NULL,
        'created' => '1454327124',
        'changed' => '1461668265',
        'uuid' => '86284f3c-a125-4e38-ae4a-81414ab82f7e',
        'language' => '',
        'current_vid' => '801',
        'field_basic_text_text' => array(
          'und' => array(
            0 => array(
              'value' => '<p style="text-align:center"><span style="font-size:30px;font-weight:100;color:gb(251, 137, 9);">The world\'s largest and fastest growing companies use Amber Road</span></p>

<p>&nbsp;</p>

<div class="container-fluid">
<div class="row">
<div class="col-lg-1 col-md-3 col-sm-6 col-xs-12"><img alt="Agilent Technologies" src="/sites/default/files/Client_logo/hp-logos_03_0.png" style="width: 150px; height: 103px;" /></div>

<div class="col-lg-1 col-md-3 col-sm-6 col-xs-12"><img alt="Amway" src="/sites/default/files/Client_logo/hp-logos_04_0.png" style="width: 150px; height: 103px;" /></div>

<div class="col-lg-1 col-md-3 col-sm-6 col-xs-12"><img alt="AXALTA" src="/sites/default/files/Client_logo/hp-logos_05_0.png" style="width: 150px; height: 103px;" /></div>

<div class="col-lg-1 col-md-3 col-sm-6 col-xs-12"><img alt="Baker Hughes" src="/sites/default/files/Client_logo/hp-logos_06_0.png" style="width: 150px; height: 103px;" /></div>

<div class="col-lg-1 col-md-3 col-sm-6 col-xs-12"><img alt="Bloomin Brands" src="/sites/default/files/hp-bloomin-brands.png" style="width: 150px; height: 103px;" /></div>

<div class="col-lg-1 col-md-3 col-sm-6 col-xs-12"><img alt="Bunzl" src="/sites/default/files/Client_logo/hp-bunzl_0.png" style="width: 150px; height: 103px;" /></div>

<div class="col-lg-1 col-md-3 col-sm-6 col-xs-12"><img alt="Caleres 5" src="/sites/default/files/Client_logo/hp-caleres.png" style="width: 150px; height: 103px;" /></div>

<div class="col-lg-1 col-md-3 col-sm-6 col-xs-12"><img alt="CISCO" src="/sites/default/files/Client_logo/hp-cisco.png" style="width: 150px; height: 103px;" /></div>

<div class="col-lg-1 col-md-3 col-sm-6 col-xs-12"><img alt="Construction Specialties" src="/sites/default/files/Client_logo/hp-constructionspecialists.png" style="width: 150px; height: 103px;" /></div>

<div class="col-lg-1 col-md-3 col-sm-6 col-xs-12"><img alt="Donaldson Filtration Solutions" src="/sites/default/files/Client_logo/hp-donaldson.png" style="width: 150px; height: 103px;" /></div>

<div class="col-lg-1 col-md-3 col-sm-6 col-xs-12"><img alt="Electrocomponents plc" src="/sites/default/files/Client_logo/hp-electrocomponents.png" style="width: 150px; height: 103px;" /></div>

<div class="col-lg-1 col-md-3 col-sm-6 col-xs-12"><img alt="Fairchild" src="/sites/default/files/Client_logo/hp-fairfield.png" style="width: 150px; height: 103px;" /></div>

<div class="col-lg-1 col-md-3 col-sm-6 col-xs-12"><img alt="FUJIFILM" src="/sites/default/files/Client_logo/hp-fujifilm.png" style="width: 150px; height: 103px;" /></div>

<div class="col-lg-1 col-md-3 col-sm-6 col-xs-12"><img alt="General Electric" src="/sites/default/files/Client_logo/hp-ge.png" style="width: 150px; height: 103px;" /></div>

<div class="col-lg-1 col-md-3 col-sm-6 col-xs-12"><img alt="General Mills" src="/sites/default/files/Client_logo/hp-generalmills.png" style="width: 150px; height: 103px;" /></div>

<div class="col-lg-1 col-md-3 col-sm-6 col-xs-12"><img alt="GlaskoSmithKline" src="/sites/default/files/Client_logo/hp-logos_18_0.png" style="width: 150px; height: 103px;" /></div>

<div class="col-lg-1 col-md-3 col-sm-6 col-xs-12"><img alt="Haworth" src="/sites/default/files/Client_logo/hp-logos_19_0.png" style="width: 150px; height: 103px;" /></div>

<div class="col-lg-1 col-md-3 col-sm-6 col-xs-12"><img alt="Honeywell" src="/sites/default/files/Client_logo/hp-logos_20_1.png" style="width: 150px; height: 103px;" /></div>

<div class="col-lg-1 col-md-3 col-sm-6 col-xs-12"><img alt="Ingersoll Rand" src="/sites/default/files/Client_logo/hp-logos_21_1.png" style="width: 150px; height: 103px;" /></div>

<div class="col-lg-1 col-md-3 col-sm-6 col-xs-12"><img alt="Intelsat" src="/sites/default/files/Client_logo/hp-logos_22_0.png" style="width: 150px; height: 103px;" /></div>

<div class="col-lg-1 col-md-3 col-sm-6 col-xs-12"><img alt="Kraft" src="/sites/default/files/Client_logo/hp-kraft.png" style="width: 150px; height: 103px;" /></div>

<div class="col-lg-1 col-md-3 col-sm-6 col-xs-12"><img alt="Leggett &amp; Platt" src="/sites/default/files/Client_logo/hp-leggettplatt.png" style="width: 150px; height: 103px;" /></div>

<div class="col-lg-1 col-md-3 col-sm-6 col-xs-12"><img alt="Levi\'s" src="/sites/default/files/Client_logo/hp-levis.png" style="width: 150px; height: 103px;" /></div>

<div class="col-lg-1 col-md-3 col-sm-6 col-xs-12"><img alt="Mercury" src="/sites/default/files/Client_logo/hp-logos_28_0.png" style="width: 150px; height: 103px;" /></div>

<div class="col-lg-1 col-md-3 col-sm-6 col-xs-12"><img alt="Monsanto" src="/sites/default/files/hp-monsanto.png" style="width: 150px; height: 103px;" /></div>

<div class="col-lg-1 col-md-3 col-sm-6 col-xs-12"><img alt="" src="/sites/default/files/Client_logo/hp-logos_29_0.png" style="width: 150px; height: 103px;" /></div>

<div class="col-lg-1 col-md-3 col-sm-6 col-xs-12"><img alt="" src="/sites/default/files/Client_logo/hp-logos_31_0.png" style="width: 150px; height: 103px;" /></div>

<div class="col-lg-1 col-md-3 col-sm-6 col-xs-12"><img alt="" src="/sites/default/files/Client_logo/hp-logos_33_0.png" style="width: 150px; height: 103px;" /></div>

<div class="col-lg-1 col-md-3 col-sm-6 col-xs-12"><img alt="" src="/sites/default/files/Client_logo/hp-logos_34_0.png" style="width: 150px; height: 103px;" /></div>

<div class="col-lg-1 col-md-3 col-sm-6 col-xs-12"><img alt="" src="/sites/default/files/Client_logo/hp-logos_35_0.png" style="width: 150px; height: 103px;" /></div>

<div class="col-lg-1 col-md-3 col-sm-6 col-xs-12"><img alt="" src="/sites/default/files/Client_logo/hp-logos_36_0.png" style="width: 150px; height: 103px;" /></div>

<div class="col-lg-1 col-md-3 col-sm-6 col-xs-12"><img alt="Tyco" src="/sites/default/files/hp-tyco.png" style="width: 150px; height: 103px;" /></div>

<div class="col-lg-1 col-md-3 col-sm-6 col-xs-12"><img alt="Unilever" src="/sites/default/files/hp-unilever.png" style="width: 150px; height: 103px;" /></div>

<div class="col-lg-1 col-md-3 col-sm-6 col-xs-12"><img alt="UPS" src="/sites/default/files/hp-ups.png" style="width: 150px; height: 103px;" /></div>

<div class="col-lg-1 col-md-3 col-sm-6 col-xs-12"><img alt="VF" src="/sites/default/files/hp-vf.png" style="width: 150px; height: 103px;" /></div>

<div class="col-lg-1 col-md-3 col-sm-6 col-xs-12"><img alt="" src="/sites/default/files/Client_logo/hp-logos_39_0.png" style="width: 150px; height: 103px;" /></div>
</div>
</div>
',
              'format' => 'full_html',
              'safe_value' => '<p style="text-align:center"><span style="font-size:30px;font-weight:100;color:gb(251, 137, 9);">The world\'s largest and fastest growing companies use Amber Road</span></p>
<p> </p>
<div class="container-fluid">
<div class="row">
<div class="col-lg-1 col-md-3 col-sm-6 col-xs-12"><img alt="Agilent Technologies" src="/sites/default/files/Client_logo/hp-logos_03_0.png" style="width: 150px; height: 103px;" /></div>
<div class="col-lg-1 col-md-3 col-sm-6 col-xs-12"><img alt="Amway" src="/sites/default/files/Client_logo/hp-logos_04_0.png" style="width: 150px; height: 103px;" /></div>
<div class="col-lg-1 col-md-3 col-sm-6 col-xs-12"><img alt="AXALTA" src="/sites/default/files/Client_logo/hp-logos_05_0.png" style="width: 150px; height: 103px;" /></div>
<div class="col-lg-1 col-md-3 col-sm-6 col-xs-12"><img alt="Baker Hughes" src="/sites/default/files/Client_logo/hp-logos_06_0.png" style="width: 150px; height: 103px;" /></div>
<div class="col-lg-1 col-md-3 col-sm-6 col-xs-12"><img alt="Bloomin Brands" src="/sites/default/files/hp-bloomin-brands.png" style="width: 150px; height: 103px;" /></div>
<div class="col-lg-1 col-md-3 col-sm-6 col-xs-12"><img alt="Bunzl" src="/sites/default/files/Client_logo/hp-bunzl_0.png" style="width: 150px; height: 103px;" /></div>
<div class="col-lg-1 col-md-3 col-sm-6 col-xs-12"><img alt="Caleres 5" src="/sites/default/files/Client_logo/hp-caleres.png" style="width: 150px; height: 103px;" /></div>
<div class="col-lg-1 col-md-3 col-sm-6 col-xs-12"><img alt="CISCO" src="/sites/default/files/Client_logo/hp-cisco.png" style="width: 150px; height: 103px;" /></div>
<div class="col-lg-1 col-md-3 col-sm-6 col-xs-12"><img alt="Construction Specialties" src="/sites/default/files/Client_logo/hp-constructionspecialists.png" style="width: 150px; height: 103px;" /></div>
<div class="col-lg-1 col-md-3 col-sm-6 col-xs-12"><img alt="Donaldson Filtration Solutions" src="/sites/default/files/Client_logo/hp-donaldson.png" style="width: 150px; height: 103px;" /></div>
<div class="col-lg-1 col-md-3 col-sm-6 col-xs-12"><img alt="Electrocomponents plc" src="/sites/default/files/Client_logo/hp-electrocomponents.png" style="width: 150px; height: 103px;" /></div>
<div class="col-lg-1 col-md-3 col-sm-6 col-xs-12"><img alt="Fairchild" src="/sites/default/files/Client_logo/hp-fairfield.png" style="width: 150px; height: 103px;" /></div>
<div class="col-lg-1 col-md-3 col-sm-6 col-xs-12"><img alt="FUJIFILM" src="/sites/default/files/Client_logo/hp-fujifilm.png" style="width: 150px; height: 103px;" /></div>
<div class="col-lg-1 col-md-3 col-sm-6 col-xs-12"><img alt="General Electric" src="/sites/default/files/Client_logo/hp-ge.png" style="width: 150px; height: 103px;" /></div>
<div class="col-lg-1 col-md-3 col-sm-6 col-xs-12"><img alt="General Mills" src="/sites/default/files/Client_logo/hp-generalmills.png" style="width: 150px; height: 103px;" /></div>
<div class="col-lg-1 col-md-3 col-sm-6 col-xs-12"><img alt="GlaskoSmithKline" src="/sites/default/files/Client_logo/hp-logos_18_0.png" style="width: 150px; height: 103px;" /></div>
<div class="col-lg-1 col-md-3 col-sm-6 col-xs-12"><img alt="Haworth" src="/sites/default/files/Client_logo/hp-logos_19_0.png" style="width: 150px; height: 103px;" /></div>
<div class="col-lg-1 col-md-3 col-sm-6 col-xs-12"><img alt="Honeywell" src="/sites/default/files/Client_logo/hp-logos_20_1.png" style="width: 150px; height: 103px;" /></div>
<div class="col-lg-1 col-md-3 col-sm-6 col-xs-12"><img alt="Ingersoll Rand" src="/sites/default/files/Client_logo/hp-logos_21_1.png" style="width: 150px; height: 103px;" /></div>
<div class="col-lg-1 col-md-3 col-sm-6 col-xs-12"><img alt="Intelsat" src="/sites/default/files/Client_logo/hp-logos_22_0.png" style="width: 150px; height: 103px;" /></div>
<div class="col-lg-1 col-md-3 col-sm-6 col-xs-12"><img alt="Kraft" src="/sites/default/files/Client_logo/hp-kraft.png" style="width: 150px; height: 103px;" /></div>
<div class="col-lg-1 col-md-3 col-sm-6 col-xs-12"><img alt="Leggett &amp; Platt" src="/sites/default/files/Client_logo/hp-leggettplatt.png" style="width: 150px; height: 103px;" /></div>
<div class="col-lg-1 col-md-3 col-sm-6 col-xs-12"><img alt="Levi\'s" src="/sites/default/files/Client_logo/hp-levis.png" style="width: 150px; height: 103px;" /></div>
<div class="col-lg-1 col-md-3 col-sm-6 col-xs-12"><img alt="Mercury" src="/sites/default/files/Client_logo/hp-logos_28_0.png" style="width: 150px; height: 103px;" /></div>
<div class="col-lg-1 col-md-3 col-sm-6 col-xs-12"><img alt="Monsanto" src="/sites/default/files/hp-monsanto.png" style="width: 150px; height: 103px;" /></div>
<div class="col-lg-1 col-md-3 col-sm-6 col-xs-12"><img alt="" src="/sites/default/files/Client_logo/hp-logos_29_0.png" style="width: 150px; height: 103px;" /></div>
<div class="col-lg-1 col-md-3 col-sm-6 col-xs-12"><img alt="" src="/sites/default/files/Client_logo/hp-logos_31_0.png" style="width: 150px; height: 103px;" /></div>
<div class="col-lg-1 col-md-3 col-sm-6 col-xs-12"><img alt="" src="/sites/default/files/Client_logo/hp-logos_33_0.png" style="width: 150px; height: 103px;" /></div>
<div class="col-lg-1 col-md-3 col-sm-6 col-xs-12"><img alt="" src="/sites/default/files/Client_logo/hp-logos_34_0.png" style="width: 150px; height: 103px;" /></div>
<div class="col-lg-1 col-md-3 col-sm-6 col-xs-12"><img alt="" src="/sites/default/files/Client_logo/hp-logos_35_0.png" style="width: 150px; height: 103px;" /></div>
<div class="col-lg-1 col-md-3 col-sm-6 col-xs-12"><img alt="" src="/sites/default/files/Client_logo/hp-logos_36_0.png" style="width: 150px; height: 103px;" /></div>
<div class="col-lg-1 col-md-3 col-sm-6 col-xs-12"><img alt="Tyco" src="/sites/default/files/hp-tyco.png" style="width: 150px; height: 103px;" /></div>
<div class="col-lg-1 col-md-3 col-sm-6 col-xs-12"><img alt="Unilever" src="/sites/default/files/hp-unilever.png" style="width: 150px; height: 103px;" /></div>
<div class="col-lg-1 col-md-3 col-sm-6 col-xs-12"><img alt="UPS" src="/sites/default/files/hp-ups.png" style="width: 150px; height: 103px;" /></div>
<div class="col-lg-1 col-md-3 col-sm-6 col-xs-12"><img alt="VF" src="/sites/default/files/hp-vf.png" style="width: 150px; height: 103px;" /></div>
<div class="col-lg-1 col-md-3 col-sm-6 col-xs-12"><img alt="" src="/sites/default/files/Client_logo/hp-logos_39_0.png" style="width: 150px; height: 103px;" /></div>
</div>
</div>
',
            ),
          ),
        ),
        'rdf_mapping' => array(),
      ),
      'old_vid' => '801',
      'vid' => '802',
    ),
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array(
    'css_id' => '',
    'css_class' => 'container-full',
  );
  $pane->extras = array();
  $pane->position = 0;
  $pane->locks = array();
  $pane->uuid = '556a5778-1cd2-4317-98e4-a7b230395a4e';
  $display->content['new-556a5778-1cd2-4317-98e4-a7b230395a4e'] = $pane;
  $display->panels['section4'][0] = 'new-556a5778-1cd2-4317-98e4-a7b230395a4e';
  $pane = new stdClass();
  $pane->pid = 'new-3e793314-7457-4490-98ac-f9868957ea56';
  $pane->panel = 'section5_2cols1';
  $pane->type = 'block';
  $pane->subtype = 'aggregator-feed-1';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'override_title' => 1,
    'override_title_text' => 'RECENT BLOG POSTS',
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
  $pane->uuid = '3e793314-7457-4490-98ac-f9868957ea56';
  $display->content['new-3e793314-7457-4490-98ac-f9868957ea56'] = $pane;
  $display->panels['section5_2cols1'][0] = 'new-3e793314-7457-4490-98ac-f9868957ea56';
  $pane = new stdClass();
  $pane->pid = 'new-e307c883-1683-4e40-b69b-e230236c7355';
  $pane->panel = 'section5_2cols1';
  $pane->type = 'views_panes';
  $pane->subtype = 'news_front_page_-panel_pane_1';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'view_settings' => 'fields',
    'header_type' => 'none',
    'view_mode' => 'teaser',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array(
    'css_id' => '',
    'css_class' => '',
  );
  $pane->extras = array();
  $pane->position = 1;
  $pane->locks = array();
  $pane->uuid = 'e307c883-1683-4e40-b69b-e230236c7355';
  $display->content['new-e307c883-1683-4e40-b69b-e230236c7355'] = $pane;
  $display->panels['section5_2cols1'][1] = 'new-e307c883-1683-4e40-b69b-e230236c7355';
  $pane = new stdClass();
  $pane->pid = 'new-fefb76d3-431d-49a0-8fb4-882bcb2a2c39';
  $pane->panel = 'section5_2cols2';
  $pane->type = 'views_panes';
  $pane->subtype = 'events_front_page_-panel_pane_1';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
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
  $pane->position = 0;
  $pane->locks = array();
  $pane->uuid = 'fefb76d3-431d-49a0-8fb4-882bcb2a2c39';
  $display->content['new-fefb76d3-431d-49a0-8fb4-882bcb2a2c39'] = $pane;
  $display->panels['section5_2cols2'][0] = 'new-fefb76d3-431d-49a0-8fb4-882bcb2a2c39';
  $display->hide_title = PANELS_TITLE_NONE;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['front'] = $page;

  return $pages;

}
