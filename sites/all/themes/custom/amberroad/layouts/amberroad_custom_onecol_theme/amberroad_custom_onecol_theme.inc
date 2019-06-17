<?php

/**
 * implementation of hook_panels_layouts()
 */
// Plugin definition
$plugin = array(
  'title' => t('Amber Road Custom One column'),
  'category' => t('Columns: 1'),
  'icon' => 'amberroad_custom_onecol_theme.png',
  'theme' => 'amberroad_custom_onecol_theme',
  'regions' => array(
  	'content_banner' => t('Content Banner'),
  	'content_main' => t('Content Main'),
  ),
);
