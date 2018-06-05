<?php

?>
<article<?php print $attributes; ?>>

  <div class="icon">
    <a href="<?php print $node_url; ?>"><?php print render($content['field_icon_file']); ?></a>
  </div>

  <div class="content">
    <h4 <?php print $title_attributes; ?>><a href="<?php print $node_url; ?>"><?php print $title; ?></a></h4>
    <?php print render($content['body']); ?>
  </div>


    <?php
      // We hide the comments and links now so that we can render them later.
      hide($content['comments']);
      hide($content['links']);
      hide($content['field_call_out']);
      print render($content);
    ?>
</article>
