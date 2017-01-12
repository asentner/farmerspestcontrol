<article<?php print $attributes; ?>>
  <?php if(!empty($content['field_icon']['#items'][0]['width'])) {
      print render($content['field_icon']);
    }
    elseif(!empty($content['field_image'][0]['#item']['uri'])) {
      print render($content['field_image']);
    };
  ?>
  <div<?php print $content_attributes; ?>>
    <header>
      <h2<?php print $title_attributes; ?>><a href="<?php print $node_url; ?>" rel="bookmark"><?php print $title; ?></a></h2>
    </header>
    <?php
      // We hide the comments and links now so that we can render them later.
      hide($content['comments']);
      hide($content['links']);
      // print render($content);
      print render($content['body']);
    ?>
  </div>
</article>
