<?php print render($content['field_icon']); ?>
<?php print render($content['field_image']); ?>
<article<?php print $attributes; ?>>
  <?php print render($title_prefix); ?>
  <?php print render($title_suffix); ?>
  <div<?php print $content_attributes; ?>>
      <?php
        if (isset($content['field_link'])):
          $link = $content['field_link'][0]['#element']['url'];
          hide($content['field_link']);
      ?>
        <h2<?php print $title_attributes; ?>><a href="<?php print $link; ?>" rel="bookmark"><?php print $title; ?></a></h2>
        <?php print render($content); ?>
        <a href="<?php print $link; ?>" class="read-more">Read More</a>
      <?php else: ?>
        <h2<?php print $title_attributes; ?>><?php print $title; ?></h2>
            <?php echo $content['body'][0]['#markup'];?>
      <?php endif; ?>
  </div>
  <?php
    // We hide the comments and links now so that we can render them later.
    hide($content['comments']);
    hide($content['links']);
  ?>
</article>
