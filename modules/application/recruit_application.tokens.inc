<?php

/**
 * @file
 * Exposes application data via token system.
 */


/**
 * Implements hook_token_info().
 */
function recruit_application_token_info() {
  $type = array(
    'name' => t('applications'),
    'description' => t('Tokens related to individual applications.'),
    'needs-data' => 'application',
  );

  // Tokens for applications.
  $application = array();

  $application['application-id'] = array(
    'name' => t('application ID'),
    'description' => t('The internal numeric ID of the application.'),
  );
  $application['type'] = array(
    'name' => t('Type'),
    'description' => t('The human readable name of the application type.'),
  );
  $application['first-name'] = array(
    'name' => t('first name'),
    'description' => t('The first name of the applicant.'),
  );
  $application['last-name'] = array(
    'name' => t('last name'),
    'description' => t('The last name of the applicant.'),
  );
  $application['edit-url'] = array(
    'name' => t('Edit URL'),
    'description' => t("The URL of the application's edit page."),
  );

  // Chained tokens for applications.
  $application['created'] = array(
    'name' => t('Date created'),
    'description' => t('The date the application was created.'),
    'type' => 'date',
  );
  $application['changed'] = array(
    'name' => t('Date updated'),
    'description' => t('The date the application was last updated.'),
    'type' => 'date',
  );

  return array(
    'types' => array('application' => $type),
    'tokens' => array('application' => $application),
  );
}

/**
 * Implements hook_tokens().
 */
function recruit_application_tokens($type, $tokens, array $data = array(), array $options = array()) {
  $url_options = array('absolute' => TRUE);

  if (isset($options['language'])) {
    $url_options['language'] = $options['language'];
    $language_code = $options['language']->language;
  }
  else {
    $language_code = NULL;
  }

  $sanitize = !empty($options['sanitize']);

  $replacements = array();

  if ($type == 'application' && !empty($data['application'])) {
    $application = $data['application'];

    foreach ($tokens as $name => $original) {
      switch ($name) {
        // Simple key values on the application.
        case 'application-id':
          $replacements[$original] = $application->application_id;
          break;

        case 'type':
          $replacements[$original] = $sanitize ? check_plain(recruit_application_type_get_name($application->type)) : recruit_application_type_get_name($application->type);
          break;

        case 'first-name':
          $replacements[$original] = $sanitize ? check_plain($application->first_name) : $application->first_name;
          break;
        case 'last-name':
          $replacements[$original] = $sanitize ? check_plain($application->last_name) : $application->last_name;
          break;

        case 'edit-url':
          $replacements[$original] = url('admin/recruit/applications/' . $application->application_id . '/edit', $url_options);
          break;

        // Default values for the chained tokens handled below.
        case 'created':
          $replacements[$original] = format_date($application->created, 'medium', '', NULL, $language_code);
          break;

        case 'changed':
          $replacements[$original] = format_date($application->changed, 'medium', '', NULL, $language_code);
          break;
      }
    }

    if ($created_tokens = token_find_with_prefix($tokens, 'created')) {
      $replacements += token_generate('date', $created_tokens, array('date' => $application->created), $options);
    }
  }

  return $replacements;
}
