<article<?php print $attributes; ?>>

  <div<?php print $content_attributes; ?>>
    <?php print render($content['field_image']); ?>
    <h2 class="node__title"><?php print $title; ?></h2>
    <?php
      // We hide the comments and links now so that we can render them later.
      hide($content['comments']);
      hide($content['links']);
      print render($content);
    ?>
  </div>  
  
  <?php print render($content['links']); ?>
  <?php print render($content['comments']); ?>
</article>
