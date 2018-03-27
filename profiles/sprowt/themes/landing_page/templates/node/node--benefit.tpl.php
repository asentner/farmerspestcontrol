<article<?php print $attributes; ?>>

    <?php
        hide($content['field_icon']);
        hide($content['field_image']);
    ?>
  <?php if(!empty($content['field_icon']['#items'][0]['width'])) {
      print render($content['field_icon']);
    }
    elseif(!empty($content['field_image'][0]['#item']['uri'])) {
      print render($content['field_image']);
    };
  ?>

  <div<?php print $content_attributes; ?>>
      <h2<?php print $title_attributes; ?>><?php print $title; ?></h2>
    <?php
      // We hide the comments and links now so that we can render them later.
      hide($content['comments']);
      hide($content['links']);
      hide($content['field_image']);
      hide($content['field_icon']);
      print render($content['body']);
    ?>
  </div>

</article>
