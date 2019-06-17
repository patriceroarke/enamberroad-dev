<?php
/**
 * @file
 * amberroad_settings.features.workbench_moderation_transitions.inc
 */

/**
 * Implements hook_workbench_moderation_export_transitions().
 */
function amberroad_settings_workbench_moderation_export_transitions() {
  $items = array(
    'draft:needs_review' => array(
      'from_name' => 'draft',
      'to_name' => 'needs_review',
      'name' => 'Submit for Review',
    ),
    'needs_review:draft' => array(
      'from_name' => 'needs_review',
      'to_name' => 'draft',
      'name' => 'Reject',
    ),
    'needs_review:scheduled' => array(
      'from_name' => 'needs_review',
      'to_name' => 'scheduled',
      'name' => 'Scheduled For Publish',
    ),
  );
  return $items;
}
