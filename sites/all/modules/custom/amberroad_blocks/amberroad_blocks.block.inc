<?php
/**
 * @file
 * Code containing block view handlers.
 */

/**
 * Handler function to display the left Social block in the footer.
 */
function amberroad_blocks_footer_social_links_left_block_view() {
  $block = array();
  $markup = "<span class='left_social_icons'>";
  $markup .= l(
    theme(
      'image',
      array(
        'path' => drupal_get_path('module', 'amberroad_blocks') . '/img/LinkedIn.gif',
        'width' => '32',
        'height' => '32',
        'alt' => 'LinkedIn',
        'title' => 'LinkedIn',
      )
    ),
    variable_get('amberroad_blocks_linkedin_page', 'http://www.linkedin.com/groupInvitation?groupID=2374608&amp;sharedKey=1A2F3F6276F1'),
    array(
      'html' => TRUE,
      'attributes' => array(
        'target' => '_blank',
      ),
    )
  );
  $markup .= l(
    theme(
      'image',
      array(
        'path' => drupal_get_path('module', 'amberroad_blocks') . '/img/Twitter.gif',
        'width' => '32',
        'height' => '32',
        'alt' => 'Twitter',
        'title' => 'Twitter',
      )
    ),
    variable_get('amberroad_blocks_twitter_page', 'http://twitter.com/GTMBestPractice'),
    array(
      'html' => TRUE,
      'attributes' => array(
        'target' => '_blank',
      ),
    )
  );
  $markup .= l(
    theme(
      'image',
      array(
        'path' => drupal_get_path('module', 'amberroad_blocks') . '/img/YouTube.gif',
        'width' => '32',
        'height' => '32',
        'alt' => 'YouTube',
        'title' => 'YouTube',
      )
    ),
    variable_get('amberroad_blocks_youtube_page', 'http://www.youtube.com/user/GTMBestPractices'),
    array(
      'html' => TRUE,
      'attributes' => array(
        'target' => '_blank',
      ),
    )
  );
  $markup .= l(
    theme(
      'image',
      array(
        'path' => drupal_get_path('module', 'amberroad_blocks') . '/img/rss.gif',
        'width' => '32',
        'height' => '32',
        'alt' => 'Blog',
        'title' => 'Blog',
      )
    ),
    variable_get('amberroad_blocks_blog_page', 'http://www.amberroad.com/html/rl_blogs.shtml'),
    array(
      'html' => TRUE,
      'attributes' => array(
        'target' => '_blank',
      ),
    )
  );
  $markup .= "</span>";

  $block['content'] = array(
    '#markup' => $markup
  );

  return $block;
}

/**
 * Handler function to display the right Social block in the footer.
 */
function amberroad_blocks_footer_social_links_right_block_view() {
  $block = array();
  $markup = "<span class='right_social_icons'>";
  $markup .= l(
    theme(
      'image',
      array(
        'path' => drupal_get_path('module', 'amberroad_blocks') . '/img/facebook.png',
        'width' => '32',
        'height' => '32',
        'alt' => 'Facebook',
        'title' => 'Facebook',
      )
    ),
    variable_get('amberroad_blocks_facebook_page', 'http://www.facebook.com/pages/Amber+Road/507641042664548'),
    array(
      'html' => TRUE,
      'attributes' => array(
        'target' => '_blank',
      ),
    )
  );
  $markup .= l(
    theme(
      'image',
      array(
        'path' => drupal_get_path('module', 'amberroad_blocks') . '/img/googlep.jpg',
        'width' => '32',
        'height' => '32',
        'alt' => 'Google Plus',
        'title' => 'Google Plus',
      )
    ),
    variable_get('amberroad_blocks_googlep_page', 'https://plus.google.com/100833232171840180230?prsrc=3'),
    array(
      'html' => TRUE,
      'attributes' => array(
        'target' => '_blank',
      ),
    )
  );
  $markup .= l(
    theme(
      'image',
      array(
        'path' => drupal_get_path('module', 'amberroad_blocks') . '/img/pinterest.jpg',
        'width' => '32',
        'height' => '32',
        'alt' => 'Pinterest',
        'title' => 'Pinterest',
      )
    ),
    variable_get('amberroad_blocks_pinterest_page', 'http://www.pinterest.com/gtmbestpractice'),
    array(
      'html' => TRUE,
      'attributes' => array(
        'target' => '_blank',
      ),
    )
  );

  $markup .= "</span>";

  $block['content'] = array(
    '#markup' => $markup
  );

  return $block;
}

