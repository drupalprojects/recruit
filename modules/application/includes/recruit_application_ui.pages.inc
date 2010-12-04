<?php
// $Id$

/**
 * @file
 * Page callbacks functions for frontend displayed applications.
 */

function recruit_application_ui_view_page($application) {

  drupal_set_breadcrumb(array(l(t('Home'), '<front>'),l(t('applications'), 'recruit-application')));
  //Load css.
  drupal_add_css(drupal_get_path('module', 'recruit_application') . '/theme/recruit-application.css');

  //Set page title.
  drupal_set_title(check_plain($application->title));

  return recruit_application_ui_application_view($application);
}