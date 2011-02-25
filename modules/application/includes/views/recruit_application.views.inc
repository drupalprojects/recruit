<?php

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

  $data['recruit_application']['first_name'] = array(
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

  $data['recruit_application']['last_name'] = array(
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
