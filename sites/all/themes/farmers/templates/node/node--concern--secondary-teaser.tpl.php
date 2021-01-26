<?php

?>
<article<?php print $attributes; ?>>

  <a href="<?php print $node_url; ?>">
    <?php print render($content['field_icon_file']); ?>
    <h4 <?php print $title_attributes; ?>><?php print $title; ?></h4>
  </a>

    <?php
      // We hide the comments and links now so that we can render them later.
      hide($content['comments']);
      hide($content['links']);
      hide($content['field_call_out']);
      print render($content);
    ?>
</article>
