<?php
// $Id$

/**
 * @file
 * The controller for the application entity containing the CRUD operations.
 */

/**
 * The controller class for applications contains methods for the application CRUD
 * operations. The load method is inherited from the default controller.
 */
class RecruitApplicationEntityController extends DrupalDefaultEntityController {
  /**
   * Create a default application.
   *
   * @param $type
   *   The machine-readable type of the application.
   *
   * @return
   *   A application object with all default fields initialized.
   */
  public function create($type = '') {
    return (object) array(
      'application_id' => '',
      'application_ref' => '',
      'type' => $type,
      'first_name' => '',
      'last_name' => '',
      'uid' => '',
      'status' => 1,
      'created' => '',
      'changed' => '',
    );
  }

  /**
   * Saves a application.
   *
   * @param $application
   *   The full application object to save.
   *
   * @return
   *   The saved application object on success, FALSE on failure.
   */
  public function save($application) {
    $transaction = db_transaction();

    try {
      $application->changed = REQUEST_TIME;

      // Save a copy of the unchanged application for rules in case of updates.
      // see recruit_application_rules_var_unchanged().
      $unchanged = &drupal_static('recruit_application_unchanged', array());
      if (!empty($application->application_id)) {
        $unchanged[$application->application_id] = clone recruit_application_load($application->application_id);
      }

      // Give modules the opportunity to prepare field data for saving.
      field_attach_presave('recruit_application', $application);
      module_invoke_all('recruit_application_presave', $application);
      rules_invoke_event('recruit_application_presave', $application);

      // If this is a new application...
      if (empty($application->application_id)) {
        // Set the creation timestamp.
        $application->created = REQUEST_TIME;

        // Save the new application and fields.
        drupal_write_record('recruit_application', $application);
        field_attach_insert('recruit_application', $application);

        $op = 'insert';
      }
      else {
        // Save the updated application and fields.
        drupal_write_record('recruit_application', $application, 'application_id');
        field_attach_update('recruit_application', $application);

        $op = 'update';
      }

      module_invoke_all('recruit_application_' . $op, $application);
      module_invoke_all('entity_' . $op, $application, 'recruit_application');
      rules_invoke_event('recruit_application_' . $op, $application);

      // Ignore slave server temporarily to give time for the
      // saved application to be propagated to the slave.
      db_ignore_slave();

      return $application;
    }
    catch (Exception $e) {
      $transaction->rollback('recruit application', $e->getMessage(), array(), WATCHDOG_ERROR);
      return FALSE;
    }
  }

  /**
   * Deletes multiple applications by ID.
   *
   * @param $application_ids
   *   An array of application IDs to delete.
   *
   * @return
   *   TRUE on success, FALSE otherwise.
   */
  public function delete($application_ids) {
    if (!empty($application_ids)) {
      $applications = $this->load($application_ids, array());

      $transaction = db_transaction();

      try {
        db_delete('recruit_application')
          ->condition('application_id', $application_ids, 'IN')
          ->execute();

        foreach ($applications as $application_id => $application) {
          module_invoke_all('recruit_application_delete', $application);
          field_attach_delete('recruit_application', $application);
          rules_invoke_event('recruit_application_delete', $application);
        }

        // Ignore slave server temporarily to give time for the
        // saved application to be propagated to the slave.
        db_ignore_slave();
      }
      catch (Exception $e) {
        $transaction->rollback('recruit application', $e->getMessage(), array(), WATCHDOG_ERROR);
        return FALSE;
      }

      // Clear the page and block and application_load_multiple caches.
      cache_clear_all();
      $this->resetCache();
    }

    return TRUE;
  }
  
}