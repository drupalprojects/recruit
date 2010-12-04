<?php
// $Id$

/**
 * @file
 * Default views table used for admin/recruit/applications page.
 */

/**
 * Views for the default application UI.
 */

/**
 * Implement hook_views_default_views().
 */
function recruit_application_ui_views_default_views() {
 /*
   * View 'applications'
   */
  $view = new view;
  $view->name = 'applications';
  $view->description = '';
  $view->tag = '';
  $view->view_php = '';
  $view->base_table = 'recruit_application';
  $view->is_cacheable = FALSE;
  $view->api_version = '3.0-alpha1';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

/* Display: Defaults */
  $handler = $view->new_display('default', 'Defaults', 'default');
  $handler->display->display_options['title'] = 'applications';
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['access']['perm'] = 'administer applications';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'title' => 'title',
    'entity_id_1' => 'title',
    'entity_id' => 'entity_id',
  );
  $handler->display->display_options['style_options']['default'] = '-1';
  $handler->display->display_options['style_options']['info'] = array(
    'title' => array(
      'sortable' => 1,
      'align' => '',
      'separator' => '',
    ),
    'entity_id_1' => array(
      'sortable' => 0,
      'align' => '',
      'separator' => '',
    ),
    'entity_id' => array(
      'sortable' => 1,
      'align' => '',
      'separator' => '',
    ),
  );
  $handler->display->display_options['style_options']['override'] = 1;
  $handler->display->display_options['style_options']['sticky'] = 0;
  /* Field: Recruit application: application Reference */
  $handler->display->display_options['fields']['application_ref']['id'] = 'application_ref';
  $handler->display->display_options['fields']['application_ref']['table'] = 'recruit_application';
  $handler->display->display_options['fields']['application_ref']['field'] = 'application_ref';
  $handler->display->display_options['fields']['application_ref']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['application_ref']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['application_ref']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['application_ref']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['application_ref']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['application_ref']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['application_ref']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['application_ref']['alter']['html'] = 0;
  $handler->display->display_options['fields']['application_ref']['hide_empty'] = 0;
  $handler->display->display_options['fields']['application_ref']['empty_zero'] = 0;
  $handler->display->display_options['fields']['application_ref']['link_to_application'] = 0;
  /* Field: Recruit application: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'recruit_application';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['title']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['title']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['title']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['title']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['title']['alter']['html'] = 0;
  $handler->display->display_options['fields']['title']['hide_empty'] = 0;
  $handler->display->display_options['fields']['title']['empty_zero'] = 0;
  $handler->display->display_options['fields']['title']['link_to_application'] = 1;
  /* Field: Recruit application: Type */
  $handler->display->display_options['fields']['type']['id'] = 'type';
  $handler->display->display_options['fields']['type']['table'] = 'recruit_application';
  $handler->display->display_options['fields']['type']['field'] = 'type';
  $handler->display->display_options['fields']['type']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['type']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['type']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['type']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['type']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['type']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['type']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['type']['alter']['html'] = 0;
  $handler->display->display_options['fields']['type']['hide_empty'] = 0;
  $handler->display->display_options['fields']['type']['empty_zero'] = 0;
  $handler->display->display_options['fields']['type']['link_to_application'] = 0;
  /* Field: Recruit application: Status */
  $handler->display->display_options['fields']['status']['id'] = 'status';
  $handler->display->display_options['fields']['status']['table'] = 'recruit_application';
  $handler->display->display_options['fields']['status']['field'] = 'status';
  $handler->display->display_options['fields']['status']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['status']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['status']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['status']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['status']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['status']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['status']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['status']['alter']['html'] = 0;
  $handler->display->display_options['fields']['status']['hide_empty'] = 0;
  $handler->display->display_options['fields']['status']['empty_zero'] = 0;
  $handler->display->display_options['fields']['status']['not'] = 0;
  /* Field: Recruit application: Created date */
  $handler->display->display_options['fields']['created']['id'] = 'created';
  $handler->display->display_options['fields']['created']['table'] = 'recruit_application';
  $handler->display->display_options['fields']['created']['field'] = 'created';
  $handler->display->display_options['fields']['created']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['created']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['created']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['created']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['created']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['created']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['created']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['created']['alter']['html'] = 0;
  $handler->display->display_options['fields']['created']['hide_empty'] = 0;
  $handler->display->display_options['fields']['created']['empty_zero'] = 0;
  /* Field: Recruit application: Updated date */
  $handler->display->display_options['fields']['changed']['id'] = 'changed';
  $handler->display->display_options['fields']['changed']['table'] = 'recruit_application';
  $handler->display->display_options['fields']['changed']['field'] = 'changed';
  $handler->display->display_options['fields']['changed']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['changed']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['changed']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['changed']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['changed']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['changed']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['changed']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['changed']['alter']['html'] = 0;
  $handler->display->display_options['fields']['changed']['hide_empty'] = 0;
  $handler->display->display_options['fields']['changed']['empty_zero'] = 0;
  /* Field: Recruit application: Edit link */
  $handler->display->display_options['fields']['edit_application']['id'] = 'edit_application';
  $handler->display->display_options['fields']['edit_application']['table'] = 'recruit_application';
  $handler->display->display_options['fields']['edit_application']['field'] = 'edit_application';
  $handler->display->display_options['fields']['edit_application']['label'] = 'Operations';
  $handler->display->display_options['fields']['edit_application']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['edit_application']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['edit_application']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['edit_application']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['edit_application']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['edit_application']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['edit_application']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['edit_application']['alter']['html'] = 0;
  $handler->display->display_options['fields']['edit_application']['hide_empty'] = 0;
  $handler->display->display_options['fields']['edit_application']['empty_zero'] = 0;
  /* Field: Recruit application: Delete link */
  $handler->display->display_options['fields']['delete_application']['id'] = 'delete_application';
  $handler->display->display_options['fields']['delete_application']['table'] = 'recruit_application';
  $handler->display->display_options['fields']['delete_application']['field'] = 'delete_application';
  $handler->display->display_options['fields']['delete_application']['label'] = '';
  $handler->display->display_options['fields']['delete_application']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['delete_application']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['delete_application']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['delete_application']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['delete_application']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['delete_application']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['delete_application']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['delete_application']['alter']['html'] = 0;
  $handler->display->display_options['fields']['delete_application']['hide_empty'] = 0;
  $handler->display->display_options['fields']['delete_application']['empty_zero'] = 0;

