<?php // $Id$ ?>

<div id="recruit-job-<?php print $job->job_id; ?>" class="<?php print $classes; ?> clearfix"<?php print $attributes; ?>>

  <?php if($job_ref): ?>
    <div class="field field-name-recruit-job-job-ref">
      <div class="field-label"><?php print t('Job Reference'); ?>: </div>
      <div class="field-item"><?php print $job_ref; ?></div>
    </div>
  <?php endif; ?>

  <?php if($changed): ?>
    <div class="field field-name-recruit-job-changed">
      <div class="field-label"><?php print t('Updated'); ?>: </div>
      <div class="field-item"><?php print $changed; ?></div>
    </div>
  <?php endif; ?>

  <div class="recruit-job-taxonomy">
    <?php if($job_location): ?>
      <?php print $job_location; ?>
    <?php endif; ?>

    <?php if($job_category): ?>
      <?php print $job_category; ?>
    <?php endif; ?>

    <?php if($job_type): ?>
      <?php print $job_type; ?>
    <?php endif; ?>
  </div>
  <div class="clearfix"></div>

  <?php if($job_description): ?>
    <div class="recruit-job-description">
      <?php print $job_description; ?>
    </div>
  <?php endif; ?>

</div>
