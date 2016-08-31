<article<?php print $attributes; ?>>
  <?php print render($content['field_image']); ?>
  <div<?php print $content_attributes; ?>>
    <?php if ($page): ?>
      <header>
        <?php if (isset($content['field_display_title'])): ?>
          <?php print render($content['field_display_title']); ?>
          <?php print render($content['field_intro']); ?>
          <?php print render($content['field_image']); ?>
          <?php if (isset($content['field_seo_title'])): ?>
            <?php print render($content['field_seo_title']); ?>
          <?php else: ?>
            <h1 class="field--name-field-seo-title"><?php print $title; ?></h1>
          <?php endif; ?>
        <?php else: ?>
          <h1 class="field--name-field-display-title"><?php print $title; ?></h1>
        <?php endif; ?>
      </header>
    <?php else: ?>
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
