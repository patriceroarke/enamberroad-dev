<?php
/**
 * @file
 * amberroad_slideshow.entityqueue_default.inc
 */

/**
 * Implements hook_entityqueue_default_queues().
 */
function amberroad_slideshow_entityqueue_default_queues() {
  $export = array();

  $queue = new EntityQueue();
  $queue->disabled = FALSE; /* Edit this to true to make a default queue disabled initially */
  $queue->api_version = 1;
  $queue->name = 'slideshow';
  $queue->label = 'Slideshow';
  $queue->language = 'en';
  $queue->handler = 'simple';
  $queue->target_type = 'node';
  $queue->settings = array(
    'target_bundles' => array(
      'slideshow' => 'slideshow',
    ),
    'min_size' => '0',
    'max_size' => '0',
    'act_as_queue' => 0,
  );
  $export['slideshow'] = $queue;

  return $export;
}
