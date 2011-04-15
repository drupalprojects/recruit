<div class="<?php print $classes; ?> clearfix"<?php print $attributes; ?>>
  
  <?php if(!empty($job_ref)): ?>
    <div class="field field-name-recruit-job-job-ref">
      <div class="field-label"><?php print t('Job Reference'); ?>: </div>
      <div class="field-item"><?php print $job_ref; ?></div>
    </div>
  <?php endif; ?>

  <?php if(!empty($changed)): ?>
    <div class="field field-name-recruit-job-changed">
      <div class="field-label"><?php print t('Updated'); ?>: </div>
      <div class="field-item"><?php print $changed; ?></div>
    </div>
  <?php endif; ?>
  
  <?php print render($content); ?>

</div>