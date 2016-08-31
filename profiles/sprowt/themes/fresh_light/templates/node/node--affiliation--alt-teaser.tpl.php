<?php
  if (isset($content['field_link'][0]['#element']['url'])) {
    $link_url = $content['field_link'][0]['#element']['url'];
  }
?>
<article<?php print $attributes; ?>>
  
  <?php print render($content['field_image']); ?>

  <div<?php print $content_attributes; ?>>
    <?php if (isset($link_url)): ?>
      <h2 class="node__title"><a href="<?php print $link_url ?>" target="_blank"><?php print $title; ?></a></h2>
    <?php else: ?>
      <h2 class="node__title"><?php print $title; ?></h2>
    <?php endif; ?>
    <?php
      // We hide the comments and links now so that we can render them later.
      hide($content['comments']);
      hide($content['links']);
      print render($content);
    ?>
  </div>  
  
  <?php print render($content['links']); ?>
  <?php print render($content['comments']); ?>
</article>