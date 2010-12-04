<?php
// $Id$

/**
 * @file
 * Default views table used for admin/recruit/jobs page.
 */

/**
 * Views for the default job UI.
 */

/**
 * Implement hook_views_default_views().
 */
function recruit_job_ui_views_default_views() {
 /*
   * View 'Jobs'
   */
  $view = new view;
  $view->name = 'Jobs';
  $view->description = '';
  $view->tag = '';
  $view->view_php = '';
  $view->base_table = 'recruit_job';
  $view->is_cacheable = FALSE;
  $view->api_version = '3.0-alpha1';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

/* Display: Defaults */
  $handler = $view->new_display('default', 'Defaults', 'default');
  $handler->display->display_options['title'] = 'Jobs';
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['access']['perm'] = 'administer jobs';
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
  /* Field: Recruit Job: Job Reference */
  $handler->display->display_options['fields']['job_ref']['id'] = 'job_ref';
  $handler->display->display_options['fields']['job_ref']['table'] = 'recruit_job';
  $handler->display->display_options['fields']['job_ref']['field'] = 'job_ref';
  $handler->display->display_options['fields']['job_ref']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['job_ref']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['job_ref']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['job_ref']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['job_ref']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['job_ref']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['job_ref']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['job_ref']['alter']['html'] = 0;
  $handler->display->display_options['fields']['job_ref']['hide_empty'] = 0;
  $handler->display->display_options['fields']['job_ref']['empty_zero'] = 0;
  $handler->display->display_options['fields']['job_ref']['link_to_job'] = 0;
  /* Field: Recruit Job: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'recruit_job';
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
  $handler->display->display_options['fields']['title']['link_to_job'] = 1;
  /* Field: Recruit Job: Type */
  $handler->display->display_options['fields']['type']['id'] = 'type';
  $handler->display->display_options['fields']['type']['table'] = 'recruit_job';
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
  $handler->display->display_options['fields']['type']['link_to_job'] = 0;
  /* Field: Recruit Job: Status */
  $handler->display->display_options['fields']['status']['id'] = 'status';
  $handler->display->display_options['fields']['status']['table'] = 'recruit_job';
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
  /* Field: Recruit Job: Created date */
  $handler->display->display_options['fields']['created']['id'] = 'created';
  $handler->display->display_options['fields']['created']['table'] = 'recruit_job';
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
  /* Field: Recruit Job: Updated date */
  $handler->display->display_options['fields']['changed']['id'] = 'changed';
  $handler->display->display_options['fields']['changed']['table'] = 'recruit_job';
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
  /* Field: Recruit Job: Edit link */
  $handler->display->display_options['fields']['edit_job']['id'] = 'edit_job';
  $handler->display->display_options['fields']['edit_job']['table'] = 'recruit_job';
  $handler->display->display_options['fields']['edit_job']['field'] = 'edit_job';
  $handler->display->display_options['fields']['edit_job']['label'] = 'Operations';
  $handler->display->display_options['fields']['edit_job']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['edit_job']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['edit_job']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['edit_job']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['edit_job']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['edit_job']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['edit_job']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['edit_job']['alter']['html'] = 0;
  $handler->display->display_options['fields']['edit_job']['hide_empty'] = 0;
  $handler->display->display_options['fields']['edit_job']['empty_zero'] = 0;
  /* Field: Recruit Job: Delete link */
  $handler->display->display_options['fields']['delete_job']['id'] = 'delete_job';
  $handler->display->display_options['fields']['delete_job']['table'] = 'recruit_job';
  $handler->display->display_options['fields']['delete_job']['field'] = 'delete_job';
  $handler->display->display_options['fields']['delete_job']['label'] = '';
  $handler->display->display_options['fields']['delete_job']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['delete_job']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['delete_job']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['delete_job']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['delete_job']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['delete_job']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['delete_job']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['delete_job']['alter']['html'] = 0;
  $handler->display->display_options['fields']['delete_job']['hide_empty'] = 0;
  $handler->display->display_options['fields']['delete_job']['empty_zero'] = 0;

/* Display: Admin page */
  $handler = $view->new_display('page', 'Admin page', 'admin_page');
  $handler->display->display_options['path'] = 'admin/recruit/jobs/list';
  $handler->display->display_options['menu']['type'] = 'default tab';
  $handler->display->display_options['menu']['title'] = 'List';
  $handler->display->display_options['menu']['weight'] = '-10';
  $handler->display->display_options['tab_options']['type'] = 'normal';
  $handler->display->display_options['tab_options']['title'] = 'Jobs';
  $handler->display->display_options['tab_options']['description'] = 'Manage jobs and job types on your site.';
  $handler->display->display_options['tab_options']['weight'] = '0';
  $handler->display->display_options['tab_options']['name'] = 'management';

/* Display: Front Page */
  $handler = $view->new_display('page', 'Front Page', 'front_page');
  $handler->display->display_options['defaults']['access'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['access']['perm'] = 'access jobs';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Recruit Job: Job Reference */
  $handler->display->display_options['fields']['job_ref']['id'] = 'job_ref';
  $handler->display->display_options['fields']['job_ref']['table'] = 'recruit_job';
  $handler->display->display_options['fields']['job_ref']['field'] = 'job_ref';
  $handler->display->display_options['fields']['job_ref']['label'] = 'Job Ref';
  $handler->display->display_options['fields']['job_ref']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['job_ref']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['job_ref']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['job_ref']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['job_ref']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['job_ref']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['job_ref']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['job_ref']['alter']['html'] = 0;
  $handler->display->display_options['fields']['job_ref']['hide_empty'] = 0;
  $handler->display->display_options['fields']['job_ref']['empty_zero'] = 0;
  $handler->display->display_options['fields']['job_ref']['link_to_job'] = 0;
  $handler->display->display_options['fields']['job_ref']['link_to_front_job'] = 0;
  /* Field: Recruit Job: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'recruit_job';
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
  $handler->display->display_options['fields']['title']['link_to_job'] = 0;
  $handler->display->display_options['fields']['title']['link_to_front_job'] = 1;
  /* Field: Fields: recruit_job_description */
  $handler->display->display_options['fields']['entity_id_1']['id'] = 'entity_id_1';
  $handler->display->display_options['fields']['entity_id_1']['table'] = 'field_data_field_recruit_job_description';
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
  /* Field: Fields: recruit_job_location */
  $handler->display->display_options['fields']['entity_id']['id'] = 'entity_id';
  $handler->display->display_options['fields']['entity_id']['table'] = 'field_data_field_recruit_job_location';
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
  /* Filter: Recruit Job: Title */
  $handler->display->display_options['filters']['title']['id'] = 'title';
  $handler->display->display_options['filters']['title']['table'] = 'recruit_job';
  $handler->display->display_options['filters']['title']['field'] = 'title';
  $handler->display->display_options['filters']['title']['operator'] = 'contains';
  $handler->display->display_options['filters']['title']['exposed'] = TRUE;
  $handler->display->display_options['filters']['title']['expose']['operator'] = 'title_op';
  $handler->display->display_options['filters']['title']['expose']['label'] = 'Title';
  $handler->display->display_options['filters']['title']['expose']['identifier'] = 'title';
  $handler->display->display_options['filters']['title']['case'] = 1;
  $handler->display->display_options['path'] = 'recruit-job';
  $views[$view->name] = $view;

  return $views;
}


