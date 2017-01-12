<article<?php print $attributes; ?>>
  <div class="content-wrap">
    <?php if(!empty($content['field_icon']['#items'][0]['width'])) {
      print render($content['field_icon']);
    }
    elseif(!empty($content['field_image'][0]['#item']['uri'])) {
      print render($content['field_image']);
    };
  ?>
    <div<?php print $content_attributes; ?>>
        <?php
          if (isset($content['field_link'])):
            $link = $content['field_link'][0]['#element']['url'];
        ?>
          <h2<?php print $title_attributes; ?>><a href="<?php print $link; ?>" rel="bookmark"><?php print $title; ?></a></h2>
        <?php else: ?>
          <h2<?php print $title_attributes; ?>><?php print $title; ?></h2>
        <?php endif; ?>
      <?php
        // We hide the comments and links now so that we can render them later.
        hide($content['comments']);
        hide($content['links']);
        hide($content['field_link']);
        print render($content['body']);
      ?>
    </div>
  </div>
  <?php if($link): ?>
    <div class="link-wrap">
      <a href="<?php print $link ?>">Read More</a>
    </div>
  <?php endif; ?>
</article>
