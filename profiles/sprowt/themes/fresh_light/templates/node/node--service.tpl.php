<?php
  hide($content['field_display_title']);
  hide($content['field_image']);
  hide($content['field_intro']);
  hide($content['field_seo_title']);
  hide($content['field_package_intro']);
?>
<article<?php print $attributes; ?>>
  <header>
    <h1><?php print render($content['field_display_title']); ?></h1>
    <?php print render($content['field_intro']); ?>
  </header>

  <?php if ($display_submitted): ?>
    <footer class="node__submitted">
      <?php print $user_picture; ?>
      <p class="submitted"><?php print $submitted; ?></p>
    </footer>
  <?php endif; ?>

  <div<?php print $content_attributes; ?>>
    <?php print render($content['field_image']); ?>
    <h2 class="seo-title"><?php print render($content['field_seo_title']); ?></h2>
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
