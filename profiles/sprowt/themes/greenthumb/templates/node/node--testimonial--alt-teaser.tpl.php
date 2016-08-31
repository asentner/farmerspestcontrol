<div<?php print $attributes; ?>>
  <div<?php print $content_attributes; ?> itemscope itemtype="http://schema.org/Review">

    <span itemprop="itemReviewed" itemscope itemtype="http://schema.org/LocalBusiness">
      <meta itemprop="name" content="<?php print variable_get('site_name'); ?>">
    </span>

    <div itemprop="reviewRating" itemscope itemtype="http://schema.org/Rating">
      <meta itemprop="worstRating" content="1">
      <span itemprop="ratingValue" content="5" class="rating">
        <i class="fa fa-star"></i>
        <i class="fa fa-star"></i>
        <i class="fa fa-star"></i>
        <i class="fa fa-star"></i>
        <i class="fa fa-star"></i>
      </span>
      <meta itemprop="bestRating" content="5">
    </div>

    <div itemprop="description">
      <?php print render($content['body']); ?>
    </div>

    <div class="name-market-wrap">
      <div class="field--title" itemprop="author"><?php print $title; ?></div><?php if (!empty($content['field_market'])): ?>,<?php endif; ?>
      <?php print render($content['field_market']); ?>
    </div>

    <div class="field--image" itemprop="image">
      <?php print render($content['field_image']); ?>
    </div>

    <?php
      // We hide the comments and links now so that we can render them later.
      hide($content['comments']);
      hide($content['links']);
      print render($content);
    ?>

  </div>

</div>
