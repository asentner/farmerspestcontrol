<?php

?>
<article<?php print $attributes; ?>>

  <?php print render($content['field_image']); ?>

  <div class="teaser-content">
    <?php if (isset($content['field_seo_title'])): ?>
      <?php print render($content['field_seo_title']); ?>
    <?php else: ?>
      <h1><?php print $title; ?></h1>
    <?php endif; ?>

    <?php print render($content['field_local_content']); ?>
  </div>

    <?php
      // We hide the comments and links now so that we can render them later.
      hide($content['comments']);
      hide($content['links']);
    ?>
</article>