/**
 * Handler function to display the mobile Social block in the footer.
 */
function amberroad_blocks_footer_social_links_mobile_block_view() {
  $block = array();
  $markup = "<span class='mobile_social_icons'>";
  $markup .= l(
    theme(
      'image',
      array(
        'path' => drupal_get_path('module', 'amberroad_blocks') . '/img/LinkedIn.gif',
        'width' => '32',
        'height' => '32',
        'alt' => 'LinkedIn',
        'title' => 'LinkedIn',
      )
    ),
    variable_get('amberroad_blocks_linkedin_page', 'http://www.linkedin.com/groupInvitation?groupID=2374608&amp;sharedKey=1A2F3F6276F1'),
    array(
      'html' => TRUE,
      'attributes' => array(
        'target' => '_blank',
      ),
    )
  );
  $markup .= l(
    theme(
      'image',
      array(
        'path' => drupal_get_path('module', 'amberroad_blocks') . '/img/Twitter.gif',
        'width' => '32',
        'height' => '32',
        'alt' => 'Twitter',
        'title' => 'Twitter',
      )
    ),
    variable_get('amberroad_blocks_twitter_page', 'http://twitter.com/GTMBestPractice'),
    array(
      'html' => TRUE,
      'attributes' => array(
        'target' => '_blank',
      ),
    )
  );
  $markup .= l(
    theme(
      'image',
      array(
        'path' => drupal_get_path('module', 'amberroad_blocks') . '/img/YouTube.gif',
        'width' => '32',
        'height' => '32',
        'alt' => 'YouTube',
        'title' => 'YouTube',
      )
    ),
    variable_get('amberroad_blocks_youtube_page', 'http://www.youtube.com/user/GTMBestPractices'),
    array(
      'html' => TRUE,
      'attributes' => array(
        'target' => '_blank',
      ),
    )
  );
  $markup .= l(
    theme(
      'image',
      array(
        'path' => drupal_get_path('module', 'amberroad_blocks') . '/img/rss.gif',
        'width' => '32',
        'height' => '32',
        'alt' => 'Blog',
        'title' => 'Blog',
      )
    ),
    variable_get('amberroad_blocks_blog_page', 'http://www.amberroad.com/html/rl_blogs.shtml'),
    array(
      'html' => TRUE,
      'attributes' => array(
        'target' => '_blank',
      ),
    )
  );
  $markup .= l(
    theme(
      'image',
      array(
        'path' => drupal_get_path('module', 'amberroad_blocks') . '/img/facebook.png',
        'width' => '32',
        'height' => '32',
        'alt' => 'Facebook',
        'title' => 'Facebook',
      )
    ),
    variable_get('amberroad_blocks_facebook_page', 'http://www.facebook.com/pages/Amber+Road/507641042664548'),
    array(
      'html' => TRUE,
      'attributes' => array(
        'target' => '_blank',
      ),
    )
  );
  $markup .= l(
    theme(
      'image',
      array(
        'path' => drupal_get_path('module', 'amberroad_blocks') . '/img/googlep.jpg',
        'width' => '32',
        'height' => '32',
        'alt' => 'Google Plus',
        'title' => 'Google Plus',
      )
    ),
    variable_get('amberroad_blocks_googlep_page', 'https://plus.google.com/100833232171840180230?prsrc=3'),
    array(
      'html' => TRUE,
      'attributes' => array(
        'target' => '_blank',
      ),
    )
  );
  $markup .= l(
    theme(
      'image',
      array(
        'path' => drupal_get_path('module', 'amberroad_blocks') . '/img/pinterest.jpg',
        'width' => '32',
        'height' => '32',
        'alt' => 'Pinterest',
        'title' => 'Pinterest',
      )
    ),
    variable_get('amberroad_blocks_pinterest_page', 'http://www.pinterest.com/gtmbestpractice'),
    array(
      'html' => TRUE,
      'attributes' => array(
        'target' => '_blank',
      ),
    )
  );

  $markup .= "</span>";

  $block['content'] = array(
    '#markup' => $markup
  );

  return $block;
}

