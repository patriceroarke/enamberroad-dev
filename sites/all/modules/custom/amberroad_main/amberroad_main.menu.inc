<?php
/**
 * @file
 * This file will create the various menus.
 */

/**
  * Create the all Menus in sites.
  */
function amberroad_main_create_menu() {
  $menus = array(
    array(
      'menu_name' => 'menu-footer-top',
      'title' => t('Footer Top Menu'),
      'description' => '',
    ),
    array(
      'menu_name' => 'menu-footer-bottom',
      'title' => t('Footer Bottom Menu'),
      'description' => '',
    ),
    array(
      'menu_name' => 'menu-header',
      'title' => t('Header Menu'),
      'description' => '',
    ),
    array(
      'menu_name' => 'amberroad-main-menu',
      'title' => t('Amber road main menu'),
      'description' => '',
    ),
  );

  // Save menu group into menu_custom table.
  foreach ($menus as $menu) {
    // Look the table first if the data does exist.
    $exists = db_query("SELECT title FROM {menu_custom} WHERE menu_name=:menu_name", array(':menu_name' => $menu['menu_name']))->fetchField();
    // Save the record if the data does not exist.
    if (!$exists) {
      menu_save($menu);
    }
  }

  // Create menu link for footer top.
  amberroad_main_create_footer_top_menu_links();

  // Create menu link for footer bottom.
  amberroad_main_create_footer_bottom_menu_links();

  // Create menu link for header.
  amberroad_main_create_header_menu_links();
}

/**
 * Create and save the menu links programmatically.
 */
function amberroad_main_create_footer_top_menu_links() {
  $items = array(
    array(
      'link_path' => '<front>',
      'link_title' => 'Home Page',
      'menu_name' => 'menu-footer-top',
      'weight' => 0,
      'plid' => 0,
      'module' => 'menu',
    ),
    array(
      'link_path' => '<front>',
      'link_title' => 'Company',
      'menu_name' => 'menu-footer-top',
      'weight' => 1,
      'plid' => 0,
      'module' => 'menu',
    ),
    array(
      'link_path' => '<front>',
      'link_title' => 'Solutions',
      'menu_name' => 'menu-footer-top',
      'weight' => 2,
      'plid' => 0,
      'module' => 'menu',
    ),
    array(
      'link_path' => '<front>',
      'link_title' => 'Industries',
      'menu_name' => 'menu-footer-top',
      'weight' => 3,
      'plid' => 0,
      'module' => 'menu',
    ),
    array(
      'link_path' => '<front>',
      'link_title' => 'Services',
      'menu_name' => 'menu-footer-top',
      'weight' => 4,
      'plid' => 0,
      'module' => 'menu',
    ),
    array(
      'link_path' => '<front>',
      'link_title' => 'Customers',
      'menu_name' => 'menu-footer-top',
      'weight' => 5,
      'plid' => 0,
      'module' => 'menu',
    ),
    array(
      'link_path' => 'html/press.shtml',
      'link_title' => 'Press Room',
      'menu_name' => 'menu-footer-top',
      'weight' => 6,
      'plid' => 0,
      'module' => 'menu',
    ),
  );

  amberroad_menu_create_menu_links($items);
}

/**
 * Create and save the menu links programmatically.
 */
function amberroad_main_create_footer_bottom_menu_links() {
  $items = array(
    array(
      'link_path' => '<front>',
      'link_title' => 'Contact',
      'menu_name' => 'menu-footer-bottom',
      'weight' => 0,
      'plid' => 0,
      'module' => 'menu',
    ),
    array(
      'link_path' => '<front>',
      'link_title' => 'Investor Relations',
      'menu_name' => 'menu-footer-bottom',
      'weight' => 1,
      'plid' => 0,
      'module' => 'menu',
    ),
    array(
      'link_path' => '<front>',
      'link_title' => 'Client Login',
      'menu_name' => 'menu-footer-bottom',
      'weight' => 2,
      'plid' => 0,
      'module' => 'menu',
    ),
    array(
      'link_path' => '<front>',
      'link_title' => 'Privacy',
      'menu_name' => 'menu-footer-bottom',
      'weight' => 3,
      'plid' => 0,
      'module' => 'menu',
    ),
    array(
      'link_path' => '<front>',
      'link_title' => 'Terms of Use',
      'menu_name' => 'menu-footer-bottom',
      'weight' => 4,
      'plid' => 0,
      'module' => 'menu',
    ),
    array(
      'link_path' => '<front>',
      'link_title' => 'Sales Representatives',
      'menu_name' => 'menu-footer-bottom',
      'weight' => 5,
      'plid' => 0,
      'module' => 'menu',
    ),
  );

  amberroad_menu_create_menu_links($items);
}

