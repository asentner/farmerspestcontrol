<?php
  if (isset($content['field_background_image'])):
    $image_url = image_style_url('slideshow_homepage', $bean->field_background_image['und'][0]['uri']);
?>
  <div<?php print $attributes; ?> style="background-image:url('<?php print $image_url; ?>');">
<?php else: ?>
  <div<?php print $attributes; ?>>
<?php endif; ?>

  	<div class="content"<?php print $content_attributes; ?>>
	    <?php
          hide($content['field_background_image']);
  	      print render($content);
  	   ?>
  	</div>

  </div>
