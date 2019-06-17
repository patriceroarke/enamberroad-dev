<?php
/**
 * @file
 * Provides page callbacks and their helper functions.
 */

/**
 * Page callback; Function that returns the block content for a Twitter feed.
 *
 * @param $block_config
 *   The block configuration array.
 * @param $context_entity_id
 *   The entity ID of the contextual entity used for token replacements.
 * @param $page
 *   Page to load.
 * @param $type
 *   Type of callback, ajax or nojs.
 *
 * @return
 *   Render array for the block.
 */
function selective_tweets_twitter_feed_build($block_config, $context_entity_id = 'no-context', $page = 0, $type = 'nojs') {
  $delta = $block_config['delta'];

  // Load context entity if there is one (for token support).
  $block_config['data']['token_entity_object'] = NULL;
  if (_selective_tweets_token_support() && $context_entity_id && $context_entity_id != 'no-context' && $block_config['data']['token_entity_type']) {
    $entity_type = str_replace('current_', '', $block_config['data']['token_entity_type']);

    if ($context_entity_object = entity_load($entity_type, array($context_entity_id))) {
      $block_config['data']['token_entity_object'] = entity_metadata_wrapper($entity_type, reset($context_entity_object));
    }
  }

  // Preprocess block configuration before doing anything else with
  // it. Tokens are replaced and other modules can alter data.
  selective_tweets_preprocess_block_config($block_config);

  // Return the throbber when for asynchronous loading when required so.
  if ($type == 'throbber') {
    return array(
      'tweet_list' => array(
        '#theme' => 'selective_tweets_throbber',
        '#message' => $block_config['data']['loading_text'],
      ),
    );
  }

  // When first loaded, take initial_count as number of tweets to load.
  $count = ($type == 'ajax') ? $block_config['data']['count'] : $block_config['data']['initial_count'];

  // Retrieve latest tweet ids from cache.
  $render = array();
  try {
    $tweet_ids = selective_tweets_twitter_feed_get($block_config, $page);
    // To check if we need a load-more link, get next page
    $tweet_ids_next_page = selective_tweets_twitter_feed_get($block_config, $page + 1);

    if (empty($tweet_ids) && $page == 0) {
      // Serve empty message when no Tweets were found.
      if ($block_config['data']['empty_text']) {
        $render['tweet_list'] = array(
          '#theme' => 'html_tag',
          '#tag' => 'p',
          '#attributes' => array(
            'class' => 'selective-tweets-message empty-message',
          ),
          '#value' => $block_config['data']['empty_text'],
        );
      }

      return $render;
    }
  } catch (Exception $ex) {
    // Serve empty message when something went wrong.
    if ($block_config['data']['empty_text']) {
      $render['tweet_list'] = array(
        '#theme' => 'html_tag',
        '#tag' => 'p',
        '#attributes' => array(
          'class' => 'selective-tweets-message empty-message',
        ),
        '#value' => $block_config['data']['empty_text'],
      );
    }

    return $render;
  }

  // Render the tweets.
  $render['tweet_list']['#markup'] = selective_tweets_feed_render($tweet_ids, $block_config);

  // Determine whether a load more link is needed or not.
  if (count($tweet_ids_next_page) && $block_config['data']['count'] != 0) {
    // Make sure the loade-more link is an <li> element when we are dealing
    // with a list, only for raw html tweets.
    $wrapper_element = ($block_config['data']['html_wrapper'] == 'ul' && $block_config['data']['render_mode'] != SELECTIVE_TWEETS_EMBED) ? 'li' : 'div';

    $render['load_more'] = array(
      '#theme' => 'link',
      '#text' => $block_config['data']['load_more_text'],
      '#path' => 'selective-tweets/feed/load/' . $delta . '/' . (isset($context_entity_id) ? $context_entity_id : 'no-context') . '/' . ++$page . '/nojs',
      '#options' => array(
        'html' => TRUE,
        'attributes' => array(
          'class' => array('use-ajax', 'load-more'),
        ),
      ),
      '#prefix' => '<' . $wrapper_element . ' id="load-more-' . $delta . '" class="load-more-wrapper">',
      '#suffix' => '</' . $wrapper_element . '>',
    );
  }

  // If ajax request, insert the ajax commands and stop the page rendering.
  $container_id = 'selective-tweets-block-' . $delta;

  if ($type == 'ajax') {
    $commands[] = ajax_command_invoke('#' . $container_id . ' .selective-tweet:last', 'after', array(drupal_render($render['tweet_list'])));
    if (!empty($render['load_more'])) {
      $commands[] = ajax_command_replace('#load-more-' . $delta, drupal_render($render['load_more']));
    }
    else {
      $commands[] = ajax_command_remove('#load-more-' . $delta);
      // During the last page load, behaviors are not executed for an unknown
      // reason. We execute it here.
      $commands[] = array(
        'command' => 'selective_tweets_attach_behaviors',
        'container' => '#' . $container_id,
      );
    }

    // Render as ajax response.
    ajax_deliver(array(
      '#type' => 'ajax',
      '#commands' => $commands,
    ));
  }

  return $render;
}

