<?php
  if (isset($content['field_hero_image'])):
    $image_url = image_style_url('slideshow_homepage', $node->field_hero_image['und'][0]['uri']);
?>
  <div<?php print $attributes; ?> style="background-image:url('<?php print $image_url; ?>');">
<?php else: ?>
  <div<?php print $attributes; ?>>
<?php endif; ?>
    <div class="slide-image-background">

    	<div class="slide-content">
    	  <div<?php print $content_attributes; ?>>
          <?php if (!empty($content['field_display_title']['#items'][0]['value'])): ?>
            <h1 class="field--name-field-display-title">
              <?php print $content['field_display_title']['#items'][0]['value']; ?>
            </h1>
            <?php print render($content['field_intro']); ?>
          <?php else: ?>
            <h1 class="field--name-field-display-title"><?php print $title; ?></h1>
          <?php endif; ?>
    	  </div>
    	</div>

    </div>
  </div>
