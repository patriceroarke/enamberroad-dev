<?php
/**
 * @file
 * Provides the admin functionality for the Selective Tweets module.
 */

/**
 * Menu callback; Builds the admin form.
 *
 * @return
 *   Renderable array.
 */
function selective_tweets_admin_form($form, &$form_state) {
  $form = array();

  $form['selective_tweets_api_account'] = array(
    '#type' => 'fieldset',
    '#title' => t('Twitter API'),
    '#description' => t('Fill in the Twitter API account details in order to connect to Twitter.'),
  );

  $form['selective_tweets_api_account']['selective_tweets_api_version'] = array(
    '#type' => 'textfield',
    '#title' => t('Twitter API version'),
    '#max_length' => 5,
    '#required' => TRUE,
    '#default_value' => variable_get('selective_tweets_api_version', SELECTIVE_TWEETS_API_VERSION),
    '#description' => t('Change this only if you know what you are doing.'),
  );

  $form['selective_tweets_api_account']['selective_tweets_api_base_url'] = array(
    '#type' => 'textfield',
    '#title' => t('Twitter API base url'),
    '#required' => TRUE,
    '#default_value' => variable_get('selective_tweets_api_base_url', SELECTIVE_TWEETS_API_BASE_URL),
    '#description' => t('Without trailing slash.') . ' ' . t('Change this only if you know what you are doing.'),
  );

  $form['selective_tweets_api_account']['selective_tweets_consumer_key'] = array(
    '#type' => 'textfield',
    '#title' => t('Consumer Key'),
    '#max_length' => 255,
    '#required' => TRUE,
    '#default_value' => variable_get('selective_tweets_consumer_key', ''),
  );

  $form['selective_tweets_api_account']['selective_tweets_consumer_secret'] = array(
    '#type' => 'textfield',
    '#title' => t('Consumer Secret'),
    '#max_length' => 255,
    '#required' => TRUE,
    '#default_value' => variable_get('selective_tweets_consumer_secret', ''),
  );

  $form['selective_tweets_api_account']['selective_tweets_oauth_token'] = array(
    '#type' => 'textfield',
    '#title' => t('Oauth Token'),
    '#max_length' => 255,
    '#required' => TRUE,
    '#default_value' => variable_get('selective_tweets_oauth_token', ''),
  );

  $form['selective_tweets_api_account']['selective_tweets_oauth_token_secret'] = array(
    '#type' => 'textfield',
    '#title' => t('Oauth Token Secret'),
    '#max_length' => 255,
    '#required' => TRUE,
    '#default_value' => variable_get('selective_tweets_oauth_token_secret', ''),
  );


  $form['selective_tweets_development'] = array(
    '#type' => 'fieldset',
    '#title' => t('Development'),
  );

  $form['selective_tweets_development']['selective_tweets_debug'] = array(
    '#type' => 'checkbox',
    '#title' => t('Log error messages in database'),
    '#default_value' => variable_get('selective_tweets_debug', FALSE),
    '#description' => t('When checked, all error messages concerning Selective Tweets will be logged by watchdog.'),
  );

  $form['selective_tweets_development']['selective_tweets_debug_help_text'] = array(
    '#markup' => t('The dblog module is currently %status.', array('%status' => module_exists('dblog') ? t('enabled') : t('disabled'))),
  );

  $form['#submit'][] = 'selective_tweets_admin_form_cache_clear';

  return system_settings_form($form);
}

/**
 * Submit handler; Extra submit handler to clear cached data.
 */
function selective_tweets_admin_form_cache_clear($form, &$form_state) {
  cache_clear_all('selective_tweets', SELECTIVE_TWEETS_CACHE_BIN, TRUE);
  drupal_set_message(t('Cached data of Selective Tweets has been cleared.'));
}

/**
 * Form constructor for the Selective Tweets block configuration form.
 *
 * @param $edit
 *   (optional) An associative array of information retrieved by
 *   selective_tweets_block_load() if an existing block is being edited, or an
 *   empty array otherwise. Defaults to array().
 *
 * @ingroup forms
 */