/**
 * Helper function to render a twitter feed based on tweet IDs.
 *
 * @param $ids
 *   An array of tweet IDs to be rendered.
 * @param $block_config
 *   The configuration array of the block.
 *
 * @return
 *   A string containing the rendered tweets (HTML).
 */
function selective_tweets_feed_render($ids, $block_config) {
  $output = '';

  try {
    foreach ($ids as $tid) {
      $output .= selective_tweets_tweet_render($tid, $block_config);
    }
  } catch (Exception $ex) {
    drupal_set_message(t("Sorry, we're not able to display Tweets at this moment."), 'error');

    if (variable_get('selective_tweets_debug', FALSE)) {
      watchdog('selective_tweets', $ex->getMessage(), array(), WATCHDOG_ERROR);
    }
  }

  return $output;
}

/**
 * Helper function to convert one tweet ID to HTML.
 *
 * @param $tid
 *   The tweet ID.
 * @param $block_config
 *   The configuration array of the block.
 *
 * @return
 *   A tweet as HTML.
 */
function selective_tweets_tweet_render($tid, $block_config) {
  // We separate the tweets per block in the cache table, so
  // they can be cleared separately.
  $rendered_tweet_cid = 'selective_tweets::' . $block_config['delta'] . '::rendered_tweets';
  // Extend cache ID by an entity ID for token activated blocks.
  selective_tweets_cid_extend($rendered_tweet_cid, $block_config['data']['token_entity_object'], $block_config['data']['token_entity_type']);

  $cache = cache_get($rendered_tweet_cid, SELECTIVE_TWEETS_CACHE_BIN);

  // Check if rendered Tweet is cached already.
  if ($cache && isset($cache->data[$tid])) {
    return $cache->data[$tid];
  }
  else {
    try {
      // Get the current cache to add the new tweet to it.
      $current_rendered_cache = array();
      if (is_object($cache) && isset($cache->data)) {
        $current_rendered_cache = $cache->data;
      }

      // Authentication Twitter API.
      $connection = selective_tweets_twitter_connect();
      $api_version = variable_get('selective_tweets_api_version', SELECTIVE_TWEETS_API_VERSION);

      switch ($block_config['data']['render_mode']) {
        case SELECTIVE_TWEETS_EMBED:
          $params = array(
            'id' => $tid,
            'hide_media' => $block_config['data']['hide_media'],
            'hide_thread' => $block_config['data']['hide_thread'],
            'maxwidth' => $block_config['data']['maxwidth'],
            'omit_script' => TRUE,
          );

          // Convert a tweet ID to an embedded Tweet via the Twitter API.
          $response = json_decode(
            $connection->oAuthRequest(
              'https://api.twitter.com/' . $api_version . '/statuses/oembed.json',
              'GET',
              $params
            )
          );

          $current_rendered_cache[$tid] = '<div class="selective-tweet tweet-id-' . $tid . '">' . $response->html . '</div>';
          break;

        case SELECTIVE_TWEETS_RAW:
          // Get the cached raw tweet data.
          $raw_tweet_cid = 'selective_tweets::' . $block_config['delta'] . '::raw_data_tweets';
          // Extend cache ID by an entity ID for token activated blocks.
          selective_tweets_cid_extend($raw_tweet_cid, $block_config['data']['token_entity_object'], $block_config['data']['token_entity_type']);

          $raw_tweet_cache = cache_get($raw_tweet_cid, SELECTIVE_TWEETS_CACHE_BIN);

          // Check if rendered Tweet is cached already.
          if ($raw_tweet_cache && isset($raw_tweet_cache->data[$tid])) {
            $response = $raw_tweet_cache->data[$tid];
          }
          else {
            // If any, add current cache to newly built cache.
            $current_raw_cache = array();
            if (is_object($raw_tweet_cache) && isset($raw_tweet_cache->data)) {
              $current_raw_cache = $raw_tweet_cache->data;
            }

            $params = array(
              'id' => $tid,
              'trim_user' => FALSE,
              'include_my_retweet' => FALSE,
              'include_entities' => TRUE,
            );

            // Convert a tweet ID to a Tweet object via the Twitter API.
            $response = json_decode(
              $connection->oAuthRequest(
                'https://api.twitter.com/' . $api_version . '/statuses/show.json',
                'GET',
                $params
              )
            );

            // Allow other modules to alter the raw Tweet object.
            $context = array(
              'block_config' => $block_config,
              'entity' => $block_config['data']['token_entity_object'] ? $block_config['data']['token_entity_object']->value() : NULL,
            );
            drupal_alter('selective_tweets_tweet_object', $response, $context);

            // Cache the raw Tweet data.
            $current_raw_cache[$tid] = $response;
            cache_set($raw_tweet_cid, $current_raw_cache, SELECTIVE_TWEETS_CACHE_BIN, CACHE_PERMANENT);
          }

          // Add the time ago value. We do this after the data is retrieved from
          // cache because this has to be up to date.
          if (isset($response->created_timestamp) && $response->created_timestamp && $time_ago = _selective_tweets_get_time_ago($response->created_timestamp)) {
            $response->time_ago = $time_ago;
          }

          $current_rendered_cache[$tid] = theme('selective_tweets_raw_tweet', array(
            'block_delta' => $block_config['delta'],
            'tweet' => $response,
          ));
          break;
      }

      // Cache the rendered Tweet if requested.
      if ($block_config['data']['render_mode'] == SELECTIVE_TWEETS_EMBED || $block_config['data']['cache_rendered_tweet']) {
        cache_set($rendered_tweet_cid, $current_rendered_cache, SELECTIVE_TWEETS_CACHE_BIN, CACHE_PERMANENT);
      }

      return $current_rendered_cache[$tid];
    } catch (Exception $ex) {
      if (variable_get('selective_tweets_debug', FALSE)) {
        watchdog('selective_tweets', $ex->getMessage(), array(), WATCHDOG_ERROR);
      }
    }
  }

  return '';
}

