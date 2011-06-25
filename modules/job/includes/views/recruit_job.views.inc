<?php

/**
 * @file
 * Exposes recruit_job.module fields to views.
 */

/**
 * Export Recruit jobs to Views.
 */

/**
 * Implements hook_views_data_alter()
 * EntityAPI implements hook_views_data for the recruit_job. 
 */
function recruit_job_views_data_alter(&$data) {
  $data['recruit_job']['table']['base']['help'] = t('Job posting.');

  // Expose the job reference.
  $data['recruit_job']['job_ref'] = array(
    'title' => t('Job reference'),
    'help' => t('The reference of the job used for administrative display.'),
    'field' => array(
      'handler' => 'recruit_job_handler_field_job',
      'click sortable' => TRUE,
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_string',
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
    'argument' => array(
      'handler' => 'views_handler_argument_string',
    ),
  );

  // Expose the job title.
  $data['recruit_job']['title'] = array(
    'title' => t('Title'),
    'help' => t('The title of the job used for administrative display.'),
    'field' => array(
      'handler' => 'recruit_job_handler_field_job',
      'click sortable' => TRUE,
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_string',
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
    'argument' => array(
      'handler' => 'views_handler_argument_string',
    ),
  );
  
  // Expose the job type.
  $data['recruit_job']['type'] = array(
    'title' => t('Type'),
    'help' => t('The human-readable name of the type of the job.'),
    'field' => array(
      'handler' => 'recruit_job_handler_field_job_type',
      'click sortable' => TRUE,
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_string',
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
    'argument' => array(
      'handler' => 'views_handler_argument_string',
    ),
  );

  // uid field
  $data['recruit_job']['uid'] = array(
    'title' => t('Creator'),
    'help' => t('Relate content to the user who created it.'),
    'relationship' => array(
      'handler' => 'views_handler_relationship',
      'base' => 'users',
      'field' => 'uid',
      'label' => t('Job creator'),
    ),
  );

  // Expose the created and changed timestamps.
  $data['recruit_job']['created'] = array(
    'title' => t('Created date'),
    'help' => t('The date the job was created.'),
    'field' => array(
      'handler' => 'views_handler_field_date',
      'click sortable' => TRUE,
    ),
    'sort' => array(
      'handler' => 'views_handler_sort_date',
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_date',
    ),
  );

  $data['recruit_job']['changed'] = array(
    'title' => t('Updated date'),
    'help' => t('The date the job was last updated.'),
    'field' => array(
      'handler' => 'views_handler_field_date',
      'click sortable' => TRUE,
    ),
    'sort' => array(
      'handler' => 'views_handler_sort_date',
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_date',
    ),
  );
  
  $data['recruit_job']['view_job'] = array(
    'field' => array(
      'title' => t('Link'),
      'help' => t('Provide a simple link to the administrator view of the job.'),
      'handler' => 'recruit_job_handler_field_job_link',
    ),
  );

  $data['recruit_job']['edit_job'] = array(
    'field' => array(
      'title' => t('Edit link'),
      'help' => t('Provide a simple link to edit the job.'),
      'handler' => 'recruit_job_handler_field_job_link_edit',
    ),
  );

  $data['recruit_job']['delete_job'] = array(
    'field' => array(
      'title' => t('Delete link'),
      'help' => t('Provide a simple link to delete the job.'),
      'handler' => 'recruit_job_handler_field_job_link_delete',
    ),
  );

  $data['recruit_job']['operations'] = array(
    'field' => array(
      'title' => t('Operations links'),
      'help' => t('Display all the available operations links for the job.'),
      'handler' => 'recruit_job_handler_field_job_operations',
    ),
  );
}