<?php
/**
 * @file
 * Default theme implementation to display a raw Selective Tweet.
 * Copy this tpl file to your theme directory and override it to suit your
 * needs.
 *
 * In order to make this template file applicable to only one Selective Tweets
 * block, rename this file to selective-tweets-raw-tweet--[block-delta].tpl.php.
 * Make sure the underscores in [block-delta] are replaced by hyphens. The block
 * delta can be found on the configuration page of a Selective Tweets block,
 * right next to the block description.
 *
 * Available variables:
 *
 * $block_delta
 *   The block delta of the Selective Tweets block where this Tweet will be
 *   rendered in.
 *
 * $tweet (object)
 * $tweet->user (object)
 * $tweet->user->profile_sidebar_fill_color (string, hexadecimal color code)
 * $tweet->user->profile_sidebar_border_color (string, hexadecimal color code)
 * $tweet->user->name (string)
 * $tweet->user->profile_image_url (string)
 * $tweet->user->screen_name (string)
 * $tweet->user->description (string)
 * $tweet->user->statuses_count (integer)
 * $tweet->user->friends_count (integer)
 * $tweet->created_at (string)
 * $tweet->created_timestamp (integer)
 * $tweet->time_ago (string)
 * $tweet->text (string)
 * $tweet->retweet_count (integer)
 * $tweet->retweeted (boolean)
 *
 * For all available variables in the $tweet object, check
 * https://dev.twitter.com/rest/reference/get/statuses/show/%3Aid. The example
 * result shows the available properties.
 *
 * @see template_preprocess()
 * @see template_preprocess_HOOK()
 * @see template_preprocess_block()
 * @see template_process()
 *
 * @ingroup themeable
 */
?>
<?php
  // IMPORTANT: the class 'selective-tweet' is required for the load-more
  // ajax functionality to work.
?>
<div class="selective-tweet selective-tweet-<?php print $tweet->id_str; ?>">

<?php if ($tweet->user->profile_image_url): ?>
  <div class="tweet-user-image">
    <img src="<?php print $tweet->user->http://www.amberroad.com/sites/all/themes/ar_theme/img/twitter_64px.png ?>" />
  </div>
<?php endif;?>

<?php if ($tweet->user->name && $tweet->user->screen_name && $tweet->time_ago): ?>
  <div class="tweet-user">
    <span class="user-name"><?php print $tweet->user->name; ?></span> <span class="screen-name"><a href="https://twitter.com/<?php print $tweet->user->screen_name; ?>" target="_blank">@<?php print $tweet->user->screen_name; ?></a></span> <span class="time-ago">&#8226; <?php print $tweet->time_ago; ?></span>
  </div>
<?php endif;?>

<?php if ($tweet->text): ?>
  <div class="tweet-text">
    <?php print $tweet->text; ?>
  </div>
<?php endif;?>

  <div class="tweet-actions">
    <a href="<?php print $tweet->link_reply_to ?>" target="_blank"><?php print t('Reply'); ?></a>
    <a href="<?php print $tweet->link_retweet ?>" target="_blank"><?php print t('Retweet'); ?></a>
    <a href="<?php print $tweet->link_favorite ?>" target="_blank"><?php print t('Favorite'); ?></a>
  </div>

</div>
