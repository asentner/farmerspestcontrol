<div class="<?php print $classes; ?>"<?php print $attributes; ?>>
  <?php if (!$label_hidden): ?>
    <div class="field-label"<?php print $title_attributes; ?>><?php print $label ?>:&nbsp;</div>
  <?php endif; ?>
  <div class="field-items"<?php print $content_attributes; ?>>
    <?php foreach ($items as $delta => $item): ?>
      <div class="field-item <?php print $delta % 2 ? 'odd' : 'even'; ?>"<?php print $item_attributes[$delta]; ?>><a href="<?php print $item['#href']; ?>"><?php print preg_replace("/^(\d{3})(\d{3})(\d{4})$/", "$1-$2-$3", $item['#title']); ?></a></div>
    <?php endforeach; ?>
  </div>
</div>
