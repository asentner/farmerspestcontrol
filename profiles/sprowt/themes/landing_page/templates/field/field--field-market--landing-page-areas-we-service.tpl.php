<div class="<?php print $classes; ?>"<?php print $attributes; ?>>
  <?php if (!$label_hidden): ?>
    <div class="field-label"<?php print $title_attributes; ?>><?php print $label ?>:&nbsp;</div>
  <?php endif; ?>
  <ul class="field-items"<?php print $content_attributes; ?>>
      <?php $place = 0; ?>
    <?php foreach ($items as $delta => $item): ?>
      <li class="field-item <?php print $place % 2 ? 'odd' : 'even'; ?>"<?php print $item_attributes[$delta]; ?>><?php print render($item); ?></li>
        <?php ++$place; ?>
    <?php endforeach; ?>
  </ul>
</div>
