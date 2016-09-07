<article<?php print $attributes; ?>>

  <div<?php print $content_attributes; ?>>
    <header>
      <h2<?php print $title_attributes; ?>><?php print $title; ?></h2>
    </header>

    <?php
      // We hide the comments and links now so that we can render them later.
      hide($content['comments']);
      hide($content['links']);
      print render($content);
    ?>
  </div>

</article>
