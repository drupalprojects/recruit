<?php
// $Id$

/**
 * @file
 * Rules integration for jobs.
 * 
 */

/**
 * Implements hook_rules_event_info().
 */
function recruit_job_rules_event_info() {
  $items = array(
    'recruit_job_insert' => array(
      'label' => t('After saving a new job'),
      'group' => t('Recruit'),
      'variables' => recruit_job_rules_variables(t('created job')),
      'access callback' => 'recruit_job_rules_access',
    ),
    'recruit_job_update' => array(
      'label' => t('After updating an existing job'),
      'group' => t('Recruit'),
      'variables' => recruit_job_rules_variables(t('updated job'), TRUE),
      'access callback' => 'recruit_job_rules_access',
    ),
    'recruit_job_presave' => array(
      'label' => t('Before saving a job'),
      'group' => t('Recruit'),
      'variables' => recruit_job_rules_variables(t('saved job'), TRUE),
      'access callback' => 'recruit_job_rules_access',
    ),
    'recruit_job_delete' => array(
      'label' => t('After deleting a job'),
      'group' => t('Recruit'),
      'variables' => recruit_job_rules_variables(t('deleted job')),
      'access callback' => 'recruit_job_rules_access',
    ),
  );
  // Specify that on presave the job is saved anyway.
  $items['recruit_job_presave']['variables']['job']['skip save'] = TRUE;
  return $items;
}

/**
 * Returns some parameter suitable for using it with a node
 */
function recruit_job_rules_variables($label, $update = FALSE) {
  $args = array(
    'job' => array('type' => 'recruit_job', 'label' => $label),
  );
  if ($update) {
    $args += array(
      'job_unchanged' => array(
        'type' => 'recruit_job',
        'label' => t('unchanged job'),
        'handler' => 'recruit_job_rules_var_unchanged',
      ),
    );
  }
  return $args;
}

/**
 * Rules integration access callback.
 */
function recruit_job_rules_access($type, $name) {
  if ($type == 'event' || $type == 'condition') {
    return recruit_job_access('view');
  }
}
