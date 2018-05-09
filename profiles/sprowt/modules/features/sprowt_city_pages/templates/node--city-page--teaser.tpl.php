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
    	    <?php
            hide($content['field_hero_image']);
    	      print render($content);
    	    ?>
    	  </div>
    	</div>

    </div>
  </div>
