<?php
// $Id$

/**
 * @file
 * Rules integration for applications.
 * 
 */

/**
 * Implements hook_rules_event_info().
 */
function recruit_application_rules_event_info() {
  $items = array(
    'recruit_application_insert' => array(
      'label' => t('After saving a new application'),
      'group' => t('Recruit'),
      'variables' => recruit_application_rules_variables(t('created application')),
      'access callback' => 'recruit_application_rules_access',
    ),
    'recruit_application_update' => array(
      'label' => t('After updating an existing application'),
      'group' => t('Recruit'),
      'variables' => recruit_application_rules_variables(t('updated application'), TRUE),
      'access callback' => 'recruit_application_rules_access',
    ),
    'recruit_application_presave' => array(
      'label' => t('Before saving a application'),
      'group' => t('Recruit'),
      'variables' => recruit_application_rules_variables(t('saved application'), TRUE),
      'access callback' => 'recruit_application_rules_access',
    ),
    'recruit_application_delete' => array(
      'label' => t('After deleting a application'),
      'group' => t('Recruit'),
      'variables' => recruit_application_rules_variables(t('deleted application')),
      'access callback' => 'recruit_application_rules_access',
    ),
  );
  // Specify that on presave the application is saved anyway.
  $items['recruit_application_presave']['variables']['application']['skip save'] = TRUE;
  return $items;
}

/**
 * Returns some parameter suitable for using it with a node
 */
function recruit_application_rules_variables($label, $update = FALSE) {
  $args = array(
    'application' => array('type' => 'recruit_application', 'label' => $label),
  );
  if ($update) {
    $args += array(
      'application_unchanged' => array(
        'type' => 'recruit_application',
        'label' => t('unchanged application'),
        'handler' => 'recruit_application_rules_var_unchanged',
      ),
    );
  }
  return $args;
}

/**
 * Rules integration access callback.
 */
function recruit_application_rules_access($type, $name) {
  if ($type == 'event' || $type == 'condition') {
    return recruit_application_access('view');
  }
}
