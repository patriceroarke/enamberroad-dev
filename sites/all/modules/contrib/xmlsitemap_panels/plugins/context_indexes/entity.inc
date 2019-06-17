<?php

$plugin = array(
  'get child' => 'xmlsitemap_panels_entity_get_child',
  'get children' => 'xmlsitemap_panels_entity_get_children',
  'callback' => 'xmlsitemap_panels_entity_index',
);

function xmlsitemap_panels_entity_get_child($plugin, $parent, $child) {
  $plugins = xmlsitemap_panels_entity_get_children($plugin, $parent);
  return $plugins[$parent . ':' . $child];
}

function xmlsitemap_panels_entity_get_children($plugin, $parent) {
  $entities = entity_get_info();
  $plugins = array();
  foreach ($entities as $entity_type => $entity) {
    $plugin['title'] = t('@entity: Index', array('@entity' => $entity['label']));
    $plugin['description'] = t('Returns an index of @entity entities.', array('@entity' => $entity_type));
    $plugin['context'] = $entity_type;
    $plugin_id = $parent . ':' . $entity_type;
    $plugins[$plugin_id] = $plugin;
  }
  return $plugins;
}

function xmlsitemap_panels_entity_index($entity_type, $bundle = NULL) {
  $query = new EntityFieldQuery;
  $query->entityCondition('entity_type', $entity_type);
  if (!empty($bundle)) {
    $query->entityCondition('bundle', $bundle);
  }

  $results = $query->execute();
  return $results[$entity_type];
}
