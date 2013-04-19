<?php

/**
 * application view callback.
 */
function recruit_application_view($application) {
  drupal_set_title(entity_label('recruit_application', $application));
  return entity_view('recruit_application', array(entity_id('recruit_application', $application) => $application), 'full');
}
