<?php
// $Id$

/**
 * @file
 * The controller for the job entity containing the CRUD operations.
 */

/**
 * The controller class for jobs contains methods for the job CRUD
 * operations. The load method is inherited from the default controller.
 */
class RecruitJobEntityController extends DrupalDefaultEntityController {
  /**
   * Create a default job.
   *
   * @param $type
   *   The machine-readable type of the job.
   *
   * @return
   *   A job object with all default fields initialized.
   */
  public function create($type = '') {
    return (object) array(
      'job_id' => '',
      'job_ref' => '',
      'type' => $type,
      'title' => '',
      'uid' => '',
      'status' => 1,
      'created' => '',
      'changed' => '',
      'expiry' => '',
    );
  }

  /**
   * Saves a job.
   *
   * @param $job
   *   The full job object to save.
   *
   * @return
   *   The saved job object on success, FALSE on failure.
   */
  public function save($job) {
    $transaction = db_transaction();

    try {
      $job->changed = REQUEST_TIME;

      // Save a copy of the unchanged job for rules in case of updates.
      // see recruit_job_rules_var_unchanged().
      $unchanged = &drupal_static('recruit_job_unchanged', array());
      if (!empty($job->job_id)) {
        $unchanged[$job->job_id] = clone recruit_job_load($job->job_id);
      }

      // Give modules the opportunity to prepare field data for saving.
      field_attach_presave('recruit_job', $job);
      module_invoke_all('recruit_job_presave', $job);
      rules_invoke_event('recruit_job_presave', $job);

      // If this is a new job...
      if (empty($job->job_id)) {
        // Set the creation timestamp.
        $job->created = REQUEST_TIME;

        // Save the new job and fields.
        drupal_write_record('recruit_job', $job);
        field_attach_insert('recruit_job', $job);

        $op = 'insert';
      }
      else {
        // Save the updated job and fields.
        drupal_write_record('recruit_job', $job, 'job_id');
        field_attach_update('recruit_job', $job);

        $op = 'update';
      }

      module_invoke_all('recruit_job_' . $op, $job);
      module_invoke_all('entity_' . $op, $job, 'recruit_job');
      rules_invoke_event('recruit_job_' . $op, $job);

      // Ignore slave server temporarily to give time for the
      // saved job to be propagated to the slave.
      db_ignore_slave();

      return $job;
    }
    catch (Exception $e) {
      $transaction->rollback('recruit job', $e->getMessage(), array(), WATCHDOG_ERROR);
      return FALSE;
    }
  }

  /**
   * Deletes multiple jobs by ID.
   *
   * @param $job_ids
   *   An array of job IDs to delete.
   *
   * @return
   *   TRUE on success, FALSE otherwise.
   */
  public function delete($job_ids) {
    if (!empty($job_ids)) {
      $jobs = $this->load($job_ids, array());

      $transaction = db_transaction();

      try {
        db_delete('recruit_job')
          ->condition('job_id', $job_ids, 'IN')
          ->execute();

        foreach ($jobs as $job_id => $job) {
          module_invoke_all('recruit_job_delete', $job);
          field_attach_delete('recruit_job', $job);
          rules_invoke_event('recruit_job_delete', $job);
        }

        // Ignore slave server temporarily to give time for the
        // saved job to be propagated to the slave.
        db_ignore_slave();
      }
      catch (Exception $e) {
        $transaction->rollback('recruit job', $e->getMessage(), array(), WATCHDOG_ERROR);
        return FALSE;
      }

      // Clear the page and block and job_load_multiple caches.
      cache_clear_all();
      $this->resetCache();
    }

    return TRUE;
  }
  
}