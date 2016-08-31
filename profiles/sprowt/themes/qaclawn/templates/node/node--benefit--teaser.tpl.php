<?php
  if (isset($content['field_display_title'][0]['#markup'])) {
    hide($content['field_display_title']);
    $title = $content['field_display_title'][0]['#markup'];
  }
?>
<article<?php print $attributes; ?>>
  <?php print render($content['field_image']); ?>

  <header>
    <?php print render($title_prefix); ?>
    <h2<?php print $title_attributes; ?>><?php print $title; ?></h2>
    <?php print render($title_suffix); ?>
  </header>

  <div<?php print $content_attributes; ?>>
    <?php
      // We hide the comments and links now so that we can render them later.
      hide($content['comments']);
      hide($content['links']);
      print render($content);
    ?>
  </div>
  
</article>