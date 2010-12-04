<?php
// $Id$

/**
 * @file
 * Page callbacks functions for frontend displayed jobs.
 */

function recruit_job_ui_view_page($job) {

  drupal_set_breadcrumb(array(l(t('Home'), '<front>'), l(t('Jobs'), 'recruit-job')));
  //Load css.
  drupal_add_css(drupal_get_path('module', 'recruit_job') . '/theme/recruit-job.css');

  //Set page title.
  drupal_set_title(check_plain($job->title));

  return recruit_job_ui_job_view($job);
}