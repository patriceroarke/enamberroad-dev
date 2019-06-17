<?php
/**
 * @file
 * Default theme implementation of the ajax load throbber when loading Tweets.
 *
 * Variables:
 * - $message
 *
 * @see template_preprocess()
 * @see template_preprocess_HOOK()
 * @see template_preprocess_block()
 * @see template_process()
 *
 * @ingroup themeable
 */
?>

<div class="ajax-progress ajax-progress-throbber">
  <span class="throbber"></span>
  <?php print $message; ?>
</div>