/**
 * Create and save the menu links programmatically.
 */
function amberroad_main_create_header_menu_links() {
  $items = array(
    array(
      'link_path' => '<front>',
      'link_title' => 'Blogs',
      'menu_name' => 'menu-header',
      'weight' => 0,
      'plid' => 0,
      'module' => 'menu',
    ),
    array(
      'link_path' => '<front>',
      'link_title' => 'Contact Us',
      'menu_name' => 'menu-header',
      'weight' => 1,
      'plid' => 0,
      'module' => 'menu',
    ),
    array(
      'link_path' => '<front>',
      'link_title' => 'Customer Login',
      'menu_name' => 'menu-header',
      'weight' => 2,
      'plid' => 0,
      'module' => 'menu',
    ),
  );

  amberroad_menu_create_menu_links($items);
}

/**
 * Create and save the menu links programmatically.
 */
function amberroad_main_create_main_menu_links() {
  $items = array(
    array(
      'link_path' => '<front>',
      'link_title' => 'Company',
      'menu_name' => 'amberroad-main-menu',
      'weight' => 0,
      'plid' => 0,
      'module' => 'menu',
    ),
    array(
      'link_path' => '<front>',
      'link_title' => 'Enterprise Suite',
      'menu_name' => 'amberroad-main-menu',
      'weight' => 1,
      'plid' => 0,
      'module' => 'menu',
    ),
    array(
      'link_path' => '<front>',
      'link_title' => 'Mid-Market Solutions',
      'menu_name' => 'amberroad-main-menu',
      'weight' => 2,
      'plid' => 0,
      'module' => 'menu',
    ),
    array(
      'link_path' => '<front>',
      'link_title' => 'Global Knowledge®',
      'menu_name' => 'amberroad-main-menu',
      'weight' => 3,
      'plid' => 0,
      'module' => 'menu',
    ),
    array(
      'link_path' => '<front>',
      'link_title' => 'Resources',
      'menu_name' => 'amberroad-main-menu',
      'weight' => 4,
      'plid' => 0,
      'module' => 'menu',
    ),
  );

  amberroad_menu_create_menu_links($items);
}

/**
 * Create and save the menu links programmatically.
 */
