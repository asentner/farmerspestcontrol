<?php

?>
<article<?php print $attributes; ?>>

  <div class="header">
    <h1 <?php print $title_attributes; ?>><?php print $title; ?></h1>
    <?php print render($content['field_subtitle']); ?>
    <?php print render($content['field_post_date']); ?>
  </div>

  <div<?php print $content_attributes; ?>>
    <?php
      // We hide the comments and links now so that we can render them later.
      hide($content['comments']);
      hide($content['links']);
      hide($content['field_call_out']);
      print render($content);
    ?>
  </div>

  <?php print render($content['links']); ?>
  <?php print render($content['field_call_out']); ?>
</article>
