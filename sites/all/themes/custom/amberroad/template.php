<?php

/**
 * Override or insert variables into the maintenance page template.
 *
 * @param $vars
 *   An array of variables to pass to the theme template.
 */
function amberroad_preprocess_maintenance_page(&$vars) {
  // When a variable is manipulated or added in preprocess_html or
  // preprocess_page, that same work is probably needed for the maintenance page
  // as well, so we can just re-use those functions to do that work here.
  // amberroad_preprocess_html($vars);
  // amberroad_preprocess_page($vars);

  // This preprocessor will also be used if the db is inactive. To ensure your
  // theme is used, add the following line to your settings.php file:
  // $conf['maintenance_theme'] = 'amberroad';
  // Also, check $vars['db_is_active'] before doing any db queries.
}

/**
 * Implements hook_modernizr_load_alter().
 *
 * @return
 *   An array to be output as yepnope testObjects.
 */
/* -- Delete this line if you want to use this function
function amberroad_modernizr_load_alter(&$load) {

}

/**
 * Implements hook_preprocess_html()
 *
 * @param $vars
 *   An array of variables to pass to the theme template.
 */
/* -- Delete this line if you want to use this function
function amberroad_preprocess_html(&$vars) {

}

/**
 * Override or insert variables into the page template.
 *
 * @param $vars
 *   An array of variables to pass to the theme template.
 */
/* -- Delete this line if you want to use this function
function amberroad_preprocess_page(&$vars) {

}

/**
 * Override or insert variables into the region templates.
 *
 * @param $vars
 *   An array of variables to pass to the theme template.
 */
/* -- Delete this line if you want to use this function
function amberroad_preprocess_region(&$vars) {

}
// */

/**
 * Override or insert variables into the block templates.
 *
 * @param $vars
 *   An array of variables to pass to the theme template.
 */
/* -- Delete this line if you want to use this function
function amberroad_preprocess_block(&$vars) {

}
// */

/**
 * Override or insert variables into the entity template.
 *
 * @param $vars
 *   An array of variables to pass to the theme template.
 */
/* -- Delete this line if you want to use this function
function amberroad_preprocess_entity(&$vars) {

}
// */

/**
 * Override or insert variables into the node template.
 *
 * @param $vars
 *   An array of variables to pass to the theme template.
 */
/* -- Delete this line if you want to use this function
function amberroad_preprocess_node(&$vars) {
  $node = $vars['node'];
}
// */

/**
 * Override or insert variables into the field template.
 *
 * @param $vars
 *   An array of variables to pass to the theme template.
 * @param $hook
 *   The name of the template being rendered ("field" in this case.)
 */
/* -- Delete this line if you want to use this function
function amberroad_preprocess_field(&$vars, $hook) {

}
// */

/**
 * Override or insert variables into the comment template.
 *
 * @param $vars
 *   An array of variables to pass to the theme template.
 */
/* -- Delete this line if you want to use this function
function amberroad_preprocess_comment(&$vars) {
  $comment = $vars['comment'];
}
// */

/**
 * Override or insert variables into the views template.
 *
 * @param $vars
 *   An array of variables to pass to the theme template.
 */
/* -- Delete this line if you want to use this function
function amberroad_preprocess_views_view(&$vars) {
  $view = $vars['view'];
}
// */


/**
 * Override or insert css on the site.
 *
 * @param $css
 *   An array of all CSS items being requested on the page.
 */
/* -- Delete this line if you want to use this function
function amberroad_css_alter(&$css) {

}
// */

/**
 * Override or insert javascript on the site.
 *
 * @param $js
 *   An array of all JavaScript being presented on the page.
 */
/* -- Delete this line if you want to use this function
function amberroad_js_alter(&$js) {

}
// */

/**
 * Add page title to breadcrumb trail.
 */
function amberroad_breadcrumb($variables) {
  $breadcrumb = $variables['breadcrumb'];
  if (!empty($breadcrumb)) {
    // Alter breadcrumb for node type Press release and Testimonial content.

    $node = menu_get_object();
    if (!empty($node) && ($node->type == 'press_release' || $node->type == 'testimonial') || $node->type == 'podcast') {
      $breadcrumb = array();
      $breadcrumb[] = l('Home', '<front>');
      $breadcrumb[] = l('Company','html/company.shtml');
      if ($node->type == 'press_release') {
        $breadcrumb[] = l('Press room','html/press.shtml');
        $breadcrumb[] = 'Press Releases';
      }
      elseif ($node->type == 'testimonial') {
        $breadcrumb[] = l('About Us','html/about_us.shtml');
        $breadcrumb[] = 'Testimonials';
      }
      elseif ($node->type == 'podcast') {
        $breadcrumb[1] = l('Resources ','html/resources.shtml');
        $breadcrumb[2] = t('Podcasts');
        unset($breadcrumb[3]);
      }
    }
    else {
      // Adding the title of the current page to the breadcrumb.
      $breadcrumb[] = drupal_get_title();
    }

    if (drupal_get_path_alias() == 'global-knowledge/home.shtml') {
      unset($breadcrumb[1]);
    }
    // Provide a navigational heading to give context for breadcrumb links to
    // screen-reader users. Make the heading invisible with .element-invisible.
    $output = '<h2 class="element-invisible">' . t('You are here') . '</h2>';

    $output .= '<div class="breadcrumb">' . implode(' &#8594; ', $breadcrumb) . '</div>';
    return $output;
  }
}

