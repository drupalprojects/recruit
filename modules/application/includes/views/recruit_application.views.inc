<?php
// $Id$

/**
 * @file
 * Exposes recruit_application.module fields to views.
 */

/**
 * Export Recruit applications to Views.
 */

/**
 * Implements hook_views_data()
 */
function recruit_application_views_data() {
  $data = array();

  $data['recruit_application']['table']['group']  = t('Recruit application');

  $data['recruit_application']['table']['base'] = array(
    'field' => 'application_id',
    'title' => t('Recruit application'),
    'help' => t('application posting.'),
  );

  // Expose the application ID.
  $data['recruit_application']['application_id'] = array(
    'title' => t('application ID'),
    'help' => t('The unique internal identifier of the application.'),
    'field' => array(
      'handler' => 'recruit_application_handler_field_application',
      'click sortable' => TRUE,
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_numeric',
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
    'argument' => array(
      'handler' => 'views_handler_argument_numeric',
    ),
  );

  // Expose the application reference.
  $data['recruit_application']['application_ref'] = array(
    'title' => t('application Reference'),
    'help' => t('The unique human-readable identifier of the application.'),
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

  // Expose the application title.
  $data['recruit_application']['title'] = array(
    'title' => t('Title'),
    'help' => t('The title of the application used for administrative display.'),
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

  // Expose the creator uid.
  $data['recruit_application']['uid'] = array(
    'title' => t('Creator'),
    'help' => t('Relate a application to the user who created it.'),
    'relationship' => array(
      'handler' => 'views_handler_relationship',
      'base' => 'users',
      'field' => 'uid',
      'label' => t('application creator'),
    ),
  );

  // Expose the application status.
  $data['recruit_application']['status'] = array(
    'title' => t('Status'),
    'help' => t('Whether or not the application is active.'),
    'field' => array(
      'handler' => 'views_handler_field_boolean',
      'click sortable' => TRUE,
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_boolean_operator',
      'label' => t('Active'),
      'type' => 'yes-no',
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
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

  // Expose links to operate on the application.
  $data['recruit_application']['view_application'] = array(
    'field' => array(
      'title' => t('Link'),
      'help' => t('Provide a simple link to the administrator view of the application.'),
      'handler' => 'recruit_application_handler_field_application_link',
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

  return $data;
}
