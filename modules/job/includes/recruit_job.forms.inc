<?php
// $Id$

/**
 * @file
 * General forms for jobs and job types.
 */

/**
 * Form callback: create or edit a job.
 *
 * @param $job
 */
function recruit_job_job_form($form, &$form_state, $job) {

  $form_state['build_info']['file'] = drupal_get_path('module', 'recruit_job') . '/includes/recruit_job.forms.inc';
  
  // Add the default field elements.
  $form['job_ref'] = array(
    '#type' => 'textfield',
    '#title' => t('Job Reference'),
    '#description' => t('Supply a unique identifier for this job using letters, numbers, hypens, and underscores.'),
    '#default_value' => $job->job_ref,
    '#maxlength' => 128,
    '#required' => TRUE,
    '#weight' => -10,
  );

  $form['title'] = array(
    '#type' => 'textfield',
    '#title' => t('Title'),
    '#default_value' => $job->title,
    '#maxlength' => 255,
    '#required' => TRUE,
    '#weight' => -5,
  );

  // Add the field related form elements. Attached fields.
  $form_state['recruit_job'] = $job;
  field_attach_form('recruit_job', $job, $form, $form_state);

  $form['status'] = array(
    '#type' => 'radios',
    '#title' => t('Status'),
    '#description' => t(''),
    '#options' => array(
      '1' => t('Active'),
      '0' => t('Disabled'),
    ),
    '#default_value' => $job->status,
    '#required' => TRUE,
    '#weight' => 35,
  );

  //TODO: fix up expiry
  if (variable_get('recruit_job_expiry_' . $job->type)) {
    $form['expiry'] = array(
      '#type' => 'date',
      '#title' => t('Expiry'),
      '#default_value' => recruit_job_ui_get_expiry_date($job),
      '#weight' => 36,
    );
  }

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
    '#value' => t('Save job'),
    '#submit' => $submit + array('recruit_job_job_form_submit'),
  );

  $form['#validate'][] = 'recruit_job_job_form_validate';

  return $form;
}

/**
 * Validation callback for recruit_job_job_form().
 */
function recruit_job_job_form_validate($form, &$form_state) {
  $job = $form_state['recruit_job'];

  $job_ref = $form_state['values']['job_ref'];

  if ($job_ref === FALSE) {
    form_set_error('job_ref', 'The job_ref contains invalid tokens.');
  }
  else {

    if (!recruit_job_validate_job_ref_characters($job_ref)) {
      form_set_error('job_ref', t('The job reference must contain only letters, numbers, hyphens, and underscores.'));
    }

    //Ensure job ref is unique.
    if (!recruit_job_validate_job_ref_unique($job_ref, $job->job_id)) {
      form_set_error('job_ref', 'This job reference is already in use and must be unique. Please supply another value.');
    }
  }

  // Notify field widgets to validate their data.
  field_attach_form_validate('recruit_job', $job, $form, $form_state);
}

/**
 * Submit callback for recruit_job_job_form().
 */
function recruit_job_job_form_submit($form, &$form_state) {
  global $user;

  $job = &$form_state['recruit_job'];

  //Set parameters.
  $job->job_ref = $form_state['values']['job_ref'];
  $job->title = $form_state['values']['title'];
  $job->status = $form_state['values']['status'];
  
  if (!empty($form_state['values']['expiry'])) {
    $job->expiry = $form_state['values']['expiry'];
  }

  if (empty($job->job_id)) {
    $job->uid = $user->uid;
  }

  // Notify field widgets.
  field_attach_submit('recruit_job', $job, $form, $form_state);

  // Save the job.
  recruit_job_save($job);

  // Set message.
  drupal_set_message(t('Job saved.'));
}

/**
 * Form callback: confirmation form for deleting a job.
 *
 * @param $job
 *   The job object to be deleted.
 *
 * @see confirm_form()
 */
function recruit_job_job_delete_form($form, &$form_state, $job) {
  $form_state['job'] = $job;

  $form_state['build_info']['file'] = drupal_get_path('module', 'recruit_job') . '/includes/recruit_job.forms.inc';

  $form['#submit'][] = 'recruit_job_job_delete_form_submit';

  $form = confirm_form($form,
    t('Are you sure you want to delete %title?', array('%title' => $job->title)),
    '',
    '<p>' . t('Job Reference: @job_ref. Deleting this job cannot be undone.', array('@job_ref' => $job->job_ref)) . '</p>',
    t('Delete'),
    t('Cancel'),
    'confirm'
  );

  return $form;
}

/**
 * Submit callback for recruit_job_job_delete_form().
 */
function recruit_job_job_delete_form_submit($form, &$form_state) {
  $job = $form_state['job'];

  if (recruit_job_delete($job->job_id)) {
    drupal_set_message(t('%title has been deleted.', array('%title' => $job->title)));
    watchdog('recruit_job', 'Deleted job %title (Job Reference: @job_ref).', array('%title' => $job->title, '@job_ref' => $job->job_ref), WATCHDOG_NOTICE);
  }
  else {
    drupal_set_message(t('%title could not be deleted.', array('%title' => $job->title)), 'error');
  }
}

/**
 * Form callback: create or edit a job type.
 *
 * @param $job_type
 */
