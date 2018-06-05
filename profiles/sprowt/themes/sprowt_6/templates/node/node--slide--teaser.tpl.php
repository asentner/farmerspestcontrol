<?php
  if (isset($content['field_image'])):
    $image_url = image_style_url('slideshow_homepage', $node->field_image['und'][0]['uri']);
?>
  <div<?php print $attributes; ?> style="background-image:url('<?php print $image_url; ?>');">
<?php else: ?>
  <div<?php print $attributes; ?>>
<?php endif; ?>
    <div class="slide-image">
    	<div class="slide-content">
    	  <h2<?php print $title_attributes; ?>><?php print $title; ?></h2>
    	  <div<?php print $content_attributes; ?>>
    	    <?php
            hide($content['field_image']);
    	      print render($content);
    	    ?>
    	  </div>
    	</div>

    </div>
  </div>
