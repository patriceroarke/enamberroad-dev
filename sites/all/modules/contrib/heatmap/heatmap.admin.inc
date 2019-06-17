<?php

/**
 * @file
 * Page for controlling the user administration area.
 */

/**
 * Administration area for HeatMap.
 */
function heatmap_admin() {
  // Check that the heatmap javascript is downloaded
  $js = libraries_get_path('heatmap.js-develop'); 
  if (!$js || file_exists('/' . $js . '/build/heatmap.min.js')) {
    drupal_set_message(t('You have to download the !link into your libraries folder before enabling HeatMap (ex. /heatmap.js-develop/build/heatmap.min.js)', 
      array('!link' => l('heatmap.js', 'http://www.patrick-wied.at/static/heatmapjs/get-heatmap.html'))), 'error');
      variable_set('heatmap_enabled', '0');
  }

  // Set a start value for the date the first time this page is entered
  if (!variable_get('heatmap_initdate', 0)) {
    variable_set('heatmap_initdate', time());
  }
  
  $form = array();

  // Get themes 
  $themes = list_themes();
  $themelist = array();
  $default_value = array();
  foreach($themes as $themename => $themevalues) {
    if ($themevalues->status) $themelist[$themename] = $themename;
  }
  
  $form['visibility'] = array(
    '#type' => 'fieldset',
    '#title' => t('Visibility'),
    '#description' => t('These settings modifies when the tracking should be loaded and when it should be run.'),
  );

  $form['visibility']['heatmap_enable'] = array(
    '#type' => 'fieldset',
    '#title' => t('Enable heatmapping'),
  );
  
  $form['visibility']['heatmap_enable']['heatmap_enabled'] = array(
    '#type' => 'checkbox',
    '#default_value' => variable_get('heatmap_enabled', '0'),
    '#title' => t('HeatMap enabled'),
    '#description' => t('Check this when you want to track')
  );  
  
  $form['visibility']['heatmap_theme'] = array(
    '#type' => 'fieldset',
    '#title' => t('Enable theme'),
  );
  
  $form['visibility']['heatmap_theme']['heatmap_themes'] = array(
    '#type' => 'checkboxes',
    '#title' => t('Choose the themes where the heatmap should be tracked'),
    '#default_value' => variable_get('heatmap_themes', array(variable_get('theme_default', ''))),
    '#options' => $themelist
  );  
  
  $form['visibility']['heatmap_path'] = array(
    '#type' => 'fieldset',
    '#title' => t('Only records specific pages'),
  );

  $form['visibility']['heatmap_path']['heatmap_show'] = array(
    '#type' => 'radios',
    '#default_value' => variable_get('heatmap_show', '0'),
    '#options' => array(
      '0' => t('All pages except those listed'),
      '1' => t('Only the listed pages'),
      '2' => t('Pages on which this PHP code returns TRUE (experts only, requires PHP module)'),
    ),
  );
  
  if (!module_exists('php') || !user_access('use PHP for settings')) {
    $form['visibility']['heatmap_path']['heatmap_show']['2'] = array('#disabled' => TRUE);
  }  

  $form['visibility']['heatmap_path']['heatmap_paths'] = array(
    '#type' => 'textarea',
    '#default_value' => variable_get('heatmap_paths', 'admin/*'),
    '#description' => t("Specify pages by using their paths. Enter one path per line. The '*' character is a wildcard. Example paths are blog for the blog page and blog/* for every personal blog. <front> is the front page. If the PHP option is chosen, enter PHP code between <?php ?>. Note that executing incorrect PHP code can break your Drupal site."),
    '#required' => FALSE,
  );

  $form['visibility']['user_roles'] = array(
    '#type' => 'fieldset',
    '#title' => t('Only record specific user roles'),
  );

  $form['visibility']['user_roles']['heatmap_user_roles'] = array(
    '#type' => 'checkboxes',
    '#multiple' => TRUE,
    '#default_value' => variable_get('heatmap_user_roles', array('1')),
    '#options' => user_roles(),
  );
  
  $form['performance'] = array(
    '#type' => 'fieldset',
    '#title' => t('Performance'),
    '#description' => t('These settings modifies how the heatmap data is stored so that the website can handle big traffic. '),
  );

  $form['performance']['fragments'] = array(
    '#type' => 'fieldset',
    '#title' => t('Fragment the traffic'),
    '#description' => t('If you have to heavy traffic load from storing the HeatMaps you can choose a fragment of the traffic to be saved. This is recommended for high traffic sites only using relational databases (MySQL, MariaDB etc.)')
  );
  
  for($i = 100; $i >= 1; $i--) {
    $percent[$i] = $i . '%';
  }

  $form['performance']['fragments']['heatmap_fragment'] = array(
    '#type' => 'select',
    '#default_value' => variable_get('heatmap_fragment', 100),
    '#title' => t('How large traffic base should be saved'),
    '#options' => $percent
  );
  
  $form['performance']['storage_type'] = array(
    '#type' => 'fieldset',
    '#title' => t('Type of storage'),
    '#description' => t('The type of storage of the HeatMap data. Use something else then built in storage when available.')
  );
  
  $storage_type = array(
    'heatmap' => t('Built in storage type (relational)'),
  );
  
  // Add add-on modules
  foreach (module_implements('heatmap_info') as $module) {
    $result = module_invoke($module, 'heatmap_info');
    if (isset($result['name'])) {
      $storage_type[$module] = t('!storage storage', array('!storage' => $result['name']));
    }
  }

  $form['performance']['storage_type']['heatmap_storage_type'] = array(
    '#type' => 'radios',
    '#default_value' => variable_get('heatmap_storage_type', 'heatmap'),
    '#required' => true,
    '#title' => t('Storage Type'),
    '#options' => $storage_type,
    '#description' => t('Check the storage type you want to use')
  );

  $form['performance']['memcache'] = array(
    '#type' => 'fieldset',
    '#title' => t('Memcache layer'),
    '#description' => t('Enabled this if you have Memcache module enabled and want the site to perform better.')
  );
  
  $form['performance']['memcache']['heatmap_memcache_enabled'] = array(
    '#type' => 'checkbox',
    '#title' => t('Enable Memcache aggregation (Recommended, requires Memcache module)'),
    '#default_value' => variable_get('heatmap_memcache_enabled', '0'),
  );
  
  $form['performance']['memcache']['heatmap_memcache_batch_time'] = array(
    '#type' => 'textfield',
    '#title' => t('Memcache batch time'),
    '#description' => t('The amount of seconds to wait between every batch release. If a to big number is given data might fall out of the memory before it becomes persistent.'),
    '#default_value' => variable_get('heatmap_memcache_batch_time', '300'),
  );  
  
  if (!module_exists('memcache')) {
    $form['performance']['memcache']['heatmap_memcache_enabled']['#disabled'] = true;
    $form['performance']['memcache']['heatmap_memcache_batch_time']['#disabled'] = true;
  }
  
  foreach (module_implements('heatmap_settings') as $module) {
    $result = module_invoke($module, 'heatmap_settings');
    if (is_array($result)) {
      $info = module_invoke($module, 'heatmap_info');
      $form['performance']['storage_type'][$module . '_fieldset'] = array(
        '#type' => 'fieldset',
        '#title' => t('!storage settings', array('!storage' => $info['name'])),
        '#states' => array('visible' => array('input[name="heatmap_storage_type"]' => array('value' => $module)))
      );
      
      $form['performance']['storage_type'][$module . '_fieldset'] = array_merge($form['performance']['storage_type'][$module . '_fieldset'], $result);
    }
  }
  
  $form['rendering'] = array(
    '#type' => 'fieldset',
    '#title' => t('Rendering'),
    '#description' => t('These settings modifies how the heatmap looks.'),
  );  
  
  $form['rendering']['heatmap_settings'] = array(
    '#type' => 'fieldset',
    '#title' => t('Theme settings'),
    '#description' => t('If you fill in these settings you can get a heatmap of all the sizes. Note that showing all sizes will be bad for responsive design pages. You have to fill in both these for this to work.')
  );
  
  // Only show theme settings if they are checked
  foreach($themelist as $theme) {
    $form['rendering']['heatmap_settings']['heatmap_theme_' . $theme] = array(
      '#type' => 'fieldset',
      '#title' => t('Settings for !theme', array('!theme' => $theme)),
      '#description' => t('If you fill in these settings you can get a heatmap of all the sizes. Note that this will be bad for responsive design pages. You have to fill in both these for this to work.'),
      '#states' => array('visible' => array('input[name="heatmap_themes[' . $theme . ']"]' => array('checked' => true)))
    );  

    $form['rendering']['heatmap_settings']['heatmap_theme_' . $theme]['heatmap_alignment_' . $theme] = array(
      '#type' => 'select',
      '#default_value' => variable_get('heatmap_alignment_' . $theme, '0'),
      '#title' => t('Alignment of the main container'),
      '#options' => array(
        '0' => t('None'),
        '1' => t('Left alignment'),
        '2' => t('Center alignment'),
        '3' => t('Right alignment'),
      ),
    );  
    
    $form['rendering']['heatmap_settings']['heatmap_theme_' . $theme]['heatmap_alignment_class_' . $theme] = array(
      '#type' => 'textfield',
      '#default_value' => variable_get('heatmap_alignment_class_' . $theme, ''),
      '#title' => t('Container identifier. Either class (e.g. .container) or id (e.g. #container).'),
    );
  }
  
  $form['#submit'][] = 'heatmap_admin_submit';
  
  return system_settings_form($form);
}

/*
 * Validation of the admin form
 */
function heatmap_admin_validate($form, &$form_values) {
  if (!module_exists('php') || !user_access('use PHP for settings')) {
    if ($form_values['values']['heatmap_show'] == 2) {
      form_set_error('heatmap_show', t('You do not have the right to enable this'));
    }
  }

  foreach (module_implements('heatmap_validation') as $module) {
    // Only run if chosen
    if($form_values['values']['heatmap_storage_type'] == $module) {
      module_invoke($module, 'heatmap_validation', $form_values['values']);
    }
  }
}

/*
 * Validation of the admin form
 */
function heatmap_admin_submit($form, &$form_values) {
  foreach (module_implements('heatmap_submitting') as $module) {
    // Only run if chosen
    if($form_values['values']['heatmap_storage_type'] == $module) {
      $form_values['values'] = module_invoke($module, 'heatmap_submitting', $form_values['values']);
    }
  }
  
}