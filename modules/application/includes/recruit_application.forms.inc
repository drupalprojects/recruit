<?php
// $Id$

/**
 * @file
 * Forms for creating / editing and deleting applications.
 */

/**
 * Form callback: create or edit a application.
 *
 * @param $application
 *   The application object to edit or for a create form an empty application object
 *     with only a application type defined.
 */
function recruit_application_application_form($form, &$form_state, $application) {
  // Ensure this include file is loaded when the form is rebuilt from the cache.
  $form_state['build_info']['file'] = drupal_get_path('module', 'recruit_application') . '/includes/recruit_application.forms.inc';

  // Add the default field elements.
  $form['application_ref'] = array(
    '#type' => 'textfield',
    '#title' => t('application Reference'),
    '#description' => t('Supply a unique identifier for this application using letters, numbers, hypens, and underscores.'),
    '#default_value' => $application->application_ref,
    '#maxlength' => 128,
    '#required' => TRUE,
    '#weight' => -10,
  );

  $form['title'] = array(
    '#type' => 'textfield',
    '#title' => t('Title'),
    '#default_value' => $application->title,
    '#maxlength' => 255,
    '#required' => TRUE,
    '#weight' => -5,
  );

  // Add the field related form elements.
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

  // We add the form's #submit array to this button along with the actual submit
  // handler to preserve any submit handlers added by a form callback_wrapper.
  $submit = array();

  if (!empty($form['#submit'])) {
    $submit += $form['#submit'];
  }

  $form['actions']['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Save application'),
    '#submit' => $submit + array('recruit_application_application_form_submit'),
  );

  // We append the validate handler to #validate in case a form callback_wrapper
  // is used to add validate handlers earlier.
  $form['#validate'][] = 'recruit_application_application_form_validate';

  return $form;
}

/**
 * Validation callback for recruit_application_application_form().
 */
function recruit_application_application_form_validate($form, &$form_state) {
  $application = $form_state['recruit_application'];

  // Until the above is resolved, simply use the SKU as entered with no tokens.
  $application_ref = $form_state['values']['application_ref'];

  // If invalid tokens were specified, throw an error.
  if ($application_ref === FALSE) {
    form_set_error('application_ref', 'The application_ref contains invalid tokens.');
  }
  else {
    // Validate the remaining characters of the string.
    if (!recruit_application_validate_application_ref_characters($application_ref)) {
      form_set_error('application_ref', t('The application reference must contain only letters, numbers, hyphens, and underscores.'));
    }

    // Ensure the proposed application ref is unique.
    if (!recruit_application_validate_application_ref_unique($application_ref, $application->application_id)) {
      form_set_error('application_ref', 'This application reference is already in use and must be unique. Please supply another value.');
    }
  }

  // Notify field widgets to validate their data.
  field_attach_form_validate('recruit_application', $application, $form, $form_state);
}

/**
 * Submit callback for recruit_application_application_form().
 */
function recruit_application_application_form_submit($form, &$form_state) {
  global $user;

  $application = &$form_state['recruit_application'];

  // Save default parameters back into the $application object.
  $application->application_ref = $form_state['values']['application_ref'];
  $application->title = $form_state['values']['title'];
  $application->status = $form_state['values']['status'];

  // Set the application's uid if it's being created at this time.
  if (empty($application->application_id)) {
    $application->uid = $user->uid;
  }

  // Notify field widgets.
  field_attach_submit('recruit_application', $application, $form, $form_state);

  // Save the application.
  recruit_application_save($application);

  // Redirect based on the button clicked.
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

  // Ensure this include file is loaded when the form is rebuilt from the cache.
  $form_state['build_info']['file'] = drupal_get_path('module', 'recruit_application') . '/includes/recruit_application.forms.inc';

  $form['#submit'][] = 'recruit_application_application_delete_form_submit';

  $form = confirm_form($form,
    t('Are you sure you want to delete %title?', array('%title' => $application->title)),
    '',
    '<p>' . t('application Reference: @application_ref. Deleting this application cannot be undone.', array('@application_ref' => $application->application_ref)) . '</p>',
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
    drupal_set_message(t('%title has been deleted.', array('%title' => $application->title)));
    watchdog('recruit_application', 'Deleted application %title (application Reference: @application_ref).', array('%title' => $application->title, '@application_ref' => $application->application_ref), WATCHDOG_NOTICE);
  }
  else {
    drupal_set_message(t('%title could not be deleted.', array('%title' => $application->title)), 'error');
  }
}

/**
 * Form callback: create or edit a application type.
 *
 * @param $application_type
 *   The application type object to edit or for a create form an empty application type
 *     object with properties instantiated but not populated.
 */
function recruit_application_application_type_form($form, &$form_state, $application_type) {
  // Ensure this include file is loaded when the form is rebuilt from the cache.
  $form_state['build_info']['file'] = drupal_get_path('module', 'recruit_application') . '/includes/recruit_application.forms.inc';

  // Store the initial application type in the form state.
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

  // We add the form's #submit array to this button along with the actual submit
  // handler to preserve any submit handlers added by a form callback_wrapper.
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
  recruit_application_type_save($application_type);

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

  // Ensure this include file is loaded when the form is rebuilt from the cache.
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

  drupal_set_message(t('The application type %name has been deleted.', array('%name' => $application_type->name)));
  watchdog('recruit_application', 'Deleted application type %name.', array('%name' => $application_type->name), WATCHDOG_NOTICE);
}