function selective_tweets_custom_block_form($edit = array()) {
  $edit += array(
    'delta' => '',
    'info' => '',
  );
  $edit += _selective_tweets_block_properties();

  // Get template file content for informative reasons.
  $template_content = @file_get_contents(drupal_get_path('module', 'selective_tweets') . '/templates/selective-tweets-raw-tweet.tpl.php');

  if ($template_content) {
    $template_content = check_plain($template_content);
  }

  $token_support_text = _selective_tweets_token_support() ? ' ' . t('This field supports tokens if enabled on this block.') : '';

  $form_states_embed_mode = array(
    'visible' => array(
      ':input[name="render_mode"]' => array('value' => SELECTIVE_TWEETS_EMBED),
    ),
  );

  $form_states_raw_mode = array(
    'visible' => array(
      ':input[name="render_mode"]' => array('value' => SELECTIVE_TWEETS_RAW),
    ),
  );

  $form_states_select_mode_search = array(
    'visible' => array(
      ':input[name="display_mode"]' => array('value' => ST_SELECTION_MODE_SEARCH),
    ),
  );

  $form['info'] = array(
    '#type' => 'textfield',
    '#title' => t('Block description'),
    '#default_value' => $edit['info'],
    '#maxlength' => 64,
    '#description' => t('A brief description of your block. Used on the <a href="@overview">Blocks administration page</a>.', array('@overview' => url('admin/structure/block'))),
    '#required' => TRUE,
  );

  $form['block_delta'] = array(
    '#type' => 'machine_name',
    '#default_value' => $edit['delta'],
    '#maxlength' => 32,
    '#machine_name' => array(
      'label' => t('Block delta'),
      'exists' => 'selective_tweets_element_validate_delta_exists',
      'source' => array('settings', 'info'),
      'replace_pattern' => '([^a-z0-9_]+)|([_]{2,})',
      'replace' => '_',
      'error' => t('The machine-readable name must unique and contain only lowercase letters, numbers, and single underscores.'),
    ),
    '#disabled' => !empty($edit['delta']),
    '#required' => TRUE,
  );

  $form['render_mode'] = array(
    '#type' => 'radios',
    '#title' => t('Render mode'),
    '#options' => array(
      SELECTIVE_TWEETS_EMBED => t('Render embedded Tweet widgets'),
      SELECTIVE_TWEETS_RAW => t('Render raw HTML, free to theme'),
    ),
    '#default_value' => $edit['render_mode'],
    '#description' => t('Depending on this selection, the settings below will adjust. Go through them carefully. Embedded Tweets are widgets, styled by Twitter. Choose raw HTML to style the Tweets yourself. You can override the raw tweet template file to suit your needs.'),
  );

  $form['selective_tweets_selection_settings'] = array(
    '#type' => 'fieldset',
    '#title' => t('Tweet selection settings'),
    '#description' => t('Determine which Tweets should be displayed.'),
    '#collapsible' => TRUE,
    '#collapsed' => FALSE,
  );

  $form['selective_tweets_selection_settings']['display_mode'] = array(
    '#type' => 'radios',
    '#title' => t('Twitter feed selection mode'),
    '#options' => array(
      ST_SELECTION_MODE_LIVE => t('Populate feed by most recent Tweets'),
      ST_SELECTION_MODE_FAVORITES => t('Populate feed by Tweets of any timeline favorited by the given Twitter account'),
      ST_SELECTION_MODE_SEARCH => t('Populate feed by Tweets filtered by'),
    ),
    '#default_value' => $edit['display_mode'],
    '#required' => TRUE,
  );

  $form['selective_tweets_selection_settings']['screen_name'] = array(
    '#type' => 'textfield',
    '#title' => t('From Twitter account'),
    '#default_value' => $edit['screen_name'],
    '#description' => t('Twitter account name to load Tweets from.') . $token_support_text,
    '#states' => array(
      'required' => array(
        ':input[name="display_mode"]' => array(
          array('value' => ST_SELECTION_MODE_LIVE),
          array('value' => ST_SELECTION_MODE_FAVORITES),
        ),
      ),
      'visible' => array(
        ':input[name="display_mode"]' => array(
          array('value' => ST_SELECTION_MODE_LIVE),
          array('value' => ST_SELECTION_MODE_FAVORITES),
        ),
      ),
    ),
  );

  $form['selective_tweets_selection_settings']['search_help_text'] = array(
    '#type' => 'item',
    '#markup' => t('Notice by Twitter:') . ' <em>' . t('"Please note that Twitter’s search service and, by extension, the Search API is not meant to be an exhaustive source of Tweets. Not all Tweets will be indexed or made available via the search interface."') . '</em><br/>' . t("If you are not getting the desired result, it's possible these Tweets are not indexed by the Twitter search index."),
    '#states' => $form_states_select_mode_search,
    '#prefix' => '<div style="margin-left:30px;">',
    '#suffix' => '</div>',
  );

  $form['selective_tweets_selection_settings']['from_account'] = array(
    '#type' => 'textfield',
    '#title' => t('From Twitter accounts'),
    '#default_value' => $edit['from_account'],
    '#description' => t('Fill in accounts separated by spaces. This will gather all Tweets from the given users. HINT: When displaying recent Tweets of one Twitter user, select "most recent Tweets" in the Twitter feed selection mode instead of using this filter. Input example: "drupal drupalcon" or "@drupal @drupalcon".') . $token_support_text,
    '#states' => $form_states_select_mode_search,
    '#prefix' => '<div style="margin-left:30px;">',
    '#suffix' => '</div>',
  );

  $form['selective_tweets_selection_settings']['to_account'] = array(
    '#type' => 'textfield',
    '#title' => t('To Twitter accounts'),
    '#default_value' => $edit['to_account'],
    '#description' => t('Fill in accounts separated by OR, AND or spaces (= AND). Separating by AND will gather all Tweets addressed to all given users. Separating by OR will gather all Tweets addressed to at least one of the given users. Input example: "drupal OR drupalcon" or "@drupal AND @drupalcon".') . $token_support_text,
    '#states' => $form_states_select_mode_search,
    '#prefix' => '<div style="margin-left:30px;">',
    '#suffix' => '</div>',
  );

  $form['selective_tweets_selection_settings']['user_mentions'] = array(
    '#type' => 'textfield',
    '#title' => t('Containing user mentions'),
    '#default_value' => $edit['user_mentions'],
    '#description' => t('Fill in user names separated by OR, AND or spaces (= AND). Separating by AND will gather all Tweets containing all user mentions. Separating by OR will gather all Tweets containing at least one of the user mentions. Input example: "drupal OR drupalcon" or "@drupal @drupalcon".') . $token_support_text,
    '#states' => $form_states_select_mode_search,
    '#prefix' => '<div style="margin-left:30px;">',
    '#suffix' => '</div>',
  );

  $form['selective_tweets_selection_settings']['hashtags'] = array(
    '#type' => 'textfield',
    '#title' => t('Containing hashtags'),
    '#default_value' => $edit['hashtags'],
    '#description' => t('Fill in hashtags separated by OR, AND or spaces (= AND). Separating by AND will gather all Tweets containing all hashtags. Separating by OR will gather all Tweets containing at least one of the hashtags. Input example: "Superbowl AND Pizza" or "#Pizza #Cheese".') . $token_support_text,
    '#states' => $form_states_select_mode_search,
    '#prefix' => '<div style="margin-left:30px;">',
    '#suffix' => '</div>',
  );

  $form['selective_tweets_selection_settings']['banned_words'] = array(
    '#type' => 'textfield',
    '#title' => t('Hide Tweets containing these words'),
    '#default_value' => $edit['banned_words'],
    '#description' => t('Fill in words separated by spaces. Hashtags and user mentions are also taken into account. Input example: "drugs alcohol".') . $token_support_text,
    '#states' => $form_states_select_mode_search,
    '#prefix' => '<div style="margin-left:30px;">',
    '#suffix' => '</div>',
  );

  $form['selective_tweets_selection_settings']['include_retweets'] = array(
    '#type' => 'checkbox',
    '#title' => t('Include retweets'),
    '#default_value' => $edit['include_retweets'],
    '#description' => t('When checked, retweets will be displayed too.'),
    '#states' => $form_states_raw_mode,
  );

  if (_selective_tweets_token_support()) {
    $options = array();
    $token_types = array();

    foreach (entity_get_info() as $entity_type => $entity_info) {
      $options[$entity_type] = $entity_info['label'];
      $token_types[] = $entity_type;
    }

    // Add 'current user' as extra option because this differs from user pages.
    $options['current_user'] = t('Current user');

    $form['selective_tweets_selection_settings']['token_entity_type'] = array(
      '#type' => 'select',
      '#title' => t('Enable tokens for the following entity type'),
      '#options' => $options,
      '#default_value' => $edit['token_entity_type'],
      '#empty_option' => t("Don't use tokens"),
      '#empty_value' => 0,
      '#description' => 'Select an entity type to use its content as input for the filters above. For example, use hashtags straight out of a node\'s field while viewing the node page. The Selective Tweets block will display different Tweets on each node page using their own hashtags.',
    );

    $form['selective_tweets_selection_settings']['token_tree'] = array(
      '#type' => 'item',
      '#theme' => 'token_tree',
      '#token_types' => $token_types,
      '#states' => array(
        'visible' => array(
          ':input[name="token_entity_type"]' => array('!value' => 0),
        ),
      ),
    );
  }
  else {
    $form['selective_tweets_selection_settings']['token_entity_type'] = array(
      '#type' => 'value',
      '#value' => 0,
    );
    $form['selective_tweets_selection_settings']['token_support_help_text'] = array(
      '#type' => 'item',
      '#title' => t('Use tokens of the following entity type'),
      '#markup' => t('Enable the <em>token</em> and <em>entity</em> module to unlock token support.'),
    );
  }

  $form['selective_tweets_display_settings'] = array(
    '#type' => 'fieldset',
    '#title' => t('Display settings'),
    '#description' => t('Determine how the Tweets should be displayed.'),
    '#collapsible' => TRUE,
    '#collapsed' => TRUE,
  );

  $form['selective_tweets_display_settings']['initial_count'] = array(
    '#type' => 'textfield',
    '#title' => t('Initial number of Tweets'),
    '#default_value' => $edit['initial_count'],
    '#description' => t('Number of Tweets displayed at page load.'),
    '#element_validate' => array('element_validate_integer_positive'),
    '#size' => 10,
    '#required' => TRUE,
  );

  $form['selective_tweets_display_settings']['count'] = array(
    '#type' => 'textfield',
    '#title' => t('Tweets per loaded page'),
    '#default_value' => $edit['count'],
    '#description' => t('Number of Tweets to load when clicking "Load more". Set to zero to hide the load more link.'),
    '#element_validate' => array('selective_tweets_element_validate_integer_zero_or_higher'),
    '#size' => 10,
    '#required' => TRUE,
  );

  $form['selective_tweets_display_settings']['load_more_text'] = array(
    '#type' => 'textfield',
    '#title' => t('Load more text'),
    '#default_value' => $edit['load_more_text'],
    '#description' => t('Text used as "load more" link.') . $token_support_text,
    '#required' => TRUE,
    '#prefix' => '<div style="margin-left:30px;">',
    '#suffix' => '</div>',
    '#states' => array(
      'visible' => array(
        ':input[name="count"]' => array('!value' => '0'),
      ),
    ),
  );

  $form['selective_tweets_display_settings']['insert_links'] = array(
    '#type' => 'checkbox',
    '#title' => t('Insert links'),
    '#default_value' => $edit['insert_links'],
    '#description' => t('When checked, hashtags, users and urls will be converted into clickable links.'),
    '#states' => $form_states_raw_mode,
  );

  $form['selective_tweets_display_settings']['theme'] = array(
    '#type' => 'select',
    '#title' => t('Widget color theme'),
    '#options' => array(
      SELECTIVE_TWEETS_LIGHT => t('Light'),
      SELECTIVE_TWEETS_DARK => t('Dark'),
    ),
    '#default_value' => $edit['theme'],
    '#required' => TRUE,
    '#states' => $form_states_embed_mode,
  );

  $form['selective_tweets_display_settings']['hide_media'] = array(
    '#type' => 'checkbox',
    '#title' => t('Hide media'),
    '#default_value' => $edit['hide_media'],
    '#description' => t('When checked, links in a Tweet are not expanded to photo, video, or link previews.'),
    '#states' => $form_states_embed_mode,
  );

  $form['selective_tweets_display_settings']['hide_thread'] = array(
    '#type' => 'checkbox',
    '#title' => t('Hide thread'),
    '#default_value' => $edit['hide_thread'],
    '#description' => t('When checked, a collapsed version of the previous Tweet in a conversation thread will not be displayed when the Tweet is in reply to another Tweet.'),
    '#states' => $form_states_embed_mode,
  );

  $form['selective_tweets_display_settings']['maxwidth'] = array(
    '#type' => 'textfield',
    '#title' => t('Maximum width of a rendered Tweet'),
    '#field_suffix' => t('pixels'),
    '#default_value' => $edit['maxwidth'],
    '#description' => t('The maximum width of a rendered Tweet in whole pixels. This value must be between 220 and 550 inclusive. A supplied value under or over the allowed range will be returned as the minimum or maximum supported width respectively.'),
    '#element_validate' => array('element_validate_integer_positive'),
    '#size' => 10,
    '#required' => TRUE,
    '#states' => $form_states_embed_mode,
  );

  $form['selective_tweets_display_settings']['maxheight'] = array(
    '#type' => 'textfield',
    '#title' => t('Maximum height of the timeline'),
    '#field_suffix' => t('pixels'),
    '#default_value' => $edit['maxheight'],
    '#description' => t('The maximum height of the Tweets container. A scrollbar will appear when the loaded Tweets exceed this threshold.'),
    '#element_validate' => array('selective_tweets_element_validate_integer_zero_or_higher'),
    '#size' => 10,
    '#required' => TRUE,
  );

  $form['selective_tweets_display_settings']['maxheight_style'] = array(
    '#type' => 'radios',
    '#title' => t('Maximum height behaviour'),
    '#options' => array(
      'height' => t('Fixed max height: the content container will always have the chosen height'),
      'max-height' => t('Variable max height: the content container will be smaller than the chosen height until the loaded Tweets exceed this threshold.')
    ),
    '#default_value' => $edit['maxheight_style'],
    '#required' => TRUE,
    '#prefix' => '<div style="margin-left:30px;">',
    '#suffix' => '</div>',
    '#states' => array(
      'visible' => array(
        ':input[name="maxheight"]' => array('!value' => '0'),
      ),
    ),
  );

  $form['selective_tweets_display_settings']['loading_text'] = array(
    '#type' => 'textfield',
    '#title' => t('Loading text'),
    '#default_value' => $edit['loading_text'],
    '#description' => t('This text is displayed in the block while the Tweets are getting loaded.') . $token_support_text,
    '#required' => TRUE,
  );

  $form['selective_tweets_display_settings']['html_wrapper'] = array(
    '#type' => 'select',
    '#title' => t('HTML wrapper element'),
    '#options' => array(
      'div' => 'div',
      'ul' => 'ul',
      'ol' => 'ol',
    ),
    '#default_value' => $edit['html_wrapper'],
    '#description' => t('Select a wrapper element for wrapping all Tweets. This can be useful for displaying Tweets as an HTML list. When selecting "ul" or "ol", make sure the overridden Tweet template file contains an "li" wrapper element in order to display them as list items.'),
    '#required' => TRUE,
    '#states' => $form_states_raw_mode,
  );

  $form['selective_tweets_display_settings']['empty_text'] = array(
    '#type' => 'textfield',
    '#title' => t('Empty text'),
    '#default_value' => $edit['empty_text'],
    '#description' => t('No results returned after fetching Tweets due to error or zero results on search request. Choose the message that will appear in the block when 0 Tweets are returned. Leave blank to hide the message.') . $token_support_text,
  );

  $form['selective_tweets_display_settings']['hide_block_if_empty'] = array(
    '#type' => 'checkbox',
    '#title' => t('Hide full block if empty'),
    '#default_value' => $edit['hide_block_if_empty'],
    '#description' => t('NOTICE: This only works when ajax loading is disabled (ajax "load more" will still be functional; see the Performance part on this page) and the <em>Empty text</em> field above is empty.'),
  );

  $form['selective_tweets_performance'] = array(
    '#type' => 'fieldset',
    '#title' => t('Performance'),
    '#description' => t('Determine how long cached Tweets can be served to save on Twitter API requests.<br><strong>IMPORTANT:</strong> Twitter API calls are limited per 15 minutes. This makes it very important to set a caching period of at least a minute or more if possible.'),
    '#collapsible' => TRUE,
    '#collapsed' => TRUE,
  );

  $form['selective_tweets_performance']['pull_cached_time'] = array(
    '#type' => 'textfield',
    '#title' => t('Time to cache pulled Tweets'),
    '#field_prefix' => t('Retrieve new Tweets from Twitter every'),
    '#field_suffix' => t('minute(s)') . '.',
    '#default_value' => $edit['pull_cached_time'],
    '#description' => t('This time equals the maximum time before a new Tweet may be displayed on this website. The actual pulling of Tweets takes place on page load. Cron is not involved.'),
    '#element_validate' => array('element_validate_integer_positive'),
    '#size' => 6,
    '#required' => TRUE,
  );

  $form['selective_tweets_performance']['stack_cached_time'] = array(
    '#type' => 'textfield',
    '#title' => t('Time to drop Tweet stack'),
    '#field_prefix' => t('Drop cached Tweet stack every'),
    '#field_suffix' => t('minute(s)') . '.',
    '#default_value' => $edit['stack_cached_time'],
    '#description' => t('This time indicates after how many minutes the Tweets in cache are dropped at the moment new Tweets are pulled in (logically this setting would be a plurality of the setting above). This way deleted or unfavorited Tweets cannot be displayed unintentionally from cache. New Tweets are added to this stack as long as it does not get dropped. Set to zero to never drop the cached Tweet stack.'),
    '#element_validate' => array('selective_tweets_element_validate_integer_zero_or_higher'),
    '#size' => 6,
    '#required' => TRUE,
  );

  $form['selective_tweets_performance']['tweet_stack_max'] = array(
    '#type' => 'textfield',
    '#title' => t('Maximum amount of Tweets in stack'),
    '#field_suffix' => t('Tweets'),
    '#default_value' => $edit['tweet_stack_max'],
    '#description' => t('The maximum amount of Tweets in the cache stack at any given time. When pulling in new Tweets from Twitter, Drupal will never save more Tweets than this amount. The oldest Tweets will be removed as new ones come in. This setting prevents the database from growing too large when adding new Tweets to the stack.'),
    '#element_validate' => array('element_validate_integer_positive'),
    '#size' => 10,
    '#required' => TRUE,
  );

  $form['selective_tweets_performance']['cache_rendered_tweet'] = array(
    '#type' => 'checkbox',
    '#title' => t('Cache rendered Tweets'),
    '#default_value' => $edit['cache_rendered_tweet'],
    '#description' => t('Turn this caching off if you are displaying the "time ago" value in the template file. Otherwise, leave it on for better performance. For the render mode "embedded Tweet widgets", this caching is always turned on automatically.'),
    '#states' => $form_states_raw_mode,
  );

  $form['selective_tweets_performance']['disable_ajax_load'] = array(
    '#type' => 'checkbox',
    '#title' => t('Disable ajax loading at page load'),
    '#default_value' => $edit['disable_ajax_load'],
    '#description' => t('Disable ajax loading of Tweets at page load. This has no effect on the ajax "load more" functionality. Notice that checking this checkbox could substantially increase your website\'s page load time, especally when the Tweet cache is cold.'),
  );

  if ($template_content) {
    $file_name = '<div class="file-name"><strong>selective-tweets-raw-tweet.tpl.php</strong> or <strong>selective-tweets-raw-tweet--<em>block-delta</em>.tpl.php</strong></div>';
    $file_content = '<div style="padding:10px; background:rgba(0, 0, 0, 0.1);"><pre>' . $template_content . '</pre></div>';

    $form['selective_tweets_override'] = array(
      '#type' => 'fieldset',
      '#title' => t('Template override - howto'),
      '#description' => t('This section is solely informative and explains how to theme a Tweet.<br />Copy and paste the template file below to <strong>selective-tweets-raw-tweet.tpl.php</strong> or <strong>selective-tweets-raw-tweet--<em>block-delta</em>.tpl.php</strong> in your theme directory. Don\'t use underscores in the file name, only hyphens. Make adjustments to the PHP/HTML as preferred. Don\'t forget to clear the cache afterwards.'),
      '#collapsible' => TRUE,
      '#collapsed' => TRUE,
      '#states' => $form_states_raw_mode,
    );

    $form['selective_tweets_override']['template_example'] = array(
      '#type' => 'item',
      '#markup' => $file_name . $file_content,
    );
  }

  return $form;
}

