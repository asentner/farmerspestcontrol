<?php
  if (isset($content['field_image'])):
    $image_url = image_style_url('slideshow_homepage', $bean->field_image['und'][0]['uri']);
?>
  <div<?php print $attributes; ?> style="background-image:url('<?php print $image_url; ?>');">
<?php else: ?>
  <div<?php print $attributes; ?>>
<?php endif; ?>
    <div class="content-wrap">
    	<div class="content"<?php print $content_attributes; ?>>
        <h2 class="block__title"><?php print $title; ?></h2>
        <?php print render($content['field_title']); ?>
        <?php print render($content['field_subtitle']); ?>
        <?php print render($content['field_body_text']); ?>
        <?php print render($content['field_button']); ?>
  	    <?php
            hide($content['field_image']);
    	      print render($content);
    	   ?>
    	</div>

    </div>
  </div>
