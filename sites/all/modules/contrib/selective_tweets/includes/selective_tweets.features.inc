<?php

/**
 * @file
 * Implement hooks for features support.
 */

/**
 * Implements hook_features_export_options().
 */
function selective_tweets_features_export_options() {
  $blocks = array();
  $result = db_select('selective_tweets_block', 's')
    ->fields('s')
    ->execute();

  while ($record = $result->fetchAssoc()) {
    $blocks[$record['delta']] = $record['delta'];
  }

  return $blocks;
}

/**
 * Implements hook_features_export().
 */
function selective_tweets_features_export($data, &$export, $module_name = '') {
  // The selective_tweets_default_formats() hook integration is provided by the
  // features module so we need to add it as a dependency.
  $export['dependencies']['features'] = 'features';
  $export['dependencies']['selective_tweets'] = 'selective_tweets';

  foreach ($data as $delta) {
    $export['features']['selective_tweets'][$delta] = $delta;
  }

  return array();
}

/**
 * Implements hook_features_export_render().
 */
function selective_tweets_features_export_render($module, $data, $export = NULL) {
  $code = array();
  $code[] = '  $blocks = array();';
  $code[] = '';

  foreach ($data as $delta) {
    if ($block = selective_tweets_block_load($delta)) {
      // Do not store pull_cache_expire and stack_cache_expire fields.
      unset($block['pull_cache_expire']);
      unset($block['stack_cache_expire']);
      // Write data to features file.
      $profile_export = features_var_export($block, '  ');
      $profile_identifier = features_var_export($delta);
      $code[] = "  // Exported selective_tweet block: {$delta}";
      $code[] = "  \$blocks[{$profile_identifier}] = {$profile_export};";
      $code[] = "";
    }
  }

  $code[] = '  return $blocks;';
  $code = implode("\n", $code);

  return array('selective_tweets_block_settings' => $code);
}

/**
 * Implements hook_features_revert().
 */
function selective_tweets_features_revert($module) {
  return selective_tweets_features_rebuild($module);
}

/**
 * Implements hook_features_rebuild().
 */
function selective_tweets_features_rebuild($module) {
  if ($defaults = features_get_default('selective_tweets', $module)) {
    foreach ($defaults as $delta => $block) {
      db_merge('selective_tweets_block')
        ->key(array('delta' => $delta))
        ->fields(array(
          'delta' => $block['delta'],
          'info' => $block['info'],
          'data' => serialize($block['data']),
          'pull_cache_expire' => REQUEST_TIME,
          'stack_cache_expire' => REQUEST_TIME,
        ))
        ->execute();

      // Clear remaining cache of the selective tweets block so revert takes
      // effect immediately.
      cache_clear_all('selective_tweets::' . $delta, SELECTIVE_TWEETS_CACHE_BIN, TRUE);
    }
  }
}
