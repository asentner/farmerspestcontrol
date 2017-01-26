<?php
  if (isset($content['field_image'])) {
    $image_style = $content['field_image'][0]['#image_style'];
    $image_uri = $content['field_image'][0]['#item']['uri'];
    $image_url = image_style_url($image_style, $image_uri);
  }
?>
<article<?php print $attributes; ?>>
  <?php if(isset($content['field_image'])): ?>
    <div class="background-wrap" style="background-image:url(<?php print $image_url ?>)"></div>
  <?php endif; ?>
  <div class="icon-wrap">
    <?php print render($content['field_icon']); ?>
    <h3 class="node__title"><a href="<?php print $node_url ?>"><?php print $title ?></a></h3>
  </div>
  <div<?php print $content_attributes; ?>>
    <?php
      // We hide the comments and links now so that we can render them later.
      hide($content['comments']);
      hide($content['links']);
      hide($content['field_image']);
      print render($content);
    ?>
  </div>
</article>
