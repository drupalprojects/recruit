<?php

/**
 * @file
 * Exposes recruit_application.module fields to views.
 */

/**
 * Export Recruit applications to Views.
 */

/**
 * Implements hook_views_data_alter()
 * EntityAPI implements hook_views_data for the recruit_application.
 */
function recruit_application_views_data_alter(&$data) {

  $data['recruit_application']['table']['base']['help'] = t('Applications.');

  // Expose the application title.
  $data['recruit_job']['first_name'] = array(
    'title' => t('First name'),
    'help' => t('The first name of the application used for administrative display.'),
    'field' => array(
      'handler' => 'recruit_application_handler_field_application',
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

  // Expose the application title.
  $data['recruit_job']['last_name'] = array(
    'title' => t('Last name'),
    'help' => t('The last name of the application used for administrative display.'),
    'field' => array(
      'handler' => 'recruit_application_handler_field_application',
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

  // Expose the application type.
  $data['recruit_application']['type'] = array(
    'title' => t('Type'),
    'help' => t('The human-readable name of the type of the application.'),
    'field' => array(
      'handler' => 'recruit_application_handler_field_application_type',
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
  $data['recruit_application']['uid'] = array(
    'title' => t('Author'),
    'help' => t('Relate content to the user who created it.'),
    'relationship' => array(
      'handler' => 'views_handler_relationship',
      'base' => 'users',
      'field' => 'uid',
      'label' => t('user'),
    ),
  );
  
  // Expose the created and changed timestamps.
  $data['recruit_application']['created'] = array(
    'title' => t('Created date'),
    'help' => t('The date the application was created.'),
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

  $data['recruit_application']['changed'] = array(
    'title' => t('Updated date'),
    'help' => t('The date the application was last updated.'),
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

  //Defining custom link fields.
  $data['recruit_application']['view_application'] = array(
    'field' => array(
      'title' => t('Link'),
      'help' => t('Provide a simple link to the administrator view of the application.'),
      'handler' => 'recruit_application_handler_field_application_link',
    ),
  );

  $data['recruit_application']['application_relation'] = array(
    'field' => array(
      'title' => t('Relation'),
      'help' => t('Provide a simple link to the job in relation.'),
      'handler' => 'recruit_application_handler_field_application_relation',
    ),
  );
  
  $data['recruit_application']['edit_application'] = array(
    'field' => array(
      'title' => t('Edit link'),
      'help' => t('Provide a simple link to edit the application.'),
      'handler' => 'recruit_application_handler_field_application_link_edit',
    ),
  );

  $data['recruit_application']['delete_application'] = array(
    'field' => array(
      'title' => t('Delete link'),
      'help' => t('Provide a simple link to delete the application.'),
      'handler' => 'recruit_application_handler_field_application_link_delete',
    ),
  );

  $data['recruit_application']['operations'] = array(
    'field' => array(
      'title' => t('Operations links'),
      'help' => t('Display all the available operations links for the application.'),
      'handler' => 'recruit_application_handler_field_application_operations',
    ),
  );

  $data['recruit_application']['full_name'] = array(
    'field' => array(
      'title' => t('Applicants full name'),
      'help' => t('Display applicants full name.'),
      'handler' => 'recruit_application_handler_field_application_full_name',
    ),
  );
}