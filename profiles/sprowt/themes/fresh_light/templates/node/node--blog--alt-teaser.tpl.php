<article<?php print $attributes; ?>>
  
  <?php print render($content['field_image']); ?>

  <div<?php print $content_attributes; ?>>

    <?php if (!empty($title_prefix) || !empty($title_suffix) || !$page): ?>
      <header>
        <?php print render($title_prefix); ?>
        <?php if (!$page): ?>
          <h3<?php print $title_attributes; ?>><a href="<?php print $node_url; ?>" rel="bookmark"><?php print $title; ?></a></h3>
        <?php endif; ?>
        <?php print render($title_suffix); ?>
      </header>
    <?php endif; ?>

    <?php if ($display_submitted): ?>
      <footer class="node__submitted">
        <p class="submitted"><?php print date('l, F j, Y' ,$created); ?></p>
      </footer>
    <?php endif; ?>

    <?php
      // We hide the comments and links now so that we can render them later.
      hide($content['comments']);
      hide($content['links']);
      print render($content);
    ?>
    
  </div>

  <?php print render($content['links']); ?>
  <?php print render($content['comments']); ?>
</article>
