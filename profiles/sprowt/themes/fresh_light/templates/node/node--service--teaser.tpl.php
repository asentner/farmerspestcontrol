<?php hide($content['field_image']); ?>
<article<?php print $attributes; ?> itemscope itemtype="http://schema.org/Product">

  <?php print render($field_image_teaser); //Altered image style in node.preprocess.inc ?>

  <div<?php print $content_attributes; ?>>
    <?php if (!empty($title_prefix) || !empty($title_suffix) || !$page): ?>
      <header>
        <?php print render($title_prefix); ?>
        <?php if (!$page): ?>
          <h2<?php print $title_attributes; ?> itemprop="name"><a href="<?php print $node_url; ?>" rel="bookmark"><?php print $title; ?></a></h2>
        <?php endif; ?>
        <?php print render($title_suffix); ?>
      </header>
    <?php endif; ?>

    <?php if ($display_submitted): ?>
      <footer class="node__submitted">
        <?php print $user_picture; ?>
        <p class="submitted"><?php print $submitted; ?></p>
      </footer>
    <?php endif; ?>

    <?php
      // We hide the comments and links now so that we can render them later.
      hide($content['comments']);
      hide($content['links']);
      print render($content);
    ?>

    <?php print render($content['links']); ?>
    <?php print render($content['comments']); ?>
  </div>

</article>
