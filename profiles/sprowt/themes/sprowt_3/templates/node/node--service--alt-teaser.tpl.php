<?php
  $link = drupal_get_path_alias('node/'.$node->nid);
 ?>
<article<?php print $attributes; ?>>
<?php print render($content['field_icon']); ?>
<h2<?php print $title_attributes; ?>><a href="<?php print $link; ?>" rel="bookmark"><?php print $title; ?></a></h2>

  <div<?php print $content_attributes; ?>>
    <?php
    // We hide the comments and links now so that we can render them later.
    hide($content['comments']);
    hide($content['links']);
    print render($content);
    ?>
    <a class="read-more" href="<?php print $link; ?>" rel="bookmark">Read More</a>
  </div>
</article>
