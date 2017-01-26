<?php
hide($content['field_display_title']);
hide($content['field_intro']);
?>
<article<?php print $attributes; ?>>
  <header>
    <?php if($intro_title): ?>
      <?php print render($content['field_display_title']); ?>
      <?php print render($content['field_intro']); ?>
    <?php endif; ?>

    <?php if(!empty($content['field_seo_title'][LANGUAGE_NONE][0]) || !empty($content['field_seo_title'][0])): ?>
      <?php print render($content['field_seo_title']); ?>
    <?php else: ?>
      <h1<?php print $title_attributes; ?>><?php print $title; ?></h1>
    <?php endif; ?>
  </header>
  <?php if(!drupal_is_front_page()): ?>
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
  <?php endif; ?>
</article>
