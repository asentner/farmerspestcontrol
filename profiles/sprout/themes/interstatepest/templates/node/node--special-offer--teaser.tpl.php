<article<?php print $attributes; ?>>
  <header>
    <?php print render($title_prefix); ?>
    <?php if (!$page): ?>
      <h3<?php print $title_attributes; ?>><?php print $title; ?></h3>
    <?php endif; ?>
    <?php print render($title_suffix); ?>
  </header>

  <div<?php print $content_attributes; ?>>
    <?php print render($content['body']); ?>
    <div class="field--group-offer">
      <?php print render($content['field_original_price']); ?>
      <?php print render($content['field_offer_price']); ?>
    </div>
    <?php print render($content['field_expiration_date']); ?>
    <?php print render($content['field_button']); ?>
  </div>

</article>
