<?php

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
  $handler->display->display_options['title'] = 'Applications';
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
  /* Empty text: Global: Text area */
  $handler->display->display_options['empty']['area']['id'] = 'area';
  $handler->display->display_options['empty']['area']['table'] = 'views';
  $handler->display->display_options['empty']['area']['field'] = 'area';
  $handler->display->display_options['empty']['area']['empty'] = FALSE;
  $handler->display->display_options['empty']['area']['content'] = 'No applications have been created yet.';
  $handler->display->display_options['empty']['area']['format'] = 'filtered_html';
  /* Field: Recruit application: application ID */
  $handler->display->display_options['fields']['application_id']['id'] = 'application_id';
  $handler->display->display_options['fields']['application_id']['table'] = 'recruit_application';
  $handler->display->display_options['fields']['application_id']['field'] = 'application_id';
  $handler->display->display_options['fields']['application_id']['label'] = 'ID';
  $handler->display->display_options['fields']['application_id']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['application_id']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['application_id']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['application_id']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['application_id']['alter']['word_boundary'] = 0;
  $handler->display->display_options['fields']['application_id']['alter']['ellipsis'] = 0;
  $handler->display->display_options['fields']['application_id']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['application_id']['alter']['html'] = 0;
  $handler->display->display_options['fields']['application_id']['hide_empty'] = 0;
  $handler->display->display_options['fields']['application_id']['empty_zero'] = 0;
  $handler->display->display_options['fields']['application_id']['link_to_application'] = 1;
  $handler->display->display_options['fields']['application_id']['link_to_front_application'] = 0;
  /* Field: Recruit application: First name */
  $handler->display->display_options['fields']['first_name']['id'] = 'first_name';
  $handler->display->display_options['fields']['first_name']['table'] = 'recruit_application';
  $handler->display->display_options['fields']['first_name']['field'] = 'first_name';
  $handler->display->display_options['fields']['first_name']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['first_name']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['first_name']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['first_name']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['first_name']['alter']['word_boundary'] = 0;
  $handler->display->display_options['fields']['first_name']['alter']['ellipsis'] = 0;
  $handler->display->display_options['fields']['first_name']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['first_name']['alter']['html'] = 0;
  $handler->display->display_options['fields']['first_name']['hide_empty'] = 0;
  $handler->display->display_options['fields']['first_name']['empty_zero'] = 0;
  $handler->display->display_options['fields']['first_name']['link_to_application'] = 0;
  $handler->display->display_options['fields']['first_name']['link_to_front_application'] = 0;
  /* Field: Recruit application: Last name */
  $handler->display->display_options['fields']['last_name']['id'] = 'last_name';
  $handler->display->display_options['fields']['last_name']['table'] = 'recruit_application';
  $handler->display->display_options['fields']['last_name']['field'] = 'last_name';
  $handler->display->display_options['fields']['last_name']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['last_name']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['last_name']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['last_name']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['last_name']['alter']['word_boundary'] = 0;
  $handler->display->display_options['fields']['last_name']['alter']['ellipsis'] = 0;
  $handler->display->display_options['fields']['last_name']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['last_name']['alter']['html'] = 0;
  $handler->display->display_options['fields']['last_name']['hide_empty'] = 0;
  $handler->display->display_options['fields']['last_name']['empty_zero'] = 0;
  $handler->display->display_options['fields']['last_name']['link_to_application'] = 0;
  $handler->display->display_options['fields']['last_name']['link_to_front_application'] = 0;
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
  $views[$view->name] = $view;

  return $views;
}