function recruit_job_job_type_form($form, &$form_state, $job_type) {

  $form_state['build_info']['file'] = drupal_get_path('module', 'recruit_job') . '/includes/recruit_job.forms.inc';
  
  $form_state['job_type'] = $job_type;

  $form['job_type'] = array(
    '#tree' => TRUE,
  );

  $form['job_type']['name'] = array(
    '#type' => 'textfield',
    '#title' => t('Name'),
    '#default_value' => $job_type->name,
    '#description' => t('The human-readable name of this job type. It is recommended that this name begin with a capital letter and contain only letters, numbers, and spaces. This name must be unique.'),
    '#required' => TRUE,
    '#size' => 32,
    '#field_suffix' => ' <small id="edit-job-type-name-suffix">' . $job_type->type . '</small>',
  );

  if (empty($job_type->type)) {
    $form['job_type']['type'] = array(
      '#type' => 'machine_name',
      '#title' => t('Machine name'),
      '#default_value' => $job_type->type,
      '#maxlength' => 32,
      '#required' => TRUE,
      '#machine_name' => array(
        'exists' => 'recruit_job_type_load',
        'source' => array('job_type', 'name'),
      ),
      '#description' => t('The machine-readable name of this job type. This name must contain only lowercase letters, numbers, and underscores, it must be unique.'),
    );
  }

  //Add expiry fieldset
  $form['job_type']['expiry'] = array(
    '#type' => 'fieldset',
    '#title' => t('Job expiry'),
    '#collapsible' => FALSE,
    '#collapsed' => FALSE,
  );

  $form['job_type']['expiry']['expiry'] = array(
    '#type' => 'checkbox',
    '#default_value' => empty($job_type->type) ? 1 : $job_type->expiry['expiry'],
    '#title' => t('Enable job expiry'),
    '#description' => t('Do you want the job to automatically expire?'),
  );
  
  $form['job_type']['expiry']['days'] = array(
    '#type' => 'textfield',
    '#title' => t('Set default expiry in days'),
    '#size' => 5,
    '#states' => array(
      'visible' => array(
        ':input[name="job_type[expiry][expiry]"]' => array('checked' => TRUE),
      ),
    ),
    '#default_value' => empty($job_type->type) ? 30 : $job_type->expiry['days'],
  );

  $form['job_type']['description'] = array(
    '#type' => 'textarea',
    '#title' => t('Description'),
    '#description' => t('Describe this job type. The text will be displayed on the <em>Add new content</em> page.'),
    '#default_value' => $job_type->description,
    '#rows' => 3,
  );

  $form['job_type']['help'] = array(
    '#type' => 'textarea',
    '#title' => t('Explanation or submission guidelines'),
    '#description' => t('This text will be displayed at the top of the page when creating or editing jobs of this type.'),
    '#default_value' => $job_type->help,
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
    '#value' => t('Save job type'),
    '#submit' => $submit + array('recruit_job_job_type_form_submit'),
  );

  $form['#validate'][] = 'recruit_job_job_type_form_validate';

  return $form;
}

/**
 * Validation callback for recruit_job_job_type_form().
 */
function recruit_job_job_type_form_validate($form, &$form_state) {
  $job_type = $form_state['job_type'];

  // If saving a new job type, ensure it has a unique machine name.
  if (empty($job_type->type)) {
    if (!recruit_job_type_validate_type_unique($form_state['values']['job_type']['type'])) {
      form_set_error('job_type][type', 'The machine name specified is already in use.');
    }
  }
}

/**
 * Form submit handler: save a job type.
 */
function recruit_job_job_type_form_submit($form, &$form_state) {
  $job_type = $form_state['job_type'];
  $updated = !empty($job_type->type);

  foreach ($form_state['values']['job_type'] as $key => $value) {
    $job_type->$key = $value;
  }

  // Write the job type to the database.
  $job_type->is_new = !$updated;
  recruit_job_type_save($job_type);

  // Redirect based on the button clicked.
  drupal_set_message(t('Job type saved.'));
}

/**
 * Form callback: confirmation form for deleting a job type.
 *
 * @param $job_type
 *   The job type object to be deleted.
 *
 * @see confirm_form()
 */
function recruit_job_job_type_delete_form($form, &$form_state, $job_type) {
  $form_state['job_type'] = $job_type;

  $form_state['build_info']['file'] = drupal_get_path('module', 'recruit_job') . '/includes/recruit_job.forms.inc';

  $form['#submit'][] = 'recruit_job_job_type_delete_form_submit';

  $form = confirm_form($form,
    t('Are you sure you want to delete the %name job type?', array('%name' => $job_type->name)),
    '',
    '<p>' . t('This action cannot be undone.') . '</p>',
    t('Delete'),
    t('Cancel'),
    'confirm'
  );

  return $form;
}

/**
 * Submit callback for recruit_job_job_type_delete_form().
 */
function recruit_job_job_type_delete_form_submit($form, &$form_state) {
  $job_type = $form_state['job_type'];

  recruit_job_type_delete($job_type->type);

  drupal_set_message(t('The job type %name has been deleted.', array('%name' => $job_type->name)));
  watchdog('recruit_job', 'Deleted job type %name.', array('%name' => $job_type->name), WATCHDOG_NOTICE);
}