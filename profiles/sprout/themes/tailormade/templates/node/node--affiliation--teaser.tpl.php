<article<?php print $attributes; ?>>

  <?php if ($display_submitted): ?>
    <footer class="node__submitted">
      <p class="submitted"><?php print date('l, F j, Y' ,$created); ?></p>
    </footer>
  <?php endif; ?>

  <div<?php print $content_attributes; ?>>
    <?php
      // We hide the comments and links now so that we can render them later.
      hide($content['comments']);
      hide($content['links']);
      print '<h2 class="element-invisible" style="margin:0; padding: 0; ">' . $title . '</h2>';
      print render($content);
    ?>
  </div>

</article>
