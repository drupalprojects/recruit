<?php
// $Id$

/**
 * @file
 * General forms for applications and application types.
 */

/**
 * Form callback: create or edit a application.
 *
 * @param $application
 */
function recruit_application_application_form($form, &$form_state, $application) {

  $form_state['build_info']['file'] = drupal_get_path('module', 'recruit_application') . '/includes/recruit_application.forms.inc';

  $form['first_name'] = array(
    '#type' => 'textfield',
    '#title' => t('First name'),
    '#default_value' => $application->first_name,
    '#maxlength' => 255,
    '#required' => TRUE,
    '#weight' => -5,
  );

  $form['last_name'] = array(
    '#type' => 'textfield',
    '#title' => t('Last name'),
    '#default_value' => $application->last_name,
    '#maxlength' => 255,
    '#required' => TRUE,
    '#weight' => -6,
  );

  // Add the field related form elements. Attached fields.
  $form_state['recruit_application'] = $application;
  field_attach_form('recruit_application', $application, $form, $form_state);

  $form['status'] = array(
    '#type' => 'radios',
    '#title' => t('Status'),
    '#description' => t(''),
    '#options' => array(
      '1' => t('Active'),
      '0' => t('Disabled'),
    ),
    '#default_value' => $application->status,
    '#required' => TRUE,
    '#weight' => 35,
  );

  $form['actions'] = array(
    '#type' => 'container',
    '#attributes' => array('class' => array('form-actions')),
    '#weight' => 40,
  );

  $submit = array();

  if (!empty($form['#submit'])) {
    $submit += $form['#submit'];
  }

  $form['actions']['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Save application'),
    '#submit' => $submit + array('recruit_application_application_form_submit'),
  );

  $form['#validate'][] = 'recruit_application_application_form_validate';

  return $form;
}

/**
 * Validation callback for recruit_application_application_form().
 */
function recruit_application_application_form_validate($form, &$form_state) {
  $application = $form_state['recruit_application'];

  // Notify field widgets to validate their data.
  field_attach_form_validate('recruit_application', $application, $form, $form_state);
}

/**
 * Submit callback for recruit_application_application_form().
 */
function recruit_application_application_form_submit($form, &$form_state) {
  global $user;

  $application = &$form_state['recruit_application'];

  //Set parameters.
  $application->first_name = $form_state['values']['first_name'];
  $application->last_name = $form_state['values']['last_name'];
  $application->status = $form_state['values']['status'];

  if (empty($application->application_id)) {
    $application->uid = $user->uid;
  }

  // Notify field widgets.
  field_attach_submit('recruit_application', $application, $form, $form_state);

  // Save the application.
  recruit_application_save($application);

  // Set message.
  drupal_set_message(t('application saved.'));
}

/**
 * Form callback: confirmation form for deleting a application.
 *
 * @param $application
 *   The application object to be deleted.
 *
 * @see confirm_form()
 */
function recruit_application_application_delete_form($form, &$form_state, $application) {
  $form_state['application'] = $application;

  $form_state['build_info']['file'] = drupal_get_path('module', 'recruit_application') . '/includes/recruit_application.forms.inc';

  $form['#submit'][] = 'recruit_application_application_delete_form_submit';

  $form = confirm_form($form,
    t('Are you sure you want to delete Application ID: %application_id?', array('%application_id' => $application->application_id)),
    '',
    '<p>' . t('Application ID: @application_id. Deleting this application cannot be undone.', array('@application_id' => $application->application_id)) . '</p>',
    t('Delete'),
    t('Cancel'),
    'confirm'
  );

  return $form;
}

/**
 * Submit callback for recruit_application_application_delete_form().
 */
function recruit_application_application_delete_form_submit($form, &$form_state) {
  $application = $form_state['application'];

  if (recruit_application_delete($application->application_id)) {
    drupal_set_message(t('Application ID: %application_id has been deleted.', array('%application_id' => $application->application_id)));
    watchdog('recruit_application', 'Deleted application ID: @application_id.', array('@application_id' => $application->application_id), WATCHDOG_NOTICE);
  }
  else {
    drupal_set_message(t('Application ID: %application_id could not be deleted.', array('%application_id' => $application->application_id)), 'error');
  }
}

/**
 * Form callback: create or edit a application type.
 *
 * @param $application_type
 */
