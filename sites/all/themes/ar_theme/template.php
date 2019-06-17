<?php
/**
 * @file
 * Theme functions
 */

// Include all files from the includes directory.
$includes_path = dirname(__FILE__) . '/includes/*.inc';
foreach (glob($includes_path) as $filename) {
  require_once dirname(__FILE__) . '/includes/' . basename($filename);
}

/**
 * Implements template_preprocess_page().
 */
function ar_theme_preprocess_page(&$variables) {

  // Add copyright to theme.
  if ($copyright = theme_get_setting('copyright')) {
    $variables['copyright'] = check_markup($copyright['value'], $copyright['format']);
  }
  if(current_path() == 'front'){
    $variables['show_messages'] = FALSE;
  }

  $variables['amberroad_structure_data'] = '';
  if(variable_get('amberroad_structure_data_active', 0) == 1){
    //https://developers.google.com/search/docs/data-types/data-type-selector

    $structured_data = array(
      '@context' => "http://schema.org",
      '@type' => "Organization",
      "name" => variable_get('amberroad_structure_data_site_name'),
      'url' => variable_get('amberroad_structure_data_site_url'),
      "logo" => variable_get('amberroad_structure_data_site_logo'),
      'sameAs' => variable_get('amberroad_structure_data_same_as'),
      'contactPoint' => array(
        '@type' => 'ContactPoint',
        'telephone' => variable_get('amberroad_structure_data_site_contact_phone'),
        'contactType' => 'customer service',
      ),
    );
    $structured_data_json = json_encode($structured_data,JSON_UNESCAPED_SLASHES);



    $breadcrumbs_json = '';
    $active_trail = menu_get_active_trail();
    if(count($active_trail) > 0){
      $count = 0;
      $breadcrumbs = array();
      foreach($active_trail as $active_breadcrumb){
        $count ++;
        $breadcrumbs[] = array(
          '@type' => 'ListItem',
          'position' => $count,
          'item' => array(
            '@id' => url($active_breadcrumb['link_path'],array('absolute' => true)),
            'name' => $active_breadcrumb['link_title'] == '' ? 'Amber Road' : $active_breadcrumb['link_title'],
          ),
        );
      }
      $breadcrumbs = array(
        '@context' => 'http://schema.org',
        '@type' => 'BreadcrumbList',
        'itemListElement' => $breadcrumbs
      );
      $breadcrumbs_json = json_encode($breadcrumbs);
    }

    $variables['amberroad_structure_data'] = "<script type=\"application/ld+json\">$structured_data_json</script><script type=\"application/ld+json\">$breadcrumbs_json</script>";


  }

}