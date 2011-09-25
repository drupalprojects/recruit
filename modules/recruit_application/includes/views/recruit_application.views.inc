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

  $data['recruit_application']['nid'] = array(
    'title' => t('Nid'),
    'help' => t('The node ID to which the application is attached to.'),
    'relationship' => array(
      'title' => t('Content'),
      'help' => t('The content to which the application is attached to.'),
      'base' => 'node',
      'base field' => 'nid',
      'handler' => 'views_handler_relationship',
      'label' => t('Content'),
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_numeric',
    ),
    'argument' => array(
      'handler' => 'views_handler_argument_numeric',
    ),
    'field' => array(
      'handler' => 'views_handler_field_numeric',
    ),
  );

  // uid field
  $data['recruit_application']['uid'] = array(
    'title' => t('Author'),
    'help' => t("The User ID of the applications's author."),
    'relationship' => array(
      'title' => t('Author'),
      'help' => t('Relate application to the user who created it.'),
      'base' => 'users',
      'base field' => 'uid',
      'handler' => 'views_handler_relationship',
      'label' => t('author'),
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_numeric',
    ),
    'argument' => array(
      'handler' => 'views_handler_argument_numeric',
    ),
    'field' => array(
      'handler' => 'views_handler_filter_user_name',
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
  /*
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
   * 
   */
}