/**
 * Helper function to get the tweets from tweet stack in cache. If the caching
 * time exceeded, the cache will be supplemented with new tweets.
 *
 * @param $block_config
 *   The configuration array of the block.
 * @param $page
 *   The page to load.
 *
 * @return
 *   An array containing the tweet IDs.
 */
function selective_tweets_twitter_feed_get($block_config, $page = 0) {
  // If caching time period exceeded, fill cache with new tweets, but keep the
  // old ones as they can still be displayed.
  $cid = 'selective_tweets::' . $block_config['delta'] . '::tweet_stack';
  // Extend cache ID by an entity ID for token activated blocks.
  selective_tweets_cid_extend($cid, $block_config['data']['token_entity_object'], $block_config['data']['token_entity_type']);

  $tweet_ids = array();
  $cache = cache_get($cid, SELECTIVE_TWEETS_CACHE_BIN);

  // Only get new Tweets from API when first page is getting loaded AND when no
  // cache is available or the Selective Tweets cache for this block is expired.
  if ((REQUEST_TIME >= $block_config['pull_cache_expire'] || !$cache) && $page == 0) {
    // If the Tweet stack cache is expired, we drop it and refill the stack with
    // a fresh list of Tweets.
    if (REQUEST_TIME >= $block_config['stack_cache_expire'] && $block_config['stack_cache_expire'] != 0) {
      $cache = NULL;
    }

    // Add newest Tweets to the tweet stack in cache.
    $tweet_ids = selective_tweets_request_tweets($cid, $cache, $block_config);
  }
  else {
    if ($cache) {
      $tweet_ids = $cache->data;
    }
  }

  // Get the tweets of the requested page out of the array.
  // These calculations are made because the initial number of tweets can differ
  // from the ones that get loaded on the next pages.
  if ($page > 0) {
    $offset = $block_config['data']['initial_count'] + (--$page * $block_config['data']['count']);
    $count = $block_config['data']['count'];
  }
  else {
    $offset = 0;
    $count = $block_config['data']['initial_count'];
  }

  return array_slice($tweet_ids, $offset, $count);
}

/**
 * Do all necessary alterations to the block configuration such as token
 * replacements and hook alterations.
 *
 * @param $block_config
 *   The block configuration as returned from selective_tweets_block_load().
 */
