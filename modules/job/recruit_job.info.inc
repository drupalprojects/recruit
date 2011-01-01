<?php
// $Id$

/**
 * @file
 * Provides entity metadata for the job entity.
 */

/**
 * Implements hook_entity_property_info().
 */
function recruit_job_entity_property_info() {
  $info = array();

  $properties = &$info['recruit_job']['properties'];

  $properties['job-id'] = array(
    'label' => t('Job ID'),
    'description' => t('The internal numeric ID of the job.'),
    'type' => 'integer',
  );
  $properties['job-ref'] = array(
    'label' => t('Job Reference'),
    'description' => t('The human readable job reference.'),
    'type' => 'text',
    'setter callback' => 'entity_metadata_verbatim_set',
    'required' => TRUE,
    'query callback' => 'entity_metadata_table_query',
  );
  $properties['type'] = array(
    'label' => t('Type'),
    'description' => t('The human readable name of the job type.'),
    'type' => 'text',
    'options list' => 'recruit_job_type_get_name',
    'required' => TRUE,
    'query callback' => 'entity_metadata_table_query',
  );
  $properties['title'] = array(
    'label' => t('Title'),
    'description' => t('The title of the job.'),
    'type' => 'text',
    'setter callback' => 'entity_metadata_verbatim_set',
    'required' => TRUE,
    'query callback' => 'entity_metadata_table_query',
  );
  $properties['edit-url'] = array(
    'label' => t('Edit URL'),
    'description' => t("The URL of the job's edit page."),
    'getter callback' => 'recruit_job_get_properties',
    'type' => 'uri',
  );
  $properties['created'] = array(
    'label' => t('Date created'),
    'description' => t('The date the job was created.'),
    'type' => 'date',
    'setter callback' => 'entity_metadata_verbatim_set',
    'query callback' => 'entity_metadata_table_query',
    'setter permission' => 'administer jobs',
  );
  $properties['uid'] = array(
    'label' => t("Creator ID"),
    'type' => 'integer',
    'description' => t("The unique ID of the job creator."),
    'setter callback' => 'entity_metadata_verbatim_set',
    'setter permission' => 'administer jobs',
    'clear' => array('creator'),
    'query callback' => 'entity_metadata_table_query',
  );
  $properties['creator'] = array(
    'label' => t("Creator"),
    'type' => 'user',
    'description' => t("The creator of the job."),
    'getter callback' => 'recruit_job_get_properties',
    'setter callback' => 'recruit_job_set_properties',
    'setter permission' => 'administer jobs',
    'required' => TRUE,
    'clear' => array('uid'),
  );

  return $info;
}
