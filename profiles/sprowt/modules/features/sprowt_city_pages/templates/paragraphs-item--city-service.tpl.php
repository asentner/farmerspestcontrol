<article <?php print $attributes; ?>>
  <div id="<?php print trim(render($content['field_anchor_tag'])); ?>" >

    <?php
      // We hide the comments and links now so that we can render them later.
      hide($content['comments']);
      hide($content['links']);
      print render($content);
    ?>

  </div>
</article>
