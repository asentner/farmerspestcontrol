<?php

?>
<article<?php print $attributes; ?>>
  <header>
    <?php print render($content['field_icon']); ?>
    <h3 class="node__title"><a href="<?php print $node_url ?>"><?php print $title ?></a></h3>
  </header>
  <?php print render($content['body']); ?>
  <div<?php print $content_attributes; ?>>
    <?php
      // We hide the comments and links now so that we can render them later.
      hide($content['comments']);
      hide($content['links']);
      hide($content['field_image']);
      print render($content);
    ?>
  </div>
</article>
