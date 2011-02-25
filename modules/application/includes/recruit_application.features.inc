<?php

/**
 * @file
 * Required code for features integration.
 */

/**
 * Implementation of hook_features_export_options().
 */
function recruit_application_type_features_export_options() {
  return recruit_application_type_get_name();
}

/**
 * Implementation of hook_features_export.
 */
function recruit_application_type_features_export($data, &$export, $module_name = '') {
  $pipe = array();
  $map = features_get_default_map('recruit_application_type');

  foreach ($data as $type) {
    // Poll node module to determine who provides the node type.
    if ($info = recruit_application_type_load($type)) {
      // If this node type is provided by a different module, add it as a dependency
      #if (isset($map[$type]) && $map[$type] != $module_name) {
      #  $export['dependencies'][$map[$type]] = $map[$type];
      #}
      // Otherwise export the node type.
      #elseif (in_array($info->base, array('node_content', 'features'))) {
        $export['features']['recruit_application_type'][$type] = $type;
        $export['dependencies']['recruit_application'] = 'recruit_application';
        $export['dependencies']['features'] = 'features';
      #}

      $fields = field_info_instances('recruit_application', $type);
      foreach ($fields as $name => $field) {
        $pipe['field'][] = "recruit_application-{$field['bundle']}-{$field['field_name']}";
      }
    }
  }

  return $pipe;
}

/**
 * Implementation of hook_features_export_render().
 */
function recruit_application_type_features_export_render($module, $data, $export = NULL) {
  $elements = array(
    'type' => FALSE,
    'name' => TRUE,
    'description' => TRUE,
    'help' => TRUE,
  );
  $output = array();
  $output[] = '  $items = array(';
  foreach ($data as $type) {
    if ($info = recruit_application_type_load($type)) {

      $info->base = 'features';
      $output[] = "    '{$type}' => (object) array(";
      foreach ($elements as $key => $t) {
        if ($t) {
          $text = str_replace("'", "\'", $info->$key);
          $text = !empty($text) ? "t('{$text}')" : "''";
          $output[] = "      '{$key}' => {$text},";
        }
        else {
          $output[] = "      '{$key}' => '{$info->$key}',";
        }
      }
      $output[] = "    ),";
    }
  }
  $output[] = '  );';
  $output[] = '  return $items;';
  $output = implode("\n", $output);
  return array('recruit_application_info' => $output);
}

/**
 * Implementation of hook_features_revert().
 *
 * @param $module
 * name of module to revert content for
 */
function recruit_application_type_features_revert($module = NULL) {
  if ($default_types = features_get_default('recruit_application_type', $module)) {
    foreach ($default_types as $type_name => $type_info) {

      //Delete application type directly from {recruit_application_type} table.
      db_delete('recruit_application_type')
        ->condition('type', $type_name)
        ->execute();

    }
    recruit_application_types_rebuild();
    menu_rebuild();
  }
}