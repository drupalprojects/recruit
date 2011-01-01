<?php
// $Id$

/**
 * @file
 * Page callbacks and forms for applications types.
 */


/**
 * Menu callback: display an overview of available types.
 */
function recruit_application_ui_types_overview() {
  drupal_add_css(drupal_get_path('module', 'recurit_application_ui') . '/theme/recurit_application_ui.types.css');

  $header = array(
    t('Name'),
    t('Operations'),
  );

  $rows = array();

  //Loop through application types.
  foreach (recruit_application_types() as $type => $application_type) {
    //Build contextual links.
    $links = menu_contextual_links('recruit-application-type', 'admin/recruit/applications/types', array(strtr($type, array('_' => '-'))));

    $rows[] = array(
      theme('application_type_admin_overview', array('application_type' => $application_type)),
      theme('links', array('links' => $links, 'attributes' => array('class' => 'links inline operations'))),
    );
  }


  if (empty($rows)) {

    $rows[] = array(
      array(
        'data' => t('There are no application types yet. <a href="@link">Add application type</a>.', array('@link' => url('admin/recruit/applications/types/add'))),
        'colspan' => 2,
      )
    );
  }

  return theme('table', array('header' => $header, 'rows' => $rows));
}

/**
 * Builds an overview of a application type for display to an administrator.
 *
 * @param $variables
 * 
 */
function theme_application_type_admin_overview($variables) {
  $application_type = $variables['application_type'];

  $output = check_plain($application_type->name);
  $output .= ' <small> (Machine name: ' . check_plain($application_type->type) . ')</small>';
  $output .= '<div class="description">' . filter_xss_admin($application_type->description) . '</div>';

  return $output;
}

/**
 * Form callback wrapper: create or edit a application type.
 *
 * @param $application_type
 *   The application type object being edited by this form.
 *
 * @see recruit_application_application_type_form()
 */
function recurit_application_ui_application_type_form_wrapper($application_type) {

  recruit_application_ui_set_breadcrumb(TRUE);

  module_load_include('inc', 'recruit_application', 'includes/recruit_application.forms');

  return drupal_get_form('recruit_application_ui_application_type_form', $application_type);
}

/**
 * Form callback wrapper: confirmation form for deleting a application type.
 *
 * @param $application_type
 *   The application type object being deleted by this form.
 *
 * @see recruit_application_application_type_delete_form()
 */
function recruit_application_ui_application_type_delete_form_wrapper($application_type) {

  recruit_application_ui_set_breadcrumb(TRUE);

  module_load_include('inc', 'recruit_application', 'includes/recruit_application.forms');

  return drupal_get_form('recruit_application_ui_application_type_delete_form', $application_type);
}