<?php

/**
 * Generates the application type editing form.
 */
function recruit_application_type_form($form, &$form_state, $application_type, $op = 'edit') {

  if ($op == 'clone') {
    $application_type->label .= ' (cloned)';
    $application_type->type = '';
  }

  $form['label'] = array(
    '#title' => t('Label'),
    '#type' => 'textfield',
    '#default_value' => $application_type->label,
    '#description' => t('The human-readable name of this application type.'),
    '#required' => TRUE,
    '#size' => 30,
  );

  // Machine-readable type name.
  $form['type'] = array(
    '#type' => 'machine_name',
    '#default_value' => isset($application_type->type) ? $application_type->type : '',
    '#maxlength' => 32,
    '#disabled' => $application_type->isLocked() && $op != 'clone',
    '#machine_name' => array(
      'exists' => 'recruit_application_types',
      'source' => array('label'),
    ),
    '#description' => t('A unique machine-readable name for this application type. It must only contain lowercase letters, numbers, and underscores.'),
  );

  $form['description'] = array(
    '#type' => 'textarea',
    '#default_value' => isset($application_type->description) ? $application_type->description : '',
    '#description' => t('Description about the application type.'),
  );

  $form['actions'] = array('#type' => 'actions');
  $form['actions']['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Save application type'),
    '#weight' => 40,
  );

  if (!$application_type->isLocked() && $op != 'add' && $op != 'clone') {
    $form['actions']['delete'] = array(
      '#type' => 'submit',
      '#value' => t('Delete application type'),
      '#weight' => 45,
      '#limit_validation_errors' => array(),
      '#submit' => array('recruit_application_type_form_submit_delete')
    );
  }
  return $form;
}

/**
 * Submit handler for creating/editing application_type.
 */
function recruit_application_type_form_submit(&$form, &$form_state) {
  $application_type = entity_ui_form_submit_build_entity($form, $form_state);
  // Save and go back.
  recruit_application_type_save($application_type);

  // Redirect user back to list of application types.
  $form_state['redirect'] = 'admin/structure/application-types';
}

function recruit_application_type_form_submit_delete(&$form, &$form_state) {
  $form_state['redirect'] = 'admin/structure/application-types/' . $form_state['recruit_application_type']->type . '/delete';
}

/**
 * application type delete form.
 */
function recruit_application_type_form_delete_confirm($form, &$form_state, $application_type) {
  $form_state['application_type'] = $application_type;
  // Always provide entity id in the same form key as in the entity edit form.
  $form['application_type_id'] = array('#type' => 'value', '#value' => entity_id('recruit_application_type' ,$application_type));
  return confirm_form($form,
    t('Are you sure you want to delete application type %title?', array('%title' => entity_label('application_type', $application_type))),
    'application/' . entity_id('recruit_application_type' ,$application_type),
    t('This action cannot be undone.'),
    t('Delete'),
    t('Cancel')
  );
}

/**
 * application type delete form submit handler.
 */
function recruit_application_type_form_delete_confirm_submit($form, &$form_state) {
  $application_type = $form_state['application_type'];
  recruit_application_type_delete($application_type);

  watchdog('recruit_application_type', '@type: deleted %title.', array('@type' => $application_type->type, '%title' => $application_type->label));
  drupal_set_message(t('@type %title has been deleted.', array('@type' => $application_type->type, '%title' => $application_type->label)));

  $form_state['redirect'] = 'admin/structure/application-types';
}

/**
 * Page to select application Type to add new application.
 */
function recruit_application_admin_add_page() {
  $items = array();
  foreach (recruit_application_types() as $application_type_key => $application_type) {
    $items[] = l(entity_label('recruit_application_type', $application_type), 'application/add/' . $application_type_key);
  }
  return array('list' => array('#theme' => 'item_list', '#items' => $items, '#title' => t('Select type of application to create.')));
}

/**
 * Add new application page callback.
 */
function recruit_application_add($type) {
  $application_type = recruit_application_types($type);

  $application = entity_create('recruit_application', array('type' => $type));
  drupal_set_title(t('Create @name', array('@name' => entity_label('application_type', $application_type))));

  $output = drupal_get_form('recruit_application_form', $application);

  return $output;
}

/**
 * application Form.
 */
function recruit_application_form($form, &$form_state, $application) {
  $form_state['application'] = $application;

  $form['title'] = array(
    '#type' => 'textfield',
    '#required' => TRUE,
    '#title' => t('Name'),
    '#default_value' => $application->title,
  );

  $form['description'] = array(
    '#type' => 'textarea',
    '#title' => t('Description'),
    '#default_value' => $application->description,
  );

  $form['uid'] = array(
    '#type' => 'value',
    '#value' => $application->uid,
  );

  field_attach_form('recruit_application', $application, $form, $form_state);

  $submit = array();
  if (!empty($form['#submit'])) {
    $submit += $form['#submit'];
  }

  $form['actions'] = array(
    '#weight' => 100,
  );

  $form['actions']['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Save application'),
    '#submit' => $submit + array('recruit_application_form_submit'),
  );

  // Show Delete button if we edit application.
  $application_id = entity_id('recruit_application' ,$application);
  if (!empty($application_id) && recruit_application_access('edit', $application)) {
    $form['actions']['delete'] = array(
      '#type' => 'submit',
      '#value' => t('Delete'),
      '#submit' => array('recruit_application_form_submit_delete'),
    );
  }

  $form['#validate'][] = 'recruit_application_form_validate';

  return $form;
}

function recruit_application_form_validate($form, &$form_state) {

}

/**
 * application submit handler.
 */
function recruit_application_form_submit($form, &$form_state) {
  $application = $form_state['application'];

  entity_form_submit_build_entity('recruit_application', $application, $form, $form_state);

  recruit_application_save($application);

  $application_uri = entity_uri('recruit_application', $application);

  $form_state['redirect'] = $application_uri['path'];

  drupal_set_message(t('application %title saved.', array('%title' => entity_label('recruit_application', $application))));
}

function recruit_application_form_submit_delete($form, &$form_state) {
  $application = $form_state['application'];
  $application_uri = entity_uri('recruit_application', $application);
  $form_state['redirect'] = $application_uri['path'] . '/delete';
}

/**
 * Delete confirmation form.
 */
function recruit_application_delete_form($form, &$form_state, $application) {
  $form_state['application'] = $application;
  // Always provide entity id in the same form key as in the entity edit form.
  $form['application_type_id'] = array('#type' => 'value', '#value' => entity_id('recruit_application' ,$application));
  $application_uri = entity_uri('recruit_application', $application);
  return confirm_form($form,
    t('Are you sure you want to delete application %title?', array('%title' => entity_label('recruit_application', $application))),
    $application_uri['path'],
    t('This action cannot be undone.'),
    t('Delete'),
    t('Cancel')
  );
}

/**
 * Delete form submit handler.
 */
function recruit_application_delete_form_submit($form, &$form_state) {
  $application = $form_state['application'];
  recruit_application_delete($application);

  drupal_set_message(t('application %title deleted.', array('%title' => entity_label('recruit_application', $application))));

  $form_state['redirect'] = '<front>';
}