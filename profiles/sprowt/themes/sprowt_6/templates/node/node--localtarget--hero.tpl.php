<article<?php print $attributes; ?>>
  <header>
      <div class="content">
          <?php
          // We hide the comments and links now so that we can render them later.
          hide($content['comments']);
          hide($content['links']);
          hide($content['field_hero_image']);
          print render($content);
          ?>
      </div>
  </header>
</article>
