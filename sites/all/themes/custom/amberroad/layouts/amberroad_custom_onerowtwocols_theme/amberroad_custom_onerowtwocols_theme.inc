<?php

/**
 * implementation of hook_panels_layouts()
 */
// Plugin definition
$plugin = array(
  'title' => t('Amber Road Custom OnerowTwocolumns'),
  'category' => t('Amberroad'),
  'icon' => 'amberroad_custom_onerowtwocols_theme.png',
  'theme' => 'amberroad_custom_onerowtwocols_theme',
  'regions' => array(
  	'content_banner' => t('Content Banner'),
  	'content_top' => t('Content Top'),
  	'content_main' => t('Content Main'),
  	'content_sidebar' => t('Content Right Sidebar'),
  ),
);
