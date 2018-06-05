<article<?php print $attributes; ?>>

  <div class="node-title">
  </div>

  <div<?php print $content_attributes; ?>>
    <h1<?php print $title_attributes; ?>><?php print $title; ?></h1>
  <?php
      // We hide the comments and links now so that we can render them later.
      hide($content['comments']);
      hide($content['links']);
      print render($content);
    ?>
  </div>

</article>
