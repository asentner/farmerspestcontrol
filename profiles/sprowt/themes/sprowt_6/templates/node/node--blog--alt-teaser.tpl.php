<?php

?>
<article<?php print $attributes; ?>>

  <?php print render($content['field_image']); ?>

  <div class="teaser-content">
    <h3 <?php print $title_attributes; ?>><a href="<?php print $node_url; ?>" rel="bookmark"><?php print $title; ?></a></h3>
    <?php print render($content['field_post_date']); ?>
    <?php print render($content['body']); ?>
    <a href="<?php print $node_url; ?>" rel="bookmark" class="more-link">Continue Reading</a>
  </div>

    <?php
      // We hide the comments and links now so that we can render them later.
      hide($content['comments']);
      hide($content['links']);
      hide($content['field_call_out']);
      print render($content);
    ?>
</article>
