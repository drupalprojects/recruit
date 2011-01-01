<?php
// $Id$

/**
 * @file
 * Exposes job data via token system.
 */


/**
 * Implements hook_token_info().
 */
function recruit_job_token_info() {
  $type = array(
    'name' => t('Jobs'),
    'description' => t('Tokens related to individual jobs.'),
    'needs-data' => 'job',
  );

  // Tokens for jobs.
  $job = array();

  $job['job-id'] = array(
    'name' => t('Job ID'),
    'description' => t('The internal numeric ID of the job.'),
  );
  $job['job-ref'] = array(
    'name' => t('Job Reference'),
    'description' => t('The human readable job reference.'),
  );
  $job['type'] = array(
    'name' => t('Type'),
    'description' => t('The human readable name of the job type.'),
  );
  $job['title'] = array(
    'name' => t('Title'),
    'description' => t('The title of the job.'),
  );
  $job['edit-url'] = array(
    'name' => t('Edit URL'),
    'description' => t("The URL of the job's edit page."),
  );

  // Chained tokens for jobs.
  $job['created'] = array(
    'name' => t('Date created'),
    'description' => t('The date the job was created.'),
    'type' => 'date',
  );
  $job['changed'] = array(
    'name' => t('Date updated'),
    'description' => t('The date the job was last updated.'),
    'type' => 'date',
  );

  return array(
    'types' => array('job' => $type),
    'tokens' => array('job' => $job),
  );
}

/**
 * Implements hook_tokens().
 */
function recruit_job_tokens($type, $tokens, array $data = array(), array $options = array()) {
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

  if ($type == 'job' && !empty($data['job'])) {
    $job = $data['job'];

    foreach ($tokens as $name => $original) {
      switch ($name) {
        // Simple key values on the job.
        case 'job-id':
          $replacements[$original] = $job->job_id;
          break;

        case 'job-ref':
          $replacements[$original] = $sanitize ? check_plain($job->job_ref) : $job->job_ref;
          break;

        case 'type':
          $replacements[$original] = $sanitize ? check_plain(recruit_job_type_get_name($job->type)) : recruit_job_type_get_name($job->type);
          break;

        case 'title':
          $replacements[$original] = $sanitize ? check_plain($job->title) : $job->title;
          break;

        case 'edit-url':
          $replacements[$original] = url('admin/recruit/jobs/' . $job->job_id . '/edit', $url_options);
          break;

        // Default values for the chained tokens handled below.
        case 'created':
          $replacements[$original] = format_date($job->created, 'medium', '', NULL, $language_code);
          break;

        case 'changed':
          $replacements[$original] = format_date($job->changed, 'medium', '', NULL, $language_code);
          break;
      }
    }

    if ($created_tokens = token_find_with_prefix($tokens, 'created')) {
      $replacements += token_generate('date', $created_tokens, array('date' => $job->created), $options);
    }
  }

  return $replacements;
}
