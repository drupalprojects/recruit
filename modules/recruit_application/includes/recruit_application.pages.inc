<?php

/**
 * @file
 * Defines functions used in menu callback view, create, edit.
 */

/**
 * Menu callback for used for application view page.
 */
function recruit_application_view_page($application, $view_mode = 'full') {
  return $application->view($view_mode);
}

/**
 * Menu callback for used for application add form.
 */
function recruit_application_add_page($node) {
  // Create new application object.
  $application = recruit_application_new($node);
  dsm($application);
  // Return form.
  return drupal_get_form($application->node_type  . "_form", $application);
}

/**
 * Menu callback for used for application edit form.
 */
function recruit_application_edit_page($application) {
  // Set edit form title.
  drupal_set_title(recruit_application_title($application));
  // Return form.
  return drupal_get_form($application->node_type  . "_form", $application);
}