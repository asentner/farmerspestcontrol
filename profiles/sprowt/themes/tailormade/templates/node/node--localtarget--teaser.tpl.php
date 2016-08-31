<?php
hide($content['field_image']);
hide($content['field_color']);
?>

<div<?php print $attributes; ?>>

  <div<?php print $content_attributes; ?>>

    <?php if (!empty($title_prefix) || !empty($title_suffix) || !$page): ?>
      <div>
        <?php print render($title_prefix); ?>
        <?php if (!$page): ?>
          <h2<?php print $title_attributes; ?>><?php print $title; ?></h2>
        <?php endif; ?>
        <?php print render($title_suffix); ?>
      </div>
    <?php endif; ?>

    <?php
      // We hide the comments and links now so that we can render them later.
      hide($content['comments']);
      hide($content['links']);
      print render($content);
    ?>
  </div>

</div>