/**
 * Set audio player open in new tab.
 */
function amberroad_file_link($variables) {
  $file = $variables['file'];
  $icon_directory = $variables['icon_directory'];

  $url = file_create_url($file->uri);
  $icon = theme('file_icon', array('file' => $file, 'icon_directory' => $icon_directory));

  // Set options as per anchor format described at
  // http://microformats.org/wiki/file-format-examples
  $options = array(
      'attributes' => array(
          'type' => $file->filemime . '; length=' . $file->filesize,
      ),
  );

  // Use the description as the link text if available.
  if (empty($file->description)) {
    $link_text = $file->filename;
  } else {
    $link_text = $file->description;
    $options['attributes']['title'] = check_plain($file->filename);
  }

  //open files of particular mime types in new window
  $new_window_mimetypes = array('audio/mpeg');
  if (in_array($file->filemime, $new_window_mimetypes)) {
    $options['attributes']['target'] = '_blank';
  }

  return '<span class="file">' . $icon . ' ' . l($link_text, $url, $options) . '</span>';

}

/**
 * Preprocess the search result page.
 */
function amberroad_preprocess_search_result(&$variables) {
  $variables['snippet'] = str_replace('...', '', $variables['snippet']);
  $variables['snippet'] = trim($variables['snippet']);
  $node = $variables['result']['node'];

  // Set external url for some content types whose node view has not themed.
  $node_types = array('awards', 'press_coverage', 'resource', 'seminar', 'industry_conference', 'webinar');
  if (in_array($node->type, $node_types)) {
    if (isset($node->field_event_link['und'][0]['url'])) {
      $url = $node->field_event_link['und'][0]['url'];
    }
    elseif (isset($node->field_external_link['und'][0]['url'])) {
      $url = $node->field_external_link['und'][0]['url'];
    }
    if (isset($node->field_external_link['und'][0]['url'])) {
      $url = $node->field_external_link['und'][0]['url'];
    }
    $variables['url'] = $url;
  }

  // Hide author info.
  $variables['info'] = '';
}

/**
* Implements hook_preprocess_search_results().
*
* Show search result page count.
*/
function amberroad_preprocess_search_results(&$vars) {
  // search.module shows 10 items per page (this isn't customizable)
  $itemsPerPage = 10;

  // Determine which page is being viewed
  // If $_REQUEST['page'] is not set, we are on page 1
  $currentPage = (isset($_REQUEST['page']) ? $_REQUEST['page'] : 0) + 1;

  // Get the total number of results from the global pager
  $total = $GLOBALS['pager_total_items'][0];

  // Determine which results are being shown ("Showing results x through y")
  $start = (10 * $currentPage) - 9;
  // If on the last page, only go up to $total, not the total that COULD be
  // shown on the page. This prevents things like "Displaying 11-20 of 17".
  $end = (($itemsPerPage * $currentPage) >= $total) ? $total : ($itemsPerPage * $currentPage);

  // If there is more than one page of results:
  if ($total > $itemsPerPage) {
    $vars['search_totals'] = '<div class="search-result-count">' .
    t('Displaying !start - !end of !total results', array(
      '!start' => $start,
      '!end' => $end,
      '!total' => $total,
    )) . '</div>';
  }
  else {
    // Only one page of results, so make it simpler
    $vars['search_totals'] = '<div class="search-result-count">' .
    t('Displaying !total !results_label', array(
      '!total' => $total,
      // Be smart about labels: show "result" for one, "results" for multiple
      '!results_label' => format_plural($total, 'result', 'results'),
    )) . '</div>';
  }
}

function amberroad_preprocess_html(&$vars) {
  $path = drupal_get_path_alias();
  $aliases = explode('/', $path);
  $vars['classes_array'][] = drupal_clean_css_identifier(end($aliases));
}




/**
 * Returns HTML for an individual feed item for display in the block.
 *
 * @param $variables
 *   An associative array containing:
 *   - item: The item to be displayed.
 *   - feed: Not used.
 *
 * @ingroup themeable
 */
/*function at_theme_aggregator_block_item($variables) {
  // Display the external link to the item.
  return '--<a href="' . check_url($variables['item']->link) . '">' . check_plain($variables['item']->title) . "</a>\n";
}*/