function amberroad_main_create_child_main_menu_links() {
  // Create menu items for Company.
  $mlid = amberroad_main_mlid_load('amberroad-main-menu', 'Company');
  $items = array(
    array(
      'link_path' => '<front>',
      'link_title' => 'About Us',
      'menu_name' => 'amberroad-main-menu',
      'weight' => 0,
      'plid' => $mlid,
      'module' => 'menu',
    ),
    array(
      'link_path' => '<front>',
      'link_title' => 'Contact Us',
      'menu_name' => 'amberroad-main-menu',
      'weight' => 1,
      'plid' => $mlid,
      'module' => 'menu',
    ),
    array(
      'link_path' => 'http://investor.amberroad.com/',
      'link_title' => 'Investor Relations',
      'menu_name' => 'amberroad-main-menu',
      'weight' => 2,
      'plid' => $mlid,
      'module' => 'menu',
    ),
    array(
      'link_path' => '<front>',
      'link_title' => 'Events',
      'menu_name' => 'amberroad-main-menu',
      'weight' => 3,
      'plid' => $mlid,
      'module' => 'menu',
    ),
    array(
      'link_path' => '<front>',
      'link_title' => 'Careers',
      'menu_name' => 'amberroad-main-menu',
      'weight' => 4,
      'plid' => $mlid,
      'module' => 'menu',
    ),
    array(
      'link_path' => '<front>',
      'link_title' => 'Partners',
      'menu_name' => 'amberroad-main-menu',
      'weight' => 5,
      'plid' => $mlid,
      'module' => 'menu',
    ),
    array(
      'link_path' => '<front>',
      'link_title' => 'Services',
      'menu_name' => 'amberroad-main-menu',
      'weight' => 6,
      'plid' => $mlid,
      'module' => 'menu',
    ),
    array(
      'link_path' => 'html/press.shtml',
      'link_title' => 'Press Room',
      'menu_name' => 'amberroad-main-menu',
      'weight' => 7,
      'plid' => $mlid,
      'module' => 'menu',
    ),
    array(
      'link_path' => '<front>',
      'link_title' => 'Platform',
      'menu_name' => 'amberroad-main-menu',
      'weight' => 8,
      'plid' => $mlid,
      'module' => 'menu',
    ),
    array(
      'link_path' => '<front>',
      'link_title' => 'Industries',
      'menu_name' => 'amberroad-main-menu',
      'weight' => 9,
      'plid' => $mlid,
      'module' => 'menu',
    ),
  );
  amberroad_menu_create_menu_links($items);

  // Create menu items for Enterprise Suite.
  $mlid = amberroad_main_mlid_load('amberroad-main-menu', 'Enterprise Suite');
  $items = array(
    array(
      'link_path' => '<front>',
      'link_title' => 'Sourcing Optimization',
      'menu_name' => 'amberroad-main-menu',
      'weight' => 0,
      'plid' => $mlid,
      'module' => 'menu',
    ),
    array(
      'link_path' => '<front>',
      'link_title' => 'Supplier Management',
      'menu_name' => 'amberroad-main-menu',
      'weight' => 1,
      'plid' => $mlid,
      'module' => 'menu',
    ),
    array(
      'link_path' => '<front>',
      'link_title' => 'Transport Management',
      'menu_name' => 'amberroad-main-menu',
      'weight' => 2,
      'plid' => $mlid,
      'module' => 'menu',
    ),
    array(
      'link_path' => '<front>',
      'link_title' => 'Export Management',
      'menu_name' => 'amberroad-main-menu',
      'weight' => 3,
      'plid' => $mlid,
      'module' => 'menu',
    ),
    array(
      'link_path' => '<front>',
      'link_title' => 'Supply Chain Visibility',
      'menu_name' => 'amberroad-main-menu',
      'weight' => 4,
      'plid' => $mlid,
      'module' => 'menu',
    ),
    array(
      'link_path' => '<front>',
      'link_title' => 'Import Management',
      'menu_name' => 'amberroad-main-menu',
      'weight' => 5,
      'plid' => $mlid,
      'module' => 'menu',
    ),
    array(
      'link_path' => '<front>',
      'link_title' => 'Duty Management',
      'menu_name' => 'amberroad-main-menu',
      'weight' => 6,
      'plid' => $mlid,
      'module' => 'menu',
    ),
  );
  amberroad_menu_create_menu_links($items);

  // Create menu items for Mid-Market Solutions.
  $mlid = amberroad_main_mlid_load('amberroad-main-menu', 'Mid-Market Solutions');
  $items = array(
    array(
      'link_path' => '<front>',
      'link_title' => 'Sourcing Optimization',
      'menu_name' => 'amberroad-main-menu',
      'weight' => 0,
      'plid' => $mlid,
      'module' => 'menu',
    ),
    array(
      'link_path' => '<front>',
      'link_title' => 'Transport Management',
      'menu_name' => 'amberroad-main-menu',
      'weight' => 1,
      'plid' => $mlid,
      'module' => 'menu',
    ),
    array(
      'link_path' => '<front>',
      'link_title' => 'Export Management',
      'menu_name' => 'amberroad-main-menu',
      'weight' => 2,
      'plid' => $mlid,
      'module' => 'menu',
    ),
    array(
      'link_path' => '<front>',
      'link_title' => 'Supply Chain Visibility',
      'menu_name' => 'amberroad-main-menu',
      'weight' => 3,
      'plid' => $mlid,
      'module' => 'menu',
    ),
  );
  amberroad_menu_create_menu_links($items);

  // Create menu items for Global Knowledge.
  $mlid = amberroad_main_mlid_load('amberroad-main-menu', 'Global Knowledge®');
  $items = array(
    array(
      'link_path' => '<front>',
      'link_title' => 'GLOBAL TRADE CONTENT - GLOBAL KNOWLEDGE',
      'menu_name' => 'amberroad-main-menu',
      'weight' => 0,
      'plid' => $mlid,
      'module' => 'menu',
    ),
    array(
      'link_path' => '<front>',
      'link_title' => 'DEPTH & BREADTH OF TRADE REGULATORY CONTENT',
      'menu_name' => 'amberroad-main-menu',
      'weight' => 1,
      'plid' => $mlid,
      'module' => 'menu',
    ),
  );
  amberroad_menu_create_menu_links($items);

  // Create menu items for Resources.
  $mlid = amberroad_main_mlid_load('amberroad-main-menu', 'Resources');
  $items = array(
    array(
      'link_path' => '<front>',
      'link_title' => 'Literature',
      'menu_name' => 'amberroad-main-menu',
      'weight' => 0,
      'plid' => $mlid,
      'module' => 'menu',
    ),
    array(
      'link_path' => '<front>',
      'link_title' => 'GTM Newsletter',
      'menu_name' => 'amberroad-main-menu',
      'weight' => 1,
      'plid' => $mlid,
      'module' => 'menu',
    ),
    array(
      'link_path' => '<front>',
      'link_title' => 'Multi-Media',
      'menu_name' => 'amberroad-main-menu',
      'weight' => 2,
      'plid' => $mlid,
      'module' => 'menu',
    ),
    array(
      'link_path' => '<front>',
      'link_title' => 'Community',
      'menu_name' => 'amberroad-main-menu',
      'weight' => 3,
      'plid' => $mlid,
      'module' => 'menu',
    ),
    array(
      'link_path' => '<front>',
      'link_title' => 'Industry Resources',
      'menu_name' => 'amberroad-main-menu',
      'weight' => 4,
      'plid' => $mlid,
      'module' => 'menu',
    ),
     array(
      'link_path' => '<front>',
      'link_title' => 'Next Steps',
      'menu_name' => 'amberroad-main-menu',
      'weight' => 5,
      'plid' => $mlid,
      'module' => 'menu',
    ),
  );
  amberroad_menu_create_menu_links($items);
}