function selective_tweets_preprocess_block_config(&$block_config) {
  // Translate fields before tokens are replaced.
  $translatable_fields = array(
    'load_more_text',
    'loading_text',
    'empty_text',
  );

  foreach ($translatable_fields as $translatable_field) {
    $block_config['data'][$translatable_field] = t($block_config['data'][$translatable_field]);
  }

  // Tokenize fields.
  $tokenizable_fields = array(
    'screen_name' => '',
    'from_account' => '',
    'to_account' => '',
    'user_mentions' => '',
    'hashtags' => '',
    'banned_words' => '',
    'load_more_text' => '',
    'loading_text' => '',
    'empty_text' => '',
  );

  foreach ($tokenizable_fields as $tokenizable_field => $value) {
    $tokenizable_fields[$tokenizable_field] = selective_tweets_token_replace(
      $block_config['data'][$tokenizable_field],
      $block_config['data']['token_entity_object'],
      $block_config['data']['token_entity_type']
    );
  }

  // Allow other modules to alter the input filters after tokens are replaced.
  $context = array(
    'block_config' => $block_config,
    'entity' => $block_config['data']['token_entity_object'] ? $block_config['data']['token_entity_object']->value() : NULL,
  );
  drupal_alter('selective_tweets_block', $tokenizable_fields, $context);

  // Merge altered values back in the block configuration data.
  $block_config['data'] = array_merge($block_config['data'], $tokenizable_fields);
}

/**
 * Helper function to get tweets from the Twitter API and cache them in order
 * to save expensive calls to Twitter.
 *
 * @param $cid
 *   The cache ID where the tweets for this block are cached.
 * @param $cache
 *   The currently cached tweet IDs.
 * @param $block_config
 *   The configuration array of the block.
 *
 * @return
 *   An array containing all cached tweet IDs.
 */
function selective_tweets_request_tweets($cid, $cache, $block_config) {
  $params = $cached_tweet_ids = array();
  $endpoint = $since_id =  NULL;

  // Authentication Twitter API.
  $connection = selective_tweets_twitter_connect();

  // Get currently cached tweets and the last cached tweet id.
  if ($cache) {
    $cached_tweet_ids = $cache->data;
    if ($since_id = reset($cached_tweet_ids)) {
      // If we already cached tweets, only get tweets that come after the last
      // cached tweet.
      $params += array('since_id' => $since_id);
    }
  }

  // Invoke hook_selective_tweets_query_alter() to assemble the final Twitter
  // query.
  $context = array(
    'block_config' => $block_config,
    'entity' => $block_config['data']['token_entity_object'] ? $block_config['data']['token_entity_object']->value() : NULL,
  );
  drupal_alter('selective_tweets_query', $params, $endpoint, $context);

  // Make the actual request to Twitter.
  $response = json_decode(
    $connection->oAuthRequest(
      $endpoint,
      'GET',
      $params
    )
  );

  $tweet_ids = array();
  $throw_error = FALSE;

  if (is_object($response)) {
    if (isset($response->errors)) {
      foreach ($response->errors as $error) {
        if (variable_get('selective_tweets_debug', FALSE)) {
          watchdog('selective_tweets', 'Twitter API: @error_code: @error_message', array(
            '@error_code' => $error->code,
            '@error_message' => $error->message,
          ), WATCHDOG_ERROR);
        }
      }
      $throw_error = TRUE;
    }

    // Responses to search requests come in differently than other responses
    // from the Twitter API. Pull out the Tweets and put them in response var.
    if (isset($response->statuses)) {
      $response = $response->statuses;
    }
  }

  if (is_array($response)) {
    foreach ($response as $tweet) {
      $tweet_ids[] = $tweet->id_str;
    }
  }

  // Merge old and new Tweets into one array.
  $new_tweet_stack = array_merge($tweet_ids, $cached_tweet_ids);

  // Limit the Tweet stack to the maximum.
  $new_tweet_stack = array_slice($new_tweet_stack, 0, $block_config['data']['tweet_stack_max']);

  // Save the new tweet stack in cache.
  cache_set($cid, $new_tweet_stack, SELECTIVE_TWEETS_CACHE_BIN, CACHE_PERMANENT);

  // Update the cache_expire time for this Selective Tweets block.
  db_update('selective_tweets_block')
    ->fields(array(
      'pull_cache_expire' => (REQUEST_TIME + ($block_config['data']['pull_cached_time'] * 60)),
      'stack_cache_expire' => (REQUEST_TIME + ($block_config['data']['stack_cached_time'] * 60)),
    ))
    ->condition('delta', $block_config['delta'])
    ->execute();

  // We throw the error after caching 0 results on failure, so we don't burn up
  // Twitter API requests everytime this block gets loaded.
  if ($throw_error) {
    throw new Exception(t('The tweets could not be loaded.'));
  }

  return $new_tweet_stack;
}

