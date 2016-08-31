<div<?php print $attributes; ?>>

  <div<?php print $content_attributes; ?> itemprop="review" itemscope itemtype="http://schema.org/Review">

    <div itemprop="reviewRating" itemscope itemtype="http://schema.org/Rating">
      <meta itemprop="worstRating" content="1">
      <span itemprop="ratingValue" content="5" class="rating">
        &#9733; &#9733; &#9733; &#9733; &#9733;
      </span>
      <meta itemprop="bestRating" content="5">
    </div>

    <div itemprop="description">
      <?php print render($content['body']); ?>
    </div>

    <?php
      // We hide the comments and links now so that we can render them later.
      hide($content['comments']);
      hide($content['links']);
      print render($content);
    ?>

    <div class="field--title" itemprop="author">
      <?php print $title; ?>
    </div>

  </div>
  
</div>