/**
 * Create menu items in database.
 *
 * Will be used only in creating new menu items.
 */
function amberroad_menu_create_menu_links($items) {
  $exists = FALSE;
  foreach ($items as $item) {
    // Look the table first if the data does exist.
    // @todo: Need to rething of having this condition as it won't be possible to
    //use existing menu name in any future menu.
    /*
     * $exists = db_query("SELECT mlid from {menu_links} WHERE link_title=:link_title AND link_path=:link_path",
      array(
        ':link_title' =>  $item['link_title'],
        ':link_path' => $item['link_path']
      ))->fetchField();
     *
     */

    // Save the record if the data does not exist.
    if (!$exists) {
      menu_link_save($item);
    }
  }
}

/**
 * Create menu items for GTM NEWSLETTER type under RESOURCES menu item.
 */
function amberroad_main_gtm_newsletter_create_menu_items() {
  $mlid = amberroad_main_mlid_load('amberroad-main-menu', 'GTM Newsletter');

  $items = array(
    array(
      'link_path' => 'http://info.amberroad.com/gtm.html',
      'link_title' => 'Subscribe',
      'menu_name' => 'amberroad-main-menu',
      'weight' => 0,
      'plid' => $mlid,
      'module' => 'menu',
    ),
  );

  foreach ($items as $item) {
    menu_link_save($item);
  }
}

/**
 * Create menu items for MULTI-MEDIA type under RESOURCES menu item.
 */
function amberroad_main_multimedia_create_menu_items() {
  $mlid = amberroad_main_mlid_load('amberroad-main-menu', 'Multi-Media');

  $items = array(
    array(
      'link_path' => 'http://stream.amberroad.com/overview/index.html',
      'link_title' => 'Amber Road Video',
      'menu_name' => 'amberroad-main-menu',
      'weight' => 0,
      'plid' => $mlid,
      'module' => 'menu',
    ),
    array(
      'link_path' => 'http://stream.amberroad.com/gtm_ondemand/index.html',
      'link_title' => 'GTM Videos',
      'menu_name' => 'amberroad-main-menu',
      'weight' => 1,
      'plid' => $mlid,
      'module' => 'menu',
    ),
    array(
      'link_path' => 'html/rl_podcasts.shtml',
      'link_title' => 'Podcasts',
      'menu_name' => 'amberroad-main-menu',
      'weight' => 2,
      'plid' => $mlid,
      'module' => 'menu',
    ),
    array(
      'link_path' => drupal_get_normal_path('html/rl_product_tours.shtml'),
      'link_title' => 'Product Tours',
      'menu_name' => 'amberroad-main-menu',
      'weight' => 3,
      'plid' => $mlid,
      'module' => 'menu',
    ),
    array(
      'link_path' => 'html/rl_webinars.shtml',
      'link_title' => 'Archived Webinars',
      'menu_name' => 'amberroad-main-menu',
      'weight' => 4,
      'plid' => $mlid,
      'module' => 'menu',
    ),
  );

  foreach ($items as $item) {
    menu_link_save($item);
  }
}