/**
 * Saves a user-created Selective Tweets block in the database.
 *
 * @param $edit
 *   Associative array of fields to save.
 * @param $delta
 *   Block delta of the block to save.
 *
 * @return
 *   Always returns TRUE.
 */
function selective_tweets_custom_block_save($edit, $delta) {
  // The serialized 'data' column contains the timeline settings.
  $data = array();

  foreach (_selective_tweets_block_properties() as $property => $value) {
    $data[$property] = $edit[$property];
  }

  // Save the block configuration.
  $delta = db_update('selective_tweets_block')
    ->fields(array(
      'delta' => $edit['block_delta'],
      'info' => $edit['info'],
      'data' => serialize($data),
      'pull_cache_expire' => REQUEST_TIME + ($edit['pull_cached_time'] * 60),
      'stack_cache_expire' => REQUEST_TIME + ($edit['stack_cached_time'] * 60),
    ))
    ->condition('delta', $delta)
    ->execute();

  cache_clear_all('selective_tweets::' . $edit['block_delta'], SELECTIVE_TWEETS_CACHE_BIN, TRUE);

  drupal_set_message(t('The cached Tweets of the block %block_name have been cleared. This means the loading time will be higher when loading the Tweets for the first time again.', array(
    '%block_name' => $edit['info'],
  )));
}

