<?php
// $Id$

/**
 * @file
 * Page callbacks and forms for jobs types.
 */


/**
 * Menu callback: display an overview of available types.
 */
function recruit_job_ui_types_overview() {
  drupal_add_css(drupal_get_path('module', 'recurit_job_ui') . '/theme/recurit_job_ui.types.css');

  $header = array(
    t('Name'),
    t('Operations'),
  );

  $rows = array();

  //Loop through job types.
  foreach (recruit_job_types() as $type => $job_type) {
    //Build contextual links.
    $links = menu_contextual_links('recruit-job-type', 'admin/recruit/jobs/types', array($type));

    $rows[] = array(
      theme('job_type_admin_overview', array('job_type' => $job_type)),
      theme('links', array('links' => $links, 'attributes' => array('class' => 'links operations'))),
    );
  }


  if (empty($rows)) {

    $rows[] = array(
      array(
        'data' => t('There are no job types yet. <a href="@link">Add job type</a>.', array('@link' => url('admin/recruit/jobs/types/add'))),
        'colspan' => 2,
      )
    );
  }

  return theme('table', array('header' => $header, 'rows' => $rows));
}

/**
 * Builds an overview of a job type for display to an administrator.
 *
 * @param $variables
 * 
 */
function theme_job_type_admin_overview($variables) {
  $job_type = $variables['job_type'];

  $output = check_plain($job_type->name);
  $output .= ' <small> (Machine name: ' . check_plain($job_type->type) . ')</small>';
  $output .= '<div class="description">' . filter_xss_admin($job_type->description) . '</div>';

  return $output;
}

/**
 * Form callback wrapper: create or edit a job type.
 *
 * @param $job_type
 *   The job type object being edited by this form.
 *
 * @see recruit_job_job_type_form()
 */
function recurit_job_ui_job_type_form_wrapper($job_type) {

  recruit_job_ui_set_breadcrumb(TRUE);

  module_load_include('inc', 'recruit_job', 'includes/recruit_job.forms');

  return drupal_get_form('recruit_job_ui_job_type_form', $job_type);
}

/**
 * Form callback wrapper: confirmation form for deleting a job type.
 *
 * @param $job_type
 *   The job type object being deleted by this form.
 *
 * @see recruit_job_job_type_delete_form()
 */
function recruit_job_ui_job_type_delete_form_wrapper($job_type) {

  recruit_job_ui_set_breadcrumb(TRUE);

  module_load_include('inc', 'recruit_job', 'includes/recruit_job.forms');

  return drupal_get_form('recruit_job_ui_job_type_delete_form', $job_type);
}