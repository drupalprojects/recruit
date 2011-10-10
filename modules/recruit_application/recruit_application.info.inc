<?php

/**
 * @file
 * Provides Entity metadata integration.
 */

/**
 * Extend the defaults.
 */
class RecruitApplicationMetadataController extends EntityDefaultMetadataController {

  public function entityPropertyInfo() {
    $info = parent::entityPropertyInfo();
    $properties = &$info[$this->type]['properties'];
    
    $properties['aid'] = array(
      'label' => t("Application ID"),
      'type' => 'integer',
      'description' => t("The unique ID of the application."),
      'schema field' => 'aid',
    );
    
    unset($properties['uid']);

    $properties['user'] = array(
      'label' => t("User"),
      'type' => 'user',
      'description' => t("The owner of the application."),
      'getter callback' => 'entity_property_getter_method',
      'setter callback' => 'entity_property_setter_method',
      'setter permission' => 'administer applications',
      'required' => TRUE,
      'schema field' => 'uid',
    );
    
    unset($properties['nid']);
    
    $properties['node'] = array(
      'label' => t("Node"),
      'description' => t("The node the application is attached to."),
      'type' => 'node',
      'getter callback' => 'entity_property_getter_method',
      'setter callback' => 'entity_property_setter_method',
      'setter permission' => 'administer applications',
      'required' => TRUE,
      'schema field' => 'nid',
    );

    $properties['created'] = array(
      'label' => t("Date created"),
      'type' => 'date',
      'description' => t("The date the application was submitted."),
      'setter callback' => 'entity_property_verbatim_set',
      'setter permission' => 'administer applications',
      'schema field' => 'created',
    );
    
    $properties['changed'] = array(
      'label' => t("Date changed"),
      'type' => 'date',
      'schema field' => 'changed',
      'description' => t("The date the application was most recently updated."),
    );

    $properties['status'] = array(
      'label' => t("Published"),
      'description' => t("Whether the application is published."),
      'setter callback' => 'entity_property_verbatim_set',
      'setter permission' => 'administer applications',
      'schema field' => 'status',
      'type' => 'boolean',
    );

    $properties['language'] = array(
      'label' => t("Language"),
      'description' => t("The language the application is written in."),
      'setter callback' => 'entity_property_verbatim_set',
      'options list' => 'entity_metadata_language_list',
      'schema field' => 'language',
      'setter permission' => 'administer applications',
    );

    return $info;
  }
}
