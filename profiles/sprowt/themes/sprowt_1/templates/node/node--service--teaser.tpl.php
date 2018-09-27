<article<?php print $attributes; ?>>

  <?php print render($content['field_icon']); ?>

  <div<?php print $content_attributes; ?>>
    <header>
      <h2<?php print $title_attributes; ?>><a href="<?php print $node_url; ?>" rel="bookmark"><?php print $title; ?></a></h2>
    </header>

    <?php
      // We hide the comments and links now so that we can render them later.
      hide($content['comments']);
      hide($content['links']);
      print render($content);
    ?>
  </div>

</article>
