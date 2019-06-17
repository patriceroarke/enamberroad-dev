<?php
/**
 * @file
 * amberroad_panels.panels_default.inc
 */

/**
 * Implements hook_default_panels_mini().
 */
function amberroad_panels_default_panels_mini() {
  $export = array();

  $mini = new stdClass();
  $mini->disabled = FALSE; /* Edit this to true to make a default mini disabled initially */
  $mini->api_version = 1;
  $mini->name = 'footer_menu';
  $mini->category = '';
  $mini->admin_title = 'Footer menu';
  $mini->admin_description = '';
  $mini->requiredcontexts = array();
  $mini->contexts = array();
  $mini->relationships = array();
  $display = new panels_display();
  $display->layout = 'easydisplay_5_col';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'col1' => NULL,
      'col2' => NULL,
      'col3' => NULL,
      'col4' => NULL,
      'col5' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = '';
  $display->uuid = '6bd75008-73a8-4617-8512-d4a98f9ec108';
  $display->content = array();
  $display->panels = array();
  $pane = new stdClass();
  $pane->pid = 'new-38d93e8b-7625-41e5-8f95-2d22c82f330d';
  $pane->panel = 'col1';
  $pane->type = 'block';
  $pane->subtype = 'menu_block-1';
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
  $pane->uuid = '38d93e8b-7625-41e5-8f95-2d22c82f330d';
  $display->content['new-38d93e8b-7625-41e5-8f95-2d22c82f330d'] = $pane;
  $display->panels['col1'][0] = 'new-38d93e8b-7625-41e5-8f95-2d22c82f330d';
  $pane = new stdClass();
  $pane->pid = 'new-ac3875a3-5cf2-4450-8890-1bfdcd8fc70a';
  $pane->panel = 'col2';
  $pane->type = 'block';
  $pane->subtype = 'menu_block-2';
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
  $pane->uuid = 'ac3875a3-5cf2-4450-8890-1bfdcd8fc70a';
  $display->content['new-ac3875a3-5cf2-4450-8890-1bfdcd8fc70a'] = $pane;
  $display->panels['col2'][0] = 'new-ac3875a3-5cf2-4450-8890-1bfdcd8fc70a';
  $pane = new stdClass();
  $pane->pid = 'new-c9878fe6-5cd6-4a00-ba81-0fd9e3e9e81f';
  $pane->panel = 'col3';
  $pane->type = 'block';
  $pane->subtype = 'menu_block-4';
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
  $pane->uuid = 'c9878fe6-5cd6-4a00-ba81-0fd9e3e9e81f';
  $display->content['new-c9878fe6-5cd6-4a00-ba81-0fd9e3e9e81f'] = $pane;
  $display->panels['col3'][0] = 'new-c9878fe6-5cd6-4a00-ba81-0fd9e3e9e81f';
  $pane = new stdClass();
  $pane->pid = 'new-3b3787c6-b6b8-4de2-971a-0a3f66669f42';
  $pane->panel = 'col4';
  $pane->type = 'block';
  $pane->subtype = 'menu_block-3';
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
  $pane->uuid = '3b3787c6-b6b8-4de2-971a-0a3f66669f42';
  $display->content['new-3b3787c6-b6b8-4de2-971a-0a3f66669f42'] = $pane;
  $display->panels['col4'][0] = 'new-3b3787c6-b6b8-4de2-971a-0a3f66669f42';
  $pane = new stdClass();
  $pane->pid = 'new-24db5cbb-a636-4cab-a9e4-6f89bee3fbb6';
  $pane->panel = 'col5';
  $pane->type = 'block';
  $pane->subtype = 'menu_block-5';
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
  $pane->uuid = '24db5cbb-a636-4cab-a9e4-6f89bee3fbb6';
  $display->content['new-24db5cbb-a636-4cab-a9e4-6f89bee3fbb6'] = $pane;
  $display->panels['col5'][0] = 'new-24db5cbb-a636-4cab-a9e4-6f89bee3fbb6';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = 'new-ac3875a3-5cf2-4450-8890-1bfdcd8fc70a';
  $mini->display = $display;
  $export['footer_menu'] = $mini;

  return $export;
}
