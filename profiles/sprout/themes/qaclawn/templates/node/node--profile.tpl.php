<article<?php print $attributes; ?>>
  <?php print render($content['field_image']); ?>

  <div<?php print $content_attributes; ?>>
    <header>
      <?php print render($title_prefix); ?>
      <h2<?php print $title_attributes; ?>><a href="<?php print $node_url; ?>" rel="bookmark"><?php print $title; ?></h2>
      <?php print render($title_suffix); ?>
    </header>
    <?php
      // We hide the comments and links now so that we can render them later.
      hide($content['comments']);
      hide($content['links']);
      print render($content);
    ?>
  </div>

</article>
