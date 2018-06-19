<?php

?>
<article<?php print $attributes; ?>>
  <div class="node-title">
    <h2<?php print $title_attributes; ?>><?php print $title; ?></h2>
  </div>
  <header>
    <?php if($intro_title): ?>
      <?php print render($content['field_display_title']); ?>
      <?php print render($content ['field_image']); ?>
      <?php print render($content['field_intro']); ?>
    <?php endif; ?>
  </header>

  <div<?php print $content_attributes; ?>>
    <?php
      // We hide the comments and links now so that we can render them later.
      hide($content['comments']);
      hide($content['links']);
      print render($content);
    ?>
  </div>

  <?php print render($content['links']); ?>
  <?php print render($content['comments']); ?>
</article>