/**
 * Helper function to display copyright info in the footer.
 */
function amberroad_blocks_footer_copyright_block_view() {
  $block = array();

  $copyright_text = variable_get('amberroad_copyright', '© ' . date('Y') . ' Amber Road, Inc.');
  $block['content'] = array(
    '#markup' => $copyright_text,
  );

  return $block;

}

/**
 * Handler function to display the language switch block in the footer.
 */
function amberroad_blocks_header_language_switch_flags_block_view() {
  $block = array();
  $urls = amberroad_blocks_get_translated_urls();
  $markup = "<span class='language_switch_flags'>";
  $markup .= l(
    t('English'),
    $urls['us'],
    array(
      'html' => TRUE,
      'attributes' => array(
        'target' => '_blank',
      ),
    )
  );
  $markup .= ' | '.l(
t('German'),
    $urls['de'],
    array(
      'html' => TRUE,
      'attributes' => array(
        'target' => '_blank',
      ),
    )
  );
  $markup .= ' | '.l(
    t('Chinese'),
    $urls['cn'],
    array(
      'html' => TRUE,
      'attributes' => array(
        'target' => '_blank',
      ),
    )
  );

  $markup .= "</span>";

  $block['content'] = array(
    '#markup' => $markup
  );

  return $block;
}

/*
 * Helper function to display featured block info in the homepage.
 */
function amberroad_blocks_homepage_featured_block_view() {
  $block = array();
  $markup = "<span class='homepage_featured'>";
  $markup .= l(
    theme(
      'image',
      array(
        'path' => drupal_get_path('module', 'amberroad_blocks') . '/img/featured_SC_Insights.jpg',
        'width' => '333',
        'height' => '230',
        'alt' => 'Featured Insight',
        'title' => 'Featured Insight',
      )
    ),
    'http://info.amberroad.com/rl_SC-Insights-Imports-and-Exports-Made-Easier-with-GTM.html',
    array(
      'html' => TRUE,
      'attributes' => array(
        'target' => '_blank',
      ),
    )
  );

  $markup .= "</span>";

  $block['content'] = array(
    '#markup' => $markup,
  );

  return $block;
}

/**
 * Helper function to display promo text in the homepage.
 */
