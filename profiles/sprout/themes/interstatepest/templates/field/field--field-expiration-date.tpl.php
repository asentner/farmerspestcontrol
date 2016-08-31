<div class="<?php print $classes; ?>"<?php print $attributes; ?>>
	<span class="field-label"<?php print $title_attributes; ?>>Expires:</span>
	<span class="field-items"<?php print $content_attributes; ?>>
		<?php foreach ($items as $delta => $item): ?>
			<span class="field-item <?php print $delta % 2 ? 'odd' : 'even'; ?>"<?php print $item_attributes[$delta]; ?>><?php print render($item); ?></span>
		<?php endforeach; ?>
	</span>
</div>
