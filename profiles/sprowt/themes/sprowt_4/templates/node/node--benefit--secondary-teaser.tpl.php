<article<?php print $attributes; ?>>

  <?php print render($content['field_image']); ?>

  <div<?php print $content_attributes; ?>>
      <?php
        if (isset($content['field_link'])):
          $link = $content['field_link'][0]['#element']['url'];
      ?>
        <h2<?php print $title_attributes; ?>><a href="<?php print $link; ?>" rel="bookmark"><?php print $title; ?></a></h2>
      <?php else: ?>
        <h2<?php print $title_attributes; ?>><?php print $title; ?></h2>
      <?php endif; ?>
    <?php
      // We hide the comments and links now so that we can render them later.
      hide($content['comments']);
      hide($content['links']);
      hide($content['field_link']);
      print render($content);
    ?>
  </div>

</article>