/**
 * Create menu items for COMMUNITY type under RESOURCES menu item.
 */
function amberroad_main_community_create_menu_items() {
  $mlid = amberroad_main_mlid_load('amberroad-main-menu', 'Community');

  $items = array(
    array(
      'link_path' => '<front>',
      'link_title' => 'Blogs',
      'menu_name' => 'amberroad-main-menu',
      'weight' => 0,
      'plid' => $mlid,
      'module' => 'menu',
    ),
    array(
      'link_path' => 'http://www.linkedin.com/groupInvitation?groupID=2374608&sharedKey=1A2F3F6276F1',
      'link_title' => 'LinkedIn',
      'menu_name' => 'amberroad-main-menu',
      'weight' => 1,
      'plid' => $mlid,
      'module' => 'menu',
    ),
    array(
      'link_path' => 'http://info.amberroad.com/gtm.html',
      'link_title' => 'Subscribe',
      'menu_name' => 'amberroad-main-menu',
      'weight' => 2,
      'plid' => $mlid,
      'module' => 'menu',
    ),
    array(
      'link_path' => 'http://twitter.com/GTMBestPractice',
      'link_title' => 'Twitter',
      'menu_name' => 'amberroad-main-menu',
      'weight' => 3,
      'plid' => $mlid,
      'module' => 'menu',
    ),
    array(
      'link_path' => 'http://www.youtube.com/user/GTMBestPractices',
      'link_title' => 'YouTube',
      'menu_name' => 'amberroad-main-menu',
      'weight' => 4,
      'plid' => $mlid,
      'module' => 'menu',
    ),
    array(
      'link_path' => 'http://www.facebook.com/pages/Amber+Road/507641042664548',
      'link_title' => 'Facebook',
      'menu_name' => 'amberroad-main-menu',
      'weight' => 5,
      'plid' => $mlid,
      'module' => 'menu',
    ),
    array(
      'link_path' => 'https://plus.google.com/100833232171840180230?prsrc=3',
      'link_title' => 'Google+',
      'menu_name' => 'amberroad-main-menu',
      'weight' => 6,
      'plid' => $mlid,
      'module' => 'menu',
    ),
    array(
      'link_path' => 'http://www.pinterest.com/gtmbestpractice/',
      'link_title' => 'Pinterest',
      'menu_name' => 'amberroad-main-menu',
      'weight' => 7,
      'plid' => $mlid,
      'module' => 'menu',
    ),
  );

  foreach ($items as $item) {
    menu_link_save($item);
  }
}

/**
 * Create menu items for Next Steps type under RESOURCES menu item.
 */
function amberroad_main_next_steps_create_menu_items() {
  $mlid = amberroad_main_mlid_load('amberroad-main-menu', 'Next Steps');

  $items = array(
    array(
      'link_path' => '<front>',
      'link_title' => 'Contact Us',
      'menu_name' => 'amberroad-main-menu',
      'weight' => 0,
      'plid' => $mlid,
      'module' => 'menu',
    ),
    array(
      'link_path' => 'http://info.amberroad.com/rl_rd.html',
      'link_title' => 'Request a Demo',
      'menu_name' => 'amberroad-main-menu',
      'weight' => 1,
      'plid' => $mlid,
      'module' => 'menu',
    ),
  );

  foreach ($items as $item) {
    menu_link_save($item);
  }
}

/**
 * Create sitemap menu item.
 */
function amberroad_main_create_sitemap_menu_item() {
  $items = array(
    array(
      'link_path' => 'sitemap',
      'link_title' => 'Site Map',
      'menu_name' => 'menu-footer-bottom',
      'weight' => 6,
      'plid' => 0,
      'module' => 'menu',
    ),
  );
  amberroad_menu_create_menu_links($items);
}

