<?php
// $Id$

/**
 * @file
 * Provides metadata for the application entity.
 */

/**
 * Implements hook_entity_property_info().
 */
function recruit_application_entity_property_info() {
  $info = array();

  $properties = &$info['recruit_application']['properties'];

  $properties['application-id'] = array(
    'label' => t('application ID'),
    'description' => t('The internal numeric ID of the application.'),
    'type' => 'integer',
  );
  $properties['application-ref'] = array(
    'label' => t('application Reference'),
    'description' => t('The human readable application reference.'),
    'type' => 'text',
    'setter callback' => 'entity_metadata_verbatim_set',
    'required' => TRUE,
    'query callback' => 'entity_metadata_table_query',
  );
  $properties['type'] = array(
    'label' => t('Type'),
    'description' => t('The human readable name of the application type.'),
    'type' => 'text',
    'options list' => 'recruit_application_type_get_name',
    'required' => TRUE,
    'query callback' => 'entity_metadata_table_query',
  );
  $properties['title'] = array(
    'label' => t('Title'),
    'description' => t('The title of the application.'),
    'type' => 'text',
    'setter callback' => 'entity_metadata_verbatim_set',
    'required' => TRUE,
    'query callback' => 'entity_metadata_table_query',
  );
  $properties['edit-url'] = array(
    'label' => t('Edit URL'),
    'description' => t("The URL of the application's edit page."),
    'getter callback' => 'recruit_application_get_properties',
    'type' => 'uri',
  );
  $properties['created'] = array(
    'label' => t('Date created'),
    'description' => t('The date the application was created.'),
    'type' => 'date',
    'setter callback' => 'entity_metadata_verbatim_set',
    'query callback' => 'entity_metadata_table_query',
    'setter permission' => 'administer applications',
  );
  $properties['uid'] = array(
    'label' => t("Creator ID"),
    'type' => 'integer',
    'description' => t("The unique ID of the application creator."),
    'setter callback' => 'entity_metadata_verbatim_set',
    'setter permission' => 'administer applications',
    'clear' => array('creator'),
    'query callback' => 'entity_metadata_table_query',
  );
  $properties['creator'] = array(
    'label' => t("Creator"),
    'type' => 'user',
    'description' => t("The creator of the application."),
    'getter callback' => 'recruit_application_get_properties',
    'setter callback' => 'recruit_application_set_properties',
    'setter permission' => 'administer applications',
    'required' => TRUE,
    'clear' => array('uid'),
  );

  return $info;
}
