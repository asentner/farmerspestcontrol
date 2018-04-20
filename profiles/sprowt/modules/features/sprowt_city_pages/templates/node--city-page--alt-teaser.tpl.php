<article<?php print $attributes; ?>>

  <?php print render($content['field_image']); ?>

  <div<?php print $content_attributes; ?>>

    <?php
      // We hide the comments and links now so that we can render them later.
      hide($content['title']);
      hide($content['comments']);
      hide($content['links']);
      print render($content);
    ?>
  </div>

</article>