/**
 * Form constructor for the add block form.
 *
 * @see selective_tweets_add_block_form_validate()
 * @see selective_tweets_add_block_form_submit()
 * @ingroup forms
 */
function selective_tweets_add_block_form($form, &$form_state) {
  module_load_include('inc', 'block', 'block.admin');
  $form = block_admin_configure($form, $form_state, 'selective_tweets', NULL);

  // Other modules should be able to use hook_form_block_add_block_form_alter()
  // to modify this form, so add a base form ID.
  $form_state['build_info']['base_form_id'] = 'block_add_block_form';

  // Prevent block_add_block_form_validate/submit() from being automatically
  // added because of the base form ID by providing these handlers manually.
  $form['#submit'] = array('selective_tweets_add_block_form_submit');

  return $form;
}

/**
 * Form submission handler for selective_tweets_add_block_form().
 * Saves the new custom Selective Tweets block.
 *
 * @see selective_tweets_add_block_form()
 * @see selective_tweets_add_block_form_validate()
 */
function selective_tweets_add_block_form_submit($form, &$form_state) {
  // The serialized 'data' column contains the timeline settings.
  $data = array();
  foreach (_selective_tweets_block_properties() as $property => $value) {
    $data[$property] = $form_state['values'][$property];
  }

  $delta = $form_state['values']['block_delta'];

  // Save the block configuration.
  db_insert('selective_tweets_block')
    ->fields(array(
      'delta' => $delta,
      'info' => $form_state['values']['info'],
      'data' => serialize($data),
      'pull_cache_expire' => REQUEST_TIME + ($data['pull_cached_time'] * 60),
      'stack_cache_expire' => REQUEST_TIME + ($data['stack_cached_time'] * 60),
    ))
    ->execute();

  // Run the normal new block submission
  // (borrowed from block_add_block_form_submit).
  $query = db_insert('block')->fields(array('visibility', 'pages', 'custom', 'title', 'module', 'theme', 'status', 'weight', 'delta', 'cache'));
  foreach (list_themes() as $key => $theme) {
    if ($theme->status) {
      $query->values(array(
        'visibility' => (int) $form_state['values']['visibility'],
        'pages' => trim($form_state['values']['pages']),
        'custom' => (int) $form_state['values']['custom'],
        'title' => $form_state['values']['title'],
        'module' => $form_state['values']['module'],
        'theme' => $theme->name,
        'status' => 0,
        'weight' => 0,
        'delta' => $delta,
        'cache' => DRUPAL_NO_CACHE,
      ));
    }
  }
  $query->execute();

  $query = db_insert('block_role')->fields(array('rid', 'module', 'delta'));
  foreach (array_filter($form_state['values']['roles']) as $rid) {
    $query->values(array(
      'rid' => $rid,
      'module' => $form_state['values']['module'],
      'delta' => $delta,
    ));
  }
  $query->execute();

  // Store regions per theme for this block.
  foreach ($form_state['values']['regions'] as $theme => $region) {
    db_merge('block')
      ->key(array('theme' => $theme, 'delta' => $delta, 'module' => $form_state['values']['module']))
      ->fields(array(
        'region' => ($region == BLOCK_REGION_NONE ? '' : $region),
        'pages' => trim($form_state['values']['pages']),
        'status' => (int) ($region != BLOCK_REGION_NONE),
      ))
      ->execute();
  }

  drupal_set_message(t('The block has been created.'));
  cache_clear_all();
  $form_state['redirect'] = 'admin/structure/block';
}

