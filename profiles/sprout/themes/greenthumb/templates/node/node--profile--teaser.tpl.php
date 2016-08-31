<?php
hide($content['field_image']);
hide($content['body']);
?>
<article<?php print $attributes; ?>>
  <?php print render($content['field_image']); ?>

  <div<?php print $content_attributes; ?>>
    <?php if (!empty($title_prefix) || !empty($title_suffix) || !$page): ?>
      <header>
        <?php print render($title_prefix); ?>
        <?php if (!$page): ?>
          <h2<?php print $title_attributes; ?>><a href="<?php print $node_url; ?>" rel="bookmark"><?php print $title; ?></a></h2>
        <?php endif; ?>
        <?php print render($title_suffix); ?>
      </header>
    <?php endif; ?>
    <?php
      // We hide the comments and links now so that we can render them later.
      hide($content['comments']);
      hide($content['links']);
      print render($content);
    ?>
  </div>
</article>