function recruit_application_application_type_form($form, &$form_state, $application_type) {

  $form_state['build_info']['file'] = drupal_get_path('module', 'recruit_application') . '/includes/recruit_application.forms.inc';
  
  $form_state['application_type'] = $application_type;

  $form['application_type'] = array(
    '#tree' => TRUE,
  );

  $form['application_type']['name'] = array(
    '#type' => 'textfield',
    '#title' => t('Name'),
    '#default_value' => $application_type->name,
    '#description' => t('The human-readable name of this application type. It is recommended that this name begin with a capital letter and contain only letters, numbers, and spaces. This name must be unique.'),
    '#required' => TRUE,
    '#size' => 32,
    '#field_suffix' => ' <small id="edit-application-type-name-suffix">' . $application_type->type . '</small>',
  );

  if (empty($application_type->type)) {
    $form['application_type']['type'] = array(
      '#type' => 'machine_name',
      '#title' => t('Machine name'),
      '#default_value' => $application_type->type,
      '#maxlength' => 32,
      '#required' => TRUE,
      '#machine_name' => array(
        'exists' => 'recruit_application_type_load',
        'source' => array('application_type', 'name'),
      ),
      '#description' => t('The machine-readable name of this application type. This name must contain only lowercase letters, numbers, and underscores, it must be unique.'),
    );
  }

  $form['application_type']['description'] = array(
    '#type' => 'textarea',
    '#title' => t('Description'),
    '#description' => t('Describe this application type. The text will be displayed on the <em>Add new content</em> page.'),
    '#default_value' => $application_type->description,
    '#rows' => 3,
  );

  $form['application_type']['help'] = array(
    '#type' => 'textarea',
    '#title' => t('Explanation or submission guidelines'),
    '#description' => t('This text will be displayed at the top of the page when creating or editing applications of this type.'),
    '#default_value' => $application_type->help,
    '#rows' => 3,
  );

  $form['actions'] = array(
    '#type' => 'container',
    '#attributes' => array('class' => array('form-actions')),
    '#weight' => 40,
  );

  $submit = array();

  if (!empty($form['#submit'])) {
    $submit += $form['#submit'];
  }

  $form['actions']['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Save application type'),
    '#submit' => $submit + array('recruit_application_application_type_form_submit'),
  );

  $form['#validate'][] = 'recruit_application_application_type_form_validate';

  return $form;
}

/**
 * Validation callback for recruit_application_application_type_form().
 */
function recruit_application_application_type_form_validate($form, &$form_state) {
  $application_type = $form_state['application_type'];

  // If saving a new application type, ensure it has a unique machine name.
  if (empty($application_type->type)) {
    if (!recruit_application_type_validate_type_unique($form_state['values']['application_type']['type'])) {
      form_set_error('application_type][type', 'The machine name specified is already in use.');
    }
  }
}

/**
 * Form submit handler: save a application type.
 */
function recruit_application_application_type_form_submit($form, &$form_state) {
  $application_type = $form_state['application_type'];
  $updated = !empty($application_type->type);

  foreach ($form_state['values']['application_type'] as $key => $value) {
    $application_type->$key = $value;
  }

  // Write the application type to the database.
  $application_type->is_new = !$updated;
  $application_type->modified = $updated;
  
  recruit_application_type_save($application_type);

  recruit_application_types_rebuild();

  // Redirect based on the button clicked.
  drupal_set_message(t('application type saved.'));
}

/**
 * Form callback: confirmation form for deleting a application type.
 *
 * @param $application_type
 *   The application type object to be deleted.
 *
 * @see confirm_form()
 */
function recruit_application_application_type_delete_form($form, &$form_state, $application_type) {
  $form_state['application_type'] = $application_type;

  $form_state['build_info']['file'] = drupal_get_path('module', 'recruit_application') . '/includes/recruit_application.forms.inc';

  $form['#submit'][] = 'recruit_application_application_type_delete_form_submit';

  $form = confirm_form($form,
    t('Are you sure you want to delete the %name application type?', array('%name' => $application_type->name)),
    '',
    '<p>' . t('This action cannot be undone.') . '</p>',
    t('Delete'),
    t('Cancel'),
    'confirm'
  );

  return $form;
}

/**
 * Submit callback for recruit_application_application_type_delete_form().
 */
function recruit_application_application_type_delete_form_submit($form, &$form_state) {
  $application_type = $form_state['application_type'];

  recruit_application_type_delete($application_type->type);
  
  recruit_application_types_rebuild();

  drupal_set_message(t('The application type %name has been deleted.', array('%name' => $application_type->name)));
  watchdog('recruit_application', 'Deleted application type %name.', array('%name' => $application_type->name), WATCHDOG_NOTICE);
}