/**
 * Form constructor for the custom Selective Tweets block deletion form.
 *
 * @param $delta
 *   The unique ID of the block within the context of $module.
 *
 * @see selective_tweets_block_delete_submit()
 */
function selective_tweets_block_delete($form, &$form_state, $delta) {
  $block = block_load('selective_tweets', $delta);
  $selective_tweets_block = selective_tweets_block_load($block->delta);
  $form['info'] = array('#type' => 'hidden', '#value' => $selective_tweets_block['info'] ? $selective_tweets_block['info'] : $selective_tweets_block['title']);
  $form['delta'] = array('#type' => 'hidden', '#value' => $block->delta);

  return confirm_form($form, t('Are you sure you want to delete the block %name?', array('%name' => $selective_tweets_block['info'])), 'admin/structure/block', '', t('Delete'), t('Cancel'));
}

/**
 * Form submission handler for selective_tweets_block_delete().
 *
 * @see selective_tweets_block_delete()
 */
function selective_tweets_block_delete_submit($form, &$form_state) {
  db_delete('selective_tweets_block')
    ->condition('delta', $form_state['values']['delta'])
    ->execute();
  db_delete('block')
    ->condition('module', 'selective_tweets')
    ->condition('delta', $form_state['values']['delta'])
    ->execute();
  db_delete('block_role')
    ->condition('module', 'selective_tweets')
    ->condition('delta', $form_state['values']['delta'])
    ->execute();
  db_delete('block_node_type')
    ->condition('module', 'selective_tweets')
    ->condition('delta', $form_state['values']['delta'])
    ->execute();

  drupal_set_message(t('The block %name has been removed.', array('%name' => $form_state['values']['info'])));
  cache_clear_all();
  $form_state['redirect'] = 'admin/structure/block';

  return;
}

/**
 * Helper function to validate integer: 0 or higher.
 */
function selective_tweets_element_validate_integer_zero_or_higher($element, &$form_state) {
  $value = $element['#value'];

  if ($value !== '' && (!is_numeric($value) || intval($value) != $value || $value < 0)) {
    form_error($element, t('%name must be 0 or higher.', array('%name' => $element['#title'])));
  }
}

/**
 * Helper function to validate block delta to be unique.
 */
function selective_tweets_element_validate_delta_exists($delta) {
  return (bool) db_query_range('SELECT 1 FROM {selective_tweets_block} WHERE delta = :delta', 0, 1, array(':delta' => $delta))->fetchField();
}
