<article<?php print $attributes; ?>>

  <?php print render($content['field_image']); ?>

  <header>
    <?php print render($title_prefix); ?>
    <?php if (!$page): ?>
      <h3<?php print $title_attributes; ?>><?php print $title; ?></h3>
    <?php endif; ?>
    <?php print render($title_suffix); ?>
  </header>

  <div<?php print $content_attributes; ?>>
    <?php
      // We hide the comments and links now so that we can render them later.
      hide($content['comments']);
      hide($content['links']);
      print render($content);
    ?>
  </div>

</article>
