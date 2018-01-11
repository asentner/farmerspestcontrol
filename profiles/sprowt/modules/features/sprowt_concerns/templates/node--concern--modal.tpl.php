
<article<?php print $attributes; ?>>
  <header>
      <span class="concern-title">Pest Concern</span>
      <h2<?php print $title_attributes; ?>>You Want To Know More About <?php print $title; ?></h2>
  </header>
    <?php print render($content['field_icon_file']); ?>

  <div<?php print $content_attributes; ?>>
    <?php
      // We hide the comments and links now so that we can render them later.
      hide($content['comments']);
      hide($content['links']);
      print render($content);
    ?>
  </div>
</article>