function amberroad_blocks_homepage_promo_text_block_view() {
  $block = array();

  $block['content'] = array(
    '#markup' => '<p>' . variable_get('amberroad_homepage_promo_text', t('Our Global Trade Management Software Enables Goods to Flow Unimpeded Across <br>
      International Borders in the Most Efficient, Compliant and Profitable Way')) . '</p>',
  );

  return $block;
}

/**
 * Helper function to display promo text in the homepage.
 */
function amberroad_blocks_client_logo_rotator_block_view() {
  $block = array();

  drupal_add_js(drupal_get_path('module', 'amberroad_blocks') . '/js/infinite-rotator.js', 'file');
  $markup = "<div id='rotating-item-wrapperw'>";
  $markup .= theme(
    'image',
    array(
      'path' => drupal_get_path('module', 'amberroad_blocks') . '/img/clients-a.jpg',
      'attributes' => array(
        'class' => 'rotating-items',
      ),
    )
  );
  $markup .= theme(
    'image',
    array(
      'path' => drupal_get_path('module', 'amberroad_blocks') . '/img/clients-b.jpg',
      'attributes' => array(
        'class' => 'rotating-items',
      ),
    )
  );

  $markup .= '</div>';

  $block['content'] = array(
    '#markup' => $markup,
  );

  return $block;
}

/**
 * Helper function to display back page link in the press release page.
 */
function amberroad_blocks_press_release_back_link_block_view() {
  $block = array();

  $amberroad_site = variable_get('amberroad_site');
  if($amberroad_site == 'de'){
    $press_releases_link = 'unternehmen/pressemitteilungen.shtml';
  } else {
    $press_releases_link = 'html/press_releases.shtml';
  }

  $markup = "<div class='press_release-link amberroad-back-page-link'>";
  $markup .= l(t('Back to Press Summary'), $press_releases_link);

  $markup .= "</div>";

  $block['content'] = array(
    '#markup' => $markup,
  );

  return $block;
}

/**
 * Helper function to display interact with us block  in the press release page.
 */
function amberroad_blocks_press_release_interact_block_view() {
  $block = array();

  $markup = "<div class='press_release-interact amberroad-interact'>";
  $markup .= '<object width="235" border="0" height="606" align="right" codebase="http://download.macromedia.com/pub/shockwave/cabs/flash/swflash.cab#version=6,0,40,0" id="obj3" classid="clsid:D27CDB6E-AE6D-11CF-96B8-444553540000">
	              <param value="http://www.amberroad.com/flash/interact-new.swf" name="movie">
	              <param value="High" name="quality">
	              <embed width="235" height="606" name="obj3" type="application/x-shockwave-flash" pluginspage="http://www.macromedia.com/go/getflashplayer" src="http://www.amberroad.com/flash/interact-new.swf">
              </object>';

  $markup .= "</div>";

  $block['content'] = array(
    '#markup' => $markup,
  );

  return $block;
}

/**
 * Helper function to display press coverage banner in the press coverage listing page.
 */
function amberroad_blocks_banner_block_view($delta, $banner) {
  $block = array();

  $markup = "<div class='amberroad-banner {$delta}'>";
  if (empty($banner['link'])) {
    $markup .= theme('image',
      array(
        'path' => drupal_get_path('module', 'amberroad_blocks') . '/img/' . $banner['file'],
        'width' => '1000',
        'height' => '280',
      )
    );
  }
  else {
    $markup .= l(
      theme('image',
        array(
          'path' => drupal_get_path('module', 'amberroad_blocks') . '/img/' . $banner['file'],
          'width' => '1000',
          'height' => '280',
        )
      ),
      $banner['link'],
      array(
        'html' => TRUE,
        'attributes' => array(
          'target' => '_blank',
        ),
      )
    );
  }


  $markup .= "</div>";

  $block['content'] = array(
    '#markup' => $markup,
  );

  return $block;
}

/**
 * @return  Banner details by block name.
 */
function amberroad_blocks_banners($delta) {
  $audio_url = '';
  if ($delta == 'podcast_audio') {
    // Retrieve audio url from current podcast audio viewed.
    $podcast = menu_get_object();
    if (!empty($podcast) && $podcast->type === 'podcast') {
      $podcast = entity_metadata_wrapper('node', $podcast);
      $audio_url = $podcast->field_podcast_mp3->value();
      $audio_url = file_create_url($audio_url['uri']);
    }
  }

  $banners = array(
    'press_coverage_banner' => array(
      'link' => '',
      'file' => 'fl_stories.jpg',
    ),
    'awards_banner' => array(
      'link' => '',
      'file' => 'fl_awards.jpg',
    ),
    'press_room_banner' => array(
      'link' => '',
      'file' => 'fl_press.jpg',
    ),
    'press_release_banner' => array(
      'link' => '',
      'file' => 'fl_press.jpg',
    ),
    'career_banner' => array(
      'link' => 'http://stream.amberroad.com/amber_road_welcome/amber_road_welcome.html',
      'file' => 'fl_careers2.jpg',
    ),
    'testimonial_banner' => array(
      'link' => '',
      'file' => 'fl_case.jpg',
    ),
    'user_conference_banner' => array(
      'link' => '',
      'file' => 'fl_user-conference.jpg',
    ),
    'webinar_banner' => array(
      'link' => '',
      'file' => 'fl_webinars.jpg',
    ),
    'seminar_banner' => array(
      'link' => '',
      'file' => 'fl_seminars.jpg',
    ),
    'industry_conference_banner' => array(
      'link' => '',
      'file' => 'fl_conferences.jpg',
    ),
    'event_banner' => array(
      'link' => '',
      'file' => 'fl_events.jpg',
    ),
    'resource_banner' => array(
      'link' => '',
      'file' => 'fl_resources.jpg',
    ),
    'podcast_audio' => array(
      'link' => $audio_url,
      'file' => 'fl_podcast.jpg',
    ),
  );

  if (isset($banners[$delta])) {
    return $banners[$delta];
  }

  return '';
}

/**
 * Retrieve translated urls.
 */
function amberroad_blocks_get_translated_urls() {
  $urls = array(
    'us' => 'http://www.amberroad.com/',
    'de' => 'http://www.amberroad.de/',
    'cn' => 'http://cn.amberroad.com/',
  );

  $node = menu_get_object('node');
  if (!empty($node)) {
    $node = entity_metadata_wrapper('node', $node);

    // Retrieve China translation link.
    if ($node->__isset('field_chinese_translation_link')) {
      $url = $node->field_chinese_translation_link->value();
      if (!empty($url)) {
        $urls['cn'] = $url['url'];
      }
    }

    // Retrieve English translation link.
    if ($node->__isset('field_english_translation_link')) {
       $url = $node->field_english_translation_link->value();
      if (!empty($url)) {
        $urls['us'] = $url['url'];
      }
    }

    // Retrieve German translation link.
    if ($node->__isset('field_translation_link')) {
      $url = $node->field_translation_link->value();
      if (!empty($url)) {
        $urls['de'] = $url['url'];
      }
    }
  }
  else {
    // For listing page all three language have same urls.
    $current_path = drupal_get_path_alias(current_path());
    $urls['us'] = $urls['us'] . $current_path;
    $urls['de'] = $urls['de'] . $current_path;
    $urls['cn'] = $urls['cn'] . $current_path;
  }

  return $urls;
}

/**
 * Handler function to display the right Social block in the footer.
 */
function amberroad_blocks_how_to_apply_career_block_view() {
  $block = array();
  $mail = '';
  $mails = array(
    'India' => variable_get('amberroad_blocks_career_mail_ind', 'careersIND@amberroad.com'),
    'United States' => variable_get('amberroad_blocks_career_mail_us', 'careersUSA@amberroad.com'),
    'Europe' => variable_get('amberroad_blocks_career_mail_eu', 'careersEU@amberroad.com'),
    'Asia Pacific' => variable_get('amberroad_blocks_career_mail_ap', 'careersAP@amberroad.com'),
  );

  $region = menu_get_object('taxonomy_term', 2);
  if (!empty($region)) {
    $mail = $mails[$region->name];
  }

  $content = '<p><a name="apply"></a><strong>How to Apply</strong></p>';
  $content .= '<p>' . t('We value knowledge, motivation and integrity. If you thrive on a challenge, and are looking for an environment with scope for personal as well as professional development and advancement, send your resume and cover letter as an attachment, referencing the specific vacancy you are interested in to: !mail', array('!mail' => l($mail, 'mailto:' . $mail, array('absolute' => TRUE)))) . '</p>';

  $block['content'] = array(
    '#markup' => $content
  );

  return $block;
}
