<?php
/**
 * @file
 * amberroad_homepage.entityqueue_default.inc
 */

/**
 * Implements hook_entityqueue_default_queues().
 */
function amberroad_homepage_entityqueue_default_queues() {
  $export = array();

  $queue = new EntityQueue();
  $queue->disabled = FALSE; /* Edit this to true to make a default queue disabled initially */
  $queue->api_version = 1;
  $queue->name = 'upcoming_event';
  $queue->label = 'Upcoming Event';
  $queue->language = 'en';
  $queue->handler = 'simple';
  $queue->target_type = 'node';
  $queue->settings = array(
    'target_bundles' => array(
      'industry_conference' => 'industry_conference',
      'seminar' => 'seminar',
    ),
    'min_size' => '0',
    'max_size' => '1',
    'act_as_queue' => 1,
  );
  $export['upcoming_event'] = $queue;

  $queue = new EntityQueue();
  $queue->disabled = FALSE; /* Edit this to true to make a default queue disabled initially */
  $queue->api_version = 1;
  $queue->name = 'upcoming_webinar';
  $queue->label = 'Upcoming Webinar';
  $queue->language = 'en';
  $queue->handler = 'simple';
  $queue->target_type = 'node';
  $queue->settings = array(
    'target_bundles' => array(
      'webinar' => 'webinar',
    ),
    'min_size' => '0',
    'max_size' => '1',
    'act_as_queue' => 1,
  );
  $export['upcoming_webinar'] = $queue;

  return $export;
}