/* Display: Admin page */
  $handler = $view->new_display('page', 'Admin page', 'admin_page');
  $handler->display->display_options['path'] = 'admin/recruit/applications/list';
  $handler->display->display_options['menu']['type'] = 'default tab';
  $handler->display->display_options['menu']['title'] = 'List';
  $handler->display->display_options['menu']['weight'] = '-10';
  $handler->display->display_options['tab_options']['type'] = 'normal';
  $handler->display->display_options['tab_options']['title'] = 'Applications';
  $handler->display->display_options['tab_options']['description'] = 'Manage applications and application types on your site.';
  $handler->display->display_options['tab_options']['weight'] = '0';
  $handler->display->display_options['tab_options']['name'] = 'management';

/* Display: Front Page */
  $handler = $view->new_display('page', 'Front Page', 'front_page');
  $handler->display->display_options['defaults']['access'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['access']['perm'] = 'access applications';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Recruit application: application Reference */
  $handler->display->display_options['fields']['application_ref']['id'] = 'application_ref';
  $handler->display->display_options['fields']['application_ref']['table'] = 'recruit_application';
  $handler->display->display_options['fields']['application_ref']['field'] = 'application_ref';
  $handler->display->display_options['fields']['application_ref']['label'] = 'application Ref';
  $handler->display->display_options['fields']['application_ref']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['application_ref']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['application_ref']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['application_ref']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['application_ref']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['application_ref']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['application_ref']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['application_ref']['alter']['html'] = 0;
  $handler->display->display_options['fields']['application_ref']['hide_empty'] = 0;
  $handler->display->display_options['fields']['application_ref']['empty_zero'] = 0;
  $handler->display->display_options['fields']['application_ref']['link_to_application'] = 0;
  $handler->display->display_options['fields']['application_ref']['link_to_front_application'] = 0;
  /* Field: Recruit application: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'recruit_application';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['title']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['title']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['title']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['title']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['title']['alter']['html'] = 0;
  $handler->display->display_options['fields']['title']['hide_empty'] = 0;
  $handler->display->display_options['fields']['title']['empty_zero'] = 0;
  $handler->display->display_options['fields']['title']['link_to_application'] = 0;
  $handler->display->display_options['fields']['title']['link_to_front_application'] = 1;
  /* Field: Fields: recruit_application_description */
  $handler->display->display_options['fields']['entity_id_1']['id'] = 'entity_id_1';
  $handler->display->display_options['fields']['entity_id_1']['table'] = 'field_data_recruit_application_description';
  $handler->display->display_options['fields']['entity_id_1']['field'] = 'entity_id';
  $handler->display->display_options['fields']['entity_id_1']['label'] = '';
  $handler->display->display_options['fields']['entity_id_1']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['entity_id_1']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['entity_id_1']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['entity_id_1']['alter']['trim'] = 1;
  $handler->display->display_options['fields']['entity_id_1']['alter']['max_length'] = '250';
  $handler->display->display_options['fields']['entity_id_1']['alter']['word_boundary'] = 0;
  $handler->display->display_options['fields']['entity_id_1']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['entity_id_1']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['entity_id_1']['alter']['html'] = 0;
  $handler->display->display_options['fields']['entity_id_1']['hide_empty'] = 0;
  $handler->display->display_options['fields']['entity_id_1']['empty_zero'] = 0;
  /* Field: Fields: recruit_application_location */
  $handler->display->display_options['fields']['entity_id']['id'] = 'entity_id';
  $handler->display->display_options['fields']['entity_id']['table'] = 'field_data_recruit_application_location';
  $handler->display->display_options['fields']['entity_id']['field'] = 'entity_id';
  $handler->display->display_options['fields']['entity_id']['label'] = 'Location';
  $handler->display->display_options['fields']['entity_id']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['entity_id']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['entity_id']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['entity_id']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['entity_id']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['entity_id']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['entity_id']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['entity_id']['alter']['html'] = 0;
  $handler->display->display_options['fields']['entity_id']['hide_empty'] = 0;
  $handler->display->display_options['fields']['entity_id']['empty_zero'] = 0;
  $handler->display->display_options['fields']['entity_id']['type'] = 'taxonomy_term_reference_plain';
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter: Recruit application: Title */
  $handler->display->display_options['filters']['title']['id'] = 'title';
  $handler->display->display_options['filters']['title']['table'] = 'recruit_application';
  $handler->display->display_options['filters']['title']['field'] = 'title';
  $handler->display->display_options['filters']['title']['operator'] = 'contains';
  $handler->display->display_options['filters']['title']['exposed'] = TRUE;
  $handler->display->display_options['filters']['title']['expose']['operator'] = 'title_op';
  $handler->display->display_options['filters']['title']['expose']['label'] = 'Title';
  $handler->display->display_options['filters']['title']['expose']['identifier'] = 'title';
  $handler->display->display_options['filters']['title']['case'] = 1;
  $handler->display->display_options['path'] = 'recruit-application';
  $views[$view->name] = $view;

  return $views;
}


