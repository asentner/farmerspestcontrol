<?php
  hide($content['field_display_title']);
  hide($content['field_intro']);
  hide($content['field_local_content']);
  hide($content['field_seo_title']);
?>
<article<?php print $attributes; ?>>
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
        <h1><?php print $title; ?></h1>
      <?php endif; ?>
    </header>
  <?php endif; ?>

  <?php if ($display_submitted): ?>
    <footer class="node__submitted">
      <?php print $user_picture; ?>
      <p class="submitted"><?php print $submitted; ?></p>
    </footer>
  <?php endif; ?>

  <div<?php print $content_attributes; ?>>
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