<?php

?>
<article <?php print $attributes; ?>>

  <div class="node-title">
    <h2<?php print $title_attributes; ?>><?php print $title; ?></h2>
  </div>

  <div <?php print $content_attributes; ?>>
      <?php print render($content['field_display_title']); ?>
      <div class="body-content">
        <?php print render($content ['body']); ?>
      </div>
  </div>

  <div class="identifications">
    <?php print render($content['field_identification_title']); ?>
    <?php print render($content['field_issue_identifications']); ?>
  </div>

    <?php
      // We hide the comments and links now so that we can render them later.
      hide($content['comments']);
      hide($content['links']);
      hide($content['field_image']);
      print render($content);
    ?>
</article>
