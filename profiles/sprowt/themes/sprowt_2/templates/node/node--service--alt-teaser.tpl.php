<?php
  if (isset($content['field_image'])) {
    $image_style = $content['field_image'][0]['#image_style'];
    $image_uri = $content['field_image'][0]['#item']['uri'];
    $image_url = image_style_url($image_style, $image_uri);
  }
?>
<?php if(isset($content['field_image'])): ?>
<article<?php print $attributes; ?> style="background-image:url(<?php print $image_url ?>)">
<?php else: ?>
<article<?php print $attributes; ?>>
<?php endif; ?>
  <header>
    <h3 class="node__title"><a href="<?php print $node_url ?>"><?php print $title ?></a></h3>
  </header>
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
