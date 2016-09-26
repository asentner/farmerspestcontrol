<article<?php print $attributes; ?>>
  <div class="coupon-wrap">
    <div class="logo-wrap">
      <img src="<?php print theme_get_setting('logo'); ?>">
    </div>
    <div<?php print $content_attributes; ?>>
      <header>
        <h3<?php print $title_attributes; ?>><?php print $title; ?></h3>
      </header>

      <?php
        // We hide the comments and links now so that we can render them later.
        hide($content['comments']);
        hide($content['links']);
        print render($content);
      ?>
    </div>
  </div>
</article>
