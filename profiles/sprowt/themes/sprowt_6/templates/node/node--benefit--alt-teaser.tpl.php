<article<?php print $attributes; ?>>

  <?php print render($content['field_icon']); ?>

  <div<?php print $content_attributes; ?>>
        <h2<?php print $title_attributes; ?>><?php print $title; ?></h2>
        <?php print render($content['body']); ?>
    <?php
      // We hide the comments and links now so that we can render them later.
      hide($content['comments']);
      hide($content['links']);
      hide($content['field_link']);
      hide($content['field_image']);
      hide($content['field_icon']);
      print render($content);
    ?>
  </div>

</article>
