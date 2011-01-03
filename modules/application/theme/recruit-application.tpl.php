<?php // $Id$ ?>

<div id="recruit-job-<?php print $job->job_id; ?>" class="<?php print $classes; ?> clearfix"<?php print $attributes; ?>>

  <?php print $content; ?>

  <?php if($changed): ?>
    <div class="field field-name-recruit-job-changed">
      <div class="field-label"><?php print t('Updated'); ?>: </div>
      <div class="field-item"><?php print $changed; ?></div>
    </div>
  <?php endif; ?>

</div>
