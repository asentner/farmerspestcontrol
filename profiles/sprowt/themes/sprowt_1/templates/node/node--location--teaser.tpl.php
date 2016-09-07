<div<?php print $attributes; ?>>

  <div<?php print $content_attributes; ?>>

    <div class="field field--title">
      <?php print $title; ?>
    </div>

    <?php
      // We hide the comments and links now so that we can render them later.
      hide($content['comments']);
      hide($content['links']);
      print render($content);
    ?>
  </div>

</div>
