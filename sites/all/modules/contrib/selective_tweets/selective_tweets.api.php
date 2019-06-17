<?php
/**
 * @file
 * Contains information about hooks provided by Selective Tweets.
 */

/**
 * Several Selective Tweets block settings such as Tweet filters can be altered.
 * Changes to $data are passed by reference. No return value is needed.
 * Potential tokens have already been replaced in this phase.
 *
 * @param $data
 *   Array containing alterable settings.
 *     - screen_name
 *     - from_account
 *     - to_account
 *     - user_mentions
 *     - hashtags
 *     - banned_words
 *     - load_more_text
 *     - loading_text
 *     - empty_text
 * @param $context
 *   Array containing contextual information:
 *     - block_config: The configuration array of the block.
 *     - entity: Object used for token replacements. Can be NULL.
 */
function hook_selective_tweets_block_alter(&$data, $context) {
  // Example: always include hashtag 'drupal' in de hashtag filter of the
  // Selective Tweets block with delta 'my_selective_tweets_block'.
  if ($context['block_config']['block_delta'] == 'my_selective_tweets_block') {
    $data['hashtags'] .= empty($data['hashtags']) ? 'drupal' : ' AND drupal';
  }

  // Example: Change empty texts of all Selective Tweets block on the website,
  // despite their individual settings.
  $data['empty_text'] = t('Go home, there are no tweets here.');
}

/**
 * Alter the parameters before the call is made to the twitter API.
 *
 * @param $params
 *   Array containing call parameters sent to Twitter.
 * @param $endpoint
 *   The endpoint to which the call is made.
 * @param $context
 *   Array containing contextual information:
 *     - block_config: The configuration array of the block.
 *     - entity: Object used for token replacements. Can be NULL.
 */
function hook_selective_tweets_query_alter(&$params, &$endpoint, $context) {
  // Example: Limit the tweets to Dutch by adding the 'lang' param if
  // the display mode is search.
  // More parameters can be found on the Twitter API documentation page.
  if ($context['block_config']['data']['display_mode'] == ST_SELECTION_MODE_SEARCH) {
    $params['lang'] = 'nl';
  }
}

/**
 * Alter the Tweet object as returned from the Twitter API. This data is used
 * for rendering a raw HTML Tweet. The $tweet object is available in the
 * template file.
 * Note that these objects are cached after passing through this hook. When
 * making changes to this hook, always make sure to clear the cache.
 * Hint: resaving the block config clears the cache of this individual block.
 *
 * @param $tweet
 *   Object containing all Tweet information as returned from the Twitter API.
 *   This object is passed to the raw Tweet template file.
 * @param $context
 *   Array containing contextual information:
 *     - block_config: The configuration array of the block.
 *     - entity: Object used for token replacements. Can be NULL.
 */
function hook_selective_tweets_tweet_object_alter(&$tweet, $context) {
  // Example: Make sure the username's first character is uppercased.
  $tweet->user->screen_name = ucfirst($tweet->user->screen_name);
}
