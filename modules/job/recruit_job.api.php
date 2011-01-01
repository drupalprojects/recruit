<?php
// $Id$

/**
 * @file
 * Hooks provided by the Job module.
 */

function hook_recruit_job_presave($job) {

}

function hook_recruit_job_insert($job) {

}

function hook_recruit_job_update($job) {

}

function hook_recruit_job_delete($job) {

}

function hook_recruit_job_info() {
  return array(
    'graduate_job' => (object) array(
      'type' => 'graduate_job',
      'name' => 'Graduate job',
      'description' => 'Jobs for graduate positions.',
      'help' => '',
    ),
    'management_job' => (object) array(
      'type' => 'management_job',
      'name' => 'Management job',
      'description' => 'Jobs for management positions.',
      'help' => '',
    ),
  );
}

function hook_recruit_job_type_insert($job_type) {

}

function hook_recruit_job_type_insert($job_type) {

}

function hook_recruit_job_type_update($job_type) {

}

function hook_recruit_job_type_delete($job_type) {

}