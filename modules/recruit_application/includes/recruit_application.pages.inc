<?php


function recruit_application_view_page($application, $view_mode = 'full') {
  return 'test';
}

/**
 * Menu callback for used for node applications tab.
 */
function recruit_application_add_page($node) {
  // Create new application object.
  $application = recruit_application_new($node);

  // Return form.
  return drupal_get_form("recruit_application_node_" . $node->type . "_form", $application);
}

function recruit_application_edit_page($application) {
  // Set edit form title.
  drupal_set_title(recruit_application_title($application));
  // Return form.
  return drupal_get_form($application->node_type  . "_form", $application);
}

function recruit_application_delete_page($application) {
  // Return form.
  return 'test';
  #return drupal_get_form($application->node_type  . "_form", $application);
}