/**
 * Extend a cache ID string by the ID of the menu object (by reference).
 *
 * @param $cid
 *   Cache ID string.
 * @param $token_entity_object
 *   The entity object as entity_metadata_wrapper.
 * @param $token_entity_type
 *   The entity type.
 */
function selective_tweets_cid_extend(&$cid, $token_entity_object, $token_entity_type) {
  // Extend cache ID by an entity ID for token activated blocks.
  if (_selective_tweets_token_support() && $token_entity_object) {
    $cid .= '::' . $token_entity_type . '_' . $token_entity_object->getIdentifier();
  }
}

/**
 * Replace tokens in text when tokens are supported.
 *
 * @param $text
 *   Input text as string.
 * @param $token_entity_object
 *   Entity object by which tokens will be replaced.
 *   object.
 * @param $token_entity_type
 *   Entity type as a string.
 *
 * @return
 *   Tokenized or original string. Could be empty when tokens not found.
 */
function selective_tweets_token_replace($text, $token_entity_object, $token_entity_type) {
  if (!$token_entity_object) {
    return $text;
  }

  $output = '';

  if (_selective_tweets_token_support() && $text && $token_entity_type) {
    $token_entity_type = ($token_entity_type == 'current_user') ? 'user' : $token_entity_type;
    $output = token_replace($text, array($token_entity_type => $token_entity_object->value()), array('clear' => TRUE));
  }

  return $output;
}

/**
 * Helper function to convert hashtags, users and urls to links.
 *
 * @param $tweet
 *   The tweet object returned from the Twitter API.
 */
function _selective_tweets_insert_links(&$tweet) {
  $twitter_url = 'https://twitter.com';

  // Convert hashtags.
  $tweet->text = _selective_tweets_filter_text($tweet->text, '#', $twitter_url . '/hashtag/');

  // Convert user mentions.
  $tweet->text = _selective_tweets_filter_text($tweet->text, '@', $twitter_url . '/');

  // Convert urls.
  if (isset($tweet->entities->urls) && !empty($tweet->entities->urls)) {
    foreach ($tweet->entities->urls as $key => $url) {
      $link = l($url->display_url, $url->expanded_url, array(
        'attributes' => array(
          'target' => '_blank',
          'rel' => 'nofollow',
        ),
      ));
      $tweet->text = str_replace($url->url, $link, $tweet->text);
    }
  }
}

/**
 * Helper function to convert user mentions and hashtags into
 * actual links.
 *
 * @param $text
 *   The Tweet text.
 * @param $prefix
 *   The entity prefix (@ or #).
 * @param $destination
 *   The destination url base.
 *
 * @return
 *   The Tweet text with links.
 */
function _selective_tweets_filter_text($text, $prefix, $destination) {
  $matches = array(
    '/\>' . $prefix . '(\w+)/ui',
    '/^' . $prefix . '(\w+)/ui',
    '/(\s+)' . $prefix . '(\w+)/ui',
  );
  $replacements = array(
    '><a target="_blank" rel="nofollow" href="' . $destination . '${1}">' . $prefix . '${1}</a>',
    '<a target="_blank" rel="nofollow" href="' . $destination . '${1}">' . $prefix . '${1}</a>',
    '${1}<a target="_blank" rel="nofollow" href="' . $destination . '${2}">' . $prefix . '${2}</a>',
  );

  return preg_replace($matches, $replacements, $text);
}

/**
 * Helper function to convert the Twitter created_at value to a timestamp.
 *
 * @param $created_at
 *   The created_at value from the Twitter API.
 *
 * @return
 *   The created timestamp.
 */
function _selective_tweets_get_timestamp($created_at) {
  $timezone = variable_get('date_default_timezone', FALSE);
  if (module_exists('date_api')) {
    $timezone = date_default_timezone(TRUE);
  }

  $datetime = new DateTime($created_at);
  if ($timezone) {
    $datetime->setTimezone(new DateTimeZone($timezone));
  }

  return $datetime->format('U');
}

/**
 * Helper function to convert the Twitter created_timestamp value to a
 * time-ago value.
 *
 * @param $created_timestamp
 *   The created_timestamp.
 *
 * @return
 *   The time ago as string.
 */
function _selective_tweets_get_time_ago($created_timestamp = NULL) {
  $time_ago = '';

  if ($created_timestamp) {
    $time_ago = t('@time ago', array('@time' => format_interval(REQUEST_TIME - $created_timestamp , 2)));
  }

  return $time_ago;
}
